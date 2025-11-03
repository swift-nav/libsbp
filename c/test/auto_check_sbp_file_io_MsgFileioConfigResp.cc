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
// spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioConfigResp.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/file_io.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_file_io_MsgFileioConfigResp,
     test_auto_check_sbp_file_io_MsgFileioConfigResp) {
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

    sbp_callback_register(&sbp_state, SbpMsgFileioConfigResp, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 2, 16,  195, 4,   16, 170, 76, 52, 91,  149, 186,
        44, 3, 216, 151, 255, 61, 12,  97, 66, 144, 239, 115,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.fileio_config_resp.batch_size = 1040160728;

    test_msg.fileio_config_resp.fileio_version = 2420269324;

    test_msg.fileio_config_resp.sequence = 1530154154;

    test_msg.fileio_config_resp.window_size = 53262997;

    sbp_message_send(&sbp_state, SbpMsgFileioConfigResp, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgFileioConfigResp, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.fileio_config_resp.batch_size, 1040160728)
        << "incorrect value for last_msg.msg.fileio_config_resp.batch_size, "
           "expected 1040160728, is "
        << (int64_t)last_msg.msg.fileio_config_resp.batch_size;

    EXPECT_EQ(last_msg.msg.fileio_config_resp.fileio_version, 2420269324)
        << "incorrect value for "
           "last_msg.msg.fileio_config_resp.fileio_version, expected "
           "2420269324, is "
        << (int64_t)last_msg.msg.fileio_config_resp.fileio_version;

    EXPECT_EQ(last_msg.msg.fileio_config_resp.sequence, 1530154154)
        << "incorrect value for last_msg.msg.fileio_config_resp.sequence, "
           "expected 1530154154, is "
        << (int64_t)last_msg.msg.fileio_config_resp.sequence;

    EXPECT_EQ(last_msg.msg.fileio_config_resp.window_size, 53262997)
        << "incorrect value for last_msg.msg.fileio_config_resp.window_size, "
           "expected 53262997, is "
        << (int64_t)last_msg.msg.fileio_config_resp.window_size;
  }
}

}  // namespace
