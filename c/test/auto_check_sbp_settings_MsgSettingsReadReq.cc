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
// spec/tests/yaml/swiftnav/sbp/settings/test_MsgSettingsReadReq.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/settings.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_settings_MsgSettingsReadReq,
     test_auto_check_sbp_settings_MsgSettingsReadReq) {
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

    sbp_callback_register(&sbp_state, SbpMsgSettingsReadReq, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  164, 0,   152, 214, 26,  115, 101, 99,  116, 105, 111,
        110, 45,  110, 97,  109, 101, 0,   115, 101, 116, 116, 105,
        110, 103, 45,  110, 97,  109, 101, 0,   181, 228,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    EXPECT_TRUE(sbp_msg_settings_read_req_setting_add_section(
        &test_msg.settings_read_req, "section-name"))
        << "Can't assign section 0";
    EXPECT_TRUE(sbp_msg_settings_read_req_setting_add_section(
        &test_msg.settings_read_req, "setting-name"))
        << "Can't assign section 1";
    EXPECT_EQ(sbp_msg_settings_read_req_setting_encoded_len(
                  &test_msg.settings_read_req),
              26)
        << "String not encoded properly";

    sbp_message_send(&sbp_state, SbpMsgSettingsReadReq, 54936, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 54936)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgSettingsReadReq, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(sbp_msg_settings_read_req_setting_encoded_len(
                  &last_msg.msg.settings_read_req),
              26)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_req_setting_get_section(
                         &last_msg.msg.settings_read_req, 0),
                     "section-name"),
              0)
        << "Section 0 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_settings_read_req_setting_get_section(
                         &last_msg.msg.settings_read_req, 1),
                     "setting-name"),
              0)
        << "Section 1 not decoded properly";
  }
}

}  // namespace
