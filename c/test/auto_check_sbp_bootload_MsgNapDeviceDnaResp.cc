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
// spec/tests/yaml/swiftnav/sbp/bootload/test_MsgNapDeviceDnaResp.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/bootload.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_bootload_MsgNapDeviceDnaResp,
     test_auto_check_sbp_bootload_MsgNapDeviceDnaResp) {
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

    sbp_callback_register(&sbp_state, SbpMsgNapDeviceDnaResp, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 221, 0, 169, 56, 8, 2, 187, 1, 130, 173, 244, 67, 122, 70, 91,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.nap_device_dna_resp.dna[0] = 2;

    test_msg.nap_device_dna_resp.dna[1] = 187;

    test_msg.nap_device_dna_resp.dna[2] = 1;

    test_msg.nap_device_dna_resp.dna[3] = 130;

    test_msg.nap_device_dna_resp.dna[4] = 173;

    test_msg.nap_device_dna_resp.dna[5] = 244;

    test_msg.nap_device_dna_resp.dna[6] = 67;

    test_msg.nap_device_dna_resp.dna[7] = 122;

    sbp_message_send(&sbp_state, SbpMsgNapDeviceDnaResp, 14505, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 14505)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgNapDeviceDnaResp, &last_msg.msg, &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.nap_device_dna_resp.dna[0], 2)
        << "incorrect value for last_msg.msg.nap_device_dna_resp.dna[0], "
           "expected 2, is "
        << (int64_t)last_msg.msg.nap_device_dna_resp.dna[0];
    EXPECT_EQ(last_msg.msg.nap_device_dna_resp.dna[1], 187)
        << "incorrect value for last_msg.msg.nap_device_dna_resp.dna[1], "
           "expected 187, is "
        << (int64_t)last_msg.msg.nap_device_dna_resp.dna[1];
    EXPECT_EQ(last_msg.msg.nap_device_dna_resp.dna[2], 1)
        << "incorrect value for last_msg.msg.nap_device_dna_resp.dna[2], "
           "expected 1, is "
        << (int64_t)last_msg.msg.nap_device_dna_resp.dna[2];
    EXPECT_EQ(last_msg.msg.nap_device_dna_resp.dna[3], 130)
        << "incorrect value for last_msg.msg.nap_device_dna_resp.dna[3], "
           "expected 130, is "
        << (int64_t)last_msg.msg.nap_device_dna_resp.dna[3];
    EXPECT_EQ(last_msg.msg.nap_device_dna_resp.dna[4], 173)
        << "incorrect value for last_msg.msg.nap_device_dna_resp.dna[4], "
           "expected 173, is "
        << (int64_t)last_msg.msg.nap_device_dna_resp.dna[4];
    EXPECT_EQ(last_msg.msg.nap_device_dna_resp.dna[5], 244)
        << "incorrect value for last_msg.msg.nap_device_dna_resp.dna[5], "
           "expected 244, is "
        << (int64_t)last_msg.msg.nap_device_dna_resp.dna[5];
    EXPECT_EQ(last_msg.msg.nap_device_dna_resp.dna[6], 67)
        << "incorrect value for last_msg.msg.nap_device_dna_resp.dna[6], "
           "expected 67, is "
        << (int64_t)last_msg.msg.nap_device_dna_resp.dna[6];
    EXPECT_EQ(last_msg.msg.nap_device_dna_resp.dna[7], 122)
        << "incorrect value for last_msg.msg.nap_device_dna_resp.dna[7], "
           "expected 122, is "
        << (int64_t)last_msg.msg.nap_device_dna_resp.dna[7];
  }
}

}  // namespace
