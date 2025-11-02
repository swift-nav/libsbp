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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgGnssCapb.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/observation.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_observation_MsgGnssCapb,
     test_auto_check_sbp_observation_MsgGnssCapb) {
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

    sbp_callback_register(&sbp_state, SbpMsgGnssCapb, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  150, 0,  123, 0,  110, 176, 207, 6,   0,  106, 8,   26,  171, 80,
        64,  0,   0,  0,   0,  81,  173, 144, 46,  0,  0,   0,   0,   209, 139,
        93,  108, 0,  0,   0,  0,   252, 204, 200, 0,  205, 92,  30,  49,  240,
        203, 21,  24, 212, 93, 182, 32,  0,   0,   0,  0,   105, 32,  192, 27,
        0,   0,   0,  0,   40, 75,  250, 114, 0,   0,  0,   0,   119, 147, 123,
        81,  0,   0,  0,   0,  85,  89,  4,   2,   0,  0,   0,   0,   233, 116,
        137, 22,  0,  0,   0,  0,   199, 109, 219, 11, 221, 171, 248, 82,  0,
        0,   0,   0,  252, 62, 221, 28,  0,   0,   0,  0,   163, 90,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.gnss_capb.gc.bds_active = 1929005864;

    test_msg.gnss_capb.gc.bds_b2 = 33839445;

    test_msg.gnss_capb.gc.bds_b2a = 378107113;

    test_msg.gnss_capb.gc.bds_d2nav = 1367053175;

    test_msg.gnss_capb.gc.gal_active = 1392028637;

    test_msg.gnss_capb.gc.gal_e5 = 484261628;

    test_msg.gnss_capb.gc.glo_active = 13159676;

    test_msg.gnss_capb.gc.glo_l2of = 824073421;

    test_msg.gnss_capb.gc.glo_l3 = 404081648;

    test_msg.gnss_capb.gc.gps_active = 1079028506;

    test_msg.gnss_capb.gc.gps_l2c = 781233489;

    test_msg.gnss_capb.gc.gps_l5 = 1818069969;

    test_msg.gnss_capb.gc.qzss_active = 198929863;

    test_msg.gnss_capb.gc.sbas_active = 548822484;

    test_msg.gnss_capb.gc.sbas_l5 = 465576041;

    test_msg.gnss_capb.t_nmct.tow = 446384;

    test_msg.gnss_capb.t_nmct.wn = 2154;

    sbp_message_send(&sbp_state, SbpMsgGnssCapb, 123, &test_msg, &dummy_write);

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
    EXPECT_EQ(last_msg.sender_id, 123)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgGnssCapb, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.bds_active, 1929005864)
        << "incorrect value for last_msg.msg.gnss_capb.gc.bds_active, expected "
           "1929005864, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.bds_active;

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.bds_b2, 33839445)
        << "incorrect value for last_msg.msg.gnss_capb.gc.bds_b2, expected "
           "33839445, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.bds_b2;

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.bds_b2a, 378107113)
        << "incorrect value for last_msg.msg.gnss_capb.gc.bds_b2a, expected "
           "378107113, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.bds_b2a;

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.bds_d2nav, 1367053175)
        << "incorrect value for last_msg.msg.gnss_capb.gc.bds_d2nav, expected "
           "1367053175, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.bds_d2nav;

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.gal_active, 1392028637)
        << "incorrect value for last_msg.msg.gnss_capb.gc.gal_active, expected "
           "1392028637, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.gal_active;

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.gal_e5, 484261628)
        << "incorrect value for last_msg.msg.gnss_capb.gc.gal_e5, expected "
           "484261628, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.gal_e5;

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.glo_active, 13159676)
        << "incorrect value for last_msg.msg.gnss_capb.gc.glo_active, expected "
           "13159676, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.glo_active;

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.glo_l2of, 824073421)
        << "incorrect value for last_msg.msg.gnss_capb.gc.glo_l2of, expected "
           "824073421, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.glo_l2of;

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.glo_l3, 404081648)
        << "incorrect value for last_msg.msg.gnss_capb.gc.glo_l3, expected "
           "404081648, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.glo_l3;

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.gps_active, 1079028506)
        << "incorrect value for last_msg.msg.gnss_capb.gc.gps_active, expected "
           "1079028506, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.gps_active;

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.gps_l2c, 781233489)
        << "incorrect value for last_msg.msg.gnss_capb.gc.gps_l2c, expected "
           "781233489, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.gps_l2c;

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.gps_l5, 1818069969)
        << "incorrect value for last_msg.msg.gnss_capb.gc.gps_l5, expected "
           "1818069969, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.gps_l5;

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.qzss_active, 198929863)
        << "incorrect value for last_msg.msg.gnss_capb.gc.qzss_active, "
           "expected 198929863, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.qzss_active;

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.sbas_active, 548822484)
        << "incorrect value for last_msg.msg.gnss_capb.gc.sbas_active, "
           "expected 548822484, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.sbas_active;

    EXPECT_EQ(last_msg.msg.gnss_capb.gc.sbas_l5, 465576041)
        << "incorrect value for last_msg.msg.gnss_capb.gc.sbas_l5, expected "
           "465576041, is "
        << (int64_t)last_msg.msg.gnss_capb.gc.sbas_l5;

    EXPECT_EQ(last_msg.msg.gnss_capb.t_nmct.tow, 446384)
        << "incorrect value for last_msg.msg.gnss_capb.t_nmct.tow, expected "
           "446384, is "
        << (int64_t)last_msg.msg.gnss_capb.t_nmct.tow;

    EXPECT_EQ(last_msg.msg.gnss_capb.t_nmct.wn, 2154)
        << "incorrect value for last_msg.msg.gnss_capb.t_nmct.wn, expected "
           "2154, is "
        << (int64_t)last_msg.msg.gnss_capb.t_nmct.wn;
  }
}

}  // namespace
