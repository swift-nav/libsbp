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
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>
#include <libsbp/navigation.h>
#include <libsbp/cpp/navigation.h>


TEST(test_msg_gps_time, default_construction) {
  sbp::MsgGpsTime variable;
  (void) variable;
}

TEST(test_msg_gps_time, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgGpsTime);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_gps_time_t *c_struct = reinterpret_cast<const msg_gps_time_t*>(buffer);
  const sbp::MsgGpsTime *cpp_struct = reinterpret_cast<const sbp::MsgGpsTime*>(buffer);

//
//  EXPECT_EQ(c_struct->wn, cpp_struct->wn);
//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->ns_residual, cpp_struct->ns_residual);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_gps_time_gnss, default_construction) {
  sbp::MsgGpsTimeGnss variable;
  (void) variable;
}

TEST(test_msg_gps_time_gnss, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgGpsTimeGnss);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_gps_time_gnss_t *c_struct = reinterpret_cast<const msg_gps_time_gnss_t*>(buffer);
  const sbp::MsgGpsTimeGnss *cpp_struct = reinterpret_cast<const sbp::MsgGpsTimeGnss*>(buffer);

//
//  EXPECT_EQ(c_struct->wn, cpp_struct->wn);
//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->ns_residual, cpp_struct->ns_residual);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_utc_time, default_construction) {
  sbp::MsgUtcTime variable;
  (void) variable;
}

TEST(test_msg_utc_time, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgUtcTime);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_utc_time_t *c_struct = reinterpret_cast<const msg_utc_time_t*>(buffer);
  const sbp::MsgUtcTime *cpp_struct = reinterpret_cast<const sbp::MsgUtcTime*>(buffer);

//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->year, cpp_struct->year);
//
//  EXPECT_EQ(c_struct->month, cpp_struct->month);
//
//  EXPECT_EQ(c_struct->day, cpp_struct->day);
//
//  EXPECT_EQ(c_struct->hours, cpp_struct->hours);
//
//  EXPECT_EQ(c_struct->minutes, cpp_struct->minutes);
//
//  EXPECT_EQ(c_struct->seconds, cpp_struct->seconds);
//
//  EXPECT_EQ(c_struct->ns, cpp_struct->ns);
//
}

TEST(test_msg_utc_time_gnss, default_construction) {
  sbp::MsgUtcTimeGnss variable;
  (void) variable;
}

TEST(test_msg_utc_time_gnss, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgUtcTimeGnss);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_utc_time_gnss_t *c_struct = reinterpret_cast<const msg_utc_time_gnss_t*>(buffer);
  const sbp::MsgUtcTimeGnss *cpp_struct = reinterpret_cast<const sbp::MsgUtcTimeGnss*>(buffer);

//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->year, cpp_struct->year);
//
//  EXPECT_EQ(c_struct->month, cpp_struct->month);
//
//  EXPECT_EQ(c_struct->day, cpp_struct->day);
//
//  EXPECT_EQ(c_struct->hours, cpp_struct->hours);
//
//  EXPECT_EQ(c_struct->minutes, cpp_struct->minutes);
//
//  EXPECT_EQ(c_struct->seconds, cpp_struct->seconds);
//
//  EXPECT_EQ(c_struct->ns, cpp_struct->ns);
//
}

TEST(test_msg_dops, default_construction) {
  sbp::MsgDops variable;
  (void) variable;
}

TEST(test_msg_dops, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgDops);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_dops_t *c_struct = reinterpret_cast<const msg_dops_t*>(buffer);
  const sbp::MsgDops *cpp_struct = reinterpret_cast<const sbp::MsgDops*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->gdop, cpp_struct->gdop);
//
//  EXPECT_EQ(c_struct->pdop, cpp_struct->pdop);
//
//  EXPECT_EQ(c_struct->tdop, cpp_struct->tdop);
//
//  EXPECT_EQ(c_struct->hdop, cpp_struct->hdop);
//
//  EXPECT_EQ(c_struct->vdop, cpp_struct->vdop);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_pos_ecef, default_construction) {
  sbp::MsgPosEcef variable;
  (void) variable;
}

TEST(test_msg_pos_ecef, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgPosEcef);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_pos_ecef_t *c_struct = reinterpret_cast<const msg_pos_ecef_t*>(buffer);
  const sbp::MsgPosEcef *cpp_struct = reinterpret_cast<const sbp::MsgPosEcef*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->accuracy, cpp_struct->accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_pos_ecef_cov, default_construction) {
  sbp::MsgPosEcefCov variable;
  (void) variable;
}

TEST(test_msg_pos_ecef_cov, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgPosEcefCov);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_pos_ecef_cov_t *c_struct = reinterpret_cast<const msg_pos_ecef_cov_t*>(buffer);
  const sbp::MsgPosEcefCov *cpp_struct = reinterpret_cast<const sbp::MsgPosEcefCov*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->cov_x_x, cpp_struct->cov_x_x);
//
//  EXPECT_EQ(c_struct->cov_x_y, cpp_struct->cov_x_y);
//
//  EXPECT_EQ(c_struct->cov_x_z, cpp_struct->cov_x_z);
//
//  EXPECT_EQ(c_struct->cov_y_y, cpp_struct->cov_y_y);
//
//  EXPECT_EQ(c_struct->cov_y_z, cpp_struct->cov_y_z);
//
//  EXPECT_EQ(c_struct->cov_z_z, cpp_struct->cov_z_z);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_pos_llh, default_construction) {
  sbp::MsgPosLlh variable;
  (void) variable;
}

TEST(test_msg_pos_llh, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgPosLlh);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_pos_llh_t *c_struct = reinterpret_cast<const msg_pos_llh_t*>(buffer);
  const sbp::MsgPosLlh *cpp_struct = reinterpret_cast<const sbp::MsgPosLlh*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->lat, cpp_struct->lat);
//
//  EXPECT_EQ(c_struct->lon, cpp_struct->lon);
//
//  EXPECT_EQ(c_struct->height, cpp_struct->height);
//
//  EXPECT_EQ(c_struct->h_accuracy, cpp_struct->h_accuracy);
//
//  EXPECT_EQ(c_struct->v_accuracy, cpp_struct->v_accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_pos_llh_cov, default_construction) {
  sbp::MsgPosLlhCov variable;
  (void) variable;
}

TEST(test_msg_pos_llh_cov, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgPosLlhCov);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_pos_llh_cov_t *c_struct = reinterpret_cast<const msg_pos_llh_cov_t*>(buffer);
  const sbp::MsgPosLlhCov *cpp_struct = reinterpret_cast<const sbp::MsgPosLlhCov*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->lat, cpp_struct->lat);
//
//  EXPECT_EQ(c_struct->lon, cpp_struct->lon);
//
//  EXPECT_EQ(c_struct->height, cpp_struct->height);
//
//  EXPECT_EQ(c_struct->cov_n_n, cpp_struct->cov_n_n);
//
//  EXPECT_EQ(c_struct->cov_n_e, cpp_struct->cov_n_e);
//
//  EXPECT_EQ(c_struct->cov_n_d, cpp_struct->cov_n_d);
//
//  EXPECT_EQ(c_struct->cov_e_e, cpp_struct->cov_e_e);
//
//  EXPECT_EQ(c_struct->cov_e_d, cpp_struct->cov_e_d);
//
//  EXPECT_EQ(c_struct->cov_d_d, cpp_struct->cov_d_d);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_baseline_ecef, default_construction) {
  sbp::MsgBaselineEcef variable;
  (void) variable;
}

TEST(test_msg_baseline_ecef, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgBaselineEcef);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_baseline_ecef_t *c_struct = reinterpret_cast<const msg_baseline_ecef_t*>(buffer);
  const sbp::MsgBaselineEcef *cpp_struct = reinterpret_cast<const sbp::MsgBaselineEcef*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->accuracy, cpp_struct->accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_baseline_ned, default_construction) {
  sbp::MsgBaselineNed variable;
  (void) variable;
}

TEST(test_msg_baseline_ned, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgBaselineNed);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_baseline_ned_t *c_struct = reinterpret_cast<const msg_baseline_ned_t*>(buffer);
  const sbp::MsgBaselineNed *cpp_struct = reinterpret_cast<const sbp::MsgBaselineNed*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->n, cpp_struct->n);
//
//  EXPECT_EQ(c_struct->e, cpp_struct->e);
//
//  EXPECT_EQ(c_struct->d, cpp_struct->d);
//
//  EXPECT_EQ(c_struct->h_accuracy, cpp_struct->h_accuracy);
//
//  EXPECT_EQ(c_struct->v_accuracy, cpp_struct->v_accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_vel_ecef, default_construction) {
  sbp::MsgVelEcef variable;
  (void) variable;
}

TEST(test_msg_vel_ecef, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgVelEcef);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_vel_ecef_t *c_struct = reinterpret_cast<const msg_vel_ecef_t*>(buffer);
  const sbp::MsgVelEcef *cpp_struct = reinterpret_cast<const sbp::MsgVelEcef*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->accuracy, cpp_struct->accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_vel_ecef_cov, default_construction) {
  sbp::MsgVelEcefCov variable;
  (void) variable;
}

TEST(test_msg_vel_ecef_cov, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgVelEcefCov);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_vel_ecef_cov_t *c_struct = reinterpret_cast<const msg_vel_ecef_cov_t*>(buffer);
  const sbp::MsgVelEcefCov *cpp_struct = reinterpret_cast<const sbp::MsgVelEcefCov*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->cov_x_x, cpp_struct->cov_x_x);
//
//  EXPECT_EQ(c_struct->cov_x_y, cpp_struct->cov_x_y);
//
//  EXPECT_EQ(c_struct->cov_x_z, cpp_struct->cov_x_z);
//
//  EXPECT_EQ(c_struct->cov_y_y, cpp_struct->cov_y_y);
//
//  EXPECT_EQ(c_struct->cov_y_z, cpp_struct->cov_y_z);
//
//  EXPECT_EQ(c_struct->cov_z_z, cpp_struct->cov_z_z);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_vel_ned, default_construction) {
  sbp::MsgVelNed variable;
  (void) variable;
}

TEST(test_msg_vel_ned, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgVelNed);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_vel_ned_t *c_struct = reinterpret_cast<const msg_vel_ned_t*>(buffer);
  const sbp::MsgVelNed *cpp_struct = reinterpret_cast<const sbp::MsgVelNed*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->n, cpp_struct->n);
//
//  EXPECT_EQ(c_struct->e, cpp_struct->e);
//
//  EXPECT_EQ(c_struct->d, cpp_struct->d);
//
//  EXPECT_EQ(c_struct->h_accuracy, cpp_struct->h_accuracy);
//
//  EXPECT_EQ(c_struct->v_accuracy, cpp_struct->v_accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_vel_ned_cov, default_construction) {
  sbp::MsgVelNedCov variable;
  (void) variable;
}

TEST(test_msg_vel_ned_cov, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgVelNedCov);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_vel_ned_cov_t *c_struct = reinterpret_cast<const msg_vel_ned_cov_t*>(buffer);
  const sbp::MsgVelNedCov *cpp_struct = reinterpret_cast<const sbp::MsgVelNedCov*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->n, cpp_struct->n);
//
//  EXPECT_EQ(c_struct->e, cpp_struct->e);
//
//  EXPECT_EQ(c_struct->d, cpp_struct->d);
//
//  EXPECT_EQ(c_struct->cov_n_n, cpp_struct->cov_n_n);
//
//  EXPECT_EQ(c_struct->cov_n_e, cpp_struct->cov_n_e);
//
//  EXPECT_EQ(c_struct->cov_n_d, cpp_struct->cov_n_d);
//
//  EXPECT_EQ(c_struct->cov_e_e, cpp_struct->cov_e_e);
//
//  EXPECT_EQ(c_struct->cov_e_d, cpp_struct->cov_e_d);
//
//  EXPECT_EQ(c_struct->cov_d_d, cpp_struct->cov_d_d);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_pos_ecef_gnss, default_construction) {
  sbp::MsgPosEcefGnss variable;
  (void) variable;
}

TEST(test_msg_pos_ecef_gnss, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgPosEcefGnss);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_pos_ecef_gnss_t *c_struct = reinterpret_cast<const msg_pos_ecef_gnss_t*>(buffer);
  const sbp::MsgPosEcefGnss *cpp_struct = reinterpret_cast<const sbp::MsgPosEcefGnss*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->accuracy, cpp_struct->accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_pos_ecef_cov_gnss, default_construction) {
  sbp::MsgPosEcefCovGnss variable;
  (void) variable;
}

TEST(test_msg_pos_ecef_cov_gnss, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgPosEcefCovGnss);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_pos_ecef_cov_gnss_t *c_struct = reinterpret_cast<const msg_pos_ecef_cov_gnss_t*>(buffer);
  const sbp::MsgPosEcefCovGnss *cpp_struct = reinterpret_cast<const sbp::MsgPosEcefCovGnss*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->cov_x_x, cpp_struct->cov_x_x);
//
//  EXPECT_EQ(c_struct->cov_x_y, cpp_struct->cov_x_y);
//
//  EXPECT_EQ(c_struct->cov_x_z, cpp_struct->cov_x_z);
//
//  EXPECT_EQ(c_struct->cov_y_y, cpp_struct->cov_y_y);
//
//  EXPECT_EQ(c_struct->cov_y_z, cpp_struct->cov_y_z);
//
//  EXPECT_EQ(c_struct->cov_z_z, cpp_struct->cov_z_z);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_pos_llh_gnss, default_construction) {
  sbp::MsgPosLlhGnss variable;
  (void) variable;
}

TEST(test_msg_pos_llh_gnss, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgPosLlhGnss);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_pos_llh_gnss_t *c_struct = reinterpret_cast<const msg_pos_llh_gnss_t*>(buffer);
  const sbp::MsgPosLlhGnss *cpp_struct = reinterpret_cast<const sbp::MsgPosLlhGnss*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->lat, cpp_struct->lat);
//
//  EXPECT_EQ(c_struct->lon, cpp_struct->lon);
//
//  EXPECT_EQ(c_struct->height, cpp_struct->height);
//
//  EXPECT_EQ(c_struct->h_accuracy, cpp_struct->h_accuracy);
//
//  EXPECT_EQ(c_struct->v_accuracy, cpp_struct->v_accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_pos_llh_cov_gnss, default_construction) {
  sbp::MsgPosLlhCovGnss variable;
  (void) variable;
}

TEST(test_msg_pos_llh_cov_gnss, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgPosLlhCovGnss);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_pos_llh_cov_gnss_t *c_struct = reinterpret_cast<const msg_pos_llh_cov_gnss_t*>(buffer);
  const sbp::MsgPosLlhCovGnss *cpp_struct = reinterpret_cast<const sbp::MsgPosLlhCovGnss*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->lat, cpp_struct->lat);
//
//  EXPECT_EQ(c_struct->lon, cpp_struct->lon);
//
//  EXPECT_EQ(c_struct->height, cpp_struct->height);
//
//  EXPECT_EQ(c_struct->cov_n_n, cpp_struct->cov_n_n);
//
//  EXPECT_EQ(c_struct->cov_n_e, cpp_struct->cov_n_e);
//
//  EXPECT_EQ(c_struct->cov_n_d, cpp_struct->cov_n_d);
//
//  EXPECT_EQ(c_struct->cov_e_e, cpp_struct->cov_e_e);
//
//  EXPECT_EQ(c_struct->cov_e_d, cpp_struct->cov_e_d);
//
//  EXPECT_EQ(c_struct->cov_d_d, cpp_struct->cov_d_d);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_vel_ecef_gnss, default_construction) {
  sbp::MsgVelEcefGnss variable;
  (void) variable;
}

TEST(test_msg_vel_ecef_gnss, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgVelEcefGnss);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_vel_ecef_gnss_t *c_struct = reinterpret_cast<const msg_vel_ecef_gnss_t*>(buffer);
  const sbp::MsgVelEcefGnss *cpp_struct = reinterpret_cast<const sbp::MsgVelEcefGnss*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->accuracy, cpp_struct->accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_vel_ecef_cov_gnss, default_construction) {
  sbp::MsgVelEcefCovGnss variable;
  (void) variable;
}

TEST(test_msg_vel_ecef_cov_gnss, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgVelEcefCovGnss);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_vel_ecef_cov_gnss_t *c_struct = reinterpret_cast<const msg_vel_ecef_cov_gnss_t*>(buffer);
  const sbp::MsgVelEcefCovGnss *cpp_struct = reinterpret_cast<const sbp::MsgVelEcefCovGnss*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->cov_x_x, cpp_struct->cov_x_x);
//
//  EXPECT_EQ(c_struct->cov_x_y, cpp_struct->cov_x_y);
//
//  EXPECT_EQ(c_struct->cov_x_z, cpp_struct->cov_x_z);
//
//  EXPECT_EQ(c_struct->cov_y_y, cpp_struct->cov_y_y);
//
//  EXPECT_EQ(c_struct->cov_y_z, cpp_struct->cov_y_z);
//
//  EXPECT_EQ(c_struct->cov_z_z, cpp_struct->cov_z_z);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_vel_ned_gnss, default_construction) {
  sbp::MsgVelNedGnss variable;
  (void) variable;
}

TEST(test_msg_vel_ned_gnss, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgVelNedGnss);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_vel_ned_gnss_t *c_struct = reinterpret_cast<const msg_vel_ned_gnss_t*>(buffer);
  const sbp::MsgVelNedGnss *cpp_struct = reinterpret_cast<const sbp::MsgVelNedGnss*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->n, cpp_struct->n);
//
//  EXPECT_EQ(c_struct->e, cpp_struct->e);
//
//  EXPECT_EQ(c_struct->d, cpp_struct->d);
//
//  EXPECT_EQ(c_struct->h_accuracy, cpp_struct->h_accuracy);
//
//  EXPECT_EQ(c_struct->v_accuracy, cpp_struct->v_accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_vel_ned_cov_gnss, default_construction) {
  sbp::MsgVelNedCovGnss variable;
  (void) variable;
}

TEST(test_msg_vel_ned_cov_gnss, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgVelNedCovGnss);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_vel_ned_cov_gnss_t *c_struct = reinterpret_cast<const msg_vel_ned_cov_gnss_t*>(buffer);
  const sbp::MsgVelNedCovGnss *cpp_struct = reinterpret_cast<const sbp::MsgVelNedCovGnss*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->n, cpp_struct->n);
//
//  EXPECT_EQ(c_struct->e, cpp_struct->e);
//
//  EXPECT_EQ(c_struct->d, cpp_struct->d);
//
//  EXPECT_EQ(c_struct->cov_n_n, cpp_struct->cov_n_n);
//
//  EXPECT_EQ(c_struct->cov_n_e, cpp_struct->cov_n_e);
//
//  EXPECT_EQ(c_struct->cov_n_d, cpp_struct->cov_n_d);
//
//  EXPECT_EQ(c_struct->cov_e_e, cpp_struct->cov_e_e);
//
//  EXPECT_EQ(c_struct->cov_e_d, cpp_struct->cov_e_d);
//
//  EXPECT_EQ(c_struct->cov_d_d, cpp_struct->cov_d_d);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_vel_body, default_construction) {
  sbp::MsgVelBody variable;
  (void) variable;
}

TEST(test_msg_vel_body, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgVelBody);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_vel_body_t *c_struct = reinterpret_cast<const msg_vel_body_t*>(buffer);
  const sbp::MsgVelBody *cpp_struct = reinterpret_cast<const sbp::MsgVelBody*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->cov_x_x, cpp_struct->cov_x_x);
//
//  EXPECT_EQ(c_struct->cov_x_y, cpp_struct->cov_x_y);
//
//  EXPECT_EQ(c_struct->cov_x_z, cpp_struct->cov_x_z);
//
//  EXPECT_EQ(c_struct->cov_y_y, cpp_struct->cov_y_y);
//
//  EXPECT_EQ(c_struct->cov_y_z, cpp_struct->cov_y_z);
//
//  EXPECT_EQ(c_struct->cov_z_z, cpp_struct->cov_z_z);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_age_corrections, default_construction) {
  sbp::MsgAgeCorrections variable;
  (void) variable;
}

TEST(test_msg_age_corrections, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgAgeCorrections);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_age_corrections_t *c_struct = reinterpret_cast<const msg_age_corrections_t*>(buffer);
  const sbp::MsgAgeCorrections *cpp_struct = reinterpret_cast<const sbp::MsgAgeCorrections*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->age, cpp_struct->age);
//
}

TEST(test_msg_gps_time_dep_a, default_construction) {
  sbp::MsgGpsTimeDepA variable;
  (void) variable;
}

TEST(test_msg_gps_time_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgGpsTimeDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_gps_time_dep_a_t *c_struct = reinterpret_cast<const msg_gps_time_dep_a_t*>(buffer);
  const sbp::MsgGpsTimeDepA *cpp_struct = reinterpret_cast<const sbp::MsgGpsTimeDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->wn, cpp_struct->wn);
//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->ns_residual, cpp_struct->ns_residual);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_dops_dep_a, default_construction) {
  sbp::MsgDopsDepA variable;
  (void) variable;
}

TEST(test_msg_dops_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgDopsDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_dops_dep_a_t *c_struct = reinterpret_cast<const msg_dops_dep_a_t*>(buffer);
  const sbp::MsgDopsDepA *cpp_struct = reinterpret_cast<const sbp::MsgDopsDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->gdop, cpp_struct->gdop);
//
//  EXPECT_EQ(c_struct->pdop, cpp_struct->pdop);
//
//  EXPECT_EQ(c_struct->tdop, cpp_struct->tdop);
//
//  EXPECT_EQ(c_struct->hdop, cpp_struct->hdop);
//
//  EXPECT_EQ(c_struct->vdop, cpp_struct->vdop);
//
}

TEST(test_msg_pos_ecef_dep_a, default_construction) {
  sbp::MsgPosEcefDepA variable;
  (void) variable;
}

TEST(test_msg_pos_ecef_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgPosEcefDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_pos_ecef_dep_a_t *c_struct = reinterpret_cast<const msg_pos_ecef_dep_a_t*>(buffer);
  const sbp::MsgPosEcefDepA *cpp_struct = reinterpret_cast<const sbp::MsgPosEcefDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->accuracy, cpp_struct->accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_pos_llh_dep_a, default_construction) {
  sbp::MsgPosLlhDepA variable;
  (void) variable;
}

TEST(test_msg_pos_llh_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgPosLlhDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_pos_llh_dep_a_t *c_struct = reinterpret_cast<const msg_pos_llh_dep_a_t*>(buffer);
  const sbp::MsgPosLlhDepA *cpp_struct = reinterpret_cast<const sbp::MsgPosLlhDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->lat, cpp_struct->lat);
//
//  EXPECT_EQ(c_struct->lon, cpp_struct->lon);
//
//  EXPECT_EQ(c_struct->height, cpp_struct->height);
//
//  EXPECT_EQ(c_struct->h_accuracy, cpp_struct->h_accuracy);
//
//  EXPECT_EQ(c_struct->v_accuracy, cpp_struct->v_accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_baseline_ecef_dep_a, default_construction) {
  sbp::MsgBaselineEcefDepA variable;
  (void) variable;
}

TEST(test_msg_baseline_ecef_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgBaselineEcefDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_baseline_ecef_dep_a_t *c_struct = reinterpret_cast<const msg_baseline_ecef_dep_a_t*>(buffer);
  const sbp::MsgBaselineEcefDepA *cpp_struct = reinterpret_cast<const sbp::MsgBaselineEcefDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->accuracy, cpp_struct->accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_baseline_ned_dep_a, default_construction) {
  sbp::MsgBaselineNedDepA variable;
  (void) variable;
}

TEST(test_msg_baseline_ned_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgBaselineNedDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_baseline_ned_dep_a_t *c_struct = reinterpret_cast<const msg_baseline_ned_dep_a_t*>(buffer);
  const sbp::MsgBaselineNedDepA *cpp_struct = reinterpret_cast<const sbp::MsgBaselineNedDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->n, cpp_struct->n);
//
//  EXPECT_EQ(c_struct->e, cpp_struct->e);
//
//  EXPECT_EQ(c_struct->d, cpp_struct->d);
//
//  EXPECT_EQ(c_struct->h_accuracy, cpp_struct->h_accuracy);
//
//  EXPECT_EQ(c_struct->v_accuracy, cpp_struct->v_accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_vel_ecef_dep_a, default_construction) {
  sbp::MsgVelEcefDepA variable;
  (void) variable;
}

TEST(test_msg_vel_ecef_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgVelEcefDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_vel_ecef_dep_a_t *c_struct = reinterpret_cast<const msg_vel_ecef_dep_a_t*>(buffer);
  const sbp::MsgVelEcefDepA *cpp_struct = reinterpret_cast<const sbp::MsgVelEcefDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->x, cpp_struct->x);
//
//  EXPECT_EQ(c_struct->y, cpp_struct->y);
//
//  EXPECT_EQ(c_struct->z, cpp_struct->z);
//
//  EXPECT_EQ(c_struct->accuracy, cpp_struct->accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_vel_ned_dep_a, default_construction) {
  sbp::MsgVelNedDepA variable;
  (void) variable;
}

TEST(test_msg_vel_ned_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgVelNedDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_vel_ned_dep_a_t *c_struct = reinterpret_cast<const msg_vel_ned_dep_a_t*>(buffer);
  const sbp::MsgVelNedDepA *cpp_struct = reinterpret_cast<const sbp::MsgVelNedDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->n, cpp_struct->n);
//
//  EXPECT_EQ(c_struct->e, cpp_struct->e);
//
//  EXPECT_EQ(c_struct->d, cpp_struct->d);
//
//  EXPECT_EQ(c_struct->h_accuracy, cpp_struct->h_accuracy);
//
//  EXPECT_EQ(c_struct->v_accuracy, cpp_struct->v_accuracy);
//
//  EXPECT_EQ(c_struct->n_sats, cpp_struct->n_sats);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_baseline_heading_dep_a, default_construction) {
  sbp::MsgBaselineHeadingDepA variable;
  (void) variable;
}

TEST(test_msg_baseline_heading_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgBaselineHeadingDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_baseline_heading_dep_a_t *c_struct = reinterpret_cast<const msg_baseline_heading_dep_a_t*>(buffer);
  const sbp::MsgBaselineHeadingDepA *cpp_struct = reinterpret_cast<const sbp::MsgBaselineHeadingDepA*>(buffer);

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

TEST(test_msg_protection_level, default_construction) {
  sbp::MsgProtectionLevel variable;
  (void) variable;
}

TEST(test_msg_protection_level, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgProtectionLevel);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_protection_level_t *c_struct = reinterpret_cast<const msg_protection_level_t*>(buffer);
  const sbp::MsgProtectionLevel *cpp_struct = reinterpret_cast<const sbp::MsgProtectionLevel*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->vpl, cpp_struct->vpl);
//
//  EXPECT_EQ(c_struct->hpl, cpp_struct->hpl);
//
//  EXPECT_EQ(c_struct->lat, cpp_struct->lat);
//
//  EXPECT_EQ(c_struct->lon, cpp_struct->lon);
//
//  EXPECT_EQ(c_struct->height, cpp_struct->height);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}
