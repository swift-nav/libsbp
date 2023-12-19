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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaCertificate.yaml by
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
#include <libsbp/legacy/signing.h>
class Test_legacy_auto_check_sbp_signing_MsgEcdsaCertificate0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ecdsa_certificate_t> {
 public:
  Test_legacy_auto_check_sbp_signing_MsgEcdsaCertificate0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ecdsa_certificate_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_ecdsa_certificate_t *>(last_msg_storage_)),
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
                      const msg_ecdsa_certificate_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ecdsa_certificate_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_signing_MsgEcdsaCertificate0, Test) {
  uint8_t encoded_frame[] = {
      85,  4,   12,  66,  0,   253, 48,  10,  11,  12,  13,  2,   180, 160, 116,
      77,  243, 28,  173, 36,  86,  33,  8,   31,  120, 73,  64,  169, 148, 224,
      57,  95,  17,  40,  213, 92,  195, 146, 235, 228, 177, 101, 82,  182, 25,
      172, 170, 250, 236, 7,   119, 4,   201, 10,  14,  208, 47,  126, 49,  210,
      174, 75,  221, 203, 24,  66,  52,  35,  26,  30,  140, 111, 246, 39,  226,
      205, 198, 178, 196, 5,   81,  9,   44,  164, 163, 214, 138, 123, 76,  74,
      237, 121, 13,  137, 186, 97,  193, 189, 200, 124, 69,  115, 230, 159, 185,
      158, 51,  12,  225, 65,  192, 105, 56,  41,  85,  133, 19,  217, 166, 48,
      139, 131, 96,  216, 98,  147, 132, 234, 167, 248, 247, 32,  239, 194, 188,
      254, 114, 117, 83,  25,  251, 191, 104, 240, 118, 68,  42,  93,  18,  16,
      37,  232, 99,  179, 23,  90,  94,  136, 6,   125, 91,  255, 15,  71,  43,
      46,  25,  252, 229, 80,  143, 58,  241, 11,  62,  181, 155, 53,  153, 149,
      152, 227, 150, 87,  112, 165, 2,   128, 231, 25,  157, 244, 204, 108, 253,
      127, 122, 145, 113, 162, 197, 171, 199, 54,  184, 222, 206, 67,  144, 78,
      187, 207, 60,  211, 141, 135, 106, 220, 79,  183, 245, 21,  161, 168, 34,
      129, 50,  176, 1,   218, 20,  130, 59,  249, 109, 219, 0,   100, 103, 55,
      29,  242, 110, 154, 190, 233, 142, 45,  61,  215, 202, 238, 88,  209, 70,
      63,  151, 27,  102, 219, 30,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ecdsa_certificate_t *test_msg =
      (msg_ecdsa_certificate_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[0] = 180;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[1] = 160;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[2] = 116;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[3] = 77;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[4] = 243;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[5] = 28;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[6] = 173;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[7] = 36;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[8] = 86;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[9] = 33;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[10] = 8;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[11] = 31;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[12] = 120;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[13] = 73;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[14] = 64;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[15] = 169;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[16] = 148;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[17] = 224;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[18] = 57;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[19] = 95;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[20] = 17;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[21] = 40;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[22] = 213;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[23] = 92;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[24] = 195;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[25] = 146;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[26] = 235;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[27] = 228;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[28] = 177;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[29] = 101;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[30] = 82;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[31] = 182;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[32] = 25;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[33] = 172;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[34] = 170;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[35] = 250;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[36] = 236;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[37] = 7;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[38] = 119;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[39] = 4;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[40] = 201;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[41] = 10;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[42] = 14;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[43] = 208;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[44] = 47;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[45] = 126;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[46] = 49;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[47] = 210;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[48] = 174;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[49] = 75;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[50] = 221;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[51] = 203;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[52] = 24;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[53] = 66;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[54] = 52;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[55] = 35;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[56] = 26;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[57] = 30;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[58] = 140;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[59] = 111;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[60] = 246;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[61] = 39;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[62] = 226;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[63] = 205;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[64] = 198;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[65] = 178;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[66] = 196;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[67] = 5;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[68] = 81;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[69] = 9;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[70] = 44;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[71] = 164;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[72] = 163;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[73] = 214;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[74] = 138;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[75] = 123;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[76] = 76;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[77] = 74;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[78] = 237;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[79] = 121;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[80] = 13;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[81] = 137;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[82] = 186;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[83] = 97;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[84] = 193;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[85] = 189;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[86] = 200;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[87] = 124;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[88] = 69;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[89] = 115;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[90] = 230;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[91] = 159;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[92] = 185;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[93] = 158;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[94] = 51;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[95] = 12;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[96] = 225;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[97] = 65;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[98] = 192;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[99] = 105;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[100] = 56;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[101] = 41;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[102] = 85;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[103] = 133;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[104] = 19;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[105] = 217;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[106] = 166;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[107] = 48;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[108] = 139;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[109] = 131;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[110] = 96;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[111] = 216;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[112] = 98;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[113] = 147;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[114] = 132;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[115] = 234;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[116] = 167;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[117] = 248;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[118] = 247;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[119] = 32;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[120] = 239;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[121] = 194;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[122] = 188;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[123] = 254;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[124] = 114;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[125] = 117;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[126] = 83;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[127] = 25;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[128] = 251;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[129] = 191;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[130] = 104;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[131] = 240;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[132] = 118;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[133] = 68;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[134] = 42;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[135] = 93;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[136] = 18;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[137] = 16;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[138] = 37;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[139] = 232;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[140] = 99;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[141] = 179;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[142] = 23;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[143] = 90;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[144] = 94;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[145] = 136;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[146] = 6;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[147] = 125;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[148] = 91;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[149] = 255;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[150] = 15;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[151] = 71;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[152] = 43;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[153] = 46;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[154] = 25;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[155] = 252;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[156] = 229;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[157] = 80;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[158] = 143;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[159] = 58;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[160] = 241;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[161] = 11;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[162] = 62;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[163] = 181;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[164] = 155;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[165] = 53;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[166] = 153;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[167] = 149;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[168] = 152;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[169] = 227;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[170] = 150;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[171] = 87;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[172] = 112;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[173] = 165;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[174] = 2;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[175] = 128;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[176] = 231;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[177] = 25;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[178] = 157;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[179] = 244;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[180] = 204;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[181] = 108;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[182] = 253;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[183] = 127;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[184] = 122;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[185] = 145;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[186] = 113;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[187] = 162;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[188] = 197;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[189] = 171;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[190] = 199;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[191] = 54;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[192] = 184;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[193] = 222;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[194] = 206;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[195] = 67;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[196] = 144;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[197] = 78;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[198] = 187;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[199] = 207;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[200] = 60;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[201] = 211;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[202] = 141;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[203] = 135;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[204] = 106;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[205] = 220;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[206] = 79;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[207] = 183;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[208] = 245;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[209] = 21;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[210] = 161;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[211] = 168;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[212] = 34;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[213] = 129;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[214] = 50;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[215] = 176;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[216] = 1;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[217] = 218;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[218] = 20;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[219] = 130;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[220] = 59;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[221] = 249;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[222] = 109;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[223] = 219;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[224] = 0;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[225] = 100;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[226] = 103;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[227] = 55;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[228] = 29;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[229] = 242;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[230] = 110;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[231] = 154;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[232] = 190;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[233] = 233;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[234] = 142;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[235] = 45;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[236] = 61;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[237] = 215;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[238] = 202;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[239] = 238;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[240] = 88;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[241] = 209;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[242] = 70;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[243] = 63;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[244] = 151;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[245] = 27;
  if (sizeof(test_msg->certificate_bytes) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_bytes[0]));
  }
  test_msg->certificate_bytes[246] = 102;
  if (sizeof(test_msg->certificate_id) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_id[0]));
  }
  test_msg->certificate_id[0] = 10;
  if (sizeof(test_msg->certificate_id) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_id[0]));
  }
  test_msg->certificate_id[1] = 11;
  if (sizeof(test_msg->certificate_id) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_id[0]));
  }
  test_msg->certificate_id[2] = 12;
  if (sizeof(test_msg->certificate_id) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->certificate_id[0]));
  }
  test_msg->certificate_id[3] = 13;
  test_msg->flags = 2;
  test_msg->n_msg = 48;

  EXPECT_EQ(send_message(0xC04, 66, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->certificate_bytes[0], 180)
      << "incorrect value for certificate_bytes[0], expected 180, is "
      << last_msg_->certificate_bytes[0];
  EXPECT_EQ(last_msg_->certificate_bytes[1], 160)
      << "incorrect value for certificate_bytes[1], expected 160, is "
      << last_msg_->certificate_bytes[1];
  EXPECT_EQ(last_msg_->certificate_bytes[2], 116)
      << "incorrect value for certificate_bytes[2], expected 116, is "
      << last_msg_->certificate_bytes[2];
  EXPECT_EQ(last_msg_->certificate_bytes[3], 77)
      << "incorrect value for certificate_bytes[3], expected 77, is "
      << last_msg_->certificate_bytes[3];
  EXPECT_EQ(last_msg_->certificate_bytes[4], 243)
      << "incorrect value for certificate_bytes[4], expected 243, is "
      << last_msg_->certificate_bytes[4];
  EXPECT_EQ(last_msg_->certificate_bytes[5], 28)
      << "incorrect value for certificate_bytes[5], expected 28, is "
      << last_msg_->certificate_bytes[5];
  EXPECT_EQ(last_msg_->certificate_bytes[6], 173)
      << "incorrect value for certificate_bytes[6], expected 173, is "
      << last_msg_->certificate_bytes[6];
  EXPECT_EQ(last_msg_->certificate_bytes[7], 36)
      << "incorrect value for certificate_bytes[7], expected 36, is "
      << last_msg_->certificate_bytes[7];
  EXPECT_EQ(last_msg_->certificate_bytes[8], 86)
      << "incorrect value for certificate_bytes[8], expected 86, is "
      << last_msg_->certificate_bytes[8];
  EXPECT_EQ(last_msg_->certificate_bytes[9], 33)
      << "incorrect value for certificate_bytes[9], expected 33, is "
      << last_msg_->certificate_bytes[9];
  EXPECT_EQ(last_msg_->certificate_bytes[10], 8)
      << "incorrect value for certificate_bytes[10], expected 8, is "
      << last_msg_->certificate_bytes[10];
  EXPECT_EQ(last_msg_->certificate_bytes[11], 31)
      << "incorrect value for certificate_bytes[11], expected 31, is "
      << last_msg_->certificate_bytes[11];
  EXPECT_EQ(last_msg_->certificate_bytes[12], 120)
      << "incorrect value for certificate_bytes[12], expected 120, is "
      << last_msg_->certificate_bytes[12];
  EXPECT_EQ(last_msg_->certificate_bytes[13], 73)
      << "incorrect value for certificate_bytes[13], expected 73, is "
      << last_msg_->certificate_bytes[13];
  EXPECT_EQ(last_msg_->certificate_bytes[14], 64)
      << "incorrect value for certificate_bytes[14], expected 64, is "
      << last_msg_->certificate_bytes[14];
  EXPECT_EQ(last_msg_->certificate_bytes[15], 169)
      << "incorrect value for certificate_bytes[15], expected 169, is "
      << last_msg_->certificate_bytes[15];
  EXPECT_EQ(last_msg_->certificate_bytes[16], 148)
      << "incorrect value for certificate_bytes[16], expected 148, is "
      << last_msg_->certificate_bytes[16];
  EXPECT_EQ(last_msg_->certificate_bytes[17], 224)
      << "incorrect value for certificate_bytes[17], expected 224, is "
      << last_msg_->certificate_bytes[17];
  EXPECT_EQ(last_msg_->certificate_bytes[18], 57)
      << "incorrect value for certificate_bytes[18], expected 57, is "
      << last_msg_->certificate_bytes[18];
  EXPECT_EQ(last_msg_->certificate_bytes[19], 95)
      << "incorrect value for certificate_bytes[19], expected 95, is "
      << last_msg_->certificate_bytes[19];
  EXPECT_EQ(last_msg_->certificate_bytes[20], 17)
      << "incorrect value for certificate_bytes[20], expected 17, is "
      << last_msg_->certificate_bytes[20];
  EXPECT_EQ(last_msg_->certificate_bytes[21], 40)
      << "incorrect value for certificate_bytes[21], expected 40, is "
      << last_msg_->certificate_bytes[21];
  EXPECT_EQ(last_msg_->certificate_bytes[22], 213)
      << "incorrect value for certificate_bytes[22], expected 213, is "
      << last_msg_->certificate_bytes[22];
  EXPECT_EQ(last_msg_->certificate_bytes[23], 92)
      << "incorrect value for certificate_bytes[23], expected 92, is "
      << last_msg_->certificate_bytes[23];
  EXPECT_EQ(last_msg_->certificate_bytes[24], 195)
      << "incorrect value for certificate_bytes[24], expected 195, is "
      << last_msg_->certificate_bytes[24];
  EXPECT_EQ(last_msg_->certificate_bytes[25], 146)
      << "incorrect value for certificate_bytes[25], expected 146, is "
      << last_msg_->certificate_bytes[25];
  EXPECT_EQ(last_msg_->certificate_bytes[26], 235)
      << "incorrect value for certificate_bytes[26], expected 235, is "
      << last_msg_->certificate_bytes[26];
  EXPECT_EQ(last_msg_->certificate_bytes[27], 228)
      << "incorrect value for certificate_bytes[27], expected 228, is "
      << last_msg_->certificate_bytes[27];
  EXPECT_EQ(last_msg_->certificate_bytes[28], 177)
      << "incorrect value for certificate_bytes[28], expected 177, is "
      << last_msg_->certificate_bytes[28];
  EXPECT_EQ(last_msg_->certificate_bytes[29], 101)
      << "incorrect value for certificate_bytes[29], expected 101, is "
      << last_msg_->certificate_bytes[29];
  EXPECT_EQ(last_msg_->certificate_bytes[30], 82)
      << "incorrect value for certificate_bytes[30], expected 82, is "
      << last_msg_->certificate_bytes[30];
  EXPECT_EQ(last_msg_->certificate_bytes[31], 182)
      << "incorrect value for certificate_bytes[31], expected 182, is "
      << last_msg_->certificate_bytes[31];
  EXPECT_EQ(last_msg_->certificate_bytes[32], 25)
      << "incorrect value for certificate_bytes[32], expected 25, is "
      << last_msg_->certificate_bytes[32];
  EXPECT_EQ(last_msg_->certificate_bytes[33], 172)
      << "incorrect value for certificate_bytes[33], expected 172, is "
      << last_msg_->certificate_bytes[33];
  EXPECT_EQ(last_msg_->certificate_bytes[34], 170)
      << "incorrect value for certificate_bytes[34], expected 170, is "
      << last_msg_->certificate_bytes[34];
  EXPECT_EQ(last_msg_->certificate_bytes[35], 250)
      << "incorrect value for certificate_bytes[35], expected 250, is "
      << last_msg_->certificate_bytes[35];
  EXPECT_EQ(last_msg_->certificate_bytes[36], 236)
      << "incorrect value for certificate_bytes[36], expected 236, is "
      << last_msg_->certificate_bytes[36];
  EXPECT_EQ(last_msg_->certificate_bytes[37], 7)
      << "incorrect value for certificate_bytes[37], expected 7, is "
      << last_msg_->certificate_bytes[37];
  EXPECT_EQ(last_msg_->certificate_bytes[38], 119)
      << "incorrect value for certificate_bytes[38], expected 119, is "
      << last_msg_->certificate_bytes[38];
  EXPECT_EQ(last_msg_->certificate_bytes[39], 4)
      << "incorrect value for certificate_bytes[39], expected 4, is "
      << last_msg_->certificate_bytes[39];
  EXPECT_EQ(last_msg_->certificate_bytes[40], 201)
      << "incorrect value for certificate_bytes[40], expected 201, is "
      << last_msg_->certificate_bytes[40];
  EXPECT_EQ(last_msg_->certificate_bytes[41], 10)
      << "incorrect value for certificate_bytes[41], expected 10, is "
      << last_msg_->certificate_bytes[41];
  EXPECT_EQ(last_msg_->certificate_bytes[42], 14)
      << "incorrect value for certificate_bytes[42], expected 14, is "
      << last_msg_->certificate_bytes[42];
  EXPECT_EQ(last_msg_->certificate_bytes[43], 208)
      << "incorrect value for certificate_bytes[43], expected 208, is "
      << last_msg_->certificate_bytes[43];
  EXPECT_EQ(last_msg_->certificate_bytes[44], 47)
      << "incorrect value for certificate_bytes[44], expected 47, is "
      << last_msg_->certificate_bytes[44];
  EXPECT_EQ(last_msg_->certificate_bytes[45], 126)
      << "incorrect value for certificate_bytes[45], expected 126, is "
      << last_msg_->certificate_bytes[45];
  EXPECT_EQ(last_msg_->certificate_bytes[46], 49)
      << "incorrect value for certificate_bytes[46], expected 49, is "
      << last_msg_->certificate_bytes[46];
  EXPECT_EQ(last_msg_->certificate_bytes[47], 210)
      << "incorrect value for certificate_bytes[47], expected 210, is "
      << last_msg_->certificate_bytes[47];
  EXPECT_EQ(last_msg_->certificate_bytes[48], 174)
      << "incorrect value for certificate_bytes[48], expected 174, is "
      << last_msg_->certificate_bytes[48];
  EXPECT_EQ(last_msg_->certificate_bytes[49], 75)
      << "incorrect value for certificate_bytes[49], expected 75, is "
      << last_msg_->certificate_bytes[49];
  EXPECT_EQ(last_msg_->certificate_bytes[50], 221)
      << "incorrect value for certificate_bytes[50], expected 221, is "
      << last_msg_->certificate_bytes[50];
  EXPECT_EQ(last_msg_->certificate_bytes[51], 203)
      << "incorrect value for certificate_bytes[51], expected 203, is "
      << last_msg_->certificate_bytes[51];
  EXPECT_EQ(last_msg_->certificate_bytes[52], 24)
      << "incorrect value for certificate_bytes[52], expected 24, is "
      << last_msg_->certificate_bytes[52];
  EXPECT_EQ(last_msg_->certificate_bytes[53], 66)
      << "incorrect value for certificate_bytes[53], expected 66, is "
      << last_msg_->certificate_bytes[53];
  EXPECT_EQ(last_msg_->certificate_bytes[54], 52)
      << "incorrect value for certificate_bytes[54], expected 52, is "
      << last_msg_->certificate_bytes[54];
  EXPECT_EQ(last_msg_->certificate_bytes[55], 35)
      << "incorrect value for certificate_bytes[55], expected 35, is "
      << last_msg_->certificate_bytes[55];
  EXPECT_EQ(last_msg_->certificate_bytes[56], 26)
      << "incorrect value for certificate_bytes[56], expected 26, is "
      << last_msg_->certificate_bytes[56];
  EXPECT_EQ(last_msg_->certificate_bytes[57], 30)
      << "incorrect value for certificate_bytes[57], expected 30, is "
      << last_msg_->certificate_bytes[57];
  EXPECT_EQ(last_msg_->certificate_bytes[58], 140)
      << "incorrect value for certificate_bytes[58], expected 140, is "
      << last_msg_->certificate_bytes[58];
  EXPECT_EQ(last_msg_->certificate_bytes[59], 111)
      << "incorrect value for certificate_bytes[59], expected 111, is "
      << last_msg_->certificate_bytes[59];
  EXPECT_EQ(last_msg_->certificate_bytes[60], 246)
      << "incorrect value for certificate_bytes[60], expected 246, is "
      << last_msg_->certificate_bytes[60];
  EXPECT_EQ(last_msg_->certificate_bytes[61], 39)
      << "incorrect value for certificate_bytes[61], expected 39, is "
      << last_msg_->certificate_bytes[61];
  EXPECT_EQ(last_msg_->certificate_bytes[62], 226)
      << "incorrect value for certificate_bytes[62], expected 226, is "
      << last_msg_->certificate_bytes[62];
  EXPECT_EQ(last_msg_->certificate_bytes[63], 205)
      << "incorrect value for certificate_bytes[63], expected 205, is "
      << last_msg_->certificate_bytes[63];
  EXPECT_EQ(last_msg_->certificate_bytes[64], 198)
      << "incorrect value for certificate_bytes[64], expected 198, is "
      << last_msg_->certificate_bytes[64];
  EXPECT_EQ(last_msg_->certificate_bytes[65], 178)
      << "incorrect value for certificate_bytes[65], expected 178, is "
      << last_msg_->certificate_bytes[65];
  EXPECT_EQ(last_msg_->certificate_bytes[66], 196)
      << "incorrect value for certificate_bytes[66], expected 196, is "
      << last_msg_->certificate_bytes[66];
  EXPECT_EQ(last_msg_->certificate_bytes[67], 5)
      << "incorrect value for certificate_bytes[67], expected 5, is "
      << last_msg_->certificate_bytes[67];
  EXPECT_EQ(last_msg_->certificate_bytes[68], 81)
      << "incorrect value for certificate_bytes[68], expected 81, is "
      << last_msg_->certificate_bytes[68];
  EXPECT_EQ(last_msg_->certificate_bytes[69], 9)
      << "incorrect value for certificate_bytes[69], expected 9, is "
      << last_msg_->certificate_bytes[69];
  EXPECT_EQ(last_msg_->certificate_bytes[70], 44)
      << "incorrect value for certificate_bytes[70], expected 44, is "
      << last_msg_->certificate_bytes[70];
  EXPECT_EQ(last_msg_->certificate_bytes[71], 164)
      << "incorrect value for certificate_bytes[71], expected 164, is "
      << last_msg_->certificate_bytes[71];
  EXPECT_EQ(last_msg_->certificate_bytes[72], 163)
      << "incorrect value for certificate_bytes[72], expected 163, is "
      << last_msg_->certificate_bytes[72];
  EXPECT_EQ(last_msg_->certificate_bytes[73], 214)
      << "incorrect value for certificate_bytes[73], expected 214, is "
      << last_msg_->certificate_bytes[73];
  EXPECT_EQ(last_msg_->certificate_bytes[74], 138)
      << "incorrect value for certificate_bytes[74], expected 138, is "
      << last_msg_->certificate_bytes[74];
  EXPECT_EQ(last_msg_->certificate_bytes[75], 123)
      << "incorrect value for certificate_bytes[75], expected 123, is "
      << last_msg_->certificate_bytes[75];
  EXPECT_EQ(last_msg_->certificate_bytes[76], 76)
      << "incorrect value for certificate_bytes[76], expected 76, is "
      << last_msg_->certificate_bytes[76];
  EXPECT_EQ(last_msg_->certificate_bytes[77], 74)
      << "incorrect value for certificate_bytes[77], expected 74, is "
      << last_msg_->certificate_bytes[77];
  EXPECT_EQ(last_msg_->certificate_bytes[78], 237)
      << "incorrect value for certificate_bytes[78], expected 237, is "
      << last_msg_->certificate_bytes[78];
  EXPECT_EQ(last_msg_->certificate_bytes[79], 121)
      << "incorrect value for certificate_bytes[79], expected 121, is "
      << last_msg_->certificate_bytes[79];
  EXPECT_EQ(last_msg_->certificate_bytes[80], 13)
      << "incorrect value for certificate_bytes[80], expected 13, is "
      << last_msg_->certificate_bytes[80];
  EXPECT_EQ(last_msg_->certificate_bytes[81], 137)
      << "incorrect value for certificate_bytes[81], expected 137, is "
      << last_msg_->certificate_bytes[81];
  EXPECT_EQ(last_msg_->certificate_bytes[82], 186)
      << "incorrect value for certificate_bytes[82], expected 186, is "
      << last_msg_->certificate_bytes[82];
  EXPECT_EQ(last_msg_->certificate_bytes[83], 97)
      << "incorrect value for certificate_bytes[83], expected 97, is "
      << last_msg_->certificate_bytes[83];
  EXPECT_EQ(last_msg_->certificate_bytes[84], 193)
      << "incorrect value for certificate_bytes[84], expected 193, is "
      << last_msg_->certificate_bytes[84];
  EXPECT_EQ(last_msg_->certificate_bytes[85], 189)
      << "incorrect value for certificate_bytes[85], expected 189, is "
      << last_msg_->certificate_bytes[85];
  EXPECT_EQ(last_msg_->certificate_bytes[86], 200)
      << "incorrect value for certificate_bytes[86], expected 200, is "
      << last_msg_->certificate_bytes[86];
  EXPECT_EQ(last_msg_->certificate_bytes[87], 124)
      << "incorrect value for certificate_bytes[87], expected 124, is "
      << last_msg_->certificate_bytes[87];
  EXPECT_EQ(last_msg_->certificate_bytes[88], 69)
      << "incorrect value for certificate_bytes[88], expected 69, is "
      << last_msg_->certificate_bytes[88];
  EXPECT_EQ(last_msg_->certificate_bytes[89], 115)
      << "incorrect value for certificate_bytes[89], expected 115, is "
      << last_msg_->certificate_bytes[89];
  EXPECT_EQ(last_msg_->certificate_bytes[90], 230)
      << "incorrect value for certificate_bytes[90], expected 230, is "
      << last_msg_->certificate_bytes[90];
  EXPECT_EQ(last_msg_->certificate_bytes[91], 159)
      << "incorrect value for certificate_bytes[91], expected 159, is "
      << last_msg_->certificate_bytes[91];
  EXPECT_EQ(last_msg_->certificate_bytes[92], 185)
      << "incorrect value for certificate_bytes[92], expected 185, is "
      << last_msg_->certificate_bytes[92];
  EXPECT_EQ(last_msg_->certificate_bytes[93], 158)
      << "incorrect value for certificate_bytes[93], expected 158, is "
      << last_msg_->certificate_bytes[93];
  EXPECT_EQ(last_msg_->certificate_bytes[94], 51)
      << "incorrect value for certificate_bytes[94], expected 51, is "
      << last_msg_->certificate_bytes[94];
  EXPECT_EQ(last_msg_->certificate_bytes[95], 12)
      << "incorrect value for certificate_bytes[95], expected 12, is "
      << last_msg_->certificate_bytes[95];
  EXPECT_EQ(last_msg_->certificate_bytes[96], 225)
      << "incorrect value for certificate_bytes[96], expected 225, is "
      << last_msg_->certificate_bytes[96];
  EXPECT_EQ(last_msg_->certificate_bytes[97], 65)
      << "incorrect value for certificate_bytes[97], expected 65, is "
      << last_msg_->certificate_bytes[97];
  EXPECT_EQ(last_msg_->certificate_bytes[98], 192)
      << "incorrect value for certificate_bytes[98], expected 192, is "
      << last_msg_->certificate_bytes[98];
  EXPECT_EQ(last_msg_->certificate_bytes[99], 105)
      << "incorrect value for certificate_bytes[99], expected 105, is "
      << last_msg_->certificate_bytes[99];
  EXPECT_EQ(last_msg_->certificate_bytes[100], 56)
      << "incorrect value for certificate_bytes[100], expected 56, is "
      << last_msg_->certificate_bytes[100];
  EXPECT_EQ(last_msg_->certificate_bytes[101], 41)
      << "incorrect value for certificate_bytes[101], expected 41, is "
      << last_msg_->certificate_bytes[101];
  EXPECT_EQ(last_msg_->certificate_bytes[102], 85)
      << "incorrect value for certificate_bytes[102], expected 85, is "
      << last_msg_->certificate_bytes[102];
  EXPECT_EQ(last_msg_->certificate_bytes[103], 133)
      << "incorrect value for certificate_bytes[103], expected 133, is "
      << last_msg_->certificate_bytes[103];
  EXPECT_EQ(last_msg_->certificate_bytes[104], 19)
      << "incorrect value for certificate_bytes[104], expected 19, is "
      << last_msg_->certificate_bytes[104];
  EXPECT_EQ(last_msg_->certificate_bytes[105], 217)
      << "incorrect value for certificate_bytes[105], expected 217, is "
      << last_msg_->certificate_bytes[105];
  EXPECT_EQ(last_msg_->certificate_bytes[106], 166)
      << "incorrect value for certificate_bytes[106], expected 166, is "
      << last_msg_->certificate_bytes[106];
  EXPECT_EQ(last_msg_->certificate_bytes[107], 48)
      << "incorrect value for certificate_bytes[107], expected 48, is "
      << last_msg_->certificate_bytes[107];
  EXPECT_EQ(last_msg_->certificate_bytes[108], 139)
      << "incorrect value for certificate_bytes[108], expected 139, is "
      << last_msg_->certificate_bytes[108];
  EXPECT_EQ(last_msg_->certificate_bytes[109], 131)
      << "incorrect value for certificate_bytes[109], expected 131, is "
      << last_msg_->certificate_bytes[109];
  EXPECT_EQ(last_msg_->certificate_bytes[110], 96)
      << "incorrect value for certificate_bytes[110], expected 96, is "
      << last_msg_->certificate_bytes[110];
  EXPECT_EQ(last_msg_->certificate_bytes[111], 216)
      << "incorrect value for certificate_bytes[111], expected 216, is "
      << last_msg_->certificate_bytes[111];
  EXPECT_EQ(last_msg_->certificate_bytes[112], 98)
      << "incorrect value for certificate_bytes[112], expected 98, is "
      << last_msg_->certificate_bytes[112];
  EXPECT_EQ(last_msg_->certificate_bytes[113], 147)
      << "incorrect value for certificate_bytes[113], expected 147, is "
      << last_msg_->certificate_bytes[113];
  EXPECT_EQ(last_msg_->certificate_bytes[114], 132)
      << "incorrect value for certificate_bytes[114], expected 132, is "
      << last_msg_->certificate_bytes[114];
  EXPECT_EQ(last_msg_->certificate_bytes[115], 234)
      << "incorrect value for certificate_bytes[115], expected 234, is "
      << last_msg_->certificate_bytes[115];
  EXPECT_EQ(last_msg_->certificate_bytes[116], 167)
      << "incorrect value for certificate_bytes[116], expected 167, is "
      << last_msg_->certificate_bytes[116];
  EXPECT_EQ(last_msg_->certificate_bytes[117], 248)
      << "incorrect value for certificate_bytes[117], expected 248, is "
      << last_msg_->certificate_bytes[117];
  EXPECT_EQ(last_msg_->certificate_bytes[118], 247)
      << "incorrect value for certificate_bytes[118], expected 247, is "
      << last_msg_->certificate_bytes[118];
  EXPECT_EQ(last_msg_->certificate_bytes[119], 32)
      << "incorrect value for certificate_bytes[119], expected 32, is "
      << last_msg_->certificate_bytes[119];
  EXPECT_EQ(last_msg_->certificate_bytes[120], 239)
      << "incorrect value for certificate_bytes[120], expected 239, is "
      << last_msg_->certificate_bytes[120];
  EXPECT_EQ(last_msg_->certificate_bytes[121], 194)
      << "incorrect value for certificate_bytes[121], expected 194, is "
      << last_msg_->certificate_bytes[121];
  EXPECT_EQ(last_msg_->certificate_bytes[122], 188)
      << "incorrect value for certificate_bytes[122], expected 188, is "
      << last_msg_->certificate_bytes[122];
  EXPECT_EQ(last_msg_->certificate_bytes[123], 254)
      << "incorrect value for certificate_bytes[123], expected 254, is "
      << last_msg_->certificate_bytes[123];
  EXPECT_EQ(last_msg_->certificate_bytes[124], 114)
      << "incorrect value for certificate_bytes[124], expected 114, is "
      << last_msg_->certificate_bytes[124];
  EXPECT_EQ(last_msg_->certificate_bytes[125], 117)
      << "incorrect value for certificate_bytes[125], expected 117, is "
      << last_msg_->certificate_bytes[125];
  EXPECT_EQ(last_msg_->certificate_bytes[126], 83)
      << "incorrect value for certificate_bytes[126], expected 83, is "
      << last_msg_->certificate_bytes[126];
  EXPECT_EQ(last_msg_->certificate_bytes[127], 25)
      << "incorrect value for certificate_bytes[127], expected 25, is "
      << last_msg_->certificate_bytes[127];
  EXPECT_EQ(last_msg_->certificate_bytes[128], 251)
      << "incorrect value for certificate_bytes[128], expected 251, is "
      << last_msg_->certificate_bytes[128];
  EXPECT_EQ(last_msg_->certificate_bytes[129], 191)
      << "incorrect value for certificate_bytes[129], expected 191, is "
      << last_msg_->certificate_bytes[129];
  EXPECT_EQ(last_msg_->certificate_bytes[130], 104)
      << "incorrect value for certificate_bytes[130], expected 104, is "
      << last_msg_->certificate_bytes[130];
  EXPECT_EQ(last_msg_->certificate_bytes[131], 240)
      << "incorrect value for certificate_bytes[131], expected 240, is "
      << last_msg_->certificate_bytes[131];
  EXPECT_EQ(last_msg_->certificate_bytes[132], 118)
      << "incorrect value for certificate_bytes[132], expected 118, is "
      << last_msg_->certificate_bytes[132];
  EXPECT_EQ(last_msg_->certificate_bytes[133], 68)
      << "incorrect value for certificate_bytes[133], expected 68, is "
      << last_msg_->certificate_bytes[133];
  EXPECT_EQ(last_msg_->certificate_bytes[134], 42)
      << "incorrect value for certificate_bytes[134], expected 42, is "
      << last_msg_->certificate_bytes[134];
  EXPECT_EQ(last_msg_->certificate_bytes[135], 93)
      << "incorrect value for certificate_bytes[135], expected 93, is "
      << last_msg_->certificate_bytes[135];
  EXPECT_EQ(last_msg_->certificate_bytes[136], 18)
      << "incorrect value for certificate_bytes[136], expected 18, is "
      << last_msg_->certificate_bytes[136];
  EXPECT_EQ(last_msg_->certificate_bytes[137], 16)
      << "incorrect value for certificate_bytes[137], expected 16, is "
      << last_msg_->certificate_bytes[137];
  EXPECT_EQ(last_msg_->certificate_bytes[138], 37)
      << "incorrect value for certificate_bytes[138], expected 37, is "
      << last_msg_->certificate_bytes[138];
  EXPECT_EQ(last_msg_->certificate_bytes[139], 232)
      << "incorrect value for certificate_bytes[139], expected 232, is "
      << last_msg_->certificate_bytes[139];
  EXPECT_EQ(last_msg_->certificate_bytes[140], 99)
      << "incorrect value for certificate_bytes[140], expected 99, is "
      << last_msg_->certificate_bytes[140];
  EXPECT_EQ(last_msg_->certificate_bytes[141], 179)
      << "incorrect value for certificate_bytes[141], expected 179, is "
      << last_msg_->certificate_bytes[141];
  EXPECT_EQ(last_msg_->certificate_bytes[142], 23)
      << "incorrect value for certificate_bytes[142], expected 23, is "
      << last_msg_->certificate_bytes[142];
  EXPECT_EQ(last_msg_->certificate_bytes[143], 90)
      << "incorrect value for certificate_bytes[143], expected 90, is "
      << last_msg_->certificate_bytes[143];
  EXPECT_EQ(last_msg_->certificate_bytes[144], 94)
      << "incorrect value for certificate_bytes[144], expected 94, is "
      << last_msg_->certificate_bytes[144];
  EXPECT_EQ(last_msg_->certificate_bytes[145], 136)
      << "incorrect value for certificate_bytes[145], expected 136, is "
      << last_msg_->certificate_bytes[145];
  EXPECT_EQ(last_msg_->certificate_bytes[146], 6)
      << "incorrect value for certificate_bytes[146], expected 6, is "
      << last_msg_->certificate_bytes[146];
  EXPECT_EQ(last_msg_->certificate_bytes[147], 125)
      << "incorrect value for certificate_bytes[147], expected 125, is "
      << last_msg_->certificate_bytes[147];
  EXPECT_EQ(last_msg_->certificate_bytes[148], 91)
      << "incorrect value for certificate_bytes[148], expected 91, is "
      << last_msg_->certificate_bytes[148];
  EXPECT_EQ(last_msg_->certificate_bytes[149], 255)
      << "incorrect value for certificate_bytes[149], expected 255, is "
      << last_msg_->certificate_bytes[149];
  EXPECT_EQ(last_msg_->certificate_bytes[150], 15)
      << "incorrect value for certificate_bytes[150], expected 15, is "
      << last_msg_->certificate_bytes[150];
  EXPECT_EQ(last_msg_->certificate_bytes[151], 71)
      << "incorrect value for certificate_bytes[151], expected 71, is "
      << last_msg_->certificate_bytes[151];
  EXPECT_EQ(last_msg_->certificate_bytes[152], 43)
      << "incorrect value for certificate_bytes[152], expected 43, is "
      << last_msg_->certificate_bytes[152];
  EXPECT_EQ(last_msg_->certificate_bytes[153], 46)
      << "incorrect value for certificate_bytes[153], expected 46, is "
      << last_msg_->certificate_bytes[153];
  EXPECT_EQ(last_msg_->certificate_bytes[154], 25)
      << "incorrect value for certificate_bytes[154], expected 25, is "
      << last_msg_->certificate_bytes[154];
  EXPECT_EQ(last_msg_->certificate_bytes[155], 252)
      << "incorrect value for certificate_bytes[155], expected 252, is "
      << last_msg_->certificate_bytes[155];
  EXPECT_EQ(last_msg_->certificate_bytes[156], 229)
      << "incorrect value for certificate_bytes[156], expected 229, is "
      << last_msg_->certificate_bytes[156];
  EXPECT_EQ(last_msg_->certificate_bytes[157], 80)
      << "incorrect value for certificate_bytes[157], expected 80, is "
      << last_msg_->certificate_bytes[157];
  EXPECT_EQ(last_msg_->certificate_bytes[158], 143)
      << "incorrect value for certificate_bytes[158], expected 143, is "
      << last_msg_->certificate_bytes[158];
  EXPECT_EQ(last_msg_->certificate_bytes[159], 58)
      << "incorrect value for certificate_bytes[159], expected 58, is "
      << last_msg_->certificate_bytes[159];
  EXPECT_EQ(last_msg_->certificate_bytes[160], 241)
      << "incorrect value for certificate_bytes[160], expected 241, is "
      << last_msg_->certificate_bytes[160];
  EXPECT_EQ(last_msg_->certificate_bytes[161], 11)
      << "incorrect value for certificate_bytes[161], expected 11, is "
      << last_msg_->certificate_bytes[161];
  EXPECT_EQ(last_msg_->certificate_bytes[162], 62)
      << "incorrect value for certificate_bytes[162], expected 62, is "
      << last_msg_->certificate_bytes[162];
  EXPECT_EQ(last_msg_->certificate_bytes[163], 181)
      << "incorrect value for certificate_bytes[163], expected 181, is "
      << last_msg_->certificate_bytes[163];
  EXPECT_EQ(last_msg_->certificate_bytes[164], 155)
      << "incorrect value for certificate_bytes[164], expected 155, is "
      << last_msg_->certificate_bytes[164];
  EXPECT_EQ(last_msg_->certificate_bytes[165], 53)
      << "incorrect value for certificate_bytes[165], expected 53, is "
      << last_msg_->certificate_bytes[165];
  EXPECT_EQ(last_msg_->certificate_bytes[166], 153)
      << "incorrect value for certificate_bytes[166], expected 153, is "
      << last_msg_->certificate_bytes[166];
  EXPECT_EQ(last_msg_->certificate_bytes[167], 149)
      << "incorrect value for certificate_bytes[167], expected 149, is "
      << last_msg_->certificate_bytes[167];
  EXPECT_EQ(last_msg_->certificate_bytes[168], 152)
      << "incorrect value for certificate_bytes[168], expected 152, is "
      << last_msg_->certificate_bytes[168];
  EXPECT_EQ(last_msg_->certificate_bytes[169], 227)
      << "incorrect value for certificate_bytes[169], expected 227, is "
      << last_msg_->certificate_bytes[169];
  EXPECT_EQ(last_msg_->certificate_bytes[170], 150)
      << "incorrect value for certificate_bytes[170], expected 150, is "
      << last_msg_->certificate_bytes[170];
  EXPECT_EQ(last_msg_->certificate_bytes[171], 87)
      << "incorrect value for certificate_bytes[171], expected 87, is "
      << last_msg_->certificate_bytes[171];
  EXPECT_EQ(last_msg_->certificate_bytes[172], 112)
      << "incorrect value for certificate_bytes[172], expected 112, is "
      << last_msg_->certificate_bytes[172];
  EXPECT_EQ(last_msg_->certificate_bytes[173], 165)
      << "incorrect value for certificate_bytes[173], expected 165, is "
      << last_msg_->certificate_bytes[173];
  EXPECT_EQ(last_msg_->certificate_bytes[174], 2)
      << "incorrect value for certificate_bytes[174], expected 2, is "
      << last_msg_->certificate_bytes[174];
  EXPECT_EQ(last_msg_->certificate_bytes[175], 128)
      << "incorrect value for certificate_bytes[175], expected 128, is "
      << last_msg_->certificate_bytes[175];
  EXPECT_EQ(last_msg_->certificate_bytes[176], 231)
      << "incorrect value for certificate_bytes[176], expected 231, is "
      << last_msg_->certificate_bytes[176];
  EXPECT_EQ(last_msg_->certificate_bytes[177], 25)
      << "incorrect value for certificate_bytes[177], expected 25, is "
      << last_msg_->certificate_bytes[177];
  EXPECT_EQ(last_msg_->certificate_bytes[178], 157)
      << "incorrect value for certificate_bytes[178], expected 157, is "
      << last_msg_->certificate_bytes[178];
  EXPECT_EQ(last_msg_->certificate_bytes[179], 244)
      << "incorrect value for certificate_bytes[179], expected 244, is "
      << last_msg_->certificate_bytes[179];
  EXPECT_EQ(last_msg_->certificate_bytes[180], 204)
      << "incorrect value for certificate_bytes[180], expected 204, is "
      << last_msg_->certificate_bytes[180];
  EXPECT_EQ(last_msg_->certificate_bytes[181], 108)
      << "incorrect value for certificate_bytes[181], expected 108, is "
      << last_msg_->certificate_bytes[181];
  EXPECT_EQ(last_msg_->certificate_bytes[182], 253)
      << "incorrect value for certificate_bytes[182], expected 253, is "
      << last_msg_->certificate_bytes[182];
  EXPECT_EQ(last_msg_->certificate_bytes[183], 127)
      << "incorrect value for certificate_bytes[183], expected 127, is "
      << last_msg_->certificate_bytes[183];
  EXPECT_EQ(last_msg_->certificate_bytes[184], 122)
      << "incorrect value for certificate_bytes[184], expected 122, is "
      << last_msg_->certificate_bytes[184];
  EXPECT_EQ(last_msg_->certificate_bytes[185], 145)
      << "incorrect value for certificate_bytes[185], expected 145, is "
      << last_msg_->certificate_bytes[185];
  EXPECT_EQ(last_msg_->certificate_bytes[186], 113)
      << "incorrect value for certificate_bytes[186], expected 113, is "
      << last_msg_->certificate_bytes[186];
  EXPECT_EQ(last_msg_->certificate_bytes[187], 162)
      << "incorrect value for certificate_bytes[187], expected 162, is "
      << last_msg_->certificate_bytes[187];
  EXPECT_EQ(last_msg_->certificate_bytes[188], 197)
      << "incorrect value for certificate_bytes[188], expected 197, is "
      << last_msg_->certificate_bytes[188];
  EXPECT_EQ(last_msg_->certificate_bytes[189], 171)
      << "incorrect value for certificate_bytes[189], expected 171, is "
      << last_msg_->certificate_bytes[189];
  EXPECT_EQ(last_msg_->certificate_bytes[190], 199)
      << "incorrect value for certificate_bytes[190], expected 199, is "
      << last_msg_->certificate_bytes[190];
  EXPECT_EQ(last_msg_->certificate_bytes[191], 54)
      << "incorrect value for certificate_bytes[191], expected 54, is "
      << last_msg_->certificate_bytes[191];
  EXPECT_EQ(last_msg_->certificate_bytes[192], 184)
      << "incorrect value for certificate_bytes[192], expected 184, is "
      << last_msg_->certificate_bytes[192];
  EXPECT_EQ(last_msg_->certificate_bytes[193], 222)
      << "incorrect value for certificate_bytes[193], expected 222, is "
      << last_msg_->certificate_bytes[193];
  EXPECT_EQ(last_msg_->certificate_bytes[194], 206)
      << "incorrect value for certificate_bytes[194], expected 206, is "
      << last_msg_->certificate_bytes[194];
  EXPECT_EQ(last_msg_->certificate_bytes[195], 67)
      << "incorrect value for certificate_bytes[195], expected 67, is "
      << last_msg_->certificate_bytes[195];
  EXPECT_EQ(last_msg_->certificate_bytes[196], 144)
      << "incorrect value for certificate_bytes[196], expected 144, is "
      << last_msg_->certificate_bytes[196];
  EXPECT_EQ(last_msg_->certificate_bytes[197], 78)
      << "incorrect value for certificate_bytes[197], expected 78, is "
      << last_msg_->certificate_bytes[197];
  EXPECT_EQ(last_msg_->certificate_bytes[198], 187)
      << "incorrect value for certificate_bytes[198], expected 187, is "
      << last_msg_->certificate_bytes[198];
  EXPECT_EQ(last_msg_->certificate_bytes[199], 207)
      << "incorrect value for certificate_bytes[199], expected 207, is "
      << last_msg_->certificate_bytes[199];
  EXPECT_EQ(last_msg_->certificate_bytes[200], 60)
      << "incorrect value for certificate_bytes[200], expected 60, is "
      << last_msg_->certificate_bytes[200];
  EXPECT_EQ(last_msg_->certificate_bytes[201], 211)
      << "incorrect value for certificate_bytes[201], expected 211, is "
      << last_msg_->certificate_bytes[201];
  EXPECT_EQ(last_msg_->certificate_bytes[202], 141)
      << "incorrect value for certificate_bytes[202], expected 141, is "
      << last_msg_->certificate_bytes[202];
  EXPECT_EQ(last_msg_->certificate_bytes[203], 135)
      << "incorrect value for certificate_bytes[203], expected 135, is "
      << last_msg_->certificate_bytes[203];
  EXPECT_EQ(last_msg_->certificate_bytes[204], 106)
      << "incorrect value for certificate_bytes[204], expected 106, is "
      << last_msg_->certificate_bytes[204];
  EXPECT_EQ(last_msg_->certificate_bytes[205], 220)
      << "incorrect value for certificate_bytes[205], expected 220, is "
      << last_msg_->certificate_bytes[205];
  EXPECT_EQ(last_msg_->certificate_bytes[206], 79)
      << "incorrect value for certificate_bytes[206], expected 79, is "
      << last_msg_->certificate_bytes[206];
  EXPECT_EQ(last_msg_->certificate_bytes[207], 183)
      << "incorrect value for certificate_bytes[207], expected 183, is "
      << last_msg_->certificate_bytes[207];
  EXPECT_EQ(last_msg_->certificate_bytes[208], 245)
      << "incorrect value for certificate_bytes[208], expected 245, is "
      << last_msg_->certificate_bytes[208];
  EXPECT_EQ(last_msg_->certificate_bytes[209], 21)
      << "incorrect value for certificate_bytes[209], expected 21, is "
      << last_msg_->certificate_bytes[209];
  EXPECT_EQ(last_msg_->certificate_bytes[210], 161)
      << "incorrect value for certificate_bytes[210], expected 161, is "
      << last_msg_->certificate_bytes[210];
  EXPECT_EQ(last_msg_->certificate_bytes[211], 168)
      << "incorrect value for certificate_bytes[211], expected 168, is "
      << last_msg_->certificate_bytes[211];
  EXPECT_EQ(last_msg_->certificate_bytes[212], 34)
      << "incorrect value for certificate_bytes[212], expected 34, is "
      << last_msg_->certificate_bytes[212];
  EXPECT_EQ(last_msg_->certificate_bytes[213], 129)
      << "incorrect value for certificate_bytes[213], expected 129, is "
      << last_msg_->certificate_bytes[213];
  EXPECT_EQ(last_msg_->certificate_bytes[214], 50)
      << "incorrect value for certificate_bytes[214], expected 50, is "
      << last_msg_->certificate_bytes[214];
  EXPECT_EQ(last_msg_->certificate_bytes[215], 176)
      << "incorrect value for certificate_bytes[215], expected 176, is "
      << last_msg_->certificate_bytes[215];
  EXPECT_EQ(last_msg_->certificate_bytes[216], 1)
      << "incorrect value for certificate_bytes[216], expected 1, is "
      << last_msg_->certificate_bytes[216];
  EXPECT_EQ(last_msg_->certificate_bytes[217], 218)
      << "incorrect value for certificate_bytes[217], expected 218, is "
      << last_msg_->certificate_bytes[217];
  EXPECT_EQ(last_msg_->certificate_bytes[218], 20)
      << "incorrect value for certificate_bytes[218], expected 20, is "
      << last_msg_->certificate_bytes[218];
  EXPECT_EQ(last_msg_->certificate_bytes[219], 130)
      << "incorrect value for certificate_bytes[219], expected 130, is "
      << last_msg_->certificate_bytes[219];
  EXPECT_EQ(last_msg_->certificate_bytes[220], 59)
      << "incorrect value for certificate_bytes[220], expected 59, is "
      << last_msg_->certificate_bytes[220];
  EXPECT_EQ(last_msg_->certificate_bytes[221], 249)
      << "incorrect value for certificate_bytes[221], expected 249, is "
      << last_msg_->certificate_bytes[221];
  EXPECT_EQ(last_msg_->certificate_bytes[222], 109)
      << "incorrect value for certificate_bytes[222], expected 109, is "
      << last_msg_->certificate_bytes[222];
  EXPECT_EQ(last_msg_->certificate_bytes[223], 219)
      << "incorrect value for certificate_bytes[223], expected 219, is "
      << last_msg_->certificate_bytes[223];
  EXPECT_EQ(last_msg_->certificate_bytes[224], 0)
      << "incorrect value for certificate_bytes[224], expected 0, is "
      << last_msg_->certificate_bytes[224];
  EXPECT_EQ(last_msg_->certificate_bytes[225], 100)
      << "incorrect value for certificate_bytes[225], expected 100, is "
      << last_msg_->certificate_bytes[225];
  EXPECT_EQ(last_msg_->certificate_bytes[226], 103)
      << "incorrect value for certificate_bytes[226], expected 103, is "
      << last_msg_->certificate_bytes[226];
  EXPECT_EQ(last_msg_->certificate_bytes[227], 55)
      << "incorrect value for certificate_bytes[227], expected 55, is "
      << last_msg_->certificate_bytes[227];
  EXPECT_EQ(last_msg_->certificate_bytes[228], 29)
      << "incorrect value for certificate_bytes[228], expected 29, is "
      << last_msg_->certificate_bytes[228];
  EXPECT_EQ(last_msg_->certificate_bytes[229], 242)
      << "incorrect value for certificate_bytes[229], expected 242, is "
      << last_msg_->certificate_bytes[229];
  EXPECT_EQ(last_msg_->certificate_bytes[230], 110)
      << "incorrect value for certificate_bytes[230], expected 110, is "
      << last_msg_->certificate_bytes[230];
  EXPECT_EQ(last_msg_->certificate_bytes[231], 154)
      << "incorrect value for certificate_bytes[231], expected 154, is "
      << last_msg_->certificate_bytes[231];
  EXPECT_EQ(last_msg_->certificate_bytes[232], 190)
      << "incorrect value for certificate_bytes[232], expected 190, is "
      << last_msg_->certificate_bytes[232];
  EXPECT_EQ(last_msg_->certificate_bytes[233], 233)
      << "incorrect value for certificate_bytes[233], expected 233, is "
      << last_msg_->certificate_bytes[233];
  EXPECT_EQ(last_msg_->certificate_bytes[234], 142)
      << "incorrect value for certificate_bytes[234], expected 142, is "
      << last_msg_->certificate_bytes[234];
  EXPECT_EQ(last_msg_->certificate_bytes[235], 45)
      << "incorrect value for certificate_bytes[235], expected 45, is "
      << last_msg_->certificate_bytes[235];
  EXPECT_EQ(last_msg_->certificate_bytes[236], 61)
      << "incorrect value for certificate_bytes[236], expected 61, is "
      << last_msg_->certificate_bytes[236];
  EXPECT_EQ(last_msg_->certificate_bytes[237], 215)
      << "incorrect value for certificate_bytes[237], expected 215, is "
      << last_msg_->certificate_bytes[237];
  EXPECT_EQ(last_msg_->certificate_bytes[238], 202)
      << "incorrect value for certificate_bytes[238], expected 202, is "
      << last_msg_->certificate_bytes[238];
  EXPECT_EQ(last_msg_->certificate_bytes[239], 238)
      << "incorrect value for certificate_bytes[239], expected 238, is "
      << last_msg_->certificate_bytes[239];
  EXPECT_EQ(last_msg_->certificate_bytes[240], 88)
      << "incorrect value for certificate_bytes[240], expected 88, is "
      << last_msg_->certificate_bytes[240];
  EXPECT_EQ(last_msg_->certificate_bytes[241], 209)
      << "incorrect value for certificate_bytes[241], expected 209, is "
      << last_msg_->certificate_bytes[241];
  EXPECT_EQ(last_msg_->certificate_bytes[242], 70)
      << "incorrect value for certificate_bytes[242], expected 70, is "
      << last_msg_->certificate_bytes[242];
  EXPECT_EQ(last_msg_->certificate_bytes[243], 63)
      << "incorrect value for certificate_bytes[243], expected 63, is "
      << last_msg_->certificate_bytes[243];
  EXPECT_EQ(last_msg_->certificate_bytes[244], 151)
      << "incorrect value for certificate_bytes[244], expected 151, is "
      << last_msg_->certificate_bytes[244];
  EXPECT_EQ(last_msg_->certificate_bytes[245], 27)
      << "incorrect value for certificate_bytes[245], expected 27, is "
      << last_msg_->certificate_bytes[245];
  EXPECT_EQ(last_msg_->certificate_bytes[246], 102)
      << "incorrect value for certificate_bytes[246], expected 102, is "
      << last_msg_->certificate_bytes[246];
  EXPECT_EQ(last_msg_->certificate_id[0], 10)
      << "incorrect value for certificate_id[0], expected 10, is "
      << last_msg_->certificate_id[0];
  EXPECT_EQ(last_msg_->certificate_id[1], 11)
      << "incorrect value for certificate_id[1], expected 11, is "
      << last_msg_->certificate_id[1];
  EXPECT_EQ(last_msg_->certificate_id[2], 12)
      << "incorrect value for certificate_id[2], expected 12, is "
      << last_msg_->certificate_id[2];
  EXPECT_EQ(last_msg_->certificate_id[3], 13)
      << "incorrect value for certificate_id[3], expected 13, is "
      << last_msg_->certificate_id[3];
  EXPECT_EQ(last_msg_->flags, 2)
      << "incorrect value for flags, expected 2, is " << last_msg_->flags;
  EXPECT_EQ(last_msg_->n_msg, 48)
      << "incorrect value for n_msg, expected 48, is " << last_msg_->n_msg;
}
