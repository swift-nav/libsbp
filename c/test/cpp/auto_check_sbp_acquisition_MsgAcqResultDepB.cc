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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepB.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_acquisition_MsgAcqResultDepB0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_acq_result_dep_b_t> {
 public:
  Test_auto_check_sbp_acquisition_MsgAcqResultDepB0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>(this),
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
                      const sbp_msg_acq_result_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_acquisition_MsgAcqResultDepB0, Test) {
  uint8_t encoded_frame[] = {
      85,  20, 0,   246, 215, 16, 137, 167, 18, 66, 0,  0,
      161, 67, 240, 24,  156, 69, 9,   0,   0,  0,  80, 195,
  };

  sbp_msg_acq_result_dep_b_t test_msg{};
  test_msg.cf = 4995.1171875;
  test_msg.cp = 322.0;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 9;
  test_msg.snr = 36.66360855102539;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cf * 100 - 4995.1171875 * 100), 0.05)
      << "incorrect value for last_msg_.cf, expected 4995.1171875, is "
      << last_msg_.cf;
  EXPECT_LT((last_msg_.cp * 100 - 322.0 * 100), 0.05)
      << "incorrect value for last_msg_.cp, expected 322.0, is "
      << last_msg_.cp;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 9)
      << "incorrect value for last_msg_.sid.sat, expected 9, is "
      << last_msg_.sid.sat;
  EXPECT_LT((last_msg_.snr * 100 - 36.663608551 * 100), 0.05)
      << "incorrect value for last_msg_.snr, expected 36.663608551, is "
      << last_msg_.snr;
}
class Test_auto_check_sbp_acquisition_MsgAcqResultDepB1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_acq_result_dep_b_t> {
 public:
  Test_auto_check_sbp_acquisition_MsgAcqResultDepB1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>(this),
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
                      const sbp_msg_acq_result_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_acquisition_MsgAcqResultDepB1, Test) {
  uint8_t encoded_frame[] = {
      85, 20, 0,   246, 215, 16,  206, 172, 16, 66, 0,   192,
      82, 68, 198, 199, 0,   198, 3,   0,   0,  0,  149, 143,
  };

  sbp_msg_acq_result_dep_b_t test_msg{};
  test_msg.cf = -8241.943359375;
  test_msg.cp = 843.0;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 3;
  test_msg.snr = 36.16875457763672;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cf * 100 - -8241.94335938 * 100), 0.05)
      << "incorrect value for last_msg_.cf, expected -8241.94335938, is "
      << last_msg_.cf;
  EXPECT_LT((last_msg_.cp * 100 - 843.0 * 100), 0.05)
      << "incorrect value for last_msg_.cp, expected 843.0, is "
      << last_msg_.cp;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 3)
      << "incorrect value for last_msg_.sid.sat, expected 3, is "
      << last_msg_.sid.sat;
  EXPECT_LT((last_msg_.snr * 100 - 36.1687545776 * 100), 0.05)
      << "incorrect value for last_msg_.snr, expected 36.1687545776, is "
      << last_msg_.snr;
}
class Test_auto_check_sbp_acquisition_MsgAcqResultDepB2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_acq_result_dep_b_t> {
 public:
  Test_auto_check_sbp_acquisition_MsgAcqResultDepB2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>(this),
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
                      const sbp_msg_acq_result_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_acquisition_MsgAcqResultDepB2, Test) {
  uint8_t encoded_frame[] = {
      85, 20, 0,   246, 215, 16, 228, 27, 15, 66, 0,   128,
      70, 68, 228, 74,  148, 69, 18,  0,  0,  0,  179, 155,
  };

  sbp_msg_acq_result_dep_b_t test_msg{};
  test_msg.cf = 4745.361328125;
  test_msg.cp = 794.0;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 18;
  test_msg.snr = 35.77723693847656;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cf * 100 - 4745.36132812 * 100), 0.05)
      << "incorrect value for last_msg_.cf, expected 4745.36132812, is "
      << last_msg_.cf;
  EXPECT_LT((last_msg_.cp * 100 - 794.0 * 100), 0.05)
      << "incorrect value for last_msg_.cp, expected 794.0, is "
      << last_msg_.cp;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 18)
      << "incorrect value for last_msg_.sid.sat, expected 18, is "
      << last_msg_.sid.sat;
  EXPECT_LT((last_msg_.snr * 100 - 35.7772369385 * 100), 0.05)
      << "incorrect value for last_msg_.snr, expected 35.7772369385, is "
      << last_msg_.snr;
}
class Test_auto_check_sbp_acquisition_MsgAcqResultDepB3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_acq_result_dep_b_t> {
 public:
  Test_auto_check_sbp_acquisition_MsgAcqResultDepB3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>(this),
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
                      const sbp_msg_acq_result_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_acquisition_MsgAcqResultDepB3, Test) {
  uint8_t encoded_frame[] = {
      85,  20, 0,   246, 215, 16, 46, 199, 14, 66, 0,  64,
      129, 67, 240, 24,  28,  69, 17, 0,   0,  0,  18, 181,
  };

  sbp_msg_acq_result_dep_b_t test_msg{};
  test_msg.cf = 2497.55859375;
  test_msg.cp = 258.5;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 17;
  test_msg.snr = 35.69451141357422;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cf * 100 - 2497.55859375 * 100), 0.05)
      << "incorrect value for last_msg_.cf, expected 2497.55859375, is "
      << last_msg_.cf;
  EXPECT_LT((last_msg_.cp * 100 - 258.5 * 100), 0.05)
      << "incorrect value for last_msg_.cp, expected 258.5, is "
      << last_msg_.cp;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 17)
      << "incorrect value for last_msg_.sid.sat, expected 17, is "
      << last_msg_.sid.sat;
  EXPECT_LT((last_msg_.snr * 100 - 35.6945114136 * 100), 0.05)
      << "incorrect value for last_msg_.snr, expected 35.6945114136, is "
      << last_msg_.snr;
}
class Test_auto_check_sbp_acquisition_MsgAcqResultDepB4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_acq_result_dep_b_t> {
 public:
  Test_auto_check_sbp_acquisition_MsgAcqResultDepB4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_acq_result_dep_b_t>(this),
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
                      const sbp_msg_acq_result_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_acquisition_MsgAcqResultDepB4, Test) {
  uint8_t encoded_frame[] = {
      85, 20, 0,   246, 215, 16,  194, 24, 14, 66, 0,  128,
      2,  68, 129, 193, 249, 195, 5,   0,  0,  0,  35, 203,
  };

  sbp_msg_acq_result_dep_b_t test_msg{};
  test_msg.cf = -499.5117492675781;
  test_msg.cp = 522.0;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 5;
  test_msg.snr = 35.52417755126953;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cf * 100 - -499.511749268 * 100), 0.05)
      << "incorrect value for last_msg_.cf, expected -499.511749268, is "
      << last_msg_.cf;
  EXPECT_LT((last_msg_.cp * 100 - 522.0 * 100), 0.05)
      << "incorrect value for last_msg_.cp, expected 522.0, is "
      << last_msg_.cp;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 5)
      << "incorrect value for last_msg_.sid.sat, expected 5, is "
      << last_msg_.sid.sat;
  EXPECT_LT((last_msg_.snr * 100 - 35.5241775513 * 100), 0.05)
      << "incorrect value for last_msg_.snr, expected 35.5241775513, is "
      << last_msg_.snr;
}
