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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEFCov.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_navigation_MsgVelECEFCov0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_vel_ecef_cov_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgVelECEFCov0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_vel_ecef_cov_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_vel_ecef_cov_t *>(last_msg_storage_)),
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
                      const msg_vel_ecef_cov_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_vel_ecef_cov_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgVelECEFCov0, Test) {
  uint8_t encoded_frame[] = {
      85, 21, 2, 66, 0, 42, 2,   0,  0,  0, 0,  0,  0,  0, 0,  0,   0,
      0,  6,  0, 0,  0, 0,  0,   0,  64, 0, 0,  0,  64, 0, 0,  0,   64,
      0,  0,  0, 64, 0, 0,  128, 63, 0,  0, 64, 64, 3,  4, 91, 254,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_vel_ecef_cov_t *test_msg = (msg_vel_ecef_cov_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cov_x_x = 2.0;
  test_msg->cov_x_y = 2.0;
  test_msg->cov_x_z = 2.0;
  test_msg->cov_y_y = 2.0;
  test_msg->cov_y_z = 1.0;
  test_msg->cov_z_z = 3.0;
  test_msg->flags = 4;
  test_msg->n_sats = 3;
  test_msg->tow = 2;
  test_msg->x = 0;
  test_msg->y = 0;
  test_msg->z = 6;

  EXPECT_EQ(send_message(0x215, 66, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->cov_x_x * 100 - 2.0 * 100), 0.05)
      << "incorrect value for cov_x_x, expected 2.0, is " << last_msg_->cov_x_x;
  EXPECT_LT((last_msg_->cov_x_y * 100 - 2.0 * 100), 0.05)
      << "incorrect value for cov_x_y, expected 2.0, is " << last_msg_->cov_x_y;
  EXPECT_LT((last_msg_->cov_x_z * 100 - 2.0 * 100), 0.05)
      << "incorrect value for cov_x_z, expected 2.0, is " << last_msg_->cov_x_z;
  EXPECT_LT((last_msg_->cov_y_y * 100 - 2.0 * 100), 0.05)
      << "incorrect value for cov_y_y, expected 2.0, is " << last_msg_->cov_y_y;
  EXPECT_LT((last_msg_->cov_y_z * 100 - 1.0 * 100), 0.05)
      << "incorrect value for cov_y_z, expected 1.0, is " << last_msg_->cov_y_z;
  EXPECT_LT((last_msg_->cov_z_z * 100 - 3.0 * 100), 0.05)
      << "incorrect value for cov_z_z, expected 3.0, is " << last_msg_->cov_z_z;
  EXPECT_EQ(last_msg_->flags, 4)
      << "incorrect value for flags, expected 4, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_sats, 3)
      << "incorrect value for n_sats, expected 3, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->tow, 2)
      << "incorrect value for tow, expected 2, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->x, 0)
      << "incorrect value for x, expected 0, is " << last_msg_->x;
  EXPECT_EQ(last_msg_->y, 0)
      << "incorrect value for y, expected 0, is " << last_msg_->y;
  EXPECT_EQ(last_msg_->z, 6)
      << "incorrect value for z, expected 6, is " << last_msg_->z;
}
