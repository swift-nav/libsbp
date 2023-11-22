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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqSvProfileDep.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_acquisition_MsgAcqSvProfileDep0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_acq_sv_profile_dep_t> {
 public:
  Test_legacy_auto_check_sbp_acquisition_MsgAcqSvProfileDep0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_acq_sv_profile_dep_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_acq_sv_profile_dep_t *>(last_msg_storage_)),
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
                      const msg_acq_sv_profile_dep_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_acq_sv_profile_dep_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_acquisition_MsgAcqSvProfileDep0, Test) {
  uint8_t encoded_frame[] = {
      85,  30,  0,   195, 4,  105, 67, 103, 151, 0,   12,  22,  0,   0,   0,
      187, 0,   91,  0,   0,  0,   75, 0,   0,   0,   132, 0,   0,   0,   36,
      0,   0,   0,   60,  0,  0,   0,  241, 0,   0,   0,   238, 38,  111, 0,
      179, 23,  0,   1,   0,  176, 0,  166, 0,   0,   0,   234, 0,   0,   0,
      155, 0,   0,   0,   24, 0,   0,  0,   212, 0,   0,   0,   247, 0,   0,
      0,   142, 213, 68,  0,  53,  24, 0,   0,   0,   52,  0,   49,  0,   0,
      0,   245, 0,   0,   0,  76,  0,  0,   0,   248, 0,   0,   0,   212, 0,
      0,   0,   101, 0,   0,  0,   67, 132,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_acq_sv_profile_dep_t *test_msg =
      (msg_acq_sv_profile_dep_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->acq_sv_profile) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->acq_sv_profile[0]));
  }
  test_msg->acq_sv_profile[0].bin_width = 187;
  test_msg->acq_sv_profile[0].cf = 60;
  test_msg->acq_sv_profile[0].cf_max = 36;
  test_msg->acq_sv_profile[0].cf_min = 132;
  test_msg->acq_sv_profile[0].cn0 = 151;
  test_msg->acq_sv_profile[0].cp = 241;
  test_msg->acq_sv_profile[0].int_time = 12;
  test_msg->acq_sv_profile[0].job_type = 67;
  test_msg->acq_sv_profile[0].sid.code = 0;
  test_msg->acq_sv_profile[0].sid.reserved = 0;
  test_msg->acq_sv_profile[0].sid.sat = 22;
  test_msg->acq_sv_profile[0].status = 103;
  test_msg->acq_sv_profile[0].time_spent = 75;
  test_msg->acq_sv_profile[0].timestamp = 91;
  if (sizeof(test_msg->acq_sv_profile) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->acq_sv_profile[0]));
  }
  test_msg->acq_sv_profile[1].bin_width = 176;
  test_msg->acq_sv_profile[1].cf = 212;
  test_msg->acq_sv_profile[1].cf_max = 24;
  test_msg->acq_sv_profile[1].cf_min = 155;
  test_msg->acq_sv_profile[1].cn0 = 111;
  test_msg->acq_sv_profile[1].cp = 247;
  test_msg->acq_sv_profile[1].int_time = 179;
  test_msg->acq_sv_profile[1].job_type = 238;
  test_msg->acq_sv_profile[1].sid.code = 1;
  test_msg->acq_sv_profile[1].sid.reserved = 0;
  test_msg->acq_sv_profile[1].sid.sat = 23;
  test_msg->acq_sv_profile[1].status = 38;
  test_msg->acq_sv_profile[1].time_spent = 234;
  test_msg->acq_sv_profile[1].timestamp = 166;
  if (sizeof(test_msg->acq_sv_profile) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->acq_sv_profile[0]));
  }
  test_msg->acq_sv_profile[2].bin_width = 52;
  test_msg->acq_sv_profile[2].cf = 212;
  test_msg->acq_sv_profile[2].cf_max = 248;
  test_msg->acq_sv_profile[2].cf_min = 76;
  test_msg->acq_sv_profile[2].cn0 = 68;
  test_msg->acq_sv_profile[2].cp = 101;
  test_msg->acq_sv_profile[2].int_time = 53;
  test_msg->acq_sv_profile[2].job_type = 142;
  test_msg->acq_sv_profile[2].sid.code = 0;
  test_msg->acq_sv_profile[2].sid.reserved = 0;
  test_msg->acq_sv_profile[2].sid.sat = 24;
  test_msg->acq_sv_profile[2].status = 213;
  test_msg->acq_sv_profile[2].time_spent = 245;
  test_msg->acq_sv_profile[2].timestamp = 49;

  EXPECT_EQ(send_message(0x1e, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->acq_sv_profile[0].bin_width, 187)
      << "incorrect value for acq_sv_profile[0].bin_width, expected 187, is "
      << last_msg_->acq_sv_profile[0].bin_width;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].cf, 60)
      << "incorrect value for acq_sv_profile[0].cf, expected 60, is "
      << last_msg_->acq_sv_profile[0].cf;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].cf_max, 36)
      << "incorrect value for acq_sv_profile[0].cf_max, expected 36, is "
      << last_msg_->acq_sv_profile[0].cf_max;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].cf_min, 132)
      << "incorrect value for acq_sv_profile[0].cf_min, expected 132, is "
      << last_msg_->acq_sv_profile[0].cf_min;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].cn0, 151)
      << "incorrect value for acq_sv_profile[0].cn0, expected 151, is "
      << last_msg_->acq_sv_profile[0].cn0;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].cp, 241)
      << "incorrect value for acq_sv_profile[0].cp, expected 241, is "
      << last_msg_->acq_sv_profile[0].cp;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].int_time, 12)
      << "incorrect value for acq_sv_profile[0].int_time, expected 12, is "
      << last_msg_->acq_sv_profile[0].int_time;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].job_type, 67)
      << "incorrect value for acq_sv_profile[0].job_type, expected 67, is "
      << last_msg_->acq_sv_profile[0].job_type;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].sid.code, 0)
      << "incorrect value for acq_sv_profile[0].sid.code, expected 0, is "
      << last_msg_->acq_sv_profile[0].sid.code;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].sid.reserved, 0)
      << "incorrect value for acq_sv_profile[0].sid.reserved, expected 0, is "
      << last_msg_->acq_sv_profile[0].sid.reserved;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].sid.sat, 22)
      << "incorrect value for acq_sv_profile[0].sid.sat, expected 22, is "
      << last_msg_->acq_sv_profile[0].sid.sat;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].status, 103)
      << "incorrect value for acq_sv_profile[0].status, expected 103, is "
      << last_msg_->acq_sv_profile[0].status;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].time_spent, 75)
      << "incorrect value for acq_sv_profile[0].time_spent, expected 75, is "
      << last_msg_->acq_sv_profile[0].time_spent;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].timestamp, 91)
      << "incorrect value for acq_sv_profile[0].timestamp, expected 91, is "
      << last_msg_->acq_sv_profile[0].timestamp;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].bin_width, 176)
      << "incorrect value for acq_sv_profile[1].bin_width, expected 176, is "
      << last_msg_->acq_sv_profile[1].bin_width;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].cf, 212)
      << "incorrect value for acq_sv_profile[1].cf, expected 212, is "
      << last_msg_->acq_sv_profile[1].cf;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].cf_max, 24)
      << "incorrect value for acq_sv_profile[1].cf_max, expected 24, is "
      << last_msg_->acq_sv_profile[1].cf_max;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].cf_min, 155)
      << "incorrect value for acq_sv_profile[1].cf_min, expected 155, is "
      << last_msg_->acq_sv_profile[1].cf_min;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].cn0, 111)
      << "incorrect value for acq_sv_profile[1].cn0, expected 111, is "
      << last_msg_->acq_sv_profile[1].cn0;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].cp, 247)
      << "incorrect value for acq_sv_profile[1].cp, expected 247, is "
      << last_msg_->acq_sv_profile[1].cp;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].int_time, 179)
      << "incorrect value for acq_sv_profile[1].int_time, expected 179, is "
      << last_msg_->acq_sv_profile[1].int_time;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].job_type, 238)
      << "incorrect value for acq_sv_profile[1].job_type, expected 238, is "
      << last_msg_->acq_sv_profile[1].job_type;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].sid.code, 1)
      << "incorrect value for acq_sv_profile[1].sid.code, expected 1, is "
      << last_msg_->acq_sv_profile[1].sid.code;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].sid.reserved, 0)
      << "incorrect value for acq_sv_profile[1].sid.reserved, expected 0, is "
      << last_msg_->acq_sv_profile[1].sid.reserved;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].sid.sat, 23)
      << "incorrect value for acq_sv_profile[1].sid.sat, expected 23, is "
      << last_msg_->acq_sv_profile[1].sid.sat;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].status, 38)
      << "incorrect value for acq_sv_profile[1].status, expected 38, is "
      << last_msg_->acq_sv_profile[1].status;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].time_spent, 234)
      << "incorrect value for acq_sv_profile[1].time_spent, expected 234, is "
      << last_msg_->acq_sv_profile[1].time_spent;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].timestamp, 166)
      << "incorrect value for acq_sv_profile[1].timestamp, expected 166, is "
      << last_msg_->acq_sv_profile[1].timestamp;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].bin_width, 52)
      << "incorrect value for acq_sv_profile[2].bin_width, expected 52, is "
      << last_msg_->acq_sv_profile[2].bin_width;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].cf, 212)
      << "incorrect value for acq_sv_profile[2].cf, expected 212, is "
      << last_msg_->acq_sv_profile[2].cf;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].cf_max, 248)
      << "incorrect value for acq_sv_profile[2].cf_max, expected 248, is "
      << last_msg_->acq_sv_profile[2].cf_max;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].cf_min, 76)
      << "incorrect value for acq_sv_profile[2].cf_min, expected 76, is "
      << last_msg_->acq_sv_profile[2].cf_min;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].cn0, 68)
      << "incorrect value for acq_sv_profile[2].cn0, expected 68, is "
      << last_msg_->acq_sv_profile[2].cn0;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].cp, 101)
      << "incorrect value for acq_sv_profile[2].cp, expected 101, is "
      << last_msg_->acq_sv_profile[2].cp;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].int_time, 53)
      << "incorrect value for acq_sv_profile[2].int_time, expected 53, is "
      << last_msg_->acq_sv_profile[2].int_time;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].job_type, 142)
      << "incorrect value for acq_sv_profile[2].job_type, expected 142, is "
      << last_msg_->acq_sv_profile[2].job_type;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].sid.code, 0)
      << "incorrect value for acq_sv_profile[2].sid.code, expected 0, is "
      << last_msg_->acq_sv_profile[2].sid.code;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].sid.reserved, 0)
      << "incorrect value for acq_sv_profile[2].sid.reserved, expected 0, is "
      << last_msg_->acq_sv_profile[2].sid.reserved;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].sid.sat, 24)
      << "incorrect value for acq_sv_profile[2].sid.sat, expected 24, is "
      << last_msg_->acq_sv_profile[2].sid.sat;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].status, 213)
      << "incorrect value for acq_sv_profile[2].status, expected 213, is "
      << last_msg_->acq_sv_profile[2].status;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].time_spent, 245)
      << "incorrect value for acq_sv_profile[2].time_spent, expected 245, is "
      << last_msg_->acq_sv_profile[2].time_spent;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].timestamp, 49)
      << "incorrect value for acq_sv_profile[2].timestamp, expected 49, is "
      << last_msg_->acq_sv_profile[2].timestamp;
}
