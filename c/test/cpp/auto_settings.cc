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
#include <libsbp/settings.h>
#include <libsbp/cpp/settings.h>
#include <libsbp/settings.h>
#include <libsbp/cpp/settings.h>
#include <libsbp/settings.h>
#include <libsbp/cpp/settings.h>
#include <libsbp/settings.h>
#include <libsbp/cpp/settings.h>
#include <libsbp/settings.h>
#include <libsbp/cpp/settings.h>
#include <libsbp/settings.h>
#include <libsbp/cpp/settings.h>
#include <libsbp/settings.h>
#include <libsbp/cpp/settings.h>
#include <libsbp/settings.h>
#include <libsbp/cpp/settings.h>
#include <libsbp/settings.h>
#include <libsbp/cpp/settings.h>
#include <libsbp/settings.h>
#include <libsbp/cpp/settings.h>


TEST(test_msg_settings_write, default_construction) {
  sbp::MsgSettingsWrite<> variable;
  (void) variable;
}

TEST(test_msg_settings_write, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSettingsWrite<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_settings_write_t *c_struct = reinterpret_cast<const msg_settings_write_t*>(buffer);
  const sbp::MsgSettingsWrite<> *cpp_struct = reinterpret_cast<const sbp::MsgSettingsWrite<>*>(buffer);

//
//  EXPECT_EQ(c_struct->setting, cpp_struct->setting);
//
}

TEST(test_msg_settings_write_resp, default_construction) {
  sbp::MsgSettingsWriteResp<> variable;
  (void) variable;
}

TEST(test_msg_settings_write_resp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSettingsWriteResp<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_settings_write_resp_t *c_struct = reinterpret_cast<const msg_settings_write_resp_t*>(buffer);
  const sbp::MsgSettingsWriteResp<> *cpp_struct = reinterpret_cast<const sbp::MsgSettingsWriteResp<>*>(buffer);

//
//  EXPECT_EQ(c_struct->status, cpp_struct->status);
//
//  EXPECT_EQ(c_struct->setting, cpp_struct->setting);
//
}

TEST(test_msg_settings_read_req, default_construction) {
  sbp::MsgSettingsReadReq<> variable;
  (void) variable;
}

TEST(test_msg_settings_read_req, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSettingsReadReq<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_settings_read_req_t *c_struct = reinterpret_cast<const msg_settings_read_req_t*>(buffer);
  const sbp::MsgSettingsReadReq<> *cpp_struct = reinterpret_cast<const sbp::MsgSettingsReadReq<>*>(buffer);

//
//  EXPECT_EQ(c_struct->setting, cpp_struct->setting);
//
}

TEST(test_msg_settings_read_resp, default_construction) {
  sbp::MsgSettingsReadResp<> variable;
  (void) variable;
}

TEST(test_msg_settings_read_resp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSettingsReadResp<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_settings_read_resp_t *c_struct = reinterpret_cast<const msg_settings_read_resp_t*>(buffer);
  const sbp::MsgSettingsReadResp<> *cpp_struct = reinterpret_cast<const sbp::MsgSettingsReadResp<>*>(buffer);

//
//  EXPECT_EQ(c_struct->setting, cpp_struct->setting);
//
}

TEST(test_msg_settings_read_by_index_req, default_construction) {
  sbp::MsgSettingsReadByIndexReq variable;
  (void) variable;
}

TEST(test_msg_settings_read_by_index_req, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSettingsReadByIndexReq);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_settings_read_by_index_req_t *c_struct = reinterpret_cast<const msg_settings_read_by_index_req_t*>(buffer);
  const sbp::MsgSettingsReadByIndexReq *cpp_struct = reinterpret_cast<const sbp::MsgSettingsReadByIndexReq*>(buffer);

//
//  EXPECT_EQ(c_struct->index, cpp_struct->index);
//
}

TEST(test_msg_settings_read_by_index_resp, default_construction) {
  sbp::MsgSettingsReadByIndexResp<> variable;
  (void) variable;
}

TEST(test_msg_settings_read_by_index_resp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSettingsReadByIndexResp<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_settings_read_by_index_resp_t *c_struct = reinterpret_cast<const msg_settings_read_by_index_resp_t*>(buffer);
  const sbp::MsgSettingsReadByIndexResp<> *cpp_struct = reinterpret_cast<const sbp::MsgSettingsReadByIndexResp<>*>(buffer);

//
//  EXPECT_EQ(c_struct->index, cpp_struct->index);
//
//  EXPECT_EQ(c_struct->setting, cpp_struct->setting);
//
}

TEST(test_msg_settings_register, default_construction) {
  sbp::MsgSettingsRegister<> variable;
  (void) variable;
}

TEST(test_msg_settings_register, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSettingsRegister<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_settings_register_t *c_struct = reinterpret_cast<const msg_settings_register_t*>(buffer);
  const sbp::MsgSettingsRegister<> *cpp_struct = reinterpret_cast<const sbp::MsgSettingsRegister<>*>(buffer);

//
//  EXPECT_EQ(c_struct->setting, cpp_struct->setting);
//
}

TEST(test_msg_settings_register_resp, default_construction) {
  sbp::MsgSettingsRegisterResp<> variable;
  (void) variable;
}

TEST(test_msg_settings_register_resp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgSettingsRegisterResp<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_settings_register_resp_t *c_struct = reinterpret_cast<const msg_settings_register_resp_t*>(buffer);
  const sbp::MsgSettingsRegisterResp<> *cpp_struct = reinterpret_cast<const sbp::MsgSettingsRegisterResp<>*>(buffer);

//
//  EXPECT_EQ(c_struct->status, cpp_struct->status);
//
//  EXPECT_EQ(c_struct->setting, cpp_struct->setting);
//
}
