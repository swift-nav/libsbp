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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignatureDepB.yaml by
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
class Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0() {
    assign(test_msg_.certificate_id[0], 1);

    assign(test_msg_.certificate_id[1], 2);

    assign(test_msg_.certificate_id[2], 3);

    assign(test_msg_.certificate_id[3], 4);
    assign(test_msg_.flags, 0);
    assign(test_msg_.n_signature_bytes, 72);
    assign(test_msg_.n_signed_messages, 3);
    assign(test_msg_.on_demand_counter, 2);

    assign(test_msg_.signature[0], 0);

    assign(test_msg_.signature[1], 1);

    assign(test_msg_.signature[2], 2);

    assign(test_msg_.signature[3], 3);

    assign(test_msg_.signature[4], 4);

    assign(test_msg_.signature[5], 5);

    assign(test_msg_.signature[6], 6);

    assign(test_msg_.signature[7], 7);

    assign(test_msg_.signature[8], 8);

    assign(test_msg_.signature[9], 9);

    assign(test_msg_.signature[10], 10);

    assign(test_msg_.signature[11], 11);

    assign(test_msg_.signature[12], 12);

    assign(test_msg_.signature[13], 13);

    assign(test_msg_.signature[14], 14);

    assign(test_msg_.signature[15], 15);

    assign(test_msg_.signature[16], 16);

    assign(test_msg_.signature[17], 17);

    assign(test_msg_.signature[18], 18);

    assign(test_msg_.signature[19], 19);

    assign(test_msg_.signature[20], 20);

    assign(test_msg_.signature[21], 21);

    assign(test_msg_.signature[22], 22);

    assign(test_msg_.signature[23], 23);

    assign(test_msg_.signature[24], 24);

    assign(test_msg_.signature[25], 25);

    assign(test_msg_.signature[26], 26);

    assign(test_msg_.signature[27], 27);

    assign(test_msg_.signature[28], 28);

    assign(test_msg_.signature[29], 29);

    assign(test_msg_.signature[30], 30);

    assign(test_msg_.signature[31], 31);

    assign(test_msg_.signature[32], 32);

    assign(test_msg_.signature[33], 33);

    assign(test_msg_.signature[34], 34);

    assign(test_msg_.signature[35], 35);

    assign(test_msg_.signature[36], 36);

    assign(test_msg_.signature[37], 37);

    assign(test_msg_.signature[38], 38);

    assign(test_msg_.signature[39], 39);

    assign(test_msg_.signature[40], 40);

    assign(test_msg_.signature[41], 41);

    assign(test_msg_.signature[42], 42);

    assign(test_msg_.signature[43], 43);

    assign(test_msg_.signature[44], 44);

    assign(test_msg_.signature[45], 45);

    assign(test_msg_.signature[46], 46);

    assign(test_msg_.signature[47], 47);

    assign(test_msg_.signature[48], 48);

    assign(test_msg_.signature[49], 49);

    assign(test_msg_.signature[50], 50);

    assign(test_msg_.signature[51], 51);

    assign(test_msg_.signature[52], 52);

    assign(test_msg_.signature[53], 53);

    assign(test_msg_.signature[54], 54);

    assign(test_msg_.signature[55], 55);

    assign(test_msg_.signature[56], 56);

    assign(test_msg_.signature[57], 57);

    assign(test_msg_.signature[58], 58);

    assign(test_msg_.signature[59], 59);

    assign(test_msg_.signature[60], 60);

    assign(test_msg_.signature[61], 61);

    assign(test_msg_.signature[62], 62);

    assign(test_msg_.signature[63], 63);

    assign(test_msg_.signature[64], 64);

    assign(test_msg_.signature[65], 65);

    assign(test_msg_.signature[66], 66);

    assign(test_msg_.signature[67], 67);

    assign(test_msg_.signature[68], 68);

    assign(test_msg_.signature[69], 69);

    assign(test_msg_.signature[70], 70);

    assign(test_msg_.signature[71], 71);

    assign(test_msg_.signed_messages[0], 10);

    assign(test_msg_.signed_messages[1], 21);

    assign(test_msg_.signed_messages[2], 23);
    assign(test_msg_.stream_counter, 1);
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
      : public sbp::MessageHandler<sbp_msg_ecdsa_signature_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_ecdsa_signature_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ecdsa_signature_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ecdsa_signature_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgEcdsaSignatureDepB,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ecdsa_signature_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgEcdsaSignatureDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ecdsa_signature_dep_b,
             sizeof(msg->ecdsa_signature_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ecdsa_signature_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ecdsa_signature_dep_b, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgEcdsaSignatureDepB);
    info.sender_id = 66;
    info.preamble = 0x55;
    info.crc = 0x9FFE;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 83;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ecdsa_signature_dep_b_t &lesser,
                        const sbp_msg_ecdsa_signature_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_b_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_ecdsa_signature_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ecdsa_signature_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ecdsa_signature_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ecdsa_signature_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgEcdsaSignatureDepB, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgEcdsaSignatureDepB, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgEcdsaSignatureDepB, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgEcdsaSignatureDepB, &wrapped_greater,
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
  sbp_msg_ecdsa_signature_dep_b_t test_msg_{};
  uint8_t encoded_frame_[83 + 8] = {
      85, 7,  12, 66, 0,  83, 0,  1,  2,  1,   2,   3,  4,  72, 0,  1,
      2,  3,  4,  5,  6,  7,  8,  9,  10, 11,  12,  13, 14, 15, 16, 17,
      18, 19, 20, 21, 22, 23, 24, 25, 26, 27,  28,  29, 30, 31, 32, 33,
      34, 35, 36, 37, 38, 39, 40, 41, 42, 43,  44,  45, 46, 47, 48, 49,
      50, 51, 52, 53, 54, 55, 56, 57, 58, 59,  60,  61, 62, 63, 64, 65,
      66, 67, 68, 69, 70, 71, 10, 21, 23, 254, 159,
  };
  uint8_t encoded_payload_[83] = {
      0,  1,  2,  1,  2,  3,  4,  72, 0,  1,  2,  3,  4,  5,  6,  7,  8,
      9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
      26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42,
      43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
      60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 10, 21, 23,
  };
};

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ecdsa_signature_dep_b_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgEcdsaSignatureDepB, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[83];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ecdsa_signature_dep_b_encode(&buf[0], sizeof(buf),
                                                 &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 83);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 83), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(
      sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                         SbpMsgEcdsaSignatureDepB, &info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(n_written, 83);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 83), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[83];

  EXPECT_EQ(sbp_msg_ecdsa_signature_dep_b_encode(&buf[0], sizeof(buf), nullptr,
                                                 &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 83), 0);
}
TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[83];

  for (uint8_t i = 0; i < 83; i++) {
    EXPECT_EQ(sbp_msg_ecdsa_signature_dep_b_encode(&buf[0], i, nullptr,
                                                   &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ecdsa_signature_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ecdsa_signature_dep_b_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 83);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgEcdsaSignatureDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 83);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ecdsa_signature_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_ecdsa_signature_dep_b_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ecdsa_signature_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ecdsa_signature_dep_b_t t{};
      return sbp_msg_ecdsa_signature_dep_b_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ecdsa_signature_dep_b_t t{};
      t.n_signed_messages = 1;
      return sbp_msg_ecdsa_signature_dep_b_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ecdsa_signature_dep_b_decode(&info.encoded_payload[0], i,
                                                   nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0, SlowRead) {
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0, BadCRC) {
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ecdsa_signature_dep_b_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEcdsaSignatureDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgEcdsaSignatureDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEcdsaSignatureDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0, Comparison) {
  auto info = get_test_msg_info();

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_id[0], greater.certificate_id[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_id[1], greater.certificate_id[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_id[2], greater.certificate_id[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_id[3], greater.certificate_id[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.n_signature_bytes, greater.n_signature_bytes);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.n_signed_messages, greater.n_signed_messages);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.on_demand_counter, greater.on_demand_counter);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[0], greater.signature[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[1], greater.signature[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[2], greater.signature[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[3], greater.signature[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[4], greater.signature[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[5], greater.signature[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[6], greater.signature[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[7], greater.signature[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[8], greater.signature[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[9], greater.signature[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[10], greater.signature[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[11], greater.signature[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[12], greater.signature[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[13], greater.signature[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[14], greater.signature[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[15], greater.signature[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[16], greater.signature[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[17], greater.signature[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[18], greater.signature[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[19], greater.signature[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[20], greater.signature[20]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[21], greater.signature[21]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[22], greater.signature[22]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[23], greater.signature[23]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[24], greater.signature[24]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[25], greater.signature[25]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[26], greater.signature[26]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[27], greater.signature[27]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[28], greater.signature[28]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[29], greater.signature[29]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[30], greater.signature[30]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[31], greater.signature[31]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[32], greater.signature[32]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[33], greater.signature[33]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[34], greater.signature[34]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[35], greater.signature[35]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[36], greater.signature[36]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[37], greater.signature[37]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[38], greater.signature[38]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[39], greater.signature[39]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[40], greater.signature[40]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[41], greater.signature[41]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[42], greater.signature[42]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[43], greater.signature[43]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[44], greater.signature[44]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[45], greater.signature[45]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[46], greater.signature[46]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[47], greater.signature[47]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[48], greater.signature[48]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[49], greater.signature[49]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[50], greater.signature[50]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[51], greater.signature[51]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[52], greater.signature[52]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[53], greater.signature[53]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[54], greater.signature[54]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[55], greater.signature[55]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[56], greater.signature[56]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[57], greater.signature[57]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[58], greater.signature[58]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[59], greater.signature[59]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[60], greater.signature[60]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[61], greater.signature[61]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[62], greater.signature[62]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[63], greater.signature[63]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[64], greater.signature[64]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[65], greater.signature[65]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[66], greater.signature[66]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[67], greater.signature[67]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[68], greater.signature[68]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[69], greater.signature[69]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[70], greater.signature[70]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[71], greater.signature[71]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[0], greater.signed_messages[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[1], greater.signed_messages[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[2], greater.signed_messages[2]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ecdsa_signature_dep_b_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.stream_counter, greater.stream_counter);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_b_t>::id,
  // SbpMsgEcdsaSignatureDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_b_t>::name,
               "MSG_ECDSA_SIGNATURE_DEP_B");
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ecdsa_signature_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_ecdsa_signature_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_b_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_b_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.ecdsa_signature_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_b_t>::to_sbp_msg(info.test_msg,
                                                                  &msg2);
  EXPECT_EQ(msg2.ecdsa_signature_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_b_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[83];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 83);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 83), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ecdsa_signature_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 83);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgEcdsaSignatureDepB,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepB0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgEcdsaSignatureDepB,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace