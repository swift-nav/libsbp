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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelECEFDepA.yaml by
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
class Testauto_check_sbp_navigation_MsgVelECEFDepA0 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgVelECEFDepA0() {
    assign(test_msg_.accuracy, 0);
    assign(test_msg_.flags, 0);
    assign(test_msg_.n_sats, 9);
    assign(test_msg_.tow, 2567700);
    assign(test_msg_.x, 3034);
    assign(test_msg_.y, -2682);
    assign(test_msg_.z, -861);
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
      : public sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_vel_ecef_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgVelEcefDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgVelEcefDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->vel_ecef_dep_a,
             sizeof(msg->vel_ecef_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_vel_ecef_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.vel_ecef_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgVelEcefDepA);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0xec50;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 20;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_vel_ecef_dep_a_t &lesser,
                        const sbp_msg_vel_ecef_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_vel_ecef_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_vel_ecef_dep_a_t test_msg_{};
  uint8_t encoded_frame_[20 + 8] = {
      85,  4,   2,   246, 215, 20,  20,  46,  39, 0, 218, 11, 0,  0,
      134, 245, 255, 255, 163, 252, 255, 255, 0,  0, 9,   0,  80, 236,
  };
  uint8_t encoded_payload_[20] = {
      20,  46,  39,  0,   218, 11,  0, 0, 134, 245,
      255, 255, 163, 252, 255, 255, 0, 0, 9,   0,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  for (uint8_t i = 0; i < 20; i++) {
    EXPECT_EQ(
        sbp_msg_vel_ecef_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgVelEcefDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0], i,
                                            nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_send(&state, info.sender_id, &info.test_msg,
                                        &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.accuracy, greater.accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.x, greater.x);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.y, greater.y);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.z, greater.z);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::id,
  // SbpMsgVelEcefDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::name,
               "MSG_VEL_ECEF_DEP_A");
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_vel_ecef_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_vel_ecef_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.vel_ecef_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg,
                                                           &msg2);
  EXPECT_EQ(msg2.vel_ecef_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgVelEcefDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgVelEcefDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_navigation_MsgVelECEFDepA1 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgVelECEFDepA1() {
    assign(test_msg_.accuracy, 0);
    assign(test_msg_.flags, 0);
    assign(test_msg_.n_sats, 9);
    assign(test_msg_.tow, 2567800);
    assign(test_msg_.x, 2884);
    assign(test_msg_.y, -2536);
    assign(test_msg_.z, -804);
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
      : public sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_vel_ecef_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgVelEcefDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgVelEcefDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->vel_ecef_dep_a,
             sizeof(msg->vel_ecef_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_vel_ecef_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.vel_ecef_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgVelEcefDepA);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0x8af8;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 20;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_vel_ecef_dep_a_t &lesser,
                        const sbp_msg_vel_ecef_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_vel_ecef_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_vel_ecef_dep_a_t test_msg_{};
  uint8_t encoded_frame_[20 + 8] = {
      85, 4,   2,   246, 215, 20,  120, 46,  39, 0, 68, 11, 0,   0,
      24, 246, 255, 255, 220, 252, 255, 255, 0,  0, 9,  0,  248, 138,
  };
  uint8_t encoded_payload_[20] = {
      120, 46,  39,  0,   68,  11,  0, 0, 24, 246,
      255, 255, 220, 252, 255, 255, 0, 0, 9,  0,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  for (uint8_t i = 0; i < 20; i++) {
    EXPECT_EQ(
        sbp_msg_vel_ecef_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgVelEcefDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0], i,
                                            nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_send(&state, info.sender_id, &info.test_msg,
                                        &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.accuracy, greater.accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.x, greater.x);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.y, greater.y);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.z, greater.z);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::id,
  // SbpMsgVelEcefDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::name,
               "MSG_VEL_ECEF_DEP_A");
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_vel_ecef_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_vel_ecef_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.vel_ecef_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg,
                                                           &msg2);
  EXPECT_EQ(msg2.vel_ecef_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgVelEcefDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA1,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgVelEcefDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_navigation_MsgVelECEFDepA2 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgVelECEFDepA2() {
    assign(test_msg_.accuracy, 0);
    assign(test_msg_.flags, 0);
    assign(test_msg_.n_sats, 9);
    assign(test_msg_.tow, 2567900);
    assign(test_msg_.x, 2837);
    assign(test_msg_.y, -2483);
    assign(test_msg_.z, -777);
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
      : public sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_vel_ecef_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgVelEcefDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgVelEcefDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->vel_ecef_dep_a,
             sizeof(msg->vel_ecef_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_vel_ecef_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.vel_ecef_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgVelEcefDepA);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0xae19;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 20;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_vel_ecef_dep_a_t &lesser,
                        const sbp_msg_vel_ecef_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_vel_ecef_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_vel_ecef_dep_a_t test_msg_{};
  uint8_t encoded_frame_[20 + 8] = {
      85, 4,   2,   246, 215, 20,  220, 46,  39, 0, 21, 11, 0,  0,
      77, 246, 255, 255, 247, 252, 255, 255, 0,  0, 9,  0,  25, 174,
  };
  uint8_t encoded_payload_[20] = {
      220, 46,  39,  0,   21,  11,  0, 0, 77, 246,
      255, 255, 247, 252, 255, 255, 0, 0, 9,  0,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  for (uint8_t i = 0; i < 20; i++) {
    EXPECT_EQ(
        sbp_msg_vel_ecef_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgVelEcefDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0], i,
                                            nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_send(&state, info.sender_id, &info.test_msg,
                                        &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.accuracy, greater.accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.x, greater.x);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.y, greater.y);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.z, greater.z);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::id,
  // SbpMsgVelEcefDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::name,
               "MSG_VEL_ECEF_DEP_A");
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_vel_ecef_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_vel_ecef_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.vel_ecef_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg,
                                                           &msg2);
  EXPECT_EQ(msg2.vel_ecef_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgVelEcefDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA2,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgVelEcefDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_navigation_MsgVelECEFDepA3 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgVelECEFDepA3() {
    assign(test_msg_.accuracy, 0);
    assign(test_msg_.flags, 0);
    assign(test_msg_.n_sats, 9);
    assign(test_msg_.tow, 2568000);
    assign(test_msg_.x, 2937);
    assign(test_msg_.y, -2558);
    assign(test_msg_.z, -790);
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
      : public sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_vel_ecef_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgVelEcefDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgVelEcefDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->vel_ecef_dep_a,
             sizeof(msg->vel_ecef_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_vel_ecef_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.vel_ecef_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgVelEcefDepA);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0xe4c3;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 20;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_vel_ecef_dep_a_t &lesser,
                        const sbp_msg_vel_ecef_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_vel_ecef_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_vel_ecef_dep_a_t test_msg_{};
  uint8_t encoded_frame_[20 + 8] = {
      85, 4,   2,   246, 215, 20,  64,  47,  39, 0, 121, 11, 0,   0,
      2,  246, 255, 255, 234, 252, 255, 255, 0,  0, 9,   0,  195, 228,
  };
  uint8_t encoded_payload_[20] = {
      64,  47,  39,  0,   121, 11,  0, 0, 2, 246,
      255, 255, 234, 252, 255, 255, 0, 0, 9, 0,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  for (uint8_t i = 0; i < 20; i++) {
    EXPECT_EQ(
        sbp_msg_vel_ecef_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgVelEcefDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0], i,
                                            nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_send(&state, info.sender_id, &info.test_msg,
                                        &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.accuracy, greater.accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.x, greater.x);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.y, greater.y);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.z, greater.z);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::id,
  // SbpMsgVelEcefDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::name,
               "MSG_VEL_ECEF_DEP_A");
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_vel_ecef_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_vel_ecef_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.vel_ecef_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg,
                                                           &msg2);
  EXPECT_EQ(msg2.vel_ecef_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgVelEcefDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA3,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgVelEcefDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_navigation_MsgVelECEFDepA4 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgVelECEFDepA4() {
    assign(test_msg_.accuracy, 0);
    assign(test_msg_.flags, 0);
    assign(test_msg_.n_sats, 9);
    assign(test_msg_.tow, 2568100);
    assign(test_msg_.x, 2847);
    assign(test_msg_.y, -2467);
    assign(test_msg_.z, -752);
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
      : public sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_vel_ecef_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgVelEcefDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgVelEcefDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->vel_ecef_dep_a,
             sizeof(msg->vel_ecef_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_vel_ecef_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.vel_ecef_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgVelEcefDepA);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0xa4db;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 20;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_vel_ecef_dep_a_t &lesser,
                        const sbp_msg_vel_ecef_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_vel_ecef_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_vel_ecef_dep_a_t test_msg_{};
  uint8_t encoded_frame_[20 + 8] = {
      85, 4,   2,   246, 215, 20,  164, 47,  39, 0, 31, 11, 0,   0,
      93, 246, 255, 255, 16,  253, 255, 255, 0,  0, 9,  0,  219, 164,
  };
  uint8_t encoded_payload_[20] = {
      164, 47,  39, 0,   31,  11,  0, 0, 93, 246,
      255, 255, 16, 253, 255, 255, 0, 0, 9,  0,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  for (uint8_t i = 0; i < 20; i++) {
    EXPECT_EQ(
        sbp_msg_vel_ecef_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgVelEcefDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0], i,
                                            nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_send(&state, info.sender_id, &info.test_msg,
                                        &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.accuracy, greater.accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.x, greater.x);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.y, greater.y);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.z, greater.z);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::id,
  // SbpMsgVelEcefDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::name,
               "MSG_VEL_ECEF_DEP_A");
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_vel_ecef_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_vel_ecef_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.vel_ecef_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg,
                                                           &msg2);
  EXPECT_EQ(msg2.vel_ecef_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgVelEcefDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA4,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgVelEcefDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_navigation_MsgVelECEFDepA5 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgVelECEFDepA5() {
    assign(test_msg_.accuracy, 0);
    assign(test_msg_.flags, 0);
    assign(test_msg_.n_sats, 8);
    assign(test_msg_.tow, 407084500);
    assign(test_msg_.x, 24);
    assign(test_msg_.y, -11);
    assign(test_msg_.z, -37);
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
      : public sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_vel_ecef_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgVelEcefDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgVelEcefDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->vel_ecef_dep_a,
             sizeof(msg->vel_ecef_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_vel_ecef_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.vel_ecef_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgVelEcefDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0xff44;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 20;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_vel_ecef_dep_a_t &lesser,
                        const sbp_msg_vel_ecef_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_vel_ecef_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_vel_ecef_dep_a_t test_msg_{};
  uint8_t encoded_frame_[20 + 8] = {
      85,  4,   2,   195, 4,   20,  212, 157, 67, 24, 24, 0, 0,  0,
      245, 255, 255, 255, 219, 255, 255, 255, 0,  0,  8,  0, 68, 255,
  };
  uint8_t encoded_payload_[20] = {
      212, 157, 67,  24,  24,  0,   0, 0, 245, 255,
      255, 255, 219, 255, 255, 255, 0, 0, 8,   0,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  for (uint8_t i = 0; i < 20; i++) {
    EXPECT_EQ(
        sbp_msg_vel_ecef_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgVelEcefDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0], i,
                                            nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_send(&state, info.sender_id, &info.test_msg,
                                        &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.accuracy, greater.accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.x, greater.x);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.y, greater.y);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.z, greater.z);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::id,
  // SbpMsgVelEcefDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::name,
               "MSG_VEL_ECEF_DEP_A");
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_vel_ecef_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_vel_ecef_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.vel_ecef_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg,
                                                           &msg2);
  EXPECT_EQ(msg2.vel_ecef_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgVelEcefDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA5,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgVelEcefDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_navigation_MsgVelECEFDepA6 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgVelECEFDepA6() {
    assign(test_msg_.accuracy, 0);
    assign(test_msg_.flags, 0);
    assign(test_msg_.n_sats, 8);
    assign(test_msg_.tow, 407084600);
    assign(test_msg_.x, 4);
    assign(test_msg_.y, -22);
    assign(test_msg_.z, 18);
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
      : public sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_vel_ecef_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgVelEcefDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgVelEcefDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->vel_ecef_dep_a,
             sizeof(msg->vel_ecef_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_vel_ecef_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.vel_ecef_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgVelEcefDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x88d6;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 20;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_vel_ecef_dep_a_t &lesser,
                        const sbp_msg_vel_ecef_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_vel_ecef_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_vel_ecef_dep_a_t test_msg_{};
  uint8_t encoded_frame_[20 + 8] = {
      85,  4,   2,   195, 4,  20, 56, 158, 67, 24, 4, 0, 0,   0,
      234, 255, 255, 255, 18, 0,  0,  0,   0,  0,  8, 0, 214, 136,
  };
  uint8_t encoded_payload_[20] = {
      56, 158, 67, 24, 4, 0, 0, 0, 234, 255, 255, 255, 18, 0, 0, 0, 0, 0, 8, 0,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  for (uint8_t i = 0; i < 20; i++) {
    EXPECT_EQ(
        sbp_msg_vel_ecef_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgVelEcefDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0], i,
                                            nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_send(&state, info.sender_id, &info.test_msg,
                                        &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.accuracy, greater.accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.x, greater.x);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.y, greater.y);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.z, greater.z);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::id,
  // SbpMsgVelEcefDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::name,
               "MSG_VEL_ECEF_DEP_A");
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_vel_ecef_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_vel_ecef_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.vel_ecef_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg,
                                                           &msg2);
  EXPECT_EQ(msg2.vel_ecef_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgVelEcefDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA6,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgVelEcefDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_navigation_MsgVelECEFDepA7 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgVelECEFDepA7() {
    assign(test_msg_.accuracy, 0);
    assign(test_msg_.flags, 0);
    assign(test_msg_.n_sats, 8);
    assign(test_msg_.tow, 407084700);
    assign(test_msg_.x, -26);
    assign(test_msg_.y, 4);
    assign(test_msg_.z, 1);
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
      : public sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_vel_ecef_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgVelEcefDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgVelEcefDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->vel_ecef_dep_a,
             sizeof(msg->vel_ecef_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_vel_ecef_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.vel_ecef_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgVelEcefDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x9f7a;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 20;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_vel_ecef_dep_a_t &lesser,
                        const sbp_msg_vel_ecef_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_vel_ecef_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_vel_ecef_dep_a_t test_msg_{};
  uint8_t encoded_frame_[20 + 8] = {
      85, 4, 2, 195, 4, 20, 156, 158, 67, 24, 230, 255, 255, 255,
      4,  0, 0, 0,   1, 0,  0,   0,   0,  0,  8,   0,   122, 159,
  };
  uint8_t encoded_payload_[20] = {
      156, 158, 67, 24, 230, 255, 255, 255, 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 8, 0,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  for (uint8_t i = 0; i < 20; i++) {
    EXPECT_EQ(
        sbp_msg_vel_ecef_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgVelEcefDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0], i,
                                            nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_send(&state, info.sender_id, &info.test_msg,
                                        &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.accuracy, greater.accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.x, greater.x);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.y, greater.y);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.z, greater.z);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::id,
  // SbpMsgVelEcefDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::name,
               "MSG_VEL_ECEF_DEP_A");
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_vel_ecef_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_vel_ecef_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.vel_ecef_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg,
                                                           &msg2);
  EXPECT_EQ(msg2.vel_ecef_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgVelEcefDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA7,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgVelEcefDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_navigation_MsgVelECEFDepA8 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgVelECEFDepA8() {
    assign(test_msg_.accuracy, 0);
    assign(test_msg_.flags, 0);
    assign(test_msg_.n_sats, 8);
    assign(test_msg_.tow, 407084800);
    assign(test_msg_.x, -9);
    assign(test_msg_.y, -19);
    assign(test_msg_.z, 28);
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
      : public sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_vel_ecef_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgVelEcefDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgVelEcefDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->vel_ecef_dep_a,
             sizeof(msg->vel_ecef_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_vel_ecef_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.vel_ecef_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgVelEcefDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x92e8;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 20;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_vel_ecef_dep_a_t &lesser,
                        const sbp_msg_vel_ecef_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_vel_ecef_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_vel_ecef_dep_a_t test_msg_{};
  uint8_t encoded_frame_[20 + 8] = {
      85,  4,   2,   195, 4,  20, 0, 159, 67, 24, 247, 255, 255, 255,
      237, 255, 255, 255, 28, 0,  0, 0,   0,  0,  8,   0,   232, 146,
  };
  uint8_t encoded_payload_[20] = {
      0,   159, 67, 24, 247, 255, 255, 255, 237, 255,
      255, 255, 28, 0,  0,   0,   0,   0,   8,   0,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  for (uint8_t i = 0; i < 20; i++) {
    EXPECT_EQ(
        sbp_msg_vel_ecef_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgVelEcefDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0], i,
                                            nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_send(&state, info.sender_id, &info.test_msg,
                                        &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.accuracy, greater.accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.x, greater.x);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.y, greater.y);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.z, greater.z);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::id,
  // SbpMsgVelEcefDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::name,
               "MSG_VEL_ECEF_DEP_A");
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_vel_ecef_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_vel_ecef_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.vel_ecef_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg,
                                                           &msg2);
  EXPECT_EQ(msg2.vel_ecef_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgVelEcefDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA8,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgVelEcefDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_navigation_MsgVelECEFDepA9 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgVelECEFDepA9() {
    assign(test_msg_.accuracy, 0);
    assign(test_msg_.flags, 0);
    assign(test_msg_.n_sats, 8);
    assign(test_msg_.tow, 407084900);
    assign(test_msg_.x, -1);
    assign(test_msg_.y, 2);
    assign(test_msg_.z, -11);
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
      : public sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_vel_ecef_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgVelEcefDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgVelEcefDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->vel_ecef_dep_a,
             sizeof(msg->vel_ecef_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_vel_ecef_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.vel_ecef_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgVelEcefDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0xeeab;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 20;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_vel_ecef_dep_a_t &lesser,
                        const sbp_msg_vel_ecef_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_vel_ecef_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_vel_ecef_dep_a_t test_msg_{};
  uint8_t encoded_frame_[20 + 8] = {
      85, 4, 2, 195, 4,   20,  100, 159, 67, 24, 255, 255, 255, 255,
      2,  0, 0, 0,   245, 255, 255, 255, 0,  0,  8,   0,   171, 238,
  };
  uint8_t encoded_payload_[20] = {
      100, 159, 67,  24,  255, 255, 255, 255, 2, 0,
      0,   0,   245, 255, 255, 255, 0,   0,   8, 0,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  for (uint8_t i = 0; i < 20; i++) {
    EXPECT_EQ(
        sbp_msg_vel_ecef_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgVelEcefDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0], i,
                                            nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_send(&state, info.sender_id, &info.test_msg,
                                        &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.accuracy, greater.accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.x, greater.x);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.y, greater.y);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.z, greater.z);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::id,
  // SbpMsgVelEcefDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::name,
               "MSG_VEL_ECEF_DEP_A");
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_vel_ecef_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_vel_ecef_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.vel_ecef_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg,
                                                           &msg2);
  EXPECT_EQ(msg2.vel_ecef_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgVelEcefDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA9,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgVelEcefDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_navigation_MsgVelECEFDepA10 : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgVelECEFDepA10() {
    assign(test_msg_.accuracy, 0);
    assign(test_msg_.flags, 0);
    assign(test_msg_.n_sats, 5);
    assign(test_msg_.tow, 407151150);
    assign(test_msg_.x, -49);
    assign(test_msg_.y, -71);
    assign(test_msg_.z, 65);
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
      : public sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_vel_ecef_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgVelEcefDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_vel_ecef_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgVelEcefDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->vel_ecef_dep_a,
             sizeof(msg->vel_ecef_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_vel_ecef_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.vel_ecef_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgVelEcefDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x9a52;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 20;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_vel_ecef_dep_a_t &lesser,
                        const sbp_msg_vel_ecef_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_vel_ecef_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_vel_ecef_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgVelEcefDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_vel_ecef_dep_a_t test_msg_{};
  uint8_t encoded_frame_[20 + 8] = {
      85,  4,   2,   195, 4,  20, 46, 162, 68, 24, 207, 255, 255, 255,
      185, 255, 255, 255, 65, 0,  0,  0,   0,  0,  5,   0,   82,  154,
  };
  uint8_t encoded_payload_[20] = {
      46,  162, 68, 24, 207, 255, 255, 255, 185, 255,
      255, 255, 65, 0,  0,   0,   0,   0,   5,   0,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgVelEcefDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[20];

  for (uint8_t i = 0; i < 20; i++) {
    EXPECT_EQ(
        sbp_msg_vel_ecef_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgVelEcefDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0],
                                          info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_vel_ecef_dep_a_decode(&info.encoded_payload[0], i,
                                            nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_vel_ecef_dep_a_send(&state, info.sender_id, &info.test_msg,
                                        &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgVelEcefDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.accuracy, greater.accuracy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.x, greater.x);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.y, greater.y);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_vel_ecef_dep_a_t lesser = info.test_msg;
    sbp_msg_vel_ecef_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.z, greater.z);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::id,
  // SbpMsgVelEcefDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::name,
               "MSG_VEL_ECEF_DEP_A");
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_vel_ecef_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_vel_ecef_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.vel_ecef_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::to_sbp_msg(info.test_msg,
                                                           &msg2);
  EXPECT_EQ(msg2.vel_ecef_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[20];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 20);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 20), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_vel_ecef_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_vel_ecef_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 20);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10,
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

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgVelEcefDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgVelECEFDepA10,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgVelEcefDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace