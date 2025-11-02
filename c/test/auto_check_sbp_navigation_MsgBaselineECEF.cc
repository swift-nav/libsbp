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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEF.yaml by
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

TEST(auto_check_sbp_navigation_MsgBaselineECEF,
     test_auto_check_sbp_navigation_MsgBaselineECEF) {
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcef, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  11, 2,  211, 136, 20,  40, 244, 122, 19, 150, 98, 238, 255,
        190, 64, 20, 0,   246, 163, 9,  0,   0,   0,  14,  0,  219, 191,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef.accuracy = 0;

    test_msg.baseline_ecef.flags = 0;

    test_msg.baseline_ecef.n_sats = 14;

    test_msg.baseline_ecef.tow = 326825000;

    test_msg.baseline_ecef.x = -1154410;

    test_msg.baseline_ecef.y = 1327294;

    test_msg.baseline_ecef.z = 631798;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcef, 35027, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 35027)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcef, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ecef.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ecef.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.baseline_ecef.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef.n_sats, 14)
        << "incorrect value for last_msg.msg.baseline_ecef.n_sats, expected "
           "14, is "
        << (int64_t)last_msg.msg.baseline_ecef.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef.tow, 326825000)
        << "incorrect value for last_msg.msg.baseline_ecef.tow, expected "
           "326825000, is "
        << (int64_t)last_msg.msg.baseline_ecef.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef.x, -1154410)
        << "incorrect value for last_msg.msg.baseline_ecef.x, expected "
           "-1154410, is "
        << (int64_t)last_msg.msg.baseline_ecef.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef.y, 1327294)
        << "incorrect value for last_msg.msg.baseline_ecef.y, expected "
           "1327294, is "
        << (int64_t)last_msg.msg.baseline_ecef.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef.z, 631798)
        << "incorrect value for last_msg.msg.baseline_ecef.z, expected 631798, "
           "is "
        << (int64_t)last_msg.msg.baseline_ecef.z;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcef, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  11, 2,  211, 136, 20,  16, 248, 122, 19, 72, 99, 238, 255,
        191, 65, 20, 0,   138, 162, 9,  0,   0,   0,  15, 0,  240, 78,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef.accuracy = 0;

    test_msg.baseline_ecef.flags = 0;

    test_msg.baseline_ecef.n_sats = 15;

    test_msg.baseline_ecef.tow = 326826000;

    test_msg.baseline_ecef.x = -1154232;

    test_msg.baseline_ecef.y = 1327551;

    test_msg.baseline_ecef.z = 631434;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcef, 35027, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 35027)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcef, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ecef.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ecef.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.baseline_ecef.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef.n_sats, 15)
        << "incorrect value for last_msg.msg.baseline_ecef.n_sats, expected "
           "15, is "
        << (int64_t)last_msg.msg.baseline_ecef.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef.tow, 326826000)
        << "incorrect value for last_msg.msg.baseline_ecef.tow, expected "
           "326826000, is "
        << (int64_t)last_msg.msg.baseline_ecef.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef.x, -1154232)
        << "incorrect value for last_msg.msg.baseline_ecef.x, expected "
           "-1154232, is "
        << (int64_t)last_msg.msg.baseline_ecef.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef.y, 1327551)
        << "incorrect value for last_msg.msg.baseline_ecef.y, expected "
           "1327551, is "
        << (int64_t)last_msg.msg.baseline_ecef.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef.z, 631434)
        << "incorrect value for last_msg.msg.baseline_ecef.z, expected 631434, "
           "is "
        << (int64_t)last_msg.msg.baseline_ecef.z;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcef, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  11, 2,  211, 136, 20,  248, 251, 122, 19, 41, 99, 238, 255,
        181, 65, 20, 0,   148, 161, 9,   0,   0,   0,  15, 0,  4,   132,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef.accuracy = 0;

    test_msg.baseline_ecef.flags = 0;

    test_msg.baseline_ecef.n_sats = 15;

    test_msg.baseline_ecef.tow = 326827000;

    test_msg.baseline_ecef.x = -1154263;

    test_msg.baseline_ecef.y = 1327541;

    test_msg.baseline_ecef.z = 631188;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcef, 35027, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 35027)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcef, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ecef.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ecef.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.baseline_ecef.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef.n_sats, 15)
        << "incorrect value for last_msg.msg.baseline_ecef.n_sats, expected "
           "15, is "
        << (int64_t)last_msg.msg.baseline_ecef.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef.tow, 326827000)
        << "incorrect value for last_msg.msg.baseline_ecef.tow, expected "
           "326827000, is "
        << (int64_t)last_msg.msg.baseline_ecef.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef.x, -1154263)
        << "incorrect value for last_msg.msg.baseline_ecef.x, expected "
           "-1154263, is "
        << (int64_t)last_msg.msg.baseline_ecef.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef.y, 1327541)
        << "incorrect value for last_msg.msg.baseline_ecef.y, expected "
           "1327541, is "
        << (int64_t)last_msg.msg.baseline_ecef.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef.z, 631188)
        << "incorrect value for last_msg.msg.baseline_ecef.z, expected 631188, "
           "is "
        << (int64_t)last_msg.msg.baseline_ecef.z;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcef, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 11, 2,  211, 136, 20,  224, 255, 122, 19, 188, 97, 238, 255,
        81, 64, 20, 0,   65,  160, 9,   0,   0,   0,  15,  0,  67,  94,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef.accuracy = 0;

    test_msg.baseline_ecef.flags = 0;

    test_msg.baseline_ecef.n_sats = 15;

    test_msg.baseline_ecef.tow = 326828000;

    test_msg.baseline_ecef.x = -1154628;

    test_msg.baseline_ecef.y = 1327185;

    test_msg.baseline_ecef.z = 630849;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcef, 35027, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 35027)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcef, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ecef.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ecef.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.baseline_ecef.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef.n_sats, 15)
        << "incorrect value for last_msg.msg.baseline_ecef.n_sats, expected "
           "15, is "
        << (int64_t)last_msg.msg.baseline_ecef.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef.tow, 326828000)
        << "incorrect value for last_msg.msg.baseline_ecef.tow, expected "
           "326828000, is "
        << (int64_t)last_msg.msg.baseline_ecef.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef.x, -1154628)
        << "incorrect value for last_msg.msg.baseline_ecef.x, expected "
           "-1154628, is "
        << (int64_t)last_msg.msg.baseline_ecef.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef.y, 1327185)
        << "incorrect value for last_msg.msg.baseline_ecef.y, expected "
           "1327185, is "
        << (int64_t)last_msg.msg.baseline_ecef.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef.z, 630849)
        << "incorrect value for last_msg.msg.baseline_ecef.z, expected 630849, "
           "is "
        << (int64_t)last_msg.msg.baseline_ecef.z;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineEcef, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 11, 2,  211, 136, 20,  200, 3, 123, 19, 189, 96, 238, 255,
        93, 63, 20, 0,   98,  159, 9,   0, 0,   0,  15,  0,  106, 94,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ecef.accuracy = 0;

    test_msg.baseline_ecef.flags = 0;

    test_msg.baseline_ecef.n_sats = 15;

    test_msg.baseline_ecef.tow = 326829000;

    test_msg.baseline_ecef.x = -1154883;

    test_msg.baseline_ecef.y = 1326941;

    test_msg.baseline_ecef.z = 630626;

    sbp_message_send(&sbp_state, SbpMsgBaselineEcef, 35027, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 35027)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineEcef, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ecef.accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ecef.accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ecef.accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ecef.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ecef.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.baseline_ecef.flags;

    EXPECT_EQ(last_msg.msg.baseline_ecef.n_sats, 15)
        << "incorrect value for last_msg.msg.baseline_ecef.n_sats, expected "
           "15, is "
        << (int64_t)last_msg.msg.baseline_ecef.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ecef.tow, 326829000)
        << "incorrect value for last_msg.msg.baseline_ecef.tow, expected "
           "326829000, is "
        << (int64_t)last_msg.msg.baseline_ecef.tow;

    EXPECT_EQ(last_msg.msg.baseline_ecef.x, -1154883)
        << "incorrect value for last_msg.msg.baseline_ecef.x, expected "
           "-1154883, is "
        << (int64_t)last_msg.msg.baseline_ecef.x;

    EXPECT_EQ(last_msg.msg.baseline_ecef.y, 1326941)
        << "incorrect value for last_msg.msg.baseline_ecef.y, expected "
           "1326941, is "
        << (int64_t)last_msg.msg.baseline_ecef.y;

    EXPECT_EQ(last_msg.msg.baseline_ecef.z, 630626)
        << "incorrect value for last_msg.msg.baseline_ecef.z, expected 630626, "
           "is "
        << (int64_t)last_msg.msg.baseline_ecef.z;
  }
}

}  // namespace
