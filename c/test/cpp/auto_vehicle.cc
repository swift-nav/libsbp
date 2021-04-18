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
#include <libsbp/vehicle.h>
#include <libsbp/cpp/vehicle.h>
#include <libsbp/vehicle.h>
#include <libsbp/cpp/vehicle.h>


TEST(test_msg_odometry, default_construction) {
  sbp::MsgOdometry variable;
  (void) variable;
}

TEST(test_msg_odometry, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgOdometry);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_odometry_t *c_struct = reinterpret_cast<const msg_odometry_t*>(buffer);
  const sbp::MsgOdometry *cpp_struct = reinterpret_cast<const sbp::MsgOdometry*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->velocity, cpp_struct->velocity);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_wheeltick, default_construction) {
  sbp::MsgWheeltick variable;
  (void) variable;
}

TEST(test_msg_wheeltick, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgWheeltick);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_wheeltick_t *c_struct = reinterpret_cast<const msg_wheeltick_t*>(buffer);
  const sbp::MsgWheeltick *cpp_struct = reinterpret_cast<const sbp::MsgWheeltick*>(buffer);

//
//  EXPECT_EQ(c_struct->time, cpp_struct->time);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
//  EXPECT_EQ(c_struct->source, cpp_struct->source);
//
//  EXPECT_EQ(c_struct->ticks, cpp_struct->ticks);
//
}
