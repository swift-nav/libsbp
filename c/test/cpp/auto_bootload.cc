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
#include <libsbp/bootload.h>
#include <libsbp/cpp/bootload.h>
#include <libsbp/bootload.h>
#include <libsbp/cpp/bootload.h>
#include <libsbp/bootload.h>
#include <libsbp/cpp/bootload.h>
#include <libsbp/bootload.h>
#include <libsbp/cpp/bootload.h>
#include <libsbp/bootload.h>
#include <libsbp/cpp/bootload.h>
#include <libsbp/bootload.h>
#include <libsbp/cpp/bootload.h>


TEST(test_msg_bootloader_handshake_resp, default_construction) {
  sbp::MsgBootloaderHandshakeResp<> variable;
  (void) variable;
}

TEST(test_msg_bootloader_handshake_resp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgBootloaderHandshakeResp<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_bootloader_handshake_resp_t *c_struct = reinterpret_cast<const msg_bootloader_handshake_resp_t*>(buffer);
  const sbp::MsgBootloaderHandshakeResp<> *cpp_struct = reinterpret_cast<const sbp::MsgBootloaderHandshakeResp<>*>(buffer);

//
//  EXPECT_EQ(c_struct->flags, cpp_struct->flags);
//
//  EXPECT_EQ(c_struct->version, cpp_struct->version);
//
}

TEST(test_msg_bootloader_jump_to_app, default_construction) {
  sbp::MsgBootloaderJumpToApp variable;
  (void) variable;
}

TEST(test_msg_bootloader_jump_to_app, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgBootloaderJumpToApp);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_bootloader_jump_to_app_t *c_struct = reinterpret_cast<const msg_bootloader_jump_to_app_t*>(buffer);
  const sbp::MsgBootloaderJumpToApp *cpp_struct = reinterpret_cast<const sbp::MsgBootloaderJumpToApp*>(buffer);

//
//  EXPECT_EQ(c_struct->jump, cpp_struct->jump);
//
}

TEST(test_msg_nap_device_dna_resp, default_construction) {
  sbp::MsgNapDeviceDnaResp variable;
  (void) variable;
}

TEST(test_msg_nap_device_dna_resp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgNapDeviceDnaResp);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_nap_device_dna_resp_t *c_struct = reinterpret_cast<const msg_nap_device_dna_resp_t*>(buffer);
  const sbp::MsgNapDeviceDnaResp *cpp_struct = reinterpret_cast<const sbp::MsgNapDeviceDnaResp*>(buffer);

//
//  EXPECT_EQ(c_struct->dna, cpp_struct->dna);
//
}

TEST(test_msg_bootloader_handshake_dep_a, default_construction) {
  sbp::MsgBootloaderHandshakeDepA<> variable;
  (void) variable;
}

TEST(test_msg_bootloader_handshake_dep_a, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgBootloaderHandshakeDepA<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_bootloader_handshake_dep_a_t *c_struct = reinterpret_cast<const msg_bootloader_handshake_dep_a_t*>(buffer);
  const sbp::MsgBootloaderHandshakeDepA<> *cpp_struct = reinterpret_cast<const sbp::MsgBootloaderHandshakeDepA<>*>(buffer);

//
//  EXPECT_EQ(c_struct->handshake, cpp_struct->handshake);
//
}
