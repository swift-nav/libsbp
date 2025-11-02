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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepC.yaml by
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

TEST(auto_check_sbp_acquisition_MsgAcqResultDepC,
     test_auto_check_sbp_acquisition_MsgAcqResultDepC) {
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepC, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  31, 0,  40, 12,  16, 72, 9, 34, 66, 155, 152,
        228, 67, 28, 34, 221, 68, 10, 0, 0,  0,  9,   189,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_c.cf = 1769.06591796875;

    test_msg.acq_result_dep_c.cn0 = 40.509063720703125;

    test_msg.acq_result_dep_c.cp = 457.1922302246094;

    test_msg.acq_result_dep_c.sid.code = 0;

    test_msg.acq_result_dep_c.sid.reserved = 0;

    test_msg.acq_result_dep_c.sid.sat = 10;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepC, 3112, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 3112)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepC, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cf * 100 - 1769.06591797 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cf, expected "
           "1769.06591797, is "
        << last_msg.msg.acq_result_dep_c.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cn0 * 100 - 40.5090637207 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cn0, expected "
           "40.5090637207, is "
        << last_msg.msg.acq_result_dep_c.cn0;

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cp * 100 - 457.192230225 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cp, expected "
           "457.192230225, is "
        << last_msg.msg.acq_result_dep_c.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.code, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.code, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.code;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.reserved, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.reserved;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.sat, 10)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.sat, "
           "expected 10, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.sat;
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepC, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 31, 0,  40,  12,  16,  132, 250, 45, 66, 207, 93,
        88, 68, 68, 185, 252, 195, 6,   0,   0,  0,  136, 185,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_c.cf = -505.4473876953125;

    test_msg.acq_result_dep_c.cn0 = 43.49464416503906;

    test_msg.acq_result_dep_c.cp = 865.4657592773438;

    test_msg.acq_result_dep_c.sid.code = 0;

    test_msg.acq_result_dep_c.sid.reserved = 0;

    test_msg.acq_result_dep_c.sid.sat = 6;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepC, 3112, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 3112)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepC, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cf * 100 - -505.447387695 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cf, expected "
           "-505.447387695, is "
        << last_msg.msg.acq_result_dep_c.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cn0 * 100 - 43.494644165 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cn0, expected "
           "43.494644165, is "
        << last_msg.msg.acq_result_dep_c.cn0;

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cp * 100 - 865.465759277 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cp, expected "
           "865.465759277, is "
        << last_msg.msg.acq_result_dep_c.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.code, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.code, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.code;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.reserved, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.reserved;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.sat, 6)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.sat, "
           "expected 6, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.sat;
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepC, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  31, 0,   40,  12,  16,  163, 223, 24, 66, 64,  91,
        102, 67, 202, 243, 157, 196, 13,  0,   0,  0,  150, 161,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_c.cf = -1263.618408203125;

    test_msg.acq_result_dep_c.cn0 = 38.2183952331543;

    test_msg.acq_result_dep_c.cp = 230.3564453125;

    test_msg.acq_result_dep_c.sid.code = 0;

    test_msg.acq_result_dep_c.sid.reserved = 0;

    test_msg.acq_result_dep_c.sid.sat = 13;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepC, 3112, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 3112)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepC, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cf * 100 - -1263.6184082 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cf, expected "
           "-1263.6184082, is "
        << last_msg.msg.acq_result_dep_c.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cn0 * 100 - 38.2183952332 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cn0, expected "
           "38.2183952332, is "
        << last_msg.msg.acq_result_dep_c.cn0;

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cp * 100 - 230.356445312 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cp, expected "
           "230.356445312, is "
        << last_msg.msg.acq_result_dep_c.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.code, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.code, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.code;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.reserved, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.reserved;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.sat, 13)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.sat, "
           "expected 13, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.sat;
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepC, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  31, 0,   40,  12, 16, 129, 65, 21, 66, 224, 214,
        124, 67, 243, 138, 61, 69, 1,   0,  0,  0,  109, 209,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_c.cf = 3032.684326171875;

    test_msg.acq_result_dep_c.cn0 = 37.313968658447266;

    test_msg.acq_result_dep_c.cp = 252.83935546875;

    test_msg.acq_result_dep_c.sid.code = 0;

    test_msg.acq_result_dep_c.sid.reserved = 0;

    test_msg.acq_result_dep_c.sid.sat = 1;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepC, 3112, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 3112)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepC, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cf * 100 - 3032.68432617 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cf, expected "
           "3032.68432617, is "
        << last_msg.msg.acq_result_dep_c.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cn0 * 100 - 37.3139686584 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cn0, expected "
           "37.3139686584, is "
        << last_msg.msg.acq_result_dep_c.cn0;

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cp * 100 - 252.839355469 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cp, expected "
           "252.839355469, is "
        << last_msg.msg.acq_result_dep_c.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.code, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.code, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.code;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.reserved, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.reserved;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.sat, 1)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.sat, "
           "expected 1, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.sat;
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

    sbp_callback_register(&sbp_state, SbpMsgAcqResultDepC, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  31, 0,   40,  12, 16, 126, 35, 62, 66, 226, 37,
        102, 68, 202, 243, 29, 69, 27,  0,  0,  0,  91,  67,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.acq_result_dep_c.cf = 2527.23681640625;

    test_msg.acq_result_dep_c.cn0 = 47.53466033935547;

    test_msg.acq_result_dep_c.cp = 920.5919189453125;

    test_msg.acq_result_dep_c.sid.code = 0;

    test_msg.acq_result_dep_c.sid.reserved = 0;

    test_msg.acq_result_dep_c.sid.sat = 27;

    sbp_message_send(&sbp_state, SbpMsgAcqResultDepC, 3112, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 3112)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqResultDepC, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cf * 100 - 2527.23681641 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cf, expected "
           "2527.23681641, is "
        << last_msg.msg.acq_result_dep_c.cf;

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cn0 * 100 - 47.5346603394 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cn0, expected "
           "47.5346603394, is "
        << last_msg.msg.acq_result_dep_c.cn0;

    EXPECT_LE((last_msg.msg.acq_result_dep_c.cp * 100 - 920.591918945 * 100),
              0.05)
        << "incorrect value for last_msg.msg.acq_result_dep_c.cp, expected "
           "920.591918945, is "
        << last_msg.msg.acq_result_dep_c.cp;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.code, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.code, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.code;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.reserved, 0)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.reserved, "
           "expected 0, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.reserved;

    EXPECT_EQ(last_msg.msg.acq_result_dep_c.sid.sat, 27)
        << "incorrect value for last_msg.msg.acq_result_dep_c.sid.sat, "
           "expected 27, is "
        << (int64_t)last_msg.msg.acq_result_dep_c.sid.sat;
  }
}

}  // namespace
