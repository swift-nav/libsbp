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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrection.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/ssr.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_ssr_MsgSsrStecCorrection,
     test_auto_check_sbp_ssr_MsgSsrStecCorrection) {
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

    sbp_callback_register(&sbp_state, SbpMsgSsrStecCorrection,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 253, 5,  66, 0,  38, 180, 0, 0,  0,  3,  0,  1,   1,  10, 0,
        15, 1,   0,  10, 0,  2,  1,   1, 1,  63, 0,  62, 0,   61, 0,  60,
        0,  31,  15, 5,  63, 0,  64,  0, 65, 0,  66, 0,  119, 50,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_stec_correction.header.num_msgs = 1;

    test_msg.ssr_stec_correction.header.seq_num = 1;

    test_msg.ssr_stec_correction.header.sol_id = 0;

    test_msg.ssr_stec_correction.header.time.tow = 180;

    test_msg.ssr_stec_correction.header.time.wn = 3;

    test_msg.ssr_stec_correction.header.update_interval = 10;

    test_msg.ssr_stec_correction.n_sats = 2;

    test_msg.ssr_stec_correction.ssr_iod_atmo = 15;

    test_msg.ssr_stec_correction.stec_sat_list[0].stec_coeff[0] = 63;

    test_msg.ssr_stec_correction.stec_sat_list[0].stec_coeff[1] = 62;

    test_msg.ssr_stec_correction.stec_sat_list[0].stec_coeff[2] = 61;

    test_msg.ssr_stec_correction.stec_sat_list[0].stec_coeff[3] = 60;

    test_msg.ssr_stec_correction.stec_sat_list[0].stec_quality_indicator = 1;

    test_msg.ssr_stec_correction.stec_sat_list[0].sv_id.constellation = 1;

    test_msg.ssr_stec_correction.stec_sat_list[0].sv_id.satId = 1;

    test_msg.ssr_stec_correction.stec_sat_list[1].stec_coeff[0] = 63;

    test_msg.ssr_stec_correction.stec_sat_list[1].stec_coeff[1] = 64;

    test_msg.ssr_stec_correction.stec_sat_list[1].stec_coeff[2] = 65;

    test_msg.ssr_stec_correction.stec_sat_list[1].stec_coeff[3] = 66;

    test_msg.ssr_stec_correction.stec_sat_list[1].stec_quality_indicator = 5;

    test_msg.ssr_stec_correction.stec_sat_list[1].sv_id.constellation = 15;

    test_msg.ssr_stec_correction.stec_sat_list[1].sv_id.satId = 31;

    test_msg.ssr_stec_correction.tile_id = 10;

    test_msg.ssr_stec_correction.tile_set_id = 1;

    sbp_message_send(&sbp_state, SbpMsgSsrStecCorrection, 66, &test_msg,
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
        sbp_message_cmp(SbpMsgSsrStecCorrection, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.header.num_msgs, 1)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.header.num_msgs, expected 1, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.header.num_msgs;

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.header.seq_num, 1)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.header.seq_num, expected 1, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.header.seq_num;

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.header.sol_id, 0)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.header.sol_id, expected 0, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.header.sol_id;

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.header.time.tow, 180)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.header.time.tow, expected 180, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.header.time.tow;

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.header.time.wn, 3)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.header.time.wn, expected 3, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.header.time.wn;

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.header.update_interval, 10)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.header.update_interval, expected "
           "10, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.header.update_interval;

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.n_sats, 2)
        << "incorrect value for last_msg.msg.ssr_stec_correction.n_sats, "
           "expected 2, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.n_sats;

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.ssr_iod_atmo, 15)
        << "incorrect value for last_msg.msg.ssr_stec_correction.ssr_iod_atmo, "
           "expected 15, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.ssr_iod_atmo;

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.stec_sat_list[0].stec_coeff[0],
              63)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.stec_sat_list[0].stec_coeff[0], "
           "expected 63, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.stec_sat_list[0]
               .stec_coeff[0];
    EXPECT_EQ(last_msg.msg.ssr_stec_correction.stec_sat_list[0].stec_coeff[1],
              62)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.stec_sat_list[0].stec_coeff[1], "
           "expected 62, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.stec_sat_list[0]
               .stec_coeff[1];
    EXPECT_EQ(last_msg.msg.ssr_stec_correction.stec_sat_list[0].stec_coeff[2],
              61)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.stec_sat_list[0].stec_coeff[2], "
           "expected 61, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.stec_sat_list[0]
               .stec_coeff[2];
    EXPECT_EQ(last_msg.msg.ssr_stec_correction.stec_sat_list[0].stec_coeff[3],
              60)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.stec_sat_list[0].stec_coeff[3], "
           "expected 60, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.stec_sat_list[0]
               .stec_coeff[3];

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.stec_sat_list[0]
                  .stec_quality_indicator,
              1)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.stec_sat_list[0].stec_quality_"
           "indicator, expected 1, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.stec_sat_list[0]
               .stec_quality_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_stec_correction.stec_sat_list[0].sv_id.constellation,
        1)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.stec_sat_list[0].sv_id."
           "constellation, expected 1, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.stec_sat_list[0]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.stec_sat_list[0].sv_id.satId, 1)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.stec_sat_list[0].sv_id.satId, "
           "expected 1, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.stec_sat_list[0]
               .sv_id.satId;

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.stec_sat_list[1].stec_coeff[0],
              63)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.stec_sat_list[1].stec_coeff[0], "
           "expected 63, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.stec_sat_list[1]
               .stec_coeff[0];
    EXPECT_EQ(last_msg.msg.ssr_stec_correction.stec_sat_list[1].stec_coeff[1],
              64)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.stec_sat_list[1].stec_coeff[1], "
           "expected 64, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.stec_sat_list[1]
               .stec_coeff[1];
    EXPECT_EQ(last_msg.msg.ssr_stec_correction.stec_sat_list[1].stec_coeff[2],
              65)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.stec_sat_list[1].stec_coeff[2], "
           "expected 65, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.stec_sat_list[1]
               .stec_coeff[2];
    EXPECT_EQ(last_msg.msg.ssr_stec_correction.stec_sat_list[1].stec_coeff[3],
              66)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.stec_sat_list[1].stec_coeff[3], "
           "expected 66, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.stec_sat_list[1]
               .stec_coeff[3];

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.stec_sat_list[1]
                  .stec_quality_indicator,
              5)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.stec_sat_list[1].stec_quality_"
           "indicator, expected 5, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.stec_sat_list[1]
               .stec_quality_indicator;

    EXPECT_EQ(
        last_msg.msg.ssr_stec_correction.stec_sat_list[1].sv_id.constellation,
        15)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.stec_sat_list[1].sv_id."
           "constellation, expected 15, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.stec_sat_list[1]
               .sv_id.constellation;

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.stec_sat_list[1].sv_id.satId, 31)
        << "incorrect value for "
           "last_msg.msg.ssr_stec_correction.stec_sat_list[1].sv_id.satId, "
           "expected 31, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.stec_sat_list[1]
               .sv_id.satId;

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.tile_id, 10)
        << "incorrect value for last_msg.msg.ssr_stec_correction.tile_id, "
           "expected 10, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.tile_id;

    EXPECT_EQ(last_msg.msg.ssr_stec_correction.tile_set_id, 1)
        << "incorrect value for last_msg.msg.ssr_stec_correction.tile_set_id, "
           "expected 1, is "
        << (int64_t)last_msg.msg.ssr_stec_correction.tile_set_id;
  }
}

}  // namespace
