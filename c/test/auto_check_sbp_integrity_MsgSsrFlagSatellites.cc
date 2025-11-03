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
// spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagSatellites.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/integrity.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_integrity_MsgSsrFlagSatellites,
     test_auto_check_sbp_integrity_MsgSsrFlagSatellites) {
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

    sbp_callback_register(&sbp_state, SbpMsgSsrFlagSatellites,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 189, 11, 66, 0, 15, 180, 0,  0,  0,   3,   0,
        1,  2,   3,  4,  5, 3,  10,  11, 12, 110, 165,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_flag_satellites.chain_id = 4;

    test_msg.ssr_flag_satellites.const_id = 5;

    test_msg.ssr_flag_satellites.faulty_sats[0] = 10;

    test_msg.ssr_flag_satellites.faulty_sats[1] = 11;

    test_msg.ssr_flag_satellites.faulty_sats[2] = 12;

    test_msg.ssr_flag_satellites.n_faulty_sats = 3;

    test_msg.ssr_flag_satellites.num_msgs = 1;

    test_msg.ssr_flag_satellites.obs_time.tow = 180;

    test_msg.ssr_flag_satellites.obs_time.wn = 3;

    test_msg.ssr_flag_satellites.seq_num = 2;

    test_msg.ssr_flag_satellites.ssr_sol_id = 3;

    sbp_message_send(&sbp_state, SbpMsgSsrFlagSatellites, 66, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 66)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgSsrFlagSatellites, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ssr_flag_satellites.chain_id, 4)
        << "incorrect value for last_msg.msg.ssr_flag_satellites.chain_id, "
           "expected 4, is "
        << (int64_t)last_msg.msg.ssr_flag_satellites.chain_id;

    EXPECT_EQ(last_msg.msg.ssr_flag_satellites.const_id, 5)
        << "incorrect value for last_msg.msg.ssr_flag_satellites.const_id, "
           "expected 5, is "
        << (int64_t)last_msg.msg.ssr_flag_satellites.const_id;

    EXPECT_EQ(last_msg.msg.ssr_flag_satellites.faulty_sats[0], 10)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_satellites.faulty_sats[0], expected 10, is "
        << (int64_t)last_msg.msg.ssr_flag_satellites.faulty_sats[0];
    EXPECT_EQ(last_msg.msg.ssr_flag_satellites.faulty_sats[1], 11)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_satellites.faulty_sats[1], expected 11, is "
        << (int64_t)last_msg.msg.ssr_flag_satellites.faulty_sats[1];
    EXPECT_EQ(last_msg.msg.ssr_flag_satellites.faulty_sats[2], 12)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_satellites.faulty_sats[2], expected 12, is "
        << (int64_t)last_msg.msg.ssr_flag_satellites.faulty_sats[2];

    EXPECT_EQ(last_msg.msg.ssr_flag_satellites.n_faulty_sats, 3)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_satellites.n_faulty_sats, expected 3, is "
        << (int64_t)last_msg.msg.ssr_flag_satellites.n_faulty_sats;

    EXPECT_EQ(last_msg.msg.ssr_flag_satellites.num_msgs, 1)
        << "incorrect value for last_msg.msg.ssr_flag_satellites.num_msgs, "
           "expected 1, is "
        << (int64_t)last_msg.msg.ssr_flag_satellites.num_msgs;

    EXPECT_EQ(last_msg.msg.ssr_flag_satellites.obs_time.tow, 180)
        << "incorrect value for last_msg.msg.ssr_flag_satellites.obs_time.tow, "
           "expected 180, is "
        << (int64_t)last_msg.msg.ssr_flag_satellites.obs_time.tow;

    EXPECT_EQ(last_msg.msg.ssr_flag_satellites.obs_time.wn, 3)
        << "incorrect value for last_msg.msg.ssr_flag_satellites.obs_time.wn, "
           "expected 3, is "
        << (int64_t)last_msg.msg.ssr_flag_satellites.obs_time.wn;

    EXPECT_EQ(last_msg.msg.ssr_flag_satellites.seq_num, 2)
        << "incorrect value for last_msg.msg.ssr_flag_satellites.seq_num, "
           "expected 2, is "
        << (int64_t)last_msg.msg.ssr_flag_satellites.seq_num;

    EXPECT_EQ(last_msg.msg.ssr_flag_satellites.ssr_sol_id, 3)
        << "incorrect value for last_msg.msg.ssr_flag_satellites.ssr_sol_id, "
           "expected 3, is "
        << (int64_t)last_msg.msg.ssr_flag_satellites.ssr_sol_id;
  }
}

}  // namespace
