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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDep.yaml
// by generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/sbp.h>
#include <libsbp/tracking.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_tracking_MsgTrackingStateDetailedDep,
     test_auto_check_sbp_tracking_MsgTrackingStateDetailedDep) {
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

    sbp_callback_register(&sbp_state, SbpMsgTrackingStateDetailedDep,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  17, 0,  59, 103, 55, 163, 151, 112, 215, 1,  0, 0, 0,   0,   0,
        0,   0,  0,  0,  0,   0,  0,   0,   0,   0,   39, 5, 0, 0,   169, 177,
        208, 54, 15, 0,  0,   0,  85,  61,  0,   0,   39, 0, 1, 0,   0,   0,
        0,   0,  0,  0,  40,  0,  108, 1,   0,   11,  0,  0, 9, 166, 214,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_detailed_dep.L.f = 169;

    test_msg.tracking_state_detailed_dep.L.i = 1319;

    test_msg.tracking_state_detailed_dep.P = 0;

    test_msg.tracking_state_detailed_dep.P_std = 0;

    test_msg.tracking_state_detailed_dep.acceleration = 108;

    test_msg.tracking_state_detailed_dep.clock_drift = 0;

    test_msg.tracking_state_detailed_dep.clock_offset = 0;

    test_msg.tracking_state_detailed_dep.cn0 = 177;

    test_msg.tracking_state_detailed_dep.corr_spacing = 40;

    test_msg.tracking_state_detailed_dep.doppler = 15701;

    test_msg.tracking_state_detailed_dep.doppler_std = 39;

    test_msg.tracking_state_detailed_dep.lock = 14032;

    test_msg.tracking_state_detailed_dep.misc_flags = 9;

    test_msg.tracking_state_detailed_dep.nav_flags = 0;

    test_msg.tracking_state_detailed_dep.pset_flags = 0;

    test_msg.tracking_state_detailed_dep.recv_time = 7909447587;

    test_msg.tracking_state_detailed_dep.sid.code = 0;

    test_msg.tracking_state_detailed_dep.sid.reserved = 0;

    test_msg.tracking_state_detailed_dep.sid.sat = 15;

    test_msg.tracking_state_detailed_dep.sync_flags = 1;

    test_msg.tracking_state_detailed_dep.tot.tow = 0;

    test_msg.tracking_state_detailed_dep.tot.wn = 0;

    test_msg.tracking_state_detailed_dep.tow_flags = 0;

    test_msg.tracking_state_detailed_dep.track_flags = 11;

    test_msg.tracking_state_detailed_dep.uptime = 1;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDetailedDep, 26427,
                     &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 26427)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.L.f, 169)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.L.f, "
           "expected 169, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.L.f;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.L.i, 1319)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.L.i, "
           "expected 1319, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.L.i;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.P, 0)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.P, "
           "expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.P;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.P_std, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.P_std, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.P_std;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.acceleration, 108)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.acceleration, expected "
           "108, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.acceleration;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.clock_drift, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.clock_drift, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.clock_drift;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.clock_offset, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.clock_offset, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.clock_offset;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.cn0, 177)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.cn0, "
           "expected 177, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.corr_spacing, 40)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.corr_spacing, expected "
           "40, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.corr_spacing;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.doppler, 15701)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.doppler, expected 15701, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.doppler;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.doppler_std, 39)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.doppler_std, expected 39, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.doppler_std;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.lock, 14032)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.lock, "
           "expected 14032, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.lock;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.misc_flags, 9)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.misc_flags, expected 9, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.misc_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.nav_flags, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.nav_flags, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.nav_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.pset_flags, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.pset_flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.pset_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.recv_time, 7909447587)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.recv_time, expected "
           "7909447587, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.recv_time;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.code, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.reserved, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.sat, 15)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.sat, expected 15, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sync_flags, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sync_flags, expected 1, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sync_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tot.tow, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tot.tow, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tot.tow;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tot.wn, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tot.wn, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tot.wn;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tow_flags, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tow_flags, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tow_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.track_flags, 11)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.track_flags, expected 11, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.track_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.uptime, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.uptime, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.uptime;
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

    sbp_callback_register(&sbp_state, SbpMsgTrackingStateDetailedDep,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  17, 0,  59, 103, 55, 97,  251, 61, 245, 1,  0, 0, 0,   0,   0,
        0,   0,  0,  0,  0,   0,  0,   0,   0,  0,   18, 7, 0, 0,   14,  175,
        208, 54, 15, 0,  0,   0,  51,  61,  0,  0,   30, 0, 1, 0,   0,   0,
        0,   0,  0,  0,  40,  0,  224, 1,   0,  11,  0,  0, 9, 136, 179,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_detailed_dep.L.f = 14;

    test_msg.tracking_state_detailed_dep.L.i = 1810;

    test_msg.tracking_state_detailed_dep.P = 0;

    test_msg.tracking_state_detailed_dep.P_std = 0;

    test_msg.tracking_state_detailed_dep.acceleration = -32;

    test_msg.tracking_state_detailed_dep.clock_drift = 0;

    test_msg.tracking_state_detailed_dep.clock_offset = 0;

    test_msg.tracking_state_detailed_dep.cn0 = 175;

    test_msg.tracking_state_detailed_dep.corr_spacing = 40;

    test_msg.tracking_state_detailed_dep.doppler = 15667;

    test_msg.tracking_state_detailed_dep.doppler_std = 30;

    test_msg.tracking_state_detailed_dep.lock = 14032;

    test_msg.tracking_state_detailed_dep.misc_flags = 9;

    test_msg.tracking_state_detailed_dep.nav_flags = 0;

    test_msg.tracking_state_detailed_dep.pset_flags = 0;

    test_msg.tracking_state_detailed_dep.recv_time = 8409447265;

    test_msg.tracking_state_detailed_dep.sid.code = 0;

    test_msg.tracking_state_detailed_dep.sid.reserved = 0;

    test_msg.tracking_state_detailed_dep.sid.sat = 15;

    test_msg.tracking_state_detailed_dep.sync_flags = 1;

    test_msg.tracking_state_detailed_dep.tot.tow = 0;

    test_msg.tracking_state_detailed_dep.tot.wn = 0;

    test_msg.tracking_state_detailed_dep.tow_flags = 0;

    test_msg.tracking_state_detailed_dep.track_flags = 11;

    test_msg.tracking_state_detailed_dep.uptime = 1;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDetailedDep, 26427,
                     &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 26427)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.L.f, 14)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.L.f, "
           "expected 14, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.L.f;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.L.i, 1810)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.L.i, "
           "expected 1810, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.L.i;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.P, 0)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.P, "
           "expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.P;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.P_std, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.P_std, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.P_std;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.acceleration, -32)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.acceleration, expected "
           "-32, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.acceleration;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.clock_drift, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.clock_drift, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.clock_drift;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.clock_offset, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.clock_offset, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.clock_offset;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.cn0, 175)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.cn0, "
           "expected 175, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.corr_spacing, 40)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.corr_spacing, expected "
           "40, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.corr_spacing;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.doppler, 15667)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.doppler, expected 15667, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.doppler;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.doppler_std, 30)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.doppler_std, expected 30, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.doppler_std;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.lock, 14032)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.lock, "
           "expected 14032, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.lock;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.misc_flags, 9)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.misc_flags, expected 9, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.misc_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.nav_flags, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.nav_flags, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.nav_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.pset_flags, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.pset_flags, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.pset_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.recv_time, 8409447265)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.recv_time, expected "
           "8409447265, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.recv_time;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.code, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.reserved, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.sat, 15)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.sat, expected 15, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sync_flags, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sync_flags, expected 1, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sync_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tot.tow, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tot.tow, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tot.tow;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tot.wn, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tot.wn, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tot.wn;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tow_flags, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tow_flags, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tow_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.track_flags, 11)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.track_flags, expected 11, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.track_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.uptime, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.uptime, expected 1, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.uptime;
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

    sbp_callback_register(&sbp_state, SbpMsgTrackingStateDetailedDep,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  17, 0,  59, 103, 55, 139, 218, 236, 18, 2,   0, 0, 0,   0,   0,
        0,   0,  0,  0,  0,   0,  0,   0,   0,   0,  250, 8, 0, 0,   8,   179,
        208, 54, 15, 0,  0,   0,  67,  61,  0,   0,  22,  0, 2, 0,   0,   0,
        0,   0,  0,  0,  40,  0,  27,  1,   0,   11, 0,   2, 9, 217, 159,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_detailed_dep.L.f = 8;

    test_msg.tracking_state_detailed_dep.L.i = 2298;

    test_msg.tracking_state_detailed_dep.P = 0;

    test_msg.tracking_state_detailed_dep.P_std = 0;

    test_msg.tracking_state_detailed_dep.acceleration = 27;

    test_msg.tracking_state_detailed_dep.clock_drift = 0;

    test_msg.tracking_state_detailed_dep.clock_offset = 0;

    test_msg.tracking_state_detailed_dep.cn0 = 179;

    test_msg.tracking_state_detailed_dep.corr_spacing = 40;

    test_msg.tracking_state_detailed_dep.doppler = 15683;

    test_msg.tracking_state_detailed_dep.doppler_std = 22;

    test_msg.tracking_state_detailed_dep.lock = 14032;

    test_msg.tracking_state_detailed_dep.misc_flags = 9;

    test_msg.tracking_state_detailed_dep.nav_flags = 0;

    test_msg.tracking_state_detailed_dep.pset_flags = 2;

    test_msg.tracking_state_detailed_dep.recv_time = 8907446923;

    test_msg.tracking_state_detailed_dep.sid.code = 0;

    test_msg.tracking_state_detailed_dep.sid.reserved = 0;

    test_msg.tracking_state_detailed_dep.sid.sat = 15;

    test_msg.tracking_state_detailed_dep.sync_flags = 1;

    test_msg.tracking_state_detailed_dep.tot.tow = 0;

    test_msg.tracking_state_detailed_dep.tot.wn = 0;

    test_msg.tracking_state_detailed_dep.tow_flags = 0;

    test_msg.tracking_state_detailed_dep.track_flags = 11;

    test_msg.tracking_state_detailed_dep.uptime = 2;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDetailedDep, 26427,
                     &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 26427)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.L.f, 8)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.L.f, "
           "expected 8, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.L.f;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.L.i, 2298)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.L.i, "
           "expected 2298, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.L.i;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.P, 0)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.P, "
           "expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.P;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.P_std, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.P_std, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.P_std;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.acceleration, 27)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.acceleration, expected "
           "27, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.acceleration;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.clock_drift, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.clock_drift, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.clock_drift;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.clock_offset, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.clock_offset, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.clock_offset;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.cn0, 179)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.cn0, "
           "expected 179, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.corr_spacing, 40)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.corr_spacing, expected "
           "40, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.corr_spacing;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.doppler, 15683)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.doppler, expected 15683, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.doppler;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.doppler_std, 22)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.doppler_std, expected 22, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.doppler_std;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.lock, 14032)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.lock, "
           "expected 14032, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.lock;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.misc_flags, 9)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.misc_flags, expected 9, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.misc_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.nav_flags, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.nav_flags, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.nav_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.pset_flags, 2)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.pset_flags, expected 2, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.pset_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.recv_time, 8907446923)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.recv_time, expected "
           "8907446923, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.recv_time;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.code, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.reserved, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.sat, 15)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.sat, expected 15, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sync_flags, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sync_flags, expected 1, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sync_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tot.tow, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tot.tow, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tot.tow;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tot.wn, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tot.wn, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tot.wn;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tow_flags, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tow_flags, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tow_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.track_flags, 11)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.track_flags, expected 11, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.track_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.uptime, 2)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.uptime, expected 2, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.uptime;
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

    sbp_callback_register(&sbp_state, SbpMsgTrackingStateDetailedDep,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  17, 0,  59, 103, 55, 255, 251, 170, 48, 2,   0,  0, 0,  0,   0,
        0,   0,  0,  0,  0,   0,  0,   0,   0,   0,  226, 10, 0, 0,  125, 181,
        208, 54, 15, 0,  0,   0,  29,  61,  0,   0,  10,  0,  2, 0,  0,   0,
        0,   0,  0,  0,  40,  0,  220, 1,   0,   11, 0,   3,  9, 66, 95,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_detailed_dep.L.f = 125;

    test_msg.tracking_state_detailed_dep.L.i = 2786;

    test_msg.tracking_state_detailed_dep.P = 0;

    test_msg.tracking_state_detailed_dep.P_std = 0;

    test_msg.tracking_state_detailed_dep.acceleration = -36;

    test_msg.tracking_state_detailed_dep.clock_drift = 0;

    test_msg.tracking_state_detailed_dep.clock_offset = 0;

    test_msg.tracking_state_detailed_dep.cn0 = 181;

    test_msg.tracking_state_detailed_dep.corr_spacing = 40;

    test_msg.tracking_state_detailed_dep.doppler = 15645;

    test_msg.tracking_state_detailed_dep.doppler_std = 10;

    test_msg.tracking_state_detailed_dep.lock = 14032;

    test_msg.tracking_state_detailed_dep.misc_flags = 9;

    test_msg.tracking_state_detailed_dep.nav_flags = 0;

    test_msg.tracking_state_detailed_dep.pset_flags = 3;

    test_msg.tracking_state_detailed_dep.recv_time = 9406446591;

    test_msg.tracking_state_detailed_dep.sid.code = 0;

    test_msg.tracking_state_detailed_dep.sid.reserved = 0;

    test_msg.tracking_state_detailed_dep.sid.sat = 15;

    test_msg.tracking_state_detailed_dep.sync_flags = 1;

    test_msg.tracking_state_detailed_dep.tot.tow = 0;

    test_msg.tracking_state_detailed_dep.tot.wn = 0;

    test_msg.tracking_state_detailed_dep.tow_flags = 0;

    test_msg.tracking_state_detailed_dep.track_flags = 11;

    test_msg.tracking_state_detailed_dep.uptime = 2;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDetailedDep, 26427,
                     &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 26427)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.L.f, 125)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.L.f, "
           "expected 125, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.L.f;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.L.i, 2786)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.L.i, "
           "expected 2786, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.L.i;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.P, 0)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.P, "
           "expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.P;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.P_std, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.P_std, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.P_std;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.acceleration, -36)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.acceleration, expected "
           "-36, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.acceleration;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.clock_drift, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.clock_drift, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.clock_drift;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.clock_offset, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.clock_offset, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.clock_offset;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.cn0, 181)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.cn0, "
           "expected 181, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.corr_spacing, 40)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.corr_spacing, expected "
           "40, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.corr_spacing;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.doppler, 15645)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.doppler, expected 15645, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.doppler;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.doppler_std, 10)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.doppler_std, expected 10, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.doppler_std;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.lock, 14032)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.lock, "
           "expected 14032, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.lock;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.misc_flags, 9)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.misc_flags, expected 9, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.misc_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.nav_flags, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.nav_flags, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.nav_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.pset_flags, 3)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.pset_flags, expected 3, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.pset_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.recv_time, 9406446591)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.recv_time, expected "
           "9406446591, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.recv_time;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.code, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.reserved, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.sat, 15)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.sat, expected 15, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sync_flags, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sync_flags, expected 1, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sync_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tot.tow, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tot.tow, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tot.tow;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tot.wn, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tot.wn, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tot.wn;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tow_flags, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tow_flags, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tow_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.track_flags, 11)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.track_flags, expected 11, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.track_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.uptime, 2)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.uptime, expected 2, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.uptime;
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

    sbp_callback_register(&sbp_state, SbpMsgTrackingStateDetailedDep,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  17, 0,  59, 103, 55, 189, 95, 120, 78, 2,   0,  0, 0,   0,   0,
        0,   0,  0,  0,  0,   0,  0,   0,  0,   0,  203, 12, 0, 0,   64,  184,
        208, 54, 15, 0,  0,   0,  24,  61, 0,   0,  4,   0,  3, 0,   0,   0,
        0,   0,  0,  0,  40,  0,  2,   1,  0,   11, 0,   3,  9, 194, 206,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.tracking_state_detailed_dep.L.f = 64;

    test_msg.tracking_state_detailed_dep.L.i = 3275;

    test_msg.tracking_state_detailed_dep.P = 0;

    test_msg.tracking_state_detailed_dep.P_std = 0;

    test_msg.tracking_state_detailed_dep.acceleration = 2;

    test_msg.tracking_state_detailed_dep.clock_drift = 0;

    test_msg.tracking_state_detailed_dep.clock_offset = 0;

    test_msg.tracking_state_detailed_dep.cn0 = 184;

    test_msg.tracking_state_detailed_dep.corr_spacing = 40;

    test_msg.tracking_state_detailed_dep.doppler = 15640;

    test_msg.tracking_state_detailed_dep.doppler_std = 4;

    test_msg.tracking_state_detailed_dep.lock = 14032;

    test_msg.tracking_state_detailed_dep.misc_flags = 9;

    test_msg.tracking_state_detailed_dep.nav_flags = 0;

    test_msg.tracking_state_detailed_dep.pset_flags = 3;

    test_msg.tracking_state_detailed_dep.recv_time = 9906446269;

    test_msg.tracking_state_detailed_dep.sid.code = 0;

    test_msg.tracking_state_detailed_dep.sid.reserved = 0;

    test_msg.tracking_state_detailed_dep.sid.sat = 15;

    test_msg.tracking_state_detailed_dep.sync_flags = 1;

    test_msg.tracking_state_detailed_dep.tot.tow = 0;

    test_msg.tracking_state_detailed_dep.tot.wn = 0;

    test_msg.tracking_state_detailed_dep.tow_flags = 0;

    test_msg.tracking_state_detailed_dep.track_flags = 11;

    test_msg.tracking_state_detailed_dep.uptime = 3;

    sbp_message_send(&sbp_state, SbpMsgTrackingStateDetailedDep, 26427,
                     &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 26427)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.L.f, 64)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.L.f, "
           "expected 64, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.L.f;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.L.i, 3275)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.L.i, "
           "expected 3275, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.L.i;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.P, 0)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.P, "
           "expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.P;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.P_std, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.P_std, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.P_std;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.acceleration, 2)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.acceleration, expected 2, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.acceleration;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.clock_drift, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.clock_drift, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.clock_drift;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.clock_offset, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.clock_offset, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.clock_offset;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.cn0, 184)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.cn0, "
           "expected 184, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.cn0;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.corr_spacing, 40)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.corr_spacing, expected "
           "40, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.corr_spacing;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.doppler, 15640)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.doppler, expected 15640, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.doppler;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.doppler_std, 4)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.doppler_std, expected 4, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.doppler_std;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.lock, 14032)
        << "incorrect value for last_msg.msg.tracking_state_detailed_dep.lock, "
           "expected 14032, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.lock;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.misc_flags, 9)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.misc_flags, expected 9, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.misc_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.nav_flags, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.nav_flags, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.nav_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.pset_flags, 3)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.pset_flags, expected 3, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.pset_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.recv_time, 9906446269)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.recv_time, expected "
           "9906446269, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.recv_time;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.code, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.code, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.code;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.reserved, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.reserved, expected 0, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.reserved;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sid.sat, 15)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sid.sat, expected 15, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sid.sat;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.sync_flags, 1)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.sync_flags, expected 1, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.sync_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tot.tow, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tot.tow, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tot.tow;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tot.wn, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tot.wn, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tot.wn;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.tow_flags, 0)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.tow_flags, expected 0, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.tow_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.track_flags, 11)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.track_flags, expected 11, "
           "is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.track_flags;

    EXPECT_EQ(last_msg.msg.tracking_state_detailed_dep.uptime, 3)
        << "incorrect value for "
           "last_msg.msg.tracking_state_detailed_dep.uptime, expected 3, is "
        << (int64_t)last_msg.msg.tracking_state_detailed_dep.uptime;
  }
}

}  // namespace
