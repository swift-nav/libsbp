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
// spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagIonoTileSatLos.yaml by
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

TEST(auto_check_sbp_integrity_MsgSsrFlagIonoTileSatLos,
     test_auto_check_sbp_integrity_MsgSsrFlagIonoTileSatLos) {
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

    sbp_callback_register(&sbp_state, SbpMsgSsrFlagIonoTileSatLos,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 205, 11, 66, 0, 19, 180, 0,  0,  0,  3,  0,   1,   2,
        3,  4,   0,  5,  0, 6,  2,   10, 11, 15, 14, 239, 235,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_flag_iono_tile_sat_los.faulty_los[0].constellation = 11;

    test_msg.ssr_flag_iono_tile_sat_los.faulty_los[0].satId = 10;

    test_msg.ssr_flag_iono_tile_sat_los.faulty_los[1].constellation = 14;

    test_msg.ssr_flag_iono_tile_sat_los.faulty_los[1].satId = 15;

    test_msg.ssr_flag_iono_tile_sat_los.header.chain_id = 6;

    test_msg.ssr_flag_iono_tile_sat_los.header.num_msgs = 1;

    test_msg.ssr_flag_iono_tile_sat_los.header.obs_time.tow = 180;

    test_msg.ssr_flag_iono_tile_sat_los.header.obs_time.wn = 3;

    test_msg.ssr_flag_iono_tile_sat_los.header.seq_num = 2;

    test_msg.ssr_flag_iono_tile_sat_los.header.ssr_sol_id = 3;

    test_msg.ssr_flag_iono_tile_sat_los.header.tile_id = 5;

    test_msg.ssr_flag_iono_tile_sat_los.header.tile_set_id = 4;

    test_msg.ssr_flag_iono_tile_sat_los.n_faulty_los = 2;

    sbp_message_send(&sbp_state, SbpMsgSsrFlagIonoTileSatLos, 66, &test_msg,
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
        sbp_message_cmp(SbpMsgSsrFlagIonoTileSatLos, &last_msg.msg, &test_msg),
        0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(
        last_msg.msg.ssr_flag_iono_tile_sat_los.faulty_los[0].constellation, 11)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_iono_tile_sat_los.faulty_los[0]."
           "constellation, expected 11, is "
        << (int64_t)last_msg.msg.ssr_flag_iono_tile_sat_los.faulty_los[0]
               .constellation;

    EXPECT_EQ(last_msg.msg.ssr_flag_iono_tile_sat_los.faulty_los[0].satId, 10)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_iono_tile_sat_los.faulty_los[0].satId, "
           "expected 10, is "
        << (int64_t)last_msg.msg.ssr_flag_iono_tile_sat_los.faulty_los[0].satId;

    EXPECT_EQ(
        last_msg.msg.ssr_flag_iono_tile_sat_los.faulty_los[1].constellation, 14)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_iono_tile_sat_los.faulty_los[1]."
           "constellation, expected 14, is "
        << (int64_t)last_msg.msg.ssr_flag_iono_tile_sat_los.faulty_los[1]
               .constellation;

    EXPECT_EQ(last_msg.msg.ssr_flag_iono_tile_sat_los.faulty_los[1].satId, 15)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_iono_tile_sat_los.faulty_los[1].satId, "
           "expected 15, is "
        << (int64_t)last_msg.msg.ssr_flag_iono_tile_sat_los.faulty_los[1].satId;

    EXPECT_EQ(last_msg.msg.ssr_flag_iono_tile_sat_los.header.chain_id, 6)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_iono_tile_sat_los.header.chain_id, expected "
           "6, is "
        << (int64_t)last_msg.msg.ssr_flag_iono_tile_sat_los.header.chain_id;

    EXPECT_EQ(last_msg.msg.ssr_flag_iono_tile_sat_los.header.num_msgs, 1)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_iono_tile_sat_los.header.num_msgs, expected "
           "1, is "
        << (int64_t)last_msg.msg.ssr_flag_iono_tile_sat_los.header.num_msgs;

    EXPECT_EQ(last_msg.msg.ssr_flag_iono_tile_sat_los.header.obs_time.tow, 180)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_iono_tile_sat_los.header.obs_time.tow, "
           "expected 180, is "
        << (int64_t)last_msg.msg.ssr_flag_iono_tile_sat_los.header.obs_time.tow;

    EXPECT_EQ(last_msg.msg.ssr_flag_iono_tile_sat_los.header.obs_time.wn, 3)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_iono_tile_sat_los.header.obs_time.wn, "
           "expected 3, is "
        << (int64_t)last_msg.msg.ssr_flag_iono_tile_sat_los.header.obs_time.wn;

    EXPECT_EQ(last_msg.msg.ssr_flag_iono_tile_sat_los.header.seq_num, 2)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_iono_tile_sat_los.header.seq_num, expected "
           "2, is "
        << (int64_t)last_msg.msg.ssr_flag_iono_tile_sat_los.header.seq_num;

    EXPECT_EQ(last_msg.msg.ssr_flag_iono_tile_sat_los.header.ssr_sol_id, 3)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_iono_tile_sat_los.header.ssr_sol_id, "
           "expected 3, is "
        << (int64_t)last_msg.msg.ssr_flag_iono_tile_sat_los.header.ssr_sol_id;

    EXPECT_EQ(last_msg.msg.ssr_flag_iono_tile_sat_los.header.tile_id, 5)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_iono_tile_sat_los.header.tile_id, expected "
           "5, is "
        << (int64_t)last_msg.msg.ssr_flag_iono_tile_sat_los.header.tile_id;

    EXPECT_EQ(last_msg.msg.ssr_flag_iono_tile_sat_los.header.tile_set_id, 4)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_iono_tile_sat_los.header.tile_set_id, "
           "expected 4, is "
        << (int64_t)last_msg.msg.ssr_flag_iono_tile_sat_los.header.tile_set_id;

    EXPECT_EQ(last_msg.msg.ssr_flag_iono_tile_sat_los.n_faulty_los, 2)
        << "incorrect value for "
           "last_msg.msg.ssr_flag_iono_tile_sat_los.n_faulty_los, expected 2, "
           "is "
        << (int64_t)last_msg.msg.ssr_flag_iono_tile_sat_los.n_faulty_los;
  }
}

}  // namespace
