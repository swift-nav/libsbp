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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgCertificateChainDep.yaml by
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

TEST(auto_check_sbp_signing_MsgCertificateChainDep,
     test_auto_check_sbp_signing_MsgCertificateChainDep) {
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

    sbp_callback_register(&sbp_state, SbpMsgCertificateChainDep,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 5,  12,  66, 0,  135, 0,  1,  2,  3,  4,   5,  6,  7,   8,   9,
        10, 11, 12,  13, 14, 15,  16, 17, 18, 19, 10,  11, 12, 13,  14,  15,
        16, 17, 18,  19, 0,  1,   2,  3,  4,  5,  6,   7,  8,  9,   20,  21,
        22, 23, 24,  25, 26, 27,  28, 29, 10, 11, 12,  13, 14, 15,  16,  17,
        18, 19, 232, 7,  3,  30,  12, 34, 59, 21, 205, 91, 7,  0,   1,   2,
        3,  4,  5,   6,  7,  0,   1,  2,  3,  4,  5,   6,  7,  0,   1,   2,
        3,  4,  5,   6,  7,  0,   1,  2,  3,  4,  5,   6,  7,  0,   1,   2,
        3,  4,  5,   6,  7,  0,   1,  2,  3,  4,  5,   6,  7,  0,   1,   2,
        3,  4,  5,   6,  7,  0,   1,  2,  3,  4,  5,   6,  7,  112, 100,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.certificate_chain_dep.corrections_certificate[0] = 20;

    test_msg.certificate_chain_dep.corrections_certificate[1] = 21;

    test_msg.certificate_chain_dep.corrections_certificate[2] = 22;

    test_msg.certificate_chain_dep.corrections_certificate[3] = 23;

    test_msg.certificate_chain_dep.corrections_certificate[4] = 24;

    test_msg.certificate_chain_dep.corrections_certificate[5] = 25;

    test_msg.certificate_chain_dep.corrections_certificate[6] = 26;

    test_msg.certificate_chain_dep.corrections_certificate[7] = 27;

    test_msg.certificate_chain_dep.corrections_certificate[8] = 28;

    test_msg.certificate_chain_dep.corrections_certificate[9] = 29;

    test_msg.certificate_chain_dep.corrections_certificate[10] = 10;

    test_msg.certificate_chain_dep.corrections_certificate[11] = 11;

    test_msg.certificate_chain_dep.corrections_certificate[12] = 12;

    test_msg.certificate_chain_dep.corrections_certificate[13] = 13;

    test_msg.certificate_chain_dep.corrections_certificate[14] = 14;

    test_msg.certificate_chain_dep.corrections_certificate[15] = 15;

    test_msg.certificate_chain_dep.corrections_certificate[16] = 16;

    test_msg.certificate_chain_dep.corrections_certificate[17] = 17;

    test_msg.certificate_chain_dep.corrections_certificate[18] = 18;

    test_msg.certificate_chain_dep.corrections_certificate[19] = 19;

    test_msg.certificate_chain_dep.expiration.day = 30;

    test_msg.certificate_chain_dep.expiration.hours = 12;

    test_msg.certificate_chain_dep.expiration.minutes = 34;

    test_msg.certificate_chain_dep.expiration.month = 3;

    test_msg.certificate_chain_dep.expiration.ns = 123456789;

    test_msg.certificate_chain_dep.expiration.seconds = 59;

    test_msg.certificate_chain_dep.expiration.year = 2024;

    test_msg.certificate_chain_dep.intermediate_certificate[0] = 10;

    test_msg.certificate_chain_dep.intermediate_certificate[1] = 11;

    test_msg.certificate_chain_dep.intermediate_certificate[2] = 12;

    test_msg.certificate_chain_dep.intermediate_certificate[3] = 13;

    test_msg.certificate_chain_dep.intermediate_certificate[4] = 14;

    test_msg.certificate_chain_dep.intermediate_certificate[5] = 15;

    test_msg.certificate_chain_dep.intermediate_certificate[6] = 16;

    test_msg.certificate_chain_dep.intermediate_certificate[7] = 17;

    test_msg.certificate_chain_dep.intermediate_certificate[8] = 18;

    test_msg.certificate_chain_dep.intermediate_certificate[9] = 19;

    test_msg.certificate_chain_dep.intermediate_certificate[10] = 0;

    test_msg.certificate_chain_dep.intermediate_certificate[11] = 1;

    test_msg.certificate_chain_dep.intermediate_certificate[12] = 2;

    test_msg.certificate_chain_dep.intermediate_certificate[13] = 3;

    test_msg.certificate_chain_dep.intermediate_certificate[14] = 4;

    test_msg.certificate_chain_dep.intermediate_certificate[15] = 5;

    test_msg.certificate_chain_dep.intermediate_certificate[16] = 6;

    test_msg.certificate_chain_dep.intermediate_certificate[17] = 7;

    test_msg.certificate_chain_dep.intermediate_certificate[18] = 8;

    test_msg.certificate_chain_dep.intermediate_certificate[19] = 9;

    test_msg.certificate_chain_dep.root_certificate[0] = 0;

    test_msg.certificate_chain_dep.root_certificate[1] = 1;

    test_msg.certificate_chain_dep.root_certificate[2] = 2;

    test_msg.certificate_chain_dep.root_certificate[3] = 3;

    test_msg.certificate_chain_dep.root_certificate[4] = 4;

    test_msg.certificate_chain_dep.root_certificate[5] = 5;

    test_msg.certificate_chain_dep.root_certificate[6] = 6;

    test_msg.certificate_chain_dep.root_certificate[7] = 7;

    test_msg.certificate_chain_dep.root_certificate[8] = 8;

    test_msg.certificate_chain_dep.root_certificate[9] = 9;

    test_msg.certificate_chain_dep.root_certificate[10] = 10;

    test_msg.certificate_chain_dep.root_certificate[11] = 11;

    test_msg.certificate_chain_dep.root_certificate[12] = 12;

    test_msg.certificate_chain_dep.root_certificate[13] = 13;

    test_msg.certificate_chain_dep.root_certificate[14] = 14;

    test_msg.certificate_chain_dep.root_certificate[15] = 15;

    test_msg.certificate_chain_dep.root_certificate[16] = 16;

    test_msg.certificate_chain_dep.root_certificate[17] = 17;

    test_msg.certificate_chain_dep.root_certificate[18] = 18;

    test_msg.certificate_chain_dep.root_certificate[19] = 19;

    test_msg.certificate_chain_dep.signature[0] = 0;

    test_msg.certificate_chain_dep.signature[1] = 1;

    test_msg.certificate_chain_dep.signature[2] = 2;

    test_msg.certificate_chain_dep.signature[3] = 3;

    test_msg.certificate_chain_dep.signature[4] = 4;

    test_msg.certificate_chain_dep.signature[5] = 5;

    test_msg.certificate_chain_dep.signature[6] = 6;

    test_msg.certificate_chain_dep.signature[7] = 7;

    test_msg.certificate_chain_dep.signature[8] = 0;

    test_msg.certificate_chain_dep.signature[9] = 1;

    test_msg.certificate_chain_dep.signature[10] = 2;

    test_msg.certificate_chain_dep.signature[11] = 3;

    test_msg.certificate_chain_dep.signature[12] = 4;

    test_msg.certificate_chain_dep.signature[13] = 5;

    test_msg.certificate_chain_dep.signature[14] = 6;

    test_msg.certificate_chain_dep.signature[15] = 7;

    test_msg.certificate_chain_dep.signature[16] = 0;

    test_msg.certificate_chain_dep.signature[17] = 1;

    test_msg.certificate_chain_dep.signature[18] = 2;

    test_msg.certificate_chain_dep.signature[19] = 3;

    test_msg.certificate_chain_dep.signature[20] = 4;

    test_msg.certificate_chain_dep.signature[21] = 5;

    test_msg.certificate_chain_dep.signature[22] = 6;

    test_msg.certificate_chain_dep.signature[23] = 7;

    test_msg.certificate_chain_dep.signature[24] = 0;

    test_msg.certificate_chain_dep.signature[25] = 1;

    test_msg.certificate_chain_dep.signature[26] = 2;

    test_msg.certificate_chain_dep.signature[27] = 3;

    test_msg.certificate_chain_dep.signature[28] = 4;

    test_msg.certificate_chain_dep.signature[29] = 5;

    test_msg.certificate_chain_dep.signature[30] = 6;

    test_msg.certificate_chain_dep.signature[31] = 7;

    test_msg.certificate_chain_dep.signature[32] = 0;

    test_msg.certificate_chain_dep.signature[33] = 1;

    test_msg.certificate_chain_dep.signature[34] = 2;

    test_msg.certificate_chain_dep.signature[35] = 3;

    test_msg.certificate_chain_dep.signature[36] = 4;

    test_msg.certificate_chain_dep.signature[37] = 5;

    test_msg.certificate_chain_dep.signature[38] = 6;

    test_msg.certificate_chain_dep.signature[39] = 7;

    test_msg.certificate_chain_dep.signature[40] = 0;

    test_msg.certificate_chain_dep.signature[41] = 1;

    test_msg.certificate_chain_dep.signature[42] = 2;

    test_msg.certificate_chain_dep.signature[43] = 3;

    test_msg.certificate_chain_dep.signature[44] = 4;

    test_msg.certificate_chain_dep.signature[45] = 5;

    test_msg.certificate_chain_dep.signature[46] = 6;

    test_msg.certificate_chain_dep.signature[47] = 7;

    test_msg.certificate_chain_dep.signature[48] = 0;

    test_msg.certificate_chain_dep.signature[49] = 1;

    test_msg.certificate_chain_dep.signature[50] = 2;

    test_msg.certificate_chain_dep.signature[51] = 3;

    test_msg.certificate_chain_dep.signature[52] = 4;

    test_msg.certificate_chain_dep.signature[53] = 5;

    test_msg.certificate_chain_dep.signature[54] = 6;

    test_msg.certificate_chain_dep.signature[55] = 7;

    test_msg.certificate_chain_dep.signature[56] = 0;

    test_msg.certificate_chain_dep.signature[57] = 1;

    test_msg.certificate_chain_dep.signature[58] = 2;

    test_msg.certificate_chain_dep.signature[59] = 3;

    test_msg.certificate_chain_dep.signature[60] = 4;

    test_msg.certificate_chain_dep.signature[61] = 5;

    test_msg.certificate_chain_dep.signature[62] = 6;

    test_msg.certificate_chain_dep.signature[63] = 7;

    sbp_message_send(&sbp_state, SbpMsgCertificateChainDep, 66, &test_msg,
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

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgCertificateChainDep, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[0], 20)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[0], "
           "expected 20, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[0];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[1], 21)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[1], "
           "expected 21, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[1];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[2], 22)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[2], "
           "expected 22, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[2];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[3], 23)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[3], "
           "expected 23, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[3];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[4], 24)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[4], "
           "expected 24, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[4];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[5], 25)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[5], "
           "expected 25, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[5];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[6], 26)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[6], "
           "expected 26, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[6];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[7], 27)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[7], "
           "expected 27, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[7];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[8], 28)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[8], "
           "expected 28, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[8];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[9], 29)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[9], "
           "expected 29, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[9];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[10],
              10)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[10], "
           "expected 10, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[10];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[11],
              11)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[11], "
           "expected 11, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[11];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[12],
              12)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[12], "
           "expected 12, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[12];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[13],
              13)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[13], "
           "expected 13, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[13];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[14],
              14)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[14], "
           "expected 14, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[14];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[15],
              15)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[15], "
           "expected 15, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[15];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[16],
              16)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[16], "
           "expected 16, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[16];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[17],
              17)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[17], "
           "expected 17, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[17];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[18],
              18)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[18], "
           "expected 18, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[18];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.corrections_certificate[19],
              19)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.corrections_certificate[19], "
           "expected 19, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.corrections_certificate[19];

    EXPECT_EQ(last_msg.msg.certificate_chain_dep.expiration.day, 30)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.expiration.day, expected 30, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.expiration.day;

    EXPECT_EQ(last_msg.msg.certificate_chain_dep.expiration.hours, 12)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.expiration.hours, expected 12, "
           "is "
        << (int64_t)last_msg.msg.certificate_chain_dep.expiration.hours;

    EXPECT_EQ(last_msg.msg.certificate_chain_dep.expiration.minutes, 34)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.expiration.minutes, expected "
           "34, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.expiration.minutes;

    EXPECT_EQ(last_msg.msg.certificate_chain_dep.expiration.month, 3)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.expiration.month, expected 3, "
           "is "
        << (int64_t)last_msg.msg.certificate_chain_dep.expiration.month;

    EXPECT_EQ(last_msg.msg.certificate_chain_dep.expiration.ns, 123456789)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.expiration.ns, expected "
           "123456789, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.expiration.ns;

    EXPECT_EQ(last_msg.msg.certificate_chain_dep.expiration.seconds, 59)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.expiration.seconds, expected "
           "59, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.expiration.seconds;

    EXPECT_EQ(last_msg.msg.certificate_chain_dep.expiration.year, 2024)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.expiration.year, expected 2024, "
           "is "
        << (int64_t)last_msg.msg.certificate_chain_dep.expiration.year;

    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[0],
              10)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[0], "
           "expected 10, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[0];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[1],
              11)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[1], "
           "expected 11, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[1];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[2],
              12)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[2], "
           "expected 12, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[2];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[3],
              13)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[3], "
           "expected 13, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[3];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[4],
              14)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[4], "
           "expected 14, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[4];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[5],
              15)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[5], "
           "expected 15, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[5];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[6],
              16)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[6], "
           "expected 16, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[6];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[7],
              17)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[7], "
           "expected 17, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[7];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[8],
              18)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[8], "
           "expected 18, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[8];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[9],
              19)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[9], "
           "expected 19, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[9];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[10],
              0)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[10], "
           "expected 0, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[10];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[11],
              1)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[11], "
           "expected 1, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[11];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[12],
              2)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[12], "
           "expected 2, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[12];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[13],
              3)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[13], "
           "expected 3, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[13];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[14],
              4)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[14], "
           "expected 4, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[14];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[15],
              5)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[15], "
           "expected 5, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[15];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[16],
              6)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[16], "
           "expected 6, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[16];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[17],
              7)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[17], "
           "expected 7, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[17];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[18],
              8)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[18], "
           "expected 8, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[18];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.intermediate_certificate[19],
              9)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.intermediate_certificate[19], "
           "expected 9, is "
        << (int64_t)
               last_msg.msg.certificate_chain_dep.intermediate_certificate[19];

    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[0], 0)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[0], expected "
           "0, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[0];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[1], 1)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[1], expected "
           "1, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[1];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[2], 2)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[2], expected "
           "2, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[2];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[3], 3)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[3], expected "
           "3, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[3];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[4], 4)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[4], expected "
           "4, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[4];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[5], 5)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[5], expected "
           "5, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[5];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[6], 6)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[6], expected "
           "6, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[6];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[7], 7)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[7], expected "
           "7, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[7];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[8], 8)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[8], expected "
           "8, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[8];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[9], 9)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[9], expected "
           "9, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[9];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[10], 10)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[10], expected "
           "10, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[10];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[11], 11)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[11], expected "
           "11, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[11];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[12], 12)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[12], expected "
           "12, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[12];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[13], 13)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[13], expected "
           "13, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[13];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[14], 14)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[14], expected "
           "14, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[14];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[15], 15)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[15], expected "
           "15, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[15];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[16], 16)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[16], expected "
           "16, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[16];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[17], 17)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[17], expected "
           "17, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[17];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[18], 18)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[18], expected "
           "18, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[18];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.root_certificate[19], 19)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.root_certificate[19], expected "
           "19, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.root_certificate[19];

    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[0], 0)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[0], expected 0, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[0];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[1], 1)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[1], expected 1, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[1];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[2], 2)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[2], expected 2, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[2];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[3], 3)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[3], expected 3, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[3];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[4], 4)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[4], expected 4, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[4];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[5], 5)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[5], expected 5, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[5];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[6], 6)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[6], expected 6, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[6];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[7], 7)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[7], expected 7, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[7];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[8], 0)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[8], expected 0, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[8];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[9], 1)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[9], expected 1, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[9];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[10], 2)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[10], expected 2, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[10];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[11], 3)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[11], expected 3, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[11];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[12], 4)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[12], expected 4, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[12];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[13], 5)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[13], expected 5, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[13];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[14], 6)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[14], expected 6, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[14];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[15], 7)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[15], expected 7, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[15];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[16], 0)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[16], expected 0, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[16];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[17], 1)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[17], expected 1, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[17];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[18], 2)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[18], expected 2, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[18];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[19], 3)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[19], expected 3, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[19];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[20], 4)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[20], expected 4, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[20];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[21], 5)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[21], expected 5, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[21];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[22], 6)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[22], expected 6, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[22];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[23], 7)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[23], expected 7, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[23];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[24], 0)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[24], expected 0, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[24];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[25], 1)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[25], expected 1, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[25];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[26], 2)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[26], expected 2, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[26];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[27], 3)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[27], expected 3, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[27];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[28], 4)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[28], expected 4, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[28];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[29], 5)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[29], expected 5, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[29];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[30], 6)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[30], expected 6, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[30];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[31], 7)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[31], expected 7, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[31];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[32], 0)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[32], expected 0, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[32];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[33], 1)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[33], expected 1, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[33];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[34], 2)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[34], expected 2, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[34];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[35], 3)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[35], expected 3, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[35];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[36], 4)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[36], expected 4, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[36];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[37], 5)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[37], expected 5, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[37];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[38], 6)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[38], expected 6, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[38];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[39], 7)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[39], expected 7, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[39];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[40], 0)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[40], expected 0, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[40];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[41], 1)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[41], expected 1, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[41];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[42], 2)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[42], expected 2, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[42];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[43], 3)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[43], expected 3, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[43];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[44], 4)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[44], expected 4, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[44];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[45], 5)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[45], expected 5, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[45];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[46], 6)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[46], expected 6, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[46];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[47], 7)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[47], expected 7, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[47];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[48], 0)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[48], expected 0, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[48];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[49], 1)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[49], expected 1, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[49];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[50], 2)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[50], expected 2, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[50];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[51], 3)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[51], expected 3, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[51];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[52], 4)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[52], expected 4, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[52];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[53], 5)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[53], expected 5, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[53];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[54], 6)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[54], expected 6, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[54];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[55], 7)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[55], expected 7, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[55];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[56], 0)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[56], expected 0, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[56];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[57], 1)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[57], expected 1, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[57];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[58], 2)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[58], expected 2, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[58];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[59], 3)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[59], expected 3, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[59];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[60], 4)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[60], expected 4, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[60];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[61], 5)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[61], expected 5, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[61];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[62], 6)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[62], expected 6, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[62];
    EXPECT_EQ(last_msg.msg.certificate_chain_dep.signature[63], 7)
        << "incorrect value for "
           "last_msg.msg.certificate_chain_dep.signature[63], expected 7, is "
        << (int64_t)last_msg.msg.certificate_chain_dep.signature[63];
  }
}

}  // namespace
