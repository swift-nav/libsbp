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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgReferenceFrameParam.yaml by
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
class Testauto_check_sbp_navigation_MsgReferenceFrameParam0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_navigation_MsgReferenceFrameParam0() {
    assign(test_msg_.delta_X0, 7);
    assign(test_msg_.delta_Y0, 8);
    assign(test_msg_.delta_Z0, 9);
    assign(test_msg_.dot_delta_X0, 14);
    assign(test_msg_.dot_delta_Y0, 15);
    assign(test_msg_.dot_delta_Z0, 16);
    assign(test_msg_.dot_scale, 20);
    assign(test_msg_.dot_theta_01, 17);
    assign(test_msg_.dot_theta_02, 18);
    assign(test_msg_.dot_theta_03, 19);
    assign(test_msg_.re_t0, 6);
    assign(test_msg_.scale, 13);
    assign(test_msg_.sin, 4);
    {
      const char assign_string[] = {
          (char)102, (char)111, (char)111, (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,   (char)0,   (char)0};
      memcpy(test_msg_.sn, assign_string, sizeof(assign_string));
    }
    assign(test_msg_.ssr_iod, 1);
    assign(test_msg_.theta_01, 10);
    assign(test_msg_.theta_02, 11);
    assign(test_msg_.theta_03, 12);
    {
      const char assign_string[] = {
          (char)98, (char)97, (char)114, (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,   (char)0};
      memcpy(test_msg_.tn, assign_string, sizeof(assign_string));
    }
    assign(test_msg_.utn, 5);
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
      : public sbp::MessageHandler<sbp_msg_reference_frame_param_t> {
    using sbp::MessageHandler<sbp_msg_reference_frame_param_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_reference_frame_param_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_reference_frame_param_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgReferenceFrameParam,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_reference_frame_param_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgReferenceFrameParam);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->reference_frame_param,
             sizeof(msg->reference_frame_param));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_reference_frame_param_t test_msg;
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
    memcpy(&info.test_msg_wrapped.reference_frame_param, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgReferenceFrameParam);
    info.sender_id = 66;
    info.preamble = 0x55;
    info.crc = 0xA106;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 124;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_reference_frame_param_t &lesser,
                        const sbp_msg_reference_frame_param_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_reference_frame_param_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_reference_frame_param_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_reference_frame_param_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_reference_frame_param_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_reference_frame_param_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_reference_frame_param_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgReferenceFrameParam, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgReferenceFrameParam, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgReferenceFrameParam, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgReferenceFrameParam, &wrapped_greater,
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
  sbp_msg_reference_frame_param_t test_msg_{};
  uint8_t encoded_frame_[124 + 8] = {
      85, 68, 2,  66, 0, 124, 1,  102, 111, 111, 0,  0,  0,   0, 0,  0,  0,
      0,  0,  0,  0,  0, 0,   0,  0,   0,   0,   0,  0,  0,   0, 0,  0,  0,
      0,  0,  0,  0,  0, 98,  97, 114, 0,   0,   0,  0,  0,   0, 0,  0,  0,
      0,  0,  0,  0,  0, 0,   0,  0,   0,   0,   0,  0,  0,   0, 0,  0,  0,
      0,  0,  0,  4,  5, 0,   6,  0,   7,   0,   0,  0,  8,   0, 0,  0,  9,
      0,  0,  0,  10, 0, 0,   0,  11,  0,   0,   0,  12, 0,   0, 0,  13, 0,
      0,  0,  14, 0,  0, 0,   15, 0,   0,   0,   16, 0,  0,   0, 17, 0,  0,
      0,  18, 0,  0,  0, 19,  0,  0,   0,   20,  0,  6,  161,
  };
  uint8_t encoded_payload_[124] = {
      1,  102, 111, 111, 0,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0,  0,  0,  0,
      0,  0,   0,   0,   0,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0,  98, 97, 114,
      0,  0,   0,   0,   0,  0, 0,  0, 0,  0, 0,  0, 0,  0, 0,  0,  0,  0,
      0,  0,   0,   0,   0,  0, 0,  0, 0,  0, 0,  4, 5,  0, 6,  0,  7,  0,
      0,  0,   8,   0,   0,  0, 9,  0, 0,  0, 10, 0, 0,  0, 11, 0,  0,  0,
      12, 0,   0,   0,   13, 0, 0,  0, 14, 0, 0,  0, 15, 0, 0,  0,  16, 0,
      0,  0,   17,  0,   0,  0, 18, 0, 0,  0, 19, 0, 0,  0, 20, 0,
  };
};

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_reference_frame_param_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgReferenceFrameParam,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[124];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_reference_frame_param_encode(&buf[0], sizeof(buf),
                                                 &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 124);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 124), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(
      sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                         SbpMsgReferenceFrameParam, &info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(n_written, 124);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 124), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[124];

  EXPECT_EQ(sbp_msg_reference_frame_param_encode(&buf[0], sizeof(buf), nullptr,
                                                 &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 124), 0);
}
TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[124];

  for (uint8_t i = 0; i < 124; i++) {
    EXPECT_EQ(sbp_msg_reference_frame_param_encode(&buf[0], i, nullptr,
                                                   &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_reference_frame_param_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_reference_frame_param_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 124);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgReferenceFrameParam, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 124);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_reference_frame_param_t msg{};

  EXPECT_EQ(sbp_msg_reference_frame_param_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_reference_frame_param_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_reference_frame_param_decode(&info.encoded_payload[0], i,
                                                   nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
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

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
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

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0, SlowRead) {
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

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0, BadCRC) {
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

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_reference_frame_param_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgReferenceFrameParam, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(
        sbp_message_send(&state, SbpMsgReferenceFrameParam, info.sender_id,
                         &info.test_msg_wrapped, &Writer::write_c),
        SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgReferenceFrameParam, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.delta_X0, greater.delta_X0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.delta_Y0, greater.delta_Y0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.delta_Z0, greater.delta_Z0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.dot_delta_X0, greater.dot_delta_X0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.dot_delta_Y0, greater.dot_delta_Y0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.dot_delta_Z0, greater.dot_delta_Z0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.dot_scale, greater.dot_scale);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.dot_theta_01, greater.dot_theta_01);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.dot_theta_02, greater.dot_theta_02);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.dot_theta_03, greater.dot_theta_03);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.re_t0, greater.re_t0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.scale, greater.scale);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.sin, greater.sin);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.sn, greater.sn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.ssr_iod, greater.ssr_iod);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.theta_01, greater.theta_01);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.theta_02, greater.theta_02);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.theta_03, greater.theta_03);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.tn, greater.tn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_reference_frame_param_t lesser = info.test_msg;
    sbp_msg_reference_frame_param_t greater = info.test_msg;
    make_lesser_greater(lesser.utn, greater.utn);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_reference_frame_param_t>::id,
  // SbpMsgReferenceFrameParam);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_reference_frame_param_t>::name,
               "MSG_REFERENCE_FRAME_PARAM");
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_reference_frame_param_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_reference_frame_param_t>::get(const_sbp_msg_t);
  sbp_msg_reference_frame_param_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_reference_frame_param_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_reference_frame_param_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.reference_frame_param, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_reference_frame_param_t>::to_sbp_msg(info.test_msg,
                                                                  &msg2);
  EXPECT_EQ(msg2.reference_frame_param, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_reference_frame_param_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_reference_frame_param_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[124];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_reference_frame_param_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 124);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 124), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_reference_frame_param_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_reference_frame_param_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 124);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
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

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgReferenceFrameParam,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_navigation_MsgReferenceFrameParam0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgReferenceFrameParam,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace
