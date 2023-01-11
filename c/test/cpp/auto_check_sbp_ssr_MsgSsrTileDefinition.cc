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
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_ssr_MsgSsrTileDefinition0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_ssr_tile_definition_t> {
 public:
  Test_auto_check_sbp_ssr_MsgSsrTileDefinition0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_ssr_tile_definition_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_ssr_tile_definition_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_ssr_tile_definition_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_ssr_MsgSsrTileDefinition0, Test) {
  uint8_t encoded_frame[] = {
      85, 248, 5, 0,   0, 33,  127, 58, 9,   0,   174, 8,   1,  2,
      3,  4,   0, 5,   0, 186, 28,  59, 167, 100, 0,   100, 0,  6,
      0,  6,   0, 210, 2, 150, 73,  0,  0,   0,   0,   204, 94,
  };

  sbp_msg_ssr_tile_definition_t test_msg{};
  test_msg.bitmask = 1234567890;
  test_msg.cols = 6;
  test_msg.corner_nw_lat = 7354;
  test_msg.corner_nw_lon = -22725;
  test_msg.iod_ssr = 3;
  test_msg.rows = 6;
  test_msg.sol_id = 2;
  test_msg.spacing_lat = 100;
  test_msg.spacing_lon = 100;
  test_msg.tile_id = 5;
  test_msg.tile_set_id = 4;
  test_msg.time.tow = 604799;
  test_msg.time.wn = 2222;
  test_msg.update_interval = 1;

  EXPECT_EQ(send_message(0, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 0);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.bitmask, 1234567890)
      << "incorrect value for last_msg_.bitmask, expected 1234567890, is "
      << last_msg_.bitmask;
  EXPECT_EQ(last_msg_.cols, 6)
      << "incorrect value for last_msg_.cols, expected 6, is "
      << last_msg_.cols;
  EXPECT_EQ(last_msg_.corner_nw_lat, 7354)
      << "incorrect value for last_msg_.corner_nw_lat, expected 7354, is "
      << last_msg_.corner_nw_lat;
  EXPECT_EQ(last_msg_.corner_nw_lon, -22725)
      << "incorrect value for last_msg_.corner_nw_lon, expected -22725, is "
      << last_msg_.corner_nw_lon;
  EXPECT_EQ(last_msg_.iod_ssr, 3)
      << "incorrect value for last_msg_.iod_ssr, expected 3, is "
      << last_msg_.iod_ssr;
  EXPECT_EQ(last_msg_.rows, 6)
      << "incorrect value for last_msg_.rows, expected 6, is "
      << last_msg_.rows;
  EXPECT_EQ(last_msg_.sol_id, 2)
      << "incorrect value for last_msg_.sol_id, expected 2, is "
      << last_msg_.sol_id;
  EXPECT_EQ(last_msg_.spacing_lat, 100)
      << "incorrect value for last_msg_.spacing_lat, expected 100, is "
      << last_msg_.spacing_lat;
  EXPECT_EQ(last_msg_.spacing_lon, 100)
      << "incorrect value for last_msg_.spacing_lon, expected 100, is "
      << last_msg_.spacing_lon;
  EXPECT_EQ(last_msg_.tile_id, 5)
      << "incorrect value for last_msg_.tile_id, expected 5, is "
      << last_msg_.tile_id;
  EXPECT_EQ(last_msg_.tile_set_id, 4)
      << "incorrect value for last_msg_.tile_set_id, expected 4, is "
      << last_msg_.tile_set_id;
  EXPECT_EQ(last_msg_.time.tow, 604799)
      << "incorrect value for last_msg_.time.tow, expected 604799, is "
      << last_msg_.time.tow;
  EXPECT_EQ(last_msg_.time.wn, 2222)
      << "incorrect value for last_msg_.time.wn, expected 2222, is "
      << last_msg_.time.wn;
  EXPECT_EQ(last_msg_.update_interval, 1)
      << "incorrect value for last_msg_.update_interval, expected 1, is "
      << last_msg_.update_interval;
}
