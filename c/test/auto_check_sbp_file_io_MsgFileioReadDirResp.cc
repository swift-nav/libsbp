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
// spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadDirResp.yaml by
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

TEST(auto_check_sbp_file_io_MsgFileioReadDirResp,
     test_auto_check_sbp_file_io_MsgFileioReadDirResp) {
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

    sbp_callback_register(&sbp_state, SbpMsgFileioReadDirResp,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  170, 0,   195, 4,   45,  78,  253, 224, 235, 102, 105, 108, 101,
        49,  0,   97,  110, 111, 116, 104, 101, 114, 32,  102, 105, 108, 101,
        0,   100, 101, 102, 105, 110, 105, 116, 101, 108, 121, 32,  110, 111,
        116, 32,  97,  32,  102, 105, 108, 101, 0,   186, 137,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    EXPECT_TRUE(sbp_msg_fileio_read_dir_resp_contents_add_section(
        &test_msg.fileio_read_dir_resp, "file1"))
        << "Can't assign section 0";
    EXPECT_TRUE(sbp_msg_fileio_read_dir_resp_contents_add_section(
        &test_msg.fileio_read_dir_resp, "another file"))
        << "Can't assign section 1";
    EXPECT_TRUE(sbp_msg_fileio_read_dir_resp_contents_add_section(
        &test_msg.fileio_read_dir_resp, "definitely not a file"))
        << "Can't assign section 2";
    EXPECT_EQ(sbp_msg_fileio_read_dir_resp_contents_encoded_len(
                  &test_msg.fileio_read_dir_resp),
              41)
        << "String not encoded properly";

    test_msg.fileio_read_dir_resp.sequence = 3957390670;

    sbp_message_send(&sbp_state, SbpMsgFileioReadDirResp, 1219, &test_msg,
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

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgFileioReadDirResp, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(sbp_msg_fileio_read_dir_resp_contents_encoded_len(
                  &last_msg.msg.fileio_read_dir_resp),
              41)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_fileio_read_dir_resp_contents_get_section(
                         &last_msg.msg.fileio_read_dir_resp, 0),
                     "file1"),
              0)
        << "Section 0 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_fileio_read_dir_resp_contents_get_section(
                         &last_msg.msg.fileio_read_dir_resp, 1),
                     "another file"),
              0)
        << "Section 1 not decoded properly";
    EXPECT_EQ(strcmp(sbp_msg_fileio_read_dir_resp_contents_get_section(
                         &last_msg.msg.fileio_read_dir_resp, 2),
                     "definitely not a file"),
              0)
        << "Section 2 not decoded properly";

    EXPECT_EQ(last_msg.msg.fileio_read_dir_resp.sequence, 3957390670)
        << "incorrect value for last_msg.msg.fileio_read_dir_resp.sequence, "
           "expected 3957390670, is "
        << (int64_t)last_msg.msg.fileio_read_dir_resp.sequence;
  }
}

}  // namespace
