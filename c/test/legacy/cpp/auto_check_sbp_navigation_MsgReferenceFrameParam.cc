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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgReferenceFrameParam.yaml by
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
class Test_legacy_auto_check_sbp_navigation_MsgReferenceFrameParam0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_reference_frame_param_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgReferenceFrameParam0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_reference_frame_param_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_reference_frame_param_t *>(last_msg_storage_)),
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
                      const msg_reference_frame_param_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_reference_frame_param_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgReferenceFrameParam0, Test) {
  uint8_t encoded_frame[] = {
      85, 68, 2,  66, 0, 124, 1,  102, 111, 111, 0,  0,  0,   0, 0,  0,  0,
      0,  0,  0,  0,  0, 0,   0,  0,   0,   0,   0,  0,  0,   0, 0,  0,  0,
      0,  0,  0,  0,  0, 98,  97, 114, 0,   0,   0,  0,  0,   0, 0,  0,  0,
      0,  0,  0,  0,  0, 0,   0,  0,   0,   0,   0,  0,  0,   0, 0,  0,  0,
      0,  0,  0,  4,  5, 0,   6,  0,   7,   0,   0,  0,  8,   0, 0,  0,  9,
      0,  0,  0,  10, 0, 0,   0,  11,  0,   0,   0,  12, 0,   0, 0,  13, 0,
      0,  0,  14, 0,  0, 0,   15, 0,   0,   0,   16, 0,  0,   0, 17, 0,  0,
      0,  18, 0,  0,  0, 19,  0,  0,   0,   20,  0,  6,  161,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_reference_frame_param_t *test_msg =
      (msg_reference_frame_param_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->delta_X0 = 7;
  test_msg->delta_Y0 = 8;
  test_msg->delta_Z0 = 9;
  test_msg->dot_delta_X0 = 14;
  test_msg->dot_delta_Y0 = 15;
  test_msg->dot_delta_Z0 = 16;
  test_msg->dot_scale = 20;
  test_msg->dot_theta_01 = 17;
  test_msg->dot_theta_02 = 18;
  test_msg->dot_theta_03 = 19;
  test_msg->re_t0 = 6;
  test_msg->scale = 13;
  test_msg->sin = 4;
  {
    const char assign_string[] = {
        (char)102, (char)111, (char)111, (char)0, (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0};
    memcpy(test_msg->sn, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->sn) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->ssr_iod = 1;
  test_msg->theta_01 = 10;
  test_msg->theta_02 = 11;
  test_msg->theta_03 = 12;
  {
    const char assign_string[] = {
        (char)98, (char)97, (char)114, (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,   (char)0};
    memcpy(test_msg->tn, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->tn) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->utn = 5;

  EXPECT_EQ(send_message(580, 66, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->delta_X0)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->delta_X0)),
            7)
      << "incorrect value for delta_X0, expected 7, is " << last_msg_->delta_X0;
  EXPECT_EQ(get_as<decltype(last_msg_->delta_Y0)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->delta_Y0)),
            8)
      << "incorrect value for delta_Y0, expected 8, is " << last_msg_->delta_Y0;
  EXPECT_EQ(get_as<decltype(last_msg_->delta_Z0)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->delta_Z0)),
            9)
      << "incorrect value for delta_Z0, expected 9, is " << last_msg_->delta_Z0;
  EXPECT_EQ(get_as<decltype(last_msg_->dot_delta_X0)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dot_delta_X0)),
            14)
      << "incorrect value for dot_delta_X0, expected 14, is "
      << last_msg_->dot_delta_X0;
  EXPECT_EQ(get_as<decltype(last_msg_->dot_delta_Y0)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dot_delta_Y0)),
            15)
      << "incorrect value for dot_delta_Y0, expected 15, is "
      << last_msg_->dot_delta_Y0;
  EXPECT_EQ(get_as<decltype(last_msg_->dot_delta_Z0)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dot_delta_Z0)),
            16)
      << "incorrect value for dot_delta_Z0, expected 16, is "
      << last_msg_->dot_delta_Z0;
  EXPECT_EQ(get_as<decltype(last_msg_->dot_scale)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dot_scale)),
            20)
      << "incorrect value for dot_scale, expected 20, is "
      << last_msg_->dot_scale;
  EXPECT_EQ(get_as<decltype(last_msg_->dot_theta_01)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dot_theta_01)),
            17)
      << "incorrect value for dot_theta_01, expected 17, is "
      << last_msg_->dot_theta_01;
  EXPECT_EQ(get_as<decltype(last_msg_->dot_theta_02)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dot_theta_02)),
            18)
      << "incorrect value for dot_theta_02, expected 18, is "
      << last_msg_->dot_theta_02;
  EXPECT_EQ(get_as<decltype(last_msg_->dot_theta_03)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dot_theta_03)),
            19)
      << "incorrect value for dot_theta_03, expected 19, is "
      << last_msg_->dot_theta_03;
  EXPECT_EQ(get_as<decltype(last_msg_->re_t0)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->re_t0)),
            6)
      << "incorrect value for re_t0, expected 6, is " << last_msg_->re_t0;
  EXPECT_EQ(get_as<decltype(last_msg_->scale)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->scale)),
            13)
      << "incorrect value for scale, expected 13, is " << last_msg_->scale;
  EXPECT_EQ(get_as<decltype(last_msg_->sin)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sin)),
            4)
      << "incorrect value for sin, expected 4, is " << last_msg_->sin;
  {
    const char check_string[] = {
        (char)102, (char)111, (char)111, (char)0, (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
        (char)0,   (char)0,   (char)0,   (char)0};
    EXPECT_EQ(memcmp(last_msg_->sn, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->sn, expected string '"
        << check_string << "', is '" << last_msg_->sn << "'";
  }
  EXPECT_EQ(get_as<decltype(last_msg_->ssr_iod)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->ssr_iod)),
            1)
      << "incorrect value for ssr_iod, expected 1, is " << last_msg_->ssr_iod;
  EXPECT_EQ(get_as<decltype(last_msg_->theta_01)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->theta_01)),
            10)
      << "incorrect value for theta_01, expected 10, is "
      << last_msg_->theta_01;
  EXPECT_EQ(get_as<decltype(last_msg_->theta_02)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->theta_02)),
            11)
      << "incorrect value for theta_02, expected 11, is "
      << last_msg_->theta_02;
  EXPECT_EQ(get_as<decltype(last_msg_->theta_03)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->theta_03)),
            12)
      << "incorrect value for theta_03, expected 12, is "
      << last_msg_->theta_03;
  {
    const char check_string[] = {
        (char)98, (char)97, (char)114, (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
        (char)0,  (char)0,  (char)0,   (char)0};
    EXPECT_EQ(memcmp(last_msg_->tn, check_string, sizeof(check_string)), 0)
        << "incorrect value for last_msg_->tn, expected string '"
        << check_string << "', is '" << last_msg_->tn << "'";
  }
  EXPECT_EQ(get_as<decltype(last_msg_->utn)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->utn)),
            5)
      << "incorrect value for utn, expected 5, is " << last_msg_->utn;
}
