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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrCodePhaseBiasesBounds.yaml by
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

TEST(auto_check_sbp_ssr_MsgSsrCodePhaseBiasesBounds,
     test_auto_check_sbp_ssr_MsgSsrCodePhaseBiasesBounds) {
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

    sbp_callback_register(&sbp_state, SbpMsgSsrCodePhaseBiasesBounds,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 236, 5,  66, 0, 31, 180, 0,  0,  0,  3,  0,  1,
        2,  1,   14, 15, 1, 3,  0,   3,  39, 1,  39, 1,  1,
        3,  39,  1,  39, 1, 1,  1,   39, 1,  39, 1,  23, 113,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ssr_code_phase_biases_bounds.const_id = 1;

    test_msg.ssr_code_phase_biases_bounds.header.num_msgs = 1;

    test_msg.ssr_code_phase_biases_bounds.header.seq_num = 2;

    test_msg.ssr_code_phase_biases_bounds.header.sol_id = 14;

    test_msg.ssr_code_phase_biases_bounds.header.time.tow = 180;

    test_msg.ssr_code_phase_biases_bounds.header.time.wn = 3;

    test_msg.ssr_code_phase_biases_bounds.header.update_interval = 1;

    test_msg.ssr_code_phase_biases_bounds.n_sats_signals = 3;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[0]
        .code_bias_bound_mu = 39;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[0]
        .code_bias_bound_sig = 1;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[0]
        .phase_bias_bound_mu = 39;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[0]
        .phase_bias_bound_sig = 1;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[0].sat_id = 0;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[0].signal_id = 3;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[1]
        .code_bias_bound_mu = 39;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[1]
        .code_bias_bound_sig = 1;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[1]
        .phase_bias_bound_mu = 39;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[1]
        .phase_bias_bound_sig = 1;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[1].sat_id = 1;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[1].signal_id = 3;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[2]
        .code_bias_bound_mu = 39;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[2]
        .code_bias_bound_sig = 1;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[2]
        .phase_bias_bound_mu = 39;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[2]
        .phase_bias_bound_sig = 1;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[2].sat_id = 1;

    test_msg.ssr_code_phase_biases_bounds.satellites_signals[2].signal_id = 1;

    test_msg.ssr_code_phase_biases_bounds.ssr_iod = 15;

    sbp_message_send(&sbp_state, SbpMsgSsrCodePhaseBiasesBounds, 66, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrCodePhaseBiasesBounds, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.const_id, 1)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.const_id, expected 1, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds.const_id;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.header.num_msgs, 1)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.header.num_msgs, "
           "expected 1, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds.header.num_msgs;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.header.seq_num, 2)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.header.seq_num, expected "
           "2, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds.header.seq_num;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.header.sol_id, 14)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.header.sol_id, expected "
           "14, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds.header.sol_id;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.header.time.tow, 180)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.header.time.tow, "
           "expected 180, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds.header.time.tow;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.header.time.wn, 3)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.header.time.wn, expected "
           "3, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds.header.time.wn;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.header.update_interval,
              1)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.header.update_interval, "
           "expected 1, is "
        << (int64_t)
               last_msg.msg.ssr_code_phase_biases_bounds.header.update_interval;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.n_sats_signals, 3)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.n_sats_signals, expected "
           "3, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds.n_sats_signals;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[0]
                  .code_bias_bound_mu,
              39)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[0]."
           "code_bias_bound_mu, expected 39, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[0]
               .code_bias_bound_mu;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[0]
                  .code_bias_bound_sig,
              1)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[0]."
           "code_bias_bound_sig, expected 1, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[0]
               .code_bias_bound_sig;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[0]
                  .phase_bias_bound_mu,
              39)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[0]."
           "phase_bias_bound_mu, expected 39, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[0]
               .phase_bias_bound_mu;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[0]
                  .phase_bias_bound_sig,
              1)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[0]."
           "phase_bias_bound_sig, expected 1, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[0]
               .phase_bias_bound_sig;

    EXPECT_EQ(
        last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[0].sat_id,
        0)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[0]."
           "sat_id, expected 0, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[0]
               .sat_id;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[0]
                  .signal_id,
              3)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[0]."
           "signal_id, expected 3, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[0]
               .signal_id;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[1]
                  .code_bias_bound_mu,
              39)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[1]."
           "code_bias_bound_mu, expected 39, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[1]
               .code_bias_bound_mu;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[1]
                  .code_bias_bound_sig,
              1)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[1]."
           "code_bias_bound_sig, expected 1, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[1]
               .code_bias_bound_sig;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[1]
                  .phase_bias_bound_mu,
              39)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[1]."
           "phase_bias_bound_mu, expected 39, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[1]
               .phase_bias_bound_mu;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[1]
                  .phase_bias_bound_sig,
              1)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[1]."
           "phase_bias_bound_sig, expected 1, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[1]
               .phase_bias_bound_sig;

    EXPECT_EQ(
        last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[1].sat_id,
        1)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[1]."
           "sat_id, expected 1, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[1]
               .sat_id;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[1]
                  .signal_id,
              3)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[1]."
           "signal_id, expected 3, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[1]
               .signal_id;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[2]
                  .code_bias_bound_mu,
              39)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[2]."
           "code_bias_bound_mu, expected 39, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[2]
               .code_bias_bound_mu;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[2]
                  .code_bias_bound_sig,
              1)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[2]."
           "code_bias_bound_sig, expected 1, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[2]
               .code_bias_bound_sig;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[2]
                  .phase_bias_bound_mu,
              39)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[2]."
           "phase_bias_bound_mu, expected 39, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[2]
               .phase_bias_bound_mu;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[2]
                  .phase_bias_bound_sig,
              1)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[2]."
           "phase_bias_bound_sig, expected 1, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[2]
               .phase_bias_bound_sig;

    EXPECT_EQ(
        last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[2].sat_id,
        1)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[2]."
           "sat_id, expected 1, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[2]
               .sat_id;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[2]
                  .signal_id,
              1)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.satellites_signals[2]."
           "signal_id, expected 1, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds
               .satellites_signals[2]
               .signal_id;

    EXPECT_EQ(last_msg.msg.ssr_code_phase_biases_bounds.ssr_iod, 15)
        << "incorrect value for "
           "last_msg.msg.ssr_code_phase_biases_bounds.ssr_iod, expected 15, is "
        << (int64_t)last_msg.msg.ssr_code_phase_biases_bounds.ssr_iod;
  }
}

}  // namespace
