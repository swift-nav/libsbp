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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhCovGnss.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_navigation_MsgPosLlhCovGnss0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_cov_gnss_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLlhCovGnss0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_cov_gnss_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_pos_llh_cov_gnss_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_cov_gnss_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLlhCovGnss0, Test) {
  uint8_t encoded_frame[] = {
      85,  49,  2,   0,   16,  54,  24,  229, 233, 29,  73,  123, 28,
      207, 101, 234, 66,  64,  100, 168, 19,  20,  86,  146, 94,  192,
      214, 198, 35,  120, 209, 100, 49,  192, 12,  102, 245, 59,  6,
      181, 192, 185, 168, 79,  243, 58,  96,  60,  148, 59,  253, 58,
      93,  186, 159, 174, 6,   61,  18,  4,   10,  196,
  };

  sbp_msg_pos_llh_cov_gnss_t test_msg{};
  test_msg.cov_d_d = 0.03288137540221214;
  test_msg.cov_e_d = -0.0008439270895905793;
  test_msg.cov_e_e = 0.004523798823356628;
  test_msg.cov_n_d = 0.0018563168123364449;
  test_msg.cov_n_e = -0.00036755966721102595;
  test_msg.cov_n_n = 0.007488971576094627;
  test_msg.flags = 4;
  test_msg.height = -17.39382124780135;
  test_msg.lat = 37.83123196497633;
  test_msg.lon = -122.28650381011681;
  test_msg.n_sats = 18;
  test_msg.tow = 501867800;

  EXPECT_EQ(send_message(4096, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 4096);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cov_d_d * 100 - 0.0328813754022 * 100), 0.05)
      << "incorrect value for last_msg_.cov_d_d, expected 0.0328813754022, is "
      << last_msg_.cov_d_d;
  EXPECT_LT((last_msg_.cov_e_d * 100 - -0.000843927089591 * 100), 0.05)
      << "incorrect value for last_msg_.cov_e_d, expected -0.000843927089591, "
         "is "
      << last_msg_.cov_e_d;
  EXPECT_LT((last_msg_.cov_e_e * 100 - 0.00452379882336 * 100), 0.05)
      << "incorrect value for last_msg_.cov_e_e, expected 0.00452379882336, is "
      << last_msg_.cov_e_e;
  EXPECT_LT((last_msg_.cov_n_d * 100 - 0.00185631681234 * 100), 0.05)
      << "incorrect value for last_msg_.cov_n_d, expected 0.00185631681234, is "
      << last_msg_.cov_n_d;
  EXPECT_LT((last_msg_.cov_n_e * 100 - -0.000367559667211 * 100), 0.05)
      << "incorrect value for last_msg_.cov_n_e, expected -0.000367559667211, "
         "is "
      << last_msg_.cov_n_e;
  EXPECT_LT((last_msg_.cov_n_n * 100 - 0.00748897157609 * 100), 0.05)
      << "incorrect value for last_msg_.cov_n_n, expected 0.00748897157609, is "
      << last_msg_.cov_n_n;
  EXPECT_EQ(last_msg_.flags, 4)
      << "incorrect value for last_msg_.flags, expected 4, is "
      << last_msg_.flags;
  EXPECT_LT((last_msg_.height * 100 - -17.3938212478 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected -17.3938212478, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.831231965 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.831231965, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -122.28650381 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -122.28650381, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 18)
      << "incorrect value for last_msg_.n_sats, expected 18, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 501867800)
      << "incorrect value for last_msg_.tow, expected 501867800, is "
      << last_msg_.tow;
}
