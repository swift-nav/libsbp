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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEd25519CertificateDep.yaml by
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
class Testauto_check_sbp_signing_MsgEd25519CertificateDep0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_signing_MsgEd25519CertificateDep0() {
    assign(test_msg_.certificate_bytes[0], 0);

    assign(test_msg_.certificate_bytes[1], 3);

    assign(test_msg_.certificate_bytes[2], 6);

    assign(test_msg_.certificate_bytes[3], 9);

    assign(test_msg_.certificate_bytes[4], 12);

    assign(test_msg_.certificate_bytes[5], 15);

    assign(test_msg_.certificate_bytes[6], 18);

    assign(test_msg_.certificate_bytes[7], 21);

    assign(test_msg_.certificate_bytes[8], 24);

    assign(test_msg_.certificate_bytes[9], 27);

    assign(test_msg_.certificate_bytes[10], 30);

    assign(test_msg_.certificate_bytes[11], 33);

    assign(test_msg_.certificate_bytes[12], 36);

    assign(test_msg_.certificate_bytes[13], 39);

    assign(test_msg_.certificate_bytes[14], 42);

    assign(test_msg_.certificate_bytes[15], 45);

    assign(test_msg_.certificate_bytes[16], 48);

    assign(test_msg_.certificate_bytes[17], 51);

    assign(test_msg_.certificate_bytes[18], 54);

    assign(test_msg_.certificate_bytes[19], 57);

    assign(test_msg_.certificate_bytes[20], 60);

    assign(test_msg_.certificate_bytes[21], 63);

    assign(test_msg_.certificate_bytes[22], 66);

    assign(test_msg_.certificate_bytes[23], 69);

    assign(test_msg_.certificate_bytes[24], 72);

    assign(test_msg_.certificate_bytes[25], 75);

    assign(test_msg_.certificate_bytes[26], 78);

    assign(test_msg_.certificate_bytes[27], 81);

    assign(test_msg_.certificate_bytes[28], 84);

    assign(test_msg_.certificate_bytes[29], 87);

    assign(test_msg_.certificate_bytes[30], 90);

    assign(test_msg_.certificate_bytes[31], 93);

    assign(test_msg_.certificate_bytes[32], 96);

    assign(test_msg_.certificate_bytes[33], 99);

    assign(test_msg_.certificate_bytes[34], 102);

    assign(test_msg_.certificate_bytes[35], 105);

    assign(test_msg_.certificate_bytes[36], 108);

    assign(test_msg_.certificate_bytes[37], 111);

    assign(test_msg_.certificate_bytes[38], 114);

    assign(test_msg_.certificate_bytes[39], 117);

    assign(test_msg_.certificate_bytes[40], 120);

    assign(test_msg_.certificate_bytes[41], 123);

    assign(test_msg_.certificate_bytes[42], 126);

    assign(test_msg_.certificate_bytes[43], 129);

    assign(test_msg_.certificate_bytes[44], 132);

    assign(test_msg_.certificate_bytes[45], 135);

    assign(test_msg_.certificate_bytes[46], 138);

    assign(test_msg_.certificate_bytes[47], 141);

    assign(test_msg_.certificate_bytes[48], 144);

    assign(test_msg_.certificate_bytes[49], 147);

    assign(test_msg_.certificate_bytes[50], 150);

    assign(test_msg_.certificate_bytes[51], 153);

    assign(test_msg_.certificate_bytes[52], 156);

    assign(test_msg_.certificate_bytes[53], 159);

    assign(test_msg_.certificate_bytes[54], 162);

    assign(test_msg_.certificate_bytes[55], 165);

    assign(test_msg_.certificate_bytes[56], 168);

    assign(test_msg_.certificate_bytes[57], 171);

    assign(test_msg_.certificate_bytes[58], 174);

    assign(test_msg_.certificate_bytes[59], 177);

    assign(test_msg_.certificate_bytes[60], 180);

    assign(test_msg_.certificate_bytes[61], 183);

    assign(test_msg_.certificate_bytes[62], 186);

    assign(test_msg_.certificate_bytes[63], 189);

    assign(test_msg_.certificate_bytes[64], 192);

    assign(test_msg_.certificate_bytes[65], 195);

    assign(test_msg_.certificate_bytes[66], 198);

    assign(test_msg_.certificate_bytes[67], 201);

    assign(test_msg_.certificate_bytes[68], 204);

    assign(test_msg_.certificate_bytes[69], 207);

    assign(test_msg_.certificate_bytes[70], 210);

    assign(test_msg_.certificate_bytes[71], 213);

    assign(test_msg_.certificate_bytes[72], 216);

    assign(test_msg_.certificate_bytes[73], 219);

    assign(test_msg_.certificate_bytes[74], 222);

    assign(test_msg_.certificate_bytes[75], 225);

    assign(test_msg_.certificate_bytes[76], 228);

    assign(test_msg_.certificate_bytes[77], 231);

    assign(test_msg_.certificate_bytes[78], 234);

    assign(test_msg_.certificate_bytes[79], 237);

    assign(test_msg_.certificate_bytes[80], 240);

    assign(test_msg_.certificate_bytes[81], 243);

    assign(test_msg_.certificate_bytes[82], 246);

    assign(test_msg_.certificate_bytes[83], 249);

    assign(test_msg_.certificate_bytes[84], 252);

    assign(test_msg_.fingerprint[0], 100);

    assign(test_msg_.fingerprint[1], 101);

    assign(test_msg_.fingerprint[2], 102);

    assign(test_msg_.fingerprint[3], 103);

    assign(test_msg_.fingerprint[4], 104);

    assign(test_msg_.fingerprint[5], 105);

    assign(test_msg_.fingerprint[6], 106);

    assign(test_msg_.fingerprint[7], 107);

    assign(test_msg_.fingerprint[8], 108);

    assign(test_msg_.fingerprint[9], 109);

    assign(test_msg_.fingerprint[10], 110);

    assign(test_msg_.fingerprint[11], 111);

    assign(test_msg_.fingerprint[12], 112);

    assign(test_msg_.fingerprint[13], 113);

    assign(test_msg_.fingerprint[14], 114);

    assign(test_msg_.fingerprint[15], 115);

    assign(test_msg_.fingerprint[16], 116);

    assign(test_msg_.fingerprint[17], 117);

    assign(test_msg_.fingerprint[18], 118);

    assign(test_msg_.fingerprint[19], 119);
    assign(test_msg_.n_certificate_bytes, 85);
    assign(test_msg_.n_msg, 16);
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
      : public sbp::MessageHandler<sbp_msg_ed25519_certificate_dep_t> {
    using sbp::MessageHandler<
        sbp_msg_ed25519_certificate_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ed25519_certificate_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ed25519_certificate_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgEd25519CertificateDep,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ed25519_certificate_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgEd25519CertificateDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ed25519_certificate_dep,
             sizeof(msg->ed25519_certificate_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ed25519_certificate_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ed25519_certificate_dep, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgEd25519CertificateDep);
    info.sender_id = 66;
    info.preamble = 0x55;
    info.crc = 0x94DA;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 106;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ed25519_certificate_dep_t &lesser,
                        const sbp_msg_ed25519_certificate_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ed25519_certificate_dep_t>::to_sbp_msg(
            lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ed25519_certificate_dep_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_ed25519_certificate_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ed25519_certificate_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ed25519_certificate_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ed25519_certificate_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgEd25519CertificateDep, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgEd25519CertificateDep, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgEd25519CertificateDep, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgEd25519CertificateDep, &wrapped_greater,
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
  sbp_msg_ed25519_certificate_dep_t test_msg_{};
  uint8_t encoded_frame_[106 + 8] = {
      85,  2,   12,  66,  0,   106, 16,  100, 101, 102, 103, 104, 105, 106, 107,
      108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 0,   3,   6,
      9,   12,  15,  18,  21,  24,  27,  30,  33,  36,  39,  42,  45,  48,  51,
      54,  57,  60,  63,  66,  69,  72,  75,  78,  81,  84,  87,  90,  93,  96,
      99,  102, 105, 108, 111, 114, 117, 120, 123, 126, 129, 132, 135, 138, 141,
      144, 147, 150, 153, 156, 159, 162, 165, 168, 171, 174, 177, 180, 183, 186,
      189, 192, 195, 198, 201, 204, 207, 210, 213, 216, 219, 222, 225, 228, 231,
      234, 237, 240, 243, 246, 249, 252, 218, 148,
  };
  uint8_t encoded_payload_[106] = {
      16,  100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112,
      113, 114, 115, 116, 117, 118, 119, 0,   3,   6,   9,   12,  15,  18,
      21,  24,  27,  30,  33,  36,  39,  42,  45,  48,  51,  54,  57,  60,
      63,  66,  69,  72,  75,  78,  81,  84,  87,  90,  93,  96,  99,  102,
      105, 108, 111, 114, 117, 120, 123, 126, 129, 132, 135, 138, 141, 144,
      147, 150, 153, 156, 159, 162, 165, 168, 171, 174, 177, 180, 183, 186,
      189, 192, 195, 198, 201, 204, 207, 210, 213, 216, 219, 222, 225, 228,
      231, 234, 237, 240, 243, 246, 249, 252,
  };
};

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ed25519_certificate_dep_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgEd25519CertificateDep,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[106];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ed25519_certificate_dep_encode(&buf[0], sizeof(buf),
                                                   &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 106);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 106), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(
      sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                         SbpMsgEd25519CertificateDep, &info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(n_written, 106);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 106), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[106];

  EXPECT_EQ(sbp_msg_ed25519_certificate_dep_encode(&buf[0], sizeof(buf),
                                                   nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 106), 0);
}
TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[106];

  for (uint8_t i = 0; i < 106; i++) {
    EXPECT_EQ(sbp_msg_ed25519_certificate_dep_encode(&buf[0], i, nullptr,
                                                     &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ed25519_certificate_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ed25519_certificate_dep_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 106);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgEd25519CertificateDep, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 106);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ed25519_certificate_dep_t msg{};

  EXPECT_EQ(sbp_msg_ed25519_certificate_dep_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ed25519_certificate_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ed25519_certificate_dep_t t{};
      return sbp_msg_ed25519_certificate_dep_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ed25519_certificate_dep_t t{};
      t.n_certificate_bytes = 1;
      return sbp_msg_ed25519_certificate_dep_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ed25519_certificate_dep_decode(&info.encoded_payload[0],
                                                     i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
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

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
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

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0, SlowRead) {
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

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0, BadCRC) {
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

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ed25519_certificate_dep_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgEd25519CertificateDep, info.sender_id,
                       &info.test_msg_wrapped, &Writer::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(
        sbp_message_send(&state, SbpMsgEd25519CertificateDep, info.sender_id,
                         &info.test_msg_wrapped, &Writer::write_c),
        SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgEd25519CertificateDep, info.sender_id,
                       &info.test_msg_wrapped, &SlowWriter::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0, Comparison) {
  auto info = get_test_msg_info();

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[0],
                        greater.certificate_bytes[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[1],
                        greater.certificate_bytes[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[2],
                        greater.certificate_bytes[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[3],
                        greater.certificate_bytes[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[4],
                        greater.certificate_bytes[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[5],
                        greater.certificate_bytes[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[6],
                        greater.certificate_bytes[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[7],
                        greater.certificate_bytes[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[8],
                        greater.certificate_bytes[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[9],
                        greater.certificate_bytes[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[10],
                        greater.certificate_bytes[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[11],
                        greater.certificate_bytes[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[12],
                        greater.certificate_bytes[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[13],
                        greater.certificate_bytes[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[14],
                        greater.certificate_bytes[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[15],
                        greater.certificate_bytes[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[16],
                        greater.certificate_bytes[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[17],
                        greater.certificate_bytes[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[18],
                        greater.certificate_bytes[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[19],
                        greater.certificate_bytes[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[20],
                        greater.certificate_bytes[20]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[21],
                        greater.certificate_bytes[21]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[22],
                        greater.certificate_bytes[22]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[23],
                        greater.certificate_bytes[23]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[24],
                        greater.certificate_bytes[24]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[25],
                        greater.certificate_bytes[25]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[26],
                        greater.certificate_bytes[26]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[27],
                        greater.certificate_bytes[27]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[28],
                        greater.certificate_bytes[28]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[29],
                        greater.certificate_bytes[29]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[30],
                        greater.certificate_bytes[30]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[31],
                        greater.certificate_bytes[31]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[32],
                        greater.certificate_bytes[32]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[33],
                        greater.certificate_bytes[33]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[34],
                        greater.certificate_bytes[34]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[35],
                        greater.certificate_bytes[35]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[36],
                        greater.certificate_bytes[36]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[37],
                        greater.certificate_bytes[37]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[38],
                        greater.certificate_bytes[38]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[39],
                        greater.certificate_bytes[39]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[40],
                        greater.certificate_bytes[40]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[41],
                        greater.certificate_bytes[41]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[42],
                        greater.certificate_bytes[42]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[43],
                        greater.certificate_bytes[43]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[44],
                        greater.certificate_bytes[44]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[45],
                        greater.certificate_bytes[45]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[46],
                        greater.certificate_bytes[46]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[47],
                        greater.certificate_bytes[47]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[48],
                        greater.certificate_bytes[48]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[49],
                        greater.certificate_bytes[49]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[50],
                        greater.certificate_bytes[50]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[51],
                        greater.certificate_bytes[51]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[52],
                        greater.certificate_bytes[52]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[53],
                        greater.certificate_bytes[53]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[54],
                        greater.certificate_bytes[54]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[55],
                        greater.certificate_bytes[55]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[56],
                        greater.certificate_bytes[56]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[57],
                        greater.certificate_bytes[57]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[58],
                        greater.certificate_bytes[58]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[59],
                        greater.certificate_bytes[59]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[60],
                        greater.certificate_bytes[60]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[61],
                        greater.certificate_bytes[61]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[62],
                        greater.certificate_bytes[62]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[63],
                        greater.certificate_bytes[63]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[64],
                        greater.certificate_bytes[64]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[65],
                        greater.certificate_bytes[65]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[66],
                        greater.certificate_bytes[66]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[67],
                        greater.certificate_bytes[67]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[68],
                        greater.certificate_bytes[68]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[69],
                        greater.certificate_bytes[69]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[70],
                        greater.certificate_bytes[70]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[71],
                        greater.certificate_bytes[71]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[72],
                        greater.certificate_bytes[72]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[73],
                        greater.certificate_bytes[73]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[74],
                        greater.certificate_bytes[74]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[75],
                        greater.certificate_bytes[75]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[76],
                        greater.certificate_bytes[76]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[77],
                        greater.certificate_bytes[77]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[78],
                        greater.certificate_bytes[78]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[79],
                        greater.certificate_bytes[79]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[80],
                        greater.certificate_bytes[80]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[81],
                        greater.certificate_bytes[81]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[82],
                        greater.certificate_bytes[82]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[83],
                        greater.certificate_bytes[83]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[84],
                        greater.certificate_bytes[84]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[0], greater.fingerprint[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[1], greater.fingerprint[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[2], greater.fingerprint[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[3], greater.fingerprint[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[4], greater.fingerprint[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[5], greater.fingerprint[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[6], greater.fingerprint[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[7], greater.fingerprint[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[8], greater.fingerprint[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[9], greater.fingerprint[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[10], greater.fingerprint[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[11], greater.fingerprint[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[12], greater.fingerprint[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[13], greater.fingerprint[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[14], greater.fingerprint[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[15], greater.fingerprint[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[16], greater.fingerprint[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[17], greater.fingerprint[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[18], greater.fingerprint[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[19], greater.fingerprint[19]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.n_certificate_bytes,
                        greater.n_certificate_bytes);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ed25519_certificate_dep_t lesser = info.test_msg;
    sbp_msg_ed25519_certificate_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.n_msg, greater.n_msg);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ed25519_certificate_dep_t>::id,
  // SbpMsgEd25519CertificateDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ed25519_certificate_dep_t>::name,
               "MSG_ED25519_CERTIFICATE_DEP");
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ed25519_certificate_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ed25519_certificate_dep_t>::get(
          const_sbp_msg_t);
  sbp_msg_ed25519_certificate_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ed25519_certificate_dep_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ed25519_certificate_dep_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.ed25519_certificate_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ed25519_certificate_dep_t>::to_sbp_msg(
      info.test_msg, &msg2);
  EXPECT_EQ(msg2.ed25519_certificate_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ed25519_certificate_dep_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ed25519_certificate_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[106];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ed25519_certificate_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 106);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 106), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ed25519_certificate_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ed25519_certificate_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 106);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
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

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgEd25519CertificateDep,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519CertificateDep0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgEd25519CertificateDep,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace