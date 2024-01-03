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
// spec/tests/yaml/swiftnav/sbp/profiling/test_MsgMeasurementPoint.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>

#include <libsbp/common.h>

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/cpp/legacy_state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/profiling.h>
class Test_legacy_auto_check_sbp_profiling_MsgMeasurementPoint0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_measurement_point_t> {
 public:
  Test_legacy_auto_check_sbp_profiling_MsgMeasurementPoint0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_measurement_point_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_measurement_point_t *>(last_msg_storage_)),
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
                      const msg_measurement_point_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_measurement_point_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_profiling_MsgMeasurementPoint0, Test) {
  uint8_t encoded_frame[] = {
      85, 0,   207, 0,   16,  48,  250, 7,   0,   0,   180, 0,  2,   0,
      0,  0,   40,  0,   0,   0,   130, 201, 148, 141, 97,  85, 0,   0,
      18, 130, 201, 148, 0,   0,   0,   0,   66,  64,  157, 15, 0,   0,
      0,  0,   18,  0,   114, 111, 117, 116, 101, 40,  41,  0,  212, 165,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_measurement_point_t *test_msg =
      (msg_measurement_point_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  {
    const char assign_string[] = {(char)114, (char)111, (char)117, (char)116,
                                  (char)101, (char)40,  (char)41,  (char)0};
    memcpy(test_msg->func, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->func) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->id = 2496234002;
  test_msg->line = 18;
  test_msg->max = 40;
  test_msg->min = 2;
  test_msg->num_executions = 180;
  test_msg->return_addr = 93877475527042;
  test_msg->slice_time = 261963842;
  test_msg->total_time = 2042;

  EXPECT_EQ(send_message(0xCF00, 4096, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 4096);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  {
    const char check_string[] = {(char)114, (char)111, (char)117, (char)116,
                                 (char)101, (char)40,  (char)41,  (char)0};
    EXPECT_EQ(memcmp(last_msg_->func, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->func, expected string '"
        << check_string << "', is '" << last_msg_->func << "'";
  }
  EXPECT_EQ(last_msg_->id, 2496234002)
      << "incorrect value for id, expected 2496234002, is " << last_msg_->id;
  EXPECT_EQ(last_msg_->line, 18)
      << "incorrect value for line, expected 18, is " << last_msg_->line;
  EXPECT_EQ(last_msg_->max, 40)
      << "incorrect value for max, expected 40, is " << last_msg_->max;
  EXPECT_EQ(last_msg_->min, 2)
      << "incorrect value for min, expected 2, is " << last_msg_->min;
  EXPECT_EQ(last_msg_->num_executions, 180)
      << "incorrect value for num_executions, expected 180, is "
      << last_msg_->num_executions;
  EXPECT_EQ(last_msg_->return_addr, 93877475527042)
      << "incorrect value for return_addr, expected 93877475527042, is "
      << last_msg_->return_addr;
  EXPECT_EQ(last_msg_->slice_time, 261963842)
      << "incorrect value for slice_time, expected 261963842, is "
      << last_msg_->slice_time;
  EXPECT_EQ(last_msg_->total_time, 2042)
      << "incorrect value for total_time, expected 2042, is "
      << last_msg_->total_time;
}
