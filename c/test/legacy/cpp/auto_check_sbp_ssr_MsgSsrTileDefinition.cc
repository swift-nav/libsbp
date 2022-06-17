/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrTileDefinition.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_ssr_MsgSsrTileDefinition0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_tile_definition_t> {
 public:
  Test_legacy_auto_check_sbp_ssr_MsgSsrTileDefinition0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_tile_definition_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_ssr_tile_definition_t *>(last_msg_storage_)),
        last_msg_len_(),
        last_sender_id_(),
        n_callbacks_logged_(),
        dummy_wr_(),
        dummy_rd_(),
        dummy_buff_() {
    set_reader(this);
    set_writer(this);
  }

  s32 read(uint8_t *buf, const uint32_t n) override {
    uint32_t real_n = n;
    memcpy(buf, dummy_buff_ + dummy_rd_, real_n);
    dummy_rd_ += real_n;
    return (s32)real_n;
  }

  s32 write(const uint8_t *buf, uint32_t n) override {
    uint32_t real_n = n;
    memcpy(dummy_buff_ + dummy_wr_, buf, real_n);
    dummy_wr_ += real_n;
    return (s32)real_n;
  }

 protected:
  void handle_sbp_msg(uint16_t sender_id, uint8_t message_length,
                      const msg_ssr_tile_definition_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_tile_definition_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ssr_MsgSsrTileDefinition0, Test) {
  uint8_t encoded_frame[] = {
      85, 247, 5, 66, 0, 25,  31,  0, 1,   0,  2, 0, 4, 0, 8,   0,  16,
      0,  32,  0, 64, 0, 128, 210, 2, 150, 73, 0, 0, 0, 0, 214, 71,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_tile_definition_t *test_msg =
      (msg_ssr_tile_definition_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->bitmask = 1234567890;
  test_msg->cols = 32768;
  test_msg->corner_nw_lat = 1024;
  test_msg->corner_nw_lon = 2048;
  test_msg->rows = 16384;
  test_msg->spacing_lat = 4096;
  test_msg->spacing_lon = 8192;
  test_msg->ssr_sol_id = 31;
  test_msg->tile_id = 512;
  test_msg->tile_set_id = 256;

  EXPECT_EQ(send_message(1527, 66, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->bitmask, 1234567890)
      << "incorrect value for bitmask, expected 1234567890, is "
      << last_msg_->bitmask;
  EXPECT_EQ(last_msg_->cols, 32768)
      << "incorrect value for cols, expected 32768, is " << last_msg_->cols;
  EXPECT_EQ(last_msg_->corner_nw_lat, 1024)
      << "incorrect value for corner_nw_lat, expected 1024, is "
      << last_msg_->corner_nw_lat;
  EXPECT_EQ(last_msg_->corner_nw_lon, 2048)
      << "incorrect value for corner_nw_lon, expected 2048, is "
      << last_msg_->corner_nw_lon;
  EXPECT_EQ(last_msg_->rows, 16384)
      << "incorrect value for rows, expected 16384, is " << last_msg_->rows;
  EXPECT_EQ(last_msg_->spacing_lat, 4096)
      << "incorrect value for spacing_lat, expected 4096, is "
      << last_msg_->spacing_lat;
  EXPECT_EQ(last_msg_->spacing_lon, 8192)
      << "incorrect value for spacing_lon, expected 8192, is "
      << last_msg_->spacing_lon;
  EXPECT_EQ(last_msg_->ssr_sol_id, 31)
      << "incorrect value for ssr_sol_id, expected 31, is "
      << last_msg_->ssr_sol_id;
  EXPECT_EQ(last_msg_->tile_id, 512)
      << "incorrect value for tile_id, expected 512, is " << last_msg_->tile_id;
  EXPECT_EQ(last_msg_->tile_set_id, 256)
      << "incorrect value for tile_set_id, expected 256, is "
      << last_msg_->tile_set_id;
}
