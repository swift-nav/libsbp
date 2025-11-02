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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTimeGNSS.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/navigation.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_navigation_MsgGPSTimeGNSS,
     test_auto_check_sbp_navigation_MsgGPSTimeGNSS) {
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

    sbp_callback_register(&sbp_state, SbpMsgGpsTimeGnss, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,  1,   211, 136, 11, 128, 7,   40, 244,
        122, 19, 244, 139, 2,   0,  0,   153, 88,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_gnss.flags = 0;

    test_msg.gps_time_gnss.ns_residual = 166900;

    test_msg.gps_time_gnss.tow = 326825000;

    test_msg.gps_time_gnss.wn = 1920;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeGnss, 35027, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgGpsTimeGnss, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.gps_time_gnss.flags, 0)
        << "incorrect value for last_msg.msg.gps_time_gnss.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.gps_time_gnss.flags;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.ns_residual, 166900)
        << "incorrect value for last_msg.msg.gps_time_gnss.ns_residual, "
           "expected 166900, is "
        << (int64_t)last_msg.msg.gps_time_gnss.ns_residual;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.tow, 326825000)
        << "incorrect value for last_msg.msg.gps_time_gnss.tow, expected "
           "326825000, is "
        << (int64_t)last_msg.msg.gps_time_gnss.tow;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.wn, 1920)
        << "incorrect value for last_msg.msg.gps_time_gnss.wn, expected 1920, "
           "is "
        << (int64_t)last_msg.msg.gps_time_gnss.wn;
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

    sbp_callback_register(&sbp_state, SbpMsgGpsTimeGnss, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,  1,   211, 136, 11, 128, 7,   28,  246,
        122, 19, 126, 234, 3,   0,  0,   250, 195,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_gnss.flags = 0;

    test_msg.gps_time_gnss.ns_residual = 256638;

    test_msg.gps_time_gnss.tow = 326825500;

    test_msg.gps_time_gnss.wn = 1920;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeGnss, 35027, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgGpsTimeGnss, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.gps_time_gnss.flags, 0)
        << "incorrect value for last_msg.msg.gps_time_gnss.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.gps_time_gnss.flags;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.ns_residual, 256638)
        << "incorrect value for last_msg.msg.gps_time_gnss.ns_residual, "
           "expected 256638, is "
        << (int64_t)last_msg.msg.gps_time_gnss.ns_residual;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.tow, 326825500)
        << "incorrect value for last_msg.msg.gps_time_gnss.tow, expected "
           "326825500, is "
        << (int64_t)last_msg.msg.gps_time_gnss.tow;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.wn, 1920)
        << "incorrect value for last_msg.msg.gps_time_gnss.wn, expected 1920, "
           "is "
        << (int64_t)last_msg.msg.gps_time_gnss.wn;
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

    sbp_callback_register(&sbp_state, SbpMsgGpsTimeGnss, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,  1,   211, 136, 11, 128, 7,   16,  248,
        122, 19, 129, 12,  4,   0,  0,   183, 148,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_gnss.flags = 0;

    test_msg.gps_time_gnss.ns_residual = 265345;

    test_msg.gps_time_gnss.tow = 326826000;

    test_msg.gps_time_gnss.wn = 1920;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeGnss, 35027, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgGpsTimeGnss, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.gps_time_gnss.flags, 0)
        << "incorrect value for last_msg.msg.gps_time_gnss.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.gps_time_gnss.flags;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.ns_residual, 265345)
        << "incorrect value for last_msg.msg.gps_time_gnss.ns_residual, "
           "expected 265345, is "
        << (int64_t)last_msg.msg.gps_time_gnss.ns_residual;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.tow, 326826000)
        << "incorrect value for last_msg.msg.gps_time_gnss.tow, expected "
           "326826000, is "
        << (int64_t)last_msg.msg.gps_time_gnss.tow;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.wn, 1920)
        << "incorrect value for last_msg.msg.gps_time_gnss.wn, expected 1920, "
           "is "
        << (int64_t)last_msg.msg.gps_time_gnss.wn;
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

    sbp_callback_register(&sbp_state, SbpMsgGpsTimeGnss, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,  1,   211, 136, 11, 128, 7,   4,   250,
        122, 19, 137, 204, 4,   0,  0,   137, 101,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_gnss.flags = 0;

    test_msg.gps_time_gnss.ns_residual = 314505;

    test_msg.gps_time_gnss.tow = 326826500;

    test_msg.gps_time_gnss.wn = 1920;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeGnss, 35027, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgGpsTimeGnss, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.gps_time_gnss.flags, 0)
        << "incorrect value for last_msg.msg.gps_time_gnss.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.gps_time_gnss.flags;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.ns_residual, 314505)
        << "incorrect value for last_msg.msg.gps_time_gnss.ns_residual, "
           "expected 314505, is "
        << (int64_t)last_msg.msg.gps_time_gnss.ns_residual;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.tow, 326826500)
        << "incorrect value for last_msg.msg.gps_time_gnss.tow, expected "
           "326826500, is "
        << (int64_t)last_msg.msg.gps_time_gnss.tow;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.wn, 1920)
        << "incorrect value for last_msg.msg.gps_time_gnss.wn, expected 1920, "
           "is "
        << (int64_t)last_msg.msg.gps_time_gnss.wn;
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

    sbp_callback_register(&sbp_state, SbpMsgGpsTimeGnss, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  4,  1,   211, 136, 11, 128, 7,  248, 251,
        122, 19, 181, 137, 5,   0,  0,   15, 225,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gps_time_gnss.flags = 0;

    test_msg.gps_time_gnss.ns_residual = 362933;

    test_msg.gps_time_gnss.tow = 326827000;

    test_msg.gps_time_gnss.wn = 1920;

    sbp_message_send(&sbp_state, SbpMsgGpsTimeGnss, 35027, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgGpsTimeGnss, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.gps_time_gnss.flags, 0)
        << "incorrect value for last_msg.msg.gps_time_gnss.flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.gps_time_gnss.flags;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.ns_residual, 362933)
        << "incorrect value for last_msg.msg.gps_time_gnss.ns_residual, "
           "expected 362933, is "
        << (int64_t)last_msg.msg.gps_time_gnss.ns_residual;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.tow, 326827000)
        << "incorrect value for last_msg.msg.gps_time_gnss.tow, expected "
           "326827000, is "
        << (int64_t)last_msg.msg.gps_time_gnss.tow;

    EXPECT_EQ(last_msg.msg.gps_time_gnss.wn, 1920)
        << "incorrect value for last_msg.msg.gps_time_gnss.wn, expected 1920, "
           "is "
        << (int64_t)last_msg.msg.gps_time_gnss.wn;
  }
}

}  // namespace
