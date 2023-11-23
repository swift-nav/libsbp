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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignatureDepB.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>

#include <libsbp/common.h>
#include <libsbp/cpp/state.h>

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/signing.h>
class Test_legacy_auto_check_sbp_signing_MsgEcdsaSignatureDepB0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ecdsa_signature_dep_b_t> {
 public:
  Test_legacy_auto_check_sbp_signing_MsgEcdsaSignatureDepB0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ecdsa_signature_dep_b_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_ecdsa_signature_dep_b_t *>(last_msg_storage_)),
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
                      const msg_ecdsa_signature_dep_b_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ecdsa_signature_dep_b_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_signing_MsgEcdsaSignatureDepB0, Test) {
  uint8_t encoded_frame[] = {
      85, 7,  12, 66, 0,  83, 0,  1,  2,  1,   2,   3,  4,  72, 0,  1,
      2,  3,  4,  5,  6,  7,  8,  9,  10, 11,  12,  13, 14, 15, 16, 17,
      18, 19, 20, 21, 22, 23, 24, 25, 26, 27,  28,  29, 30, 31, 32, 33,
      34, 35, 36, 37, 38, 39, 40, 41, 42, 43,  44,  45, 46, 47, 48, 49,
      50, 51, 52, 53, 54, 55, 56, 57, 58, 59,  60,  61, 62, 63, 64, 65,
      66, 67, 68, 69, 70, 71, 10, 21, 23, 254, 159,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ecdsa_signature_dep_b_t *test_msg =
      (msg_ecdsa_signature_dep_b_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->certificate_id) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_id[0]));
  }
  test_msg->certificate_id[0] = 1;
  if (sizeof(test_msg->certificate_id) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_id[0]));
  }
  test_msg->certificate_id[1] = 2;
  if (sizeof(test_msg->certificate_id) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_id[0]));
  }
  test_msg->certificate_id[2] = 3;
  if (sizeof(test_msg->certificate_id) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_id[0]));
  }
  test_msg->certificate_id[3] = 4;
  test_msg->flags = 0;
  test_msg->n_signature_bytes = 72;
  test_msg->on_demand_counter = 2;
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
  test_msg->signature[8] = 8;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[9] = 9;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[10] = 10;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[11] = 11;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[12] = 12;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[13] = 13;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[14] = 14;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[15] = 15;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[16] = 16;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[17] = 17;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[18] = 18;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[19] = 19;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[20] = 20;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[21] = 21;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[22] = 22;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[23] = 23;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[24] = 24;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[25] = 25;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[26] = 26;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[27] = 27;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[28] = 28;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[29] = 29;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[30] = 30;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[31] = 31;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[32] = 32;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[33] = 33;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[34] = 34;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[35] = 35;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[36] = 36;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[37] = 37;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[38] = 38;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[39] = 39;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[40] = 40;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[41] = 41;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[42] = 42;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[43] = 43;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[44] = 44;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[45] = 45;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[46] = 46;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[47] = 47;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[48] = 48;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[49] = 49;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[50] = 50;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[51] = 51;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[52] = 52;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[53] = 53;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[54] = 54;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[55] = 55;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[56] = 56;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[57] = 57;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[58] = 58;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[59] = 59;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[60] = 60;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[61] = 61;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[62] = 62;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[63] = 63;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[64] = 64;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[65] = 65;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[66] = 66;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[67] = 67;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[68] = 68;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[69] = 69;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[70] = 70;
  if (sizeof(test_msg->signature) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->signature[0]));
  }
  test_msg->signature[71] = 71;
  if (sizeof(test_msg->signed_messages) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signed_messages[0]));
  }
  test_msg->signed_messages[0] = 10;
  if (sizeof(test_msg->signed_messages) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signed_messages[0]));
  }
  test_msg->signed_messages[1] = 21;
  if (sizeof(test_msg->signed_messages) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signed_messages[0]));
  }
  test_msg->signed_messages[2] = 23;
  test_msg->stream_counter = 1;

  EXPECT_EQ(send_message(0xC07, 66, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->certificate_id[0], 1)
      << "incorrect value for certificate_id[0], expected 1, is "
      << last_msg_->certificate_id[0];
  EXPECT_EQ(last_msg_->certificate_id[1], 2)
      << "incorrect value for certificate_id[1], expected 2, is "
      << last_msg_->certificate_id[1];
  EXPECT_EQ(last_msg_->certificate_id[2], 3)
      << "incorrect value for certificate_id[2], expected 3, is "
      << last_msg_->certificate_id[2];
  EXPECT_EQ(last_msg_->certificate_id[3], 4)
      << "incorrect value for certificate_id[3], expected 4, is "
      << last_msg_->certificate_id[3];
  EXPECT_EQ(last_msg_->flags, 0)
      << "incorrect value for flags, expected 0, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_signature_bytes, 72)
      << "incorrect value for n_signature_bytes, expected 72, is "
      << last_msg_->n_signature_bytes;
  EXPECT_EQ(last_msg_->on_demand_counter, 2)
      << "incorrect value for on_demand_counter, expected 2, is "
      << last_msg_->on_demand_counter;
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
  EXPECT_EQ(last_msg_->signature[8], 8)
      << "incorrect value for signature[8], expected 8, is "
      << last_msg_->signature[8];
  EXPECT_EQ(last_msg_->signature[9], 9)
      << "incorrect value for signature[9], expected 9, is "
      << last_msg_->signature[9];
  EXPECT_EQ(last_msg_->signature[10], 10)
      << "incorrect value for signature[10], expected 10, is "
      << last_msg_->signature[10];
  EXPECT_EQ(last_msg_->signature[11], 11)
      << "incorrect value for signature[11], expected 11, is "
      << last_msg_->signature[11];
  EXPECT_EQ(last_msg_->signature[12], 12)
      << "incorrect value for signature[12], expected 12, is "
      << last_msg_->signature[12];
  EXPECT_EQ(last_msg_->signature[13], 13)
      << "incorrect value for signature[13], expected 13, is "
      << last_msg_->signature[13];
  EXPECT_EQ(last_msg_->signature[14], 14)
      << "incorrect value for signature[14], expected 14, is "
      << last_msg_->signature[14];
  EXPECT_EQ(last_msg_->signature[15], 15)
      << "incorrect value for signature[15], expected 15, is "
      << last_msg_->signature[15];
  EXPECT_EQ(last_msg_->signature[16], 16)
      << "incorrect value for signature[16], expected 16, is "
      << last_msg_->signature[16];
  EXPECT_EQ(last_msg_->signature[17], 17)
      << "incorrect value for signature[17], expected 17, is "
      << last_msg_->signature[17];
  EXPECT_EQ(last_msg_->signature[18], 18)
      << "incorrect value for signature[18], expected 18, is "
      << last_msg_->signature[18];
  EXPECT_EQ(last_msg_->signature[19], 19)
      << "incorrect value for signature[19], expected 19, is "
      << last_msg_->signature[19];
  EXPECT_EQ(last_msg_->signature[20], 20)
      << "incorrect value for signature[20], expected 20, is "
      << last_msg_->signature[20];
  EXPECT_EQ(last_msg_->signature[21], 21)
      << "incorrect value for signature[21], expected 21, is "
      << last_msg_->signature[21];
  EXPECT_EQ(last_msg_->signature[22], 22)
      << "incorrect value for signature[22], expected 22, is "
      << last_msg_->signature[22];
  EXPECT_EQ(last_msg_->signature[23], 23)
      << "incorrect value for signature[23], expected 23, is "
      << last_msg_->signature[23];
  EXPECT_EQ(last_msg_->signature[24], 24)
      << "incorrect value for signature[24], expected 24, is "
      << last_msg_->signature[24];
  EXPECT_EQ(last_msg_->signature[25], 25)
      << "incorrect value for signature[25], expected 25, is "
      << last_msg_->signature[25];
  EXPECT_EQ(last_msg_->signature[26], 26)
      << "incorrect value for signature[26], expected 26, is "
      << last_msg_->signature[26];
  EXPECT_EQ(last_msg_->signature[27], 27)
      << "incorrect value for signature[27], expected 27, is "
      << last_msg_->signature[27];
  EXPECT_EQ(last_msg_->signature[28], 28)
      << "incorrect value for signature[28], expected 28, is "
      << last_msg_->signature[28];
  EXPECT_EQ(last_msg_->signature[29], 29)
      << "incorrect value for signature[29], expected 29, is "
      << last_msg_->signature[29];
  EXPECT_EQ(last_msg_->signature[30], 30)
      << "incorrect value for signature[30], expected 30, is "
      << last_msg_->signature[30];
  EXPECT_EQ(last_msg_->signature[31], 31)
      << "incorrect value for signature[31], expected 31, is "
      << last_msg_->signature[31];
  EXPECT_EQ(last_msg_->signature[32], 32)
      << "incorrect value for signature[32], expected 32, is "
      << last_msg_->signature[32];
  EXPECT_EQ(last_msg_->signature[33], 33)
      << "incorrect value for signature[33], expected 33, is "
      << last_msg_->signature[33];
  EXPECT_EQ(last_msg_->signature[34], 34)
      << "incorrect value for signature[34], expected 34, is "
      << last_msg_->signature[34];
  EXPECT_EQ(last_msg_->signature[35], 35)
      << "incorrect value for signature[35], expected 35, is "
      << last_msg_->signature[35];
  EXPECT_EQ(last_msg_->signature[36], 36)
      << "incorrect value for signature[36], expected 36, is "
      << last_msg_->signature[36];
  EXPECT_EQ(last_msg_->signature[37], 37)
      << "incorrect value for signature[37], expected 37, is "
      << last_msg_->signature[37];
  EXPECT_EQ(last_msg_->signature[38], 38)
      << "incorrect value for signature[38], expected 38, is "
      << last_msg_->signature[38];
  EXPECT_EQ(last_msg_->signature[39], 39)
      << "incorrect value for signature[39], expected 39, is "
      << last_msg_->signature[39];
  EXPECT_EQ(last_msg_->signature[40], 40)
      << "incorrect value for signature[40], expected 40, is "
      << last_msg_->signature[40];
  EXPECT_EQ(last_msg_->signature[41], 41)
      << "incorrect value for signature[41], expected 41, is "
      << last_msg_->signature[41];
  EXPECT_EQ(last_msg_->signature[42], 42)
      << "incorrect value for signature[42], expected 42, is "
      << last_msg_->signature[42];
  EXPECT_EQ(last_msg_->signature[43], 43)
      << "incorrect value for signature[43], expected 43, is "
      << last_msg_->signature[43];
  EXPECT_EQ(last_msg_->signature[44], 44)
      << "incorrect value for signature[44], expected 44, is "
      << last_msg_->signature[44];
  EXPECT_EQ(last_msg_->signature[45], 45)
      << "incorrect value for signature[45], expected 45, is "
      << last_msg_->signature[45];
  EXPECT_EQ(last_msg_->signature[46], 46)
      << "incorrect value for signature[46], expected 46, is "
      << last_msg_->signature[46];
  EXPECT_EQ(last_msg_->signature[47], 47)
      << "incorrect value for signature[47], expected 47, is "
      << last_msg_->signature[47];
  EXPECT_EQ(last_msg_->signature[48], 48)
      << "incorrect value for signature[48], expected 48, is "
      << last_msg_->signature[48];
  EXPECT_EQ(last_msg_->signature[49], 49)
      << "incorrect value for signature[49], expected 49, is "
      << last_msg_->signature[49];
  EXPECT_EQ(last_msg_->signature[50], 50)
      << "incorrect value for signature[50], expected 50, is "
      << last_msg_->signature[50];
  EXPECT_EQ(last_msg_->signature[51], 51)
      << "incorrect value for signature[51], expected 51, is "
      << last_msg_->signature[51];
  EXPECT_EQ(last_msg_->signature[52], 52)
      << "incorrect value for signature[52], expected 52, is "
      << last_msg_->signature[52];
  EXPECT_EQ(last_msg_->signature[53], 53)
      << "incorrect value for signature[53], expected 53, is "
      << last_msg_->signature[53];
  EXPECT_EQ(last_msg_->signature[54], 54)
      << "incorrect value for signature[54], expected 54, is "
      << last_msg_->signature[54];
  EXPECT_EQ(last_msg_->signature[55], 55)
      << "incorrect value for signature[55], expected 55, is "
      << last_msg_->signature[55];
  EXPECT_EQ(last_msg_->signature[56], 56)
      << "incorrect value for signature[56], expected 56, is "
      << last_msg_->signature[56];
  EXPECT_EQ(last_msg_->signature[57], 57)
      << "incorrect value for signature[57], expected 57, is "
      << last_msg_->signature[57];
  EXPECT_EQ(last_msg_->signature[58], 58)
      << "incorrect value for signature[58], expected 58, is "
      << last_msg_->signature[58];
  EXPECT_EQ(last_msg_->signature[59], 59)
      << "incorrect value for signature[59], expected 59, is "
      << last_msg_->signature[59];
  EXPECT_EQ(last_msg_->signature[60], 60)
      << "incorrect value for signature[60], expected 60, is "
      << last_msg_->signature[60];
  EXPECT_EQ(last_msg_->signature[61], 61)
      << "incorrect value for signature[61], expected 61, is "
      << last_msg_->signature[61];
  EXPECT_EQ(last_msg_->signature[62], 62)
      << "incorrect value for signature[62], expected 62, is "
      << last_msg_->signature[62];
  EXPECT_EQ(last_msg_->signature[63], 63)
      << "incorrect value for signature[63], expected 63, is "
      << last_msg_->signature[63];
  EXPECT_EQ(last_msg_->signature[64], 64)
      << "incorrect value for signature[64], expected 64, is "
      << last_msg_->signature[64];
  EXPECT_EQ(last_msg_->signature[65], 65)
      << "incorrect value for signature[65], expected 65, is "
      << last_msg_->signature[65];
  EXPECT_EQ(last_msg_->signature[66], 66)
      << "incorrect value for signature[66], expected 66, is "
      << last_msg_->signature[66];
  EXPECT_EQ(last_msg_->signature[67], 67)
      << "incorrect value for signature[67], expected 67, is "
      << last_msg_->signature[67];
  EXPECT_EQ(last_msg_->signature[68], 68)
      << "incorrect value for signature[68], expected 68, is "
      << last_msg_->signature[68];
  EXPECT_EQ(last_msg_->signature[69], 69)
      << "incorrect value for signature[69], expected 69, is "
      << last_msg_->signature[69];
  EXPECT_EQ(last_msg_->signature[70], 70)
      << "incorrect value for signature[70], expected 70, is "
      << last_msg_->signature[70];
  EXPECT_EQ(last_msg_->signature[71], 71)
      << "incorrect value for signature[71], expected 71, is "
      << last_msg_->signature[71];
  EXPECT_EQ(last_msg_->signed_messages[0], 10)
      << "incorrect value for signed_messages[0], expected 10, is "
      << last_msg_->signed_messages[0];
  EXPECT_EQ(last_msg_->signed_messages[1], 21)
      << "incorrect value for signed_messages[1], expected 21, is "
      << last_msg_->signed_messages[1];
  EXPECT_EQ(last_msg_->signed_messages[2], 23)
      << "incorrect value for signed_messages[2], expected 23, is "
      << last_msg_->signed_messages[2];
  EXPECT_EQ(last_msg_->stream_counter, 1)
      << "incorrect value for stream_counter, expected 1, is "
      << last_msg_->stream_counter;
}
