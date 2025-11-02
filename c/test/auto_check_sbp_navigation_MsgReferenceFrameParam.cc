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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgReferenceFrameParam.yaml by
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

TEST(auto_check_sbp_navigation_MsgReferenceFrameParam,
     test_auto_check_sbp_navigation_MsgReferenceFrameParam) {
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

    sbp_callback_register(&sbp_state, SbpMsgReferenceFrameParam,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 68, 2,  66, 0, 124, 1,  102, 111, 111, 0,  0,  0,   0, 0,  0,  0,
        0,  0,  0,  0,  0, 0,   0,  0,   0,   0,   0,  0,  0,   0, 0,  0,  0,
        0,  0,  0,  0,  0, 98,  97, 114, 0,   0,   0,  0,  0,   0, 0,  0,  0,
        0,  0,  0,  0,  0, 0,   0,  0,   0,   0,   0,  0,  0,   0, 0,  0,  0,
        0,  0,  0,  4,  5, 0,   6,  0,   7,   0,   0,  0,  8,   0, 0,  0,  9,
        0,  0,  0,  10, 0, 0,   0,  11,  0,   0,   0,  12, 0,   0, 0,  13, 0,
        0,  0,  14, 0,  0, 0,   15, 0,   0,   0,   16, 0,  0,   0, 17, 0,  0,
        0,  18, 0,  0,  0, 19,  0,  0,   0,   20,  0,  6,  161,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.reference_frame_param.delta_X0 = 7;

    test_msg.reference_frame_param.delta_Y0 = 8;

    test_msg.reference_frame_param.delta_Z0 = 9;

    test_msg.reference_frame_param.dot_delta_X0 = 14;

    test_msg.reference_frame_param.dot_delta_Y0 = 15;

    test_msg.reference_frame_param.dot_delta_Z0 = 16;

    test_msg.reference_frame_param.dot_scale = 20;

    test_msg.reference_frame_param.dot_theta_01 = 17;

    test_msg.reference_frame_param.dot_theta_02 = 18;

    test_msg.reference_frame_param.dot_theta_03 = 19;

    test_msg.reference_frame_param.re_t0 = 6;

    test_msg.reference_frame_param.scale = 13;

    test_msg.reference_frame_param.sin = 4;

    {
      const char assign_string[] = {
          (char)102, (char)111, (char)111, (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0};
      memcpy(test_msg.reference_frame_param.sn, assign_string,
             sizeof(assign_string));
    }

    test_msg.reference_frame_param.ssr_iod = 1;

    test_msg.reference_frame_param.theta_01 = 10;

    test_msg.reference_frame_param.theta_02 = 11;

    test_msg.reference_frame_param.theta_03 = 12;

    {
      const char assign_string[] = {
          (char)98, (char)97, (char)114, (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0};
      memcpy(test_msg.reference_frame_param.tn, assign_string,
             sizeof(assign_string));
    }

    test_msg.reference_frame_param.utn = 5;

    sbp_message_send(&sbp_state, SbpMsgReferenceFrameParam, 66, &test_msg,
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
        sbp_message_cmp(SbpMsgReferenceFrameParam, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.reference_frame_param.delta_X0, 7)
        << "incorrect value for last_msg.msg.reference_frame_param.delta_X0, "
           "expected 7, is "
        << (int64_t)last_msg.msg.reference_frame_param.delta_X0;

    EXPECT_EQ(last_msg.msg.reference_frame_param.delta_Y0, 8)
        << "incorrect value for last_msg.msg.reference_frame_param.delta_Y0, "
           "expected 8, is "
        << (int64_t)last_msg.msg.reference_frame_param.delta_Y0;

    EXPECT_EQ(last_msg.msg.reference_frame_param.delta_Z0, 9)
        << "incorrect value for last_msg.msg.reference_frame_param.delta_Z0, "
           "expected 9, is "
        << (int64_t)last_msg.msg.reference_frame_param.delta_Z0;

    EXPECT_EQ(last_msg.msg.reference_frame_param.dot_delta_X0, 14)
        << "incorrect value for "
           "last_msg.msg.reference_frame_param.dot_delta_X0, expected 14, is "
        << (int64_t)last_msg.msg.reference_frame_param.dot_delta_X0;

    EXPECT_EQ(last_msg.msg.reference_frame_param.dot_delta_Y0, 15)
        << "incorrect value for "
           "last_msg.msg.reference_frame_param.dot_delta_Y0, expected 15, is "
        << (int64_t)last_msg.msg.reference_frame_param.dot_delta_Y0;

    EXPECT_EQ(last_msg.msg.reference_frame_param.dot_delta_Z0, 16)
        << "incorrect value for "
           "last_msg.msg.reference_frame_param.dot_delta_Z0, expected 16, is "
        << (int64_t)last_msg.msg.reference_frame_param.dot_delta_Z0;

    EXPECT_EQ(last_msg.msg.reference_frame_param.dot_scale, 20)
        << "incorrect value for last_msg.msg.reference_frame_param.dot_scale, "
           "expected 20, is "
        << (int64_t)last_msg.msg.reference_frame_param.dot_scale;

    EXPECT_EQ(last_msg.msg.reference_frame_param.dot_theta_01, 17)
        << "incorrect value for "
           "last_msg.msg.reference_frame_param.dot_theta_01, expected 17, is "
        << (int64_t)last_msg.msg.reference_frame_param.dot_theta_01;

    EXPECT_EQ(last_msg.msg.reference_frame_param.dot_theta_02, 18)
        << "incorrect value for "
           "last_msg.msg.reference_frame_param.dot_theta_02, expected 18, is "
        << (int64_t)last_msg.msg.reference_frame_param.dot_theta_02;

    EXPECT_EQ(last_msg.msg.reference_frame_param.dot_theta_03, 19)
        << "incorrect value for "
           "last_msg.msg.reference_frame_param.dot_theta_03, expected 19, is "
        << (int64_t)last_msg.msg.reference_frame_param.dot_theta_03;

    EXPECT_EQ(last_msg.msg.reference_frame_param.re_t0, 6)
        << "incorrect value for last_msg.msg.reference_frame_param.re_t0, "
           "expected 6, is "
        << (int64_t)last_msg.msg.reference_frame_param.re_t0;

    EXPECT_EQ(last_msg.msg.reference_frame_param.scale, 13)
        << "incorrect value for last_msg.msg.reference_frame_param.scale, "
           "expected 13, is "
        << (int64_t)last_msg.msg.reference_frame_param.scale;

    EXPECT_EQ(last_msg.msg.reference_frame_param.sin, 4)
        << "incorrect value for last_msg.msg.reference_frame_param.sin, "
           "expected 4, is "
        << (int64_t)last_msg.msg.reference_frame_param.sin;

    {
      const char check_string[] = {
          (char)102, (char)111, (char)111, (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0};
      EXPECT_EQ(memcmp(&last_msg.msg.reference_frame_param.sn, check_string,
                       sizeof(check_string)),
                0)
          << "incorrect value for last_msg.msg.reference_frame_param.sn, "
             "expected string '"
          << check_string << "', is '" << last_msg.msg.reference_frame_param.sn
          << "'";
    }

    EXPECT_EQ(last_msg.msg.reference_frame_param.ssr_iod, 1)
        << "incorrect value for last_msg.msg.reference_frame_param.ssr_iod, "
           "expected 1, is "
        << (int64_t)last_msg.msg.reference_frame_param.ssr_iod;

    EXPECT_EQ(last_msg.msg.reference_frame_param.theta_01, 10)
        << "incorrect value for last_msg.msg.reference_frame_param.theta_01, "
           "expected 10, is "
        << (int64_t)last_msg.msg.reference_frame_param.theta_01;

    EXPECT_EQ(last_msg.msg.reference_frame_param.theta_02, 11)
        << "incorrect value for last_msg.msg.reference_frame_param.theta_02, "
           "expected 11, is "
        << (int64_t)last_msg.msg.reference_frame_param.theta_02;

    EXPECT_EQ(last_msg.msg.reference_frame_param.theta_03, 12)
        << "incorrect value for last_msg.msg.reference_frame_param.theta_03, "
           "expected 12, is "
        << (int64_t)last_msg.msg.reference_frame_param.theta_03;

    {
      const char check_string[] = {
          (char)98, (char)97, (char)114, (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0};
      EXPECT_EQ(memcmp(&last_msg.msg.reference_frame_param.tn, check_string,
                       sizeof(check_string)),
                0)
          << "incorrect value for last_msg.msg.reference_frame_param.tn, "
             "expected string '"
          << check_string << "', is '" << last_msg.msg.reference_frame_param.tn
          << "'";
    }

    EXPECT_EQ(last_msg.msg.reference_frame_param.utn, 5)
        << "incorrect value for last_msg.msg.reference_frame_param.utn, "
           "expected 5, is "
        << (int64_t)last_msg.msg.reference_frame_param.utn;
  }
}

}  // namespace
