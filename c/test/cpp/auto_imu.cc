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
#include <libsbp/imu.h>
#include <libsbp/cpp/imu.h>
#include <libsbp/imu.h>
#include <libsbp/cpp/imu.h>


TEST(test_msg_imu_raw, default_construction) {
  sbp::MsgImuRaw variable;
  (void) variable;
}

TEST(test_msg_imu_raw, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgImuRaw);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_imu_raw_t *c_struct = reinterpret_cast<const msg_imu_raw_t*>(buffer);
  const sbp::MsgImuRaw *cpp_struct = reinterpret_cast<const sbp::MsgImuRaw*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->tow_f, cpp_struct->tow_f);
//
//  EXPECT_EQ(c_struct->acc_x, cpp_struct->acc_x);
//
//  EXPECT_EQ(c_struct->acc_y, cpp_struct->acc_y);
//
//  EXPECT_EQ(c_struct->acc_z, cpp_struct->acc_z);
//
//  EXPECT_EQ(c_struct->gyr_x, cpp_struct->gyr_x);
//
//  EXPECT_EQ(c_struct->gyr_y, cpp_struct->gyr_y);
//
//  EXPECT_EQ(c_struct->gyr_z, cpp_struct->gyr_z);
//
}

TEST(test_msg_imu_aux, default_construction) {
  sbp::MsgImuAux variable;
  (void) variable;
}

TEST(test_msg_imu_aux, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgImuAux);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_imu_aux_t *c_struct = reinterpret_cast<const msg_imu_aux_t*>(buffer);
  const sbp::MsgImuAux *cpp_struct = reinterpret_cast<const sbp::MsgImuAux*>(buffer);

//
//  EXPECT_EQ(c_struct->imu_type, cpp_struct->imu_type);
//
//  EXPECT_EQ(c_struct->temp, cpp_struct->temp);
//
//  EXPECT_EQ(c_struct->imu_conf, cpp_struct->imu_conf);
//
}
