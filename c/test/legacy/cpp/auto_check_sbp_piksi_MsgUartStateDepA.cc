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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartStateDepA.yaml by generate.py.
// Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_uart_state_depa_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_uart_state_depa_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_uart_state_depa_t *>(last_msg_storage_)),
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
                      const msg_uart_state_depa_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_uart_state_depa_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA0, Test) {
  uint8_t encoded_frame[] = {
      85,  24,  0,  195, 4, 58, 0, 0, 0, 0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,  0,   0, 0,  0, 0, 0, 0,   0,   0,   0,   0,   0,   0,   0,
      154, 153, 57, 65,  0, 0,  0, 0, 0, 0,   0,   0,   15,  0,   255, 255, 255,
      255, 0,   0,  0,   0, 0,  0, 0, 0, 255, 255, 255, 255, 247, 5,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_uart_state_depa_t *test_msg = (msg_uart_state_depa_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->latency.avg = -1;
  test_msg->latency.current = -1;
  test_msg->latency.lmax = 0;
  test_msg->latency.lmin = 0;
  test_msg->uart_a.crc_error_count = 0;
  test_msg->uart_a.io_error_count = 0;
  test_msg->uart_a.rx_buffer_level = 0;
  test_msg->uart_a.rx_throughput = 0.0;
  test_msg->uart_a.tx_buffer_level = 0;
  test_msg->uart_a.tx_throughput = 0.0;
  test_msg->uart_b.crc_error_count = 0;
  test_msg->uart_b.io_error_count = 0;
  test_msg->uart_b.rx_buffer_level = 0;
  test_msg->uart_b.rx_throughput = 0.0;
  test_msg->uart_b.tx_buffer_level = 0;
  test_msg->uart_b.tx_throughput = 0.0;
  test_msg->uart_ftdi.crc_error_count = 0;
  test_msg->uart_ftdi.io_error_count = 0;
  test_msg->uart_ftdi.rx_buffer_level = 0;
  test_msg->uart_ftdi.rx_throughput = 0.0;
  test_msg->uart_ftdi.tx_buffer_level = 15;
  test_msg->uart_ftdi.tx_throughput = 11.600000381469727;

  EXPECT_EQ(send_message(0x18, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->latency.avg, -1)
      << "incorrect value for latency.avg, expected -1, is "
      << last_msg_->latency.avg;
  EXPECT_EQ(last_msg_->latency.current, -1)
      << "incorrect value for latency.current, expected -1, is "
      << last_msg_->latency.current;
  EXPECT_EQ(last_msg_->latency.lmax, 0)
      << "incorrect value for latency.lmax, expected 0, is "
      << last_msg_->latency.lmax;
  EXPECT_EQ(last_msg_->latency.lmin, 0)
      << "incorrect value for latency.lmin, expected 0, is "
      << last_msg_->latency.lmin;
  EXPECT_EQ(last_msg_->uart_a.crc_error_count, 0)
      << "incorrect value for uart_a.crc_error_count, expected 0, is "
      << last_msg_->uart_a.crc_error_count;
  EXPECT_EQ(last_msg_->uart_a.io_error_count, 0)
      << "incorrect value for uart_a.io_error_count, expected 0, is "
      << last_msg_->uart_a.io_error_count;
  EXPECT_EQ(last_msg_->uart_a.rx_buffer_level, 0)
      << "incorrect value for uart_a.rx_buffer_level, expected 0, is "
      << last_msg_->uart_a.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_a.rx_throughput, expected 0.0, is "
      << last_msg_->uart_a.rx_throughput;
  EXPECT_EQ(last_msg_->uart_a.tx_buffer_level, 0)
      << "incorrect value for uart_a.tx_buffer_level, expected 0, is "
      << last_msg_->uart_a.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.tx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_a.tx_throughput, expected 0.0, is "
      << last_msg_->uart_a.tx_throughput;
  EXPECT_EQ(last_msg_->uart_b.crc_error_count, 0)
      << "incorrect value for uart_b.crc_error_count, expected 0, is "
      << last_msg_->uart_b.crc_error_count;
  EXPECT_EQ(last_msg_->uart_b.io_error_count, 0)
      << "incorrect value for uart_b.io_error_count, expected 0, is "
      << last_msg_->uart_b.io_error_count;
  EXPECT_EQ(last_msg_->uart_b.rx_buffer_level, 0)
      << "incorrect value for uart_b.rx_buffer_level, expected 0, is "
      << last_msg_->uart_b.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_b.rx_throughput, expected 0.0, is "
      << last_msg_->uart_b.rx_throughput;
  EXPECT_EQ(last_msg_->uart_b.tx_buffer_level, 0)
      << "incorrect value for uart_b.tx_buffer_level, expected 0, is "
      << last_msg_->uart_b.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.tx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_b.tx_throughput, expected 0.0, is "
      << last_msg_->uart_b.tx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.crc_error_count, 0)
      << "incorrect value for uart_ftdi.crc_error_count, expected 0, is "
      << last_msg_->uart_ftdi.crc_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.io_error_count, 0)
      << "incorrect value for uart_ftdi.io_error_count, expected 0, is "
      << last_msg_->uart_ftdi.io_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.rx_buffer_level, 0)
      << "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is "
      << last_msg_->uart_ftdi.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is "
      << last_msg_->uart_ftdi.rx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.tx_buffer_level, 15)
      << "incorrect value for uart_ftdi.tx_buffer_level, expected 15, is "
      << last_msg_->uart_ftdi.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.tx_throughput * 100 - 11.6000003815 * 100),
            0.05)
      << "incorrect value for uart_ftdi.tx_throughput, expected 11.6000003815, "
         "is "
      << last_msg_->uart_ftdi.tx_throughput;
}
class Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_uart_state_depa_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_uart_state_depa_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_uart_state_depa_t *>(last_msg_storage_)),
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
                      const msg_uart_state_depa_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_uart_state_depa_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA1, Test) {
  uint8_t encoded_frame[] = {
      85,  24, 0,   195, 4, 58, 0, 0, 0, 0,   0,   0,   0,   0,  0,   0,   0,
      0,   0,  0,   0,   0, 0,  0, 0, 0, 0,   0,   0,   0,   0,  0,   0,   0,
      2,   43, 135, 61,  0, 0,  0, 0, 0, 0,   0,   0,   0,   0,  255, 255, 255,
      255, 0,  0,   0,   0, 0,  0, 0, 0, 255, 255, 255, 255, 65, 110,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_uart_state_depa_t *test_msg = (msg_uart_state_depa_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->latency.avg = -1;
  test_msg->latency.current = -1;
  test_msg->latency.lmax = 0;
  test_msg->latency.lmin = 0;
  test_msg->uart_a.crc_error_count = 0;
  test_msg->uart_a.io_error_count = 0;
  test_msg->uart_a.rx_buffer_level = 0;
  test_msg->uart_a.rx_throughput = 0.0;
  test_msg->uart_a.tx_buffer_level = 0;
  test_msg->uart_a.tx_throughput = 0.0;
  test_msg->uart_b.crc_error_count = 0;
  test_msg->uart_b.io_error_count = 0;
  test_msg->uart_b.rx_buffer_level = 0;
  test_msg->uart_b.rx_throughput = 0.0;
  test_msg->uart_b.tx_buffer_level = 0;
  test_msg->uart_b.tx_throughput = 0.0;
  test_msg->uart_ftdi.crc_error_count = 0;
  test_msg->uart_ftdi.io_error_count = 0;
  test_msg->uart_ftdi.rx_buffer_level = 0;
  test_msg->uart_ftdi.rx_throughput = 0.0;
  test_msg->uart_ftdi.tx_buffer_level = 0;
  test_msg->uart_ftdi.tx_throughput = 0.06599999964237213;

  EXPECT_EQ(send_message(0x18, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->latency.avg, -1)
      << "incorrect value for latency.avg, expected -1, is "
      << last_msg_->latency.avg;
  EXPECT_EQ(last_msg_->latency.current, -1)
      << "incorrect value for latency.current, expected -1, is "
      << last_msg_->latency.current;
  EXPECT_EQ(last_msg_->latency.lmax, 0)
      << "incorrect value for latency.lmax, expected 0, is "
      << last_msg_->latency.lmax;
  EXPECT_EQ(last_msg_->latency.lmin, 0)
      << "incorrect value for latency.lmin, expected 0, is "
      << last_msg_->latency.lmin;
  EXPECT_EQ(last_msg_->uart_a.crc_error_count, 0)
      << "incorrect value for uart_a.crc_error_count, expected 0, is "
      << last_msg_->uart_a.crc_error_count;
  EXPECT_EQ(last_msg_->uart_a.io_error_count, 0)
      << "incorrect value for uart_a.io_error_count, expected 0, is "
      << last_msg_->uart_a.io_error_count;
  EXPECT_EQ(last_msg_->uart_a.rx_buffer_level, 0)
      << "incorrect value for uart_a.rx_buffer_level, expected 0, is "
      << last_msg_->uart_a.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_a.rx_throughput, expected 0.0, is "
      << last_msg_->uart_a.rx_throughput;
  EXPECT_EQ(last_msg_->uart_a.tx_buffer_level, 0)
      << "incorrect value for uart_a.tx_buffer_level, expected 0, is "
      << last_msg_->uart_a.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.tx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_a.tx_throughput, expected 0.0, is "
      << last_msg_->uart_a.tx_throughput;
  EXPECT_EQ(last_msg_->uart_b.crc_error_count, 0)
      << "incorrect value for uart_b.crc_error_count, expected 0, is "
      << last_msg_->uart_b.crc_error_count;
  EXPECT_EQ(last_msg_->uart_b.io_error_count, 0)
      << "incorrect value for uart_b.io_error_count, expected 0, is "
      << last_msg_->uart_b.io_error_count;
  EXPECT_EQ(last_msg_->uart_b.rx_buffer_level, 0)
      << "incorrect value for uart_b.rx_buffer_level, expected 0, is "
      << last_msg_->uart_b.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_b.rx_throughput, expected 0.0, is "
      << last_msg_->uart_b.rx_throughput;
  EXPECT_EQ(last_msg_->uart_b.tx_buffer_level, 0)
      << "incorrect value for uart_b.tx_buffer_level, expected 0, is "
      << last_msg_->uart_b.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.tx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_b.tx_throughput, expected 0.0, is "
      << last_msg_->uart_b.tx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.crc_error_count, 0)
      << "incorrect value for uart_ftdi.crc_error_count, expected 0, is "
      << last_msg_->uart_ftdi.crc_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.io_error_count, 0)
      << "incorrect value for uart_ftdi.io_error_count, expected 0, is "
      << last_msg_->uart_ftdi.io_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.rx_buffer_level, 0)
      << "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is "
      << last_msg_->uart_ftdi.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is "
      << last_msg_->uart_ftdi.rx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.tx_buffer_level, 0)
      << "incorrect value for uart_ftdi.tx_buffer_level, expected 0, is "
      << last_msg_->uart_ftdi.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.tx_throughput * 100 - 0.0659999996424 * 100),
            0.05)
      << "incorrect value for uart_ftdi.tx_throughput, expected "
         "0.0659999996424, is "
      << last_msg_->uart_ftdi.tx_throughput;
}
class Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_uart_state_depa_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_uart_state_depa_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_uart_state_depa_t *>(last_msg_storage_)),
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
                      const msg_uart_state_depa_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_uart_state_depa_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA2, Test) {
  uint8_t encoded_frame[] = {
      85,  24, 0,  195, 4, 58, 0, 0, 0, 0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,  0,  0,   0, 0,  0, 0, 0, 0,   0,   0,   0,   0,   0,   0,   0,
      4,   86, 14, 62,  0, 0,  0, 0, 0, 0,   0,   0,   10,  0,   255, 255, 255,
      255, 0,  0,  0,   0, 0,  0, 0, 0, 255, 255, 255, 255, 198, 36,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_uart_state_depa_t *test_msg = (msg_uart_state_depa_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->latency.avg = -1;
  test_msg->latency.current = -1;
  test_msg->latency.lmax = 0;
  test_msg->latency.lmin = 0;
  test_msg->uart_a.crc_error_count = 0;
  test_msg->uart_a.io_error_count = 0;
  test_msg->uart_a.rx_buffer_level = 0;
  test_msg->uart_a.rx_throughput = 0.0;
  test_msg->uart_a.tx_buffer_level = 0;
  test_msg->uart_a.tx_throughput = 0.0;
  test_msg->uart_b.crc_error_count = 0;
  test_msg->uart_b.io_error_count = 0;
  test_msg->uart_b.rx_buffer_level = 0;
  test_msg->uart_b.rx_throughput = 0.0;
  test_msg->uart_b.tx_buffer_level = 0;
  test_msg->uart_b.tx_throughput = 0.0;
  test_msg->uart_ftdi.crc_error_count = 0;
  test_msg->uart_ftdi.io_error_count = 0;
  test_msg->uart_ftdi.rx_buffer_level = 0;
  test_msg->uart_ftdi.rx_throughput = 0.0;
  test_msg->uart_ftdi.tx_buffer_level = 10;
  test_msg->uart_ftdi.tx_throughput = 0.13899999856948853;

  EXPECT_EQ(send_message(0x18, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->latency.avg, -1)
      << "incorrect value for latency.avg, expected -1, is "
      << last_msg_->latency.avg;
  EXPECT_EQ(last_msg_->latency.current, -1)
      << "incorrect value for latency.current, expected -1, is "
      << last_msg_->latency.current;
  EXPECT_EQ(last_msg_->latency.lmax, 0)
      << "incorrect value for latency.lmax, expected 0, is "
      << last_msg_->latency.lmax;
  EXPECT_EQ(last_msg_->latency.lmin, 0)
      << "incorrect value for latency.lmin, expected 0, is "
      << last_msg_->latency.lmin;
  EXPECT_EQ(last_msg_->uart_a.crc_error_count, 0)
      << "incorrect value for uart_a.crc_error_count, expected 0, is "
      << last_msg_->uart_a.crc_error_count;
  EXPECT_EQ(last_msg_->uart_a.io_error_count, 0)
      << "incorrect value for uart_a.io_error_count, expected 0, is "
      << last_msg_->uart_a.io_error_count;
  EXPECT_EQ(last_msg_->uart_a.rx_buffer_level, 0)
      << "incorrect value for uart_a.rx_buffer_level, expected 0, is "
      << last_msg_->uart_a.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_a.rx_throughput, expected 0.0, is "
      << last_msg_->uart_a.rx_throughput;
  EXPECT_EQ(last_msg_->uart_a.tx_buffer_level, 0)
      << "incorrect value for uart_a.tx_buffer_level, expected 0, is "
      << last_msg_->uart_a.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.tx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_a.tx_throughput, expected 0.0, is "
      << last_msg_->uart_a.tx_throughput;
  EXPECT_EQ(last_msg_->uart_b.crc_error_count, 0)
      << "incorrect value for uart_b.crc_error_count, expected 0, is "
      << last_msg_->uart_b.crc_error_count;
  EXPECT_EQ(last_msg_->uart_b.io_error_count, 0)
      << "incorrect value for uart_b.io_error_count, expected 0, is "
      << last_msg_->uart_b.io_error_count;
  EXPECT_EQ(last_msg_->uart_b.rx_buffer_level, 0)
      << "incorrect value for uart_b.rx_buffer_level, expected 0, is "
      << last_msg_->uart_b.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_b.rx_throughput, expected 0.0, is "
      << last_msg_->uart_b.rx_throughput;
  EXPECT_EQ(last_msg_->uart_b.tx_buffer_level, 0)
      << "incorrect value for uart_b.tx_buffer_level, expected 0, is "
      << last_msg_->uart_b.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.tx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_b.tx_throughput, expected 0.0, is "
      << last_msg_->uart_b.tx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.crc_error_count, 0)
      << "incorrect value for uart_ftdi.crc_error_count, expected 0, is "
      << last_msg_->uart_ftdi.crc_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.io_error_count, 0)
      << "incorrect value for uart_ftdi.io_error_count, expected 0, is "
      << last_msg_->uart_ftdi.io_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.rx_buffer_level, 0)
      << "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is "
      << last_msg_->uart_ftdi.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is "
      << last_msg_->uart_ftdi.rx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.tx_buffer_level, 10)
      << "incorrect value for uart_ftdi.tx_buffer_level, expected 10, is "
      << last_msg_->uart_ftdi.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.tx_throughput * 100 - 0.138999998569 * 100),
            0.05)
      << "incorrect value for uart_ftdi.tx_throughput, expected "
         "0.138999998569, is "
      << last_msg_->uart_ftdi.tx_throughput;
}
class Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_uart_state_depa_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_uart_state_depa_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_uart_state_depa_t *>(last_msg_storage_)),
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
                      const msg_uart_state_depa_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_uart_state_depa_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA3, Test) {
  uint8_t encoded_frame[] = {
      85,  24, 0,   195, 4, 58, 0, 0, 0, 0,   0,   0,   0,   0,  0,   0,   0,
      0,   0,  0,   0,   0, 0,  0, 0, 0, 0,   0,   0,   0,   0,  0,   0,   0,
      2,   43, 135, 61,  0, 0,  0, 0, 0, 0,   0,   0,   0,   0,  255, 255, 255,
      255, 0,  0,   0,   0, 0,  0, 0, 0, 255, 255, 255, 255, 65, 110,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_uart_state_depa_t *test_msg = (msg_uart_state_depa_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->latency.avg = -1;
  test_msg->latency.current = -1;
  test_msg->latency.lmax = 0;
  test_msg->latency.lmin = 0;
  test_msg->uart_a.crc_error_count = 0;
  test_msg->uart_a.io_error_count = 0;
  test_msg->uart_a.rx_buffer_level = 0;
  test_msg->uart_a.rx_throughput = 0.0;
  test_msg->uart_a.tx_buffer_level = 0;
  test_msg->uart_a.tx_throughput = 0.0;
  test_msg->uart_b.crc_error_count = 0;
  test_msg->uart_b.io_error_count = 0;
  test_msg->uart_b.rx_buffer_level = 0;
  test_msg->uart_b.rx_throughput = 0.0;
  test_msg->uart_b.tx_buffer_level = 0;
  test_msg->uart_b.tx_throughput = 0.0;
  test_msg->uart_ftdi.crc_error_count = 0;
  test_msg->uart_ftdi.io_error_count = 0;
  test_msg->uart_ftdi.rx_buffer_level = 0;
  test_msg->uart_ftdi.rx_throughput = 0.0;
  test_msg->uart_ftdi.tx_buffer_level = 0;
  test_msg->uart_ftdi.tx_throughput = 0.06599999964237213;

  EXPECT_EQ(send_message(0x18, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->latency.avg, -1)
      << "incorrect value for latency.avg, expected -1, is "
      << last_msg_->latency.avg;
  EXPECT_EQ(last_msg_->latency.current, -1)
      << "incorrect value for latency.current, expected -1, is "
      << last_msg_->latency.current;
  EXPECT_EQ(last_msg_->latency.lmax, 0)
      << "incorrect value for latency.lmax, expected 0, is "
      << last_msg_->latency.lmax;
  EXPECT_EQ(last_msg_->latency.lmin, 0)
      << "incorrect value for latency.lmin, expected 0, is "
      << last_msg_->latency.lmin;
  EXPECT_EQ(last_msg_->uart_a.crc_error_count, 0)
      << "incorrect value for uart_a.crc_error_count, expected 0, is "
      << last_msg_->uart_a.crc_error_count;
  EXPECT_EQ(last_msg_->uart_a.io_error_count, 0)
      << "incorrect value for uart_a.io_error_count, expected 0, is "
      << last_msg_->uart_a.io_error_count;
  EXPECT_EQ(last_msg_->uart_a.rx_buffer_level, 0)
      << "incorrect value for uart_a.rx_buffer_level, expected 0, is "
      << last_msg_->uart_a.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_a.rx_throughput, expected 0.0, is "
      << last_msg_->uart_a.rx_throughput;
  EXPECT_EQ(last_msg_->uart_a.tx_buffer_level, 0)
      << "incorrect value for uart_a.tx_buffer_level, expected 0, is "
      << last_msg_->uart_a.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.tx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_a.tx_throughput, expected 0.0, is "
      << last_msg_->uart_a.tx_throughput;
  EXPECT_EQ(last_msg_->uart_b.crc_error_count, 0)
      << "incorrect value for uart_b.crc_error_count, expected 0, is "
      << last_msg_->uart_b.crc_error_count;
  EXPECT_EQ(last_msg_->uart_b.io_error_count, 0)
      << "incorrect value for uart_b.io_error_count, expected 0, is "
      << last_msg_->uart_b.io_error_count;
  EXPECT_EQ(last_msg_->uart_b.rx_buffer_level, 0)
      << "incorrect value for uart_b.rx_buffer_level, expected 0, is "
      << last_msg_->uart_b.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_b.rx_throughput, expected 0.0, is "
      << last_msg_->uart_b.rx_throughput;
  EXPECT_EQ(last_msg_->uart_b.tx_buffer_level, 0)
      << "incorrect value for uart_b.tx_buffer_level, expected 0, is "
      << last_msg_->uart_b.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.tx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_b.tx_throughput, expected 0.0, is "
      << last_msg_->uart_b.tx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.crc_error_count, 0)
      << "incorrect value for uart_ftdi.crc_error_count, expected 0, is "
      << last_msg_->uart_ftdi.crc_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.io_error_count, 0)
      << "incorrect value for uart_ftdi.io_error_count, expected 0, is "
      << last_msg_->uart_ftdi.io_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.rx_buffer_level, 0)
      << "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is "
      << last_msg_->uart_ftdi.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is "
      << last_msg_->uart_ftdi.rx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.tx_buffer_level, 0)
      << "incorrect value for uart_ftdi.tx_buffer_level, expected 0, is "
      << last_msg_->uart_ftdi.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.tx_throughput * 100 - 0.0659999996424 * 100),
            0.05)
      << "incorrect value for uart_ftdi.tx_throughput, expected "
         "0.0659999996424, is "
      << last_msg_->uart_ftdi.tx_throughput;
}
class Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_uart_state_depa_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_uart_state_depa_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_uart_state_depa_t *>(last_msg_storage_)),
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
                      const msg_uart_state_depa_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_uart_state_depa_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA4, Test) {
  uint8_t encoded_frame[] = {
      85, 24, 0, 195, 4,   58,  0,   0,   0,   0,   138, 75, 6, 60,
      0,  0,  0, 0,   0,   0,   80,  113, 201, 61,  0,   0,  0, 0,
      0,  0,  0, 0,   2,   0,   145, 237, 252, 62,  0,   0,  0, 0,
      0,  0,  0, 0,   38,  0,   255, 255, 255, 255, 0,   0,  0, 0,
      0,  0,  0, 0,   255, 255, 255, 255, 112, 111,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_uart_state_depa_t *test_msg = (msg_uart_state_depa_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->latency.avg = -1;
  test_msg->latency.current = -1;
  test_msg->latency.lmax = 0;
  test_msg->latency.lmin = 0;
  test_msg->uart_a.crc_error_count = 0;
  test_msg->uart_a.io_error_count = 0;
  test_msg->uart_a.rx_buffer_level = 0;
  test_msg->uart_a.rx_throughput = 0.008196720853447914;
  test_msg->uart_a.tx_buffer_level = 0;
  test_msg->uart_a.tx_throughput = 0.0;
  test_msg->uart_b.crc_error_count = 0;
  test_msg->uart_b.io_error_count = 0;
  test_msg->uart_b.rx_buffer_level = 0;
  test_msg->uart_b.rx_throughput = 0.0;
  test_msg->uart_b.tx_buffer_level = 2;
  test_msg->uart_b.tx_throughput = 0.09836065769195557;
  test_msg->uart_ftdi.crc_error_count = 0;
  test_msg->uart_ftdi.io_error_count = 0;
  test_msg->uart_ftdi.rx_buffer_level = 0;
  test_msg->uart_ftdi.rx_throughput = 0.0;
  test_msg->uart_ftdi.tx_buffer_level = 38;
  test_msg->uart_ftdi.tx_throughput = 0.49399998784065247;

  EXPECT_EQ(send_message(0x18, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->latency.avg, -1)
      << "incorrect value for latency.avg, expected -1, is "
      << last_msg_->latency.avg;
  EXPECT_EQ(last_msg_->latency.current, -1)
      << "incorrect value for latency.current, expected -1, is "
      << last_msg_->latency.current;
  EXPECT_EQ(last_msg_->latency.lmax, 0)
      << "incorrect value for latency.lmax, expected 0, is "
      << last_msg_->latency.lmax;
  EXPECT_EQ(last_msg_->latency.lmin, 0)
      << "incorrect value for latency.lmin, expected 0, is "
      << last_msg_->latency.lmin;
  EXPECT_EQ(last_msg_->uart_a.crc_error_count, 0)
      << "incorrect value for uart_a.crc_error_count, expected 0, is "
      << last_msg_->uart_a.crc_error_count;
  EXPECT_EQ(last_msg_->uart_a.io_error_count, 0)
      << "incorrect value for uart_a.io_error_count, expected 0, is "
      << last_msg_->uart_a.io_error_count;
  EXPECT_EQ(last_msg_->uart_a.rx_buffer_level, 0)
      << "incorrect value for uart_a.rx_buffer_level, expected 0, is "
      << last_msg_->uart_a.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.rx_throughput * 100 - 0.00819672085345 * 100),
            0.05)
      << "incorrect value for uart_a.rx_throughput, expected 0.00819672085345, "
         "is "
      << last_msg_->uart_a.rx_throughput;
  EXPECT_EQ(last_msg_->uart_a.tx_buffer_level, 0)
      << "incorrect value for uart_a.tx_buffer_level, expected 0, is "
      << last_msg_->uart_a.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.tx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_a.tx_throughput, expected 0.0, is "
      << last_msg_->uart_a.tx_throughput;
  EXPECT_EQ(last_msg_->uart_b.crc_error_count, 0)
      << "incorrect value for uart_b.crc_error_count, expected 0, is "
      << last_msg_->uart_b.crc_error_count;
  EXPECT_EQ(last_msg_->uart_b.io_error_count, 0)
      << "incorrect value for uart_b.io_error_count, expected 0, is "
      << last_msg_->uart_b.io_error_count;
  EXPECT_EQ(last_msg_->uart_b.rx_buffer_level, 0)
      << "incorrect value for uart_b.rx_buffer_level, expected 0, is "
      << last_msg_->uart_b.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_b.rx_throughput, expected 0.0, is "
      << last_msg_->uart_b.rx_throughput;
  EXPECT_EQ(last_msg_->uart_b.tx_buffer_level, 2)
      << "incorrect value for uart_b.tx_buffer_level, expected 2, is "
      << last_msg_->uart_b.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.tx_throughput * 100 - 0.098360657692 * 100),
            0.05)
      << "incorrect value for uart_b.tx_throughput, expected 0.098360657692, "
         "is "
      << last_msg_->uart_b.tx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.crc_error_count, 0)
      << "incorrect value for uart_ftdi.crc_error_count, expected 0, is "
      << last_msg_->uart_ftdi.crc_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.io_error_count, 0)
      << "incorrect value for uart_ftdi.io_error_count, expected 0, is "
      << last_msg_->uart_ftdi.io_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.rx_buffer_level, 0)
      << "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is "
      << last_msg_->uart_ftdi.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is "
      << last_msg_->uart_ftdi.rx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.tx_buffer_level, 38)
      << "incorrect value for uart_ftdi.tx_buffer_level, expected 38, is "
      << last_msg_->uart_ftdi.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.tx_throughput * 100 - 0.493999987841 * 100),
            0.05)
      << "incorrect value for uart_ftdi.tx_throughput, expected "
         "0.493999987841, is "
      << last_msg_->uart_ftdi.tx_throughput;
}
class Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA5
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_uart_state_depa_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA5()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_uart_state_depa_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_uart_state_depa_t *>(last_msg_storage_)),
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
                      const msg_uart_state_depa_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_uart_state_depa_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgUartStateDepA5, Test) {
  uint8_t encoded_frame[] = {
      85, 24, 0, 195, 4,   58,  166, 155, 68,  60,  0, 0, 0, 0,
      0,  0,  0, 0,   2,   0,   166, 155, 68,  60,  0, 0, 0, 0,
      0,  0,  0, 0,   2,   0,   236, 81,  168, 63,  0, 0, 0, 0,
      0,  0,  0, 0,   50,  0,   255, 255, 255, 255, 0, 0, 0, 0,
      0,  0,  0, 0,   255, 255, 255, 255, 22,  72,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_uart_state_depa_t *test_msg = (msg_uart_state_depa_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->latency.avg = -1;
  test_msg->latency.current = -1;
  test_msg->latency.lmax = 0;
  test_msg->latency.lmin = 0;
  test_msg->uart_a.crc_error_count = 0;
  test_msg->uart_a.io_error_count = 0;
  test_msg->uart_a.rx_buffer_level = 0;
  test_msg->uart_a.rx_throughput = 0.0;
  test_msg->uart_a.tx_buffer_level = 2;
  test_msg->uart_a.tx_throughput = 0.012000000104308128;
  test_msg->uart_b.crc_error_count = 0;
  test_msg->uart_b.io_error_count = 0;
  test_msg->uart_b.rx_buffer_level = 0;
  test_msg->uart_b.rx_throughput = 0.0;
  test_msg->uart_b.tx_buffer_level = 2;
  test_msg->uart_b.tx_throughput = 0.012000000104308128;
  test_msg->uart_ftdi.crc_error_count = 0;
  test_msg->uart_ftdi.io_error_count = 0;
  test_msg->uart_ftdi.rx_buffer_level = 0;
  test_msg->uart_ftdi.rx_throughput = 0.0;
  test_msg->uart_ftdi.tx_buffer_level = 50;
  test_msg->uart_ftdi.tx_throughput = 1.315000057220459;

  EXPECT_EQ(send_message(0x18, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->latency.avg, -1)
      << "incorrect value for latency.avg, expected -1, is "
      << last_msg_->latency.avg;
  EXPECT_EQ(last_msg_->latency.current, -1)
      << "incorrect value for latency.current, expected -1, is "
      << last_msg_->latency.current;
  EXPECT_EQ(last_msg_->latency.lmax, 0)
      << "incorrect value for latency.lmax, expected 0, is "
      << last_msg_->latency.lmax;
  EXPECT_EQ(last_msg_->latency.lmin, 0)
      << "incorrect value for latency.lmin, expected 0, is "
      << last_msg_->latency.lmin;
  EXPECT_EQ(last_msg_->uart_a.crc_error_count, 0)
      << "incorrect value for uart_a.crc_error_count, expected 0, is "
      << last_msg_->uart_a.crc_error_count;
  EXPECT_EQ(last_msg_->uart_a.io_error_count, 0)
      << "incorrect value for uart_a.io_error_count, expected 0, is "
      << last_msg_->uart_a.io_error_count;
  EXPECT_EQ(last_msg_->uart_a.rx_buffer_level, 0)
      << "incorrect value for uart_a.rx_buffer_level, expected 0, is "
      << last_msg_->uart_a.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_a.rx_throughput, expected 0.0, is "
      << last_msg_->uart_a.rx_throughput;
  EXPECT_EQ(last_msg_->uart_a.tx_buffer_level, 2)
      << "incorrect value for uart_a.tx_buffer_level, expected 2, is "
      << last_msg_->uart_a.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.tx_throughput * 100 - 0.0120000001043 * 100),
            0.05)
      << "incorrect value for uart_a.tx_throughput, expected 0.0120000001043, "
         "is "
      << last_msg_->uart_a.tx_throughput;
  EXPECT_EQ(last_msg_->uart_b.crc_error_count, 0)
      << "incorrect value for uart_b.crc_error_count, expected 0, is "
      << last_msg_->uart_b.crc_error_count;
  EXPECT_EQ(last_msg_->uart_b.io_error_count, 0)
      << "incorrect value for uart_b.io_error_count, expected 0, is "
      << last_msg_->uart_b.io_error_count;
  EXPECT_EQ(last_msg_->uart_b.rx_buffer_level, 0)
      << "incorrect value for uart_b.rx_buffer_level, expected 0, is "
      << last_msg_->uart_b.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_b.rx_throughput, expected 0.0, is "
      << last_msg_->uart_b.rx_throughput;
  EXPECT_EQ(last_msg_->uart_b.tx_buffer_level, 2)
      << "incorrect value for uart_b.tx_buffer_level, expected 2, is "
      << last_msg_->uart_b.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.tx_throughput * 100 - 0.0120000001043 * 100),
            0.05)
      << "incorrect value for uart_b.tx_throughput, expected 0.0120000001043, "
         "is "
      << last_msg_->uart_b.tx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.crc_error_count, 0)
      << "incorrect value for uart_ftdi.crc_error_count, expected 0, is "
      << last_msg_->uart_ftdi.crc_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.io_error_count, 0)
      << "incorrect value for uart_ftdi.io_error_count, expected 0, is "
      << last_msg_->uart_ftdi.io_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.rx_buffer_level, 0)
      << "incorrect value for uart_ftdi.rx_buffer_level, expected 0, is "
      << last_msg_->uart_ftdi.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.rx_throughput * 100 - 0.0 * 100), 0.05)
      << "incorrect value for uart_ftdi.rx_throughput, expected 0.0, is "
      << last_msg_->uart_ftdi.rx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.tx_buffer_level, 50)
      << "incorrect value for uart_ftdi.tx_buffer_level, expected 50, is "
      << last_msg_->uart_ftdi.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.tx_throughput * 100 - 1.31500005722 * 100),
            0.05)
      << "incorrect value for uart_ftdi.tx_throughput, expected 1.31500005722, "
         "is "
      << last_msg_->uart_ftdi.tx_throughput;
}
