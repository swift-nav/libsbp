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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgSpecanDep.yaml by generate.py. Do
// not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_piksi_MsgSpecanDep0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_specan_dep_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgSpecanDep0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_specan_dep_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_specan_dep_t *>(last_msg_storage_)),
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
                      const msg_specan_dep_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_specan_dep_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgSpecanDep0, Test) {
  uint8_t encoded_frame[] = {
      85,  80,  0,   112, 217, 255, 246, 22,  221, 56,  37,  59,  45,  27,  154,
      97,  198, 69,  154, 1,   144, 69,  205, 20,  18,  70,  51,  211, 89,  69,
      240, 14,  179, 186, 227, 244, 173, 240, 182, 71,  166, 117, 196, 13,  44,
      27,  33,  28,  67,  254, 3,   249, 92,  44,  122, 169, 77,  186, 68,  135,
      63,  168, 162, 89,  36,  186, 99,  63,  105, 116, 216, 44,  67,  212, 156,
      75,  81,  53,  250, 225, 23,  205, 26,  34,  119, 50,  101, 64,  7,   231,
      124, 183, 203, 102, 234, 84,  83,  208, 23,  68,  54,  179, 98,  96,  116,
      244, 246, 94,  104, 94,  13,  56,  210, 18,  191, 22,  133, 81,  153, 159,
      161, 219, 59,  21,  164, 121, 145, 203, 171, 132, 57,  180, 102, 101, 11,
      229, 175, 145, 73,  72,  124, 4,   184, 228, 61,  234, 218, 62,  226, 217,
      193, 7,   109, 44,  83,  201, 20,  101, 9,   140, 186, 162, 81,  91,  30,
      231, 161, 81,  216, 114, 60,  231, 163, 163, 49,  237, 244, 185, 240, 89,
      143, 174, 165, 211, 241, 13,  16,  61,  141, 101, 89,  37,  117, 189, 86,
      118, 176, 228, 12,  14,  119, 135, 129, 243, 50,  29,  207, 198, 117, 100,
      225, 6,   139, 110, 39,  210, 68,  199, 43,  132, 64,  17,  51,  173, 181,
      12,  140, 16,  247, 84,  183, 105, 39,  157, 77,  30,  205, 194, 59,  64,
      241, 183, 238, 105, 181, 170, 45,  8,   166, 164, 238, 83,  148, 173, 108,
      228, 67,  89,  189, 67,  26,  39,  216,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_specan_dep_t *test_msg = (msg_specan_dep_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->amplitude_ref = 9349.2001953125;
  test_msg->amplitude_unit = 3485.199951171875;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[0] = 240;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[1] = 14;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[2] = 179;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[3] = 186;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[4] = 227;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[5] = 244;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[6] = 173;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[7] = 240;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[8] = 182;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[9] = 71;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[10] = 166;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[11] = 117;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[12] = 196;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[13] = 13;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[14] = 44;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[15] = 27;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[16] = 33;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[17] = 28;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[18] = 67;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[19] = 254;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[20] = 3;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[21] = 249;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[22] = 92;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[23] = 44;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[24] = 122;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[25] = 169;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[26] = 77;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[27] = 186;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[28] = 68;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[29] = 135;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[30] = 63;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[31] = 168;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[32] = 162;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[33] = 89;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[34] = 36;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[35] = 186;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[36] = 99;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[37] = 63;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[38] = 105;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[39] = 116;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[40] = 216;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[41] = 44;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[42] = 67;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[43] = 212;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[44] = 156;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[45] = 75;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[46] = 81;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[47] = 53;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[48] = 250;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[49] = 225;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[50] = 23;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[51] = 205;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[52] = 26;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[53] = 34;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[54] = 119;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[55] = 50;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[56] = 101;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[57] = 64;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[58] = 7;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[59] = 231;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[60] = 124;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[61] = 183;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[62] = 203;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[63] = 102;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[64] = 234;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[65] = 84;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[66] = 83;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[67] = 208;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[68] = 23;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[69] = 68;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[70] = 54;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[71] = 179;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[72] = 98;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[73] = 96;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[74] = 116;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[75] = 244;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[76] = 246;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[77] = 94;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[78] = 104;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[79] = 94;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[80] = 13;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[81] = 56;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[82] = 210;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[83] = 18;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[84] = 191;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[85] = 22;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[86] = 133;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[87] = 81;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[88] = 153;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[89] = 159;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[90] = 161;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[91] = 219;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[92] = 59;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[93] = 21;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[94] = 164;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[95] = 121;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[96] = 145;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[97] = 203;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[98] = 171;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[99] = 132;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[100] = 57;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[101] = 180;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[102] = 102;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[103] = 101;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[104] = 11;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[105] = 229;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[106] = 175;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[107] = 145;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[108] = 73;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[109] = 72;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[110] = 124;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[111] = 4;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[112] = 184;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[113] = 228;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[114] = 61;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[115] = 234;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[116] = 218;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[117] = 62;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[118] = 226;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[119] = 217;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[120] = 193;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[121] = 7;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[122] = 109;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[123] = 44;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[124] = 83;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[125] = 201;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[126] = 20;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[127] = 101;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[128] = 9;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[129] = 140;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[130] = 186;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[131] = 162;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[132] = 81;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[133] = 91;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[134] = 30;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[135] = 231;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[136] = 161;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[137] = 81;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[138] = 216;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[139] = 114;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[140] = 60;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[141] = 231;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[142] = 163;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[143] = 163;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[144] = 49;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[145] = 237;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[146] = 244;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[147] = 185;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[148] = 240;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[149] = 89;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[150] = 143;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[151] = 174;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[152] = 165;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[153] = 211;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[154] = 241;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[155] = 13;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[156] = 16;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[157] = 61;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[158] = 141;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[159] = 101;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[160] = 89;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[161] = 37;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[162] = 117;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[163] = 189;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[164] = 86;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[165] = 118;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[166] = 176;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[167] = 228;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[168] = 12;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[169] = 14;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[170] = 119;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[171] = 135;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[172] = 129;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[173] = 243;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[174] = 50;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[175] = 29;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[176] = 207;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[177] = 198;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[178] = 117;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[179] = 100;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[180] = 225;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[181] = 6;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[182] = 139;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[183] = 110;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[184] = 39;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[185] = 210;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[186] = 68;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[187] = 199;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[188] = 43;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[189] = 132;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[190] = 64;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[191] = 17;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[192] = 51;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[193] = 173;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[194] = 181;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[195] = 12;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[196] = 140;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[197] = 16;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[198] = 247;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[199] = 84;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[200] = 183;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[201] = 105;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[202] = 39;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[203] = 157;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[204] = 77;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[205] = 30;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[206] = 205;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[207] = 194;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[208] = 59;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[209] = 64;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[210] = 241;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[211] = 183;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[212] = 238;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[213] = 105;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[214] = 181;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[215] = 170;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[216] = 45;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[217] = 8;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[218] = 166;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[219] = 164;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[220] = 238;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[221] = 83;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[222] = 148;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[223] = 173;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[224] = 108;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[225] = 228;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[226] = 67;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[227] = 89;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[228] = 189;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[229] = 67;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[230] = 26;
  test_msg->channel_tag = 5878;
  test_msg->freq_ref = 6348.2001953125;
  test_msg->freq_step = 4608.2001953125;
  test_msg->t.tow = 992295133;
  test_msg->t.wn = 6957;

  EXPECT_EQ(send_message(0x50, 55664, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55664);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->amplitude_ref * 100 - 9349.20019531 * 100), 0.05)
      << "incorrect value for amplitude_ref, expected 9349.20019531, is "
      << last_msg_->amplitude_ref;
  EXPECT_LT((last_msg_->amplitude_unit * 100 - 3485.19995117 * 100), 0.05)
      << "incorrect value for amplitude_unit, expected 3485.19995117, is "
      << last_msg_->amplitude_unit;
  EXPECT_EQ(last_msg_->amplitude_value[0], 240)
      << "incorrect value for amplitude_value[0], expected 240, is "
      << last_msg_->amplitude_value[0];
  EXPECT_EQ(last_msg_->amplitude_value[1], 14)
      << "incorrect value for amplitude_value[1], expected 14, is "
      << last_msg_->amplitude_value[1];
  EXPECT_EQ(last_msg_->amplitude_value[2], 179)
      << "incorrect value for amplitude_value[2], expected 179, is "
      << last_msg_->amplitude_value[2];
  EXPECT_EQ(last_msg_->amplitude_value[3], 186)
      << "incorrect value for amplitude_value[3], expected 186, is "
      << last_msg_->amplitude_value[3];
  EXPECT_EQ(last_msg_->amplitude_value[4], 227)
      << "incorrect value for amplitude_value[4], expected 227, is "
      << last_msg_->amplitude_value[4];
  EXPECT_EQ(last_msg_->amplitude_value[5], 244)
      << "incorrect value for amplitude_value[5], expected 244, is "
      << last_msg_->amplitude_value[5];
  EXPECT_EQ(last_msg_->amplitude_value[6], 173)
      << "incorrect value for amplitude_value[6], expected 173, is "
      << last_msg_->amplitude_value[6];
  EXPECT_EQ(last_msg_->amplitude_value[7], 240)
      << "incorrect value for amplitude_value[7], expected 240, is "
      << last_msg_->amplitude_value[7];
  EXPECT_EQ(last_msg_->amplitude_value[8], 182)
      << "incorrect value for amplitude_value[8], expected 182, is "
      << last_msg_->amplitude_value[8];
  EXPECT_EQ(last_msg_->amplitude_value[9], 71)
      << "incorrect value for amplitude_value[9], expected 71, is "
      << last_msg_->amplitude_value[9];
  EXPECT_EQ(last_msg_->amplitude_value[10], 166)
      << "incorrect value for amplitude_value[10], expected 166, is "
      << last_msg_->amplitude_value[10];
  EXPECT_EQ(last_msg_->amplitude_value[11], 117)
      << "incorrect value for amplitude_value[11], expected 117, is "
      << last_msg_->amplitude_value[11];
  EXPECT_EQ(last_msg_->amplitude_value[12], 196)
      << "incorrect value for amplitude_value[12], expected 196, is "
      << last_msg_->amplitude_value[12];
  EXPECT_EQ(last_msg_->amplitude_value[13], 13)
      << "incorrect value for amplitude_value[13], expected 13, is "
      << last_msg_->amplitude_value[13];
  EXPECT_EQ(last_msg_->amplitude_value[14], 44)
      << "incorrect value for amplitude_value[14], expected 44, is "
      << last_msg_->amplitude_value[14];
  EXPECT_EQ(last_msg_->amplitude_value[15], 27)
      << "incorrect value for amplitude_value[15], expected 27, is "
      << last_msg_->amplitude_value[15];
  EXPECT_EQ(last_msg_->amplitude_value[16], 33)
      << "incorrect value for amplitude_value[16], expected 33, is "
      << last_msg_->amplitude_value[16];
  EXPECT_EQ(last_msg_->amplitude_value[17], 28)
      << "incorrect value for amplitude_value[17], expected 28, is "
      << last_msg_->amplitude_value[17];
  EXPECT_EQ(last_msg_->amplitude_value[18], 67)
      << "incorrect value for amplitude_value[18], expected 67, is "
      << last_msg_->amplitude_value[18];
  EXPECT_EQ(last_msg_->amplitude_value[19], 254)
      << "incorrect value for amplitude_value[19], expected 254, is "
      << last_msg_->amplitude_value[19];
  EXPECT_EQ(last_msg_->amplitude_value[20], 3)
      << "incorrect value for amplitude_value[20], expected 3, is "
      << last_msg_->amplitude_value[20];
  EXPECT_EQ(last_msg_->amplitude_value[21], 249)
      << "incorrect value for amplitude_value[21], expected 249, is "
      << last_msg_->amplitude_value[21];
  EXPECT_EQ(last_msg_->amplitude_value[22], 92)
      << "incorrect value for amplitude_value[22], expected 92, is "
      << last_msg_->amplitude_value[22];
  EXPECT_EQ(last_msg_->amplitude_value[23], 44)
      << "incorrect value for amplitude_value[23], expected 44, is "
      << last_msg_->amplitude_value[23];
  EXPECT_EQ(last_msg_->amplitude_value[24], 122)
      << "incorrect value for amplitude_value[24], expected 122, is "
      << last_msg_->amplitude_value[24];
  EXPECT_EQ(last_msg_->amplitude_value[25], 169)
      << "incorrect value for amplitude_value[25], expected 169, is "
      << last_msg_->amplitude_value[25];
  EXPECT_EQ(last_msg_->amplitude_value[26], 77)
      << "incorrect value for amplitude_value[26], expected 77, is "
      << last_msg_->amplitude_value[26];
  EXPECT_EQ(last_msg_->amplitude_value[27], 186)
      << "incorrect value for amplitude_value[27], expected 186, is "
      << last_msg_->amplitude_value[27];
  EXPECT_EQ(last_msg_->amplitude_value[28], 68)
      << "incorrect value for amplitude_value[28], expected 68, is "
      << last_msg_->amplitude_value[28];
  EXPECT_EQ(last_msg_->amplitude_value[29], 135)
      << "incorrect value for amplitude_value[29], expected 135, is "
      << last_msg_->amplitude_value[29];
  EXPECT_EQ(last_msg_->amplitude_value[30], 63)
      << "incorrect value for amplitude_value[30], expected 63, is "
      << last_msg_->amplitude_value[30];
  EXPECT_EQ(last_msg_->amplitude_value[31], 168)
      << "incorrect value for amplitude_value[31], expected 168, is "
      << last_msg_->amplitude_value[31];
  EXPECT_EQ(last_msg_->amplitude_value[32], 162)
      << "incorrect value for amplitude_value[32], expected 162, is "
      << last_msg_->amplitude_value[32];
  EXPECT_EQ(last_msg_->amplitude_value[33], 89)
      << "incorrect value for amplitude_value[33], expected 89, is "
      << last_msg_->amplitude_value[33];
  EXPECT_EQ(last_msg_->amplitude_value[34], 36)
      << "incorrect value for amplitude_value[34], expected 36, is "
      << last_msg_->amplitude_value[34];
  EXPECT_EQ(last_msg_->amplitude_value[35], 186)
      << "incorrect value for amplitude_value[35], expected 186, is "
      << last_msg_->amplitude_value[35];
  EXPECT_EQ(last_msg_->amplitude_value[36], 99)
      << "incorrect value for amplitude_value[36], expected 99, is "
      << last_msg_->amplitude_value[36];
  EXPECT_EQ(last_msg_->amplitude_value[37], 63)
      << "incorrect value for amplitude_value[37], expected 63, is "
      << last_msg_->amplitude_value[37];
  EXPECT_EQ(last_msg_->amplitude_value[38], 105)
      << "incorrect value for amplitude_value[38], expected 105, is "
      << last_msg_->amplitude_value[38];
  EXPECT_EQ(last_msg_->amplitude_value[39], 116)
      << "incorrect value for amplitude_value[39], expected 116, is "
      << last_msg_->amplitude_value[39];
  EXPECT_EQ(last_msg_->amplitude_value[40], 216)
      << "incorrect value for amplitude_value[40], expected 216, is "
      << last_msg_->amplitude_value[40];
  EXPECT_EQ(last_msg_->amplitude_value[41], 44)
      << "incorrect value for amplitude_value[41], expected 44, is "
      << last_msg_->amplitude_value[41];
  EXPECT_EQ(last_msg_->amplitude_value[42], 67)
      << "incorrect value for amplitude_value[42], expected 67, is "
      << last_msg_->amplitude_value[42];
  EXPECT_EQ(last_msg_->amplitude_value[43], 212)
      << "incorrect value for amplitude_value[43], expected 212, is "
      << last_msg_->amplitude_value[43];
  EXPECT_EQ(last_msg_->amplitude_value[44], 156)
      << "incorrect value for amplitude_value[44], expected 156, is "
      << last_msg_->amplitude_value[44];
  EXPECT_EQ(last_msg_->amplitude_value[45], 75)
      << "incorrect value for amplitude_value[45], expected 75, is "
      << last_msg_->amplitude_value[45];
  EXPECT_EQ(last_msg_->amplitude_value[46], 81)
      << "incorrect value for amplitude_value[46], expected 81, is "
      << last_msg_->amplitude_value[46];
  EXPECT_EQ(last_msg_->amplitude_value[47], 53)
      << "incorrect value for amplitude_value[47], expected 53, is "
      << last_msg_->amplitude_value[47];
  EXPECT_EQ(last_msg_->amplitude_value[48], 250)
      << "incorrect value for amplitude_value[48], expected 250, is "
      << last_msg_->amplitude_value[48];
  EXPECT_EQ(last_msg_->amplitude_value[49], 225)
      << "incorrect value for amplitude_value[49], expected 225, is "
      << last_msg_->amplitude_value[49];
  EXPECT_EQ(last_msg_->amplitude_value[50], 23)
      << "incorrect value for amplitude_value[50], expected 23, is "
      << last_msg_->amplitude_value[50];
  EXPECT_EQ(last_msg_->amplitude_value[51], 205)
      << "incorrect value for amplitude_value[51], expected 205, is "
      << last_msg_->amplitude_value[51];
  EXPECT_EQ(last_msg_->amplitude_value[52], 26)
      << "incorrect value for amplitude_value[52], expected 26, is "
      << last_msg_->amplitude_value[52];
  EXPECT_EQ(last_msg_->amplitude_value[53], 34)
      << "incorrect value for amplitude_value[53], expected 34, is "
      << last_msg_->amplitude_value[53];
  EXPECT_EQ(last_msg_->amplitude_value[54], 119)
      << "incorrect value for amplitude_value[54], expected 119, is "
      << last_msg_->amplitude_value[54];
  EXPECT_EQ(last_msg_->amplitude_value[55], 50)
      << "incorrect value for amplitude_value[55], expected 50, is "
      << last_msg_->amplitude_value[55];
  EXPECT_EQ(last_msg_->amplitude_value[56], 101)
      << "incorrect value for amplitude_value[56], expected 101, is "
      << last_msg_->amplitude_value[56];
  EXPECT_EQ(last_msg_->amplitude_value[57], 64)
      << "incorrect value for amplitude_value[57], expected 64, is "
      << last_msg_->amplitude_value[57];
  EXPECT_EQ(last_msg_->amplitude_value[58], 7)
      << "incorrect value for amplitude_value[58], expected 7, is "
      << last_msg_->amplitude_value[58];
  EXPECT_EQ(last_msg_->amplitude_value[59], 231)
      << "incorrect value for amplitude_value[59], expected 231, is "
      << last_msg_->amplitude_value[59];
  EXPECT_EQ(last_msg_->amplitude_value[60], 124)
      << "incorrect value for amplitude_value[60], expected 124, is "
      << last_msg_->amplitude_value[60];
  EXPECT_EQ(last_msg_->amplitude_value[61], 183)
      << "incorrect value for amplitude_value[61], expected 183, is "
      << last_msg_->amplitude_value[61];
  EXPECT_EQ(last_msg_->amplitude_value[62], 203)
      << "incorrect value for amplitude_value[62], expected 203, is "
      << last_msg_->amplitude_value[62];
  EXPECT_EQ(last_msg_->amplitude_value[63], 102)
      << "incorrect value for amplitude_value[63], expected 102, is "
      << last_msg_->amplitude_value[63];
  EXPECT_EQ(last_msg_->amplitude_value[64], 234)
      << "incorrect value for amplitude_value[64], expected 234, is "
      << last_msg_->amplitude_value[64];
  EXPECT_EQ(last_msg_->amplitude_value[65], 84)
      << "incorrect value for amplitude_value[65], expected 84, is "
      << last_msg_->amplitude_value[65];
  EXPECT_EQ(last_msg_->amplitude_value[66], 83)
      << "incorrect value for amplitude_value[66], expected 83, is "
      << last_msg_->amplitude_value[66];
  EXPECT_EQ(last_msg_->amplitude_value[67], 208)
      << "incorrect value for amplitude_value[67], expected 208, is "
      << last_msg_->amplitude_value[67];
  EXPECT_EQ(last_msg_->amplitude_value[68], 23)
      << "incorrect value for amplitude_value[68], expected 23, is "
      << last_msg_->amplitude_value[68];
  EXPECT_EQ(last_msg_->amplitude_value[69], 68)
      << "incorrect value for amplitude_value[69], expected 68, is "
      << last_msg_->amplitude_value[69];
  EXPECT_EQ(last_msg_->amplitude_value[70], 54)
      << "incorrect value for amplitude_value[70], expected 54, is "
      << last_msg_->amplitude_value[70];
  EXPECT_EQ(last_msg_->amplitude_value[71], 179)
      << "incorrect value for amplitude_value[71], expected 179, is "
      << last_msg_->amplitude_value[71];
  EXPECT_EQ(last_msg_->amplitude_value[72], 98)
      << "incorrect value for amplitude_value[72], expected 98, is "
      << last_msg_->amplitude_value[72];
  EXPECT_EQ(last_msg_->amplitude_value[73], 96)
      << "incorrect value for amplitude_value[73], expected 96, is "
      << last_msg_->amplitude_value[73];
  EXPECT_EQ(last_msg_->amplitude_value[74], 116)
      << "incorrect value for amplitude_value[74], expected 116, is "
      << last_msg_->amplitude_value[74];
  EXPECT_EQ(last_msg_->amplitude_value[75], 244)
      << "incorrect value for amplitude_value[75], expected 244, is "
      << last_msg_->amplitude_value[75];
  EXPECT_EQ(last_msg_->amplitude_value[76], 246)
      << "incorrect value for amplitude_value[76], expected 246, is "
      << last_msg_->amplitude_value[76];
  EXPECT_EQ(last_msg_->amplitude_value[77], 94)
      << "incorrect value for amplitude_value[77], expected 94, is "
      << last_msg_->amplitude_value[77];
  EXPECT_EQ(last_msg_->amplitude_value[78], 104)
      << "incorrect value for amplitude_value[78], expected 104, is "
      << last_msg_->amplitude_value[78];
  EXPECT_EQ(last_msg_->amplitude_value[79], 94)
      << "incorrect value for amplitude_value[79], expected 94, is "
      << last_msg_->amplitude_value[79];
  EXPECT_EQ(last_msg_->amplitude_value[80], 13)
      << "incorrect value for amplitude_value[80], expected 13, is "
      << last_msg_->amplitude_value[80];
  EXPECT_EQ(last_msg_->amplitude_value[81], 56)
      << "incorrect value for amplitude_value[81], expected 56, is "
      << last_msg_->amplitude_value[81];
  EXPECT_EQ(last_msg_->amplitude_value[82], 210)
      << "incorrect value for amplitude_value[82], expected 210, is "
      << last_msg_->amplitude_value[82];
  EXPECT_EQ(last_msg_->amplitude_value[83], 18)
      << "incorrect value for amplitude_value[83], expected 18, is "
      << last_msg_->amplitude_value[83];
  EXPECT_EQ(last_msg_->amplitude_value[84], 191)
      << "incorrect value for amplitude_value[84], expected 191, is "
      << last_msg_->amplitude_value[84];
  EXPECT_EQ(last_msg_->amplitude_value[85], 22)
      << "incorrect value for amplitude_value[85], expected 22, is "
      << last_msg_->amplitude_value[85];
  EXPECT_EQ(last_msg_->amplitude_value[86], 133)
      << "incorrect value for amplitude_value[86], expected 133, is "
      << last_msg_->amplitude_value[86];
  EXPECT_EQ(last_msg_->amplitude_value[87], 81)
      << "incorrect value for amplitude_value[87], expected 81, is "
      << last_msg_->amplitude_value[87];
  EXPECT_EQ(last_msg_->amplitude_value[88], 153)
      << "incorrect value for amplitude_value[88], expected 153, is "
      << last_msg_->amplitude_value[88];
  EXPECT_EQ(last_msg_->amplitude_value[89], 159)
      << "incorrect value for amplitude_value[89], expected 159, is "
      << last_msg_->amplitude_value[89];
  EXPECT_EQ(last_msg_->amplitude_value[90], 161)
      << "incorrect value for amplitude_value[90], expected 161, is "
      << last_msg_->amplitude_value[90];
  EXPECT_EQ(last_msg_->amplitude_value[91], 219)
      << "incorrect value for amplitude_value[91], expected 219, is "
      << last_msg_->amplitude_value[91];
  EXPECT_EQ(last_msg_->amplitude_value[92], 59)
      << "incorrect value for amplitude_value[92], expected 59, is "
      << last_msg_->amplitude_value[92];
  EXPECT_EQ(last_msg_->amplitude_value[93], 21)
      << "incorrect value for amplitude_value[93], expected 21, is "
      << last_msg_->amplitude_value[93];
  EXPECT_EQ(last_msg_->amplitude_value[94], 164)
      << "incorrect value for amplitude_value[94], expected 164, is "
      << last_msg_->amplitude_value[94];
  EXPECT_EQ(last_msg_->amplitude_value[95], 121)
      << "incorrect value for amplitude_value[95], expected 121, is "
      << last_msg_->amplitude_value[95];
  EXPECT_EQ(last_msg_->amplitude_value[96], 145)
      << "incorrect value for amplitude_value[96], expected 145, is "
      << last_msg_->amplitude_value[96];
  EXPECT_EQ(last_msg_->amplitude_value[97], 203)
      << "incorrect value for amplitude_value[97], expected 203, is "
      << last_msg_->amplitude_value[97];
  EXPECT_EQ(last_msg_->amplitude_value[98], 171)
      << "incorrect value for amplitude_value[98], expected 171, is "
      << last_msg_->amplitude_value[98];
  EXPECT_EQ(last_msg_->amplitude_value[99], 132)
      << "incorrect value for amplitude_value[99], expected 132, is "
      << last_msg_->amplitude_value[99];
  EXPECT_EQ(last_msg_->amplitude_value[100], 57)
      << "incorrect value for amplitude_value[100], expected 57, is "
      << last_msg_->amplitude_value[100];
  EXPECT_EQ(last_msg_->amplitude_value[101], 180)
      << "incorrect value for amplitude_value[101], expected 180, is "
      << last_msg_->amplitude_value[101];
  EXPECT_EQ(last_msg_->amplitude_value[102], 102)
      << "incorrect value for amplitude_value[102], expected 102, is "
      << last_msg_->amplitude_value[102];
  EXPECT_EQ(last_msg_->amplitude_value[103], 101)
      << "incorrect value for amplitude_value[103], expected 101, is "
      << last_msg_->amplitude_value[103];
  EXPECT_EQ(last_msg_->amplitude_value[104], 11)
      << "incorrect value for amplitude_value[104], expected 11, is "
      << last_msg_->amplitude_value[104];
  EXPECT_EQ(last_msg_->amplitude_value[105], 229)
      << "incorrect value for amplitude_value[105], expected 229, is "
      << last_msg_->amplitude_value[105];
  EXPECT_EQ(last_msg_->amplitude_value[106], 175)
      << "incorrect value for amplitude_value[106], expected 175, is "
      << last_msg_->amplitude_value[106];
  EXPECT_EQ(last_msg_->amplitude_value[107], 145)
      << "incorrect value for amplitude_value[107], expected 145, is "
      << last_msg_->amplitude_value[107];
  EXPECT_EQ(last_msg_->amplitude_value[108], 73)
      << "incorrect value for amplitude_value[108], expected 73, is "
      << last_msg_->amplitude_value[108];
  EXPECT_EQ(last_msg_->amplitude_value[109], 72)
      << "incorrect value for amplitude_value[109], expected 72, is "
      << last_msg_->amplitude_value[109];
  EXPECT_EQ(last_msg_->amplitude_value[110], 124)
      << "incorrect value for amplitude_value[110], expected 124, is "
      << last_msg_->amplitude_value[110];
  EXPECT_EQ(last_msg_->amplitude_value[111], 4)
      << "incorrect value for amplitude_value[111], expected 4, is "
      << last_msg_->amplitude_value[111];
  EXPECT_EQ(last_msg_->amplitude_value[112], 184)
      << "incorrect value for amplitude_value[112], expected 184, is "
      << last_msg_->amplitude_value[112];
  EXPECT_EQ(last_msg_->amplitude_value[113], 228)
      << "incorrect value for amplitude_value[113], expected 228, is "
      << last_msg_->amplitude_value[113];
  EXPECT_EQ(last_msg_->amplitude_value[114], 61)
      << "incorrect value for amplitude_value[114], expected 61, is "
      << last_msg_->amplitude_value[114];
  EXPECT_EQ(last_msg_->amplitude_value[115], 234)
      << "incorrect value for amplitude_value[115], expected 234, is "
      << last_msg_->amplitude_value[115];
  EXPECT_EQ(last_msg_->amplitude_value[116], 218)
      << "incorrect value for amplitude_value[116], expected 218, is "
      << last_msg_->amplitude_value[116];
  EXPECT_EQ(last_msg_->amplitude_value[117], 62)
      << "incorrect value for amplitude_value[117], expected 62, is "
      << last_msg_->amplitude_value[117];
  EXPECT_EQ(last_msg_->amplitude_value[118], 226)
      << "incorrect value for amplitude_value[118], expected 226, is "
      << last_msg_->amplitude_value[118];
  EXPECT_EQ(last_msg_->amplitude_value[119], 217)
      << "incorrect value for amplitude_value[119], expected 217, is "
      << last_msg_->amplitude_value[119];
  EXPECT_EQ(last_msg_->amplitude_value[120], 193)
      << "incorrect value for amplitude_value[120], expected 193, is "
      << last_msg_->amplitude_value[120];
  EXPECT_EQ(last_msg_->amplitude_value[121], 7)
      << "incorrect value for amplitude_value[121], expected 7, is "
      << last_msg_->amplitude_value[121];
  EXPECT_EQ(last_msg_->amplitude_value[122], 109)
      << "incorrect value for amplitude_value[122], expected 109, is "
      << last_msg_->amplitude_value[122];
  EXPECT_EQ(last_msg_->amplitude_value[123], 44)
      << "incorrect value for amplitude_value[123], expected 44, is "
      << last_msg_->amplitude_value[123];
  EXPECT_EQ(last_msg_->amplitude_value[124], 83)
      << "incorrect value for amplitude_value[124], expected 83, is "
      << last_msg_->amplitude_value[124];
  EXPECT_EQ(last_msg_->amplitude_value[125], 201)
      << "incorrect value for amplitude_value[125], expected 201, is "
      << last_msg_->amplitude_value[125];
  EXPECT_EQ(last_msg_->amplitude_value[126], 20)
      << "incorrect value for amplitude_value[126], expected 20, is "
      << last_msg_->amplitude_value[126];
  EXPECT_EQ(last_msg_->amplitude_value[127], 101)
      << "incorrect value for amplitude_value[127], expected 101, is "
      << last_msg_->amplitude_value[127];
  EXPECT_EQ(last_msg_->amplitude_value[128], 9)
      << "incorrect value for amplitude_value[128], expected 9, is "
      << last_msg_->amplitude_value[128];
  EXPECT_EQ(last_msg_->amplitude_value[129], 140)
      << "incorrect value for amplitude_value[129], expected 140, is "
      << last_msg_->amplitude_value[129];
  EXPECT_EQ(last_msg_->amplitude_value[130], 186)
      << "incorrect value for amplitude_value[130], expected 186, is "
      << last_msg_->amplitude_value[130];
  EXPECT_EQ(last_msg_->amplitude_value[131], 162)
      << "incorrect value for amplitude_value[131], expected 162, is "
      << last_msg_->amplitude_value[131];
  EXPECT_EQ(last_msg_->amplitude_value[132], 81)
      << "incorrect value for amplitude_value[132], expected 81, is "
      << last_msg_->amplitude_value[132];
  EXPECT_EQ(last_msg_->amplitude_value[133], 91)
      << "incorrect value for amplitude_value[133], expected 91, is "
      << last_msg_->amplitude_value[133];
  EXPECT_EQ(last_msg_->amplitude_value[134], 30)
      << "incorrect value for amplitude_value[134], expected 30, is "
      << last_msg_->amplitude_value[134];
  EXPECT_EQ(last_msg_->amplitude_value[135], 231)
      << "incorrect value for amplitude_value[135], expected 231, is "
      << last_msg_->amplitude_value[135];
  EXPECT_EQ(last_msg_->amplitude_value[136], 161)
      << "incorrect value for amplitude_value[136], expected 161, is "
      << last_msg_->amplitude_value[136];
  EXPECT_EQ(last_msg_->amplitude_value[137], 81)
      << "incorrect value for amplitude_value[137], expected 81, is "
      << last_msg_->amplitude_value[137];
  EXPECT_EQ(last_msg_->amplitude_value[138], 216)
      << "incorrect value for amplitude_value[138], expected 216, is "
      << last_msg_->amplitude_value[138];
  EXPECT_EQ(last_msg_->amplitude_value[139], 114)
      << "incorrect value for amplitude_value[139], expected 114, is "
      << last_msg_->amplitude_value[139];
  EXPECT_EQ(last_msg_->amplitude_value[140], 60)
      << "incorrect value for amplitude_value[140], expected 60, is "
      << last_msg_->amplitude_value[140];
  EXPECT_EQ(last_msg_->amplitude_value[141], 231)
      << "incorrect value for amplitude_value[141], expected 231, is "
      << last_msg_->amplitude_value[141];
  EXPECT_EQ(last_msg_->amplitude_value[142], 163)
      << "incorrect value for amplitude_value[142], expected 163, is "
      << last_msg_->amplitude_value[142];
  EXPECT_EQ(last_msg_->amplitude_value[143], 163)
      << "incorrect value for amplitude_value[143], expected 163, is "
      << last_msg_->amplitude_value[143];
  EXPECT_EQ(last_msg_->amplitude_value[144], 49)
      << "incorrect value for amplitude_value[144], expected 49, is "
      << last_msg_->amplitude_value[144];
  EXPECT_EQ(last_msg_->amplitude_value[145], 237)
      << "incorrect value for amplitude_value[145], expected 237, is "
      << last_msg_->amplitude_value[145];
  EXPECT_EQ(last_msg_->amplitude_value[146], 244)
      << "incorrect value for amplitude_value[146], expected 244, is "
      << last_msg_->amplitude_value[146];
  EXPECT_EQ(last_msg_->amplitude_value[147], 185)
      << "incorrect value for amplitude_value[147], expected 185, is "
      << last_msg_->amplitude_value[147];
  EXPECT_EQ(last_msg_->amplitude_value[148], 240)
      << "incorrect value for amplitude_value[148], expected 240, is "
      << last_msg_->amplitude_value[148];
  EXPECT_EQ(last_msg_->amplitude_value[149], 89)
      << "incorrect value for amplitude_value[149], expected 89, is "
      << last_msg_->amplitude_value[149];
  EXPECT_EQ(last_msg_->amplitude_value[150], 143)
      << "incorrect value for amplitude_value[150], expected 143, is "
      << last_msg_->amplitude_value[150];
  EXPECT_EQ(last_msg_->amplitude_value[151], 174)
      << "incorrect value for amplitude_value[151], expected 174, is "
      << last_msg_->amplitude_value[151];
  EXPECT_EQ(last_msg_->amplitude_value[152], 165)
      << "incorrect value for amplitude_value[152], expected 165, is "
      << last_msg_->amplitude_value[152];
  EXPECT_EQ(last_msg_->amplitude_value[153], 211)
      << "incorrect value for amplitude_value[153], expected 211, is "
      << last_msg_->amplitude_value[153];
  EXPECT_EQ(last_msg_->amplitude_value[154], 241)
      << "incorrect value for amplitude_value[154], expected 241, is "
      << last_msg_->amplitude_value[154];
  EXPECT_EQ(last_msg_->amplitude_value[155], 13)
      << "incorrect value for amplitude_value[155], expected 13, is "
      << last_msg_->amplitude_value[155];
  EXPECT_EQ(last_msg_->amplitude_value[156], 16)
      << "incorrect value for amplitude_value[156], expected 16, is "
      << last_msg_->amplitude_value[156];
  EXPECT_EQ(last_msg_->amplitude_value[157], 61)
      << "incorrect value for amplitude_value[157], expected 61, is "
      << last_msg_->amplitude_value[157];
  EXPECT_EQ(last_msg_->amplitude_value[158], 141)
      << "incorrect value for amplitude_value[158], expected 141, is "
      << last_msg_->amplitude_value[158];
  EXPECT_EQ(last_msg_->amplitude_value[159], 101)
      << "incorrect value for amplitude_value[159], expected 101, is "
      << last_msg_->amplitude_value[159];
  EXPECT_EQ(last_msg_->amplitude_value[160], 89)
      << "incorrect value for amplitude_value[160], expected 89, is "
      << last_msg_->amplitude_value[160];
  EXPECT_EQ(last_msg_->amplitude_value[161], 37)
      << "incorrect value for amplitude_value[161], expected 37, is "
      << last_msg_->amplitude_value[161];
  EXPECT_EQ(last_msg_->amplitude_value[162], 117)
      << "incorrect value for amplitude_value[162], expected 117, is "
      << last_msg_->amplitude_value[162];
  EXPECT_EQ(last_msg_->amplitude_value[163], 189)
      << "incorrect value for amplitude_value[163], expected 189, is "
      << last_msg_->amplitude_value[163];
  EXPECT_EQ(last_msg_->amplitude_value[164], 86)
      << "incorrect value for amplitude_value[164], expected 86, is "
      << last_msg_->amplitude_value[164];
  EXPECT_EQ(last_msg_->amplitude_value[165], 118)
      << "incorrect value for amplitude_value[165], expected 118, is "
      << last_msg_->amplitude_value[165];
  EXPECT_EQ(last_msg_->amplitude_value[166], 176)
      << "incorrect value for amplitude_value[166], expected 176, is "
      << last_msg_->amplitude_value[166];
  EXPECT_EQ(last_msg_->amplitude_value[167], 228)
      << "incorrect value for amplitude_value[167], expected 228, is "
      << last_msg_->amplitude_value[167];
  EXPECT_EQ(last_msg_->amplitude_value[168], 12)
      << "incorrect value for amplitude_value[168], expected 12, is "
      << last_msg_->amplitude_value[168];
  EXPECT_EQ(last_msg_->amplitude_value[169], 14)
      << "incorrect value for amplitude_value[169], expected 14, is "
      << last_msg_->amplitude_value[169];
  EXPECT_EQ(last_msg_->amplitude_value[170], 119)
      << "incorrect value for amplitude_value[170], expected 119, is "
      << last_msg_->amplitude_value[170];
  EXPECT_EQ(last_msg_->amplitude_value[171], 135)
      << "incorrect value for amplitude_value[171], expected 135, is "
      << last_msg_->amplitude_value[171];
  EXPECT_EQ(last_msg_->amplitude_value[172], 129)
      << "incorrect value for amplitude_value[172], expected 129, is "
      << last_msg_->amplitude_value[172];
  EXPECT_EQ(last_msg_->amplitude_value[173], 243)
      << "incorrect value for amplitude_value[173], expected 243, is "
      << last_msg_->amplitude_value[173];
  EXPECT_EQ(last_msg_->amplitude_value[174], 50)
      << "incorrect value for amplitude_value[174], expected 50, is "
      << last_msg_->amplitude_value[174];
  EXPECT_EQ(last_msg_->amplitude_value[175], 29)
      << "incorrect value for amplitude_value[175], expected 29, is "
      << last_msg_->amplitude_value[175];
  EXPECT_EQ(last_msg_->amplitude_value[176], 207)
      << "incorrect value for amplitude_value[176], expected 207, is "
      << last_msg_->amplitude_value[176];
  EXPECT_EQ(last_msg_->amplitude_value[177], 198)
      << "incorrect value for amplitude_value[177], expected 198, is "
      << last_msg_->amplitude_value[177];
  EXPECT_EQ(last_msg_->amplitude_value[178], 117)
      << "incorrect value for amplitude_value[178], expected 117, is "
      << last_msg_->amplitude_value[178];
  EXPECT_EQ(last_msg_->amplitude_value[179], 100)
      << "incorrect value for amplitude_value[179], expected 100, is "
      << last_msg_->amplitude_value[179];
  EXPECT_EQ(last_msg_->amplitude_value[180], 225)
      << "incorrect value for amplitude_value[180], expected 225, is "
      << last_msg_->amplitude_value[180];
  EXPECT_EQ(last_msg_->amplitude_value[181], 6)
      << "incorrect value for amplitude_value[181], expected 6, is "
      << last_msg_->amplitude_value[181];
  EXPECT_EQ(last_msg_->amplitude_value[182], 139)
      << "incorrect value for amplitude_value[182], expected 139, is "
      << last_msg_->amplitude_value[182];
  EXPECT_EQ(last_msg_->amplitude_value[183], 110)
      << "incorrect value for amplitude_value[183], expected 110, is "
      << last_msg_->amplitude_value[183];
  EXPECT_EQ(last_msg_->amplitude_value[184], 39)
      << "incorrect value for amplitude_value[184], expected 39, is "
      << last_msg_->amplitude_value[184];
  EXPECT_EQ(last_msg_->amplitude_value[185], 210)
      << "incorrect value for amplitude_value[185], expected 210, is "
      << last_msg_->amplitude_value[185];
  EXPECT_EQ(last_msg_->amplitude_value[186], 68)
      << "incorrect value for amplitude_value[186], expected 68, is "
      << last_msg_->amplitude_value[186];
  EXPECT_EQ(last_msg_->amplitude_value[187], 199)
      << "incorrect value for amplitude_value[187], expected 199, is "
      << last_msg_->amplitude_value[187];
  EXPECT_EQ(last_msg_->amplitude_value[188], 43)
      << "incorrect value for amplitude_value[188], expected 43, is "
      << last_msg_->amplitude_value[188];
  EXPECT_EQ(last_msg_->amplitude_value[189], 132)
      << "incorrect value for amplitude_value[189], expected 132, is "
      << last_msg_->amplitude_value[189];
  EXPECT_EQ(last_msg_->amplitude_value[190], 64)
      << "incorrect value for amplitude_value[190], expected 64, is "
      << last_msg_->amplitude_value[190];
  EXPECT_EQ(last_msg_->amplitude_value[191], 17)
      << "incorrect value for amplitude_value[191], expected 17, is "
      << last_msg_->amplitude_value[191];
  EXPECT_EQ(last_msg_->amplitude_value[192], 51)
      << "incorrect value for amplitude_value[192], expected 51, is "
      << last_msg_->amplitude_value[192];
  EXPECT_EQ(last_msg_->amplitude_value[193], 173)
      << "incorrect value for amplitude_value[193], expected 173, is "
      << last_msg_->amplitude_value[193];
  EXPECT_EQ(last_msg_->amplitude_value[194], 181)
      << "incorrect value for amplitude_value[194], expected 181, is "
      << last_msg_->amplitude_value[194];
  EXPECT_EQ(last_msg_->amplitude_value[195], 12)
      << "incorrect value for amplitude_value[195], expected 12, is "
      << last_msg_->amplitude_value[195];
  EXPECT_EQ(last_msg_->amplitude_value[196], 140)
      << "incorrect value for amplitude_value[196], expected 140, is "
      << last_msg_->amplitude_value[196];
  EXPECT_EQ(last_msg_->amplitude_value[197], 16)
      << "incorrect value for amplitude_value[197], expected 16, is "
      << last_msg_->amplitude_value[197];
  EXPECT_EQ(last_msg_->amplitude_value[198], 247)
      << "incorrect value for amplitude_value[198], expected 247, is "
      << last_msg_->amplitude_value[198];
  EXPECT_EQ(last_msg_->amplitude_value[199], 84)
      << "incorrect value for amplitude_value[199], expected 84, is "
      << last_msg_->amplitude_value[199];
  EXPECT_EQ(last_msg_->amplitude_value[200], 183)
      << "incorrect value for amplitude_value[200], expected 183, is "
      << last_msg_->amplitude_value[200];
  EXPECT_EQ(last_msg_->amplitude_value[201], 105)
      << "incorrect value for amplitude_value[201], expected 105, is "
      << last_msg_->amplitude_value[201];
  EXPECT_EQ(last_msg_->amplitude_value[202], 39)
      << "incorrect value for amplitude_value[202], expected 39, is "
      << last_msg_->amplitude_value[202];
  EXPECT_EQ(last_msg_->amplitude_value[203], 157)
      << "incorrect value for amplitude_value[203], expected 157, is "
      << last_msg_->amplitude_value[203];
  EXPECT_EQ(last_msg_->amplitude_value[204], 77)
      << "incorrect value for amplitude_value[204], expected 77, is "
      << last_msg_->amplitude_value[204];
  EXPECT_EQ(last_msg_->amplitude_value[205], 30)
      << "incorrect value for amplitude_value[205], expected 30, is "
      << last_msg_->amplitude_value[205];
  EXPECT_EQ(last_msg_->amplitude_value[206], 205)
      << "incorrect value for amplitude_value[206], expected 205, is "
      << last_msg_->amplitude_value[206];
  EXPECT_EQ(last_msg_->amplitude_value[207], 194)
      << "incorrect value for amplitude_value[207], expected 194, is "
      << last_msg_->amplitude_value[207];
  EXPECT_EQ(last_msg_->amplitude_value[208], 59)
      << "incorrect value for amplitude_value[208], expected 59, is "
      << last_msg_->amplitude_value[208];
  EXPECT_EQ(last_msg_->amplitude_value[209], 64)
      << "incorrect value for amplitude_value[209], expected 64, is "
      << last_msg_->amplitude_value[209];
  EXPECT_EQ(last_msg_->amplitude_value[210], 241)
      << "incorrect value for amplitude_value[210], expected 241, is "
      << last_msg_->amplitude_value[210];
  EXPECT_EQ(last_msg_->amplitude_value[211], 183)
      << "incorrect value for amplitude_value[211], expected 183, is "
      << last_msg_->amplitude_value[211];
  EXPECT_EQ(last_msg_->amplitude_value[212], 238)
      << "incorrect value for amplitude_value[212], expected 238, is "
      << last_msg_->amplitude_value[212];
  EXPECT_EQ(last_msg_->amplitude_value[213], 105)
      << "incorrect value for amplitude_value[213], expected 105, is "
      << last_msg_->amplitude_value[213];
  EXPECT_EQ(last_msg_->amplitude_value[214], 181)
      << "incorrect value for amplitude_value[214], expected 181, is "
      << last_msg_->amplitude_value[214];
  EXPECT_EQ(last_msg_->amplitude_value[215], 170)
      << "incorrect value for amplitude_value[215], expected 170, is "
      << last_msg_->amplitude_value[215];
  EXPECT_EQ(last_msg_->amplitude_value[216], 45)
      << "incorrect value for amplitude_value[216], expected 45, is "
      << last_msg_->amplitude_value[216];
  EXPECT_EQ(last_msg_->amplitude_value[217], 8)
      << "incorrect value for amplitude_value[217], expected 8, is "
      << last_msg_->amplitude_value[217];
  EXPECT_EQ(last_msg_->amplitude_value[218], 166)
      << "incorrect value for amplitude_value[218], expected 166, is "
      << last_msg_->amplitude_value[218];
  EXPECT_EQ(last_msg_->amplitude_value[219], 164)
      << "incorrect value for amplitude_value[219], expected 164, is "
      << last_msg_->amplitude_value[219];
  EXPECT_EQ(last_msg_->amplitude_value[220], 238)
      << "incorrect value for amplitude_value[220], expected 238, is "
      << last_msg_->amplitude_value[220];
  EXPECT_EQ(last_msg_->amplitude_value[221], 83)
      << "incorrect value for amplitude_value[221], expected 83, is "
      << last_msg_->amplitude_value[221];
  EXPECT_EQ(last_msg_->amplitude_value[222], 148)
      << "incorrect value for amplitude_value[222], expected 148, is "
      << last_msg_->amplitude_value[222];
  EXPECT_EQ(last_msg_->amplitude_value[223], 173)
      << "incorrect value for amplitude_value[223], expected 173, is "
      << last_msg_->amplitude_value[223];
  EXPECT_EQ(last_msg_->amplitude_value[224], 108)
      << "incorrect value for amplitude_value[224], expected 108, is "
      << last_msg_->amplitude_value[224];
  EXPECT_EQ(last_msg_->amplitude_value[225], 228)
      << "incorrect value for amplitude_value[225], expected 228, is "
      << last_msg_->amplitude_value[225];
  EXPECT_EQ(last_msg_->amplitude_value[226], 67)
      << "incorrect value for amplitude_value[226], expected 67, is "
      << last_msg_->amplitude_value[226];
  EXPECT_EQ(last_msg_->amplitude_value[227], 89)
      << "incorrect value for amplitude_value[227], expected 89, is "
      << last_msg_->amplitude_value[227];
  EXPECT_EQ(last_msg_->amplitude_value[228], 189)
      << "incorrect value for amplitude_value[228], expected 189, is "
      << last_msg_->amplitude_value[228];
  EXPECT_EQ(last_msg_->amplitude_value[229], 67)
      << "incorrect value for amplitude_value[229], expected 67, is "
      << last_msg_->amplitude_value[229];
  EXPECT_EQ(last_msg_->amplitude_value[230], 26)
      << "incorrect value for amplitude_value[230], expected 26, is "
      << last_msg_->amplitude_value[230];
  EXPECT_EQ(last_msg_->channel_tag, 5878)
      << "incorrect value for channel_tag, expected 5878, is "
      << last_msg_->channel_tag;
  EXPECT_LT((last_msg_->freq_ref * 100 - 6348.20019531 * 100), 0.05)
      << "incorrect value for freq_ref, expected 6348.20019531, is "
      << last_msg_->freq_ref;
  EXPECT_LT((last_msg_->freq_step * 100 - 4608.20019531 * 100), 0.05)
      << "incorrect value for freq_step, expected 4608.20019531, is "
      << last_msg_->freq_step;
  EXPECT_EQ(last_msg_->t.tow, 992295133)
      << "incorrect value for t.tow, expected 992295133, is "
      << last_msg_->t.tow;
  EXPECT_EQ(last_msg_->t.wn, 6957)
      << "incorrect value for t.wn, expected 6957, is " << last_msg_->t.wn;
}
