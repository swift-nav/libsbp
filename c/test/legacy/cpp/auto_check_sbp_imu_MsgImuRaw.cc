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
// spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuRaw.yaml by generate.py. Do not
// modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_imu_MsgImuRaw0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_imu_raw_t> {
 public:
  Test_legacy_auto_check_sbp_imu_MsgImuRaw0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_imu_raw_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_imu_raw_t *>(last_msg_storage_)),
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
                      const msg_imu_raw_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_imu_raw_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_imu_MsgImuRaw0, Test) {
  uint8_t encoded_frame[] = {
      85,  0,   9,  52, 18, 17, 26,  1,   0,   192, 206, 96,  0,
      223, 255, 44, 16, 60, 0,  208, 254, 238, 255, 70,  135,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_imu_raw_t *test_msg = (msg_imu_raw_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->acc_x = 96;
  test_msg->acc_y = -33;
  test_msg->acc_z = 4140;
  test_msg->gyr_x = 60;
  test_msg->gyr_y = -304;
  test_msg->gyr_z = -18;
  test_msg->tow = 3221225754;
  test_msg->tow_f = 206;

  EXPECT_EQ(send_message(0x900, 4660, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 4660);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->acc_x, 96)
      << "incorrect value for acc_x, expected 96, is " << last_msg_->acc_x;
  EXPECT_EQ(last_msg_->acc_y, -33)
      << "incorrect value for acc_y, expected -33, is " << last_msg_->acc_y;
  EXPECT_EQ(last_msg_->acc_z, 4140)
      << "incorrect value for acc_z, expected 4140, is " << last_msg_->acc_z;
  EXPECT_EQ(last_msg_->gyr_x, 60)
      << "incorrect value for gyr_x, expected 60, is " << last_msg_->gyr_x;
  EXPECT_EQ(last_msg_->gyr_y, -304)
      << "incorrect value for gyr_y, expected -304, is " << last_msg_->gyr_y;
  EXPECT_EQ(last_msg_->gyr_z, -18)
      << "incorrect value for gyr_z, expected -18, is " << last_msg_->gyr_z;
  EXPECT_EQ(last_msg_->tow, 3221225754)
      << "incorrect value for tow, expected 3221225754, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->tow_f, 206)
      << "incorrect value for tow_f, expected 206, is " << last_msg_->tow_f;
}
