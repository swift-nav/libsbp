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
// spec/tests/yaml/swiftnav/sbp/bootload/test_MsgNapDeviceDnaResp.yaml by
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
#include <libsbp/legacy/bootload.h>
#include <libsbp/legacy/cpp/legacy_state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_bootload_MsgNapDeviceDnaResp0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_nap_device_dna_resp_t> {
 public:
  Test_legacy_auto_check_sbp_bootload_MsgNapDeviceDnaResp0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_nap_device_dna_resp_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_nap_device_dna_resp_t *>(last_msg_storage_)),
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
                      const msg_nap_device_dna_resp_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_nap_device_dna_resp_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_bootload_MsgNapDeviceDnaResp0, Test) {
  uint8_t encoded_frame[] = {
      85, 221, 0, 169, 56, 8, 2, 187, 1, 130, 173, 244, 67, 122, 70, 91,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_nap_device_dna_resp_t *test_msg =
      (msg_nap_device_dna_resp_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->dna) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->dna[0]));
  }
  test_msg->dna[0] = 2;
  if (sizeof(test_msg->dna) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->dna[0]));
  }
  test_msg->dna[1] = 187;
  if (sizeof(test_msg->dna) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->dna[0]));
  }
  test_msg->dna[2] = 1;
  if (sizeof(test_msg->dna) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->dna[0]));
  }
  test_msg->dna[3] = 130;
  if (sizeof(test_msg->dna) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->dna[0]));
  }
  test_msg->dna[4] = 173;
  if (sizeof(test_msg->dna) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->dna[0]));
  }
  test_msg->dna[5] = 244;
  if (sizeof(test_msg->dna) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->dna[0]));
  }
  test_msg->dna[6] = 67;
  if (sizeof(test_msg->dna) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->dna[0]));
  }
  test_msg->dna[7] = 122;

  EXPECT_EQ(send_message(0xdd, 14505, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 14505);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->dna[0])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dna[0])),
            2)
      << "incorrect value for dna[0], expected 2, is " << last_msg_->dna[0];
  EXPECT_EQ(get_as<decltype(last_msg_->dna[1])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dna[1])),
            187)
      << "incorrect value for dna[1], expected 187, is " << last_msg_->dna[1];
  EXPECT_EQ(get_as<decltype(last_msg_->dna[2])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dna[2])),
            1)
      << "incorrect value for dna[2], expected 1, is " << last_msg_->dna[2];
  EXPECT_EQ(get_as<decltype(last_msg_->dna[3])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dna[3])),
            130)
      << "incorrect value for dna[3], expected 130, is " << last_msg_->dna[3];
  EXPECT_EQ(get_as<decltype(last_msg_->dna[4])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dna[4])),
            173)
      << "incorrect value for dna[4], expected 173, is " << last_msg_->dna[4];
  EXPECT_EQ(get_as<decltype(last_msg_->dna[5])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dna[5])),
            244)
      << "incorrect value for dna[5], expected 244, is " << last_msg_->dna[5];
  EXPECT_EQ(get_as<decltype(last_msg_->dna[6])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dna[6])),
            67)
      << "incorrect value for dna[6], expected 67, is " << last_msg_->dna[6];
  EXPECT_EQ(get_as<decltype(last_msg_->dna[7])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->dna[7])),
            122)
      << "incorrect value for dna[7], expected 122, is " << last_msg_->dna[7];
}
