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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/acquisition.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_acquisition_MsgAcqResultDepA,
     test_auto_check_sbp_acquisition_MsgAcqResultDepA) {
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  21, 0,  195, 4,   13, 0,  0, 104, 65, 0,
        192, 53, 68, 198, 199, 0,  70, 8, 2,   68,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_a.cf = 8241.943359375;

    test_msg.acq_result_dep_a.cp = 727.0;

    test_msg.acq_result_dep_a.prn = 8;

    test_msg.acq_result_dep_a.snr = 14.5;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepA, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_a.cf * 100 - 8241.94335938 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.cf, expected "
           "8241.94335938, is "
        << last_msg.msg.acq_result_dep_a.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_a.cp * 100 - 727.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.cp, expected "
           "727.0, is "
        << last_msg.msg.acq_result_dep_a.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_a.prn, 8)
        << "incorrect value for last_msg.msg.acq_result_dep_a.prn, expected 8, "
           "is "
        << (int64_t)last_msg.msg.acq_result_dep_a.prn;

    EXPECT_LE((last_msg.msg.acq_result_dep_a.snr * 100 - 14.5 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.snr, expected "
           "14.5, is "
        << last_msg.msg.acq_result_dep_a.snr;
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  21,  0,  195, 4,  13, 205, 204, 116, 65, 0,
        192, 179, 67, 33,  81, 59, 68,  9,   219, 27,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_a.cf = 749.2676391601562;

    test_msg.acq_result_dep_a.cp = 359.5;

    test_msg.acq_result_dep_a.prn = 9;

    test_msg.acq_result_dep_a.snr = 15.300000190734863;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepA, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_a.cf * 100 - 749.26763916 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.cf, expected "
           "749.26763916, is "
        << last_msg.msg.acq_result_dep_a.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_a.cp * 100 - 359.5 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.cp, expected "
           "359.5, is "
        << last_msg.msg.acq_result_dep_a.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_a.prn, 9)
        << "incorrect value for last_msg.msg.acq_result_dep_a.prn, expected 9, "
           "is "
        << (int64_t)last_msg.msg.acq_result_dep_a.prn;

    EXPECT_LE((last_msg.msg.acq_result_dep_a.snr * 100 - 15.3000001907 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.snr, expected "
           "15.3000001907, is "
        << last_msg.msg.acq_result_dep_a.snr;
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 21, 0,  195, 4,   13,  205, 204, 144, 65, 0,
        0,  34, 66, 57,  237, 202, 197, 11,  150, 35,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_a.cf = -6493.65283203125;

    test_msg.acq_result_dep_a.cp = 40.5;

    test_msg.acq_result_dep_a.prn = 11;

    test_msg.acq_result_dep_a.snr = 18.100000381469727;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepA, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_a.cf * 100 - -6493.65283203 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.cf, expected "
           "-6493.65283203, is "
        << last_msg.msg.acq_result_dep_a.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_a.cp * 100 - 40.5 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.cp, expected "
           "40.5, is "
        << last_msg.msg.acq_result_dep_a.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_a.prn, 11)
        << "incorrect value for last_msg.msg.acq_result_dep_a.prn, expected "
           "11, is "
        << (int64_t)last_msg.msg.acq_result_dep_a.prn;

    EXPECT_LE((last_msg.msg.acq_result_dep_a.snr * 100 - 18.1000003815 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.snr, expected "
           "18.1000003815, is "
        << last_msg.msg.acq_result_dep_a.snr;
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 21, 0,  195, 4,   13,  205, 204, 116, 65,  0,
        32, 9,  68, 129, 193, 121, 196, 12,  146, 118,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_a.cf = -999.0234985351562;

    test_msg.acq_result_dep_a.cp = 548.5;

    test_msg.acq_result_dep_a.prn = 12;

    test_msg.acq_result_dep_a.snr = 15.300000190734863;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepA, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_a.cf * 100 - -999.023498535 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.cf, expected "
           "-999.023498535, is "
        << last_msg.msg.acq_result_dep_a.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_a.cp * 100 - 548.5 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.cp, expected "
           "548.5, is "
        << last_msg.msg.acq_result_dep_a.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_a.prn, 12)
        << "incorrect value for last_msg.msg.acq_result_dep_a.prn, expected "
           "12, is "
        << (int64_t)last_msg.msg.acq_result_dep_a.prn;

    EXPECT_LE((last_msg.msg.acq_result_dep_a.snr * 100 - 15.3000001907 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.snr, expected "
           "15.3000001907, is "
        << last_msg.msg.acq_result_dep_a.snr;
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 21, 0,  195, 4,  13,  205, 204, 116, 65, 0,
        32, 67, 68, 228, 74, 148, 69,  14,  23,  75,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_a.cf = 4745.361328125;

    test_msg.acq_result_dep_a.cp = 780.5;

    test_msg.acq_result_dep_a.prn = 14;

    test_msg.acq_result_dep_a.snr = 15.300000190734863;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepA, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_a.cf * 100 - 4745.36132812 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.cf, expected "
           "4745.36132812, is "
        << last_msg.msg.acq_result_dep_a.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_a.cp * 100 - 780.5 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.cp, expected "
           "780.5, is "
        << last_msg.msg.acq_result_dep_a.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_a.prn, 14)
        << "incorrect value for last_msg.msg.acq_result_dep_a.prn, expected "
           "14, is "
        << (int64_t)last_msg.msg.acq_result_dep_a.prn;

    EXPECT_LE((last_msg.msg.acq_result_dep_a.snr * 100 - 15.3000001907 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.snr, expected "
           "15.3000001907, is "
        << last_msg.msg.acq_result_dep_a.snr;
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepA, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 21, 0,  195, 4,   13,  228, 56, 35,  67,  0,
        32, 18, 68, 129, 193, 249, 195, 0,  204, 207,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_a.cf = -499.5117492675781;

    test_msg.acq_result_dep_a.cp = 584.5;

    test_msg.acq_result_dep_a.prn = 0;

    test_msg.acq_result_dep_a.snr = 163.22222900390625;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepA, 1219, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepA, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_a.cf * 100 - -499.511749268 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.cf, expected "
           "-499.511749268, is "
        << last_msg.msg.acq_result_dep_a.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_a.cp * 100 - 584.5 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.cp, expected "
           "584.5, is "
        << last_msg.msg.acq_result_dep_a.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_a.prn, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_a.prn, expected 0, "
           "is "
        << (int64_t)last_msg.msg.acq_result_dep_a.prn;

    EXPECT_LE((last_msg.msg.acq_result_dep_a.snr * 100 - 163.222229004 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_a.snr, expected "
           "163.222229004, is "
        << last_msg.msg.acq_result_dep_a.snr;
  }
}

}  // namespace
