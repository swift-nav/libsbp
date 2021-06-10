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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLLH.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_navigation_MsgPosLLH0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLH0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_t>(this),
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
                      const sbp_msg_pos_llh_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLH0, Test) {
  uint8_t encoded_frame[] = {
      85,  10,  2,  211, 136, 34,  40, 244, 122, 19,  201, 106, 155, 186,
      42,  160, 66, 64,  168, 109, 26, 225, 0,   120, 94,  192, 130, 102,
      237, 230, 43, 54,  60,  64,  0,  0,   0,   0,   14,  2,   175, 162,
  };

  sbp_msg_pos_llh_t test_msg{};
  test_msg.flags = 2;
  test_msg.h_accuracy = 0;
  test_msg.height = 28.21160739227208;
  test_msg.lat = 37.25130398358085;
  test_msg.lon = -121.87505366879361;
  test_msg.n_sats = 14;
  test_msg.tow = 326825000;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(35027, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 2)
      << "incorrect value for last_msg_.flags, expected 2, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 28.2116073923 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 28.2116073923, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.2513039836 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.2513039836, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -121.875053669 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -121.875053669, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 14)
      << "incorrect value for last_msg_.n_sats, expected 14, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 326825000)
      << "incorrect value for last_msg_.tow, expected 326825000, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgPosLLH1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLH1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_t>(this),
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
                      const sbp_msg_pos_llh_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLH1, Test) {
  uint8_t encoded_frame[] = {
      85,  10,  2,   211, 136, 34, 16, 248, 122, 19,  52, 177, 251, 178,
      42,  160, 66,  64,  237, 22, 97, 224, 0,   120, 94, 192, 107, 188,
      109, 90,  247, 189, 59,  64, 0,  0,   0,   0,   15, 2,   38,  177,
  };

  sbp_msg_pos_llh_t test_msg{};
  test_msg.flags = 2;
  test_msg.h_accuracy = 0;
  test_msg.height = 27.742055560866373;
  test_msg.lat = 37.251303074738104;
  test_msg.lon = -121.87505349618341;
  test_msg.n_sats = 15;
  test_msg.tow = 326826000;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(35027, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 2)
      << "incorrect value for last_msg_.flags, expected 2, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 27.7420555609 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 27.7420555609, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.2513030747 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.2513030747, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -121.875053496 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -121.875053496, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 15)
      << "incorrect value for last_msg_.n_sats, expected 15, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 326826000)
      << "incorrect value for last_msg_.tow, expected 326826000, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgPosLLH2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLH2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_t>(this),
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
                      const sbp_msg_pos_llh_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLH2, Test) {
  uint8_t encoded_frame[] = {
      85,  10,  2,  211, 136, 34, 248, 251, 122, 19,  135, 66,  9,  163,
      42,  160, 66, 64,  146, 8,  99,  225, 0,   120, 94,  192, 45, 181,
      143, 219, 28, 157, 59,  64, 0,   0,   0,   0,   15,  2,   51, 40,
  };

  sbp_msg_pos_llh_t test_msg{};
  test_msg.flags = 2;
  test_msg.h_accuracy = 0;
  test_msg.height = 27.613721582970516;
  test_msg.lat = 37.25130117370741;
  test_msg.lon = -121.87505373641241;
  test_msg.n_sats = 15;
  test_msg.tow = 326827000;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(35027, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 2)
      << "incorrect value for last_msg_.flags, expected 2, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 27.613721583 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 27.613721583, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.2513011737 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.2513011737, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -121.875053736 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -121.875053736, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 15)
      << "incorrect value for last_msg_.n_sats, expected 15, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 326827000)
      << "incorrect value for last_msg_.tow, expected 326827000, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgPosLLH3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLH3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_t>(this),
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
                      const sbp_msg_pos_llh_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLH3, Test) {
  uint8_t encoded_frame[] = {
      85, 10,  2,   211, 136, 34,  224, 255, 122, 19,  18, 44,  253, 119,
      42, 160, 66,  64,  48,  109, 39,  231, 0,   120, 94, 192, 185, 76,
      48, 17,  119, 205, 59,  64,  0,   0,   0,   0,   15, 2,   12,  194,
  };

  sbp_msg_pos_llh_t test_msg{};
  test_msg.flags = 2;
  test_msg.h_accuracy = 0;
  test_msg.height = 27.80259807042305;
  test_msg.lat = 37.251296042079176;
  test_msg.lon = -121.87505511141057;
  test_msg.n_sats = 15;
  test_msg.tow = 326828000;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(35027, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 2)
      << "incorrect value for last_msg_.flags, expected 2, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 27.8025980704 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 27.8025980704, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.2512960421 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.2512960421, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -121.875055111 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -121.875055111, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 15)
      << "incorrect value for last_msg_.n_sats, expected 15, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 326828000)
      << "incorrect value for last_msg_.tow, expected 326828000, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
class Test_auto_check_sbp_navigation_MsgPosLLH4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_pos_llh_t> {
 public:
  Test_auto_check_sbp_navigation_MsgPosLLH4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_pos_llh_t>(this),
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
                      const sbp_msg_pos_llh_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_navigation_MsgPosLLH4, Test) {
  uint8_t encoded_frame[] = {
      85,  10,  2,   211, 136, 34,  200, 3,   123, 19,  225, 237, 238, 90,
      42,  160, 66,  64,  59,  143, 70,  235, 0,   120, 94,  192, 101, 106,
      249, 224, 131, 240, 59,  64,  0,   0,   0,   0,   15,  2,   34,  103,
  };

  sbp_msg_pos_llh_t test_msg{};
  test_msg.flags = 2;
  test_msg.h_accuracy = 0;
  test_msg.height = 27.939512310879213;
  test_msg.lat = 37.251292578377395;
  test_msg.lon = -121.87505609407974;
  test_msg.n_sats = 15;
  test_msg.tow = 326829000;
  test_msg.v_accuracy = 0;

  EXPECT_EQ(send_message(35027, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 35027);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.flags, 2)
      << "incorrect value for last_msg_.flags, expected 2, is "
      << last_msg_.flags;
  EXPECT_EQ(last_msg_.h_accuracy, 0)
      << "incorrect value for last_msg_.h_accuracy, expected 0, is "
      << last_msg_.h_accuracy;
  EXPECT_LT((last_msg_.height * 100 - 27.9395123109 * 100), 0.05)
      << "incorrect value for last_msg_.height, expected 27.9395123109, is "
      << last_msg_.height;
  EXPECT_LT((last_msg_.lat * 100 - 37.2512925784 * 100), 0.05)
      << "incorrect value for last_msg_.lat, expected 37.2512925784, is "
      << last_msg_.lat;
  EXPECT_LT((last_msg_.lon * 100 - -121.875056094 * 100), 0.05)
      << "incorrect value for last_msg_.lon, expected -121.875056094, is "
      << last_msg_.lon;
  EXPECT_EQ(last_msg_.n_sats, 15)
      << "incorrect value for last_msg_.n_sats, expected 15, is "
      << last_msg_.n_sats;
  EXPECT_EQ(last_msg_.tow, 326829000)
      << "incorrect value for last_msg_.tow, expected 326829000, is "
      << last_msg_.tow;
  EXPECT_EQ(last_msg_.v_accuracy, 0)
      << "incorrect value for last_msg_.v_accuracy, expected 0, is "
      << last_msg_.v_accuracy;
}
