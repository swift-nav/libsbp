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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgAesCmacSignature.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/signing.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_signing_MsgAesCmacSignature,
     test_auto_check_sbp_signing_MsgAesCmacSignature) {
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

    sbp_callback_register(&sbp_state, SbpMsgAesCmacSignature, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 16, 12, 66, 0, 26, 1,  2,  1,  2,  3,  4, 0,  1,  2,  3,   4,
        5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 0, 11, 22, 33, 192, 21,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.aes_cmac_signature.certificate_id[0] = 1;

    test_msg.aes_cmac_signature.certificate_id[1] = 2;

    test_msg.aes_cmac_signature.certificate_id[2] = 3;

    test_msg.aes_cmac_signature.certificate_id[3] = 4;

    test_msg.aes_cmac_signature.flags = 0;

    test_msg.aes_cmac_signature.n_signed_messages = 3;

    test_msg.aes_cmac_signature.on_demand_counter = 2;

    test_msg.aes_cmac_signature.signature[0] = 0;

    test_msg.aes_cmac_signature.signature[1] = 1;

    test_msg.aes_cmac_signature.signature[2] = 2;

    test_msg.aes_cmac_signature.signature[3] = 3;

    test_msg.aes_cmac_signature.signature[4] = 4;

    test_msg.aes_cmac_signature.signature[5] = 5;

    test_msg.aes_cmac_signature.signature[6] = 6;

    test_msg.aes_cmac_signature.signature[7] = 7;

    test_msg.aes_cmac_signature.signature[8] = 8;

    test_msg.aes_cmac_signature.signature[9] = 9;

    test_msg.aes_cmac_signature.signature[10] = 10;

    test_msg.aes_cmac_signature.signature[11] = 11;

    test_msg.aes_cmac_signature.signature[12] = 12;

    test_msg.aes_cmac_signature.signature[13] = 13;

    test_msg.aes_cmac_signature.signature[14] = 14;

    test_msg.aes_cmac_signature.signature[15] = 15;

    test_msg.aes_cmac_signature.signed_messages[0] = 11;

    test_msg.aes_cmac_signature.signed_messages[1] = 22;

    test_msg.aes_cmac_signature.signed_messages[2] = 33;

    test_msg.aes_cmac_signature.stream_counter = 1;

    sbp_message_send(&sbp_state, SbpMsgAesCmacSignature, 66, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 66)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgAesCmacSignature, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.aes_cmac_signature.certificate_id[0], 1)
        << "incorrect value for "
           "last_msg.msg.aes_cmac_signature.certificate_id[0], expected 1, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.certificate_id[0];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.certificate_id[1], 2)
        << "incorrect value for "
           "last_msg.msg.aes_cmac_signature.certificate_id[1], expected 2, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.certificate_id[1];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.certificate_id[2], 3)
        << "incorrect value for "
           "last_msg.msg.aes_cmac_signature.certificate_id[2], expected 3, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.certificate_id[2];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.certificate_id[3], 4)
        << "incorrect value for "
           "last_msg.msg.aes_cmac_signature.certificate_id[3], expected 4, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.certificate_id[3];

    EXPECT_EQ(last_msg.msg.aes_cmac_signature.flags, 0)
        << "incorrect value for last_msg.msg.aes_cmac_signature.flags, "
           "expected 0, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.flags;

    EXPECT_EQ(last_msg.msg.aes_cmac_signature.n_signed_messages, 3)
        << "incorrect value for "
           "last_msg.msg.aes_cmac_signature.n_signed_messages, expected 3, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.n_signed_messages;

    EXPECT_EQ(last_msg.msg.aes_cmac_signature.on_demand_counter, 2)
        << "incorrect value for "
           "last_msg.msg.aes_cmac_signature.on_demand_counter, expected 2, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.on_demand_counter;

    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[0], 0)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[0], "
           "expected 0, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[0];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[1], 1)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[1], "
           "expected 1, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[1];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[2], 2)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[2], "
           "expected 2, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[2];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[3], 3)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[3], "
           "expected 3, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[3];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[4], 4)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[4], "
           "expected 4, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[4];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[5], 5)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[5], "
           "expected 5, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[5];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[6], 6)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[6], "
           "expected 6, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[6];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[7], 7)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[7], "
           "expected 7, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[7];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[8], 8)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[8], "
           "expected 8, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[8];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[9], 9)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[9], "
           "expected 9, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[9];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[10], 10)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[10], "
           "expected 10, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[10];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[11], 11)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[11], "
           "expected 11, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[11];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[12], 12)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[12], "
           "expected 12, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[12];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[13], 13)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[13], "
           "expected 13, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[13];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[14], 14)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[14], "
           "expected 14, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[14];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signature[15], 15)
        << "incorrect value for last_msg.msg.aes_cmac_signature.signature[15], "
           "expected 15, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signature[15];

    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signed_messages[0], 11)
        << "incorrect value for "
           "last_msg.msg.aes_cmac_signature.signed_messages[0], expected 11, "
           "is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signed_messages[0];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signed_messages[1], 22)
        << "incorrect value for "
           "last_msg.msg.aes_cmac_signature.signed_messages[1], expected 22, "
           "is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signed_messages[1];
    EXPECT_EQ(last_msg.msg.aes_cmac_signature.signed_messages[2], 33)
        << "incorrect value for "
           "last_msg.msg.aes_cmac_signature.signed_messages[2], expected 33, "
           "is "
        << (int64_t)last_msg.msg.aes_cmac_signature.signed_messages[2];

    EXPECT_EQ(last_msg.msg.aes_cmac_signature.stream_counter, 1)
        << "incorrect value for "
           "last_msg.msg.aes_cmac_signature.stream_counter, expected 1, is "
        << (int64_t)last_msg.msg.aes_cmac_signature.stream_counter;
  }
}

}  // namespace
