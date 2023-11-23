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
// spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadResp.yaml by
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
#include <libsbp/legacy/file_io.h>
class Test_legacy_auto_check_sbp_file_io_MsgFileioReadResp0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_fileio_read_resp_t> {
 public:
  Test_legacy_auto_check_sbp_file_io_MsgFileioReadResp0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_fileio_read_resp_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_fileio_read_resp_t *>(last_msg_storage_)),
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
                      const msg_fileio_read_resp_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_fileio_read_resp_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_file_io_MsgFileioReadResp0, Test) {
  uint8_t encoded_frame[] = {
      85,  163, 0,   195, 4,   255, 67,  183, 115, 15,  73,  231, 227, 179, 18,
      76,  68,  229, 216, 21,  98,  183, 69,  190, 5,   252, 176, 55,  32,  78,
      8,   52,  127, 50,  71,  106, 61,  79,  191, 106, 46,  79,  118, 248, 118,
      207, 206, 210, 91,  73,  251, 81,  131, 205, 193, 146, 206, 185, 140, 249,
      163, 231, 65,  67,  94,  250, 109, 152, 95,  123, 77,  224, 124, 238, 205,
      65,  103, 35,  104, 209, 5,   191, 47,  249, 176, 166, 213, 46,  192, 86,
      32,  103, 146, 252, 4,   16,  54,  161, 60,  6,   13,  191, 116, 182, 42,
      191, 213, 20,  217, 8,   142, 187, 238, 120, 184, 250, 31,  151, 37,  51,
      177, 130, 190, 155, 71,  68,  56,  238, 92,  130, 37,  137, 146, 246, 114,
      116, 138, 165, 217, 79,  10,  189, 128, 189, 2,   240, 92,  28,  126, 105,
      236, 228, 194, 0,   51,  61,  74,  41,  10,  239, 133, 106, 190, 30,  27,
      3,   240, 205, 253, 113, 25,  28,  187, 81,  101, 216, 121, 41,  179, 120,
      152, 18,  116, 53,  212, 100, 2,   114, 198, 200, 10,  147, 25,  33,  115,
      208, 113, 60,  179, 183, 0,   41,  217, 206, 255, 211, 225, 142, 191, 133,
      81,  15,  248, 193, 66,  191, 244, 221, 248, 199, 241, 112, 51,  1,   180,
      180, 125, 97,  145, 25,  72,  210, 215, 208, 15,  126, 56,  38,  65,  4,
      64,  19,  74,  223, 111, 109, 52,  43,  167, 186, 202, 111, 11,  91,  21,
      236, 234, 196, 36,  171, 147, 10,  240,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_fileio_read_resp_t *test_msg = (msg_fileio_read_resp_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[0] = 73;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[1] = 231;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[2] = 227;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[3] = 179;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[4] = 18;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[5] = 76;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[6] = 68;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[7] = 229;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[8] = 216;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[9] = 21;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[10] = 98;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[11] = 183;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[12] = 69;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[13] = 190;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[14] = 5;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[15] = 252;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[16] = 176;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[17] = 55;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[18] = 32;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[19] = 78;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[20] = 8;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[21] = 52;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[22] = 127;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[23] = 50;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[24] = 71;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[25] = 106;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[26] = 61;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[27] = 79;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[28] = 191;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[29] = 106;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[30] = 46;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[31] = 79;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[32] = 118;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[33] = 248;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[34] = 118;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[35] = 207;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[36] = 206;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[37] = 210;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[38] = 91;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[39] = 73;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[40] = 251;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[41] = 81;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[42] = 131;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[43] = 205;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[44] = 193;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[45] = 146;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[46] = 206;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[47] = 185;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[48] = 140;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[49] = 249;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[50] = 163;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[51] = 231;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[52] = 65;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[53] = 67;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[54] = 94;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[55] = 250;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[56] = 109;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[57] = 152;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[58] = 95;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[59] = 123;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[60] = 77;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[61] = 224;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[62] = 124;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[63] = 238;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[64] = 205;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[65] = 65;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[66] = 103;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[67] = 35;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[68] = 104;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[69] = 209;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[70] = 5;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[71] = 191;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[72] = 47;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[73] = 249;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[74] = 176;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[75] = 166;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[76] = 213;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[77] = 46;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[78] = 192;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[79] = 86;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[80] = 32;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[81] = 103;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[82] = 146;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[83] = 252;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[84] = 4;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[85] = 16;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[86] = 54;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[87] = 161;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[88] = 60;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[89] = 6;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[90] = 13;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[91] = 191;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[92] = 116;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[93] = 182;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[94] = 42;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[95] = 191;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[96] = 213;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[97] = 20;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[98] = 217;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[99] = 8;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[100] = 142;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[101] = 187;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[102] = 238;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[103] = 120;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[104] = 184;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[105] = 250;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[106] = 31;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[107] = 151;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[108] = 37;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[109] = 51;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[110] = 177;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[111] = 130;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[112] = 190;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[113] = 155;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[114] = 71;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[115] = 68;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[116] = 56;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[117] = 238;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[118] = 92;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[119] = 130;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[120] = 37;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[121] = 137;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[122] = 146;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[123] = 246;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[124] = 114;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[125] = 116;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[126] = 138;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[127] = 165;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[128] = 217;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[129] = 79;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[130] = 10;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[131] = 189;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[132] = 128;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[133] = 189;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[134] = 2;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[135] = 240;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[136] = 92;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[137] = 28;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[138] = 126;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[139] = 105;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[140] = 236;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[141] = 228;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[142] = 194;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[143] = 0;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[144] = 51;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[145] = 61;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[146] = 74;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[147] = 41;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[148] = 10;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[149] = 239;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[150] = 133;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[151] = 106;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[152] = 190;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[153] = 30;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[154] = 27;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[155] = 3;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[156] = 240;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[157] = 205;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[158] = 253;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[159] = 113;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[160] = 25;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[161] = 28;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[162] = 187;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[163] = 81;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[164] = 101;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[165] = 216;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[166] = 121;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[167] = 41;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[168] = 179;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[169] = 120;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[170] = 152;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[171] = 18;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[172] = 116;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[173] = 53;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[174] = 212;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[175] = 100;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[176] = 2;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[177] = 114;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[178] = 198;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[179] = 200;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[180] = 10;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[181] = 147;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[182] = 25;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[183] = 33;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[184] = 115;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[185] = 208;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[186] = 113;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[187] = 60;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[188] = 179;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[189] = 183;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[190] = 0;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[191] = 41;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[192] = 217;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[193] = 206;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[194] = 255;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[195] = 211;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[196] = 225;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[197] = 142;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[198] = 191;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[199] = 133;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[200] = 81;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[201] = 15;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[202] = 248;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[203] = 193;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[204] = 66;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[205] = 191;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[206] = 244;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[207] = 221;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[208] = 248;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[209] = 199;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[210] = 241;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[211] = 112;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[212] = 51;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[213] = 1;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[214] = 180;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[215] = 180;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[216] = 125;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[217] = 97;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[218] = 145;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[219] = 25;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[220] = 72;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[221] = 210;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[222] = 215;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[223] = 208;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[224] = 15;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[225] = 126;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[226] = 56;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[227] = 38;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[228] = 65;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[229] = 4;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[230] = 64;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[231] = 19;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[232] = 74;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[233] = 223;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[234] = 111;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[235] = 109;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[236] = 52;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[237] = 43;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[238] = 167;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[239] = 186;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[240] = 202;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[241] = 111;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[242] = 11;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[243] = 91;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[244] = 21;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[245] = 236;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[246] = 234;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[247] = 196;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[248] = 36;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[249] = 171;
  if (sizeof(test_msg->contents) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->contents[0]));
  }
  test_msg->contents[250] = 147;
  test_msg->sequence = 259241795;

  EXPECT_EQ(send_message(0xa3, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->contents[0], 73)
      << "incorrect value for contents[0], expected 73, is "
      << last_msg_->contents[0];
  EXPECT_EQ(last_msg_->contents[1], 231)
      << "incorrect value for contents[1], expected 231, is "
      << last_msg_->contents[1];
  EXPECT_EQ(last_msg_->contents[2], 227)
      << "incorrect value for contents[2], expected 227, is "
      << last_msg_->contents[2];
  EXPECT_EQ(last_msg_->contents[3], 179)
      << "incorrect value for contents[3], expected 179, is "
      << last_msg_->contents[3];
  EXPECT_EQ(last_msg_->contents[4], 18)
      << "incorrect value for contents[4], expected 18, is "
      << last_msg_->contents[4];
  EXPECT_EQ(last_msg_->contents[5], 76)
      << "incorrect value for contents[5], expected 76, is "
      << last_msg_->contents[5];
  EXPECT_EQ(last_msg_->contents[6], 68)
      << "incorrect value for contents[6], expected 68, is "
      << last_msg_->contents[6];
  EXPECT_EQ(last_msg_->contents[7], 229)
      << "incorrect value for contents[7], expected 229, is "
      << last_msg_->contents[7];
  EXPECT_EQ(last_msg_->contents[8], 216)
      << "incorrect value for contents[8], expected 216, is "
      << last_msg_->contents[8];
  EXPECT_EQ(last_msg_->contents[9], 21)
      << "incorrect value for contents[9], expected 21, is "
      << last_msg_->contents[9];
  EXPECT_EQ(last_msg_->contents[10], 98)
      << "incorrect value for contents[10], expected 98, is "
      << last_msg_->contents[10];
  EXPECT_EQ(last_msg_->contents[11], 183)
      << "incorrect value for contents[11], expected 183, is "
      << last_msg_->contents[11];
  EXPECT_EQ(last_msg_->contents[12], 69)
      << "incorrect value for contents[12], expected 69, is "
      << last_msg_->contents[12];
  EXPECT_EQ(last_msg_->contents[13], 190)
      << "incorrect value for contents[13], expected 190, is "
      << last_msg_->contents[13];
  EXPECT_EQ(last_msg_->contents[14], 5)
      << "incorrect value for contents[14], expected 5, is "
      << last_msg_->contents[14];
  EXPECT_EQ(last_msg_->contents[15], 252)
      << "incorrect value for contents[15], expected 252, is "
      << last_msg_->contents[15];
  EXPECT_EQ(last_msg_->contents[16], 176)
      << "incorrect value for contents[16], expected 176, is "
      << last_msg_->contents[16];
  EXPECT_EQ(last_msg_->contents[17], 55)
      << "incorrect value for contents[17], expected 55, is "
      << last_msg_->contents[17];
  EXPECT_EQ(last_msg_->contents[18], 32)
      << "incorrect value for contents[18], expected 32, is "
      << last_msg_->contents[18];
  EXPECT_EQ(last_msg_->contents[19], 78)
      << "incorrect value for contents[19], expected 78, is "
      << last_msg_->contents[19];
  EXPECT_EQ(last_msg_->contents[20], 8)
      << "incorrect value for contents[20], expected 8, is "
      << last_msg_->contents[20];
  EXPECT_EQ(last_msg_->contents[21], 52)
      << "incorrect value for contents[21], expected 52, is "
      << last_msg_->contents[21];
  EXPECT_EQ(last_msg_->contents[22], 127)
      << "incorrect value for contents[22], expected 127, is "
      << last_msg_->contents[22];
  EXPECT_EQ(last_msg_->contents[23], 50)
      << "incorrect value for contents[23], expected 50, is "
      << last_msg_->contents[23];
  EXPECT_EQ(last_msg_->contents[24], 71)
      << "incorrect value for contents[24], expected 71, is "
      << last_msg_->contents[24];
  EXPECT_EQ(last_msg_->contents[25], 106)
      << "incorrect value for contents[25], expected 106, is "
      << last_msg_->contents[25];
  EXPECT_EQ(last_msg_->contents[26], 61)
      << "incorrect value for contents[26], expected 61, is "
      << last_msg_->contents[26];
  EXPECT_EQ(last_msg_->contents[27], 79)
      << "incorrect value for contents[27], expected 79, is "
      << last_msg_->contents[27];
  EXPECT_EQ(last_msg_->contents[28], 191)
      << "incorrect value for contents[28], expected 191, is "
      << last_msg_->contents[28];
  EXPECT_EQ(last_msg_->contents[29], 106)
      << "incorrect value for contents[29], expected 106, is "
      << last_msg_->contents[29];
  EXPECT_EQ(last_msg_->contents[30], 46)
      << "incorrect value for contents[30], expected 46, is "
      << last_msg_->contents[30];
  EXPECT_EQ(last_msg_->contents[31], 79)
      << "incorrect value for contents[31], expected 79, is "
      << last_msg_->contents[31];
  EXPECT_EQ(last_msg_->contents[32], 118)
      << "incorrect value for contents[32], expected 118, is "
      << last_msg_->contents[32];
  EXPECT_EQ(last_msg_->contents[33], 248)
      << "incorrect value for contents[33], expected 248, is "
      << last_msg_->contents[33];
  EXPECT_EQ(last_msg_->contents[34], 118)
      << "incorrect value for contents[34], expected 118, is "
      << last_msg_->contents[34];
  EXPECT_EQ(last_msg_->contents[35], 207)
      << "incorrect value for contents[35], expected 207, is "
      << last_msg_->contents[35];
  EXPECT_EQ(last_msg_->contents[36], 206)
      << "incorrect value for contents[36], expected 206, is "
      << last_msg_->contents[36];
  EXPECT_EQ(last_msg_->contents[37], 210)
      << "incorrect value for contents[37], expected 210, is "
      << last_msg_->contents[37];
  EXPECT_EQ(last_msg_->contents[38], 91)
      << "incorrect value for contents[38], expected 91, is "
      << last_msg_->contents[38];
  EXPECT_EQ(last_msg_->contents[39], 73)
      << "incorrect value for contents[39], expected 73, is "
      << last_msg_->contents[39];
  EXPECT_EQ(last_msg_->contents[40], 251)
      << "incorrect value for contents[40], expected 251, is "
      << last_msg_->contents[40];
  EXPECT_EQ(last_msg_->contents[41], 81)
      << "incorrect value for contents[41], expected 81, is "
      << last_msg_->contents[41];
  EXPECT_EQ(last_msg_->contents[42], 131)
      << "incorrect value for contents[42], expected 131, is "
      << last_msg_->contents[42];
  EXPECT_EQ(last_msg_->contents[43], 205)
      << "incorrect value for contents[43], expected 205, is "
      << last_msg_->contents[43];
  EXPECT_EQ(last_msg_->contents[44], 193)
      << "incorrect value for contents[44], expected 193, is "
      << last_msg_->contents[44];
  EXPECT_EQ(last_msg_->contents[45], 146)
      << "incorrect value for contents[45], expected 146, is "
      << last_msg_->contents[45];
  EXPECT_EQ(last_msg_->contents[46], 206)
      << "incorrect value for contents[46], expected 206, is "
      << last_msg_->contents[46];
  EXPECT_EQ(last_msg_->contents[47], 185)
      << "incorrect value for contents[47], expected 185, is "
      << last_msg_->contents[47];
  EXPECT_EQ(last_msg_->contents[48], 140)
      << "incorrect value for contents[48], expected 140, is "
      << last_msg_->contents[48];
  EXPECT_EQ(last_msg_->contents[49], 249)
      << "incorrect value for contents[49], expected 249, is "
      << last_msg_->contents[49];
  EXPECT_EQ(last_msg_->contents[50], 163)
      << "incorrect value for contents[50], expected 163, is "
      << last_msg_->contents[50];
  EXPECT_EQ(last_msg_->contents[51], 231)
      << "incorrect value for contents[51], expected 231, is "
      << last_msg_->contents[51];
  EXPECT_EQ(last_msg_->contents[52], 65)
      << "incorrect value for contents[52], expected 65, is "
      << last_msg_->contents[52];
  EXPECT_EQ(last_msg_->contents[53], 67)
      << "incorrect value for contents[53], expected 67, is "
      << last_msg_->contents[53];
  EXPECT_EQ(last_msg_->contents[54], 94)
      << "incorrect value for contents[54], expected 94, is "
      << last_msg_->contents[54];
  EXPECT_EQ(last_msg_->contents[55], 250)
      << "incorrect value for contents[55], expected 250, is "
      << last_msg_->contents[55];
  EXPECT_EQ(last_msg_->contents[56], 109)
      << "incorrect value for contents[56], expected 109, is "
      << last_msg_->contents[56];
  EXPECT_EQ(last_msg_->contents[57], 152)
      << "incorrect value for contents[57], expected 152, is "
      << last_msg_->contents[57];
  EXPECT_EQ(last_msg_->contents[58], 95)
      << "incorrect value for contents[58], expected 95, is "
      << last_msg_->contents[58];
  EXPECT_EQ(last_msg_->contents[59], 123)
      << "incorrect value for contents[59], expected 123, is "
      << last_msg_->contents[59];
  EXPECT_EQ(last_msg_->contents[60], 77)
      << "incorrect value for contents[60], expected 77, is "
      << last_msg_->contents[60];
  EXPECT_EQ(last_msg_->contents[61], 224)
      << "incorrect value for contents[61], expected 224, is "
      << last_msg_->contents[61];
  EXPECT_EQ(last_msg_->contents[62], 124)
      << "incorrect value for contents[62], expected 124, is "
      << last_msg_->contents[62];
  EXPECT_EQ(last_msg_->contents[63], 238)
      << "incorrect value for contents[63], expected 238, is "
      << last_msg_->contents[63];
  EXPECT_EQ(last_msg_->contents[64], 205)
      << "incorrect value for contents[64], expected 205, is "
      << last_msg_->contents[64];
  EXPECT_EQ(last_msg_->contents[65], 65)
      << "incorrect value for contents[65], expected 65, is "
      << last_msg_->contents[65];
  EXPECT_EQ(last_msg_->contents[66], 103)
      << "incorrect value for contents[66], expected 103, is "
      << last_msg_->contents[66];
  EXPECT_EQ(last_msg_->contents[67], 35)
      << "incorrect value for contents[67], expected 35, is "
      << last_msg_->contents[67];
  EXPECT_EQ(last_msg_->contents[68], 104)
      << "incorrect value for contents[68], expected 104, is "
      << last_msg_->contents[68];
  EXPECT_EQ(last_msg_->contents[69], 209)
      << "incorrect value for contents[69], expected 209, is "
      << last_msg_->contents[69];
  EXPECT_EQ(last_msg_->contents[70], 5)
      << "incorrect value for contents[70], expected 5, is "
      << last_msg_->contents[70];
  EXPECT_EQ(last_msg_->contents[71], 191)
      << "incorrect value for contents[71], expected 191, is "
      << last_msg_->contents[71];
  EXPECT_EQ(last_msg_->contents[72], 47)
      << "incorrect value for contents[72], expected 47, is "
      << last_msg_->contents[72];
  EXPECT_EQ(last_msg_->contents[73], 249)
      << "incorrect value for contents[73], expected 249, is "
      << last_msg_->contents[73];
  EXPECT_EQ(last_msg_->contents[74], 176)
      << "incorrect value for contents[74], expected 176, is "
      << last_msg_->contents[74];
  EXPECT_EQ(last_msg_->contents[75], 166)
      << "incorrect value for contents[75], expected 166, is "
      << last_msg_->contents[75];
  EXPECT_EQ(last_msg_->contents[76], 213)
      << "incorrect value for contents[76], expected 213, is "
      << last_msg_->contents[76];
  EXPECT_EQ(last_msg_->contents[77], 46)
      << "incorrect value for contents[77], expected 46, is "
      << last_msg_->contents[77];
  EXPECT_EQ(last_msg_->contents[78], 192)
      << "incorrect value for contents[78], expected 192, is "
      << last_msg_->contents[78];
  EXPECT_EQ(last_msg_->contents[79], 86)
      << "incorrect value for contents[79], expected 86, is "
      << last_msg_->contents[79];
  EXPECT_EQ(last_msg_->contents[80], 32)
      << "incorrect value for contents[80], expected 32, is "
      << last_msg_->contents[80];
  EXPECT_EQ(last_msg_->contents[81], 103)
      << "incorrect value for contents[81], expected 103, is "
      << last_msg_->contents[81];
  EXPECT_EQ(last_msg_->contents[82], 146)
      << "incorrect value for contents[82], expected 146, is "
      << last_msg_->contents[82];
  EXPECT_EQ(last_msg_->contents[83], 252)
      << "incorrect value for contents[83], expected 252, is "
      << last_msg_->contents[83];
  EXPECT_EQ(last_msg_->contents[84], 4)
      << "incorrect value for contents[84], expected 4, is "
      << last_msg_->contents[84];
  EXPECT_EQ(last_msg_->contents[85], 16)
      << "incorrect value for contents[85], expected 16, is "
      << last_msg_->contents[85];
  EXPECT_EQ(last_msg_->contents[86], 54)
      << "incorrect value for contents[86], expected 54, is "
      << last_msg_->contents[86];
  EXPECT_EQ(last_msg_->contents[87], 161)
      << "incorrect value for contents[87], expected 161, is "
      << last_msg_->contents[87];
  EXPECT_EQ(last_msg_->contents[88], 60)
      << "incorrect value for contents[88], expected 60, is "
      << last_msg_->contents[88];
  EXPECT_EQ(last_msg_->contents[89], 6)
      << "incorrect value for contents[89], expected 6, is "
      << last_msg_->contents[89];
  EXPECT_EQ(last_msg_->contents[90], 13)
      << "incorrect value for contents[90], expected 13, is "
      << last_msg_->contents[90];
  EXPECT_EQ(last_msg_->contents[91], 191)
      << "incorrect value for contents[91], expected 191, is "
      << last_msg_->contents[91];
  EXPECT_EQ(last_msg_->contents[92], 116)
      << "incorrect value for contents[92], expected 116, is "
      << last_msg_->contents[92];
  EXPECT_EQ(last_msg_->contents[93], 182)
      << "incorrect value for contents[93], expected 182, is "
      << last_msg_->contents[93];
  EXPECT_EQ(last_msg_->contents[94], 42)
      << "incorrect value for contents[94], expected 42, is "
      << last_msg_->contents[94];
  EXPECT_EQ(last_msg_->contents[95], 191)
      << "incorrect value for contents[95], expected 191, is "
      << last_msg_->contents[95];
  EXPECT_EQ(last_msg_->contents[96], 213)
      << "incorrect value for contents[96], expected 213, is "
      << last_msg_->contents[96];
  EXPECT_EQ(last_msg_->contents[97], 20)
      << "incorrect value for contents[97], expected 20, is "
      << last_msg_->contents[97];
  EXPECT_EQ(last_msg_->contents[98], 217)
      << "incorrect value for contents[98], expected 217, is "
      << last_msg_->contents[98];
  EXPECT_EQ(last_msg_->contents[99], 8)
      << "incorrect value for contents[99], expected 8, is "
      << last_msg_->contents[99];
  EXPECT_EQ(last_msg_->contents[100], 142)
      << "incorrect value for contents[100], expected 142, is "
      << last_msg_->contents[100];
  EXPECT_EQ(last_msg_->contents[101], 187)
      << "incorrect value for contents[101], expected 187, is "
      << last_msg_->contents[101];
  EXPECT_EQ(last_msg_->contents[102], 238)
      << "incorrect value for contents[102], expected 238, is "
      << last_msg_->contents[102];
  EXPECT_EQ(last_msg_->contents[103], 120)
      << "incorrect value for contents[103], expected 120, is "
      << last_msg_->contents[103];
  EXPECT_EQ(last_msg_->contents[104], 184)
      << "incorrect value for contents[104], expected 184, is "
      << last_msg_->contents[104];
  EXPECT_EQ(last_msg_->contents[105], 250)
      << "incorrect value for contents[105], expected 250, is "
      << last_msg_->contents[105];
  EXPECT_EQ(last_msg_->contents[106], 31)
      << "incorrect value for contents[106], expected 31, is "
      << last_msg_->contents[106];
  EXPECT_EQ(last_msg_->contents[107], 151)
      << "incorrect value for contents[107], expected 151, is "
      << last_msg_->contents[107];
  EXPECT_EQ(last_msg_->contents[108], 37)
      << "incorrect value for contents[108], expected 37, is "
      << last_msg_->contents[108];
  EXPECT_EQ(last_msg_->contents[109], 51)
      << "incorrect value for contents[109], expected 51, is "
      << last_msg_->contents[109];
  EXPECT_EQ(last_msg_->contents[110], 177)
      << "incorrect value for contents[110], expected 177, is "
      << last_msg_->contents[110];
  EXPECT_EQ(last_msg_->contents[111], 130)
      << "incorrect value for contents[111], expected 130, is "
      << last_msg_->contents[111];
  EXPECT_EQ(last_msg_->contents[112], 190)
      << "incorrect value for contents[112], expected 190, is "
      << last_msg_->contents[112];
  EXPECT_EQ(last_msg_->contents[113], 155)
      << "incorrect value for contents[113], expected 155, is "
      << last_msg_->contents[113];
  EXPECT_EQ(last_msg_->contents[114], 71)
      << "incorrect value for contents[114], expected 71, is "
      << last_msg_->contents[114];
  EXPECT_EQ(last_msg_->contents[115], 68)
      << "incorrect value for contents[115], expected 68, is "
      << last_msg_->contents[115];
  EXPECT_EQ(last_msg_->contents[116], 56)
      << "incorrect value for contents[116], expected 56, is "
      << last_msg_->contents[116];
  EXPECT_EQ(last_msg_->contents[117], 238)
      << "incorrect value for contents[117], expected 238, is "
      << last_msg_->contents[117];
  EXPECT_EQ(last_msg_->contents[118], 92)
      << "incorrect value for contents[118], expected 92, is "
      << last_msg_->contents[118];
  EXPECT_EQ(last_msg_->contents[119], 130)
      << "incorrect value for contents[119], expected 130, is "
      << last_msg_->contents[119];
  EXPECT_EQ(last_msg_->contents[120], 37)
      << "incorrect value for contents[120], expected 37, is "
      << last_msg_->contents[120];
  EXPECT_EQ(last_msg_->contents[121], 137)
      << "incorrect value for contents[121], expected 137, is "
      << last_msg_->contents[121];
  EXPECT_EQ(last_msg_->contents[122], 146)
      << "incorrect value for contents[122], expected 146, is "
      << last_msg_->contents[122];
  EXPECT_EQ(last_msg_->contents[123], 246)
      << "incorrect value for contents[123], expected 246, is "
      << last_msg_->contents[123];
  EXPECT_EQ(last_msg_->contents[124], 114)
      << "incorrect value for contents[124], expected 114, is "
      << last_msg_->contents[124];
  EXPECT_EQ(last_msg_->contents[125], 116)
      << "incorrect value for contents[125], expected 116, is "
      << last_msg_->contents[125];
  EXPECT_EQ(last_msg_->contents[126], 138)
      << "incorrect value for contents[126], expected 138, is "
      << last_msg_->contents[126];
  EXPECT_EQ(last_msg_->contents[127], 165)
      << "incorrect value for contents[127], expected 165, is "
      << last_msg_->contents[127];
  EXPECT_EQ(last_msg_->contents[128], 217)
      << "incorrect value for contents[128], expected 217, is "
      << last_msg_->contents[128];
  EXPECT_EQ(last_msg_->contents[129], 79)
      << "incorrect value for contents[129], expected 79, is "
      << last_msg_->contents[129];
  EXPECT_EQ(last_msg_->contents[130], 10)
      << "incorrect value for contents[130], expected 10, is "
      << last_msg_->contents[130];
  EXPECT_EQ(last_msg_->contents[131], 189)
      << "incorrect value for contents[131], expected 189, is "
      << last_msg_->contents[131];
  EXPECT_EQ(last_msg_->contents[132], 128)
      << "incorrect value for contents[132], expected 128, is "
      << last_msg_->contents[132];
  EXPECT_EQ(last_msg_->contents[133], 189)
      << "incorrect value for contents[133], expected 189, is "
      << last_msg_->contents[133];
  EXPECT_EQ(last_msg_->contents[134], 2)
      << "incorrect value for contents[134], expected 2, is "
      << last_msg_->contents[134];
  EXPECT_EQ(last_msg_->contents[135], 240)
      << "incorrect value for contents[135], expected 240, is "
      << last_msg_->contents[135];
  EXPECT_EQ(last_msg_->contents[136], 92)
      << "incorrect value for contents[136], expected 92, is "
      << last_msg_->contents[136];
  EXPECT_EQ(last_msg_->contents[137], 28)
      << "incorrect value for contents[137], expected 28, is "
      << last_msg_->contents[137];
  EXPECT_EQ(last_msg_->contents[138], 126)
      << "incorrect value for contents[138], expected 126, is "
      << last_msg_->contents[138];
  EXPECT_EQ(last_msg_->contents[139], 105)
      << "incorrect value for contents[139], expected 105, is "
      << last_msg_->contents[139];
  EXPECT_EQ(last_msg_->contents[140], 236)
      << "incorrect value for contents[140], expected 236, is "
      << last_msg_->contents[140];
  EXPECT_EQ(last_msg_->contents[141], 228)
      << "incorrect value for contents[141], expected 228, is "
      << last_msg_->contents[141];
  EXPECT_EQ(last_msg_->contents[142], 194)
      << "incorrect value for contents[142], expected 194, is "
      << last_msg_->contents[142];
  EXPECT_EQ(last_msg_->contents[143], 0)
      << "incorrect value for contents[143], expected 0, is "
      << last_msg_->contents[143];
  EXPECT_EQ(last_msg_->contents[144], 51)
      << "incorrect value for contents[144], expected 51, is "
      << last_msg_->contents[144];
  EXPECT_EQ(last_msg_->contents[145], 61)
      << "incorrect value for contents[145], expected 61, is "
      << last_msg_->contents[145];
  EXPECT_EQ(last_msg_->contents[146], 74)
      << "incorrect value for contents[146], expected 74, is "
      << last_msg_->contents[146];
  EXPECT_EQ(last_msg_->contents[147], 41)
      << "incorrect value for contents[147], expected 41, is "
      << last_msg_->contents[147];
  EXPECT_EQ(last_msg_->contents[148], 10)
      << "incorrect value for contents[148], expected 10, is "
      << last_msg_->contents[148];
  EXPECT_EQ(last_msg_->contents[149], 239)
      << "incorrect value for contents[149], expected 239, is "
      << last_msg_->contents[149];
  EXPECT_EQ(last_msg_->contents[150], 133)
      << "incorrect value for contents[150], expected 133, is "
      << last_msg_->contents[150];
  EXPECT_EQ(last_msg_->contents[151], 106)
      << "incorrect value for contents[151], expected 106, is "
      << last_msg_->contents[151];
  EXPECT_EQ(last_msg_->contents[152], 190)
      << "incorrect value for contents[152], expected 190, is "
      << last_msg_->contents[152];
  EXPECT_EQ(last_msg_->contents[153], 30)
      << "incorrect value for contents[153], expected 30, is "
      << last_msg_->contents[153];
  EXPECT_EQ(last_msg_->contents[154], 27)
      << "incorrect value for contents[154], expected 27, is "
      << last_msg_->contents[154];
  EXPECT_EQ(last_msg_->contents[155], 3)
      << "incorrect value for contents[155], expected 3, is "
      << last_msg_->contents[155];
  EXPECT_EQ(last_msg_->contents[156], 240)
      << "incorrect value for contents[156], expected 240, is "
      << last_msg_->contents[156];
  EXPECT_EQ(last_msg_->contents[157], 205)
      << "incorrect value for contents[157], expected 205, is "
      << last_msg_->contents[157];
  EXPECT_EQ(last_msg_->contents[158], 253)
      << "incorrect value for contents[158], expected 253, is "
      << last_msg_->contents[158];
  EXPECT_EQ(last_msg_->contents[159], 113)
      << "incorrect value for contents[159], expected 113, is "
      << last_msg_->contents[159];
  EXPECT_EQ(last_msg_->contents[160], 25)
      << "incorrect value for contents[160], expected 25, is "
      << last_msg_->contents[160];
  EXPECT_EQ(last_msg_->contents[161], 28)
      << "incorrect value for contents[161], expected 28, is "
      << last_msg_->contents[161];
  EXPECT_EQ(last_msg_->contents[162], 187)
      << "incorrect value for contents[162], expected 187, is "
      << last_msg_->contents[162];
  EXPECT_EQ(last_msg_->contents[163], 81)
      << "incorrect value for contents[163], expected 81, is "
      << last_msg_->contents[163];
  EXPECT_EQ(last_msg_->contents[164], 101)
      << "incorrect value for contents[164], expected 101, is "
      << last_msg_->contents[164];
  EXPECT_EQ(last_msg_->contents[165], 216)
      << "incorrect value for contents[165], expected 216, is "
      << last_msg_->contents[165];
  EXPECT_EQ(last_msg_->contents[166], 121)
      << "incorrect value for contents[166], expected 121, is "
      << last_msg_->contents[166];
  EXPECT_EQ(last_msg_->contents[167], 41)
      << "incorrect value for contents[167], expected 41, is "
      << last_msg_->contents[167];
  EXPECT_EQ(last_msg_->contents[168], 179)
      << "incorrect value for contents[168], expected 179, is "
      << last_msg_->contents[168];
  EXPECT_EQ(last_msg_->contents[169], 120)
      << "incorrect value for contents[169], expected 120, is "
      << last_msg_->contents[169];
  EXPECT_EQ(last_msg_->contents[170], 152)
      << "incorrect value for contents[170], expected 152, is "
      << last_msg_->contents[170];
  EXPECT_EQ(last_msg_->contents[171], 18)
      << "incorrect value for contents[171], expected 18, is "
      << last_msg_->contents[171];
  EXPECT_EQ(last_msg_->contents[172], 116)
      << "incorrect value for contents[172], expected 116, is "
      << last_msg_->contents[172];
  EXPECT_EQ(last_msg_->contents[173], 53)
      << "incorrect value for contents[173], expected 53, is "
      << last_msg_->contents[173];
  EXPECT_EQ(last_msg_->contents[174], 212)
      << "incorrect value for contents[174], expected 212, is "
      << last_msg_->contents[174];
  EXPECT_EQ(last_msg_->contents[175], 100)
      << "incorrect value for contents[175], expected 100, is "
      << last_msg_->contents[175];
  EXPECT_EQ(last_msg_->contents[176], 2)
      << "incorrect value for contents[176], expected 2, is "
      << last_msg_->contents[176];
  EXPECT_EQ(last_msg_->contents[177], 114)
      << "incorrect value for contents[177], expected 114, is "
      << last_msg_->contents[177];
  EXPECT_EQ(last_msg_->contents[178], 198)
      << "incorrect value for contents[178], expected 198, is "
      << last_msg_->contents[178];
  EXPECT_EQ(last_msg_->contents[179], 200)
      << "incorrect value for contents[179], expected 200, is "
      << last_msg_->contents[179];
  EXPECT_EQ(last_msg_->contents[180], 10)
      << "incorrect value for contents[180], expected 10, is "
      << last_msg_->contents[180];
  EXPECT_EQ(last_msg_->contents[181], 147)
      << "incorrect value for contents[181], expected 147, is "
      << last_msg_->contents[181];
  EXPECT_EQ(last_msg_->contents[182], 25)
      << "incorrect value for contents[182], expected 25, is "
      << last_msg_->contents[182];
  EXPECT_EQ(last_msg_->contents[183], 33)
      << "incorrect value for contents[183], expected 33, is "
      << last_msg_->contents[183];
  EXPECT_EQ(last_msg_->contents[184], 115)
      << "incorrect value for contents[184], expected 115, is "
      << last_msg_->contents[184];
  EXPECT_EQ(last_msg_->contents[185], 208)
      << "incorrect value for contents[185], expected 208, is "
      << last_msg_->contents[185];
  EXPECT_EQ(last_msg_->contents[186], 113)
      << "incorrect value for contents[186], expected 113, is "
      << last_msg_->contents[186];
  EXPECT_EQ(last_msg_->contents[187], 60)
      << "incorrect value for contents[187], expected 60, is "
      << last_msg_->contents[187];
  EXPECT_EQ(last_msg_->contents[188], 179)
      << "incorrect value for contents[188], expected 179, is "
      << last_msg_->contents[188];
  EXPECT_EQ(last_msg_->contents[189], 183)
      << "incorrect value for contents[189], expected 183, is "
      << last_msg_->contents[189];
  EXPECT_EQ(last_msg_->contents[190], 0)
      << "incorrect value for contents[190], expected 0, is "
      << last_msg_->contents[190];
  EXPECT_EQ(last_msg_->contents[191], 41)
      << "incorrect value for contents[191], expected 41, is "
      << last_msg_->contents[191];
  EXPECT_EQ(last_msg_->contents[192], 217)
      << "incorrect value for contents[192], expected 217, is "
      << last_msg_->contents[192];
  EXPECT_EQ(last_msg_->contents[193], 206)
      << "incorrect value for contents[193], expected 206, is "
      << last_msg_->contents[193];
  EXPECT_EQ(last_msg_->contents[194], 255)
      << "incorrect value for contents[194], expected 255, is "
      << last_msg_->contents[194];
  EXPECT_EQ(last_msg_->contents[195], 211)
      << "incorrect value for contents[195], expected 211, is "
      << last_msg_->contents[195];
  EXPECT_EQ(last_msg_->contents[196], 225)
      << "incorrect value for contents[196], expected 225, is "
      << last_msg_->contents[196];
  EXPECT_EQ(last_msg_->contents[197], 142)
      << "incorrect value for contents[197], expected 142, is "
      << last_msg_->contents[197];
  EXPECT_EQ(last_msg_->contents[198], 191)
      << "incorrect value for contents[198], expected 191, is "
      << last_msg_->contents[198];
  EXPECT_EQ(last_msg_->contents[199], 133)
      << "incorrect value for contents[199], expected 133, is "
      << last_msg_->contents[199];
  EXPECT_EQ(last_msg_->contents[200], 81)
      << "incorrect value for contents[200], expected 81, is "
      << last_msg_->contents[200];
  EXPECT_EQ(last_msg_->contents[201], 15)
      << "incorrect value for contents[201], expected 15, is "
      << last_msg_->contents[201];
  EXPECT_EQ(last_msg_->contents[202], 248)
      << "incorrect value for contents[202], expected 248, is "
      << last_msg_->contents[202];
  EXPECT_EQ(last_msg_->contents[203], 193)
      << "incorrect value for contents[203], expected 193, is "
      << last_msg_->contents[203];
  EXPECT_EQ(last_msg_->contents[204], 66)
      << "incorrect value for contents[204], expected 66, is "
      << last_msg_->contents[204];
  EXPECT_EQ(last_msg_->contents[205], 191)
      << "incorrect value for contents[205], expected 191, is "
      << last_msg_->contents[205];
  EXPECT_EQ(last_msg_->contents[206], 244)
      << "incorrect value for contents[206], expected 244, is "
      << last_msg_->contents[206];
  EXPECT_EQ(last_msg_->contents[207], 221)
      << "incorrect value for contents[207], expected 221, is "
      << last_msg_->contents[207];
  EXPECT_EQ(last_msg_->contents[208], 248)
      << "incorrect value for contents[208], expected 248, is "
      << last_msg_->contents[208];
  EXPECT_EQ(last_msg_->contents[209], 199)
      << "incorrect value for contents[209], expected 199, is "
      << last_msg_->contents[209];
  EXPECT_EQ(last_msg_->contents[210], 241)
      << "incorrect value for contents[210], expected 241, is "
      << last_msg_->contents[210];
  EXPECT_EQ(last_msg_->contents[211], 112)
      << "incorrect value for contents[211], expected 112, is "
      << last_msg_->contents[211];
  EXPECT_EQ(last_msg_->contents[212], 51)
      << "incorrect value for contents[212], expected 51, is "
      << last_msg_->contents[212];
  EXPECT_EQ(last_msg_->contents[213], 1)
      << "incorrect value for contents[213], expected 1, is "
      << last_msg_->contents[213];
  EXPECT_EQ(last_msg_->contents[214], 180)
      << "incorrect value for contents[214], expected 180, is "
      << last_msg_->contents[214];
  EXPECT_EQ(last_msg_->contents[215], 180)
      << "incorrect value for contents[215], expected 180, is "
      << last_msg_->contents[215];
  EXPECT_EQ(last_msg_->contents[216], 125)
      << "incorrect value for contents[216], expected 125, is "
      << last_msg_->contents[216];
  EXPECT_EQ(last_msg_->contents[217], 97)
      << "incorrect value for contents[217], expected 97, is "
      << last_msg_->contents[217];
  EXPECT_EQ(last_msg_->contents[218], 145)
      << "incorrect value for contents[218], expected 145, is "
      << last_msg_->contents[218];
  EXPECT_EQ(last_msg_->contents[219], 25)
      << "incorrect value for contents[219], expected 25, is "
      << last_msg_->contents[219];
  EXPECT_EQ(last_msg_->contents[220], 72)
      << "incorrect value for contents[220], expected 72, is "
      << last_msg_->contents[220];
  EXPECT_EQ(last_msg_->contents[221], 210)
      << "incorrect value for contents[221], expected 210, is "
      << last_msg_->contents[221];
  EXPECT_EQ(last_msg_->contents[222], 215)
      << "incorrect value for contents[222], expected 215, is "
      << last_msg_->contents[222];
  EXPECT_EQ(last_msg_->contents[223], 208)
      << "incorrect value for contents[223], expected 208, is "
      << last_msg_->contents[223];
  EXPECT_EQ(last_msg_->contents[224], 15)
      << "incorrect value for contents[224], expected 15, is "
      << last_msg_->contents[224];
  EXPECT_EQ(last_msg_->contents[225], 126)
      << "incorrect value for contents[225], expected 126, is "
      << last_msg_->contents[225];
  EXPECT_EQ(last_msg_->contents[226], 56)
      << "incorrect value for contents[226], expected 56, is "
      << last_msg_->contents[226];
  EXPECT_EQ(last_msg_->contents[227], 38)
      << "incorrect value for contents[227], expected 38, is "
      << last_msg_->contents[227];
  EXPECT_EQ(last_msg_->contents[228], 65)
      << "incorrect value for contents[228], expected 65, is "
      << last_msg_->contents[228];
  EXPECT_EQ(last_msg_->contents[229], 4)
      << "incorrect value for contents[229], expected 4, is "
      << last_msg_->contents[229];
  EXPECT_EQ(last_msg_->contents[230], 64)
      << "incorrect value for contents[230], expected 64, is "
      << last_msg_->contents[230];
  EXPECT_EQ(last_msg_->contents[231], 19)
      << "incorrect value for contents[231], expected 19, is "
      << last_msg_->contents[231];
  EXPECT_EQ(last_msg_->contents[232], 74)
      << "incorrect value for contents[232], expected 74, is "
      << last_msg_->contents[232];
  EXPECT_EQ(last_msg_->contents[233], 223)
      << "incorrect value for contents[233], expected 223, is "
      << last_msg_->contents[233];
  EXPECT_EQ(last_msg_->contents[234], 111)
      << "incorrect value for contents[234], expected 111, is "
      << last_msg_->contents[234];
  EXPECT_EQ(last_msg_->contents[235], 109)
      << "incorrect value for contents[235], expected 109, is "
      << last_msg_->contents[235];
  EXPECT_EQ(last_msg_->contents[236], 52)
      << "incorrect value for contents[236], expected 52, is "
      << last_msg_->contents[236];
  EXPECT_EQ(last_msg_->contents[237], 43)
      << "incorrect value for contents[237], expected 43, is "
      << last_msg_->contents[237];
  EXPECT_EQ(last_msg_->contents[238], 167)
      << "incorrect value for contents[238], expected 167, is "
      << last_msg_->contents[238];
  EXPECT_EQ(last_msg_->contents[239], 186)
      << "incorrect value for contents[239], expected 186, is "
      << last_msg_->contents[239];
  EXPECT_EQ(last_msg_->contents[240], 202)
      << "incorrect value for contents[240], expected 202, is "
      << last_msg_->contents[240];
  EXPECT_EQ(last_msg_->contents[241], 111)
      << "incorrect value for contents[241], expected 111, is "
      << last_msg_->contents[241];
  EXPECT_EQ(last_msg_->contents[242], 11)
      << "incorrect value for contents[242], expected 11, is "
      << last_msg_->contents[242];
  EXPECT_EQ(last_msg_->contents[243], 91)
      << "incorrect value for contents[243], expected 91, is "
      << last_msg_->contents[243];
  EXPECT_EQ(last_msg_->contents[244], 21)
      << "incorrect value for contents[244], expected 21, is "
      << last_msg_->contents[244];
  EXPECT_EQ(last_msg_->contents[245], 236)
      << "incorrect value for contents[245], expected 236, is "
      << last_msg_->contents[245];
  EXPECT_EQ(last_msg_->contents[246], 234)
      << "incorrect value for contents[246], expected 234, is "
      << last_msg_->contents[246];
  EXPECT_EQ(last_msg_->contents[247], 196)
      << "incorrect value for contents[247], expected 196, is "
      << last_msg_->contents[247];
  EXPECT_EQ(last_msg_->contents[248], 36)
      << "incorrect value for contents[248], expected 36, is "
      << last_msg_->contents[248];
  EXPECT_EQ(last_msg_->contents[249], 171)
      << "incorrect value for contents[249], expected 171, is "
      << last_msg_->contents[249];
  EXPECT_EQ(last_msg_->contents[250], 147)
      << "incorrect value for contents[250], expected 147, is "
      << last_msg_->contents[250];
  EXPECT_EQ(last_msg_->sequence, 259241795)
      << "incorrect value for sequence, expected 259241795, is "
      << last_msg_->sequence;
}
