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
// spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingResourceCounter.yaml
// by generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/profiling.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc
#include "test_utils.h"

using namespace utils;
using namespace utils::io;
using namespace utils::logging;

namespace {

TEST(auto_check_sbp_profiling_MsgProfilingResourceCounter,
     test_auto_check_sbp_profiling_MsgProfilingResourceCounter) {
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

    sbp_callback_register(&sbp_state, SbpMsgProfilingResourceCounter,
                          &logging_callback, &DUMMY_MEMORY_FOR_CALLBACKS, &n);

    u8 encoded_frame[] = {
        85,  3,   207, 0,   16,  248, 1,   3,   70,  117, 115, 105, 111, 110,
        32,  101, 110, 103, 105, 110, 101, 0,   0,   0,   0,   0,   0,   0,
        0,   1,   2,   2,   0,   248, 38,  14,  0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   78,  84,  82,  73,  80,  32,  99,
        108, 105, 101, 110, 116, 0,   0,   0,   0,   0,   0,   0,   0,   0,
        1,   1,   1,   1,   230, 73,  1,   0,   0,   0,   0,   0,   111, 3,
        0,   0,   64,  76,  0,   0,   83,  83,  82,  50,  79,  83,  82,  0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,
        1,   1,   0,   72,  13,  66,  0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   80,  101, 114, 105, 111, 100, 105, 99,  0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   2,
        1,   0,   72,  197, 3,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   73,  77,  85,  0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   1,
        1,   129, 71,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   95,
        102, 0,   0,   115, 98,  112, 0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   5,   2,   2,   2,
        243, 169, 0,   0,   0,   0,   0,   0,   187, 151, 3,   0,   242, 1,
        0,   0,   181, 153,
    };

    dummy_reset();

    sbp_msg_t test_msg;
    memset(&test_msg, 0, sizeof(test_msg));

    test_msg.profiling_resource_counter.buckets[0].cv = 2;

    test_msg.profiling_resource_counter.buckets[0].heap_bytes_alloc = 927480;

    test_msg.profiling_resource_counter.buckets[0].heap_bytes_free = 0;

    test_msg.profiling_resource_counter.buckets[0].io = 0;

    test_msg.profiling_resource_counter.buckets[0].io_read = 0;

    test_msg.profiling_resource_counter.buckets[0].io_write = 0;

    test_msg.profiling_resource_counter.buckets[0].mutex = 2;

    {
      const char assign_string[] = {
          (char)70,  (char)117, (char)115, (char)105, (char)111, (char)110,
          (char)32,  (char)101, (char)110, (char)103, (char)105, (char)110,
          (char)101, (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0};
      memcpy(test_msg.profiling_resource_counter.buckets[0].name, assign_string,
             sizeof(assign_string));
    }

    test_msg.profiling_resource_counter.buckets[0].thread = 1;

    test_msg.profiling_resource_counter.buckets[1].cv = 1;

    test_msg.profiling_resource_counter.buckets[1].heap_bytes_alloc = 84454;

    test_msg.profiling_resource_counter.buckets[1].heap_bytes_free = 0;

    test_msg.profiling_resource_counter.buckets[1].io = 1;

    test_msg.profiling_resource_counter.buckets[1].io_read = 19520;

    test_msg.profiling_resource_counter.buckets[1].io_write = 879;

    test_msg.profiling_resource_counter.buckets[1].mutex = 1;

    {
      const char assign_string[] = {
          (char)78, (char)84,  (char)82,  (char)73,  (char)80,  (char)32,
          (char)99, (char)108, (char)105, (char)101, (char)110, (char)116,
          (char)0,  (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,  (char)0,   (char)0};
      memcpy(test_msg.profiling_resource_counter.buckets[1].name, assign_string,
             sizeof(assign_string));
    }

    test_msg.profiling_resource_counter.buckets[1].thread = 1;

    test_msg.profiling_resource_counter.buckets[2].cv = 1;

    test_msg.profiling_resource_counter.buckets[2].heap_bytes_alloc = 4328776;

    test_msg.profiling_resource_counter.buckets[2].heap_bytes_free = 0;

    test_msg.profiling_resource_counter.buckets[2].io = 0;

    test_msg.profiling_resource_counter.buckets[2].io_read = 0;

    test_msg.profiling_resource_counter.buckets[2].io_write = 0;

    test_msg.profiling_resource_counter.buckets[2].mutex = 1;

    {
      const char assign_string[] = {
          (char)83, (char)83, (char)82, (char)50, (char)79, (char)83, (char)82,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
      memcpy(test_msg.profiling_resource_counter.buckets[2].name, assign_string,
             sizeof(assign_string));
    }

    test_msg.profiling_resource_counter.buckets[2].thread = 1;

    test_msg.profiling_resource_counter.buckets[3].cv = 1;

    test_msg.profiling_resource_counter.buckets[3].heap_bytes_alloc = 247112;

    test_msg.profiling_resource_counter.buckets[3].heap_bytes_free = 0;

    test_msg.profiling_resource_counter.buckets[3].io = 0;

    test_msg.profiling_resource_counter.buckets[3].io_read = 0;

    test_msg.profiling_resource_counter.buckets[3].io_write = 0;

    test_msg.profiling_resource_counter.buckets[3].mutex = 2;

    {
      const char assign_string[] = {
          (char)80,  (char)101, (char)114, (char)105, (char)111, (char)100,
          (char)105, (char)99,  (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0};
      memcpy(test_msg.profiling_resource_counter.buckets[3].name, assign_string,
             sizeof(assign_string));
    }

    test_msg.profiling_resource_counter.buckets[3].thread = 1;

    test_msg.profiling_resource_counter.buckets[4].cv = 1;

    test_msg.profiling_resource_counter.buckets[4].heap_bytes_alloc = 18305;

    test_msg.profiling_resource_counter.buckets[4].heap_bytes_free = 0;

    test_msg.profiling_resource_counter.buckets[4].io = 1;

    test_msg.profiling_resource_counter.buckets[4].io_read = 26207;

    test_msg.profiling_resource_counter.buckets[4].io_write = 0;

    test_msg.profiling_resource_counter.buckets[4].mutex = 1;

    {
      const char assign_string[] = {
          (char)73, (char)77, (char)85, (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0};
      memcpy(test_msg.profiling_resource_counter.buckets[4].name, assign_string,
             sizeof(assign_string));
    }

    test_msg.profiling_resource_counter.buckets[4].thread = 1;

    test_msg.profiling_resource_counter.buckets[5].cv = 2;

    test_msg.profiling_resource_counter.buckets[5].heap_bytes_alloc = 43507;

    test_msg.profiling_resource_counter.buckets[5].heap_bytes_free = 0;

    test_msg.profiling_resource_counter.buckets[5].io = 2;

    test_msg.profiling_resource_counter.buckets[5].io_read = 498;

    test_msg.profiling_resource_counter.buckets[5].io_write = 235451;

    test_msg.profiling_resource_counter.buckets[5].mutex = 2;

    {
      const char assign_string[] = {
          (char)115, (char)98, (char)112, (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0};
      memcpy(test_msg.profiling_resource_counter.buckets[5].name, assign_string,
             sizeof(assign_string));
    }

    test_msg.profiling_resource_counter.buckets[5].thread = 5;

    test_msg.profiling_resource_counter.n_buckets = 6;

    test_msg.profiling_resource_counter.seq_len = 3;

    test_msg.profiling_resource_counter.seq_no = 1;

    sbp_message_send(&sbp_state, SbpMsgProfilingResourceCounter, 4096,
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
    EXPECT_EQ(last_msg.sender_id, 4096)
        << "msg_callback: sender_id decoded incorrectly";

    EXPECT_EQ(sbp_message_cmp(SbpMsgProfilingResourceCounter, &last_msg.msg,
                              &test_msg),
              0)
        << "Sent and received messages did not compare equal";

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[0].cv, 2)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[0].cv, expected 2, "
           "is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[0].cv;

    EXPECT_EQ(
        last_msg.msg.profiling_resource_counter.buckets[0].heap_bytes_alloc,
        927480)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[0].heap_bytes_"
           "alloc, expected 927480, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[0]
               .heap_bytes_alloc;

    EXPECT_EQ(
        last_msg.msg.profiling_resource_counter.buckets[0].heap_bytes_free, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[0].heap_bytes_free,"
           " expected 0, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[0]
               .heap_bytes_free;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[0].io, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[0].io, expected 0, "
           "is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[0].io;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[0].io_read, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[0].io_read, "
           "expected 0, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[0].io_read;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[0].io_write, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[0].io_write, "
           "expected 0, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[0].io_write;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[0].mutex, 2)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[0].mutex, expected "
           "2, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[0].mutex;

    {
      const char check_string[] = {
          (char)70,  (char)117, (char)115, (char)105, (char)111, (char)110,
          (char)32,  (char)101, (char)110, (char)103, (char)105, (char)110,
          (char)101, (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0};
      EXPECT_EQ(memcmp(&last_msg.msg.profiling_resource_counter.buckets[0].name,
                       check_string, sizeof(check_string)),
                0)
          << "incorrect value for "
             "last_msg.msg.profiling_resource_counter.buckets[0].name, "
             "expected string '"
          << check_string << "', is '"
          << last_msg.msg.profiling_resource_counter.buckets[0].name << "'";
    }

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[0].thread, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[0].thread, "
           "expected 1, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[0].thread;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[1].cv, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[1].cv, expected 1, "
           "is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[1].cv;

    EXPECT_EQ(
        last_msg.msg.profiling_resource_counter.buckets[1].heap_bytes_alloc,
        84454)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[1].heap_bytes_"
           "alloc, expected 84454, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[1]
               .heap_bytes_alloc;

    EXPECT_EQ(
        last_msg.msg.profiling_resource_counter.buckets[1].heap_bytes_free, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[1].heap_bytes_free,"
           " expected 0, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[1]
               .heap_bytes_free;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[1].io, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[1].io, expected 1, "
           "is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[1].io;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[1].io_read, 19520)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[1].io_read, "
           "expected 19520, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[1].io_read;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[1].io_write, 879)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[1].io_write, "
           "expected 879, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[1].io_write;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[1].mutex, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[1].mutex, expected "
           "1, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[1].mutex;

    {
      const char check_string[] = {
          (char)78, (char)84,  (char)82,  (char)73,  (char)80,  (char)32,
          (char)99, (char)108, (char)105, (char)101, (char)110, (char)116,
          (char)0,  (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,  (char)0,   (char)0};
      EXPECT_EQ(memcmp(&last_msg.msg.profiling_resource_counter.buckets[1].name,
                       check_string, sizeof(check_string)),
                0)
          << "incorrect value for "
             "last_msg.msg.profiling_resource_counter.buckets[1].name, "
             "expected string '"
          << check_string << "', is '"
          << last_msg.msg.profiling_resource_counter.buckets[1].name << "'";
    }

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[1].thread, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[1].thread, "
           "expected 1, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[1].thread;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[2].cv, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[2].cv, expected 1, "
           "is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[2].cv;

    EXPECT_EQ(
        last_msg.msg.profiling_resource_counter.buckets[2].heap_bytes_alloc,
        4328776)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[2].heap_bytes_"
           "alloc, expected 4328776, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[2]
               .heap_bytes_alloc;

    EXPECT_EQ(
        last_msg.msg.profiling_resource_counter.buckets[2].heap_bytes_free, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[2].heap_bytes_free,"
           " expected 0, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[2]
               .heap_bytes_free;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[2].io, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[2].io, expected 0, "
           "is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[2].io;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[2].io_read, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[2].io_read, "
           "expected 0, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[2].io_read;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[2].io_write, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[2].io_write, "
           "expected 0, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[2].io_write;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[2].mutex, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[2].mutex, expected "
           "1, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[2].mutex;

    {
      const char check_string[] = {
          (char)83, (char)83, (char)82, (char)50, (char)79, (char)83, (char)82,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
      EXPECT_EQ(memcmp(&last_msg.msg.profiling_resource_counter.buckets[2].name,
                       check_string, sizeof(check_string)),
                0)
          << "incorrect value for "
             "last_msg.msg.profiling_resource_counter.buckets[2].name, "
             "expected string '"
          << check_string << "', is '"
          << last_msg.msg.profiling_resource_counter.buckets[2].name << "'";
    }

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[2].thread, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[2].thread, "
           "expected 1, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[2].thread;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[3].cv, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[3].cv, expected 1, "
           "is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[3].cv;

    EXPECT_EQ(
        last_msg.msg.profiling_resource_counter.buckets[3].heap_bytes_alloc,
        247112)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[3].heap_bytes_"
           "alloc, expected 247112, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[3]
               .heap_bytes_alloc;

    EXPECT_EQ(
        last_msg.msg.profiling_resource_counter.buckets[3].heap_bytes_free, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[3].heap_bytes_free,"
           " expected 0, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[3]
               .heap_bytes_free;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[3].io, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[3].io, expected 0, "
           "is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[3].io;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[3].io_read, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[3].io_read, "
           "expected 0, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[3].io_read;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[3].io_write, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[3].io_write, "
           "expected 0, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[3].io_write;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[3].mutex, 2)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[3].mutex, expected "
           "2, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[3].mutex;

    {
      const char check_string[] = {
          (char)80,  (char)101, (char)114, (char)105, (char)111, (char)100,
          (char)105, (char)99,  (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0};
      EXPECT_EQ(memcmp(&last_msg.msg.profiling_resource_counter.buckets[3].name,
                       check_string, sizeof(check_string)),
                0)
          << "incorrect value for "
             "last_msg.msg.profiling_resource_counter.buckets[3].name, "
             "expected string '"
          << check_string << "', is '"
          << last_msg.msg.profiling_resource_counter.buckets[3].name << "'";
    }

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[3].thread, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[3].thread, "
           "expected 1, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[3].thread;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[4].cv, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[4].cv, expected 1, "
           "is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[4].cv;

    EXPECT_EQ(
        last_msg.msg.profiling_resource_counter.buckets[4].heap_bytes_alloc,
        18305)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[4].heap_bytes_"
           "alloc, expected 18305, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[4]
               .heap_bytes_alloc;

    EXPECT_EQ(
        last_msg.msg.profiling_resource_counter.buckets[4].heap_bytes_free, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[4].heap_bytes_free,"
           " expected 0, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[4]
               .heap_bytes_free;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[4].io, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[4].io, expected 1, "
           "is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[4].io;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[4].io_read, 26207)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[4].io_read, "
           "expected 26207, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[4].io_read;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[4].io_write, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[4].io_write, "
           "expected 0, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[4].io_write;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[4].mutex, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[4].mutex, expected "
           "1, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[4].mutex;

    {
      const char check_string[] = {
          (char)73, (char)77, (char)85, (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0};
      EXPECT_EQ(memcmp(&last_msg.msg.profiling_resource_counter.buckets[4].name,
                       check_string, sizeof(check_string)),
                0)
          << "incorrect value for "
             "last_msg.msg.profiling_resource_counter.buckets[4].name, "
             "expected string '"
          << check_string << "', is '"
          << last_msg.msg.profiling_resource_counter.buckets[4].name << "'";
    }

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[4].thread, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[4].thread, "
           "expected 1, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[4].thread;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[5].cv, 2)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[5].cv, expected 2, "
           "is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[5].cv;

    EXPECT_EQ(
        last_msg.msg.profiling_resource_counter.buckets[5].heap_bytes_alloc,
        43507)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[5].heap_bytes_"
           "alloc, expected 43507, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[5]
               .heap_bytes_alloc;

    EXPECT_EQ(
        last_msg.msg.profiling_resource_counter.buckets[5].heap_bytes_free, 0)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[5].heap_bytes_free,"
           " expected 0, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[5]
               .heap_bytes_free;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[5].io, 2)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[5].io, expected 2, "
           "is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[5].io;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[5].io_read, 498)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[5].io_read, "
           "expected 498, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[5].io_read;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[5].io_write,
              235451)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[5].io_write, "
           "expected 235451, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[5].io_write;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[5].mutex, 2)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[5].mutex, expected "
           "2, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[5].mutex;

    {
      const char check_string[] = {
          (char)115, (char)98, (char)112, (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0};
      EXPECT_EQ(memcmp(&last_msg.msg.profiling_resource_counter.buckets[5].name,
                       check_string, sizeof(check_string)),
                0)
          << "incorrect value for "
             "last_msg.msg.profiling_resource_counter.buckets[5].name, "
             "expected string '"
          << check_string << "', is '"
          << last_msg.msg.profiling_resource_counter.buckets[5].name << "'";
    }

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.buckets[5].thread, 5)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.buckets[5].thread, "
           "expected 5, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.buckets[5].thread;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.n_buckets, 6)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.n_buckets, expected 6, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.n_buckets;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.seq_len, 3)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.seq_len, expected 3, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.seq_len;

    EXPECT_EQ(last_msg.msg.profiling_resource_counter.seq_no, 1)
        << "incorrect value for "
           "last_msg.msg.profiling_resource_counter.seq_no, expected 1, is "
        << (int64_t)last_msg.msg.profiling_resource_counter.seq_no;
  }
}

}  // namespace
