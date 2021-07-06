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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepA.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_acq_result_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_acq_result_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_acq_result_dep_a_t *>(last_msg_storage_)),
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
                      const msg_acq_result_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_acq_result_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA0, Test) {
  uint8_t encoded_frame[] = {
      85,  21, 0,  195, 4,   13, 0,  0, 104, 65, 0,
      192, 53, 68, 198, 199, 0,  70, 8, 2,   68,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_acq_result_dep_a_t *test_msg = (msg_acq_result_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cf = 8241.943359375;
  test_msg->cp = 727.0;
  test_msg->prn = 8;
  test_msg->snr = 14.5;

  EXPECT_EQ(send_message(0x15, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->cf * 100 - 8241.94335938 * 100), 0.05)
      << "incorrect value for cf, expected 8241.94335938, is " << last_msg_->cf;
  EXPECT_LT((last_msg_->cp * 100 - 727.0 * 100), 0.05)
      << "incorrect value for cp, expected 727.0, is " << last_msg_->cp;
  EXPECT_EQ(last_msg_->prn, 8)
      << "incorrect value for prn, expected 8, is " << last_msg_->prn;
  EXPECT_LT((last_msg_->snr * 100 - 14.5 * 100), 0.05)
      << "incorrect value for snr, expected 14.5, is " << last_msg_->snr;
}
class Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_acq_result_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_acq_result_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_acq_result_dep_a_t *>(last_msg_storage_)),
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
                      const msg_acq_result_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_acq_result_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA1, Test) {
  uint8_t encoded_frame[] = {
      85,  21,  0,  195, 4,  13, 205, 204, 116, 65, 0,
      192, 179, 67, 33,  81, 59, 68,  9,   219, 27,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_acq_result_dep_a_t *test_msg = (msg_acq_result_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cf = 749.2676391601562;
  test_msg->cp = 359.5;
  test_msg->prn = 9;
  test_msg->snr = 15.300000190734863;

  EXPECT_EQ(send_message(0x15, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->cf * 100 - 749.26763916 * 100), 0.05)
      << "incorrect value for cf, expected 749.26763916, is " << last_msg_->cf;
  EXPECT_LT((last_msg_->cp * 100 - 359.5 * 100), 0.05)
      << "incorrect value for cp, expected 359.5, is " << last_msg_->cp;
  EXPECT_EQ(last_msg_->prn, 9)
      << "incorrect value for prn, expected 9, is " << last_msg_->prn;
  EXPECT_LT((last_msg_->snr * 100 - 15.3000001907 * 100), 0.05)
      << "incorrect value for snr, expected 15.3000001907, is "
      << last_msg_->snr;
}
class Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_acq_result_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_acq_result_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_acq_result_dep_a_t *>(last_msg_storage_)),
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
                      const msg_acq_result_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_acq_result_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA2, Test) {
  uint8_t encoded_frame[] = {
      85, 21, 0,  195, 4,   13,  205, 204, 144, 65, 0,
      0,  34, 66, 57,  237, 202, 197, 11,  150, 35,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_acq_result_dep_a_t *test_msg = (msg_acq_result_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cf = -6493.65283203125;
  test_msg->cp = 40.5;
  test_msg->prn = 11;
  test_msg->snr = 18.100000381469727;

  EXPECT_EQ(send_message(0x15, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->cf * 100 - -6493.65283203 * 100), 0.05)
      << "incorrect value for cf, expected -6493.65283203, is "
      << last_msg_->cf;
  EXPECT_LT((last_msg_->cp * 100 - 40.5 * 100), 0.05)
      << "incorrect value for cp, expected 40.5, is " << last_msg_->cp;
  EXPECT_EQ(last_msg_->prn, 11)
      << "incorrect value for prn, expected 11, is " << last_msg_->prn;
  EXPECT_LT((last_msg_->snr * 100 - 18.1000003815 * 100), 0.05)
      << "incorrect value for snr, expected 18.1000003815, is "
      << last_msg_->snr;
}
class Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_acq_result_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_acq_result_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_acq_result_dep_a_t *>(last_msg_storage_)),
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
                      const msg_acq_result_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_acq_result_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA3, Test) {
  uint8_t encoded_frame[] = {
      85, 21, 0,  195, 4,   13,  205, 204, 116, 65,  0,
      32, 9,  68, 129, 193, 121, 196, 12,  146, 118,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_acq_result_dep_a_t *test_msg = (msg_acq_result_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cf = -999.0234985351562;
  test_msg->cp = 548.5;
  test_msg->prn = 12;
  test_msg->snr = 15.300000190734863;

  EXPECT_EQ(send_message(0x15, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->cf * 100 - -999.023498535 * 100), 0.05)
      << "incorrect value for cf, expected -999.023498535, is "
      << last_msg_->cf;
  EXPECT_LT((last_msg_->cp * 100 - 548.5 * 100), 0.05)
      << "incorrect value for cp, expected 548.5, is " << last_msg_->cp;
  EXPECT_EQ(last_msg_->prn, 12)
      << "incorrect value for prn, expected 12, is " << last_msg_->prn;
  EXPECT_LT((last_msg_->snr * 100 - 15.3000001907 * 100), 0.05)
      << "incorrect value for snr, expected 15.3000001907, is "
      << last_msg_->snr;
}
class Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_acq_result_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_acq_result_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_acq_result_dep_a_t *>(last_msg_storage_)),
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
                      const msg_acq_result_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_acq_result_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA4, Test) {
  uint8_t encoded_frame[] = {
      85, 21, 0,  195, 4,  13,  205, 204, 116, 65, 0,
      32, 67, 68, 228, 74, 148, 69,  14,  23,  75,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_acq_result_dep_a_t *test_msg = (msg_acq_result_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cf = 4745.361328125;
  test_msg->cp = 780.5;
  test_msg->prn = 14;
  test_msg->snr = 15.300000190734863;

  EXPECT_EQ(send_message(0x15, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->cf * 100 - 4745.36132812 * 100), 0.05)
      << "incorrect value for cf, expected 4745.36132812, is " << last_msg_->cf;
  EXPECT_LT((last_msg_->cp * 100 - 780.5 * 100), 0.05)
      << "incorrect value for cp, expected 780.5, is " << last_msg_->cp;
  EXPECT_EQ(last_msg_->prn, 14)
      << "incorrect value for prn, expected 14, is " << last_msg_->prn;
  EXPECT_LT((last_msg_->snr * 100 - 15.3000001907 * 100), 0.05)
      << "incorrect value for snr, expected 15.3000001907, is "
      << last_msg_->snr;
}
class Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA5
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_acq_result_dep_a_t> {
 public:
  Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA5()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_acq_result_dep_a_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_acq_result_dep_a_t *>(last_msg_storage_)),
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
                      const msg_acq_result_dep_a_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_acq_result_dep_a_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_acquisition_MsgAcqResultDepA5, Test) {
  uint8_t encoded_frame[] = {
      85, 21, 0,  195, 4,   13,  228, 56, 35,  67,  0,
      32, 18, 68, 129, 193, 249, 195, 0,  204, 207,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_acq_result_dep_a_t *test_msg = (msg_acq_result_dep_a_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->cf = -499.5117492675781;
  test_msg->cp = 584.5;
  test_msg->prn = 0;
  test_msg->snr = 163.22222900390625;

  EXPECT_EQ(send_message(0x15, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_LT((last_msg_->cf * 100 - -499.511749268 * 100), 0.05)
      << "incorrect value for cf, expected -499.511749268, is "
      << last_msg_->cf;
  EXPECT_LT((last_msg_->cp * 100 - 584.5 * 100), 0.05)
      << "incorrect value for cp, expected 584.5, is " << last_msg_->cp;
  EXPECT_EQ(last_msg_->prn, 0)
      << "incorrect value for prn, expected 0, is " << last_msg_->prn;
  EXPECT_LT((last_msg_->snr * 100 - 163.222229004 * 100), 0.05)
      << "incorrect value for snr, expected 163.222229004, is "
      << last_msg_->snr;
}
