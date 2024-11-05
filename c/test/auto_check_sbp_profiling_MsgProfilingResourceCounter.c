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

#include <check.h>
#include <libsbp/profiling.h>
#include <libsbp/sbp.h>
#include <stdio.h>   // for debugging
#include <stdlib.h>  // for malloc

static struct {
  u32 n_callbacks_logged;
  u16 sender_id;
  sbp_msg_type_t msg_type;
  sbp_msg_t msg;
  void *context;
} last_msg;

static size_t dummy_wr = 0;
static size_t dummy_rd = 0;
static u8 dummy_buff[1024];
static void *last_io_context;

static void *DUMMY_MEMORY_FOR_CALLBACKS = (void *)0xdeadbeef;
static void *DUMMY_MEMORY_FOR_IO = (void *)0xdead0000;

static void dummy_reset() {
  dummy_rd = dummy_wr = 0;
  memset(dummy_buff, 0, sizeof(dummy_buff));
}

static s32 dummy_write(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(dummy_buff + dummy_wr, buff, real_n);
  dummy_wr += real_n;
  return (s32)real_n;
}

static s32 dummy_read(u8 *buff, u32 n, void *context) {
  last_io_context = context;
  size_t real_n = n;  //(dummy_n > n) ? n : dummy_n;
  memcpy(buff, dummy_buff + dummy_rd, real_n);
  dummy_rd += real_n;
  return (s32)real_n;
}

static void logging_reset() { memset(&last_msg, 0, sizeof(last_msg)); }

static void msg_callback(u16 sender_id, sbp_msg_type_t msg_type,
                         const sbp_msg_t *msg, void *context) {
  last_msg.n_callbacks_logged++;
  last_msg.sender_id = sender_id;
  last_msg.msg_type = msg_type;
  last_msg.msg = *msg;
  last_msg.context = context;
}

START_TEST(test_auto_check_sbp_profiling_MsgProfilingResourceCounter) {
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

    sbp_callback_register(&sbp_state, 0xcf03, &msg_callback,
                          &DUMMY_MEMORY_FOR_CALLBACKS, &n);

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

    ck_assert_msg(dummy_wr == sizeof(encoded_frame),
                  "not enough data was written to dummy_buff (expected: %zu, "
                  "actual: %zu)",
                  sizeof(encoded_frame), dummy_wr);
    ck_assert_msg(memcmp(dummy_buff, encoded_frame, sizeof(encoded_frame)) == 0,
                  "frame was not encoded properly");

    while (dummy_rd < dummy_wr) {
      ck_assert_msg(sbp_process(&sbp_state, &dummy_read) >= SBP_OK,
                    "sbp_process threw an error!");
    }

    ck_assert_msg(last_msg.n_callbacks_logged == 1,
                  "msg_callback: one callback should have been logged");
    ck_assert_msg(last_msg.sender_id == 4096,
                  "msg_callback: sender_id decoded incorrectly");

    ck_assert_msg(sbp_message_cmp(SbpMsgProfilingResourceCounter, &last_msg.msg,
                                  &test_msg) == 0,
                  "Sent and received messages did not compare equal");

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[0].cv == 2,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[0].cv, expected 2, is "
        "%" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[0].cv);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[0].heap_bytes_alloc ==
            927480,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[0].heap_bytes_alloc, "
        "expected 927480, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[0]
            .heap_bytes_alloc);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[0].heap_bytes_free == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[0].heap_bytes_free, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[0]
            .heap_bytes_free);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[0].io == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[0].io, expected 0, is "
        "%" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[0].io);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[0].io_read == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[0].io_read, expected "
        "0, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[0].io_read);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[0].io_write == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[0].io_write, expected "
        "0, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[0].io_write);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[0].mutex == 2,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[0].mutex, expected 2, "
        "is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[0].mutex);

    {
      const char check_string[] = {
          (char)70,  (char)117, (char)115, (char)105, (char)111, (char)110,
          (char)32,  (char)101, (char)110, (char)103, (char)105, (char)110,
          (char)101, (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0};
      ck_assert_msg(
          memcmp(&last_msg.msg.profiling_resource_counter.buckets[0].name,
                 check_string, sizeof(check_string)) == 0,
          "incorrect value for "
          "last_msg.msg.profiling_resource_counter.buckets[0].name, expected "
          "string '%s', is '%s'",
          check_string,
          last_msg.msg.profiling_resource_counter.buckets[0].name);
    }

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[0].thread == 1,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[0].thread, expected "
        "1, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[0].thread);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[1].cv == 1,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[1].cv, expected 1, is "
        "%" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[1].cv);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[1].heap_bytes_alloc ==
            84454,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[1].heap_bytes_alloc, "
        "expected 84454, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[1]
            .heap_bytes_alloc);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[1].heap_bytes_free == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[1].heap_bytes_free, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[1]
            .heap_bytes_free);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[1].io == 1,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[1].io, expected 1, is "
        "%" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[1].io);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[1].io_read == 19520,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[1].io_read, expected "
        "19520, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[1].io_read);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[1].io_write == 879,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[1].io_write, expected "
        "879, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[1].io_write);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[1].mutex == 1,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[1].mutex, expected 1, "
        "is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[1].mutex);

    {
      const char check_string[] = {
          (char)78, (char)84,  (char)82,  (char)73,  (char)80,  (char)32,
          (char)99, (char)108, (char)105, (char)101, (char)110, (char)116,
          (char)0,  (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,  (char)0,   (char)0};
      ck_assert_msg(
          memcmp(&last_msg.msg.profiling_resource_counter.buckets[1].name,
                 check_string, sizeof(check_string)) == 0,
          "incorrect value for "
          "last_msg.msg.profiling_resource_counter.buckets[1].name, expected "
          "string '%s', is '%s'",
          check_string,
          last_msg.msg.profiling_resource_counter.buckets[1].name);
    }

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[1].thread == 1,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[1].thread, expected "
        "1, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[1].thread);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[2].cv == 1,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[2].cv, expected 1, is "
        "%" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[2].cv);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[2].heap_bytes_alloc ==
            4328776,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[2].heap_bytes_alloc, "
        "expected 4328776, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[2]
            .heap_bytes_alloc);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[2].heap_bytes_free == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[2].heap_bytes_free, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[2]
            .heap_bytes_free);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[2].io == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[2].io, expected 0, is "
        "%" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[2].io);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[2].io_read == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[2].io_read, expected "
        "0, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[2].io_read);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[2].io_write == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[2].io_write, expected "
        "0, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[2].io_write);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[2].mutex == 1,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[2].mutex, expected 1, "
        "is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[2].mutex);

    {
      const char check_string[] = {
          (char)83, (char)83, (char)82, (char)50, (char)79, (char)83, (char)82,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
      ck_assert_msg(
          memcmp(&last_msg.msg.profiling_resource_counter.buckets[2].name,
                 check_string, sizeof(check_string)) == 0,
          "incorrect value for "
          "last_msg.msg.profiling_resource_counter.buckets[2].name, expected "
          "string '%s', is '%s'",
          check_string,
          last_msg.msg.profiling_resource_counter.buckets[2].name);
    }

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[2].thread == 1,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[2].thread, expected "
        "1, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[2].thread);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[3].cv == 1,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[3].cv, expected 1, is "
        "%" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[3].cv);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[3].heap_bytes_alloc ==
            247112,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[3].heap_bytes_alloc, "
        "expected 247112, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[3]
            .heap_bytes_alloc);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[3].heap_bytes_free == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[3].heap_bytes_free, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[3]
            .heap_bytes_free);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[3].io == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[3].io, expected 0, is "
        "%" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[3].io);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[3].io_read == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[3].io_read, expected "
        "0, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[3].io_read);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[3].io_write == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[3].io_write, expected "
        "0, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[3].io_write);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[3].mutex == 2,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[3].mutex, expected 2, "
        "is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[3].mutex);

    {
      const char check_string[] = {
          (char)80,  (char)101, (char)114, (char)105, (char)111, (char)100,
          (char)105, (char)99,  (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0};
      ck_assert_msg(
          memcmp(&last_msg.msg.profiling_resource_counter.buckets[3].name,
                 check_string, sizeof(check_string)) == 0,
          "incorrect value for "
          "last_msg.msg.profiling_resource_counter.buckets[3].name, expected "
          "string '%s', is '%s'",
          check_string,
          last_msg.msg.profiling_resource_counter.buckets[3].name);
    }

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[3].thread == 1,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[3].thread, expected "
        "1, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[3].thread);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[4].cv == 1,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[4].cv, expected 1, is "
        "%" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[4].cv);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[4].heap_bytes_alloc ==
            18305,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[4].heap_bytes_alloc, "
        "expected 18305, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[4]
            .heap_bytes_alloc);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[4].heap_bytes_free == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[4].heap_bytes_free, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[4]
            .heap_bytes_free);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[4].io == 1,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[4].io, expected 1, is "
        "%" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[4].io);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[4].io_read == 26207,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[4].io_read, expected "
        "26207, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[4].io_read);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[4].io_write == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[4].io_write, expected "
        "0, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[4].io_write);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[4].mutex == 1,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[4].mutex, expected 1, "
        "is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[4].mutex);

    {
      const char check_string[] = {
          (char)73, (char)77, (char)85, (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0};
      ck_assert_msg(
          memcmp(&last_msg.msg.profiling_resource_counter.buckets[4].name,
                 check_string, sizeof(check_string)) == 0,
          "incorrect value for "
          "last_msg.msg.profiling_resource_counter.buckets[4].name, expected "
          "string '%s', is '%s'",
          check_string,
          last_msg.msg.profiling_resource_counter.buckets[4].name);
    }

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[4].thread == 1,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[4].thread, expected "
        "1, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[4].thread);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[5].cv == 2,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[5].cv, expected 2, is "
        "%" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[5].cv);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[5].heap_bytes_alloc ==
            43507,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[5].heap_bytes_alloc, "
        "expected 43507, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[5]
            .heap_bytes_alloc);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[5].heap_bytes_free == 0,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[5].heap_bytes_free, "
        "expected 0, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[5]
            .heap_bytes_free);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[5].io == 2,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[5].io, expected 2, is "
        "%" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[5].io);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[5].io_read == 498,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[5].io_read, expected "
        "498, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[5].io_read);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[5].io_write == 235451,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[5].io_write, expected "
        "235451, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[5].io_write);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[5].mutex == 2,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[5].mutex, expected 2, "
        "is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[5].mutex);

    {
      const char check_string[] = {
          (char)115, (char)98, (char)112, (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0};
      ck_assert_msg(
          memcmp(&last_msg.msg.profiling_resource_counter.buckets[5].name,
                 check_string, sizeof(check_string)) == 0,
          "incorrect value for "
          "last_msg.msg.profiling_resource_counter.buckets[5].name, expected "
          "string '%s', is '%s'",
          check_string,
          last_msg.msg.profiling_resource_counter.buckets[5].name);
    }

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.buckets[5].thread == 5,
        "incorrect value for "
        "last_msg.msg.profiling_resource_counter.buckets[5].thread, expected "
        "5, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.buckets[5].thread);

    ck_assert_msg(last_msg.msg.profiling_resource_counter.n_buckets == 6,
                  "incorrect value for "
                  "last_msg.msg.profiling_resource_counter.n_buckets, expected "
                  "6, is %" PRId64,
                  (int64_t)last_msg.msg.profiling_resource_counter.n_buckets);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.seq_len == 3,
        "incorrect value for last_msg.msg.profiling_resource_counter.seq_len, "
        "expected 3, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.seq_len);

    ck_assert_msg(
        last_msg.msg.profiling_resource_counter.seq_no == 1,
        "incorrect value for last_msg.msg.profiling_resource_counter.seq_no, "
        "expected 1, is %" PRId64,
        (int64_t)last_msg.msg.profiling_resource_counter.seq_no);
  }
}
END_TEST

Suite *auto_check_sbp_profiling_MsgProfilingResourceCounter_suite(void) {
  Suite *s = suite_create(
      "SBP generated test suite: "
      "auto_check_sbp_profiling_MsgProfilingResourceCounter");
  TCase *tc_acq = tcase_create(
      "Automated_Suite_auto_check_sbp_profiling_MsgProfilingResourceCounter");
  tcase_add_test(tc_acq,
                 test_auto_check_sbp_profiling_MsgProfilingResourceCounter);
  suite_add_tcase(s, tc_acq);
  return s;
}
