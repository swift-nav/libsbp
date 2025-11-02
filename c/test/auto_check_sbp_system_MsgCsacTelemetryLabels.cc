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
// spec/tests/yaml/swiftnav/sbp/system/test_MsgCsacTelemetryLabels.yaml by
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

TEST(auto_check_sbp_system_MsgCsacTelemetryLabels,
     test_auto_check_sbp_system_MsgCsacTelemetryLabels) {
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

    sbp_callback_register(&sbp_state, SbpMsgCsacTelemetryLabels,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  5,  255, 91, 200, 12,  186, 115, 111, 109,
        101, 32, 108, 97, 98,  101, 108, 115, 86,  236,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.csac_telemetry_labels.id = 186;

    size_t written;
    EXPECT_TRUE(sbp_msg_csac_telemetry_labels_telemetry_labels_set(
        &test_msg.csac_telemetry_labels, "some labels", false, &written))
        << "Can't assign text";
    EXPECT_EQ(written, strlen("some labels")) << "Wrote different to expected";
    EXPECT_EQ(sbp_msg_csac_telemetry_labels_telemetry_labels_encoded_len(
                  &test_msg.csac_telemetry_labels),
              11)
        << "String not encoded properly";

    sbp_message_send(&sbp_state, SbpMsgCsacTelemetryLabels, 51291, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 51291)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgCsacTelemetryLabels, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.csac_telemetry_labels.id, 186)
        << "incorrect value for last_msg.msg.csac_telemetry_labels.id, "
           "expected 186, is "
        << (int64_t)last_msg.msg.csac_telemetry_labels.id;

    EXPECT_EQ(sbp_msg_csac_telemetry_labels_telemetry_labels_encoded_len(
                  &last_msg.msg.csac_telemetry_labels),
              11)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_csac_telemetry_labels_telemetry_labels_get(
                         &last_msg.msg.csac_telemetry_labels),
                     "some labels"),
              0)
        << "String not decoded properly";
  }
}

}  // namespace
