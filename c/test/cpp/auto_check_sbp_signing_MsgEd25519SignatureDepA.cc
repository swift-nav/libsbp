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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEd25519SignatureDepA.yaml by
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
class Testauto_check_sbp_signing_MsgEd25519SignatureDepA0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_signing_MsgEd25519SignatureDepA0() {
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
    assign(test_msg_.n_signed_messages, 25);

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

    assign(test_msg_.signed_messages[0], 5000);

    assign(test_msg_.signed_messages[1], 5234);

    assign(test_msg_.signed_messages[2], 5468);

    assign(test_msg_.signed_messages[3], 5702);

    assign(test_msg_.signed_messages[4], 5936);

    assign(test_msg_.signed_messages[5], 6170);

    assign(test_msg_.signed_messages[6], 6404);

    assign(test_msg_.signed_messages[7], 6638);

    assign(test_msg_.signed_messages[8], 6872);

    assign(test_msg_.signed_messages[9], 7106);

    assign(test_msg_.signed_messages[10], 7340);

    assign(test_msg_.signed_messages[11], 7574);

    assign(test_msg_.signed_messages[12], 7808);

    assign(test_msg_.signed_messages[13], 8042);

    assign(test_msg_.signed_messages[14], 8276);

    assign(test_msg_.signed_messages[15], 8510);

    assign(test_msg_.signed_messages[16], 8744);

    assign(test_msg_.signed_messages[17], 8978);

    assign(test_msg_.signed_messages[18], 9212);

    assign(test_msg_.signed_messages[19], 9446);

    assign(test_msg_.signed_messages[20], 9680);

    assign(test_msg_.signed_messages[21], 9914);

    assign(test_msg_.signed_messages[22], 10148);

    assign(test_msg_.signed_messages[23], 10382);

    assign(test_msg_.signed_messages[24], 10616);
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
      : public sbp::MessageHandler<sbp_msg_ed25519_signature_dep_a_t> {
    using sbp::MessageHandler<
        sbp_msg_ed25519_signature_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ed25519_signature_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ed25519_signature_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgEd25519SignatureDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ed25519_signature_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgEd25519SignatureDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ed25519_signature_dep_a,
             sizeof(msg->ed25519_signature_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ed25519_signature_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ed25519_signature_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgEd25519SignatureDepA);
    info.sender_id = 66;
    info.preamble = 0x55;
    info.crc = 0x6FA9;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 184;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ed25519_signature_dep_a_t &lesser,
                        const sbp_msg_ed25519_signature_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ed25519_signature_dep_a_t>::to_sbp_msg(
            lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ed25519_signature_dep_a_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_ed25519_signature_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ed25519_signature_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ed25519_signature_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ed25519_signature_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgEd25519SignatureDepA, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgEd25519SignatureDepA, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgEd25519SignatureDepA, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgEd25519SignatureDepA, &wrapped_greater,
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
  sbp_msg_ed25519_signature_dep_a_t test_msg_{};
  uint8_t encoded_frame_[184 + 8] = {
      85,  1,   12,  66,  0,   184, 0,   1,   2,   3,   4,   5,   6,   7,   8,
      9,   10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,
      24,  25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,
      39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,
      54,  55,  56,  57,  58,  59,  60,  61,  62,  63,  100, 101, 102, 103, 104,
      105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
      136, 19,  0,   0,   114, 20,  0,   0,   92,  21,  0,   0,   70,  22,  0,
      0,   48,  23,  0,   0,   26,  24,  0,   0,   4,   25,  0,   0,   238, 25,
      0,   0,   216, 26,  0,   0,   194, 27,  0,   0,   172, 28,  0,   0,   150,
      29,  0,   0,   128, 30,  0,   0,   106, 31,  0,   0,   84,  32,  0,   0,
      62,  33,  0,   0,   40,  34,  0,   0,   18,  35,  0,   0,   252, 35,  0,
      0,   230, 36,  0,   0,   208, 37,  0,   0,   186, 38,  0,   0,   164, 39,
      0,   0,   142, 40,  0,   0,   120, 41,  0,   0,   169, 111,
  };
  uint8_t encoded_payload_[184] = {
      0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,
      15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
      30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,
      45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
      60,  61,  62,  63,  100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
      111, 112, 113, 114, 115, 116, 117, 118, 119, 136, 19,  0,   0,   114, 20,
      0,   0,   92,  21,  0,   0,   70,  22,  0,   0,   48,  23,  0,   0,   26,
      24,  0,   0,   4,   25,  0,   0,   238, 25,  0,   0,   216, 26,  0,   0,
      194, 27,  0,   0,   172, 28,  0,   0,   150, 29,  0,   0,   128, 30,  0,
      0,   106, 31,  0,   0,   84,  32,  0,   0,   62,  33,  0,   0,   40,  34,
      0,   0,   18,  35,  0,   0,   252, 35,  0,   0,   230, 36,  0,   0,   208,
      37,  0,   0,   186, 38,  0,   0,   164, 39,  0,   0,   142, 40,  0,   0,
      120, 41,  0,   0,
  };
};

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ed25519_signature_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgEd25519SignatureDepA,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[184];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ed25519_signature_dep_a_encode(&buf[0], sizeof(buf),
                                                   &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 184);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 184), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(
      sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                         SbpMsgEd25519SignatureDepA, &info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(n_written, 184);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 184), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[184];

  EXPECT_EQ(sbp_msg_ed25519_signature_dep_a_encode(&buf[0], sizeof(buf),
                                                   nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 184), 0);
}
TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[184];

  for (uint8_t i = 0; i < 184; i++) {
    EXPECT_EQ(sbp_msg_ed25519_signature_dep_a_encode(&buf[0], i, nullptr,
                                                     &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ed25519_signature_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ed25519_signature_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 184);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgEd25519SignatureDepA, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 184);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ed25519_signature_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_ed25519_signature_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ed25519_signature_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ed25519_signature_dep_a_t t{};
      return sbp_msg_ed25519_signature_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ed25519_signature_dep_a_t t{};
      t.n_signed_messages = 1;
      return sbp_msg_ed25519_signature_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ed25519_signature_dep_a_decode(&info.encoded_payload[0],
                                                     i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
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

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
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

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0, SlowRead) {
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

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0, BadCRC) {
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

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ed25519_signature_dep_a_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEd25519SignatureDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(
        sbp_message_send(&state, SbpMsgEd25519SignatureDepA, info.sender_id,
                         &info.test_msg_wrapped, &Writer::write_c),
        SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEd25519SignatureDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0, Comparison) {
  auto info = get_test_msg_info();

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[0], greater.fingerprint[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[1], greater.fingerprint[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[2], greater.fingerprint[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[3], greater.fingerprint[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[4], greater.fingerprint[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[5], greater.fingerprint[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[6], greater.fingerprint[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[7], greater.fingerprint[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[8], greater.fingerprint[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[9], greater.fingerprint[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[10], greater.fingerprint[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[11], greater.fingerprint[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[12], greater.fingerprint[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[13], greater.fingerprint[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[14], greater.fingerprint[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[15], greater.fingerprint[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[16], greater.fingerprint[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[17], greater.fingerprint[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[18], greater.fingerprint[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.fingerprint[19], greater.fingerprint[19]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_signed_messages, greater.n_signed_messages);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[0], greater.signature[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[1], greater.signature[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[2], greater.signature[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[3], greater.signature[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[4], greater.signature[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[5], greater.signature[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[6], greater.signature[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[7], greater.signature[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[8], greater.signature[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[9], greater.signature[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[10], greater.signature[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[11], greater.signature[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[12], greater.signature[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[13], greater.signature[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[14], greater.signature[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[15], greater.signature[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[16], greater.signature[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[17], greater.signature[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[18], greater.signature[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[19], greater.signature[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[20], greater.signature[20]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[21], greater.signature[21]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[22], greater.signature[22]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[23], greater.signature[23]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[24], greater.signature[24]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[25], greater.signature[25]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[26], greater.signature[26]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[27], greater.signature[27]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[28], greater.signature[28]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[29], greater.signature[29]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[30], greater.signature[30]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[31], greater.signature[31]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[32], greater.signature[32]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[33], greater.signature[33]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[34], greater.signature[34]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[35], greater.signature[35]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[36], greater.signature[36]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[37], greater.signature[37]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[38], greater.signature[38]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[39], greater.signature[39]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[40], greater.signature[40]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[41], greater.signature[41]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[42], greater.signature[42]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[43], greater.signature[43]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[44], greater.signature[44]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[45], greater.signature[45]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[46], greater.signature[46]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[47], greater.signature[47]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[48], greater.signature[48]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[49], greater.signature[49]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[50], greater.signature[50]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[51], greater.signature[51]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[52], greater.signature[52]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[53], greater.signature[53]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[54], greater.signature[54]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[55], greater.signature[55]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[56], greater.signature[56]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[57], greater.signature[57]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[58], greater.signature[58]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[59], greater.signature[59]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[60], greater.signature[60]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[61], greater.signature[61]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[62], greater.signature[62]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[63], greater.signature[63]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[0], greater.signed_messages[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[1], greater.signed_messages[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[2], greater.signed_messages[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[3], greater.signed_messages[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[4], greater.signed_messages[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[5], greater.signed_messages[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[6], greater.signed_messages[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[7], greater.signed_messages[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[8], greater.signed_messages[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[9], greater.signed_messages[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[10],
                        greater.signed_messages[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[11],
                        greater.signed_messages[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[12],
                        greater.signed_messages[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[13],
                        greater.signed_messages[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[14],
                        greater.signed_messages[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[15],
                        greater.signed_messages[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[16],
                        greater.signed_messages[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[17],
                        greater.signed_messages[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[18],
                        greater.signed_messages[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[19],
                        greater.signed_messages[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[20],
                        greater.signed_messages[20]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[21],
                        greater.signed_messages[21]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[22],
                        greater.signed_messages[22]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[23],
                        greater.signed_messages[23]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ed25519_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ed25519_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[24],
                        greater.signed_messages[24]);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ed25519_signature_dep_a_t>::id,
  // SbpMsgEd25519SignatureDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ed25519_signature_dep_a_t>::name,
               "MSG_ED25519_SIGNATURE_DEP_A");
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ed25519_signature_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ed25519_signature_dep_a_t>::get(
          const_sbp_msg_t);
  sbp_msg_ed25519_signature_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ed25519_signature_dep_a_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ed25519_signature_dep_a_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.ed25519_signature_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ed25519_signature_dep_a_t>::to_sbp_msg(
      info.test_msg, &msg2);
  EXPECT_EQ(msg2.ed25519_signature_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ed25519_signature_dep_a_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ed25519_signature_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[184];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ed25519_signature_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 184);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 184), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ed25519_signature_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ed25519_signature_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 184);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
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

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgEd25519SignatureDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEd25519SignatureDepA0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgEd25519SignatureDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace