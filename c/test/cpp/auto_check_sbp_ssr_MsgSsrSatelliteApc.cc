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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApc.yaml by generate.py.
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
class Testauto_check_sbp_ssr_MsgSsrSatelliteApc0 : public ::testing::Test {
 public:
  Testauto_check_sbp_ssr_MsgSsrSatelliteApc0() {
    assign(test_msg_.apc[0].pco[0], 1);

    assign(test_msg_.apc[0].pco[1], -1);

    assign(test_msg_.apc[0].pco[2], 729);

    assign(test_msg_.apc[0].pcv[0], 11);

    assign(test_msg_.apc[0].pcv[1], 10);

    assign(test_msg_.apc[0].pcv[2], 8);

    assign(test_msg_.apc[0].pcv[3], 5);

    assign(test_msg_.apc[0].pcv[4], 1);

    assign(test_msg_.apc[0].pcv[5], -4);

    assign(test_msg_.apc[0].pcv[6], -8);

    assign(test_msg_.apc[0].pcv[7], -10);

    assign(test_msg_.apc[0].pcv[8], -10);

    assign(test_msg_.apc[0].pcv[9], -10);

    assign(test_msg_.apc[0].pcv[10], -7);

    assign(test_msg_.apc[0].pcv[11], -4);

    assign(test_msg_.apc[0].pcv[12], 0);

    assign(test_msg_.apc[0].pcv[13], 6);

    assign(test_msg_.apc[0].pcv[14], 12);

    assign(test_msg_.apc[0].pcv[15], 22);

    assign(test_msg_.apc[0].pcv[16], 30);

    assign(test_msg_.apc[0].pcv[17], 41);

    assign(test_msg_.apc[0].pcv[18], 41);

    assign(test_msg_.apc[0].pcv[19], 41);

    assign(test_msg_.apc[0].pcv[20], 41);
    assign(test_msg_.apc[0].sat_info, 4);
    assign(test_msg_.apc[0].sid.code, 0);
    assign(test_msg_.apc[0].sid.sat, 2);
    assign(test_msg_.apc[0].svn, 61);
    assign(test_msg_.iod_ssr, 3);
    assign(test_msg_.n_apc, 1);
    assign(test_msg_.sol_id, 2);
    assign(test_msg_.time.tow, 604799);
    assign(test_msg_.time.wn, 2222);
    assign(test_msg_.update_interval, 1);
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
      : public sbp::MessageHandler<sbp_msg_ssr_satellite_apc_t> {
    using sbp::MessageHandler<sbp_msg_ssr_satellite_apc_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_satellite_apc_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ssr_satellite_apc_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgSsrSatelliteApc,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_satellite_apc_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgSsrSatelliteApc);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ssr_satellite_apc,
             sizeof(msg->ssr_satellite_apc));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ssr_satellite_apc_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ssr_satellite_apc, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgSsrSatelliteApc);
    info.sender_id = 0;
    info.preamble = 0x55;
    info.crc = 0xA190;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 41;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ssr_satellite_apc_t &lesser,
                        const sbp_msg_ssr_satellite_apc_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ssr_satellite_apc_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ssr_satellite_apc_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_ssr_satellite_apc_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ssr_satellite_apc_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ssr_satellite_apc_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ssr_satellite_apc_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrSatelliteApc, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrSatelliteApc, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgSsrSatelliteApc, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgSsrSatelliteApc, &wrapped_greater,
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
  sbp_msg_ssr_satellite_apc_t test_msg_{};
  uint8_t encoded_frame_[41 + 8] = {
      85, 5,  6,  0,  0,  41,  127, 58,  9,   0,   174, 8,   1,
      2,  3,  2,  0,  4,  61,  0,   1,   0,   255, 255, 217, 2,
      11, 10, 8,  5,  1,  252, 248, 246, 246, 246, 249, 252, 0,
      6,  12, 22, 30, 41, 41,  41,  41,  144, 161,
  };
  uint8_t encoded_payload_[41] = {
      127, 58,  9,   0,   174, 8, 1,  2,  3,  2,  0,  4,   61,  0,
      1,   0,   255, 255, 217, 2, 11, 10, 8,  5,  1,  252, 248, 246,
      246, 246, 249, 252, 0,   6, 12, 22, 30, 41, 41, 41,  41,
  };
};

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ssr_satellite_apc_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgSsrSatelliteApc, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[41];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ssr_satellite_apc_encode(&buf[0], sizeof(buf), &n_written,
                                             &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 41);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 41), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgSsrSatelliteApc, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 41);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 41), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[41];

  EXPECT_EQ(sbp_msg_ssr_satellite_apc_encode(&buf[0], sizeof(buf), nullptr,
                                             &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 41), 0);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[41];

  for (uint8_t i = 0; i < 41; i++) {
    EXPECT_EQ(
        sbp_msg_ssr_satellite_apc_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_satellite_apc_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ssr_satellite_apc_decode(&info.encoded_payload[0],
                                             info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 41);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgSsrSatelliteApc, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 41);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_satellite_apc_t msg{};

  EXPECT_EQ(sbp_msg_ssr_satellite_apc_decode(&info.encoded_payload[0],
                                             info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_satellite_apc_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ssr_satellite_apc_t t{};
      return sbp_msg_ssr_satellite_apc_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ssr_satellite_apc_t t{};
      t.n_apc = 1;
      return sbp_msg_ssr_satellite_apc_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ssr_satellite_apc_decode(&info.encoded_payload[0], i,
                                               nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, SlowRead) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, BadCRC) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ssr_satellite_apc_send(&state, info.sender_id,
                                           &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSsrSatelliteApc, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgSsrSatelliteApc, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSsrSatelliteApc, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, Comparison) {
  auto info = get_test_msg_info();

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pco[0], greater.apc[0].pco[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pco[1], greater.apc[0].pco[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pco[2], greater.apc[0].pco[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[0], greater.apc[0].pcv[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[1], greater.apc[0].pcv[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[2], greater.apc[0].pcv[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[3], greater.apc[0].pcv[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[4], greater.apc[0].pcv[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[5], greater.apc[0].pcv[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[6], greater.apc[0].pcv[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[7], greater.apc[0].pcv[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[8], greater.apc[0].pcv[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[9], greater.apc[0].pcv[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[10], greater.apc[0].pcv[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[11], greater.apc[0].pcv[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[12], greater.apc[0].pcv[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[13], greater.apc[0].pcv[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[14], greater.apc[0].pcv[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[15], greater.apc[0].pcv[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[16], greater.apc[0].pcv[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[17], greater.apc[0].pcv[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[18], greater.apc[0].pcv[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[19], greater.apc[0].pcv[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[20], greater.apc[0].pcv[20]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].sat_info, greater.apc[0].sat_info);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].sid.code, greater.apc[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].sid.sat, greater.apc[0].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].svn, greater.apc[0].svn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.iod_ssr, greater.iod_ssr);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.n_apc, greater.n_apc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_id, greater.sol_id);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.time.tow, greater.time.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.time.wn, greater.time.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_t greater = info.test_msg;
    make_lesser_greater(lesser.update_interval, greater.update_interval);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_satellite_apc_t>::id,
  // SbpMsgSsrSatelliteApc);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ssr_satellite_apc_t>::name,
               "MSG_SSR_SATELLITE_APC");
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ssr_satellite_apc_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_satellite_apc_t>::get(const_sbp_msg_t);
  sbp_msg_ssr_satellite_apc_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_satellite_apc_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 = sbp::MessageTraits<sbp_msg_ssr_satellite_apc_t>::to_sbp_msg(
      info.test_msg);
  EXPECT_EQ(msg1.ssr_satellite_apc, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ssr_satellite_apc_t>::to_sbp_msg(info.test_msg,
                                                              &msg2);
  EXPECT_EQ(msg2.ssr_satellite_apc, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_satellite_apc_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_satellite_apc_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[41];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_satellite_apc_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 41);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 41), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_satellite_apc_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_satellite_apc_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 41);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgSsrSatelliteApc,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApc0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgSsrSatelliteApc,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace