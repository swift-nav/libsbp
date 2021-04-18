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
#include <libsbp/file_io.h>
#include <libsbp/cpp/file_io.h>
#include <libsbp/file_io.h>
#include <libsbp/cpp/file_io.h>
#include <libsbp/file_io.h>
#include <libsbp/cpp/file_io.h>
#include <libsbp/file_io.h>
#include <libsbp/cpp/file_io.h>
#include <libsbp/file_io.h>
#include <libsbp/cpp/file_io.h>
#include <libsbp/file_io.h>
#include <libsbp/cpp/file_io.h>
#include <libsbp/file_io.h>
#include <libsbp/cpp/file_io.h>
#include <libsbp/file_io.h>
#include <libsbp/cpp/file_io.h>
#include <libsbp/file_io.h>
#include <libsbp/cpp/file_io.h>


TEST(test_msg_fileio_read_req, default_construction) {
  sbp::MsgFileioReadReq<> variable;
  (void) variable;
}

TEST(test_msg_fileio_read_req, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFileioReadReq<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_fileio_read_req_t *c_struct = reinterpret_cast<const msg_fileio_read_req_t*>(buffer);
  const sbp::MsgFileioReadReq<> *cpp_struct = reinterpret_cast<const sbp::MsgFileioReadReq<>*>(buffer);

//
//  EXPECT_EQ(c_struct->sequence, cpp_struct->sequence);
//
//  EXPECT_EQ(c_struct->offset, cpp_struct->offset);
//
//  EXPECT_EQ(c_struct->chunk_size, cpp_struct->chunk_size);
//
//  EXPECT_EQ(c_struct->filename, cpp_struct->filename);
//
}

TEST(test_msg_fileio_read_resp, default_construction) {
  sbp::MsgFileioReadResp<> variable;
  (void) variable;
}

TEST(test_msg_fileio_read_resp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFileioReadResp<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_fileio_read_resp_t *c_struct = reinterpret_cast<const msg_fileio_read_resp_t*>(buffer);
  const sbp::MsgFileioReadResp<> *cpp_struct = reinterpret_cast<const sbp::MsgFileioReadResp<>*>(buffer);

//
//  EXPECT_EQ(c_struct->sequence, cpp_struct->sequence);
//
//  EXPECT_EQ(c_struct->contents, cpp_struct->contents);
//
}

TEST(test_msg_fileio_read_dir_req, default_construction) {
  sbp::MsgFileioReadDirReq<> variable;
  (void) variable;
}

TEST(test_msg_fileio_read_dir_req, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFileioReadDirReq<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_fileio_read_dir_req_t *c_struct = reinterpret_cast<const msg_fileio_read_dir_req_t*>(buffer);
  const sbp::MsgFileioReadDirReq<> *cpp_struct = reinterpret_cast<const sbp::MsgFileioReadDirReq<>*>(buffer);

//
//  EXPECT_EQ(c_struct->sequence, cpp_struct->sequence);
//
//  EXPECT_EQ(c_struct->offset, cpp_struct->offset);
//
//  EXPECT_EQ(c_struct->dirname, cpp_struct->dirname);
//
}

TEST(test_msg_fileio_read_dir_resp, default_construction) {
  sbp::MsgFileioReadDirResp<> variable;
  (void) variable;
}

TEST(test_msg_fileio_read_dir_resp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFileioReadDirResp<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_fileio_read_dir_resp_t *c_struct = reinterpret_cast<const msg_fileio_read_dir_resp_t*>(buffer);
  const sbp::MsgFileioReadDirResp<> *cpp_struct = reinterpret_cast<const sbp::MsgFileioReadDirResp<>*>(buffer);

//
//  EXPECT_EQ(c_struct->sequence, cpp_struct->sequence);
//
//  EXPECT_EQ(c_struct->contents, cpp_struct->contents);
//
}

TEST(test_msg_fileio_remove, default_construction) {
  sbp::MsgFileioRemove<> variable;
  (void) variable;
}

TEST(test_msg_fileio_remove, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFileioRemove<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_fileio_remove_t *c_struct = reinterpret_cast<const msg_fileio_remove_t*>(buffer);
  const sbp::MsgFileioRemove<> *cpp_struct = reinterpret_cast<const sbp::MsgFileioRemove<>*>(buffer);

//
//  EXPECT_EQ(c_struct->filename, cpp_struct->filename);
//
}

TEST(test_msg_fileio_write_resp, default_construction) {
  sbp::MsgFileioWriteResp variable;
  (void) variable;
}

TEST(test_msg_fileio_write_resp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFileioWriteResp);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_fileio_write_resp_t *c_struct = reinterpret_cast<const msg_fileio_write_resp_t*>(buffer);
  const sbp::MsgFileioWriteResp *cpp_struct = reinterpret_cast<const sbp::MsgFileioWriteResp*>(buffer);

//
//  EXPECT_EQ(c_struct->sequence, cpp_struct->sequence);
//
}

TEST(test_msg_fileio_config_req, default_construction) {
  sbp::MsgFileioConfigReq variable;
  (void) variable;
}

TEST(test_msg_fileio_config_req, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFileioConfigReq);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_fileio_config_req_t *c_struct = reinterpret_cast<const msg_fileio_config_req_t*>(buffer);
  const sbp::MsgFileioConfigReq *cpp_struct = reinterpret_cast<const sbp::MsgFileioConfigReq*>(buffer);

//
//  EXPECT_EQ(c_struct->sequence, cpp_struct->sequence);
//
}

TEST(test_msg_fileio_config_resp, default_construction) {
  sbp::MsgFileioConfigResp variable;
  (void) variable;
}

TEST(test_msg_fileio_config_resp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFileioConfigResp);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_fileio_config_resp_t *c_struct = reinterpret_cast<const msg_fileio_config_resp_t*>(buffer);
  const sbp::MsgFileioConfigResp *cpp_struct = reinterpret_cast<const sbp::MsgFileioConfigResp*>(buffer);

//
//  EXPECT_EQ(c_struct->sequence, cpp_struct->sequence);
//
//  EXPECT_EQ(c_struct->window_size, cpp_struct->window_size);
//
//  EXPECT_EQ(c_struct->batch_size, cpp_struct->batch_size);
//
//  EXPECT_EQ(c_struct->fileio_version, cpp_struct->fileio_version);
//
}
