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
#include <libsbp/acquisition.h>
#include <libsbp/cpp/acquisition.h>
#include <libsbp/acquisition.h>
#include <libsbp/cpp/acquisition.h>
#include <libsbp/acquisition.h>
#include <libsbp/cpp/acquisition.h>
#include <libsbp/acquisition.h>
#include <libsbp/cpp/acquisition.h>
#include <libsbp/acquisition.h>
#include <libsbp/cpp/acquisition.h>
#include <libsbp/acquisition.h>
#include <libsbp/cpp/acquisition.h>
#include <libsbp/acquisition.h>
#include <libsbp/cpp/acquisition.h>
#include <libsbp/acquisition.h>
#include <libsbp/cpp/acquisition.h>


TEST(test_msg_acq_result, default_construction) {
  sbp::MsgAcqResult variable;
  (void) variable;
}

TEST(test_msg_acq_result, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgAcqResult);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_acq_result_t *c_struct = reinterpret_cast<const msg_acq_result_t*>(buffer);
  const sbp::MsgAcqResult *cpp_struct = reinterpret_cast<const sbp::MsgAcqResult*>(buffer);

//
//  EXPECT_EQ(c_struct->cn0, cpp_struct->cn0);
//
//  EXPECT_EQ(c_struct->cp, cpp_struct->cp);
//
//  EXPECT_EQ(c_struct->cf, cpp_struct->cf);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
}

TEST(test_msg_acq_result_dep_c, default_construction) {
  sbp::MsgAcqResultDepC variable;
  (void) variable;
}

TEST(test_msg_acq_result_dep_c, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgAcqResultDepC);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_acq_result_dep_c_t *c_struct = reinterpret_cast<const msg_acq_result_dep_c_t*>(buffer);
  const sbp::MsgAcqResultDepC *cpp_struct = reinterpret_cast<const sbp::MsgAcqResultDepC*>(buffer);

//
//  EXPECT_EQ(c_struct->cn0, cpp_struct->cn0);
//
//  EXPECT_EQ(c_struct->cp, cpp_struct->cp);
//
//  EXPECT_EQ(c_struct->cf, cpp_struct->cf);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
}

TEST(test_msg_acq_result_dep_b, default_construction) {
  sbp::MsgAcqResultDepB variable;
  (void) variable;
}

TEST(test_msg_acq_result_dep_b, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgAcqResultDepB);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_acq_result_dep_b_t *c_struct = reinterpret_cast<const msg_acq_result_dep_b_t*>(buffer);
  const sbp::MsgAcqResultDepB *cpp_struct = reinterpret_cast<const sbp::MsgAcqResultDepB*>(buffer);

//
//  EXPECT_EQ(c_struct->snr, cpp_struct->snr);
//
//  EXPECT_EQ(c_struct->cp, cpp_struct->cp);
//
//  EXPECT_EQ(c_struct->cf, cpp_struct->cf);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
}

TEST(test_msg_acq_result_dep_a, default_construction) {
  sbp::MsgAcqResultDepA variable;
  (void) variable;
}

TEST(test_msg_acq_result_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgAcqResultDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_acq_result_dep_a_t *c_struct = reinterpret_cast<const msg_acq_result_dep_a_t*>(buffer);
  const sbp::MsgAcqResultDepA *cpp_struct = reinterpret_cast<const sbp::MsgAcqResultDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->snr, cpp_struct->snr);
//
//  EXPECT_EQ(c_struct->cp, cpp_struct->cp);
//
//  EXPECT_EQ(c_struct->cf, cpp_struct->cf);
//
//  EXPECT_EQ(c_struct->prn, cpp_struct->prn);
//
}

TEST(test_acq_sv_profile, default_construction) {
  sbp::AcqSvProfile variable;
  (void) variable;
}

TEST(test_acq_sv_profile, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::AcqSvProfile);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const acq_sv_profile_t *c_struct = reinterpret_cast<const acq_sv_profile_t*>(buffer);
  const sbp::AcqSvProfile *cpp_struct = reinterpret_cast<const sbp::AcqSvProfile*>(buffer);

//
//  EXPECT_EQ(c_struct->job_type, cpp_struct->job_type);
//
//  EXPECT_EQ(c_struct->status, cpp_struct->status);
//
//  EXPECT_EQ(c_struct->cn0, cpp_struct->cn0);
//
//  EXPECT_EQ(c_struct->int_time, cpp_struct->int_time);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->bin_width, cpp_struct->bin_width);
//
//  EXPECT_EQ(c_struct->timestamp, cpp_struct->timestamp);
//
//  EXPECT_EQ(c_struct->time_spent, cpp_struct->time_spent);
//
//  EXPECT_EQ(c_struct->cf_min, cpp_struct->cf_min);
//
//  EXPECT_EQ(c_struct->cf_max, cpp_struct->cf_max);
//
//  EXPECT_EQ(c_struct->cf, cpp_struct->cf);
//
//  EXPECT_EQ(c_struct->cp, cpp_struct->cp);
//
}

TEST(test_acq_sv_profile_dep, default_construction) {
  sbp::AcqSvProfileDep variable;
  (void) variable;
}

TEST(test_acq_sv_profile_dep, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::AcqSvProfileDep);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const acq_sv_profile_dep_t *c_struct = reinterpret_cast<const acq_sv_profile_dep_t*>(buffer);
  const sbp::AcqSvProfileDep *cpp_struct = reinterpret_cast<const sbp::AcqSvProfileDep*>(buffer);

//
//  EXPECT_EQ(c_struct->job_type, cpp_struct->job_type);
//
//  EXPECT_EQ(c_struct->status, cpp_struct->status);
//
//  EXPECT_EQ(c_struct->cn0, cpp_struct->cn0);
//
//  EXPECT_EQ(c_struct->int_time, cpp_struct->int_time);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->bin_width, cpp_struct->bin_width);
//
//  EXPECT_EQ(c_struct->timestamp, cpp_struct->timestamp);
//
//  EXPECT_EQ(c_struct->time_spent, cpp_struct->time_spent);
//
//  EXPECT_EQ(c_struct->cf_min, cpp_struct->cf_min);
//
//  EXPECT_EQ(c_struct->cf_max, cpp_struct->cf_max);
//
//  EXPECT_EQ(c_struct->cf, cpp_struct->cf);
//
//  EXPECT_EQ(c_struct->cp, cpp_struct->cp);
//
}

TEST(test_msg_acq_sv_profile, default_construction) {
  sbp::MsgAcqSvProfile<> variable;
  (void) variable;
}

TEST(test_msg_acq_sv_profile, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgAcqSvProfile<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_acq_sv_profile_t *c_struct = reinterpret_cast<const msg_acq_sv_profile_t*>(buffer);
  const sbp::MsgAcqSvProfile<> *cpp_struct = reinterpret_cast<const sbp::MsgAcqSvProfile<>*>(buffer);

//
//  EXPECT_EQ(c_struct->acq_sv_profile, cpp_struct->acq_sv_profile);
//
}

TEST(test_msg_acq_sv_profile_dep, default_construction) {
  sbp::MsgAcqSvProfileDep<> variable;
  (void) variable;
}

TEST(test_msg_acq_sv_profile_dep, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgAcqSvProfileDep<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_acq_sv_profile_dep_t *c_struct = reinterpret_cast<const msg_acq_sv_profile_dep_t*>(buffer);
  const sbp::MsgAcqSvProfileDep<> *cpp_struct = reinterpret_cast<const sbp::MsgAcqSvProfileDep<>*>(buffer);

//
//  EXPECT_EQ(c_struct->acq_sv_profile, cpp_struct->acq_sv_profile);
//
}
