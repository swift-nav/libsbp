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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhAcc.yaml by
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
#include <libsbp/legacy/navigation.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_navigation_MsgPosLlhAcc0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_pos_llh_acc_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgPosLlhAcc0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_pos_llh_acc_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_pos_llh_acc_t *>(last_msg_storage_)),
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
                      const msg_pos_llh_acc_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_pos_llh_acc_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgPosLlhAcc0, Test) {
  uint8_t encoded_frame[] = {
      85,  24,  2,   2,   28,  67,  39,  120, 110, 18,  51,  51,  51, 51,  51,
      139, 189, 64,  154, 153, 153, 153, 25,  151, 192, 64,  51,  51, 51,  51,
      51,  161, 176, 64,  51,  51,  51,  51,  51,  101, 179, 64,  51, 163, 22,
      69,  154, 25,  173, 69,  102, 134, 243, 68,  154, 201, 196, 69, 205, 224,
      0,   70,  51,  35,  72,  69,  51,  99,  31,  69,  95,  27,  72, 220, 177,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_pos_llh_acc_t *test_msg = (msg_pos_llh_acc_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->at_accuracy = 6297.2001953125;
  test_msg->confidence_and_geoid = 95;
  test_msg->ct_accuracy = 1948.199951171875;
  test_msg->flags = 72;
  test_msg->h_accuracy = 2410.199951171875;
  test_msg->h_ellipse.orientation = 2550.199951171875;
  test_msg->h_ellipse.semi_major = 8248.2001953125;
  test_msg->h_ellipse.semi_minor = 3202.199951171875;
  test_msg->height = 4257.2;
  test_msg->lat = 7563.2;
  test_msg->lon = 8494.2;
  test_msg->n_sats = 27;
  test_msg->orthometric_height = 4965.2;
  test_msg->tow = 309229607;
  test_msg->v_accuracy = 5539.2001953125;

  EXPECT_EQ(send_message(0x218, 7170, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 7170);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->at_accuracy * 100 - 6297.20019531 * 100), 0.05)
      << "incorrect value for at_accuracy, expected 6297.20019531, is "
      << last_msg_->at_accuracy;
  EXPECT_EQ(
      get_as<decltype(last_msg_->confidence_and_geoid)>(
          reinterpret_cast<const uint8_t *>(&last_msg_->confidence_and_geoid)),
      95)
      << "incorrect value for confidence_and_geoid, expected 95, is "
      << last_msg_->confidence_and_geoid;
  EXPECT_LT((last_msg_->ct_accuracy * 100 - 1948.19995117 * 100), 0.05)
      << "incorrect value for ct_accuracy, expected 1948.19995117, is "
      << last_msg_->ct_accuracy;
  EXPECT_EQ(get_as<decltype(last_msg_->flags)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->flags)),
            72)
      << "incorrect value for flags, expected 72, is " << last_msg_->flags;
  EXPECT_LT((last_msg_->h_accuracy * 100 - 2410.19995117 * 100), 0.05)
      << "incorrect value for h_accuracy, expected 2410.19995117, is "
      << last_msg_->h_accuracy;
  EXPECT_LT((last_msg_->h_ellipse.orientation * 100 - 2550.19995117 * 100),
            0.05)
      << "incorrect value for h_ellipse.orientation, expected 2550.19995117, "
         "is "
      << last_msg_->h_ellipse.orientation;
  EXPECT_LT((last_msg_->h_ellipse.semi_major * 100 - 8248.20019531 * 100), 0.05)
      << "incorrect value for h_ellipse.semi_major, expected 8248.20019531, is "
      << last_msg_->h_ellipse.semi_major;
  EXPECT_LT((last_msg_->h_ellipse.semi_minor * 100 - 3202.19995117 * 100), 0.05)
      << "incorrect value for h_ellipse.semi_minor, expected 3202.19995117, is "
      << last_msg_->h_ellipse.semi_minor;
  EXPECT_LT((last_msg_->height * 100 - 4257.2 * 100), 0.05)
      << "incorrect value for height, expected 4257.2, is "
      << last_msg_->height;
  EXPECT_LT((last_msg_->lat * 100 - 7563.2 * 100), 0.05)
      << "incorrect value for lat, expected 7563.2, is " << last_msg_->lat;
  EXPECT_LT((last_msg_->lon * 100 - 8494.2 * 100), 0.05)
      << "incorrect value for lon, expected 8494.2, is " << last_msg_->lon;
  EXPECT_EQ(get_as<decltype(last_msg_->n_sats)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->n_sats)),
            27)
      << "incorrect value for n_sats, expected 27, is " << last_msg_->n_sats;
  EXPECT_LT((last_msg_->orthometric_height * 100 - 4965.2 * 100), 0.05)
      << "incorrect value for orthometric_height, expected 4965.2, is "
      << last_msg_->orthometric_height;
  EXPECT_EQ(get_as<decltype(last_msg_->tow)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->tow)),
            309229607)
      << "incorrect value for tow, expected 309229607, is " << last_msg_->tow;
  EXPECT_LT((last_msg_->v_accuracy * 100 - 5539.20019531 * 100), 0.05)
      << "incorrect value for v_accuracy, expected 5539.20019531, is "
      << last_msg_->v_accuracy;
}
