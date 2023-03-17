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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignature.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_signing_MsgEcdsaSignature0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ecdsa_signature_t> {
 public:
  Test_legacy_auto_check_sbp_signing_MsgEcdsaSignature0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ecdsa_signature_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ecdsa_signature_t *>(last_msg_storage_)),
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
                      const msg_ecdsa_signature_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ecdsa_signature_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_signing_MsgEcdsaSignature0, Test) {
  uint8_t encoded_frame[] = {
      85, 8,  12, 66, 0,  83, 0,  1,  2,  1,   2,   3,  4,  72, 0,  1,
      2,  3,  4,  5,  6,  7,  8,  9,  10, 11,  12,  13, 14, 15, 16, 17,
      18, 19, 20, 21, 22, 23, 24, 25, 26, 27,  28,  29, 30, 31, 32, 33,
      34, 35, 36, 37, 38, 39, 40, 41, 42, 43,  44,  45, 46, 47, 48, 49,
      50, 51, 52, 53, 54, 55, 56, 57, 58, 59,  60,  61, 62, 63, 64, 65,
      66, 67, 68, 69, 70, 71, 10, 21, 23, 232, 131,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ecdsa_signature_t *test_msg = (msg_ecdsa_signature_t *)test_msg_storage;
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
  test_msg->on_demand_counter = 2;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[0] = 0;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[1] = 1;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[2] = 2;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[3] = 3;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[4] = 4;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[5] = 5;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[6] = 6;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[7] = 7;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[8] = 8;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[9] = 9;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[10] = 10;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[11] = 11;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[12] = 12;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[13] = 13;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[14] = 14;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[15] = 15;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[16] = 16;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[17] = 17;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[18] = 18;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[19] = 19;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[20] = 20;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[21] = 21;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[22] = 22;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[23] = 23;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[24] = 24;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[25] = 25;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[26] = 26;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[27] = 27;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[28] = 28;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[29] = 29;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[30] = 30;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[31] = 31;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[32] = 32;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[33] = 33;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[34] = 34;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[35] = 35;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[36] = 36;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[37] = 37;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[38] = 38;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[39] = 39;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[40] = 40;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[41] = 41;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[42] = 42;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[43] = 43;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[44] = 44;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[45] = 45;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[46] = 46;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[47] = 47;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[48] = 48;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[49] = 49;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[50] = 50;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[51] = 51;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[52] = 52;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[53] = 53;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[54] = 54;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[55] = 55;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[56] = 56;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[57] = 57;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[58] = 58;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[59] = 59;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[60] = 60;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[61] = 61;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[62] = 62;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[63] = 63;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[64] = 64;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[65] = 65;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[66] = 66;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[67] = 67;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[68] = 68;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[69] = 69;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[70] = 70;
  if (sizeof(test_msg->signature.data) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->signature.data[0]));
  }
  test_msg->signature.data[71] = 71;
  test_msg->signature.len = 72;
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

  EXPECT_EQ(send_message(0xC08, 66, test_msg_len, test_msg_storage), SBP_OK);

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
  EXPECT_EQ(last_msg_->on_demand_counter, 2)
      << "incorrect value for on_demand_counter, expected 2, is "
      << last_msg_->on_demand_counter;
  EXPECT_EQ(last_msg_->signature.data[0], 0)
      << "incorrect value for signature.data[0], expected 0, is "
      << last_msg_->signature.data[0];
  EXPECT_EQ(last_msg_->signature.data[1], 1)
      << "incorrect value for signature.data[1], expected 1, is "
      << last_msg_->signature.data[1];
  EXPECT_EQ(last_msg_->signature.data[2], 2)
      << "incorrect value for signature.data[2], expected 2, is "
      << last_msg_->signature.data[2];
  EXPECT_EQ(last_msg_->signature.data[3], 3)
      << "incorrect value for signature.data[3], expected 3, is "
      << last_msg_->signature.data[3];
  EXPECT_EQ(last_msg_->signature.data[4], 4)
      << "incorrect value for signature.data[4], expected 4, is "
      << last_msg_->signature.data[4];
  EXPECT_EQ(last_msg_->signature.data[5], 5)
      << "incorrect value for signature.data[5], expected 5, is "
      << last_msg_->signature.data[5];
  EXPECT_EQ(last_msg_->signature.data[6], 6)
      << "incorrect value for signature.data[6], expected 6, is "
      << last_msg_->signature.data[6];
  EXPECT_EQ(last_msg_->signature.data[7], 7)
      << "incorrect value for signature.data[7], expected 7, is "
      << last_msg_->signature.data[7];
  EXPECT_EQ(last_msg_->signature.data[8], 8)
      << "incorrect value for signature.data[8], expected 8, is "
      << last_msg_->signature.data[8];
  EXPECT_EQ(last_msg_->signature.data[9], 9)
      << "incorrect value for signature.data[9], expected 9, is "
      << last_msg_->signature.data[9];
  EXPECT_EQ(last_msg_->signature.data[10], 10)
      << "incorrect value for signature.data[10], expected 10, is "
      << last_msg_->signature.data[10];
  EXPECT_EQ(last_msg_->signature.data[11], 11)
      << "incorrect value for signature.data[11], expected 11, is "
      << last_msg_->signature.data[11];
  EXPECT_EQ(last_msg_->signature.data[12], 12)
      << "incorrect value for signature.data[12], expected 12, is "
      << last_msg_->signature.data[12];
  EXPECT_EQ(last_msg_->signature.data[13], 13)
      << "incorrect value for signature.data[13], expected 13, is "
      << last_msg_->signature.data[13];
  EXPECT_EQ(last_msg_->signature.data[14], 14)
      << "incorrect value for signature.data[14], expected 14, is "
      << last_msg_->signature.data[14];
  EXPECT_EQ(last_msg_->signature.data[15], 15)
      << "incorrect value for signature.data[15], expected 15, is "
      << last_msg_->signature.data[15];
  EXPECT_EQ(last_msg_->signature.data[16], 16)
      << "incorrect value for signature.data[16], expected 16, is "
      << last_msg_->signature.data[16];
  EXPECT_EQ(last_msg_->signature.data[17], 17)
      << "incorrect value for signature.data[17], expected 17, is "
      << last_msg_->signature.data[17];
  EXPECT_EQ(last_msg_->signature.data[18], 18)
      << "incorrect value for signature.data[18], expected 18, is "
      << last_msg_->signature.data[18];
  EXPECT_EQ(last_msg_->signature.data[19], 19)
      << "incorrect value for signature.data[19], expected 19, is "
      << last_msg_->signature.data[19];
  EXPECT_EQ(last_msg_->signature.data[20], 20)
      << "incorrect value for signature.data[20], expected 20, is "
      << last_msg_->signature.data[20];
  EXPECT_EQ(last_msg_->signature.data[21], 21)
      << "incorrect value for signature.data[21], expected 21, is "
      << last_msg_->signature.data[21];
  EXPECT_EQ(last_msg_->signature.data[22], 22)
      << "incorrect value for signature.data[22], expected 22, is "
      << last_msg_->signature.data[22];
  EXPECT_EQ(last_msg_->signature.data[23], 23)
      << "incorrect value for signature.data[23], expected 23, is "
      << last_msg_->signature.data[23];
  EXPECT_EQ(last_msg_->signature.data[24], 24)
      << "incorrect value for signature.data[24], expected 24, is "
      << last_msg_->signature.data[24];
  EXPECT_EQ(last_msg_->signature.data[25], 25)
      << "incorrect value for signature.data[25], expected 25, is "
      << last_msg_->signature.data[25];
  EXPECT_EQ(last_msg_->signature.data[26], 26)
      << "incorrect value for signature.data[26], expected 26, is "
      << last_msg_->signature.data[26];
  EXPECT_EQ(last_msg_->signature.data[27], 27)
      << "incorrect value for signature.data[27], expected 27, is "
      << last_msg_->signature.data[27];
  EXPECT_EQ(last_msg_->signature.data[28], 28)
      << "incorrect value for signature.data[28], expected 28, is "
      << last_msg_->signature.data[28];
  EXPECT_EQ(last_msg_->signature.data[29], 29)
      << "incorrect value for signature.data[29], expected 29, is "
      << last_msg_->signature.data[29];
  EXPECT_EQ(last_msg_->signature.data[30], 30)
      << "incorrect value for signature.data[30], expected 30, is "
      << last_msg_->signature.data[30];
  EXPECT_EQ(last_msg_->signature.data[31], 31)
      << "incorrect value for signature.data[31], expected 31, is "
      << last_msg_->signature.data[31];
  EXPECT_EQ(last_msg_->signature.data[32], 32)
      << "incorrect value for signature.data[32], expected 32, is "
      << last_msg_->signature.data[32];
  EXPECT_EQ(last_msg_->signature.data[33], 33)
      << "incorrect value for signature.data[33], expected 33, is "
      << last_msg_->signature.data[33];
  EXPECT_EQ(last_msg_->signature.data[34], 34)
      << "incorrect value for signature.data[34], expected 34, is "
      << last_msg_->signature.data[34];
  EXPECT_EQ(last_msg_->signature.data[35], 35)
      << "incorrect value for signature.data[35], expected 35, is "
      << last_msg_->signature.data[35];
  EXPECT_EQ(last_msg_->signature.data[36], 36)
      << "incorrect value for signature.data[36], expected 36, is "
      << last_msg_->signature.data[36];
  EXPECT_EQ(last_msg_->signature.data[37], 37)
      << "incorrect value for signature.data[37], expected 37, is "
      << last_msg_->signature.data[37];
  EXPECT_EQ(last_msg_->signature.data[38], 38)
      << "incorrect value for signature.data[38], expected 38, is "
      << last_msg_->signature.data[38];
  EXPECT_EQ(last_msg_->signature.data[39], 39)
      << "incorrect value for signature.data[39], expected 39, is "
      << last_msg_->signature.data[39];
  EXPECT_EQ(last_msg_->signature.data[40], 40)
      << "incorrect value for signature.data[40], expected 40, is "
      << last_msg_->signature.data[40];
  EXPECT_EQ(last_msg_->signature.data[41], 41)
      << "incorrect value for signature.data[41], expected 41, is "
      << last_msg_->signature.data[41];
  EXPECT_EQ(last_msg_->signature.data[42], 42)
      << "incorrect value for signature.data[42], expected 42, is "
      << last_msg_->signature.data[42];
  EXPECT_EQ(last_msg_->signature.data[43], 43)
      << "incorrect value for signature.data[43], expected 43, is "
      << last_msg_->signature.data[43];
  EXPECT_EQ(last_msg_->signature.data[44], 44)
      << "incorrect value for signature.data[44], expected 44, is "
      << last_msg_->signature.data[44];
  EXPECT_EQ(last_msg_->signature.data[45], 45)
      << "incorrect value for signature.data[45], expected 45, is "
      << last_msg_->signature.data[45];
  EXPECT_EQ(last_msg_->signature.data[46], 46)
      << "incorrect value for signature.data[46], expected 46, is "
      << last_msg_->signature.data[46];
  EXPECT_EQ(last_msg_->signature.data[47], 47)
      << "incorrect value for signature.data[47], expected 47, is "
      << last_msg_->signature.data[47];
  EXPECT_EQ(last_msg_->signature.data[48], 48)
      << "incorrect value for signature.data[48], expected 48, is "
      << last_msg_->signature.data[48];
  EXPECT_EQ(last_msg_->signature.data[49], 49)
      << "incorrect value for signature.data[49], expected 49, is "
      << last_msg_->signature.data[49];
  EXPECT_EQ(last_msg_->signature.data[50], 50)
      << "incorrect value for signature.data[50], expected 50, is "
      << last_msg_->signature.data[50];
  EXPECT_EQ(last_msg_->signature.data[51], 51)
      << "incorrect value for signature.data[51], expected 51, is "
      << last_msg_->signature.data[51];
  EXPECT_EQ(last_msg_->signature.data[52], 52)
      << "incorrect value for signature.data[52], expected 52, is "
      << last_msg_->signature.data[52];
  EXPECT_EQ(last_msg_->signature.data[53], 53)
      << "incorrect value for signature.data[53], expected 53, is "
      << last_msg_->signature.data[53];
  EXPECT_EQ(last_msg_->signature.data[54], 54)
      << "incorrect value for signature.data[54], expected 54, is "
      << last_msg_->signature.data[54];
  EXPECT_EQ(last_msg_->signature.data[55], 55)
      << "incorrect value for signature.data[55], expected 55, is "
      << last_msg_->signature.data[55];
  EXPECT_EQ(last_msg_->signature.data[56], 56)
      << "incorrect value for signature.data[56], expected 56, is "
      << last_msg_->signature.data[56];
  EXPECT_EQ(last_msg_->signature.data[57], 57)
      << "incorrect value for signature.data[57], expected 57, is "
      << last_msg_->signature.data[57];
  EXPECT_EQ(last_msg_->signature.data[58], 58)
      << "incorrect value for signature.data[58], expected 58, is "
      << last_msg_->signature.data[58];
  EXPECT_EQ(last_msg_->signature.data[59], 59)
      << "incorrect value for signature.data[59], expected 59, is "
      << last_msg_->signature.data[59];
  EXPECT_EQ(last_msg_->signature.data[60], 60)
      << "incorrect value for signature.data[60], expected 60, is "
      << last_msg_->signature.data[60];
  EXPECT_EQ(last_msg_->signature.data[61], 61)
      << "incorrect value for signature.data[61], expected 61, is "
      << last_msg_->signature.data[61];
  EXPECT_EQ(last_msg_->signature.data[62], 62)
      << "incorrect value for signature.data[62], expected 62, is "
      << last_msg_->signature.data[62];
  EXPECT_EQ(last_msg_->signature.data[63], 63)
      << "incorrect value for signature.data[63], expected 63, is "
      << last_msg_->signature.data[63];
  EXPECT_EQ(last_msg_->signature.data[64], 64)
      << "incorrect value for signature.data[64], expected 64, is "
      << last_msg_->signature.data[64];
  EXPECT_EQ(last_msg_->signature.data[65], 65)
      << "incorrect value for signature.data[65], expected 65, is "
      << last_msg_->signature.data[65];
  EXPECT_EQ(last_msg_->signature.data[66], 66)
      << "incorrect value for signature.data[66], expected 66, is "
      << last_msg_->signature.data[66];
  EXPECT_EQ(last_msg_->signature.data[67], 67)
      << "incorrect value for signature.data[67], expected 67, is "
      << last_msg_->signature.data[67];
  EXPECT_EQ(last_msg_->signature.data[68], 68)
      << "incorrect value for signature.data[68], expected 68, is "
      << last_msg_->signature.data[68];
  EXPECT_EQ(last_msg_->signature.data[69], 69)
      << "incorrect value for signature.data[69], expected 69, is "
      << last_msg_->signature.data[69];
  EXPECT_EQ(last_msg_->signature.data[70], 70)
      << "incorrect value for signature.data[70], expected 70, is "
      << last_msg_->signature.data[70];
  EXPECT_EQ(last_msg_->signature.data[71], 71)
      << "incorrect value for signature.data[71], expected 71, is "
      << last_msg_->signature.data[71];
  EXPECT_EQ(last_msg_->signature.len, 72)
      << "incorrect value for signature.len, expected 72, is "
      << last_msg_->signature.len;
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
