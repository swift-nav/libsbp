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
#include <libsbp/solution_meta.h>
#include <libsbp/cpp/solution_meta.h>
#include <libsbp/solution_meta.h>
#include <libsbp/cpp/solution_meta.h>
#include <libsbp/solution_meta.h>
#include <libsbp/cpp/solution_meta.h>
#include <libsbp/solution_meta.h>
#include <libsbp/cpp/solution_meta.h>
#include <libsbp/solution_meta.h>
#include <libsbp/cpp/solution_meta.h>
#include <libsbp/solution_meta.h>
#include <libsbp/cpp/solution_meta.h>


TEST(test_solution_input_type, default_construction) {
  sbp::SolutionInputType variable;
  (void) variable;
}

TEST(test_solution_input_type, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::SolutionInputType);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const solution_input_type_t *c_struct = reinterpret_cast<const solution_input_type_t*>(buffer);
  const sbp::SolutionInputType *cpp_struct = reinterpret_cast<const sbp::SolutionInputType*>(buffer);

//
//  EXPECT_EQ(c_struct->sensor_type, cpp_struct->sensor_type);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_soln_meta_dep_a, default_construction) {
  sbp::MsgSolnMetaDepA<> variable;
  (void) variable;
}

TEST(test_msg_soln_meta_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSolnMetaDepA<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_soln_meta_dep_a_t *c_struct = reinterpret_cast<const msg_soln_meta_dep_a_t*>(buffer);
  const sbp::MsgSolnMetaDepA<> *cpp_struct = reinterpret_cast<const sbp::MsgSolnMetaDepA<>*>(buffer);

//
//  EXPECT_EQ(c_struct->pdop, cpp_struct->pdop);
//
//  EXPECT_EQ(c_struct->hdop, cpp_struct->hdop);
//
//  EXPECT_EQ(c_struct->vdop, cpp_struct->vdop);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->age_corrections, cpp_struct->age_corrections);
//
//  EXPECT_EQ(c_struct->alignment_status, cpp_struct->alignment_status);
//
//  EXPECT_EQ(c_struct->last_used_gnss_pos_tow, cpp_struct->last_used_gnss_pos_tow);
//
//  EXPECT_EQ(c_struct->last_used_gnss_vel_tow, cpp_struct->last_used_gnss_vel_tow);
//
//  EXPECT_EQ(c_struct->sol_in, cpp_struct->sol_in);
//
}

TEST(test_msg_soln_meta, default_construction) {
  sbp::MsgSolnMeta<> variable;
  (void) variable;
}

TEST(test_msg_soln_meta, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSolnMeta<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_soln_meta_t *c_struct = reinterpret_cast<const msg_soln_meta_t*>(buffer);
  const sbp::MsgSolnMeta<> *cpp_struct = reinterpret_cast<const sbp::MsgSolnMeta<>*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->pdop, cpp_struct->pdop);
//
//  EXPECT_EQ(c_struct->hdop, cpp_struct->hdop);
//
//  EXPECT_EQ(c_struct->vdop, cpp_struct->vdop);
//
//  EXPECT_EQ(c_struct->age_corrections, cpp_struct->age_corrections);
//
//  EXPECT_EQ(c_struct->age_gnss, cpp_struct->age_gnss);
//
//  EXPECT_EQ(c_struct->sol_in, cpp_struct->sol_in);
//
}

TEST(test_g_n_s_s_input_type, default_construction) {
  sbp::GNSSInputType variable;
  (void) variable;
}

TEST(test_g_n_s_s_input_type, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::GNSSInputType);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const gnss_input_type_t *c_struct = reinterpret_cast<const gnss_input_type_t*>(buffer);
  const sbp::GNSSInputType *cpp_struct = reinterpret_cast<const sbp::GNSSInputType*>(buffer);

//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_i_m_u_input_type, default_construction) {
  sbp::IMUInputType variable;
  (void) variable;
}

TEST(test_i_m_u_input_type, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::IMUInputType);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const imu_input_type_t *c_struct = reinterpret_cast<const imu_input_type_t*>(buffer);
  const sbp::IMUInputType *cpp_struct = reinterpret_cast<const sbp::IMUInputType*>(buffer);

//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_odo_input_type, default_construction) {
  sbp::OdoInputType variable;
  (void) variable;
}

TEST(test_odo_input_type, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::OdoInputType);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const odo_input_type_t *c_struct = reinterpret_cast<const odo_input_type_t*>(buffer);
  const sbp::OdoInputType *cpp_struct = reinterpret_cast<const sbp::OdoInputType*>(buffer);

//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}
