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
#include <libsbp/sbas.h>
#include <libsbp/cpp/sbas.h>


TEST(test_msg_sbas_raw, default_construction) {
  sbp::MsgSbasRaw variable;
  (void) variable;
}

TEST(test_msg_sbas_raw, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSbasRaw);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_sbas_raw_t *c_struct = reinterpret_cast<const msg_sbas_raw_t*>(buffer);
  const sbp::MsgSbasRaw *cpp_struct = reinterpret_cast<const sbp::MsgSbasRaw*>(buffer);

//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->message_type, cpp_struct->message_type);
//
//  EXPECT_EQ(c_struct->data, cpp_struct->data);
//
}
