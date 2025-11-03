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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevelDepA.yaml by
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

TEST(auto_check_sbp_navigation_MsgProtectionLevelDepA,
     test_auto_check_sbp_navigation_MsgProtectionLevelDepA) {
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

    sbp_callback_register(&sbp_state, SbpMsgProtectionLevelDepA,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  22, 2,   148, 22,  33,  52,  126, 69,  185, 47,  85,  4,   139,
        51,  51, 51,  51,  51,  244, 190, 64,  102, 102, 102, 102, 102, 204,
        168, 64, 154, 153, 153, 153, 25,  39,  192, 64,  248, 81,  104,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.protection_level_dep_a.flags = 248;

    test_msg.protection_level_dep_a.height = 8270.2;

    test_msg.protection_level_dep_a.hpl = 35588;

    test_msg.protection_level_dep_a.lat = 7924.2;

    test_msg.protection_level_dep_a.lon = 3174.2;

    test_msg.protection_level_dep_a.tow = 3108339252;

    test_msg.protection_level_dep_a.vpl = 21807;

    sbp_message_send(&sbp_state, SbpMsgProtectionLevelDepA, 5780, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 5780)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgProtectionLevelDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.protection_level_dep_a.flags, 248)
        << "incorrect value for last_msg.msg.protection_level_dep_a.flags, "
           "expected 248, is "
        << (int64_t)last_msg.msg.protection_level_dep_a.flags;

    EXPECT_LE((last_msg.msg.protection_level_dep_a.height * 100 - 8270.2 * 100),
              0.05)
        << "incorrect value for last_msg.msg.protection_level_dep_a.height, "
           "expected 8270.2, is "
        << last_msg.msg.protection_level_dep_a.height;

    EXPECT_EQ(last_msg.msg.protection_level_dep_a.hpl, 35588)
        << "incorrect value for last_msg.msg.protection_level_dep_a.hpl, "
           "expected 35588, is "
        << (int64_t)last_msg.msg.protection_level_dep_a.hpl;

    EXPECT_LE((last_msg.msg.protection_level_dep_a.lat * 100 - 7924.2 * 100),
              0.05)
        << "incorrect value for last_msg.msg.protection_level_dep_a.lat, "
           "expected 7924.2, is "
        << last_msg.msg.protection_level_dep_a.lat;

    EXPECT_LE((last_msg.msg.protection_level_dep_a.lon * 100 - 3174.2 * 100),
              0.05)
        << "incorrect value for last_msg.msg.protection_level_dep_a.lon, "
           "expected 3174.2, is "
        << last_msg.msg.protection_level_dep_a.lon;

    EXPECT_EQ(last_msg.msg.protection_level_dep_a.tow, 3108339252)
        << "incorrect value for last_msg.msg.protection_level_dep_a.tow, "
           "expected 3108339252, is "
        << (int64_t)last_msg.msg.protection_level_dep_a.tow;

    EXPECT_EQ(last_msg.msg.protection_level_dep_a.vpl, 21807)
        << "incorrect value for last_msg.msg.protection_level_dep_a.vpl, "
           "expected 21807, is "
        << (int64_t)last_msg.msg.protection_level_dep_a.vpl;
  }
}

}  // namespace
