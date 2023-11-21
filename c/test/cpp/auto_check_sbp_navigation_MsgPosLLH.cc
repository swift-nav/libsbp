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
#include <libsbp/cpp/state.h>
#include <libsbp/sbp.h>
#include <algorithm>

namespace {

template <typename T, typename U>
void assign(T &dest, const U &source) {
  dest = static_cast<T>(source);
}
class Testauto_check_sbp_navigation_MsgPosLLH0 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgPosLLH0() {
    assign(test_msg_.flags, 2);
    assign(test_msg_.h_accuracy, 0);
    assign(test_msg_.height, 28.21160739227208);
    assign(test_msg_.lat, 37.25130398358085);
    assign(test_msg_.lon, -121.87505366879361);
    assign(test_msg_.n_sats, 14);
    assign(test_msg_.tow, 326825000);
    assign(test_msg_.v_accuracy, 0);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_pos_llh_t> {
    using sbp::MessageHandler<sbp_msg_pos_llh_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_pos_llh_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_pos_llh_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgPosLlh, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_pos_llh_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgPosLlh);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->pos_llh, sizeof(msg->pos_llh));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_pos_llh_t test_msg;
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
    memcpy(&info.test_msg_wrapped.pos_llh, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgPosLlh);
    info.sender_id = 35027;
    info.preamble = 0x55;
    info.crc = 0xa2af;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 34;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_pos_llh_t &lesser,
                        const sbp_msg_pos_llh_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_pos_llh_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_pos_llh_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_pos_llh_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_pos_llh_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &wrapped_greater, &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgPosLlh, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgPosLlh, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_pos_llh_t test_msg_{};
  uint8_t encoded_frame_[34 + 8] = {
      85,  10,  2,  211, 136, 34,  40, 244, 122, 19,  201, 106, 155, 186,
      42,  160, 66, 64,  168, 109, 26, 225, 0,   120, 94,  192, 130, 102,
      237, 230, 43, 54,  60,  64,  0,  0,   0,   0,   14,  2,   175, 162,
  };
  uint8_t encoded_payload_[34] = {
      40,  244, 122, 19,  201, 106, 155, 186, 42,  160, 66,  64,
      168, 109, 26,  225, 0,   120, 94,  192, 130, 102, 237, 230,
      43,  54,  60,  64,  0,   0,   0,   0,   14,  2,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_pos_llh_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgPosLlh, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[34];
  uint8_t n_written;

  EXPECT_EQ(
      sbp_msg_pos_llh_encode(&buf[0], sizeof(buf), &n_written, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgPosLlh,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[34];

  EXPECT_EQ(
      sbp_msg_pos_llh_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[34];

  for (uint8_t i = 0; i < 34; i++) {
    EXPECT_EQ(sbp_msg_pos_llh_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_pos_llh_decode(&info.encoded_payload[0], info.payload_len,
                                   &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgPosLlh, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};

  EXPECT_EQ(sbp_msg_pos_llh_decode(&info.encoded_payload[0], info.payload_len,
                                   nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(
        sbp_msg_pos_llh_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0,
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_pos_llh_send(&state, info.sender_id, &info.test_msg,
                                 &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.h_accuracy, greater.h_accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.height, greater.height);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.lat, greater.lat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.lon, greater.lon);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.v_accuracy, greater.v_accuracy);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::id, SbpMsgPosLlh);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::name, "MSG_POS_LLH");
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_pos_llh_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::get(const_sbp_msg_t);
  sbp_msg_pos_llh_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.pos_llh, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.pos_llh, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[34];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgPosLlh, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgPosLlh, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_navigation_MsgPosLLH1 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgPosLLH1() {
    assign(test_msg_.flags, 2);
    assign(test_msg_.h_accuracy, 0);
    assign(test_msg_.height, 27.742055560866373);
    assign(test_msg_.lat, 37.251303074738104);
    assign(test_msg_.lon, -121.87505349618341);
    assign(test_msg_.n_sats, 15);
    assign(test_msg_.tow, 326826000);
    assign(test_msg_.v_accuracy, 0);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_pos_llh_t> {
    using sbp::MessageHandler<sbp_msg_pos_llh_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_pos_llh_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_pos_llh_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgPosLlh, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_pos_llh_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgPosLlh);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->pos_llh, sizeof(msg->pos_llh));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_pos_llh_t test_msg;
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
    memcpy(&info.test_msg_wrapped.pos_llh, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgPosLlh);
    info.sender_id = 35027;
    info.preamble = 0x55;
    info.crc = 0xb126;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 34;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_pos_llh_t &lesser,
                        const sbp_msg_pos_llh_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_pos_llh_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_pos_llh_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_pos_llh_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_pos_llh_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &wrapped_greater, &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgPosLlh, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgPosLlh, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_pos_llh_t test_msg_{};
  uint8_t encoded_frame_[34 + 8] = {
      85,  10,  2,   211, 136, 34, 16, 248, 122, 19,  52, 177, 251, 178,
      42,  160, 66,  64,  237, 22, 97, 224, 0,   120, 94, 192, 107, 188,
      109, 90,  247, 189, 59,  64, 0,  0,   0,   0,   15, 2,   38,  177,
  };
  uint8_t encoded_payload_[34] = {
      16,  248, 122, 19,  52, 177, 251, 178, 42,  160, 66,  64,
      237, 22,  97,  224, 0,  120, 94,  192, 107, 188, 109, 90,
      247, 189, 59,  64,  0,  0,   0,   0,   15,  2,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_pos_llh_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgPosLlh, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[34];
  uint8_t n_written;

  EXPECT_EQ(
      sbp_msg_pos_llh_encode(&buf[0], sizeof(buf), &n_written, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgPosLlh,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[34];

  EXPECT_EQ(
      sbp_msg_pos_llh_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[34];

  for (uint8_t i = 0; i < 34; i++) {
    EXPECT_EQ(sbp_msg_pos_llh_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_pos_llh_decode(&info.encoded_payload[0], info.payload_len,
                                   &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgPosLlh, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};

  EXPECT_EQ(sbp_msg_pos_llh_decode(&info.encoded_payload[0], info.payload_len,
                                   nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(
        sbp_msg_pos_llh_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1,
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_pos_llh_send(&state, info.sender_id, &info.test_msg,
                                 &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.h_accuracy, greater.h_accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.height, greater.height);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.lat, greater.lat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.lon, greater.lon);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.v_accuracy, greater.v_accuracy);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::id, SbpMsgPosLlh);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::name, "MSG_POS_LLH");
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_pos_llh_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::get(const_sbp_msg_t);
  sbp_msg_pos_llh_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.pos_llh, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.pos_llh, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[34];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgPosLlh, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH1,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgPosLlh, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_navigation_MsgPosLLH2 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgPosLLH2() {
    assign(test_msg_.flags, 2);
    assign(test_msg_.h_accuracy, 0);
    assign(test_msg_.height, 27.613721582970516);
    assign(test_msg_.lat, 37.25130117370741);
    assign(test_msg_.lon, -121.87505373641241);
    assign(test_msg_.n_sats, 15);
    assign(test_msg_.tow, 326827000);
    assign(test_msg_.v_accuracy, 0);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_pos_llh_t> {
    using sbp::MessageHandler<sbp_msg_pos_llh_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_pos_llh_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_pos_llh_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgPosLlh, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_pos_llh_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgPosLlh);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->pos_llh, sizeof(msg->pos_llh));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_pos_llh_t test_msg;
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
    memcpy(&info.test_msg_wrapped.pos_llh, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgPosLlh);
    info.sender_id = 35027;
    info.preamble = 0x55;
    info.crc = 0x2833;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 34;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_pos_llh_t &lesser,
                        const sbp_msg_pos_llh_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_pos_llh_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_pos_llh_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_pos_llh_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_pos_llh_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &wrapped_greater, &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgPosLlh, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgPosLlh, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_pos_llh_t test_msg_{};
  uint8_t encoded_frame_[34 + 8] = {
      85,  10,  2,  211, 136, 34, 248, 251, 122, 19,  135, 66,  9,  163,
      42,  160, 66, 64,  146, 8,  99,  225, 0,   120, 94,  192, 45, 181,
      143, 219, 28, 157, 59,  64, 0,   0,   0,   0,   15,  2,   51, 40,
  };
  uint8_t encoded_payload_[34] = {
      248, 251, 122, 19,  135, 66,  9,  163, 42, 160, 66,  64,
      146, 8,   99,  225, 0,   120, 94, 192, 45, 181, 143, 219,
      28,  157, 59,  64,  0,   0,   0,  0,   15, 2,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_pos_llh_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgPosLlh, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[34];
  uint8_t n_written;

  EXPECT_EQ(
      sbp_msg_pos_llh_encode(&buf[0], sizeof(buf), &n_written, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgPosLlh,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[34];

  EXPECT_EQ(
      sbp_msg_pos_llh_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[34];

  for (uint8_t i = 0; i < 34; i++) {
    EXPECT_EQ(sbp_msg_pos_llh_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_pos_llh_decode(&info.encoded_payload[0], info.payload_len,
                                   &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgPosLlh, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};

  EXPECT_EQ(sbp_msg_pos_llh_decode(&info.encoded_payload[0], info.payload_len,
                                   nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(
        sbp_msg_pos_llh_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2,
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_pos_llh_send(&state, info.sender_id, &info.test_msg,
                                 &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.h_accuracy, greater.h_accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.height, greater.height);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.lat, greater.lat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.lon, greater.lon);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.v_accuracy, greater.v_accuracy);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::id, SbpMsgPosLlh);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::name, "MSG_POS_LLH");
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_pos_llh_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::get(const_sbp_msg_t);
  sbp_msg_pos_llh_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.pos_llh, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.pos_llh, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[34];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgPosLlh, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH2,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgPosLlh, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_navigation_MsgPosLLH3 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgPosLLH3() {
    assign(test_msg_.flags, 2);
    assign(test_msg_.h_accuracy, 0);
    assign(test_msg_.height, 27.80259807042305);
    assign(test_msg_.lat, 37.251296042079176);
    assign(test_msg_.lon, -121.87505511141057);
    assign(test_msg_.n_sats, 15);
    assign(test_msg_.tow, 326828000);
    assign(test_msg_.v_accuracy, 0);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_pos_llh_t> {
    using sbp::MessageHandler<sbp_msg_pos_llh_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_pos_llh_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_pos_llh_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgPosLlh, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_pos_llh_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgPosLlh);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->pos_llh, sizeof(msg->pos_llh));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_pos_llh_t test_msg;
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
    memcpy(&info.test_msg_wrapped.pos_llh, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgPosLlh);
    info.sender_id = 35027;
    info.preamble = 0x55;
    info.crc = 0xc20c;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 34;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_pos_llh_t &lesser,
                        const sbp_msg_pos_llh_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_pos_llh_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_pos_llh_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_pos_llh_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_pos_llh_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &wrapped_greater, &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgPosLlh, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgPosLlh, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_pos_llh_t test_msg_{};
  uint8_t encoded_frame_[34 + 8] = {
      85, 10,  2,   211, 136, 34,  224, 255, 122, 19,  18, 44,  253, 119,
      42, 160, 66,  64,  48,  109, 39,  231, 0,   120, 94, 192, 185, 76,
      48, 17,  119, 205, 59,  64,  0,   0,   0,   0,   15, 2,   12,  194,
  };
  uint8_t encoded_payload_[34] = {
      224, 255, 122, 19,  18, 44,  253, 119, 42,  160, 66, 64,
      48,  109, 39,  231, 0,  120, 94,  192, 185, 76,  48, 17,
      119, 205, 59,  64,  0,  0,   0,   0,   15,  2,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_pos_llh_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgPosLlh, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[34];
  uint8_t n_written;

  EXPECT_EQ(
      sbp_msg_pos_llh_encode(&buf[0], sizeof(buf), &n_written, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgPosLlh,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[34];

  EXPECT_EQ(
      sbp_msg_pos_llh_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[34];

  for (uint8_t i = 0; i < 34; i++) {
    EXPECT_EQ(sbp_msg_pos_llh_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_pos_llh_decode(&info.encoded_payload[0], info.payload_len,
                                   &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgPosLlh, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};

  EXPECT_EQ(sbp_msg_pos_llh_decode(&info.encoded_payload[0], info.payload_len,
                                   nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(
        sbp_msg_pos_llh_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3,
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_pos_llh_send(&state, info.sender_id, &info.test_msg,
                                 &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.h_accuracy, greater.h_accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.height, greater.height);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.lat, greater.lat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.lon, greater.lon);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.v_accuracy, greater.v_accuracy);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::id, SbpMsgPosLlh);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::name, "MSG_POS_LLH");
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_pos_llh_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::get(const_sbp_msg_t);
  sbp_msg_pos_llh_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.pos_llh, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.pos_llh, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[34];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgPosLlh, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH3,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgPosLlh, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_navigation_MsgPosLLH4 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgPosLLH4() {
    assign(test_msg_.flags, 2);
    assign(test_msg_.h_accuracy, 0);
    assign(test_msg_.height, 27.939512310879213);
    assign(test_msg_.lat, 37.251292578377395);
    assign(test_msg_.lon, -121.87505609407974);
    assign(test_msg_.n_sats, 15);
    assign(test_msg_.tow, 326829000);
    assign(test_msg_.v_accuracy, 0);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_pos_llh_t> {
    using sbp::MessageHandler<sbp_msg_pos_llh_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_pos_llh_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_pos_llh_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgPosLlh, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_pos_llh_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgPosLlh);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->pos_llh, sizeof(msg->pos_llh));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_pos_llh_t test_msg;
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
    memcpy(&info.test_msg_wrapped.pos_llh, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgPosLlh);
    info.sender_id = 35027;
    info.preamble = 0x55;
    info.crc = 0x6722;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 34;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_pos_llh_t &lesser,
                        const sbp_msg_pos_llh_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_pos_llh_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_pos_llh_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_pos_llh_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_pos_llh_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgPosLlh, &wrapped_greater, &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgPosLlh, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgPosLlh, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_pos_llh_t test_msg_{};
  uint8_t encoded_frame_[34 + 8] = {
      85,  10,  2,   211, 136, 34,  200, 3,   123, 19,  225, 237, 238, 90,
      42,  160, 66,  64,  59,  143, 70,  235, 0,   120, 94,  192, 101, 106,
      249, 224, 131, 240, 59,  64,  0,   0,   0,   0,   15,  2,   34,  103,
  };
  uint8_t encoded_payload_[34] = {
      200, 3,   123, 19,  225, 237, 238, 90,  42,  160, 66,  64,
      59,  143, 70,  235, 0,   120, 94,  192, 101, 106, 249, 224,
      131, 240, 59,  64,  0,   0,   0,   0,   15,  2,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_pos_llh_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgPosLlh, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[34];
  uint8_t n_written;

  EXPECT_EQ(
      sbp_msg_pos_llh_encode(&buf[0], sizeof(buf), &n_written, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgPosLlh,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[34];

  EXPECT_EQ(
      sbp_msg_pos_llh_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[34];

  for (uint8_t i = 0; i < 34; i++) {
    EXPECT_EQ(sbp_msg_pos_llh_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_pos_llh_decode(&info.encoded_payload[0], info.payload_len,
                                   &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgPosLlh, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};

  EXPECT_EQ(sbp_msg_pos_llh_decode(&info.encoded_payload[0], info.payload_len,
                                   nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(
        sbp_msg_pos_llh_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4,
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_pos_llh_send(&state, info.sender_id, &info.test_msg,
                                 &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPosLlh, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.h_accuracy, greater.h_accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.height, greater.height);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.lat, greater.lat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.lon, greater.lon);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_pos_llh_t lesser = info.test_msg;
    sbp_msg_pos_llh_t greater = info.test_msg;
    make_lesser_greater(lesser.v_accuracy, greater.v_accuracy);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::id, SbpMsgPosLlh);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::name, "MSG_POS_LLH");
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_pos_llh_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::get(const_sbp_msg_t);
  sbp_msg_pos_llh_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.pos_llh, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_pos_llh_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.pos_llh, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[34];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 34);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 34), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_pos_llh_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_pos_llh_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 34);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgPosLlh, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgPosLLH4,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgPosLlh, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace