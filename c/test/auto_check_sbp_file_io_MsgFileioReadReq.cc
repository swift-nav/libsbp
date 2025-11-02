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
// spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadReq.yaml by
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

TEST(auto_check_sbp_file_io_MsgFileioReadReq,
     test_auto_check_sbp_file_io_MsgFileioReadReq) {
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

    sbp_callback_register(&sbp_state, SbpMsgFileioReadReq, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  168, 0,   195, 4,   28,  34,  156, 130, 40,  98,  178,
        190, 23,  53,  47,  112, 97,  116, 104, 47,  116, 111, 47,
        115, 111, 109, 101, 47,  102, 105, 108, 101, 0,   86,  100,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.fileio_read_req.chunk_size = 53;

    size_t written;
    EXPECT_TRUE(sbp_msg_fileio_read_req_filename_set(
        &test_msg.fileio_read_req, "/path/to/some/file", false, &written))
        << "Can't assign text";
    EXPECT_EQ(written, strlen("/path/to/some/file"))
        << "Wrote different to expected";
    EXPECT_EQ(
        sbp_msg_fileio_read_req_filename_encoded_len(&test_msg.fileio_read_req),
        19)
        << "String not encoded properly";

    test_msg.fileio_read_req.offset = 398373474;

    test_msg.fileio_read_req.sequence = 679648290;

    sbp_message_send(&sbp_state, SbpMsgFileioReadReq, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgFileioReadReq, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.fileio_read_req.chunk_size, 53)
        << "incorrect value for last_msg.msg.fileio_read_req.chunk_size, "
           "expected 53, is "
        << (int64_t)last_msg.msg.fileio_read_req.chunk_size;

    EXPECT_EQ(sbp_msg_fileio_read_req_filename_encoded_len(
                  &last_msg.msg.fileio_read_req),
              19)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_fileio_read_req_filename_get(
                         &last_msg.msg.fileio_read_req),
                     "/path/to/some/file"),
              0)
        << "String not decoded properly";

    EXPECT_EQ(last_msg.msg.fileio_read_req.offset, 398373474)
        << "incorrect value for last_msg.msg.fileio_read_req.offset, expected "
           "398373474, is "
        << (int64_t)last_msg.msg.fileio_read_req.offset;

    EXPECT_EQ(last_msg.msg.fileio_read_req.sequence, 679648290)
        << "incorrect value for last_msg.msg.fileio_read_req.sequence, "
           "expected 679648290, is "
        << (int64_t)last_msg.msg.fileio_read_req.sequence;
  }
}

}  // namespace
