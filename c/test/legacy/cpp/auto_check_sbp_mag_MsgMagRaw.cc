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
// spec/tests/yaml/swiftnav/sbp/mag/test_MsgMagRaw.yaml by generate.py. Do not
// modify by hand!

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
#include <libsbp/legacy/mag.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_mag_MsgMagRaw0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_mag_raw_t> {
 public:
  Test_legacy_auto_check_sbp_mag_MsgMagRaw0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_mag_raw_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_mag_raw_t *>(last_msg_storage_)),
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
                      const msg_mag_raw_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_mag_raw_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_mag_MsgMagRaw0, Test) {
  uint8_t encoded_frame[] = {
      85,  2,  9, 195, 4, 11,  173, 227, 158, 198,
      206, 98, 3, 230, 2, 110, 229, 159, 23,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_mag_raw_t *test_msg = (msg_mag_raw_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->mag_x = 866;
  test_msg->mag_y = 742;
  test_msg->mag_z = -6802;
  test_msg->tow = 3332301741;
  test_msg->tow_f = 206;

  EXPECT_EQ(send_message(0x902, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->mag_x)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->mag_x)),
            866)
      << "incorrect value for mag_x, expected 866, is " << last_msg_->mag_x;
  EXPECT_EQ(get_as<decltype(last_msg_->mag_y)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->mag_y)),
            742)
      << "incorrect value for mag_y, expected 742, is " << last_msg_->mag_y;
  EXPECT_EQ(get_as<decltype(last_msg_->mag_z)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->mag_z)),
            -6802)
      << "incorrect value for mag_z, expected -6802, is " << last_msg_->mag_z;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            3332301741)
      << "incorrect value for tow, expected 3332301741, is " << last_msg_->tow;
  EXPECT_EQ(get_as<decltype(last_msg_->tow_f)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow_f)),
            206)
      << "incorrect value for tow_f, expected 206, is " << last_msg_->tow_f;
}
