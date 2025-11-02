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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEFDepA.yaml by
// generate.py. Do not modify by hand!

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

TEST(auto_check_sbp_navigation_MsgVelECEFDepA,
     test_auto_check_sbp_navigation_MsgVelECEFDepA) {
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,   2,   246, 215, 20,  20,  46,  39, 0, 218, 11, 0,  0,
        134, 245, 255, 255, 163, 252, 255, 255, 0,  0, 9,   0,  80, 236,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef_dep_a.accuracy = 0;

    test_msg.vel_ecef_dep_a.flags = 0;

    test_msg.vel_ecef_dep_a.n_sats = 9;

    test_msg.vel_ecef_dep_a.tow = 2567700;

    test_msg.vel_ecef_dep_a.x = 3034;

    test_msg.vel_ecef_dep_a.y = -2682;

    test_msg.vel_ecef_dep_a.z = -861;

    sbp_message_send(&sbp_state, SbpMsgVelEcefDepA, 55286, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcefDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.n_sats, 9)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.n_sats, expected "
           "9, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.tow, 2567700)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.tow, expected "
           "2567700, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.x, 3034)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.x, expected 3034, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.y, -2682)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.y, expected -2682, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.z, -861)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.z, expected -861, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 4,   2,   246, 215, 20,  120, 46,  39, 0, 68, 11, 0,   0,
        24, 246, 255, 255, 220, 252, 255, 255, 0,  0, 9,  0,  248, 138,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef_dep_a.accuracy = 0;

    test_msg.vel_ecef_dep_a.flags = 0;

    test_msg.vel_ecef_dep_a.n_sats = 9;

    test_msg.vel_ecef_dep_a.tow = 2567800;

    test_msg.vel_ecef_dep_a.x = 2884;

    test_msg.vel_ecef_dep_a.y = -2536;

    test_msg.vel_ecef_dep_a.z = -804;

    sbp_message_send(&sbp_state, SbpMsgVelEcefDepA, 55286, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcefDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.n_sats, 9)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.n_sats, expected "
           "9, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.tow, 2567800)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.tow, expected "
           "2567800, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.x, 2884)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.x, expected 2884, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.y, -2536)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.y, expected -2536, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.z, -804)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.z, expected -804, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 4,   2,   246, 215, 20,  220, 46,  39, 0, 21, 11, 0,  0,
        77, 246, 255, 255, 247, 252, 255, 255, 0,  0, 9,  0,  25, 174,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef_dep_a.accuracy = 0;

    test_msg.vel_ecef_dep_a.flags = 0;

    test_msg.vel_ecef_dep_a.n_sats = 9;

    test_msg.vel_ecef_dep_a.tow = 2567900;

    test_msg.vel_ecef_dep_a.x = 2837;

    test_msg.vel_ecef_dep_a.y = -2483;

    test_msg.vel_ecef_dep_a.z = -777;

    sbp_message_send(&sbp_state, SbpMsgVelEcefDepA, 55286, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcefDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.n_sats, 9)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.n_sats, expected "
           "9, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.tow, 2567900)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.tow, expected "
           "2567900, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.x, 2837)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.x, expected 2837, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.y, -2483)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.y, expected -2483, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.z, -777)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.z, expected -777, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 4,   2,   246, 215, 20,  64,  47,  39, 0, 121, 11, 0,   0,
        2,  246, 255, 255, 234, 252, 255, 255, 0,  0, 9,   0,  195, 228,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef_dep_a.accuracy = 0;

    test_msg.vel_ecef_dep_a.flags = 0;

    test_msg.vel_ecef_dep_a.n_sats = 9;

    test_msg.vel_ecef_dep_a.tow = 2568000;

    test_msg.vel_ecef_dep_a.x = 2937;

    test_msg.vel_ecef_dep_a.y = -2558;

    test_msg.vel_ecef_dep_a.z = -790;

    sbp_message_send(&sbp_state, SbpMsgVelEcefDepA, 55286, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcefDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.n_sats, 9)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.n_sats, expected "
           "9, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.tow, 2568000)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.tow, expected "
           "2568000, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.x, 2937)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.x, expected 2937, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.y, -2558)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.y, expected -2558, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.z, -790)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.z, expected -790, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 4,   2,   246, 215, 20,  164, 47,  39, 0, 31, 11, 0,   0,
        93, 246, 255, 255, 16,  253, 255, 255, 0,  0, 9,  0,  219, 164,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef_dep_a.accuracy = 0;

    test_msg.vel_ecef_dep_a.flags = 0;

    test_msg.vel_ecef_dep_a.n_sats = 9;

    test_msg.vel_ecef_dep_a.tow = 2568100;

    test_msg.vel_ecef_dep_a.x = 2847;

    test_msg.vel_ecef_dep_a.y = -2467;

    test_msg.vel_ecef_dep_a.z = -752;

    sbp_message_send(&sbp_state, SbpMsgVelEcefDepA, 55286, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcefDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.n_sats, 9)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.n_sats, expected "
           "9, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.tow, 2568100)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.tow, expected "
           "2568100, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.x, 2847)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.x, expected 2847, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.y, -2467)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.y, expected -2467, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.z, -752)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.z, expected -752, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,   2,   195, 4,   20,  212, 157, 67, 24, 24, 0, 0,  0,
        245, 255, 255, 255, 219, 255, 255, 255, 0,  0,  8,  0, 68, 255,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef_dep_a.accuracy = 0;

    test_msg.vel_ecef_dep_a.flags = 0;

    test_msg.vel_ecef_dep_a.n_sats = 8;

    test_msg.vel_ecef_dep_a.tow = 407084500;

    test_msg.vel_ecef_dep_a.x = 24;

    test_msg.vel_ecef_dep_a.y = -11;

    test_msg.vel_ecef_dep_a.z = -37;

    sbp_message_send(&sbp_state, SbpMsgVelEcefDepA, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcefDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.n_sats, 8)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.n_sats, expected "
           "8, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.tow, 407084500)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.tow, expected "
           "407084500, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.x, 24)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.x, expected 24, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.y, -11)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.y, expected -11, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.z, -37)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.z, expected -37, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,   2,   195, 4,  20, 56, 158, 67, 24, 4, 0, 0,   0,
        234, 255, 255, 255, 18, 0,  0,  0,   0,  0,  8, 0, 214, 136,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef_dep_a.accuracy = 0;

    test_msg.vel_ecef_dep_a.flags = 0;

    test_msg.vel_ecef_dep_a.n_sats = 8;

    test_msg.vel_ecef_dep_a.tow = 407084600;

    test_msg.vel_ecef_dep_a.x = 4;

    test_msg.vel_ecef_dep_a.y = -22;

    test_msg.vel_ecef_dep_a.z = 18;

    sbp_message_send(&sbp_state, SbpMsgVelEcefDepA, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcefDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.n_sats, 8)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.n_sats, expected "
           "8, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.tow, 407084600)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.tow, expected "
           "407084600, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.x, 4)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.x, expected 4, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.y, -22)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.y, expected -22, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.z, 18)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.z, expected 18, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 4, 2, 195, 4, 20, 156, 158, 67, 24, 230, 255, 255, 255,
        4,  0, 0, 0,   1, 0,  0,   0,   0,  0,  8,   0,   122, 159,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef_dep_a.accuracy = 0;

    test_msg.vel_ecef_dep_a.flags = 0;

    test_msg.vel_ecef_dep_a.n_sats = 8;

    test_msg.vel_ecef_dep_a.tow = 407084700;

    test_msg.vel_ecef_dep_a.x = -26;

    test_msg.vel_ecef_dep_a.y = 4;

    test_msg.vel_ecef_dep_a.z = 1;

    sbp_message_send(&sbp_state, SbpMsgVelEcefDepA, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcefDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.n_sats, 8)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.n_sats, expected "
           "8, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.tow, 407084700)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.tow, expected "
           "407084700, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.x, -26)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.x, expected -26, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.y, 4)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.y, expected 4, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.z, 1)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.z, expected 1, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,   2,   195, 4,  20, 0, 159, 67, 24, 247, 255, 255, 255,
        237, 255, 255, 255, 28, 0,  0, 0,   0,  0,  8,   0,   232, 146,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef_dep_a.accuracy = 0;

    test_msg.vel_ecef_dep_a.flags = 0;

    test_msg.vel_ecef_dep_a.n_sats = 8;

    test_msg.vel_ecef_dep_a.tow = 407084800;

    test_msg.vel_ecef_dep_a.x = -9;

    test_msg.vel_ecef_dep_a.y = -19;

    test_msg.vel_ecef_dep_a.z = 28;

    sbp_message_send(&sbp_state, SbpMsgVelEcefDepA, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcefDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.n_sats, 8)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.n_sats, expected "
           "8, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.tow, 407084800)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.tow, expected "
           "407084800, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.x, -9)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.x, expected -9, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.y, -19)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.y, expected -19, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.z, 28)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.z, expected 28, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 4, 2, 195, 4,   20,  100, 159, 67, 24, 255, 255, 255, 255,
        2,  0, 0, 0,   245, 255, 255, 255, 0,  0,  8,   0,   171, 238,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef_dep_a.accuracy = 0;

    test_msg.vel_ecef_dep_a.flags = 0;

    test_msg.vel_ecef_dep_a.n_sats = 8;

    test_msg.vel_ecef_dep_a.tow = 407084900;

    test_msg.vel_ecef_dep_a.x = -1;

    test_msg.vel_ecef_dep_a.y = 2;

    test_msg.vel_ecef_dep_a.z = -11;

    sbp_message_send(&sbp_state, SbpMsgVelEcefDepA, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcefDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.n_sats, 8)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.n_sats, expected "
           "8, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.tow, 407084900)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.tow, expected "
           "407084900, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.x, -1)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.x, expected -1, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.y, 2)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.y, expected 2, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.z, -11)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.z, expected -11, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgVelEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,   2,   195, 4,  20, 46, 162, 68, 24, 207, 255, 255, 255,
        185, 255, 255, 255, 65, 0,  0,  0,   0,  0,  5,   0,   82,  154,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.vel_ecef_dep_a.accuracy = 0;

    test_msg.vel_ecef_dep_a.flags = 0;

    test_msg.vel_ecef_dep_a.n_sats = 5;

    test_msg.vel_ecef_dep_a.tow = 407151150;

    test_msg.vel_ecef_dep_a.x = -49;

    test_msg.vel_ecef_dep_a.y = -71;

    test_msg.vel_ecef_dep_a.z = 65;

    sbp_message_send(&sbp_state, SbpMsgVelEcefDepA, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgVelEcefDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.n_sats, 5)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.n_sats, expected "
           "5, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.tow, 407151150)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.tow, expected "
           "407151150, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.x, -49)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.x, expected -49, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.y, -71)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.y, expected -71, "
           "is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.vel_ecef_dep_a.z, 65)
        << "incorrect value for last_msg.msg.vel_ecef_dep_a.z, expected 65, is "
        << (int64_t)last_msg.msg.vel_ecef_dep_a.z;
  }
}

}  // namespace
