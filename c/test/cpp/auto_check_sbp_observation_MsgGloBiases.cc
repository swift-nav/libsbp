/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgGloBiases.yaml by
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
class Testauto_check_sbp_observation_MsgGloBiases0 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgGloBiases0() {
    assign(test_msg_.l1ca_bias, 0);
    assign(test_msg_.l1p_bias, 0);
    assign(test_msg_.l2ca_bias, 0);
    assign(test_msg_.l2p_bias, 0);
    assign(test_msg_.mask, 0);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_glo_biases_t> {
    using sbp::MessageHandler<sbp_msg_glo_biases_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_glo_biases_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_glo_biases_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgGloBiases, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_glo_biases_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgGloBiases);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->glo_biases, sizeof(msg->glo_biases));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_glo_biases_t test_msg;
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
    memcpy(&info.test_msg_wrapped.glo_biases, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgGloBiases);
    info.sender_id = 0;
    info.preamble = 0x55;
    info.crc = 0xd34d;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 9;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_glo_biases_t &lesser,
                        const sbp_msg_glo_biases_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_glo_biases_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_glo_biases_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_glo_biases_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_glo_biases_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_glo_biases_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_glo_biases_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgGloBiases, &wrapped_lesser, &wrapped_lesser), 0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgGloBiases, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgGloBiases, &wrapped_lesser, &wrapped_greater), 0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgGloBiases, &wrapped_greater, &wrapped_lesser), 0);

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
    if (lesser > std::numeric_limits<T>::min()) {
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
  sbp_msg_glo_biases_t test_msg_{};
  uint8_t encoded_frame_[9 + 8] = {
      85, 117, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77, 211,
  };
  uint8_t encoded_payload_[9] = {
      0, 0, 0, 0, 0, 0, 0, 0, 0,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_glo_biases_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgGloBiases, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[9];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_glo_biases_encode(&buf[0], sizeof(buf), &n_written,
                                      &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 9);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 9), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgGloBiases, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 9);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 9), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[9];

  EXPECT_EQ(
      sbp_msg_glo_biases_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 9), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[9];

  for (uint8_t i = 0; i < 9; i++) {
    EXPECT_EQ(sbp_msg_glo_biases_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_glo_biases_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_glo_biases_decode(&info.encoded_payload[0],
                                      info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 9);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgGloBiases, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 9);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_glo_biases_t msg{};

  EXPECT_EQ(sbp_msg_glo_biases_decode(&info.encoded_payload[0],
                                      info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_glo_biases_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(
        sbp_msg_glo_biases_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0,
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

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_glo_biases_send(&state, info.sender_id, &info.test_msg,
                                    &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgGloBiases, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgGloBiases, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgGloBiases, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_glo_biases_t lesser = info.test_msg;
    sbp_msg_glo_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.l1ca_bias, greater.l1ca_bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_glo_biases_t lesser = info.test_msg;
    sbp_msg_glo_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.l1p_bias, greater.l1p_bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_glo_biases_t lesser = info.test_msg;
    sbp_msg_glo_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.l2ca_bias, greater.l2ca_bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_glo_biases_t lesser = info.test_msg;
    sbp_msg_glo_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.l2p_bias, greater.l2p_bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_glo_biases_t lesser = info.test_msg;
    sbp_msg_glo_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.mask, greater.mask);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_glo_biases_t>::id, SbpMsgGloBiases);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_glo_biases_t>::name,
               "MSG_GLO_BIASES");
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_glo_biases_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_glo_biases_t>::get(const_sbp_msg_t);
  sbp_msg_glo_biases_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_glo_biases_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_glo_biases_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.glo_biases, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_glo_biases_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.glo_biases, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_glo_biases_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_glo_biases_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[9];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_glo_biases_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 9);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 9), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_glo_biases_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_glo_biases_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 9);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0,
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

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgGloBiases,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgGloBiases0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgGloBiases,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace