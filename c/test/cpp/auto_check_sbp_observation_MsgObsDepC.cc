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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgObsDepC.yaml by generate.py.
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
class Testauto_check_sbp_observation_MsgObsDepC0 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgObsDepC0() {
    assign(test_msg_.header.n_obs, 32);
    assign(test_msg_.header.t.tow, 414670600);
    assign(test_msg_.header.t.wn, 1898);
    assign(test_msg_.n_obs, 5);

    assign(test_msg_.obs[0].L.f, 231);
    assign(test_msg_.obs[0].L.i, -565647);
    assign(test_msg_.obs[0].P, 1347025534);
    assign(test_msg_.obs[0].cn0, 163);
    assign(test_msg_.obs[0].lock, 58853);
    assign(test_msg_.obs[0].sid.code, 0);
    assign(test_msg_.obs[0].sid.reserved, 0);
    assign(test_msg_.obs[0].sid.sat, 4);

    assign(test_msg_.obs[1].L.f, 196);
    assign(test_msg_.obs[1].L.i, -355503);
    assign(test_msg_.obs[1].P, 1180752956);
    assign(test_msg_.obs[1].cn0, 208);
    assign(test_msg_.obs[1].lock, 7188);
    assign(test_msg_.obs[1].sid.code, 0);
    assign(test_msg_.obs[1].sid.reserved, 0);
    assign(test_msg_.obs[1].sid.sat, 6);

    assign(test_msg_.obs[2].L.f, 110);
    assign(test_msg_.obs[2].L.i, -902116);
    assign(test_msg_.obs[2].P, 1295924728);
    assign(test_msg_.obs[2].cn0, 171);
    assign(test_msg_.obs[2].lock, 45748);
    assign(test_msg_.obs[2].sid.code, 0);
    assign(test_msg_.obs[2].sid.reserved, 0);
    assign(test_msg_.obs[2].sid.sat, 7);

    assign(test_msg_.obs[3].L.f, 41);
    assign(test_msg_.obs[3].L.i, 861612);
    assign(test_msg_.obs[3].P, 1304319213);
    assign(test_msg_.obs[3].cn0, 170);
    assign(test_msg_.obs[3].lock, 42217);
    assign(test_msg_.obs[3].sid.code, 0);
    assign(test_msg_.obs[3].sid.reserved, 0);
    assign(test_msg_.obs[3].sid.sat, 10);

    assign(test_msg_.obs[4].L.f, 19);
    assign(test_msg_.obs[4].L.i, 1424624);
    assign(test_msg_.obs[4].P, 1258902820);
    assign(test_msg_.obs[4].cn0, 182);
    assign(test_msg_.obs[4].lock, 53700);
    assign(test_msg_.obs[4].sid.code, 0);
    assign(test_msg_.obs[4].sid.reserved, 0);
    assign(test_msg_.obs[4].sid.sat, 12);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_c_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_c_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_c_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_c_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepC, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_c_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepC);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_c, sizeof(msg->obs_dep_c));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_c_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_c, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepC);
    info.sender_id = 38982;
    info.preamble = 0x55;
    info.crc = 0xafbe;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 87;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_c_t &lesser,
                        const sbp_msg_obs_dep_c_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_c_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_c_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_c_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_c_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepC, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepC, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepC, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepC, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_c_t test_msg_{};
  uint8_t encoded_frame_[87 + 8] = {
      85, 73,  0,   70,  152, 87,  8,   95,  183, 24, 106, 7, 32, 126, 250, 73,
      80, 113, 94,  247, 255, 231, 163, 229, 229, 4,  0,   0, 0,  60,  220, 96,
      70, 81,  147, 250, 255, 196, 208, 20,  28,  6,  0,   0, 0,  248, 61,  62,
      77, 28,  60,  242, 255, 110, 171, 180, 178, 7,  0,   0, 0,  237, 84,  190,
      77, 172, 37,  13,  0,   41,  170, 233, 164, 10, 0,   0, 0,  36,  85,  9,
      75, 240, 188, 21,  0,   19,  182, 196, 209, 12, 0,   0, 0,  190, 175,
  };
  uint8_t encoded_payload_[87] = {
      8,   95,  183, 24,  106, 7,   32,  126, 250, 73,  80,  113, 94,  247, 255,
      231, 163, 229, 229, 4,   0,   0,   0,   60,  220, 96,  70,  81,  147, 250,
      255, 196, 208, 20,  28,  6,   0,   0,   0,   248, 61,  62,  77,  28,  60,
      242, 255, 110, 171, 180, 178, 7,   0,   0,   0,   237, 84,  190, 77,  172,
      37,  13,  0,   41,  170, 233, 164, 10,  0,   0,   0,   36,  85,  9,   75,
      240, 188, 21,  0,   19,  182, 196, 209, 12,  0,   0,   0,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_c_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepC, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[87];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_c_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 87);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 87), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepC,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 87);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 87), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[87];

  EXPECT_EQ(
      sbp_msg_obs_dep_c_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 87), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[87];

  for (uint8_t i = 0; i < 87; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_c_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 87);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepC, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 87);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_c_t t{};
      return sbp_msg_obs_dep_c_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_c_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_c_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_c_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.code, greater.obs[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.reserved,
                        greater.obs[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.sat, greater.obs[0].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.code, greater.obs[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.reserved,
                        greater.obs[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.sat, greater.obs[1].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.code, greater.obs[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.reserved,
                        greater.obs[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.sat, greater.obs[2].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.f, greater.obs[3].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.i, greater.obs[3].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].P, greater.obs[3].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].cn0, greater.obs[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].lock, greater.obs[3].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.code, greater.obs[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.reserved,
                        greater.obs[3].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.sat, greater.obs[3].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.f, greater.obs[4].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.i, greater.obs[4].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].P, greater.obs[4].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].cn0, greater.obs[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].lock, greater.obs[4].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.code, greater.obs[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.reserved,
                        greater.obs[4].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.sat, greater.obs[4].sid.sat);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::id, SbpMsgObsDepC);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::name, "MSG_OBS_DEP_C");
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_c_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_c_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_c, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_c, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[87];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 87);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 87), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 87);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepC, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepC, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_MsgObsDepC1 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgObsDepC1() {
    assign(test_msg_.header.n_obs, 33);
    assign(test_msg_.header.t.tow, 414670600);
    assign(test_msg_.header.t.wn, 1898);
    assign(test_msg_.n_obs, 3);

    assign(test_msg_.obs[0].L.f, 101);
    assign(test_msg_.obs[0].L.i, 1631930);
    assign(test_msg_.obs[0].P, 1296803396);
    assign(test_msg_.obs[0].cn0, 186);
    assign(test_msg_.obs[0].lock, 26274);
    assign(test_msg_.obs[0].sid.code, 0);
    assign(test_msg_.obs[0].sid.reserved, 0);
    assign(test_msg_.obs[0].sid.sat, 16);

    assign(test_msg_.obs[1].L.f, 26);
    assign(test_msg_.obs[1].L.i, 368202);
    assign(test_msg_.obs[1].P, 1167851351);
    assign(test_msg_.obs[1].cn0, 190);
    assign(test_msg_.obs[1].lock, 7886);
    assign(test_msg_.obs[1].sid.code, 0);
    assign(test_msg_.obs[1].sid.reserved, 0);
    assign(test_msg_.obs[1].sid.sat, 27);

    assign(test_msg_.obs[2].L.f, 114);
    assign(test_msg_.obs[2].L.i, 202266);
    assign(test_msg_.obs[2].P, 1149000000);
    assign(test_msg_.obs[2].cn0, 217);
    assign(test_msg_.obs[2].lock, 18913);
    assign(test_msg_.obs[2].sid.code, 0);
    assign(test_msg_.obs[2].sid.reserved, 0);
    assign(test_msg_.obs[2].sid.sat, 29);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_c_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_c_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_c_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_c_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepC, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_c_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepC);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_c, sizeof(msg->obs_dep_c));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_c_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_c, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepC);
    info.sender_id = 38982;
    info.preamble = 0x55;
    info.crc = 0xb325;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 55;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_c_t &lesser,
                        const sbp_msg_obs_dep_c_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_c_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_c_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_c_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_c_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepC, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepC, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepC, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepC, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_c_t test_msg_{};
  uint8_t encoded_frame_[55 + 8] = {
      85, 73,  0,   70, 152, 55,  8,   95,  183, 24, 106, 7, 33, 68, 166, 75,
      77, 186, 230, 24, 0,   101, 186, 162, 102, 16, 0,   0, 0,  87, 255, 155,
      69, 74,  158, 5,  0,   26,  190, 206, 30,  27, 0,   0, 0,  64, 89,  124,
      68, 26,  22,  3,  0,   114, 217, 225, 73,  29, 0,   0, 0,  37, 179,
  };
  uint8_t encoded_payload_[55] = {
      8,   95,  183, 24,  106, 7,   33,  68,  166, 75, 77,  186, 230, 24,
      0,   101, 186, 162, 102, 16,  0,   0,   0,   87, 255, 155, 69,  74,
      158, 5,   0,   26,  190, 206, 30,  27,  0,   0,  0,   64,  89,  124,
      68,  26,  22,  3,   0,   114, 217, 225, 73,  29, 0,   0,   0,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_c_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepC, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_c_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepC,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  EXPECT_EQ(
      sbp_msg_obs_dep_c_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  for (uint8_t i = 0; i < 55; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_c_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepC, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_c_t t{};
      return sbp_msg_obs_dep_c_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_c_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_c_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_c_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.code, greater.obs[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.reserved,
                        greater.obs[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.sat, greater.obs[0].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.code, greater.obs[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.reserved,
                        greater.obs[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.sat, greater.obs[1].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.code, greater.obs[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.reserved,
                        greater.obs[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.sat, greater.obs[2].sid.sat);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::id, SbpMsgObsDepC);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::name, "MSG_OBS_DEP_C");
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_c_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_c_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_c, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_c, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepC, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC1,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepC, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_MsgObsDepC2 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgObsDepC2() {
    assign(test_msg_.header.n_obs, 32);
    assign(test_msg_.header.t.tow, 414670600);
    assign(test_msg_.header.t.wn, 1898);
    assign(test_msg_.n_obs, 5);

    assign(test_msg_.obs[0].L.f, 30);
    assign(test_msg_.obs[0].L.i, -505847);
    assign(test_msg_.obs[0].P, 1347025881);
    assign(test_msg_.obs[0].cn0, 168);
    assign(test_msg_.obs[0].lock, 20849);
    assign(test_msg_.obs[0].sid.code, 0);
    assign(test_msg_.obs[0].sid.reserved, 0);
    assign(test_msg_.obs[0].sid.sat, 4);

    assign(test_msg_.obs[1].L.f, 115);
    assign(test_msg_.obs[1].L.i, -300090);
    assign(test_msg_.obs[1].P, 1180753107);
    assign(test_msg_.obs[1].cn0, 195);
    assign(test_msg_.obs[1].lock, 36917);
    assign(test_msg_.obs[1].sid.code, 0);
    assign(test_msg_.obs[1].sid.reserved, 0);
    assign(test_msg_.obs[1].sid.sat, 6);

    assign(test_msg_.obs[2].L.f, 130);
    assign(test_msg_.obs[2].L.i, -810712);
    assign(test_msg_.obs[2].P, 1295924557);
    assign(test_msg_.obs[2].cn0, 176);
    assign(test_msg_.obs[2].lock, 36445);
    assign(test_msg_.obs[2].sid.code, 0);
    assign(test_msg_.obs[2].sid.reserved, 0);
    assign(test_msg_.obs[2].sid.sat, 7);

    assign(test_msg_.obs[3].L.f, 116);
    assign(test_msg_.obs[3].L.i, 806232);
    assign(test_msg_.obs[3].P, 1304319489);
    assign(test_msg_.obs[3].cn0, 199);
    assign(test_msg_.obs[3].lock, 54757);
    assign(test_msg_.obs[3].sid.code, 0);
    assign(test_msg_.obs[3].sid.reserved, 0);
    assign(test_msg_.obs[3].sid.sat, 10);

    assign(test_msg_.obs[4].L.f, 120);
    assign(test_msg_.obs[4].L.i, 1346368);
    assign(test_msg_.obs[4].P, 1258902877);
    assign(test_msg_.obs[4].cn0, 177);
    assign(test_msg_.obs[4].lock, 49860);
    assign(test_msg_.obs[4].sid.code, 0);
    assign(test_msg_.obs[4].sid.reserved, 0);
    assign(test_msg_.obs[4].sid.sat, 12);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_c_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_c_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_c_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_c_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepC, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_c_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepC);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_c, sizeof(msg->obs_dep_c));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_c_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_c, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepC);
    info.sender_id = 0;
    info.preamble = 0x55;
    info.crc = 0xa18d;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 87;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_c_t &lesser,
                        const sbp_msg_obs_dep_c_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_c_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_c_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_c_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_c_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepC, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepC, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepC, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepC, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_c_t test_msg_{};
  uint8_t encoded_frame_[87 + 8] = {
      85, 73,  0,   0,   0,   87,  8,   95,  183, 24, 106, 7, 32, 217, 251, 73,
      80, 9,   72,  248, 255, 30,  168, 113, 81,  4,  0,   0, 0,  211, 220, 96,
      70, 198, 107, 251, 255, 115, 195, 53,  144, 6,  0,   0, 0,  77,  61,  62,
      77, 40,  161, 243, 255, 130, 176, 93,  142, 7,  0,   0, 0,  1,   86,  190,
      77, 88,  77,  12,  0,   116, 199, 229, 213, 10, 0,   0, 0,  93,  85,  9,
      75, 64,  139, 20,  0,   120, 177, 196, 194, 12, 0,   0, 0,  141, 161,
  };
  uint8_t encoded_payload_[87] = {
      8,   95,  183, 24,  106, 7,   32,  217, 251, 73,  80, 9,  72,  248, 255,
      30,  168, 113, 81,  4,   0,   0,   0,   211, 220, 96, 70, 198, 107, 251,
      255, 115, 195, 53,  144, 6,   0,   0,   0,   77,  61, 62, 77,  40,  161,
      243, 255, 130, 176, 93,  142, 7,   0,   0,   0,   1,  86, 190, 77,  88,
      77,  12,  0,   116, 199, 229, 213, 10,  0,   0,   0,  93, 85,  9,   75,
      64,  139, 20,  0,   120, 177, 196, 194, 12,  0,   0,  0,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_c_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepC, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[87];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_c_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 87);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 87), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepC,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 87);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 87), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[87];

  EXPECT_EQ(
      sbp_msg_obs_dep_c_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 87), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[87];

  for (uint8_t i = 0; i < 87; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_c_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 87);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepC, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 87);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_c_t t{};
      return sbp_msg_obs_dep_c_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_c_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_c_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_c_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.code, greater.obs[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.reserved,
                        greater.obs[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.sat, greater.obs[0].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.code, greater.obs[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.reserved,
                        greater.obs[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.sat, greater.obs[1].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.code, greater.obs[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.reserved,
                        greater.obs[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.sat, greater.obs[2].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.f, greater.obs[3].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.i, greater.obs[3].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].P, greater.obs[3].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].cn0, greater.obs[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].lock, greater.obs[3].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.code, greater.obs[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.reserved,
                        greater.obs[3].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.sat, greater.obs[3].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.f, greater.obs[4].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.i, greater.obs[4].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].P, greater.obs[4].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].cn0, greater.obs[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].lock, greater.obs[4].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.code, greater.obs[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.reserved,
                        greater.obs[4].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.sat, greater.obs[4].sid.sat);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::id, SbpMsgObsDepC);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::name, "MSG_OBS_DEP_C");
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_c_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_c_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_c, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_c, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[87];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 87);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 87), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 87);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepC, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC2,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepC, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_MsgObsDepC3 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgObsDepC3() {
    assign(test_msg_.header.n_obs, 33);
    assign(test_msg_.header.t.tow, 414670600);
    assign(test_msg_.header.t.wn, 1898);
    assign(test_msg_.n_obs, 3);

    assign(test_msg_.obs[0].L.f, 90);
    assign(test_msg_.obs[0].L.i, 1542284);
    assign(test_msg_.obs[0].P, 1296803654);
    assign(test_msg_.obs[0].cn0, 187);
    assign(test_msg_.obs[0].lock, 33182);
    assign(test_msg_.obs[0].sid.code, 0);
    assign(test_msg_.obs[0].sid.reserved, 0);
    assign(test_msg_.obs[0].sid.sat, 16);

    assign(test_msg_.obs[1].L.f, 17);
    assign(test_msg_.obs[1].L.i, 372525);
    assign(test_msg_.obs[1].P, 1167851496);
    assign(test_msg_.obs[1].cn0, 208);
    assign(test_msg_.obs[1].lock, 14511);
    assign(test_msg_.obs[1].sid.code, 0);
    assign(test_msg_.obs[1].sid.reserved, 0);
    assign(test_msg_.obs[1].sid.sat, 27);

    assign(test_msg_.obs[2].L.f, 75);
    assign(test_msg_.obs[2].L.i, 221229);
    assign(test_msg_.obs[2].P, 1149000000);
    assign(test_msg_.obs[2].cn0, 185);
    assign(test_msg_.obs[2].lock, 52809);
    assign(test_msg_.obs[2].sid.code, 0);
    assign(test_msg_.obs[2].sid.reserved, 0);
    assign(test_msg_.obs[2].sid.sat, 29);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_c_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_c_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_c_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_c_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepC, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_c_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepC);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_c, sizeof(msg->obs_dep_c));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_c_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_c, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepC);
    info.sender_id = 0;
    info.preamble = 0x55;
    info.crc = 0x9edc;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 55;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_c_t &lesser,
                        const sbp_msg_obs_dep_c_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_c_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_c_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_c_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_c_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepC, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepC, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepC, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepC, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_c_t test_msg_{};
  uint8_t encoded_frame_[55 + 8] = {
      85, 73,  0,   0,  0, 55, 8,   95,  183, 24, 106, 7, 33, 70,  167, 75,
      77, 140, 136, 23, 0, 90, 187, 158, 129, 16, 0,   0, 0,  232, 255, 155,
      69, 45,  175, 5,  0, 17, 208, 175, 56,  27, 0,   0, 0,  64,  89,  124,
      68, 45,  96,  3,  0, 75, 185, 73,  206, 29, 0,   0, 0,  220, 158,
  };
  uint8_t encoded_payload_[55] = {
      8,   95, 183, 24,  106, 7,   33,  70, 167, 75,  77,  140, 136, 23,
      0,   90, 187, 158, 129, 16,  0,   0,  0,   232, 255, 155, 69,  45,
      175, 5,  0,   17,  208, 175, 56,  27, 0,   0,   0,   64,  89,  124,
      68,  45, 96,  3,   0,   75,  185, 73, 206, 29,  0,   0,   0,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_c_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepC, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_c_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepC,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  EXPECT_EQ(
      sbp_msg_obs_dep_c_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  for (uint8_t i = 0; i < 55; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_c_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepC, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_c_t t{};
      return sbp_msg_obs_dep_c_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_c_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_c_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_c_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.code, greater.obs[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.reserved,
                        greater.obs[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.sat, greater.obs[0].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.code, greater.obs[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.reserved,
                        greater.obs[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.sat, greater.obs[1].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.code, greater.obs[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.reserved,
                        greater.obs[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.sat, greater.obs[2].sid.sat);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::id, SbpMsgObsDepC);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::name, "MSG_OBS_DEP_C");
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_c_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_c_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_c, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_c, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepC, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC3,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepC, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_MsgObsDepC4 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgObsDepC4() {
    assign(test_msg_.header.n_obs, 32);
    assign(test_msg_.header.t.tow, 414670800);
    assign(test_msg_.header.t.wn, 1898);
    assign(test_msg_.n_obs, 5);

    assign(test_msg_.obs[0].L.f, 57);
    assign(test_msg_.obs[0].L.i, -565930);
    assign(test_msg_.obs[0].P, 1347029036);
    assign(test_msg_.obs[0].cn0, 158);
    assign(test_msg_.obs[0].lock, 58853);
    assign(test_msg_.obs[0].sid.code, 0);
    assign(test_msg_.obs[0].sid.reserved, 0);
    assign(test_msg_.obs[0].sid.sat, 4);

    assign(test_msg_.obs[1].L.f, 221);
    assign(test_msg_.obs[1].L.i, -355684);
    assign(test_msg_.obs[1].P, 1180755424);
    assign(test_msg_.obs[1].cn0, 200);
    assign(test_msg_.obs[1].lock, 7188);
    assign(test_msg_.obs[1].sid.code, 0);
    assign(test_msg_.obs[1].sid.reserved, 0);
    assign(test_msg_.obs[1].sid.sat, 6);

    assign(test_msg_.obs[2].L.f, 39);
    assign(test_msg_.obs[2].L.i, -902563);
    assign(test_msg_.obs[2].P, 1295929916);
    assign(test_msg_.obs[2].cn0, 164);
    assign(test_msg_.obs[2].lock, 45748);
    assign(test_msg_.obs[2].sid.code, 0);
    assign(test_msg_.obs[2].sid.reserved, 0);
    assign(test_msg_.obs[2].sid.sat, 7);

    assign(test_msg_.obs[3].L.f, 202);
    assign(test_msg_.obs[3].L.i, 861998);
    assign(test_msg_.obs[3].P, 1304316382);
    assign(test_msg_.obs[3].cn0, 181);
    assign(test_msg_.obs[3].lock, 42217);
    assign(test_msg_.obs[3].sid.code, 0);
    assign(test_msg_.obs[3].sid.reserved, 0);
    assign(test_msg_.obs[3].sid.sat, 10);

    assign(test_msg_.obs[4].L.f, 249);
    assign(test_msg_.obs[4].L.i, 1425266);
    assign(test_msg_.obs[4].P, 1258897557);
    assign(test_msg_.obs[4].cn0, 182);
    assign(test_msg_.obs[4].lock, 53700);
    assign(test_msg_.obs[4].sid.code, 0);
    assign(test_msg_.obs[4].sid.reserved, 0);
    assign(test_msg_.obs[4].sid.sat, 12);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_c_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_c_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_c_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_c_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepC, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_c_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepC);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_c, sizeof(msg->obs_dep_c));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_c_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_c, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepC);
    info.sender_id = 38982;
    info.preamble = 0x55;
    info.crc = 0x870;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 87;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_c_t &lesser,
                        const sbp_msg_obs_dep_c_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_c_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_c_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_c_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_c_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepC, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepC, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepC, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepC, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_c_t test_msg_{};
  uint8_t encoded_frame_[87 + 8] = {
      85, 73,  0,   70,  152, 87,  208, 95,  183, 24, 106, 7, 32, 44,  8,   74,
      80, 86,  93,  247, 255, 57,  158, 229, 229, 4,  0,   0, 0,  224, 229, 96,
      70, 156, 146, 250, 255, 221, 200, 20,  28,  6,  0,   0, 0,  60,  82,  62,
      77, 93,  58,  242, 255, 39,  164, 180, 178, 7,  0,   0, 0,  222, 73,  190,
      77, 46,  39,  13,  0,   202, 181, 233, 164, 10, 0,   0, 0,  149, 64,  9,
      75, 114, 191, 21,  0,   249, 182, 196, 209, 12, 0,   0, 0,  112, 8,
  };
  uint8_t encoded_payload_[87] = {
      208, 95,  183, 24,  106, 7,   32,  44,  8,   74,  80,  86,  93,  247, 255,
      57,  158, 229, 229, 4,   0,   0,   0,   224, 229, 96,  70,  156, 146, 250,
      255, 221, 200, 20,  28,  6,   0,   0,   0,   60,  82,  62,  77,  93,  58,
      242, 255, 39,  164, 180, 178, 7,   0,   0,   0,   222, 73,  190, 77,  46,
      39,  13,  0,   202, 181, 233, 164, 10,  0,   0,   0,   149, 64,  9,   75,
      114, 191, 21,  0,   249, 182, 196, 209, 12,  0,   0,   0,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_c_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepC, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[87];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_c_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 87);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 87), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepC,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 87);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 87), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[87];

  EXPECT_EQ(
      sbp_msg_obs_dep_c_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 87), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[87];

  for (uint8_t i = 0; i < 87; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_c_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 87);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepC, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 87);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_c_t t{};
      return sbp_msg_obs_dep_c_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_c_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_c_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_c_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_c_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepC, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.code, greater.obs[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.reserved,
                        greater.obs[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.sat, greater.obs[0].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.code, greater.obs[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.reserved,
                        greater.obs[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.sat, greater.obs[1].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.code, greater.obs[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.reserved,
                        greater.obs[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.sat, greater.obs[2].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.f, greater.obs[3].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.i, greater.obs[3].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].P, greater.obs[3].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].cn0, greater.obs[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].lock, greater.obs[3].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.code, greater.obs[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.reserved,
                        greater.obs[3].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.sat, greater.obs[3].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.f, greater.obs[4].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.i, greater.obs[4].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].P, greater.obs[4].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].cn0, greater.obs[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].lock, greater.obs[4].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.code, greater.obs[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.reserved,
                        greater.obs[4].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_c_t lesser = info.test_msg;
    sbp_msg_obs_dep_c_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.sat, greater.obs[4].sid.sat);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::id, SbpMsgObsDepC);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::name, "MSG_OBS_DEP_C");
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_c_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_c_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_c, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_c_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_c, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[87];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 87);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 87), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_c_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_c_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 87);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepC, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepC4,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepC, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace
