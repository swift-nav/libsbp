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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgNetworkBandwidthUsage.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/piksi.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_piksi_MsgNetworkBandwidthUsage,
     test_auto_check_sbp_piksi_MsgNetworkBandwidthUsage) {
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

    sbp_callback_register(&sbp_state, SbpMsgNetworkBandwidthUsage,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  189, 0,   207, 121, 200, 94,  105, 178, 128, 0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   99,  97,  110, 48,  0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   94,  105, 178, 128, 0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        99,  97,  110, 49,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   94,  105, 178, 128, 0,   0,   0,   0,   165, 235, 94,  203,
        0,   0,   0,   0,   237, 14,  148, 240, 184, 220, 202, 218, 101, 116,
        104, 48,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        94,  105, 178, 128, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   108, 111, 0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   94,  105,
        178, 128, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   115, 105, 116, 48,  0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   27,  133,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.network_bandwidth_usage.interfaces[0].duration = 2159176030;

    {
      const char assign_string[] = {(char)99, (char)97, (char)110, (char)48,
                                    (char)0,  (char)0,  (char)0,   (char)0,
                                    (char)0,  (char)0,  (char)0,   (char)0,
                                    (char)0,  (char)0,  (char)0,   (char)0};
      memcpy(test_msg.network_bandwidth_usage.interfaces[0].interface_name,
             assign_string, sizeof(assign_string));
    }

    test_msg.network_bandwidth_usage.interfaces[0].rx_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[0].total_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[0].tx_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[1].duration = 2159176030;

    {
      const char assign_string[] = {(char)99, (char)97, (char)110, (char)49,
                                    (char)0,  (char)0,  (char)0,   (char)0,
                                    (char)0,  (char)0,  (char)0,   (char)0,
                                    (char)0,  (char)0,  (char)0,   (char)0};
      memcpy(test_msg.network_bandwidth_usage.interfaces[1].interface_name,
             assign_string, sizeof(assign_string));
    }

    test_msg.network_bandwidth_usage.interfaces[1].rx_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[1].total_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[1].tx_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[2].duration = 2159176030;

    {
      const char assign_string[] = {(char)101, (char)116, (char)104, (char)48,
                                    (char)0,   (char)0,   (char)0,   (char)0,
                                    (char)0,   (char)0,   (char)0,   (char)0,
                                    (char)0,   (char)0,   (char)0,   (char)0};
      memcpy(test_msg.network_bandwidth_usage.interfaces[2].interface_name,
             assign_string, sizeof(assign_string));
    }

    test_msg.network_bandwidth_usage.interfaces[2].rx_bytes = 4036234989;

    test_msg.network_bandwidth_usage.interfaces[2].total_bytes = 3411995557;

    test_msg.network_bandwidth_usage.interfaces[2].tx_bytes = 3670727864;

    test_msg.network_bandwidth_usage.interfaces[3].duration = 2159176030;

    {
      const char assign_string[] = {(char)108, (char)111, (char)0, (char)0,
                                    (char)0,   (char)0,   (char)0, (char)0,
                                    (char)0,   (char)0,   (char)0, (char)0,
                                    (char)0,   (char)0,   (char)0, (char)0};
      memcpy(test_msg.network_bandwidth_usage.interfaces[3].interface_name,
             assign_string, sizeof(assign_string));
    }

    test_msg.network_bandwidth_usage.interfaces[3].rx_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[3].total_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[3].tx_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[4].duration = 2159176030;

    {
      const char assign_string[] = {(char)115, (char)105, (char)116, (char)48,
                                    (char)0,   (char)0,   (char)0,   (char)0,
                                    (char)0,   (char)0,   (char)0,   (char)0,
                                    (char)0,   (char)0,   (char)0,   (char)0};
      memcpy(test_msg.network_bandwidth_usage.interfaces[4].interface_name,
             assign_string, sizeof(assign_string));
    }

    test_msg.network_bandwidth_usage.interfaces[4].rx_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[4].total_bytes = 0;

    test_msg.network_bandwidth_usage.interfaces[4].tx_bytes = 0;

    test_msg.network_bandwidth_usage.n_interfaces = 5;

    sbp_message_send(&sbp_state, SbpMsgNetworkBandwidthUsage, 31183, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 31183)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgNetworkBandwidthUsage, &last_msg.msg, &test_msg),
        0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[0].duration,
              2159176030)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[0].duration, "
           "expected 2159176030, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[0].duration;

    {
      const char check_string[] = {(char)99, (char)97, (char)110, (char)48,
                                   (char)0,  (char)0,  (char)0,   (char)0,
                                   (char)0,  (char)0,  (char)0,   (char)0,
                                   (char)0,  (char)0,  (char)0,   (char)0};
      EXPECT_EQ(memcmp(&last_msg.msg.network_bandwidth_usage.interfaces[0]
                            .interface_name,
                       check_string, sizeof(check_string)),
                0)
          << "incorrect value for "
             "last_msg.msg.network_bandwidth_usage.interfaces[0].interface_"
             "name, expected string '"
          << check_string << "', is '"
          << last_msg.msg.network_bandwidth_usage.interfaces[0].interface_name
          << "'";
    }

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[0].rx_bytes, 0)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[0].rx_bytes, "
           "expected 0, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[0].rx_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[0].total_bytes, 0)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[0].total_bytes, "
           "expected 0, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[0]
               .total_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[0].tx_bytes, 0)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[0].tx_bytes, "
           "expected 0, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[0].tx_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[1].duration,
              2159176030)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[1].duration, "
           "expected 2159176030, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[1].duration;

    {
      const char check_string[] = {(char)99, (char)97, (char)110, (char)49,
                                   (char)0,  (char)0,  (char)0,   (char)0,
                                   (char)0,  (char)0,  (char)0,   (char)0,
                                   (char)0,  (char)0,  (char)0,   (char)0};
      EXPECT_EQ(memcmp(&last_msg.msg.network_bandwidth_usage.interfaces[1]
                            .interface_name,
                       check_string, sizeof(check_string)),
                0)
          << "incorrect value for "
             "last_msg.msg.network_bandwidth_usage.interfaces[1].interface_"
             "name, expected string '"
          << check_string << "', is '"
          << last_msg.msg.network_bandwidth_usage.interfaces[1].interface_name
          << "'";
    }

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[1].rx_bytes, 0)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[1].rx_bytes, "
           "expected 0, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[1].rx_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[1].total_bytes, 0)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[1].total_bytes, "
           "expected 0, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[1]
               .total_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[1].tx_bytes, 0)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[1].tx_bytes, "
           "expected 0, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[1].tx_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[2].duration,
              2159176030)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[2].duration, "
           "expected 2159176030, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[2].duration;

    {
      const char check_string[] = {(char)101, (char)116, (char)104, (char)48,
                                   (char)0,   (char)0,   (char)0,   (char)0,
                                   (char)0,   (char)0,   (char)0,   (char)0,
                                   (char)0,   (char)0,   (char)0,   (char)0};
      EXPECT_EQ(memcmp(&last_msg.msg.network_bandwidth_usage.interfaces[2]
                            .interface_name,
                       check_string, sizeof(check_string)),
                0)
          << "incorrect value for "
             "last_msg.msg.network_bandwidth_usage.interfaces[2].interface_"
             "name, expected string '"
          << check_string << "', is '"
          << last_msg.msg.network_bandwidth_usage.interfaces[2].interface_name
          << "'";
    }

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[2].rx_bytes,
              4036234989)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[2].rx_bytes, "
           "expected 4036234989, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[2].rx_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[2].total_bytes,
              3411995557)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[2].total_bytes, "
           "expected 3411995557, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[2]
               .total_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[2].tx_bytes,
              3670727864)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[2].tx_bytes, "
           "expected 3670727864, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[2].tx_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[3].duration,
              2159176030)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[3].duration, "
           "expected 2159176030, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[3].duration;

    {
      const char check_string[] = {(char)108, (char)111, (char)0, (char)0,
                                   (char)0,   (char)0,   (char)0, (char)0,
                                   (char)0,   (char)0,   (char)0, (char)0,
                                   (char)0,   (char)0,   (char)0, (char)0};
      EXPECT_EQ(memcmp(&last_msg.msg.network_bandwidth_usage.interfaces[3]
                            .interface_name,
                       check_string, sizeof(check_string)),
                0)
          << "incorrect value for "
             "last_msg.msg.network_bandwidth_usage.interfaces[3].interface_"
             "name, expected string '"
          << check_string << "', is '"
          << last_msg.msg.network_bandwidth_usage.interfaces[3].interface_name
          << "'";
    }

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[3].rx_bytes, 0)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[3].rx_bytes, "
           "expected 0, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[3].rx_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[3].total_bytes, 0)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[3].total_bytes, "
           "expected 0, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[3]
               .total_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[3].tx_bytes, 0)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[3].tx_bytes, "
           "expected 0, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[3].tx_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[4].duration,
              2159176030)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[4].duration, "
           "expected 2159176030, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[4].duration;

    {
      const char check_string[] = {(char)115, (char)105, (char)116, (char)48,
                                   (char)0,   (char)0,   (char)0,   (char)0,
                                   (char)0,   (char)0,   (char)0,   (char)0,
                                   (char)0,   (char)0,   (char)0,   (char)0};
      EXPECT_EQ(memcmp(&last_msg.msg.network_bandwidth_usage.interfaces[4]
                            .interface_name,
                       check_string, sizeof(check_string)),
                0)
          << "incorrect value for "
             "last_msg.msg.network_bandwidth_usage.interfaces[4].interface_"
             "name, expected string '"
          << check_string << "', is '"
          << last_msg.msg.network_bandwidth_usage.interfaces[4].interface_name
          << "'";
    }

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[4].rx_bytes, 0)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[4].rx_bytes, "
           "expected 0, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[4].rx_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[4].total_bytes, 0)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[4].total_bytes, "
           "expected 0, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[4]
               .total_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.interfaces[4].tx_bytes, 0)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.interfaces[4].tx_bytes, "
           "expected 0, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.interfaces[4].tx_bytes;

    EXPECT_EQ(last_msg.msg.network_bandwidth_usage.n_interfaces, 5)
        << "incorrect value for "
           "last_msg.msg.network_bandwidth_usage.n_interfaces, expected 5, is "
        << (int64_t)last_msg.msg.network_bandwidth_usage.n_interfaces;
  }
}

}  // namespace
