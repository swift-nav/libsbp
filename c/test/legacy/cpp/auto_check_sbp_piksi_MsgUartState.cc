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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartState.yaml by generate.py. Do
// not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
class Test_legacy_auto_check_sbp_piksi_MsgUartState0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_uart_state_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgUartState0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_uart_state_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_uart_state_t *>(last_msg_storage_)),
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
                      const msg_uart_state_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_uart_state_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgUartState0, Test) {
  uint8_t encoded_frame[] = {
      85,  29,  0,   200, 224, 74,  154, 169, 242, 69,  102, 166, 231, 68,
      89,  98,  79,  184, 138, 244, 154, 73,  201, 69,  154, 65,  211, 69,
      201, 16,  103, 249, 143, 161, 154, 17,  186, 69,  51,  211, 7,   69,
      215, 149, 253, 25,  218, 24,  29,  195, 16,  19,  159, 142, 71,  17,
      10,  113, 137, 219, 135, 18,  182, 21,  38,  190, 59,  196, 169, 155,
      107, 111, 253, 168, 244, 158, 112, 19,  251, 131, 100, 225,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_uart_state_t *test_msg = (msg_uart_state_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->latency.avg = 319865629;
  test_msg->latency.current = 364253831;
  test_msg->latency.lmax = -611749622;
  test_msg->latency.lmin = 289902239;
  test_msg->obs_period.avg = -1002717658;
  test_msg->obs_period.current = -2080697488;
  test_msg->obs_period.pmax = -1628133123;
  test_msg->obs_period.pmin = 1869323177;
  test_msg->uart_a.crc_error_count = 25177;
  test_msg->uart_a.io_error_count = 47183;
  test_msg->uart_a.rx_buffer_level = 244;
  test_msg->uart_a.rx_throughput = 1853.199951171875;
  test_msg->uart_a.tx_buffer_level = 138;
  test_msg->uart_a.tx_throughput = 7765.2001953125;
  test_msg->uart_b.crc_error_count = 4297;
  test_msg->uart_b.io_error_count = 63847;
  test_msg->uart_b.rx_buffer_level = 161;
  test_msg->uart_b.rx_throughput = 6760.2001953125;
  test_msg->uart_b.tx_buffer_level = 143;
  test_msg->uart_b.tx_throughput = 6441.2001953125;
  test_msg->uart_ftdi.crc_error_count = 38359;
  test_msg->uart_ftdi.io_error_count = 6653;
  test_msg->uart_ftdi.rx_buffer_level = 24;
  test_msg->uart_ftdi.rx_throughput = 2173.199951171875;
  test_msg->uart_ftdi.tx_buffer_level = 218;
  test_msg->uart_ftdi.tx_throughput = 5954.2001953125;

  EXPECT_EQ(send_message(0x1d, 57544, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 57544);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->latency.avg, 319865629)
      << "incorrect value for latency.avg, expected 319865629, is "
      << last_msg_->latency.avg;
  EXPECT_EQ(last_msg_->latency.current, 364253831)
      << "incorrect value for latency.current, expected 364253831, is "
      << last_msg_->latency.current;
  EXPECT_EQ(last_msg_->latency.lmax, -611749622)
      << "incorrect value for latency.lmax, expected -611749622, is "
      << last_msg_->latency.lmax;
  EXPECT_EQ(last_msg_->latency.lmin, 289902239)
      << "incorrect value for latency.lmin, expected 289902239, is "
      << last_msg_->latency.lmin;
  EXPECT_EQ(last_msg_->obs_period.avg, -1002717658)
      << "incorrect value for obs_period.avg, expected -1002717658, is "
      << last_msg_->obs_period.avg;
  EXPECT_EQ(last_msg_->obs_period.current, -2080697488)
      << "incorrect value for obs_period.current, expected -2080697488, is "
      << last_msg_->obs_period.current;
  EXPECT_EQ(last_msg_->obs_period.pmax, -1628133123)
      << "incorrect value for obs_period.pmax, expected -1628133123, is "
      << last_msg_->obs_period.pmax;
  EXPECT_EQ(last_msg_->obs_period.pmin, 1869323177)
      << "incorrect value for obs_period.pmin, expected 1869323177, is "
      << last_msg_->obs_period.pmin;
  EXPECT_EQ(last_msg_->uart_a.crc_error_count, 25177)
      << "incorrect value for uart_a.crc_error_count, expected 25177, is "
      << last_msg_->uart_a.crc_error_count;
  EXPECT_EQ(last_msg_->uart_a.io_error_count, 47183)
      << "incorrect value for uart_a.io_error_count, expected 47183, is "
      << last_msg_->uart_a.io_error_count;
  EXPECT_EQ(last_msg_->uart_a.rx_buffer_level, 244)
      << "incorrect value for uart_a.rx_buffer_level, expected 244, is "
      << last_msg_->uart_a.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.rx_throughput * 100 - 1853.19995117 * 100), 0.05)
      << "incorrect value for uart_a.rx_throughput, expected 1853.19995117, is "
      << last_msg_->uart_a.rx_throughput;
  EXPECT_EQ(last_msg_->uart_a.tx_buffer_level, 138)
      << "incorrect value for uart_a.tx_buffer_level, expected 138, is "
      << last_msg_->uart_a.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.tx_throughput * 100 - 7765.20019531 * 100), 0.05)
      << "incorrect value for uart_a.tx_throughput, expected 7765.20019531, is "
      << last_msg_->uart_a.tx_throughput;
  EXPECT_EQ(last_msg_->uart_b.crc_error_count, 4297)
      << "incorrect value for uart_b.crc_error_count, expected 4297, is "
      << last_msg_->uart_b.crc_error_count;
  EXPECT_EQ(last_msg_->uart_b.io_error_count, 63847)
      << "incorrect value for uart_b.io_error_count, expected 63847, is "
      << last_msg_->uart_b.io_error_count;
  EXPECT_EQ(last_msg_->uart_b.rx_buffer_level, 161)
      << "incorrect value for uart_b.rx_buffer_level, expected 161, is "
      << last_msg_->uart_b.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.rx_throughput * 100 - 6760.20019531 * 100), 0.05)
      << "incorrect value for uart_b.rx_throughput, expected 6760.20019531, is "
      << last_msg_->uart_b.rx_throughput;
  EXPECT_EQ(last_msg_->uart_b.tx_buffer_level, 143)
      << "incorrect value for uart_b.tx_buffer_level, expected 143, is "
      << last_msg_->uart_b.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.tx_throughput * 100 - 6441.20019531 * 100), 0.05)
      << "incorrect value for uart_b.tx_throughput, expected 6441.20019531, is "
      << last_msg_->uart_b.tx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.crc_error_count, 38359)
      << "incorrect value for uart_ftdi.crc_error_count, expected 38359, is "
      << last_msg_->uart_ftdi.crc_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.io_error_count, 6653)
      << "incorrect value for uart_ftdi.io_error_count, expected 6653, is "
      << last_msg_->uart_ftdi.io_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.rx_buffer_level, 24)
      << "incorrect value for uart_ftdi.rx_buffer_level, expected 24, is "
      << last_msg_->uart_ftdi.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.rx_throughput * 100 - 2173.19995117 * 100),
            0.05)
      << "incorrect value for uart_ftdi.rx_throughput, expected 2173.19995117, "
         "is "
      << last_msg_->uart_ftdi.rx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.tx_buffer_level, 218)
      << "incorrect value for uart_ftdi.tx_buffer_level, expected 218, is "
      << last_msg_->uart_ftdi.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.tx_throughput * 100 - 5954.20019531 * 100),
            0.05)
      << "incorrect value for uart_ftdi.tx_throughput, expected 5954.20019531, "
         "is "
      << last_msg_->uart_ftdi.tx_throughput;
}
class Test_legacy_auto_check_sbp_piksi_MsgUartState1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_uart_state_depa_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgUartState1()
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

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgUartState1, Test) {
  uint8_t encoded_frame[] = {
      85, 24, 0, 246, 215, 58,  26,  191, 93,  63,  0,   0,  0,  0,
      0,  0,  0, 0,   24,  0,   123, 50,  62,  64,  0,   0,  0,  0,
      0,  0,  0, 0,   40,  0,   54,  7,   162, 64,  177, 57, 16, 61,
      0,  0,  0, 0,   81,  1,   255, 255, 255, 255, 0,   0,  0,  0,
      0,  0,  0, 0,   255, 255, 255, 255, 71,  124,
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
  test_msg->uart_a.tx_buffer_level = 24;
  test_msg->uart_a.tx_throughput = 0.8661972284317017;
  test_msg->uart_b.crc_error_count = 0;
  test_msg->uart_b.io_error_count = 0;
  test_msg->uart_b.rx_buffer_level = 0;
  test_msg->uart_b.rx_throughput = 0.0;
  test_msg->uart_b.tx_buffer_level = 40;
  test_msg->uart_b.tx_throughput = 2.9718310832977295;
  test_msg->uart_ftdi.crc_error_count = 0;
  test_msg->uart_ftdi.io_error_count = 0;
  test_msg->uart_ftdi.rx_buffer_level = 1;
  test_msg->uart_ftdi.rx_throughput = 0.035211268812417984;
  test_msg->uart_ftdi.tx_buffer_level = 81;
  test_msg->uart_ftdi.tx_throughput = 5.063380241394043;

  EXPECT_EQ(send_message(0x18, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
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
  EXPECT_EQ(last_msg_->uart_a.tx_buffer_level, 24)
      << "incorrect value for uart_a.tx_buffer_level, expected 24, is "
      << last_msg_->uart_a.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.tx_throughput * 100 - 0.866197228432 * 100),
            0.05)
      << "incorrect value for uart_a.tx_throughput, expected 0.866197228432, "
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
  EXPECT_EQ(last_msg_->uart_b.tx_buffer_level, 40)
      << "incorrect value for uart_b.tx_buffer_level, expected 40, is "
      << last_msg_->uart_b.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.tx_throughput * 100 - 2.9718310833 * 100), 0.05)
      << "incorrect value for uart_b.tx_throughput, expected 2.9718310833, is "
      << last_msg_->uart_b.tx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.crc_error_count, 0)
      << "incorrect value for uart_ftdi.crc_error_count, expected 0, is "
      << last_msg_->uart_ftdi.crc_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.io_error_count, 0)
      << "incorrect value for uart_ftdi.io_error_count, expected 0, is "
      << last_msg_->uart_ftdi.io_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.rx_buffer_level, 1)
      << "incorrect value for uart_ftdi.rx_buffer_level, expected 1, is "
      << last_msg_->uart_ftdi.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.rx_throughput * 100 - 0.0352112688124 * 100),
            0.05)
      << "incorrect value for uart_ftdi.rx_throughput, expected "
         "0.0352112688124, is "
      << last_msg_->uart_ftdi.rx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.tx_buffer_level, 81)
      << "incorrect value for uart_ftdi.tx_buffer_level, expected 81, is "
      << last_msg_->uart_ftdi.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.tx_throughput * 100 - 5.06338024139 * 100),
            0.05)
      << "incorrect value for uart_ftdi.tx_throughput, expected 5.06338024139, "
         "is "
      << last_msg_->uart_ftdi.tx_throughput;
}
class Test_legacy_auto_check_sbp_piksi_MsgUartState2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_uart_state_depa_t> {
 public:
  Test_legacy_auto_check_sbp_piksi_MsgUartState2()
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

TEST_F(Test_legacy_auto_check_sbp_piksi_MsgUartState2, Test) {
  uint8_t encoded_frame[] = {
      85, 24, 0, 246, 215, 58,  237, 232, 95,  63,  0,  0,  0,   0,
      0,  0,  0, 0,   24,  0,   198, 186, 63,  64,  0,  0,  0,   0,
      0,  0,  0, 0,   40,  0,   214, 72,  217, 64,  29, 72, 180, 62,
      0,  0,  0, 0,   85,  1,   255, 255, 255, 255, 0,  0,  0,   0,
      0,  0,  0, 0,   255, 255, 255, 255, 153, 248,
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
  test_msg->uart_a.tx_buffer_level = 24;
  test_msg->uart_a.tx_throughput = 0.8746479153633118;
  test_msg->uart_b.crc_error_count = 0;
  test_msg->uart_b.io_error_count = 0;
  test_msg->uart_b.rx_buffer_level = 0;
  test_msg->uart_b.rx_throughput = 0.0;
  test_msg->uart_b.tx_buffer_level = 40;
  test_msg->uart_b.tx_throughput = 2.995774745941162;
  test_msg->uart_ftdi.crc_error_count = 0;
  test_msg->uart_ftdi.io_error_count = 0;
  test_msg->uart_ftdi.rx_buffer_level = 1;
  test_msg->uart_ftdi.rx_throughput = 0.35211268067359924;
  test_msg->uart_ftdi.tx_buffer_level = 85;
  test_msg->uart_ftdi.tx_throughput = 6.7901411056518555;

  EXPECT_EQ(send_message(0x18, 55286, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
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
  EXPECT_EQ(last_msg_->uart_a.tx_buffer_level, 24)
      << "incorrect value for uart_a.tx_buffer_level, expected 24, is "
      << last_msg_->uart_a.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_a.tx_throughput * 100 - 0.874647915363 * 100),
            0.05)
      << "incorrect value for uart_a.tx_throughput, expected 0.874647915363, "
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
  EXPECT_EQ(last_msg_->uart_b.tx_buffer_level, 40)
      << "incorrect value for uart_b.tx_buffer_level, expected 40, is "
      << last_msg_->uart_b.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_b.tx_throughput * 100 - 2.99577474594 * 100), 0.05)
      << "incorrect value for uart_b.tx_throughput, expected 2.99577474594, is "
      << last_msg_->uart_b.tx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.crc_error_count, 0)
      << "incorrect value for uart_ftdi.crc_error_count, expected 0, is "
      << last_msg_->uart_ftdi.crc_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.io_error_count, 0)
      << "incorrect value for uart_ftdi.io_error_count, expected 0, is "
      << last_msg_->uart_ftdi.io_error_count;
  EXPECT_EQ(last_msg_->uart_ftdi.rx_buffer_level, 1)
      << "incorrect value for uart_ftdi.rx_buffer_level, expected 1, is "
      << last_msg_->uart_ftdi.rx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.rx_throughput * 100 - 0.352112680674 * 100),
            0.05)
      << "incorrect value for uart_ftdi.rx_throughput, expected "
         "0.352112680674, is "
      << last_msg_->uart_ftdi.rx_throughput;
  EXPECT_EQ(last_msg_->uart_ftdi.tx_buffer_level, 85)
      << "incorrect value for uart_ftdi.tx_buffer_level, expected 85, is "
      << last_msg_->uart_ftdi.tx_buffer_level;
  EXPECT_LT((last_msg_->uart_ftdi.tx_throughput * 100 - 6.79014110565 * 100),
            0.05)
      << "incorrect value for uart_ftdi.tx_throughput, expected 6.79014110565, "
         "is "
      << last_msg_->uart_ftdi.tx_throughput;
}
