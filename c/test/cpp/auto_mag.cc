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
#include <libsbp/mag.h>
#include <libsbp/cpp/mag.h>


TEST(test_msg_mag_raw, default_construction) {
  sbp::MsgMagRaw variable;
  (void) variable;
}

TEST(test_msg_mag_raw, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgMagRaw);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_mag_raw_t *c_struct = reinterpret_cast<const msg_mag_raw_t*>(buffer);
  const sbp::MsgMagRaw *cpp_struct = reinterpret_cast<const sbp::MsgMagRaw*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->tow_f, cpp_struct->tow_f);
//
//  EXPECT_EQ(c_struct->mag_x, cpp_struct->mag_x);
//
//  EXPECT_EQ(c_struct->mag_y, cpp_struct->mag_y);
//
//  EXPECT_EQ(c_struct->mag_z, cpp_struct->mag_z);
//
}
