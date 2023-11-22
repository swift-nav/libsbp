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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqSvProfile.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_acquisition_MsgAcqSvProfile0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_acq_sv_profile_t> {
 public:
  Test_legacy_auto_check_sbp_acquisition_MsgAcqSvProfile0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_acq_sv_profile_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_acq_sv_profile_t *>(last_msg_storage_)),
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
                      const msg_acq_sv_profile_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_acq_sv_profile_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_acquisition_MsgAcqSvProfile0, Test) {
  uint8_t encoded_frame[] = {
      85,  46,  0, 195, 4,   99,  7, 13,  38,  0,   97,  22,  0,   174, 0,   52,
      0,   0,   0, 49,  0,   0,   0, 61,  0,   0,   0,   147, 0,   0,   0,   47,
      0,   0,   0, 140, 0,   0,   0, 166, 210, 59,  0,   253, 23,  1,   121, 0,
      190, 0,   0, 0,   175, 0,   0, 0,   175, 0,   0,   0,   142, 0,   0,   0,
      237, 0,   0, 0,   12,  0,   0, 0,   126, 88,  21,  0,   153, 24,  0,   8,
      0,   130, 0, 0,   0,   172, 0, 0,   0,   91,  0,   0,   0,   191, 0,   0,
      0,   84,  0, 0,   0,   82,  0, 0,   0,   168, 177,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_acq_sv_profile_t *test_msg = (msg_acq_sv_profile_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->acq_sv_profile) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->acq_sv_profile[0]));
  }
  test_msg->acq_sv_profile[0].bin_width = 174;
  test_msg->acq_sv_profile[0].cf = 47;
  test_msg->acq_sv_profile[0].cf_max = 147;
  test_msg->acq_sv_profile[0].cf_min = 61;
  test_msg->acq_sv_profile[0].cn0 = 38;
  test_msg->acq_sv_profile[0].cp = 140;
  test_msg->acq_sv_profile[0].int_time = 97;
  test_msg->acq_sv_profile[0].job_type = 7;
  test_msg->acq_sv_profile[0].sid.code = 0;
  test_msg->acq_sv_profile[0].sid.sat = 22;
  test_msg->acq_sv_profile[0].status = 13;
  test_msg->acq_sv_profile[0].time_spent = 49;
  test_msg->acq_sv_profile[0].timestamp = 52;
  if (sizeof(test_msg->acq_sv_profile) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->acq_sv_profile[0]));
  }
  test_msg->acq_sv_profile[1].bin_width = 121;
  test_msg->acq_sv_profile[1].cf = 237;
  test_msg->acq_sv_profile[1].cf_max = 142;
  test_msg->acq_sv_profile[1].cf_min = 175;
  test_msg->acq_sv_profile[1].cn0 = 59;
  test_msg->acq_sv_profile[1].cp = 12;
  test_msg->acq_sv_profile[1].int_time = 253;
  test_msg->acq_sv_profile[1].job_type = 166;
  test_msg->acq_sv_profile[1].sid.code = 1;
  test_msg->acq_sv_profile[1].sid.sat = 23;
  test_msg->acq_sv_profile[1].status = 210;
  test_msg->acq_sv_profile[1].time_spent = 175;
  test_msg->acq_sv_profile[1].timestamp = 190;
  if (sizeof(test_msg->acq_sv_profile) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->acq_sv_profile[0]));
  }
  test_msg->acq_sv_profile[2].bin_width = 8;
  test_msg->acq_sv_profile[2].cf = 84;
  test_msg->acq_sv_profile[2].cf_max = 191;
  test_msg->acq_sv_profile[2].cf_min = 91;
  test_msg->acq_sv_profile[2].cn0 = 21;
  test_msg->acq_sv_profile[2].cp = 82;
  test_msg->acq_sv_profile[2].int_time = 153;
  test_msg->acq_sv_profile[2].job_type = 126;
  test_msg->acq_sv_profile[2].sid.code = 0;
  test_msg->acq_sv_profile[2].sid.sat = 24;
  test_msg->acq_sv_profile[2].status = 88;
  test_msg->acq_sv_profile[2].time_spent = 172;
  test_msg->acq_sv_profile[2].timestamp = 130;

  EXPECT_EQ(send_message(0x2e, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->acq_sv_profile[0].bin_width, 174)
      << "incorrect value for acq_sv_profile[0].bin_width, expected 174, is "
      << last_msg_->acq_sv_profile[0].bin_width;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].cf, 47)
      << "incorrect value for acq_sv_profile[0].cf, expected 47, is "
      << last_msg_->acq_sv_profile[0].cf;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].cf_max, 147)
      << "incorrect value for acq_sv_profile[0].cf_max, expected 147, is "
      << last_msg_->acq_sv_profile[0].cf_max;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].cf_min, 61)
      << "incorrect value for acq_sv_profile[0].cf_min, expected 61, is "
      << last_msg_->acq_sv_profile[0].cf_min;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].cn0, 38)
      << "incorrect value for acq_sv_profile[0].cn0, expected 38, is "
      << last_msg_->acq_sv_profile[0].cn0;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].cp, 140)
      << "incorrect value for acq_sv_profile[0].cp, expected 140, is "
      << last_msg_->acq_sv_profile[0].cp;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].int_time, 97)
      << "incorrect value for acq_sv_profile[0].int_time, expected 97, is "
      << last_msg_->acq_sv_profile[0].int_time;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].job_type, 7)
      << "incorrect value for acq_sv_profile[0].job_type, expected 7, is "
      << last_msg_->acq_sv_profile[0].job_type;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].sid.code, 0)
      << "incorrect value for acq_sv_profile[0].sid.code, expected 0, is "
      << last_msg_->acq_sv_profile[0].sid.code;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].sid.sat, 22)
      << "incorrect value for acq_sv_profile[0].sid.sat, expected 22, is "
      << last_msg_->acq_sv_profile[0].sid.sat;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].status, 13)
      << "incorrect value for acq_sv_profile[0].status, expected 13, is "
      << last_msg_->acq_sv_profile[0].status;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].time_spent, 49)
      << "incorrect value for acq_sv_profile[0].time_spent, expected 49, is "
      << last_msg_->acq_sv_profile[0].time_spent;
  EXPECT_EQ(last_msg_->acq_sv_profile[0].timestamp, 52)
      << "incorrect value for acq_sv_profile[0].timestamp, expected 52, is "
      << last_msg_->acq_sv_profile[0].timestamp;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].bin_width, 121)
      << "incorrect value for acq_sv_profile[1].bin_width, expected 121, is "
      << last_msg_->acq_sv_profile[1].bin_width;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].cf, 237)
      << "incorrect value for acq_sv_profile[1].cf, expected 237, is "
      << last_msg_->acq_sv_profile[1].cf;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].cf_max, 142)
      << "incorrect value for acq_sv_profile[1].cf_max, expected 142, is "
      << last_msg_->acq_sv_profile[1].cf_max;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].cf_min, 175)
      << "incorrect value for acq_sv_profile[1].cf_min, expected 175, is "
      << last_msg_->acq_sv_profile[1].cf_min;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].cn0, 59)
      << "incorrect value for acq_sv_profile[1].cn0, expected 59, is "
      << last_msg_->acq_sv_profile[1].cn0;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].cp, 12)
      << "incorrect value for acq_sv_profile[1].cp, expected 12, is "
      << last_msg_->acq_sv_profile[1].cp;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].int_time, 253)
      << "incorrect value for acq_sv_profile[1].int_time, expected 253, is "
      << last_msg_->acq_sv_profile[1].int_time;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].job_type, 166)
      << "incorrect value for acq_sv_profile[1].job_type, expected 166, is "
      << last_msg_->acq_sv_profile[1].job_type;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].sid.code, 1)
      << "incorrect value for acq_sv_profile[1].sid.code, expected 1, is "
      << last_msg_->acq_sv_profile[1].sid.code;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].sid.sat, 23)
      << "incorrect value for acq_sv_profile[1].sid.sat, expected 23, is "
      << last_msg_->acq_sv_profile[1].sid.sat;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].status, 210)
      << "incorrect value for acq_sv_profile[1].status, expected 210, is "
      << last_msg_->acq_sv_profile[1].status;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].time_spent, 175)
      << "incorrect value for acq_sv_profile[1].time_spent, expected 175, is "
      << last_msg_->acq_sv_profile[1].time_spent;
  EXPECT_EQ(last_msg_->acq_sv_profile[1].timestamp, 190)
      << "incorrect value for acq_sv_profile[1].timestamp, expected 190, is "
      << last_msg_->acq_sv_profile[1].timestamp;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].bin_width, 8)
      << "incorrect value for acq_sv_profile[2].bin_width, expected 8, is "
      << last_msg_->acq_sv_profile[2].bin_width;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].cf, 84)
      << "incorrect value for acq_sv_profile[2].cf, expected 84, is "
      << last_msg_->acq_sv_profile[2].cf;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].cf_max, 191)
      << "incorrect value for acq_sv_profile[2].cf_max, expected 191, is "
      << last_msg_->acq_sv_profile[2].cf_max;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].cf_min, 91)
      << "incorrect value for acq_sv_profile[2].cf_min, expected 91, is "
      << last_msg_->acq_sv_profile[2].cf_min;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].cn0, 21)
      << "incorrect value for acq_sv_profile[2].cn0, expected 21, is "
      << last_msg_->acq_sv_profile[2].cn0;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].cp, 82)
      << "incorrect value for acq_sv_profile[2].cp, expected 82, is "
      << last_msg_->acq_sv_profile[2].cp;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].int_time, 153)
      << "incorrect value for acq_sv_profile[2].int_time, expected 153, is "
      << last_msg_->acq_sv_profile[2].int_time;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].job_type, 126)
      << "incorrect value for acq_sv_profile[2].job_type, expected 126, is "
      << last_msg_->acq_sv_profile[2].job_type;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].sid.code, 0)
      << "incorrect value for acq_sv_profile[2].sid.code, expected 0, is "
      << last_msg_->acq_sv_profile[2].sid.code;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].sid.sat, 24)
      << "incorrect value for acq_sv_profile[2].sid.sat, expected 24, is "
      << last_msg_->acq_sv_profile[2].sid.sat;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].status, 88)
      << "incorrect value for acq_sv_profile[2].status, expected 88, is "
      << last_msg_->acq_sv_profile[2].status;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].time_spent, 172)
      << "incorrect value for acq_sv_profile[2].time_spent, expected 172, is "
      << last_msg_->acq_sv_profile[2].time_spent;
  EXPECT_EQ(last_msg_->acq_sv_profile[2].timestamp, 130)
      << "incorrect value for acq_sv_profile[2].timestamp, expected 130, is "
      << last_msg_->acq_sv_profile[2].timestamp;
}
