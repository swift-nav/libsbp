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
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>
#include <libsbp/tracking.h>
#include <libsbp/cpp/tracking.h>


TEST(test_msg_tracking_state_detailed_dep_a, default_construction) {
  sbp::MsgTrackingStateDetailedDepA variable;
  (void) variable;
}

TEST(test_msg_tracking_state_detailed_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgTrackingStateDetailedDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_tracking_state_detailed_dep_a_t *c_struct = reinterpret_cast<const msg_tracking_state_detailed_dep_a_t*>(buffer);
  const sbp::MsgTrackingStateDetailedDepA *cpp_struct = reinterpret_cast<const sbp::MsgTrackingStateDetailedDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->recv_time, cpp_struct->recv_time);
//
//  EXPECT_EQ(c_struct->tot, cpp_struct->tot);
//
//  EXPECT_EQ(c_struct->P, cpp_struct->P);
//
//  EXPECT_EQ(c_struct->P_std, cpp_struct->P_std);
//
//  EXPECT_EQ(c_struct->L, cpp_struct->L);
//
//  EXPECT_EQ(c_struct->cn0, cpp_struct->cn0);
//
//  EXPECT_EQ(c_struct->lock, cpp_struct->lock);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->doppler, cpp_struct->doppler);
//
//  EXPECT_EQ(c_struct->doppler_std, cpp_struct->doppler_std);
//
//  EXPECT_EQ(c_struct->uptime, cpp_struct->uptime);
//
//  EXPECT_EQ(c_struct->clock_offset, cpp_struct->clock_offset);
//
//  EXPECT_EQ(c_struct->clock_drift, cpp_struct->clock_drift);
//
//  EXPECT_EQ(c_struct->corr_spacing, cpp_struct->corr_spacing);
//
//  EXPECT_EQ(c_struct->acceleration, cpp_struct->acceleration);
//
//  EXPECT_EQ(c_struct->sync_flags, cpp_struct->sync_flags);
//
//  EXPECT_EQ(c_struct->tow_flags, cpp_struct->tow_flags);
//
//  EXPECT_EQ(c_struct->track_flags, cpp_struct->track_flags);
//
//  EXPECT_EQ(c_struct->nav_flags, cpp_struct->nav_flags);
//
//  EXPECT_EQ(c_struct->pset_flags, cpp_struct->pset_flags);
//
//  EXPECT_EQ(c_struct->misc_flags, cpp_struct->misc_flags);
//
}

TEST(test_msg_tracking_state_detailed_dep, default_construction) {
  sbp::MsgTrackingStateDetailedDep variable;
  (void) variable;
}

TEST(test_msg_tracking_state_detailed_dep, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgTrackingStateDetailedDep);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_tracking_state_detailed_dep_t *c_struct = reinterpret_cast<const msg_tracking_state_detailed_dep_t*>(buffer);
  const sbp::MsgTrackingStateDetailedDep *cpp_struct = reinterpret_cast<const sbp::MsgTrackingStateDetailedDep*>(buffer);

//
//  EXPECT_EQ(c_struct->recv_time, cpp_struct->recv_time);
//
//  EXPECT_EQ(c_struct->tot, cpp_struct->tot);
//
//  EXPECT_EQ(c_struct->P, cpp_struct->P);
//
//  EXPECT_EQ(c_struct->P_std, cpp_struct->P_std);
//
//  EXPECT_EQ(c_struct->L, cpp_struct->L);
//
//  EXPECT_EQ(c_struct->cn0, cpp_struct->cn0);
//
//  EXPECT_EQ(c_struct->lock, cpp_struct->lock);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->doppler, cpp_struct->doppler);
//
//  EXPECT_EQ(c_struct->doppler_std, cpp_struct->doppler_std);
//
//  EXPECT_EQ(c_struct->uptime, cpp_struct->uptime);
//
//  EXPECT_EQ(c_struct->clock_offset, cpp_struct->clock_offset);
//
//  EXPECT_EQ(c_struct->clock_drift, cpp_struct->clock_drift);
//
//  EXPECT_EQ(c_struct->corr_spacing, cpp_struct->corr_spacing);
//
//  EXPECT_EQ(c_struct->acceleration, cpp_struct->acceleration);
//
//  EXPECT_EQ(c_struct->sync_flags, cpp_struct->sync_flags);
//
//  EXPECT_EQ(c_struct->tow_flags, cpp_struct->tow_flags);
//
//  EXPECT_EQ(c_struct->track_flags, cpp_struct->track_flags);
//
//  EXPECT_EQ(c_struct->nav_flags, cpp_struct->nav_flags);
//
//  EXPECT_EQ(c_struct->pset_flags, cpp_struct->pset_flags);
//
//  EXPECT_EQ(c_struct->misc_flags, cpp_struct->misc_flags);
//
}

TEST(test_tracking_channel_state, default_construction) {
  sbp::TrackingChannelState variable;
  (void) variable;
}

TEST(test_tracking_channel_state, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::TrackingChannelState);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const tracking_channel_state_t *c_struct = reinterpret_cast<const tracking_channel_state_t*>(buffer);
  const sbp::TrackingChannelState *cpp_struct = reinterpret_cast<const sbp::TrackingChannelState*>(buffer);

//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->fcn, cpp_struct->fcn);
//
//  EXPECT_EQ(c_struct->cn0, cpp_struct->cn0);
//
}

TEST(test_msg_tracking_state, default_construction) {
  sbp::MsgTrackingState<> variable;
  (void) variable;
}

TEST(test_msg_tracking_state, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgTrackingState<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_tracking_state_t *c_struct = reinterpret_cast<const msg_tracking_state_t*>(buffer);
  const sbp::MsgTrackingState<> *cpp_struct = reinterpret_cast<const sbp::MsgTrackingState<>*>(buffer);

//
//  EXPECT_EQ(c_struct->states, cpp_struct->states);
//
}

TEST(test_measurement_state, default_construction) {
  sbp::MeasurementState variable;
  (void) variable;
}

TEST(test_measurement_state, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MeasurementState);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const measurement_state_t *c_struct = reinterpret_cast<const measurement_state_t*>(buffer);
  const sbp::MeasurementState *cpp_struct = reinterpret_cast<const sbp::MeasurementState*>(buffer);

//
//  EXPECT_EQ(c_struct->mesid, cpp_struct->mesid);
//
//  EXPECT_EQ(c_struct->cn0, cpp_struct->cn0);
//
}

TEST(test_msg_measurement_state, default_construction) {
  sbp::MsgMeasurementState<> variable;
  (void) variable;
}

TEST(test_msg_measurement_state, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgMeasurementState<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_measurement_state_t *c_struct = reinterpret_cast<const msg_measurement_state_t*>(buffer);
  const sbp::MsgMeasurementState<> *cpp_struct = reinterpret_cast<const sbp::MsgMeasurementState<>*>(buffer);

//
//  EXPECT_EQ(c_struct->states, cpp_struct->states);
//
}

TEST(test_tracking_channel_correlation, default_construction) {
  sbp::TrackingChannelCorrelation variable;
  (void) variable;
}

TEST(test_tracking_channel_correlation, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::TrackingChannelCorrelation);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const tracking_channel_correlation_t *c_struct = reinterpret_cast<const tracking_channel_correlation_t*>(buffer);
  const sbp::TrackingChannelCorrelation *cpp_struct = reinterpret_cast<const sbp::TrackingChannelCorrelation*>(buffer);

//
//  EXPECT_EQ(c_struct->I, cpp_struct->I);
//
//  EXPECT_EQ(c_struct->Q, cpp_struct->Q);
//
}

TEST(test_msg_tracking_iq, default_construction) {
  sbp::MsgTrackingIq variable;
  (void) variable;
}

TEST(test_msg_tracking_iq, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgTrackingIq);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_tracking_iq_t *c_struct = reinterpret_cast<const msg_tracking_iq_t*>(buffer);
  const sbp::MsgTrackingIq *cpp_struct = reinterpret_cast<const sbp::MsgTrackingIq*>(buffer);

//
//  EXPECT_EQ(c_struct->channel, cpp_struct->channel);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->corrs, cpp_struct->corrs);
//
}

TEST(test_tracking_channel_correlation_dep, default_construction) {
  sbp::TrackingChannelCorrelationDep variable;
  (void) variable;
}

TEST(test_tracking_channel_correlation_dep, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::TrackingChannelCorrelationDep);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const tracking_channel_correlation_dep_t *c_struct = reinterpret_cast<const tracking_channel_correlation_dep_t*>(buffer);
  const sbp::TrackingChannelCorrelationDep *cpp_struct = reinterpret_cast<const sbp::TrackingChannelCorrelationDep*>(buffer);

//
//  EXPECT_EQ(c_struct->I, cpp_struct->I);
//
//  EXPECT_EQ(c_struct->Q, cpp_struct->Q);
//
}

TEST(test_msg_tracking_iq_dep_b, default_construction) {
  sbp::MsgTrackingIqDepB variable;
  (void) variable;
}

TEST(test_msg_tracking_iq_dep_b, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgTrackingIqDepB);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_tracking_iq_dep_b_t *c_struct = reinterpret_cast<const msg_tracking_iq_dep_b_t*>(buffer);
  const sbp::MsgTrackingIqDepB *cpp_struct = reinterpret_cast<const sbp::MsgTrackingIqDepB*>(buffer);

//
//  EXPECT_EQ(c_struct->channel, cpp_struct->channel);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->corrs, cpp_struct->corrs);
//
}

TEST(test_msg_tracking_iq_dep_a, default_construction) {
  sbp::MsgTrackingIqDepA variable;
  (void) variable;
}

TEST(test_msg_tracking_iq_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgTrackingIqDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_tracking_iq_dep_a_t *c_struct = reinterpret_cast<const msg_tracking_iq_dep_a_t*>(buffer);
  const sbp::MsgTrackingIqDepA *cpp_struct = reinterpret_cast<const sbp::MsgTrackingIqDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->channel, cpp_struct->channel);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->corrs, cpp_struct->corrs);
//
}

TEST(test_tracking_channel_state_dep_a, default_construction) {
  sbp::TrackingChannelStateDepA variable;
  (void) variable;
}

TEST(test_tracking_channel_state_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::TrackingChannelStateDepA);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const tracking_channel_state_dep_a_t *c_struct = reinterpret_cast<const tracking_channel_state_dep_a_t*>(buffer);
  const sbp::TrackingChannelStateDepA *cpp_struct = reinterpret_cast<const sbp::TrackingChannelStateDepA*>(buffer);

//
//  EXPECT_EQ(c_struct->state, cpp_struct->state);
//
//  EXPECT_EQ(c_struct->prn, cpp_struct->prn);
//
//  EXPECT_EQ(c_struct->cn0, cpp_struct->cn0);
//
}

TEST(test_msg_tracking_state_dep_a, default_construction) {
  sbp::MsgTrackingStateDepA<> variable;
  (void) variable;
}

TEST(test_msg_tracking_state_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgTrackingStateDepA<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_tracking_state_dep_a_t *c_struct = reinterpret_cast<const msg_tracking_state_dep_a_t*>(buffer);
  const sbp::MsgTrackingStateDepA<> *cpp_struct = reinterpret_cast<const sbp::MsgTrackingStateDepA<>*>(buffer);

//
//  EXPECT_EQ(c_struct->states, cpp_struct->states);
//
}

TEST(test_tracking_channel_state_dep_b, default_construction) {
  sbp::TrackingChannelStateDepB variable;
  (void) variable;
}

TEST(test_tracking_channel_state_dep_b, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::TrackingChannelStateDepB);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const tracking_channel_state_dep_b_t *c_struct = reinterpret_cast<const tracking_channel_state_dep_b_t*>(buffer);
  const sbp::TrackingChannelStateDepB *cpp_struct = reinterpret_cast<const sbp::TrackingChannelStateDepB*>(buffer);

//
//  EXPECT_EQ(c_struct->state, cpp_struct->state);
//
//  EXPECT_EQ(c_struct->sid, cpp_struct->sid);
//
//  EXPECT_EQ(c_struct->cn0, cpp_struct->cn0);
//
}

TEST(test_msg_tracking_state_dep_b, default_construction) {
  sbp::MsgTrackingStateDepB<> variable;
  (void) variable;
}

TEST(test_msg_tracking_state_dep_b, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgTrackingStateDepB<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_tracking_state_dep_b_t *c_struct = reinterpret_cast<const msg_tracking_state_dep_b_t*>(buffer);
  const sbp::MsgTrackingStateDepB<> *cpp_struct = reinterpret_cast<const sbp::MsgTrackingStateDepB<>*>(buffer);

//
//  EXPECT_EQ(c_struct->states, cpp_struct->states);
//
}
