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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhAcc.yaml by
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

TEST(auto_check_sbp_navigation_MsgPosLlhAcc,
     test_auto_check_sbp_navigation_MsgPosLlhAcc) {
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

    sbp_callback_register(&sbp_state, SbpMsgPosLlhAcc, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  24,  2,   2,   28,  67,  39,  120, 110, 18,  51,  51,  51,
        51,  51,  139, 189, 64,  154, 153, 153, 153, 25,  151, 192, 64,
        51,  51,  51,  51,  51,  161, 176, 64,  51,  51,  51,  51,  51,
        101, 179, 64,  51,  163, 22,  69,  154, 25,  173, 69,  102, 134,
        243, 68,  154, 201, 196, 69,  205, 224, 0,   70,  51,  35,  72,
        69,  51,  99,  31,  69,  95,  27,  72,  220, 177,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh_acc.at_accuracy = 6297.2001953125;

    test_msg.pos_llh_acc.confidence_and_geoid = 95;

    test_msg.pos_llh_acc.ct_accuracy = 1948.199951171875;

    test_msg.pos_llh_acc.flags = 72;

    test_msg.pos_llh_acc.h_accuracy = 2410.199951171875;

    test_msg.pos_llh_acc.h_ellipse.orientation = 2550.199951171875;

    test_msg.pos_llh_acc.h_ellipse.semi_major = 8248.2001953125;

    test_msg.pos_llh_acc.h_ellipse.semi_minor = 3202.199951171875;

    test_msg.pos_llh_acc.height = 4257.2;

    test_msg.pos_llh_acc.lat = 7563.2;

    test_msg.pos_llh_acc.lon = 8494.2;

    test_msg.pos_llh_acc.n_sats = 27;

    test_msg.pos_llh_acc.orthometric_height = 4965.2;

    test_msg.pos_llh_acc.tow = 309229607;

    test_msg.pos_llh_acc.v_accuracy = 5539.2001953125;

    sbp_message_send(&sbp_state, SbpMsgPosLlhAcc, 7170, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 7170)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlhAcc, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE(
        (last_msg.msg.pos_llh_acc.at_accuracy * 100 - 6297.20019531 * 100),
        0.05)
        << "incorrect value for last_msg.msg.pos_llh_acc.at_accuracy, expected "
           "6297.20019531, is "
        << last_msg.msg.pos_llh_acc.at_accuracy;

    EXPECT_EQ(last_msg.msg.pos_llh_acc.confidence_and_geoid, 95)
        << "incorrect value for last_msg.msg.pos_llh_acc.confidence_and_geoid, "
           "expected 95, is "
        << (int64_t)last_msg.msg.pos_llh_acc.confidence_and_geoid;

    EXPECT_LE(
        (last_msg.msg.pos_llh_acc.ct_accuracy * 100 - 1948.19995117 * 100),
        0.05)
        << "incorrect value for last_msg.msg.pos_llh_acc.ct_accuracy, expected "
           "1948.19995117, is "
        << last_msg.msg.pos_llh_acc.ct_accuracy;

    EXPECT_EQ(last_msg.msg.pos_llh_acc.flags, 72)
        << "incorrect value for last_msg.msg.pos_llh_acc.flags, expected 72, "
           "is "
        << (int64_t)last_msg.msg.pos_llh_acc.flags;

    EXPECT_LE((last_msg.msg.pos_llh_acc.h_accuracy * 100 - 2410.19995117 * 100),
              0.05)
        << "incorrect value for last_msg.msg.pos_llh_acc.h_accuracy, expected "
           "2410.19995117, is "
        << last_msg.msg.pos_llh_acc.h_accuracy;

    EXPECT_LE((last_msg.msg.pos_llh_acc.h_ellipse.orientation * 100 -
               2550.19995117 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.pos_llh_acc.h_ellipse.orientation, expected "
           "2550.19995117, is "
        << last_msg.msg.pos_llh_acc.h_ellipse.orientation;

    EXPECT_LE((last_msg.msg.pos_llh_acc.h_ellipse.semi_major * 100 -
               8248.20019531 * 100),
              0.05)
        << "incorrect value for last_msg.msg.pos_llh_acc.h_ellipse.semi_major, "
           "expected 8248.20019531, is "
        << last_msg.msg.pos_llh_acc.h_ellipse.semi_major;

    EXPECT_LE((last_msg.msg.pos_llh_acc.h_ellipse.semi_minor * 100 -
               3202.19995117 * 100),
              0.05)
        << "incorrect value for last_msg.msg.pos_llh_acc.h_ellipse.semi_minor, "
           "expected 3202.19995117, is "
        << last_msg.msg.pos_llh_acc.h_ellipse.semi_minor;

    EXPECT_LE((last_msg.msg.pos_llh_acc.height * 100 - 4257.2 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh_acc.height, expected "
           "4257.2, is "
        << last_msg.msg.pos_llh_acc.height;

    EXPECT_LE((last_msg.msg.pos_llh_acc.lat * 100 - 7563.2 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh_acc.lat, expected 7563.2, "
           "is "
        << last_msg.msg.pos_llh_acc.lat;

    EXPECT_LE((last_msg.msg.pos_llh_acc.lon * 100 - 8494.2 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh_acc.lon, expected 8494.2, "
           "is "
        << last_msg.msg.pos_llh_acc.lon;

    EXPECT_EQ(last_msg.msg.pos_llh_acc.n_sats, 27)
        << "incorrect value for last_msg.msg.pos_llh_acc.n_sats, expected 27, "
           "is "
        << (int64_t)last_msg.msg.pos_llh_acc.n_sats;

    EXPECT_LE(
        (last_msg.msg.pos_llh_acc.orthometric_height * 100 - 4965.2 * 100),
        0.05)
        << "incorrect value for last_msg.msg.pos_llh_acc.orthometric_height, "
           "expected 4965.2, is "
        << last_msg.msg.pos_llh_acc.orthometric_height;

    EXPECT_EQ(last_msg.msg.pos_llh_acc.tow, 309229607)
        << "incorrect value for last_msg.msg.pos_llh_acc.tow, expected "
           "309229607, is "
        << (int64_t)last_msg.msg.pos_llh_acc.tow;

    EXPECT_LE((last_msg.msg.pos_llh_acc.v_accuracy * 100 - 5539.20019531 * 100),
              0.05)
        << "incorrect value for last_msg.msg.pos_llh_acc.v_accuracy, expected "
           "5539.20019531, is "
        << last_msg.msg.pos_llh_acc.v_accuracy;
  }
}

}  // namespace
