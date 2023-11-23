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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgNetworkStateResp.yaml by
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
#include <libsbp/legacy/piksi.h>
class Test_legacy_auto_check_sbp_piksi_MsgNetworkStateResp0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_network_state_resp_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgNetworkStateResp0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_network_state_resp_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_network_state_resp_t *>(last_msg_storage_)),
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
                      const msg_network_state_resp_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_network_state_resp_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgNetworkStateResp0, Test) {
  uint8_t encoded_frame[] = {
      85,  187, 0,   40,  15,  50,  143, 241, 84,  180, 152, 194, 137, 32, 44,
      114, 147, 68,  222, 92,  192, 78,  235, 63,  208, 114, 53,  183, 24, 244,
      231, 26,  105, 25,  136, 3,   105, 102, 48,  0,   0,   0,   0,   0,  0,
      0,   0,   0,   0,   0,   0,   0,   195, 229, 80,  147, 118, 193,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_network_state_resp_t *test_msg =
      (msg_network_state_resp_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->flags = 2471552451;
  {
    const char assign_string[] = {(char)105, (char)102, (char)48, (char)0,
                                  (char)0,   (char)0,   (char)0,  (char)0,
                                  (char)0,   (char)0,   (char)0,  (char)0,
                                  (char)0,   (char)0,   (char)0,  (char)0};
    memcpy(test_msg->interface_name, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->interface_name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  if (sizeof(test_msg->ipv4_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv4_address[0]));
  }
  test_msg->ipv4_address[0] = 143;
  if (sizeof(test_msg->ipv4_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv4_address[0]));
  }
  test_msg->ipv4_address[1] = 241;
  if (sizeof(test_msg->ipv4_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv4_address[0]));
  }
  test_msg->ipv4_address[2] = 84;
  if (sizeof(test_msg->ipv4_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv4_address[0]));
  }
  test_msg->ipv4_address[3] = 180;
  test_msg->ipv4_mask_size = 152;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[0] = 194;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[1] = 137;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[2] = 32;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[3] = 44;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[4] = 114;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[5] = 147;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[6] = 68;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[7] = 222;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[8] = 92;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[9] = 192;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[10] = 78;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[11] = 235;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[12] = 63;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[13] = 208;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[14] = 114;
  if (sizeof(test_msg->ipv6_address) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->ipv6_address[0]));
  }
  test_msg->ipv6_address[15] = 53;
  test_msg->ipv6_mask_size = 183;
  test_msg->rx_bytes = 451408920;
  test_msg->tx_bytes = 59251049;

  EXPECT_EQ(send_message(0xbb, 3880, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 3880);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->flags, 2471552451)
      << "incorrect value for flags, expected 2471552451, is "
      << last_msg_->flags;
  {
    const char check_string[] = {(char)105, (char)102, (char)48, (char)0,
                                 (char)0,   (char)0,   (char)0,  (char)0,
                                 (char)0,   (char)0,   (char)0,  (char)0,
                                 (char)0,   (char)0,   (char)0,  (char)0};
    EXPECT_EQ(
        memcmp(last_msg_->interface_name, check_string, sizeof(check_string)),
        0)
        << "incorrect value for last_msg_->interface_name, expected string '"
        << check_string << "', is '" << last_msg_->interface_name << "'";
  }
  EXPECT_EQ(last_msg_->ipv4_address[0], 143)
      << "incorrect value for ipv4_address[0], expected 143, is "
      << last_msg_->ipv4_address[0];
  EXPECT_EQ(last_msg_->ipv4_address[1], 241)
      << "incorrect value for ipv4_address[1], expected 241, is "
      << last_msg_->ipv4_address[1];
  EXPECT_EQ(last_msg_->ipv4_address[2], 84)
      << "incorrect value for ipv4_address[2], expected 84, is "
      << last_msg_->ipv4_address[2];
  EXPECT_EQ(last_msg_->ipv4_address[3], 180)
      << "incorrect value for ipv4_address[3], expected 180, is "
      << last_msg_->ipv4_address[3];
  EXPECT_EQ(last_msg_->ipv4_mask_size, 152)
      << "incorrect value for ipv4_mask_size, expected 152, is "
      << last_msg_->ipv4_mask_size;
  EXPECT_EQ(last_msg_->ipv6_address[0], 194)
      << "incorrect value for ipv6_address[0], expected 194, is "
      << last_msg_->ipv6_address[0];
  EXPECT_EQ(last_msg_->ipv6_address[1], 137)
      << "incorrect value for ipv6_address[1], expected 137, is "
      << last_msg_->ipv6_address[1];
  EXPECT_EQ(last_msg_->ipv6_address[2], 32)
      << "incorrect value for ipv6_address[2], expected 32, is "
      << last_msg_->ipv6_address[2];
  EXPECT_EQ(last_msg_->ipv6_address[3], 44)
      << "incorrect value for ipv6_address[3], expected 44, is "
      << last_msg_->ipv6_address[3];
  EXPECT_EQ(last_msg_->ipv6_address[4], 114)
      << "incorrect value for ipv6_address[4], expected 114, is "
      << last_msg_->ipv6_address[4];
  EXPECT_EQ(last_msg_->ipv6_address[5], 147)
      << "incorrect value for ipv6_address[5], expected 147, is "
      << last_msg_->ipv6_address[5];
  EXPECT_EQ(last_msg_->ipv6_address[6], 68)
      << "incorrect value for ipv6_address[6], expected 68, is "
      << last_msg_->ipv6_address[6];
  EXPECT_EQ(last_msg_->ipv6_address[7], 222)
      << "incorrect value for ipv6_address[7], expected 222, is "
      << last_msg_->ipv6_address[7];
  EXPECT_EQ(last_msg_->ipv6_address[8], 92)
      << "incorrect value for ipv6_address[8], expected 92, is "
      << last_msg_->ipv6_address[8];
  EXPECT_EQ(last_msg_->ipv6_address[9], 192)
      << "incorrect value for ipv6_address[9], expected 192, is "
      << last_msg_->ipv6_address[9];
  EXPECT_EQ(last_msg_->ipv6_address[10], 78)
      << "incorrect value for ipv6_address[10], expected 78, is "
      << last_msg_->ipv6_address[10];
  EXPECT_EQ(last_msg_->ipv6_address[11], 235)
      << "incorrect value for ipv6_address[11], expected 235, is "
      << last_msg_->ipv6_address[11];
  EXPECT_EQ(last_msg_->ipv6_address[12], 63)
      << "incorrect value for ipv6_address[12], expected 63, is "
      << last_msg_->ipv6_address[12];
  EXPECT_EQ(last_msg_->ipv6_address[13], 208)
      << "incorrect value for ipv6_address[13], expected 208, is "
      << last_msg_->ipv6_address[13];
  EXPECT_EQ(last_msg_->ipv6_address[14], 114)
      << "incorrect value for ipv6_address[14], expected 114, is "
      << last_msg_->ipv6_address[14];
  EXPECT_EQ(last_msg_->ipv6_address[15], 53)
      << "incorrect value for ipv6_address[15], expected 53, is "
      << last_msg_->ipv6_address[15];
  EXPECT_EQ(last_msg_->ipv6_mask_size, 183)
      << "incorrect value for ipv6_mask_size, expected 183, is "
      << last_msg_->ipv6_mask_size;
  EXPECT_EQ(last_msg_->rx_bytes, 451408920)
      << "incorrect value for rx_bytes, expected 451408920, is "
      << last_msg_->rx_bytes;
  EXPECT_EQ(last_msg_->tx_bytes, 59251049)
      << "incorrect value for tx_bytes, expected 59251049, is "
      << last_msg_->tx_bytes;
}
