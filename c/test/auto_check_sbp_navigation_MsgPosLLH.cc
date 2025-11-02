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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLH.yaml by generate.py.
// Do not modify by hand!

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

TEST(auto_check_sbp_navigation_MsgPosLLH,
     test_auto_check_sbp_navigation_MsgPosLLH) {
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

    sbp_callback_register(&sbp_state, SbpMsgPosLlh, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  10,  2,  211, 136, 34,  40, 244, 122, 19,  201, 106, 155, 186,
        42,  160, 66, 64,  168, 109, 26, 225, 0,   120, 94,  192, 130, 102,
        237, 230, 43, 54,  60,  64,  0,  0,   0,   0,   14,  2,   175, 162,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh.flags = 2;

    test_msg.pos_llh.h_accuracy = 0;

    test_msg.pos_llh.height = 28.21160739227208;

    test_msg.pos_llh.lat = 37.25130398358085;

    test_msg.pos_llh.lon = -121.87505366879361;

    test_msg.pos_llh.n_sats = 14;

    test_msg.pos_llh.tow = 326825000;

    test_msg.pos_llh.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlh, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.pos_llh.flags, 2)
        << "incorrect value for last_msg.msg.pos_llh.flags, expected 2, is "
        << (int64_t)last_msg.msg.pos_llh.flags;

    EXPECT_EQ(last_msg.msg.pos_llh.h_accuracy, 0)
        << "incorrect value for last_msg.msg.pos_llh.h_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.h_accuracy;

    EXPECT_LE((last_msg.msg.pos_llh.height * 100 - 28.2116073923 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.height, expected "
           "28.2116073923, is "
        << last_msg.msg.pos_llh.height;

    EXPECT_LE((last_msg.msg.pos_llh.lat * 100 - 37.2513039836 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.lat, expected "
           "37.2513039836, is "
        << last_msg.msg.pos_llh.lat;

    EXPECT_LE((last_msg.msg.pos_llh.lon * 100 - -121.875053669 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.lon, expected "
           "-121.875053669, is "
        << last_msg.msg.pos_llh.lon;

    EXPECT_EQ(last_msg.msg.pos_llh.n_sats, 14)
        << "incorrect value for last_msg.msg.pos_llh.n_sats, expected 14, is "
        << (int64_t)last_msg.msg.pos_llh.n_sats;

    EXPECT_EQ(last_msg.msg.pos_llh.tow, 326825000)
        << "incorrect value for last_msg.msg.pos_llh.tow, expected 326825000, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.tow;

    EXPECT_EQ(last_msg.msg.pos_llh.v_accuracy, 0)
        << "incorrect value for last_msg.msg.pos_llh.v_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.v_accuracy;
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

    sbp_callback_register(&sbp_state, SbpMsgPosLlh, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  10,  2,   211, 136, 34, 16, 248, 122, 19,  52, 177, 251, 178,
        42,  160, 66,  64,  237, 22, 97, 224, 0,   120, 94, 192, 107, 188,
        109, 90,  247, 189, 59,  64, 0,  0,   0,   0,   15, 2,   38,  177,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh.flags = 2;

    test_msg.pos_llh.h_accuracy = 0;

    test_msg.pos_llh.height = 27.742055560866373;

    test_msg.pos_llh.lat = 37.251303074738104;

    test_msg.pos_llh.lon = -121.87505349618341;

    test_msg.pos_llh.n_sats = 15;

    test_msg.pos_llh.tow = 326826000;

    test_msg.pos_llh.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlh, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.pos_llh.flags, 2)
        << "incorrect value for last_msg.msg.pos_llh.flags, expected 2, is "
        << (int64_t)last_msg.msg.pos_llh.flags;

    EXPECT_EQ(last_msg.msg.pos_llh.h_accuracy, 0)
        << "incorrect value for last_msg.msg.pos_llh.h_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.h_accuracy;

    EXPECT_LE((last_msg.msg.pos_llh.height * 100 - 27.7420555609 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.height, expected "
           "27.7420555609, is "
        << last_msg.msg.pos_llh.height;

    EXPECT_LE((last_msg.msg.pos_llh.lat * 100 - 37.2513030747 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.lat, expected "
           "37.2513030747, is "
        << last_msg.msg.pos_llh.lat;

    EXPECT_LE((last_msg.msg.pos_llh.lon * 100 - -121.875053496 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.lon, expected "
           "-121.875053496, is "
        << last_msg.msg.pos_llh.lon;

    EXPECT_EQ(last_msg.msg.pos_llh.n_sats, 15)
        << "incorrect value for last_msg.msg.pos_llh.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.pos_llh.n_sats;

    EXPECT_EQ(last_msg.msg.pos_llh.tow, 326826000)
        << "incorrect value for last_msg.msg.pos_llh.tow, expected 326826000, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.tow;

    EXPECT_EQ(last_msg.msg.pos_llh.v_accuracy, 0)
        << "incorrect value for last_msg.msg.pos_llh.v_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.v_accuracy;
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

    sbp_callback_register(&sbp_state, SbpMsgPosLlh, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  10,  2,  211, 136, 34, 248, 251, 122, 19,  135, 66,  9,  163,
        42,  160, 66, 64,  146, 8,  99,  225, 0,   120, 94,  192, 45, 181,
        143, 219, 28, 157, 59,  64, 0,   0,   0,   0,   15,  2,   51, 40,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh.flags = 2;

    test_msg.pos_llh.h_accuracy = 0;

    test_msg.pos_llh.height = 27.613721582970516;

    test_msg.pos_llh.lat = 37.25130117370741;

    test_msg.pos_llh.lon = -121.87505373641241;

    test_msg.pos_llh.n_sats = 15;

    test_msg.pos_llh.tow = 326827000;

    test_msg.pos_llh.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlh, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.pos_llh.flags, 2)
        << "incorrect value for last_msg.msg.pos_llh.flags, expected 2, is "
        << (int64_t)last_msg.msg.pos_llh.flags;

    EXPECT_EQ(last_msg.msg.pos_llh.h_accuracy, 0)
        << "incorrect value for last_msg.msg.pos_llh.h_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.h_accuracy;

    EXPECT_LE((last_msg.msg.pos_llh.height * 100 - 27.613721583 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.height, expected "
           "27.613721583, is "
        << last_msg.msg.pos_llh.height;

    EXPECT_LE((last_msg.msg.pos_llh.lat * 100 - 37.2513011737 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.lat, expected "
           "37.2513011737, is "
        << last_msg.msg.pos_llh.lat;

    EXPECT_LE((last_msg.msg.pos_llh.lon * 100 - -121.875053736 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.lon, expected "
           "-121.875053736, is "
        << last_msg.msg.pos_llh.lon;

    EXPECT_EQ(last_msg.msg.pos_llh.n_sats, 15)
        << "incorrect value for last_msg.msg.pos_llh.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.pos_llh.n_sats;

    EXPECT_EQ(last_msg.msg.pos_llh.tow, 326827000)
        << "incorrect value for last_msg.msg.pos_llh.tow, expected 326827000, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.tow;

    EXPECT_EQ(last_msg.msg.pos_llh.v_accuracy, 0)
        << "incorrect value for last_msg.msg.pos_llh.v_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.v_accuracy;
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

    sbp_callback_register(&sbp_state, SbpMsgPosLlh, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 10,  2,   211, 136, 34,  224, 255, 122, 19,  18, 44,  253, 119,
        42, 160, 66,  64,  48,  109, 39,  231, 0,   120, 94, 192, 185, 76,
        48, 17,  119, 205, 59,  64,  0,   0,   0,   0,   15, 2,   12,  194,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh.flags = 2;

    test_msg.pos_llh.h_accuracy = 0;

    test_msg.pos_llh.height = 27.80259807042305;

    test_msg.pos_llh.lat = 37.251296042079176;

    test_msg.pos_llh.lon = -121.87505511141057;

    test_msg.pos_llh.n_sats = 15;

    test_msg.pos_llh.tow = 326828000;

    test_msg.pos_llh.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlh, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.pos_llh.flags, 2)
        << "incorrect value for last_msg.msg.pos_llh.flags, expected 2, is "
        << (int64_t)last_msg.msg.pos_llh.flags;

    EXPECT_EQ(last_msg.msg.pos_llh.h_accuracy, 0)
        << "incorrect value for last_msg.msg.pos_llh.h_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.h_accuracy;

    EXPECT_LE((last_msg.msg.pos_llh.height * 100 - 27.8025980704 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.height, expected "
           "27.8025980704, is "
        << last_msg.msg.pos_llh.height;

    EXPECT_LE((last_msg.msg.pos_llh.lat * 100 - 37.2512960421 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.lat, expected "
           "37.2512960421, is "
        << last_msg.msg.pos_llh.lat;

    EXPECT_LE((last_msg.msg.pos_llh.lon * 100 - -121.875055111 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.lon, expected "
           "-121.875055111, is "
        << last_msg.msg.pos_llh.lon;

    EXPECT_EQ(last_msg.msg.pos_llh.n_sats, 15)
        << "incorrect value for last_msg.msg.pos_llh.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.pos_llh.n_sats;

    EXPECT_EQ(last_msg.msg.pos_llh.tow, 326828000)
        << "incorrect value for last_msg.msg.pos_llh.tow, expected 326828000, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.tow;

    EXPECT_EQ(last_msg.msg.pos_llh.v_accuracy, 0)
        << "incorrect value for last_msg.msg.pos_llh.v_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.v_accuracy;
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

    sbp_callback_register(&sbp_state, SbpMsgPosLlh, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  10,  2,   211, 136, 34,  200, 3,   123, 19,  225, 237, 238, 90,
        42,  160, 66,  64,  59,  143, 70,  235, 0,   120, 94,  192, 101, 106,
        249, 224, 131, 240, 59,  64,  0,   0,   0,   0,   15,  2,   34,  103,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.pos_llh.flags = 2;

    test_msg.pos_llh.h_accuracy = 0;

    test_msg.pos_llh.height = 27.939512310879213;

    test_msg.pos_llh.lat = 37.251292578377395;

    test_msg.pos_llh.lon = -121.87505609407974;

    test_msg.pos_llh.n_sats = 15;

    test_msg.pos_llh.tow = 326829000;

    test_msg.pos_llh.v_accuracy = 0;

    sbp_message_send(&sbp_state, SbpMsgPosLlh, 35027, &test_msg, &dummy_write);

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

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.pos_llh.flags, 2)
        << "incorrect value for last_msg.msg.pos_llh.flags, expected 2, is "
        << (int64_t)last_msg.msg.pos_llh.flags;

    EXPECT_EQ(last_msg.msg.pos_llh.h_accuracy, 0)
        << "incorrect value for last_msg.msg.pos_llh.h_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.h_accuracy;

    EXPECT_LE((last_msg.msg.pos_llh.height * 100 - 27.9395123109 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.height, expected "
           "27.9395123109, is "
        << last_msg.msg.pos_llh.height;

    EXPECT_LE((last_msg.msg.pos_llh.lat * 100 - 37.2512925784 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.lat, expected "
           "37.2512925784, is "
        << last_msg.msg.pos_llh.lat;

    EXPECT_LE((last_msg.msg.pos_llh.lon * 100 - -121.875056094 * 100), 0.05)
        << "incorrect value for last_msg.msg.pos_llh.lon, expected "
           "-121.875056094, is "
        << last_msg.msg.pos_llh.lon;

    EXPECT_EQ(last_msg.msg.pos_llh.n_sats, 15)
        << "incorrect value for last_msg.msg.pos_llh.n_sats, expected 15, is "
        << (int64_t)last_msg.msg.pos_llh.n_sats;

    EXPECT_EQ(last_msg.msg.pos_llh.tow, 326829000)
        << "incorrect value for last_msg.msg.pos_llh.tow, expected 326829000, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.tow;

    EXPECT_EQ(last_msg.msg.pos_llh.v_accuracy, 0)
        << "incorrect value for last_msg.msg.pos_llh.v_accuracy, expected 0, "
           "is "
        << (int64_t)last_msg.msg.pos_llh.v_accuracy;
  }
}

}  // namespace
