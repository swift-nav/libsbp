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
#include <libsbp/base.h>
#include <libsbp/cpp/base.h>


TEST(test_sbp, default_construction) {
  sbp::Sbp variable;
  (void) variable;
}

TEST(test_sbp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::Sbp);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const sbp_t *c_struct = reinterpret_cast<const sbp_t*>(buffer);
  const sbp::Sbp *cpp_struct = reinterpret_cast<const sbp::Sbp*>(buffer);

//
//  EXPECT_EQ(c_struct->preamble, cpp_struct->preamble);
//
//  EXPECT_EQ(c_struct->msg_type, cpp_struct->msg_type);
//
//  EXPECT_EQ(c_struct->sender, cpp_struct->sender);
//
//  EXPECT_EQ(c_struct->length, cpp_struct->length);
//
//  EXPECT_EQ(c_struct->payload, cpp_struct->payload);
//
//  EXPECT_EQ(c_struct->crc, cpp_struct->crc);
//
}
