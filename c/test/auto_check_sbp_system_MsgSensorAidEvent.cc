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
// spec/tests/yaml/swiftnav/sbp/system/test_MsgSensorAidEvent.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/system.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_system_MsgSensorAidEvent,
     test_auto_check_sbp_system_MsgSensorAidEvent) {
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

    sbp_callback_register(&sbp_state, SbpMsgSensorAidEvent, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 9, 255, 211, 136, 15, 48, 246, 122, 19, 0,   0,
        0,  0, 0,   0,   0,   0,  0,  0,   0,   33, 236,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.sensor_aid_event.flags = 0;

    test_msg.sensor_aid_event.n_accepted_meas = 0;

    test_msg.sensor_aid_event.n_attempted_meas = 0;

    test_msg.sensor_aid_event.n_available_meas = 0;

    test_msg.sensor_aid_event.sensor_id = 0;

    test_msg.sensor_aid_event.sensor_state = 0;

    test_msg.sensor_aid_event.sensor_type = 0;

    test_msg.sensor_aid_event.time = 326825520;

    sbp_message_send(&sbp_state, SbpMsgSensorAidEvent, 35027, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 35027)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgSensorAidEvent, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.sensor_aid_event.flags, 0)
        << "incorrect value for last_msg.msg.sensor_aid_event.flags, expected "
           "0, is "
        << (int64_t)last_msg.msg.sensor_aid_event.flags;

    EXPECT_EQ(last_msg.msg.sensor_aid_event.n_accepted_meas, 0)
        << "incorrect value for last_msg.msg.sensor_aid_event.n_accepted_meas, "
           "expected 0, is "
        << (int64_t)last_msg.msg.sensor_aid_event.n_accepted_meas;

    EXPECT_EQ(last_msg.msg.sensor_aid_event.n_attempted_meas, 0)
        << "incorrect value for "
           "last_msg.msg.sensor_aid_event.n_attempted_meas, expected 0, is "
        << (int64_t)last_msg.msg.sensor_aid_event.n_attempted_meas;

    EXPECT_EQ(last_msg.msg.sensor_aid_event.n_available_meas, 0)
        << "incorrect value for "
           "last_msg.msg.sensor_aid_event.n_available_meas, expected 0, is "
        << (int64_t)last_msg.msg.sensor_aid_event.n_available_meas;

    EXPECT_EQ(last_msg.msg.sensor_aid_event.sensor_id, 0)
        << "incorrect value for last_msg.msg.sensor_aid_event.sensor_id, "
           "expected 0, is "
        << (int64_t)last_msg.msg.sensor_aid_event.sensor_id;

    EXPECT_EQ(last_msg.msg.sensor_aid_event.sensor_state, 0)
        << "incorrect value for last_msg.msg.sensor_aid_event.sensor_state, "
           "expected 0, is "
        << (int64_t)last_msg.msg.sensor_aid_event.sensor_state;

    EXPECT_EQ(last_msg.msg.sensor_aid_event.sensor_type, 0)
        << "incorrect value for last_msg.msg.sensor_aid_event.sensor_type, "
           "expected 0, is "
        << (int64_t)last_msg.msg.sensor_aid_event.sensor_type;

    EXPECT_EQ(last_msg.msg.sensor_aid_event.time, 326825520)
        << "incorrect value for last_msg.msg.sensor_aid_event.time, expected "
           "326825520, is "
        << (int64_t)last_msg.msg.sensor_aid_event.time;
  }
}

}  // namespace
