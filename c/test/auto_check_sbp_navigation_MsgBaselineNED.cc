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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineNED.yaml by
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

TEST(auto_check_sbp_navigation_MsgBaselineNED,
     test_auto_check_sbp_navigation_MsgBaselineNED) {
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineNed, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 12,  2,   211, 136, 22, 40, 244, 122, 19, 201, 115, 12, 0,   179,
        88, 230, 255, 153, 125, 0,  0,  0,   0,   0,  0,   14,  0,  226, 70,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned.d = 32153;

    test_msg.baseline_ned.e = -1681229;

    test_msg.baseline_ned.flags = 0;

    test_msg.baseline_ned.h_accuracy = 0;

    test_msg.baseline_ned.n = 816073;

    test_msg.baseline_ned.n_sats = 14;

    test_msg.baseline_ned.tow = 326825000;

    test_msg.baseline_ned.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNed, 35027, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineNed, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ned.d, 32153)
        << "incorrect value for last_msg.msg.baseline_ned.d, expected 32153, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.d;

    EXPECT_EQ(last_msg.msg.baseline_ned.e, -1681229)
        << "incorrect value for last_msg.msg.baseline_ned.e, expected "
           "-1681229, is "
        << (int64_t)last_msg.msg.baseline_ned.e;

    EXPECT_EQ(last_msg.msg.baseline_ned.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ned.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.flags;

    EXPECT_EQ(last_msg.msg.baseline_ned.h_accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ned.h_accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ned.h_accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ned.n, 816073)
        << "incorrect value for last_msg.msg.baseline_ned.n, expected 816073, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.n;

    EXPECT_EQ(last_msg.msg.baseline_ned.n_sats, 14)
        << "incorrect value for last_msg.msg.baseline_ned.n_sats, expected 14, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ned.tow, 326825000)
        << "incorrect value for last_msg.msg.baseline_ned.tow, expected "
           "326825000, is "
        << (int64_t)last_msg.msg.baseline_ned.tow;

    EXPECT_EQ(last_msg.msg.baseline_ned.v_accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ned.v_accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ned.v_accuracy;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineNed, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 12,  2,   211, 136, 22, 16, 248, 122, 19, 98, 115, 12, 0,  194,
        88, 230, 255, 110, 127, 0,  0,  0,   0,   0,  0,  15,  0,  69, 93,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned.d = 32622;

    test_msg.baseline_ned.e = -1681214;

    test_msg.baseline_ned.flags = 0;

    test_msg.baseline_ned.h_accuracy = 0;

    test_msg.baseline_ned.n = 815970;

    test_msg.baseline_ned.n_sats = 15;

    test_msg.baseline_ned.tow = 326826000;

    test_msg.baseline_ned.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNed, 35027, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineNed, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ned.d, 32622)
        << "incorrect value for last_msg.msg.baseline_ned.d, expected 32622, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.d;

    EXPECT_EQ(last_msg.msg.baseline_ned.e, -1681214)
        << "incorrect value for last_msg.msg.baseline_ned.e, expected "
           "-1681214, is "
        << (int64_t)last_msg.msg.baseline_ned.e;

    EXPECT_EQ(last_msg.msg.baseline_ned.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ned.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.flags;

    EXPECT_EQ(last_msg.msg.baseline_ned.h_accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ned.h_accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ned.h_accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ned.n, 815970)
        << "incorrect value for last_msg.msg.baseline_ned.n, expected 815970, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.n;

    EXPECT_EQ(last_msg.msg.baseline_ned.n_sats, 15)
        << "incorrect value for last_msg.msg.baseline_ned.n_sats, expected 15, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ned.tow, 326826000)
        << "incorrect value for last_msg.msg.baseline_ned.tow, expected "
           "326826000, is "
        << (int64_t)last_msg.msg.baseline_ned.tow;

    EXPECT_EQ(last_msg.msg.baseline_ned.v_accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ned.v_accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ned.v_accuracy;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineNed, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 12,  2,   211, 136, 22, 248, 251, 122, 19, 143, 114, 12, 0,   173,
        88, 230, 255, 238, 127, 0,  0,   0,   0,   0,  0,   15,  0,  210, 169,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned.d = 32750;

    test_msg.baseline_ned.e = -1681235;

    test_msg.baseline_ned.flags = 0;

    test_msg.baseline_ned.h_accuracy = 0;

    test_msg.baseline_ned.n = 815759;

    test_msg.baseline_ned.n_sats = 15;

    test_msg.baseline_ned.tow = 326827000;

    test_msg.baseline_ned.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNed, 35027, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineNed, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ned.d, 32750)
        << "incorrect value for last_msg.msg.baseline_ned.d, expected 32750, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.d;

    EXPECT_EQ(last_msg.msg.baseline_ned.e, -1681235)
        << "incorrect value for last_msg.msg.baseline_ned.e, expected "
           "-1681235, is "
        << (int64_t)last_msg.msg.baseline_ned.e;

    EXPECT_EQ(last_msg.msg.baseline_ned.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ned.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.flags;

    EXPECT_EQ(last_msg.msg.baseline_ned.h_accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ned.h_accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ned.h_accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ned.n, 815759)
        << "incorrect value for last_msg.msg.baseline_ned.n, expected 815759, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.n;

    EXPECT_EQ(last_msg.msg.baseline_ned.n_sats, 15)
        << "incorrect value for last_msg.msg.baseline_ned.n_sats, expected 15, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ned.tow, 326827000)
        << "incorrect value for last_msg.msg.baseline_ned.tow, expected "
           "326827000, is "
        << (int64_t)last_msg.msg.baseline_ned.tow;

    EXPECT_EQ(last_msg.msg.baseline_ned.v_accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ned.v_accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ned.v_accuracy;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineNed, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 12,  2,   211, 136, 22, 224, 255, 122, 19, 86, 112, 12, 0,   51,
        88, 230, 255, 47,  127, 0,  0,   0,   0,   0,  0,  15,  0,  135, 107,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned.d = 32559;

    test_msg.baseline_ned.e = -1681357;

    test_msg.baseline_ned.flags = 0;

    test_msg.baseline_ned.h_accuracy = 0;

    test_msg.baseline_ned.n = 815190;

    test_msg.baseline_ned.n_sats = 15;

    test_msg.baseline_ned.tow = 326828000;

    test_msg.baseline_ned.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNed, 35027, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineNed, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ned.d, 32559)
        << "incorrect value for last_msg.msg.baseline_ned.d, expected 32559, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.d;

    EXPECT_EQ(last_msg.msg.baseline_ned.e, -1681357)
        << "incorrect value for last_msg.msg.baseline_ned.e, expected "
           "-1681357, is "
        << (int64_t)last_msg.msg.baseline_ned.e;

    EXPECT_EQ(last_msg.msg.baseline_ned.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ned.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.flags;

    EXPECT_EQ(last_msg.msg.baseline_ned.h_accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ned.h_accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ned.h_accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ned.n, 815190)
        << "incorrect value for last_msg.msg.baseline_ned.n, expected 815190, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.n;

    EXPECT_EQ(last_msg.msg.baseline_ned.n_sats, 15)
        << "incorrect value for last_msg.msg.baseline_ned.n_sats, expected 15, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ned.tow, 326828000)
        << "incorrect value for last_msg.msg.baseline_ned.tow, expected "
           "326828000, is "
        << (int64_t)last_msg.msg.baseline_ned.tow;

    EXPECT_EQ(last_msg.msg.baseline_ned.v_accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ned.v_accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ned.v_accuracy;
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

    sbp_callback_register(&sbp_state, SbpMsgBaselineNed, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 12,  2,   211, 136, 22, 200, 3, 123, 19, 214, 110, 12, 0,   220,
        87, 230, 255, 165, 126, 0,  0,   0, 0,   0,  0,   15,  0,  190, 80,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.baseline_ned.d = 32421;

    test_msg.baseline_ned.e = -1681444;

    test_msg.baseline_ned.flags = 0;

    test_msg.baseline_ned.h_accuracy = 0;

    test_msg.baseline_ned.n = 814806;

    test_msg.baseline_ned.n_sats = 15;

    test_msg.baseline_ned.tow = 326829000;

    test_msg.baseline_ned.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgBaselineNed, 35027, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgBaselineNed, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.baseline_ned.d, 32421)
        << "incorrect value for last_msg.msg.baseline_ned.d, expected 32421, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.d;

    EXPECT_EQ(last_msg.msg.baseline_ned.e, -1681444)
        << "incorrect value for last_msg.msg.baseline_ned.e, expected "
           "-1681444, is "
        << (int64_t)last_msg.msg.baseline_ned.e;

    EXPECT_EQ(last_msg.msg.baseline_ned.flags, 0)
        << "incorrect value for last_msg.msg.baseline_ned.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.flags;

    EXPECT_EQ(last_msg.msg.baseline_ned.h_accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ned.h_accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ned.h_accuracy;

    EXPECT_EQ(last_msg.msg.baseline_ned.n, 814806)
        << "incorrect value for last_msg.msg.baseline_ned.n, expected 814806, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.n;

    EXPECT_EQ(last_msg.msg.baseline_ned.n_sats, 15)
        << "incorrect value for last_msg.msg.baseline_ned.n_sats, expected 15, "
           "is "
        << (int64_t)last_msg.msg.baseline_ned.n_sats;

    EXPECT_EQ(last_msg.msg.baseline_ned.tow, 326829000)
        << "incorrect value for last_msg.msg.baseline_ned.tow, expected "
           "326829000, is "
        << (int64_t)last_msg.msg.baseline_ned.tow;

    EXPECT_EQ(last_msg.msg.baseline_ned.v_accuracy, 0)
        << "incorrect value for last_msg.msg.baseline_ned.v_accuracy, expected "
           "0, is "
        << (int64_t)last_msg.msg.baseline_ned.v_accuracy;
  }
}

}  // namespace
