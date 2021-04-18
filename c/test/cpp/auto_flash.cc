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
#include <libsbp/flash.h>
#include <libsbp/cpp/flash.h>
#include <libsbp/flash.h>
#include <libsbp/cpp/flash.h>
#include <libsbp/flash.h>
#include <libsbp/cpp/flash.h>
#include <libsbp/flash.h>
#include <libsbp/cpp/flash.h>
#include <libsbp/flash.h>
#include <libsbp/cpp/flash.h>
#include <libsbp/flash.h>
#include <libsbp/cpp/flash.h>
#include <libsbp/flash.h>
#include <libsbp/cpp/flash.h>
#include <libsbp/flash.h>
#include <libsbp/cpp/flash.h>
#include <libsbp/flash.h>
#include <libsbp/cpp/flash.h>
#include <libsbp/flash.h>
#include <libsbp/cpp/flash.h>


TEST(test_msg_flash_program, default_construction) {
  sbp::MsgFlashProgram<> variable;
  (void) variable;
}

TEST(test_msg_flash_program, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFlashProgram<>);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_flash_program_t *c_struct = reinterpret_cast<const msg_flash_program_t*>(buffer);
  const sbp::MsgFlashProgram<> *cpp_struct = reinterpret_cast<const sbp::MsgFlashProgram<>*>(buffer);

//
//  EXPECT_EQ(c_struct->target, cpp_struct->target);
//
//  EXPECT_EQ(c_struct->addr_start, cpp_struct->addr_start);
//
//  EXPECT_EQ(c_struct->addr_len, cpp_struct->addr_len);
//
//  EXPECT_EQ(c_struct->data, cpp_struct->data);
//
}

TEST(test_msg_flash_done, default_construction) {
  sbp::MsgFlashDone variable;
  (void) variable;
}

TEST(test_msg_flash_done, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFlashDone);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_flash_done_t *c_struct = reinterpret_cast<const msg_flash_done_t*>(buffer);
  const sbp::MsgFlashDone *cpp_struct = reinterpret_cast<const sbp::MsgFlashDone*>(buffer);

//
//  EXPECT_EQ(c_struct->response, cpp_struct->response);
//
}

TEST(test_msg_flash_read_req, default_construction) {
  sbp::MsgFlashReadReq variable;
  (void) variable;
}

TEST(test_msg_flash_read_req, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFlashReadReq);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_flash_read_req_t *c_struct = reinterpret_cast<const msg_flash_read_req_t*>(buffer);
  const sbp::MsgFlashReadReq *cpp_struct = reinterpret_cast<const sbp::MsgFlashReadReq*>(buffer);

//
//  EXPECT_EQ(c_struct->target, cpp_struct->target);
//
//  EXPECT_EQ(c_struct->addr_start, cpp_struct->addr_start);
//
//  EXPECT_EQ(c_struct->addr_len, cpp_struct->addr_len);
//
}

TEST(test_msg_flash_read_resp, default_construction) {
  sbp::MsgFlashReadResp variable;
  (void) variable;
}

TEST(test_msg_flash_read_resp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFlashReadResp);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_flash_read_resp_t *c_struct = reinterpret_cast<const msg_flash_read_resp_t*>(buffer);
  const sbp::MsgFlashReadResp *cpp_struct = reinterpret_cast<const sbp::MsgFlashReadResp*>(buffer);

//
//  EXPECT_EQ(c_struct->target, cpp_struct->target);
//
//  EXPECT_EQ(c_struct->addr_start, cpp_struct->addr_start);
//
//  EXPECT_EQ(c_struct->addr_len, cpp_struct->addr_len);
//
}

TEST(test_msg_flash_erase, default_construction) {
  sbp::MsgFlashErase variable;
  (void) variable;
}

TEST(test_msg_flash_erase, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgFlashErase);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_flash_erase_t *c_struct = reinterpret_cast<const msg_flash_erase_t*>(buffer);
  const sbp::MsgFlashErase *cpp_struct = reinterpret_cast<const sbp::MsgFlashErase*>(buffer);

//
//  EXPECT_EQ(c_struct->target, cpp_struct->target);
//
//  EXPECT_EQ(c_struct->sector_num, cpp_struct->sector_num);
//
}

TEST(test_msg_stm_flash_lock_sector, default_construction) {
  sbp::MsgStmFlashLockSector variable;
  (void) variable;
}

TEST(test_msg_stm_flash_lock_sector, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgStmFlashLockSector);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_stm_flash_lock_sector_t *c_struct = reinterpret_cast<const msg_stm_flash_lock_sector_t*>(buffer);
  const sbp::MsgStmFlashLockSector *cpp_struct = reinterpret_cast<const sbp::MsgStmFlashLockSector*>(buffer);

//
//  EXPECT_EQ(c_struct->sector, cpp_struct->sector);
//
}

TEST(test_msg_stm_flash_unlock_sector, default_construction) {
  sbp::MsgStmFlashUnlockSector variable;
  (void) variable;
}

TEST(test_msg_stm_flash_unlock_sector, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgStmFlashUnlockSector);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_stm_flash_unlock_sector_t *c_struct = reinterpret_cast<const msg_stm_flash_unlock_sector_t*>(buffer);
  const sbp::MsgStmFlashUnlockSector *cpp_struct = reinterpret_cast<const sbp::MsgStmFlashUnlockSector*>(buffer);

//
//  EXPECT_EQ(c_struct->sector, cpp_struct->sector);
//
}

TEST(test_msg_stm_unique_id_resp, default_construction) {
  sbp::MsgStmUniqueIdResp variable;
  (void) variable;
}

TEST(test_msg_stm_unique_id_resp, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgStmUniqueIdResp);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_stm_unique_id_resp_t *c_struct = reinterpret_cast<const msg_stm_unique_id_resp_t*>(buffer);
  const sbp::MsgStmUniqueIdResp *cpp_struct = reinterpret_cast<const sbp::MsgStmUniqueIdResp*>(buffer);

//
//  EXPECT_EQ(c_struct->stm_id, cpp_struct->stm_id);
//
}

TEST(test_msg_m25_flash_write_status, default_construction) {
  sbp::MsgM25FlashWriteStatus variable;
  (void) variable;
}

TEST(test_msg_m25_flash_write_status, reinterpret_from_c) {
  srand(static_cast<unsigned int>(time(nullptr)));
  constexpr size_t kBufferSize = sizeof(sbp::MsgM25FlashWriteStatus);

  alignas(alignof(std::max_align_t)) uint8_t buffer[kBufferSize];
  for(size_t i = 0; i < kBufferSize; ++i) {
    buffer[i] = static_cast<uint8_t>(rand() % 256);
  }

  const msg_m25_flash_write_status_t *c_struct = reinterpret_cast<const msg_m25_flash_write_status_t*>(buffer);
  const sbp::MsgM25FlashWriteStatus *cpp_struct = reinterpret_cast<const sbp::MsgM25FlashWriteStatus*>(buffer);

//
//  EXPECT_EQ(c_struct->status, cpp_struct->status);
//
}
