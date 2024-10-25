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
// spec/tests/yaml/swiftnav/sbp/observation/test_msgEphemerisDepB.yaml by
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
class Testauto_check_sbp_observation_msgEphemerisDepB0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_msgEphemerisDepB0() {
    assign(test_msg_.af0, -1.035025343298912e-05);
    assign(test_msg_.af1, -9.094947017729282e-13);
    assign(test_msg_.af2, 0.0);
    assign(test_msg_.c_ic, 6.332993507385254e-08);
    assign(test_msg_.c_is, -1.564621925354004e-07);
    assign(test_msg_.c_rc, 234.375);
    assign(test_msg_.c_rs, -74.90625);
    assign(test_msg_.c_uc, -3.937631845474243e-06);
    assign(test_msg_.c_us, 6.9122761487960815e-06);
    assign(test_msg_.dn, 4.8884179079418005e-09);
    assign(test_msg_.ecc, 0.011132609914056957);
    assign(test_msg_.healthy, 1);
    assign(test_msg_.inc, 0.9395524830579087);
    assign(test_msg_.inc_dot, -3.296565886629854e-10);
    assign(test_msg_.iode, 0);
    assign(test_msg_.m0, 2.467348395627239);
    assign(test_msg_.omega0, -0.9468985437479658);
    assign(test_msg_.omegadot, -8.201055892610478e-09);
    assign(test_msg_.prn, 3);
    assign(test_msg_.sqrta, 5153.714303970337);
    assign(test_msg_.tgd, -6.51925802230835e-09);
    assign(test_msg_.toc_tow, 410400.0);
    assign(test_msg_.toc_wn, 1838);
    assign(test_msg_.toe_tow, 410400.0);
    assign(test_msg_.toe_wn, 1838);
    assign(test_msg_.valid, 1);
    assign(test_msg_.w, 1.0525047200405302);
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
      : public sbp::MessageHandler<sbp_msg_ephemeris_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_ephemeris_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ephemeris_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ephemeris_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgEphemerisDepB,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ephemeris_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgEphemerisDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ephemeris_dep_b,
             sizeof(msg->ephemeris_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ephemeris_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ephemeris_dep_b, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgEphemerisDepB);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x9ce1;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 176;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ephemeris_dep_b_t &lesser,
                        const sbp_msg_ephemeris_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_ephemeris_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ephemeris_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ephemeris_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ephemeris_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_ephemeris_dep_b_t test_msg_{};
  uint8_t encoded_frame_[176 + 8] = {
      85,  70,  0,   195, 4,   176, 0,   0,   0,   0,   0,   0,   60,  190, 0,
      0,   0,   0,   0,   186, 82,  192, 0,   0,   0,   0,   0,   76,  109, 64,
      0,   0,   0,   0,   0,   132, 208, 190, 0,   0,   0,   0,   0,   254, 220,
      62,  0,   0,   0,   0,   0,   0,   113, 62,  0,   0,   0,   0,   0,   0,
      133, 190, 28,  36,  25,  81,  223, 254, 52,  62,  220, 116, 216, 39,  33,
      189, 3,   64,  0,   0,   0,   156, 177, 204, 134, 63,  0,   0,   160, 220,
      182, 33,  180, 64,  152, 225, 192, 44,  254, 76,  238, 191, 41,  150, 24,
      2,   148, 156, 65,  190, 252, 90,  119, 48,  15,  215, 240, 63,  124, 127,
      115, 94,  208, 16,  238, 63,  165, 115, 52,  74,  97,  167, 246, 189, 0,
      0,   0,   0,   192, 180, 229, 190, 0,   0,   0,   0,   0,   0,   112, 189,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 12,  25,
      65,  46,  7,   0,   0,   0,   0,   128, 12,  25,  65,  46,  7,   1,   1,
      3,   0,   225, 156,
  };
  uint8_t encoded_payload_[176] = {
      0,   0,   0,   0,   0,   0,   60,  190, 0,   0,   0,   0,   0,   186, 82,
      192, 0,   0,   0,   0,   0,   76,  109, 64,  0,   0,   0,   0,   0,   132,
      208, 190, 0,   0,   0,   0,   0,   254, 220, 62,  0,   0,   0,   0,   0,
      0,   113, 62,  0,   0,   0,   0,   0,   0,   133, 190, 28,  36,  25,  81,
      223, 254, 52,  62,  220, 116, 216, 39,  33,  189, 3,   64,  0,   0,   0,
      156, 177, 204, 134, 63,  0,   0,   160, 220, 182, 33,  180, 64,  152, 225,
      192, 44,  254, 76,  238, 191, 41,  150, 24,  2,   148, 156, 65,  190, 252,
      90,  119, 48,  15,  215, 240, 63,  124, 127, 115, 94,  208, 16,  238, 63,
      165, 115, 52,  74,  97,  167, 246, 189, 0,   0,   0,   0,   192, 180, 229,
      190, 0,   0,   0,   0,   0,   0,   112, 189, 0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   128, 12,  25,  65,  46,  7,   0,   0,   0,
      0,   128, 12,  25,  65,  46,  7,   1,   1,   3,   0,
  };
};

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgEphemerisDepB, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[176];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encode(&buf[0], sizeof(buf), &n_written,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgEphemerisDepB, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[176];

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}
TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[176];

  for (uint8_t i = 0; i < 176; i++) {
    EXPECT_EQ(
        sbp_msg_ephemeris_dep_b_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0],
                                           info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgEphemerisDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0],
                                           info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0], i,
                                             nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_send(&state, info.sender_id, &info.test_msg,
                                         &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af0, greater.af0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af1, greater.af1);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af2, greater.af2);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_ic, greater.c_ic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_is, greater.c_is);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_rc, greater.c_rc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_rs, greater.c_rs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_uc, greater.c_uc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_us, greater.c_us);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.dn, greater.dn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.ecc, greater.ecc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.healthy, greater.healthy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.inc, greater.inc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.inc_dot, greater.inc_dot);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.iode, greater.iode);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.m0, greater.m0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.omega0, greater.omega0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.omegadot, greater.omegadot);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.prn, greater.prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.sqrta, greater.sqrta);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.tgd, greater.tgd);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toc_tow, greater.toc_tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toc_wn, greater.toc_wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toe_tow, greater.toe_tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toe_wn, greater.toe_wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.valid, greater.valid);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.w, greater.w);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::id,
  // SbpMsgEphemerisDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::name,
               "MSG_EPHEMERIS_DEP_B");
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ephemeris_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_ephemeris_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.ephemeris_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(info.test_msg,
                                                            &msg2);
  EXPECT_EQ(msg2.ephemeris_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[176];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgEphemerisDepB,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgEphemerisDepB,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_msgEphemerisDepB1
    : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_msgEphemerisDepB1() {
    assign(test_msg_.af0, 7.384549826383591e-05);
    assign(test_msg_.af1, -2.8421709430404007e-12);
    assign(test_msg_.af2, 0.0);
    assign(test_msg_.c_ic, 1.341104507446289e-07);
    assign(test_msg_.c_is, 1.1920928955078125e-07);
    assign(test_msg_.c_rc, 315.78125);
    assign(test_msg_.c_rs, 36.5625);
    assign(test_msg_.c_uc, 2.0638108253479004e-06);
    assign(test_msg_.c_us, 3.4142285585403442e-06);
    assign(test_msg_.dn, 4.86198823561129e-09);
    assign(test_msg_.ecc, 0.007922741584479809);
    assign(test_msg_.healthy, 1);
    assign(test_msg_.inc, 0.9669012918227122);
    assign(test_msg_.inc_dot, 2.6251093463412166e-10);
    assign(test_msg_.iode, 0);
    assign(test_msg_.m0, -1.588160855720083);
    assign(test_msg_.omega0, 1.237919941568746);
    assign(test_msg_.omegadot, -8.295702692172441e-09);
    assign(test_msg_.prn, 13);
    assign(test_msg_.sqrta, 5153.57085609436);
    assign(test_msg_.tgd, -9.313225746154785e-09);
    assign(test_msg_.toc_tow, 410400.0);
    assign(test_msg_.toc_wn, 1838);
    assign(test_msg_.toe_tow, 410400.0);
    assign(test_msg_.toe_wn, 1838);
    assign(test_msg_.valid, 1);
    assign(test_msg_.w, -1.9736022837941165);
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
      : public sbp::MessageHandler<sbp_msg_ephemeris_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_ephemeris_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ephemeris_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ephemeris_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgEphemerisDepB,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ephemeris_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgEphemerisDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ephemeris_dep_b,
             sizeof(msg->ephemeris_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ephemeris_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ephemeris_dep_b, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgEphemerisDepB);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x15b4;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 176;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ephemeris_dep_b_t &lesser,
                        const sbp_msg_ephemeris_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_ephemeris_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ephemeris_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ephemeris_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ephemeris_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_ephemeris_dep_b_t test_msg_{};
  uint8_t encoded_frame_[176 + 8] = {
      85,  70,  0,   195, 4,   176, 0,   0,   0,   0,   0,   0,   68,  190, 0,
      0,   0,   0,   0,   72,  66,  64,  0,   0,   0,   0,   128, 188, 115, 64,
      0,   0,   0,   0,   0,   80,  193, 62,  0,   0,   0,   0,   0,   164, 204,
      62,  0,   0,   0,   0,   0,   0,   130, 62,  0,   0,   0,   0,   0,   0,
      128, 62,  72,  181, 127, 6,   208, 225, 52,  62,  158, 174, 129, 91,  27,
      105, 249, 191, 0,   0,   0,   96,  204, 57,  128, 63,  0,   0,   160, 35,
      146, 33,  180, 64,  247, 169, 1,   36,  133, 206, 243, 63,  79,  11,  109,
      92,  156, 208, 65,  190, 103, 78,  3,   253, 223, 147, 255, 191, 164, 214,
      90,  250, 218, 240, 238, 63,  94,  239, 187, 37,  36,  10,  242, 61,  0,
      0,   0,   0,   176, 91,  19,  63,  0,   0,   0,   0,   0,   0,   137, 189,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 12,  25,
      65,  46,  7,   0,   0,   0,   0,   128, 12,  25,  65,  46,  7,   1,   1,
      13,  0,   180, 21,
  };
  uint8_t encoded_payload_[176] = {
      0,   0,   0,   0,   0,   0,   68,  190, 0,   0,   0,   0,   0,   72,  66,
      64,  0,   0,   0,   0,   128, 188, 115, 64,  0,   0,   0,   0,   0,   80,
      193, 62,  0,   0,   0,   0,   0,   164, 204, 62,  0,   0,   0,   0,   0,
      0,   130, 62,  0,   0,   0,   0,   0,   0,   128, 62,  72,  181, 127, 6,
      208, 225, 52,  62,  158, 174, 129, 91,  27,  105, 249, 191, 0,   0,   0,
      96,  204, 57,  128, 63,  0,   0,   160, 35,  146, 33,  180, 64,  247, 169,
      1,   36,  133, 206, 243, 63,  79,  11,  109, 92,  156, 208, 65,  190, 103,
      78,  3,   253, 223, 147, 255, 191, 164, 214, 90,  250, 218, 240, 238, 63,
      94,  239, 187, 37,  36,  10,  242, 61,  0,   0,   0,   0,   176, 91,  19,
      63,  0,   0,   0,   0,   0,   0,   137, 189, 0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   128, 12,  25,  65,  46,  7,   0,   0,   0,
      0,   128, 12,  25,  65,  46,  7,   1,   1,   13,  0,
  };
};

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgEphemerisDepB, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[176];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encode(&buf[0], sizeof(buf), &n_written,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgEphemerisDepB, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[176];

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}
TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[176];

  for (uint8_t i = 0; i < 176; i++) {
    EXPECT_EQ(
        sbp_msg_ephemeris_dep_b_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0],
                                           info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgEphemerisDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0],
                                           info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0], i,
                                             nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_send(&state, info.sender_id, &info.test_msg,
                                         &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af0, greater.af0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af1, greater.af1);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af2, greater.af2);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_ic, greater.c_ic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_is, greater.c_is);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_rc, greater.c_rc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_rs, greater.c_rs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_uc, greater.c_uc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_us, greater.c_us);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.dn, greater.dn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.ecc, greater.ecc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.healthy, greater.healthy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.inc, greater.inc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.inc_dot, greater.inc_dot);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.iode, greater.iode);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.m0, greater.m0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.omega0, greater.omega0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.omegadot, greater.omegadot);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.prn, greater.prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.sqrta, greater.sqrta);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.tgd, greater.tgd);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toc_tow, greater.toc_tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toc_wn, greater.toc_wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toe_tow, greater.toe_tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toe_wn, greater.toe_wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.valid, greater.valid);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.w, greater.w);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::id,
  // SbpMsgEphemerisDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::name,
               "MSG_EPHEMERIS_DEP_B");
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ephemeris_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_ephemeris_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.ephemeris_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(info.test_msg,
                                                            &msg2);
  EXPECT_EQ(msg2.ephemeris_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[176];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgEphemerisDepB,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB1,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgEphemerisDepB,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_msgEphemerisDepB2
    : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_msgEphemerisDepB2() {
    assign(test_msg_.af0, -7.249414920806885e-06);
    assign(test_msg_.af1, 4.547473508864641e-13);
    assign(test_msg_.af2, 0.0);
    assign(test_msg_.c_ic, -4.6566128730773926e-08);
    assign(test_msg_.c_is, -2.60770320892334e-08);
    assign(test_msg_.c_rc, 236.03125);
    assign(test_msg_.c_rs, -68.625);
    assign(test_msg_.c_uc, -3.470107913017273e-06);
    assign(test_msg_.c_us, 7.461756467819214e-06);
    assign(test_msg_.dn, 4.4637573619826565e-09);
    assign(test_msg_.ecc, 0.004040417145006359);
    assign(test_msg_.healthy, 1);
    assign(test_msg_.inc, 0.9619021920701416);
    assign(test_msg_.inc_dot, -3.3644258561271105e-10);
    assign(test_msg_.iode, 0);
    assign(test_msg_.m0, 2.7055255058713295);
    assign(test_msg_.omega0, -0.9258770941316397);
    assign(test_msg_.omegadot, -8.082122367123182e-09);
    assign(test_msg_.prn, 0);
    assign(test_msg_.sqrta, 5153.669353485107);
    assign(test_msg_.tgd, 5.587935447692871e-09);
    assign(test_msg_.toc_tow, 410400.0);
    assign(test_msg_.toc_wn, 1838);
    assign(test_msg_.toe_tow, 410400.0);
    assign(test_msg_.toe_wn, 1838);
    assign(test_msg_.valid, 1);
    assign(test_msg_.w, 0.37873566614641857);
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
      : public sbp::MessageHandler<sbp_msg_ephemeris_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_ephemeris_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ephemeris_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ephemeris_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgEphemerisDepB,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ephemeris_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgEphemerisDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ephemeris_dep_b,
             sizeof(msg->ephemeris_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ephemeris_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ephemeris_dep_b, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgEphemerisDepB);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x98de;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 176;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ephemeris_dep_b_t &lesser,
                        const sbp_msg_ephemeris_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_ephemeris_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ephemeris_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ephemeris_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ephemeris_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_ephemeris_dep_b_t test_msg_{};
  uint8_t encoded_frame_[176 + 8] = {
      85,  70,  0,   195, 4,   176, 0,   0,   0,   0,   0,   0,   56,  62,  0,
      0,   0,   0,   0,   40,  81,  192, 0,   0,   0,   0,   0,   129, 109, 64,
      0,   0,   0,   0,   0,   28,  205, 190, 0,   0,   0,   0,   0,   76,  223,
      62,  0,   0,   0,   0,   0,   0,   105, 190, 0,   0,   0,   0,   0,   0,
      92,  190, 134, 161, 223, 255, 243, 43,  51,  62,  146, 176, 113, 142, 234,
      164, 5,   64,  0,   0,   0,   56,  175, 140, 112, 63,  0,   0,   192, 90,
      171, 33,  180, 64,  36,  38,  237, 255, 200, 160, 237, 191, 204, 92,  63,
      154, 49,  91,  65,  190, 125, 94,  251, 132, 52,  61,  216, 63,  2,   139,
      28,  27,  231, 199, 238, 63,  124, 183, 4,   180, 194, 30,  247, 189, 0,
      0,   0,   0,   0,   104, 222, 190, 0,   0,   0,   0,   0,   0,   96,  61,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 12,  25,
      65,  46,  7,   0,   0,   0,   0,   128, 12,  25,  65,  46,  7,   1,   1,
      0,   0,   222, 152,
  };
  uint8_t encoded_payload_[176] = {
      0,   0,   0,   0,   0,   0,   56,  62,  0,   0,   0,   0,   0,   40,  81,
      192, 0,   0,   0,   0,   0,   129, 109, 64,  0,   0,   0,   0,   0,   28,
      205, 190, 0,   0,   0,   0,   0,   76,  223, 62,  0,   0,   0,   0,   0,
      0,   105, 190, 0,   0,   0,   0,   0,   0,   92,  190, 134, 161, 223, 255,
      243, 43,  51,  62,  146, 176, 113, 142, 234, 164, 5,   64,  0,   0,   0,
      56,  175, 140, 112, 63,  0,   0,   192, 90,  171, 33,  180, 64,  36,  38,
      237, 255, 200, 160, 237, 191, 204, 92,  63,  154, 49,  91,  65,  190, 125,
      94,  251, 132, 52,  61,  216, 63,  2,   139, 28,  27,  231, 199, 238, 63,
      124, 183, 4,   180, 194, 30,  247, 189, 0,   0,   0,   0,   0,   104, 222,
      190, 0,   0,   0,   0,   0,   0,   96,  61,  0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   128, 12,  25,  65,  46,  7,   0,   0,   0,
      0,   128, 12,  25,  65,  46,  7,   1,   1,   0,   0,
  };
};

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgEphemerisDepB, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[176];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encode(&buf[0], sizeof(buf), &n_written,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgEphemerisDepB, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[176];

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}
TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[176];

  for (uint8_t i = 0; i < 176; i++) {
    EXPECT_EQ(
        sbp_msg_ephemeris_dep_b_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0],
                                           info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgEphemerisDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0],
                                           info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0], i,
                                             nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_send(&state, info.sender_id, &info.test_msg,
                                         &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af0, greater.af0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af1, greater.af1);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af2, greater.af2);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_ic, greater.c_ic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_is, greater.c_is);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_rc, greater.c_rc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_rs, greater.c_rs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_uc, greater.c_uc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_us, greater.c_us);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.dn, greater.dn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.ecc, greater.ecc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.healthy, greater.healthy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.inc, greater.inc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.inc_dot, greater.inc_dot);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.iode, greater.iode);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.m0, greater.m0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.omega0, greater.omega0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.omegadot, greater.omegadot);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.prn, greater.prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.sqrta, greater.sqrta);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.tgd, greater.tgd);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toc_tow, greater.toc_tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toc_wn, greater.toc_wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toe_tow, greater.toe_tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toe_wn, greater.toe_wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.valid, greater.valid);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.w, greater.w);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::id,
  // SbpMsgEphemerisDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::name,
               "MSG_EPHEMERIS_DEP_B");
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ephemeris_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_ephemeris_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.ephemeris_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(info.test_msg,
                                                            &msg2);
  EXPECT_EQ(msg2.ephemeris_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[176];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgEphemerisDepB,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB2,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgEphemerisDepB,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_msgEphemerisDepB3
    : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_msgEphemerisDepB3() {
    assign(test_msg_.af0, 7.384549826383591e-05);
    assign(test_msg_.af1, -2.8421709430404007e-12);
    assign(test_msg_.af2, 0.0);
    assign(test_msg_.c_ic, 1.341104507446289e-07);
    assign(test_msg_.c_is, 1.1920928955078125e-07);
    assign(test_msg_.c_rc, 315.78125);
    assign(test_msg_.c_rs, 36.5625);
    assign(test_msg_.c_uc, 2.0638108253479004e-06);
    assign(test_msg_.c_us, 3.4142285585403442e-06);
    assign(test_msg_.dn, 4.86198823561129e-09);
    assign(test_msg_.ecc, 0.007922741584479809);
    assign(test_msg_.healthy, 1);
    assign(test_msg_.inc, 0.9669012918227122);
    assign(test_msg_.inc_dot, 2.6251093463412166e-10);
    assign(test_msg_.iode, 0);
    assign(test_msg_.m0, -1.588160855720083);
    assign(test_msg_.omega0, 1.237919941568746);
    assign(test_msg_.omegadot, -8.295702692172441e-09);
    assign(test_msg_.prn, 13);
    assign(test_msg_.sqrta, 5153.57085609436);
    assign(test_msg_.tgd, -9.313225746154785e-09);
    assign(test_msg_.toc_tow, 410400.0);
    assign(test_msg_.toc_wn, 1838);
    assign(test_msg_.toe_tow, 410400.0);
    assign(test_msg_.toe_wn, 1838);
    assign(test_msg_.valid, 1);
    assign(test_msg_.w, -1.9736022837941165);
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
      : public sbp::MessageHandler<sbp_msg_ephemeris_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_ephemeris_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ephemeris_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ephemeris_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgEphemerisDepB,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ephemeris_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgEphemerisDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ephemeris_dep_b,
             sizeof(msg->ephemeris_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ephemeris_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ephemeris_dep_b, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgEphemerisDepB);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x15b4;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 176;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ephemeris_dep_b_t &lesser,
                        const sbp_msg_ephemeris_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_ephemeris_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ephemeris_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ephemeris_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ephemeris_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_ephemeris_dep_b_t test_msg_{};
  uint8_t encoded_frame_[176 + 8] = {
      85,  70,  0,   195, 4,   176, 0,   0,   0,   0,   0,   0,   68,  190, 0,
      0,   0,   0,   0,   72,  66,  64,  0,   0,   0,   0,   128, 188, 115, 64,
      0,   0,   0,   0,   0,   80,  193, 62,  0,   0,   0,   0,   0,   164, 204,
      62,  0,   0,   0,   0,   0,   0,   130, 62,  0,   0,   0,   0,   0,   0,
      128, 62,  72,  181, 127, 6,   208, 225, 52,  62,  158, 174, 129, 91,  27,
      105, 249, 191, 0,   0,   0,   96,  204, 57,  128, 63,  0,   0,   160, 35,
      146, 33,  180, 64,  247, 169, 1,   36,  133, 206, 243, 63,  79,  11,  109,
      92,  156, 208, 65,  190, 103, 78,  3,   253, 223, 147, 255, 191, 164, 214,
      90,  250, 218, 240, 238, 63,  94,  239, 187, 37,  36,  10,  242, 61,  0,
      0,   0,   0,   176, 91,  19,  63,  0,   0,   0,   0,   0,   0,   137, 189,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 12,  25,
      65,  46,  7,   0,   0,   0,   0,   128, 12,  25,  65,  46,  7,   1,   1,
      13,  0,   180, 21,
  };
  uint8_t encoded_payload_[176] = {
      0,   0,   0,   0,   0,   0,   68,  190, 0,   0,   0,   0,   0,   72,  66,
      64,  0,   0,   0,   0,   128, 188, 115, 64,  0,   0,   0,   0,   0,   80,
      193, 62,  0,   0,   0,   0,   0,   164, 204, 62,  0,   0,   0,   0,   0,
      0,   130, 62,  0,   0,   0,   0,   0,   0,   128, 62,  72,  181, 127, 6,
      208, 225, 52,  62,  158, 174, 129, 91,  27,  105, 249, 191, 0,   0,   0,
      96,  204, 57,  128, 63,  0,   0,   160, 35,  146, 33,  180, 64,  247, 169,
      1,   36,  133, 206, 243, 63,  79,  11,  109, 92,  156, 208, 65,  190, 103,
      78,  3,   253, 223, 147, 255, 191, 164, 214, 90,  250, 218, 240, 238, 63,
      94,  239, 187, 37,  36,  10,  242, 61,  0,   0,   0,   0,   176, 91,  19,
      63,  0,   0,   0,   0,   0,   0,   137, 189, 0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   128, 12,  25,  65,  46,  7,   0,   0,   0,
      0,   128, 12,  25,  65,  46,  7,   1,   1,   13,  0,
  };
};

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgEphemerisDepB, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[176];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encode(&buf[0], sizeof(buf), &n_written,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgEphemerisDepB, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[176];

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}
TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[176];

  for (uint8_t i = 0; i < 176; i++) {
    EXPECT_EQ(
        sbp_msg_ephemeris_dep_b_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0],
                                           info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgEphemerisDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0],
                                           info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0], i,
                                             nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_send(&state, info.sender_id, &info.test_msg,
                                         &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af0, greater.af0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af1, greater.af1);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af2, greater.af2);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_ic, greater.c_ic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_is, greater.c_is);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_rc, greater.c_rc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_rs, greater.c_rs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_uc, greater.c_uc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_us, greater.c_us);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.dn, greater.dn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.ecc, greater.ecc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.healthy, greater.healthy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.inc, greater.inc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.inc_dot, greater.inc_dot);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.iode, greater.iode);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.m0, greater.m0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.omega0, greater.omega0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.omegadot, greater.omegadot);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.prn, greater.prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.sqrta, greater.sqrta);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.tgd, greater.tgd);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toc_tow, greater.toc_tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toc_wn, greater.toc_wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toe_tow, greater.toe_tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toe_wn, greater.toe_wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.valid, greater.valid);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.w, greater.w);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::id,
  // SbpMsgEphemerisDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::name,
               "MSG_EPHEMERIS_DEP_B");
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ephemeris_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_ephemeris_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.ephemeris_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(info.test_msg,
                                                            &msg2);
  EXPECT_EQ(msg2.ephemeris_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[176];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgEphemerisDepB,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB3,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgEphemerisDepB,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_msgEphemerisDepB4
    : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_msgEphemerisDepB4() {
    assign(test_msg_.af0, -9.925523772835732e-05);
    assign(test_msg_.af1, -2.5011104298755527e-12);
    assign(test_msg_.af2, 0.0);
    assign(test_msg_.c_ic, -3.166496753692627e-08);
    assign(test_msg_.c_is, -2.0675361156463623e-07);
    assign(test_msg_.c_rc, 305.21875);
    assign(test_msg_.c_rs, 43.21875);
    assign(test_msg_.c_uc, 2.1010637283325195e-06);
    assign(test_msg_.c_us, 3.766268491744995e-06);
    assign(test_msg_.dn, 5.26057626697412e-09);
    assign(test_msg_.ecc, 0.009923744946718216);
    assign(test_msg_.healthy, 1);
    assign(test_msg_.inc, 0.9487513221807672);
    assign(test_msg_.inc_dot, 3.000124967247105e-10);
    assign(test_msg_.iode, 0);
    assign(test_msg_.m0, -2.666160271911327);
    assign(test_msg_.omega0, 1.1669551972594425);
    assign(test_msg_.omegadot, -8.45999524990264e-09);
    assign(test_msg_.prn, 22);
    assign(test_msg_.sqrta, 5153.636667251587);
    assign(test_msg_.tgd, -2.0023435354232788e-08);
    assign(test_msg_.toc_tow, 410400.0);
    assign(test_msg_.toc_wn, 1838);
    assign(test_msg_.toe_tow, 410400.0);
    assign(test_msg_.toe_wn, 1838);
    assign(test_msg_.valid, 1);
    assign(test_msg_.w, -2.7021241452652935);
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
      : public sbp::MessageHandler<sbp_msg_ephemeris_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_ephemeris_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ephemeris_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ephemeris_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgEphemerisDepB,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ephemeris_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgEphemerisDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ephemeris_dep_b,
             sizeof(msg->ephemeris_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ephemeris_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ephemeris_dep_b, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgEphemerisDepB);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x3d63;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 176;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ephemeris_dep_b_t &lesser,
                        const sbp_msg_ephemeris_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_ephemeris_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ephemeris_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ephemeris_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ephemeris_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_ephemeris_dep_b_t test_msg_{};
  uint8_t encoded_frame_[176 + 8] = {
      85,  70,  0,   195, 4,   176, 0,   0,   0,   0,   0,   128, 85,  190, 0,
      0,   0,   0,   0,   156, 69,  64,  0,   0,   0,   0,   128, 19,  115, 64,
      0,   0,   0,   0,   0,   160, 193, 62,  0,   0,   0,   0,   0,   152, 207,
      62,  0,   0,   0,   0,   0,   0,   97,  190, 0,   0,   0,   0,   0,   192,
      139, 190, 26,  26,  13,  149, 16,  152, 54,  62,  104, 7,   46,  214, 75,
      84,  5,   192, 0,   0,   0,   128, 230, 82,  132, 63,  0,   0,   160, 252,
      162, 33,  180, 64,  73,  6,   130, 54,  217, 171, 242, 63,  81,  224, 163,
      123, 238, 42,  66,  190, 206, 43,  141, 67,  243, 157, 5,   192, 113, 179,
      153, 187, 43,  92,  238, 63,  254, 236, 31,  43,  224, 157, 244, 61,  0,
      0,   0,   0,   232, 4,   26,  191, 0,   0,   0,   0,   0,   0,   134, 189,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 12,  25,
      65,  46,  7,   0,   0,   0,   0,   128, 12,  25,  65,  46,  7,   1,   1,
      22,  0,   99,  61,
  };
  uint8_t encoded_payload_[176] = {
      0,   0,   0,   0,   0,   128, 85,  190, 0,   0,   0,   0,   0,   156, 69,
      64,  0,   0,   0,   0,   128, 19,  115, 64,  0,   0,   0,   0,   0,   160,
      193, 62,  0,   0,   0,   0,   0,   152, 207, 62,  0,   0,   0,   0,   0,
      0,   97,  190, 0,   0,   0,   0,   0,   192, 139, 190, 26,  26,  13,  149,
      16,  152, 54,  62,  104, 7,   46,  214, 75,  84,  5,   192, 0,   0,   0,
      128, 230, 82,  132, 63,  0,   0,   160, 252, 162, 33,  180, 64,  73,  6,
      130, 54,  217, 171, 242, 63,  81,  224, 163, 123, 238, 42,  66,  190, 206,
      43,  141, 67,  243, 157, 5,   192, 113, 179, 153, 187, 43,  92,  238, 63,
      254, 236, 31,  43,  224, 157, 244, 61,  0,   0,   0,   0,   232, 4,   26,
      191, 0,   0,   0,   0,   0,   0,   134, 189, 0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   128, 12,  25,  65,  46,  7,   0,   0,   0,
      0,   128, 12,  25,  65,  46,  7,   1,   1,   22,  0,
  };
};

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgEphemerisDepB, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[176];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encode(&buf[0], sizeof(buf), &n_written,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgEphemerisDepB, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[176];

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}
TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[176];

  for (uint8_t i = 0; i < 176; i++) {
    EXPECT_EQ(
        sbp_msg_ephemeris_dep_b_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0],
                                           info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgEphemerisDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0],
                                           info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0], i,
                                             nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_send(&state, info.sender_id, &info.test_msg,
                                         &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af0, greater.af0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af1, greater.af1);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af2, greater.af2);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_ic, greater.c_ic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_is, greater.c_is);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_rc, greater.c_rc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_rs, greater.c_rs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_uc, greater.c_uc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_us, greater.c_us);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.dn, greater.dn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.ecc, greater.ecc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.healthy, greater.healthy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.inc, greater.inc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.inc_dot, greater.inc_dot);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.iode, greater.iode);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.m0, greater.m0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.omega0, greater.omega0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.omegadot, greater.omegadot);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.prn, greater.prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.sqrta, greater.sqrta);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.tgd, greater.tgd);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toc_tow, greater.toc_tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toc_wn, greater.toc_wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toe_tow, greater.toe_tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toe_wn, greater.toe_wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.valid, greater.valid);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.w, greater.w);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::id,
  // SbpMsgEphemerisDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::name,
               "MSG_EPHEMERIS_DEP_B");
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ephemeris_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_ephemeris_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.ephemeris_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(info.test_msg,
                                                            &msg2);
  EXPECT_EQ(msg2.ephemeris_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[176];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgEphemerisDepB,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB4,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgEphemerisDepB,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_msgEphemerisDepB5
    : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_msgEphemerisDepB5() {
    assign(test_msg_.af0, 0.0003196117468178272);
    assign(test_msg_.af1, -1.0231815394945443e-12);
    assign(test_msg_.af2, 0.0);
    assign(test_msg_.c_ic, 9.12696123123169e-08);
    assign(test_msg_.c_is, 5.21540641784668e-08);
    assign(test_msg_.c_rc, 247.28125);
    assign(test_msg_.c_rs, -77.90625);
    assign(test_msg_.c_uc, -3.723427653312683e-06);
    assign(test_msg_.c_us, 7.178634405136108e-06);
    assign(test_msg_.dn, 4.400897600764146e-09);
    assign(test_msg_.ecc, 0.008178644930012524);
    assign(test_msg_.healthy, 1);
    assign(test_msg_.inc, 0.9755122017245301);
    assign(test_msg_.inc_dot, -5.882387882209502e-10);
    assign(test_msg_.iode, 0);
    assign(test_msg_.m0, 1.9401823459824192);
    assign(test_msg_.omega0, 2.241868028927766);
    assign(test_msg_.omegadot, -7.962474526167494e-09);
    assign(test_msg_.prn, 30);
    assign(test_msg_.sqrta, 5153.7539920806885);
    assign(test_msg_.tgd, -1.3504177331924438e-08);
    assign(test_msg_.toc_tow, 410400.0);
    assign(test_msg_.toc_wn, 1838);
    assign(test_msg_.toe_tow, 410400.0);
    assign(test_msg_.toe_wn, 1838);
    assign(test_msg_.valid, 1);
    assign(test_msg_.w, -0.5237901716088061);
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
      : public sbp::MessageHandler<sbp_msg_ephemeris_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_ephemeris_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ephemeris_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ephemeris_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgEphemerisDepB,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ephemeris_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgEphemerisDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ephemeris_dep_b,
             sizeof(msg->ephemeris_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ephemeris_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ephemeris_dep_b, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgEphemerisDepB);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x21aa;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 176;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ephemeris_dep_b_t &lesser,
                        const sbp_msg_ephemeris_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_ephemeris_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ephemeris_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ephemeris_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ephemeris_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgEphemerisDepB, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_ephemeris_dep_b_t test_msg_{};
  uint8_t encoded_frame_[176 + 8] = {
      85,  70,  0,   195, 4,   176, 0,   0,   0,   0,   0,   0,   77,  190, 0,
      0,   0,   0,   0,   122, 83,  192, 0,   0,   0,   0,   0,   233, 110, 64,
      0,   0,   0,   0,   0,   60,  207, 190, 0,   0,   0,   0,   0,   28,  222,
      62,  0,   0,   0,   0,   0,   128, 120, 62,  0,   0,   0,   0,   0,   0,
      108, 62,  10,  230, 183, 140, 214, 230, 50,  62,  54,  86,  196, 164, 252,
      10,  255, 63,  0,   0,   0,   36,  247, 191, 128, 63,  0,   0,   160, 5,
      193, 33,  180, 64,  186, 138, 81,  129, 88,  239, 1,   64,  94,  210, 120,
      170, 106, 25,  65,  190, 103, 213, 32,  155, 227, 194, 224, 191, 156, 47,
      104, 93,  101, 55,  239, 63,  196, 83,  100, 254, 51,  54,  4,   190, 0,
      0,   0,   0,   50,  242, 52,  63,  0,   0,   0,   0,   0,   0,   114, 189,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 12,  25,
      65,  46,  7,   0,   0,   0,   0,   128, 12,  25,  65,  46,  7,   1,   1,
      30,  0,   170, 33,
  };
  uint8_t encoded_payload_[176] = {
      0,   0,   0,   0,   0,   0,   77,  190, 0,   0,   0,   0,   0,   122, 83,
      192, 0,   0,   0,   0,   0,   233, 110, 64,  0,   0,   0,   0,   0,   60,
      207, 190, 0,   0,   0,   0,   0,   28,  222, 62,  0,   0,   0,   0,   0,
      128, 120, 62,  0,   0,   0,   0,   0,   0,   108, 62,  10,  230, 183, 140,
      214, 230, 50,  62,  54,  86,  196, 164, 252, 10,  255, 63,  0,   0,   0,
      36,  247, 191, 128, 63,  0,   0,   160, 5,   193, 33,  180, 64,  186, 138,
      81,  129, 88,  239, 1,   64,  94,  210, 120, 170, 106, 25,  65,  190, 103,
      213, 32,  155, 227, 194, 224, 191, 156, 47,  104, 93,  101, 55,  239, 63,
      196, 83,  100, 254, 51,  54,  4,   190, 0,   0,   0,   0,   50,  242, 52,
      63,  0,   0,   0,   0,   0,   0,   114, 189, 0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   128, 12,  25,  65,  46,  7,   0,   0,   0,
      0,   128, 12,  25,  65,  46,  7,   1,   1,   30,  0,
  };
};

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgEphemerisDepB, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[176];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encode(&buf[0], sizeof(buf), &n_written,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgEphemerisDepB, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[176];

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}
TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[176];

  for (uint8_t i = 0; i < 176; i++) {
    EXPECT_EQ(
        sbp_msg_ephemeris_dep_b_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0],
                                           info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgEphemerisDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0],
                                           info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_ephemeris_dep_b_decode(&info.encoded_payload[0], i,
                                             nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ephemeris_dep_b_send(&state, info.sender_id, &info.test_msg,
                                         &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEphemerisDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af0, greater.af0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af1, greater.af1);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.af2, greater.af2);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_ic, greater.c_ic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_is, greater.c_is);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_rc, greater.c_rc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_rs, greater.c_rs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_uc, greater.c_uc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.c_us, greater.c_us);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.dn, greater.dn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.ecc, greater.ecc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.healthy, greater.healthy);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.inc, greater.inc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.inc_dot, greater.inc_dot);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.iode, greater.iode);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.m0, greater.m0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.omega0, greater.omega0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.omegadot, greater.omegadot);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.prn, greater.prn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.sqrta, greater.sqrta);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.tgd, greater.tgd);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toc_tow, greater.toc_tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toc_wn, greater.toc_wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toe_tow, greater.toe_tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.toe_wn, greater.toe_wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.valid, greater.valid);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ephemeris_dep_b_t lesser = info.test_msg;
    sbp_msg_ephemeris_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.w, greater.w);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::id,
  // SbpMsgEphemerisDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::name,
               "MSG_EPHEMERIS_DEP_B");
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ephemeris_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_ephemeris_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.ephemeris_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::to_sbp_msg(info.test_msg,
                                                            &msg2);
  EXPECT_EQ(msg2.ephemeris_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[176];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 176);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 176), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ephemeris_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ephemeris_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 176);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5,
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

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgEphemerisDepB,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_msgEphemerisDepB5,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgEphemerisDepB,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace
