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
// spec/tests/yaml/swiftnav/sbp/logging/test_MsgPrintDep.yaml by generate.py. Do
// not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/logging.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_logging_MsgPrintDep,
     test_auto_check_sbp_logging_MsgPrintDep) {
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

    sbp_callback_register(&sbp_state, SbpMsgPrintDep, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  16,  0,   34, 34, 43, 73, 78, 70, 79, 58,  32,  97,
        99,  113, 58,  32, 80, 82, 78, 32, 49, 53, 32,  102, 111,
        117, 110, 100, 32, 64, 32, 45, 50, 52, 57, 55,  32,  72,
        122, 44,  32,  50, 48, 32, 83, 78, 82, 10, 116, 103,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    size_t written;
    EXPECT_TRUE(sbp_msg_print_dep_text_set(
        &test_msg.print_dep, "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n",
        false, &written))
        << "Can't assign text";
    EXPECT_EQ(written, strlen("INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n"))
        << "Wrote different to expected";
    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg.print_dep), 43)
        << "String not encoded properly";

    sbp_message_send(&sbp_state, SbpMsgPrintDep, 8738, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 8738)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgPrintDep, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&last_msg.msg.print_dep), 43)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_print_dep_text_get(&last_msg.msg.print_dep),
                     "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n"),
              0)
        << "String not decoded properly";
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

    sbp_callback_register(&sbp_state, SbpMsgPrintDep, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  16,  0,   34, 34, 42, 73, 78, 70, 79,  58, 32,  97,
        99,  113, 58,  32, 80, 82, 78, 32, 51, 49,  32, 102, 111,
        117, 110, 100, 32, 64, 32, 52, 50, 52, 53,  32, 72,  122,
        44,  32,  50,  49, 32, 83, 78, 82, 10, 140, 43,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    size_t written;
    EXPECT_TRUE(sbp_msg_print_dep_text_set(
        &test_msg.print_dep, "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n",
        false, &written))
        << "Can't assign text";
    EXPECT_EQ(written, strlen("INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n"))
        << "Wrote different to expected";
    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg.print_dep), 42)
        << "String not encoded properly";

    sbp_message_send(&sbp_state, SbpMsgPrintDep, 8738, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 8738)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgPrintDep, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&last_msg.msg.print_dep), 42)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_print_dep_text_get(&last_msg.msg.print_dep),
                     "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n"),
              0)
        << "String not decoded properly";
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

    sbp_callback_register(&sbp_state, SbpMsgPrintDep, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 16, 0,   34,  34,  35,  73, 78, 70,  79, 58,  32,  68,  105, 115,
        97, 98, 108, 105, 110, 103, 32, 99, 104, 97, 110, 110, 101, 108, 32,
        48, 32, 40,  80,  82,  78,  32, 49, 49,  41, 10,  23,  143,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    size_t written;
    EXPECT_TRUE(sbp_msg_print_dep_text_set(
        &test_msg.print_dep, "INFO: Disabling channel 0 (PRN 11)\n", false,
        &written))
        << "Can't assign text";
    EXPECT_EQ(written, strlen("INFO: Disabling channel 0 (PRN 11)\n"))
        << "Wrote different to expected";
    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg.print_dep), 35)
        << "String not encoded properly";

    sbp_message_send(&sbp_state, SbpMsgPrintDep, 8738, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 8738)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgPrintDep, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&last_msg.msg.print_dep), 35)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_print_dep_text_get(&last_msg.msg.print_dep),
                     "INFO: Disabling channel 0 (PRN 11)\n"),
              0)
        << "String not decoded properly";
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

    sbp_callback_register(&sbp_state, SbpMsgPrintDep, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  16,  0,  34, 34, 41, 73, 78, 70,  79, 58,  32,  97,
        99,  113, 58, 32, 80, 82, 78, 32, 50,  32, 102, 111, 117,
        110, 100, 32, 64, 32, 51, 57, 57, 54,  32, 72,  122, 44,
        32,  50,  48, 32, 83, 78, 82, 10, 239, 48,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    size_t written;
    EXPECT_TRUE(sbp_msg_print_dep_text_set(
        &test_msg.print_dep, "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n",
        false, &written))
        << "Can't assign text";
    EXPECT_EQ(written, strlen("INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n"))
        << "Wrote different to expected";
    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg.print_dep), 41)
        << "String not encoded properly";

    sbp_message_send(&sbp_state, SbpMsgPrintDep, 8738, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 8738)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgPrintDep, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&last_msg.msg.print_dep), 41)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_print_dep_text_get(&last_msg.msg.print_dep),
                     "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n"),
              0)
        << "String not decoded properly";
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

    sbp_callback_register(&sbp_state, SbpMsgPrintDep, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  16,  0,  34, 34, 42, 73, 78, 70, 79, 58,  32,  97,
        99,  113, 58, 32, 80, 82, 78, 32, 52, 32, 102, 111, 117,
        110, 100, 32, 64, 32, 45, 55, 52, 57, 50, 32,  72,  122,
        44,  32,  50, 48, 32, 83, 78, 82, 10, 47, 248,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    size_t written;
    EXPECT_TRUE(sbp_msg_print_dep_text_set(
        &test_msg.print_dep, "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n",
        false, &written))
        << "Can't assign text";
    EXPECT_EQ(written, strlen("INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n"))
        << "Wrote different to expected";
    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg.print_dep), 42)
        << "String not encoded properly";

    sbp_message_send(&sbp_state, SbpMsgPrintDep, 8738, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 8738)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgPrintDep, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&last_msg.msg.print_dep), 42)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_print_dep_text_get(&last_msg.msg.print_dep),
                     "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n"),
              0)
        << "String not decoded properly";
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

    sbp_callback_register(&sbp_state, SbpMsgPrintDep, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 16, 0,   34,  34,  35,  73, 78, 70,  79, 58,  32,  68,  105, 115,
        97, 98, 108, 105, 110, 103, 32, 99, 104, 97, 110, 110, 101, 108, 32,
        49, 32, 40,  80,  82,  78,  32, 49, 53,  41, 10,  158, 139,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    size_t written;
    EXPECT_TRUE(sbp_msg_print_dep_text_set(
        &test_msg.print_dep, "INFO: Disabling channel 1 (PRN 15)\n", false,
        &written))
        << "Can't assign text";
    EXPECT_EQ(written, strlen("INFO: Disabling channel 1 (PRN 15)\n"))
        << "Wrote different to expected";
    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg.print_dep), 35)
        << "String not encoded properly";

    sbp_message_send(&sbp_state, SbpMsgPrintDep, 8738, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 8738)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgPrintDep, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&last_msg.msg.print_dep), 35)
        << "Invalid encoded len";
    EXPECT_EQ(strcmp(sbp_msg_print_dep_text_get(&last_msg.msg.print_dep),
                     "INFO: Disabling channel 1 (PRN 15)\n"),
              0)
        << "String not decoded properly";
  }
}

}  // namespace
