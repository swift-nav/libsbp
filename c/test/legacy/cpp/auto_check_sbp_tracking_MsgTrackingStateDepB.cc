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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDepB.yaml by
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
#include <libsbp/legacy/tracking.h>
class Test_legacy_auto_check_sbp_tracking_MsgTrackingStateDepB0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_tracking_state_dep_b_t> {
 public:
  Test_legacy_auto_check_sbp_tracking_MsgTrackingStateDepB0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_tracking_state_dep_b_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_tracking_state_dep_b_t *>(last_msg_storage_)),
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
                      const msg_tracking_state_dep_b_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_tracking_state_dep_b_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_tracking_MsgTrackingStateDepB0, Test) {
  uint8_t encoded_frame[] = {
      85,  19,  0,   242, 241, 252, 115, 183, 227, 63,  68,  154, 1,   183, 69,
      255, 175, 121, 43,  222, 51,  67,  35,  69,  78,  240, 5,   53,  20,  51,
      211, 54,  69,  153, 130, 237, 66,  155, 51,  227, 71,  69,  53,  242, 136,
      161, 190, 205, 188, 6,   70,  153, 125, 255, 142, 149, 154, 217, 184, 69,
      248, 102, 95,  31,  76,  154, 33,  169, 69,  131, 115, 141, 27,  12,  154,
      225, 200, 69,  208, 44,  147, 39,  23,  51,  3,   66,  69,  237, 159, 251,
      49,  203, 51,  99,  102, 69,  70,  214, 87,  128, 206, 154, 121, 186, 69,
      14,  206, 111, 218, 19,  154, 121, 169, 69,  216, 98,  209, 54,  2,   154,
      25,  219, 67,  200, 133, 99,  7,   34,  102, 198, 232, 68,  155, 43,  85,
      135, 46,  154, 177, 170, 69,  155, 3,   83,  171, 201, 154, 241, 232, 69,
      121, 43,  197, 16,  19,  154, 241, 222, 69,  128, 245, 53,  63,  176, 51,
      115, 66,  69,  36,  20,  61,  153, 51,  154, 73,  134, 69,  46,  82,  116,
      140, 22,  51,  147, 37,  69,  177, 67,  146, 96,  143, 205, 76,  107, 68,
      220, 51,  160, 201, 251, 102, 102, 192, 68,  168, 194, 2,   161, 220, 102,
      102, 180, 68,  69,  8,   9,   125, 178, 102, 70,  134, 68,  185, 20,  135,
      186, 171, 51,  163, 4,   69,  18,  124, 155, 85,  170, 205, 208, 13,  70,
      57,  244, 206, 255, 186, 154, 105, 149, 69,  165, 199, 93,  181, 175, 51,
      67,  64,  69,  6,   28,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_tracking_state_dep_b_t *test_msg =
      (msg_tracking_state_dep_b_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[0].cn0 = 5856.2001953125;
  test_msg->states[0].sid.code = 63;
  test_msg->states[0].sid.reserved = 68;
  test_msg->states[0].sid.sat = 58295;
  test_msg->states[0].state = 115;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[1].cn0 = 2612.199951171875;
  test_msg->states[1].sid.code = 43;
  test_msg->states[1].sid.reserved = 222;
  test_msg->states[1].sid.sat = 31151;
  test_msg->states[1].state = 255;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[2].cn0 = 2925.199951171875;
  test_msg->states[2].sid.code = 53;
  test_msg->states[2].sid.reserved = 20;
  test_msg->states[2].sid.sat = 1520;
  test_msg->states[2].state = 78;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[3].cn0 = 3198.199951171875;
  test_msg->states[3].sid.code = 66;
  test_msg->states[3].sid.reserved = 155;
  test_msg->states[3].sid.sat = 60802;
  test_msg->states[3].state = 153;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[4].cn0 = 8623.2001953125;
  test_msg->states[4].sid.code = 161;
  test_msg->states[4].sid.reserved = 190;
  test_msg->states[4].sid.sat = 35058;
  test_msg->states[4].state = 53;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[5].cn0 = 5915.2001953125;
  test_msg->states[5].sid.code = 142;
  test_msg->states[5].sid.reserved = 149;
  test_msg->states[5].sid.sat = 65405;
  test_msg->states[5].state = 153;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[6].cn0 = 5412.2001953125;
  test_msg->states[6].sid.code = 31;
  test_msg->states[6].sid.reserved = 76;
  test_msg->states[6].sid.sat = 24422;
  test_msg->states[6].state = 248;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[7].cn0 = 6428.2001953125;
  test_msg->states[7].sid.code = 27;
  test_msg->states[7].sid.reserved = 12;
  test_msg->states[7].sid.sat = 36211;
  test_msg->states[7].state = 131;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[8].cn0 = 3104.199951171875;
  test_msg->states[8].sid.code = 39;
  test_msg->states[8].sid.reserved = 23;
  test_msg->states[8].sid.sat = 37676;
  test_msg->states[8].state = 208;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[9].cn0 = 3686.199951171875;
  test_msg->states[9].sid.code = 49;
  test_msg->states[9].sid.reserved = 203;
  test_msg->states[9].sid.sat = 64415;
  test_msg->states[9].state = 237;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[10].cn0 = 5967.2001953125;
  test_msg->states[10].sid.code = 128;
  test_msg->states[10].sid.reserved = 206;
  test_msg->states[10].sid.sat = 22486;
  test_msg->states[10].state = 70;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[11].cn0 = 5423.2001953125;
  test_msg->states[11].sid.code = 218;
  test_msg->states[11].sid.reserved = 19;
  test_msg->states[11].sid.sat = 28622;
  test_msg->states[11].state = 14;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[12].cn0 = 438.20001220703125;
  test_msg->states[12].sid.code = 54;
  test_msg->states[12].sid.reserved = 2;
  test_msg->states[12].sid.sat = 53602;
  test_msg->states[12].state = 216;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[13].cn0 = 1862.199951171875;
  test_msg->states[13].sid.code = 7;
  test_msg->states[13].sid.reserved = 34;
  test_msg->states[13].sid.sat = 25477;
  test_msg->states[13].state = 200;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[14].cn0 = 5462.2001953125;
  test_msg->states[14].sid.code = 135;
  test_msg->states[14].sid.reserved = 46;
  test_msg->states[14].sid.sat = 21803;
  test_msg->states[14].state = 155;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[15].cn0 = 7454.2001953125;
  test_msg->states[15].sid.code = 171;
  test_msg->states[15].sid.reserved = 201;
  test_msg->states[15].sid.sat = 21251;
  test_msg->states[15].state = 155;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[16].cn0 = 7134.2001953125;
  test_msg->states[16].sid.code = 16;
  test_msg->states[16].sid.reserved = 19;
  test_msg->states[16].sid.sat = 50475;
  test_msg->states[16].state = 121;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[17].cn0 = 3111.199951171875;
  test_msg->states[17].sid.code = 63;
  test_msg->states[17].sid.reserved = 176;
  test_msg->states[17].sid.sat = 13813;
  test_msg->states[17].state = 128;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[18].cn0 = 4297.2001953125;
  test_msg->states[18].sid.code = 153;
  test_msg->states[18].sid.reserved = 51;
  test_msg->states[18].sid.sat = 15636;
  test_msg->states[18].state = 36;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[19].cn0 = 2649.199951171875;
  test_msg->states[19].sid.code = 140;
  test_msg->states[19].sid.reserved = 22;
  test_msg->states[19].sid.sat = 29778;
  test_msg->states[19].state = 46;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[20].cn0 = 941.2000122070312;
  test_msg->states[20].sid.code = 96;
  test_msg->states[20].sid.reserved = 143;
  test_msg->states[20].sid.sat = 37443;
  test_msg->states[20].state = 177;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[21].cn0 = 1539.199951171875;
  test_msg->states[21].sid.code = 201;
  test_msg->states[21].sid.reserved = 251;
  test_msg->states[21].sid.sat = 41011;
  test_msg->states[21].state = 220;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[22].cn0 = 1443.199951171875;
  test_msg->states[22].sid.code = 161;
  test_msg->states[22].sid.reserved = 220;
  test_msg->states[22].sid.sat = 706;
  test_msg->states[22].state = 168;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[23].cn0 = 1074.199951171875;
  test_msg->states[23].sid.code = 125;
  test_msg->states[23].sid.reserved = 178;
  test_msg->states[23].sid.sat = 2312;
  test_msg->states[23].state = 69;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[24].cn0 = 2122.199951171875;
  test_msg->states[24].sid.code = 186;
  test_msg->states[24].sid.reserved = 171;
  test_msg->states[24].sid.sat = 34580;
  test_msg->states[24].state = 185;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[25].cn0 = 9076.2001953125;
  test_msg->states[25].sid.code = 85;
  test_msg->states[25].sid.reserved = 170;
  test_msg->states[25].sid.sat = 39804;
  test_msg->states[25].state = 18;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[26].cn0 = 4781.2001953125;
  test_msg->states[26].sid.code = 255;
  test_msg->states[26].sid.reserved = 186;
  test_msg->states[26].sid.sat = 52980;
  test_msg->states[26].state = 57;
  if (sizeof(test_msg->states) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->states[0]));
  }
  test_msg->states[27].cn0 = 3076.199951171875;
  test_msg->states[27].sid.code = 181;
  test_msg->states[27].sid.reserved = 175;
  test_msg->states[27].sid.sat = 24007;
  test_msg->states[27].state = 165;

  EXPECT_EQ(send_message(0x13, 61938, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 61938);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->states[0].cn0 * 100 - 5856.20019531 * 100), 0.05)
      << "incorrect value for states[0].cn0, expected 5856.20019531, is "
      << last_msg_->states[0].cn0;
  EXPECT_EQ(last_msg_->states[0].sid.code, 63)
      << "incorrect value for states[0].sid.code, expected 63, is "
      << last_msg_->states[0].sid.code;
  EXPECT_EQ(last_msg_->states[0].sid.reserved, 68)
      << "incorrect value for states[0].sid.reserved, expected 68, is "
      << last_msg_->states[0].sid.reserved;
  EXPECT_EQ(last_msg_->states[0].sid.sat, 58295)
      << "incorrect value for states[0].sid.sat, expected 58295, is "
      << last_msg_->states[0].sid.sat;
  EXPECT_EQ(last_msg_->states[0].state, 115)
      << "incorrect value for states[0].state, expected 115, is "
      << last_msg_->states[0].state;
  EXPECT_LT((last_msg_->states[1].cn0 * 100 - 2612.19995117 * 100), 0.05)
      << "incorrect value for states[1].cn0, expected 2612.19995117, is "
      << last_msg_->states[1].cn0;
  EXPECT_EQ(last_msg_->states[1].sid.code, 43)
      << "incorrect value for states[1].sid.code, expected 43, is "
      << last_msg_->states[1].sid.code;
  EXPECT_EQ(last_msg_->states[1].sid.reserved, 222)
      << "incorrect value for states[1].sid.reserved, expected 222, is "
      << last_msg_->states[1].sid.reserved;
  EXPECT_EQ(last_msg_->states[1].sid.sat, 31151)
      << "incorrect value for states[1].sid.sat, expected 31151, is "
      << last_msg_->states[1].sid.sat;
  EXPECT_EQ(last_msg_->states[1].state, 255)
      << "incorrect value for states[1].state, expected 255, is "
      << last_msg_->states[1].state;
  EXPECT_LT((last_msg_->states[2].cn0 * 100 - 2925.19995117 * 100), 0.05)
      << "incorrect value for states[2].cn0, expected 2925.19995117, is "
      << last_msg_->states[2].cn0;
  EXPECT_EQ(last_msg_->states[2].sid.code, 53)
      << "incorrect value for states[2].sid.code, expected 53, is "
      << last_msg_->states[2].sid.code;
  EXPECT_EQ(last_msg_->states[2].sid.reserved, 20)
      << "incorrect value for states[2].sid.reserved, expected 20, is "
      << last_msg_->states[2].sid.reserved;
  EXPECT_EQ(last_msg_->states[2].sid.sat, 1520)
      << "incorrect value for states[2].sid.sat, expected 1520, is "
      << last_msg_->states[2].sid.sat;
  EXPECT_EQ(last_msg_->states[2].state, 78)
      << "incorrect value for states[2].state, expected 78, is "
      << last_msg_->states[2].state;
  EXPECT_LT((last_msg_->states[3].cn0 * 100 - 3198.19995117 * 100), 0.05)
      << "incorrect value for states[3].cn0, expected 3198.19995117, is "
      << last_msg_->states[3].cn0;
  EXPECT_EQ(last_msg_->states[3].sid.code, 66)
      << "incorrect value for states[3].sid.code, expected 66, is "
      << last_msg_->states[3].sid.code;
  EXPECT_EQ(last_msg_->states[3].sid.reserved, 155)
      << "incorrect value for states[3].sid.reserved, expected 155, is "
      << last_msg_->states[3].sid.reserved;
  EXPECT_EQ(last_msg_->states[3].sid.sat, 60802)
      << "incorrect value for states[3].sid.sat, expected 60802, is "
      << last_msg_->states[3].sid.sat;
  EXPECT_EQ(last_msg_->states[3].state, 153)
      << "incorrect value for states[3].state, expected 153, is "
      << last_msg_->states[3].state;
  EXPECT_LT((last_msg_->states[4].cn0 * 100 - 8623.20019531 * 100), 0.05)
      << "incorrect value for states[4].cn0, expected 8623.20019531, is "
      << last_msg_->states[4].cn0;
  EXPECT_EQ(last_msg_->states[4].sid.code, 161)
      << "incorrect value for states[4].sid.code, expected 161, is "
      << last_msg_->states[4].sid.code;
  EXPECT_EQ(last_msg_->states[4].sid.reserved, 190)
      << "incorrect value for states[4].sid.reserved, expected 190, is "
      << last_msg_->states[4].sid.reserved;
  EXPECT_EQ(last_msg_->states[4].sid.sat, 35058)
      << "incorrect value for states[4].sid.sat, expected 35058, is "
      << last_msg_->states[4].sid.sat;
  EXPECT_EQ(last_msg_->states[4].state, 53)
      << "incorrect value for states[4].state, expected 53, is "
      << last_msg_->states[4].state;
  EXPECT_LT((last_msg_->states[5].cn0 * 100 - 5915.20019531 * 100), 0.05)
      << "incorrect value for states[5].cn0, expected 5915.20019531, is "
      << last_msg_->states[5].cn0;
  EXPECT_EQ(last_msg_->states[5].sid.code, 142)
      << "incorrect value for states[5].sid.code, expected 142, is "
      << last_msg_->states[5].sid.code;
  EXPECT_EQ(last_msg_->states[5].sid.reserved, 149)
      << "incorrect value for states[5].sid.reserved, expected 149, is "
      << last_msg_->states[5].sid.reserved;
  EXPECT_EQ(last_msg_->states[5].sid.sat, 65405)
      << "incorrect value for states[5].sid.sat, expected 65405, is "
      << last_msg_->states[5].sid.sat;
  EXPECT_EQ(last_msg_->states[5].state, 153)
      << "incorrect value for states[5].state, expected 153, is "
      << last_msg_->states[5].state;
  EXPECT_LT((last_msg_->states[6].cn0 * 100 - 5412.20019531 * 100), 0.05)
      << "incorrect value for states[6].cn0, expected 5412.20019531, is "
      << last_msg_->states[6].cn0;
  EXPECT_EQ(last_msg_->states[6].sid.code, 31)
      << "incorrect value for states[6].sid.code, expected 31, is "
      << last_msg_->states[6].sid.code;
  EXPECT_EQ(last_msg_->states[6].sid.reserved, 76)
      << "incorrect value for states[6].sid.reserved, expected 76, is "
      << last_msg_->states[6].sid.reserved;
  EXPECT_EQ(last_msg_->states[6].sid.sat, 24422)
      << "incorrect value for states[6].sid.sat, expected 24422, is "
      << last_msg_->states[6].sid.sat;
  EXPECT_EQ(last_msg_->states[6].state, 248)
      << "incorrect value for states[6].state, expected 248, is "
      << last_msg_->states[6].state;
  EXPECT_LT((last_msg_->states[7].cn0 * 100 - 6428.20019531 * 100), 0.05)
      << "incorrect value for states[7].cn0, expected 6428.20019531, is "
      << last_msg_->states[7].cn0;
  EXPECT_EQ(last_msg_->states[7].sid.code, 27)
      << "incorrect value for states[7].sid.code, expected 27, is "
      << last_msg_->states[7].sid.code;
  EXPECT_EQ(last_msg_->states[7].sid.reserved, 12)
      << "incorrect value for states[7].sid.reserved, expected 12, is "
      << last_msg_->states[7].sid.reserved;
  EXPECT_EQ(last_msg_->states[7].sid.sat, 36211)
      << "incorrect value for states[7].sid.sat, expected 36211, is "
      << last_msg_->states[7].sid.sat;
  EXPECT_EQ(last_msg_->states[7].state, 131)
      << "incorrect value for states[7].state, expected 131, is "
      << last_msg_->states[7].state;
  EXPECT_LT((last_msg_->states[8].cn0 * 100 - 3104.19995117 * 100), 0.05)
      << "incorrect value for states[8].cn0, expected 3104.19995117, is "
      << last_msg_->states[8].cn0;
  EXPECT_EQ(last_msg_->states[8].sid.code, 39)
      << "incorrect value for states[8].sid.code, expected 39, is "
      << last_msg_->states[8].sid.code;
  EXPECT_EQ(last_msg_->states[8].sid.reserved, 23)
      << "incorrect value for states[8].sid.reserved, expected 23, is "
      << last_msg_->states[8].sid.reserved;
  EXPECT_EQ(last_msg_->states[8].sid.sat, 37676)
      << "incorrect value for states[8].sid.sat, expected 37676, is "
      << last_msg_->states[8].sid.sat;
  EXPECT_EQ(last_msg_->states[8].state, 208)
      << "incorrect value for states[8].state, expected 208, is "
      << last_msg_->states[8].state;
  EXPECT_LT((last_msg_->states[9].cn0 * 100 - 3686.19995117 * 100), 0.05)
      << "incorrect value for states[9].cn0, expected 3686.19995117, is "
      << last_msg_->states[9].cn0;
  EXPECT_EQ(last_msg_->states[9].sid.code, 49)
      << "incorrect value for states[9].sid.code, expected 49, is "
      << last_msg_->states[9].sid.code;
  EXPECT_EQ(last_msg_->states[9].sid.reserved, 203)
      << "incorrect value for states[9].sid.reserved, expected 203, is "
      << last_msg_->states[9].sid.reserved;
  EXPECT_EQ(last_msg_->states[9].sid.sat, 64415)
      << "incorrect value for states[9].sid.sat, expected 64415, is "
      << last_msg_->states[9].sid.sat;
  EXPECT_EQ(last_msg_->states[9].state, 237)
      << "incorrect value for states[9].state, expected 237, is "
      << last_msg_->states[9].state;
  EXPECT_LT((last_msg_->states[10].cn0 * 100 - 5967.20019531 * 100), 0.05)
      << "incorrect value for states[10].cn0, expected 5967.20019531, is "
      << last_msg_->states[10].cn0;
  EXPECT_EQ(last_msg_->states[10].sid.code, 128)
      << "incorrect value for states[10].sid.code, expected 128, is "
      << last_msg_->states[10].sid.code;
  EXPECT_EQ(last_msg_->states[10].sid.reserved, 206)
      << "incorrect value for states[10].sid.reserved, expected 206, is "
      << last_msg_->states[10].sid.reserved;
  EXPECT_EQ(last_msg_->states[10].sid.sat, 22486)
      << "incorrect value for states[10].sid.sat, expected 22486, is "
      << last_msg_->states[10].sid.sat;
  EXPECT_EQ(last_msg_->states[10].state, 70)
      << "incorrect value for states[10].state, expected 70, is "
      << last_msg_->states[10].state;
  EXPECT_LT((last_msg_->states[11].cn0 * 100 - 5423.20019531 * 100), 0.05)
      << "incorrect value for states[11].cn0, expected 5423.20019531, is "
      << last_msg_->states[11].cn0;
  EXPECT_EQ(last_msg_->states[11].sid.code, 218)
      << "incorrect value for states[11].sid.code, expected 218, is "
      << last_msg_->states[11].sid.code;
  EXPECT_EQ(last_msg_->states[11].sid.reserved, 19)
      << "incorrect value for states[11].sid.reserved, expected 19, is "
      << last_msg_->states[11].sid.reserved;
  EXPECT_EQ(last_msg_->states[11].sid.sat, 28622)
      << "incorrect value for states[11].sid.sat, expected 28622, is "
      << last_msg_->states[11].sid.sat;
  EXPECT_EQ(last_msg_->states[11].state, 14)
      << "incorrect value for states[11].state, expected 14, is "
      << last_msg_->states[11].state;
  EXPECT_LT((last_msg_->states[12].cn0 * 100 - 438.200012207 * 100), 0.05)
      << "incorrect value for states[12].cn0, expected 438.200012207, is "
      << last_msg_->states[12].cn0;
  EXPECT_EQ(last_msg_->states[12].sid.code, 54)
      << "incorrect value for states[12].sid.code, expected 54, is "
      << last_msg_->states[12].sid.code;
  EXPECT_EQ(last_msg_->states[12].sid.reserved, 2)
      << "incorrect value for states[12].sid.reserved, expected 2, is "
      << last_msg_->states[12].sid.reserved;
  EXPECT_EQ(last_msg_->states[12].sid.sat, 53602)
      << "incorrect value for states[12].sid.sat, expected 53602, is "
      << last_msg_->states[12].sid.sat;
  EXPECT_EQ(last_msg_->states[12].state, 216)
      << "incorrect value for states[12].state, expected 216, is "
      << last_msg_->states[12].state;
  EXPECT_LT((last_msg_->states[13].cn0 * 100 - 1862.19995117 * 100), 0.05)
      << "incorrect value for states[13].cn0, expected 1862.19995117, is "
      << last_msg_->states[13].cn0;
  EXPECT_EQ(last_msg_->states[13].sid.code, 7)
      << "incorrect value for states[13].sid.code, expected 7, is "
      << last_msg_->states[13].sid.code;
  EXPECT_EQ(last_msg_->states[13].sid.reserved, 34)
      << "incorrect value for states[13].sid.reserved, expected 34, is "
      << last_msg_->states[13].sid.reserved;
  EXPECT_EQ(last_msg_->states[13].sid.sat, 25477)
      << "incorrect value for states[13].sid.sat, expected 25477, is "
      << last_msg_->states[13].sid.sat;
  EXPECT_EQ(last_msg_->states[13].state, 200)
      << "incorrect value for states[13].state, expected 200, is "
      << last_msg_->states[13].state;
  EXPECT_LT((last_msg_->states[14].cn0 * 100 - 5462.20019531 * 100), 0.05)
      << "incorrect value for states[14].cn0, expected 5462.20019531, is "
      << last_msg_->states[14].cn0;
  EXPECT_EQ(last_msg_->states[14].sid.code, 135)
      << "incorrect value for states[14].sid.code, expected 135, is "
      << last_msg_->states[14].sid.code;
  EXPECT_EQ(last_msg_->states[14].sid.reserved, 46)
      << "incorrect value for states[14].sid.reserved, expected 46, is "
      << last_msg_->states[14].sid.reserved;
  EXPECT_EQ(last_msg_->states[14].sid.sat, 21803)
      << "incorrect value for states[14].sid.sat, expected 21803, is "
      << last_msg_->states[14].sid.sat;
  EXPECT_EQ(last_msg_->states[14].state, 155)
      << "incorrect value for states[14].state, expected 155, is "
      << last_msg_->states[14].state;
  EXPECT_LT((last_msg_->states[15].cn0 * 100 - 7454.20019531 * 100), 0.05)
      << "incorrect value for states[15].cn0, expected 7454.20019531, is "
      << last_msg_->states[15].cn0;
  EXPECT_EQ(last_msg_->states[15].sid.code, 171)
      << "incorrect value for states[15].sid.code, expected 171, is "
      << last_msg_->states[15].sid.code;
  EXPECT_EQ(last_msg_->states[15].sid.reserved, 201)
      << "incorrect value for states[15].sid.reserved, expected 201, is "
      << last_msg_->states[15].sid.reserved;
  EXPECT_EQ(last_msg_->states[15].sid.sat, 21251)
      << "incorrect value for states[15].sid.sat, expected 21251, is "
      << last_msg_->states[15].sid.sat;
  EXPECT_EQ(last_msg_->states[15].state, 155)
      << "incorrect value for states[15].state, expected 155, is "
      << last_msg_->states[15].state;
  EXPECT_LT((last_msg_->states[16].cn0 * 100 - 7134.20019531 * 100), 0.05)
      << "incorrect value for states[16].cn0, expected 7134.20019531, is "
      << last_msg_->states[16].cn0;
  EXPECT_EQ(last_msg_->states[16].sid.code, 16)
      << "incorrect value for states[16].sid.code, expected 16, is "
      << last_msg_->states[16].sid.code;
  EXPECT_EQ(last_msg_->states[16].sid.reserved, 19)
      << "incorrect value for states[16].sid.reserved, expected 19, is "
      << last_msg_->states[16].sid.reserved;
  EXPECT_EQ(last_msg_->states[16].sid.sat, 50475)
      << "incorrect value for states[16].sid.sat, expected 50475, is "
      << last_msg_->states[16].sid.sat;
  EXPECT_EQ(last_msg_->states[16].state, 121)
      << "incorrect value for states[16].state, expected 121, is "
      << last_msg_->states[16].state;
  EXPECT_LT((last_msg_->states[17].cn0 * 100 - 3111.19995117 * 100), 0.05)
      << "incorrect value for states[17].cn0, expected 3111.19995117, is "
      << last_msg_->states[17].cn0;
  EXPECT_EQ(last_msg_->states[17].sid.code, 63)
      << "incorrect value for states[17].sid.code, expected 63, is "
      << last_msg_->states[17].sid.code;
  EXPECT_EQ(last_msg_->states[17].sid.reserved, 176)
      << "incorrect value for states[17].sid.reserved, expected 176, is "
      << last_msg_->states[17].sid.reserved;
  EXPECT_EQ(last_msg_->states[17].sid.sat, 13813)
      << "incorrect value for states[17].sid.sat, expected 13813, is "
      << last_msg_->states[17].sid.sat;
  EXPECT_EQ(last_msg_->states[17].state, 128)
      << "incorrect value for states[17].state, expected 128, is "
      << last_msg_->states[17].state;
  EXPECT_LT((last_msg_->states[18].cn0 * 100 - 4297.20019531 * 100), 0.05)
      << "incorrect value for states[18].cn0, expected 4297.20019531, is "
      << last_msg_->states[18].cn0;
  EXPECT_EQ(last_msg_->states[18].sid.code, 153)
      << "incorrect value for states[18].sid.code, expected 153, is "
      << last_msg_->states[18].sid.code;
  EXPECT_EQ(last_msg_->states[18].sid.reserved, 51)
      << "incorrect value for states[18].sid.reserved, expected 51, is "
      << last_msg_->states[18].sid.reserved;
  EXPECT_EQ(last_msg_->states[18].sid.sat, 15636)
      << "incorrect value for states[18].sid.sat, expected 15636, is "
      << last_msg_->states[18].sid.sat;
  EXPECT_EQ(last_msg_->states[18].state, 36)
      << "incorrect value for states[18].state, expected 36, is "
      << last_msg_->states[18].state;
  EXPECT_LT((last_msg_->states[19].cn0 * 100 - 2649.19995117 * 100), 0.05)
      << "incorrect value for states[19].cn0, expected 2649.19995117, is "
      << last_msg_->states[19].cn0;
  EXPECT_EQ(last_msg_->states[19].sid.code, 140)
      << "incorrect value for states[19].sid.code, expected 140, is "
      << last_msg_->states[19].sid.code;
  EXPECT_EQ(last_msg_->states[19].sid.reserved, 22)
      << "incorrect value for states[19].sid.reserved, expected 22, is "
      << last_msg_->states[19].sid.reserved;
  EXPECT_EQ(last_msg_->states[19].sid.sat, 29778)
      << "incorrect value for states[19].sid.sat, expected 29778, is "
      << last_msg_->states[19].sid.sat;
  EXPECT_EQ(last_msg_->states[19].state, 46)
      << "incorrect value for states[19].state, expected 46, is "
      << last_msg_->states[19].state;
  EXPECT_LT((last_msg_->states[20].cn0 * 100 - 941.200012207 * 100), 0.05)
      << "incorrect value for states[20].cn0, expected 941.200012207, is "
      << last_msg_->states[20].cn0;
  EXPECT_EQ(last_msg_->states[20].sid.code, 96)
      << "incorrect value for states[20].sid.code, expected 96, is "
      << last_msg_->states[20].sid.code;
  EXPECT_EQ(last_msg_->states[20].sid.reserved, 143)
      << "incorrect value for states[20].sid.reserved, expected 143, is "
      << last_msg_->states[20].sid.reserved;
  EXPECT_EQ(last_msg_->states[20].sid.sat, 37443)
      << "incorrect value for states[20].sid.sat, expected 37443, is "
      << last_msg_->states[20].sid.sat;
  EXPECT_EQ(last_msg_->states[20].state, 177)
      << "incorrect value for states[20].state, expected 177, is "
      << last_msg_->states[20].state;
  EXPECT_LT((last_msg_->states[21].cn0 * 100 - 1539.19995117 * 100), 0.05)
      << "incorrect value for states[21].cn0, expected 1539.19995117, is "
      << last_msg_->states[21].cn0;
  EXPECT_EQ(last_msg_->states[21].sid.code, 201)
      << "incorrect value for states[21].sid.code, expected 201, is "
      << last_msg_->states[21].sid.code;
  EXPECT_EQ(last_msg_->states[21].sid.reserved, 251)
      << "incorrect value for states[21].sid.reserved, expected 251, is "
      << last_msg_->states[21].sid.reserved;
  EXPECT_EQ(last_msg_->states[21].sid.sat, 41011)
      << "incorrect value for states[21].sid.sat, expected 41011, is "
      << last_msg_->states[21].sid.sat;
  EXPECT_EQ(last_msg_->states[21].state, 220)
      << "incorrect value for states[21].state, expected 220, is "
      << last_msg_->states[21].state;
  EXPECT_LT((last_msg_->states[22].cn0 * 100 - 1443.19995117 * 100), 0.05)
      << "incorrect value for states[22].cn0, expected 1443.19995117, is "
      << last_msg_->states[22].cn0;
  EXPECT_EQ(last_msg_->states[22].sid.code, 161)
      << "incorrect value for states[22].sid.code, expected 161, is "
      << last_msg_->states[22].sid.code;
  EXPECT_EQ(last_msg_->states[22].sid.reserved, 220)
      << "incorrect value for states[22].sid.reserved, expected 220, is "
      << last_msg_->states[22].sid.reserved;
  EXPECT_EQ(last_msg_->states[22].sid.sat, 706)
      << "incorrect value for states[22].sid.sat, expected 706, is "
      << last_msg_->states[22].sid.sat;
  EXPECT_EQ(last_msg_->states[22].state, 168)
      << "incorrect value for states[22].state, expected 168, is "
      << last_msg_->states[22].state;
  EXPECT_LT((last_msg_->states[23].cn0 * 100 - 1074.19995117 * 100), 0.05)
      << "incorrect value for states[23].cn0, expected 1074.19995117, is "
      << last_msg_->states[23].cn0;
  EXPECT_EQ(last_msg_->states[23].sid.code, 125)
      << "incorrect value for states[23].sid.code, expected 125, is "
      << last_msg_->states[23].sid.code;
  EXPECT_EQ(last_msg_->states[23].sid.reserved, 178)
      << "incorrect value for states[23].sid.reserved, expected 178, is "
      << last_msg_->states[23].sid.reserved;
  EXPECT_EQ(last_msg_->states[23].sid.sat, 2312)
      << "incorrect value for states[23].sid.sat, expected 2312, is "
      << last_msg_->states[23].sid.sat;
  EXPECT_EQ(last_msg_->states[23].state, 69)
      << "incorrect value for states[23].state, expected 69, is "
      << last_msg_->states[23].state;
  EXPECT_LT((last_msg_->states[24].cn0 * 100 - 2122.19995117 * 100), 0.05)
      << "incorrect value for states[24].cn0, expected 2122.19995117, is "
      << last_msg_->states[24].cn0;
  EXPECT_EQ(last_msg_->states[24].sid.code, 186)
      << "incorrect value for states[24].sid.code, expected 186, is "
      << last_msg_->states[24].sid.code;
  EXPECT_EQ(last_msg_->states[24].sid.reserved, 171)
      << "incorrect value for states[24].sid.reserved, expected 171, is "
      << last_msg_->states[24].sid.reserved;
  EXPECT_EQ(last_msg_->states[24].sid.sat, 34580)
      << "incorrect value for states[24].sid.sat, expected 34580, is "
      << last_msg_->states[24].sid.sat;
  EXPECT_EQ(last_msg_->states[24].state, 185)
      << "incorrect value for states[24].state, expected 185, is "
      << last_msg_->states[24].state;
  EXPECT_LT((last_msg_->states[25].cn0 * 100 - 9076.20019531 * 100), 0.05)
      << "incorrect value for states[25].cn0, expected 9076.20019531, is "
      << last_msg_->states[25].cn0;
  EXPECT_EQ(last_msg_->states[25].sid.code, 85)
      << "incorrect value for states[25].sid.code, expected 85, is "
      << last_msg_->states[25].sid.code;
  EXPECT_EQ(last_msg_->states[25].sid.reserved, 170)
      << "incorrect value for states[25].sid.reserved, expected 170, is "
      << last_msg_->states[25].sid.reserved;
  EXPECT_EQ(last_msg_->states[25].sid.sat, 39804)
      << "incorrect value for states[25].sid.sat, expected 39804, is "
      << last_msg_->states[25].sid.sat;
  EXPECT_EQ(last_msg_->states[25].state, 18)
      << "incorrect value for states[25].state, expected 18, is "
      << last_msg_->states[25].state;
  EXPECT_LT((last_msg_->states[26].cn0 * 100 - 4781.20019531 * 100), 0.05)
      << "incorrect value for states[26].cn0, expected 4781.20019531, is "
      << last_msg_->states[26].cn0;
  EXPECT_EQ(last_msg_->states[26].sid.code, 255)
      << "incorrect value for states[26].sid.code, expected 255, is "
      << last_msg_->states[26].sid.code;
  EXPECT_EQ(last_msg_->states[26].sid.reserved, 186)
      << "incorrect value for states[26].sid.reserved, expected 186, is "
      << last_msg_->states[26].sid.reserved;
  EXPECT_EQ(last_msg_->states[26].sid.sat, 52980)
      << "incorrect value for states[26].sid.sat, expected 52980, is "
      << last_msg_->states[26].sid.sat;
  EXPECT_EQ(last_msg_->states[26].state, 57)
      << "incorrect value for states[26].state, expected 57, is "
      << last_msg_->states[26].state;
  EXPECT_LT((last_msg_->states[27].cn0 * 100 - 3076.19995117 * 100), 0.05)
      << "incorrect value for states[27].cn0, expected 3076.19995117, is "
      << last_msg_->states[27].cn0;
  EXPECT_EQ(last_msg_->states[27].sid.code, 181)
      << "incorrect value for states[27].sid.code, expected 181, is "
      << last_msg_->states[27].sid.code;
  EXPECT_EQ(last_msg_->states[27].sid.reserved, 175)
      << "incorrect value for states[27].sid.reserved, expected 175, is "
      << last_msg_->states[27].sid.reserved;
  EXPECT_EQ(last_msg_->states[27].sid.sat, 24007)
      << "incorrect value for states[27].sid.sat, expected 24007, is "
      << last_msg_->states[27].sid.sat;
  EXPECT_EQ(last_msg_->states[27].state, 165)
      << "incorrect value for states[27].state, expected 165, is "
      << last_msg_->states[27].state;
}
