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
#include <libsbp/system.h>
#include <libsbp/cpp/system.h>
#include <libsbp/system.h>
#include <libsbp/cpp/system.h>
#include <libsbp/system.h>
#include <libsbp/cpp/system.h>
#include <libsbp/system.h>
#include <libsbp/cpp/system.h>
#include <libsbp/system.h>
#include <libsbp/cpp/system.h>
#include <libsbp/system.h>
#include <libsbp/cpp/system.h>
#include <libsbp/system.h>
#include <libsbp/cpp/system.h>
#include <libsbp/system.h>
#include <libsbp/cpp/system.h>
#include <libsbp/system.h>
#include <libsbp/cpp/system.h>
#include <libsbp/system.h>
#include <libsbp/cpp/system.h>
#include <libsbp/system.h>
#include <libsbp/cpp/system.h>


TEST(test_msg_startup, default_construction) {
  sbp::MsgStartup variable;
  (void) variable;
}

TEST(test_msg_startup, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgStartup);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_startup_t *c_struct = reinterpret_cast<const msg_startup_t*>(buffer);
  const sbp::MsgStartup *cpp_struct = reinterpret_cast<const sbp::MsgStartup*>(buffer);

//
//  EXPECT_EQ(c_struct->cause, cpp_struct->cause);
//
//  EXPECT_EQ(c_struct->startup_type, cpp_struct->startup_type);
//
//  EXPECT_EQ(c_struct->reserved, cpp_struct->reserved);
//
}

TEST(test_msg_dgnss_status, default_construction) {
  sbp::MsgDgnssStatus<> variable;
  (void) variable;
}

TEST(test_msg_dgnss_status, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgDgnssStatus<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_dgnss_status_t *c_struct = reinterpret_cast<const msg_dgnss_status_t*>(buffer);
  const sbp::MsgDgnssStatus<> *cpp_struct = reinterpret_cast<const sbp::MsgDgnssStatus<>*>(buffer);

//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
//  EXPECT_EQ(c_struct->latency, cpp_struct->latency);
//
//  EXPECT_EQ(c_struct->num_signals, cpp_struct->num_signals);
//
//  EXPECT_EQ(c_struct->source, cpp_struct->source);
//
}

TEST(test_msg_heartbeat, default_construction) {
  sbp::MsgHeartbeat variable;
  (void) variable;
}

TEST(test_msg_heartbeat, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgHeartbeat);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_heartbeat_t *c_struct = reinterpret_cast<const msg_heartbeat_t*>(buffer);
  const sbp::MsgHeartbeat *cpp_struct = reinterpret_cast<const sbp::MsgHeartbeat*>(buffer);

//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_sub_system_report, default_construction) {
  sbp::SubSystemReport variable;
  (void) variable;
}

TEST(test_sub_system_report, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::SubSystemReport);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const sub_system_report_t *c_struct = reinterpret_cast<const sub_system_report_t*>(buffer);
  const sbp::SubSystemReport *cpp_struct = reinterpret_cast<const sbp::SubSystemReport*>(buffer);

//
//  EXPECT_EQ(c_struct->component, cpp_struct->component);
//
//  EXPECT_EQ(c_struct->generic, cpp_struct->generic);
//
//  EXPECT_EQ(c_struct->specific, cpp_struct->specific);
//
}

TEST(test_msg_status_report, default_construction) {
  sbp::MsgStatusReport<> variable;
  (void) variable;
}

TEST(test_msg_status_report, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgStatusReport<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_status_report_t *c_struct = reinterpret_cast<const msg_status_report_t*>(buffer);
  const sbp::MsgStatusReport<> *cpp_struct = reinterpret_cast<const sbp::MsgStatusReport<>*>(buffer);

//
//  EXPECT_EQ(c_struct->reporting_system, cpp_struct->reporting_system);
//
//  EXPECT_EQ(c_struct->sbp_version, cpp_struct->sbp_version);
//
//  EXPECT_EQ(c_struct->sequence, cpp_struct->sequence);
//
//  EXPECT_EQ(c_struct->uptime, cpp_struct->uptime);
//
//  EXPECT_EQ(c_struct->status, cpp_struct->status);
//
}

TEST(test_msg_ins_status, default_construction) {
  sbp::MsgInsStatus variable;
  (void) variable;
}

TEST(test_msg_ins_status, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgInsStatus);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ins_status_t *c_struct = reinterpret_cast<const msg_ins_status_t*>(buffer);
  const sbp::MsgInsStatus *cpp_struct = reinterpret_cast<const sbp::MsgInsStatus*>(buffer);

//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_csac_telemetry, default_construction) {
  sbp::MsgCsacTelemetry<> variable;
  (void) variable;
}

TEST(test_msg_csac_telemetry, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgCsacTelemetry<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_csac_telemetry_t *c_struct = reinterpret_cast<const msg_csac_telemetry_t*>(buffer);
  const sbp::MsgCsacTelemetry<> *cpp_struct = reinterpret_cast<const sbp::MsgCsacTelemetry<>*>(buffer);

//
//  EXPECT_EQ(c_struct->id, cpp_struct->id);
//
//  EXPECT_EQ(c_struct->telemetry, cpp_struct->telemetry);
//
}

TEST(test_msg_csac_telemetry_labels, default_construction) {
  sbp::MsgCsacTelemetryLabels<> variable;
  (void) variable;
}

TEST(test_msg_csac_telemetry_labels, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgCsacTelemetryLabels<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_csac_telemetry_labels_t *c_struct = reinterpret_cast<const msg_csac_telemetry_labels_t*>(buffer);
  const sbp::MsgCsacTelemetryLabels<> *cpp_struct = reinterpret_cast<const sbp::MsgCsacTelemetryLabels<>*>(buffer);

//
//  EXPECT_EQ(c_struct->id, cpp_struct->id);
//
//  EXPECT_EQ(c_struct->telemetry_labels, cpp_struct->telemetry_labels);
//
}

TEST(test_msg_ins_updates, default_construction) {
  sbp::MsgInsUpdates variable;
  (void) variable;
}

TEST(test_msg_ins_updates, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgInsUpdates);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_ins_updates_t *c_struct = reinterpret_cast<const msg_ins_updates_t*>(buffer);
  const sbp::MsgInsUpdates *cpp_struct = reinterpret_cast<const sbp::MsgInsUpdates*>(buffer);

//
//  EXPECT_EQ(c_struct->tow, cpp_struct->tow);
//
//  EXPECT_EQ(c_struct->gnsspos, cpp_struct->gnsspos);
//
//  EXPECT_EQ(c_struct->gnssvel, cpp_struct->gnssvel);
//
//  EXPECT_EQ(c_struct->wheelticks, cpp_struct->wheelticks);
//
//  EXPECT_EQ(c_struct->speed, cpp_struct->speed);
//
//  EXPECT_EQ(c_struct->nhc, cpp_struct->nhc);
//
//  EXPECT_EQ(c_struct->zerovel, cpp_struct->zerovel);
//
}

TEST(test_msg_gnss_time_offset, default_construction) {
  sbp::MsgGnssTimeOffset variable;
  (void) variable;
}

TEST(test_msg_gnss_time_offset, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgGnssTimeOffset);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_gnss_time_offset_t *c_struct = reinterpret_cast<const msg_gnss_time_offset_t*>(buffer);
  const sbp::MsgGnssTimeOffset *cpp_struct = reinterpret_cast<const sbp::MsgGnssTimeOffset*>(buffer);

//
//  EXPECT_EQ(c_struct->weeks, cpp_struct->weeks);
//
//  EXPECT_EQ(c_struct->milliseconds, cpp_struct->milliseconds);
//
//  EXPECT_EQ(c_struct->microseconds, cpp_struct->microseconds);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
}

TEST(test_msg_group_meta, default_construction) {
  sbp::MsgGroupMeta<> variable;
  (void) variable;
}

TEST(test_msg_group_meta, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgGroupMeta<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_group_meta_t *c_struct = reinterpret_cast<const msg_group_meta_t*>(buffer);
  const sbp::MsgGroupMeta<> *cpp_struct = reinterpret_cast<const sbp::MsgGroupMeta<>*>(buffer);

//
//  EXPECT_EQ(c_struct->group_id, cpp_struct->group_id);
//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
//  EXPECT_EQ(c_struct->n_group_msgs, cpp_struct->n_group_msgs);
//
//  EXPECT_EQ(c_struct->group_msgs, cpp_struct->group_msgs);
//
}
