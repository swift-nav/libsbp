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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrTileDefinitionDepA.yaml by
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
#include <libsbp/legacy/ssr.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_ssr_MsgSsrTileDefinitionDepA0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ssr_tile_definition_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_ssr_MsgSsrTileDefinitionDepA0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ssr_tile_definition_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ssr_tile_definition_dep_a_t *>(
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
                      const msg_ssr_tile_definition_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ssr_tile_definition_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ssr_MsgSsrTileDefinitionDepA0, Test) {
  uint8_t encoded_frame[] = {
      85, 246, 5,   200, 133, 24,  57,  190, 178, 247, 8, 185, 9, 181, 162, 240,
      65, 19,  255, 143, 21,  191, 239, 205, 171, 0,   0, 0,   0, 0,   65,  154,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ssr_tile_definition_dep_a_t *test_msg =
      (msg_ssr_tile_definition_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->bitmask = 11259375;
  test_msg->cols = 48917;
  test_msg->corner_nw_lat = -18168;
  test_msg->corner_nw_lon = -19191;
  test_msg->rows = 36863;
  test_msg->spacing_lat = 61602;
  test_msg->spacing_lon = 4929;
  test_msg->tile_id = 63410;
  test_msg->tile_set_id = 48697;

  EXPECT_EQ(send_message(0x5f6, 34248, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 34248);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->bitmask)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->bitmask)),
            11259375)
      << "incorrect value for bitmask, expected 11259375, is "
      << last_msg_->bitmask;
  EXPECT_EQ(get_as<decltype(last_msg_->cols)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->cols)),
            48917)
      << "incorrect value for cols, expected 48917, is " << last_msg_->cols;
  EXPECT_EQ(get_as<decltype(last_msg_->corner_nw_lat)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->corner_nw_lat)),
            -18168)
      << "incorrect value for corner_nw_lat, expected -18168, is "
      << last_msg_->corner_nw_lat;
  EXPECT_EQ(get_as<decltype(last_msg_->corner_nw_lon)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->corner_nw_lon)),
            -19191)
      << "incorrect value for corner_nw_lon, expected -19191, is "
      << last_msg_->corner_nw_lon;
  EXPECT_EQ(get_as<decltype(last_msg_->rows)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->rows)),
            36863)
      << "incorrect value for rows, expected 36863, is " << last_msg_->rows;
  EXPECT_EQ(get_as<decltype(last_msg_->spacing_lat)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->spacing_lat)),
            61602)
      << "incorrect value for spacing_lat, expected 61602, is "
      << last_msg_->spacing_lat;
  EXPECT_EQ(get_as<decltype(last_msg_->spacing_lon)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->spacing_lon)),
            4929)
      << "incorrect value for spacing_lon, expected 4929, is "
      << last_msg_->spacing_lon;
  EXPECT_EQ(get_as<decltype(last_msg_->tile_id)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tile_id)),
            63410)
      << "incorrect value for tile_id, expected 63410, is "
      << last_msg_->tile_id;
  EXPECT_EQ(get_as<decltype(last_msg_->tile_set_id)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tile_set_id)),
            48697)
      << "incorrect value for tile_set_id, expected 48697, is "
      << last_msg_->tile_set_id;
}
