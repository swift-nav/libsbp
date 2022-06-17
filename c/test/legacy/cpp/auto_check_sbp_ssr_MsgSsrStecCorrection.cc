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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrection.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_ssr_MsgSsrStecCorrection0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_stec_correction_t> {
 public:
  Test_legacy_auto_check_sbp_ssr_MsgSsrStecCorrection0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_stec_correction_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_ssr_stec_correction_t *>(last_msg_storage_)),
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
                      const msg_ssr_stec_correction_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_stec_correction_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ssr_MsgSsrStecCorrection0, Test) {
  uint8_t encoded_frame[] = {
      85, 253, 5,  66, 0,  38, 180, 0, 0,  0,  3,  0,  1,   1,  10, 0,
      15, 1,   0,  10, 0,  2,  1,   1, 1,  63, 0,  62, 0,   61, 0,  60,
      0,  31,  15, 5,  63, 0,  64,  0, 65, 0,  66, 0,  119, 50,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_stec_correction_t *test_msg =
      (msg_ssr_stec_correction_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->header.num_msgs = 1;
  test_msg->header.seq_num = 1;
  test_msg->header.sol_id = 0;
  test_msg->header.time.tow = 180;
  test_msg->header.time.wn = 3;
  test_msg->header.update_interval = 10;
  test_msg->n_sats = 2;
  test_msg->ssr_iod_atmo = 15;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[0].stec_coeff[0]));
  }
  test_msg->stec_sat_list[0].stec_coeff[0] = 63;
  if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[0].stec_coeff[0]));
  }
  test_msg->stec_sat_list[0].stec_coeff[1] = 62;
  if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[0].stec_coeff[0]));
  }
  test_msg->stec_sat_list[0].stec_coeff[2] = 61;
  if (sizeof(test_msg->stec_sat_list[0].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[0].stec_coeff[0]));
  }
  test_msg->stec_sat_list[0].stec_coeff[3] = 60;
  test_msg->stec_sat_list[0].stec_quality_indicator = 1;
  test_msg->stec_sat_list[0].sv_id.constellation = 1;
  test_msg->stec_sat_list[0].sv_id.satId = 1;
  if (sizeof(test_msg->stec_sat_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stec_sat_list[0]));
  }
  if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[1].stec_coeff[0]));
  }
  test_msg->stec_sat_list[1].stec_coeff[0] = 63;
  if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[1].stec_coeff[0]));
  }
  test_msg->stec_sat_list[1].stec_coeff[1] = 64;
  if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[1].stec_coeff[0]));
  }
  test_msg->stec_sat_list[1].stec_coeff[2] = 65;
  if (sizeof(test_msg->stec_sat_list[1].stec_coeff) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len +
                             sizeof(test_msg->stec_sat_list[1].stec_coeff[0]));
  }
  test_msg->stec_sat_list[1].stec_coeff[3] = 66;
  test_msg->stec_sat_list[1].stec_quality_indicator = 5;
  test_msg->stec_sat_list[1].sv_id.constellation = 15;
  test_msg->stec_sat_list[1].sv_id.satId = 31;
  test_msg->tile_id = 10;
  test_msg->tile_set_id = 1;

  EXPECT_EQ(send_message(1533, 66, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->header.num_msgs, 1)
      << "incorrect value for header.num_msgs, expected 1, is "
      << last_msg_->header.num_msgs;
  EXPECT_EQ(last_msg_->header.seq_num, 1)
      << "incorrect value for header.seq_num, expected 1, is "
      << last_msg_->header.seq_num;
  EXPECT_EQ(last_msg_->header.sol_id, 0)
      << "incorrect value for header.sol_id, expected 0, is "
      << last_msg_->header.sol_id;
  EXPECT_EQ(last_msg_->header.time.tow, 180)
      << "incorrect value for header.time.tow, expected 180, is "
      << last_msg_->header.time.tow;
  EXPECT_EQ(last_msg_->header.time.wn, 3)
      << "incorrect value for header.time.wn, expected 3, is "
      << last_msg_->header.time.wn;
  EXPECT_EQ(last_msg_->header.update_interval, 10)
      << "incorrect value for header.update_interval, expected 10, is "
      << last_msg_->header.update_interval;
  EXPECT_EQ(last_msg_->n_sats, 2)
      << "incorrect value for n_sats, expected 2, is " << last_msg_->n_sats;
  EXPECT_EQ(last_msg_->ssr_iod_atmo, 15)
      << "incorrect value for ssr_iod_atmo, expected 15, is "
      << last_msg_->ssr_iod_atmo;
  EXPECT_EQ(last_msg_->stec_sat_list[0].stec_coeff[0], 63)
      << "incorrect value for stec_sat_list[0].stec_coeff[0], expected 63, is "
      << last_msg_->stec_sat_list[0].stec_coeff[0];
  EXPECT_EQ(last_msg_->stec_sat_list[0].stec_coeff[1], 62)
      << "incorrect value for stec_sat_list[0].stec_coeff[1], expected 62, is "
      << last_msg_->stec_sat_list[0].stec_coeff[1];
  EXPECT_EQ(last_msg_->stec_sat_list[0].stec_coeff[2], 61)
      << "incorrect value for stec_sat_list[0].stec_coeff[2], expected 61, is "
      << last_msg_->stec_sat_list[0].stec_coeff[2];
  EXPECT_EQ(last_msg_->stec_sat_list[0].stec_coeff[3], 60)
      << "incorrect value for stec_sat_list[0].stec_coeff[3], expected 60, is "
      << last_msg_->stec_sat_list[0].stec_coeff[3];
  EXPECT_EQ(last_msg_->stec_sat_list[0].stec_quality_indicator, 1)
      << "incorrect value for stec_sat_list[0].stec_quality_indicator, "
         "expected 1, is "
      << last_msg_->stec_sat_list[0].stec_quality_indicator;
  EXPECT_EQ(last_msg_->stec_sat_list[0].sv_id.constellation, 1)
      << "incorrect value for stec_sat_list[0].sv_id.constellation, expected "
         "1, is "
      << last_msg_->stec_sat_list[0].sv_id.constellation;
  EXPECT_EQ(last_msg_->stec_sat_list[0].sv_id.satId, 1)
      << "incorrect value for stec_sat_list[0].sv_id.satId, expected 1, is "
      << last_msg_->stec_sat_list[0].sv_id.satId;
  EXPECT_EQ(last_msg_->stec_sat_list[1].stec_coeff[0], 63)
      << "incorrect value for stec_sat_list[1].stec_coeff[0], expected 63, is "
      << last_msg_->stec_sat_list[1].stec_coeff[0];
  EXPECT_EQ(last_msg_->stec_sat_list[1].stec_coeff[1], 64)
      << "incorrect value for stec_sat_list[1].stec_coeff[1], expected 64, is "
      << last_msg_->stec_sat_list[1].stec_coeff[1];
  EXPECT_EQ(last_msg_->stec_sat_list[1].stec_coeff[2], 65)
      << "incorrect value for stec_sat_list[1].stec_coeff[2], expected 65, is "
      << last_msg_->stec_sat_list[1].stec_coeff[2];
  EXPECT_EQ(last_msg_->stec_sat_list[1].stec_coeff[3], 66)
      << "incorrect value for stec_sat_list[1].stec_coeff[3], expected 66, is "
      << last_msg_->stec_sat_list[1].stec_coeff[3];
  EXPECT_EQ(last_msg_->stec_sat_list[1].stec_quality_indicator, 5)
      << "incorrect value for stec_sat_list[1].stec_quality_indicator, "
         "expected 5, is "
      << last_msg_->stec_sat_list[1].stec_quality_indicator;
  EXPECT_EQ(last_msg_->stec_sat_list[1].sv_id.constellation, 15)
      << "incorrect value for stec_sat_list[1].sv_id.constellation, expected "
         "15, is "
      << last_msg_->stec_sat_list[1].sv_id.constellation;
  EXPECT_EQ(last_msg_->stec_sat_list[1].sv_id.satId, 31)
      << "incorrect value for stec_sat_list[1].sv_id.satId, expected 31, is "
      << last_msg_->stec_sat_list[1].sv_id.satId;
  EXPECT_EQ(last_msg_->tile_id, 10)
      << "incorrect value for tile_id, expected 10, is " << last_msg_->tile_id;
  EXPECT_EQ(last_msg_->tile_set_id, 1)
      << "incorrect value for tile_set_id, expected 1, is "
      << last_msg_->tile_set_id;
}
