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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCovGNSS.yaml by
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

TEST(auto_check_sbp_navigation_MsgPosECEFCovGNSS,
     test_auto_check_sbp_navigation_MsgPosECEFCovGNSS) {
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

    sbp_callback_register(&sbp_state, SbpMsgPosEcefCovGnss, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  52,  2,   0,   16,  54,  24,  229, 233, 29,  52, 254, 158,
        218, 42,  142, 68,  193, 69,  162, 89,  91,  34,  68, 80,  193,
        131, 21,  176, 129, 239, 174, 77,  65,  158, 232, 30, 60,  218,
        221, 20,  60,  129, 136, 198, 187, 205, 120, 166, 60, 5,   166,
        35,  188, 122, 177, 115, 60,  18,  4,   159, 102,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_ecef_cov_gnss.cov_x_x = 0.009699014946818352;

    test_msg.pos_ecef_cov_gnss.cov_x_y = 0.009086096659302711;

    test_msg.pos_ecef_cov_gnss.cov_x_z = -0.006058753002434969;

    test_msg.pos_ecef_cov_gnss.cov_y_y = 0.020321274176239967;

    test_msg.pos_ecef_cov_gnss.cov_y_z = -0.009988312609493732;

    test_msg.pos_ecef_cov_gnss.cov_z_z = 0.01487385667860508;

    test_msg.pos_ecef_cov_gnss.flags = 4;

    test_msg.pos_ecef_cov_gnss.n_sats = 18;

    test_msg.pos_ecef_cov_gnss.tow = 501867800;

    test_msg.pos_ecef_cov_gnss.x = -2694229.7079770807;

    test_msg.pos_ecef_cov_gnss.y = -4264073.427345817;

    test_msg.pos_ecef_cov_gnss.z = 3890655.013186158;

    sbp_message_send(&sbp_state, SbpMsgPosEcefCovGnss, 4096, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 4096)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosEcefCovGnss, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE(
        (last_msg.msg.pos_ecef_cov_gnss.cov_x_x * 100 - 0.00969901494682 * 100),
        0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov_gnss.cov_x_x, "
           "expected 0.00969901494682, is "
        << last_msg.msg.pos_ecef_cov_gnss.cov_x_x;

    EXPECT_LE(
        (last_msg.msg.pos_ecef_cov_gnss.cov_x_y * 100 - 0.0090860966593 * 100),
        0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov_gnss.cov_x_y, "
           "expected 0.0090860966593, is "
        << last_msg.msg.pos_ecef_cov_gnss.cov_x_y;

    EXPECT_LE((last_msg.msg.pos_ecef_cov_gnss.cov_x_z * 100 -
               -0.00605875300243 * 100),
              0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov_gnss.cov_x_z, "
           "expected -0.00605875300243, is "
        << last_msg.msg.pos_ecef_cov_gnss.cov_x_z;

    EXPECT_LE(
        (last_msg.msg.pos_ecef_cov_gnss.cov_y_y * 100 - 0.0203212741762 * 100),
        0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov_gnss.cov_y_y, "
           "expected 0.0203212741762, is "
        << last_msg.msg.pos_ecef_cov_gnss.cov_y_y;

    EXPECT_LE((last_msg.msg.pos_ecef_cov_gnss.cov_y_z * 100 -
               -0.00998831260949 * 100),
              0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov_gnss.cov_y_z, "
           "expected -0.00998831260949, is "
        << last_msg.msg.pos_ecef_cov_gnss.cov_y_z;

    EXPECT_LE(
        (last_msg.msg.pos_ecef_cov_gnss.cov_z_z * 100 - 0.0148738566786 * 100),
        0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov_gnss.cov_z_z, "
           "expected 0.0148738566786, is "
        << last_msg.msg.pos_ecef_cov_gnss.cov_z_z;

    EXPECT_EQ(last_msg.msg.pos_ecef_cov_gnss.flags, 4)
        << "incorrect value for last_msg.msg.pos_ecef_cov_gnss.flags, expected "
           "4, is "
        << (int64_t)last_msg.msg.pos_ecef_cov_gnss.flags;

    EXPECT_EQ(last_msg.msg.pos_ecef_cov_gnss.n_sats, 18)
        << "incorrect value for last_msg.msg.pos_ecef_cov_gnss.n_sats, "
           "expected 18, is "
        << (int64_t)last_msg.msg.pos_ecef_cov_gnss.n_sats;

    EXPECT_EQ(last_msg.msg.pos_ecef_cov_gnss.tow, 501867800)
        << "incorrect value for last_msg.msg.pos_ecef_cov_gnss.tow, expected "
           "501867800, is "
        << (int64_t)last_msg.msg.pos_ecef_cov_gnss.tow;

    EXPECT_LE((last_msg.msg.pos_ecef_cov_gnss.x * 100 - -2694229.70798 * 100),
              0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov_gnss.x, expected "
           "-2694229.70798, is "
        << last_msg.msg.pos_ecef_cov_gnss.x;

    EXPECT_LE((last_msg.msg.pos_ecef_cov_gnss.y * 100 - -4264073.42735 * 100),
              0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov_gnss.y, expected "
           "-4264073.42735, is "
        << last_msg.msg.pos_ecef_cov_gnss.y;

    EXPECT_LE((last_msg.msg.pos_ecef_cov_gnss.z * 100 - 3890655.01319 * 100),
              0.05)
        << "incorrect value for last_msg.msg.pos_ecef_cov_gnss.z, expected "
           "3890655.01319, is "
        << last_msg.msg.pos_ecef_cov_gnss.z;
  }
}

}  // namespace
