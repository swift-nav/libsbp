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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEF.yaml by generate.py.
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

TEST(auto_check_sbp_navigation_MsgPosECEF,
     test_auto_check_sbp_navigation_MsgPosECEF) {
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

    sbp_callback_register(&sbp_state, SbpMsgPosEcef, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  9,   2,  211, 136, 32,  16, 248, 122, 19,  73, 29,  46, 132,
        182, 122, 68, 193, 219, 192, 29, 176, 121, 119, 80, 193, 83, 11,
        210, 90,  79, 75,  77,  65,  0,  0,   15,  2,   84, 6,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef.accuracy = 0;

    test_msg.pos_ecef.flags = 2;

    test_msg.pos_ecef.n_sats = 15;

    test_msg.pos_ecef.tow = 326826000;

    test_msg.pos_ecef.x = -2684269.0326572997;

    test_msg.pos_ecef.y = -4316646.751816;

    test_msg.pos_ecef.z = 3839646.7095350414;

    sbp_message_send(&sbp_state, SbpMsgPosEcef, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosEcef, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.pos_ecef.accuracy, 0)
        << "incorrect value for last_msg.msg.pos_ecef.accuracy, expected 0, is "
        << (int64_t)last_msg.msg.pos_ecef.accuracy;

    EXPECT_EQ(last_msg.msg.pos_ecef.flags, 2)
        << "incorrect value for last_msg.msg.pos_ecef.flags, expected 2, is "
        << (int64_t)last_msg.msg.pos_ecef.flags;

    EXPECT_EQ(last_msg.msg.pos_ecef.n_sats, 15)
        << "incorrect value for last_msg.msg.pos_ecef.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.pos_ecef.n_sats;

    EXPECT_EQ(last_msg.msg.pos_ecef.tow, 326826000)
        << "incorrect value for last_msg.msg.pos_ecef.tow, expected 326826000, "
           "is "
        << (int64_t)last_msg.msg.pos_ecef.tow;

    EXPECT_LE((last_msg.msg.pos_ecef.x * 100 - -2684269.03266 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef.x, expected "
           "-2684269.03266, is "
        << last_msg.msg.pos_ecef.x;

    EXPECT_LE((last_msg.msg.pos_ecef.y * 100 - -4316646.75182 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef.y, expected "
           "-4316646.75182, is "
        << last_msg.msg.pos_ecef.y;

    EXPECT_LE((last_msg.msg.pos_ecef.z * 100 - 3839646.70954 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef.z, expected "
           "3839646.70954, is "
        << last_msg.msg.pos_ecef.z;
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

    sbp_callback_register(&sbp_state, SbpMsgPosEcef, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  9,   2,  211, 136, 32,  248, 251, 122, 19,  103, 106, 57,  136,
        182, 122, 68, 193, 176, 242, 200, 176, 121, 119, 80,  193, 244, 135,
        97,  59,  79, 75,  77,  65,  0,   0,   15,  2,   147, 216,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef.accuracy = 0;

    test_msg.pos_ecef.flags = 2;

    test_msg.pos_ecef.n_sats = 15;

    test_msg.pos_ecef.tow = 326827000;

    test_msg.pos_ecef.x = -2684269.064252186;

    test_msg.pos_ecef.y = -4316646.762264892;

    test_msg.pos_ecef.z = 3839646.463913912;

    sbp_message_send(&sbp_state, SbpMsgPosEcef, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosEcef, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.pos_ecef.accuracy, 0)
        << "incorrect value for last_msg.msg.pos_ecef.accuracy, expected 0, is "
        << (int64_t)last_msg.msg.pos_ecef.accuracy;

    EXPECT_EQ(last_msg.msg.pos_ecef.flags, 2)
        << "incorrect value for last_msg.msg.pos_ecef.flags, expected 2, is "
        << (int64_t)last_msg.msg.pos_ecef.flags;

    EXPECT_EQ(last_msg.msg.pos_ecef.n_sats, 15)
        << "incorrect value for last_msg.msg.pos_ecef.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.pos_ecef.n_sats;

    EXPECT_EQ(last_msg.msg.pos_ecef.tow, 326827000)
        << "incorrect value for last_msg.msg.pos_ecef.tow, expected 326827000, "
           "is "
        << (int64_t)last_msg.msg.pos_ecef.tow;

    EXPECT_LE((last_msg.msg.pos_ecef.x * 100 - -2684269.06425 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef.x, expected "
           "-2684269.06425, is "
        << last_msg.msg.pos_ecef.x;

    EXPECT_LE((last_msg.msg.pos_ecef.y * 100 - -4316646.76226 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef.y, expected "
           "-4316646.76226, is "
        << last_msg.msg.pos_ecef.y;

    EXPECT_LE((last_msg.msg.pos_ecef.z * 100 - 3839646.46391 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef.z, expected "
           "3839646.46391, is "
        << last_msg.msg.pos_ecef.z;
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

    sbp_callback_register(&sbp_state, SbpMsgPosEcef, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  9,   2,  211, 136, 32,  224, 255, 122, 19,  101, 179, 242, 182,
        182, 122, 68, 193, 130, 196, 145, 199, 121, 119, 80,  193, 212, 10,
        253, 15,  79, 75,  77,  65,  0,   0,   15,  2,   40,  201,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef.accuracy = 0;

    test_msg.pos_ecef.flags = 2;

    test_msg.pos_ecef.n_sats = 15;

    test_msg.pos_ecef.tow = 326828000;

    test_msg.pos_ecef.x = -2684269.4292816394;

    test_msg.pos_ecef.y = -4316647.118271949;

    test_msg.pos_ecef.z = 3839646.124909738;

    sbp_message_send(&sbp_state, SbpMsgPosEcef, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosEcef, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.pos_ecef.accuracy, 0)
        << "incorrect value for last_msg.msg.pos_ecef.accuracy, expected 0, is "
        << (int64_t)last_msg.msg.pos_ecef.accuracy;

    EXPECT_EQ(last_msg.msg.pos_ecef.flags, 2)
        << "incorrect value for last_msg.msg.pos_ecef.flags, expected 2, is "
        << (int64_t)last_msg.msg.pos_ecef.flags;

    EXPECT_EQ(last_msg.msg.pos_ecef.n_sats, 15)
        << "incorrect value for last_msg.msg.pos_ecef.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.pos_ecef.n_sats;

    EXPECT_EQ(last_msg.msg.pos_ecef.tow, 326828000)
        << "incorrect value for last_msg.msg.pos_ecef.tow, expected 326828000, "
           "is "
        << (int64_t)last_msg.msg.pos_ecef.tow;

    EXPECT_LE((last_msg.msg.pos_ecef.x * 100 - -2684269.42928 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef.x, expected "
           "-2684269.42928, is "
        << last_msg.msg.pos_ecef.x;

    EXPECT_LE((last_msg.msg.pos_ecef.y * 100 - -4316647.11827 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef.y, expected "
           "-4316647.11827, is "
        << last_msg.msg.pos_ecef.y;

    EXPECT_LE((last_msg.msg.pos_ecef.z * 100 - 3839646.12491 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef.z, expected "
           "3839646.12491, is "
        << last_msg.msg.pos_ecef.z;
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

    sbp_callback_register(&sbp_state, SbpMsgPosEcef, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  9,   2,  211, 136, 32, 200, 3,   123, 19,  146, 214, 132, 215,
        182, 122, 68, 193, 213, 68, 49,  215, 121, 119, 80,  193, 71,  34,
        110, 243, 78, 75,  77,  65, 0,   0,   15,  2,   187, 86,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef.accuracy = 0;

    test_msg.pos_ecef.flags = 2;

    test_msg.pos_ecef.n_sats = 15;

    test_msg.pos_ecef.tow = 326829000;

    test_msg.pos_ecef.x = -2684269.683741399;

    test_msg.pos_ecef.y = -4316647.3623821335;

    test_msg.pos_ecef.z = 3839645.90179852;

    sbp_message_send(&sbp_state, SbpMsgPosEcef, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosEcef, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.pos_ecef.accuracy, 0)
        << "incorrect value for last_msg.msg.pos_ecef.accuracy, expected 0, is "
        << (int64_t)last_msg.msg.pos_ecef.accuracy;

    EXPECT_EQ(last_msg.msg.pos_ecef.flags, 2)
        << "incorrect value for last_msg.msg.pos_ecef.flags, expected 2, is "
        << (int64_t)last_msg.msg.pos_ecef.flags;

    EXPECT_EQ(last_msg.msg.pos_ecef.n_sats, 15)
        << "incorrect value for last_msg.msg.pos_ecef.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.pos_ecef.n_sats;

    EXPECT_EQ(last_msg.msg.pos_ecef.tow, 326829000)
        << "incorrect value for last_msg.msg.pos_ecef.tow, expected 326829000, "
           "is "
        << (int64_t)last_msg.msg.pos_ecef.tow;

    EXPECT_LE((last_msg.msg.pos_ecef.x * 100 - -2684269.68374 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef.x, expected "
           "-2684269.68374, is "
        << last_msg.msg.pos_ecef.x;

    EXPECT_LE((last_msg.msg.pos_ecef.y * 100 - -4316647.36238 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef.y, expected "
           "-4316647.36238, is "
        << last_msg.msg.pos_ecef.y;

    EXPECT_LE((last_msg.msg.pos_ecef.z * 100 - 3839645.9018 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_ecef.z, expected "
           "3839645.9018, is "
        << last_msg.msg.pos_ecef.z;
  }
}

}  // namespace
