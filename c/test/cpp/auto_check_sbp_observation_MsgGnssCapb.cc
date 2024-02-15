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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgGnssCapb.yaml by
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
class Testauto_check_sbp_observation_MsgGnssCapb0 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgGnssCapb0() {
    assign(test_msg_.gc.bds_active, 1929005864);
    assign(test_msg_.gc.bds_b2, 33839445);
    assign(test_msg_.gc.bds_b2a, 378107113);
    assign(test_msg_.gc.bds_d2nav, 1367053175);
    assign(test_msg_.gc.gal_active, 1392028637);
    assign(test_msg_.gc.gal_e5, 484261628);
    assign(test_msg_.gc.glo_active, 13159676);
    assign(test_msg_.gc.glo_l2of, 824073421);
    assign(test_msg_.gc.glo_l3, 404081648);
    assign(test_msg_.gc.gps_active, 1079028506);
    assign(test_msg_.gc.gps_l2c, 781233489);
    assign(test_msg_.gc.gps_l5, 1818069969);
    assign(test_msg_.gc.qzss_active, 198929863);
    assign(test_msg_.gc.sbas_active, 548822484);
    assign(test_msg_.gc.sbas_l5, 465576041);
    assign(test_msg_.t_nmct.tow, 446384);
    assign(test_msg_.t_nmct.wn, 2154);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_gnss_capb_t> {
    using sbp::MessageHandler<sbp_msg_gnss_capb_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_gnss_capb_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_gnss_capb_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgGnssCapb, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_gnss_capb_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgGnssCapb);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->gnss_capb, sizeof(msg->gnss_capb));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_gnss_capb_t test_msg;
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
    memcpy(&info.test_msg_wrapped.gnss_capb, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgGnssCapb);
    info.sender_id = 123;
    info.preamble = 0x55;
    info.crc = 0x5aa3;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 110;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_gnss_capb_t &lesser,
                        const sbp_msg_gnss_capb_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_gnss_capb_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_gnss_capb_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_gnss_capb_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_gnss_capb_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_gnss_capb_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_gnss_capb_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgGnssCapb, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgGnssCapb, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgGnssCapb, &wrapped_lesser, &wrapped_greater), 0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgGnssCapb, &wrapped_greater, &wrapped_lesser), 0);

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
  sbp_msg_gnss_capb_t test_msg_{};
  uint8_t encoded_frame_[110 + 8] = {
      85,  150, 0,  123, 0,  110, 176, 207, 6,   0,  106, 8,   26,  171, 80,
      64,  0,   0,  0,   0,  81,  173, 144, 46,  0,  0,   0,   0,   209, 139,
      93,  108, 0,  0,   0,  0,   252, 204, 200, 0,  205, 92,  30,  49,  240,
      203, 21,  24, 212, 93, 182, 32,  0,   0,   0,  0,   105, 32,  192, 27,
      0,   0,   0,  0,   40, 75,  250, 114, 0,   0,  0,   0,   119, 147, 123,
      81,  0,   0,  0,   0,  85,  89,  4,   2,   0,  0,   0,   0,   233, 116,
      137, 22,  0,  0,   0,  0,   199, 109, 219, 11, 221, 171, 248, 82,  0,
      0,   0,   0,  252, 62, 221, 28,  0,   0,   0,  0,   163, 90,
  };
  uint8_t encoded_payload_[110] = {
      176, 207, 6,   0,   106, 8,   26,  171, 80,  64,  0,   0,   0,   0,
      81,  173, 144, 46,  0,   0,   0,   0,   209, 139, 93,  108, 0,   0,
      0,   0,   252, 204, 200, 0,   205, 92,  30,  49,  240, 203, 21,  24,
      212, 93,  182, 32,  0,   0,   0,   0,   105, 32,  192, 27,  0,   0,
      0,   0,   40,  75,  250, 114, 0,   0,   0,   0,   119, 147, 123, 81,
      0,   0,   0,   0,   85,  89,  4,   2,   0,   0,   0,   0,   233, 116,
      137, 22,  0,   0,   0,   0,   199, 109, 219, 11,  221, 171, 248, 82,
      0,   0,   0,   0,   252, 62,  221, 28,  0,   0,   0,   0,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_gnss_capb_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgGnssCapb, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[110];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_gnss_capb_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 110);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 110), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgGnssCapb,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 110);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 110), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[110];

  EXPECT_EQ(
      sbp_msg_gnss_capb_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 110), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[110];

  for (uint8_t i = 0; i < 110; i++) {
    EXPECT_EQ(sbp_msg_gnss_capb_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_gnss_capb_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_gnss_capb_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 110);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgGnssCapb, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 110);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_gnss_capb_t msg{};

  EXPECT_EQ(sbp_msg_gnss_capb_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_gnss_capb_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(
        sbp_msg_gnss_capb_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0,
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

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_gnss_capb_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgGnssCapb, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgGnssCapb, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgGnssCapb, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.bds_active, greater.gc.bds_active);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.bds_b2, greater.gc.bds_b2);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.bds_b2a, greater.gc.bds_b2a);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.bds_d2nav, greater.gc.bds_d2nav);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.gal_active, greater.gc.gal_active);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.gal_e5, greater.gc.gal_e5);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.glo_active, greater.gc.glo_active);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.glo_l2of, greater.gc.glo_l2of);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.glo_l3, greater.gc.glo_l3);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.gps_active, greater.gc.gps_active);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.gps_l2c, greater.gc.gps_l2c);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.gps_l5, greater.gc.gps_l5);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.qzss_active, greater.gc.qzss_active);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.sbas_active, greater.gc.sbas_active);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.gc.sbas_l5, greater.gc.sbas_l5);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.t_nmct.tow, greater.t_nmct.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_gnss_capb_t lesser = info.test_msg;
    sbp_msg_gnss_capb_t greater = info.test_msg;
    make_lesser_greater(lesser.t_nmct.wn, greater.t_nmct.wn);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_gnss_capb_t>::id, SbpMsgGnssCapb);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_gnss_capb_t>::name, "MSG_GNSS_CAPB");
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_gnss_capb_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_gnss_capb_t>::get(const_sbp_msg_t);
  sbp_msg_gnss_capb_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_gnss_capb_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_gnss_capb_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.gnss_capb, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_gnss_capb_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.gnss_capb, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_gnss_capb_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_gnss_capb_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[110];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_gnss_capb_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 110);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 110), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_gnss_capb_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_gnss_capb_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 110);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0,
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

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgGnssCapb, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgGnssCapb0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgGnssCapb, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace