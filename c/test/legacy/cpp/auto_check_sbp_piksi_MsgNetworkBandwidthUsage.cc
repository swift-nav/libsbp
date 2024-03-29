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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgNetworkBandwidthUsage.yaml by
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

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_piksi_MsgNetworkBandwidthUsage0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_network_bandwidth_usage_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgNetworkBandwidthUsage0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_network_bandwidth_usage_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_network_bandwidth_usage_t *>(
            last_msg_storage_)),
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
                      const msg_network_bandwidth_usage_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_network_bandwidth_usage_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgNetworkBandwidthUsage0, Test) {
  uint8_t encoded_frame[] = {
      85,  189, 0,   207, 121, 200, 94,  105, 178, 128, 0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      99,  97,  110, 48,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   94,  105, 178, 128, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   99,  97,  110, 49,  0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   94,  105, 178, 128,
      0,   0,   0,   0,   165, 235, 94,  203, 0,   0,   0,   0,   237, 14,  148,
      240, 184, 220, 202, 218, 101, 116, 104, 48,  0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   94,  105, 178, 128, 0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      108, 111, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   94,  105, 178, 128, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   115, 105, 116, 48,  0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   27,  133,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_network_bandwidth_usage_t *test_msg =
      (msg_network_bandwidth_usage_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->interfaces) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->interfaces[0]));
  }
  test_msg->interfaces[0].duration = 2159176030;
  {
    const char assign_string[] = {(char)99, (char)97, (char)110, (char)48,
                                  (char)0,  (char)0,  (char)0,   (char)0,
                                  (char)0,  (char)0,  (char)0,   (char)0,
                                  (char)0,  (char)0,  (char)0,   (char)0};
    memcpy(test_msg->interfaces[0].interface_name, assign_string,
           sizeof(assign_string));
    if (sizeof(test_msg->interfaces[0].interface_name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->interfaces[0].rx_bytes = 0;
  test_msg->interfaces[0].total_bytes = 0;
  test_msg->interfaces[0].tx_bytes = 0;
  if (sizeof(test_msg->interfaces) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->interfaces[0]));
  }
  test_msg->interfaces[1].duration = 2159176030;
  {
    const char assign_string[] = {(char)99, (char)97, (char)110, (char)49,
                                  (char)0,  (char)0,  (char)0,   (char)0,
                                  (char)0,  (char)0,  (char)0,   (char)0,
                                  (char)0,  (char)0,  (char)0,   (char)0};
    memcpy(test_msg->interfaces[1].interface_name, assign_string,
           sizeof(assign_string));
    if (sizeof(test_msg->interfaces[1].interface_name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->interfaces[1].rx_bytes = 0;
  test_msg->interfaces[1].total_bytes = 0;
  test_msg->interfaces[1].tx_bytes = 0;
  if (sizeof(test_msg->interfaces) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->interfaces[0]));
  }
  test_msg->interfaces[2].duration = 2159176030;
  {
    const char assign_string[] = {(char)101, (char)116, (char)104, (char)48,
                                  (char)0,   (char)0,   (char)0,   (char)0,
                                  (char)0,   (char)0,   (char)0,   (char)0,
                                  (char)0,   (char)0,   (char)0,   (char)0};
    memcpy(test_msg->interfaces[2].interface_name, assign_string,
           sizeof(assign_string));
    if (sizeof(test_msg->interfaces[2].interface_name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->interfaces[2].rx_bytes = 4036234989;
  test_msg->interfaces[2].total_bytes = 3411995557;
  test_msg->interfaces[2].tx_bytes = 3670727864;
  if (sizeof(test_msg->interfaces) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->interfaces[0]));
  }
  test_msg->interfaces[3].duration = 2159176030;
  {
    const char assign_string[] = {(char)108, (char)111, (char)0, (char)0,
                                  (char)0,   (char)0,   (char)0, (char)0,
                                  (char)0,   (char)0,   (char)0, (char)0,
                                  (char)0,   (char)0,   (char)0, (char)0};
    memcpy(test_msg->interfaces[3].interface_name, assign_string,
           sizeof(assign_string));
    if (sizeof(test_msg->interfaces[3].interface_name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->interfaces[3].rx_bytes = 0;
  test_msg->interfaces[3].total_bytes = 0;
  test_msg->interfaces[3].tx_bytes = 0;
  if (sizeof(test_msg->interfaces) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->interfaces[0]));
  }
  test_msg->interfaces[4].duration = 2159176030;
  {
    const char assign_string[] = {(char)115, (char)105, (char)116, (char)48,
                                  (char)0,   (char)0,   (char)0,   (char)0,
                                  (char)0,   (char)0,   (char)0,   (char)0,
                                  (char)0,   (char)0,   (char)0,   (char)0};
    memcpy(test_msg->interfaces[4].interface_name, assign_string,
           sizeof(assign_string));
    if (sizeof(test_msg->interfaces[4].interface_name) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->interfaces[4].rx_bytes = 0;
  test_msg->interfaces[4].total_bytes = 0;
  test_msg->interfaces[4].tx_bytes = 0;

  EXPECT_EQ(send_message(0xBD, 31183, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 31183);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[0].duration)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[0].duration)),
            2159176030)
      << "incorrect value for interfaces[0].duration, expected 2159176030, is "
      << last_msg_->interfaces[0].duration;
  {
    const char check_string[] = {(char)99, (char)97, (char)110, (char)48,
                                 (char)0,  (char)0,  (char)0,   (char)0,
                                 (char)0,  (char)0,  (char)0,   (char)0,
                                 (char)0,  (char)0,  (char)0,   (char)0};
    EXPECT_EQ(memcmp(last_msg_->interfaces[0].interface_name, check_string,
                     sizeof(check_string)),
              0)
        << "incorrect value for last_msg_->interfaces[0].interface_name, "
           "expected string '"
        << check_string << "', is '" << last_msg_->interfaces[0].interface_name
        << "'";
  }
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[0].rx_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[0].rx_bytes)),
            0)
      << "incorrect value for interfaces[0].rx_bytes, expected 0, is "
      << last_msg_->interfaces[0].rx_bytes;
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[0].total_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[0].total_bytes)),
            0)
      << "incorrect value for interfaces[0].total_bytes, expected 0, is "
      << last_msg_->interfaces[0].total_bytes;
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[0].tx_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[0].tx_bytes)),
            0)
      << "incorrect value for interfaces[0].tx_bytes, expected 0, is "
      << last_msg_->interfaces[0].tx_bytes;
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[1].duration)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[1].duration)),
            2159176030)
      << "incorrect value for interfaces[1].duration, expected 2159176030, is "
      << last_msg_->interfaces[1].duration;
  {
    const char check_string[] = {(char)99, (char)97, (char)110, (char)49,
                                 (char)0,  (char)0,  (char)0,   (char)0,
                                 (char)0,  (char)0,  (char)0,   (char)0,
                                 (char)0,  (char)0,  (char)0,   (char)0};
    EXPECT_EQ(memcmp(last_msg_->interfaces[1].interface_name, check_string,
                     sizeof(check_string)),
              0)
        << "incorrect value for last_msg_->interfaces[1].interface_name, "
           "expected string '"
        << check_string << "', is '" << last_msg_->interfaces[1].interface_name
        << "'";
  }
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[1].rx_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[1].rx_bytes)),
            0)
      << "incorrect value for interfaces[1].rx_bytes, expected 0, is "
      << last_msg_->interfaces[1].rx_bytes;
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[1].total_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[1].total_bytes)),
            0)
      << "incorrect value for interfaces[1].total_bytes, expected 0, is "
      << last_msg_->interfaces[1].total_bytes;
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[1].tx_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[1].tx_bytes)),
            0)
      << "incorrect value for interfaces[1].tx_bytes, expected 0, is "
      << last_msg_->interfaces[1].tx_bytes;
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[2].duration)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[2].duration)),
            2159176030)
      << "incorrect value for interfaces[2].duration, expected 2159176030, is "
      << last_msg_->interfaces[2].duration;
  {
    const char check_string[] = {(char)101, (char)116, (char)104, (char)48,
                                 (char)0,   (char)0,   (char)0,   (char)0,
                                 (char)0,   (char)0,   (char)0,   (char)0,
                                 (char)0,   (char)0,   (char)0,   (char)0};
    EXPECT_EQ(memcmp(last_msg_->interfaces[2].interface_name, check_string,
                     sizeof(check_string)),
              0)
        << "incorrect value for last_msg_->interfaces[2].interface_name, "
           "expected string '"
        << check_string << "', is '" << last_msg_->interfaces[2].interface_name
        << "'";
  }
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[2].rx_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[2].rx_bytes)),
            4036234989)
      << "incorrect value for interfaces[2].rx_bytes, expected 4036234989, is "
      << last_msg_->interfaces[2].rx_bytes;
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[2].total_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[2].total_bytes)),
            3411995557)
      << "incorrect value for interfaces[2].total_bytes, expected 3411995557, "
         "is "
      << last_msg_->interfaces[2].total_bytes;
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[2].tx_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[2].tx_bytes)),
            3670727864)
      << "incorrect value for interfaces[2].tx_bytes, expected 3670727864, is "
      << last_msg_->interfaces[2].tx_bytes;
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[3].duration)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[3].duration)),
            2159176030)
      << "incorrect value for interfaces[3].duration, expected 2159176030, is "
      << last_msg_->interfaces[3].duration;
  {
    const char check_string[] = {(char)108, (char)111, (char)0, (char)0,
                                 (char)0,   (char)0,   (char)0, (char)0,
                                 (char)0,   (char)0,   (char)0, (char)0,
                                 (char)0,   (char)0,   (char)0, (char)0};
    EXPECT_EQ(memcmp(last_msg_->interfaces[3].interface_name, check_string,
                     sizeof(check_string)),
              0)
        << "incorrect value for last_msg_->interfaces[3].interface_name, "
           "expected string '"
        << check_string << "', is '" << last_msg_->interfaces[3].interface_name
        << "'";
  }
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[3].rx_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[3].rx_bytes)),
            0)
      << "incorrect value for interfaces[3].rx_bytes, expected 0, is "
      << last_msg_->interfaces[3].rx_bytes;
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[3].total_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[3].total_bytes)),
            0)
      << "incorrect value for interfaces[3].total_bytes, expected 0, is "
      << last_msg_->interfaces[3].total_bytes;
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[3].tx_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[3].tx_bytes)),
            0)
      << "incorrect value for interfaces[3].tx_bytes, expected 0, is "
      << last_msg_->interfaces[3].tx_bytes;
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[4].duration)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[4].duration)),
            2159176030)
      << "incorrect value for interfaces[4].duration, expected 2159176030, is "
      << last_msg_->interfaces[4].duration;
  {
    const char check_string[] = {(char)115, (char)105, (char)116, (char)48,
                                 (char)0,   (char)0,   (char)0,   (char)0,
                                 (char)0,   (char)0,   (char)0,   (char)0,
                                 (char)0,   (char)0,   (char)0,   (char)0};
    EXPECT_EQ(memcmp(last_msg_->interfaces[4].interface_name, check_string,
                     sizeof(check_string)),
              0)
        << "incorrect value for last_msg_->interfaces[4].interface_name, "
           "expected string '"
        << check_string << "', is '" << last_msg_->interfaces[4].interface_name
        << "'";
  }
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[4].rx_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[4].rx_bytes)),
            0)
      << "incorrect value for interfaces[4].rx_bytes, expected 0, is "
      << last_msg_->interfaces[4].rx_bytes;
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[4].total_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[4].total_bytes)),
            0)
      << "incorrect value for interfaces[4].total_bytes, expected 0, is "
      << last_msg_->interfaces[4].total_bytes;
  EXPECT_EQ(get_as<decltype(last_msg_->interfaces[4].tx_bytes)>(
                reinterpret_cast<const uint8_t *>(
                    &last_msg_->interfaces[4].tx_bytes)),
            0)
      << "incorrect value for interfaces[4].tx_bytes, expected 0, is "
      << last_msg_->interfaces[4].tx_bytes;
}
