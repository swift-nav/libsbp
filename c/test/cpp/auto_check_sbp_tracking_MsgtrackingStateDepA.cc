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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgtrackingStateDepA.yaml by
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
class Testauto_check_sbp_tracking_MsgtrackingStateDepA0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgtrackingStateDepA0() {
    assign(test_msg_.n_states, 11);

    assign(test_msg_.states[0].cn0, 11.230907440185547);
    assign(test_msg_.states[0].prn, 0);
    assign(test_msg_.states[0].state, 1);

    assign(test_msg_.states[1].cn0, 10.438665390014648);
    assign(test_msg_.states[1].prn, 2);
    assign(test_msg_.states[1].state, 1);

    assign(test_msg_.states[2].cn0, 9.732142448425293);
    assign(test_msg_.states[2].prn, 3);
    assign(test_msg_.states[2].state, 1);

    assign(test_msg_.states[3].cn0, 14.341922760009766);
    assign(test_msg_.states[3].prn, 7);
    assign(test_msg_.states[3].state, 1);

    assign(test_msg_.states[4].cn0, 7.8549017906188965);
    assign(test_msg_.states[4].prn, 10);
    assign(test_msg_.states[4].state, 1);

    assign(test_msg_.states[5].cn0, 5.0982866287231445);
    assign(test_msg_.states[5].prn, 13);
    assign(test_msg_.states[5].state, 1);

    assign(test_msg_.states[6].cn0, 6.741272926330566);
    assign(test_msg_.states[6].prn, 22);
    assign(test_msg_.states[6].state, 1);

    assign(test_msg_.states[7].cn0, 12.700549125671387);
    assign(test_msg_.states[7].prn, 30);
    assign(test_msg_.states[7].state, 1);

    assign(test_msg_.states[8].cn0, 15.893081665039062);
    assign(test_msg_.states[8].prn, 31);
    assign(test_msg_.states[8].state, 1);

    assign(test_msg_.states[9].cn0, 4.242738723754883);
    assign(test_msg_.states[9].prn, 25);
    assign(test_msg_.states[9].state, 1);

    assign(test_msg_.states[10].cn0, 6.97599983215332);
    assign(test_msg_.states[10].prn, 6);
    assign(test_msg_.states[10].state, 1);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_tracking_state_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_dep_a,
             sizeof(msg->tracking_state_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0xe111;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 66;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_dep_a_t &lesser,
                        const sbp_msg_tracking_state_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_tracking_state_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_greater,
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
  sbp_msg_tracking_state_dep_a_t test_msg_{};
  uint8_t encoded_frame_[66 + 8] = {
      85,  22,  0,   195, 4,   66,  1,   0,  204, 177, 51,  65,  1,   2,   198,
      4,   39,  65,  1,   3,   219, 182, 27, 65,  1,   7,   132, 120, 101, 65,
      1,   10,  91,  91,  251, 64,  1,   13, 42,  37,  163, 64,  1,   22,  130,
      184, 215, 64,  1,   30,  115, 53,  75, 65,  1,   31,  16,  74,  126, 65,
      1,   25,  132, 196, 135, 64,  1,   6,  100, 59,  223, 64,  17,  225,
  };
  uint8_t encoded_payload_[66] = {
      1,   0,   204, 177, 51, 65, 1,   2,   198, 4,  39,  65,  1,   3,
      219, 182, 27,  65,  1,  7,  132, 120, 101, 65, 1,   10,  91,  91,
      251, 64,  1,   13,  42, 37, 163, 64,  1,   22, 130, 184, 215, 64,
      1,   30,  115, 53,  75, 65, 1,   31,  16,  74, 126, 65,  1,   25,
      132, 196, 135, 64,  1,  6,  100, 59,  223, 64,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgTrackingStateDepA, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[66];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], sizeof(buf),
                                                &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[66];

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[66];

  for (uint8_t i = 0; i < 66; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], i, nullptr,
                                                  &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgTrackingStateDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_tracking_state_dep_a_t t{};
      return sbp_msg_tracking_state_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_tracking_state_dep_a_t t{};
      t.n_states = 1;
      return sbp_msg_tracking_state_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(&info.encoded_payload[0], i,
                                                  nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_send(&state, info.sender_id,
                                              &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_states, greater.n_states);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].cn0, greater.states[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].prn, greater.states[0].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].state, greater.states[0].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].cn0, greater.states[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].prn, greater.states[1].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].state, greater.states[1].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].cn0, greater.states[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].prn, greater.states[2].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].state, greater.states[2].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].cn0, greater.states[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].prn, greater.states[3].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].state, greater.states[3].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].cn0, greater.states[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].prn, greater.states[4].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].state, greater.states[4].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].cn0, greater.states[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].prn, greater.states[5].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].state, greater.states[5].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].cn0, greater.states[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].prn, greater.states[6].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].state, greater.states[6].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].cn0, greater.states[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].prn, greater.states[7].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].state, greater.states[7].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].cn0, greater.states[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].prn, greater.states[8].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].state, greater.states[8].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].cn0, greater.states[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].prn, greater.states[9].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].state, greater.states[9].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].cn0, greater.states[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].prn, greater.states[10].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].state, greater.states[10].state);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::id,
  // SbpMsgTrackingStateDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::name,
               "MSG_TRACKING_STATE_DEP_A");
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_tracking_state_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(info.test_msg,
                                                                 &msg2);
  EXPECT_EQ(msg2.tracking_state_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[66];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_tracking_MsgtrackingStateDepA1
    : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgtrackingStateDepA1() {
    assign(test_msg_.n_states, 11);

    assign(test_msg_.states[0].cn0, 11.014122009277344);
    assign(test_msg_.states[0].prn, 0);
    assign(test_msg_.states[0].state, 1);

    assign(test_msg_.states[1].cn0, 10.885148048400879);
    assign(test_msg_.states[1].prn, 2);
    assign(test_msg_.states[1].state, 1);

    assign(test_msg_.states[2].cn0, 10.131351470947266);
    assign(test_msg_.states[2].prn, 3);
    assign(test_msg_.states[2].state, 1);

    assign(test_msg_.states[3].cn0, 14.829026222229004);
    assign(test_msg_.states[3].prn, 7);
    assign(test_msg_.states[3].state, 1);

    assign(test_msg_.states[4].cn0, 7.79104471206665);
    assign(test_msg_.states[4].prn, 10);
    assign(test_msg_.states[4].state, 1);

    assign(test_msg_.states[5].cn0, 4.868161201477051);
    assign(test_msg_.states[5].prn, 13);
    assign(test_msg_.states[5].state, 1);

    assign(test_msg_.states[6].cn0, 6.721095561981201);
    assign(test_msg_.states[6].prn, 22);
    assign(test_msg_.states[6].state, 1);

    assign(test_msg_.states[7].cn0, 12.971323013305664);
    assign(test_msg_.states[7].prn, 30);
    assign(test_msg_.states[7].state, 1);

    assign(test_msg_.states[8].cn0, 15.481405258178711);
    assign(test_msg_.states[8].prn, 31);
    assign(test_msg_.states[8].state, 1);

    assign(test_msg_.states[9].cn0, 3.8834354877471924);
    assign(test_msg_.states[9].prn, 25);
    assign(test_msg_.states[9].state, 1);

    assign(test_msg_.states[10].cn0, 4.061488628387451);
    assign(test_msg_.states[10].prn, 6);
    assign(test_msg_.states[10].state, 1);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_tracking_state_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_dep_a,
             sizeof(msg->tracking_state_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0xada8;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 66;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_dep_a_t &lesser,
                        const sbp_msg_tracking_state_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_tracking_state_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_greater,
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
  sbp_msg_tracking_state_dep_a_t test_msg_{};
  uint8_t encoded_frame_[66 + 8] = {
      85, 22,  0,  195, 4,   66,  1,   0,  216, 57,  48,  65,  1,   2,   145,
      41, 46,  65, 1,   3,   4,   26,  34, 65,  1,   7,   177, 67,  109, 65,
      1,  10,  61, 80,  249, 64,  1,   13, 250, 199, 155, 64,  1,   22,  55,
      19, 215, 64, 1,   30,  138, 138, 79, 65,  1,   31,  214, 179, 119, 65,
      1,  25,  53, 138, 120, 64,  1,   6,  183, 247, 129, 64,  168, 173,
  };
  uint8_t encoded_payload_[66] = {
      1,   0,   216, 57,  48,  65,  1,   2,   145, 41,  46,  65, 1,   3,
      4,   26,  34,  65,  1,   7,   177, 67,  109, 65,  1,   10, 61,  80,
      249, 64,  1,   13,  250, 199, 155, 64,  1,   22,  55,  19, 215, 64,
      1,   30,  138, 138, 79,  65,  1,   31,  214, 179, 119, 65, 1,   25,
      53,  138, 120, 64,  1,   6,   183, 247, 129, 64,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgTrackingStateDepA, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[66];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], sizeof(buf),
                                                &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[66];

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[66];

  for (uint8_t i = 0; i < 66; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], i, nullptr,
                                                  &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgTrackingStateDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_tracking_state_dep_a_t t{};
      return sbp_msg_tracking_state_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_tracking_state_dep_a_t t{};
      t.n_states = 1;
      return sbp_msg_tracking_state_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(&info.encoded_payload[0], i,
                                                  nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_send(&state, info.sender_id,
                                              &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_states, greater.n_states);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].cn0, greater.states[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].prn, greater.states[0].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].state, greater.states[0].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].cn0, greater.states[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].prn, greater.states[1].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].state, greater.states[1].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].cn0, greater.states[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].prn, greater.states[2].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].state, greater.states[2].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].cn0, greater.states[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].prn, greater.states[3].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].state, greater.states[3].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].cn0, greater.states[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].prn, greater.states[4].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].state, greater.states[4].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].cn0, greater.states[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].prn, greater.states[5].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].state, greater.states[5].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].cn0, greater.states[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].prn, greater.states[6].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].state, greater.states[6].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].cn0, greater.states[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].prn, greater.states[7].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].state, greater.states[7].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].cn0, greater.states[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].prn, greater.states[8].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].state, greater.states[8].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].cn0, greater.states[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].prn, greater.states[9].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].state, greater.states[9].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].cn0, greater.states[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].prn, greater.states[10].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].state, greater.states[10].state);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::id,
  // SbpMsgTrackingStateDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::name,
               "MSG_TRACKING_STATE_DEP_A");
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_tracking_state_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(info.test_msg,
                                                                 &msg2);
  EXPECT_EQ(msg2.tracking_state_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[66];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA1,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_tracking_MsgtrackingStateDepA2
    : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgtrackingStateDepA2() {
    assign(test_msg_.n_states, 11);

    assign(test_msg_.states[0].cn0, 11.768689155578613);
    assign(test_msg_.states[0].prn, 0);
    assign(test_msg_.states[0].state, 1);

    assign(test_msg_.states[1].cn0, 10.909001350402832);
    assign(test_msg_.states[1].prn, 2);
    assign(test_msg_.states[1].state, 1);

    assign(test_msg_.states[2].cn0, 9.881731033325195);
    assign(test_msg_.states[2].prn, 3);
    assign(test_msg_.states[2].state, 1);

    assign(test_msg_.states[3].cn0, 14.076395988464355);
    assign(test_msg_.states[3].prn, 7);
    assign(test_msg_.states[3].state, 1);

    assign(test_msg_.states[4].cn0, 7.619818210601807);
    assign(test_msg_.states[4].prn, 10);
    assign(test_msg_.states[4].state, 1);

    assign(test_msg_.states[5].cn0, 5.208371162414551);
    assign(test_msg_.states[5].prn, 13);
    assign(test_msg_.states[5].state, 1);

    assign(test_msg_.states[6].cn0, 6.2935872077941895);
    assign(test_msg_.states[6].prn, 22);
    assign(test_msg_.states[6].state, 1);

    assign(test_msg_.states[7].cn0, 13.232341766357422);
    assign(test_msg_.states[7].prn, 30);
    assign(test_msg_.states[7].state, 1);

    assign(test_msg_.states[8].cn0, 15.547346115112305);
    assign(test_msg_.states[8].prn, 31);
    assign(test_msg_.states[8].state, 1);

    assign(test_msg_.states[9].cn0, 4.130964279174805);
    assign(test_msg_.states[9].prn, 25);
    assign(test_msg_.states[9].state, 1);

    assign(test_msg_.states[10].cn0, 2.856823205947876);
    assign(test_msg_.states[10].prn, 6);
    assign(test_msg_.states[10].state, 1);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_tracking_state_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_dep_a,
             sizeof(msg->tracking_state_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0xb36e;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 66;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_dep_a_t &lesser,
                        const sbp_msg_tracking_state_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_tracking_state_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_greater,
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
  sbp_msg_tracking_state_dep_a_t test_msg_{};
  uint8_t encoded_frame_[66 + 8] = {
      85,  22,  0,   195, 4,   66,  1,   0,  141, 76,  60,  65,  1,   2,   69,
      139, 46,  65,  1,   3,   146, 27,  30, 65,  1,   7,   235, 56,  97,  65,
      1,   10,  141, 213, 243, 64,  1,   13, 250, 170, 166, 64,  1,   22,  17,
      101, 201, 64,  1,   30,  172, 183, 83, 65,  1,   31,  238, 193, 120, 65,
      1,   25,  220, 48,  132, 64,  1,   6,  49,  214, 54,  64,  110, 179,
  };
  uint8_t encoded_payload_[66] = {
      1,   0,  141, 76,  60,  65,  1,   2,   69,  139, 46,  65,  1,   3,
      146, 27, 30,  65,  1,   7,   235, 56,  97,  65,  1,   10,  141, 213,
      243, 64, 1,   13,  250, 170, 166, 64,  1,   22,  17,  101, 201, 64,
      1,   30, 172, 183, 83,  65,  1,   31,  238, 193, 120, 65,  1,   25,
      220, 48, 132, 64,  1,   6,   49,  214, 54,  64,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgTrackingStateDepA, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[66];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], sizeof(buf),
                                                &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[66];

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[66];

  for (uint8_t i = 0; i < 66; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], i, nullptr,
                                                  &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgTrackingStateDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_tracking_state_dep_a_t t{};
      return sbp_msg_tracking_state_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_tracking_state_dep_a_t t{};
      t.n_states = 1;
      return sbp_msg_tracking_state_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(&info.encoded_payload[0], i,
                                                  nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_send(&state, info.sender_id,
                                              &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_states, greater.n_states);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].cn0, greater.states[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].prn, greater.states[0].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].state, greater.states[0].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].cn0, greater.states[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].prn, greater.states[1].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].state, greater.states[1].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].cn0, greater.states[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].prn, greater.states[2].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].state, greater.states[2].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].cn0, greater.states[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].prn, greater.states[3].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].state, greater.states[3].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].cn0, greater.states[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].prn, greater.states[4].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].state, greater.states[4].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].cn0, greater.states[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].prn, greater.states[5].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].state, greater.states[5].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].cn0, greater.states[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].prn, greater.states[6].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].state, greater.states[6].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].cn0, greater.states[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].prn, greater.states[7].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].state, greater.states[7].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].cn0, greater.states[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].prn, greater.states[8].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].state, greater.states[8].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].cn0, greater.states[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].prn, greater.states[9].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].state, greater.states[9].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].cn0, greater.states[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].prn, greater.states[10].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].state, greater.states[10].state);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::id,
  // SbpMsgTrackingStateDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::name,
               "MSG_TRACKING_STATE_DEP_A");
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_tracking_state_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(info.test_msg,
                                                                 &msg2);
  EXPECT_EQ(msg2.tracking_state_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[66];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA2,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_tracking_MsgtrackingStateDepA3
    : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgtrackingStateDepA3() {
    assign(test_msg_.n_states, 11);

    assign(test_msg_.states[0].cn0, 62.13985824584961);
    assign(test_msg_.states[0].prn, 0);
    assign(test_msg_.states[0].state, 1);

    assign(test_msg_.states[1].cn0, -1.0);
    assign(test_msg_.states[1].prn, 0);
    assign(test_msg_.states[1].state, 0);

    assign(test_msg_.states[2].cn0, -1.0);
    assign(test_msg_.states[2].prn, 0);
    assign(test_msg_.states[2].state, 0);

    assign(test_msg_.states[3].cn0, -1.0);
    assign(test_msg_.states[3].prn, 0);
    assign(test_msg_.states[3].state, 0);

    assign(test_msg_.states[4].cn0, -1.0);
    assign(test_msg_.states[4].prn, 0);
    assign(test_msg_.states[4].state, 0);

    assign(test_msg_.states[5].cn0, -1.0);
    assign(test_msg_.states[5].prn, 0);
    assign(test_msg_.states[5].state, 0);

    assign(test_msg_.states[6].cn0, -1.0);
    assign(test_msg_.states[6].prn, 0);
    assign(test_msg_.states[6].state, 0);

    assign(test_msg_.states[7].cn0, -1.0);
    assign(test_msg_.states[7].prn, 0);
    assign(test_msg_.states[7].state, 0);

    assign(test_msg_.states[8].cn0, -1.0);
    assign(test_msg_.states[8].prn, 0);
    assign(test_msg_.states[8].state, 0);

    assign(test_msg_.states[9].cn0, -1.0);
    assign(test_msg_.states[9].prn, 0);
    assign(test_msg_.states[9].state, 0);

    assign(test_msg_.states[10].cn0, -1.0);
    assign(test_msg_.states[10].prn, 0);
    assign(test_msg_.states[10].state, 0);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_tracking_state_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_dep_a,
             sizeof(msg->tracking_state_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x59f8;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 66;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_dep_a_t &lesser,
                        const sbp_msg_tracking_state_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_tracking_state_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_greater,
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
  sbp_msg_tracking_state_dep_a_t test_msg_{};
  uint8_t encoded_frame_[66 + 8] = {
      85, 22,  0,   195, 4,   66,  1, 0,   55,  143, 120, 66,  0,   0,   0,
      0,  128, 191, 0,   0,   0,   0, 128, 191, 0,   0,   0,   0,   128, 191,
      0,  0,   0,   0,   128, 191, 0, 0,   0,   0,   128, 191, 0,   0,   0,
      0,  128, 191, 0,   0,   0,   0, 128, 191, 0,   0,   0,   0,   128, 191,
      0,  0,   0,   0,   128, 191, 0, 0,   0,   0,   128, 191, 248, 89,
  };
  uint8_t encoded_payload_[66] = {
      1, 0, 55, 143, 120, 66,  0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191,
      0, 0, 0,  0,   128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191,
      0, 0, 0,  0,   128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0, 0, 128, 191,
      0, 0, 0,  0,   128, 191, 0, 0, 0, 0, 128, 191,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgTrackingStateDepA, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[66];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], sizeof(buf),
                                                &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[66];

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[66];

  for (uint8_t i = 0; i < 66; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], i, nullptr,
                                                  &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgTrackingStateDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_tracking_state_dep_a_t t{};
      return sbp_msg_tracking_state_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_tracking_state_dep_a_t t{};
      t.n_states = 1;
      return sbp_msg_tracking_state_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(&info.encoded_payload[0], i,
                                                  nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_send(&state, info.sender_id,
                                              &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_states, greater.n_states);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].cn0, greater.states[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].prn, greater.states[0].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].state, greater.states[0].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].cn0, greater.states[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].prn, greater.states[1].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].state, greater.states[1].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].cn0, greater.states[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].prn, greater.states[2].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].state, greater.states[2].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].cn0, greater.states[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].prn, greater.states[3].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].state, greater.states[3].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].cn0, greater.states[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].prn, greater.states[4].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].state, greater.states[4].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].cn0, greater.states[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].prn, greater.states[5].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].state, greater.states[5].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].cn0, greater.states[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].prn, greater.states[6].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].state, greater.states[6].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].cn0, greater.states[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].prn, greater.states[7].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].state, greater.states[7].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].cn0, greater.states[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].prn, greater.states[8].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].state, greater.states[8].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].cn0, greater.states[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].prn, greater.states[9].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].state, greater.states[9].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].cn0, greater.states[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].prn, greater.states[10].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].state, greater.states[10].state);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::id,
  // SbpMsgTrackingStateDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::name,
               "MSG_TRACKING_STATE_DEP_A");
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_tracking_state_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(info.test_msg,
                                                                 &msg2);
  EXPECT_EQ(msg2.tracking_state_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[66];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA3,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_tracking_MsgtrackingStateDepA4
    : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgtrackingStateDepA4() {
    assign(test_msg_.n_states, 11);

    assign(test_msg_.states[0].cn0, 36.764503479003906);
    assign(test_msg_.states[0].prn, 0);
    assign(test_msg_.states[0].state, 1);

    assign(test_msg_.states[1].cn0, 9.313432693481445);
    assign(test_msg_.states[1].prn, 2);
    assign(test_msg_.states[1].state, 1);

    assign(test_msg_.states[2].cn0, 16.854938507080078);
    assign(test_msg_.states[2].prn, 3);
    assign(test_msg_.states[2].state, 1);

    assign(test_msg_.states[3].cn0, -1.0);
    assign(test_msg_.states[3].prn, 0);
    assign(test_msg_.states[3].state, 0);

    assign(test_msg_.states[4].cn0, -1.0);
    assign(test_msg_.states[4].prn, 0);
    assign(test_msg_.states[4].state, 0);

    assign(test_msg_.states[5].cn0, -1.0);
    assign(test_msg_.states[5].prn, 0);
    assign(test_msg_.states[5].state, 0);

    assign(test_msg_.states[6].cn0, -1.0);
    assign(test_msg_.states[6].prn, 0);
    assign(test_msg_.states[6].state, 0);

    assign(test_msg_.states[7].cn0, -1.0);
    assign(test_msg_.states[7].prn, 0);
    assign(test_msg_.states[7].state, 0);

    assign(test_msg_.states[8].cn0, -1.0);
    assign(test_msg_.states[8].prn, 0);
    assign(test_msg_.states[8].state, 0);

    assign(test_msg_.states[9].cn0, -1.0);
    assign(test_msg_.states[9].prn, 0);
    assign(test_msg_.states[9].state, 0);

    assign(test_msg_.states[10].cn0, -1.0);
    assign(test_msg_.states[10].prn, 0);
    assign(test_msg_.states[10].state, 0);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_tracking_state_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_dep_a,
             sizeof(msg->tracking_state_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x6554;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 66;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_dep_a_t &lesser,
                        const sbp_msg_tracking_state_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_tracking_state_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_greater,
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
  sbp_msg_tracking_state_dep_a_t test_msg_{};
  uint8_t encoded_frame_[66 + 8] = {
      85, 22,  0,   195, 4,   66,  1,   0,   218, 14, 19,  66,  1,  2,   210,
      3,  21,  65,  1,   3,   234, 214, 134, 65,  0,  0,   0,   0,  128, 191,
      0,  0,   0,   0,   128, 191, 0,   0,   0,   0,  128, 191, 0,  0,   0,
      0,  128, 191, 0,   0,   0,   0,   128, 191, 0,  0,   0,   0,  128, 191,
      0,  0,   0,   0,   128, 191, 0,   0,   0,   0,  128, 191, 84, 101,
  };
  uint8_t encoded_payload_[66] = {
      1, 0, 218, 14, 19,  66,  1, 2, 210, 3, 21,  65,  1, 3, 234, 214, 134, 65,
      0, 0, 0,   0,  128, 191, 0, 0, 0,   0, 128, 191, 0, 0, 0,   0,   128, 191,
      0, 0, 0,   0,  128, 191, 0, 0, 0,   0, 128, 191, 0, 0, 0,   0,   128, 191,
      0, 0, 0,   0,  128, 191, 0, 0, 0,   0, 128, 191,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgTrackingStateDepA, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[66];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], sizeof(buf),
                                                &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[66];

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[66];

  for (uint8_t i = 0; i < 66; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], i, nullptr,
                                                  &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgTrackingStateDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_tracking_state_dep_a_t t{};
      return sbp_msg_tracking_state_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_tracking_state_dep_a_t t{};
      t.n_states = 1;
      return sbp_msg_tracking_state_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(&info.encoded_payload[0], i,
                                                  nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_send(&state, info.sender_id,
                                              &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_states, greater.n_states);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].cn0, greater.states[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].prn, greater.states[0].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].state, greater.states[0].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].cn0, greater.states[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].prn, greater.states[1].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].state, greater.states[1].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].cn0, greater.states[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].prn, greater.states[2].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].state, greater.states[2].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].cn0, greater.states[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].prn, greater.states[3].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].state, greater.states[3].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].cn0, greater.states[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].prn, greater.states[4].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].state, greater.states[4].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].cn0, greater.states[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].prn, greater.states[5].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].state, greater.states[5].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].cn0, greater.states[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].prn, greater.states[6].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].state, greater.states[6].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].cn0, greater.states[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].prn, greater.states[7].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].state, greater.states[7].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].cn0, greater.states[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].prn, greater.states[8].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].state, greater.states[8].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].cn0, greater.states[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].prn, greater.states[9].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].state, greater.states[9].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].cn0, greater.states[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].prn, greater.states[10].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].state, greater.states[10].state);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::id,
  // SbpMsgTrackingStateDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::name,
               "MSG_TRACKING_STATE_DEP_A");
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_tracking_state_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(info.test_msg,
                                                                 &msg2);
  EXPECT_EQ(msg2.tracking_state_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[66];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA4,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_tracking_MsgtrackingStateDepA5
    : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgtrackingStateDepA5() {
    assign(test_msg_.n_states, 11);

    assign(test_msg_.states[0].cn0, 27.394229888916016);
    assign(test_msg_.states[0].prn, 0);
    assign(test_msg_.states[0].state, 1);

    assign(test_msg_.states[1].cn0, 2.875);
    assign(test_msg_.states[1].prn, 2);
    assign(test_msg_.states[1].state, 1);

    assign(test_msg_.states[2].cn0, 8.467644691467285);
    assign(test_msg_.states[2].prn, 3);
    assign(test_msg_.states[2].state, 1);

    assign(test_msg_.states[3].cn0, -1.0);
    assign(test_msg_.states[3].prn, 0);
    assign(test_msg_.states[3].state, 0);

    assign(test_msg_.states[4].cn0, -1.0);
    assign(test_msg_.states[4].prn, 0);
    assign(test_msg_.states[4].state, 0);

    assign(test_msg_.states[5].cn0, -1.0);
    assign(test_msg_.states[5].prn, 0);
    assign(test_msg_.states[5].state, 0);

    assign(test_msg_.states[6].cn0, -1.0);
    assign(test_msg_.states[6].prn, 0);
    assign(test_msg_.states[6].state, 0);

    assign(test_msg_.states[7].cn0, -1.0);
    assign(test_msg_.states[7].prn, 0);
    assign(test_msg_.states[7].state, 0);

    assign(test_msg_.states[8].cn0, -1.0);
    assign(test_msg_.states[8].prn, 0);
    assign(test_msg_.states[8].state, 0);

    assign(test_msg_.states[9].cn0, -1.0);
    assign(test_msg_.states[9].prn, 0);
    assign(test_msg_.states[9].state, 0);

    assign(test_msg_.states[10].cn0, -1.0);
    assign(test_msg_.states[10].prn, 0);
    assign(test_msg_.states[10].state, 0);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_tracking_state_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_dep_a,
             sizeof(msg->tracking_state_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDepA);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x7b25;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 66;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_dep_a_t &lesser,
                        const sbp_msg_tracking_state_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_tracking_state_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDepA, &wrapped_greater,
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
  sbp_msg_tracking_state_dep_a_t test_msg_{};
  uint8_t encoded_frame_[66 + 8] = {
      85, 22,  0,   195, 4,   66,  1,   0,   98,  39, 219, 65,  1,  2,   0,
      0,  56,  64,  1,   3,   121, 123, 7,   65,  0,  0,   0,   0,  128, 191,
      0,  0,   0,   0,   128, 191, 0,   0,   0,   0,  128, 191, 0,  0,   0,
      0,  128, 191, 0,   0,   0,   0,   128, 191, 0,  0,   0,   0,  128, 191,
      0,  0,   0,   0,   128, 191, 0,   0,   0,   0,  128, 191, 37, 123,
  };
  uint8_t encoded_payload_[66] = {
      1, 0, 98, 39, 219, 65,  1, 2, 0, 0, 56,  64,  1, 3, 121, 123, 7,   65,
      0, 0, 0,  0,  128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0,   0,   128, 191,
      0, 0, 0,  0,  128, 191, 0, 0, 0, 0, 128, 191, 0, 0, 0,   0,   128, 191,
      0, 0, 0,  0,  128, 191, 0, 0, 0, 0, 128, 191,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgTrackingStateDepA, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[66];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], sizeof(buf),
                                                &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[66];

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[66];

  for (uint8_t i = 0; i < 66; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_dep_a_encode(&buf[0], i, nullptr,
                                                  &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgTrackingStateDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_tracking_state_dep_a_t t{};
      return sbp_msg_tracking_state_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_tracking_state_dep_a_t t{};
      t.n_states = 1;
      return sbp_msg_tracking_state_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_tracking_state_dep_a_decode(&info.encoded_payload[0], i,
                                                  nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_dep_a_send(&state, info.sender_id,
                                              &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_states, greater.n_states);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].cn0, greater.states[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].prn, greater.states[0].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].state, greater.states[0].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].cn0, greater.states[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].prn, greater.states[1].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].state, greater.states[1].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].cn0, greater.states[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].prn, greater.states[2].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].state, greater.states[2].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].cn0, greater.states[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].prn, greater.states[3].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].state, greater.states[3].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].cn0, greater.states[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].prn, greater.states[4].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].state, greater.states[4].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].cn0, greater.states[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].prn, greater.states[5].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].state, greater.states[5].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].cn0, greater.states[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].prn, greater.states[6].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].state, greater.states[6].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].cn0, greater.states[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].prn, greater.states[7].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].state, greater.states[7].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].cn0, greater.states[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].prn, greater.states[8].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].state, greater.states[8].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].cn0, greater.states[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].prn, greater.states[9].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].state, greater.states[9].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].cn0, greater.states[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].prn, greater.states[10].prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_a_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].state, greater.states[10].state);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::id,
  // SbpMsgTrackingStateDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::name,
               "MSG_TRACKING_STATE_DEP_A");
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_tracking_state_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::to_sbp_msg(info.test_msg,
                                                                 &msg2);
  EXPECT_EQ(msg2.tracking_state_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[66];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 66);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 66), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 66);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
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

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgtrackingStateDepA5,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace