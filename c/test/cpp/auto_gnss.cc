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
#include <libsbp/gnss.h>
#include <libsbp/cpp/gnss.h>
#include <libsbp/gnss.h>
#include <libsbp/cpp/gnss.h>
#include <libsbp/gnss.h>
#include <libsbp/cpp/gnss.h>
#include <libsbp/gnss.h>
#include <libsbp/cpp/gnss.h>
#include <libsbp/gnss.h>
#include <libsbp/cpp/gnss.h>
#include <libsbp/gnss.h>
#include <libsbp/cpp/gnss.h>
#include <libsbp/gnss.h>
#include <libsbp/cpp/gnss.h>


TEST(test_gnss_signal, default_construction) {
  sbp::GnssSignal variable;
  (void) variable;
}

TEST(test_gnss_signal, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::GnssSignal);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const sbp_gnss_signal_t *c_struct = reinterpret_cast<const sbp_gnss_signal_t*>(buffer);
  const sbp::GnssSignal *cpp_struct = reinterpret_cast<const sbp::GnssSignal*>(buffer);

//
//  EXPECT_EQ(c_struct->sat, cpp_struct->sat);
//
//  EXPECT_EQ(c_struct->code, cpp_struct->code);
//
}

TEST(test_sv_id, default_construction) {
  sbp::SvId variable;
  (void) variable;
}

TEST(test_sv_id, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::SvId);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const sv_id_t *c_struct = reinterpret_cast<const sv_id_t*>(buffer);
  const sbp::SvId *cpp_struct = reinterpret_cast<const sbp::SvId*>(buffer);

//
//  EXPECT_EQ(c_struct->satId, cpp_struct->satId);
//
//  EXPECT_EQ(c_struct->constellation, cpp_struct->constellation);
//
}

TEST(test_gnss_signal_dep, default_construction) {
  sbp::GnssSignalDep variable;
  (void) variable;
}

TEST(test_gnss_signal_dep, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::GnssSignalDep);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const gnss_signal_dep_t *c_struct = reinterpret_cast<const gnss_signal_dep_t*>(buffer);
  const sbp::GnssSignalDep *cpp_struct = reinterpret_cast<const sbp::GnssSignalDep*>(buffer);

//
//  EXPECT_EQ(c_struct->sat, cpp_struct->sat);
//
//  EXPECT_EQ(c_struct->code, cpp_struct->code);
//
//  EXPECT_EQ(c_struct->reserved, cpp_struct->reserved);
//
}

TEST(test_g_p_s_time_dep, default_construction) {
  sbp::GPSTimeDep variable;
  (void) variable;
}

TEST(test_g_p_s_time_dep, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::GPSTimeDep);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const gps_time_dep_t *c_struct = reinterpret_cast<const gps_time_dep_t*>(buffer);
  const sbp::GPSTimeDep *cpp_struct = reinterpret_cast<const sbp::GPSTimeDep*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->wn, cpp_struct->wn);
//
}

TEST(test_g_p_s_time_sec, default_construction) {
  sbp::GPSTimeSec variable;
  (void) variable;
}

TEST(test_g_p_s_time_sec, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::GPSTimeSec);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const gps_time_sec_t *c_struct = reinterpret_cast<const gps_time_sec_t*>(buffer);
  const sbp::GPSTimeSec *cpp_struct = reinterpret_cast<const sbp::GPSTimeSec*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->wn, cpp_struct->wn);
//
}

TEST(test_g_p_s_time, default_construction) {
  sbp::GPSTime variable;
  (void) variable;
}

TEST(test_g_p_s_time, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::GPSTime);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const sbp_gps_time_t *c_struct = reinterpret_cast<const sbp_gps_time_t*>(buffer);
  const sbp::GPSTime *cpp_struct = reinterpret_cast<const sbp::GPSTime*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->ns_residual, cpp_struct->ns_residual);
//
//  EXPECT_EQ(c_struct->wn, cpp_struct->wn);
//
}

TEST(test_carrier_phase, default_construction) {
  sbp::CarrierPhase variable;
  (void) variable;
}

TEST(test_carrier_phase, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::CarrierPhase);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const carrier_phase_t *c_struct = reinterpret_cast<const carrier_phase_t*>(buffer);
  const sbp::CarrierPhase *cpp_struct = reinterpret_cast<const sbp::CarrierPhase*>(buffer);

//
//  EXPECT_EQ(c_struct->i, cpp_struct->i);
//
//  EXPECT_EQ(c_struct->f, cpp_struct->f);
//
}
