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
// spec/tests/yaml/swiftnav/sbp/ndb/test_MsgNdbEvent.yaml by generate.py. Do not
// modify by hand!

#include <gtest/gtest.h>
#include <libsbp/ndb.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_ndb_MsgNdbEvent, test_auto_check_sbp_ndb_MsgNdbEvent) {
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

    sbp_callback_register(&sbp_state, SbpMsgNdbEvent, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 0,   4,  164, 174, 18,  254, 188, 70, 185, 69,  0,  0,
        0,  249, 73, 205, 115, 238, 74,  98,  66, 182, 148, 16, 166,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ndb_event.data_source = 115;

    test_msg.ndb_event.event = 249;

    test_msg.ndb_event.object_sid.code = 74;

    test_msg.ndb_event.object_sid.sat = 238;

    test_msg.ndb_event.object_type = 73;

    test_msg.ndb_event.original_sender = 38070;

    test_msg.ndb_event.recv_time = 299461164286;

    test_msg.ndb_event.result = 205;

    test_msg.ndb_event.src_sid.code = 66;

    test_msg.ndb_event.src_sid.sat = 98;

    sbp_message_send(&sbp_state, SbpMsgNdbEvent, 44708, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 44708)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgNdbEvent, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ndb_event.data_source, 115)
        << "incorrect value for last_msg.msg.ndb_event.data_source, expected "
           "115, is "
        << (int64_t)last_msg.msg.ndb_event.data_source;

    EXPECT_EQ(last_msg.msg.ndb_event.event, 249)
        << "incorrect value for last_msg.msg.ndb_event.event, expected 249, is "
        << (int64_t)last_msg.msg.ndb_event.event;

    EXPECT_EQ(last_msg.msg.ndb_event.object_sid.code, 74)
        << "incorrect value for last_msg.msg.ndb_event.object_sid.code, "
           "expected 74, is "
        << (int64_t)last_msg.msg.ndb_event.object_sid.code;

    EXPECT_EQ(last_msg.msg.ndb_event.object_sid.sat, 238)
        << "incorrect value for last_msg.msg.ndb_event.object_sid.sat, "
           "expected 238, is "
        << (int64_t)last_msg.msg.ndb_event.object_sid.sat;

    EXPECT_EQ(last_msg.msg.ndb_event.object_type, 73)
        << "incorrect value for last_msg.msg.ndb_event.object_type, expected "
           "73, is "
        << (int64_t)last_msg.msg.ndb_event.object_type;

    EXPECT_EQ(last_msg.msg.ndb_event.original_sender, 38070)
        << "incorrect value for last_msg.msg.ndb_event.original_sender, "
           "expected 38070, is "
        << (int64_t)last_msg.msg.ndb_event.original_sender;

    EXPECT_EQ(last_msg.msg.ndb_event.recv_time, 299461164286)
        << "incorrect value for last_msg.msg.ndb_event.recv_time, expected "
           "299461164286, is "
        << (int64_t)last_msg.msg.ndb_event.recv_time;

    EXPECT_EQ(last_msg.msg.ndb_event.result, 205)
        << "incorrect value for last_msg.msg.ndb_event.result, expected 205, "
           "is "
        << (int64_t)last_msg.msg.ndb_event.result;

    EXPECT_EQ(last_msg.msg.ndb_event.src_sid.code, 66)
        << "incorrect value for last_msg.msg.ndb_event.src_sid.code, expected "
           "66, is "
        << (int64_t)last_msg.msg.ndb_event.src_sid.code;

    EXPECT_EQ(last_msg.msg.ndb_event.src_sid.sat, 98)
        << "incorrect value for last_msg.msg.ndb_event.src_sid.sat, expected "
           "98, is "
        << (int64_t)last_msg.msg.ndb_event.src_sid.sat;
  }
}

}  // namespace
