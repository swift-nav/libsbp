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
#include <libsbp/ext_events.h>
#include <libsbp/cpp/ext_events.h>


TEST(test_msg_ext_event, default_construction) {
  sbp::MsgExtEvent variable;
  (void) variable;
}

TEST(test_msg_ext_event, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgExtEvent);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ext_event_t *c_struct = reinterpret_cast<const msg_ext_event_t*>(buffer);
  const sbp::MsgExtEvent *cpp_struct = reinterpret_cast<const sbp::MsgExtEvent*>(buffer);

//
//  EXPECT_EQ(c_struct->wn, cpp_struct->wn);
//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->ns_residual, cpp_struct->ns_residual);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
//  EXPECT_EQ(c_struct->pin, cpp_struct->pin);
//
}
