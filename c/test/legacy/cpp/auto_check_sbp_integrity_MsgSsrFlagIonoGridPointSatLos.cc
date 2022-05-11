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
// spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagIonoGridPointSatLos.yaml
// by generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_integrity_MsgSsrFlagIonoGridPointSatLos0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_flag_iono_grid_point_sat_los_t> {
 public:
  Test_legacy_auto_check_sbp_integrity_MsgSsrFlagIonoGridPointSatLos0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_flag_iono_grid_point_sat_los_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ssr_flag_iono_grid_point_sat_los_t *>(
            last_msg_storage_)),
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
  void handle_sbp_msg(
      uint16_t sender_id, uint8_t message_length,
      const msg_ssr_flag_iono_grid_point_sat_los_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_flag_iono_grid_point_sat_los_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_integrity_MsgSsrFlagIonoGridPointSatLos0,
       Test) {
  uint8_t encoded_frame[] = {
      85, 209, 11, 66, 0, 21, 180, 0, 0,  0,  3,  0,  1,  2,   3,
      4,  0,   5,  0,  6, 30, 0,   2, 10, 11, 15, 14, 98, 148,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_flag_iono_grid_point_sat_los_t *test_msg =
      (msg_ssr_flag_iono_grid_point_sat_los_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->faulty_los) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->faulty_los[0]));
  }
  test_msg->faulty_los[0].constellation = 11;
  test_msg->faulty_los[0].satId = 10;
  if (sizeof(test_msg->faulty_los) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->faulty_los[0]));
  }
  test_msg->faulty_los[1].constellation = 14;
  test_msg->faulty_los[1].satId = 15;
  test_msg->grid_point_id = 30;
  test_msg->header.chain_id = 6;
  test_msg->header.num_msgs = 1;
  test_msg->header.obs_time.tow = 180;
  test_msg->header.obs_time.wn = 3;
  test_msg->header.seq_num = 2;
  test_msg->header.ssr_sol_id = 3;
  test_msg->header.tile_id = 5;
  test_msg->header.tile_set_id = 4;
  test_msg->n_faulty_los = 2;

  EXPECT_EQ(send_message(3025, 66, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->faulty_los[0].constellation, 11)
      << "incorrect value for faulty_los[0].constellation, expected 11, is "
      << last_msg_->faulty_los[0].constellation;
  EXPECT_EQ(last_msg_->faulty_los[0].satId, 10)
      << "incorrect value for faulty_los[0].satId, expected 10, is "
      << last_msg_->faulty_los[0].satId;
  EXPECT_EQ(last_msg_->faulty_los[1].constellation, 14)
      << "incorrect value for faulty_los[1].constellation, expected 14, is "
      << last_msg_->faulty_los[1].constellation;
  EXPECT_EQ(last_msg_->faulty_los[1].satId, 15)
      << "incorrect value for faulty_los[1].satId, expected 15, is "
      << last_msg_->faulty_los[1].satId;
  EXPECT_EQ(last_msg_->grid_point_id, 30)
      << "incorrect value for grid_point_id, expected 30, is "
      << last_msg_->grid_point_id;
  EXPECT_EQ(last_msg_->header.chain_id, 6)
      << "incorrect value for header.chain_id, expected 6, is "
      << last_msg_->header.chain_id;
  EXPECT_EQ(last_msg_->header.num_msgs, 1)
      << "incorrect value for header.num_msgs, expected 1, is "
      << last_msg_->header.num_msgs;
  EXPECT_EQ(last_msg_->header.obs_time.tow, 180)
      << "incorrect value for header.obs_time.tow, expected 180, is "
      << last_msg_->header.obs_time.tow;
  EXPECT_EQ(last_msg_->header.obs_time.wn, 3)
      << "incorrect value for header.obs_time.wn, expected 3, is "
      << last_msg_->header.obs_time.wn;
  EXPECT_EQ(last_msg_->header.seq_num, 2)
      << "incorrect value for header.seq_num, expected 2, is "
      << last_msg_->header.seq_num;
  EXPECT_EQ(last_msg_->header.ssr_sol_id, 3)
      << "incorrect value for header.ssr_sol_id, expected 3, is "
      << last_msg_->header.ssr_sol_id;
  EXPECT_EQ(last_msg_->header.tile_id, 5)
      << "incorrect value for header.tile_id, expected 5, is "
      << last_msg_->header.tile_id;
  EXPECT_EQ(last_msg_->header.tile_set_id, 4)
      << "incorrect value for header.tile_set_id, expected 4, is "
      << last_msg_->header.tile_set_id;
  EXPECT_EQ(last_msg_->n_faulty_los, 2)
      << "incorrect value for n_faulty_los, expected 2, is "
      << last_msg_->n_faulty_los;
}
