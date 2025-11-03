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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignature.yaml by
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

TEST(auto_check_sbp_signing_MsgEcdsaSignature,
     test_auto_check_sbp_signing_MsgEcdsaSignature) {
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

    sbp_callback_register(&sbp_state, SbpMsgEcdsaSignature, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 8,  12, 66, 0,  83, 0,  1,  2,  1,   2,   3,  4,  72, 0,  1,
        2,  3,  4,  5,  6,  7,  8,  9,  10, 11,  12,  13, 14, 15, 16, 17,
        18, 19, 20, 21, 22, 23, 24, 25, 26, 27,  28,  29, 30, 31, 32, 33,
        34, 35, 36, 37, 38, 39, 40, 41, 42, 43,  44,  45, 46, 47, 48, 49,
        50, 51, 52, 53, 54, 55, 56, 57, 58, 59,  60,  61, 62, 63, 64, 65,
        66, 67, 68, 69, 70, 71, 10, 21, 23, 232, 131,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.ecdsa_signature.certificate_id[0] = 1;

    test_msg.ecdsa_signature.certificate_id[1] = 2;

    test_msg.ecdsa_signature.certificate_id[2] = 3;

    test_msg.ecdsa_signature.certificate_id[3] = 4;

    test_msg.ecdsa_signature.flags = 0;

    test_msg.ecdsa_signature.n_signed_messages = 3;

    test_msg.ecdsa_signature.on_demand_counter = 2;

    test_msg.ecdsa_signature.signature.data[0] = 0;

    test_msg.ecdsa_signature.signature.data[1] = 1;

    test_msg.ecdsa_signature.signature.data[2] = 2;

    test_msg.ecdsa_signature.signature.data[3] = 3;

    test_msg.ecdsa_signature.signature.data[4] = 4;

    test_msg.ecdsa_signature.signature.data[5] = 5;

    test_msg.ecdsa_signature.signature.data[6] = 6;

    test_msg.ecdsa_signature.signature.data[7] = 7;

    test_msg.ecdsa_signature.signature.data[8] = 8;

    test_msg.ecdsa_signature.signature.data[9] = 9;

    test_msg.ecdsa_signature.signature.data[10] = 10;

    test_msg.ecdsa_signature.signature.data[11] = 11;

    test_msg.ecdsa_signature.signature.data[12] = 12;

    test_msg.ecdsa_signature.signature.data[13] = 13;

    test_msg.ecdsa_signature.signature.data[14] = 14;

    test_msg.ecdsa_signature.signature.data[15] = 15;

    test_msg.ecdsa_signature.signature.data[16] = 16;

    test_msg.ecdsa_signature.signature.data[17] = 17;

    test_msg.ecdsa_signature.signature.data[18] = 18;

    test_msg.ecdsa_signature.signature.data[19] = 19;

    test_msg.ecdsa_signature.signature.data[20] = 20;

    test_msg.ecdsa_signature.signature.data[21] = 21;

    test_msg.ecdsa_signature.signature.data[22] = 22;

    test_msg.ecdsa_signature.signature.data[23] = 23;

    test_msg.ecdsa_signature.signature.data[24] = 24;

    test_msg.ecdsa_signature.signature.data[25] = 25;

    test_msg.ecdsa_signature.signature.data[26] = 26;

    test_msg.ecdsa_signature.signature.data[27] = 27;

    test_msg.ecdsa_signature.signature.data[28] = 28;

    test_msg.ecdsa_signature.signature.data[29] = 29;

    test_msg.ecdsa_signature.signature.data[30] = 30;

    test_msg.ecdsa_signature.signature.data[31] = 31;

    test_msg.ecdsa_signature.signature.data[32] = 32;

    test_msg.ecdsa_signature.signature.data[33] = 33;

    test_msg.ecdsa_signature.signature.data[34] = 34;

    test_msg.ecdsa_signature.signature.data[35] = 35;

    test_msg.ecdsa_signature.signature.data[36] = 36;

    test_msg.ecdsa_signature.signature.data[37] = 37;

    test_msg.ecdsa_signature.signature.data[38] = 38;

    test_msg.ecdsa_signature.signature.data[39] = 39;

    test_msg.ecdsa_signature.signature.data[40] = 40;

    test_msg.ecdsa_signature.signature.data[41] = 41;

    test_msg.ecdsa_signature.signature.data[42] = 42;

    test_msg.ecdsa_signature.signature.data[43] = 43;

    test_msg.ecdsa_signature.signature.data[44] = 44;

    test_msg.ecdsa_signature.signature.data[45] = 45;

    test_msg.ecdsa_signature.signature.data[46] = 46;

    test_msg.ecdsa_signature.signature.data[47] = 47;

    test_msg.ecdsa_signature.signature.data[48] = 48;

    test_msg.ecdsa_signature.signature.data[49] = 49;

    test_msg.ecdsa_signature.signature.data[50] = 50;

    test_msg.ecdsa_signature.signature.data[51] = 51;

    test_msg.ecdsa_signature.signature.data[52] = 52;

    test_msg.ecdsa_signature.signature.data[53] = 53;

    test_msg.ecdsa_signature.signature.data[54] = 54;

    test_msg.ecdsa_signature.signature.data[55] = 55;

    test_msg.ecdsa_signature.signature.data[56] = 56;

    test_msg.ecdsa_signature.signature.data[57] = 57;

    test_msg.ecdsa_signature.signature.data[58] = 58;

    test_msg.ecdsa_signature.signature.data[59] = 59;

    test_msg.ecdsa_signature.signature.data[60] = 60;

    test_msg.ecdsa_signature.signature.data[61] = 61;

    test_msg.ecdsa_signature.signature.data[62] = 62;

    test_msg.ecdsa_signature.signature.data[63] = 63;

    test_msg.ecdsa_signature.signature.data[64] = 64;

    test_msg.ecdsa_signature.signature.data[65] = 65;

    test_msg.ecdsa_signature.signature.data[66] = 66;

    test_msg.ecdsa_signature.signature.data[67] = 67;

    test_msg.ecdsa_signature.signature.data[68] = 68;

    test_msg.ecdsa_signature.signature.data[69] = 69;

    test_msg.ecdsa_signature.signature.data[70] = 70;

    test_msg.ecdsa_signature.signature.data[71] = 71;

    test_msg.ecdsa_signature.signature.len = 72;

    test_msg.ecdsa_signature.signed_messages[0] = 10;

    test_msg.ecdsa_signature.signed_messages[1] = 21;

    test_msg.ecdsa_signature.signed_messages[2] = 23;

    test_msg.ecdsa_signature.stream_counter = 1;

    sbp_message_send(&sbp_state, SbpMsgEcdsaSignature, 66, &test_msg,
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

    EXPECT_EQ(sbp_message_cmp(SbpMsgEcdsaSignature, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.ecdsa_signature.certificate_id[0], 1)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.certificate_id[0], expected 1, is "
        << (int64_t)last_msg.msg.ecdsa_signature.certificate_id[0];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.certificate_id[1], 2)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.certificate_id[1], expected 2, is "
        << (int64_t)last_msg.msg.ecdsa_signature.certificate_id[1];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.certificate_id[2], 3)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.certificate_id[2], expected 3, is "
        << (int64_t)last_msg.msg.ecdsa_signature.certificate_id[2];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.certificate_id[3], 4)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.certificate_id[3], expected 4, is "
        << (int64_t)last_msg.msg.ecdsa_signature.certificate_id[3];

    EXPECT_EQ(last_msg.msg.ecdsa_signature.flags, 0)
        << "incorrect value for last_msg.msg.ecdsa_signature.flags, expected "
           "0, is "
        << (int64_t)last_msg.msg.ecdsa_signature.flags;

    EXPECT_EQ(last_msg.msg.ecdsa_signature.n_signed_messages, 3)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.n_signed_messages, expected 3, is "
        << (int64_t)last_msg.msg.ecdsa_signature.n_signed_messages;

    EXPECT_EQ(last_msg.msg.ecdsa_signature.on_demand_counter, 2)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.on_demand_counter, expected 2, is "
        << (int64_t)last_msg.msg.ecdsa_signature.on_demand_counter;

    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[0], 0)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[0], expected 0, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[0];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[1], 1)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[1], expected 1, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[1];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[2], 2)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[2], expected 2, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[2];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[3], 3)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[3], expected 3, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[3];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[4], 4)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[4], expected 4, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[4];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[5], 5)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[5], expected 5, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[5];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[6], 6)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[6], expected 6, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[6];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[7], 7)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[7], expected 7, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[7];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[8], 8)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[8], expected 8, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[8];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[9], 9)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[9], expected 9, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[9];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[10], 10)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[10], expected 10, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[10];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[11], 11)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[11], expected 11, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[11];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[12], 12)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[12], expected 12, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[12];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[13], 13)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[13], expected 13, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[13];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[14], 14)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[14], expected 14, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[14];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[15], 15)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[15], expected 15, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[15];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[16], 16)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[16], expected 16, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[16];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[17], 17)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[17], expected 17, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[17];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[18], 18)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[18], expected 18, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[18];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[19], 19)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[19], expected 19, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[19];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[20], 20)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[20], expected 20, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[20];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[21], 21)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[21], expected 21, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[21];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[22], 22)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[22], expected 22, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[22];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[23], 23)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[23], expected 23, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[23];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[24], 24)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[24], expected 24, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[24];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[25], 25)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[25], expected 25, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[25];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[26], 26)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[26], expected 26, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[26];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[27], 27)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[27], expected 27, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[27];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[28], 28)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[28], expected 28, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[28];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[29], 29)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[29], expected 29, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[29];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[30], 30)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[30], expected 30, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[30];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[31], 31)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[31], expected 31, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[31];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[32], 32)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[32], expected 32, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[32];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[33], 33)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[33], expected 33, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[33];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[34], 34)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[34], expected 34, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[34];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[35], 35)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[35], expected 35, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[35];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[36], 36)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[36], expected 36, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[36];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[37], 37)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[37], expected 37, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[37];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[38], 38)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[38], expected 38, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[38];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[39], 39)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[39], expected 39, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[39];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[40], 40)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[40], expected 40, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[40];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[41], 41)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[41], expected 41, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[41];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[42], 42)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[42], expected 42, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[42];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[43], 43)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[43], expected 43, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[43];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[44], 44)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[44], expected 44, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[44];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[45], 45)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[45], expected 45, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[45];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[46], 46)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[46], expected 46, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[46];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[47], 47)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[47], expected 47, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[47];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[48], 48)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[48], expected 48, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[48];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[49], 49)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[49], expected 49, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[49];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[50], 50)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[50], expected 50, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[50];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[51], 51)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[51], expected 51, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[51];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[52], 52)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[52], expected 52, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[52];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[53], 53)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[53], expected 53, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[53];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[54], 54)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[54], expected 54, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[54];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[55], 55)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[55], expected 55, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[55];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[56], 56)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[56], expected 56, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[56];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[57], 57)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[57], expected 57, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[57];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[58], 58)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[58], expected 58, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[58];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[59], 59)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[59], expected 59, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[59];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[60], 60)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[60], expected 60, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[60];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[61], 61)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[61], expected 61, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[61];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[62], 62)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[62], expected 62, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[62];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[63], 63)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[63], expected 63, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[63];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[64], 64)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[64], expected 64, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[64];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[65], 65)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[65], expected 65, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[65];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[66], 66)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[66], expected 66, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[66];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[67], 67)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[67], expected 67, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[67];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[68], 68)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[68], expected 68, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[68];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[69], 69)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[69], expected 69, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[69];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[70], 70)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[70], expected 70, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[70];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.data[71], 71)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signature.data[71], expected 71, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.data[71];

    EXPECT_EQ(last_msg.msg.ecdsa_signature.signature.len, 72)
        << "incorrect value for last_msg.msg.ecdsa_signature.signature.len, "
           "expected 72, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signature.len;

    EXPECT_EQ(last_msg.msg.ecdsa_signature.signed_messages[0], 10)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signed_messages[0], expected 10, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signed_messages[0];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signed_messages[1], 21)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signed_messages[1], expected 21, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signed_messages[1];
    EXPECT_EQ(last_msg.msg.ecdsa_signature.signed_messages[2], 23)
        << "incorrect value for "
           "last_msg.msg.ecdsa_signature.signed_messages[2], expected 23, is "
        << (int64_t)last_msg.msg.ecdsa_signature.signed_messages[2];

    EXPECT_EQ(last_msg.msg.ecdsa_signature.stream_counter, 1)
        << "incorrect value for last_msg.msg.ecdsa_signature.stream_counter, "
           "expected 1, is "
        << (int64_t)last_msg.msg.ecdsa_signature.stream_counter;
  }
}

}  // namespace
