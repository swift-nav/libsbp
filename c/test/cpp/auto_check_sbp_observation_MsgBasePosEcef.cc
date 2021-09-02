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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgBasePosEcef.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_observation_MsgBasePosEcef0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_base_pos_ecef_t> {
 public:
  Test_auto_check_sbp_observation_MsgBasePosEcef0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_base_pos_ecef_t>(this),
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
                      const sbp_msg_base_pos_ecef_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_base_pos_ecef_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_observation_MsgBasePosEcef0, Test) {
  uint8_t encoded_frame[] = {
      85,  72,  0,   0,   0,  24,  228, 131, 158, 245, 87,
      205, 68,  193, 66,  62, 232, 209, 32,  118, 80,  193,
      213, 231, 106, 251, 63, 20,  77,  65,  194, 125,
  };

  sbp_msg_base_pos_ecef_t test_msg{};
  test_msg.x = -2726575.9189;
  test_msg.y = -4315267.2798;
  test_msg.z = 3811455.9642;

  EXPECT_EQ(send_message(0, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 0);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.x * 100 - -2726575.9189 * 100), 0.05)
      << "incorrect value for last_msg_.x, expected -2726575.9189, is "
      << last_msg_.x;
  EXPECT_LT((last_msg_.y * 100 - -4315267.2798 * 100), 0.05)
      << "incorrect value for last_msg_.y, expected -4315267.2798, is "
      << last_msg_.y;
  EXPECT_LT((last_msg_.z * 100 - 3811455.9642 * 100), 0.05)
      << "incorrect value for last_msg_.z, expected 3811455.9642, is "
      << last_msg_.z;
}
