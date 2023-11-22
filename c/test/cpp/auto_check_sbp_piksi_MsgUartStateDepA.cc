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
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/state.h>
#include <libsbp/sbp.h>
#include <algorithm>

namespace {

template <typename T, typename U>
void assign(T &dest, const U &source) {
  dest = static_cast<T>(source);
}
class Testauto_check_sbp_piksi_MsgUartStateDepA0 : public ::testing::Test {
 public:
  Testauto_check_sbp_piksi_MsgUartStateDepA0() {
    assign(test_msg_.latency.avg, -1);
    assign(test_msg_.latency.current, -1);
    assign(test_msg_.latency.lmax, 0);
    assign(test_msg_.latency.lmin, 0);
    assign(test_msg_.uart_a.crc_error_count, 0);
    assign(test_msg_.uart_a.io_error_count, 0);
    assign(test_msg_.uart_a.rx_buffer_level, 0);
    assign(test_msg_.uart_a.rx_throughput, 0.0);
    assign(test_msg_.uart_a.tx_buffer_level, 0);
    assign(test_msg_.uart_a.tx_throughput, 0.0);
    assign(test_msg_.uart_b.crc_error_count, 0);
    assign(test_msg_.uart_b.io_error_count, 0);
    assign(test_msg_.uart_b.rx_buffer_level, 0);
    assign(test_msg_.uart_b.rx_throughput, 0.0);
    assign(test_msg_.uart_b.tx_buffer_level, 0);
    assign(test_msg_.uart_b.tx_throughput, 0.0);
    assign(test_msg_.uart_ftdi.crc_error_count, 0);
    assign(test_msg_.uart_ftdi.io_error_count, 0);
    assign(test_msg_.uart_ftdi.rx_buffer_level, 0);
    assign(test_msg_.uart_ftdi.rx_throughput, 0.0);
    assign(test_msg_.uart_ftdi.tx_buffer_level, 15);
    assign(test_msg_.uart_ftdi.tx_throughput, 11.600000381469727);
  }

  class SlowReader final : public sbp::IReader {
   public:
    SlowReader(const uint8_t *buf, uint32_t len)
        : sbp::IReader(), buf_{buf}, len_{len} {}

    s32 read(uint8_t *buf, const uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      if (remaining() == 0) {
        return -1;
      }
      skip_next_read = !skip_next_read;
      if (skip_next_read) {
        return 0;
      }
      uint32_t real_n = std::min(n, 1u);
      memcpy(buf, buf_ + offset_, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return len_ - offset_; }

    static s32 read_static(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowReader *>(ctx)->read(buf, len);
    }

   private:
    const uint8_t *buf_;
    uint32_t len_;
    uint32_t offset_{};
    bool skip_next_read{};
  };

  class Reader final : public sbp::IReader {
   public:
    Reader(const uint8_t *buf, uint32_t len)
        : sbp::IReader(), buf_{buf}, len_{len} {}

    s32 read(uint8_t *buf, const uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, remaining());
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf, buf_ + offset_, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return len_ - offset_; }

    static s32 read_static(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Reader *>(ctx)->read(buf, len);
    }

   private:
    const uint8_t *buf_;
    uint32_t len_;
    uint32_t offset_{};
  };

  class SlowWriter final : public sbp::IWriter {
   public:
    explicit SlowWriter(uint32_t max_len = cMaxLen)
        : IWriter(), max_len_{max_len} {}
    static constexpr uint32_t cMaxLen = SBP_MAX_FRAME_LEN;

    s32 write(const uint8_t *buf, uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, 1u);
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf_ + offset_, buf, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return max_len_ - offset_; }

    const uint8_t *data() const noexcept { return buf_; }

    uint32_t len() const noexcept { return offset_; }

    static s32 write_static(const uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowWriter *>(ctx)->write(buf, len);
    }

    static s32 write_c(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowWriter *>(ctx)->write(buf, len);
    }

   private:
    uint8_t buf_[cMaxLen];
    uint32_t max_len_;
    uint32_t offset_{};
  };

  class Writer final : public sbp::IWriter {
   public:
    explicit Writer(uint32_t max_len = cMaxLen)
        : IWriter(), max_len_{max_len} {}
    static constexpr uint32_t cMaxLen = SBP_MAX_FRAME_LEN;

    s32 write(const uint8_t *buf, uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, remaining());
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf_ + offset_, buf, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return max_len_ - offset_; }

    const uint8_t *data() const noexcept { return buf_; }

    uint32_t len() const noexcept { return offset_; }

    static s32 write_static(const uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Writer *>(ctx)->write(buf, len);
    }

    static s32 write_c(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Writer *>(ctx)->write(buf, len);
    }

   private:
    uint8_t buf_[cMaxLen];
    uint32_t max_len_;
    uint32_t offset_{};
  };

  struct CppHandler final
      : public sbp::MessageHandler<sbp_msg_uart_state_depa_t> {
    using sbp::MessageHandler<sbp_msg_uart_state_depa_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_uart_state_depa_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_uart_state_depa_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgUartStateDepa,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_uart_state_depa_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgUartStateDepa);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->uart_state_depa,
             sizeof(msg->uart_state_depa));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_uart_state_depa_t test_msg;
    sbp_msg_t test_msg_wrapped;
    sbp_msg_type_t msg_type;
    uint16_t sender_id;
    uint8_t preamble;
    uint16_t crc;
    const uint8_t *encoded_frame;
    uint32_t frame_len;
    const uint8_t *encoded_payload;
    uint8_t payload_len;

    Reader get_frame_reader() const noexcept {
      return Reader{encoded_frame, frame_len};
    }

    Reader get_frame_reader(uint32_t max) const noexcept {
      assert(max <= frame_len);
      return Reader{encoded_frame, max};
    }

    SlowReader get_slow_frame_reader() const noexcept {
      return SlowReader{encoded_frame, frame_len};
    }

    Writer get_frame_writer() const noexcept { return Writer{frame_len}; }

    Writer get_frame_writer(uint32_t max) const noexcept { return Writer{max}; }

    SlowWriter get_slow_frame_writer() const noexcept {
      return SlowWriter{frame_len};
    }
  };

  TestMsgInfo get_test_msg_info() const noexcept {
    TestMsgInfo info;
    memcpy(&info.test_msg, &test_msg_, sizeof(test_msg_));
    memcpy(&info.test_msg_wrapped.uart_state_depa, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgUartStateDepa);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x5f7;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 58;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_uart_state_depa_t &lesser,
                        const sbp_msg_uart_state_depa_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_uart_state_depa_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_uart_state_depa_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_uart_state_depa_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_uart_state_depa_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_greater, &wrapped_lesser),
        0);

    // lesser vs lesser
    EXPECT_TRUE(lesser == lesser);
    EXPECT_FALSE(lesser != lesser);
    EXPECT_FALSE(lesser < lesser);
    EXPECT_TRUE(lesser <= lesser);
    EXPECT_FALSE(lesser > lesser);
    EXPECT_TRUE(lesser >= lesser);

    // greater vs greater
    EXPECT_TRUE(greater == greater);
    EXPECT_FALSE(greater != greater);
    EXPECT_FALSE(greater < greater);
    EXPECT_TRUE(greater <= greater);
    EXPECT_FALSE(greater > greater);
    EXPECT_TRUE(greater >= greater);

    // lesser vs greater
    EXPECT_FALSE(lesser == greater);
    EXPECT_TRUE(lesser != greater);
    EXPECT_TRUE(lesser < greater);
    EXPECT_TRUE(lesser <= greater);
    EXPECT_FALSE(lesser > greater);
    EXPECT_FALSE(lesser >= greater);

    // greater vs lesser
    EXPECT_FALSE(greater == lesser);
    EXPECT_TRUE(greater != lesser);
    EXPECT_FALSE(greater < lesser);
    EXPECT_FALSE(greater <= lesser);
    EXPECT_TRUE(greater > lesser);
    EXPECT_TRUE(greater >= lesser);
  }

  template <typename T,
            std::enable_if_t<std::is_integral<T>::value, bool> = true>
  void make_lesser_greater(T &lesser, T &greater) {
    if (greater == std::numeric_limits<T>::max()) {
      lesser--;
    } else {
      greater++;
    }
  }

  template <typename T,
            std::enable_if_t<std::is_floating_point<T>::value, bool> = true>
  void make_lesser_greater(T &lesser, T &greater) {
    (void)lesser;
    greater += static_cast<T>(1.0);
  }

  void make_lesser_greater(sbp_string_t &lesser, sbp_string_t &greater) {
    if (greater.data[0] == 'z') {
      lesser.data[0]--;
    } else {
      greater.data[0]++;
    }
  }

  template <size_t N>
  void make_lesser_greater(char (&lesser)[N], char (&greater)[N]) {
    if (lesser[0] == 'z') {
      lesser[0]--;
    } else {
      greater[0]++;
    }
  }

 private:
  sbp_msg_uart_state_depa_t test_msg_{};
  uint8_t encoded_frame_[58 + 8] = {
      85,  24,  0,  195, 4, 58, 0, 0, 0, 0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,  0,   0, 0,  0, 0, 0, 0,   0,   0,   0,   0,   0,   0,   0,
      154, 153, 57, 65,  0, 0,  0, 0, 0, 0,   0,   0,   15,  0,   255, 255, 255,
      255, 0,   0,  0,   0, 0,  0, 0, 0, 255, 255, 255, 255, 247, 5,
  };
  uint8_t encoded_payload_[58] = {
      0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,
      0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   154, 153,
      57,  65, 0, 0, 0, 0, 0, 0, 0, 0,   15,  0,   255, 255, 255,
      255, 0,  0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255,
  };
};

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_uart_state_depa_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgUartStateDepa, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[58];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_uart_state_depa_encode(&buf[0], sizeof(buf), &n_written,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgUartStateDepa, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[58];

  EXPECT_EQ(sbp_msg_uart_state_depa_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}
TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[58];

  for (uint8_t i = 0; i < 58; i++) {
    EXPECT_EQ(
        sbp_msg_uart_state_depa_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0],
                                           info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgUartStateDepa, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};

  EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0],
                                           info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0], i,
                                             nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, ReceiveThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto reader = info.get_frame_reader();
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(sbp_process(&state, &Reader::read_static), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0,
       ReceiveThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto reader = info.get_frame_reader(i);
    sbp_state_set_io_context(&state, &reader);

    CHandler handler(&state);

    int most_recent_return = sbp_process(&state, &Reader::read_static);
    while (most_recent_return == SBP_OK || reader.remaining() > 0) {
      most_recent_return = sbp_process(&state, &Reader::read_static);
    }

    EXPECT_NE(most_recent_return, SBP_OK);
    EXPECT_EQ(reader.remaining(), 0);

    EXPECT_EQ(handler.outputs.size(), 0);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, SlowRead) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto reader = info.get_slow_frame_reader();
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(sbp_process(&state, &SlowReader::read_static), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, BadCRC) {
  auto info = get_test_msg_info();
  uint8_t buf[SBP_MAX_FRAME_LEN];
  memcpy(&buf[0], info.encoded_frame, info.frame_len);

  // Introduce a CRC error which should cause an error return and no callback
  buf[info.frame_len - 1]++;

  sbp_state_t state;
  sbp_state_init(&state);

  Reader reader{buf, info.frame_len};
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    int res = sbp_process(&state, &Reader::read_static);
    EXPECT_EQ(res, reader.remaining() == 0 ? SBP_CRC_ERROR : SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_uart_state_depa_send(&state, info.sender_id, &info.test_msg,
                                         &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.avg, greater.latency.avg);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.current, greater.latency.current);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.lmax, greater.latency.lmax);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.lmin, greater.latency.lmin);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.crc_error_count,
                        greater.uart_a.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.io_error_count,
                        greater.uart_a.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.rx_buffer_level,
                        greater.uart_a.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.rx_throughput,
                        greater.uart_a.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.tx_buffer_level,
                        greater.uart_a.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.tx_throughput,
                        greater.uart_a.tx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.crc_error_count,
                        greater.uart_b.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.io_error_count,
                        greater.uart_b.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.rx_buffer_level,
                        greater.uart_b.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.rx_throughput,
                        greater.uart_b.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.tx_buffer_level,
                        greater.uart_b.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.tx_throughput,
                        greater.uart_b.tx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.crc_error_count,
                        greater.uart_ftdi.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.io_error_count,
                        greater.uart_ftdi.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.rx_buffer_level,
                        greater.uart_ftdi.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.rx_throughput,
                        greater.uart_ftdi.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.tx_buffer_level,
                        greater.uart_ftdi.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.tx_throughput,
                        greater.uart_ftdi.tx_throughput);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::id,
  // SbpMsgUartStateDepa);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::name,
               "MSG_UART_STATE_DEPA");
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_uart_state_depa_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::get(const_sbp_msg_t);
  sbp_msg_uart_state_depa_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.uart_state_depa, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(info.test_msg,
                                                            &msg2);
  EXPECT_EQ(msg2.uart_state_depa, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[58];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0,
       ReceiveThroughMessageHandler) {
  auto info = get_test_msg_info();
  auto reader = info.get_frame_reader();

  sbp::State state{};
  state.set_reader(&reader);

  CppHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(state.process(), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgUartStateDepa,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgUartStateDepa,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_piksi_MsgUartStateDepA1 : public ::testing::Test {
 public:
  Testauto_check_sbp_piksi_MsgUartStateDepA1() {
    assign(test_msg_.latency.avg, -1);
    assign(test_msg_.latency.current, -1);
    assign(test_msg_.latency.lmax, 0);
    assign(test_msg_.latency.lmin, 0);
    assign(test_msg_.uart_a.crc_error_count, 0);
    assign(test_msg_.uart_a.io_error_count, 0);
    assign(test_msg_.uart_a.rx_buffer_level, 0);
    assign(test_msg_.uart_a.rx_throughput, 0.0);
    assign(test_msg_.uart_a.tx_buffer_level, 0);
    assign(test_msg_.uart_a.tx_throughput, 0.0);
    assign(test_msg_.uart_b.crc_error_count, 0);
    assign(test_msg_.uart_b.io_error_count, 0);
    assign(test_msg_.uart_b.rx_buffer_level, 0);
    assign(test_msg_.uart_b.rx_throughput, 0.0);
    assign(test_msg_.uart_b.tx_buffer_level, 0);
    assign(test_msg_.uart_b.tx_throughput, 0.0);
    assign(test_msg_.uart_ftdi.crc_error_count, 0);
    assign(test_msg_.uart_ftdi.io_error_count, 0);
    assign(test_msg_.uart_ftdi.rx_buffer_level, 0);
    assign(test_msg_.uart_ftdi.rx_throughput, 0.0);
    assign(test_msg_.uart_ftdi.tx_buffer_level, 0);
    assign(test_msg_.uart_ftdi.tx_throughput, 0.06599999964237213);
  }

  class SlowReader final : public sbp::IReader {
   public:
    SlowReader(const uint8_t *buf, uint32_t len)
        : sbp::IReader(), buf_{buf}, len_{len} {}

    s32 read(uint8_t *buf, const uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      if (remaining() == 0) {
        return -1;
      }
      skip_next_read = !skip_next_read;
      if (skip_next_read) {
        return 0;
      }
      uint32_t real_n = std::min(n, 1u);
      memcpy(buf, buf_ + offset_, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return len_ - offset_; }

    static s32 read_static(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowReader *>(ctx)->read(buf, len);
    }

   private:
    const uint8_t *buf_;
    uint32_t len_;
    uint32_t offset_{};
    bool skip_next_read{};
  };

  class Reader final : public sbp::IReader {
   public:
    Reader(const uint8_t *buf, uint32_t len)
        : sbp::IReader(), buf_{buf}, len_{len} {}

    s32 read(uint8_t *buf, const uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, remaining());
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf, buf_ + offset_, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return len_ - offset_; }

    static s32 read_static(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Reader *>(ctx)->read(buf, len);
    }

   private:
    const uint8_t *buf_;
    uint32_t len_;
    uint32_t offset_{};
  };

  class SlowWriter final : public sbp::IWriter {
   public:
    explicit SlowWriter(uint32_t max_len = cMaxLen)
        : IWriter(), max_len_{max_len} {}
    static constexpr uint32_t cMaxLen = SBP_MAX_FRAME_LEN;

    s32 write(const uint8_t *buf, uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, 1u);
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf_ + offset_, buf, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return max_len_ - offset_; }

    const uint8_t *data() const noexcept { return buf_; }

    uint32_t len() const noexcept { return offset_; }

    static s32 write_static(const uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowWriter *>(ctx)->write(buf, len);
    }

    static s32 write_c(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowWriter *>(ctx)->write(buf, len);
    }

   private:
    uint8_t buf_[cMaxLen];
    uint32_t max_len_;
    uint32_t offset_{};
  };

  class Writer final : public sbp::IWriter {
   public:
    explicit Writer(uint32_t max_len = cMaxLen)
        : IWriter(), max_len_{max_len} {}
    static constexpr uint32_t cMaxLen = SBP_MAX_FRAME_LEN;

    s32 write(const uint8_t *buf, uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, remaining());
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf_ + offset_, buf, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return max_len_ - offset_; }

    const uint8_t *data() const noexcept { return buf_; }

    uint32_t len() const noexcept { return offset_; }

    static s32 write_static(const uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Writer *>(ctx)->write(buf, len);
    }

    static s32 write_c(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Writer *>(ctx)->write(buf, len);
    }

   private:
    uint8_t buf_[cMaxLen];
    uint32_t max_len_;
    uint32_t offset_{};
  };

  struct CppHandler final
      : public sbp::MessageHandler<sbp_msg_uart_state_depa_t> {
    using sbp::MessageHandler<sbp_msg_uart_state_depa_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_uart_state_depa_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_uart_state_depa_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgUartStateDepa,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_uart_state_depa_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgUartStateDepa);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->uart_state_depa,
             sizeof(msg->uart_state_depa));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_uart_state_depa_t test_msg;
    sbp_msg_t test_msg_wrapped;
    sbp_msg_type_t msg_type;
    uint16_t sender_id;
    uint8_t preamble;
    uint16_t crc;
    const uint8_t *encoded_frame;
    uint32_t frame_len;
    const uint8_t *encoded_payload;
    uint8_t payload_len;

    Reader get_frame_reader() const noexcept {
      return Reader{encoded_frame, frame_len};
    }

    Reader get_frame_reader(uint32_t max) const noexcept {
      assert(max <= frame_len);
      return Reader{encoded_frame, max};
    }

    SlowReader get_slow_frame_reader() const noexcept {
      return SlowReader{encoded_frame, frame_len};
    }

    Writer get_frame_writer() const noexcept { return Writer{frame_len}; }

    Writer get_frame_writer(uint32_t max) const noexcept { return Writer{max}; }

    SlowWriter get_slow_frame_writer() const noexcept {
      return SlowWriter{frame_len};
    }
  };

  TestMsgInfo get_test_msg_info() const noexcept {
    TestMsgInfo info;
    memcpy(&info.test_msg, &test_msg_, sizeof(test_msg_));
    memcpy(&info.test_msg_wrapped.uart_state_depa, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgUartStateDepa);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x6e41;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 58;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_uart_state_depa_t &lesser,
                        const sbp_msg_uart_state_depa_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_uart_state_depa_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_uart_state_depa_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_uart_state_depa_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_uart_state_depa_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_greater, &wrapped_lesser),
        0);

    // lesser vs lesser
    EXPECT_TRUE(lesser == lesser);
    EXPECT_FALSE(lesser != lesser);
    EXPECT_FALSE(lesser < lesser);
    EXPECT_TRUE(lesser <= lesser);
    EXPECT_FALSE(lesser > lesser);
    EXPECT_TRUE(lesser >= lesser);

    // greater vs greater
    EXPECT_TRUE(greater == greater);
    EXPECT_FALSE(greater != greater);
    EXPECT_FALSE(greater < greater);
    EXPECT_TRUE(greater <= greater);
    EXPECT_FALSE(greater > greater);
    EXPECT_TRUE(greater >= greater);

    // lesser vs greater
    EXPECT_FALSE(lesser == greater);
    EXPECT_TRUE(lesser != greater);
    EXPECT_TRUE(lesser < greater);
    EXPECT_TRUE(lesser <= greater);
    EXPECT_FALSE(lesser > greater);
    EXPECT_FALSE(lesser >= greater);

    // greater vs lesser
    EXPECT_FALSE(greater == lesser);
    EXPECT_TRUE(greater != lesser);
    EXPECT_FALSE(greater < lesser);
    EXPECT_FALSE(greater <= lesser);
    EXPECT_TRUE(greater > lesser);
    EXPECT_TRUE(greater >= lesser);
  }

  template <typename T,
            std::enable_if_t<std::is_integral<T>::value, bool> = true>
  void make_lesser_greater(T &lesser, T &greater) {
    if (greater == std::numeric_limits<T>::max()) {
      lesser--;
    } else {
      greater++;
    }
  }

  template <typename T,
            std::enable_if_t<std::is_floating_point<T>::value, bool> = true>
  void make_lesser_greater(T &lesser, T &greater) {
    (void)lesser;
    greater += static_cast<T>(1.0);
  }

  void make_lesser_greater(sbp_string_t &lesser, sbp_string_t &greater) {
    if (greater.data[0] == 'z') {
      lesser.data[0]--;
    } else {
      greater.data[0]++;
    }
  }

  template <size_t N>
  void make_lesser_greater(char (&lesser)[N], char (&greater)[N]) {
    if (lesser[0] == 'z') {
      lesser[0]--;
    } else {
      greater[0]++;
    }
  }

 private:
  sbp_msg_uart_state_depa_t test_msg_{};
  uint8_t encoded_frame_[58 + 8] = {
      85,  24, 0,   195, 4, 58, 0, 0, 0, 0,   0,   0,   0,   0,  0,   0,   0,
      0,   0,  0,   0,   0, 0,  0, 0, 0, 0,   0,   0,   0,   0,  0,   0,   0,
      2,   43, 135, 61,  0, 0,  0, 0, 0, 0,   0,   0,   0,   0,  255, 255, 255,
      255, 0,  0,   0,   0, 0,  0, 0, 0, 255, 255, 255, 255, 65, 110,
  };
  uint8_t encoded_payload_[58] = {
      0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,
      0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   2,   43,
      135, 61, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   255, 255, 255,
      255, 0,  0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255,
  };
};

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_uart_state_depa_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgUartStateDepa, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[58];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_uart_state_depa_encode(&buf[0], sizeof(buf), &n_written,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgUartStateDepa, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[58];

  EXPECT_EQ(sbp_msg_uart_state_depa_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}
TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[58];

  for (uint8_t i = 0; i < 58; i++) {
    EXPECT_EQ(
        sbp_msg_uart_state_depa_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0],
                                           info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgUartStateDepa, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};

  EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0],
                                           info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0], i,
                                             nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, ReceiveThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto reader = info.get_frame_reader();
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(sbp_process(&state, &Reader::read_static), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1,
       ReceiveThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto reader = info.get_frame_reader(i);
    sbp_state_set_io_context(&state, &reader);

    CHandler handler(&state);

    int most_recent_return = sbp_process(&state, &Reader::read_static);
    while (most_recent_return == SBP_OK || reader.remaining() > 0) {
      most_recent_return = sbp_process(&state, &Reader::read_static);
    }

    EXPECT_NE(most_recent_return, SBP_OK);
    EXPECT_EQ(reader.remaining(), 0);

    EXPECT_EQ(handler.outputs.size(), 0);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, SlowRead) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto reader = info.get_slow_frame_reader();
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(sbp_process(&state, &SlowReader::read_static), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, BadCRC) {
  auto info = get_test_msg_info();
  uint8_t buf[SBP_MAX_FRAME_LEN];
  memcpy(&buf[0], info.encoded_frame, info.frame_len);

  // Introduce a CRC error which should cause an error return and no callback
  buf[info.frame_len - 1]++;

  sbp_state_t state;
  sbp_state_init(&state);

  Reader reader{buf, info.frame_len};
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    int res = sbp_process(&state, &Reader::read_static);
    EXPECT_EQ(res, reader.remaining() == 0 ? SBP_CRC_ERROR : SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_uart_state_depa_send(&state, info.sender_id, &info.test_msg,
                                         &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.avg, greater.latency.avg);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.current, greater.latency.current);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.lmax, greater.latency.lmax);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.lmin, greater.latency.lmin);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.crc_error_count,
                        greater.uart_a.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.io_error_count,
                        greater.uart_a.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.rx_buffer_level,
                        greater.uart_a.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.rx_throughput,
                        greater.uart_a.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.tx_buffer_level,
                        greater.uart_a.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.tx_throughput,
                        greater.uart_a.tx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.crc_error_count,
                        greater.uart_b.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.io_error_count,
                        greater.uart_b.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.rx_buffer_level,
                        greater.uart_b.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.rx_throughput,
                        greater.uart_b.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.tx_buffer_level,
                        greater.uart_b.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.tx_throughput,
                        greater.uart_b.tx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.crc_error_count,
                        greater.uart_ftdi.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.io_error_count,
                        greater.uart_ftdi.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.rx_buffer_level,
                        greater.uart_ftdi.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.rx_throughput,
                        greater.uart_ftdi.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.tx_buffer_level,
                        greater.uart_ftdi.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.tx_throughput,
                        greater.uart_ftdi.tx_throughput);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::id,
  // SbpMsgUartStateDepa);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::name,
               "MSG_UART_STATE_DEPA");
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_uart_state_depa_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::get(const_sbp_msg_t);
  sbp_msg_uart_state_depa_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.uart_state_depa, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(info.test_msg,
                                                            &msg2);
  EXPECT_EQ(msg2.uart_state_depa, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[58];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1,
       ReceiveThroughMessageHandler) {
  auto info = get_test_msg_info();
  auto reader = info.get_frame_reader();

  sbp::State state{};
  state.set_reader(&reader);

  CppHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(state.process(), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgUartStateDepa,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA1,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgUartStateDepa,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_piksi_MsgUartStateDepA2 : public ::testing::Test {
 public:
  Testauto_check_sbp_piksi_MsgUartStateDepA2() {
    assign(test_msg_.latency.avg, -1);
    assign(test_msg_.latency.current, -1);
    assign(test_msg_.latency.lmax, 0);
    assign(test_msg_.latency.lmin, 0);
    assign(test_msg_.uart_a.crc_error_count, 0);
    assign(test_msg_.uart_a.io_error_count, 0);
    assign(test_msg_.uart_a.rx_buffer_level, 0);
    assign(test_msg_.uart_a.rx_throughput, 0.0);
    assign(test_msg_.uart_a.tx_buffer_level, 0);
    assign(test_msg_.uart_a.tx_throughput, 0.0);
    assign(test_msg_.uart_b.crc_error_count, 0);
    assign(test_msg_.uart_b.io_error_count, 0);
    assign(test_msg_.uart_b.rx_buffer_level, 0);
    assign(test_msg_.uart_b.rx_throughput, 0.0);
    assign(test_msg_.uart_b.tx_buffer_level, 0);
    assign(test_msg_.uart_b.tx_throughput, 0.0);
    assign(test_msg_.uart_ftdi.crc_error_count, 0);
    assign(test_msg_.uart_ftdi.io_error_count, 0);
    assign(test_msg_.uart_ftdi.rx_buffer_level, 0);
    assign(test_msg_.uart_ftdi.rx_throughput, 0.0);
    assign(test_msg_.uart_ftdi.tx_buffer_level, 10);
    assign(test_msg_.uart_ftdi.tx_throughput, 0.13899999856948853);
  }

  class SlowReader final : public sbp::IReader {
   public:
    SlowReader(const uint8_t *buf, uint32_t len)
        : sbp::IReader(), buf_{buf}, len_{len} {}

    s32 read(uint8_t *buf, const uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      if (remaining() == 0) {
        return -1;
      }
      skip_next_read = !skip_next_read;
      if (skip_next_read) {
        return 0;
      }
      uint32_t real_n = std::min(n, 1u);
      memcpy(buf, buf_ + offset_, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return len_ - offset_; }

    static s32 read_static(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowReader *>(ctx)->read(buf, len);
    }

   private:
    const uint8_t *buf_;
    uint32_t len_;
    uint32_t offset_{};
    bool skip_next_read{};
  };

  class Reader final : public sbp::IReader {
   public:
    Reader(const uint8_t *buf, uint32_t len)
        : sbp::IReader(), buf_{buf}, len_{len} {}

    s32 read(uint8_t *buf, const uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, remaining());
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf, buf_ + offset_, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return len_ - offset_; }

    static s32 read_static(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Reader *>(ctx)->read(buf, len);
    }

   private:
    const uint8_t *buf_;
    uint32_t len_;
    uint32_t offset_{};
  };

  class SlowWriter final : public sbp::IWriter {
   public:
    explicit SlowWriter(uint32_t max_len = cMaxLen)
        : IWriter(), max_len_{max_len} {}
    static constexpr uint32_t cMaxLen = SBP_MAX_FRAME_LEN;

    s32 write(const uint8_t *buf, uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, 1u);
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf_ + offset_, buf, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return max_len_ - offset_; }

    const uint8_t *data() const noexcept { return buf_; }

    uint32_t len() const noexcept { return offset_; }

    static s32 write_static(const uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowWriter *>(ctx)->write(buf, len);
    }

    static s32 write_c(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowWriter *>(ctx)->write(buf, len);
    }

   private:
    uint8_t buf_[cMaxLen];
    uint32_t max_len_;
    uint32_t offset_{};
  };

  class Writer final : public sbp::IWriter {
   public:
    explicit Writer(uint32_t max_len = cMaxLen)
        : IWriter(), max_len_{max_len} {}
    static constexpr uint32_t cMaxLen = SBP_MAX_FRAME_LEN;

    s32 write(const uint8_t *buf, uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, remaining());
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf_ + offset_, buf, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return max_len_ - offset_; }

    const uint8_t *data() const noexcept { return buf_; }

    uint32_t len() const noexcept { return offset_; }

    static s32 write_static(const uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Writer *>(ctx)->write(buf, len);
    }

    static s32 write_c(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Writer *>(ctx)->write(buf, len);
    }

   private:
    uint8_t buf_[cMaxLen];
    uint32_t max_len_;
    uint32_t offset_{};
  };

  struct CppHandler final
      : public sbp::MessageHandler<sbp_msg_uart_state_depa_t> {
    using sbp::MessageHandler<sbp_msg_uart_state_depa_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_uart_state_depa_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_uart_state_depa_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgUartStateDepa,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_uart_state_depa_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgUartStateDepa);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->uart_state_depa,
             sizeof(msg->uart_state_depa));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_uart_state_depa_t test_msg;
    sbp_msg_t test_msg_wrapped;
    sbp_msg_type_t msg_type;
    uint16_t sender_id;
    uint8_t preamble;
    uint16_t crc;
    const uint8_t *encoded_frame;
    uint32_t frame_len;
    const uint8_t *encoded_payload;
    uint8_t payload_len;

    Reader get_frame_reader() const noexcept {
      return Reader{encoded_frame, frame_len};
    }

    Reader get_frame_reader(uint32_t max) const noexcept {
      assert(max <= frame_len);
      return Reader{encoded_frame, max};
    }

    SlowReader get_slow_frame_reader() const noexcept {
      return SlowReader{encoded_frame, frame_len};
    }

    Writer get_frame_writer() const noexcept { return Writer{frame_len}; }

    Writer get_frame_writer(uint32_t max) const noexcept { return Writer{max}; }

    SlowWriter get_slow_frame_writer() const noexcept {
      return SlowWriter{frame_len};
    }
  };

  TestMsgInfo get_test_msg_info() const noexcept {
    TestMsgInfo info;
    memcpy(&info.test_msg, &test_msg_, sizeof(test_msg_));
    memcpy(&info.test_msg_wrapped.uart_state_depa, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgUartStateDepa);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x24c6;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 58;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_uart_state_depa_t &lesser,
                        const sbp_msg_uart_state_depa_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_uart_state_depa_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_uart_state_depa_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_uart_state_depa_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_uart_state_depa_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_greater, &wrapped_lesser),
        0);

    // lesser vs lesser
    EXPECT_TRUE(lesser == lesser);
    EXPECT_FALSE(lesser != lesser);
    EXPECT_FALSE(lesser < lesser);
    EXPECT_TRUE(lesser <= lesser);
    EXPECT_FALSE(lesser > lesser);
    EXPECT_TRUE(lesser >= lesser);

    // greater vs greater
    EXPECT_TRUE(greater == greater);
    EXPECT_FALSE(greater != greater);
    EXPECT_FALSE(greater < greater);
    EXPECT_TRUE(greater <= greater);
    EXPECT_FALSE(greater > greater);
    EXPECT_TRUE(greater >= greater);

    // lesser vs greater
    EXPECT_FALSE(lesser == greater);
    EXPECT_TRUE(lesser != greater);
    EXPECT_TRUE(lesser < greater);
    EXPECT_TRUE(lesser <= greater);
    EXPECT_FALSE(lesser > greater);
    EXPECT_FALSE(lesser >= greater);

    // greater vs lesser
    EXPECT_FALSE(greater == lesser);
    EXPECT_TRUE(greater != lesser);
    EXPECT_FALSE(greater < lesser);
    EXPECT_FALSE(greater <= lesser);
    EXPECT_TRUE(greater > lesser);
    EXPECT_TRUE(greater >= lesser);
  }

  template <typename T,
            std::enable_if_t<std::is_integral<T>::value, bool> = true>
  void make_lesser_greater(T &lesser, T &greater) {
    if (greater == std::numeric_limits<T>::max()) {
      lesser--;
    } else {
      greater++;
    }
  }

  template <typename T,
            std::enable_if_t<std::is_floating_point<T>::value, bool> = true>
  void make_lesser_greater(T &lesser, T &greater) {
    (void)lesser;
    greater += static_cast<T>(1.0);
  }

  void make_lesser_greater(sbp_string_t &lesser, sbp_string_t &greater) {
    if (greater.data[0] == 'z') {
      lesser.data[0]--;
    } else {
      greater.data[0]++;
    }
  }

  template <size_t N>
  void make_lesser_greater(char (&lesser)[N], char (&greater)[N]) {
    if (lesser[0] == 'z') {
      lesser[0]--;
    } else {
      greater[0]++;
    }
  }

 private:
  sbp_msg_uart_state_depa_t test_msg_{};
  uint8_t encoded_frame_[58 + 8] = {
      85,  24, 0,  195, 4, 58, 0, 0, 0, 0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,  0,  0,   0, 0,  0, 0, 0, 0,   0,   0,   0,   0,   0,   0,   0,
      4,   86, 14, 62,  0, 0,  0, 0, 0, 0,   0,   0,   10,  0,   255, 255, 255,
      255, 0,  0,  0,   0, 0,  0, 0, 0, 255, 255, 255, 255, 198, 36,
  };
  uint8_t encoded_payload_[58] = {
      0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,
      0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   4,   86,
      14,  62, 0, 0, 0, 0, 0, 0, 0, 0,   10,  0,   255, 255, 255,
      255, 0,  0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255,
  };
};

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_uart_state_depa_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgUartStateDepa, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[58];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_uart_state_depa_encode(&buf[0], sizeof(buf), &n_written,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgUartStateDepa, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[58];

  EXPECT_EQ(sbp_msg_uart_state_depa_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}
TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[58];

  for (uint8_t i = 0; i < 58; i++) {
    EXPECT_EQ(
        sbp_msg_uart_state_depa_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0],
                                           info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgUartStateDepa, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};

  EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0],
                                           info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0], i,
                                             nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, ReceiveThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto reader = info.get_frame_reader();
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(sbp_process(&state, &Reader::read_static), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2,
       ReceiveThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto reader = info.get_frame_reader(i);
    sbp_state_set_io_context(&state, &reader);

    CHandler handler(&state);

    int most_recent_return = sbp_process(&state, &Reader::read_static);
    while (most_recent_return == SBP_OK || reader.remaining() > 0) {
      most_recent_return = sbp_process(&state, &Reader::read_static);
    }

    EXPECT_NE(most_recent_return, SBP_OK);
    EXPECT_EQ(reader.remaining(), 0);

    EXPECT_EQ(handler.outputs.size(), 0);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, SlowRead) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto reader = info.get_slow_frame_reader();
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(sbp_process(&state, &SlowReader::read_static), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, BadCRC) {
  auto info = get_test_msg_info();
  uint8_t buf[SBP_MAX_FRAME_LEN];
  memcpy(&buf[0], info.encoded_frame, info.frame_len);

  // Introduce a CRC error which should cause an error return and no callback
  buf[info.frame_len - 1]++;

  sbp_state_t state;
  sbp_state_init(&state);

  Reader reader{buf, info.frame_len};
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    int res = sbp_process(&state, &Reader::read_static);
    EXPECT_EQ(res, reader.remaining() == 0 ? SBP_CRC_ERROR : SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_uart_state_depa_send(&state, info.sender_id, &info.test_msg,
                                         &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.avg, greater.latency.avg);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.current, greater.latency.current);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.lmax, greater.latency.lmax);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.lmin, greater.latency.lmin);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.crc_error_count,
                        greater.uart_a.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.io_error_count,
                        greater.uart_a.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.rx_buffer_level,
                        greater.uart_a.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.rx_throughput,
                        greater.uart_a.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.tx_buffer_level,
                        greater.uart_a.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.tx_throughput,
                        greater.uart_a.tx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.crc_error_count,
                        greater.uart_b.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.io_error_count,
                        greater.uart_b.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.rx_buffer_level,
                        greater.uart_b.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.rx_throughput,
                        greater.uart_b.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.tx_buffer_level,
                        greater.uart_b.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.tx_throughput,
                        greater.uart_b.tx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.crc_error_count,
                        greater.uart_ftdi.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.io_error_count,
                        greater.uart_ftdi.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.rx_buffer_level,
                        greater.uart_ftdi.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.rx_throughput,
                        greater.uart_ftdi.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.tx_buffer_level,
                        greater.uart_ftdi.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.tx_throughput,
                        greater.uart_ftdi.tx_throughput);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::id,
  // SbpMsgUartStateDepa);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::name,
               "MSG_UART_STATE_DEPA");
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_uart_state_depa_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::get(const_sbp_msg_t);
  sbp_msg_uart_state_depa_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.uart_state_depa, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(info.test_msg,
                                                            &msg2);
  EXPECT_EQ(msg2.uart_state_depa, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[58];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2,
       ReceiveThroughMessageHandler) {
  auto info = get_test_msg_info();
  auto reader = info.get_frame_reader();

  sbp::State state{};
  state.set_reader(&reader);

  CppHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(state.process(), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgUartStateDepa,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA2,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgUartStateDepa,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_piksi_MsgUartStateDepA3 : public ::testing::Test {
 public:
  Testauto_check_sbp_piksi_MsgUartStateDepA3() {
    assign(test_msg_.latency.avg, -1);
    assign(test_msg_.latency.current, -1);
    assign(test_msg_.latency.lmax, 0);
    assign(test_msg_.latency.lmin, 0);
    assign(test_msg_.uart_a.crc_error_count, 0);
    assign(test_msg_.uart_a.io_error_count, 0);
    assign(test_msg_.uart_a.rx_buffer_level, 0);
    assign(test_msg_.uart_a.rx_throughput, 0.0);
    assign(test_msg_.uart_a.tx_buffer_level, 0);
    assign(test_msg_.uart_a.tx_throughput, 0.0);
    assign(test_msg_.uart_b.crc_error_count, 0);
    assign(test_msg_.uart_b.io_error_count, 0);
    assign(test_msg_.uart_b.rx_buffer_level, 0);
    assign(test_msg_.uart_b.rx_throughput, 0.0);
    assign(test_msg_.uart_b.tx_buffer_level, 0);
    assign(test_msg_.uart_b.tx_throughput, 0.0);
    assign(test_msg_.uart_ftdi.crc_error_count, 0);
    assign(test_msg_.uart_ftdi.io_error_count, 0);
    assign(test_msg_.uart_ftdi.rx_buffer_level, 0);
    assign(test_msg_.uart_ftdi.rx_throughput, 0.0);
    assign(test_msg_.uart_ftdi.tx_buffer_level, 0);
    assign(test_msg_.uart_ftdi.tx_throughput, 0.06599999964237213);
  }

  class SlowReader final : public sbp::IReader {
   public:
    SlowReader(const uint8_t *buf, uint32_t len)
        : sbp::IReader(), buf_{buf}, len_{len} {}

    s32 read(uint8_t *buf, const uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      if (remaining() == 0) {
        return -1;
      }
      skip_next_read = !skip_next_read;
      if (skip_next_read) {
        return 0;
      }
      uint32_t real_n = std::min(n, 1u);
      memcpy(buf, buf_ + offset_, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return len_ - offset_; }

    static s32 read_static(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowReader *>(ctx)->read(buf, len);
    }

   private:
    const uint8_t *buf_;
    uint32_t len_;
    uint32_t offset_{};
    bool skip_next_read{};
  };

  class Reader final : public sbp::IReader {
   public:
    Reader(const uint8_t *buf, uint32_t len)
        : sbp::IReader(), buf_{buf}, len_{len} {}

    s32 read(uint8_t *buf, const uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, remaining());
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf, buf_ + offset_, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return len_ - offset_; }

    static s32 read_static(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Reader *>(ctx)->read(buf, len);
    }

   private:
    const uint8_t *buf_;
    uint32_t len_;
    uint32_t offset_{};
  };

  class SlowWriter final : public sbp::IWriter {
   public:
    explicit SlowWriter(uint32_t max_len = cMaxLen)
        : IWriter(), max_len_{max_len} {}
    static constexpr uint32_t cMaxLen = SBP_MAX_FRAME_LEN;

    s32 write(const uint8_t *buf, uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, 1u);
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf_ + offset_, buf, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return max_len_ - offset_; }

    const uint8_t *data() const noexcept { return buf_; }

    uint32_t len() const noexcept { return offset_; }

    static s32 write_static(const uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowWriter *>(ctx)->write(buf, len);
    }

    static s32 write_c(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowWriter *>(ctx)->write(buf, len);
    }

   private:
    uint8_t buf_[cMaxLen];
    uint32_t max_len_;
    uint32_t offset_{};
  };

  class Writer final : public sbp::IWriter {
   public:
    explicit Writer(uint32_t max_len = cMaxLen)
        : IWriter(), max_len_{max_len} {}
    static constexpr uint32_t cMaxLen = SBP_MAX_FRAME_LEN;

    s32 write(const uint8_t *buf, uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, remaining());
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf_ + offset_, buf, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return max_len_ - offset_; }

    const uint8_t *data() const noexcept { return buf_; }

    uint32_t len() const noexcept { return offset_; }

    static s32 write_static(const uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Writer *>(ctx)->write(buf, len);
    }

    static s32 write_c(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Writer *>(ctx)->write(buf, len);
    }

   private:
    uint8_t buf_[cMaxLen];
    uint32_t max_len_;
    uint32_t offset_{};
  };

  struct CppHandler final
      : public sbp::MessageHandler<sbp_msg_uart_state_depa_t> {
    using sbp::MessageHandler<sbp_msg_uart_state_depa_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_uart_state_depa_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_uart_state_depa_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgUartStateDepa,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_uart_state_depa_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgUartStateDepa);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->uart_state_depa,
             sizeof(msg->uart_state_depa));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_uart_state_depa_t test_msg;
    sbp_msg_t test_msg_wrapped;
    sbp_msg_type_t msg_type;
    uint16_t sender_id;
    uint8_t preamble;
    uint16_t crc;
    const uint8_t *encoded_frame;
    uint32_t frame_len;
    const uint8_t *encoded_payload;
    uint8_t payload_len;

    Reader get_frame_reader() const noexcept {
      return Reader{encoded_frame, frame_len};
    }

    Reader get_frame_reader(uint32_t max) const noexcept {
      assert(max <= frame_len);
      return Reader{encoded_frame, max};
    }

    SlowReader get_slow_frame_reader() const noexcept {
      return SlowReader{encoded_frame, frame_len};
    }

    Writer get_frame_writer() const noexcept { return Writer{frame_len}; }

    Writer get_frame_writer(uint32_t max) const noexcept { return Writer{max}; }

    SlowWriter get_slow_frame_writer() const noexcept {
      return SlowWriter{frame_len};
    }
  };

  TestMsgInfo get_test_msg_info() const noexcept {
    TestMsgInfo info;
    memcpy(&info.test_msg, &test_msg_, sizeof(test_msg_));
    memcpy(&info.test_msg_wrapped.uart_state_depa, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgUartStateDepa);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x6e41;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 58;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_uart_state_depa_t &lesser,
                        const sbp_msg_uart_state_depa_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_uart_state_depa_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_uart_state_depa_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_uart_state_depa_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_uart_state_depa_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_greater, &wrapped_lesser),
        0);

    // lesser vs lesser
    EXPECT_TRUE(lesser == lesser);
    EXPECT_FALSE(lesser != lesser);
    EXPECT_FALSE(lesser < lesser);
    EXPECT_TRUE(lesser <= lesser);
    EXPECT_FALSE(lesser > lesser);
    EXPECT_TRUE(lesser >= lesser);

    // greater vs greater
    EXPECT_TRUE(greater == greater);
    EXPECT_FALSE(greater != greater);
    EXPECT_FALSE(greater < greater);
    EXPECT_TRUE(greater <= greater);
    EXPECT_FALSE(greater > greater);
    EXPECT_TRUE(greater >= greater);

    // lesser vs greater
    EXPECT_FALSE(lesser == greater);
    EXPECT_TRUE(lesser != greater);
    EXPECT_TRUE(lesser < greater);
    EXPECT_TRUE(lesser <= greater);
    EXPECT_FALSE(lesser > greater);
    EXPECT_FALSE(lesser >= greater);

    // greater vs lesser
    EXPECT_FALSE(greater == lesser);
    EXPECT_TRUE(greater != lesser);
    EXPECT_FALSE(greater < lesser);
    EXPECT_FALSE(greater <= lesser);
    EXPECT_TRUE(greater > lesser);
    EXPECT_TRUE(greater >= lesser);
  }

  template <typename T,
            std::enable_if_t<std::is_integral<T>::value, bool> = true>
  void make_lesser_greater(T &lesser, T &greater) {
    if (greater == std::numeric_limits<T>::max()) {
      lesser--;
    } else {
      greater++;
    }
  }

  template <typename T,
            std::enable_if_t<std::is_floating_point<T>::value, bool> = true>
  void make_lesser_greater(T &lesser, T &greater) {
    (void)lesser;
    greater += static_cast<T>(1.0);
  }

  void make_lesser_greater(sbp_string_t &lesser, sbp_string_t &greater) {
    if (greater.data[0] == 'z') {
      lesser.data[0]--;
    } else {
      greater.data[0]++;
    }
  }

  template <size_t N>
  void make_lesser_greater(char (&lesser)[N], char (&greater)[N]) {
    if (lesser[0] == 'z') {
      lesser[0]--;
    } else {
      greater[0]++;
    }
  }

 private:
  sbp_msg_uart_state_depa_t test_msg_{};
  uint8_t encoded_frame_[58 + 8] = {
      85,  24, 0,   195, 4, 58, 0, 0, 0, 0,   0,   0,   0,   0,  0,   0,   0,
      0,   0,  0,   0,   0, 0,  0, 0, 0, 0,   0,   0,   0,   0,  0,   0,   0,
      2,   43, 135, 61,  0, 0,  0, 0, 0, 0,   0,   0,   0,   0,  255, 255, 255,
      255, 0,  0,   0,   0, 0,  0, 0, 0, 255, 255, 255, 255, 65, 110,
  };
  uint8_t encoded_payload_[58] = {
      0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,
      0,   0,  0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   2,   43,
      135, 61, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   255, 255, 255,
      255, 0,  0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255,
  };
};

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_uart_state_depa_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgUartStateDepa, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[58];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_uart_state_depa_encode(&buf[0], sizeof(buf), &n_written,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgUartStateDepa, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[58];

  EXPECT_EQ(sbp_msg_uart_state_depa_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}
TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[58];

  for (uint8_t i = 0; i < 58; i++) {
    EXPECT_EQ(
        sbp_msg_uart_state_depa_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0],
                                           info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgUartStateDepa, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};

  EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0],
                                           info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0], i,
                                             nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, ReceiveThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto reader = info.get_frame_reader();
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(sbp_process(&state, &Reader::read_static), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3,
       ReceiveThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto reader = info.get_frame_reader(i);
    sbp_state_set_io_context(&state, &reader);

    CHandler handler(&state);

    int most_recent_return = sbp_process(&state, &Reader::read_static);
    while (most_recent_return == SBP_OK || reader.remaining() > 0) {
      most_recent_return = sbp_process(&state, &Reader::read_static);
    }

    EXPECT_NE(most_recent_return, SBP_OK);
    EXPECT_EQ(reader.remaining(), 0);

    EXPECT_EQ(handler.outputs.size(), 0);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, SlowRead) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto reader = info.get_slow_frame_reader();
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(sbp_process(&state, &SlowReader::read_static), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, BadCRC) {
  auto info = get_test_msg_info();
  uint8_t buf[SBP_MAX_FRAME_LEN];
  memcpy(&buf[0], info.encoded_frame, info.frame_len);

  // Introduce a CRC error which should cause an error return and no callback
  buf[info.frame_len - 1]++;

  sbp_state_t state;
  sbp_state_init(&state);

  Reader reader{buf, info.frame_len};
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    int res = sbp_process(&state, &Reader::read_static);
    EXPECT_EQ(res, reader.remaining() == 0 ? SBP_CRC_ERROR : SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_uart_state_depa_send(&state, info.sender_id, &info.test_msg,
                                         &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.avg, greater.latency.avg);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.current, greater.latency.current);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.lmax, greater.latency.lmax);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.lmin, greater.latency.lmin);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.crc_error_count,
                        greater.uart_a.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.io_error_count,
                        greater.uart_a.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.rx_buffer_level,
                        greater.uart_a.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.rx_throughput,
                        greater.uart_a.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.tx_buffer_level,
                        greater.uart_a.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.tx_throughput,
                        greater.uart_a.tx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.crc_error_count,
                        greater.uart_b.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.io_error_count,
                        greater.uart_b.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.rx_buffer_level,
                        greater.uart_b.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.rx_throughput,
                        greater.uart_b.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.tx_buffer_level,
                        greater.uart_b.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.tx_throughput,
                        greater.uart_b.tx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.crc_error_count,
                        greater.uart_ftdi.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.io_error_count,
                        greater.uart_ftdi.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.rx_buffer_level,
                        greater.uart_ftdi.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.rx_throughput,
                        greater.uart_ftdi.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.tx_buffer_level,
                        greater.uart_ftdi.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.tx_throughput,
                        greater.uart_ftdi.tx_throughput);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::id,
  // SbpMsgUartStateDepa);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::name,
               "MSG_UART_STATE_DEPA");
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_uart_state_depa_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::get(const_sbp_msg_t);
  sbp_msg_uart_state_depa_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.uart_state_depa, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(info.test_msg,
                                                            &msg2);
  EXPECT_EQ(msg2.uart_state_depa, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[58];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3,
       ReceiveThroughMessageHandler) {
  auto info = get_test_msg_info();
  auto reader = info.get_frame_reader();

  sbp::State state{};
  state.set_reader(&reader);

  CppHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(state.process(), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgUartStateDepa,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA3,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgUartStateDepa,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_piksi_MsgUartStateDepA4 : public ::testing::Test {
 public:
  Testauto_check_sbp_piksi_MsgUartStateDepA4() {
    assign(test_msg_.latency.avg, -1);
    assign(test_msg_.latency.current, -1);
    assign(test_msg_.latency.lmax, 0);
    assign(test_msg_.latency.lmin, 0);
    assign(test_msg_.uart_a.crc_error_count, 0);
    assign(test_msg_.uart_a.io_error_count, 0);
    assign(test_msg_.uart_a.rx_buffer_level, 0);
    assign(test_msg_.uart_a.rx_throughput, 0.008196720853447914);
    assign(test_msg_.uart_a.tx_buffer_level, 0);
    assign(test_msg_.uart_a.tx_throughput, 0.0);
    assign(test_msg_.uart_b.crc_error_count, 0);
    assign(test_msg_.uart_b.io_error_count, 0);
    assign(test_msg_.uart_b.rx_buffer_level, 0);
    assign(test_msg_.uart_b.rx_throughput, 0.0);
    assign(test_msg_.uart_b.tx_buffer_level, 2);
    assign(test_msg_.uart_b.tx_throughput, 0.09836065769195557);
    assign(test_msg_.uart_ftdi.crc_error_count, 0);
    assign(test_msg_.uart_ftdi.io_error_count, 0);
    assign(test_msg_.uart_ftdi.rx_buffer_level, 0);
    assign(test_msg_.uart_ftdi.rx_throughput, 0.0);
    assign(test_msg_.uart_ftdi.tx_buffer_level, 38);
    assign(test_msg_.uart_ftdi.tx_throughput, 0.49399998784065247);
  }

  class SlowReader final : public sbp::IReader {
   public:
    SlowReader(const uint8_t *buf, uint32_t len)
        : sbp::IReader(), buf_{buf}, len_{len} {}

    s32 read(uint8_t *buf, const uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      if (remaining() == 0) {
        return -1;
      }
      skip_next_read = !skip_next_read;
      if (skip_next_read) {
        return 0;
      }
      uint32_t real_n = std::min(n, 1u);
      memcpy(buf, buf_ + offset_, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return len_ - offset_; }

    static s32 read_static(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowReader *>(ctx)->read(buf, len);
    }

   private:
    const uint8_t *buf_;
    uint32_t len_;
    uint32_t offset_{};
    bool skip_next_read{};
  };

  class Reader final : public sbp::IReader {
   public:
    Reader(const uint8_t *buf, uint32_t len)
        : sbp::IReader(), buf_{buf}, len_{len} {}

    s32 read(uint8_t *buf, const uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, remaining());
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf, buf_ + offset_, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return len_ - offset_; }

    static s32 read_static(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Reader *>(ctx)->read(buf, len);
    }

   private:
    const uint8_t *buf_;
    uint32_t len_;
    uint32_t offset_{};
  };

  class SlowWriter final : public sbp::IWriter {
   public:
    explicit SlowWriter(uint32_t max_len = cMaxLen)
        : IWriter(), max_len_{max_len} {}
    static constexpr uint32_t cMaxLen = SBP_MAX_FRAME_LEN;

    s32 write(const uint8_t *buf, uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, 1u);
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf_ + offset_, buf, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return max_len_ - offset_; }

    const uint8_t *data() const noexcept { return buf_; }

    uint32_t len() const noexcept { return offset_; }

    static s32 write_static(const uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowWriter *>(ctx)->write(buf, len);
    }

    static s32 write_c(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowWriter *>(ctx)->write(buf, len);
    }

   private:
    uint8_t buf_[cMaxLen];
    uint32_t max_len_;
    uint32_t offset_{};
  };

  class Writer final : public sbp::IWriter {
   public:
    explicit Writer(uint32_t max_len = cMaxLen)
        : IWriter(), max_len_{max_len} {}
    static constexpr uint32_t cMaxLen = SBP_MAX_FRAME_LEN;

    s32 write(const uint8_t *buf, uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, remaining());
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf_ + offset_, buf, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return max_len_ - offset_; }

    const uint8_t *data() const noexcept { return buf_; }

    uint32_t len() const noexcept { return offset_; }

    static s32 write_static(const uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Writer *>(ctx)->write(buf, len);
    }

    static s32 write_c(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Writer *>(ctx)->write(buf, len);
    }

   private:
    uint8_t buf_[cMaxLen];
    uint32_t max_len_;
    uint32_t offset_{};
  };

  struct CppHandler final
      : public sbp::MessageHandler<sbp_msg_uart_state_depa_t> {
    using sbp::MessageHandler<sbp_msg_uart_state_depa_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_uart_state_depa_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_uart_state_depa_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgUartStateDepa,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_uart_state_depa_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgUartStateDepa);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->uart_state_depa,
             sizeof(msg->uart_state_depa));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_uart_state_depa_t test_msg;
    sbp_msg_t test_msg_wrapped;
    sbp_msg_type_t msg_type;
    uint16_t sender_id;
    uint8_t preamble;
    uint16_t crc;
    const uint8_t *encoded_frame;
    uint32_t frame_len;
    const uint8_t *encoded_payload;
    uint8_t payload_len;

    Reader get_frame_reader() const noexcept {
      return Reader{encoded_frame, frame_len};
    }

    Reader get_frame_reader(uint32_t max) const noexcept {
      assert(max <= frame_len);
      return Reader{encoded_frame, max};
    }

    SlowReader get_slow_frame_reader() const noexcept {
      return SlowReader{encoded_frame, frame_len};
    }

    Writer get_frame_writer() const noexcept { return Writer{frame_len}; }

    Writer get_frame_writer(uint32_t max) const noexcept { return Writer{max}; }

    SlowWriter get_slow_frame_writer() const noexcept {
      return SlowWriter{frame_len};
    }
  };

  TestMsgInfo get_test_msg_info() const noexcept {
    TestMsgInfo info;
    memcpy(&info.test_msg, &test_msg_, sizeof(test_msg_));
    memcpy(&info.test_msg_wrapped.uart_state_depa, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgUartStateDepa);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x6f70;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 58;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_uart_state_depa_t &lesser,
                        const sbp_msg_uart_state_depa_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_uart_state_depa_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_uart_state_depa_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_uart_state_depa_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_uart_state_depa_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_greater, &wrapped_lesser),
        0);

    // lesser vs lesser
    EXPECT_TRUE(lesser == lesser);
    EXPECT_FALSE(lesser != lesser);
    EXPECT_FALSE(lesser < lesser);
    EXPECT_TRUE(lesser <= lesser);
    EXPECT_FALSE(lesser > lesser);
    EXPECT_TRUE(lesser >= lesser);

    // greater vs greater
    EXPECT_TRUE(greater == greater);
    EXPECT_FALSE(greater != greater);
    EXPECT_FALSE(greater < greater);
    EXPECT_TRUE(greater <= greater);
    EXPECT_FALSE(greater > greater);
    EXPECT_TRUE(greater >= greater);

    // lesser vs greater
    EXPECT_FALSE(lesser == greater);
    EXPECT_TRUE(lesser != greater);
    EXPECT_TRUE(lesser < greater);
    EXPECT_TRUE(lesser <= greater);
    EXPECT_FALSE(lesser > greater);
    EXPECT_FALSE(lesser >= greater);

    // greater vs lesser
    EXPECT_FALSE(greater == lesser);
    EXPECT_TRUE(greater != lesser);
    EXPECT_FALSE(greater < lesser);
    EXPECT_FALSE(greater <= lesser);
    EXPECT_TRUE(greater > lesser);
    EXPECT_TRUE(greater >= lesser);
  }

  template <typename T,
            std::enable_if_t<std::is_integral<T>::value, bool> = true>
  void make_lesser_greater(T &lesser, T &greater) {
    if (greater == std::numeric_limits<T>::max()) {
      lesser--;
    } else {
      greater++;
    }
  }

  template <typename T,
            std::enable_if_t<std::is_floating_point<T>::value, bool> = true>
  void make_lesser_greater(T &lesser, T &greater) {
    (void)lesser;
    greater += static_cast<T>(1.0);
  }

  void make_lesser_greater(sbp_string_t &lesser, sbp_string_t &greater) {
    if (greater.data[0] == 'z') {
      lesser.data[0]--;
    } else {
      greater.data[0]++;
    }
  }

  template <size_t N>
  void make_lesser_greater(char (&lesser)[N], char (&greater)[N]) {
    if (lesser[0] == 'z') {
      lesser[0]--;
    } else {
      greater[0]++;
    }
  }

 private:
  sbp_msg_uart_state_depa_t test_msg_{};
  uint8_t encoded_frame_[58 + 8] = {
      85, 24, 0, 195, 4,   58,  0,   0,   0,   0,   138, 75, 6, 60,
      0,  0,  0, 0,   0,   0,   80,  113, 201, 61,  0,   0,  0, 0,
      0,  0,  0, 0,   2,   0,   145, 237, 252, 62,  0,   0,  0, 0,
      0,  0,  0, 0,   38,  0,   255, 255, 255, 255, 0,   0,  0, 0,
      0,  0,  0, 0,   255, 255, 255, 255, 112, 111,
  };
  uint8_t encoded_payload_[58] = {
      0,   0,   0,  0, 138, 75, 6, 60, 0, 0,   0,   0,   0,   0,   80,
      113, 201, 61, 0, 0,   0,  0, 0,  0, 0,   0,   2,   0,   145, 237,
      252, 62,  0,  0, 0,   0,  0, 0,  0, 0,   38,  0,   255, 255, 255,
      255, 0,   0,  0, 0,   0,  0, 0,  0, 255, 255, 255, 255,
  };
};

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_uart_state_depa_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgUartStateDepa, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[58];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_uart_state_depa_encode(&buf[0], sizeof(buf), &n_written,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgUartStateDepa, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[58];

  EXPECT_EQ(sbp_msg_uart_state_depa_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}
TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[58];

  for (uint8_t i = 0; i < 58; i++) {
    EXPECT_EQ(
        sbp_msg_uart_state_depa_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0],
                                           info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgUartStateDepa, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};

  EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0],
                                           info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0], i,
                                             nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, ReceiveThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto reader = info.get_frame_reader();
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(sbp_process(&state, &Reader::read_static), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4,
       ReceiveThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto reader = info.get_frame_reader(i);
    sbp_state_set_io_context(&state, &reader);

    CHandler handler(&state);

    int most_recent_return = sbp_process(&state, &Reader::read_static);
    while (most_recent_return == SBP_OK || reader.remaining() > 0) {
      most_recent_return = sbp_process(&state, &Reader::read_static);
    }

    EXPECT_NE(most_recent_return, SBP_OK);
    EXPECT_EQ(reader.remaining(), 0);

    EXPECT_EQ(handler.outputs.size(), 0);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, SlowRead) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto reader = info.get_slow_frame_reader();
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(sbp_process(&state, &SlowReader::read_static), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, BadCRC) {
  auto info = get_test_msg_info();
  uint8_t buf[SBP_MAX_FRAME_LEN];
  memcpy(&buf[0], info.encoded_frame, info.frame_len);

  // Introduce a CRC error which should cause an error return and no callback
  buf[info.frame_len - 1]++;

  sbp_state_t state;
  sbp_state_init(&state);

  Reader reader{buf, info.frame_len};
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    int res = sbp_process(&state, &Reader::read_static);
    EXPECT_EQ(res, reader.remaining() == 0 ? SBP_CRC_ERROR : SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_uart_state_depa_send(&state, info.sender_id, &info.test_msg,
                                         &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.avg, greater.latency.avg);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.current, greater.latency.current);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.lmax, greater.latency.lmax);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.lmin, greater.latency.lmin);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.crc_error_count,
                        greater.uart_a.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.io_error_count,
                        greater.uart_a.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.rx_buffer_level,
                        greater.uart_a.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.rx_throughput,
                        greater.uart_a.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.tx_buffer_level,
                        greater.uart_a.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.tx_throughput,
                        greater.uart_a.tx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.crc_error_count,
                        greater.uart_b.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.io_error_count,
                        greater.uart_b.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.rx_buffer_level,
                        greater.uart_b.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.rx_throughput,
                        greater.uart_b.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.tx_buffer_level,
                        greater.uart_b.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.tx_throughput,
                        greater.uart_b.tx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.crc_error_count,
                        greater.uart_ftdi.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.io_error_count,
                        greater.uart_ftdi.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.rx_buffer_level,
                        greater.uart_ftdi.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.rx_throughput,
                        greater.uart_ftdi.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.tx_buffer_level,
                        greater.uart_ftdi.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.tx_throughput,
                        greater.uart_ftdi.tx_throughput);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::id,
  // SbpMsgUartStateDepa);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::name,
               "MSG_UART_STATE_DEPA");
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_uart_state_depa_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::get(const_sbp_msg_t);
  sbp_msg_uart_state_depa_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.uart_state_depa, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(info.test_msg,
                                                            &msg2);
  EXPECT_EQ(msg2.uart_state_depa, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[58];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4,
       ReceiveThroughMessageHandler) {
  auto info = get_test_msg_info();
  auto reader = info.get_frame_reader();

  sbp::State state{};
  state.set_reader(&reader);

  CppHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(state.process(), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgUartStateDepa,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA4,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgUartStateDepa,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_piksi_MsgUartStateDepA5 : public ::testing::Test {
 public:
  Testauto_check_sbp_piksi_MsgUartStateDepA5() {
    assign(test_msg_.latency.avg, -1);
    assign(test_msg_.latency.current, -1);
    assign(test_msg_.latency.lmax, 0);
    assign(test_msg_.latency.lmin, 0);
    assign(test_msg_.uart_a.crc_error_count, 0);
    assign(test_msg_.uart_a.io_error_count, 0);
    assign(test_msg_.uart_a.rx_buffer_level, 0);
    assign(test_msg_.uart_a.rx_throughput, 0.0);
    assign(test_msg_.uart_a.tx_buffer_level, 2);
    assign(test_msg_.uart_a.tx_throughput, 0.012000000104308128);
    assign(test_msg_.uart_b.crc_error_count, 0);
    assign(test_msg_.uart_b.io_error_count, 0);
    assign(test_msg_.uart_b.rx_buffer_level, 0);
    assign(test_msg_.uart_b.rx_throughput, 0.0);
    assign(test_msg_.uart_b.tx_buffer_level, 2);
    assign(test_msg_.uart_b.tx_throughput, 0.012000000104308128);
    assign(test_msg_.uart_ftdi.crc_error_count, 0);
    assign(test_msg_.uart_ftdi.io_error_count, 0);
    assign(test_msg_.uart_ftdi.rx_buffer_level, 0);
    assign(test_msg_.uart_ftdi.rx_throughput, 0.0);
    assign(test_msg_.uart_ftdi.tx_buffer_level, 50);
    assign(test_msg_.uart_ftdi.tx_throughput, 1.315000057220459);
  }

  class SlowReader final : public sbp::IReader {
   public:
    SlowReader(const uint8_t *buf, uint32_t len)
        : sbp::IReader(), buf_{buf}, len_{len} {}

    s32 read(uint8_t *buf, const uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      if (remaining() == 0) {
        return -1;
      }
      skip_next_read = !skip_next_read;
      if (skip_next_read) {
        return 0;
      }
      uint32_t real_n = std::min(n, 1u);
      memcpy(buf, buf_ + offset_, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return len_ - offset_; }

    static s32 read_static(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowReader *>(ctx)->read(buf, len);
    }

   private:
    const uint8_t *buf_;
    uint32_t len_;
    uint32_t offset_{};
    bool skip_next_read{};
  };

  class Reader final : public sbp::IReader {
   public:
    Reader(const uint8_t *buf, uint32_t len)
        : sbp::IReader(), buf_{buf}, len_{len} {}

    s32 read(uint8_t *buf, const uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, remaining());
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf, buf_ + offset_, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return len_ - offset_; }

    static s32 read_static(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Reader *>(ctx)->read(buf, len);
    }

   private:
    const uint8_t *buf_;
    uint32_t len_;
    uint32_t offset_{};
  };

  class SlowWriter final : public sbp::IWriter {
   public:
    explicit SlowWriter(uint32_t max_len = cMaxLen)
        : IWriter(), max_len_{max_len} {}
    static constexpr uint32_t cMaxLen = SBP_MAX_FRAME_LEN;

    s32 write(const uint8_t *buf, uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, 1u);
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf_ + offset_, buf, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return max_len_ - offset_; }

    const uint8_t *data() const noexcept { return buf_; }

    uint32_t len() const noexcept { return offset_; }

    static s32 write_static(const uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowWriter *>(ctx)->write(buf, len);
    }

    static s32 write_c(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<SlowWriter *>(ctx)->write(buf, len);
    }

   private:
    uint8_t buf_[cMaxLen];
    uint32_t max_len_;
    uint32_t offset_{};
  };

  class Writer final : public sbp::IWriter {
   public:
    explicit Writer(uint32_t max_len = cMaxLen)
        : IWriter(), max_len_{max_len} {}
    static constexpr uint32_t cMaxLen = SBP_MAX_FRAME_LEN;

    s32 write(const uint8_t *buf, uint32_t n) override {
      if (n == 0) {
        return 0;
      }
      uint32_t real_n = std::min(n, remaining());
      if (real_n == 0) {
        return -1;
      }
      memcpy(buf_ + offset_, buf, real_n);
      offset_ += real_n;
      return static_cast<s32>(real_n);
    }

    uint32_t remaining() const noexcept { return max_len_ - offset_; }

    const uint8_t *data() const noexcept { return buf_; }

    uint32_t len() const noexcept { return offset_; }

    static s32 write_static(const uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Writer *>(ctx)->write(buf, len);
    }

    static s32 write_c(uint8_t *buf, uint32_t len, void *ctx) {
      return static_cast<Writer *>(ctx)->write(buf, len);
    }

   private:
    uint8_t buf_[cMaxLen];
    uint32_t max_len_;
    uint32_t offset_{};
  };

  struct CppHandler final
      : public sbp::MessageHandler<sbp_msg_uart_state_depa_t> {
    using sbp::MessageHandler<sbp_msg_uart_state_depa_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_uart_state_depa_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_uart_state_depa_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgUartStateDepa,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_uart_state_depa_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgUartStateDepa);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->uart_state_depa,
             sizeof(msg->uart_state_depa));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_uart_state_depa_t test_msg;
    sbp_msg_t test_msg_wrapped;
    sbp_msg_type_t msg_type;
    uint16_t sender_id;
    uint8_t preamble;
    uint16_t crc;
    const uint8_t *encoded_frame;
    uint32_t frame_len;
    const uint8_t *encoded_payload;
    uint8_t payload_len;

    Reader get_frame_reader() const noexcept {
      return Reader{encoded_frame, frame_len};
    }

    Reader get_frame_reader(uint32_t max) const noexcept {
      assert(max <= frame_len);
      return Reader{encoded_frame, max};
    }

    SlowReader get_slow_frame_reader() const noexcept {
      return SlowReader{encoded_frame, frame_len};
    }

    Writer get_frame_writer() const noexcept { return Writer{frame_len}; }

    Writer get_frame_writer(uint32_t max) const noexcept { return Writer{max}; }

    SlowWriter get_slow_frame_writer() const noexcept {
      return SlowWriter{frame_len};
    }
  };

  TestMsgInfo get_test_msg_info() const noexcept {
    TestMsgInfo info;
    memcpy(&info.test_msg, &test_msg_, sizeof(test_msg_));
    memcpy(&info.test_msg_wrapped.uart_state_depa, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgUartStateDepa);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x4816;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 58;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_uart_state_depa_t &lesser,
                        const sbp_msg_uart_state_depa_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_uart_state_depa_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_uart_state_depa_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_uart_state_depa_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_uart_state_depa_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgUartStateDepa, &wrapped_greater, &wrapped_lesser),
        0);

    // lesser vs lesser
    EXPECT_TRUE(lesser == lesser);
    EXPECT_FALSE(lesser != lesser);
    EXPECT_FALSE(lesser < lesser);
    EXPECT_TRUE(lesser <= lesser);
    EXPECT_FALSE(lesser > lesser);
    EXPECT_TRUE(lesser >= lesser);

    // greater vs greater
    EXPECT_TRUE(greater == greater);
    EXPECT_FALSE(greater != greater);
    EXPECT_FALSE(greater < greater);
    EXPECT_TRUE(greater <= greater);
    EXPECT_FALSE(greater > greater);
    EXPECT_TRUE(greater >= greater);

    // lesser vs greater
    EXPECT_FALSE(lesser == greater);
    EXPECT_TRUE(lesser != greater);
    EXPECT_TRUE(lesser < greater);
    EXPECT_TRUE(lesser <= greater);
    EXPECT_FALSE(lesser > greater);
    EXPECT_FALSE(lesser >= greater);

    // greater vs lesser
    EXPECT_FALSE(greater == lesser);
    EXPECT_TRUE(greater != lesser);
    EXPECT_FALSE(greater < lesser);
    EXPECT_FALSE(greater <= lesser);
    EXPECT_TRUE(greater > lesser);
    EXPECT_TRUE(greater >= lesser);
  }

  template <typename T,
            std::enable_if_t<std::is_integral<T>::value, bool> = true>
  void make_lesser_greater(T &lesser, T &greater) {
    if (greater == std::numeric_limits<T>::max()) {
      lesser--;
    } else {
      greater++;
    }
  }

  template <typename T,
            std::enable_if_t<std::is_floating_point<T>::value, bool> = true>
  void make_lesser_greater(T &lesser, T &greater) {
    (void)lesser;
    greater += static_cast<T>(1.0);
  }

  void make_lesser_greater(sbp_string_t &lesser, sbp_string_t &greater) {
    if (greater.data[0] == 'z') {
      lesser.data[0]--;
    } else {
      greater.data[0]++;
    }
  }

  template <size_t N>
  void make_lesser_greater(char (&lesser)[N], char (&greater)[N]) {
    if (lesser[0] == 'z') {
      lesser[0]--;
    } else {
      greater[0]++;
    }
  }

 private:
  sbp_msg_uart_state_depa_t test_msg_{};
  uint8_t encoded_frame_[58 + 8] = {
      85, 24, 0, 195, 4,   58,  166, 155, 68,  60,  0, 0, 0, 0,
      0,  0,  0, 0,   2,   0,   166, 155, 68,  60,  0, 0, 0, 0,
      0,  0,  0, 0,   2,   0,   236, 81,  168, 63,  0, 0, 0, 0,
      0,  0,  0, 0,   50,  0,   255, 255, 255, 255, 0, 0, 0, 0,
      0,  0,  0, 0,   255, 255, 255, 255, 22,  72,
  };
  uint8_t encoded_payload_[58] = {
      166, 155, 68, 60, 0, 0, 0, 0, 0, 0,   0,   0,   2,   0,   166,
      155, 68,  60, 0,  0, 0, 0, 0, 0, 0,   0,   2,   0,   236, 81,
      168, 63,  0,  0,  0, 0, 0, 0, 0, 0,   50,  0,   255, 255, 255,
      255, 0,   0,  0,  0, 0, 0, 0, 0, 255, 255, 255, 255,
  };
};

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_uart_state_depa_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgUartStateDepa, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[58];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_uart_state_depa_encode(&buf[0], sizeof(buf), &n_written,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgUartStateDepa, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[58];

  EXPECT_EQ(sbp_msg_uart_state_depa_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}
TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[58];

  for (uint8_t i = 0; i < 58; i++) {
    EXPECT_EQ(
        sbp_msg_uart_state_depa_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0],
                                           info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgUartStateDepa, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};

  EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0],
                                           info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_uart_state_depa_decode(&info.encoded_payload[0], i,
                                             nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, ReceiveThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto reader = info.get_frame_reader();
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(sbp_process(&state, &Reader::read_static), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5,
       ReceiveThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto reader = info.get_frame_reader(i);
    sbp_state_set_io_context(&state, &reader);

    CHandler handler(&state);

    int most_recent_return = sbp_process(&state, &Reader::read_static);
    while (most_recent_return == SBP_OK || reader.remaining() > 0) {
      most_recent_return = sbp_process(&state, &Reader::read_static);
    }

    EXPECT_NE(most_recent_return, SBP_OK);
    EXPECT_EQ(reader.remaining(), 0);

    EXPECT_EQ(handler.outputs.size(), 0);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, SlowRead) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto reader = info.get_slow_frame_reader();
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(sbp_process(&state, &SlowReader::read_static), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, BadCRC) {
  auto info = get_test_msg_info();
  uint8_t buf[SBP_MAX_FRAME_LEN];
  memcpy(&buf[0], info.encoded_frame, info.frame_len);

  // Introduce a CRC error which should cause an error return and no callback
  buf[info.frame_len - 1]++;

  sbp_state_t state;
  sbp_state_init(&state);

  Reader reader{buf, info.frame_len};
  sbp_state_set_io_context(&state, &reader);

  CHandler handler{&state};

  while (reader.remaining() > 0) {
    int res = sbp_process(&state, &Reader::read_static);
    EXPECT_EQ(res, reader.remaining() == 0 ? SBP_CRC_ERROR : SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_uart_state_depa_send(&state, info.sender_id, &info.test_msg,
                                         &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgUartStateDepa, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.avg, greater.latency.avg);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.current, greater.latency.current);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.lmax, greater.latency.lmax);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.latency.lmin, greater.latency.lmin);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.crc_error_count,
                        greater.uart_a.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.io_error_count,
                        greater.uart_a.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.rx_buffer_level,
                        greater.uart_a.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.rx_throughput,
                        greater.uart_a.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.tx_buffer_level,
                        greater.uart_a.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_a.tx_throughput,
                        greater.uart_a.tx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.crc_error_count,
                        greater.uart_b.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.io_error_count,
                        greater.uart_b.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.rx_buffer_level,
                        greater.uart_b.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.rx_throughput,
                        greater.uart_b.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.tx_buffer_level,
                        greater.uart_b.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_b.tx_throughput,
                        greater.uart_b.tx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.crc_error_count,
                        greater.uart_ftdi.crc_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.io_error_count,
                        greater.uart_ftdi.io_error_count);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.rx_buffer_level,
                        greater.uart_ftdi.rx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.rx_throughput,
                        greater.uart_ftdi.rx_throughput);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.tx_buffer_level,
                        greater.uart_ftdi.tx_buffer_level);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_uart_state_depa_t lesser = info.test_msg;
    sbp_msg_uart_state_depa_t greater = info.test_msg;
    make_lesser_greater(lesser.uart_ftdi.tx_throughput,
                        greater.uart_ftdi.tx_throughput);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::id,
  // SbpMsgUartStateDepa);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::name,
               "MSG_UART_STATE_DEPA");
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_uart_state_depa_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::get(const_sbp_msg_t);
  sbp_msg_uart_state_depa_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.uart_state_depa, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_uart_state_depa_t>::to_sbp_msg(info.test_msg,
                                                            &msg2);
  EXPECT_EQ(msg2.uart_state_depa, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_uart_state_depa_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[58];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 58);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 58), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_uart_state_depa_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_uart_state_depa_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 58);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5,
       ReceiveThroughMessageHandler) {
  auto info = get_test_msg_info();
  auto reader = info.get_frame_reader();

  sbp::State state{};
  state.set_reader(&reader);

  CppHandler handler{&state};

  while (reader.remaining() > 0) {
    EXPECT_GE(state.process(), SBP_OK);
  }

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgUartStateDepa,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgUartStateDepA5,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgUartStateDepa,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace