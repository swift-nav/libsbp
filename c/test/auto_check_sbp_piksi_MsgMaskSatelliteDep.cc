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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgMaskSatelliteDep.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/piksi.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_piksi_MsgMaskSatelliteDep,
     test_auto_check_sbp_piksi_MsgMaskSatelliteDep) {
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

    sbp_callback_register(&sbp_state, SbpMsgMaskSatelliteDep, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 27, 0, 187, 134, 5, 33, 2, 153, 95, 4, 29, 188,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.mask_satellite_dep.mask = 33;

    test_msg.mask_satellite_dep.sid.code = 95;

    test_msg.mask_satellite_dep.sid.reserved = 4;

    test_msg.mask_satellite_dep.sid.sat = 39170;

    sbp_message_send(&sbp_state, SbpMsgMaskSatelliteDep, 34491, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 34491)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgMaskSatelliteDep, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.mask_satellite_dep.mask, 33)
        << "incorrect value for last_msg.msg.mask_satellite_dep.mask, expected "
           "33, is "
        << (int64_t)last_msg.msg.mask_satellite_dep.mask;

    EXPECT_EQ(last_msg.msg.mask_satellite_dep.sid.code, 95)
        << "incorrect value for last_msg.msg.mask_satellite_dep.sid.code, "
           "expected 95, is "
        << (int64_t)last_msg.msg.mask_satellite_dep.sid.code;

    EXPECT_EQ(last_msg.msg.mask_satellite_dep.sid.reserved, 4)
        << "incorrect value for last_msg.msg.mask_satellite_dep.sid.reserved, "
           "expected 4, is "
        << (int64_t)last_msg.msg.mask_satellite_dep.sid.reserved;

    EXPECT_EQ(last_msg.msg.mask_satellite_dep.sid.sat, 39170)
        << "incorrect value for last_msg.msg.mask_satellite_dep.sid.sat, "
           "expected 39170, is "
        << (int64_t)last_msg.msg.mask_satellite_dep.sid.sat;
  }
}

}  // namespace
