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
// spec/tests/yaml/swiftnav/sbp/skylark/test_MsgAcknowledge.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_skylark_MsgAcknowledge0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_acknowledge_t> {
 public:
  Test_auto_check_sbp_skylark_MsgAcknowledge0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_acknowledge_t>(this),
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
                      const sbp_msg_acknowledge_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acknowledge_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_skylark_MsgAcknowledge0, Test) {
  uint8_t encoded_frame[] = {
      85, 160, 15, 42, 0, 11, 30, 64, 226, 1, 0, 0, 1, 0, 1, 0, 2, 187, 128,
  };

  sbp_msg_acknowledge_t test_msg{};
  test_msg.area_id = 123456;
  test_msg.correction_mask_on_demand = 1;
  test_msg.correction_mask_stream = 1;
  test_msg.request_counter = 30;
  test_msg.response_code = 0;
  test_msg.solution_id = 2;

  EXPECT_EQ(send_message(42, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 42);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.area_id, 123456)
      << "incorrect value for last_msg_.area_id, expected 123456, is "
      << last_msg_.area_id;
  EXPECT_EQ(last_msg_.correction_mask_on_demand, 1)
      << "incorrect value for last_msg_.correction_mask_on_demand, expected 1, "
         "is "
      << last_msg_.correction_mask_on_demand;
  EXPECT_EQ(last_msg_.correction_mask_stream, 1)
      << "incorrect value for last_msg_.correction_mask_stream, expected 1, is "
      << last_msg_.correction_mask_stream;
  EXPECT_EQ(last_msg_.request_counter, 30)
      << "incorrect value for last_msg_.request_counter, expected 30, is "
      << last_msg_.request_counter;
  EXPECT_EQ(last_msg_.response_code, 0)
      << "incorrect value for last_msg_.response_code, expected 0, is "
      << last_msg_.response_code;
  EXPECT_EQ(last_msg_.solution_id, 2)
      << "incorrect value for last_msg_.solution_id, expected 2, is "
      << last_msg_.solution_id;
}
