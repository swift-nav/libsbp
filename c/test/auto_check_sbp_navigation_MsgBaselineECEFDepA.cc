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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEFDepA.yaml by
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

TEST(auto_check_sbp_navigation_MsgBaselineECEFDepA,
     test_auto_check_sbp_navigation_MsgBaselineECEFDepA) {
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 2,   2,   246, 215, 20,  20,  46,  39, 0, 21, 48, 255, 255,
        52, 117, 255, 255, 216, 211, 254, 255, 0,  0, 9,  1,  50,  137,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef_dep_a.accuracy = 0;

    test_msg.baseline_ecef_dep_a.flags = 1;

    test_msg.baseline_ecef_dep_a.n_sats = 9;

    test_msg.baseline_ecef_dep_a.tow = 2567700;

    test_msg.baseline_ecef_dep_a.x = -53227;

    test_msg.baseline_ecef_dep_a.y = -35532;

    test_msg.baseline_ecef_dep_a.z = -76840;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcefDepA, 55286, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcefDepA, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.accuracy, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.flags, 1)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.flags, "
           "expected 1, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.n_sats, 9)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.n_sats, "
           "expected 9, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.tow, 2567700)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.tow, expected "
           "2567700, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.x, -53227)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.x, expected "
           "-53227, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.y, -35532)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.y, expected "
           "-35532, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.z, -76840)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.z, expected "
           "-76840, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 2,   2,   246, 215, 20,  120, 46,  39, 0, 58, 49, 255, 255,
        49, 116, 255, 255, 134, 211, 254, 255, 0,  0, 9,  1,  227, 155,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef_dep_a.accuracy = 0;

    test_msg.baseline_ecef_dep_a.flags = 1;

    test_msg.baseline_ecef_dep_a.n_sats = 9;

    test_msg.baseline_ecef_dep_a.tow = 2567800;

    test_msg.baseline_ecef_dep_a.x = -52934;

    test_msg.baseline_ecef_dep_a.y = -35791;

    test_msg.baseline_ecef_dep_a.z = -76922;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcefDepA, 55286, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcefDepA, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.accuracy, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.flags, 1)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.flags, "
           "expected 1, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.n_sats, 9)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.n_sats, "
           "expected 9, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.tow, 2567800)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.tow, expected "
           "2567800, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.x, -52934)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.x, expected "
           "-52934, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.y, -35791)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.y, expected "
           "-35791, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.z, -76922)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.z, expected "
           "-76922, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 2,   2,   246, 215, 20,  220, 46,  39, 0, 97, 50, 255, 255,
        47, 115, 255, 255, 52,  211, 254, 255, 0,  0, 9,  1,  61,  126,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef_dep_a.accuracy = 0;

    test_msg.baseline_ecef_dep_a.flags = 1;

    test_msg.baseline_ecef_dep_a.n_sats = 9;

    test_msg.baseline_ecef_dep_a.tow = 2567900;

    test_msg.baseline_ecef_dep_a.x = -52639;

    test_msg.baseline_ecef_dep_a.y = -36049;

    test_msg.baseline_ecef_dep_a.z = -77004;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcefDepA, 55286, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcefDepA, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.accuracy, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.flags, 1)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.flags, "
           "expected 1, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.n_sats, 9)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.n_sats, "
           "expected 9, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.tow, 2567900)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.tow, expected "
           "2567900, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.x, -52639)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.x, expected "
           "-52639, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.y, -36049)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.y, expected "
           "-36049, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.z, -77004)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.z, expected "
           "-77004, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 2,   2,   246, 215, 20,  64,  47,  39, 0, 136, 51, 255, 255,
        45, 114, 255, 255, 228, 210, 254, 255, 0,  0, 9,   1,  200, 79,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef_dep_a.accuracy = 0;

    test_msg.baseline_ecef_dep_a.flags = 1;

    test_msg.baseline_ecef_dep_a.n_sats = 9;

    test_msg.baseline_ecef_dep_a.tow = 2568000;

    test_msg.baseline_ecef_dep_a.x = -52344;

    test_msg.baseline_ecef_dep_a.y = -36307;

    test_msg.baseline_ecef_dep_a.z = -77084;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcefDepA, 55286, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcefDepA, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.accuracy, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.flags, 1)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.flags, "
           "expected 1, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.n_sats, 9)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.n_sats, "
           "expected 9, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.tow, 2568000)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.tow, expected "
           "2568000, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.x, -52344)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.x, expected "
           "-52344, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.y, -36307)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.y, expected "
           "-36307, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.z, -77084)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.z, expected "
           "-77084, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 2,   2,   246, 215, 20,  164, 47,  39, 0, 176, 52, 255, 255,
        44, 113, 255, 255, 149, 210, 254, 255, 0,  0, 9,   1,  104, 24,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef_dep_a.accuracy = 0;

    test_msg.baseline_ecef_dep_a.flags = 1;

    test_msg.baseline_ecef_dep_a.n_sats = 9;

    test_msg.baseline_ecef_dep_a.tow = 2568100;

    test_msg.baseline_ecef_dep_a.x = -52048;

    test_msg.baseline_ecef_dep_a.y = -36564;

    test_msg.baseline_ecef_dep_a.z = -77163;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcefDepA, 55286, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcefDepA, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.accuracy, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.flags, 1)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.flags, "
           "expected 1, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.n_sats, 9)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.n_sats, "
           "expected 9, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.tow, 2568100)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.tow, expected "
           "2568100, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.x, -52048)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.x, expected "
           "-52048, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.y, -36564)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.y, expected "
           "-36564, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.z, -77163)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.z, expected "
           "-77163, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  2,   2,   195, 4,   20, 156, 21, 69, 24, 169, 231, 255, 255,
        102, 208, 255, 255, 251, 28, 0,   0,  0,  0,  6,   0,   146, 168,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef_dep_a.accuracy = 0;

    test_msg.baseline_ecef_dep_a.flags = 0;

    test_msg.baseline_ecef_dep_a.n_sats = 6;

    test_msg.baseline_ecef_dep_a.tow = 407180700;

    test_msg.baseline_ecef_dep_a.x = -6231;

    test_msg.baseline_ecef_dep_a.y = -12186;

    test_msg.baseline_ecef_dep_a.z = 7419;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcefDepA, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcefDepA, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.accuracy, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.flags, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.n_sats, 6)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.n_sats, "
           "expected 6, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.tow, 407180700)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.tow, expected "
           "407180700, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.x, -6231)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.x, expected "
           "-6231, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.y, -12186)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.y, expected "
           "-12186, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.z, 7419)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.z, expected "
           "7419, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  2,   2,   195, 4,   20, 0, 22, 69, 24, 169, 231, 255, 255,
        103, 208, 255, 255, 252, 28, 0, 0,  0,  0,  6,   0,   34,  116,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef_dep_a.accuracy = 0;

    test_msg.baseline_ecef_dep_a.flags = 0;

    test_msg.baseline_ecef_dep_a.n_sats = 6;

    test_msg.baseline_ecef_dep_a.tow = 407180800;

    test_msg.baseline_ecef_dep_a.x = -6231;

    test_msg.baseline_ecef_dep_a.y = -12185;

    test_msg.baseline_ecef_dep_a.z = 7420;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcefDepA, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcefDepA, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.accuracy, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.flags, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.n_sats, 6)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.n_sats, "
           "expected 6, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.tow, 407180800)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.tow, expected "
           "407180800, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.x, -6231)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.x, expected "
           "-6231, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.y, -12185)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.y, expected "
           "-12185, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.z, 7420)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.z, expected "
           "7420, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  2,   2,   195, 4,   20, 100, 22, 69, 24, 30, 224, 255, 255,
        192, 183, 255, 255, 239, 53, 0,   0,  0,  0,  6,  0,   225, 15,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef_dep_a.accuracy = 0;

    test_msg.baseline_ecef_dep_a.flags = 0;

    test_msg.baseline_ecef_dep_a.n_sats = 6;

    test_msg.baseline_ecef_dep_a.tow = 407180900;

    test_msg.baseline_ecef_dep_a.x = -8162;

    test_msg.baseline_ecef_dep_a.y = -18496;

    test_msg.baseline_ecef_dep_a.z = 13807;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcefDepA, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcefDepA, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.accuracy, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.flags, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.n_sats, 6)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.n_sats, "
           "expected 6, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.tow, 407180900)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.tow, expected "
           "407180900, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.x, -8162)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.x, expected "
           "-8162, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.y, -18496)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.y, expected "
           "-18496, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.z, 13807)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.z, expected "
           "13807, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  2,   2,   195, 4,   20, 200, 22, 69, 24, 28, 224, 255, 255,
        191, 183, 255, 255, 242, 53, 0,   0,  0,  0,  6,  0,   35,  100,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef_dep_a.accuracy = 0;

    test_msg.baseline_ecef_dep_a.flags = 0;

    test_msg.baseline_ecef_dep_a.n_sats = 6;

    test_msg.baseline_ecef_dep_a.tow = 407181000;

    test_msg.baseline_ecef_dep_a.x = -8164;

    test_msg.baseline_ecef_dep_a.y = -18497;

    test_msg.baseline_ecef_dep_a.z = 13810;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcefDepA, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcefDepA, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.accuracy, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.flags, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.n_sats, 6)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.n_sats, "
           "expected 6, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.tow, 407181000)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.tow, expected "
           "407181000, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.x, -8164)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.x, expected "
           "-8164, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.y, -18497)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.y, expected "
           "-18497, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.z, 13810)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.z, expected "
           "13810, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 2,   2,   195, 4,   20, 44, 23, 69, 24, 24, 227, 255, 255,
        25, 195, 255, 255, 153, 59, 0,  0,  0,  0,  6,  0,   66,  66,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef_dep_a.accuracy = 0;

    test_msg.baseline_ecef_dep_a.flags = 0;

    test_msg.baseline_ecef_dep_a.n_sats = 6;

    test_msg.baseline_ecef_dep_a.tow = 407181100;

    test_msg.baseline_ecef_dep_a.x = -7400;

    test_msg.baseline_ecef_dep_a.y = -15591;

    test_msg.baseline_ecef_dep_a.z = 15257;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcefDepA, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcefDepA, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.accuracy, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.flags, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.n_sats, 6)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.n_sats, "
           "expected 6, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.tow, 407181100)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.tow, expected "
           "407181100, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.x, -7400)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.x, expected "
           "-7400, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.y, -15591)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.y, expected "
           "-15591, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.z, 15257)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.z, expected "
           "15257, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.z;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcefDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 2,   2,   195, 4,   20, 144, 23, 69, 24, 23, 227, 255, 255,
        25, 195, 255, 255, 153, 59, 0,   0,  0,  0,  6,  0,   35,  135,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef_dep_a.accuracy = 0;

    test_msg.baseline_ecef_dep_a.flags = 0;

    test_msg.baseline_ecef_dep_a.n_sats = 6;

    test_msg.baseline_ecef_dep_a.tow = 407181200;

    test_msg.baseline_ecef_dep_a.x = -7401;

    test_msg.baseline_ecef_dep_a.y = -15591;

    test_msg.baseline_ecef_dep_a.z = 15257;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcefDepA, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcefDepA, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.accuracy, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.flags, "
           "expected 0, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.n_sats, 6)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.n_sats, "
           "expected 6, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.tow, 407181200)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.tow, expected "
           "407181200, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.x, -7401)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.x, expected "
           "-7401, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.y, -15591)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.y, expected "
           "-15591, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef_dep_a.z, 15257)
        << "incorrect value for last_msg.msg.baseline_ecef_dep_a.z, expected "
           "15257, is "
        << (int64_t)last_msg.msg.baseline_ecef_dep_a.z;
  }
}

}  // namespace
