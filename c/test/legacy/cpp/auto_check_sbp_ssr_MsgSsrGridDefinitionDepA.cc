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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGridDefinitionDepA.yaml by
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
#include <libsbp/legacy/ssr.h>
class Test_legacy_auto_check_sbp_ssr_MsgSsrGridDefinitionDepA0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_grid_definition_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_ssr_MsgSsrGridDefinitionDepA0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_grid_definition_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ssr_grid_definition_dep_a_t *>(
            last_msg_storage_)),
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
                      const msg_ssr_grid_definition_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_grid_definition_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, Test) {
  uint8_t encoded_frame[] = {
      85,  245, 5,   181, 247, 255, 11,  84,  171, 229, 132, 143, 46,  204, 52,
      92,  104, 25,  204, 182, 22,  98,  203, 123, 211, 38,  13,  253, 129, 173,
      171, 235, 253, 26,  203, 3,   120, 126, 42,  44,  39,  87,  69,  154, 13,
      28,  179, 32,  47,  36,  195, 39,  198, 134, 235, 134, 57,  120, 243, 151,
      35,  17,  201, 211, 125, 117, 164, 142, 101, 239, 144, 158, 239, 90,  56,
      71,  120, 67,  221, 114, 10,  190, 4,   230, 164, 171, 78,  185, 90,  46,
      177, 82,  228, 123, 222, 227, 145, 195, 219, 27,  56,  227, 246, 215, 144,
      158, 31,  214, 241, 254, 200, 86,  142, 89,  12,  121, 29,  124, 9,   19,
      153, 44,  35,  126, 14,  217, 65,  116, 26,  139, 122, 114, 90,  124, 81,
      0,   186, 246, 46,  98,  179, 243, 198, 217, 36,  30,  202, 12,  135, 61,
      42,  150, 221, 102, 83,  179, 43,  252, 81,  62,  126, 204, 195, 238, 18,
      128, 193, 53,  94,  99,  63,  182, 2,   186, 220, 77,  186, 224, 220, 13,
      212, 182, 88,  15,  151, 5,   93,  251, 164, 18,  228, 168, 226, 195, 44,
      170, 145, 36,  58,  96,  107, 144, 11,  228, 12,  163, 238, 247, 159, 189,
      1,   115, 65,  202, 121, 47,  193, 11,  96,  93,  72,  81,  207, 121, 19,
      151, 136, 233, 51,  133, 195, 77,  44,  147, 206, 120, 252, 77,  212, 68,
      60,  206, 106, 207, 243, 158, 94,  6,   3,   205, 92,  84,  2,   220, 50,
      61,  38,  141, 117, 108, 101, 76,  139,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_grid_definition_dep_a_t *test_msg =
      (msg_ssr_grid_definition_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->header.area_width = 43860;
  test_msg->header.lat_nw_corner_enc = 34021;
  test_msg->header.lon_nw_corner_enc = 11919;
  test_msg->header.num_msgs = 204;
  test_msg->header.region_size_inverse = 11;
  test_msg->header.seq_num = 52;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[0] = 92;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[1] = 104;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[2] = 25;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[3] = 204;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[4] = 182;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[5] = 22;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[6] = 98;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[7] = 203;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[8] = 123;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[9] = 211;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[10] = 38;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[11] = 13;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[12] = 253;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[13] = 129;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[14] = 173;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[15] = 171;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[16] = 235;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[17] = 253;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[18] = 26;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[19] = 203;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[20] = 3;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[21] = 120;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[22] = 126;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[23] = 42;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[24] = 44;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[25] = 39;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[26] = 87;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[27] = 69;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[28] = 154;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[29] = 13;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[30] = 28;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[31] = 179;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[32] = 32;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[33] = 47;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[34] = 36;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[35] = 195;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[36] = 39;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[37] = 198;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[38] = 134;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[39] = 235;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[40] = 134;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[41] = 57;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[42] = 120;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[43] = 243;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[44] = 151;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[45] = 35;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[46] = 17;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[47] = 201;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[48] = 211;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[49] = 125;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[50] = 117;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[51] = 164;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[52] = 142;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[53] = 101;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[54] = 239;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[55] = 144;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[56] = 158;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[57] = 239;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[58] = 90;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[59] = 56;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[60] = 71;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[61] = 120;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[62] = 67;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[63] = 221;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[64] = 114;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[65] = 10;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[66] = 190;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[67] = 4;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[68] = 230;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[69] = 164;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[70] = 171;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[71] = 78;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[72] = 185;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[73] = 90;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[74] = 46;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[75] = 177;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[76] = 82;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[77] = 228;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[78] = 123;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[79] = 222;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[80] = 227;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[81] = 145;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[82] = 195;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[83] = 219;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[84] = 27;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[85] = 56;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[86] = 227;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[87] = 246;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[88] = 215;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[89] = 144;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[90] = 158;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[91] = 31;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[92] = 214;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[93] = 241;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[94] = 254;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[95] = 200;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[96] = 86;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[97] = 142;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[98] = 89;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[99] = 12;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[100] = 121;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[101] = 29;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[102] = 124;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[103] = 9;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[104] = 19;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[105] = 153;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[106] = 44;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[107] = 35;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[108] = 126;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[109] = 14;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[110] = 217;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[111] = 65;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[112] = 116;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[113] = 26;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[114] = 139;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[115] = 122;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[116] = 114;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[117] = 90;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[118] = 124;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[119] = 81;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[120] = 0;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[121] = 186;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[122] = 246;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[123] = 46;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[124] = 98;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[125] = 179;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[126] = 243;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[127] = 198;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[128] = 217;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[129] = 36;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[130] = 30;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[131] = 202;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[132] = 12;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[133] = 135;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[134] = 61;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[135] = 42;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[136] = 150;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[137] = 221;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[138] = 102;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[139] = 83;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[140] = 179;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[141] = 43;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[142] = 252;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[143] = 81;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[144] = 62;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[145] = 126;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[146] = 204;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[147] = 195;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[148] = 238;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[149] = 18;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[150] = 128;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[151] = 193;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[152] = 53;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[153] = 94;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[154] = 99;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[155] = 63;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[156] = 182;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[157] = 2;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[158] = 186;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[159] = 220;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[160] = 77;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[161] = 186;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[162] = 224;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[163] = 220;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[164] = 13;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[165] = 212;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[166] = 182;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[167] = 88;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[168] = 15;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[169] = 151;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[170] = 5;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[171] = 93;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[172] = 251;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[173] = 164;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[174] = 18;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[175] = 228;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[176] = 168;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[177] = 226;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[178] = 195;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[179] = 44;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[180] = 170;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[181] = 145;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[182] = 36;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[183] = 58;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[184] = 96;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[185] = 107;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[186] = 144;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[187] = 11;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[188] = 228;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[189] = 12;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[190] = 163;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[191] = 238;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[192] = 247;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[193] = 159;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[194] = 189;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[195] = 1;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[196] = 115;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[197] = 65;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[198] = 202;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[199] = 121;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[200] = 47;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[201] = 193;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[202] = 11;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[203] = 96;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[204] = 93;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[205] = 72;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[206] = 81;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[207] = 207;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[208] = 121;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[209] = 19;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[210] = 151;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[211] = 136;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[212] = 233;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[213] = 51;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[214] = 133;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[215] = 195;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[216] = 77;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[217] = 44;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[218] = 147;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[219] = 206;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[220] = 120;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[221] = 252;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[222] = 77;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[223] = 212;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[224] = 68;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[225] = 60;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[226] = 206;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[227] = 106;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[228] = 207;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[229] = 243;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[230] = 158;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[231] = 94;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[232] = 6;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[233] = 3;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[234] = 205;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[235] = 92;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[236] = 84;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[237] = 2;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[238] = 220;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[239] = 50;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[240] = 61;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[241] = 38;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[242] = 141;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[243] = 117;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[244] = 108;
  if (sizeof(test_msg->rle_list) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->rle_list[0]));
  }
  test_msg->rle_list[245] = 101;

  EXPECT_EQ(send_message(0x5f5, 63413, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 63413);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->header.area_width, 43860)
      << "incorrect value for header.area_width, expected 43860, is "
      << last_msg_->header.area_width;
  EXPECT_EQ(last_msg_->header.lat_nw_corner_enc, 34021)
      << "incorrect value for header.lat_nw_corner_enc, expected 34021, is "
      << last_msg_->header.lat_nw_corner_enc;
  EXPECT_EQ(last_msg_->header.lon_nw_corner_enc, 11919)
      << "incorrect value for header.lon_nw_corner_enc, expected 11919, is "
      << last_msg_->header.lon_nw_corner_enc;
  EXPECT_EQ(last_msg_->header.num_msgs, 204)
      << "incorrect value for header.num_msgs, expected 204, is "
      << last_msg_->header.num_msgs;
  EXPECT_EQ(last_msg_->header.region_size_inverse, 11)
      << "incorrect value for header.region_size_inverse, expected 11, is "
      << last_msg_->header.region_size_inverse;
  EXPECT_EQ(last_msg_->header.seq_num, 52)
      << "incorrect value for header.seq_num, expected 52, is "
      << last_msg_->header.seq_num;
  EXPECT_EQ(last_msg_->rle_list[0], 92)
      << "incorrect value for rle_list[0], expected 92, is "
      << last_msg_->rle_list[0];
  EXPECT_EQ(last_msg_->rle_list[1], 104)
      << "incorrect value for rle_list[1], expected 104, is "
      << last_msg_->rle_list[1];
  EXPECT_EQ(last_msg_->rle_list[2], 25)
      << "incorrect value for rle_list[2], expected 25, is "
      << last_msg_->rle_list[2];
  EXPECT_EQ(last_msg_->rle_list[3], 204)
      << "incorrect value for rle_list[3], expected 204, is "
      << last_msg_->rle_list[3];
  EXPECT_EQ(last_msg_->rle_list[4], 182)
      << "incorrect value for rle_list[4], expected 182, is "
      << last_msg_->rle_list[4];
  EXPECT_EQ(last_msg_->rle_list[5], 22)
      << "incorrect value for rle_list[5], expected 22, is "
      << last_msg_->rle_list[5];
  EXPECT_EQ(last_msg_->rle_list[6], 98)
      << "incorrect value for rle_list[6], expected 98, is "
      << last_msg_->rle_list[6];
  EXPECT_EQ(last_msg_->rle_list[7], 203)
      << "incorrect value for rle_list[7], expected 203, is "
      << last_msg_->rle_list[7];
  EXPECT_EQ(last_msg_->rle_list[8], 123)
      << "incorrect value for rle_list[8], expected 123, is "
      << last_msg_->rle_list[8];
  EXPECT_EQ(last_msg_->rle_list[9], 211)
      << "incorrect value for rle_list[9], expected 211, is "
      << last_msg_->rle_list[9];
  EXPECT_EQ(last_msg_->rle_list[10], 38)
      << "incorrect value for rle_list[10], expected 38, is "
      << last_msg_->rle_list[10];
  EXPECT_EQ(last_msg_->rle_list[11], 13)
      << "incorrect value for rle_list[11], expected 13, is "
      << last_msg_->rle_list[11];
  EXPECT_EQ(last_msg_->rle_list[12], 253)
      << "incorrect value for rle_list[12], expected 253, is "
      << last_msg_->rle_list[12];
  EXPECT_EQ(last_msg_->rle_list[13], 129)
      << "incorrect value for rle_list[13], expected 129, is "
      << last_msg_->rle_list[13];
  EXPECT_EQ(last_msg_->rle_list[14], 173)
      << "incorrect value for rle_list[14], expected 173, is "
      << last_msg_->rle_list[14];
  EXPECT_EQ(last_msg_->rle_list[15], 171)
      << "incorrect value for rle_list[15], expected 171, is "
      << last_msg_->rle_list[15];
  EXPECT_EQ(last_msg_->rle_list[16], 235)
      << "incorrect value for rle_list[16], expected 235, is "
      << last_msg_->rle_list[16];
  EXPECT_EQ(last_msg_->rle_list[17], 253)
      << "incorrect value for rle_list[17], expected 253, is "
      << last_msg_->rle_list[17];
  EXPECT_EQ(last_msg_->rle_list[18], 26)
      << "incorrect value for rle_list[18], expected 26, is "
      << last_msg_->rle_list[18];
  EXPECT_EQ(last_msg_->rle_list[19], 203)
      << "incorrect value for rle_list[19], expected 203, is "
      << last_msg_->rle_list[19];
  EXPECT_EQ(last_msg_->rle_list[20], 3)
      << "incorrect value for rle_list[20], expected 3, is "
      << last_msg_->rle_list[20];
  EXPECT_EQ(last_msg_->rle_list[21], 120)
      << "incorrect value for rle_list[21], expected 120, is "
      << last_msg_->rle_list[21];
  EXPECT_EQ(last_msg_->rle_list[22], 126)
      << "incorrect value for rle_list[22], expected 126, is "
      << last_msg_->rle_list[22];
  EXPECT_EQ(last_msg_->rle_list[23], 42)
      << "incorrect value for rle_list[23], expected 42, is "
      << last_msg_->rle_list[23];
  EXPECT_EQ(last_msg_->rle_list[24], 44)
      << "incorrect value for rle_list[24], expected 44, is "
      << last_msg_->rle_list[24];
  EXPECT_EQ(last_msg_->rle_list[25], 39)
      << "incorrect value for rle_list[25], expected 39, is "
      << last_msg_->rle_list[25];
  EXPECT_EQ(last_msg_->rle_list[26], 87)
      << "incorrect value for rle_list[26], expected 87, is "
      << last_msg_->rle_list[26];
  EXPECT_EQ(last_msg_->rle_list[27], 69)
      << "incorrect value for rle_list[27], expected 69, is "
      << last_msg_->rle_list[27];
  EXPECT_EQ(last_msg_->rle_list[28], 154)
      << "incorrect value for rle_list[28], expected 154, is "
      << last_msg_->rle_list[28];
  EXPECT_EQ(last_msg_->rle_list[29], 13)
      << "incorrect value for rle_list[29], expected 13, is "
      << last_msg_->rle_list[29];
  EXPECT_EQ(last_msg_->rle_list[30], 28)
      << "incorrect value for rle_list[30], expected 28, is "
      << last_msg_->rle_list[30];
  EXPECT_EQ(last_msg_->rle_list[31], 179)
      << "incorrect value for rle_list[31], expected 179, is "
      << last_msg_->rle_list[31];
  EXPECT_EQ(last_msg_->rle_list[32], 32)
      << "incorrect value for rle_list[32], expected 32, is "
      << last_msg_->rle_list[32];
  EXPECT_EQ(last_msg_->rle_list[33], 47)
      << "incorrect value for rle_list[33], expected 47, is "
      << last_msg_->rle_list[33];
  EXPECT_EQ(last_msg_->rle_list[34], 36)
      << "incorrect value for rle_list[34], expected 36, is "
      << last_msg_->rle_list[34];
  EXPECT_EQ(last_msg_->rle_list[35], 195)
      << "incorrect value for rle_list[35], expected 195, is "
      << last_msg_->rle_list[35];
  EXPECT_EQ(last_msg_->rle_list[36], 39)
      << "incorrect value for rle_list[36], expected 39, is "
      << last_msg_->rle_list[36];
  EXPECT_EQ(last_msg_->rle_list[37], 198)
      << "incorrect value for rle_list[37], expected 198, is "
      << last_msg_->rle_list[37];
  EXPECT_EQ(last_msg_->rle_list[38], 134)
      << "incorrect value for rle_list[38], expected 134, is "
      << last_msg_->rle_list[38];
  EXPECT_EQ(last_msg_->rle_list[39], 235)
      << "incorrect value for rle_list[39], expected 235, is "
      << last_msg_->rle_list[39];
  EXPECT_EQ(last_msg_->rle_list[40], 134)
      << "incorrect value for rle_list[40], expected 134, is "
      << last_msg_->rle_list[40];
  EXPECT_EQ(last_msg_->rle_list[41], 57)
      << "incorrect value for rle_list[41], expected 57, is "
      << last_msg_->rle_list[41];
  EXPECT_EQ(last_msg_->rle_list[42], 120)
      << "incorrect value for rle_list[42], expected 120, is "
      << last_msg_->rle_list[42];
  EXPECT_EQ(last_msg_->rle_list[43], 243)
      << "incorrect value for rle_list[43], expected 243, is "
      << last_msg_->rle_list[43];
  EXPECT_EQ(last_msg_->rle_list[44], 151)
      << "incorrect value for rle_list[44], expected 151, is "
      << last_msg_->rle_list[44];
  EXPECT_EQ(last_msg_->rle_list[45], 35)
      << "incorrect value for rle_list[45], expected 35, is "
      << last_msg_->rle_list[45];
  EXPECT_EQ(last_msg_->rle_list[46], 17)
      << "incorrect value for rle_list[46], expected 17, is "
      << last_msg_->rle_list[46];
  EXPECT_EQ(last_msg_->rle_list[47], 201)
      << "incorrect value for rle_list[47], expected 201, is "
      << last_msg_->rle_list[47];
  EXPECT_EQ(last_msg_->rle_list[48], 211)
      << "incorrect value for rle_list[48], expected 211, is "
      << last_msg_->rle_list[48];
  EXPECT_EQ(last_msg_->rle_list[49], 125)
      << "incorrect value for rle_list[49], expected 125, is "
      << last_msg_->rle_list[49];
  EXPECT_EQ(last_msg_->rle_list[50], 117)
      << "incorrect value for rle_list[50], expected 117, is "
      << last_msg_->rle_list[50];
  EXPECT_EQ(last_msg_->rle_list[51], 164)
      << "incorrect value for rle_list[51], expected 164, is "
      << last_msg_->rle_list[51];
  EXPECT_EQ(last_msg_->rle_list[52], 142)
      << "incorrect value for rle_list[52], expected 142, is "
      << last_msg_->rle_list[52];
  EXPECT_EQ(last_msg_->rle_list[53], 101)
      << "incorrect value for rle_list[53], expected 101, is "
      << last_msg_->rle_list[53];
  EXPECT_EQ(last_msg_->rle_list[54], 239)
      << "incorrect value for rle_list[54], expected 239, is "
      << last_msg_->rle_list[54];
  EXPECT_EQ(last_msg_->rle_list[55], 144)
      << "incorrect value for rle_list[55], expected 144, is "
      << last_msg_->rle_list[55];
  EXPECT_EQ(last_msg_->rle_list[56], 158)
      << "incorrect value for rle_list[56], expected 158, is "
      << last_msg_->rle_list[56];
  EXPECT_EQ(last_msg_->rle_list[57], 239)
      << "incorrect value for rle_list[57], expected 239, is "
      << last_msg_->rle_list[57];
  EXPECT_EQ(last_msg_->rle_list[58], 90)
      << "incorrect value for rle_list[58], expected 90, is "
      << last_msg_->rle_list[58];
  EXPECT_EQ(last_msg_->rle_list[59], 56)
      << "incorrect value for rle_list[59], expected 56, is "
      << last_msg_->rle_list[59];
  EXPECT_EQ(last_msg_->rle_list[60], 71)
      << "incorrect value for rle_list[60], expected 71, is "
      << last_msg_->rle_list[60];
  EXPECT_EQ(last_msg_->rle_list[61], 120)
      << "incorrect value for rle_list[61], expected 120, is "
      << last_msg_->rle_list[61];
  EXPECT_EQ(last_msg_->rle_list[62], 67)
      << "incorrect value for rle_list[62], expected 67, is "
      << last_msg_->rle_list[62];
  EXPECT_EQ(last_msg_->rle_list[63], 221)
      << "incorrect value for rle_list[63], expected 221, is "
      << last_msg_->rle_list[63];
  EXPECT_EQ(last_msg_->rle_list[64], 114)
      << "incorrect value for rle_list[64], expected 114, is "
      << last_msg_->rle_list[64];
  EXPECT_EQ(last_msg_->rle_list[65], 10)
      << "incorrect value for rle_list[65], expected 10, is "
      << last_msg_->rle_list[65];
  EXPECT_EQ(last_msg_->rle_list[66], 190)
      << "incorrect value for rle_list[66], expected 190, is "
      << last_msg_->rle_list[66];
  EXPECT_EQ(last_msg_->rle_list[67], 4)
      << "incorrect value for rle_list[67], expected 4, is "
      << last_msg_->rle_list[67];
  EXPECT_EQ(last_msg_->rle_list[68], 230)
      << "incorrect value for rle_list[68], expected 230, is "
      << last_msg_->rle_list[68];
  EXPECT_EQ(last_msg_->rle_list[69], 164)
      << "incorrect value for rle_list[69], expected 164, is "
      << last_msg_->rle_list[69];
  EXPECT_EQ(last_msg_->rle_list[70], 171)
      << "incorrect value for rle_list[70], expected 171, is "
      << last_msg_->rle_list[70];
  EXPECT_EQ(last_msg_->rle_list[71], 78)
      << "incorrect value for rle_list[71], expected 78, is "
      << last_msg_->rle_list[71];
  EXPECT_EQ(last_msg_->rle_list[72], 185)
      << "incorrect value for rle_list[72], expected 185, is "
      << last_msg_->rle_list[72];
  EXPECT_EQ(last_msg_->rle_list[73], 90)
      << "incorrect value for rle_list[73], expected 90, is "
      << last_msg_->rle_list[73];
  EXPECT_EQ(last_msg_->rle_list[74], 46)
      << "incorrect value for rle_list[74], expected 46, is "
      << last_msg_->rle_list[74];
  EXPECT_EQ(last_msg_->rle_list[75], 177)
      << "incorrect value for rle_list[75], expected 177, is "
      << last_msg_->rle_list[75];
  EXPECT_EQ(last_msg_->rle_list[76], 82)
      << "incorrect value for rle_list[76], expected 82, is "
      << last_msg_->rle_list[76];
  EXPECT_EQ(last_msg_->rle_list[77], 228)
      << "incorrect value for rle_list[77], expected 228, is "
      << last_msg_->rle_list[77];
  EXPECT_EQ(last_msg_->rle_list[78], 123)
      << "incorrect value for rle_list[78], expected 123, is "
      << last_msg_->rle_list[78];
  EXPECT_EQ(last_msg_->rle_list[79], 222)
      << "incorrect value for rle_list[79], expected 222, is "
      << last_msg_->rle_list[79];
  EXPECT_EQ(last_msg_->rle_list[80], 227)
      << "incorrect value for rle_list[80], expected 227, is "
      << last_msg_->rle_list[80];
  EXPECT_EQ(last_msg_->rle_list[81], 145)
      << "incorrect value for rle_list[81], expected 145, is "
      << last_msg_->rle_list[81];
  EXPECT_EQ(last_msg_->rle_list[82], 195)
      << "incorrect value for rle_list[82], expected 195, is "
      << last_msg_->rle_list[82];
  EXPECT_EQ(last_msg_->rle_list[83], 219)
      << "incorrect value for rle_list[83], expected 219, is "
      << last_msg_->rle_list[83];
  EXPECT_EQ(last_msg_->rle_list[84], 27)
      << "incorrect value for rle_list[84], expected 27, is "
      << last_msg_->rle_list[84];
  EXPECT_EQ(last_msg_->rle_list[85], 56)
      << "incorrect value for rle_list[85], expected 56, is "
      << last_msg_->rle_list[85];
  EXPECT_EQ(last_msg_->rle_list[86], 227)
      << "incorrect value for rle_list[86], expected 227, is "
      << last_msg_->rle_list[86];
  EXPECT_EQ(last_msg_->rle_list[87], 246)
      << "incorrect value for rle_list[87], expected 246, is "
      << last_msg_->rle_list[87];
  EXPECT_EQ(last_msg_->rle_list[88], 215)
      << "incorrect value for rle_list[88], expected 215, is "
      << last_msg_->rle_list[88];
  EXPECT_EQ(last_msg_->rle_list[89], 144)
      << "incorrect value for rle_list[89], expected 144, is "
      << last_msg_->rle_list[89];
  EXPECT_EQ(last_msg_->rle_list[90], 158)
      << "incorrect value for rle_list[90], expected 158, is "
      << last_msg_->rle_list[90];
  EXPECT_EQ(last_msg_->rle_list[91], 31)
      << "incorrect value for rle_list[91], expected 31, is "
      << last_msg_->rle_list[91];
  EXPECT_EQ(last_msg_->rle_list[92], 214)
      << "incorrect value for rle_list[92], expected 214, is "
      << last_msg_->rle_list[92];
  EXPECT_EQ(last_msg_->rle_list[93], 241)
      << "incorrect value for rle_list[93], expected 241, is "
      << last_msg_->rle_list[93];
  EXPECT_EQ(last_msg_->rle_list[94], 254)
      << "incorrect value for rle_list[94], expected 254, is "
      << last_msg_->rle_list[94];
  EXPECT_EQ(last_msg_->rle_list[95], 200)
      << "incorrect value for rle_list[95], expected 200, is "
      << last_msg_->rle_list[95];
  EXPECT_EQ(last_msg_->rle_list[96], 86)
      << "incorrect value for rle_list[96], expected 86, is "
      << last_msg_->rle_list[96];
  EXPECT_EQ(last_msg_->rle_list[97], 142)
      << "incorrect value for rle_list[97], expected 142, is "
      << last_msg_->rle_list[97];
  EXPECT_EQ(last_msg_->rle_list[98], 89)
      << "incorrect value for rle_list[98], expected 89, is "
      << last_msg_->rle_list[98];
  EXPECT_EQ(last_msg_->rle_list[99], 12)
      << "incorrect value for rle_list[99], expected 12, is "
      << last_msg_->rle_list[99];
  EXPECT_EQ(last_msg_->rle_list[100], 121)
      << "incorrect value for rle_list[100], expected 121, is "
      << last_msg_->rle_list[100];
  EXPECT_EQ(last_msg_->rle_list[101], 29)
      << "incorrect value for rle_list[101], expected 29, is "
      << last_msg_->rle_list[101];
  EXPECT_EQ(last_msg_->rle_list[102], 124)
      << "incorrect value for rle_list[102], expected 124, is "
      << last_msg_->rle_list[102];
  EXPECT_EQ(last_msg_->rle_list[103], 9)
      << "incorrect value for rle_list[103], expected 9, is "
      << last_msg_->rle_list[103];
  EXPECT_EQ(last_msg_->rle_list[104], 19)
      << "incorrect value for rle_list[104], expected 19, is "
      << last_msg_->rle_list[104];
  EXPECT_EQ(last_msg_->rle_list[105], 153)
      << "incorrect value for rle_list[105], expected 153, is "
      << last_msg_->rle_list[105];
  EXPECT_EQ(last_msg_->rle_list[106], 44)
      << "incorrect value for rle_list[106], expected 44, is "
      << last_msg_->rle_list[106];
  EXPECT_EQ(last_msg_->rle_list[107], 35)
      << "incorrect value for rle_list[107], expected 35, is "
      << last_msg_->rle_list[107];
  EXPECT_EQ(last_msg_->rle_list[108], 126)
      << "incorrect value for rle_list[108], expected 126, is "
      << last_msg_->rle_list[108];
  EXPECT_EQ(last_msg_->rle_list[109], 14)
      << "incorrect value for rle_list[109], expected 14, is "
      << last_msg_->rle_list[109];
  EXPECT_EQ(last_msg_->rle_list[110], 217)
      << "incorrect value for rle_list[110], expected 217, is "
      << last_msg_->rle_list[110];
  EXPECT_EQ(last_msg_->rle_list[111], 65)
      << "incorrect value for rle_list[111], expected 65, is "
      << last_msg_->rle_list[111];
  EXPECT_EQ(last_msg_->rle_list[112], 116)
      << "incorrect value for rle_list[112], expected 116, is "
      << last_msg_->rle_list[112];
  EXPECT_EQ(last_msg_->rle_list[113], 26)
      << "incorrect value for rle_list[113], expected 26, is "
      << last_msg_->rle_list[113];
  EXPECT_EQ(last_msg_->rle_list[114], 139)
      << "incorrect value for rle_list[114], expected 139, is "
      << last_msg_->rle_list[114];
  EXPECT_EQ(last_msg_->rle_list[115], 122)
      << "incorrect value for rle_list[115], expected 122, is "
      << last_msg_->rle_list[115];
  EXPECT_EQ(last_msg_->rle_list[116], 114)
      << "incorrect value for rle_list[116], expected 114, is "
      << last_msg_->rle_list[116];
  EXPECT_EQ(last_msg_->rle_list[117], 90)
      << "incorrect value for rle_list[117], expected 90, is "
      << last_msg_->rle_list[117];
  EXPECT_EQ(last_msg_->rle_list[118], 124)
      << "incorrect value for rle_list[118], expected 124, is "
      << last_msg_->rle_list[118];
  EXPECT_EQ(last_msg_->rle_list[119], 81)
      << "incorrect value for rle_list[119], expected 81, is "
      << last_msg_->rle_list[119];
  EXPECT_EQ(last_msg_->rle_list[120], 0)
      << "incorrect value for rle_list[120], expected 0, is "
      << last_msg_->rle_list[120];
  EXPECT_EQ(last_msg_->rle_list[121], 186)
      << "incorrect value for rle_list[121], expected 186, is "
      << last_msg_->rle_list[121];
  EXPECT_EQ(last_msg_->rle_list[122], 246)
      << "incorrect value for rle_list[122], expected 246, is "
      << last_msg_->rle_list[122];
  EXPECT_EQ(last_msg_->rle_list[123], 46)
      << "incorrect value for rle_list[123], expected 46, is "
      << last_msg_->rle_list[123];
  EXPECT_EQ(last_msg_->rle_list[124], 98)
      << "incorrect value for rle_list[124], expected 98, is "
      << last_msg_->rle_list[124];
  EXPECT_EQ(last_msg_->rle_list[125], 179)
      << "incorrect value for rle_list[125], expected 179, is "
      << last_msg_->rle_list[125];
  EXPECT_EQ(last_msg_->rle_list[126], 243)
      << "incorrect value for rle_list[126], expected 243, is "
      << last_msg_->rle_list[126];
  EXPECT_EQ(last_msg_->rle_list[127], 198)
      << "incorrect value for rle_list[127], expected 198, is "
      << last_msg_->rle_list[127];
  EXPECT_EQ(last_msg_->rle_list[128], 217)
      << "incorrect value for rle_list[128], expected 217, is "
      << last_msg_->rle_list[128];
  EXPECT_EQ(last_msg_->rle_list[129], 36)
      << "incorrect value for rle_list[129], expected 36, is "
      << last_msg_->rle_list[129];
  EXPECT_EQ(last_msg_->rle_list[130], 30)
      << "incorrect value for rle_list[130], expected 30, is "
      << last_msg_->rle_list[130];
  EXPECT_EQ(last_msg_->rle_list[131], 202)
      << "incorrect value for rle_list[131], expected 202, is "
      << last_msg_->rle_list[131];
  EXPECT_EQ(last_msg_->rle_list[132], 12)
      << "incorrect value for rle_list[132], expected 12, is "
      << last_msg_->rle_list[132];
  EXPECT_EQ(last_msg_->rle_list[133], 135)
      << "incorrect value for rle_list[133], expected 135, is "
      << last_msg_->rle_list[133];
  EXPECT_EQ(last_msg_->rle_list[134], 61)
      << "incorrect value for rle_list[134], expected 61, is "
      << last_msg_->rle_list[134];
  EXPECT_EQ(last_msg_->rle_list[135], 42)
      << "incorrect value for rle_list[135], expected 42, is "
      << last_msg_->rle_list[135];
  EXPECT_EQ(last_msg_->rle_list[136], 150)
      << "incorrect value for rle_list[136], expected 150, is "
      << last_msg_->rle_list[136];
  EXPECT_EQ(last_msg_->rle_list[137], 221)
      << "incorrect value for rle_list[137], expected 221, is "
      << last_msg_->rle_list[137];
  EXPECT_EQ(last_msg_->rle_list[138], 102)
      << "incorrect value for rle_list[138], expected 102, is "
      << last_msg_->rle_list[138];
  EXPECT_EQ(last_msg_->rle_list[139], 83)
      << "incorrect value for rle_list[139], expected 83, is "
      << last_msg_->rle_list[139];
  EXPECT_EQ(last_msg_->rle_list[140], 179)
      << "incorrect value for rle_list[140], expected 179, is "
      << last_msg_->rle_list[140];
  EXPECT_EQ(last_msg_->rle_list[141], 43)
      << "incorrect value for rle_list[141], expected 43, is "
      << last_msg_->rle_list[141];
  EXPECT_EQ(last_msg_->rle_list[142], 252)
      << "incorrect value for rle_list[142], expected 252, is "
      << last_msg_->rle_list[142];
  EXPECT_EQ(last_msg_->rle_list[143], 81)
      << "incorrect value for rle_list[143], expected 81, is "
      << last_msg_->rle_list[143];
  EXPECT_EQ(last_msg_->rle_list[144], 62)
      << "incorrect value for rle_list[144], expected 62, is "
      << last_msg_->rle_list[144];
  EXPECT_EQ(last_msg_->rle_list[145], 126)
      << "incorrect value for rle_list[145], expected 126, is "
      << last_msg_->rle_list[145];
  EXPECT_EQ(last_msg_->rle_list[146], 204)
      << "incorrect value for rle_list[146], expected 204, is "
      << last_msg_->rle_list[146];
  EXPECT_EQ(last_msg_->rle_list[147], 195)
      << "incorrect value for rle_list[147], expected 195, is "
      << last_msg_->rle_list[147];
  EXPECT_EQ(last_msg_->rle_list[148], 238)
      << "incorrect value for rle_list[148], expected 238, is "
      << last_msg_->rle_list[148];
  EXPECT_EQ(last_msg_->rle_list[149], 18)
      << "incorrect value for rle_list[149], expected 18, is "
      << last_msg_->rle_list[149];
  EXPECT_EQ(last_msg_->rle_list[150], 128)
      << "incorrect value for rle_list[150], expected 128, is "
      << last_msg_->rle_list[150];
  EXPECT_EQ(last_msg_->rle_list[151], 193)
      << "incorrect value for rle_list[151], expected 193, is "
      << last_msg_->rle_list[151];
  EXPECT_EQ(last_msg_->rle_list[152], 53)
      << "incorrect value for rle_list[152], expected 53, is "
      << last_msg_->rle_list[152];
  EXPECT_EQ(last_msg_->rle_list[153], 94)
      << "incorrect value for rle_list[153], expected 94, is "
      << last_msg_->rle_list[153];
  EXPECT_EQ(last_msg_->rle_list[154], 99)
      << "incorrect value for rle_list[154], expected 99, is "
      << last_msg_->rle_list[154];
  EXPECT_EQ(last_msg_->rle_list[155], 63)
      << "incorrect value for rle_list[155], expected 63, is "
      << last_msg_->rle_list[155];
  EXPECT_EQ(last_msg_->rle_list[156], 182)
      << "incorrect value for rle_list[156], expected 182, is "
      << last_msg_->rle_list[156];
  EXPECT_EQ(last_msg_->rle_list[157], 2)
      << "incorrect value for rle_list[157], expected 2, is "
      << last_msg_->rle_list[157];
  EXPECT_EQ(last_msg_->rle_list[158], 186)
      << "incorrect value for rle_list[158], expected 186, is "
      << last_msg_->rle_list[158];
  EXPECT_EQ(last_msg_->rle_list[159], 220)
      << "incorrect value for rle_list[159], expected 220, is "
      << last_msg_->rle_list[159];
  EXPECT_EQ(last_msg_->rle_list[160], 77)
      << "incorrect value for rle_list[160], expected 77, is "
      << last_msg_->rle_list[160];
  EXPECT_EQ(last_msg_->rle_list[161], 186)
      << "incorrect value for rle_list[161], expected 186, is "
      << last_msg_->rle_list[161];
  EXPECT_EQ(last_msg_->rle_list[162], 224)
      << "incorrect value for rle_list[162], expected 224, is "
      << last_msg_->rle_list[162];
  EXPECT_EQ(last_msg_->rle_list[163], 220)
      << "incorrect value for rle_list[163], expected 220, is "
      << last_msg_->rle_list[163];
  EXPECT_EQ(last_msg_->rle_list[164], 13)
      << "incorrect value for rle_list[164], expected 13, is "
      << last_msg_->rle_list[164];
  EXPECT_EQ(last_msg_->rle_list[165], 212)
      << "incorrect value for rle_list[165], expected 212, is "
      << last_msg_->rle_list[165];
  EXPECT_EQ(last_msg_->rle_list[166], 182)
      << "incorrect value for rle_list[166], expected 182, is "
      << last_msg_->rle_list[166];
  EXPECT_EQ(last_msg_->rle_list[167], 88)
      << "incorrect value for rle_list[167], expected 88, is "
      << last_msg_->rle_list[167];
  EXPECT_EQ(last_msg_->rle_list[168], 15)
      << "incorrect value for rle_list[168], expected 15, is "
      << last_msg_->rle_list[168];
  EXPECT_EQ(last_msg_->rle_list[169], 151)
      << "incorrect value for rle_list[169], expected 151, is "
      << last_msg_->rle_list[169];
  EXPECT_EQ(last_msg_->rle_list[170], 5)
      << "incorrect value for rle_list[170], expected 5, is "
      << last_msg_->rle_list[170];
  EXPECT_EQ(last_msg_->rle_list[171], 93)
      << "incorrect value for rle_list[171], expected 93, is "
      << last_msg_->rle_list[171];
  EXPECT_EQ(last_msg_->rle_list[172], 251)
      << "incorrect value for rle_list[172], expected 251, is "
      << last_msg_->rle_list[172];
  EXPECT_EQ(last_msg_->rle_list[173], 164)
      << "incorrect value for rle_list[173], expected 164, is "
      << last_msg_->rle_list[173];
  EXPECT_EQ(last_msg_->rle_list[174], 18)
      << "incorrect value for rle_list[174], expected 18, is "
      << last_msg_->rle_list[174];
  EXPECT_EQ(last_msg_->rle_list[175], 228)
      << "incorrect value for rle_list[175], expected 228, is "
      << last_msg_->rle_list[175];
  EXPECT_EQ(last_msg_->rle_list[176], 168)
      << "incorrect value for rle_list[176], expected 168, is "
      << last_msg_->rle_list[176];
  EXPECT_EQ(last_msg_->rle_list[177], 226)
      << "incorrect value for rle_list[177], expected 226, is "
      << last_msg_->rle_list[177];
  EXPECT_EQ(last_msg_->rle_list[178], 195)
      << "incorrect value for rle_list[178], expected 195, is "
      << last_msg_->rle_list[178];
  EXPECT_EQ(last_msg_->rle_list[179], 44)
      << "incorrect value for rle_list[179], expected 44, is "
      << last_msg_->rle_list[179];
  EXPECT_EQ(last_msg_->rle_list[180], 170)
      << "incorrect value for rle_list[180], expected 170, is "
      << last_msg_->rle_list[180];
  EXPECT_EQ(last_msg_->rle_list[181], 145)
      << "incorrect value for rle_list[181], expected 145, is "
      << last_msg_->rle_list[181];
  EXPECT_EQ(last_msg_->rle_list[182], 36)
      << "incorrect value for rle_list[182], expected 36, is "
      << last_msg_->rle_list[182];
  EXPECT_EQ(last_msg_->rle_list[183], 58)
      << "incorrect value for rle_list[183], expected 58, is "
      << last_msg_->rle_list[183];
  EXPECT_EQ(last_msg_->rle_list[184], 96)
      << "incorrect value for rle_list[184], expected 96, is "
      << last_msg_->rle_list[184];
  EXPECT_EQ(last_msg_->rle_list[185], 107)
      << "incorrect value for rle_list[185], expected 107, is "
      << last_msg_->rle_list[185];
  EXPECT_EQ(last_msg_->rle_list[186], 144)
      << "incorrect value for rle_list[186], expected 144, is "
      << last_msg_->rle_list[186];
  EXPECT_EQ(last_msg_->rle_list[187], 11)
      << "incorrect value for rle_list[187], expected 11, is "
      << last_msg_->rle_list[187];
  EXPECT_EQ(last_msg_->rle_list[188], 228)
      << "incorrect value for rle_list[188], expected 228, is "
      << last_msg_->rle_list[188];
  EXPECT_EQ(last_msg_->rle_list[189], 12)
      << "incorrect value for rle_list[189], expected 12, is "
      << last_msg_->rle_list[189];
  EXPECT_EQ(last_msg_->rle_list[190], 163)
      << "incorrect value for rle_list[190], expected 163, is "
      << last_msg_->rle_list[190];
  EXPECT_EQ(last_msg_->rle_list[191], 238)
      << "incorrect value for rle_list[191], expected 238, is "
      << last_msg_->rle_list[191];
  EXPECT_EQ(last_msg_->rle_list[192], 247)
      << "incorrect value for rle_list[192], expected 247, is "
      << last_msg_->rle_list[192];
  EXPECT_EQ(last_msg_->rle_list[193], 159)
      << "incorrect value for rle_list[193], expected 159, is "
      << last_msg_->rle_list[193];
  EXPECT_EQ(last_msg_->rle_list[194], 189)
      << "incorrect value for rle_list[194], expected 189, is "
      << last_msg_->rle_list[194];
  EXPECT_EQ(last_msg_->rle_list[195], 1)
      << "incorrect value for rle_list[195], expected 1, is "
      << last_msg_->rle_list[195];
  EXPECT_EQ(last_msg_->rle_list[196], 115)
      << "incorrect value for rle_list[196], expected 115, is "
      << last_msg_->rle_list[196];
  EXPECT_EQ(last_msg_->rle_list[197], 65)
      << "incorrect value for rle_list[197], expected 65, is "
      << last_msg_->rle_list[197];
  EXPECT_EQ(last_msg_->rle_list[198], 202)
      << "incorrect value for rle_list[198], expected 202, is "
      << last_msg_->rle_list[198];
  EXPECT_EQ(last_msg_->rle_list[199], 121)
      << "incorrect value for rle_list[199], expected 121, is "
      << last_msg_->rle_list[199];
  EXPECT_EQ(last_msg_->rle_list[200], 47)
      << "incorrect value for rle_list[200], expected 47, is "
      << last_msg_->rle_list[200];
  EXPECT_EQ(last_msg_->rle_list[201], 193)
      << "incorrect value for rle_list[201], expected 193, is "
      << last_msg_->rle_list[201];
  EXPECT_EQ(last_msg_->rle_list[202], 11)
      << "incorrect value for rle_list[202], expected 11, is "
      << last_msg_->rle_list[202];
  EXPECT_EQ(last_msg_->rle_list[203], 96)
      << "incorrect value for rle_list[203], expected 96, is "
      << last_msg_->rle_list[203];
  EXPECT_EQ(last_msg_->rle_list[204], 93)
      << "incorrect value for rle_list[204], expected 93, is "
      << last_msg_->rle_list[204];
  EXPECT_EQ(last_msg_->rle_list[205], 72)
      << "incorrect value for rle_list[205], expected 72, is "
      << last_msg_->rle_list[205];
  EXPECT_EQ(last_msg_->rle_list[206], 81)
      << "incorrect value for rle_list[206], expected 81, is "
      << last_msg_->rle_list[206];
  EXPECT_EQ(last_msg_->rle_list[207], 207)
      << "incorrect value for rle_list[207], expected 207, is "
      << last_msg_->rle_list[207];
  EXPECT_EQ(last_msg_->rle_list[208], 121)
      << "incorrect value for rle_list[208], expected 121, is "
      << last_msg_->rle_list[208];
  EXPECT_EQ(last_msg_->rle_list[209], 19)
      << "incorrect value for rle_list[209], expected 19, is "
      << last_msg_->rle_list[209];
  EXPECT_EQ(last_msg_->rle_list[210], 151)
      << "incorrect value for rle_list[210], expected 151, is "
      << last_msg_->rle_list[210];
  EXPECT_EQ(last_msg_->rle_list[211], 136)
      << "incorrect value for rle_list[211], expected 136, is "
      << last_msg_->rle_list[211];
  EXPECT_EQ(last_msg_->rle_list[212], 233)
      << "incorrect value for rle_list[212], expected 233, is "
      << last_msg_->rle_list[212];
  EXPECT_EQ(last_msg_->rle_list[213], 51)
      << "incorrect value for rle_list[213], expected 51, is "
      << last_msg_->rle_list[213];
  EXPECT_EQ(last_msg_->rle_list[214], 133)
      << "incorrect value for rle_list[214], expected 133, is "
      << last_msg_->rle_list[214];
  EXPECT_EQ(last_msg_->rle_list[215], 195)
      << "incorrect value for rle_list[215], expected 195, is "
      << last_msg_->rle_list[215];
  EXPECT_EQ(last_msg_->rle_list[216], 77)
      << "incorrect value for rle_list[216], expected 77, is "
      << last_msg_->rle_list[216];
  EXPECT_EQ(last_msg_->rle_list[217], 44)
      << "incorrect value for rle_list[217], expected 44, is "
      << last_msg_->rle_list[217];
  EXPECT_EQ(last_msg_->rle_list[218], 147)
      << "incorrect value for rle_list[218], expected 147, is "
      << last_msg_->rle_list[218];
  EXPECT_EQ(last_msg_->rle_list[219], 206)
      << "incorrect value for rle_list[219], expected 206, is "
      << last_msg_->rle_list[219];
  EXPECT_EQ(last_msg_->rle_list[220], 120)
      << "incorrect value for rle_list[220], expected 120, is "
      << last_msg_->rle_list[220];
  EXPECT_EQ(last_msg_->rle_list[221], 252)
      << "incorrect value for rle_list[221], expected 252, is "
      << last_msg_->rle_list[221];
  EXPECT_EQ(last_msg_->rle_list[222], 77)
      << "incorrect value for rle_list[222], expected 77, is "
      << last_msg_->rle_list[222];
  EXPECT_EQ(last_msg_->rle_list[223], 212)
      << "incorrect value for rle_list[223], expected 212, is "
      << last_msg_->rle_list[223];
  EXPECT_EQ(last_msg_->rle_list[224], 68)
      << "incorrect value for rle_list[224], expected 68, is "
      << last_msg_->rle_list[224];
  EXPECT_EQ(last_msg_->rle_list[225], 60)
      << "incorrect value for rle_list[225], expected 60, is "
      << last_msg_->rle_list[225];
  EXPECT_EQ(last_msg_->rle_list[226], 206)
      << "incorrect value for rle_list[226], expected 206, is "
      << last_msg_->rle_list[226];
  EXPECT_EQ(last_msg_->rle_list[227], 106)
      << "incorrect value for rle_list[227], expected 106, is "
      << last_msg_->rle_list[227];
  EXPECT_EQ(last_msg_->rle_list[228], 207)
      << "incorrect value for rle_list[228], expected 207, is "
      << last_msg_->rle_list[228];
  EXPECT_EQ(last_msg_->rle_list[229], 243)
      << "incorrect value for rle_list[229], expected 243, is "
      << last_msg_->rle_list[229];
  EXPECT_EQ(last_msg_->rle_list[230], 158)
      << "incorrect value for rle_list[230], expected 158, is "
      << last_msg_->rle_list[230];
  EXPECT_EQ(last_msg_->rle_list[231], 94)
      << "incorrect value for rle_list[231], expected 94, is "
      << last_msg_->rle_list[231];
  EXPECT_EQ(last_msg_->rle_list[232], 6)
      << "incorrect value for rle_list[232], expected 6, is "
      << last_msg_->rle_list[232];
  EXPECT_EQ(last_msg_->rle_list[233], 3)
      << "incorrect value for rle_list[233], expected 3, is "
      << last_msg_->rle_list[233];
  EXPECT_EQ(last_msg_->rle_list[234], 205)
      << "incorrect value for rle_list[234], expected 205, is "
      << last_msg_->rle_list[234];
  EXPECT_EQ(last_msg_->rle_list[235], 92)
      << "incorrect value for rle_list[235], expected 92, is "
      << last_msg_->rle_list[235];
  EXPECT_EQ(last_msg_->rle_list[236], 84)
      << "incorrect value for rle_list[236], expected 84, is "
      << last_msg_->rle_list[236];
  EXPECT_EQ(last_msg_->rle_list[237], 2)
      << "incorrect value for rle_list[237], expected 2, is "
      << last_msg_->rle_list[237];
  EXPECT_EQ(last_msg_->rle_list[238], 220)
      << "incorrect value for rle_list[238], expected 220, is "
      << last_msg_->rle_list[238];
  EXPECT_EQ(last_msg_->rle_list[239], 50)
      << "incorrect value for rle_list[239], expected 50, is "
      << last_msg_->rle_list[239];
  EXPECT_EQ(last_msg_->rle_list[240], 61)
      << "incorrect value for rle_list[240], expected 61, is "
      << last_msg_->rle_list[240];
  EXPECT_EQ(last_msg_->rle_list[241], 38)
      << "incorrect value for rle_list[241], expected 38, is "
      << last_msg_->rle_list[241];
  EXPECT_EQ(last_msg_->rle_list[242], 141)
      << "incorrect value for rle_list[242], expected 141, is "
      << last_msg_->rle_list[242];
  EXPECT_EQ(last_msg_->rle_list[243], 117)
      << "incorrect value for rle_list[243], expected 117, is "
      << last_msg_->rle_list[243];
  EXPECT_EQ(last_msg_->rle_list[244], 108)
      << "incorrect value for rle_list[244], expected 108, is "
      << last_msg_->rle_list[244];
  EXPECT_EQ(last_msg_->rle_list[245], 101)
      << "incorrect value for rle_list[245], expected 101, is "
      << last_msg_->rle_list[245];
}
