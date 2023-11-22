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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgSpecan.yaml by generate.py. Do not
// modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_piksi_MsgSpecan0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_specan_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgSpecan0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_specan_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_specan_t *>(last_msg_storage_)),
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
                      const msg_specan_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_specan_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgSpecan0, Test) {
  uint8_t encoded_frame[] = {
      85,  81,  0,   28,  212, 255, 74,  137, 71,  245, 34,  73,  12,  221, 215,
      167, 211, 19,  154, 201, 241, 69,  205, 136, 0,   70,  51,  67,  108, 69,
      102, 38,  166, 68,  100, 179, 185, 17,  175, 49,  193, 228, 228, 47,  33,
      24,  141, 177, 18,  99,  246, 121, 61,  40,  91,  145, 223, 167, 174, 9,
      116, 11,  247, 84,  49,  153, 205, 2,   230, 194, 218, 241, 101, 107, 45,
      137, 93,  114, 230, 43,  224, 23,  74,  209, 199, 211, 130, 89,  220, 163,
      68,  20,  253, 7,   206, 50,  129, 116, 194, 23,  31,  226, 217, 157, 205,
      221, 5,   224, 92,  82,  109, 223, 195, 233, 165, 1,   82,  141, 157, 177,
      169, 244, 131, 96,  109, 111, 253, 149, 28,  225, 225, 72,  158, 158, 210,
      196, 206, 70,  63,  225, 184, 150, 174, 240, 45,  146, 59,  82,  194, 4,
      179, 148, 66,  254, 115, 77,  30,  46,  4,   204, 37,  200, 121, 18,  17,
      171, 102, 163, 175, 50,  66,  101, 69,  13,  223, 172, 160, 233, 220, 101,
      237, 156, 62,  117, 47,  143, 94,  135, 22,  155, 113, 110, 15,  243, 141,
      227, 46,  143, 227, 209, 249, 2,   153, 168, 131, 249, 160, 88,  38,  117,
      129, 57,  40,  109, 209, 177, 38,  47,  12,  15,  16,  9,   175, 69,  70,
      182, 239, 117, 135, 6,   71,  99,  230, 115, 2,   71,  165, 228, 123, 210,
      168, 90,  124, 20,  7,   220, 144, 168, 69,  22,  72,  162, 69,  111, 91,
      251, 72,  220, 28,  119, 150, 95,  2,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_specan_t *test_msg = (msg_specan_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->amplitude_ref = 3780.199951171875;
  test_msg->amplitude_unit = 1329.199951171875;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[0] = 100;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[1] = 179;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[2] = 185;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[3] = 17;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[4] = 175;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[5] = 49;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[6] = 193;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[7] = 228;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[8] = 228;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[9] = 47;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[10] = 33;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[11] = 24;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[12] = 141;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[13] = 177;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[14] = 18;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[15] = 99;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[16] = 246;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[17] = 121;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[18] = 61;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[19] = 40;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[20] = 91;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[21] = 145;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[22] = 223;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[23] = 167;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[24] = 174;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[25] = 9;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[26] = 116;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[27] = 11;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[28] = 247;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[29] = 84;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[30] = 49;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[31] = 153;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[32] = 205;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[33] = 2;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[34] = 230;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[35] = 194;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[36] = 218;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[37] = 241;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[38] = 101;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[39] = 107;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[40] = 45;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[41] = 137;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[42] = 93;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[43] = 114;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[44] = 230;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[45] = 43;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[46] = 224;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[47] = 23;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[48] = 74;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[49] = 209;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[50] = 199;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[51] = 211;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[52] = 130;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[53] = 89;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[54] = 220;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[55] = 163;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[56] = 68;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[57] = 20;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[58] = 253;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[59] = 7;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[60] = 206;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[61] = 50;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[62] = 129;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[63] = 116;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[64] = 194;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[65] = 23;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[66] = 31;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[67] = 226;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[68] = 217;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[69] = 157;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[70] = 205;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[71] = 221;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[72] = 5;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[73] = 224;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[74] = 92;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[75] = 82;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[76] = 109;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[77] = 223;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[78] = 195;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[79] = 233;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[80] = 165;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[81] = 1;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[82] = 82;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[83] = 141;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[84] = 157;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[85] = 177;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[86] = 169;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[87] = 244;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[88] = 131;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[89] = 96;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[90] = 109;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[91] = 111;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[92] = 253;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[93] = 149;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[94] = 28;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[95] = 225;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[96] = 225;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[97] = 72;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[98] = 158;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[99] = 158;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[100] = 210;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[101] = 196;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[102] = 206;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[103] = 70;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[104] = 63;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[105] = 225;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[106] = 184;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[107] = 150;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[108] = 174;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[109] = 240;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[110] = 45;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[111] = 146;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[112] = 59;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[113] = 82;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[114] = 194;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[115] = 4;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[116] = 179;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[117] = 148;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[118] = 66;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[119] = 254;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[120] = 115;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[121] = 77;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[122] = 30;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[123] = 46;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[124] = 4;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[125] = 204;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[126] = 37;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[127] = 200;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[128] = 121;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[129] = 18;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[130] = 17;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[131] = 171;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[132] = 102;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[133] = 163;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[134] = 175;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[135] = 50;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[136] = 66;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[137] = 101;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[138] = 69;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[139] = 13;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[140] = 223;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[141] = 172;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[142] = 160;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[143] = 233;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[144] = 220;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[145] = 101;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[146] = 237;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[147] = 156;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[148] = 62;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[149] = 117;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[150] = 47;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[151] = 143;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[152] = 94;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[153] = 135;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[154] = 22;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[155] = 155;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[156] = 113;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[157] = 110;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[158] = 15;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[159] = 243;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[160] = 141;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[161] = 227;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[162] = 46;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[163] = 143;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[164] = 227;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[165] = 209;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[166] = 249;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[167] = 2;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[168] = 153;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[169] = 168;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[170] = 131;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[171] = 249;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[172] = 160;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[173] = 88;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[174] = 38;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[175] = 117;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[176] = 129;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[177] = 57;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[178] = 40;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[179] = 109;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[180] = 209;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[181] = 177;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[182] = 38;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[183] = 47;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[184] = 12;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[185] = 15;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[186] = 16;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[187] = 9;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[188] = 175;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[189] = 69;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[190] = 70;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[191] = 182;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[192] = 239;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[193] = 117;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[194] = 135;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[195] = 6;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[196] = 71;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[197] = 99;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[198] = 230;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[199] = 115;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[200] = 2;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[201] = 71;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[202] = 165;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[203] = 228;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[204] = 123;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[205] = 210;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[206] = 168;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[207] = 90;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[208] = 124;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[209] = 20;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[210] = 7;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[211] = 220;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[212] = 144;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[213] = 168;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[214] = 69;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[215] = 22;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[216] = 72;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[217] = 162;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[218] = 69;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[219] = 111;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[220] = 91;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[221] = 251;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[222] = 72;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[223] = 220;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[224] = 28;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[225] = 119;
  if (sizeof(test_msg->amplitude_value) == 0) {
    // Cope with variable length arrays
    test_msg_len =
        (uint8_t)(test_msg_len + sizeof(test_msg->amplitude_value[0]));
  }
  test_msg->amplitude_value[226] = 150;
  test_msg->channel_tag = 35146;
  test_msg->freq_ref = 7737.2001953125;
  test_msg->freq_step = 8226.2001953125;
  test_msg->t.ns_residual = -1479025396;
  test_msg->t.tow = 1227027783;
  test_msg->t.wn = 5075;

  EXPECT_EQ(send_message(0x51, 54300, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 54300);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->amplitude_ref * 100 - 3780.19995117 * 100), 0.05)
      << "incorrect value for amplitude_ref, expected 3780.19995117, is "
      << last_msg_->amplitude_ref;
  EXPECT_LT((last_msg_->amplitude_unit * 100 - 1329.19995117 * 100), 0.05)
      << "incorrect value for amplitude_unit, expected 1329.19995117, is "
      << last_msg_->amplitude_unit;
  EXPECT_EQ(last_msg_->amplitude_value[0], 100)
      << "incorrect value for amplitude_value[0], expected 100, is "
      << last_msg_->amplitude_value[0];
  EXPECT_EQ(last_msg_->amplitude_value[1], 179)
      << "incorrect value for amplitude_value[1], expected 179, is "
      << last_msg_->amplitude_value[1];
  EXPECT_EQ(last_msg_->amplitude_value[2], 185)
      << "incorrect value for amplitude_value[2], expected 185, is "
      << last_msg_->amplitude_value[2];
  EXPECT_EQ(last_msg_->amplitude_value[3], 17)
      << "incorrect value for amplitude_value[3], expected 17, is "
      << last_msg_->amplitude_value[3];
  EXPECT_EQ(last_msg_->amplitude_value[4], 175)
      << "incorrect value for amplitude_value[4], expected 175, is "
      << last_msg_->amplitude_value[4];
  EXPECT_EQ(last_msg_->amplitude_value[5], 49)
      << "incorrect value for amplitude_value[5], expected 49, is "
      << last_msg_->amplitude_value[5];
  EXPECT_EQ(last_msg_->amplitude_value[6], 193)
      << "incorrect value for amplitude_value[6], expected 193, is "
      << last_msg_->amplitude_value[6];
  EXPECT_EQ(last_msg_->amplitude_value[7], 228)
      << "incorrect value for amplitude_value[7], expected 228, is "
      << last_msg_->amplitude_value[7];
  EXPECT_EQ(last_msg_->amplitude_value[8], 228)
      << "incorrect value for amplitude_value[8], expected 228, is "
      << last_msg_->amplitude_value[8];
  EXPECT_EQ(last_msg_->amplitude_value[9], 47)
      << "incorrect value for amplitude_value[9], expected 47, is "
      << last_msg_->amplitude_value[9];
  EXPECT_EQ(last_msg_->amplitude_value[10], 33)
      << "incorrect value for amplitude_value[10], expected 33, is "
      << last_msg_->amplitude_value[10];
  EXPECT_EQ(last_msg_->amplitude_value[11], 24)
      << "incorrect value for amplitude_value[11], expected 24, is "
      << last_msg_->amplitude_value[11];
  EXPECT_EQ(last_msg_->amplitude_value[12], 141)
      << "incorrect value for amplitude_value[12], expected 141, is "
      << last_msg_->amplitude_value[12];
  EXPECT_EQ(last_msg_->amplitude_value[13], 177)
      << "incorrect value for amplitude_value[13], expected 177, is "
      << last_msg_->amplitude_value[13];
  EXPECT_EQ(last_msg_->amplitude_value[14], 18)
      << "incorrect value for amplitude_value[14], expected 18, is "
      << last_msg_->amplitude_value[14];
  EXPECT_EQ(last_msg_->amplitude_value[15], 99)
      << "incorrect value for amplitude_value[15], expected 99, is "
      << last_msg_->amplitude_value[15];
  EXPECT_EQ(last_msg_->amplitude_value[16], 246)
      << "incorrect value for amplitude_value[16], expected 246, is "
      << last_msg_->amplitude_value[16];
  EXPECT_EQ(last_msg_->amplitude_value[17], 121)
      << "incorrect value for amplitude_value[17], expected 121, is "
      << last_msg_->amplitude_value[17];
  EXPECT_EQ(last_msg_->amplitude_value[18], 61)
      << "incorrect value for amplitude_value[18], expected 61, is "
      << last_msg_->amplitude_value[18];
  EXPECT_EQ(last_msg_->amplitude_value[19], 40)
      << "incorrect value for amplitude_value[19], expected 40, is "
      << last_msg_->amplitude_value[19];
  EXPECT_EQ(last_msg_->amplitude_value[20], 91)
      << "incorrect value for amplitude_value[20], expected 91, is "
      << last_msg_->amplitude_value[20];
  EXPECT_EQ(last_msg_->amplitude_value[21], 145)
      << "incorrect value for amplitude_value[21], expected 145, is "
      << last_msg_->amplitude_value[21];
  EXPECT_EQ(last_msg_->amplitude_value[22], 223)
      << "incorrect value for amplitude_value[22], expected 223, is "
      << last_msg_->amplitude_value[22];
  EXPECT_EQ(last_msg_->amplitude_value[23], 167)
      << "incorrect value for amplitude_value[23], expected 167, is "
      << last_msg_->amplitude_value[23];
  EXPECT_EQ(last_msg_->amplitude_value[24], 174)
      << "incorrect value for amplitude_value[24], expected 174, is "
      << last_msg_->amplitude_value[24];
  EXPECT_EQ(last_msg_->amplitude_value[25], 9)
      << "incorrect value for amplitude_value[25], expected 9, is "
      << last_msg_->amplitude_value[25];
  EXPECT_EQ(last_msg_->amplitude_value[26], 116)
      << "incorrect value for amplitude_value[26], expected 116, is "
      << last_msg_->amplitude_value[26];
  EXPECT_EQ(last_msg_->amplitude_value[27], 11)
      << "incorrect value for amplitude_value[27], expected 11, is "
      << last_msg_->amplitude_value[27];
  EXPECT_EQ(last_msg_->amplitude_value[28], 247)
      << "incorrect value for amplitude_value[28], expected 247, is "
      << last_msg_->amplitude_value[28];
  EXPECT_EQ(last_msg_->amplitude_value[29], 84)
      << "incorrect value for amplitude_value[29], expected 84, is "
      << last_msg_->amplitude_value[29];
  EXPECT_EQ(last_msg_->amplitude_value[30], 49)
      << "incorrect value for amplitude_value[30], expected 49, is "
      << last_msg_->amplitude_value[30];
  EXPECT_EQ(last_msg_->amplitude_value[31], 153)
      << "incorrect value for amplitude_value[31], expected 153, is "
      << last_msg_->amplitude_value[31];
  EXPECT_EQ(last_msg_->amplitude_value[32], 205)
      << "incorrect value for amplitude_value[32], expected 205, is "
      << last_msg_->amplitude_value[32];
  EXPECT_EQ(last_msg_->amplitude_value[33], 2)
      << "incorrect value for amplitude_value[33], expected 2, is "
      << last_msg_->amplitude_value[33];
  EXPECT_EQ(last_msg_->amplitude_value[34], 230)
      << "incorrect value for amplitude_value[34], expected 230, is "
      << last_msg_->amplitude_value[34];
  EXPECT_EQ(last_msg_->amplitude_value[35], 194)
      << "incorrect value for amplitude_value[35], expected 194, is "
      << last_msg_->amplitude_value[35];
  EXPECT_EQ(last_msg_->amplitude_value[36], 218)
      << "incorrect value for amplitude_value[36], expected 218, is "
      << last_msg_->amplitude_value[36];
  EXPECT_EQ(last_msg_->amplitude_value[37], 241)
      << "incorrect value for amplitude_value[37], expected 241, is "
      << last_msg_->amplitude_value[37];
  EXPECT_EQ(last_msg_->amplitude_value[38], 101)
      << "incorrect value for amplitude_value[38], expected 101, is "
      << last_msg_->amplitude_value[38];
  EXPECT_EQ(last_msg_->amplitude_value[39], 107)
      << "incorrect value for amplitude_value[39], expected 107, is "
      << last_msg_->amplitude_value[39];
  EXPECT_EQ(last_msg_->amplitude_value[40], 45)
      << "incorrect value for amplitude_value[40], expected 45, is "
      << last_msg_->amplitude_value[40];
  EXPECT_EQ(last_msg_->amplitude_value[41], 137)
      << "incorrect value for amplitude_value[41], expected 137, is "
      << last_msg_->amplitude_value[41];
  EXPECT_EQ(last_msg_->amplitude_value[42], 93)
      << "incorrect value for amplitude_value[42], expected 93, is "
      << last_msg_->amplitude_value[42];
  EXPECT_EQ(last_msg_->amplitude_value[43], 114)
      << "incorrect value for amplitude_value[43], expected 114, is "
      << last_msg_->amplitude_value[43];
  EXPECT_EQ(last_msg_->amplitude_value[44], 230)
      << "incorrect value for amplitude_value[44], expected 230, is "
      << last_msg_->amplitude_value[44];
  EXPECT_EQ(last_msg_->amplitude_value[45], 43)
      << "incorrect value for amplitude_value[45], expected 43, is "
      << last_msg_->amplitude_value[45];
  EXPECT_EQ(last_msg_->amplitude_value[46], 224)
      << "incorrect value for amplitude_value[46], expected 224, is "
      << last_msg_->amplitude_value[46];
  EXPECT_EQ(last_msg_->amplitude_value[47], 23)
      << "incorrect value for amplitude_value[47], expected 23, is "
      << last_msg_->amplitude_value[47];
  EXPECT_EQ(last_msg_->amplitude_value[48], 74)
      << "incorrect value for amplitude_value[48], expected 74, is "
      << last_msg_->amplitude_value[48];
  EXPECT_EQ(last_msg_->amplitude_value[49], 209)
      << "incorrect value for amplitude_value[49], expected 209, is "
      << last_msg_->amplitude_value[49];
  EXPECT_EQ(last_msg_->amplitude_value[50], 199)
      << "incorrect value for amplitude_value[50], expected 199, is "
      << last_msg_->amplitude_value[50];
  EXPECT_EQ(last_msg_->amplitude_value[51], 211)
      << "incorrect value for amplitude_value[51], expected 211, is "
      << last_msg_->amplitude_value[51];
  EXPECT_EQ(last_msg_->amplitude_value[52], 130)
      << "incorrect value for amplitude_value[52], expected 130, is "
      << last_msg_->amplitude_value[52];
  EXPECT_EQ(last_msg_->amplitude_value[53], 89)
      << "incorrect value for amplitude_value[53], expected 89, is "
      << last_msg_->amplitude_value[53];
  EXPECT_EQ(last_msg_->amplitude_value[54], 220)
      << "incorrect value for amplitude_value[54], expected 220, is "
      << last_msg_->amplitude_value[54];
  EXPECT_EQ(last_msg_->amplitude_value[55], 163)
      << "incorrect value for amplitude_value[55], expected 163, is "
      << last_msg_->amplitude_value[55];
  EXPECT_EQ(last_msg_->amplitude_value[56], 68)
      << "incorrect value for amplitude_value[56], expected 68, is "
      << last_msg_->amplitude_value[56];
  EXPECT_EQ(last_msg_->amplitude_value[57], 20)
      << "incorrect value for amplitude_value[57], expected 20, is "
      << last_msg_->amplitude_value[57];
  EXPECT_EQ(last_msg_->amplitude_value[58], 253)
      << "incorrect value for amplitude_value[58], expected 253, is "
      << last_msg_->amplitude_value[58];
  EXPECT_EQ(last_msg_->amplitude_value[59], 7)
      << "incorrect value for amplitude_value[59], expected 7, is "
      << last_msg_->amplitude_value[59];
  EXPECT_EQ(last_msg_->amplitude_value[60], 206)
      << "incorrect value for amplitude_value[60], expected 206, is "
      << last_msg_->amplitude_value[60];
  EXPECT_EQ(last_msg_->amplitude_value[61], 50)
      << "incorrect value for amplitude_value[61], expected 50, is "
      << last_msg_->amplitude_value[61];
  EXPECT_EQ(last_msg_->amplitude_value[62], 129)
      << "incorrect value for amplitude_value[62], expected 129, is "
      << last_msg_->amplitude_value[62];
  EXPECT_EQ(last_msg_->amplitude_value[63], 116)
      << "incorrect value for amplitude_value[63], expected 116, is "
      << last_msg_->amplitude_value[63];
  EXPECT_EQ(last_msg_->amplitude_value[64], 194)
      << "incorrect value for amplitude_value[64], expected 194, is "
      << last_msg_->amplitude_value[64];
  EXPECT_EQ(last_msg_->amplitude_value[65], 23)
      << "incorrect value for amplitude_value[65], expected 23, is "
      << last_msg_->amplitude_value[65];
  EXPECT_EQ(last_msg_->amplitude_value[66], 31)
      << "incorrect value for amplitude_value[66], expected 31, is "
      << last_msg_->amplitude_value[66];
  EXPECT_EQ(last_msg_->amplitude_value[67], 226)
      << "incorrect value for amplitude_value[67], expected 226, is "
      << last_msg_->amplitude_value[67];
  EXPECT_EQ(last_msg_->amplitude_value[68], 217)
      << "incorrect value for amplitude_value[68], expected 217, is "
      << last_msg_->amplitude_value[68];
  EXPECT_EQ(last_msg_->amplitude_value[69], 157)
      << "incorrect value for amplitude_value[69], expected 157, is "
      << last_msg_->amplitude_value[69];
  EXPECT_EQ(last_msg_->amplitude_value[70], 205)
      << "incorrect value for amplitude_value[70], expected 205, is "
      << last_msg_->amplitude_value[70];
  EXPECT_EQ(last_msg_->amplitude_value[71], 221)
      << "incorrect value for amplitude_value[71], expected 221, is "
      << last_msg_->amplitude_value[71];
  EXPECT_EQ(last_msg_->amplitude_value[72], 5)
      << "incorrect value for amplitude_value[72], expected 5, is "
      << last_msg_->amplitude_value[72];
  EXPECT_EQ(last_msg_->amplitude_value[73], 224)
      << "incorrect value for amplitude_value[73], expected 224, is "
      << last_msg_->amplitude_value[73];
  EXPECT_EQ(last_msg_->amplitude_value[74], 92)
      << "incorrect value for amplitude_value[74], expected 92, is "
      << last_msg_->amplitude_value[74];
  EXPECT_EQ(last_msg_->amplitude_value[75], 82)
      << "incorrect value for amplitude_value[75], expected 82, is "
      << last_msg_->amplitude_value[75];
  EXPECT_EQ(last_msg_->amplitude_value[76], 109)
      << "incorrect value for amplitude_value[76], expected 109, is "
      << last_msg_->amplitude_value[76];
  EXPECT_EQ(last_msg_->amplitude_value[77], 223)
      << "incorrect value for amplitude_value[77], expected 223, is "
      << last_msg_->amplitude_value[77];
  EXPECT_EQ(last_msg_->amplitude_value[78], 195)
      << "incorrect value for amplitude_value[78], expected 195, is "
      << last_msg_->amplitude_value[78];
  EXPECT_EQ(last_msg_->amplitude_value[79], 233)
      << "incorrect value for amplitude_value[79], expected 233, is "
      << last_msg_->amplitude_value[79];
  EXPECT_EQ(last_msg_->amplitude_value[80], 165)
      << "incorrect value for amplitude_value[80], expected 165, is "
      << last_msg_->amplitude_value[80];
  EXPECT_EQ(last_msg_->amplitude_value[81], 1)
      << "incorrect value for amplitude_value[81], expected 1, is "
      << last_msg_->amplitude_value[81];
  EXPECT_EQ(last_msg_->amplitude_value[82], 82)
      << "incorrect value for amplitude_value[82], expected 82, is "
      << last_msg_->amplitude_value[82];
  EXPECT_EQ(last_msg_->amplitude_value[83], 141)
      << "incorrect value for amplitude_value[83], expected 141, is "
      << last_msg_->amplitude_value[83];
  EXPECT_EQ(last_msg_->amplitude_value[84], 157)
      << "incorrect value for amplitude_value[84], expected 157, is "
      << last_msg_->amplitude_value[84];
  EXPECT_EQ(last_msg_->amplitude_value[85], 177)
      << "incorrect value for amplitude_value[85], expected 177, is "
      << last_msg_->amplitude_value[85];
  EXPECT_EQ(last_msg_->amplitude_value[86], 169)
      << "incorrect value for amplitude_value[86], expected 169, is "
      << last_msg_->amplitude_value[86];
  EXPECT_EQ(last_msg_->amplitude_value[87], 244)
      << "incorrect value for amplitude_value[87], expected 244, is "
      << last_msg_->amplitude_value[87];
  EXPECT_EQ(last_msg_->amplitude_value[88], 131)
      << "incorrect value for amplitude_value[88], expected 131, is "
      << last_msg_->amplitude_value[88];
  EXPECT_EQ(last_msg_->amplitude_value[89], 96)
      << "incorrect value for amplitude_value[89], expected 96, is "
      << last_msg_->amplitude_value[89];
  EXPECT_EQ(last_msg_->amplitude_value[90], 109)
      << "incorrect value for amplitude_value[90], expected 109, is "
      << last_msg_->amplitude_value[90];
  EXPECT_EQ(last_msg_->amplitude_value[91], 111)
      << "incorrect value for amplitude_value[91], expected 111, is "
      << last_msg_->amplitude_value[91];
  EXPECT_EQ(last_msg_->amplitude_value[92], 253)
      << "incorrect value for amplitude_value[92], expected 253, is "
      << last_msg_->amplitude_value[92];
  EXPECT_EQ(last_msg_->amplitude_value[93], 149)
      << "incorrect value for amplitude_value[93], expected 149, is "
      << last_msg_->amplitude_value[93];
  EXPECT_EQ(last_msg_->amplitude_value[94], 28)
      << "incorrect value for amplitude_value[94], expected 28, is "
      << last_msg_->amplitude_value[94];
  EXPECT_EQ(last_msg_->amplitude_value[95], 225)
      << "incorrect value for amplitude_value[95], expected 225, is "
      << last_msg_->amplitude_value[95];
  EXPECT_EQ(last_msg_->amplitude_value[96], 225)
      << "incorrect value for amplitude_value[96], expected 225, is "
      << last_msg_->amplitude_value[96];
  EXPECT_EQ(last_msg_->amplitude_value[97], 72)
      << "incorrect value for amplitude_value[97], expected 72, is "
      << last_msg_->amplitude_value[97];
  EXPECT_EQ(last_msg_->amplitude_value[98], 158)
      << "incorrect value for amplitude_value[98], expected 158, is "
      << last_msg_->amplitude_value[98];
  EXPECT_EQ(last_msg_->amplitude_value[99], 158)
      << "incorrect value for amplitude_value[99], expected 158, is "
      << last_msg_->amplitude_value[99];
  EXPECT_EQ(last_msg_->amplitude_value[100], 210)
      << "incorrect value for amplitude_value[100], expected 210, is "
      << last_msg_->amplitude_value[100];
  EXPECT_EQ(last_msg_->amplitude_value[101], 196)
      << "incorrect value for amplitude_value[101], expected 196, is "
      << last_msg_->amplitude_value[101];
  EXPECT_EQ(last_msg_->amplitude_value[102], 206)
      << "incorrect value for amplitude_value[102], expected 206, is "
      << last_msg_->amplitude_value[102];
  EXPECT_EQ(last_msg_->amplitude_value[103], 70)
      << "incorrect value for amplitude_value[103], expected 70, is "
      << last_msg_->amplitude_value[103];
  EXPECT_EQ(last_msg_->amplitude_value[104], 63)
      << "incorrect value for amplitude_value[104], expected 63, is "
      << last_msg_->amplitude_value[104];
  EXPECT_EQ(last_msg_->amplitude_value[105], 225)
      << "incorrect value for amplitude_value[105], expected 225, is "
      << last_msg_->amplitude_value[105];
  EXPECT_EQ(last_msg_->amplitude_value[106], 184)
      << "incorrect value for amplitude_value[106], expected 184, is "
      << last_msg_->amplitude_value[106];
  EXPECT_EQ(last_msg_->amplitude_value[107], 150)
      << "incorrect value for amplitude_value[107], expected 150, is "
      << last_msg_->amplitude_value[107];
  EXPECT_EQ(last_msg_->amplitude_value[108], 174)
      << "incorrect value for amplitude_value[108], expected 174, is "
      << last_msg_->amplitude_value[108];
  EXPECT_EQ(last_msg_->amplitude_value[109], 240)
      << "incorrect value for amplitude_value[109], expected 240, is "
      << last_msg_->amplitude_value[109];
  EXPECT_EQ(last_msg_->amplitude_value[110], 45)
      << "incorrect value for amplitude_value[110], expected 45, is "
      << last_msg_->amplitude_value[110];
  EXPECT_EQ(last_msg_->amplitude_value[111], 146)
      << "incorrect value for amplitude_value[111], expected 146, is "
      << last_msg_->amplitude_value[111];
  EXPECT_EQ(last_msg_->amplitude_value[112], 59)
      << "incorrect value for amplitude_value[112], expected 59, is "
      << last_msg_->amplitude_value[112];
  EXPECT_EQ(last_msg_->amplitude_value[113], 82)
      << "incorrect value for amplitude_value[113], expected 82, is "
      << last_msg_->amplitude_value[113];
  EXPECT_EQ(last_msg_->amplitude_value[114], 194)
      << "incorrect value for amplitude_value[114], expected 194, is "
      << last_msg_->amplitude_value[114];
  EXPECT_EQ(last_msg_->amplitude_value[115], 4)
      << "incorrect value for amplitude_value[115], expected 4, is "
      << last_msg_->amplitude_value[115];
  EXPECT_EQ(last_msg_->amplitude_value[116], 179)
      << "incorrect value for amplitude_value[116], expected 179, is "
      << last_msg_->amplitude_value[116];
  EXPECT_EQ(last_msg_->amplitude_value[117], 148)
      << "incorrect value for amplitude_value[117], expected 148, is "
      << last_msg_->amplitude_value[117];
  EXPECT_EQ(last_msg_->amplitude_value[118], 66)
      << "incorrect value for amplitude_value[118], expected 66, is "
      << last_msg_->amplitude_value[118];
  EXPECT_EQ(last_msg_->amplitude_value[119], 254)
      << "incorrect value for amplitude_value[119], expected 254, is "
      << last_msg_->amplitude_value[119];
  EXPECT_EQ(last_msg_->amplitude_value[120], 115)
      << "incorrect value for amplitude_value[120], expected 115, is "
      << last_msg_->amplitude_value[120];
  EXPECT_EQ(last_msg_->amplitude_value[121], 77)
      << "incorrect value for amplitude_value[121], expected 77, is "
      << last_msg_->amplitude_value[121];
  EXPECT_EQ(last_msg_->amplitude_value[122], 30)
      << "incorrect value for amplitude_value[122], expected 30, is "
      << last_msg_->amplitude_value[122];
  EXPECT_EQ(last_msg_->amplitude_value[123], 46)
      << "incorrect value for amplitude_value[123], expected 46, is "
      << last_msg_->amplitude_value[123];
  EXPECT_EQ(last_msg_->amplitude_value[124], 4)
      << "incorrect value for amplitude_value[124], expected 4, is "
      << last_msg_->amplitude_value[124];
  EXPECT_EQ(last_msg_->amplitude_value[125], 204)
      << "incorrect value for amplitude_value[125], expected 204, is "
      << last_msg_->amplitude_value[125];
  EXPECT_EQ(last_msg_->amplitude_value[126], 37)
      << "incorrect value for amplitude_value[126], expected 37, is "
      << last_msg_->amplitude_value[126];
  EXPECT_EQ(last_msg_->amplitude_value[127], 200)
      << "incorrect value for amplitude_value[127], expected 200, is "
      << last_msg_->amplitude_value[127];
  EXPECT_EQ(last_msg_->amplitude_value[128], 121)
      << "incorrect value for amplitude_value[128], expected 121, is "
      << last_msg_->amplitude_value[128];
  EXPECT_EQ(last_msg_->amplitude_value[129], 18)
      << "incorrect value for amplitude_value[129], expected 18, is "
      << last_msg_->amplitude_value[129];
  EXPECT_EQ(last_msg_->amplitude_value[130], 17)
      << "incorrect value for amplitude_value[130], expected 17, is "
      << last_msg_->amplitude_value[130];
  EXPECT_EQ(last_msg_->amplitude_value[131], 171)
      << "incorrect value for amplitude_value[131], expected 171, is "
      << last_msg_->amplitude_value[131];
  EXPECT_EQ(last_msg_->amplitude_value[132], 102)
      << "incorrect value for amplitude_value[132], expected 102, is "
      << last_msg_->amplitude_value[132];
  EXPECT_EQ(last_msg_->amplitude_value[133], 163)
      << "incorrect value for amplitude_value[133], expected 163, is "
      << last_msg_->amplitude_value[133];
  EXPECT_EQ(last_msg_->amplitude_value[134], 175)
      << "incorrect value for amplitude_value[134], expected 175, is "
      << last_msg_->amplitude_value[134];
  EXPECT_EQ(last_msg_->amplitude_value[135], 50)
      << "incorrect value for amplitude_value[135], expected 50, is "
      << last_msg_->amplitude_value[135];
  EXPECT_EQ(last_msg_->amplitude_value[136], 66)
      << "incorrect value for amplitude_value[136], expected 66, is "
      << last_msg_->amplitude_value[136];
  EXPECT_EQ(last_msg_->amplitude_value[137], 101)
      << "incorrect value for amplitude_value[137], expected 101, is "
      << last_msg_->amplitude_value[137];
  EXPECT_EQ(last_msg_->amplitude_value[138], 69)
      << "incorrect value for amplitude_value[138], expected 69, is "
      << last_msg_->amplitude_value[138];
  EXPECT_EQ(last_msg_->amplitude_value[139], 13)
      << "incorrect value for amplitude_value[139], expected 13, is "
      << last_msg_->amplitude_value[139];
  EXPECT_EQ(last_msg_->amplitude_value[140], 223)
      << "incorrect value for amplitude_value[140], expected 223, is "
      << last_msg_->amplitude_value[140];
  EXPECT_EQ(last_msg_->amplitude_value[141], 172)
      << "incorrect value for amplitude_value[141], expected 172, is "
      << last_msg_->amplitude_value[141];
  EXPECT_EQ(last_msg_->amplitude_value[142], 160)
      << "incorrect value for amplitude_value[142], expected 160, is "
      << last_msg_->amplitude_value[142];
  EXPECT_EQ(last_msg_->amplitude_value[143], 233)
      << "incorrect value for amplitude_value[143], expected 233, is "
      << last_msg_->amplitude_value[143];
  EXPECT_EQ(last_msg_->amplitude_value[144], 220)
      << "incorrect value for amplitude_value[144], expected 220, is "
      << last_msg_->amplitude_value[144];
  EXPECT_EQ(last_msg_->amplitude_value[145], 101)
      << "incorrect value for amplitude_value[145], expected 101, is "
      << last_msg_->amplitude_value[145];
  EXPECT_EQ(last_msg_->amplitude_value[146], 237)
      << "incorrect value for amplitude_value[146], expected 237, is "
      << last_msg_->amplitude_value[146];
  EXPECT_EQ(last_msg_->amplitude_value[147], 156)
      << "incorrect value for amplitude_value[147], expected 156, is "
      << last_msg_->amplitude_value[147];
  EXPECT_EQ(last_msg_->amplitude_value[148], 62)
      << "incorrect value for amplitude_value[148], expected 62, is "
      << last_msg_->amplitude_value[148];
  EXPECT_EQ(last_msg_->amplitude_value[149], 117)
      << "incorrect value for amplitude_value[149], expected 117, is "
      << last_msg_->amplitude_value[149];
  EXPECT_EQ(last_msg_->amplitude_value[150], 47)
      << "incorrect value for amplitude_value[150], expected 47, is "
      << last_msg_->amplitude_value[150];
  EXPECT_EQ(last_msg_->amplitude_value[151], 143)
      << "incorrect value for amplitude_value[151], expected 143, is "
      << last_msg_->amplitude_value[151];
  EXPECT_EQ(last_msg_->amplitude_value[152], 94)
      << "incorrect value for amplitude_value[152], expected 94, is "
      << last_msg_->amplitude_value[152];
  EXPECT_EQ(last_msg_->amplitude_value[153], 135)
      << "incorrect value for amplitude_value[153], expected 135, is "
      << last_msg_->amplitude_value[153];
  EXPECT_EQ(last_msg_->amplitude_value[154], 22)
      << "incorrect value for amplitude_value[154], expected 22, is "
      << last_msg_->amplitude_value[154];
  EXPECT_EQ(last_msg_->amplitude_value[155], 155)
      << "incorrect value for amplitude_value[155], expected 155, is "
      << last_msg_->amplitude_value[155];
  EXPECT_EQ(last_msg_->amplitude_value[156], 113)
      << "incorrect value for amplitude_value[156], expected 113, is "
      << last_msg_->amplitude_value[156];
  EXPECT_EQ(last_msg_->amplitude_value[157], 110)
      << "incorrect value for amplitude_value[157], expected 110, is "
      << last_msg_->amplitude_value[157];
  EXPECT_EQ(last_msg_->amplitude_value[158], 15)
      << "incorrect value for amplitude_value[158], expected 15, is "
      << last_msg_->amplitude_value[158];
  EXPECT_EQ(last_msg_->amplitude_value[159], 243)
      << "incorrect value for amplitude_value[159], expected 243, is "
      << last_msg_->amplitude_value[159];
  EXPECT_EQ(last_msg_->amplitude_value[160], 141)
      << "incorrect value for amplitude_value[160], expected 141, is "
      << last_msg_->amplitude_value[160];
  EXPECT_EQ(last_msg_->amplitude_value[161], 227)
      << "incorrect value for amplitude_value[161], expected 227, is "
      << last_msg_->amplitude_value[161];
  EXPECT_EQ(last_msg_->amplitude_value[162], 46)
      << "incorrect value for amplitude_value[162], expected 46, is "
      << last_msg_->amplitude_value[162];
  EXPECT_EQ(last_msg_->amplitude_value[163], 143)
      << "incorrect value for amplitude_value[163], expected 143, is "
      << last_msg_->amplitude_value[163];
  EXPECT_EQ(last_msg_->amplitude_value[164], 227)
      << "incorrect value for amplitude_value[164], expected 227, is "
      << last_msg_->amplitude_value[164];
  EXPECT_EQ(last_msg_->amplitude_value[165], 209)
      << "incorrect value for amplitude_value[165], expected 209, is "
      << last_msg_->amplitude_value[165];
  EXPECT_EQ(last_msg_->amplitude_value[166], 249)
      << "incorrect value for amplitude_value[166], expected 249, is "
      << last_msg_->amplitude_value[166];
  EXPECT_EQ(last_msg_->amplitude_value[167], 2)
      << "incorrect value for amplitude_value[167], expected 2, is "
      << last_msg_->amplitude_value[167];
  EXPECT_EQ(last_msg_->amplitude_value[168], 153)
      << "incorrect value for amplitude_value[168], expected 153, is "
      << last_msg_->amplitude_value[168];
  EXPECT_EQ(last_msg_->amplitude_value[169], 168)
      << "incorrect value for amplitude_value[169], expected 168, is "
      << last_msg_->amplitude_value[169];
  EXPECT_EQ(last_msg_->amplitude_value[170], 131)
      << "incorrect value for amplitude_value[170], expected 131, is "
      << last_msg_->amplitude_value[170];
  EXPECT_EQ(last_msg_->amplitude_value[171], 249)
      << "incorrect value for amplitude_value[171], expected 249, is "
      << last_msg_->amplitude_value[171];
  EXPECT_EQ(last_msg_->amplitude_value[172], 160)
      << "incorrect value for amplitude_value[172], expected 160, is "
      << last_msg_->amplitude_value[172];
  EXPECT_EQ(last_msg_->amplitude_value[173], 88)
      << "incorrect value for amplitude_value[173], expected 88, is "
      << last_msg_->amplitude_value[173];
  EXPECT_EQ(last_msg_->amplitude_value[174], 38)
      << "incorrect value for amplitude_value[174], expected 38, is "
      << last_msg_->amplitude_value[174];
  EXPECT_EQ(last_msg_->amplitude_value[175], 117)
      << "incorrect value for amplitude_value[175], expected 117, is "
      << last_msg_->amplitude_value[175];
  EXPECT_EQ(last_msg_->amplitude_value[176], 129)
      << "incorrect value for amplitude_value[176], expected 129, is "
      << last_msg_->amplitude_value[176];
  EXPECT_EQ(last_msg_->amplitude_value[177], 57)
      << "incorrect value for amplitude_value[177], expected 57, is "
      << last_msg_->amplitude_value[177];
  EXPECT_EQ(last_msg_->amplitude_value[178], 40)
      << "incorrect value for amplitude_value[178], expected 40, is "
      << last_msg_->amplitude_value[178];
  EXPECT_EQ(last_msg_->amplitude_value[179], 109)
      << "incorrect value for amplitude_value[179], expected 109, is "
      << last_msg_->amplitude_value[179];
  EXPECT_EQ(last_msg_->amplitude_value[180], 209)
      << "incorrect value for amplitude_value[180], expected 209, is "
      << last_msg_->amplitude_value[180];
  EXPECT_EQ(last_msg_->amplitude_value[181], 177)
      << "incorrect value for amplitude_value[181], expected 177, is "
      << last_msg_->amplitude_value[181];
  EXPECT_EQ(last_msg_->amplitude_value[182], 38)
      << "incorrect value for amplitude_value[182], expected 38, is "
      << last_msg_->amplitude_value[182];
  EXPECT_EQ(last_msg_->amplitude_value[183], 47)
      << "incorrect value for amplitude_value[183], expected 47, is "
      << last_msg_->amplitude_value[183];
  EXPECT_EQ(last_msg_->amplitude_value[184], 12)
      << "incorrect value for amplitude_value[184], expected 12, is "
      << last_msg_->amplitude_value[184];
  EXPECT_EQ(last_msg_->amplitude_value[185], 15)
      << "incorrect value for amplitude_value[185], expected 15, is "
      << last_msg_->amplitude_value[185];
  EXPECT_EQ(last_msg_->amplitude_value[186], 16)
      << "incorrect value for amplitude_value[186], expected 16, is "
      << last_msg_->amplitude_value[186];
  EXPECT_EQ(last_msg_->amplitude_value[187], 9)
      << "incorrect value for amplitude_value[187], expected 9, is "
      << last_msg_->amplitude_value[187];
  EXPECT_EQ(last_msg_->amplitude_value[188], 175)
      << "incorrect value for amplitude_value[188], expected 175, is "
      << last_msg_->amplitude_value[188];
  EXPECT_EQ(last_msg_->amplitude_value[189], 69)
      << "incorrect value for amplitude_value[189], expected 69, is "
      << last_msg_->amplitude_value[189];
  EXPECT_EQ(last_msg_->amplitude_value[190], 70)
      << "incorrect value for amplitude_value[190], expected 70, is "
      << last_msg_->amplitude_value[190];
  EXPECT_EQ(last_msg_->amplitude_value[191], 182)
      << "incorrect value for amplitude_value[191], expected 182, is "
      << last_msg_->amplitude_value[191];
  EXPECT_EQ(last_msg_->amplitude_value[192], 239)
      << "incorrect value for amplitude_value[192], expected 239, is "
      << last_msg_->amplitude_value[192];
  EXPECT_EQ(last_msg_->amplitude_value[193], 117)
      << "incorrect value for amplitude_value[193], expected 117, is "
      << last_msg_->amplitude_value[193];
  EXPECT_EQ(last_msg_->amplitude_value[194], 135)
      << "incorrect value for amplitude_value[194], expected 135, is "
      << last_msg_->amplitude_value[194];
  EXPECT_EQ(last_msg_->amplitude_value[195], 6)
      << "incorrect value for amplitude_value[195], expected 6, is "
      << last_msg_->amplitude_value[195];
  EXPECT_EQ(last_msg_->amplitude_value[196], 71)
      << "incorrect value for amplitude_value[196], expected 71, is "
      << last_msg_->amplitude_value[196];
  EXPECT_EQ(last_msg_->amplitude_value[197], 99)
      << "incorrect value for amplitude_value[197], expected 99, is "
      << last_msg_->amplitude_value[197];
  EXPECT_EQ(last_msg_->amplitude_value[198], 230)
      << "incorrect value for amplitude_value[198], expected 230, is "
      << last_msg_->amplitude_value[198];
  EXPECT_EQ(last_msg_->amplitude_value[199], 115)
      << "incorrect value for amplitude_value[199], expected 115, is "
      << last_msg_->amplitude_value[199];
  EXPECT_EQ(last_msg_->amplitude_value[200], 2)
      << "incorrect value for amplitude_value[200], expected 2, is "
      << last_msg_->amplitude_value[200];
  EXPECT_EQ(last_msg_->amplitude_value[201], 71)
      << "incorrect value for amplitude_value[201], expected 71, is "
      << last_msg_->amplitude_value[201];
  EXPECT_EQ(last_msg_->amplitude_value[202], 165)
      << "incorrect value for amplitude_value[202], expected 165, is "
      << last_msg_->amplitude_value[202];
  EXPECT_EQ(last_msg_->amplitude_value[203], 228)
      << "incorrect value for amplitude_value[203], expected 228, is "
      << last_msg_->amplitude_value[203];
  EXPECT_EQ(last_msg_->amplitude_value[204], 123)
      << "incorrect value for amplitude_value[204], expected 123, is "
      << last_msg_->amplitude_value[204];
  EXPECT_EQ(last_msg_->amplitude_value[205], 210)
      << "incorrect value for amplitude_value[205], expected 210, is "
      << last_msg_->amplitude_value[205];
  EXPECT_EQ(last_msg_->amplitude_value[206], 168)
      << "incorrect value for amplitude_value[206], expected 168, is "
      << last_msg_->amplitude_value[206];
  EXPECT_EQ(last_msg_->amplitude_value[207], 90)
      << "incorrect value for amplitude_value[207], expected 90, is "
      << last_msg_->amplitude_value[207];
  EXPECT_EQ(last_msg_->amplitude_value[208], 124)
      << "incorrect value for amplitude_value[208], expected 124, is "
      << last_msg_->amplitude_value[208];
  EXPECT_EQ(last_msg_->amplitude_value[209], 20)
      << "incorrect value for amplitude_value[209], expected 20, is "
      << last_msg_->amplitude_value[209];
  EXPECT_EQ(last_msg_->amplitude_value[210], 7)
      << "incorrect value for amplitude_value[210], expected 7, is "
      << last_msg_->amplitude_value[210];
  EXPECT_EQ(last_msg_->amplitude_value[211], 220)
      << "incorrect value for amplitude_value[211], expected 220, is "
      << last_msg_->amplitude_value[211];
  EXPECT_EQ(last_msg_->amplitude_value[212], 144)
      << "incorrect value for amplitude_value[212], expected 144, is "
      << last_msg_->amplitude_value[212];
  EXPECT_EQ(last_msg_->amplitude_value[213], 168)
      << "incorrect value for amplitude_value[213], expected 168, is "
      << last_msg_->amplitude_value[213];
  EXPECT_EQ(last_msg_->amplitude_value[214], 69)
      << "incorrect value for amplitude_value[214], expected 69, is "
      << last_msg_->amplitude_value[214];
  EXPECT_EQ(last_msg_->amplitude_value[215], 22)
      << "incorrect value for amplitude_value[215], expected 22, is "
      << last_msg_->amplitude_value[215];
  EXPECT_EQ(last_msg_->amplitude_value[216], 72)
      << "incorrect value for amplitude_value[216], expected 72, is "
      << last_msg_->amplitude_value[216];
  EXPECT_EQ(last_msg_->amplitude_value[217], 162)
      << "incorrect value for amplitude_value[217], expected 162, is "
      << last_msg_->amplitude_value[217];
  EXPECT_EQ(last_msg_->amplitude_value[218], 69)
      << "incorrect value for amplitude_value[218], expected 69, is "
      << last_msg_->amplitude_value[218];
  EXPECT_EQ(last_msg_->amplitude_value[219], 111)
      << "incorrect value for amplitude_value[219], expected 111, is "
      << last_msg_->amplitude_value[219];
  EXPECT_EQ(last_msg_->amplitude_value[220], 91)
      << "incorrect value for amplitude_value[220], expected 91, is "
      << last_msg_->amplitude_value[220];
  EXPECT_EQ(last_msg_->amplitude_value[221], 251)
      << "incorrect value for amplitude_value[221], expected 251, is "
      << last_msg_->amplitude_value[221];
  EXPECT_EQ(last_msg_->amplitude_value[222], 72)
      << "incorrect value for amplitude_value[222], expected 72, is "
      << last_msg_->amplitude_value[222];
  EXPECT_EQ(last_msg_->amplitude_value[223], 220)
      << "incorrect value for amplitude_value[223], expected 220, is "
      << last_msg_->amplitude_value[223];
  EXPECT_EQ(last_msg_->amplitude_value[224], 28)
      << "incorrect value for amplitude_value[224], expected 28, is "
      << last_msg_->amplitude_value[224];
  EXPECT_EQ(last_msg_->amplitude_value[225], 119)
      << "incorrect value for amplitude_value[225], expected 119, is "
      << last_msg_->amplitude_value[225];
  EXPECT_EQ(last_msg_->amplitude_value[226], 150)
      << "incorrect value for amplitude_value[226], expected 150, is "
      << last_msg_->amplitude_value[226];
  EXPECT_EQ(last_msg_->channel_tag, 35146)
      << "incorrect value for channel_tag, expected 35146, is "
      << last_msg_->channel_tag;
  EXPECT_LT((last_msg_->freq_ref * 100 - 7737.20019531 * 100), 0.05)
      << "incorrect value for freq_ref, expected 7737.20019531, is "
      << last_msg_->freq_ref;
  EXPECT_LT((last_msg_->freq_step * 100 - 8226.20019531 * 100), 0.05)
      << "incorrect value for freq_step, expected 8226.20019531, is "
      << last_msg_->freq_step;
  EXPECT_EQ(last_msg_->t.ns_residual, -1479025396)
      << "incorrect value for t.ns_residual, expected -1479025396, is "
      << last_msg_->t.ns_residual;
  EXPECT_EQ(last_msg_->t.tow, 1227027783)
      << "incorrect value for t.tow, expected 1227027783, is "
      << last_msg_->t.tow;
  EXPECT_EQ(last_msg_->t.wn, 5075)
      << "incorrect value for t.wn, expected 5075, is " << last_msg_->t.wn;
}
