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
// spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashProgram.yaml by generate.py.
// Do not modify by hand!

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
#include <libsbp/legacy/flash.h>
class Test_legacy_auto_check_sbp_flash_MsgFlashProgram0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_flash_program_t> {
 public:
  Test_legacy_auto_check_sbp_flash_MsgFlashProgram0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_flash_program_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_flash_program_t *>(last_msg_storage_)),
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
                      const msg_flash_program_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_flash_program_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_flash_MsgFlashProgram0, Test) {
  uint8_t encoded_frame[] = {
      85,  230, 0,   195, 4,   255, 212, 87,  52,  244, 250, 176, 222, 235, 106,
      144, 29,  141, 255, 3,   16,  192, 237, 172, 254, 213, 4,   220, 98,  34,
      222, 230, 214, 6,   217, 172, 122, 46,  13,  38,  240, 236, 60,  121, 47,
      252, 163, 141, 222, 29,  168, 214, 118, 55,  201, 233, 21,  214, 57,  245,
      246, 19,  3,   121, 49,  231, 37,  186, 58,  238, 98,  39,  70,  232, 133,
      25,  10,  134, 129, 69,  228, 134, 9,   88,  183, 133, 171, 255, 166, 100,
      152, 231, 92,  9,   196, 106, 246, 29,  145, 156, 151, 32,  67,  188, 63,
      233, 142, 174, 139, 154, 127, 35,  60,  56,  187, 121, 103, 135, 152, 182,
      88,  160, 255, 227, 240, 54,  100, 91,  31,  141, 102, 130, 254, 54,  227,
      229, 62,  53,  225, 143, 88,  139, 126, 235, 235, 35,  54,  134, 163, 92,
      57,  87,  130, 178, 22,  158, 18,  237, 209, 187, 226, 1,   46,  64,  226,
      235, 213, 186, 159, 221, 186, 25,  115, 84,  131, 167, 201, 104, 1,   200,
      13,  50,  71,  73,  193, 201, 250, 172, 193, 13,  20,  238, 130, 243, 68,
      4,   72,  46,  194, 113, 255, 238, 15,  230, 64,  178, 127, 217, 92,  160,
      201, 118, 163, 144, 58,  28,  174, 65,  73,  45,  123, 118, 83,  107, 239,
      168, 32,  212, 191, 81,  93,  186, 223, 32,  19,  58,  137, 72,  217, 151,
      251, 83,  20,  113, 37,  151, 34,  37,  71,  95,  105, 235, 144, 164, 83,
      197, 254, 183, 223, 91,  19,  45,  227,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_flash_program_t *test_msg = (msg_flash_program_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->addr_len = 250;
  if (sizeof(test_msg->addr_start) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->addr_start[0]));
  }
  test_msg->addr_start[0] = 87;
  if (sizeof(test_msg->addr_start) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->addr_start[0]));
  }
  test_msg->addr_start[1] = 52;
  if (sizeof(test_msg->addr_start) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->addr_start[0]));
  }
  test_msg->addr_start[2] = 244;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[0] = 176;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[1] = 222;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[2] = 235;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[3] = 106;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[4] = 144;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[5] = 29;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[6] = 141;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[7] = 255;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[8] = 3;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[9] = 16;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[10] = 192;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[11] = 237;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[12] = 172;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[13] = 254;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[14] = 213;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[15] = 4;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[16] = 220;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[17] = 98;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[18] = 34;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[19] = 222;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[20] = 230;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[21] = 214;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[22] = 6;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[23] = 217;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[24] = 172;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[25] = 122;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[26] = 46;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[27] = 13;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[28] = 38;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[29] = 240;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[30] = 236;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[31] = 60;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[32] = 121;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[33] = 47;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[34] = 252;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[35] = 163;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[36] = 141;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[37] = 222;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[38] = 29;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[39] = 168;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[40] = 214;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[41] = 118;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[42] = 55;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[43] = 201;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[44] = 233;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[45] = 21;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[46] = 214;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[47] = 57;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[48] = 245;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[49] = 246;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[50] = 19;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[51] = 3;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[52] = 121;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[53] = 49;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[54] = 231;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[55] = 37;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[56] = 186;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[57] = 58;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[58] = 238;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[59] = 98;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[60] = 39;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[61] = 70;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[62] = 232;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[63] = 133;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[64] = 25;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[65] = 10;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[66] = 134;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[67] = 129;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[68] = 69;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[69] = 228;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[70] = 134;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[71] = 9;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[72] = 88;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[73] = 183;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[74] = 133;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[75] = 171;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[76] = 255;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[77] = 166;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[78] = 100;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[79] = 152;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[80] = 231;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[81] = 92;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[82] = 9;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[83] = 196;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[84] = 106;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[85] = 246;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[86] = 29;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[87] = 145;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[88] = 156;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[89] = 151;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[90] = 32;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[91] = 67;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[92] = 188;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[93] = 63;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[94] = 233;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[95] = 142;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[96] = 174;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[97] = 139;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[98] = 154;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[99] = 127;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[100] = 35;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[101] = 60;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[102] = 56;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[103] = 187;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[104] = 121;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[105] = 103;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[106] = 135;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[107] = 152;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[108] = 182;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[109] = 88;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[110] = 160;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[111] = 255;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[112] = 227;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[113] = 240;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[114] = 54;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[115] = 100;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[116] = 91;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[117] = 31;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[118] = 141;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[119] = 102;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[120] = 130;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[121] = 254;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[122] = 54;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[123] = 227;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[124] = 229;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[125] = 62;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[126] = 53;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[127] = 225;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[128] = 143;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[129] = 88;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[130] = 139;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[131] = 126;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[132] = 235;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[133] = 235;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[134] = 35;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[135] = 54;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[136] = 134;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[137] = 163;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[138] = 92;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[139] = 57;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[140] = 87;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[141] = 130;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[142] = 178;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[143] = 22;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[144] = 158;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[145] = 18;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[146] = 237;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[147] = 209;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[148] = 187;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[149] = 226;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[150] = 1;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[151] = 46;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[152] = 64;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[153] = 226;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[154] = 235;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[155] = 213;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[156] = 186;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[157] = 159;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[158] = 221;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[159] = 186;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[160] = 25;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[161] = 115;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[162] = 84;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[163] = 131;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[164] = 167;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[165] = 201;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[166] = 104;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[167] = 1;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[168] = 200;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[169] = 13;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[170] = 50;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[171] = 71;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[172] = 73;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[173] = 193;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[174] = 201;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[175] = 250;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[176] = 172;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[177] = 193;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[178] = 13;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[179] = 20;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[180] = 238;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[181] = 130;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[182] = 243;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[183] = 68;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[184] = 4;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[185] = 72;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[186] = 46;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[187] = 194;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[188] = 113;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[189] = 255;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[190] = 238;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[191] = 15;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[192] = 230;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[193] = 64;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[194] = 178;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[195] = 127;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[196] = 217;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[197] = 92;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[198] = 160;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[199] = 201;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[200] = 118;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[201] = 163;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[202] = 144;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[203] = 58;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[204] = 28;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[205] = 174;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[206] = 65;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[207] = 73;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[208] = 45;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[209] = 123;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[210] = 118;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[211] = 83;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[212] = 107;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[213] = 239;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[214] = 168;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[215] = 32;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[216] = 212;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[217] = 191;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[218] = 81;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[219] = 93;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[220] = 186;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[221] = 223;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[222] = 32;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[223] = 19;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[224] = 58;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[225] = 137;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[226] = 72;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[227] = 217;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[228] = 151;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[229] = 251;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[230] = 83;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[231] = 20;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[232] = 113;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[233] = 37;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[234] = 151;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[235] = 34;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[236] = 37;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[237] = 71;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[238] = 95;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[239] = 105;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[240] = 235;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[241] = 144;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[242] = 164;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[243] = 83;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[244] = 197;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[245] = 254;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[246] = 183;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[247] = 223;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[248] = 91;
  if (sizeof(test_msg->data) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->data[0]));
  }
  test_msg->data[249] = 19;
  test_msg->target = 212;

  EXPECT_EQ(send_message(0xe6, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->addr_len, 250)
      << "incorrect value for addr_len, expected 250, is "
      << last_msg_->addr_len;
  EXPECT_EQ(last_msg_->addr_start[0], 87)
      << "incorrect value for addr_start[0], expected 87, is "
      << last_msg_->addr_start[0];
  EXPECT_EQ(last_msg_->addr_start[1], 52)
      << "incorrect value for addr_start[1], expected 52, is "
      << last_msg_->addr_start[1];
  EXPECT_EQ(last_msg_->addr_start[2], 244)
      << "incorrect value for addr_start[2], expected 244, is "
      << last_msg_->addr_start[2];
  EXPECT_EQ(last_msg_->data[0], 176)
      << "incorrect value for data[0], expected 176, is " << last_msg_->data[0];
  EXPECT_EQ(last_msg_->data[1], 222)
      << "incorrect value for data[1], expected 222, is " << last_msg_->data[1];
  EXPECT_EQ(last_msg_->data[2], 235)
      << "incorrect value for data[2], expected 235, is " << last_msg_->data[2];
  EXPECT_EQ(last_msg_->data[3], 106)
      << "incorrect value for data[3], expected 106, is " << last_msg_->data[3];
  EXPECT_EQ(last_msg_->data[4], 144)
      << "incorrect value for data[4], expected 144, is " << last_msg_->data[4];
  EXPECT_EQ(last_msg_->data[5], 29)
      << "incorrect value for data[5], expected 29, is " << last_msg_->data[5];
  EXPECT_EQ(last_msg_->data[6], 141)
      << "incorrect value for data[6], expected 141, is " << last_msg_->data[6];
  EXPECT_EQ(last_msg_->data[7], 255)
      << "incorrect value for data[7], expected 255, is " << last_msg_->data[7];
  EXPECT_EQ(last_msg_->data[8], 3)
      << "incorrect value for data[8], expected 3, is " << last_msg_->data[8];
  EXPECT_EQ(last_msg_->data[9], 16)
      << "incorrect value for data[9], expected 16, is " << last_msg_->data[9];
  EXPECT_EQ(last_msg_->data[10], 192)
      << "incorrect value for data[10], expected 192, is "
      << last_msg_->data[10];
  EXPECT_EQ(last_msg_->data[11], 237)
      << "incorrect value for data[11], expected 237, is "
      << last_msg_->data[11];
  EXPECT_EQ(last_msg_->data[12], 172)
      << "incorrect value for data[12], expected 172, is "
      << last_msg_->data[12];
  EXPECT_EQ(last_msg_->data[13], 254)
      << "incorrect value for data[13], expected 254, is "
      << last_msg_->data[13];
  EXPECT_EQ(last_msg_->data[14], 213)
      << "incorrect value for data[14], expected 213, is "
      << last_msg_->data[14];
  EXPECT_EQ(last_msg_->data[15], 4)
      << "incorrect value for data[15], expected 4, is " << last_msg_->data[15];
  EXPECT_EQ(last_msg_->data[16], 220)
      << "incorrect value for data[16], expected 220, is "
      << last_msg_->data[16];
  EXPECT_EQ(last_msg_->data[17], 98)
      << "incorrect value for data[17], expected 98, is "
      << last_msg_->data[17];
  EXPECT_EQ(last_msg_->data[18], 34)
      << "incorrect value for data[18], expected 34, is "
      << last_msg_->data[18];
  EXPECT_EQ(last_msg_->data[19], 222)
      << "incorrect value for data[19], expected 222, is "
      << last_msg_->data[19];
  EXPECT_EQ(last_msg_->data[20], 230)
      << "incorrect value for data[20], expected 230, is "
      << last_msg_->data[20];
  EXPECT_EQ(last_msg_->data[21], 214)
      << "incorrect value for data[21], expected 214, is "
      << last_msg_->data[21];
  EXPECT_EQ(last_msg_->data[22], 6)
      << "incorrect value for data[22], expected 6, is " << last_msg_->data[22];
  EXPECT_EQ(last_msg_->data[23], 217)
      << "incorrect value for data[23], expected 217, is "
      << last_msg_->data[23];
  EXPECT_EQ(last_msg_->data[24], 172)
      << "incorrect value for data[24], expected 172, is "
      << last_msg_->data[24];
  EXPECT_EQ(last_msg_->data[25], 122)
      << "incorrect value for data[25], expected 122, is "
      << last_msg_->data[25];
  EXPECT_EQ(last_msg_->data[26], 46)
      << "incorrect value for data[26], expected 46, is "
      << last_msg_->data[26];
  EXPECT_EQ(last_msg_->data[27], 13)
      << "incorrect value for data[27], expected 13, is "
      << last_msg_->data[27];
  EXPECT_EQ(last_msg_->data[28], 38)
      << "incorrect value for data[28], expected 38, is "
      << last_msg_->data[28];
  EXPECT_EQ(last_msg_->data[29], 240)
      << "incorrect value for data[29], expected 240, is "
      << last_msg_->data[29];
  EXPECT_EQ(last_msg_->data[30], 236)
      << "incorrect value for data[30], expected 236, is "
      << last_msg_->data[30];
  EXPECT_EQ(last_msg_->data[31], 60)
      << "incorrect value for data[31], expected 60, is "
      << last_msg_->data[31];
  EXPECT_EQ(last_msg_->data[32], 121)
      << "incorrect value for data[32], expected 121, is "
      << last_msg_->data[32];
  EXPECT_EQ(last_msg_->data[33], 47)
      << "incorrect value for data[33], expected 47, is "
      << last_msg_->data[33];
  EXPECT_EQ(last_msg_->data[34], 252)
      << "incorrect value for data[34], expected 252, is "
      << last_msg_->data[34];
  EXPECT_EQ(last_msg_->data[35], 163)
      << "incorrect value for data[35], expected 163, is "
      << last_msg_->data[35];
  EXPECT_EQ(last_msg_->data[36], 141)
      << "incorrect value for data[36], expected 141, is "
      << last_msg_->data[36];
  EXPECT_EQ(last_msg_->data[37], 222)
      << "incorrect value for data[37], expected 222, is "
      << last_msg_->data[37];
  EXPECT_EQ(last_msg_->data[38], 29)
      << "incorrect value for data[38], expected 29, is "
      << last_msg_->data[38];
  EXPECT_EQ(last_msg_->data[39], 168)
      << "incorrect value for data[39], expected 168, is "
      << last_msg_->data[39];
  EXPECT_EQ(last_msg_->data[40], 214)
      << "incorrect value for data[40], expected 214, is "
      << last_msg_->data[40];
  EXPECT_EQ(last_msg_->data[41], 118)
      << "incorrect value for data[41], expected 118, is "
      << last_msg_->data[41];
  EXPECT_EQ(last_msg_->data[42], 55)
      << "incorrect value for data[42], expected 55, is "
      << last_msg_->data[42];
  EXPECT_EQ(last_msg_->data[43], 201)
      << "incorrect value for data[43], expected 201, is "
      << last_msg_->data[43];
  EXPECT_EQ(last_msg_->data[44], 233)
      << "incorrect value for data[44], expected 233, is "
      << last_msg_->data[44];
  EXPECT_EQ(last_msg_->data[45], 21)
      << "incorrect value for data[45], expected 21, is "
      << last_msg_->data[45];
  EXPECT_EQ(last_msg_->data[46], 214)
      << "incorrect value for data[46], expected 214, is "
      << last_msg_->data[46];
  EXPECT_EQ(last_msg_->data[47], 57)
      << "incorrect value for data[47], expected 57, is "
      << last_msg_->data[47];
  EXPECT_EQ(last_msg_->data[48], 245)
      << "incorrect value for data[48], expected 245, is "
      << last_msg_->data[48];
  EXPECT_EQ(last_msg_->data[49], 246)
      << "incorrect value for data[49], expected 246, is "
      << last_msg_->data[49];
  EXPECT_EQ(last_msg_->data[50], 19)
      << "incorrect value for data[50], expected 19, is "
      << last_msg_->data[50];
  EXPECT_EQ(last_msg_->data[51], 3)
      << "incorrect value for data[51], expected 3, is " << last_msg_->data[51];
  EXPECT_EQ(last_msg_->data[52], 121)
      << "incorrect value for data[52], expected 121, is "
      << last_msg_->data[52];
  EXPECT_EQ(last_msg_->data[53], 49)
      << "incorrect value for data[53], expected 49, is "
      << last_msg_->data[53];
  EXPECT_EQ(last_msg_->data[54], 231)
      << "incorrect value for data[54], expected 231, is "
      << last_msg_->data[54];
  EXPECT_EQ(last_msg_->data[55], 37)
      << "incorrect value for data[55], expected 37, is "
      << last_msg_->data[55];
  EXPECT_EQ(last_msg_->data[56], 186)
      << "incorrect value for data[56], expected 186, is "
      << last_msg_->data[56];
  EXPECT_EQ(last_msg_->data[57], 58)
      << "incorrect value for data[57], expected 58, is "
      << last_msg_->data[57];
  EXPECT_EQ(last_msg_->data[58], 238)
      << "incorrect value for data[58], expected 238, is "
      << last_msg_->data[58];
  EXPECT_EQ(last_msg_->data[59], 98)
      << "incorrect value for data[59], expected 98, is "
      << last_msg_->data[59];
  EXPECT_EQ(last_msg_->data[60], 39)
      << "incorrect value for data[60], expected 39, is "
      << last_msg_->data[60];
  EXPECT_EQ(last_msg_->data[61], 70)
      << "incorrect value for data[61], expected 70, is "
      << last_msg_->data[61];
  EXPECT_EQ(last_msg_->data[62], 232)
      << "incorrect value for data[62], expected 232, is "
      << last_msg_->data[62];
  EXPECT_EQ(last_msg_->data[63], 133)
      << "incorrect value for data[63], expected 133, is "
      << last_msg_->data[63];
  EXPECT_EQ(last_msg_->data[64], 25)
      << "incorrect value for data[64], expected 25, is "
      << last_msg_->data[64];
  EXPECT_EQ(last_msg_->data[65], 10)
      << "incorrect value for data[65], expected 10, is "
      << last_msg_->data[65];
  EXPECT_EQ(last_msg_->data[66], 134)
      << "incorrect value for data[66], expected 134, is "
      << last_msg_->data[66];
  EXPECT_EQ(last_msg_->data[67], 129)
      << "incorrect value for data[67], expected 129, is "
      << last_msg_->data[67];
  EXPECT_EQ(last_msg_->data[68], 69)
      << "incorrect value for data[68], expected 69, is "
      << last_msg_->data[68];
  EXPECT_EQ(last_msg_->data[69], 228)
      << "incorrect value for data[69], expected 228, is "
      << last_msg_->data[69];
  EXPECT_EQ(last_msg_->data[70], 134)
      << "incorrect value for data[70], expected 134, is "
      << last_msg_->data[70];
  EXPECT_EQ(last_msg_->data[71], 9)
      << "incorrect value for data[71], expected 9, is " << last_msg_->data[71];
  EXPECT_EQ(last_msg_->data[72], 88)
      << "incorrect value for data[72], expected 88, is "
      << last_msg_->data[72];
  EXPECT_EQ(last_msg_->data[73], 183)
      << "incorrect value for data[73], expected 183, is "
      << last_msg_->data[73];
  EXPECT_EQ(last_msg_->data[74], 133)
      << "incorrect value for data[74], expected 133, is "
      << last_msg_->data[74];
  EXPECT_EQ(last_msg_->data[75], 171)
      << "incorrect value for data[75], expected 171, is "
      << last_msg_->data[75];
  EXPECT_EQ(last_msg_->data[76], 255)
      << "incorrect value for data[76], expected 255, is "
      << last_msg_->data[76];
  EXPECT_EQ(last_msg_->data[77], 166)
      << "incorrect value for data[77], expected 166, is "
      << last_msg_->data[77];
  EXPECT_EQ(last_msg_->data[78], 100)
      << "incorrect value for data[78], expected 100, is "
      << last_msg_->data[78];
  EXPECT_EQ(last_msg_->data[79], 152)
      << "incorrect value for data[79], expected 152, is "
      << last_msg_->data[79];
  EXPECT_EQ(last_msg_->data[80], 231)
      << "incorrect value for data[80], expected 231, is "
      << last_msg_->data[80];
  EXPECT_EQ(last_msg_->data[81], 92)
      << "incorrect value for data[81], expected 92, is "
      << last_msg_->data[81];
  EXPECT_EQ(last_msg_->data[82], 9)
      << "incorrect value for data[82], expected 9, is " << last_msg_->data[82];
  EXPECT_EQ(last_msg_->data[83], 196)
      << "incorrect value for data[83], expected 196, is "
      << last_msg_->data[83];
  EXPECT_EQ(last_msg_->data[84], 106)
      << "incorrect value for data[84], expected 106, is "
      << last_msg_->data[84];
  EXPECT_EQ(last_msg_->data[85], 246)
      << "incorrect value for data[85], expected 246, is "
      << last_msg_->data[85];
  EXPECT_EQ(last_msg_->data[86], 29)
      << "incorrect value for data[86], expected 29, is "
      << last_msg_->data[86];
  EXPECT_EQ(last_msg_->data[87], 145)
      << "incorrect value for data[87], expected 145, is "
      << last_msg_->data[87];
  EXPECT_EQ(last_msg_->data[88], 156)
      << "incorrect value for data[88], expected 156, is "
      << last_msg_->data[88];
  EXPECT_EQ(last_msg_->data[89], 151)
      << "incorrect value for data[89], expected 151, is "
      << last_msg_->data[89];
  EXPECT_EQ(last_msg_->data[90], 32)
      << "incorrect value for data[90], expected 32, is "
      << last_msg_->data[90];
  EXPECT_EQ(last_msg_->data[91], 67)
      << "incorrect value for data[91], expected 67, is "
      << last_msg_->data[91];
  EXPECT_EQ(last_msg_->data[92], 188)
      << "incorrect value for data[92], expected 188, is "
      << last_msg_->data[92];
  EXPECT_EQ(last_msg_->data[93], 63)
      << "incorrect value for data[93], expected 63, is "
      << last_msg_->data[93];
  EXPECT_EQ(last_msg_->data[94], 233)
      << "incorrect value for data[94], expected 233, is "
      << last_msg_->data[94];
  EXPECT_EQ(last_msg_->data[95], 142)
      << "incorrect value for data[95], expected 142, is "
      << last_msg_->data[95];
  EXPECT_EQ(last_msg_->data[96], 174)
      << "incorrect value for data[96], expected 174, is "
      << last_msg_->data[96];
  EXPECT_EQ(last_msg_->data[97], 139)
      << "incorrect value for data[97], expected 139, is "
      << last_msg_->data[97];
  EXPECT_EQ(last_msg_->data[98], 154)
      << "incorrect value for data[98], expected 154, is "
      << last_msg_->data[98];
  EXPECT_EQ(last_msg_->data[99], 127)
      << "incorrect value for data[99], expected 127, is "
      << last_msg_->data[99];
  EXPECT_EQ(last_msg_->data[100], 35)
      << "incorrect value for data[100], expected 35, is "
      << last_msg_->data[100];
  EXPECT_EQ(last_msg_->data[101], 60)
      << "incorrect value for data[101], expected 60, is "
      << last_msg_->data[101];
  EXPECT_EQ(last_msg_->data[102], 56)
      << "incorrect value for data[102], expected 56, is "
      << last_msg_->data[102];
  EXPECT_EQ(last_msg_->data[103], 187)
      << "incorrect value for data[103], expected 187, is "
      << last_msg_->data[103];
  EXPECT_EQ(last_msg_->data[104], 121)
      << "incorrect value for data[104], expected 121, is "
      << last_msg_->data[104];
  EXPECT_EQ(last_msg_->data[105], 103)
      << "incorrect value for data[105], expected 103, is "
      << last_msg_->data[105];
  EXPECT_EQ(last_msg_->data[106], 135)
      << "incorrect value for data[106], expected 135, is "
      << last_msg_->data[106];
  EXPECT_EQ(last_msg_->data[107], 152)
      << "incorrect value for data[107], expected 152, is "
      << last_msg_->data[107];
  EXPECT_EQ(last_msg_->data[108], 182)
      << "incorrect value for data[108], expected 182, is "
      << last_msg_->data[108];
  EXPECT_EQ(last_msg_->data[109], 88)
      << "incorrect value for data[109], expected 88, is "
      << last_msg_->data[109];
  EXPECT_EQ(last_msg_->data[110], 160)
      << "incorrect value for data[110], expected 160, is "
      << last_msg_->data[110];
  EXPECT_EQ(last_msg_->data[111], 255)
      << "incorrect value for data[111], expected 255, is "
      << last_msg_->data[111];
  EXPECT_EQ(last_msg_->data[112], 227)
      << "incorrect value for data[112], expected 227, is "
      << last_msg_->data[112];
  EXPECT_EQ(last_msg_->data[113], 240)
      << "incorrect value for data[113], expected 240, is "
      << last_msg_->data[113];
  EXPECT_EQ(last_msg_->data[114], 54)
      << "incorrect value for data[114], expected 54, is "
      << last_msg_->data[114];
  EXPECT_EQ(last_msg_->data[115], 100)
      << "incorrect value for data[115], expected 100, is "
      << last_msg_->data[115];
  EXPECT_EQ(last_msg_->data[116], 91)
      << "incorrect value for data[116], expected 91, is "
      << last_msg_->data[116];
  EXPECT_EQ(last_msg_->data[117], 31)
      << "incorrect value for data[117], expected 31, is "
      << last_msg_->data[117];
  EXPECT_EQ(last_msg_->data[118], 141)
      << "incorrect value for data[118], expected 141, is "
      << last_msg_->data[118];
  EXPECT_EQ(last_msg_->data[119], 102)
      << "incorrect value for data[119], expected 102, is "
      << last_msg_->data[119];
  EXPECT_EQ(last_msg_->data[120], 130)
      << "incorrect value for data[120], expected 130, is "
      << last_msg_->data[120];
  EXPECT_EQ(last_msg_->data[121], 254)
      << "incorrect value for data[121], expected 254, is "
      << last_msg_->data[121];
  EXPECT_EQ(last_msg_->data[122], 54)
      << "incorrect value for data[122], expected 54, is "
      << last_msg_->data[122];
  EXPECT_EQ(last_msg_->data[123], 227)
      << "incorrect value for data[123], expected 227, is "
      << last_msg_->data[123];
  EXPECT_EQ(last_msg_->data[124], 229)
      << "incorrect value for data[124], expected 229, is "
      << last_msg_->data[124];
  EXPECT_EQ(last_msg_->data[125], 62)
      << "incorrect value for data[125], expected 62, is "
      << last_msg_->data[125];
  EXPECT_EQ(last_msg_->data[126], 53)
      << "incorrect value for data[126], expected 53, is "
      << last_msg_->data[126];
  EXPECT_EQ(last_msg_->data[127], 225)
      << "incorrect value for data[127], expected 225, is "
      << last_msg_->data[127];
  EXPECT_EQ(last_msg_->data[128], 143)
      << "incorrect value for data[128], expected 143, is "
      << last_msg_->data[128];
  EXPECT_EQ(last_msg_->data[129], 88)
      << "incorrect value for data[129], expected 88, is "
      << last_msg_->data[129];
  EXPECT_EQ(last_msg_->data[130], 139)
      << "incorrect value for data[130], expected 139, is "
      << last_msg_->data[130];
  EXPECT_EQ(last_msg_->data[131], 126)
      << "incorrect value for data[131], expected 126, is "
      << last_msg_->data[131];
  EXPECT_EQ(last_msg_->data[132], 235)
      << "incorrect value for data[132], expected 235, is "
      << last_msg_->data[132];
  EXPECT_EQ(last_msg_->data[133], 235)
      << "incorrect value for data[133], expected 235, is "
      << last_msg_->data[133];
  EXPECT_EQ(last_msg_->data[134], 35)
      << "incorrect value for data[134], expected 35, is "
      << last_msg_->data[134];
  EXPECT_EQ(last_msg_->data[135], 54)
      << "incorrect value for data[135], expected 54, is "
      << last_msg_->data[135];
  EXPECT_EQ(last_msg_->data[136], 134)
      << "incorrect value for data[136], expected 134, is "
      << last_msg_->data[136];
  EXPECT_EQ(last_msg_->data[137], 163)
      << "incorrect value for data[137], expected 163, is "
      << last_msg_->data[137];
  EXPECT_EQ(last_msg_->data[138], 92)
      << "incorrect value for data[138], expected 92, is "
      << last_msg_->data[138];
  EXPECT_EQ(last_msg_->data[139], 57)
      << "incorrect value for data[139], expected 57, is "
      << last_msg_->data[139];
  EXPECT_EQ(last_msg_->data[140], 87)
      << "incorrect value for data[140], expected 87, is "
      << last_msg_->data[140];
  EXPECT_EQ(last_msg_->data[141], 130)
      << "incorrect value for data[141], expected 130, is "
      << last_msg_->data[141];
  EXPECT_EQ(last_msg_->data[142], 178)
      << "incorrect value for data[142], expected 178, is "
      << last_msg_->data[142];
  EXPECT_EQ(last_msg_->data[143], 22)
      << "incorrect value for data[143], expected 22, is "
      << last_msg_->data[143];
  EXPECT_EQ(last_msg_->data[144], 158)
      << "incorrect value for data[144], expected 158, is "
      << last_msg_->data[144];
  EXPECT_EQ(last_msg_->data[145], 18)
      << "incorrect value for data[145], expected 18, is "
      << last_msg_->data[145];
  EXPECT_EQ(last_msg_->data[146], 237)
      << "incorrect value for data[146], expected 237, is "
      << last_msg_->data[146];
  EXPECT_EQ(last_msg_->data[147], 209)
      << "incorrect value for data[147], expected 209, is "
      << last_msg_->data[147];
  EXPECT_EQ(last_msg_->data[148], 187)
      << "incorrect value for data[148], expected 187, is "
      << last_msg_->data[148];
  EXPECT_EQ(last_msg_->data[149], 226)
      << "incorrect value for data[149], expected 226, is "
      << last_msg_->data[149];
  EXPECT_EQ(last_msg_->data[150], 1)
      << "incorrect value for data[150], expected 1, is "
      << last_msg_->data[150];
  EXPECT_EQ(last_msg_->data[151], 46)
      << "incorrect value for data[151], expected 46, is "
      << last_msg_->data[151];
  EXPECT_EQ(last_msg_->data[152], 64)
      << "incorrect value for data[152], expected 64, is "
      << last_msg_->data[152];
  EXPECT_EQ(last_msg_->data[153], 226)
      << "incorrect value for data[153], expected 226, is "
      << last_msg_->data[153];
  EXPECT_EQ(last_msg_->data[154], 235)
      << "incorrect value for data[154], expected 235, is "
      << last_msg_->data[154];
  EXPECT_EQ(last_msg_->data[155], 213)
      << "incorrect value for data[155], expected 213, is "
      << last_msg_->data[155];
  EXPECT_EQ(last_msg_->data[156], 186)
      << "incorrect value for data[156], expected 186, is "
      << last_msg_->data[156];
  EXPECT_EQ(last_msg_->data[157], 159)
      << "incorrect value for data[157], expected 159, is "
      << last_msg_->data[157];
  EXPECT_EQ(last_msg_->data[158], 221)
      << "incorrect value for data[158], expected 221, is "
      << last_msg_->data[158];
  EXPECT_EQ(last_msg_->data[159], 186)
      << "incorrect value for data[159], expected 186, is "
      << last_msg_->data[159];
  EXPECT_EQ(last_msg_->data[160], 25)
      << "incorrect value for data[160], expected 25, is "
      << last_msg_->data[160];
  EXPECT_EQ(last_msg_->data[161], 115)
      << "incorrect value for data[161], expected 115, is "
      << last_msg_->data[161];
  EXPECT_EQ(last_msg_->data[162], 84)
      << "incorrect value for data[162], expected 84, is "
      << last_msg_->data[162];
  EXPECT_EQ(last_msg_->data[163], 131)
      << "incorrect value for data[163], expected 131, is "
      << last_msg_->data[163];
  EXPECT_EQ(last_msg_->data[164], 167)
      << "incorrect value for data[164], expected 167, is "
      << last_msg_->data[164];
  EXPECT_EQ(last_msg_->data[165], 201)
      << "incorrect value for data[165], expected 201, is "
      << last_msg_->data[165];
  EXPECT_EQ(last_msg_->data[166], 104)
      << "incorrect value for data[166], expected 104, is "
      << last_msg_->data[166];
  EXPECT_EQ(last_msg_->data[167], 1)
      << "incorrect value for data[167], expected 1, is "
      << last_msg_->data[167];
  EXPECT_EQ(last_msg_->data[168], 200)
      << "incorrect value for data[168], expected 200, is "
      << last_msg_->data[168];
  EXPECT_EQ(last_msg_->data[169], 13)
      << "incorrect value for data[169], expected 13, is "
      << last_msg_->data[169];
  EXPECT_EQ(last_msg_->data[170], 50)
      << "incorrect value for data[170], expected 50, is "
      << last_msg_->data[170];
  EXPECT_EQ(last_msg_->data[171], 71)
      << "incorrect value for data[171], expected 71, is "
      << last_msg_->data[171];
  EXPECT_EQ(last_msg_->data[172], 73)
      << "incorrect value for data[172], expected 73, is "
      << last_msg_->data[172];
  EXPECT_EQ(last_msg_->data[173], 193)
      << "incorrect value for data[173], expected 193, is "
      << last_msg_->data[173];
  EXPECT_EQ(last_msg_->data[174], 201)
      << "incorrect value for data[174], expected 201, is "
      << last_msg_->data[174];
  EXPECT_EQ(last_msg_->data[175], 250)
      << "incorrect value for data[175], expected 250, is "
      << last_msg_->data[175];
  EXPECT_EQ(last_msg_->data[176], 172)
      << "incorrect value for data[176], expected 172, is "
      << last_msg_->data[176];
  EXPECT_EQ(last_msg_->data[177], 193)
      << "incorrect value for data[177], expected 193, is "
      << last_msg_->data[177];
  EXPECT_EQ(last_msg_->data[178], 13)
      << "incorrect value for data[178], expected 13, is "
      << last_msg_->data[178];
  EXPECT_EQ(last_msg_->data[179], 20)
      << "incorrect value for data[179], expected 20, is "
      << last_msg_->data[179];
  EXPECT_EQ(last_msg_->data[180], 238)
      << "incorrect value for data[180], expected 238, is "
      << last_msg_->data[180];
  EXPECT_EQ(last_msg_->data[181], 130)
      << "incorrect value for data[181], expected 130, is "
      << last_msg_->data[181];
  EXPECT_EQ(last_msg_->data[182], 243)
      << "incorrect value for data[182], expected 243, is "
      << last_msg_->data[182];
  EXPECT_EQ(last_msg_->data[183], 68)
      << "incorrect value for data[183], expected 68, is "
      << last_msg_->data[183];
  EXPECT_EQ(last_msg_->data[184], 4)
      << "incorrect value for data[184], expected 4, is "
      << last_msg_->data[184];
  EXPECT_EQ(last_msg_->data[185], 72)
      << "incorrect value for data[185], expected 72, is "
      << last_msg_->data[185];
  EXPECT_EQ(last_msg_->data[186], 46)
      << "incorrect value for data[186], expected 46, is "
      << last_msg_->data[186];
  EXPECT_EQ(last_msg_->data[187], 194)
      << "incorrect value for data[187], expected 194, is "
      << last_msg_->data[187];
  EXPECT_EQ(last_msg_->data[188], 113)
      << "incorrect value for data[188], expected 113, is "
      << last_msg_->data[188];
  EXPECT_EQ(last_msg_->data[189], 255)
      << "incorrect value for data[189], expected 255, is "
      << last_msg_->data[189];
  EXPECT_EQ(last_msg_->data[190], 238)
      << "incorrect value for data[190], expected 238, is "
      << last_msg_->data[190];
  EXPECT_EQ(last_msg_->data[191], 15)
      << "incorrect value for data[191], expected 15, is "
      << last_msg_->data[191];
  EXPECT_EQ(last_msg_->data[192], 230)
      << "incorrect value for data[192], expected 230, is "
      << last_msg_->data[192];
  EXPECT_EQ(last_msg_->data[193], 64)
      << "incorrect value for data[193], expected 64, is "
      << last_msg_->data[193];
  EXPECT_EQ(last_msg_->data[194], 178)
      << "incorrect value for data[194], expected 178, is "
      << last_msg_->data[194];
  EXPECT_EQ(last_msg_->data[195], 127)
      << "incorrect value for data[195], expected 127, is "
      << last_msg_->data[195];
  EXPECT_EQ(last_msg_->data[196], 217)
      << "incorrect value for data[196], expected 217, is "
      << last_msg_->data[196];
  EXPECT_EQ(last_msg_->data[197], 92)
      << "incorrect value for data[197], expected 92, is "
      << last_msg_->data[197];
  EXPECT_EQ(last_msg_->data[198], 160)
      << "incorrect value for data[198], expected 160, is "
      << last_msg_->data[198];
  EXPECT_EQ(last_msg_->data[199], 201)
      << "incorrect value for data[199], expected 201, is "
      << last_msg_->data[199];
  EXPECT_EQ(last_msg_->data[200], 118)
      << "incorrect value for data[200], expected 118, is "
      << last_msg_->data[200];
  EXPECT_EQ(last_msg_->data[201], 163)
      << "incorrect value for data[201], expected 163, is "
      << last_msg_->data[201];
  EXPECT_EQ(last_msg_->data[202], 144)
      << "incorrect value for data[202], expected 144, is "
      << last_msg_->data[202];
  EXPECT_EQ(last_msg_->data[203], 58)
      << "incorrect value for data[203], expected 58, is "
      << last_msg_->data[203];
  EXPECT_EQ(last_msg_->data[204], 28)
      << "incorrect value for data[204], expected 28, is "
      << last_msg_->data[204];
  EXPECT_EQ(last_msg_->data[205], 174)
      << "incorrect value for data[205], expected 174, is "
      << last_msg_->data[205];
  EXPECT_EQ(last_msg_->data[206], 65)
      << "incorrect value for data[206], expected 65, is "
      << last_msg_->data[206];
  EXPECT_EQ(last_msg_->data[207], 73)
      << "incorrect value for data[207], expected 73, is "
      << last_msg_->data[207];
  EXPECT_EQ(last_msg_->data[208], 45)
      << "incorrect value for data[208], expected 45, is "
      << last_msg_->data[208];
  EXPECT_EQ(last_msg_->data[209], 123)
      << "incorrect value for data[209], expected 123, is "
      << last_msg_->data[209];
  EXPECT_EQ(last_msg_->data[210], 118)
      << "incorrect value for data[210], expected 118, is "
      << last_msg_->data[210];
  EXPECT_EQ(last_msg_->data[211], 83)
      << "incorrect value for data[211], expected 83, is "
      << last_msg_->data[211];
  EXPECT_EQ(last_msg_->data[212], 107)
      << "incorrect value for data[212], expected 107, is "
      << last_msg_->data[212];
  EXPECT_EQ(last_msg_->data[213], 239)
      << "incorrect value for data[213], expected 239, is "
      << last_msg_->data[213];
  EXPECT_EQ(last_msg_->data[214], 168)
      << "incorrect value for data[214], expected 168, is "
      << last_msg_->data[214];
  EXPECT_EQ(last_msg_->data[215], 32)
      << "incorrect value for data[215], expected 32, is "
      << last_msg_->data[215];
  EXPECT_EQ(last_msg_->data[216], 212)
      << "incorrect value for data[216], expected 212, is "
      << last_msg_->data[216];
  EXPECT_EQ(last_msg_->data[217], 191)
      << "incorrect value for data[217], expected 191, is "
      << last_msg_->data[217];
  EXPECT_EQ(last_msg_->data[218], 81)
      << "incorrect value for data[218], expected 81, is "
      << last_msg_->data[218];
  EXPECT_EQ(last_msg_->data[219], 93)
      << "incorrect value for data[219], expected 93, is "
      << last_msg_->data[219];
  EXPECT_EQ(last_msg_->data[220], 186)
      << "incorrect value for data[220], expected 186, is "
      << last_msg_->data[220];
  EXPECT_EQ(last_msg_->data[221], 223)
      << "incorrect value for data[221], expected 223, is "
      << last_msg_->data[221];
  EXPECT_EQ(last_msg_->data[222], 32)
      << "incorrect value for data[222], expected 32, is "
      << last_msg_->data[222];
  EXPECT_EQ(last_msg_->data[223], 19)
      << "incorrect value for data[223], expected 19, is "
      << last_msg_->data[223];
  EXPECT_EQ(last_msg_->data[224], 58)
      << "incorrect value for data[224], expected 58, is "
      << last_msg_->data[224];
  EXPECT_EQ(last_msg_->data[225], 137)
      << "incorrect value for data[225], expected 137, is "
      << last_msg_->data[225];
  EXPECT_EQ(last_msg_->data[226], 72)
      << "incorrect value for data[226], expected 72, is "
      << last_msg_->data[226];
  EXPECT_EQ(last_msg_->data[227], 217)
      << "incorrect value for data[227], expected 217, is "
      << last_msg_->data[227];
  EXPECT_EQ(last_msg_->data[228], 151)
      << "incorrect value for data[228], expected 151, is "
      << last_msg_->data[228];
  EXPECT_EQ(last_msg_->data[229], 251)
      << "incorrect value for data[229], expected 251, is "
      << last_msg_->data[229];
  EXPECT_EQ(last_msg_->data[230], 83)
      << "incorrect value for data[230], expected 83, is "
      << last_msg_->data[230];
  EXPECT_EQ(last_msg_->data[231], 20)
      << "incorrect value for data[231], expected 20, is "
      << last_msg_->data[231];
  EXPECT_EQ(last_msg_->data[232], 113)
      << "incorrect value for data[232], expected 113, is "
      << last_msg_->data[232];
  EXPECT_EQ(last_msg_->data[233], 37)
      << "incorrect value for data[233], expected 37, is "
      << last_msg_->data[233];
  EXPECT_EQ(last_msg_->data[234], 151)
      << "incorrect value for data[234], expected 151, is "
      << last_msg_->data[234];
  EXPECT_EQ(last_msg_->data[235], 34)
      << "incorrect value for data[235], expected 34, is "
      << last_msg_->data[235];
  EXPECT_EQ(last_msg_->data[236], 37)
      << "incorrect value for data[236], expected 37, is "
      << last_msg_->data[236];
  EXPECT_EQ(last_msg_->data[237], 71)
      << "incorrect value for data[237], expected 71, is "
      << last_msg_->data[237];
  EXPECT_EQ(last_msg_->data[238], 95)
      << "incorrect value for data[238], expected 95, is "
      << last_msg_->data[238];
  EXPECT_EQ(last_msg_->data[239], 105)
      << "incorrect value for data[239], expected 105, is "
      << last_msg_->data[239];
  EXPECT_EQ(last_msg_->data[240], 235)
      << "incorrect value for data[240], expected 235, is "
      << last_msg_->data[240];
  EXPECT_EQ(last_msg_->data[241], 144)
      << "incorrect value for data[241], expected 144, is "
      << last_msg_->data[241];
  EXPECT_EQ(last_msg_->data[242], 164)
      << "incorrect value for data[242], expected 164, is "
      << last_msg_->data[242];
  EXPECT_EQ(last_msg_->data[243], 83)
      << "incorrect value for data[243], expected 83, is "
      << last_msg_->data[243];
  EXPECT_EQ(last_msg_->data[244], 197)
      << "incorrect value for data[244], expected 197, is "
      << last_msg_->data[244];
  EXPECT_EQ(last_msg_->data[245], 254)
      << "incorrect value for data[245], expected 254, is "
      << last_msg_->data[245];
  EXPECT_EQ(last_msg_->data[246], 183)
      << "incorrect value for data[246], expected 183, is "
      << last_msg_->data[246];
  EXPECT_EQ(last_msg_->data[247], 223)
      << "incorrect value for data[247], expected 223, is "
      << last_msg_->data[247];
  EXPECT_EQ(last_msg_->data[248], 91)
      << "incorrect value for data[248], expected 91, is "
      << last_msg_->data[248];
  EXPECT_EQ(last_msg_->data[249], 19)
      << "incorrect value for data[249], expected 19, is "
      << last_msg_->data[249];
  EXPECT_EQ(last_msg_->target, 212)
      << "incorrect value for target, expected 212, is " << last_msg_->target;
}
