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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLHCov.yaml by
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

TEST(auto_check_sbp_navigation_MsgPosLLHCov,
     test_auto_check_sbp_navigation_MsgPosLLHCov) {
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

    sbp_callback_register(&sbp_state, SbpMsgPosLlhCov, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  17, 2, 66, 0,   54, 7, 0, 0,   0,  0, 0, 0,   0,  0, 0,
        0,   0,  0, 0,  0,   0,  0, 0, 28,  64, 0, 0, 0,   0,  0, 0,
        0,   0,  0, 0,  224, 64, 0, 0, 160, 64, 0, 0, 0,   65, 0, 0,
        192, 64, 0, 0,  128, 63, 0, 0, 0,   64, 5, 5, 151, 98,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh_cov.cov_d_d = 2.0;

    test_msg.pos_llh_cov.cov_e_d = 1.0;

    test_msg.pos_llh_cov.cov_e_e = 6.0;

    test_msg.pos_llh_cov.cov_n_d = 8.0;

    test_msg.pos_llh_cov.cov_n_e = 5.0;

    test_msg.pos_llh_cov.cov_n_n = 7.0;

    test_msg.pos_llh_cov.flags = 5;

    test_msg.pos_llh_cov.height = 0.0;

    test_msg.pos_llh_cov.lat = 0.0;

    test_msg.pos_llh_cov.lon = 7.0;

    test_msg.pos_llh_cov.n_sats = 5;

    test_msg.pos_llh_cov.tow = 7;

    sbp_message_send(&sbp_state, SbpMsgPosLlhCov, 66, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 66)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlhCov, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.pos_llh_cov.cov_d_d * 100 - 2.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh_cov.cov_d_d, expected "
           "2.0, is "
        << last_msg.msg.pos_llh_cov.cov_d_d;

    EXPECT_LE((last_msg.msg.pos_llh_cov.cov_e_d * 100 - 1.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh_cov.cov_e_d, expected "
           "1.0, is "
        << last_msg.msg.pos_llh_cov.cov_e_d;

    EXPECT_LE((last_msg.msg.pos_llh_cov.cov_e_e * 100 - 6.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh_cov.cov_e_e, expected "
           "6.0, is "
        << last_msg.msg.pos_llh_cov.cov_e_e;

    EXPECT_LE((last_msg.msg.pos_llh_cov.cov_n_d * 100 - 8.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh_cov.cov_n_d, expected "
           "8.0, is "
        << last_msg.msg.pos_llh_cov.cov_n_d;

    EXPECT_LE((last_msg.msg.pos_llh_cov.cov_n_e * 100 - 5.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh_cov.cov_n_e, expected "
           "5.0, is "
        << last_msg.msg.pos_llh_cov.cov_n_e;

    EXPECT_LE((last_msg.msg.pos_llh_cov.cov_n_n * 100 - 7.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh_cov.cov_n_n, expected "
           "7.0, is "
        << last_msg.msg.pos_llh_cov.cov_n_n;

    EXPECT_EQ(last_msg.msg.pos_llh_cov.flags, 5)
        << "incorrect value for last_msg.msg.pos_llh_cov.flags, expected 5, is "
        << (int64_t)last_msg.msg.pos_llh_cov.flags;

    EXPECT_LE((last_msg.msg.pos_llh_cov.height * 100 - 0.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh_cov.height, expected 0.0, "
           "is "
        << last_msg.msg.pos_llh_cov.height;

    EXPECT_LE((last_msg.msg.pos_llh_cov.lat * 100 - 0.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh_cov.lat, expected 0.0, is "
        << last_msg.msg.pos_llh_cov.lat;

    EXPECT_LE((last_msg.msg.pos_llh_cov.lon * 100 - 7.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh_cov.lon, expected 7.0, is "
        << last_msg.msg.pos_llh_cov.lon;

    EXPECT_EQ(last_msg.msg.pos_llh_cov.n_sats, 5)
        << "incorrect value for last_msg.msg.pos_llh_cov.n_sats, expected 5, "
           "is "
        << (int64_t)last_msg.msg.pos_llh_cov.n_sats;

    EXPECT_EQ(last_msg.msg.pos_llh_cov.tow, 7)
        << "incorrect value for last_msg.msg.pos_llh_cov.tow, expected 7, is "
        << (int64_t)last_msg.msg.pos_llh_cov.tow;
  }
}

}  // namespace
