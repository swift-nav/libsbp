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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSocketUsage.yaml by
// generate.py. Do not modify by hand!

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
class Testauto_check_sbp_linux_MsgLinuxSocketUsage0 : public ::testing::Test {
 public:
  Testauto_check_sbp_linux_MsgLinuxSocketUsage0() {
    assign(test_msg_.avg_queue_depth, 2907030541);
    assign(test_msg_.max_queue_depth, 3048922691);

    assign(test_msg_.socket_state_counts[0], 39670);

    assign(test_msg_.socket_state_counts[1], 4603);

    assign(test_msg_.socket_state_counts[2], 46048);

    assign(test_msg_.socket_state_counts[3], 43290);

    assign(test_msg_.socket_state_counts[4], 23217);

    assign(test_msg_.socket_state_counts[5], 54677);

    assign(test_msg_.socket_state_counts[6], 1750);

    assign(test_msg_.socket_state_counts[7], 16510);

    assign(test_msg_.socket_state_counts[8], 47480);

    assign(test_msg_.socket_state_counts[9], 33620);

    assign(test_msg_.socket_state_counts[10], 28616);

    assign(test_msg_.socket_state_counts[11], 36128);

    assign(test_msg_.socket_state_counts[12], 53721);

    assign(test_msg_.socket_state_counts[13], 3636);

    assign(test_msg_.socket_state_counts[14], 37822);

    assign(test_msg_.socket_state_counts[15], 63135);

    assign(test_msg_.socket_type_counts[0], 31373);

    assign(test_msg_.socket_type_counts[1], 30676);

    assign(test_msg_.socket_type_counts[2], 7811);

    assign(test_msg_.socket_type_counts[3], 12152);

    assign(test_msg_.socket_type_counts[4], 27929);

    assign(test_msg_.socket_type_counts[5], 16794);

    assign(test_msg_.socket_type_counts[6], 42116);

    assign(test_msg_.socket_type_counts[7], 7719);

    assign(test_msg_.socket_type_counts[8], 44830);

    assign(test_msg_.socket_type_counts[9], 11272);

    assign(test_msg_.socket_type_counts[10], 28444);

    assign(test_msg_.socket_type_counts[11], 61676);

    assign(test_msg_.socket_type_counts[12], 19120);

    assign(test_msg_.socket_type_counts[13], 33183);

    assign(test_msg_.socket_type_counts[14], 39322);

    assign(test_msg_.socket_type_counts[15], 58786);
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
      : public sbp::MessageHandler<sbp_msg_linux_socket_usage_t> {
    using sbp::MessageHandler<sbp_msg_linux_socket_usage_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_linux_socket_usage_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_linux_socket_usage_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgLinuxSocketUsage,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_linux_socket_usage_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgLinuxSocketUsage);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->linux_socket_usage,
             sizeof(msg->linux_socket_usage));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_linux_socket_usage_t test_msg;
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
    memcpy(&info.test_msg_wrapped.linux_socket_usage, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgLinuxSocketUsage);
    info.sender_id = 35442;
    info.preamble = 0x55;
    info.crc = 0x9a82;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 72;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_linux_socket_usage_t &lesser,
                        const sbp_msg_linux_socket_usage_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_linux_socket_usage_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_linux_socket_usage_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_linux_socket_usage_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_linux_socket_usage_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_linux_socket_usage_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_linux_socket_usage_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgLinuxSocketUsage, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgLinuxSocketUsage, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgLinuxSocketUsage, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgLinuxSocketUsage, &wrapped_greater,
                              &wrapped_lesser),
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
  sbp_msg_linux_socket_usage_t test_msg_{};
  uint8_t encoded_frame_[72 + 8] = {
      85,  5,   127, 114, 138, 72,  13,  196, 69,  173, 67,  222, 186, 181,
      246, 154, 251, 17,  224, 179, 26,  169, 177, 90,  149, 213, 214, 6,
      126, 64,  120, 185, 84,  131, 200, 111, 32,  141, 217, 209, 52,  14,
      190, 147, 159, 246, 141, 122, 212, 119, 131, 30,  120, 47,  25,  109,
      154, 65,  132, 164, 39,  30,  30,  175, 8,   44,  28,  111, 236, 240,
      176, 74,  159, 129, 154, 153, 162, 229, 130, 154,
  };
  uint8_t encoded_payload_[72] = {
      13,  196, 69,  173, 67,  222, 186, 181, 246, 154, 251, 17,  224, 179, 26,
      169, 177, 90,  149, 213, 214, 6,   126, 64,  120, 185, 84,  131, 200, 111,
      32,  141, 217, 209, 52,  14,  190, 147, 159, 246, 141, 122, 212, 119, 131,
      30,  120, 47,  25,  109, 154, 65,  132, 164, 39,  30,  30,  175, 8,   44,
      28,  111, 236, 240, 176, 74,  159, 129, 154, 153, 162, 229,
  };
};

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_linux_socket_usage_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgLinuxSocketUsage, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[72];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_linux_socket_usage_encode(&buf[0], sizeof(buf), &n_written,
                                              &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 72);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 72), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgLinuxSocketUsage, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 72);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 72), 0);
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[72];

  EXPECT_EQ(sbp_msg_linux_socket_usage_encode(&buf[0], sizeof(buf), nullptr,
                                              &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 72), 0);
}
TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[72];

  for (uint8_t i = 0; i < 72; i++) {
    EXPECT_EQ(
        sbp_msg_linux_socket_usage_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_linux_socket_usage_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_linux_socket_usage_decode(&info.encoded_payload[0],
                                              info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 72);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgLinuxSocketUsage, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 72);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_linux_socket_usage_t msg{};

  EXPECT_EQ(sbp_msg_linux_socket_usage_decode(&info.encoded_payload[0],
                                              info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_linux_socket_usage_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_linux_socket_usage_decode(&info.encoded_payload[0], i,
                                                nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0,
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

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, SlowRead) {
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

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, BadCRC) {
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

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_linux_socket_usage_send(&state, info.sender_id,
                                            &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgLinuxSocketUsage, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgLinuxSocketUsage, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgLinuxSocketUsage, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.avg_queue_depth, greater.avg_queue_depth);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.max_queue_depth, greater.max_queue_depth);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[0],
                        greater.socket_state_counts[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[1],
                        greater.socket_state_counts[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[2],
                        greater.socket_state_counts[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[3],
                        greater.socket_state_counts[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[4],
                        greater.socket_state_counts[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[5],
                        greater.socket_state_counts[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[6],
                        greater.socket_state_counts[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[7],
                        greater.socket_state_counts[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[8],
                        greater.socket_state_counts[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[9],
                        greater.socket_state_counts[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[10],
                        greater.socket_state_counts[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[11],
                        greater.socket_state_counts[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[12],
                        greater.socket_state_counts[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[13],
                        greater.socket_state_counts[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[14],
                        greater.socket_state_counts[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_state_counts[15],
                        greater.socket_state_counts[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[0],
                        greater.socket_type_counts[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[1],
                        greater.socket_type_counts[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[2],
                        greater.socket_type_counts[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[3],
                        greater.socket_type_counts[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[4],
                        greater.socket_type_counts[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[5],
                        greater.socket_type_counts[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[6],
                        greater.socket_type_counts[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[7],
                        greater.socket_type_counts[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[8],
                        greater.socket_type_counts[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[9],
                        greater.socket_type_counts[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[10],
                        greater.socket_type_counts[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[11],
                        greater.socket_type_counts[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[12],
                        greater.socket_type_counts[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[13],
                        greater.socket_type_counts[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[14],
                        greater.socket_type_counts[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_linux_socket_usage_t lesser = info.test_msg;
    sbp_msg_linux_socket_usage_t greater = info.test_msg;
    make_lesser_greater(lesser.socket_type_counts[15],
                        greater.socket_type_counts[15]);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_linux_socket_usage_t>::id,
  // SbpMsgLinuxSocketUsage);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_linux_socket_usage_t>::name,
               "MSG_LINUX_SOCKET_USAGE");
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_linux_socket_usage_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_linux_socket_usage_t>::get(const_sbp_msg_t);
  sbp_msg_linux_socket_usage_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_linux_socket_usage_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 = sbp::MessageTraits<sbp_msg_linux_socket_usage_t>::to_sbp_msg(
      info.test_msg);
  EXPECT_EQ(msg1.linux_socket_usage, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_linux_socket_usage_t>::to_sbp_msg(info.test_msg,
                                                               &msg2);
  EXPECT_EQ(msg2.linux_socket_usage, info.test_msg);
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_linux_socket_usage_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_linux_socket_usage_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[72];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_linux_socket_usage_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 72);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 72), 0);
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_linux_socket_usage_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_linux_socket_usage_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 72);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0,
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

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgLinuxSocketUsage,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_linux_MsgLinuxSocketUsage0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgLinuxSocketUsage,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace