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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepB.yaml by
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

TEST(auto_check_sbp_acquisition_MsgAcqResultDepB,
     test_auto_check_sbp_acquisition_MsgAcqResultDepB) {
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepB, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  20, 0,   246, 215, 16, 137, 167, 18, 66, 0,  0,
        161, 67, 240, 24,  156, 69, 9,   0,   0,  0,  80, 195,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_b.cf = 4995.1171875;

    test_msg.acq_result_dep_b.cp = 322.0;

    test_msg.acq_result_dep_b.sid.code = 0;

    test_msg.acq_result_dep_b.sid.reserved = 0;

    test_msg.acq_result_dep_b.sid.sat = 9;

    test_msg.acq_result_dep_b.snr = 36.66360855102539;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepB, 55286, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepB, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_b.cf * 100 - 4995.1171875 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.cf, expected "
           "4995.1171875, is "
        << last_msg.msg.acq_result_dep_b.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_b.cp * 100 - 322.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.cp, expected "
           "322.0, is "
        << last_msg.msg.acq_result_dep_b.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.code, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.code, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.code;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.reserved, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.reserved;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.sat, 9)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.sat, "
           "expected 9, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.sat;

    EXPECT_LE((last_msg.msg.acq_result_dep_b.snr * 100 - 36.663608551 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.snr, expected "
           "36.663608551, is "
        << last_msg.msg.acq_result_dep_b.snr;
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepB, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 20, 0,   246, 215, 16,  206, 172, 16, 66, 0,   192,
        82, 68, 198, 199, 0,   198, 3,   0,   0,  0,  149, 143,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_b.cf = -8241.943359375;

    test_msg.acq_result_dep_b.cp = 843.0;

    test_msg.acq_result_dep_b.sid.code = 0;

    test_msg.acq_result_dep_b.sid.reserved = 0;

    test_msg.acq_result_dep_b.sid.sat = 3;

    test_msg.acq_result_dep_b.snr = 36.16875457763672;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepB, 55286, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepB, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_b.cf * 100 - -8241.94335938 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.cf, expected "
           "-8241.94335938, is "
        << last_msg.msg.acq_result_dep_b.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_b.cp * 100 - 843.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.cp, expected "
           "843.0, is "
        << last_msg.msg.acq_result_dep_b.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.code, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.code, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.code;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.reserved, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.reserved;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.sat, 3)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.sat, "
           "expected 3, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.sat;

    EXPECT_LE((last_msg.msg.acq_result_dep_b.snr * 100 - 36.1687545776 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.snr, expected "
           "36.1687545776, is "
        << last_msg.msg.acq_result_dep_b.snr;
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepB, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 20, 0,   246, 215, 16, 228, 27, 15, 66, 0,   128,
        70, 68, 228, 74,  148, 69, 18,  0,  0,  0,  179, 155,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_b.cf = 4745.361328125;

    test_msg.acq_result_dep_b.cp = 794.0;

    test_msg.acq_result_dep_b.sid.code = 0;

    test_msg.acq_result_dep_b.sid.reserved = 0;

    test_msg.acq_result_dep_b.sid.sat = 18;

    test_msg.acq_result_dep_b.snr = 35.77723693847656;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepB, 55286, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepB, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_b.cf * 100 - 4745.36132812 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.cf, expected "
           "4745.36132812, is "
        << last_msg.msg.acq_result_dep_b.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_b.cp * 100 - 794.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.cp, expected "
           "794.0, is "
        << last_msg.msg.acq_result_dep_b.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.code, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.code, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.code;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.reserved, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.reserved;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.sat, 18)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.sat, "
           "expected 18, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.sat;

    EXPECT_LE((last_msg.msg.acq_result_dep_b.snr * 100 - 35.7772369385 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.snr, expected "
           "35.7772369385, is "
        << last_msg.msg.acq_result_dep_b.snr;
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepB, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  20, 0,   246, 215, 16, 46, 199, 14, 66, 0,  64,
        129, 67, 240, 24,  28,  69, 17, 0,   0,  0,  18, 181,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_b.cf = 2497.55859375;

    test_msg.acq_result_dep_b.cp = 258.5;

    test_msg.acq_result_dep_b.sid.code = 0;

    test_msg.acq_result_dep_b.sid.reserved = 0;

    test_msg.acq_result_dep_b.sid.sat = 17;

    test_msg.acq_result_dep_b.snr = 35.69451141357422;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepB, 55286, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepB, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_b.cf * 100 - 2497.55859375 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.cf, expected "
           "2497.55859375, is "
        << last_msg.msg.acq_result_dep_b.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_b.cp * 100 - 258.5 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.cp, expected "
           "258.5, is "
        << last_msg.msg.acq_result_dep_b.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.code, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.code, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.code;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.reserved, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.reserved;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.sat, 17)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.sat, "
           "expected 17, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.sat;

    EXPECT_LE((last_msg.msg.acq_result_dep_b.snr * 100 - 35.6945114136 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.snr, expected "
           "35.6945114136, is "
        << last_msg.msg.acq_result_dep_b.snr;
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepB, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 20, 0,   246, 215, 16,  194, 24, 14, 66, 0,  128,
        2,  68, 129, 193, 249, 195, 5,   0,  0,  0,  35, 203,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_b.cf = -499.5117492675781;

    test_msg.acq_result_dep_b.cp = 522.0;

    test_msg.acq_result_dep_b.sid.code = 0;

    test_msg.acq_result_dep_b.sid.reserved = 0;

    test_msg.acq_result_dep_b.sid.sat = 5;

    test_msg.acq_result_dep_b.snr = 35.52417755126953;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepB, 55286, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 55286)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepB, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_b.cf * 100 - -499.511749268 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.cf, expected "
           "-499.511749268, is "
        << last_msg.msg.acq_result_dep_b.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_b.cp * 100 - 522.0 * 100), 0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.cp, expected "
           "522.0, is "
        << last_msg.msg.acq_result_dep_b.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.code, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.code, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.code;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.reserved, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.reserved;

    EXPECT_EQ(last_msg.msg.acq_result_dep_b.sid.sat, 5)
        << "incorrect value for last_msg.msg.acq_result_dep_b.sid.sat, "
           "expected 5, is "
        << (int64_t)last_msg.msg.acq_result_dep_b.sid.sat;

    EXPECT_LE((last_msg.msg.acq_result_dep_b.snr * 100 - 35.5241775513 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_b.snr, expected "
           "35.5241775513, is "
        << last_msg.msg.acq_result_dep_b.snr;
  }
}

}  // namespace
