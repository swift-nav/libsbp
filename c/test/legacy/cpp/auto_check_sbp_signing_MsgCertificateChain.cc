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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgCertificateChain.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_signing_MsgCertificateChain0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_certificate_chain_t> {
 public:
  Test_legacy_auto_check_sbp_signing_MsgCertificateChain0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_certificate_chain_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_certificate_chain_t *>(last_msg_storage_)),
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
                      const msg_certificate_chain_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_certificate_chain_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_signing_MsgCertificateChain0, Test) {
  uint8_t encoded_frame[] = {
      85, 5,  12,  66, 0,  135, 0,  1,  2,  3,  4,   5,  6,  7,   8,   9,
      10, 11, 12,  13, 14, 15,  16, 17, 18, 19, 10,  11, 12, 13,  14,  15,
      16, 17, 18,  19, 0,  1,   2,  3,  4,  5,  6,   7,  8,  9,   20,  21,
      22, 23, 24,  25, 26, 27,  28, 29, 10, 11, 12,  13, 14, 15,  16,  17,
      18, 19, 232, 7,  3,  30,  12, 34, 59, 21, 205, 91, 7,  0,   1,   2,
      3,  4,  5,   6,  7,  0,   1,  2,  3,  4,  5,   6,  7,  0,   1,   2,
      3,  4,  5,   6,  7,  0,   1,  2,  3,  4,  5,   6,  7,  0,   1,   2,
      3,  4,  5,   6,  7,  0,   1,  2,  3,  4,  5,   6,  7,  0,   1,   2,
      3,  4,  5,   6,  7,  0,   1,  2,  3,  4,  5,   6,  7,  112, 100,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_certificate_chain_t *test_msg =
      (msg_certificate_chain_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[0] = 20;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[1] = 21;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[2] = 22;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[3] = 23;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[4] = 24;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[5] = 25;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[6] = 26;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[7] = 27;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[8] = 28;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[9] = 29;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[10] = 10;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[11] = 11;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[12] = 12;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[13] = 13;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[14] = 14;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[15] = 15;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[16] = 16;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[17] = 17;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[18] = 18;
  if (sizeof(test_msg->corrections_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->corrections_certificate[0]));
  }
  test_msg->corrections_certificate[19] = 19;
  test_msg->expiration.day = 30;
  test_msg->expiration.hours = 12;
  test_msg->expiration.minutes = 34;
  test_msg->expiration.month = 3;
  test_msg->expiration.ns = 123456789;
  test_msg->expiration.seconds = 59;
  test_msg->expiration.year = 2024;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[0] = 10;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[1] = 11;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[2] = 12;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[3] = 13;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[4] = 14;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[5] = 15;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[6] = 16;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[7] = 17;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[8] = 18;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[9] = 19;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[10] = 0;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[11] = 1;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[12] = 2;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[13] = 3;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[14] = 4;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[15] = 5;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[16] = 6;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[17] = 7;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[18] = 8;
  if (sizeof(test_msg->intermediate_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->intermediate_certificate[0]));
  }
  test_msg->intermediate_certificate[19] = 9;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[0] = 0;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[1] = 1;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[2] = 2;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[3] = 3;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[4] = 4;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[5] = 5;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[6] = 6;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[7] = 7;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[8] = 8;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[9] = 9;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[10] = 10;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[11] = 11;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[12] = 12;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[13] = 13;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[14] = 14;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[15] = 15;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[16] = 16;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[17] = 17;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[18] = 18;
  if (sizeof(test_msg->root_certificate) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->root_certificate[0]));
  }
  test_msg->root_certificate[19] = 19;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[0] = 0;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[1] = 1;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[2] = 2;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[3] = 3;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[4] = 4;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[5] = 5;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[6] = 6;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[7] = 7;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[8] = 0;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[9] = 1;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[10] = 2;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[11] = 3;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[12] = 4;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[13] = 5;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[14] = 6;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[15] = 7;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[16] = 0;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[17] = 1;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[18] = 2;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[19] = 3;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[20] = 4;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[21] = 5;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[22] = 6;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[23] = 7;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[24] = 0;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[25] = 1;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[26] = 2;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[27] = 3;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[28] = 4;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[29] = 5;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[30] = 6;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[31] = 7;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[32] = 0;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[33] = 1;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[34] = 2;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[35] = 3;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[36] = 4;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[37] = 5;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[38] = 6;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[39] = 7;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[40] = 0;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[41] = 1;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[42] = 2;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[43] = 3;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[44] = 4;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[45] = 5;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[46] = 6;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[47] = 7;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[48] = 0;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[49] = 1;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[50] = 2;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[51] = 3;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[52] = 4;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[53] = 5;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[54] = 6;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[55] = 7;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[56] = 0;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[57] = 1;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[58] = 2;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[59] = 3;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[60] = 4;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[61] = 5;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[62] = 6;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[63] = 7;

  EXPECT_EQ(send_message(0xC05, 66, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->corrections_certificate[0], 20)
      << "incorrect value for corrections_certificate[0], expected 20, is "
      << last_msg_->corrections_certificate[0];
  EXPECT_EQ(last_msg_->corrections_certificate[1], 21)
      << "incorrect value for corrections_certificate[1], expected 21, is "
      << last_msg_->corrections_certificate[1];
  EXPECT_EQ(last_msg_->corrections_certificate[2], 22)
      << "incorrect value for corrections_certificate[2], expected 22, is "
      << last_msg_->corrections_certificate[2];
  EXPECT_EQ(last_msg_->corrections_certificate[3], 23)
      << "incorrect value for corrections_certificate[3], expected 23, is "
      << last_msg_->corrections_certificate[3];
  EXPECT_EQ(last_msg_->corrections_certificate[4], 24)
      << "incorrect value for corrections_certificate[4], expected 24, is "
      << last_msg_->corrections_certificate[4];
  EXPECT_EQ(last_msg_->corrections_certificate[5], 25)
      << "incorrect value for corrections_certificate[5], expected 25, is "
      << last_msg_->corrections_certificate[5];
  EXPECT_EQ(last_msg_->corrections_certificate[6], 26)
      << "incorrect value for corrections_certificate[6], expected 26, is "
      << last_msg_->corrections_certificate[6];
  EXPECT_EQ(last_msg_->corrections_certificate[7], 27)
      << "incorrect value for corrections_certificate[7], expected 27, is "
      << last_msg_->corrections_certificate[7];
  EXPECT_EQ(last_msg_->corrections_certificate[8], 28)
      << "incorrect value for corrections_certificate[8], expected 28, is "
      << last_msg_->corrections_certificate[8];
  EXPECT_EQ(last_msg_->corrections_certificate[9], 29)
      << "incorrect value for corrections_certificate[9], expected 29, is "
      << last_msg_->corrections_certificate[9];
  EXPECT_EQ(last_msg_->corrections_certificate[10], 10)
      << "incorrect value for corrections_certificate[10], expected 10, is "
      << last_msg_->corrections_certificate[10];
  EXPECT_EQ(last_msg_->corrections_certificate[11], 11)
      << "incorrect value for corrections_certificate[11], expected 11, is "
      << last_msg_->corrections_certificate[11];
  EXPECT_EQ(last_msg_->corrections_certificate[12], 12)
      << "incorrect value for corrections_certificate[12], expected 12, is "
      << last_msg_->corrections_certificate[12];
  EXPECT_EQ(last_msg_->corrections_certificate[13], 13)
      << "incorrect value for corrections_certificate[13], expected 13, is "
      << last_msg_->corrections_certificate[13];
  EXPECT_EQ(last_msg_->corrections_certificate[14], 14)
      << "incorrect value for corrections_certificate[14], expected 14, is "
      << last_msg_->corrections_certificate[14];
  EXPECT_EQ(last_msg_->corrections_certificate[15], 15)
      << "incorrect value for corrections_certificate[15], expected 15, is "
      << last_msg_->corrections_certificate[15];
  EXPECT_EQ(last_msg_->corrections_certificate[16], 16)
      << "incorrect value for corrections_certificate[16], expected 16, is "
      << last_msg_->corrections_certificate[16];
  EXPECT_EQ(last_msg_->corrections_certificate[17], 17)
      << "incorrect value for corrections_certificate[17], expected 17, is "
      << last_msg_->corrections_certificate[17];
  EXPECT_EQ(last_msg_->corrections_certificate[18], 18)
      << "incorrect value for corrections_certificate[18], expected 18, is "
      << last_msg_->corrections_certificate[18];
  EXPECT_EQ(last_msg_->corrections_certificate[19], 19)
      << "incorrect value for corrections_certificate[19], expected 19, is "
      << last_msg_->corrections_certificate[19];
  EXPECT_EQ(last_msg_->expiration.day, 30)
      << "incorrect value for expiration.day, expected 30, is "
      << last_msg_->expiration.day;
  EXPECT_EQ(last_msg_->expiration.hours, 12)
      << "incorrect value for expiration.hours, expected 12, is "
      << last_msg_->expiration.hours;
  EXPECT_EQ(last_msg_->expiration.minutes, 34)
      << "incorrect value for expiration.minutes, expected 34, is "
      << last_msg_->expiration.minutes;
  EXPECT_EQ(last_msg_->expiration.month, 3)
      << "incorrect value for expiration.month, expected 3, is "
      << last_msg_->expiration.month;
  EXPECT_EQ(last_msg_->expiration.ns, 123456789)
      << "incorrect value for expiration.ns, expected 123456789, is "
      << last_msg_->expiration.ns;
  EXPECT_EQ(last_msg_->expiration.seconds, 59)
      << "incorrect value for expiration.seconds, expected 59, is "
      << last_msg_->expiration.seconds;
  EXPECT_EQ(last_msg_->expiration.year, 2024)
      << "incorrect value for expiration.year, expected 2024, is "
      << last_msg_->expiration.year;
  EXPECT_EQ(last_msg_->intermediate_certificate[0], 10)
      << "incorrect value for intermediate_certificate[0], expected 10, is "
      << last_msg_->intermediate_certificate[0];
  EXPECT_EQ(last_msg_->intermediate_certificate[1], 11)
      << "incorrect value for intermediate_certificate[1], expected 11, is "
      << last_msg_->intermediate_certificate[1];
  EXPECT_EQ(last_msg_->intermediate_certificate[2], 12)
      << "incorrect value for intermediate_certificate[2], expected 12, is "
      << last_msg_->intermediate_certificate[2];
  EXPECT_EQ(last_msg_->intermediate_certificate[3], 13)
      << "incorrect value for intermediate_certificate[3], expected 13, is "
      << last_msg_->intermediate_certificate[3];
  EXPECT_EQ(last_msg_->intermediate_certificate[4], 14)
      << "incorrect value for intermediate_certificate[4], expected 14, is "
      << last_msg_->intermediate_certificate[4];
  EXPECT_EQ(last_msg_->intermediate_certificate[5], 15)
      << "incorrect value for intermediate_certificate[5], expected 15, is "
      << last_msg_->intermediate_certificate[5];
  EXPECT_EQ(last_msg_->intermediate_certificate[6], 16)
      << "incorrect value for intermediate_certificate[6], expected 16, is "
      << last_msg_->intermediate_certificate[6];
  EXPECT_EQ(last_msg_->intermediate_certificate[7], 17)
      << "incorrect value for intermediate_certificate[7], expected 17, is "
      << last_msg_->intermediate_certificate[7];
  EXPECT_EQ(last_msg_->intermediate_certificate[8], 18)
      << "incorrect value for intermediate_certificate[8], expected 18, is "
      << last_msg_->intermediate_certificate[8];
  EXPECT_EQ(last_msg_->intermediate_certificate[9], 19)
      << "incorrect value for intermediate_certificate[9], expected 19, is "
      << last_msg_->intermediate_certificate[9];
  EXPECT_EQ(last_msg_->intermediate_certificate[10], 0)
      << "incorrect value for intermediate_certificate[10], expected 0, is "
      << last_msg_->intermediate_certificate[10];
  EXPECT_EQ(last_msg_->intermediate_certificate[11], 1)
      << "incorrect value for intermediate_certificate[11], expected 1, is "
      << last_msg_->intermediate_certificate[11];
  EXPECT_EQ(last_msg_->intermediate_certificate[12], 2)
      << "incorrect value for intermediate_certificate[12], expected 2, is "
      << last_msg_->intermediate_certificate[12];
  EXPECT_EQ(last_msg_->intermediate_certificate[13], 3)
      << "incorrect value for intermediate_certificate[13], expected 3, is "
      << last_msg_->intermediate_certificate[13];
  EXPECT_EQ(last_msg_->intermediate_certificate[14], 4)
      << "incorrect value for intermediate_certificate[14], expected 4, is "
      << last_msg_->intermediate_certificate[14];
  EXPECT_EQ(last_msg_->intermediate_certificate[15], 5)
      << "incorrect value for intermediate_certificate[15], expected 5, is "
      << last_msg_->intermediate_certificate[15];
  EXPECT_EQ(last_msg_->intermediate_certificate[16], 6)
      << "incorrect value for intermediate_certificate[16], expected 6, is "
      << last_msg_->intermediate_certificate[16];
  EXPECT_EQ(last_msg_->intermediate_certificate[17], 7)
      << "incorrect value for intermediate_certificate[17], expected 7, is "
      << last_msg_->intermediate_certificate[17];
  EXPECT_EQ(last_msg_->intermediate_certificate[18], 8)
      << "incorrect value for intermediate_certificate[18], expected 8, is "
      << last_msg_->intermediate_certificate[18];
  EXPECT_EQ(last_msg_->intermediate_certificate[19], 9)
      << "incorrect value for intermediate_certificate[19], expected 9, is "
      << last_msg_->intermediate_certificate[19];
  EXPECT_EQ(last_msg_->root_certificate[0], 0)
      << "incorrect value for root_certificate[0], expected 0, is "
      << last_msg_->root_certificate[0];
  EXPECT_EQ(last_msg_->root_certificate[1], 1)
      << "incorrect value for root_certificate[1], expected 1, is "
      << last_msg_->root_certificate[1];
  EXPECT_EQ(last_msg_->root_certificate[2], 2)
      << "incorrect value for root_certificate[2], expected 2, is "
      << last_msg_->root_certificate[2];
  EXPECT_EQ(last_msg_->root_certificate[3], 3)
      << "incorrect value for root_certificate[3], expected 3, is "
      << last_msg_->root_certificate[3];
  EXPECT_EQ(last_msg_->root_certificate[4], 4)
      << "incorrect value for root_certificate[4], expected 4, is "
      << last_msg_->root_certificate[4];
  EXPECT_EQ(last_msg_->root_certificate[5], 5)
      << "incorrect value for root_certificate[5], expected 5, is "
      << last_msg_->root_certificate[5];
  EXPECT_EQ(last_msg_->root_certificate[6], 6)
      << "incorrect value for root_certificate[6], expected 6, is "
      << last_msg_->root_certificate[6];
  EXPECT_EQ(last_msg_->root_certificate[7], 7)
      << "incorrect value for root_certificate[7], expected 7, is "
      << last_msg_->root_certificate[7];
  EXPECT_EQ(last_msg_->root_certificate[8], 8)
      << "incorrect value for root_certificate[8], expected 8, is "
      << last_msg_->root_certificate[8];
  EXPECT_EQ(last_msg_->root_certificate[9], 9)
      << "incorrect value for root_certificate[9], expected 9, is "
      << last_msg_->root_certificate[9];
  EXPECT_EQ(last_msg_->root_certificate[10], 10)
      << "incorrect value for root_certificate[10], expected 10, is "
      << last_msg_->root_certificate[10];
  EXPECT_EQ(last_msg_->root_certificate[11], 11)
      << "incorrect value for root_certificate[11], expected 11, is "
      << last_msg_->root_certificate[11];
  EXPECT_EQ(last_msg_->root_certificate[12], 12)
      << "incorrect value for root_certificate[12], expected 12, is "
      << last_msg_->root_certificate[12];
  EXPECT_EQ(last_msg_->root_certificate[13], 13)
      << "incorrect value for root_certificate[13], expected 13, is "
      << last_msg_->root_certificate[13];
  EXPECT_EQ(last_msg_->root_certificate[14], 14)
      << "incorrect value for root_certificate[14], expected 14, is "
      << last_msg_->root_certificate[14];
  EXPECT_EQ(last_msg_->root_certificate[15], 15)
      << "incorrect value for root_certificate[15], expected 15, is "
      << last_msg_->root_certificate[15];
  EXPECT_EQ(last_msg_->root_certificate[16], 16)
      << "incorrect value for root_certificate[16], expected 16, is "
      << last_msg_->root_certificate[16];
  EXPECT_EQ(last_msg_->root_certificate[17], 17)
      << "incorrect value for root_certificate[17], expected 17, is "
      << last_msg_->root_certificate[17];
  EXPECT_EQ(last_msg_->root_certificate[18], 18)
      << "incorrect value for root_certificate[18], expected 18, is "
      << last_msg_->root_certificate[18];
  EXPECT_EQ(last_msg_->root_certificate[19], 19)
      << "incorrect value for root_certificate[19], expected 19, is "
      << last_msg_->root_certificate[19];
  EXPECT_EQ(last_msg_->signature[0], 0)
      << "incorrect value for signature[0], expected 0, is "
      << last_msg_->signature[0];
  EXPECT_EQ(last_msg_->signature[1], 1)
      << "incorrect value for signature[1], expected 1, is "
      << last_msg_->signature[1];
  EXPECT_EQ(last_msg_->signature[2], 2)
      << "incorrect value for signature[2], expected 2, is "
      << last_msg_->signature[2];
  EXPECT_EQ(last_msg_->signature[3], 3)
      << "incorrect value for signature[3], expected 3, is "
      << last_msg_->signature[3];
  EXPECT_EQ(last_msg_->signature[4], 4)
      << "incorrect value for signature[4], expected 4, is "
      << last_msg_->signature[4];
  EXPECT_EQ(last_msg_->signature[5], 5)
      << "incorrect value for signature[5], expected 5, is "
      << last_msg_->signature[5];
  EXPECT_EQ(last_msg_->signature[6], 6)
      << "incorrect value for signature[6], expected 6, is "
      << last_msg_->signature[6];
  EXPECT_EQ(last_msg_->signature[7], 7)
      << "incorrect value for signature[7], expected 7, is "
      << last_msg_->signature[7];
  EXPECT_EQ(last_msg_->signature[8], 0)
      << "incorrect value for signature[8], expected 0, is "
      << last_msg_->signature[8];
  EXPECT_EQ(last_msg_->signature[9], 1)
      << "incorrect value for signature[9], expected 1, is "
      << last_msg_->signature[9];
  EXPECT_EQ(last_msg_->signature[10], 2)
      << "incorrect value for signature[10], expected 2, is "
      << last_msg_->signature[10];
  EXPECT_EQ(last_msg_->signature[11], 3)
      << "incorrect value for signature[11], expected 3, is "
      << last_msg_->signature[11];
  EXPECT_EQ(last_msg_->signature[12], 4)
      << "incorrect value for signature[12], expected 4, is "
      << last_msg_->signature[12];
  EXPECT_EQ(last_msg_->signature[13], 5)
      << "incorrect value for signature[13], expected 5, is "
      << last_msg_->signature[13];
  EXPECT_EQ(last_msg_->signature[14], 6)
      << "incorrect value for signature[14], expected 6, is "
      << last_msg_->signature[14];
  EXPECT_EQ(last_msg_->signature[15], 7)
      << "incorrect value for signature[15], expected 7, is "
      << last_msg_->signature[15];
  EXPECT_EQ(last_msg_->signature[16], 0)
      << "incorrect value for signature[16], expected 0, is "
      << last_msg_->signature[16];
  EXPECT_EQ(last_msg_->signature[17], 1)
      << "incorrect value for signature[17], expected 1, is "
      << last_msg_->signature[17];
  EXPECT_EQ(last_msg_->signature[18], 2)
      << "incorrect value for signature[18], expected 2, is "
      << last_msg_->signature[18];
  EXPECT_EQ(last_msg_->signature[19], 3)
      << "incorrect value for signature[19], expected 3, is "
      << last_msg_->signature[19];
  EXPECT_EQ(last_msg_->signature[20], 4)
      << "incorrect value for signature[20], expected 4, is "
      << last_msg_->signature[20];
  EXPECT_EQ(last_msg_->signature[21], 5)
      << "incorrect value for signature[21], expected 5, is "
      << last_msg_->signature[21];
  EXPECT_EQ(last_msg_->signature[22], 6)
      << "incorrect value for signature[22], expected 6, is "
      << last_msg_->signature[22];
  EXPECT_EQ(last_msg_->signature[23], 7)
      << "incorrect value for signature[23], expected 7, is "
      << last_msg_->signature[23];
  EXPECT_EQ(last_msg_->signature[24], 0)
      << "incorrect value for signature[24], expected 0, is "
      << last_msg_->signature[24];
  EXPECT_EQ(last_msg_->signature[25], 1)
      << "incorrect value for signature[25], expected 1, is "
      << last_msg_->signature[25];
  EXPECT_EQ(last_msg_->signature[26], 2)
      << "incorrect value for signature[26], expected 2, is "
      << last_msg_->signature[26];
  EXPECT_EQ(last_msg_->signature[27], 3)
      << "incorrect value for signature[27], expected 3, is "
      << last_msg_->signature[27];
  EXPECT_EQ(last_msg_->signature[28], 4)
      << "incorrect value for signature[28], expected 4, is "
      << last_msg_->signature[28];
  EXPECT_EQ(last_msg_->signature[29], 5)
      << "incorrect value for signature[29], expected 5, is "
      << last_msg_->signature[29];
  EXPECT_EQ(last_msg_->signature[30], 6)
      << "incorrect value for signature[30], expected 6, is "
      << last_msg_->signature[30];
  EXPECT_EQ(last_msg_->signature[31], 7)
      << "incorrect value for signature[31], expected 7, is "
      << last_msg_->signature[31];
  EXPECT_EQ(last_msg_->signature[32], 0)
      << "incorrect value for signature[32], expected 0, is "
      << last_msg_->signature[32];
  EXPECT_EQ(last_msg_->signature[33], 1)
      << "incorrect value for signature[33], expected 1, is "
      << last_msg_->signature[33];
  EXPECT_EQ(last_msg_->signature[34], 2)
      << "incorrect value for signature[34], expected 2, is "
      << last_msg_->signature[34];
  EXPECT_EQ(last_msg_->signature[35], 3)
      << "incorrect value for signature[35], expected 3, is "
      << last_msg_->signature[35];
  EXPECT_EQ(last_msg_->signature[36], 4)
      << "incorrect value for signature[36], expected 4, is "
      << last_msg_->signature[36];
  EXPECT_EQ(last_msg_->signature[37], 5)
      << "incorrect value for signature[37], expected 5, is "
      << last_msg_->signature[37];
  EXPECT_EQ(last_msg_->signature[38], 6)
      << "incorrect value for signature[38], expected 6, is "
      << last_msg_->signature[38];
  EXPECT_EQ(last_msg_->signature[39], 7)
      << "incorrect value for signature[39], expected 7, is "
      << last_msg_->signature[39];
  EXPECT_EQ(last_msg_->signature[40], 0)
      << "incorrect value for signature[40], expected 0, is "
      << last_msg_->signature[40];
  EXPECT_EQ(last_msg_->signature[41], 1)
      << "incorrect value for signature[41], expected 1, is "
      << last_msg_->signature[41];
  EXPECT_EQ(last_msg_->signature[42], 2)
      << "incorrect value for signature[42], expected 2, is "
      << last_msg_->signature[42];
  EXPECT_EQ(last_msg_->signature[43], 3)
      << "incorrect value for signature[43], expected 3, is "
      << last_msg_->signature[43];
  EXPECT_EQ(last_msg_->signature[44], 4)
      << "incorrect value for signature[44], expected 4, is "
      << last_msg_->signature[44];
  EXPECT_EQ(last_msg_->signature[45], 5)
      << "incorrect value for signature[45], expected 5, is "
      << last_msg_->signature[45];
  EXPECT_EQ(last_msg_->signature[46], 6)
      << "incorrect value for signature[46], expected 6, is "
      << last_msg_->signature[46];
  EXPECT_EQ(last_msg_->signature[47], 7)
      << "incorrect value for signature[47], expected 7, is "
      << last_msg_->signature[47];
  EXPECT_EQ(last_msg_->signature[48], 0)
      << "incorrect value for signature[48], expected 0, is "
      << last_msg_->signature[48];
  EXPECT_EQ(last_msg_->signature[49], 1)
      << "incorrect value for signature[49], expected 1, is "
      << last_msg_->signature[49];
  EXPECT_EQ(last_msg_->signature[50], 2)
      << "incorrect value for signature[50], expected 2, is "
      << last_msg_->signature[50];
  EXPECT_EQ(last_msg_->signature[51], 3)
      << "incorrect value for signature[51], expected 3, is "
      << last_msg_->signature[51];
  EXPECT_EQ(last_msg_->signature[52], 4)
      << "incorrect value for signature[52], expected 4, is "
      << last_msg_->signature[52];
  EXPECT_EQ(last_msg_->signature[53], 5)
      << "incorrect value for signature[53], expected 5, is "
      << last_msg_->signature[53];
  EXPECT_EQ(last_msg_->signature[54], 6)
      << "incorrect value for signature[54], expected 6, is "
      << last_msg_->signature[54];
  EXPECT_EQ(last_msg_->signature[55], 7)
      << "incorrect value for signature[55], expected 7, is "
      << last_msg_->signature[55];
  EXPECT_EQ(last_msg_->signature[56], 0)
      << "incorrect value for signature[56], expected 0, is "
      << last_msg_->signature[56];
  EXPECT_EQ(last_msg_->signature[57], 1)
      << "incorrect value for signature[57], expected 1, is "
      << last_msg_->signature[57];
  EXPECT_EQ(last_msg_->signature[58], 2)
      << "incorrect value for signature[58], expected 2, is "
      << last_msg_->signature[58];
  EXPECT_EQ(last_msg_->signature[59], 3)
      << "incorrect value for signature[59], expected 3, is "
      << last_msg_->signature[59];
  EXPECT_EQ(last_msg_->signature[60], 4)
      << "incorrect value for signature[60], expected 4, is "
      << last_msg_->signature[60];
  EXPECT_EQ(last_msg_->signature[61], 5)
      << "incorrect value for signature[61], expected 5, is "
      << last_msg_->signature[61];
  EXPECT_EQ(last_msg_->signature[62], 6)
      << "incorrect value for signature[62], expected 6, is "
      << last_msg_->signature[62];
  EXPECT_EQ(last_msg_->signature[63], 7)
      << "incorrect value for signature[63], expected 7, is "
      << last_msg_->signature[63];
}
