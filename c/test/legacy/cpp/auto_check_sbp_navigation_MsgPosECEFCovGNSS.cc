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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosECEFCovGNSS.yaml by
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
#include <libsbp/legacy/navigation.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_navigation_MsgPosECEFCovGNSS0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_pos_ecef_cov_gnss_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgPosECEFCovGNSS0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_pos_ecef_cov_gnss_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_pos_ecef_cov_gnss_t *>(last_msg_storage_)),
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
                      const msg_pos_ecef_cov_gnss_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_pos_ecef_cov_gnss_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgPosECEFCovGNSS0, Test) {
  uint8_t encoded_frame[] = {
      85,  52,  2,   0,   16,  54,  24,  229, 233, 29,  52, 254, 158,
      218, 42,  142, 68,  193, 69,  162, 89,  91,  34,  68, 80,  193,
      131, 21,  176, 129, 239, 174, 77,  65,  158, 232, 30, 60,  218,
      221, 20,  60,  129, 136, 198, 187, 205, 120, 166, 60, 5,   166,
      35,  188, 122, 177, 115, 60,  18,  4,   159, 102,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_pos_ecef_cov_gnss_t *test_msg =
      (msg_pos_ecef_cov_gnss_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cov_x_x = 0.009699014946818352;
  test_msg->cov_x_y = 0.009086096659302711;
  test_msg->cov_x_z = -0.006058753002434969;
  test_msg->cov_y_y = 0.020321274176239967;
  test_msg->cov_y_z = -0.009988312609493732;
  test_msg->cov_z_z = 0.01487385667860508;
  test_msg->flags = 4;
  test_msg->n_sats = 18;
  test_msg->tow = 501867800;
  test_msg->x = -2694229.7079770807;
  test_msg->y = -4264073.427345817;
  test_msg->z = 3890655.013186158;

  EXPECT_EQ(send_message(0x234, 4096, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 4096);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->cov_x_x * 100 - 0.00969901494682 * 100), 0.05)
      << "incorrect value for cov_x_x, expected 0.00969901494682, is "
      << last_msg_->cov_x_x;
  EXPECT_LT((last_msg_->cov_x_y * 100 - 0.0090860966593 * 100), 0.05)
      << "incorrect value for cov_x_y, expected 0.0090860966593, is "
      << last_msg_->cov_x_y;
  EXPECT_LT((last_msg_->cov_x_z * 100 - -0.00605875300243 * 100), 0.05)
      << "incorrect value for cov_x_z, expected -0.00605875300243, is "
      << last_msg_->cov_x_z;
  EXPECT_LT((last_msg_->cov_y_y * 100 - 0.0203212741762 * 100), 0.05)
      << "incorrect value for cov_y_y, expected 0.0203212741762, is "
      << last_msg_->cov_y_y;
  EXPECT_LT((last_msg_->cov_y_z * 100 - -0.00998831260949 * 100), 0.05)
      << "incorrect value for cov_y_z, expected -0.00998831260949, is "
      << last_msg_->cov_y_z;
  EXPECT_LT((last_msg_->cov_z_z * 100 - 0.0148738566786 * 100), 0.05)
      << "incorrect value for cov_z_z, expected 0.0148738566786, is "
      << last_msg_->cov_z_z;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            4)
      << "incorrect value for flags, expected 4, is " << last_msg_->flags;
  EXPECT_EQ(get_as<decltype(last_msg_->n_sats)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_sats)),
            18)
      << "incorrect value for n_sats, expected 18, is " << last_msg_->n_sats;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            501867800)
      << "incorrect value for tow, expected 501867800, is " << last_msg_->tow;
  EXPECT_LT((last_msg_->x * 100 - -2694229.70798 * 100), 0.05)
      << "incorrect value for x, expected -2694229.70798, is " << last_msg_->x;
  EXPECT_LT((last_msg_->y * 100 - -4264073.42735 * 100), 0.05)
      << "incorrect value for y, expected -4264073.42735, is " << last_msg_->y;
  EXPECT_LT((last_msg_->z * 100 - 3890655.01319 * 100), 0.05)
      << "incorrect value for z, expected 3890655.01319, is " << last_msg_->z;
}
