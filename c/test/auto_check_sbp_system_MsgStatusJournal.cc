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
// spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusJournal.yaml by
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

TEST(auto_check_sbp_system_MsgStatusJournal,
     test_auto_check_sbp_system_MsgStatusJournal) {
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

    sbp_callback_register(&sbp_state, SbpMsgStatusJournal, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 253, 255, 211, 136, 33, 1, 0, 1,  4,   100, 0,   0,   0,
        16, 146, 16,  0,   0,   6,  0, 1, 13, 186, 19,  0,   0,   6,
        0,  1,   14,  184, 34,  0,  0, 6, 0,  1,   15,  113, 119,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.status_journal.journal[0].report.component = 6;

    test_msg.status_journal.journal[0].report.generic = 1;

    test_msg.status_journal.journal[0].report.specific = 13;

    test_msg.status_journal.journal[0].uptime = 4242;

    test_msg.status_journal.journal[1].report.component = 6;

    test_msg.status_journal.journal[1].report.generic = 1;

    test_msg.status_journal.journal[1].report.specific = 14;

    test_msg.status_journal.journal[1].uptime = 5050;

    test_msg.status_journal.journal[2].report.component = 6;

    test_msg.status_journal.journal[2].report.generic = 1;

    test_msg.status_journal.journal[2].report.specific = 15;

    test_msg.status_journal.journal[2].uptime = 8888;

    test_msg.status_journal.n_journal = 3;

    test_msg.status_journal.reporting_system = 1;

    test_msg.status_journal.sbp_version = 1025;

    test_msg.status_journal.sequence_descriptor = 16;

    test_msg.status_journal.total_status_reports = 100;

    sbp_message_send(&sbp_state, SbpMsgStatusJournal, 35027, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgStatusJournal, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.status_journal.journal[0].report.component, 6)
        << "incorrect value for "
           "last_msg.msg.status_journal.journal[0].report.component, expected "
           "6, is "
        << (int64_t)last_msg.msg.status_journal.journal[0].report.component;

    EXPECT_EQ(last_msg.msg.status_journal.journal[0].report.generic, 1)
        << "incorrect value for "
           "last_msg.msg.status_journal.journal[0].report.generic, expected 1, "
           "is "
        << (int64_t)last_msg.msg.status_journal.journal[0].report.generic;

    EXPECT_EQ(last_msg.msg.status_journal.journal[0].report.specific, 13)
        << "incorrect value for "
           "last_msg.msg.status_journal.journal[0].report.specific, expected "
           "13, is "
        << (int64_t)last_msg.msg.status_journal.journal[0].report.specific;

    EXPECT_EQ(last_msg.msg.status_journal.journal[0].uptime, 4242)
        << "incorrect value for last_msg.msg.status_journal.journal[0].uptime, "
           "expected 4242, is "
        << (int64_t)last_msg.msg.status_journal.journal[0].uptime;

    EXPECT_EQ(last_msg.msg.status_journal.journal[1].report.component, 6)
        << "incorrect value for "
           "last_msg.msg.status_journal.journal[1].report.component, expected "
           "6, is "
        << (int64_t)last_msg.msg.status_journal.journal[1].report.component;

    EXPECT_EQ(last_msg.msg.status_journal.journal[1].report.generic, 1)
        << "incorrect value for "
           "last_msg.msg.status_journal.journal[1].report.generic, expected 1, "
           "is "
        << (int64_t)last_msg.msg.status_journal.journal[1].report.generic;

    EXPECT_EQ(last_msg.msg.status_journal.journal[1].report.specific, 14)
        << "incorrect value for "
           "last_msg.msg.status_journal.journal[1].report.specific, expected "
           "14, is "
        << (int64_t)last_msg.msg.status_journal.journal[1].report.specific;

    EXPECT_EQ(last_msg.msg.status_journal.journal[1].uptime, 5050)
        << "incorrect value for last_msg.msg.status_journal.journal[1].uptime, "
           "expected 5050, is "
        << (int64_t)last_msg.msg.status_journal.journal[1].uptime;

    EXPECT_EQ(last_msg.msg.status_journal.journal[2].report.component, 6)
        << "incorrect value for "
           "last_msg.msg.status_journal.journal[2].report.component, expected "
           "6, is "
        << (int64_t)last_msg.msg.status_journal.journal[2].report.component;

    EXPECT_EQ(last_msg.msg.status_journal.journal[2].report.generic, 1)
        << "incorrect value for "
           "last_msg.msg.status_journal.journal[2].report.generic, expected 1, "
           "is "
        << (int64_t)last_msg.msg.status_journal.journal[2].report.generic;

    EXPECT_EQ(last_msg.msg.status_journal.journal[2].report.specific, 15)
        << "incorrect value for "
           "last_msg.msg.status_journal.journal[2].report.specific, expected "
           "15, is "
        << (int64_t)last_msg.msg.status_journal.journal[2].report.specific;

    EXPECT_EQ(last_msg.msg.status_journal.journal[2].uptime, 8888)
        << "incorrect value for last_msg.msg.status_journal.journal[2].uptime, "
           "expected 8888, is "
        << (int64_t)last_msg.msg.status_journal.journal[2].uptime;

    EXPECT_EQ(last_msg.msg.status_journal.n_journal, 3)
        << "incorrect value for last_msg.msg.status_journal.n_journal, "
           "expected 3, is "
        << (int64_t)last_msg.msg.status_journal.n_journal;

    EXPECT_EQ(last_msg.msg.status_journal.reporting_system, 1)
        << "incorrect value for last_msg.msg.status_journal.reporting_system, "
           "expected 1, is "
        << (int64_t)last_msg.msg.status_journal.reporting_system;

    EXPECT_EQ(last_msg.msg.status_journal.sbp_version, 1025)
        << "incorrect value for last_msg.msg.status_journal.sbp_version, "
           "expected 1025, is "
        << (int64_t)last_msg.msg.status_journal.sbp_version;

    EXPECT_EQ(last_msg.msg.status_journal.sequence_descriptor, 16)
        << "incorrect value for "
           "last_msg.msg.status_journal.sequence_descriptor, expected 16, is "
        << (int64_t)last_msg.msg.status_journal.sequence_descriptor;

    EXPECT_EQ(last_msg.msg.status_journal.total_status_reports, 100)
        << "incorrect value for "
           "last_msg.msg.status_journal.total_status_reports, expected 100, is "
        << (int64_t)last_msg.msg.status_journal.total_status_reports;
  }
  // Test successful parsing of a message
  {
    // SBP parser state must be initialized before sbp_process is called.
    // We re-initialize before every test so that callbacks for the same message
    // types can be
    //  allocated multiple times across different tests.
    sbp_state_init(&sbp_state);

    sbp_state_set_io_context(&sbp_state, &DUMMY_MEMORY_FOR_IO);

    logging_reset();

    sbp_callback_register(&sbp_state, SbpMsgStatusJournal, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 253, 255, 211, 136, 17, 1, 0, 1, 4,  100, 0,   0,
        0,  16,  146, 16,  0,   0,  6, 0, 1, 13, 144, 121,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.status_journal.journal[0].report.component = 6;

    test_msg.status_journal.journal[0].report.generic = 1;

    test_msg.status_journal.journal[0].report.specific = 13;

    test_msg.status_journal.journal[0].uptime = 4242;

    test_msg.status_journal.n_journal = 1;

    test_msg.status_journal.reporting_system = 1;

    test_msg.status_journal.sbp_version = 1025;

    test_msg.status_journal.sequence_descriptor = 16;

    test_msg.status_journal.total_status_reports = 100;

    sbp_message_send(&sbp_state, SbpMsgStatusJournal, 35027, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgStatusJournal, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.status_journal.journal[0].report.component, 6)
        << "incorrect value for "
           "last_msg.msg.status_journal.journal[0].report.component, expected "
           "6, is "
        << (int64_t)last_msg.msg.status_journal.journal[0].report.component;

    EXPECT_EQ(last_msg.msg.status_journal.journal[0].report.generic, 1)
        << "incorrect value for "
           "last_msg.msg.status_journal.journal[0].report.generic, expected 1, "
           "is "
        << (int64_t)last_msg.msg.status_journal.journal[0].report.generic;

    EXPECT_EQ(last_msg.msg.status_journal.journal[0].report.specific, 13)
        << "incorrect value for "
           "last_msg.msg.status_journal.journal[0].report.specific, expected "
           "13, is "
        << (int64_t)last_msg.msg.status_journal.journal[0].report.specific;

    EXPECT_EQ(last_msg.msg.status_journal.journal[0].uptime, 4242)
        << "incorrect value for last_msg.msg.status_journal.journal[0].uptime, "
           "expected 4242, is "
        << (int64_t)last_msg.msg.status_journal.journal[0].uptime;

    EXPECT_EQ(last_msg.msg.status_journal.n_journal, 1)
        << "incorrect value for last_msg.msg.status_journal.n_journal, "
           "expected 1, is "
        << (int64_t)last_msg.msg.status_journal.n_journal;

    EXPECT_EQ(last_msg.msg.status_journal.reporting_system, 1)
        << "incorrect value for last_msg.msg.status_journal.reporting_system, "
           "expected 1, is "
        << (int64_t)last_msg.msg.status_journal.reporting_system;

    EXPECT_EQ(last_msg.msg.status_journal.sbp_version, 1025)
        << "incorrect value for last_msg.msg.status_journal.sbp_version, "
           "expected 1025, is "
        << (int64_t)last_msg.msg.status_journal.sbp_version;

    EXPECT_EQ(last_msg.msg.status_journal.sequence_descriptor, 16)
        << "incorrect value for "
           "last_msg.msg.status_journal.sequence_descriptor, expected 16, is "
        << (int64_t)last_msg.msg.status_journal.sequence_descriptor;

    EXPECT_EQ(last_msg.msg.status_journal.total_status_reports, 100)
        << "incorrect value for "
           "last_msg.msg.status_journal.total_status_reports, expected 100, is "
        << (int64_t)last_msg.msg.status_journal.total_status_reports;
  }
}

}  // namespace
