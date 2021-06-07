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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepC.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_acquisition_MsgAcqResultDepC0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_acq_result_dep_c_t> {
 public:
  Test_auto_check_sbp_acquisition_MsgAcqResultDepC0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_acq_result_dep_c_t>(this),
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
                      const sbp_msg_acq_result_dep_c_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_c_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_acquisition_MsgAcqResultDepC0, Test) {
  uint8_t encoded_frame[] = {
      85,  31, 0,  40, 12,  16, 72, 9, 34, 66, 155, 152,
      228, 67, 28, 34, 221, 68, 10, 0, 0,  0,  9,   189,
  };

  sbp_msg_acq_result_dep_c_t test_msg{};
  test_msg.cf = 1769.06591796875;
  test_msg.cn0 = 40.509063720703125;
  test_msg.cp = 457.1922302246094;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 10;

  EXPECT_EQ(send_message(3112, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 3112);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cf * 100 - 1769.06591797 * 100), 0.05)
      << "incorrect value for last_msg_.cf, expected 1769.06591797, is "
      << last_msg_.cf;
  EXPECT_LT((last_msg_.cn0 * 100 - 40.5090637207 * 100), 0.05)
      << "incorrect value for last_msg_.cn0, expected 40.5090637207, is "
      << last_msg_.cn0;
  EXPECT_LT((last_msg_.cp * 100 - 457.192230225 * 100), 0.05)
      << "incorrect value for last_msg_.cp, expected 457.192230225, is "
      << last_msg_.cp;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 10)
      << "incorrect value for last_msg_.sid.sat, expected 10, is "
      << last_msg_.sid.sat;
}
class Test_auto_check_sbp_acquisition_MsgAcqResultDepC1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_acq_result_dep_c_t> {
 public:
  Test_auto_check_sbp_acquisition_MsgAcqResultDepC1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_acq_result_dep_c_t>(this),
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
                      const sbp_msg_acq_result_dep_c_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_c_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_acquisition_MsgAcqResultDepC1, Test) {
  uint8_t encoded_frame[] = {
      85, 31, 0,  40,  12,  16,  132, 250, 45, 66, 207, 93,
      88, 68, 68, 185, 252, 195, 6,   0,   0,  0,  136, 185,
  };

  sbp_msg_acq_result_dep_c_t test_msg{};
  test_msg.cf = -505.4473876953125;
  test_msg.cn0 = 43.49464416503906;
  test_msg.cp = 865.4657592773438;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 6;

  EXPECT_EQ(send_message(3112, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 3112);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cf * 100 - -505.447387695 * 100), 0.05)
      << "incorrect value for last_msg_.cf, expected -505.447387695, is "
      << last_msg_.cf;
  EXPECT_LT((last_msg_.cn0 * 100 - 43.494644165 * 100), 0.05)
      << "incorrect value for last_msg_.cn0, expected 43.494644165, is "
      << last_msg_.cn0;
  EXPECT_LT((last_msg_.cp * 100 - 865.465759277 * 100), 0.05)
      << "incorrect value for last_msg_.cp, expected 865.465759277, is "
      << last_msg_.cp;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 6)
      << "incorrect value for last_msg_.sid.sat, expected 6, is "
      << last_msg_.sid.sat;
}
class Test_auto_check_sbp_acquisition_MsgAcqResultDepC2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_acq_result_dep_c_t> {
 public:
  Test_auto_check_sbp_acquisition_MsgAcqResultDepC2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_acq_result_dep_c_t>(this),
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
                      const sbp_msg_acq_result_dep_c_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_c_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_acquisition_MsgAcqResultDepC2, Test) {
  uint8_t encoded_frame[] = {
      85,  31, 0,   40,  12,  16,  163, 223, 24, 66, 64,  91,
      102, 67, 202, 243, 157, 196, 13,  0,   0,  0,  150, 161,
  };

  sbp_msg_acq_result_dep_c_t test_msg{};
  test_msg.cf = -1263.618408203125;
  test_msg.cn0 = 38.2183952331543;
  test_msg.cp = 230.3564453125;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 13;

  EXPECT_EQ(send_message(3112, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 3112);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cf * 100 - -1263.6184082 * 100), 0.05)
      << "incorrect value for last_msg_.cf, expected -1263.6184082, is "
      << last_msg_.cf;
  EXPECT_LT((last_msg_.cn0 * 100 - 38.2183952332 * 100), 0.05)
      << "incorrect value for last_msg_.cn0, expected 38.2183952332, is "
      << last_msg_.cn0;
  EXPECT_LT((last_msg_.cp * 100 - 230.356445312 * 100), 0.05)
      << "incorrect value for last_msg_.cp, expected 230.356445312, is "
      << last_msg_.cp;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 13)
      << "incorrect value for last_msg_.sid.sat, expected 13, is "
      << last_msg_.sid.sat;
}
class Test_auto_check_sbp_acquisition_MsgAcqResultDepC3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_acq_result_dep_c_t> {
 public:
  Test_auto_check_sbp_acquisition_MsgAcqResultDepC3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_acq_result_dep_c_t>(this),
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
                      const sbp_msg_acq_result_dep_c_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_c_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_acquisition_MsgAcqResultDepC3, Test) {
  uint8_t encoded_frame[] = {
      85,  31, 0,   40,  12, 16, 129, 65, 21, 66, 224, 214,
      124, 67, 243, 138, 61, 69, 1,   0,  0,  0,  109, 209,
  };

  sbp_msg_acq_result_dep_c_t test_msg{};
  test_msg.cf = 3032.684326171875;
  test_msg.cn0 = 37.313968658447266;
  test_msg.cp = 252.83935546875;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 1;

  EXPECT_EQ(send_message(3112, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 3112);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cf * 100 - 3032.68432617 * 100), 0.05)
      << "incorrect value for last_msg_.cf, expected 3032.68432617, is "
      << last_msg_.cf;
  EXPECT_LT((last_msg_.cn0 * 100 - 37.3139686584 * 100), 0.05)
      << "incorrect value for last_msg_.cn0, expected 37.3139686584, is "
      << last_msg_.cn0;
  EXPECT_LT((last_msg_.cp * 100 - 252.839355469 * 100), 0.05)
      << "incorrect value for last_msg_.cp, expected 252.839355469, is "
      << last_msg_.cp;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 1)
      << "incorrect value for last_msg_.sid.sat, expected 1, is "
      << last_msg_.sid.sat;
}
class Test_auto_check_sbp_acquisition_MsgAcqResultDepC4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_acq_result_dep_c_t> {
 public:
  Test_auto_check_sbp_acquisition_MsgAcqResultDepC4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_acq_result_dep_c_t>(this),
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
                      const sbp_msg_acq_result_dep_c_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_acq_result_dep_c_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_acquisition_MsgAcqResultDepC4, Test) {
  uint8_t encoded_frame[] = {
      85,  31, 0,   40,  12, 16, 126, 35, 62, 66, 226, 37,
      102, 68, 202, 243, 29, 69, 27,  0,  0,  0,  91,  67,
  };

  sbp_msg_acq_result_dep_c_t test_msg{};
  test_msg.cf = 2527.23681640625;
  test_msg.cn0 = 47.53466033935547;
  test_msg.cp = 920.5919189453125;
  test_msg.sid.code = 0;
  test_msg.sid.reserved = 0;
  test_msg.sid.sat = 27;

  EXPECT_EQ(send_message(3112, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 3112);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_LT((last_msg_.cf * 100 - 2527.23681641 * 100), 0.05)
      << "incorrect value for last_msg_.cf, expected 2527.23681641, is "
      << last_msg_.cf;
  EXPECT_LT((last_msg_.cn0 * 100 - 47.5346603394 * 100), 0.05)
      << "incorrect value for last_msg_.cn0, expected 47.5346603394, is "
      << last_msg_.cn0;
  EXPECT_LT((last_msg_.cp * 100 - 920.591918945 * 100), 0.05)
      << "incorrect value for last_msg_.cp, expected 920.591918945, is "
      << last_msg_.cp;
  EXPECT_EQ(last_msg_.sid.code, 0)
      << "incorrect value for last_msg_.sid.code, expected 0, is "
      << last_msg_.sid.code;
  EXPECT_EQ(last_msg_.sid.reserved, 0)
      << "incorrect value for last_msg_.sid.reserved, expected 0, is "
      << last_msg_.sid.reserved;
  EXPECT_EQ(last_msg_.sid.sat, 27)
      << "incorrect value for last_msg_.sid.sat, expected 27, is "
      << last_msg_.sid.sat;
}
