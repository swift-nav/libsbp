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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgIono.yaml by generate.py. Do
// not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/observation.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_observation_MsgIono,
     test_auto_check_sbp_observation_MsgIono) {
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

    sbp_callback_register(&sbp_state, SbpMsgIono, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 144, 0,   123, 0, 70, 0, 0, 0, 0, 0,   0,   0,   0,  0, 0,
        0,  0,   52,  62,  0, 0,  0, 0, 0, 0, 80,  62,  0,   0,  0, 0,
        0,  0,   112, 190, 0, 0,  0, 0, 0, 0, 112, 190, 0,   0,  0, 0,
        0,  0,   243, 64,  0, 0,  0, 0, 0, 0, 232, 64,  0,   0,  0, 0,
        0,  0,   240, 192, 0, 0,  0, 0, 0, 0, 20,  193, 101, 31,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.iono.a0 = 4.6566128730773926e-09;

    test_msg.iono.a1 = 1.4901161193847656e-08;

    test_msg.iono.a2 = -5.960464477539063e-08;

    test_msg.iono.a3 = -5.960464477539063e-08;

    test_msg.iono.b0 = 77824.0;

    test_msg.iono.b1 = 49152.0;

    test_msg.iono.b2 = -65536.0;

    test_msg.iono.b3 = -327680.0;

    test_msg.iono.t_nmct.tow = 0;

    test_msg.iono.t_nmct.wn = 0;

    sbp_message_send(&sbp_state, SbpMsgIono, 123, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 123)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgIono, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.iono.a0 * 100 - 4.65661287308e-09 * 100), 0.05)
        << "incorrect value for last_msg.msg.iono.a0, expected "
           "4.65661287308e-09, is "
        << last_msg.msg.iono.a0;

    EXPECT_LE((last_msg.msg.iono.a1 * 100 - 1.49011611938e-08 * 100), 0.05)
        << "incorrect value for last_msg.msg.iono.a1, expected "
           "1.49011611938e-08, is "
        << last_msg.msg.iono.a1;

    EXPECT_LE((last_msg.msg.iono.a2 * 100 - -5.96046447754e-08 * 100), 0.05)
        << "incorrect value for last_msg.msg.iono.a2, expected "
           "-5.96046447754e-08, is "
        << last_msg.msg.iono.a2;

    EXPECT_LE((last_msg.msg.iono.a3 * 100 - -5.96046447754e-08 * 100), 0.05)
        << "incorrect value for last_msg.msg.iono.a3, expected "
           "-5.96046447754e-08, is "
        << last_msg.msg.iono.a3;

    EXPECT_LE((last_msg.msg.iono.b0 * 100 - 77824.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.iono.b0, expected 77824.0, is "
        << last_msg.msg.iono.b0;

    EXPECT_LE((last_msg.msg.iono.b1 * 100 - 49152.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.iono.b1, expected 49152.0, is "
        << last_msg.msg.iono.b1;

    EXPECT_LE((last_msg.msg.iono.b2 * 100 - -65536.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.iono.b2, expected -65536.0, is "
        << last_msg.msg.iono.b2;

    EXPECT_LE((last_msg.msg.iono.b3 * 100 - -327680.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.iono.b3, expected -327680.0, is "
        << last_msg.msg.iono.b3;

    EXPECT_EQ(last_msg.msg.iono.t_nmct.tow, 0)
        << "incorrect value for last_msg.msg.iono.t_nmct.tow, expected 0, is "
        << (int64_t)last_msg.msg.iono.t_nmct.tow;

    EXPECT_EQ(last_msg.msg.iono.t_nmct.wn, 0)
        << "incorrect value for last_msg.msg.iono.t_nmct.wn, expected 0, is "
        << (int64_t)last_msg.msg.iono.t_nmct.wn;
  }
}

}  // namespace
