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
// spec/tests/yaml/swiftnav/sbp/observation/test_msgObsDepA.yaml by generate.py.
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
class Testauto_check_sbp_observation_msgObsDepA0 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_msgObsDepA0() {
    assign(test_msg_.header.n_obs, 32);
    assign(test_msg_.header.t.tow, 407084600);
    assign(test_msg_.header.t.wn, 1838);
    assign(test_msg_.n_obs, 7);

    assign(test_msg_.obs[0].L.f, 33);
    assign(test_msg_.obs[0].L.i, -36108);
    assign(test_msg_.obs[0].P, 2046421816);
    assign(test_msg_.obs[0].cn0, 46);
    assign(test_msg_.obs[0].lock, 55875);
    assign(test_msg_.obs[0].prn, 0);

    assign(test_msg_.obs[1].L.f, 98);
    assign(test_msg_.obs[1].L.i, 203030);
    assign(test_msg_.obs[1].P, 2085014510);
    assign(test_msg_.obs[1].cn0, 43);
    assign(test_msg_.obs[1].lock, 40376);
    assign(test_msg_.obs[1].prn, 2);

    assign(test_msg_.obs[2].L.f, 185);
    assign(test_msg_.obs[2].L.i, -178306);
    assign(test_msg_.obs[2].P, 2110096816);
    assign(test_msg_.obs[2].cn0, 39);
    assign(test_msg_.obs[2].lock, 14148);
    assign(test_msg_.obs[2].prn, 3);

    assign(test_msg_.obs[3].L.f, 139);
    assign(test_msg_.obs[3].L.i, -137374);
    assign(test_msg_.obs[3].P, 2208476476);
    assign(test_msg_.obs[3].cn0, 30);
    assign(test_msg_.obs[3].lock, 4129);
    assign(test_msg_.obs[3].prn, 10);

    assign(test_msg_.obs[4].L.f, 40);
    assign(test_msg_.obs[4].L.i, -167638);
    assign(test_msg_.obs[4].P, 2298000000);
    assign(test_msg_.obs[4].cn0, 20);
    assign(test_msg_.obs[4].lock, 18218);
    assign(test_msg_.obs[4].prn, 13);

    assign(test_msg_.obs[5].L.f, 64);
    assign(test_msg_.obs[5].L.i, 209919);
    assign(test_msg_.obs[5].P, 2266101494);
    assign(test_msg_.obs[5].cn0, 27);
    assign(test_msg_.obs[5].lock, 63852);
    assign(test_msg_.obs[5].prn, 22);

    assign(test_msg_.obs[6].L.f, 31);
    assign(test_msg_.obs[6].L.i, -53117);
    assign(test_msg_.obs[6].P, 1987193298);
    assign(test_msg_.obs[6].cn0, 52);
    assign(test_msg_.obs[6].lock, 15074);
    assign(test_msg_.obs[6].prn, 30);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepA, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_a, sizeof(msg->obs_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_a, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0xd917;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 98;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_a_t &lesser,
                        const sbp_msg_obs_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepA, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepA, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepA, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_a_t test_msg_{};
  uint8_t encoded_frame_[98 + 8] = {
      85,  69,  0,   195, 4,   98,  56,  158, 67,  24,  46,  7,   32,  56,
      235, 249, 121, 244, 114, 255, 255, 33,  46,  67,  218, 0,   238, 203,
      70,  124, 22,  25,  3,   0,   98,  43,  184, 157, 2,   176, 133, 197,
      125, 126, 71,  253, 255, 185, 39,  68,  55,  3,   60,  173, 162, 131,
      98,  231, 253, 255, 139, 30,  33,  16,  10,  128, 178, 248, 136, 42,
      113, 253, 255, 40,  20,  42,  71,  13,  246, 246, 17,  135, 255, 51,
      3,   0,   64,  27,  108, 249, 22,  210, 41,  114, 118, 131, 48,  255,
      255, 31,  52,  226, 58,  30,  23,  217,
  };
  uint8_t encoded_payload_[98] = {
      56,  158, 67,  24,  46,  7,   32,  56,  235, 249, 121, 244, 114, 255,
      255, 33,  46,  67,  218, 0,   238, 203, 70,  124, 22,  25,  3,   0,
      98,  43,  184, 157, 2,   176, 133, 197, 125, 126, 71,  253, 255, 185,
      39,  68,  55,  3,   60,  173, 162, 131, 98,  231, 253, 255, 139, 30,
      33,  16,  10,  128, 178, 248, 136, 42,  113, 253, 255, 40,  20,  42,
      71,  13,  246, 246, 17,  135, 255, 51,  3,   0,   64,  27,  108, 249,
      22,  210, 41,  114, 118, 131, 48,  255, 255, 31,  52,  226, 58,  30,
  };
};

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_a_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[98];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 98);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 98), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepA,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 98);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 98), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[98];

  EXPECT_EQ(
      sbp_msg_obs_dep_a_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 98), 0);
}
TEST_F(Testauto_check_sbp_observation_msgObsDepA0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[98];

  for (uint8_t i = 0; i < 98; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 98);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 98);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_msgObsDepA0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_a_t t{};
      return sbp_msg_obs_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_a_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA0,
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_a_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].prn, greater.obs[0].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].prn, greater.obs[1].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].prn, greater.obs[2].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.f, greater.obs[3].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.i, greater.obs[3].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].P, greater.obs[3].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].cn0, greater.obs[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].lock, greater.obs[3].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].prn, greater.obs[3].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.f, greater.obs[4].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.i, greater.obs[4].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].P, greater.obs[4].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].cn0, greater.obs[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].lock, greater.obs[4].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].prn, greater.obs[4].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].L.f, greater.obs[5].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].L.i, greater.obs[5].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].P, greater.obs[5].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].cn0, greater.obs[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].lock, greater.obs[5].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].prn, greater.obs[5].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].L.f, greater.obs[6].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].L.i, greater.obs[6].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].P, greater.obs[6].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].cn0, greater.obs[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].lock, greater.obs[6].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].prn, greater.obs[6].prn);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::id, SbpMsgObsDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::name, "MSG_OBS_DEP_A");
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[98];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 98);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 98), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 98);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0,
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepA, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepA, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_msgObsDepA1 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_msgObsDepA1() {
    assign(test_msg_.header.n_obs, 33);
    assign(test_msg_.header.t.tow, 407084600);
    assign(test_msg_.header.t.wn, 1838);
    assign(test_msg_.n_obs, 1);

    assign(test_msg_.obs[0].L.f, 147);
    assign(test_msg_.obs[0].L.i, 8294);
    assign(test_msg_.obs[0].P, 1973695572);
    assign(test_msg_.obs[0].cn0, 62);
    assign(test_msg_.obs[0].lock, 64062);
    assign(test_msg_.obs[0].prn, 31);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepA, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_a, sizeof(msg->obs_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_a, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0xeea;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 20;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_a_t &lesser,
                        const sbp_msg_obs_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepA, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepA, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepA, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_a_t test_msg_{};
  uint8_t encoded_frame_[20 + 8] = {
      85, 69,  0,   195, 4,  20, 56, 158, 67, 24, 46,  7,  33,  84,
      52, 164, 117, 102, 32, 0,  0,  147, 62, 62, 250, 31, 234, 14,
  };
  uint8_t encoded_payload_[20] = {
      56,  158, 67, 24, 46, 7,   33, 84, 52,  164,
      117, 102, 32, 0,  0,  147, 62, 62, 250, 31,
  };
};

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_a_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepA,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  EXPECT_EQ(
      sbp_msg_obs_dep_a_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}
TEST_F(Testauto_check_sbp_observation_msgObsDepA1, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  for (uint8_t i = 0; i < 20; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_msgObsDepA1, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_a_t t{};
      return sbp_msg_obs_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_a_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA1,
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_a_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].prn, greater.obs[0].prn);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::id, SbpMsgObsDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::name, "MSG_OBS_DEP_A");
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1,
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA1,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepA, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA1,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepA, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_msgObsDepA2 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_msgObsDepA2() {
    assign(test_msg_.header.n_obs, 32);
    assign(test_msg_.header.t.tow, 407084800);
    assign(test_msg_.header.t.wn, 1838);
    assign(test_msg_.n_obs, 7);

    assign(test_msg_.obs[0].L.f, 141);
    assign(test_msg_.obs[0].L.i, -36207);
    assign(test_msg_.obs[0].P, 2046415136);
    assign(test_msg_.obs[0].cn0, 45);
    assign(test_msg_.obs[0].lock, 55875);
    assign(test_msg_.obs[0].prn, 0);

    assign(test_msg_.obs[1].L.f, 159);
    assign(test_msg_.obs[1].L.i, 203599);
    assign(test_msg_.obs[1].P, 2084995249);
    assign(test_msg_.obs[1].cn0, 44);
    assign(test_msg_.obs[1].lock, 40376);
    assign(test_msg_.obs[1].prn, 2);

    assign(test_msg_.obs[2].L.f, 77);
    assign(test_msg_.obs[2].L.i, -178769);
    assign(test_msg_.obs[2].P, 2110097211);
    assign(test_msg_.obs[2].cn0, 40);
    assign(test_msg_.obs[2].lock, 14148);
    assign(test_msg_.obs[2].prn, 3);

    assign(test_msg_.obs[3].L.f, 20);
    assign(test_msg_.obs[3].L.i, -137807);
    assign(test_msg_.obs[3].P, 2208476371);
    assign(test_msg_.obs[3].cn0, 31);
    assign(test_msg_.obs[3].lock, 4129);
    assign(test_msg_.obs[3].prn, 10);

    assign(test_msg_.obs[4].L.f, 94);
    assign(test_msg_.obs[4].L.i, -168076);
    assign(test_msg_.obs[4].P, 2298000000);
    assign(test_msg_.obs[4].cn0, 21);
    assign(test_msg_.obs[4].lock, 18218);
    assign(test_msg_.obs[4].prn, 13);

    assign(test_msg_.obs[5].L.f, 214);
    assign(test_msg_.obs[5].L.i, 210469);
    assign(test_msg_.obs[5].P, 2266082742);
    assign(test_msg_.obs[5].cn0, 27);
    assign(test_msg_.obs[5].lock, 63852);
    assign(test_msg_.obs[5].prn, 22);

    assign(test_msg_.obs[6].L.f, 129);
    assign(test_msg_.obs[6].L.i, -53264);
    assign(test_msg_.obs[6].P, 1987187803);
    assign(test_msg_.obs[6].cn0, 52);
    assign(test_msg_.obs[6].lock, 15074);
    assign(test_msg_.obs[6].prn, 30);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepA, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_a, sizeof(msg->obs_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_a, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x77c8;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 98;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_a_t &lesser,
                        const sbp_msg_obs_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepA, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepA, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepA, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_a_t test_msg_{};
  uint8_t encoded_frame_[98 + 8] = {
      85,  69,  0,   195, 4,   98,  0,   159, 67,  24,  46,  7,   32,  32,
      209, 249, 121, 145, 114, 255, 255, 141, 45,  67,  218, 0,   177, 128,
      70,  124, 79,  27,  3,   0,   159, 44,  184, 157, 2,   59,  135, 197,
      125, 175, 69,  253, 255, 77,  40,  68,  55,  3,   211, 172, 162, 131,
      177, 229, 253, 255, 20,  31,  33,  16,  10,  128, 178, 248, 136, 116,
      111, 253, 255, 94,  21,  42,  71,  13,  182, 173, 17,  135, 37,  54,
      3,   0,   214, 27,  108, 249, 22,  91,  20,  114, 118, 240, 47,  255,
      255, 129, 52,  226, 58,  30,  200, 119,
  };
  uint8_t encoded_payload_[98] = {
      0,   159, 67,  24,  46,  7,   32,  32,  209, 249, 121, 145, 114, 255,
      255, 141, 45,  67,  218, 0,   177, 128, 70,  124, 79,  27,  3,   0,
      159, 44,  184, 157, 2,   59,  135, 197, 125, 175, 69,  253, 255, 77,
      40,  68,  55,  3,   211, 172, 162, 131, 177, 229, 253, 255, 20,  31,
      33,  16,  10,  128, 178, 248, 136, 116, 111, 253, 255, 94,  21,  42,
      71,  13,  182, 173, 17,  135, 37,  54,  3,   0,   214, 27,  108, 249,
      22,  91,  20,  114, 118, 240, 47,  255, 255, 129, 52,  226, 58,  30,
  };
};

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_a_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[98];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 98);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 98), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepA,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 98);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 98), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[98];

  EXPECT_EQ(
      sbp_msg_obs_dep_a_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 98), 0);
}
TEST_F(Testauto_check_sbp_observation_msgObsDepA2, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[98];

  for (uint8_t i = 0; i < 98; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 98);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 98);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_msgObsDepA2, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_a_t t{};
      return sbp_msg_obs_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_a_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA2,
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_a_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].prn, greater.obs[0].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].prn, greater.obs[1].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].prn, greater.obs[2].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.f, greater.obs[3].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.i, greater.obs[3].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].P, greater.obs[3].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].cn0, greater.obs[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].lock, greater.obs[3].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].prn, greater.obs[3].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.f, greater.obs[4].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.i, greater.obs[4].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].P, greater.obs[4].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].cn0, greater.obs[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].lock, greater.obs[4].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].prn, greater.obs[4].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].L.f, greater.obs[5].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].L.i, greater.obs[5].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].P, greater.obs[5].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].cn0, greater.obs[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].lock, greater.obs[5].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].prn, greater.obs[5].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].L.f, greater.obs[6].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].L.i, greater.obs[6].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].P, greater.obs[6].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].cn0, greater.obs[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].lock, greater.obs[6].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].prn, greater.obs[6].prn);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::id, SbpMsgObsDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::name, "MSG_OBS_DEP_A");
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[98];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 98);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 98), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 98);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2,
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA2,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepA, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA2,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepA, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_msgObsDepA3 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_msgObsDepA3() {
    assign(test_msg_.header.n_obs, 33);
    assign(test_msg_.header.t.tow, 407084800);
    assign(test_msg_.header.t.wn, 1838);
    assign(test_msg_.n_obs, 1);

    assign(test_msg_.obs[0].L.f, 222);
    assign(test_msg_.obs[0].L.i, 8312);
    assign(test_msg_.obs[0].P, 1973687089);
    assign(test_msg_.obs[0].cn0, 63);
    assign(test_msg_.obs[0].lock, 64062);
    assign(test_msg_.obs[0].prn, 31);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepA, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_a, sizeof(msg->obs_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_a, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0xe70b;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 20;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_a_t &lesser,
                        const sbp_msg_obs_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepA, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepA, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepA, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_a_t test_msg_{};
  uint8_t encoded_frame_[20 + 8] = {
      85, 69,  0,   195, 4,  20, 0, 159, 67, 24, 46,  7,  33, 49,
      19, 164, 117, 120, 32, 0,  0, 222, 63, 62, 250, 31, 11, 231,
  };
  uint8_t encoded_payload_[20] = {
      0,   159, 67, 24, 46, 7,   33, 49, 19,  164,
      117, 120, 32, 0,  0,  222, 63, 62, 250, 31,
  };
};

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_a_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepA,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  EXPECT_EQ(
      sbp_msg_obs_dep_a_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}
TEST_F(Testauto_check_sbp_observation_msgObsDepA3, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  for (uint8_t i = 0; i < 20; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_msgObsDepA3, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_a_t t{};
      return sbp_msg_obs_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_a_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA3,
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_a_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].prn, greater.obs[0].prn);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::id, SbpMsgObsDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::name, "MSG_OBS_DEP_A");
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3,
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA3,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepA, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA3,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepA, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_msgObsDepA4 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_msgObsDepA4() {
    assign(test_msg_.header.n_obs, 16);
    assign(test_msg_.header.t.tow, 407151200);
    assign(test_msg_.header.t.wn, 1838);
    assign(test_msg_.n_obs, 5);

    assign(test_msg_.obs[0].L.f, 189);
    assign(test_msg_.obs[0].L.i, -27527);
    assign(test_msg_.obs[0].P, 2044298327);
    assign(test_msg_.obs[0].cn0, 43);
    assign(test_msg_.obs[0].lock, 37807);
    assign(test_msg_.obs[0].prn, 0);

    assign(test_msg_.obs[1].L.f, 1);
    assign(test_msg_.obs[1].L.i, -123030);
    assign(test_msg_.obs[1].P, 2110275716);
    assign(test_msg_.obs[1].cn0, 41);
    assign(test_msg_.obs[1].lock, 45326);
    assign(test_msg_.obs[1].prn, 3);

    assign(test_msg_.obs[2].L.f, 166);
    assign(test_msg_.obs[2].L.i, -113594);
    assign(test_msg_.obs[2].P, 2298000000);
    assign(test_msg_.obs[2].cn0, 18);
    assign(test_msg_.obs[2].lock, 34232);
    assign(test_msg_.obs[2].prn, 13);

    assign(test_msg_.obs[3].L.f, 249);
    assign(test_msg_.obs[3].L.i, 137478);
    assign(test_msg_.obs[3].P, 2259844888);
    assign(test_msg_.obs[3].cn0, 28);
    assign(test_msg_.obs[3].lock, 24609);
    assign(test_msg_.obs[3].prn, 22);

    assign(test_msg_.obs[4].L.f, 203);
    assign(test_msg_.obs[4].L.i, -36797);
    assign(test_msg_.obs[4].P, 1985374378);
    assign(test_msg_.obs[4].cn0, 56);
    assign(test_msg_.obs[4].lock, 22736);
    assign(test_msg_.obs[4].prn, 30);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepA, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_a, sizeof(msg->obs_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_a, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x6b2b;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 72;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_a_t &lesser,
                        const sbp_msg_obs_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepA, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepA, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepA, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_a_t test_msg_{};
  uint8_t encoded_frame_[72 + 8] = {
      85,  69,  0,   195, 4,   72,  96,  162, 68,  24,  46,  7,   16,  87,
      132, 217, 121, 121, 148, 255, 255, 189, 43,  175, 147, 0,   132, 64,
      200, 125, 106, 31,  254, 255, 1,   41,  14,  177, 3,   128, 178, 248,
      136, 70,  68,  254, 255, 166, 18,  184, 133, 13,  24,  127, 178, 134,
      6,   25,  2,   0,   249, 28,  33,  96,  22,  170, 104, 86,  118, 67,
      112, 255, 255, 203, 56,  208, 88,  30,  43,  107,
  };
  uint8_t encoded_payload_[72] = {
      96,  162, 68,  24,  46,  7,   16,  87,  132, 217, 121, 121, 148, 255, 255,
      189, 43,  175, 147, 0,   132, 64,  200, 125, 106, 31,  254, 255, 1,   41,
      14,  177, 3,   128, 178, 248, 136, 70,  68,  254, 255, 166, 18,  184, 133,
      13,  24,  127, 178, 134, 6,   25,  2,   0,   249, 28,  33,  96,  22,  170,
      104, 86,  118, 67,  112, 255, 255, 203, 56,  208, 88,  30,
  };
};

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_a_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[72];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 72);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 72), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepA,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 72);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 72), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[72];

  EXPECT_EQ(
      sbp_msg_obs_dep_a_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 72), 0);
}
TEST_F(Testauto_check_sbp_observation_msgObsDepA4, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[72];

  for (uint8_t i = 0; i < 72; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 72);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 72);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_msgObsDepA4, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_a_t t{};
      return sbp_msg_obs_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_a_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA4,
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_a_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].prn, greater.obs[0].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].prn, greater.obs[1].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].prn, greater.obs[2].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.f, greater.obs[3].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.i, greater.obs[3].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].P, greater.obs[3].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].cn0, greater.obs[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].lock, greater.obs[3].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].prn, greater.obs[3].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.f, greater.obs[4].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.i, greater.obs[4].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].P, greater.obs[4].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].cn0, greater.obs[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].lock, greater.obs[4].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].prn, greater.obs[4].prn);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::id, SbpMsgObsDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::name, "MSG_OBS_DEP_A");
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[72];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 72);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 72), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 72);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4,
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA4,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepA, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA4,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepA, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_msgObsDepA5 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_msgObsDepA5() {
    assign(test_msg_.header.n_obs, 16);
    assign(test_msg_.header.t.tow, 407151400);
    assign(test_msg_.header.t.wn, 1838);
    assign(test_msg_.n_obs, 5);

    assign(test_msg_.obs[0].L.f, 1);
    assign(test_msg_.obs[0].L.i, -27634);
    assign(test_msg_.obs[0].P, 2044291972);
    assign(test_msg_.obs[0].cn0, 44);
    assign(test_msg_.obs[0].lock, 37807);
    assign(test_msg_.obs[0].prn, 0);

    assign(test_msg_.obs[1].L.f, 153);
    assign(test_msg_.obs[1].L.i, -123500);
    assign(test_msg_.obs[1].P, 2110276225);
    assign(test_msg_.obs[1].cn0, 41);
    assign(test_msg_.obs[1].lock, 45326);
    assign(test_msg_.obs[1].prn, 3);

    assign(test_msg_.obs[2].L.f, 222);
    assign(test_msg_.obs[2].L.i, -114033);
    assign(test_msg_.obs[2].P, 2298000000);
    assign(test_msg_.obs[2].cn0, 18);
    assign(test_msg_.obs[2].lock, 34232);
    assign(test_msg_.obs[2].prn, 13);

    assign(test_msg_.obs[3].L.f, 237);
    assign(test_msg_.obs[3].L.i, 138026);
    assign(test_msg_.obs[3].P, 2259826078);
    assign(test_msg_.obs[3].cn0, 30);
    assign(test_msg_.obs[3].lock, 24609);
    assign(test_msg_.obs[3].prn, 22);

    assign(test_msg_.obs[4].L.f, 45);
    assign(test_msg_.obs[4].L.i, -36952);
    assign(test_msg_.obs[4].P, 1985368870);
    assign(test_msg_.obs[4].cn0, 56);
    assign(test_msg_.obs[4].lock, 22736);
    assign(test_msg_.obs[4].prn, 30);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepA, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_a, sizeof(msg->obs_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_a, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0xaf01;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 72;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_a_t &lesser,
                        const sbp_msg_obs_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepA, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepA, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepA, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_a_t test_msg_{};
  uint8_t encoded_frame_[72 + 8] = {
      85,  69,  0,   195, 4,   72,  40,  163, 68,  24,  46,  7,   16,  132,
      107, 217, 121, 14,  148, 255, 255, 1,   44,  175, 147, 0,   129, 66,
      200, 125, 148, 29,  254, 255, 153, 41,  14,  177, 3,   128, 178, 248,
      136, 143, 66,  254, 255, 222, 18,  184, 133, 13,  158, 53,  178, 134,
      42,  27,  2,   0,   237, 30,  33,  96,  22,  38,  83,  86,  118, 168,
      111, 255, 255, 45,  56,  208, 88,  30,  1,   175,
  };
  uint8_t encoded_payload_[72] = {
      40, 163, 68,  24,  46,  7,   16,  132, 107, 217, 121, 14,  148, 255, 255,
      1,  44,  175, 147, 0,   129, 66,  200, 125, 148, 29,  254, 255, 153, 41,
      14, 177, 3,   128, 178, 248, 136, 143, 66,  254, 255, 222, 18,  184, 133,
      13, 158, 53,  178, 134, 42,  27,  2,   0,   237, 30,  33,  96,  22,  38,
      83, 86,  118, 168, 111, 255, 255, 45,  56,  208, 88,  30,
  };
};

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_a_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[72];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 72);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 72), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepA,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 72);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 72), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[72];

  EXPECT_EQ(
      sbp_msg_obs_dep_a_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 72), 0);
}
TEST_F(Testauto_check_sbp_observation_msgObsDepA5, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[72];

  for (uint8_t i = 0; i < 72; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 72);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 72);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_msgObsDepA5, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_a_t t{};
      return sbp_msg_obs_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_a_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_a_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA5,
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_a_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].prn, greater.obs[0].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].prn, greater.obs[1].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].prn, greater.obs[2].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.f, greater.obs[3].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.i, greater.obs[3].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].P, greater.obs[3].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].cn0, greater.obs[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].lock, greater.obs[3].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].prn, greater.obs[3].prn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.f, greater.obs[4].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.i, greater.obs[4].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].P, greater.obs[4].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].cn0, greater.obs[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].lock, greater.obs[4].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_a_t lesser = info.test_msg;
    sbp_msg_obs_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].prn, greater.obs[4].prn);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::id, SbpMsgObsDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::name, "MSG_OBS_DEP_A");
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_a_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[72];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 72);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 72), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 72);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5,
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

TEST_F(Testauto_check_sbp_observation_msgObsDepA5,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepA, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgObsDepA5,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepA, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace