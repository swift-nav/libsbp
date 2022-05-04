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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgItrf.yaml by generate.py. Do
// not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_navigation_MsgItrf0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_itrf_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgItrf0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_itrf_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_itrf_t *>(last_msg_storage_)),
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
                      const msg_itrf_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_itrf_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgItrf0, Test) {
  uint8_t encoded_frame[] = {
      85, 68, 2,  66, 0, 124, 1,  2,  102, 111, 111, 0,  0,   0, 0,  0,  0,
      0,  0,  0,  0,  0, 0,   0,  0,  0,   0,   0,   0,  0,   0, 0,  0,  0,
      0,  0,  0,  0,  0, 3,   98, 97, 114, 0,   0,   0,  0,   0, 0,  0,  0,
      0,  0,  0,  0,  0, 0,   0,  0,  0,   0,   0,   0,  0,   0, 0,  0,  0,
      0,  0,  0,  4,  5, 0,   6,  0,  7,   0,   0,   0,  8,   0, 0,  0,  9,
      0,  0,  0,  10, 0, 0,   0,  11, 0,   0,   0,   12, 0,   0, 0,  13, 0,
      0,  0,  14, 0,  0, 0,   15, 0,  0,   0,   16,  0,  0,   0, 17, 0,  0,
      0,  18, 0,  0,  0, 19,  0,  0,  0,   20,  0,   66, 126,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_itrf_t *test_msg = (msg_itrf_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[0] = 1;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[1] = 2;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[2] = 102;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[3] = 111;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[4] = 111;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[5] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[6] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[7] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[8] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[9] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[10] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[11] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[12] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[13] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[14] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[15] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[16] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[17] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[18] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[19] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[20] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[21] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[22] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[23] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[24] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[25] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[26] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[27] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[28] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[29] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[30] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[31] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[32] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[33] = 3;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[34] = 98;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[35] = 97;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[36] = 114;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[37] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[38] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[39] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[40] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[41] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[42] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[43] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[44] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[45] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[46] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[47] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[48] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[49] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[50] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[51] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[52] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[53] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[54] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[55] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[56] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[57] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[58] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[59] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[60] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[61] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[62] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[63] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[64] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[65] = 4;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[66] = 5;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[67] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[68] = 6;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[69] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[70] = 7;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[71] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[72] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[73] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[74] = 8;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[75] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[76] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[77] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[78] = 9;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[79] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[80] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[81] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[82] = 10;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[83] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[84] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[85] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[86] = 11;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[87] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[88] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[89] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[90] = 12;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[91] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[92] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[93] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[94] = 13;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[95] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[96] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[97] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[98] = 14;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[99] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[100] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[101] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[102] = 15;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[103] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[104] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[105] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[106] = 16;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[107] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[108] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[109] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[110] = 17;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[111] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[112] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[113] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[114] = 18;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[115] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[116] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[117] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[118] = 19;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[119] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[120] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[121] = 0;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[122] = 20;
  if (sizeof(test_msg->stub) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->stub[0]));
  }
  test_msg->stub[123] = 0;

  EXPECT_EQ(send_message(580, 66, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 66);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->stub[0], 1)
      << "incorrect value for stub[0], expected 1, is " << last_msg_->stub[0];
  EXPECT_EQ(last_msg_->stub[1], 2)
      << "incorrect value for stub[1], expected 2, is " << last_msg_->stub[1];
  EXPECT_EQ(last_msg_->stub[2], 102)
      << "incorrect value for stub[2], expected 102, is " << last_msg_->stub[2];
  EXPECT_EQ(last_msg_->stub[3], 111)
      << "incorrect value for stub[3], expected 111, is " << last_msg_->stub[3];
  EXPECT_EQ(last_msg_->stub[4], 111)
      << "incorrect value for stub[4], expected 111, is " << last_msg_->stub[4];
  EXPECT_EQ(last_msg_->stub[5], 0)
      << "incorrect value for stub[5], expected 0, is " << last_msg_->stub[5];
  EXPECT_EQ(last_msg_->stub[6], 0)
      << "incorrect value for stub[6], expected 0, is " << last_msg_->stub[6];
  EXPECT_EQ(last_msg_->stub[7], 0)
      << "incorrect value for stub[7], expected 0, is " << last_msg_->stub[7];
  EXPECT_EQ(last_msg_->stub[8], 0)
      << "incorrect value for stub[8], expected 0, is " << last_msg_->stub[8];
  EXPECT_EQ(last_msg_->stub[9], 0)
      << "incorrect value for stub[9], expected 0, is " << last_msg_->stub[9];
  EXPECT_EQ(last_msg_->stub[10], 0)
      << "incorrect value for stub[10], expected 0, is " << last_msg_->stub[10];
  EXPECT_EQ(last_msg_->stub[11], 0)
      << "incorrect value for stub[11], expected 0, is " << last_msg_->stub[11];
  EXPECT_EQ(last_msg_->stub[12], 0)
      << "incorrect value for stub[12], expected 0, is " << last_msg_->stub[12];
  EXPECT_EQ(last_msg_->stub[13], 0)
      << "incorrect value for stub[13], expected 0, is " << last_msg_->stub[13];
  EXPECT_EQ(last_msg_->stub[14], 0)
      << "incorrect value for stub[14], expected 0, is " << last_msg_->stub[14];
  EXPECT_EQ(last_msg_->stub[15], 0)
      << "incorrect value for stub[15], expected 0, is " << last_msg_->stub[15];
  EXPECT_EQ(last_msg_->stub[16], 0)
      << "incorrect value for stub[16], expected 0, is " << last_msg_->stub[16];
  EXPECT_EQ(last_msg_->stub[17], 0)
      << "incorrect value for stub[17], expected 0, is " << last_msg_->stub[17];
  EXPECT_EQ(last_msg_->stub[18], 0)
      << "incorrect value for stub[18], expected 0, is " << last_msg_->stub[18];
  EXPECT_EQ(last_msg_->stub[19], 0)
      << "incorrect value for stub[19], expected 0, is " << last_msg_->stub[19];
  EXPECT_EQ(last_msg_->stub[20], 0)
      << "incorrect value for stub[20], expected 0, is " << last_msg_->stub[20];
  EXPECT_EQ(last_msg_->stub[21], 0)
      << "incorrect value for stub[21], expected 0, is " << last_msg_->stub[21];
  EXPECT_EQ(last_msg_->stub[22], 0)
      << "incorrect value for stub[22], expected 0, is " << last_msg_->stub[22];
  EXPECT_EQ(last_msg_->stub[23], 0)
      << "incorrect value for stub[23], expected 0, is " << last_msg_->stub[23];
  EXPECT_EQ(last_msg_->stub[24], 0)
      << "incorrect value for stub[24], expected 0, is " << last_msg_->stub[24];
  EXPECT_EQ(last_msg_->stub[25], 0)
      << "incorrect value for stub[25], expected 0, is " << last_msg_->stub[25];
  EXPECT_EQ(last_msg_->stub[26], 0)
      << "incorrect value for stub[26], expected 0, is " << last_msg_->stub[26];
  EXPECT_EQ(last_msg_->stub[27], 0)
      << "incorrect value for stub[27], expected 0, is " << last_msg_->stub[27];
  EXPECT_EQ(last_msg_->stub[28], 0)
      << "incorrect value for stub[28], expected 0, is " << last_msg_->stub[28];
  EXPECT_EQ(last_msg_->stub[29], 0)
      << "incorrect value for stub[29], expected 0, is " << last_msg_->stub[29];
  EXPECT_EQ(last_msg_->stub[30], 0)
      << "incorrect value for stub[30], expected 0, is " << last_msg_->stub[30];
  EXPECT_EQ(last_msg_->stub[31], 0)
      << "incorrect value for stub[31], expected 0, is " << last_msg_->stub[31];
  EXPECT_EQ(last_msg_->stub[32], 0)
      << "incorrect value for stub[32], expected 0, is " << last_msg_->stub[32];
  EXPECT_EQ(last_msg_->stub[33], 3)
      << "incorrect value for stub[33], expected 3, is " << last_msg_->stub[33];
  EXPECT_EQ(last_msg_->stub[34], 98)
      << "incorrect value for stub[34], expected 98, is "
      << last_msg_->stub[34];
  EXPECT_EQ(last_msg_->stub[35], 97)
      << "incorrect value for stub[35], expected 97, is "
      << last_msg_->stub[35];
  EXPECT_EQ(last_msg_->stub[36], 114)
      << "incorrect value for stub[36], expected 114, is "
      << last_msg_->stub[36];
  EXPECT_EQ(last_msg_->stub[37], 0)
      << "incorrect value for stub[37], expected 0, is " << last_msg_->stub[37];
  EXPECT_EQ(last_msg_->stub[38], 0)
      << "incorrect value for stub[38], expected 0, is " << last_msg_->stub[38];
  EXPECT_EQ(last_msg_->stub[39], 0)
      << "incorrect value for stub[39], expected 0, is " << last_msg_->stub[39];
  EXPECT_EQ(last_msg_->stub[40], 0)
      << "incorrect value for stub[40], expected 0, is " << last_msg_->stub[40];
  EXPECT_EQ(last_msg_->stub[41], 0)
      << "incorrect value for stub[41], expected 0, is " << last_msg_->stub[41];
  EXPECT_EQ(last_msg_->stub[42], 0)
      << "incorrect value for stub[42], expected 0, is " << last_msg_->stub[42];
  EXPECT_EQ(last_msg_->stub[43], 0)
      << "incorrect value for stub[43], expected 0, is " << last_msg_->stub[43];
  EXPECT_EQ(last_msg_->stub[44], 0)
      << "incorrect value for stub[44], expected 0, is " << last_msg_->stub[44];
  EXPECT_EQ(last_msg_->stub[45], 0)
      << "incorrect value for stub[45], expected 0, is " << last_msg_->stub[45];
  EXPECT_EQ(last_msg_->stub[46], 0)
      << "incorrect value for stub[46], expected 0, is " << last_msg_->stub[46];
  EXPECT_EQ(last_msg_->stub[47], 0)
      << "incorrect value for stub[47], expected 0, is " << last_msg_->stub[47];
  EXPECT_EQ(last_msg_->stub[48], 0)
      << "incorrect value for stub[48], expected 0, is " << last_msg_->stub[48];
  EXPECT_EQ(last_msg_->stub[49], 0)
      << "incorrect value for stub[49], expected 0, is " << last_msg_->stub[49];
  EXPECT_EQ(last_msg_->stub[50], 0)
      << "incorrect value for stub[50], expected 0, is " << last_msg_->stub[50];
  EXPECT_EQ(last_msg_->stub[51], 0)
      << "incorrect value for stub[51], expected 0, is " << last_msg_->stub[51];
  EXPECT_EQ(last_msg_->stub[52], 0)
      << "incorrect value for stub[52], expected 0, is " << last_msg_->stub[52];
  EXPECT_EQ(last_msg_->stub[53], 0)
      << "incorrect value for stub[53], expected 0, is " << last_msg_->stub[53];
  EXPECT_EQ(last_msg_->stub[54], 0)
      << "incorrect value for stub[54], expected 0, is " << last_msg_->stub[54];
  EXPECT_EQ(last_msg_->stub[55], 0)
      << "incorrect value for stub[55], expected 0, is " << last_msg_->stub[55];
  EXPECT_EQ(last_msg_->stub[56], 0)
      << "incorrect value for stub[56], expected 0, is " << last_msg_->stub[56];
  EXPECT_EQ(last_msg_->stub[57], 0)
      << "incorrect value for stub[57], expected 0, is " << last_msg_->stub[57];
  EXPECT_EQ(last_msg_->stub[58], 0)
      << "incorrect value for stub[58], expected 0, is " << last_msg_->stub[58];
  EXPECT_EQ(last_msg_->stub[59], 0)
      << "incorrect value for stub[59], expected 0, is " << last_msg_->stub[59];
  EXPECT_EQ(last_msg_->stub[60], 0)
      << "incorrect value for stub[60], expected 0, is " << last_msg_->stub[60];
  EXPECT_EQ(last_msg_->stub[61], 0)
      << "incorrect value for stub[61], expected 0, is " << last_msg_->stub[61];
  EXPECT_EQ(last_msg_->stub[62], 0)
      << "incorrect value for stub[62], expected 0, is " << last_msg_->stub[62];
  EXPECT_EQ(last_msg_->stub[63], 0)
      << "incorrect value for stub[63], expected 0, is " << last_msg_->stub[63];
  EXPECT_EQ(last_msg_->stub[64], 0)
      << "incorrect value for stub[64], expected 0, is " << last_msg_->stub[64];
  EXPECT_EQ(last_msg_->stub[65], 4)
      << "incorrect value for stub[65], expected 4, is " << last_msg_->stub[65];
  EXPECT_EQ(last_msg_->stub[66], 5)
      << "incorrect value for stub[66], expected 5, is " << last_msg_->stub[66];
  EXPECT_EQ(last_msg_->stub[67], 0)
      << "incorrect value for stub[67], expected 0, is " << last_msg_->stub[67];
  EXPECT_EQ(last_msg_->stub[68], 6)
      << "incorrect value for stub[68], expected 6, is " << last_msg_->stub[68];
  EXPECT_EQ(last_msg_->stub[69], 0)
      << "incorrect value for stub[69], expected 0, is " << last_msg_->stub[69];
  EXPECT_EQ(last_msg_->stub[70], 7)
      << "incorrect value for stub[70], expected 7, is " << last_msg_->stub[70];
  EXPECT_EQ(last_msg_->stub[71], 0)
      << "incorrect value for stub[71], expected 0, is " << last_msg_->stub[71];
  EXPECT_EQ(last_msg_->stub[72], 0)
      << "incorrect value for stub[72], expected 0, is " << last_msg_->stub[72];
  EXPECT_EQ(last_msg_->stub[73], 0)
      << "incorrect value for stub[73], expected 0, is " << last_msg_->stub[73];
  EXPECT_EQ(last_msg_->stub[74], 8)
      << "incorrect value for stub[74], expected 8, is " << last_msg_->stub[74];
  EXPECT_EQ(last_msg_->stub[75], 0)
      << "incorrect value for stub[75], expected 0, is " << last_msg_->stub[75];
  EXPECT_EQ(last_msg_->stub[76], 0)
      << "incorrect value for stub[76], expected 0, is " << last_msg_->stub[76];
  EXPECT_EQ(last_msg_->stub[77], 0)
      << "incorrect value for stub[77], expected 0, is " << last_msg_->stub[77];
  EXPECT_EQ(last_msg_->stub[78], 9)
      << "incorrect value for stub[78], expected 9, is " << last_msg_->stub[78];
  EXPECT_EQ(last_msg_->stub[79], 0)
      << "incorrect value for stub[79], expected 0, is " << last_msg_->stub[79];
  EXPECT_EQ(last_msg_->stub[80], 0)
      << "incorrect value for stub[80], expected 0, is " << last_msg_->stub[80];
  EXPECT_EQ(last_msg_->stub[81], 0)
      << "incorrect value for stub[81], expected 0, is " << last_msg_->stub[81];
  EXPECT_EQ(last_msg_->stub[82], 10)
      << "incorrect value for stub[82], expected 10, is "
      << last_msg_->stub[82];
  EXPECT_EQ(last_msg_->stub[83], 0)
      << "incorrect value for stub[83], expected 0, is " << last_msg_->stub[83];
  EXPECT_EQ(last_msg_->stub[84], 0)
      << "incorrect value for stub[84], expected 0, is " << last_msg_->stub[84];
  EXPECT_EQ(last_msg_->stub[85], 0)
      << "incorrect value for stub[85], expected 0, is " << last_msg_->stub[85];
  EXPECT_EQ(last_msg_->stub[86], 11)
      << "incorrect value for stub[86], expected 11, is "
      << last_msg_->stub[86];
  EXPECT_EQ(last_msg_->stub[87], 0)
      << "incorrect value for stub[87], expected 0, is " << last_msg_->stub[87];
  EXPECT_EQ(last_msg_->stub[88], 0)
      << "incorrect value for stub[88], expected 0, is " << last_msg_->stub[88];
  EXPECT_EQ(last_msg_->stub[89], 0)
      << "incorrect value for stub[89], expected 0, is " << last_msg_->stub[89];
  EXPECT_EQ(last_msg_->stub[90], 12)
      << "incorrect value for stub[90], expected 12, is "
      << last_msg_->stub[90];
  EXPECT_EQ(last_msg_->stub[91], 0)
      << "incorrect value for stub[91], expected 0, is " << last_msg_->stub[91];
  EXPECT_EQ(last_msg_->stub[92], 0)
      << "incorrect value for stub[92], expected 0, is " << last_msg_->stub[92];
  EXPECT_EQ(last_msg_->stub[93], 0)
      << "incorrect value for stub[93], expected 0, is " << last_msg_->stub[93];
  EXPECT_EQ(last_msg_->stub[94], 13)
      << "incorrect value for stub[94], expected 13, is "
      << last_msg_->stub[94];
  EXPECT_EQ(last_msg_->stub[95], 0)
      << "incorrect value for stub[95], expected 0, is " << last_msg_->stub[95];
  EXPECT_EQ(last_msg_->stub[96], 0)
      << "incorrect value for stub[96], expected 0, is " << last_msg_->stub[96];
  EXPECT_EQ(last_msg_->stub[97], 0)
      << "incorrect value for stub[97], expected 0, is " << last_msg_->stub[97];
  EXPECT_EQ(last_msg_->stub[98], 14)
      << "incorrect value for stub[98], expected 14, is "
      << last_msg_->stub[98];
  EXPECT_EQ(last_msg_->stub[99], 0)
      << "incorrect value for stub[99], expected 0, is " << last_msg_->stub[99];
  EXPECT_EQ(last_msg_->stub[100], 0)
      << "incorrect value for stub[100], expected 0, is "
      << last_msg_->stub[100];
  EXPECT_EQ(last_msg_->stub[101], 0)
      << "incorrect value for stub[101], expected 0, is "
      << last_msg_->stub[101];
  EXPECT_EQ(last_msg_->stub[102], 15)
      << "incorrect value for stub[102], expected 15, is "
      << last_msg_->stub[102];
  EXPECT_EQ(last_msg_->stub[103], 0)
      << "incorrect value for stub[103], expected 0, is "
      << last_msg_->stub[103];
  EXPECT_EQ(last_msg_->stub[104], 0)
      << "incorrect value for stub[104], expected 0, is "
      << last_msg_->stub[104];
  EXPECT_EQ(last_msg_->stub[105], 0)
      << "incorrect value for stub[105], expected 0, is "
      << last_msg_->stub[105];
  EXPECT_EQ(last_msg_->stub[106], 16)
      << "incorrect value for stub[106], expected 16, is "
      << last_msg_->stub[106];
  EXPECT_EQ(last_msg_->stub[107], 0)
      << "incorrect value for stub[107], expected 0, is "
      << last_msg_->stub[107];
  EXPECT_EQ(last_msg_->stub[108], 0)
      << "incorrect value for stub[108], expected 0, is "
      << last_msg_->stub[108];
  EXPECT_EQ(last_msg_->stub[109], 0)
      << "incorrect value for stub[109], expected 0, is "
      << last_msg_->stub[109];
  EXPECT_EQ(last_msg_->stub[110], 17)
      << "incorrect value for stub[110], expected 17, is "
      << last_msg_->stub[110];
  EXPECT_EQ(last_msg_->stub[111], 0)
      << "incorrect value for stub[111], expected 0, is "
      << last_msg_->stub[111];
  EXPECT_EQ(last_msg_->stub[112], 0)
      << "incorrect value for stub[112], expected 0, is "
      << last_msg_->stub[112];
  EXPECT_EQ(last_msg_->stub[113], 0)
      << "incorrect value for stub[113], expected 0, is "
      << last_msg_->stub[113];
  EXPECT_EQ(last_msg_->stub[114], 18)
      << "incorrect value for stub[114], expected 18, is "
      << last_msg_->stub[114];
  EXPECT_EQ(last_msg_->stub[115], 0)
      << "incorrect value for stub[115], expected 0, is "
      << last_msg_->stub[115];
  EXPECT_EQ(last_msg_->stub[116], 0)
      << "incorrect value for stub[116], expected 0, is "
      << last_msg_->stub[116];
  EXPECT_EQ(last_msg_->stub[117], 0)
      << "incorrect value for stub[117], expected 0, is "
      << last_msg_->stub[117];
  EXPECT_EQ(last_msg_->stub[118], 19)
      << "incorrect value for stub[118], expected 19, is "
      << last_msg_->stub[118];
  EXPECT_EQ(last_msg_->stub[119], 0)
      << "incorrect value for stub[119], expected 0, is "
      << last_msg_->stub[119];
  EXPECT_EQ(last_msg_->stub[120], 0)
      << "incorrect value for stub[120], expected 0, is "
      << last_msg_->stub[120];
  EXPECT_EQ(last_msg_->stub[121], 0)
      << "incorrect value for stub[121], expected 0, is "
      << last_msg_->stub[121];
  EXPECT_EQ(last_msg_->stub[122], 20)
      << "incorrect value for stub[122], expected 20, is "
      << last_msg_->stub[122];
  EXPECT_EQ(last_msg_->stub[123], 0)
      << "incorrect value for stub[123], expected 0, is "
      << last_msg_->stub[123];
}
