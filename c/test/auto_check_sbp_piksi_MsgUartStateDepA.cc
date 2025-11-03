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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartStateDepA.yaml by generate.py.
// Do not modify by hand!

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

TEST(auto_check_sbp_piksi_MsgUartStateDepA,
     test_auto_check_sbp_piksi_MsgUartStateDepA) {
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

    sbp_callback_register(&sbp_state, SbpMsgUartStateDepa, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 24, 0, 195, 4,   58,  0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   154, 153, 57,  65,  0, 0, 0, 0,
        0,  0,  0, 0,   15,  0,   255, 255, 255, 255, 0, 0, 0, 0,
        0,  0,  0, 0,   255, 255, 255, 255, 247, 5,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.uart_state_depa.latency.avg = -1;

    test_msg.uart_state_depa.latency.current = -1;

    test_msg.uart_state_depa.latency.lmax = 0;

    test_msg.uart_state_depa.latency.lmin = 0;

    test_msg.uart_state_depa.uart_a.crc_error_count = 0;

    test_msg.uart_state_depa.uart_a.io_error_count = 0;

    test_msg.uart_state_depa.uart_a.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_a.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_a.tx_buffer_level = 0;

    test_msg.uart_state_depa.uart_a.tx_throughput = 0.0;

    test_msg.uart_state_depa.uart_b.crc_error_count = 0;

    test_msg.uart_state_depa.uart_b.io_error_count = 0;

    test_msg.uart_state_depa.uart_b.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_b.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_b.tx_buffer_level = 0;

    test_msg.uart_state_depa.uart_b.tx_throughput = 0.0;

    test_msg.uart_state_depa.uart_ftdi.crc_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.io_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_ftdi.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_ftdi.tx_buffer_level = 15;

    test_msg.uart_state_depa.uart_ftdi.tx_throughput = 11.600000381469727;

    sbp_message_send(&sbp_state, SbpMsgUartStateDepa, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgUartStateDepa, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.avg, -1)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.avg, "
           "expected -1, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.avg;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.current, -1)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.current, "
           "expected -1, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.current;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.lmax, 0)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.lmax, "
           "expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.lmax;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.lmin, 0)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.lmin, "
           "expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.lmin;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.crc_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.io_error_count, expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.rx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.rx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_a.rx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.rx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_a.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.tx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.tx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.tx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_a.tx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.tx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_a.tx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.crc_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.io_error_count, expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.rx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.rx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_b.rx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.rx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_b.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.tx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.tx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.tx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_b.tx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.tx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_b.tx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count, expected "
           "0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.io_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level, expected "
           "0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput * 100 -
               0.0 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput, expected "
           "0.0, is "
        << last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level, 15)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level, expected "
           "15, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput * 100 -
               11.6000003815 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput, expected "
           "11.6000003815, is "
        << last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput;
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

    sbp_callback_register(&sbp_state, SbpMsgUartStateDepa, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 24, 0, 195, 4,   58,  0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   2,   43,  135, 61,  0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   255, 255, 255, 255, 0, 0, 0, 0,
        0,  0,  0, 0,   255, 255, 255, 255, 65,  110,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.uart_state_depa.latency.avg = -1;

    test_msg.uart_state_depa.latency.current = -1;

    test_msg.uart_state_depa.latency.lmax = 0;

    test_msg.uart_state_depa.latency.lmin = 0;

    test_msg.uart_state_depa.uart_a.crc_error_count = 0;

    test_msg.uart_state_depa.uart_a.io_error_count = 0;

    test_msg.uart_state_depa.uart_a.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_a.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_a.tx_buffer_level = 0;

    test_msg.uart_state_depa.uart_a.tx_throughput = 0.0;

    test_msg.uart_state_depa.uart_b.crc_error_count = 0;

    test_msg.uart_state_depa.uart_b.io_error_count = 0;

    test_msg.uart_state_depa.uart_b.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_b.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_b.tx_buffer_level = 0;

    test_msg.uart_state_depa.uart_b.tx_throughput = 0.0;

    test_msg.uart_state_depa.uart_ftdi.crc_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.io_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_ftdi.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_ftdi.tx_buffer_level = 0;

    test_msg.uart_state_depa.uart_ftdi.tx_throughput = 0.06599999964237213;

    sbp_message_send(&sbp_state, SbpMsgUartStateDepa, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgUartStateDepa, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.avg, -1)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.avg, "
           "expected -1, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.avg;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.current, -1)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.current, "
           "expected -1, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.current;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.lmax, 0)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.lmax, "
           "expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.lmax;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.lmin, 0)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.lmin, "
           "expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.lmin;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.crc_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.io_error_count, expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.rx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.rx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_a.rx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.rx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_a.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.tx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.tx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.tx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_a.tx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.tx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_a.tx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.crc_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.io_error_count, expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.rx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.rx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_b.rx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.rx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_b.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.tx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.tx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.tx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_b.tx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.tx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_b.tx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count, expected "
           "0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.io_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level, expected "
           "0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput * 100 -
               0.0 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput, expected "
           "0.0, is "
        << last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level, expected "
           "0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput * 100 -
               0.0659999996424 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput, expected "
           "0.0659999996424, is "
        << last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput;
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

    sbp_callback_register(&sbp_state, SbpMsgUartStateDepa, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 24, 0, 195, 4,   58,  0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   4,   86,  14,  62,  0, 0, 0, 0,
        0,  0,  0, 0,   10,  0,   255, 255, 255, 255, 0, 0, 0, 0,
        0,  0,  0, 0,   255, 255, 255, 255, 198, 36,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.uart_state_depa.latency.avg = -1;

    test_msg.uart_state_depa.latency.current = -1;

    test_msg.uart_state_depa.latency.lmax = 0;

    test_msg.uart_state_depa.latency.lmin = 0;

    test_msg.uart_state_depa.uart_a.crc_error_count = 0;

    test_msg.uart_state_depa.uart_a.io_error_count = 0;

    test_msg.uart_state_depa.uart_a.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_a.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_a.tx_buffer_level = 0;

    test_msg.uart_state_depa.uart_a.tx_throughput = 0.0;

    test_msg.uart_state_depa.uart_b.crc_error_count = 0;

    test_msg.uart_state_depa.uart_b.io_error_count = 0;

    test_msg.uart_state_depa.uart_b.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_b.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_b.tx_buffer_level = 0;

    test_msg.uart_state_depa.uart_b.tx_throughput = 0.0;

    test_msg.uart_state_depa.uart_ftdi.crc_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.io_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_ftdi.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_ftdi.tx_buffer_level = 10;

    test_msg.uart_state_depa.uart_ftdi.tx_throughput = 0.13899999856948853;

    sbp_message_send(&sbp_state, SbpMsgUartStateDepa, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgUartStateDepa, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.avg, -1)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.avg, "
           "expected -1, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.avg;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.current, -1)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.current, "
           "expected -1, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.current;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.lmax, 0)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.lmax, "
           "expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.lmax;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.lmin, 0)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.lmin, "
           "expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.lmin;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.crc_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.io_error_count, expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.rx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.rx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_a.rx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.rx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_a.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.tx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.tx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.tx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_a.tx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.tx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_a.tx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.crc_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.io_error_count, expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.rx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.rx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_b.rx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.rx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_b.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.tx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.tx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.tx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_b.tx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.tx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_b.tx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count, expected "
           "0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.io_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level, expected "
           "0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput * 100 -
               0.0 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput, expected "
           "0.0, is "
        << last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level, 10)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level, expected "
           "10, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput * 100 -
               0.138999998569 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput, expected "
           "0.138999998569, is "
        << last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput;
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

    sbp_callback_register(&sbp_state, SbpMsgUartStateDepa, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 24, 0, 195, 4,   58,  0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   2,   43,  135, 61,  0, 0, 0, 0,
        0,  0,  0, 0,   0,   0,   255, 255, 255, 255, 0, 0, 0, 0,
        0,  0,  0, 0,   255, 255, 255, 255, 65,  110,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.uart_state_depa.latency.avg = -1;

    test_msg.uart_state_depa.latency.current = -1;

    test_msg.uart_state_depa.latency.lmax = 0;

    test_msg.uart_state_depa.latency.lmin = 0;

    test_msg.uart_state_depa.uart_a.crc_error_count = 0;

    test_msg.uart_state_depa.uart_a.io_error_count = 0;

    test_msg.uart_state_depa.uart_a.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_a.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_a.tx_buffer_level = 0;

    test_msg.uart_state_depa.uart_a.tx_throughput = 0.0;

    test_msg.uart_state_depa.uart_b.crc_error_count = 0;

    test_msg.uart_state_depa.uart_b.io_error_count = 0;

    test_msg.uart_state_depa.uart_b.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_b.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_b.tx_buffer_level = 0;

    test_msg.uart_state_depa.uart_b.tx_throughput = 0.0;

    test_msg.uart_state_depa.uart_ftdi.crc_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.io_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_ftdi.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_ftdi.tx_buffer_level = 0;

    test_msg.uart_state_depa.uart_ftdi.tx_throughput = 0.06599999964237213;

    sbp_message_send(&sbp_state, SbpMsgUartStateDepa, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgUartStateDepa, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.avg, -1)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.avg, "
           "expected -1, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.avg;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.current, -1)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.current, "
           "expected -1, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.current;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.lmax, 0)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.lmax, "
           "expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.lmax;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.lmin, 0)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.lmin, "
           "expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.lmin;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.crc_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.io_error_count, expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.rx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.rx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_a.rx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.rx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_a.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.tx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.tx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.tx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_a.tx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.tx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_a.tx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.crc_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.io_error_count, expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.rx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.rx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_b.rx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.rx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_b.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.tx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.tx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.tx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_b.tx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.tx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_b.tx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count, expected "
           "0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.io_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level, expected "
           "0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput * 100 -
               0.0 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput, expected "
           "0.0, is "
        << last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level, expected "
           "0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput * 100 -
               0.0659999996424 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput, expected "
           "0.0659999996424, is "
        << last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput;
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

    sbp_callback_register(&sbp_state, SbpMsgUartStateDepa, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 24, 0, 195, 4,   58,  0,   0,   0,   0,   138, 75, 6, 60,
        0,  0,  0, 0,   0,   0,   80,  113, 201, 61,  0,   0,  0, 0,
        0,  0,  0, 0,   2,   0,   145, 237, 252, 62,  0,   0,  0, 0,
        0,  0,  0, 0,   38,  0,   255, 255, 255, 255, 0,   0,  0, 0,
        0,  0,  0, 0,   255, 255, 255, 255, 112, 111,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.uart_state_depa.latency.avg = -1;

    test_msg.uart_state_depa.latency.current = -1;

    test_msg.uart_state_depa.latency.lmax = 0;

    test_msg.uart_state_depa.latency.lmin = 0;

    test_msg.uart_state_depa.uart_a.crc_error_count = 0;

    test_msg.uart_state_depa.uart_a.io_error_count = 0;

    test_msg.uart_state_depa.uart_a.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_a.rx_throughput = 0.008196720853447914;

    test_msg.uart_state_depa.uart_a.tx_buffer_level = 0;

    test_msg.uart_state_depa.uart_a.tx_throughput = 0.0;

    test_msg.uart_state_depa.uart_b.crc_error_count = 0;

    test_msg.uart_state_depa.uart_b.io_error_count = 0;

    test_msg.uart_state_depa.uart_b.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_b.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_b.tx_buffer_level = 2;

    test_msg.uart_state_depa.uart_b.tx_throughput = 0.09836065769195557;

    test_msg.uart_state_depa.uart_ftdi.crc_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.io_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_ftdi.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_ftdi.tx_buffer_level = 38;

    test_msg.uart_state_depa.uart_ftdi.tx_throughput = 0.49399998784065247;

    sbp_message_send(&sbp_state, SbpMsgUartStateDepa, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgUartStateDepa, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.avg, -1)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.avg, "
           "expected -1, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.avg;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.current, -1)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.current, "
           "expected -1, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.current;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.lmax, 0)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.lmax, "
           "expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.lmax;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.lmin, 0)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.lmin, "
           "expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.lmin;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.crc_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.io_error_count, expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.rx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.rx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_a.rx_throughput * 100 -
               0.00819672085345 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.rx_throughput, expected "
           "0.00819672085345, is "
        << last_msg.msg.uart_state_depa.uart_a.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.tx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.tx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.tx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_a.tx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.tx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_a.tx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.crc_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.io_error_count, expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.rx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.rx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_b.rx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.rx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_b.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.tx_buffer_level, 2)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.tx_buffer_level, expected 2, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.tx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_b.tx_throughput * 100 -
               0.098360657692 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.tx_throughput, expected "
           "0.098360657692, is "
        << last_msg.msg.uart_state_depa.uart_b.tx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count, expected "
           "0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.io_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level, expected "
           "0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput * 100 -
               0.0 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput, expected "
           "0.0, is "
        << last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level, 38)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level, expected "
           "38, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput * 100 -
               0.493999987841 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput, expected "
           "0.493999987841, is "
        << last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput;
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

    sbp_callback_register(&sbp_state, SbpMsgUartStateDepa, &logging_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85, 24, 0, 195, 4,   58,  166, 155, 68,  60,  0, 0, 0, 0,
        0,  0,  0, 0,   2,   0,   166, 155, 68,  60,  0, 0, 0, 0,
        0,  0,  0, 0,   2,   0,   236, 81,  168, 63,  0, 0, 0, 0,
        0,  0,  0, 0,   50,  0,   255, 255, 255, 255, 0, 0, 0, 0,
        0,  0,  0, 0,   255, 255, 255, 255, 22,  72,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.uart_state_depa.latency.avg = -1;

    test_msg.uart_state_depa.latency.current = -1;

    test_msg.uart_state_depa.latency.lmax = 0;

    test_msg.uart_state_depa.latency.lmin = 0;

    test_msg.uart_state_depa.uart_a.crc_error_count = 0;

    test_msg.uart_state_depa.uart_a.io_error_count = 0;

    test_msg.uart_state_depa.uart_a.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_a.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_a.tx_buffer_level = 2;

    test_msg.uart_state_depa.uart_a.tx_throughput = 0.012000000104308128;

    test_msg.uart_state_depa.uart_b.crc_error_count = 0;

    test_msg.uart_state_depa.uart_b.io_error_count = 0;

    test_msg.uart_state_depa.uart_b.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_b.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_b.tx_buffer_level = 2;

    test_msg.uart_state_depa.uart_b.tx_throughput = 0.012000000104308128;

    test_msg.uart_state_depa.uart_ftdi.crc_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.io_error_count = 0;

    test_msg.uart_state_depa.uart_ftdi.rx_buffer_level = 0;

    test_msg.uart_state_depa.uart_ftdi.rx_throughput = 0.0;

    test_msg.uart_state_depa.uart_ftdi.tx_buffer_level = 50;

    test_msg.uart_state_depa.uart_ftdi.tx_throughput = 1.315000057220459;

    sbp_message_send(&sbp_state, SbpMsgUartStateDepa, 1219, &test_msg,
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
    EXPECT_EQ(last_msg.sender_id, 1219)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgUartStateDepa, &last_msg.msg, &test_msg), 0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.avg, -1)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.avg, "
           "expected -1, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.avg;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.current, -1)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.current, "
           "expected -1, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.current;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.lmax, 0)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.lmax, "
           "expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.lmax;

    EXPECT_EQ(last_msg.msg.uart_state_depa.latency.lmin, 0)
        << "incorrect value for last_msg.msg.uart_state_depa.latency.lmin, "
           "expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.latency.lmin;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.crc_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.io_error_count, expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.rx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.rx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_a.rx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.rx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_a.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_a.tx_buffer_level, 2)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.tx_buffer_level, expected 2, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_a.tx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_a.tx_throughput * 100 -
               0.0120000001043 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_a.tx_throughput, expected "
           "0.0120000001043, is "
        << last_msg.msg.uart_state_depa.uart_a.tx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.crc_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.io_error_count, expected 0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.rx_buffer_level, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.rx_buffer_level;

    EXPECT_LE(
        (last_msg.msg.uart_state_depa.uart_b.rx_throughput * 100 - 0.0 * 100),
        0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.rx_throughput, expected 0.0, "
           "is "
        << last_msg.msg.uart_state_depa.uart_b.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_b.tx_buffer_level, 2)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.tx_buffer_level, expected 2, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_b.tx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_b.tx_throughput * 100 -
               0.0120000001043 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_b.tx_throughput, expected "
           "0.0120000001043, is "
        << last_msg.msg.uart_state_depa.uart_b.tx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count, expected "
           "0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.crc_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.io_error_count, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.io_error_count, expected 0, "
           "is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.io_error_count;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level, 0)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level, expected "
           "0, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.rx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput * 100 -
               0.0 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput, expected "
           "0.0, is "
        << last_msg.msg.uart_state_depa.uart_ftdi.rx_throughput;

    EXPECT_EQ(last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level, 50)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level, expected "
           "50, is "
        << (int64_t)last_msg.msg.uart_state_depa.uart_ftdi.tx_buffer_level;

    EXPECT_LE((last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput * 100 -
               1.31500005722 * 100),
              0.05)
        << "incorrect value for "
           "last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput, expected "
           "1.31500005722, is "
        << last_msg.msg.uart_state_depa.uart_ftdi.tx_throughput;
  }
}

}  // namespace
