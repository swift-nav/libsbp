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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIqDepB.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/tracking.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_tracking_MsgTrackingIqDepB,
     test_auto_check_sbp_tracking_MsgTrackingIqDepB) {
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

    sbp_callback_register(&sbp_state, SbpMsgTrackingIqDepB, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  44,  0,   39,  101, 27,  45,  188, 183, 72,  185, 157,
        15,  187, 249, 101, 24,  135, 146, 180, 224, 123, 235, 142,
        208, 102, 112, 25,  21,  177, 96,  116, 68,  246, 153,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_iq_dep_b.channel = 45;

    test_msg.tracking_iq_dep_b.corrs[0].I = 261994824;

    test_msg.tracking_iq_dep_b.corrs[0].Q = 409336251;

    test_msg.tracking_iq_dep_b.corrs[1].I = -525036921;

    test_msg.tracking_iq_dep_b.corrs[1].Q = -795939973;

    test_msg.tracking_iq_dep_b.corrs[2].I = 353988710;

    test_msg.tracking_iq_dep_b.corrs[2].Q = 1148477617;

    test_msg.tracking_iq_dep_b.sid.code = 183;

    test_msg.tracking_iq_dep_b.sid.sat = 188;

    sbp_message_send(&sbp_state, SbpMsgTrackingIqDepB, 25895, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 25895)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingIqDepB, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_b.channel, 45)
        << "incorrect value for last_msg.msg.tracking_iq_dep_b.channel, "
           "expected 45, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_b.channel;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_b.corrs[0].I, 261994824)
        << "incorrect value for last_msg.msg.tracking_iq_dep_b.corrs[0].I, "
           "expected 261994824, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_b.corrs[0].I;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_b.corrs[0].Q, 409336251)
        << "incorrect value for last_msg.msg.tracking_iq_dep_b.corrs[0].Q, "
           "expected 409336251, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_b.corrs[0].Q;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_b.corrs[1].I, -525036921)
        << "incorrect value for last_msg.msg.tracking_iq_dep_b.corrs[1].I, "
           "expected -525036921, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_b.corrs[1].I;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_b.corrs[1].Q, -795939973)
        << "incorrect value for last_msg.msg.tracking_iq_dep_b.corrs[1].Q, "
           "expected -795939973, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_b.corrs[1].Q;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_b.corrs[2].I, 353988710)
        << "incorrect value for last_msg.msg.tracking_iq_dep_b.corrs[2].I, "
           "expected 353988710, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_b.corrs[2].I;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_b.corrs[2].Q, 1148477617)
        << "incorrect value for last_msg.msg.tracking_iq_dep_b.corrs[2].Q, "
           "expected 1148477617, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_b.corrs[2].Q;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_b.sid.code, 183)
        << "incorrect value for last_msg.msg.tracking_iq_dep_b.sid.code, "
           "expected 183, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_b.sid.code;

    EXPECT_EQ(last_msg.msg.tracking_iq_dep_b.sid.sat, 188)
        << "incorrect value for last_msg.msg.tracking_iq_dep_b.sid.sat, "
           "expected 188, is "
        << (int64_t)last_msg.msg.tracking_iq_dep_b.sid.sat;
  }
}

}  // namespace
