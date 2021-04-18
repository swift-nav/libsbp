/*
 * Copyright (C) 2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated. Do not modify by hand!

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <gtest/gtest.h>
#include <libsbp/logging.h>
#include <libsbp/cpp/logging.h>
#include <libsbp/logging.h>
#include <libsbp/cpp/logging.h>
#include <libsbp/logging.h>
#include <libsbp/cpp/logging.h>


TEST(test_msg_log, default_construction) {
  sbp::MsgLog<> variable;
  (void) variable;
}

TEST(test_msg_log, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgLog<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_log_t *c_struct = reinterpret_cast<const msg_log_t*>(buffer);
  const sbp::MsgLog<> *cpp_struct = reinterpret_cast<const sbp::MsgLog<>*>(buffer);

//
//  EXPECT_EQ(c_struct->level, cpp_struct->level);
//
//  EXPECT_EQ(c_struct->text, cpp_struct->text);
//
}

TEST(test_msg_fwd, default_construction) {
  sbp::MsgFwd<> variable;
  (void) variable;
}

TEST(test_msg_fwd, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFwd<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_fwd_t *c_struct = reinterpret_cast<const msg_fwd_t*>(buffer);
  const sbp::MsgFwd<> *cpp_struct = reinterpret_cast<const sbp::MsgFwd<>*>(buffer);

//
//  EXPECT_EQ(c_struct->source, cpp_struct->source);
//
//  EXPECT_EQ(c_struct->protocol, cpp_struct->protocol);
//
//  EXPECT_EQ(c_struct->fwd_payload, cpp_struct->fwd_payload);
//
}

TEST(test_msg_print_dep, default_construction) {
  sbp::MsgPrintDep<> variable;
  (void) variable;
}

TEST(test_msg_print_dep, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgPrintDep<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_print_dep_t *c_struct = reinterpret_cast<const msg_print_dep_t*>(buffer);
  const sbp::MsgPrintDep<> *cpp_struct = reinterpret_cast<const sbp::MsgPrintDep<>*>(buffer);

//
//  EXPECT_EQ(c_struct->text, cpp_struct->text);
//
}
