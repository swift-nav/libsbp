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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCellModemStatus.yaml by
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
class Test_legacy_auto_check_sbp_piksi_MsgCellModemStatus0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_cell_modem_status_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgCellModemStatus0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_cell_modem_status_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_cell_modem_status_t *>(last_msg_storage_)),
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
                      const msg_cell_modem_status_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_cell_modem_status_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgCellModemStatus0, Test) {
  uint8_t encoded_frame[] = {
      85,  190, 0,   19,  27,  255, 103, 205, 48,  6,   70,  123, 242, 46,  52,
      64,  176, 154, 98,  43,  132, 196, 89,  253, 161, 250, 174, 204, 110, 47,
      38,  187, 63,  102, 177, 162, 49,  80,  194, 37,  107, 60,  225, 52,  101,
      178, 142, 246, 21,  17,  93,  75,  169, 86,  16,  209, 80,  243, 30,  206,
      220, 206, 115, 47,  154, 91,  227, 88,  11,  1,   85,  146, 100, 190, 232,
      207, 61,  61,  201, 220, 31,  78,  34,  57,  82,  59,  104, 65,  221, 0,
      43,  210, 9,   32,  122, 29,  237, 11,  151, 223, 18,  81,  204, 172, 234,
      127, 3,   82,  133, 169, 12,  176, 193, 0,   24,  121, 85,  55,  214, 198,
      75,  234, 179, 214, 85,  94,  115, 21,  73,  121, 75,  46,  158, 63,  100,
      122, 213, 20,  85,  212, 131, 50,  224, 218, 215, 215, 149, 2,   19,  129,
      39,  164, 5,   175, 6,   62,  51,  78,  66,  248, 116, 88,  90,  128, 226,
      177, 0,   47,  140, 33,  126, 221, 110, 144, 97,  74,  250, 181, 199, 27,
      176, 65,  185, 110, 92,  34,  44,  131, 96,  178, 40,  176, 4,   90,  36,
      7,   180, 244, 244, 23,  108, 171, 204, 196, 61,  51,  179, 242, 156, 81,
      83,  16,  15,  134, 40,  245, 253, 150, 94,  150, 144, 197, 113, 5,   141,
      232, 33,  101, 231, 38,  75,  178, 243, 119, 1,   248, 218, 86,  7,   88,
      197, 148, 240, 227, 2,   65,  173, 122, 143, 251, 156, 217, 67,  239, 219,
      31,  224, 176, 129, 81,  80,  40,  230,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_cell_modem_status_t *test_msg =
      (msg_cell_modem_status_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[0] = 123;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[1] = 242;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[2] = 46;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[3] = 52;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[4] = 64;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[5] = 176;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[6] = 154;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[7] = 98;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[8] = 43;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[9] = 132;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[10] = 196;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[11] = 89;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[12] = 253;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[13] = 161;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[14] = 250;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[15] = 174;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[16] = 204;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[17] = 110;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[18] = 47;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[19] = 38;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[20] = 187;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[21] = 63;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[22] = 102;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[23] = 177;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[24] = 162;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[25] = 49;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[26] = 80;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[27] = 194;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[28] = 37;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[29] = 107;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[30] = 60;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[31] = 225;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[32] = 52;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[33] = 101;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[34] = 178;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[35] = 142;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[36] = 246;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[37] = 21;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[38] = 17;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[39] = 93;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[40] = 75;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[41] = 169;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[42] = 86;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[43] = 16;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[44] = 209;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[45] = 80;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[46] = 243;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[47] = 30;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[48] = 206;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[49] = 220;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[50] = 206;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[51] = 115;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[52] = 47;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[53] = 154;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[54] = 91;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[55] = 227;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[56] = 88;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[57] = 11;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[58] = 1;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[59] = 85;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[60] = 146;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[61] = 100;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[62] = 190;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[63] = 232;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[64] = 207;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[65] = 61;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[66] = 61;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[67] = 201;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[68] = 220;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[69] = 31;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[70] = 78;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[71] = 34;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[72] = 57;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[73] = 82;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[74] = 59;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[75] = 104;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[76] = 65;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[77] = 221;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[78] = 0;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[79] = 43;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[80] = 210;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[81] = 9;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[82] = 32;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[83] = 122;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[84] = 29;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[85] = 237;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[86] = 11;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[87] = 151;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[88] = 223;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[89] = 18;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[90] = 81;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[91] = 204;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[92] = 172;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[93] = 234;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[94] = 127;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[95] = 3;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[96] = 82;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[97] = 133;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[98] = 169;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[99] = 12;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[100] = 176;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[101] = 193;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[102] = 0;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[103] = 24;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[104] = 121;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[105] = 85;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[106] = 55;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[107] = 214;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[108] = 198;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[109] = 75;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[110] = 234;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[111] = 179;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[112] = 214;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[113] = 85;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[114] = 94;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[115] = 115;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[116] = 21;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[117] = 73;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[118] = 121;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[119] = 75;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[120] = 46;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[121] = 158;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[122] = 63;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[123] = 100;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[124] = 122;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[125] = 213;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[126] = 20;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[127] = 85;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[128] = 212;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[129] = 131;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[130] = 50;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[131] = 224;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[132] = 218;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[133] = 215;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[134] = 215;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[135] = 149;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[136] = 2;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[137] = 19;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[138] = 129;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[139] = 39;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[140] = 164;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[141] = 5;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[142] = 175;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[143] = 6;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[144] = 62;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[145] = 51;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[146] = 78;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[147] = 66;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[148] = 248;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[149] = 116;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[150] = 88;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[151] = 90;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[152] = 128;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[153] = 226;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[154] = 177;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[155] = 0;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[156] = 47;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[157] = 140;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[158] = 33;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[159] = 126;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[160] = 221;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[161] = 110;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[162] = 144;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[163] = 97;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[164] = 74;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[165] = 250;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[166] = 181;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[167] = 199;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[168] = 27;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[169] = 176;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[170] = 65;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[171] = 185;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[172] = 110;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[173] = 92;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[174] = 34;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[175] = 44;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[176] = 131;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[177] = 96;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[178] = 178;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[179] = 40;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[180] = 176;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[181] = 4;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[182] = 90;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[183] = 36;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[184] = 7;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[185] = 180;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[186] = 244;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[187] = 244;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[188] = 23;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[189] = 108;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[190] = 171;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[191] = 204;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[192] = 196;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[193] = 61;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[194] = 51;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[195] = 179;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[196] = 242;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[197] = 156;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[198] = 81;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[199] = 83;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[200] = 16;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[201] = 15;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[202] = 134;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[203] = 40;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[204] = 245;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[205] = 253;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[206] = 150;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[207] = 94;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[208] = 150;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[209] = 144;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[210] = 197;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[211] = 113;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[212] = 5;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[213] = 141;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[214] = 232;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[215] = 33;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[216] = 101;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[217] = 231;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[218] = 38;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[219] = 75;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[220] = 178;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[221] = 243;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[222] = 119;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[223] = 1;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[224] = 248;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[225] = 218;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[226] = 86;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[227] = 7;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[228] = 88;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[229] = 197;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[230] = 148;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[231] = 240;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[232] = 227;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[233] = 2;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[234] = 65;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[235] = 173;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[236] = 122;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[237] = 143;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[238] = 251;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[239] = 156;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[240] = 217;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[241] = 67;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[242] = 239;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[243] = 219;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[244] = 31;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[245] = 224;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[246] = 176;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[247] = 129;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[248] = 81;
  if (sizeof(test_msg->reserved) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->reserved[0]));
  }
  test_msg->reserved[249] = 80;
  test_msg->signal_error_rate = 8588.2001953125;
  test_msg->signal_strength = 103;

  EXPECT_EQ(send_message(0xbe, 6931, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 6931);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->reserved[0], 123)
      << "incorrect value for reserved[0], expected 123, is "
      << last_msg_->reserved[0];
  EXPECT_EQ(last_msg_->reserved[1], 242)
      << "incorrect value for reserved[1], expected 242, is "
      << last_msg_->reserved[1];
  EXPECT_EQ(last_msg_->reserved[2], 46)
      << "incorrect value for reserved[2], expected 46, is "
      << last_msg_->reserved[2];
  EXPECT_EQ(last_msg_->reserved[3], 52)
      << "incorrect value for reserved[3], expected 52, is "
      << last_msg_->reserved[3];
  EXPECT_EQ(last_msg_->reserved[4], 64)
      << "incorrect value for reserved[4], expected 64, is "
      << last_msg_->reserved[4];
  EXPECT_EQ(last_msg_->reserved[5], 176)
      << "incorrect value for reserved[5], expected 176, is "
      << last_msg_->reserved[5];
  EXPECT_EQ(last_msg_->reserved[6], 154)
      << "incorrect value for reserved[6], expected 154, is "
      << last_msg_->reserved[6];
  EXPECT_EQ(last_msg_->reserved[7], 98)
      << "incorrect value for reserved[7], expected 98, is "
      << last_msg_->reserved[7];
  EXPECT_EQ(last_msg_->reserved[8], 43)
      << "incorrect value for reserved[8], expected 43, is "
      << last_msg_->reserved[8];
  EXPECT_EQ(last_msg_->reserved[9], 132)
      << "incorrect value for reserved[9], expected 132, is "
      << last_msg_->reserved[9];
  EXPECT_EQ(last_msg_->reserved[10], 196)
      << "incorrect value for reserved[10], expected 196, is "
      << last_msg_->reserved[10];
  EXPECT_EQ(last_msg_->reserved[11], 89)
      << "incorrect value for reserved[11], expected 89, is "
      << last_msg_->reserved[11];
  EXPECT_EQ(last_msg_->reserved[12], 253)
      << "incorrect value for reserved[12], expected 253, is "
      << last_msg_->reserved[12];
  EXPECT_EQ(last_msg_->reserved[13], 161)
      << "incorrect value for reserved[13], expected 161, is "
      << last_msg_->reserved[13];
  EXPECT_EQ(last_msg_->reserved[14], 250)
      << "incorrect value for reserved[14], expected 250, is "
      << last_msg_->reserved[14];
  EXPECT_EQ(last_msg_->reserved[15], 174)
      << "incorrect value for reserved[15], expected 174, is "
      << last_msg_->reserved[15];
  EXPECT_EQ(last_msg_->reserved[16], 204)
      << "incorrect value for reserved[16], expected 204, is "
      << last_msg_->reserved[16];
  EXPECT_EQ(last_msg_->reserved[17], 110)
      << "incorrect value for reserved[17], expected 110, is "
      << last_msg_->reserved[17];
  EXPECT_EQ(last_msg_->reserved[18], 47)
      << "incorrect value for reserved[18], expected 47, is "
      << last_msg_->reserved[18];
  EXPECT_EQ(last_msg_->reserved[19], 38)
      << "incorrect value for reserved[19], expected 38, is "
      << last_msg_->reserved[19];
  EXPECT_EQ(last_msg_->reserved[20], 187)
      << "incorrect value for reserved[20], expected 187, is "
      << last_msg_->reserved[20];
  EXPECT_EQ(last_msg_->reserved[21], 63)
      << "incorrect value for reserved[21], expected 63, is "
      << last_msg_->reserved[21];
  EXPECT_EQ(last_msg_->reserved[22], 102)
      << "incorrect value for reserved[22], expected 102, is "
      << last_msg_->reserved[22];
  EXPECT_EQ(last_msg_->reserved[23], 177)
      << "incorrect value for reserved[23], expected 177, is "
      << last_msg_->reserved[23];
  EXPECT_EQ(last_msg_->reserved[24], 162)
      << "incorrect value for reserved[24], expected 162, is "
      << last_msg_->reserved[24];
  EXPECT_EQ(last_msg_->reserved[25], 49)
      << "incorrect value for reserved[25], expected 49, is "
      << last_msg_->reserved[25];
  EXPECT_EQ(last_msg_->reserved[26], 80)
      << "incorrect value for reserved[26], expected 80, is "
      << last_msg_->reserved[26];
  EXPECT_EQ(last_msg_->reserved[27], 194)
      << "incorrect value for reserved[27], expected 194, is "
      << last_msg_->reserved[27];
  EXPECT_EQ(last_msg_->reserved[28], 37)
      << "incorrect value for reserved[28], expected 37, is "
      << last_msg_->reserved[28];
  EXPECT_EQ(last_msg_->reserved[29], 107)
      << "incorrect value for reserved[29], expected 107, is "
      << last_msg_->reserved[29];
  EXPECT_EQ(last_msg_->reserved[30], 60)
      << "incorrect value for reserved[30], expected 60, is "
      << last_msg_->reserved[30];
  EXPECT_EQ(last_msg_->reserved[31], 225)
      << "incorrect value for reserved[31], expected 225, is "
      << last_msg_->reserved[31];
  EXPECT_EQ(last_msg_->reserved[32], 52)
      << "incorrect value for reserved[32], expected 52, is "
      << last_msg_->reserved[32];
  EXPECT_EQ(last_msg_->reserved[33], 101)
      << "incorrect value for reserved[33], expected 101, is "
      << last_msg_->reserved[33];
  EXPECT_EQ(last_msg_->reserved[34], 178)
      << "incorrect value for reserved[34], expected 178, is "
      << last_msg_->reserved[34];
  EXPECT_EQ(last_msg_->reserved[35], 142)
      << "incorrect value for reserved[35], expected 142, is "
      << last_msg_->reserved[35];
  EXPECT_EQ(last_msg_->reserved[36], 246)
      << "incorrect value for reserved[36], expected 246, is "
      << last_msg_->reserved[36];
  EXPECT_EQ(last_msg_->reserved[37], 21)
      << "incorrect value for reserved[37], expected 21, is "
      << last_msg_->reserved[37];
  EXPECT_EQ(last_msg_->reserved[38], 17)
      << "incorrect value for reserved[38], expected 17, is "
      << last_msg_->reserved[38];
  EXPECT_EQ(last_msg_->reserved[39], 93)
      << "incorrect value for reserved[39], expected 93, is "
      << last_msg_->reserved[39];
  EXPECT_EQ(last_msg_->reserved[40], 75)
      << "incorrect value for reserved[40], expected 75, is "
      << last_msg_->reserved[40];
  EXPECT_EQ(last_msg_->reserved[41], 169)
      << "incorrect value for reserved[41], expected 169, is "
      << last_msg_->reserved[41];
  EXPECT_EQ(last_msg_->reserved[42], 86)
      << "incorrect value for reserved[42], expected 86, is "
      << last_msg_->reserved[42];
  EXPECT_EQ(last_msg_->reserved[43], 16)
      << "incorrect value for reserved[43], expected 16, is "
      << last_msg_->reserved[43];
  EXPECT_EQ(last_msg_->reserved[44], 209)
      << "incorrect value for reserved[44], expected 209, is "
      << last_msg_->reserved[44];
  EXPECT_EQ(last_msg_->reserved[45], 80)
      << "incorrect value for reserved[45], expected 80, is "
      << last_msg_->reserved[45];
  EXPECT_EQ(last_msg_->reserved[46], 243)
      << "incorrect value for reserved[46], expected 243, is "
      << last_msg_->reserved[46];
  EXPECT_EQ(last_msg_->reserved[47], 30)
      << "incorrect value for reserved[47], expected 30, is "
      << last_msg_->reserved[47];
  EXPECT_EQ(last_msg_->reserved[48], 206)
      << "incorrect value for reserved[48], expected 206, is "
      << last_msg_->reserved[48];
  EXPECT_EQ(last_msg_->reserved[49], 220)
      << "incorrect value for reserved[49], expected 220, is "
      << last_msg_->reserved[49];
  EXPECT_EQ(last_msg_->reserved[50], 206)
      << "incorrect value for reserved[50], expected 206, is "
      << last_msg_->reserved[50];
  EXPECT_EQ(last_msg_->reserved[51], 115)
      << "incorrect value for reserved[51], expected 115, is "
      << last_msg_->reserved[51];
  EXPECT_EQ(last_msg_->reserved[52], 47)
      << "incorrect value for reserved[52], expected 47, is "
      << last_msg_->reserved[52];
  EXPECT_EQ(last_msg_->reserved[53], 154)
      << "incorrect value for reserved[53], expected 154, is "
      << last_msg_->reserved[53];
  EXPECT_EQ(last_msg_->reserved[54], 91)
      << "incorrect value for reserved[54], expected 91, is "
      << last_msg_->reserved[54];
  EXPECT_EQ(last_msg_->reserved[55], 227)
      << "incorrect value for reserved[55], expected 227, is "
      << last_msg_->reserved[55];
  EXPECT_EQ(last_msg_->reserved[56], 88)
      << "incorrect value for reserved[56], expected 88, is "
      << last_msg_->reserved[56];
  EXPECT_EQ(last_msg_->reserved[57], 11)
      << "incorrect value for reserved[57], expected 11, is "
      << last_msg_->reserved[57];
  EXPECT_EQ(last_msg_->reserved[58], 1)
      << "incorrect value for reserved[58], expected 1, is "
      << last_msg_->reserved[58];
  EXPECT_EQ(last_msg_->reserved[59], 85)
      << "incorrect value for reserved[59], expected 85, is "
      << last_msg_->reserved[59];
  EXPECT_EQ(last_msg_->reserved[60], 146)
      << "incorrect value for reserved[60], expected 146, is "
      << last_msg_->reserved[60];
  EXPECT_EQ(last_msg_->reserved[61], 100)
      << "incorrect value for reserved[61], expected 100, is "
      << last_msg_->reserved[61];
  EXPECT_EQ(last_msg_->reserved[62], 190)
      << "incorrect value for reserved[62], expected 190, is "
      << last_msg_->reserved[62];
  EXPECT_EQ(last_msg_->reserved[63], 232)
      << "incorrect value for reserved[63], expected 232, is "
      << last_msg_->reserved[63];
  EXPECT_EQ(last_msg_->reserved[64], 207)
      << "incorrect value for reserved[64], expected 207, is "
      << last_msg_->reserved[64];
  EXPECT_EQ(last_msg_->reserved[65], 61)
      << "incorrect value for reserved[65], expected 61, is "
      << last_msg_->reserved[65];
  EXPECT_EQ(last_msg_->reserved[66], 61)
      << "incorrect value for reserved[66], expected 61, is "
      << last_msg_->reserved[66];
  EXPECT_EQ(last_msg_->reserved[67], 201)
      << "incorrect value for reserved[67], expected 201, is "
      << last_msg_->reserved[67];
  EXPECT_EQ(last_msg_->reserved[68], 220)
      << "incorrect value for reserved[68], expected 220, is "
      << last_msg_->reserved[68];
  EXPECT_EQ(last_msg_->reserved[69], 31)
      << "incorrect value for reserved[69], expected 31, is "
      << last_msg_->reserved[69];
  EXPECT_EQ(last_msg_->reserved[70], 78)
      << "incorrect value for reserved[70], expected 78, is "
      << last_msg_->reserved[70];
  EXPECT_EQ(last_msg_->reserved[71], 34)
      << "incorrect value for reserved[71], expected 34, is "
      << last_msg_->reserved[71];
  EXPECT_EQ(last_msg_->reserved[72], 57)
      << "incorrect value for reserved[72], expected 57, is "
      << last_msg_->reserved[72];
  EXPECT_EQ(last_msg_->reserved[73], 82)
      << "incorrect value for reserved[73], expected 82, is "
      << last_msg_->reserved[73];
  EXPECT_EQ(last_msg_->reserved[74], 59)
      << "incorrect value for reserved[74], expected 59, is "
      << last_msg_->reserved[74];
  EXPECT_EQ(last_msg_->reserved[75], 104)
      << "incorrect value for reserved[75], expected 104, is "
      << last_msg_->reserved[75];
  EXPECT_EQ(last_msg_->reserved[76], 65)
      << "incorrect value for reserved[76], expected 65, is "
      << last_msg_->reserved[76];
  EXPECT_EQ(last_msg_->reserved[77], 221)
      << "incorrect value for reserved[77], expected 221, is "
      << last_msg_->reserved[77];
  EXPECT_EQ(last_msg_->reserved[78], 0)
      << "incorrect value for reserved[78], expected 0, is "
      << last_msg_->reserved[78];
  EXPECT_EQ(last_msg_->reserved[79], 43)
      << "incorrect value for reserved[79], expected 43, is "
      << last_msg_->reserved[79];
  EXPECT_EQ(last_msg_->reserved[80], 210)
      << "incorrect value for reserved[80], expected 210, is "
      << last_msg_->reserved[80];
  EXPECT_EQ(last_msg_->reserved[81], 9)
      << "incorrect value for reserved[81], expected 9, is "
      << last_msg_->reserved[81];
  EXPECT_EQ(last_msg_->reserved[82], 32)
      << "incorrect value for reserved[82], expected 32, is "
      << last_msg_->reserved[82];
  EXPECT_EQ(last_msg_->reserved[83], 122)
      << "incorrect value for reserved[83], expected 122, is "
      << last_msg_->reserved[83];
  EXPECT_EQ(last_msg_->reserved[84], 29)
      << "incorrect value for reserved[84], expected 29, is "
      << last_msg_->reserved[84];
  EXPECT_EQ(last_msg_->reserved[85], 237)
      << "incorrect value for reserved[85], expected 237, is "
      << last_msg_->reserved[85];
  EXPECT_EQ(last_msg_->reserved[86], 11)
      << "incorrect value for reserved[86], expected 11, is "
      << last_msg_->reserved[86];
  EXPECT_EQ(last_msg_->reserved[87], 151)
      << "incorrect value for reserved[87], expected 151, is "
      << last_msg_->reserved[87];
  EXPECT_EQ(last_msg_->reserved[88], 223)
      << "incorrect value for reserved[88], expected 223, is "
      << last_msg_->reserved[88];
  EXPECT_EQ(last_msg_->reserved[89], 18)
      << "incorrect value for reserved[89], expected 18, is "
      << last_msg_->reserved[89];
  EXPECT_EQ(last_msg_->reserved[90], 81)
      << "incorrect value for reserved[90], expected 81, is "
      << last_msg_->reserved[90];
  EXPECT_EQ(last_msg_->reserved[91], 204)
      << "incorrect value for reserved[91], expected 204, is "
      << last_msg_->reserved[91];
  EXPECT_EQ(last_msg_->reserved[92], 172)
      << "incorrect value for reserved[92], expected 172, is "
      << last_msg_->reserved[92];
  EXPECT_EQ(last_msg_->reserved[93], 234)
      << "incorrect value for reserved[93], expected 234, is "
      << last_msg_->reserved[93];
  EXPECT_EQ(last_msg_->reserved[94], 127)
      << "incorrect value for reserved[94], expected 127, is "
      << last_msg_->reserved[94];
  EXPECT_EQ(last_msg_->reserved[95], 3)
      << "incorrect value for reserved[95], expected 3, is "
      << last_msg_->reserved[95];
  EXPECT_EQ(last_msg_->reserved[96], 82)
      << "incorrect value for reserved[96], expected 82, is "
      << last_msg_->reserved[96];
  EXPECT_EQ(last_msg_->reserved[97], 133)
      << "incorrect value for reserved[97], expected 133, is "
      << last_msg_->reserved[97];
  EXPECT_EQ(last_msg_->reserved[98], 169)
      << "incorrect value for reserved[98], expected 169, is "
      << last_msg_->reserved[98];
  EXPECT_EQ(last_msg_->reserved[99], 12)
      << "incorrect value for reserved[99], expected 12, is "
      << last_msg_->reserved[99];
  EXPECT_EQ(last_msg_->reserved[100], 176)
      << "incorrect value for reserved[100], expected 176, is "
      << last_msg_->reserved[100];
  EXPECT_EQ(last_msg_->reserved[101], 193)
      << "incorrect value for reserved[101], expected 193, is "
      << last_msg_->reserved[101];
  EXPECT_EQ(last_msg_->reserved[102], 0)
      << "incorrect value for reserved[102], expected 0, is "
      << last_msg_->reserved[102];
  EXPECT_EQ(last_msg_->reserved[103], 24)
      << "incorrect value for reserved[103], expected 24, is "
      << last_msg_->reserved[103];
  EXPECT_EQ(last_msg_->reserved[104], 121)
      << "incorrect value for reserved[104], expected 121, is "
      << last_msg_->reserved[104];
  EXPECT_EQ(last_msg_->reserved[105], 85)
      << "incorrect value for reserved[105], expected 85, is "
      << last_msg_->reserved[105];
  EXPECT_EQ(last_msg_->reserved[106], 55)
      << "incorrect value for reserved[106], expected 55, is "
      << last_msg_->reserved[106];
  EXPECT_EQ(last_msg_->reserved[107], 214)
      << "incorrect value for reserved[107], expected 214, is "
      << last_msg_->reserved[107];
  EXPECT_EQ(last_msg_->reserved[108], 198)
      << "incorrect value for reserved[108], expected 198, is "
      << last_msg_->reserved[108];
  EXPECT_EQ(last_msg_->reserved[109], 75)
      << "incorrect value for reserved[109], expected 75, is "
      << last_msg_->reserved[109];
  EXPECT_EQ(last_msg_->reserved[110], 234)
      << "incorrect value for reserved[110], expected 234, is "
      << last_msg_->reserved[110];
  EXPECT_EQ(last_msg_->reserved[111], 179)
      << "incorrect value for reserved[111], expected 179, is "
      << last_msg_->reserved[111];
  EXPECT_EQ(last_msg_->reserved[112], 214)
      << "incorrect value for reserved[112], expected 214, is "
      << last_msg_->reserved[112];
  EXPECT_EQ(last_msg_->reserved[113], 85)
      << "incorrect value for reserved[113], expected 85, is "
      << last_msg_->reserved[113];
  EXPECT_EQ(last_msg_->reserved[114], 94)
      << "incorrect value for reserved[114], expected 94, is "
      << last_msg_->reserved[114];
  EXPECT_EQ(last_msg_->reserved[115], 115)
      << "incorrect value for reserved[115], expected 115, is "
      << last_msg_->reserved[115];
  EXPECT_EQ(last_msg_->reserved[116], 21)
      << "incorrect value for reserved[116], expected 21, is "
      << last_msg_->reserved[116];
  EXPECT_EQ(last_msg_->reserved[117], 73)
      << "incorrect value for reserved[117], expected 73, is "
      << last_msg_->reserved[117];
  EXPECT_EQ(last_msg_->reserved[118], 121)
      << "incorrect value for reserved[118], expected 121, is "
      << last_msg_->reserved[118];
  EXPECT_EQ(last_msg_->reserved[119], 75)
      << "incorrect value for reserved[119], expected 75, is "
      << last_msg_->reserved[119];
  EXPECT_EQ(last_msg_->reserved[120], 46)
      << "incorrect value for reserved[120], expected 46, is "
      << last_msg_->reserved[120];
  EXPECT_EQ(last_msg_->reserved[121], 158)
      << "incorrect value for reserved[121], expected 158, is "
      << last_msg_->reserved[121];
  EXPECT_EQ(last_msg_->reserved[122], 63)
      << "incorrect value for reserved[122], expected 63, is "
      << last_msg_->reserved[122];
  EXPECT_EQ(last_msg_->reserved[123], 100)
      << "incorrect value for reserved[123], expected 100, is "
      << last_msg_->reserved[123];
  EXPECT_EQ(last_msg_->reserved[124], 122)
      << "incorrect value for reserved[124], expected 122, is "
      << last_msg_->reserved[124];
  EXPECT_EQ(last_msg_->reserved[125], 213)
      << "incorrect value for reserved[125], expected 213, is "
      << last_msg_->reserved[125];
  EXPECT_EQ(last_msg_->reserved[126], 20)
      << "incorrect value for reserved[126], expected 20, is "
      << last_msg_->reserved[126];
  EXPECT_EQ(last_msg_->reserved[127], 85)
      << "incorrect value for reserved[127], expected 85, is "
      << last_msg_->reserved[127];
  EXPECT_EQ(last_msg_->reserved[128], 212)
      << "incorrect value for reserved[128], expected 212, is "
      << last_msg_->reserved[128];
  EXPECT_EQ(last_msg_->reserved[129], 131)
      << "incorrect value for reserved[129], expected 131, is "
      << last_msg_->reserved[129];
  EXPECT_EQ(last_msg_->reserved[130], 50)
      << "incorrect value for reserved[130], expected 50, is "
      << last_msg_->reserved[130];
  EXPECT_EQ(last_msg_->reserved[131], 224)
      << "incorrect value for reserved[131], expected 224, is "
      << last_msg_->reserved[131];
  EXPECT_EQ(last_msg_->reserved[132], 218)
      << "incorrect value for reserved[132], expected 218, is "
      << last_msg_->reserved[132];
  EXPECT_EQ(last_msg_->reserved[133], 215)
      << "incorrect value for reserved[133], expected 215, is "
      << last_msg_->reserved[133];
  EXPECT_EQ(last_msg_->reserved[134], 215)
      << "incorrect value for reserved[134], expected 215, is "
      << last_msg_->reserved[134];
  EXPECT_EQ(last_msg_->reserved[135], 149)
      << "incorrect value for reserved[135], expected 149, is "
      << last_msg_->reserved[135];
  EXPECT_EQ(last_msg_->reserved[136], 2)
      << "incorrect value for reserved[136], expected 2, is "
      << last_msg_->reserved[136];
  EXPECT_EQ(last_msg_->reserved[137], 19)
      << "incorrect value for reserved[137], expected 19, is "
      << last_msg_->reserved[137];
  EXPECT_EQ(last_msg_->reserved[138], 129)
      << "incorrect value for reserved[138], expected 129, is "
      << last_msg_->reserved[138];
  EXPECT_EQ(last_msg_->reserved[139], 39)
      << "incorrect value for reserved[139], expected 39, is "
      << last_msg_->reserved[139];
  EXPECT_EQ(last_msg_->reserved[140], 164)
      << "incorrect value for reserved[140], expected 164, is "
      << last_msg_->reserved[140];
  EXPECT_EQ(last_msg_->reserved[141], 5)
      << "incorrect value for reserved[141], expected 5, is "
      << last_msg_->reserved[141];
  EXPECT_EQ(last_msg_->reserved[142], 175)
      << "incorrect value for reserved[142], expected 175, is "
      << last_msg_->reserved[142];
  EXPECT_EQ(last_msg_->reserved[143], 6)
      << "incorrect value for reserved[143], expected 6, is "
      << last_msg_->reserved[143];
  EXPECT_EQ(last_msg_->reserved[144], 62)
      << "incorrect value for reserved[144], expected 62, is "
      << last_msg_->reserved[144];
  EXPECT_EQ(last_msg_->reserved[145], 51)
      << "incorrect value for reserved[145], expected 51, is "
      << last_msg_->reserved[145];
  EXPECT_EQ(last_msg_->reserved[146], 78)
      << "incorrect value for reserved[146], expected 78, is "
      << last_msg_->reserved[146];
  EXPECT_EQ(last_msg_->reserved[147], 66)
      << "incorrect value for reserved[147], expected 66, is "
      << last_msg_->reserved[147];
  EXPECT_EQ(last_msg_->reserved[148], 248)
      << "incorrect value for reserved[148], expected 248, is "
      << last_msg_->reserved[148];
  EXPECT_EQ(last_msg_->reserved[149], 116)
      << "incorrect value for reserved[149], expected 116, is "
      << last_msg_->reserved[149];
  EXPECT_EQ(last_msg_->reserved[150], 88)
      << "incorrect value for reserved[150], expected 88, is "
      << last_msg_->reserved[150];
  EXPECT_EQ(last_msg_->reserved[151], 90)
      << "incorrect value for reserved[151], expected 90, is "
      << last_msg_->reserved[151];
  EXPECT_EQ(last_msg_->reserved[152], 128)
      << "incorrect value for reserved[152], expected 128, is "
      << last_msg_->reserved[152];
  EXPECT_EQ(last_msg_->reserved[153], 226)
      << "incorrect value for reserved[153], expected 226, is "
      << last_msg_->reserved[153];
  EXPECT_EQ(last_msg_->reserved[154], 177)
      << "incorrect value for reserved[154], expected 177, is "
      << last_msg_->reserved[154];
  EXPECT_EQ(last_msg_->reserved[155], 0)
      << "incorrect value for reserved[155], expected 0, is "
      << last_msg_->reserved[155];
  EXPECT_EQ(last_msg_->reserved[156], 47)
      << "incorrect value for reserved[156], expected 47, is "
      << last_msg_->reserved[156];
  EXPECT_EQ(last_msg_->reserved[157], 140)
      << "incorrect value for reserved[157], expected 140, is "
      << last_msg_->reserved[157];
  EXPECT_EQ(last_msg_->reserved[158], 33)
      << "incorrect value for reserved[158], expected 33, is "
      << last_msg_->reserved[158];
  EXPECT_EQ(last_msg_->reserved[159], 126)
      << "incorrect value for reserved[159], expected 126, is "
      << last_msg_->reserved[159];
  EXPECT_EQ(last_msg_->reserved[160], 221)
      << "incorrect value for reserved[160], expected 221, is "
      << last_msg_->reserved[160];
  EXPECT_EQ(last_msg_->reserved[161], 110)
      << "incorrect value for reserved[161], expected 110, is "
      << last_msg_->reserved[161];
  EXPECT_EQ(last_msg_->reserved[162], 144)
      << "incorrect value for reserved[162], expected 144, is "
      << last_msg_->reserved[162];
  EXPECT_EQ(last_msg_->reserved[163], 97)
      << "incorrect value for reserved[163], expected 97, is "
      << last_msg_->reserved[163];
  EXPECT_EQ(last_msg_->reserved[164], 74)
      << "incorrect value for reserved[164], expected 74, is "
      << last_msg_->reserved[164];
  EXPECT_EQ(last_msg_->reserved[165], 250)
      << "incorrect value for reserved[165], expected 250, is "
      << last_msg_->reserved[165];
  EXPECT_EQ(last_msg_->reserved[166], 181)
      << "incorrect value for reserved[166], expected 181, is "
      << last_msg_->reserved[166];
  EXPECT_EQ(last_msg_->reserved[167], 199)
      << "incorrect value for reserved[167], expected 199, is "
      << last_msg_->reserved[167];
  EXPECT_EQ(last_msg_->reserved[168], 27)
      << "incorrect value for reserved[168], expected 27, is "
      << last_msg_->reserved[168];
  EXPECT_EQ(last_msg_->reserved[169], 176)
      << "incorrect value for reserved[169], expected 176, is "
      << last_msg_->reserved[169];
  EXPECT_EQ(last_msg_->reserved[170], 65)
      << "incorrect value for reserved[170], expected 65, is "
      << last_msg_->reserved[170];
  EXPECT_EQ(last_msg_->reserved[171], 185)
      << "incorrect value for reserved[171], expected 185, is "
      << last_msg_->reserved[171];
  EXPECT_EQ(last_msg_->reserved[172], 110)
      << "incorrect value for reserved[172], expected 110, is "
      << last_msg_->reserved[172];
  EXPECT_EQ(last_msg_->reserved[173], 92)
      << "incorrect value for reserved[173], expected 92, is "
      << last_msg_->reserved[173];
  EXPECT_EQ(last_msg_->reserved[174], 34)
      << "incorrect value for reserved[174], expected 34, is "
      << last_msg_->reserved[174];
  EXPECT_EQ(last_msg_->reserved[175], 44)
      << "incorrect value for reserved[175], expected 44, is "
      << last_msg_->reserved[175];
  EXPECT_EQ(last_msg_->reserved[176], 131)
      << "incorrect value for reserved[176], expected 131, is "
      << last_msg_->reserved[176];
  EXPECT_EQ(last_msg_->reserved[177], 96)
      << "incorrect value for reserved[177], expected 96, is "
      << last_msg_->reserved[177];
  EXPECT_EQ(last_msg_->reserved[178], 178)
      << "incorrect value for reserved[178], expected 178, is "
      << last_msg_->reserved[178];
  EXPECT_EQ(last_msg_->reserved[179], 40)
      << "incorrect value for reserved[179], expected 40, is "
      << last_msg_->reserved[179];
  EXPECT_EQ(last_msg_->reserved[180], 176)
      << "incorrect value for reserved[180], expected 176, is "
      << last_msg_->reserved[180];
  EXPECT_EQ(last_msg_->reserved[181], 4)
      << "incorrect value for reserved[181], expected 4, is "
      << last_msg_->reserved[181];
  EXPECT_EQ(last_msg_->reserved[182], 90)
      << "incorrect value for reserved[182], expected 90, is "
      << last_msg_->reserved[182];
  EXPECT_EQ(last_msg_->reserved[183], 36)
      << "incorrect value for reserved[183], expected 36, is "
      << last_msg_->reserved[183];
  EXPECT_EQ(last_msg_->reserved[184], 7)
      << "incorrect value for reserved[184], expected 7, is "
      << last_msg_->reserved[184];
  EXPECT_EQ(last_msg_->reserved[185], 180)
      << "incorrect value for reserved[185], expected 180, is "
      << last_msg_->reserved[185];
  EXPECT_EQ(last_msg_->reserved[186], 244)
      << "incorrect value for reserved[186], expected 244, is "
      << last_msg_->reserved[186];
  EXPECT_EQ(last_msg_->reserved[187], 244)
      << "incorrect value for reserved[187], expected 244, is "
      << last_msg_->reserved[187];
  EXPECT_EQ(last_msg_->reserved[188], 23)
      << "incorrect value for reserved[188], expected 23, is "
      << last_msg_->reserved[188];
  EXPECT_EQ(last_msg_->reserved[189], 108)
      << "incorrect value for reserved[189], expected 108, is "
      << last_msg_->reserved[189];
  EXPECT_EQ(last_msg_->reserved[190], 171)
      << "incorrect value for reserved[190], expected 171, is "
      << last_msg_->reserved[190];
  EXPECT_EQ(last_msg_->reserved[191], 204)
      << "incorrect value for reserved[191], expected 204, is "
      << last_msg_->reserved[191];
  EXPECT_EQ(last_msg_->reserved[192], 196)
      << "incorrect value for reserved[192], expected 196, is "
      << last_msg_->reserved[192];
  EXPECT_EQ(last_msg_->reserved[193], 61)
      << "incorrect value for reserved[193], expected 61, is "
      << last_msg_->reserved[193];
  EXPECT_EQ(last_msg_->reserved[194], 51)
      << "incorrect value for reserved[194], expected 51, is "
      << last_msg_->reserved[194];
  EXPECT_EQ(last_msg_->reserved[195], 179)
      << "incorrect value for reserved[195], expected 179, is "
      << last_msg_->reserved[195];
  EXPECT_EQ(last_msg_->reserved[196], 242)
      << "incorrect value for reserved[196], expected 242, is "
      << last_msg_->reserved[196];
  EXPECT_EQ(last_msg_->reserved[197], 156)
      << "incorrect value for reserved[197], expected 156, is "
      << last_msg_->reserved[197];
  EXPECT_EQ(last_msg_->reserved[198], 81)
      << "incorrect value for reserved[198], expected 81, is "
      << last_msg_->reserved[198];
  EXPECT_EQ(last_msg_->reserved[199], 83)
      << "incorrect value for reserved[199], expected 83, is "
      << last_msg_->reserved[199];
  EXPECT_EQ(last_msg_->reserved[200], 16)
      << "incorrect value for reserved[200], expected 16, is "
      << last_msg_->reserved[200];
  EXPECT_EQ(last_msg_->reserved[201], 15)
      << "incorrect value for reserved[201], expected 15, is "
      << last_msg_->reserved[201];
  EXPECT_EQ(last_msg_->reserved[202], 134)
      << "incorrect value for reserved[202], expected 134, is "
      << last_msg_->reserved[202];
  EXPECT_EQ(last_msg_->reserved[203], 40)
      << "incorrect value for reserved[203], expected 40, is "
      << last_msg_->reserved[203];
  EXPECT_EQ(last_msg_->reserved[204], 245)
      << "incorrect value for reserved[204], expected 245, is "
      << last_msg_->reserved[204];
  EXPECT_EQ(last_msg_->reserved[205], 253)
      << "incorrect value for reserved[205], expected 253, is "
      << last_msg_->reserved[205];
  EXPECT_EQ(last_msg_->reserved[206], 150)
      << "incorrect value for reserved[206], expected 150, is "
      << last_msg_->reserved[206];
  EXPECT_EQ(last_msg_->reserved[207], 94)
      << "incorrect value for reserved[207], expected 94, is "
      << last_msg_->reserved[207];
  EXPECT_EQ(last_msg_->reserved[208], 150)
      << "incorrect value for reserved[208], expected 150, is "
      << last_msg_->reserved[208];
  EXPECT_EQ(last_msg_->reserved[209], 144)
      << "incorrect value for reserved[209], expected 144, is "
      << last_msg_->reserved[209];
  EXPECT_EQ(last_msg_->reserved[210], 197)
      << "incorrect value for reserved[210], expected 197, is "
      << last_msg_->reserved[210];
  EXPECT_EQ(last_msg_->reserved[211], 113)
      << "incorrect value for reserved[211], expected 113, is "
      << last_msg_->reserved[211];
  EXPECT_EQ(last_msg_->reserved[212], 5)
      << "incorrect value for reserved[212], expected 5, is "
      << last_msg_->reserved[212];
  EXPECT_EQ(last_msg_->reserved[213], 141)
      << "incorrect value for reserved[213], expected 141, is "
      << last_msg_->reserved[213];
  EXPECT_EQ(last_msg_->reserved[214], 232)
      << "incorrect value for reserved[214], expected 232, is "
      << last_msg_->reserved[214];
  EXPECT_EQ(last_msg_->reserved[215], 33)
      << "incorrect value for reserved[215], expected 33, is "
      << last_msg_->reserved[215];
  EXPECT_EQ(last_msg_->reserved[216], 101)
      << "incorrect value for reserved[216], expected 101, is "
      << last_msg_->reserved[216];
  EXPECT_EQ(last_msg_->reserved[217], 231)
      << "incorrect value for reserved[217], expected 231, is "
      << last_msg_->reserved[217];
  EXPECT_EQ(last_msg_->reserved[218], 38)
      << "incorrect value for reserved[218], expected 38, is "
      << last_msg_->reserved[218];
  EXPECT_EQ(last_msg_->reserved[219], 75)
      << "incorrect value for reserved[219], expected 75, is "
      << last_msg_->reserved[219];
  EXPECT_EQ(last_msg_->reserved[220], 178)
      << "incorrect value for reserved[220], expected 178, is "
      << last_msg_->reserved[220];
  EXPECT_EQ(last_msg_->reserved[221], 243)
      << "incorrect value for reserved[221], expected 243, is "
      << last_msg_->reserved[221];
  EXPECT_EQ(last_msg_->reserved[222], 119)
      << "incorrect value for reserved[222], expected 119, is "
      << last_msg_->reserved[222];
  EXPECT_EQ(last_msg_->reserved[223], 1)
      << "incorrect value for reserved[223], expected 1, is "
      << last_msg_->reserved[223];
  EXPECT_EQ(last_msg_->reserved[224], 248)
      << "incorrect value for reserved[224], expected 248, is "
      << last_msg_->reserved[224];
  EXPECT_EQ(last_msg_->reserved[225], 218)
      << "incorrect value for reserved[225], expected 218, is "
      << last_msg_->reserved[225];
  EXPECT_EQ(last_msg_->reserved[226], 86)
      << "incorrect value for reserved[226], expected 86, is "
      << last_msg_->reserved[226];
  EXPECT_EQ(last_msg_->reserved[227], 7)
      << "incorrect value for reserved[227], expected 7, is "
      << last_msg_->reserved[227];
  EXPECT_EQ(last_msg_->reserved[228], 88)
      << "incorrect value for reserved[228], expected 88, is "
      << last_msg_->reserved[228];
  EXPECT_EQ(last_msg_->reserved[229], 197)
      << "incorrect value for reserved[229], expected 197, is "
      << last_msg_->reserved[229];
  EXPECT_EQ(last_msg_->reserved[230], 148)
      << "incorrect value for reserved[230], expected 148, is "
      << last_msg_->reserved[230];
  EXPECT_EQ(last_msg_->reserved[231], 240)
      << "incorrect value for reserved[231], expected 240, is "
      << last_msg_->reserved[231];
  EXPECT_EQ(last_msg_->reserved[232], 227)
      << "incorrect value for reserved[232], expected 227, is "
      << last_msg_->reserved[232];
  EXPECT_EQ(last_msg_->reserved[233], 2)
      << "incorrect value for reserved[233], expected 2, is "
      << last_msg_->reserved[233];
  EXPECT_EQ(last_msg_->reserved[234], 65)
      << "incorrect value for reserved[234], expected 65, is "
      << last_msg_->reserved[234];
  EXPECT_EQ(last_msg_->reserved[235], 173)
      << "incorrect value for reserved[235], expected 173, is "
      << last_msg_->reserved[235];
  EXPECT_EQ(last_msg_->reserved[236], 122)
      << "incorrect value for reserved[236], expected 122, is "
      << last_msg_->reserved[236];
  EXPECT_EQ(last_msg_->reserved[237], 143)
      << "incorrect value for reserved[237], expected 143, is "
      << last_msg_->reserved[237];
  EXPECT_EQ(last_msg_->reserved[238], 251)
      << "incorrect value for reserved[238], expected 251, is "
      << last_msg_->reserved[238];
  EXPECT_EQ(last_msg_->reserved[239], 156)
      << "incorrect value for reserved[239], expected 156, is "
      << last_msg_->reserved[239];
  EXPECT_EQ(last_msg_->reserved[240], 217)
      << "incorrect value for reserved[240], expected 217, is "
      << last_msg_->reserved[240];
  EXPECT_EQ(last_msg_->reserved[241], 67)
      << "incorrect value for reserved[241], expected 67, is "
      << last_msg_->reserved[241];
  EXPECT_EQ(last_msg_->reserved[242], 239)
      << "incorrect value for reserved[242], expected 239, is "
      << last_msg_->reserved[242];
  EXPECT_EQ(last_msg_->reserved[243], 219)
      << "incorrect value for reserved[243], expected 219, is "
      << last_msg_->reserved[243];
  EXPECT_EQ(last_msg_->reserved[244], 31)
      << "incorrect value for reserved[244], expected 31, is "
      << last_msg_->reserved[244];
  EXPECT_EQ(last_msg_->reserved[245], 224)
      << "incorrect value for reserved[245], expected 224, is "
      << last_msg_->reserved[245];
  EXPECT_EQ(last_msg_->reserved[246], 176)
      << "incorrect value for reserved[246], expected 176, is "
      << last_msg_->reserved[246];
  EXPECT_EQ(last_msg_->reserved[247], 129)
      << "incorrect value for reserved[247], expected 129, is "
      << last_msg_->reserved[247];
  EXPECT_EQ(last_msg_->reserved[248], 81)
      << "incorrect value for reserved[248], expected 81, is "
      << last_msg_->reserved[248];
  EXPECT_EQ(last_msg_->reserved[249], 80)
      << "incorrect value for reserved[249], expected 80, is "
      << last_msg_->reserved[249];
  EXPECT_LT((last_msg_->signal_error_rate * 100 - 8588.20019531 * 100), 0.05)
      << "incorrect value for signal_error_rate, expected 8588.20019531, is "
      << last_msg_->signal_error_rate;
  EXPECT_EQ(last_msg_->signal_strength, 103)
      << "incorrect value for signal_strength, expected 103, is "
      << last_msg_->signal_strength;
}
