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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDep.yaml
// by generate.py. Do not modify by hand!

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
class Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0() {
    assign(test_msg_.L.f, 169);
    assign(test_msg_.L.i, 1319);
    assign(test_msg_.P, 0);
    assign(test_msg_.P_std, 0);
    assign(test_msg_.acceleration, 108);
    assign(test_msg_.clock_drift, 0);
    assign(test_msg_.clock_offset, 0);
    assign(test_msg_.cn0, 177);
    assign(test_msg_.corr_spacing, 40);
    assign(test_msg_.doppler, 15701);
    assign(test_msg_.doppler_std, 39);
    assign(test_msg_.lock, 14032);
    assign(test_msg_.misc_flags, 9);
    assign(test_msg_.nav_flags, 0);
    assign(test_msg_.pset_flags, 0);
    assign(test_msg_.recv_time, 7909447587);
    assign(test_msg_.sid.code, 0);
    assign(test_msg_.sid.reserved, 0);
    assign(test_msg_.sid.sat, 15);
    assign(test_msg_.sync_flags, 1);
    assign(test_msg_.tot.tow, 0);
    assign(test_msg_.tot.wn, 0);
    assign(test_msg_.tow_flags, 0);
    assign(test_msg_.track_flags, 11);
    assign(test_msg_.uptime, 1);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t> {
    using sbp::MessageHandler<
        sbp_msg_tracking_state_detailed_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_detailed_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(
        uint16_t sender_id,
        const sbp_msg_tracking_state_detailed_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDetailedDep,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_detailed_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDetailedDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_detailed_dep,
             sizeof(msg->tracking_state_detailed_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_detailed_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_detailed_dep, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDetailedDep);
    info.sender_id = 26427;
    info.preamble = 0x55;
    info.crc = 0xd6a6;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 55;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_detailed_dep_t &lesser,
                        const sbp_msg_tracking_state_detailed_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
            lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_detailed_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_detailed_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_greater,
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
  sbp_msg_tracking_state_detailed_dep_t test_msg_{};
  uint8_t encoded_frame_[55 + 8] = {
      85,  17, 0,  59, 103, 55, 163, 151, 112, 215, 1,  0, 0, 0,   0,   0,
      0,   0,  0,  0,  0,   0,  0,   0,   0,   0,   39, 5, 0, 0,   169, 177,
      208, 54, 15, 0,  0,   0,  85,  61,  0,   0,   39, 0, 1, 0,   0,   0,
      0,   0,  0,  0,  40,  0,  108, 1,   0,   11,  0,  0, 9, 166, 214,
  };
  uint8_t encoded_payload_[55] = {
      163, 151, 112, 215, 1,  0,  0,   0, 0,  0,  0,   0,   0,   0,
      0,   0,   0,   0,   0,  0,  39,  5, 0,  0,  169, 177, 208, 54,
      15,  0,   0,   0,   85, 61, 0,   0, 39, 0,  1,   0,   0,   0,
      0,   0,   0,   0,   40, 0,  108, 1, 0,  11, 0,   0,   9,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgTrackingStateDetailedDep,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(
                &buf[0], sizeof(buf), &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDetailedDep,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(&buf[0], sizeof(buf),
                                                       nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  for (uint8_t i = 0; i < 55; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(&buf[0], i, nullptr,
                                                         &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgTrackingStateDetailedDep, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                  &info.encoded_payload[0], i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                       &info.test_msg_wrapped, &Writer::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(
        sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                         &info.test_msg_wrapped, &Writer::write_c),
        SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                       &info.test_msg_wrapped, &SlowWriter::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.L.f, greater.L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.L.i, greater.L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.P, greater.P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.P_std, greater.P_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acceleration, greater.acceleration);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.clock_drift, greater.clock_drift);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.clock_offset, greater.clock_offset);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.cn0, greater.cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.corr_spacing, greater.corr_spacing);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.doppler, greater.doppler);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.doppler_std, greater.doppler_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.lock, greater.lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.misc_flags, greater.misc_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.nav_flags, greater.nav_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.pset_flags, greater.pset_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.recv_time, greater.recv_time);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.code, greater.sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.reserved, greater.sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.sat, greater.sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sync_flags, greater.sync_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tot.tow, greater.tot.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tot.wn, greater.tot.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tow_flags, greater.tow_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.track_flags, greater.track_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.uptime, greater.uptime);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::id,
  // SbpMsgTrackingStateDetailedDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::name,
               "MSG_TRACKING_STATE_DETAILED_DEP");
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_detailed_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::get(
          const_sbp_msg_t);
  sbp_msg_tracking_state_detailed_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_detailed_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
      info.test_msg, &msg2);
  EXPECT_EQ(msg2.tracking_state_detailed_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::encoded_len(
          info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDetailedDep,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDetailedDep,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1
    : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1() {
    assign(test_msg_.L.f, 14);
    assign(test_msg_.L.i, 1810);
    assign(test_msg_.P, 0);
    assign(test_msg_.P_std, 0);
    assign(test_msg_.acceleration, -32);
    assign(test_msg_.clock_drift, 0);
    assign(test_msg_.clock_offset, 0);
    assign(test_msg_.cn0, 175);
    assign(test_msg_.corr_spacing, 40);
    assign(test_msg_.doppler, 15667);
    assign(test_msg_.doppler_std, 30);
    assign(test_msg_.lock, 14032);
    assign(test_msg_.misc_flags, 9);
    assign(test_msg_.nav_flags, 0);
    assign(test_msg_.pset_flags, 0);
    assign(test_msg_.recv_time, 8409447265);
    assign(test_msg_.sid.code, 0);
    assign(test_msg_.sid.reserved, 0);
    assign(test_msg_.sid.sat, 15);
    assign(test_msg_.sync_flags, 1);
    assign(test_msg_.tot.tow, 0);
    assign(test_msg_.tot.wn, 0);
    assign(test_msg_.tow_flags, 0);
    assign(test_msg_.track_flags, 11);
    assign(test_msg_.uptime, 1);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t> {
    using sbp::MessageHandler<
        sbp_msg_tracking_state_detailed_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_detailed_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(
        uint16_t sender_id,
        const sbp_msg_tracking_state_detailed_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDetailedDep,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_detailed_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDetailedDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_detailed_dep,
             sizeof(msg->tracking_state_detailed_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_detailed_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_detailed_dep, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDetailedDep);
    info.sender_id = 26427;
    info.preamble = 0x55;
    info.crc = 0xb388;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 55;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_detailed_dep_t &lesser,
                        const sbp_msg_tracking_state_detailed_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
            lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_detailed_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_detailed_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_greater,
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
  sbp_msg_tracking_state_detailed_dep_t test_msg_{};
  uint8_t encoded_frame_[55 + 8] = {
      85,  17, 0,  59, 103, 55, 97,  251, 61, 245, 1,  0, 0, 0,   0,   0,
      0,   0,  0,  0,  0,   0,  0,   0,   0,  0,   18, 7, 0, 0,   14,  175,
      208, 54, 15, 0,  0,   0,  51,  61,  0,  0,   30, 0, 1, 0,   0,   0,
      0,   0,  0,  0,  40,  0,  224, 1,   0,  11,  0,  0, 9, 136, 179,
  };
  uint8_t encoded_payload_[55] = {
      97, 251, 61, 245, 1, 0,  0,   0,   0,  0,  0,   0, 0, 0,  0,  0, 0, 0,  0,
      0,  18,  7,  0,   0, 14, 175, 208, 54, 15, 0,   0, 0, 51, 61, 0, 0, 30, 0,
      1,  0,   0,  0,   0, 0,  0,   0,   40, 0,  224, 1, 0, 11, 0,  0, 9,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgTrackingStateDetailedDep,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(
                &buf[0], sizeof(buf), &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDetailedDep,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(&buf[0], sizeof(buf),
                                                       nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  for (uint8_t i = 0; i < 55; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(&buf[0], i, nullptr,
                                                         &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgTrackingStateDetailedDep, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                  &info.encoded_payload[0], i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                       &info.test_msg_wrapped, &Writer::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(
        sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                         &info.test_msg_wrapped, &Writer::write_c),
        SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                       &info.test_msg_wrapped, &SlowWriter::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.L.f, greater.L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.L.i, greater.L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.P, greater.P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.P_std, greater.P_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acceleration, greater.acceleration);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.clock_drift, greater.clock_drift);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.clock_offset, greater.clock_offset);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.cn0, greater.cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.corr_spacing, greater.corr_spacing);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.doppler, greater.doppler);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.doppler_std, greater.doppler_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.lock, greater.lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.misc_flags, greater.misc_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.nav_flags, greater.nav_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.pset_flags, greater.pset_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.recv_time, greater.recv_time);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.code, greater.sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.reserved, greater.sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.sat, greater.sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sync_flags, greater.sync_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tot.tow, greater.tot.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tot.wn, greater.tot.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tow_flags, greater.tow_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.track_flags, greater.track_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.uptime, greater.uptime);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::id,
  // SbpMsgTrackingStateDetailedDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::name,
               "MSG_TRACKING_STATE_DETAILED_DEP");
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_detailed_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::get(
          const_sbp_msg_t);
  sbp_msg_tracking_state_detailed_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_detailed_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
      info.test_msg, &msg2);
  EXPECT_EQ(msg2.tracking_state_detailed_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::encoded_len(
          info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDetailedDep,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep1,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDetailedDep,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2
    : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2() {
    assign(test_msg_.L.f, 8);
    assign(test_msg_.L.i, 2298);
    assign(test_msg_.P, 0);
    assign(test_msg_.P_std, 0);
    assign(test_msg_.acceleration, 27);
    assign(test_msg_.clock_drift, 0);
    assign(test_msg_.clock_offset, 0);
    assign(test_msg_.cn0, 179);
    assign(test_msg_.corr_spacing, 40);
    assign(test_msg_.doppler, 15683);
    assign(test_msg_.doppler_std, 22);
    assign(test_msg_.lock, 14032);
    assign(test_msg_.misc_flags, 9);
    assign(test_msg_.nav_flags, 0);
    assign(test_msg_.pset_flags, 2);
    assign(test_msg_.recv_time, 8907446923);
    assign(test_msg_.sid.code, 0);
    assign(test_msg_.sid.reserved, 0);
    assign(test_msg_.sid.sat, 15);
    assign(test_msg_.sync_flags, 1);
    assign(test_msg_.tot.tow, 0);
    assign(test_msg_.tot.wn, 0);
    assign(test_msg_.tow_flags, 0);
    assign(test_msg_.track_flags, 11);
    assign(test_msg_.uptime, 2);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t> {
    using sbp::MessageHandler<
        sbp_msg_tracking_state_detailed_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_detailed_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(
        uint16_t sender_id,
        const sbp_msg_tracking_state_detailed_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDetailedDep,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_detailed_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDetailedDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_detailed_dep,
             sizeof(msg->tracking_state_detailed_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_detailed_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_detailed_dep, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDetailedDep);
    info.sender_id = 26427;
    info.preamble = 0x55;
    info.crc = 0x9fd9;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 55;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_detailed_dep_t &lesser,
                        const sbp_msg_tracking_state_detailed_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
            lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_detailed_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_detailed_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_greater,
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
  sbp_msg_tracking_state_detailed_dep_t test_msg_{};
  uint8_t encoded_frame_[55 + 8] = {
      85,  17, 0,  59, 103, 55, 139, 218, 236, 18, 2,   0, 0, 0,   0,   0,
      0,   0,  0,  0,  0,   0,  0,   0,   0,   0,  250, 8, 0, 0,   8,   179,
      208, 54, 15, 0,  0,   0,  67,  61,  0,   0,  22,  0, 2, 0,   0,   0,
      0,   0,  0,  0,  40,  0,  27,  1,   0,   11, 0,   2, 9, 217, 159,
  };
  uint8_t encoded_payload_[55] = {
      139, 218, 236, 18, 2, 0, 0,   0,   0,  0,  0,  0, 0, 0,  0,  0, 0, 0,  0,
      0,   250, 8,   0,  0, 8, 179, 208, 54, 15, 0,  0, 0, 67, 61, 0, 0, 22, 0,
      2,   0,   0,   0,  0, 0, 0,   0,   40, 0,  27, 1, 0, 11, 0,  2, 9,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgTrackingStateDetailedDep,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(
                &buf[0], sizeof(buf), &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDetailedDep,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(&buf[0], sizeof(buf),
                                                       nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  for (uint8_t i = 0; i < 55; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(&buf[0], i, nullptr,
                                                         &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgTrackingStateDetailedDep, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                  &info.encoded_payload[0], i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                       &info.test_msg_wrapped, &Writer::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(
        sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                         &info.test_msg_wrapped, &Writer::write_c),
        SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                       &info.test_msg_wrapped, &SlowWriter::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.L.f, greater.L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.L.i, greater.L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.P, greater.P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.P_std, greater.P_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acceleration, greater.acceleration);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.clock_drift, greater.clock_drift);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.clock_offset, greater.clock_offset);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.cn0, greater.cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.corr_spacing, greater.corr_spacing);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.doppler, greater.doppler);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.doppler_std, greater.doppler_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.lock, greater.lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.misc_flags, greater.misc_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.nav_flags, greater.nav_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.pset_flags, greater.pset_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.recv_time, greater.recv_time);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.code, greater.sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.reserved, greater.sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.sat, greater.sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sync_flags, greater.sync_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tot.tow, greater.tot.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tot.wn, greater.tot.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tow_flags, greater.tow_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.track_flags, greater.track_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.uptime, greater.uptime);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::id,
  // SbpMsgTrackingStateDetailedDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::name,
               "MSG_TRACKING_STATE_DETAILED_DEP");
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_detailed_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::get(
          const_sbp_msg_t);
  sbp_msg_tracking_state_detailed_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_detailed_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
      info.test_msg, &msg2);
  EXPECT_EQ(msg2.tracking_state_detailed_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::encoded_len(
          info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDetailedDep,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep2,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDetailedDep,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3
    : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3() {
    assign(test_msg_.L.f, 125);
    assign(test_msg_.L.i, 2786);
    assign(test_msg_.P, 0);
    assign(test_msg_.P_std, 0);
    assign(test_msg_.acceleration, -36);
    assign(test_msg_.clock_drift, 0);
    assign(test_msg_.clock_offset, 0);
    assign(test_msg_.cn0, 181);
    assign(test_msg_.corr_spacing, 40);
    assign(test_msg_.doppler, 15645);
    assign(test_msg_.doppler_std, 10);
    assign(test_msg_.lock, 14032);
    assign(test_msg_.misc_flags, 9);
    assign(test_msg_.nav_flags, 0);
    assign(test_msg_.pset_flags, 3);
    assign(test_msg_.recv_time, 9406446591);
    assign(test_msg_.sid.code, 0);
    assign(test_msg_.sid.reserved, 0);
    assign(test_msg_.sid.sat, 15);
    assign(test_msg_.sync_flags, 1);
    assign(test_msg_.tot.tow, 0);
    assign(test_msg_.tot.wn, 0);
    assign(test_msg_.tow_flags, 0);
    assign(test_msg_.track_flags, 11);
    assign(test_msg_.uptime, 2);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t> {
    using sbp::MessageHandler<
        sbp_msg_tracking_state_detailed_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_detailed_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(
        uint16_t sender_id,
        const sbp_msg_tracking_state_detailed_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDetailedDep,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_detailed_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDetailedDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_detailed_dep,
             sizeof(msg->tracking_state_detailed_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_detailed_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_detailed_dep, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDetailedDep);
    info.sender_id = 26427;
    info.preamble = 0x55;
    info.crc = 0x5f42;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 55;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_detailed_dep_t &lesser,
                        const sbp_msg_tracking_state_detailed_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
            lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_detailed_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_detailed_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_greater,
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
  sbp_msg_tracking_state_detailed_dep_t test_msg_{};
  uint8_t encoded_frame_[55 + 8] = {
      85,  17, 0,  59, 103, 55, 255, 251, 170, 48, 2,   0,  0, 0,  0,   0,
      0,   0,  0,  0,  0,   0,  0,   0,   0,   0,  226, 10, 0, 0,  125, 181,
      208, 54, 15, 0,  0,   0,  29,  61,  0,   0,  10,  0,  2, 0,  0,   0,
      0,   0,  0,  0,  40,  0,  220, 1,   0,   11, 0,   3,  9, 66, 95,
  };
  uint8_t encoded_payload_[55] = {
      255, 251, 170, 48, 2,  0,  0,   0,  0,  0,  0,   0,   0,   0,
      0,   0,   0,   0,  0,  0,  226, 10, 0,  0,  125, 181, 208, 54,
      15,  0,   0,   0,  29, 61, 0,   0,  10, 0,  2,   0,   0,   0,
      0,   0,   0,   0,  40, 0,  220, 1,  0,  11, 0,   3,   9,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgTrackingStateDetailedDep,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(
                &buf[0], sizeof(buf), &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDetailedDep,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(&buf[0], sizeof(buf),
                                                       nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  for (uint8_t i = 0; i < 55; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(&buf[0], i, nullptr,
                                                         &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgTrackingStateDetailedDep, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                  &info.encoded_payload[0], i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                       &info.test_msg_wrapped, &Writer::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(
        sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                         &info.test_msg_wrapped, &Writer::write_c),
        SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                       &info.test_msg_wrapped, &SlowWriter::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.L.f, greater.L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.L.i, greater.L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.P, greater.P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.P_std, greater.P_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acceleration, greater.acceleration);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.clock_drift, greater.clock_drift);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.clock_offset, greater.clock_offset);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.cn0, greater.cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.corr_spacing, greater.corr_spacing);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.doppler, greater.doppler);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.doppler_std, greater.doppler_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.lock, greater.lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.misc_flags, greater.misc_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.nav_flags, greater.nav_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.pset_flags, greater.pset_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.recv_time, greater.recv_time);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.code, greater.sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.reserved, greater.sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.sat, greater.sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sync_flags, greater.sync_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tot.tow, greater.tot.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tot.wn, greater.tot.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tow_flags, greater.tow_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.track_flags, greater.track_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.uptime, greater.uptime);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::id,
  // SbpMsgTrackingStateDetailedDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::name,
               "MSG_TRACKING_STATE_DETAILED_DEP");
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_detailed_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::get(
          const_sbp_msg_t);
  sbp_msg_tracking_state_detailed_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_detailed_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
      info.test_msg, &msg2);
  EXPECT_EQ(msg2.tracking_state_detailed_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::encoded_len(
          info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDetailedDep,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep3,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDetailedDep,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4
    : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4() {
    assign(test_msg_.L.f, 64);
    assign(test_msg_.L.i, 3275);
    assign(test_msg_.P, 0);
    assign(test_msg_.P_std, 0);
    assign(test_msg_.acceleration, 2);
    assign(test_msg_.clock_drift, 0);
    assign(test_msg_.clock_offset, 0);
    assign(test_msg_.cn0, 184);
    assign(test_msg_.corr_spacing, 40);
    assign(test_msg_.doppler, 15640);
    assign(test_msg_.doppler_std, 4);
    assign(test_msg_.lock, 14032);
    assign(test_msg_.misc_flags, 9);
    assign(test_msg_.nav_flags, 0);
    assign(test_msg_.pset_flags, 3);
    assign(test_msg_.recv_time, 9906446269);
    assign(test_msg_.sid.code, 0);
    assign(test_msg_.sid.reserved, 0);
    assign(test_msg_.sid.sat, 15);
    assign(test_msg_.sync_flags, 1);
    assign(test_msg_.tot.tow, 0);
    assign(test_msg_.tot.wn, 0);
    assign(test_msg_.tow_flags, 0);
    assign(test_msg_.track_flags, 11);
    assign(test_msg_.uptime, 3);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t> {
    using sbp::MessageHandler<
        sbp_msg_tracking_state_detailed_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_detailed_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(
        uint16_t sender_id,
        const sbp_msg_tracking_state_detailed_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDetailedDep,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_detailed_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDetailedDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_detailed_dep,
             sizeof(msg->tracking_state_detailed_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_detailed_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_detailed_dep, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDetailedDep);
    info.sender_id = 26427;
    info.preamble = 0x55;
    info.crc = 0xcec2;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 55;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_detailed_dep_t &lesser,
                        const sbp_msg_tracking_state_detailed_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
            lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_detailed_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_detailed_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDetailedDep, &wrapped_greater,
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
  sbp_msg_tracking_state_detailed_dep_t test_msg_{};
  uint8_t encoded_frame_[55 + 8] = {
      85,  17, 0,  59, 103, 55, 189, 95, 120, 78, 2,   0,  0, 0,   0,   0,
      0,   0,  0,  0,  0,   0,  0,   0,  0,   0,  203, 12, 0, 0,   64,  184,
      208, 54, 15, 0,  0,   0,  24,  61, 0,   0,  4,   0,  3, 0,   0,   0,
      0,   0,  0,  0,  40,  0,  2,   1,  0,   11, 0,   3,  9, 194, 206,
  };
  uint8_t encoded_payload_[55] = {
      189, 95,  120, 78, 2, 0,  0,   0,   0,  0,  0, 0, 0, 0,  0,  0, 0, 0, 0,
      0,   203, 12,  0,  0, 64, 184, 208, 54, 15, 0, 0, 0, 24, 61, 0, 0, 4, 0,
      3,   0,   0,   0,  0, 0,  0,   0,   40, 0,  2, 1, 0, 11, 0,  3, 9,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgTrackingStateDetailedDep,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(
                &buf[0], sizeof(buf), &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDetailedDep,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(&buf[0], sizeof(buf),
                                                       nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[55];

  for (uint8_t i = 0; i < 55; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_encode(&buf[0], i, nullptr,
                                                         &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgTrackingStateDetailedDep, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_decode(
                  &info.encoded_payload[0], i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_detailed_dep_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                       &info.test_msg_wrapped, &Writer::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(
        sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                         &info.test_msg_wrapped, &Writer::write_c),
        SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgTrackingStateDetailedDep, info.sender_id,
                       &info.test_msg_wrapped, &SlowWriter::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.L.f, greater.L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.L.i, greater.L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.P, greater.P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.P_std, greater.P_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acceleration, greater.acceleration);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.clock_drift, greater.clock_drift);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.clock_offset, greater.clock_offset);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.cn0, greater.cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.corr_spacing, greater.corr_spacing);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.doppler, greater.doppler);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.doppler_std, greater.doppler_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.lock, greater.lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.misc_flags, greater.misc_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.nav_flags, greater.nav_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.pset_flags, greater.pset_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.recv_time, greater.recv_time);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.code, greater.sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.reserved, greater.sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.sat, greater.sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.sync_flags, greater.sync_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tot.tow, greater.tot.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tot.wn, greater.tot.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.tow_flags, greater.tow_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.track_flags, greater.track_flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_detailed_dep_t lesser = info.test_msg;
    sbp_msg_tracking_state_detailed_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.uptime, greater.uptime);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::id,
  // SbpMsgTrackingStateDetailedDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::name,
               "MSG_TRACKING_STATE_DETAILED_DEP");
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_detailed_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::get(
          const_sbp_msg_t);
  sbp_msg_tracking_state_detailed_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_detailed_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::to_sbp_msg(
      info.test_msg, &msg2);
  EXPECT_EQ(msg2.tracking_state_detailed_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::encoded_len(
          info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[55];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 55);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 55), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_detailed_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_detailed_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 55);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDetailedDep,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDetailedDep4,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDetailedDep,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace