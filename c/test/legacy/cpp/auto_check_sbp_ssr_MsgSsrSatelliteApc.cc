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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApc.yaml by generate.py.
// Do not modify by hand!

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
#include <libsbp/legacy/ssr.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_ssr_MsgSsrSatelliteApc0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_satellite_apc_t> {
 public:
  Test_legacy_auto_check_sbp_ssr_MsgSsrSatelliteApc0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_satellite_apc_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_ssr_satellite_apc_t *>(last_msg_storage_)),
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
                      const msg_ssr_satellite_apc_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_satellite_apc_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ssr_MsgSsrSatelliteApc0, Test) {
  uint8_t encoded_frame[] = {
      85, 5,  6,  0,  0,  41,  127, 58,  9,   0,   174, 8,   1,
      2,  3,  2,  0,  4,  61,  0,   1,   0,   255, 255, 217, 2,
      11, 10, 8,  5,  1,  252, 248, 246, 246, 246, 249, 252, 0,
      6,  12, 22, 30, 41, 41,  41,  41,  144, 161,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_satellite_apc_t *test_msg =
      (msg_ssr_satellite_apc_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  if (sizeof(test_msg->apc) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0]));
  }
  if (sizeof(test_msg->apc[0].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pco[0]));
  }
  test_msg->apc[0].pco[0] = 1;
  if (sizeof(test_msg->apc[0].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pco[0]));
  }
  test_msg->apc[0].pco[1] = -1;
  if (sizeof(test_msg->apc[0].pco) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pco[0]));
  }
  test_msg->apc[0].pco[2] = 729;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[0] = 11;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[1] = 10;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[2] = 8;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[3] = 5;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[4] = 1;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[5] = -4;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[6] = -8;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[7] = -10;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[8] = -10;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[9] = -10;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[10] = -7;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[11] = -4;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[12] = 0;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[13] = 6;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[14] = 12;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[15] = 22;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[16] = 30;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[17] = 41;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[18] = 41;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[19] = 41;
  if (sizeof(test_msg->apc[0].pcv) == 0) {
    // Cope with variable length arrays
    test_msg_len = (uint8_t)(test_msg_len + sizeof(test_msg->apc[0].pcv[0]));
  }
  test_msg->apc[0].pcv[20] = 41;
  test_msg->apc[0].sat_info = 4;
  test_msg->apc[0].sid.code = 0;
  test_msg->apc[0].sid.sat = 2;
  test_msg->apc[0].svn = 61;
  test_msg->iod_ssr = 3;
  test_msg->sol_id = 2;
  test_msg->time.tow = 604799;
  test_msg->time.wn = 2222;
  test_msg->update_interval = 1;

  EXPECT_EQ(send_message(0x605, 0, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 0);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pco[0])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pco[0])),
            1)
      << "incorrect value for apc[0].pco[0], expected 1, is "
      << last_msg_->apc[0].pco[0];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pco[1])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pco[1])),
            -1)
      << "incorrect value for apc[0].pco[1], expected -1, is "
      << last_msg_->apc[0].pco[1];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pco[2])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pco[2])),
            729)
      << "incorrect value for apc[0].pco[2], expected 729, is "
      << last_msg_->apc[0].pco[2];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[0])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[0])),
            11)
      << "incorrect value for apc[0].pcv[0], expected 11, is "
      << last_msg_->apc[0].pcv[0];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[1])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[1])),
            10)
      << "incorrect value for apc[0].pcv[1], expected 10, is "
      << last_msg_->apc[0].pcv[1];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[2])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[2])),
            8)
      << "incorrect value for apc[0].pcv[2], expected 8, is "
      << last_msg_->apc[0].pcv[2];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[3])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[3])),
            5)
      << "incorrect value for apc[0].pcv[3], expected 5, is "
      << last_msg_->apc[0].pcv[3];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[4])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[4])),
            1)
      << "incorrect value for apc[0].pcv[4], expected 1, is "
      << last_msg_->apc[0].pcv[4];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[5])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[5])),
            -4)
      << "incorrect value for apc[0].pcv[5], expected -4, is "
      << last_msg_->apc[0].pcv[5];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[6])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[6])),
            -8)
      << "incorrect value for apc[0].pcv[6], expected -8, is "
      << last_msg_->apc[0].pcv[6];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[7])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[7])),
            -10)
      << "incorrect value for apc[0].pcv[7], expected -10, is "
      << last_msg_->apc[0].pcv[7];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[8])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[8])),
            -10)
      << "incorrect value for apc[0].pcv[8], expected -10, is "
      << last_msg_->apc[0].pcv[8];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[9])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[9])),
            -10)
      << "incorrect value for apc[0].pcv[9], expected -10, is "
      << last_msg_->apc[0].pcv[9];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[10])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[10])),
            -7)
      << "incorrect value for apc[0].pcv[10], expected -7, is "
      << last_msg_->apc[0].pcv[10];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[11])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[11])),
            -4)
      << "incorrect value for apc[0].pcv[11], expected -4, is "
      << last_msg_->apc[0].pcv[11];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[12])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[12])),
            0)
      << "incorrect value for apc[0].pcv[12], expected 0, is "
      << last_msg_->apc[0].pcv[12];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[13])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[13])),
            6)
      << "incorrect value for apc[0].pcv[13], expected 6, is "
      << last_msg_->apc[0].pcv[13];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[14])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[14])),
            12)
      << "incorrect value for apc[0].pcv[14], expected 12, is "
      << last_msg_->apc[0].pcv[14];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[15])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[15])),
            22)
      << "incorrect value for apc[0].pcv[15], expected 22, is "
      << last_msg_->apc[0].pcv[15];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[16])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[16])),
            30)
      << "incorrect value for apc[0].pcv[16], expected 30, is "
      << last_msg_->apc[0].pcv[16];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[17])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[17])),
            41)
      << "incorrect value for apc[0].pcv[17], expected 41, is "
      << last_msg_->apc[0].pcv[17];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[18])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[18])),
            41)
      << "incorrect value for apc[0].pcv[18], expected 41, is "
      << last_msg_->apc[0].pcv[18];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[19])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[19])),
            41)
      << "incorrect value for apc[0].pcv[19], expected 41, is "
      << last_msg_->apc[0].pcv[19];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].pcv[20])>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].pcv[20])),
            41)
      << "incorrect value for apc[0].pcv[20], expected 41, is "
      << last_msg_->apc[0].pcv[20];
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].sat_info)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].sat_info)),
            4)
      << "incorrect value for apc[0].sat_info, expected 4, is "
      << last_msg_->apc[0].sat_info;
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].sid.code)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].sid.code)),
            0)
      << "incorrect value for apc[0].sid.code, expected 0, is "
      << last_msg_->apc[0].sid.code;
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].sid.sat)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].sid.sat)),
            2)
      << "incorrect value for apc[0].sid.sat, expected 2, is "
      << last_msg_->apc[0].sid.sat;
  EXPECT_EQ(get_as<decltype(last_msg_->apc[0].svn)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->apc[0].svn)),
            61)
      << "incorrect value for apc[0].svn, expected 61, is "
      << last_msg_->apc[0].svn;
  EXPECT_EQ(get_as<decltype(last_msg_->iod_ssr)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->iod_ssr)),
            3)
      << "incorrect value for iod_ssr, expected 3, is " << last_msg_->iod_ssr;
  EXPECT_EQ(get_as<decltype(last_msg_->sol_id)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->sol_id)),
            2)
      << "incorrect value for sol_id, expected 2, is " << last_msg_->sol_id;
  EXPECT_EQ(get_as<decltype(last_msg_->time.tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->time.tow)),
            604799)
      << "incorrect value for time.tow, expected 604799, is "
      << last_msg_->time.tow;
  EXPECT_EQ(get_as<decltype(last_msg_->time.wn)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->time.wn)),
            2222)
      << "incorrect value for time.wn, expected 2222, is "
      << last_msg_->time.wn;
  EXPECT_EQ(get_as<decltype(last_msg_->update_interval)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->update_interval)),
            1)
      << "incorrect value for update_interval, expected 1, is "
      << last_msg_->update_interval;
}
