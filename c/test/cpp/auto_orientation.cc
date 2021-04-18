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
#include <libsbp/orientation.h>
#include <libsbp/cpp/orientation.h>
#include <libsbp/orientation.h>
#include <libsbp/cpp/orientation.h>
#include <libsbp/orientation.h>
#include <libsbp/cpp/orientation.h>
#include <libsbp/orientation.h>
#include <libsbp/cpp/orientation.h>


TEST(test_msg_baseline_heading, default_construction) {
  sbp::MsgBaselineHeading variable;
  (void) variable;
}

TEST(test_msg_baseline_heading, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgBaselineHeading);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_baseline_heading_t *c_struct = reinterpret_cast<const msg_baseline_heading_t*>(buffer);
  const sbp::MsgBaselineHeading *cpp_struct = reinterpret_cast<const sbp::MsgBaselineHeading*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->heading, cpp_struct->heading);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_orient_quat, default_construction) {
  sbp::MsgOrientQuat variable;
  (void) variable;
}

TEST(test_msg_orient_quat, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgOrientQuat);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_orient_quat_t *c_struct = reinterpret_cast<const msg_orient_quat_t*>(buffer);
  const sbp::MsgOrientQuat *cpp_struct = reinterpret_cast<const sbp::MsgOrientQuat*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->w, cpp_struct->w);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->w_accuracy, cpp_struct->w_accuracy);
//
//  EXPECT_EQ(c_struct->x_accuracy, cpp_struct->x_accuracy);
//
//  EXPECT_EQ(c_struct->y_accuracy, cpp_struct->y_accuracy);
//
//  EXPECT_EQ(c_struct->z_accuracy, cpp_struct->z_accuracy);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_orient_euler, default_construction) {
  sbp::MsgOrientEuler variable;
  (void) variable;
}

TEST(test_msg_orient_euler, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgOrientEuler);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_orient_euler_t *c_struct = reinterpret_cast<const msg_orient_euler_t*>(buffer);
  const sbp::MsgOrientEuler *cpp_struct = reinterpret_cast<const sbp::MsgOrientEuler*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->roll, cpp_struct->roll);
//
//  EXPECT_EQ(c_struct->pitch, cpp_struct->pitch);
//
//  EXPECT_EQ(c_struct->yaw, cpp_struct->yaw);
//
//  EXPECT_EQ(c_struct->roll_accuracy, cpp_struct->roll_accuracy);
//
//  EXPECT_EQ(c_struct->pitch_accuracy, cpp_struct->pitch_accuracy);
//
//  EXPECT_EQ(c_struct->yaw_accuracy, cpp_struct->yaw_accuracy);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_angular_rate, default_construction) {
  sbp::MsgAngularRate variable;
  (void) variable;
}

TEST(test_msg_angular_rate, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgAngularRate);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_angular_rate_t *c_struct = reinterpret_cast<const msg_angular_rate_t*>(buffer);
  const sbp::MsgAngularRate *cpp_struct = reinterpret_cast<const sbp::MsgAngularRate*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}
