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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgObsDepB.yaml by generate.py.
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
class Testauto_check_sbp_observation_MsgObsDepB0 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgObsDepB0() {
    assign(test_msg_.header.n_obs, 32);
    assign(test_msg_.header.t.tow, 2567800);
    assign(test_msg_.header.t.wn, 1787);
    assign(test_msg_.n_obs, 6);

    assign(test_msg_.obs[0].L.f, 27);
    assign(test_msg_.obs[0].L.i, 117913055);
    assign(test_msg_.obs[0].P, 2243669940);
    assign(test_msg_.obs[0].cn0, 157);
    assign(test_msg_.obs[0].lock, 0);
    assign(test_msg_.obs[0].sid.code, 0);
    assign(test_msg_.obs[0].sid.reserved, 0);
    assign(test_msg_.obs[0].sid.sat, 202);

    assign(test_msg_.obs[1].L.f, 175);
    assign(test_msg_.obs[1].L.i, 129899608);
    assign(test_msg_.obs[1].P, 2471857210);
    assign(test_msg_.obs[1].cn0, 144);
    assign(test_msg_.obs[1].lock, 0);
    assign(test_msg_.obs[1].sid.code, 0);
    assign(test_msg_.obs[1].sid.reserved, 0);
    assign(test_msg_.obs[1].sid.sat, 203);

    assign(test_msg_.obs[2].L.f, 135);
    assign(test_msg_.obs[2].L.i, 122531024);
    assign(test_msg_.obs[2].P, 2331544796);
    assign(test_msg_.obs[2].cn0, 151);
    assign(test_msg_.obs[2].lock, 0);
    assign(test_msg_.obs[2].sid.code, 0);
    assign(test_msg_.obs[2].sid.reserved, 0);
    assign(test_msg_.obs[2].sid.sat, 208);

    assign(test_msg_.obs[3].L.f, 242);
    assign(test_msg_.obs[3].L.i, 119280243);
    assign(test_msg_.obs[3].P, 2269692589);
    assign(test_msg_.obs[3].cn0, 156);
    assign(test_msg_.obs[3].lock, 0);
    assign(test_msg_.obs[3].sid.code, 0);
    assign(test_msg_.obs[3].sid.reserved, 0);
    assign(test_msg_.obs[3].sid.sat, 212);

    assign(test_msg_.obs[4].L.f, 120);
    assign(test_msg_.obs[4].L.i, 109691922);
    assign(test_msg_.obs[4].P, 2087293092);
    assign(test_msg_.obs[4].cn0, 168);
    assign(test_msg_.obs[4].lock, 0);
    assign(test_msg_.obs[4].sid.code, 0);
    assign(test_msg_.obs[4].sid.reserved, 0);
    assign(test_msg_.obs[4].sid.sat, 217);

    assign(test_msg_.obs[5].L.f, 87);
    assign(test_msg_.obs[5].L.i, 123340754);
    assign(test_msg_.obs[5].P, 2347034654);
    assign(test_msg_.obs[5].cn0, 150);
    assign(test_msg_.obs[5].lock, 0);
    assign(test_msg_.obs[5].sid.code, 0);
    assign(test_msg_.obs[5].sid.reserved, 0);
    assign(test_msg_.obs[5].sid.sat, 218);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepB, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_b, sizeof(msg->obs_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_b, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepB);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0x55a9;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 103;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_b_t &lesser,
                        const sbp_msg_obs_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepB, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepB, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepB, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepB, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_b_t test_msg_{};
  uint8_t encoded_frame_[103 + 8] = {
      85,  67,  0,   246, 215, 103, 120, 46, 39, 0,   251, 6, 32, 180, 175, 187,
      133, 223, 53,  7,   7,   27,  157, 0,  0,  202, 0,   0, 0,  58,  140, 85,
      147, 88,  28,  190, 7,   175, 144, 0,  0,  203, 0,   0, 0,  220, 140, 248,
      138, 208, 172, 77,  7,   135, 151, 0,  0,  208, 0,   0, 0,  173, 194, 72,
      135, 115, 18,  28,  7,   242, 156, 0,  0,  212, 0,   0, 0,  164, 144, 105,
      124, 18,  196, 137, 6,   120, 168, 0,  0,  217, 0,   0, 0,  30,  232, 228,
      139, 210, 7,   90,  7,   87,  150, 0,  0,  218, 0,   0, 0,  169, 85,
  };
  uint8_t encoded_payload_[103] = {
      120, 46,  39,  0,   251, 6,   32,  180, 175, 187, 133, 223, 53,  7,   7,
      27,  157, 0,   0,   202, 0,   0,   0,   58,  140, 85,  147, 88,  28,  190,
      7,   175, 144, 0,   0,   203, 0,   0,   0,   220, 140, 248, 138, 208, 172,
      77,  7,   135, 151, 0,   0,   208, 0,   0,   0,   173, 194, 72,  135, 115,
      18,  28,  7,   242, 156, 0,   0,   212, 0,   0,   0,   164, 144, 105, 124,
      18,  196, 137, 6,   120, 168, 0,   0,   217, 0,   0,   0,   30,  232, 228,
      139, 210, 7,   90,  7,   87,  150, 0,   0,   218, 0,   0,   0,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_b_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepB, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[103];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_b_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 103);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 103), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepB,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 103);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 103), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[103];

  EXPECT_EQ(
      sbp_msg_obs_dep_b_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 103), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[103];

  for (uint8_t i = 0; i < 103; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_b_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 103);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 103);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_b_t t{};
      return sbp_msg_obs_dep_b_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_b_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_b_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_b_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.code, greater.obs[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.reserved,
                        greater.obs[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.sat, greater.obs[0].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.code, greater.obs[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.reserved,
                        greater.obs[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.sat, greater.obs[1].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.code, greater.obs[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.reserved,
                        greater.obs[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.sat, greater.obs[2].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.f, greater.obs[3].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.i, greater.obs[3].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].P, greater.obs[3].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].cn0, greater.obs[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].lock, greater.obs[3].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.code, greater.obs[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.reserved,
                        greater.obs[3].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.sat, greater.obs[3].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.f, greater.obs[4].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.i, greater.obs[4].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].P, greater.obs[4].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].cn0, greater.obs[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].lock, greater.obs[4].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.code, greater.obs[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.reserved,
                        greater.obs[4].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.sat, greater.obs[4].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].L.f, greater.obs[5].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].L.i, greater.obs[5].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].P, greater.obs[5].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].cn0, greater.obs[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].lock, greater.obs[5].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].sid.code, greater.obs[5].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].sid.reserved,
                        greater.obs[5].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].sid.sat, greater.obs[5].sid.sat);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::id, SbpMsgObsDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::name, "MSG_OBS_DEP_B");
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[103];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 103);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 103), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 103);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepB, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepB, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_MsgObsDepB1 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgObsDepB1() {
    assign(test_msg_.header.n_obs, 33);
    assign(test_msg_.header.t.tow, 2567800);
    assign(test_msg_.header.t.wn, 1787);
    assign(test_msg_.n_obs, 3);

    assign(test_msg_.obs[0].L.f, 219);
    assign(test_msg_.obs[0].L.i, 120256389);
    assign(test_msg_.obs[0].P, 2288371524);
    assign(test_msg_.obs[0].cn0, 154);
    assign(test_msg_.obs[0].lock, 0);
    assign(test_msg_.obs[0].sid.code, 0);
    assign(test_msg_.obs[0].sid.reserved, 0);
    assign(test_msg_.obs[0].sid.sat, 220);

    assign(test_msg_.obs[1].L.f, 235);
    assign(test_msg_.obs[1].L.i, 117692256);
    assign(test_msg_.obs[1].P, 2239434459);
    assign(test_msg_.obs[1].cn0, 156);
    assign(test_msg_.obs[1].lock, 0);
    assign(test_msg_.obs[1].sid.code, 0);
    assign(test_msg_.obs[1].sid.reserved, 0);
    assign(test_msg_.obs[1].sid.sat, 222);

    assign(test_msg_.obs[2].L.f, 174);
    assign(test_msg_.obs[2].L.i, 107851013);
    assign(test_msg_.obs[2].P, 2052171351);
    assign(test_msg_.obs[2].cn0, 170);
    assign(test_msg_.obs[2].lock, 0);
    assign(test_msg_.obs[2].sid.code, 0);
    assign(test_msg_.obs[2].sid.reserved, 0);
    assign(test_msg_.obs[2].sid.sat, 225);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepB, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_b, sizeof(msg->obs_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_b, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepB);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0xe90b;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 55;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_b_t &lesser,
                        const sbp_msg_obs_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepB, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepB, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepB, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepB, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_b_t test_msg_{};
  uint8_t encoded_frame_[55 + 8] = {
      85,  67,  0,   246, 215, 55,  120, 46, 39, 0,   251, 6, 33, 68,  199, 101,
      136, 133, 247, 42,  7,   219, 154, 0,  0,  220, 0,   0, 0,  219, 14,  123,
      133, 96,  215, 3,   7,   235, 156, 0,  0,  222, 0,   0, 0,  87,  166, 81,
      122, 5,   173, 109, 6,   174, 170, 0,  0,  225, 0,   0, 0,  11,  233,
  };
  uint8_t encoded_payload_[55] = {
      120, 46,  39,  0,   251, 6,   33,  68,  199, 101, 136, 133, 247, 42,
      7,   219, 154, 0,   0,   220, 0,   0,   0,   219, 14,  123, 133, 96,
      215, 3,   7,   235, 156, 0,   0,   222, 0,   0,   0,   87,  166, 81,
      122, 5,   173, 109, 6,   174, 170, 0,   0,   225, 0,   0,   0,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_b_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepB, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_b_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepB,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  EXPECT_EQ(
      sbp_msg_obs_dep_b_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  for (uint8_t i = 0; i < 55; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_b_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_b_t t{};
      return sbp_msg_obs_dep_b_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_b_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_b_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_b_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.code, greater.obs[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.reserved,
                        greater.obs[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.sat, greater.obs[0].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.code, greater.obs[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.reserved,
                        greater.obs[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.sat, greater.obs[1].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.code, greater.obs[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.reserved,
                        greater.obs[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.sat, greater.obs[2].sid.sat);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::id, SbpMsgObsDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::name, "MSG_OBS_DEP_B");
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepB, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB1,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepB, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_MsgObsDepB2 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgObsDepB2() {
    assign(test_msg_.header.n_obs, 32);
    assign(test_msg_.header.t.tow, 2568000);
    assign(test_msg_.header.t.wn, 1787);
    assign(test_msg_.n_obs, 6);

    assign(test_msg_.obs[0].L.f, 94);
    assign(test_msg_.obs[0].L.i, 117912556);
    assign(test_msg_.obs[0].P, 2243658852);
    assign(test_msg_.obs[0].cn0, 156);
    assign(test_msg_.obs[0].lock, 0);
    assign(test_msg_.obs[0].sid.code, 0);
    assign(test_msg_.obs[0].sid.reserved, 0);
    assign(test_msg_.obs[0].sid.sat, 202);

    assign(test_msg_.obs[1].L.f, 40);
    assign(test_msg_.obs[1].L.i, 129900210);
    assign(test_msg_.obs[1].P, 2471868513);
    assign(test_msg_.obs[1].cn0, 140);
    assign(test_msg_.obs[1].lock, 0);
    assign(test_msg_.obs[1].sid.code, 0);
    assign(test_msg_.obs[1].sid.reserved, 0);
    assign(test_msg_.obs[1].sid.sat, 203);

    assign(test_msg_.obs[2].L.f, 2);
    assign(test_msg_.obs[2].L.i, 122530650);
    assign(test_msg_.obs[2].P, 2331537287);
    assign(test_msg_.obs[2].cn0, 150);
    assign(test_msg_.obs[2].lock, 0);
    assign(test_msg_.obs[2].sid.code, 0);
    assign(test_msg_.obs[2].sid.reserved, 0);
    assign(test_msg_.obs[2].sid.sat, 208);

    assign(test_msg_.obs[3].L.f, 241);
    assign(test_msg_.obs[3].L.i, 119280830);
    assign(test_msg_.obs[3].P, 2269703860);
    assign(test_msg_.obs[3].cn0, 155);
    assign(test_msg_.obs[3].lock, 0);
    assign(test_msg_.obs[3].sid.code, 0);
    assign(test_msg_.obs[3].sid.reserved, 0);
    assign(test_msg_.obs[3].sid.sat, 212);

    assign(test_msg_.obs[4].L.f, 153);
    assign(test_msg_.obs[4].L.i, 109691996);
    assign(test_msg_.obs[4].P, 2087295247);
    assign(test_msg_.obs[4].cn0, 168);
    assign(test_msg_.obs[4].lock, 0);
    assign(test_msg_.obs[4].sid.code, 0);
    assign(test_msg_.obs[4].sid.reserved, 0);
    assign(test_msg_.obs[4].sid.sat, 217);

    assign(test_msg_.obs[5].L.f, 41);
    assign(test_msg_.obs[5].L.i, 123340176);
    assign(test_msg_.obs[5].P, 2347022641);
    assign(test_msg_.obs[5].cn0, 150);
    assign(test_msg_.obs[5].lock, 0);
    assign(test_msg_.obs[5].sid.code, 0);
    assign(test_msg_.obs[5].sid.reserved, 0);
    assign(test_msg_.obs[5].sid.sat, 218);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepB, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_b, sizeof(msg->obs_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_b, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepB);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0x62f1;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 103;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_b_t &lesser,
                        const sbp_msg_obs_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepB, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepB, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepB, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepB, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_b_t test_msg_{};
  uint8_t encoded_frame_[103 + 8] = {
      85,  67,  0,   246, 215, 103, 64,  47, 39, 0,   251, 6, 32, 100, 132, 187,
      133, 236, 51,  7,   7,   94,  156, 0,  0,  202, 0,   0, 0,  97,  184, 85,
      147, 178, 30,  190, 7,   40,  140, 0,  0,  203, 0,   0, 0,  135, 111, 248,
      138, 90,  171, 77,  7,   2,   150, 0,  0,  208, 0,   0, 0,  180, 238, 72,
      135, 190, 20,  28,  7,   241, 155, 0,  0,  212, 0,   0, 0,  15,  153, 105,
      124, 92,  196, 137, 6,   153, 168, 0,  0,  217, 0,   0, 0,  49,  185, 228,
      139, 144, 5,   90,  7,   41,  150, 0,  0,  218, 0,   0, 0,  241, 98,
  };
  uint8_t encoded_payload_[103] = {
      64,  47,  39,  0,   251, 6,   32,  100, 132, 187, 133, 236, 51,  7,   7,
      94,  156, 0,   0,   202, 0,   0,   0,   97,  184, 85,  147, 178, 30,  190,
      7,   40,  140, 0,   0,   203, 0,   0,   0,   135, 111, 248, 138, 90,  171,
      77,  7,   2,   150, 0,   0,   208, 0,   0,   0,   180, 238, 72,  135, 190,
      20,  28,  7,   241, 155, 0,   0,   212, 0,   0,   0,   15,  153, 105, 124,
      92,  196, 137, 6,   153, 168, 0,   0,   217, 0,   0,   0,   49,  185, 228,
      139, 144, 5,   90,  7,   41,  150, 0,   0,   218, 0,   0,   0,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_b_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepB, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[103];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_b_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 103);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 103), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepB,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 103);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 103), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[103];

  EXPECT_EQ(
      sbp_msg_obs_dep_b_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 103), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[103];

  for (uint8_t i = 0; i < 103; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_b_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 103);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 103);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_b_t t{};
      return sbp_msg_obs_dep_b_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_b_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_b_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_b_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.code, greater.obs[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.reserved,
                        greater.obs[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.sat, greater.obs[0].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.code, greater.obs[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.reserved,
                        greater.obs[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.sat, greater.obs[1].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.code, greater.obs[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.reserved,
                        greater.obs[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.sat, greater.obs[2].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.f, greater.obs[3].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.i, greater.obs[3].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].P, greater.obs[3].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].cn0, greater.obs[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].lock, greater.obs[3].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.code, greater.obs[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.reserved,
                        greater.obs[3].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.sat, greater.obs[3].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.f, greater.obs[4].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.i, greater.obs[4].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].P, greater.obs[4].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].cn0, greater.obs[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].lock, greater.obs[4].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.code, greater.obs[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.reserved,
                        greater.obs[4].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.sat, greater.obs[4].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].L.f, greater.obs[5].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].L.i, greater.obs[5].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].P, greater.obs[5].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].cn0, greater.obs[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].lock, greater.obs[5].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].sid.code, greater.obs[5].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].sid.reserved,
                        greater.obs[5].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].sid.sat, greater.obs[5].sid.sat);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::id, SbpMsgObsDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::name, "MSG_OBS_DEP_B");
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[103];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 103);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 103), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 103);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepB, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB2,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepB, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_MsgObsDepB3 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgObsDepB3() {
    assign(test_msg_.header.n_obs, 33);
    assign(test_msg_.header.t.tow, 2568000);
    assign(test_msg_.header.t.wn, 1787);
    assign(test_msg_.n_obs, 3);

    assign(test_msg_.obs[0].L.f, 20);
    assign(test_msg_.obs[0].L.i, 120255759);
    assign(test_msg_.obs[0].P, 2288358634);
    assign(test_msg_.obs[0].cn0, 154);
    assign(test_msg_.obs[0].lock, 0);
    assign(test_msg_.obs[0].sid.code, 0);
    assign(test_msg_.obs[0].sid.reserved, 0);
    assign(test_msg_.obs[0].sid.sat, 220);

    assign(test_msg_.obs[1].L.f, 38);
    assign(test_msg_.obs[1].L.i, 117691920);
    assign(test_msg_.obs[1].P, 2239428560);
    assign(test_msg_.obs[1].cn0, 156);
    assign(test_msg_.obs[1].lock, 0);
    assign(test_msg_.obs[1].sid.code, 0);
    assign(test_msg_.obs[1].sid.reserved, 0);
    assign(test_msg_.obs[1].sid.sat, 222);

    assign(test_msg_.obs[2].L.f, 7);
    assign(test_msg_.obs[2].L.i, 107850774);
    assign(test_msg_.obs[2].P, 2052167183);
    assign(test_msg_.obs[2].cn0, 172);
    assign(test_msg_.obs[2].lock, 0);
    assign(test_msg_.obs[2].sid.code, 0);
    assign(test_msg_.obs[2].sid.reserved, 0);
    assign(test_msg_.obs[2].sid.sat, 225);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepB, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_b, sizeof(msg->obs_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_b, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepB);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0xdc9;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 55;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_b_t &lesser,
                        const sbp_msg_obs_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepB, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepB, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepB, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepB, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_b_t test_msg_{};
  uint8_t encoded_frame_[55 + 8] = {
      85,  67, 0,   246, 215, 55, 64,  47, 39, 0,   251, 6, 33, 234, 148, 101,
      136, 15, 245, 42,  7,   20, 154, 0,  0,  220, 0,   0, 0,  208, 247, 122,
      133, 16, 214, 3,   7,   38, 156, 0,  0,  222, 0,   0, 0,  15,  150, 81,
      122, 22, 172, 109, 6,   7,  172, 0,  0,  225, 0,   0, 0,  201, 13,
  };
  uint8_t encoded_payload_[55] = {
      64,  47, 39,  0,   251, 6,   33,  234, 148, 101, 136, 15,  245, 42,
      7,   20, 154, 0,   0,   220, 0,   0,   0,   208, 247, 122, 133, 16,
      214, 3,  7,   38,  156, 0,   0,   222, 0,   0,   0,   15,  150, 81,
      122, 22, 172, 109, 6,   7,   172, 0,   0,   225, 0,   0,   0,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_b_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepB, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_b_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepB,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  EXPECT_EQ(
      sbp_msg_obs_dep_b_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  for (uint8_t i = 0; i < 55; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_b_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_b_t t{};
      return sbp_msg_obs_dep_b_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_b_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_b_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_b_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.code, greater.obs[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.reserved,
                        greater.obs[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.sat, greater.obs[0].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.code, greater.obs[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.reserved,
                        greater.obs[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.sat, greater.obs[1].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.code, greater.obs[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.reserved,
                        greater.obs[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.sat, greater.obs[2].sid.sat);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::id, SbpMsgObsDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::name, "MSG_OBS_DEP_B");
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepB, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB3,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepB, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_MsgObsDepB4 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgObsDepB4() {
    assign(test_msg_.header.n_obs, 32);
    assign(test_msg_.header.t.tow, 2568200);
    assign(test_msg_.header.t.wn, 1787);
    assign(test_msg_.n_obs, 6);

    assign(test_msg_.obs[0].L.f, 165);
    assign(test_msg_.obs[0].L.i, 117912057);
    assign(test_msg_.obs[0].P, 2243649790);
    assign(test_msg_.obs[0].cn0, 156);
    assign(test_msg_.obs[0].lock, 0);
    assign(test_msg_.obs[0].sid.code, 0);
    assign(test_msg_.obs[0].sid.reserved, 0);
    assign(test_msg_.obs[0].sid.sat, 202);

    assign(test_msg_.obs[1].L.f, 106);
    assign(test_msg_.obs[1].L.i, 129900811);
    assign(test_msg_.obs[1].P, 2471880049);
    assign(test_msg_.obs[1].cn0, 143);
    assign(test_msg_.obs[1].lock, 0);
    assign(test_msg_.obs[1].sid.code, 0);
    assign(test_msg_.obs[1].sid.reserved, 0);
    assign(test_msg_.obs[1].sid.sat, 203);

    assign(test_msg_.obs[2].L.f, 159);
    assign(test_msg_.obs[2].L.i, 122530275);
    assign(test_msg_.obs[2].P, 2331530678);
    assign(test_msg_.obs[2].cn0, 150);
    assign(test_msg_.obs[2].lock, 0);
    assign(test_msg_.obs[2].sid.code, 0);
    assign(test_msg_.obs[2].sid.reserved, 0);
    assign(test_msg_.obs[2].sid.sat, 208);

    assign(test_msg_.obs[3].L.f, 7);
    assign(test_msg_.obs[3].L.i, 119281418);
    assign(test_msg_.obs[3].P, 2269714449);
    assign(test_msg_.obs[3].cn0, 156);
    assign(test_msg_.obs[3].lock, 0);
    assign(test_msg_.obs[3].sid.code, 0);
    assign(test_msg_.obs[3].sid.reserved, 0);
    assign(test_msg_.obs[3].sid.sat, 212);

    assign(test_msg_.obs[4].L.f, 186);
    assign(test_msg_.obs[4].L.i, 109692070);
    assign(test_msg_.obs[4].P, 2087295852);
    assign(test_msg_.obs[4].cn0, 170);
    assign(test_msg_.obs[4].lock, 0);
    assign(test_msg_.obs[4].sid.code, 0);
    assign(test_msg_.obs[4].sid.reserved, 0);
    assign(test_msg_.obs[4].sid.sat, 217);

    assign(test_msg_.obs[5].L.f, 236);
    assign(test_msg_.obs[5].L.i, 123339597);
    assign(test_msg_.obs[5].P, 2347011798);
    assign(test_msg_.obs[5].cn0, 151);
    assign(test_msg_.obs[5].lock, 0);
    assign(test_msg_.obs[5].sid.code, 0);
    assign(test_msg_.obs[5].sid.reserved, 0);
    assign(test_msg_.obs[5].sid.sat, 218);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_obs_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_obs_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObsDepB, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObsDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs_dep_b, sizeof(msg->obs_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs_dep_b, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObsDepB);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0x763b;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 103;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_dep_b_t &lesser,
                        const sbp_msg_obs_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObsDepB, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgObsDepB, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObsDepB, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObsDepB, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_obs_dep_b_t test_msg_{};
  uint8_t encoded_frame_[103 + 8] = {
      85,  67,  0,   246, 215, 103, 8,   48, 39, 0,   251, 6, 32, 254, 96,  187,
      133, 249, 49,  7,   7,   165, 156, 0,  0,  202, 0,   0, 0,  113, 229, 85,
      147, 11,  33,  190, 7,   106, 143, 0,  0,  203, 0,   0, 0,  182, 85,  248,
      138, 227, 169, 77,  7,   159, 150, 0,  0,  208, 0,   0, 0,  17,  24,  73,
      135, 10,  23,  28,  7,   7,   156, 0,  0,  212, 0,   0, 0,  108, 155, 105,
      124, 166, 196, 137, 6,   186, 170, 0,  0,  217, 0,   0, 0,  214, 142, 228,
      139, 77,  3,   90,  7,   236, 151, 0,  0,  218, 0,   0, 0,  59,  118,
  };
  uint8_t encoded_payload_[103] = {
      8,   48,  39,  0,   251, 6,   32,  254, 96,  187, 133, 249, 49,  7,   7,
      165, 156, 0,   0,   202, 0,   0,   0,   113, 229, 85,  147, 11,  33,  190,
      7,   106, 143, 0,   0,   203, 0,   0,   0,   182, 85,  248, 138, 227, 169,
      77,  7,   159, 150, 0,   0,   208, 0,   0,   0,   17,  24,  73,  135, 10,
      23,  28,  7,   7,   156, 0,   0,   212, 0,   0,   0,   108, 155, 105, 124,
      166, 196, 137, 6,   186, 170, 0,   0,   217, 0,   0,   0,   214, 142, 228,
      139, 77,  3,   90,  7,   236, 151, 0,   0,   218, 0,   0,   0,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_dep_b_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObsDepB, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[103];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_obs_dep_b_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 103);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 103), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObsDepB,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 103);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 103), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[103];

  EXPECT_EQ(
      sbp_msg_obs_dep_b_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 103), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[103];

  for (uint8_t i = 0; i < 103; i++) {
    EXPECT_EQ(sbp_msg_obs_dep_b_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 103);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObsDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 103);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_dep_b_t t{};
      return sbp_msg_obs_dep_b_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_dep_b_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_dep_b_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_obs_dep_b_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_dep_b_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObsDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.code, greater.obs[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.reserved,
                        greater.obs[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.sat, greater.obs[0].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.code, greater.obs[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.reserved,
                        greater.obs[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.sat, greater.obs[1].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.code, greater.obs[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.reserved,
                        greater.obs[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.sat, greater.obs[2].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.f, greater.obs[3].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.i, greater.obs[3].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].P, greater.obs[3].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].cn0, greater.obs[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].lock, greater.obs[3].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.code, greater.obs[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.reserved,
                        greater.obs[3].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.sat, greater.obs[3].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.f, greater.obs[4].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.i, greater.obs[4].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].P, greater.obs[4].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].cn0, greater.obs[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].lock, greater.obs[4].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.code, greater.obs[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.reserved,
                        greater.obs[4].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.sat, greater.obs[4].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].L.f, greater.obs[5].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].L.i, greater.obs[5].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].P, greater.obs[5].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].cn0, greater.obs[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].lock, greater.obs[5].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].sid.code, greater.obs[5].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].sid.reserved,
                        greater.obs[5].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_dep_b_t lesser = info.test_msg;
    sbp_msg_obs_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].sid.sat, greater.obs[5].sid.sat);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::id, SbpMsgObsDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::name, "MSG_OBS_DEP_B");
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_obs_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_dep_b_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[103];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 103);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 103), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 103);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4,
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

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObsDepB, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObsDepB4,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObsDepB, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace