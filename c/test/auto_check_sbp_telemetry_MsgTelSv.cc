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
// spec/tests/yaml/swiftnav/sbp/telemetry/test_MsgTelSv.yaml by generate.py. Do
// not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/telemetry.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_telemetry_MsgTelSv,
     test_auto_check_sbp_telemetry_MsgTelSv) {
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

    sbp_callback_register(&sbp_state, SbpMsgTelSv, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 32, 1, 148, 38,  20, 175, 8, 208, 221, 62, 24, 16, 1,
        40, 50, 5, 226, 255, 1,  0,   1, 1,   1,   33, 12, 39, 105,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tel_sv.n_obs = 16;

    test_msg.tel_sv.n_sv_tel = 1;

    test_msg.tel_sv.origin_flags = 1;

    test_msg.tel_sv.sv_tel[0].availability_flags = 5;

    test_msg.tel_sv.sv_tel[0].az = 40;

    test_msg.tel_sv.sv_tel[0].correction_flags = 1;

    test_msg.tel_sv.sv_tel[0].el = 50;

    test_msg.tel_sv.sv_tel[0].ephemeris_flags = 1;

    test_msg.tel_sv.sv_tel[0].outlier_flags = 1;

    test_msg.tel_sv.sv_tel[0].phase_residual = 1;

    test_msg.tel_sv.sv_tel[0].pseudorange_residual = -30;

    test_msg.tel_sv.sv_tel[0].sid.code = 12;

    test_msg.tel_sv.sv_tel[0].sid.sat = 33;

    test_msg.tel_sv.tow = 406773200;

    test_msg.tel_sv.wn = 2223;

    sbp_message_send(&sbp_state, SbpMsgTelSv, 9876, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 9876)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgTelSv, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tel_sv.n_obs, 16)
        << "incorrect value for last_msg.msg.tel_sv.n_obs, expected 16, is "
        << (int64_t)last_msg.msg.tel_sv.n_obs;

    EXPECT_EQ(last_msg.msg.tel_sv.n_sv_tel, 1)
        << "incorrect value for last_msg.msg.tel_sv.n_sv_tel, expected 1, is "
        << (int64_t)last_msg.msg.tel_sv.n_sv_tel;

    EXPECT_EQ(last_msg.msg.tel_sv.origin_flags, 1)
        << "incorrect value for last_msg.msg.tel_sv.origin_flags, expected 1, "
           "is "
        << (int64_t)last_msg.msg.tel_sv.origin_flags;

    EXPECT_EQ(last_msg.msg.tel_sv.sv_tel[0].availability_flags, 5)
        << "incorrect value for "
           "last_msg.msg.tel_sv.sv_tel[0].availability_flags, expected 5, is "
        << (int64_t)last_msg.msg.tel_sv.sv_tel[0].availability_flags;

    EXPECT_EQ(last_msg.msg.tel_sv.sv_tel[0].az, 40)
        << "incorrect value for last_msg.msg.tel_sv.sv_tel[0].az, expected 40, "
           "is "
        << (int64_t)last_msg.msg.tel_sv.sv_tel[0].az;

    EXPECT_EQ(last_msg.msg.tel_sv.sv_tel[0].correction_flags, 1)
        << "incorrect value for "
           "last_msg.msg.tel_sv.sv_tel[0].correction_flags, expected 1, is "
        << (int64_t)last_msg.msg.tel_sv.sv_tel[0].correction_flags;

    EXPECT_EQ(last_msg.msg.tel_sv.sv_tel[0].el, 50)
        << "incorrect value for last_msg.msg.tel_sv.sv_tel[0].el, expected 50, "
           "is "
        << (int64_t)last_msg.msg.tel_sv.sv_tel[0].el;

    EXPECT_EQ(last_msg.msg.tel_sv.sv_tel[0].ephemeris_flags, 1)
        << "incorrect value for last_msg.msg.tel_sv.sv_tel[0].ephemeris_flags, "
           "expected 1, is "
        << (int64_t)last_msg.msg.tel_sv.sv_tel[0].ephemeris_flags;

    EXPECT_EQ(last_msg.msg.tel_sv.sv_tel[0].outlier_flags, 1)
        << "incorrect value for last_msg.msg.tel_sv.sv_tel[0].outlier_flags, "
           "expected 1, is "
        << (int64_t)last_msg.msg.tel_sv.sv_tel[0].outlier_flags;

    EXPECT_EQ(last_msg.msg.tel_sv.sv_tel[0].phase_residual, 1)
        << "incorrect value for last_msg.msg.tel_sv.sv_tel[0].phase_residual, "
           "expected 1, is "
        << (int64_t)last_msg.msg.tel_sv.sv_tel[0].phase_residual;

    EXPECT_EQ(last_msg.msg.tel_sv.sv_tel[0].pseudorange_residual, -30)
        << "incorrect value for "
           "last_msg.msg.tel_sv.sv_tel[0].pseudorange_residual, expected -30, "
           "is "
        << (int64_t)last_msg.msg.tel_sv.sv_tel[0].pseudorange_residual;

    EXPECT_EQ(last_msg.msg.tel_sv.sv_tel[0].sid.code, 12)
        << "incorrect value for last_msg.msg.tel_sv.sv_tel[0].sid.code, "
           "expected 12, is "
        << (int64_t)last_msg.msg.tel_sv.sv_tel[0].sid.code;

    EXPECT_EQ(last_msg.msg.tel_sv.sv_tel[0].sid.sat, 33)
        << "incorrect value for last_msg.msg.tel_sv.sv_tel[0].sid.sat, "
           "expected 33, is "
        << (int64_t)last_msg.msg.tel_sv.sv_tel[0].sid.sat;

    EXPECT_EQ(last_msg.msg.tel_sv.tow, 406773200)
        << "incorrect value for last_msg.msg.tel_sv.tow, expected 406773200, "
           "is "
        << (int64_t)last_msg.msg.tel_sv.tow;

    EXPECT_EQ(last_msg.msg.tel_sv.wn, 2223)
        << "incorrect value for last_msg.msg.tel_sv.wn, expected 2223, is "
        << (int64_t)last_msg.msg.tel_sv.wn;
  }
}

}  // namespace
