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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrPhaseBiases.yaml by generate.py.
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
class Testauto_check_sbp_ssr_MsgSsrPhaseBiases0 : public ::testing::Test {
 public:
  Testauto_check_sbp_ssr_MsgSsrPhaseBiases0() {
    assign(test_msg_.biases[0].bias, -1311498533);
    assign(test_msg_.biases[0].code, 29);
    assign(test_msg_.biases[0].discontinuity_counter, 193);
    assign(test_msg_.biases[0].integer_indicator, 250);
    assign(test_msg_.biases[0].widelane_integer_indicator, 245);

    assign(test_msg_.biases[1].bias, 1101319226);
    assign(test_msg_.biases[1].code, 207);
    assign(test_msg_.biases[1].discontinuity_counter, 146);
    assign(test_msg_.biases[1].integer_indicator, 187);
    assign(test_msg_.biases[1].widelane_integer_indicator, 33);

    assign(test_msg_.biases[2].bias, -64184056);
    assign(test_msg_.biases[2].code, 114);
    assign(test_msg_.biases[2].discontinuity_counter, 52);
    assign(test_msg_.biases[2].integer_indicator, 49);
    assign(test_msg_.biases[2].widelane_integer_indicator, 248);

    assign(test_msg_.biases[3].bias, -240298362);
    assign(test_msg_.biases[3].code, 166);
    assign(test_msg_.biases[3].discontinuity_counter, 124);
    assign(test_msg_.biases[3].integer_indicator, 168);
    assign(test_msg_.biases[3].widelane_integer_indicator, 232);

    assign(test_msg_.biases[4].bias, -1581740159);
    assign(test_msg_.biases[4].code, 174);
    assign(test_msg_.biases[4].discontinuity_counter, 155);
    assign(test_msg_.biases[4].integer_indicator, 44);
    assign(test_msg_.biases[4].widelane_integer_indicator, 142);

    assign(test_msg_.biases[5].bias, -1730297136);
    assign(test_msg_.biases[5].code, 211);
    assign(test_msg_.biases[5].discontinuity_counter, 189);
    assign(test_msg_.biases[5].integer_indicator, 15);
    assign(test_msg_.biases[5].widelane_integer_indicator, 36);

    assign(test_msg_.biases[6].bias, -1117221444);
    assign(test_msg_.biases[6].code, 16);
    assign(test_msg_.biases[6].discontinuity_counter, 34);
    assign(test_msg_.biases[6].integer_indicator, 203);
    assign(test_msg_.biases[6].widelane_integer_indicator, 87);

    assign(test_msg_.biases[7].bias, -1137604357);
    assign(test_msg_.biases[7].code, 102);
    assign(test_msg_.biases[7].discontinuity_counter, 22);
    assign(test_msg_.biases[7].integer_indicator, 156);
    assign(test_msg_.biases[7].widelane_integer_indicator, 252);

    assign(test_msg_.biases[8].bias, -1910370172);
    assign(test_msg_.biases[8].code, 157);
    assign(test_msg_.biases[8].discontinuity_counter, 49);
    assign(test_msg_.biases[8].integer_indicator, 222);
    assign(test_msg_.biases[8].widelane_integer_indicator, 245);

    assign(test_msg_.biases[9].bias, 1247996869);
    assign(test_msg_.biases[9].code, 228);
    assign(test_msg_.biases[9].discontinuity_counter, 221);
    assign(test_msg_.biases[9].integer_indicator, 85);
    assign(test_msg_.biases[9].widelane_integer_indicator, 139);

    assign(test_msg_.biases[10].bias, -1133446161);
    assign(test_msg_.biases[10].code, 107);
    assign(test_msg_.biases[10].discontinuity_counter, 38);
    assign(test_msg_.biases[10].integer_indicator, 70);
    assign(test_msg_.biases[10].widelane_integer_indicator, 36);

    assign(test_msg_.biases[11].bias, -720934762);
    assign(test_msg_.biases[11].code, 124);
    assign(test_msg_.biases[11].discontinuity_counter, 164);
    assign(test_msg_.biases[11].integer_indicator, 246);
    assign(test_msg_.biases[11].widelane_integer_indicator, 141);

    assign(test_msg_.biases[12].bias, 706252548);
    assign(test_msg_.biases[12].code, 44);
    assign(test_msg_.biases[12].discontinuity_counter, 192);
    assign(test_msg_.biases[12].integer_indicator, 21);
    assign(test_msg_.biases[12].widelane_integer_indicator, 244);

    assign(test_msg_.biases[13].bias, 388855338);
    assign(test_msg_.biases[13].code, 21);
    assign(test_msg_.biases[13].discontinuity_counter, 7);
    assign(test_msg_.biases[13].integer_indicator, 84);
    assign(test_msg_.biases[13].widelane_integer_indicator, 136);

    assign(test_msg_.biases[14].bias, 47517353);
    assign(test_msg_.biases[14].code, 174);
    assign(test_msg_.biases[14].discontinuity_counter, 54);
    assign(test_msg_.biases[14].integer_indicator, 175);
    assign(test_msg_.biases[14].widelane_integer_indicator, 129);

    assign(test_msg_.biases[15].bias, -2124125745);
    assign(test_msg_.biases[15].code, 197);
    assign(test_msg_.biases[15].discontinuity_counter, 13);
    assign(test_msg_.biases[15].integer_indicator, 98);
    assign(test_msg_.biases[15].widelane_integer_indicator, 60);

    assign(test_msg_.biases[16].bias, -1401812607);
    assign(test_msg_.biases[16].code, 72);
    assign(test_msg_.biases[16].discontinuity_counter, 140);
    assign(test_msg_.biases[16].integer_indicator, 136);
    assign(test_msg_.biases[16].widelane_integer_indicator, 240);

    assign(test_msg_.biases[17].bias, 60257151);
    assign(test_msg_.biases[17].code, 151);
    assign(test_msg_.biases[17].discontinuity_counter, 210);
    assign(test_msg_.biases[17].integer_indicator, 150);
    assign(test_msg_.biases[17].widelane_integer_indicator, 17);

    assign(test_msg_.biases[18].bias, 41820677);
    assign(test_msg_.biases[18].code, 242);
    assign(test_msg_.biases[18].discontinuity_counter, 14);
    assign(test_msg_.biases[18].integer_indicator, 254);
    assign(test_msg_.biases[18].widelane_integer_indicator, 215);

    assign(test_msg_.biases[19].bias, 1640616471);
    assign(test_msg_.biases[19].code, 215);
    assign(test_msg_.biases[19].discontinuity_counter, 176);
    assign(test_msg_.biases[19].integer_indicator, 65);
    assign(test_msg_.biases[19].widelane_integer_indicator, 38);

    assign(test_msg_.biases[20].bias, -744786918);
    assign(test_msg_.biases[20].code, 36);
    assign(test_msg_.biases[20].discontinuity_counter, 224);
    assign(test_msg_.biases[20].integer_indicator, 207);
    assign(test_msg_.biases[20].widelane_integer_indicator, 92);

    assign(test_msg_.biases[21].bias, 1966589763);
    assign(test_msg_.biases[21].code, 165);
    assign(test_msg_.biases[21].discontinuity_counter, 38);
    assign(test_msg_.biases[21].integer_indicator, 47);
    assign(test_msg_.biases[21].widelane_integer_indicator, 102);

    assign(test_msg_.biases[22].bias, 364366310);
    assign(test_msg_.biases[22].code, 36);
    assign(test_msg_.biases[22].discontinuity_counter, 1);
    assign(test_msg_.biases[22].integer_indicator, 169);
    assign(test_msg_.biases[22].widelane_integer_indicator, 33);

    assign(test_msg_.biases[23].bias, -1839031379);
    assign(test_msg_.biases[23].code, 42);
    assign(test_msg_.biases[23].discontinuity_counter, 173);
    assign(test_msg_.biases[23].integer_indicator, 62);
    assign(test_msg_.biases[23].widelane_integer_indicator, 147);

    assign(test_msg_.biases[24].bias, 31817639);
    assign(test_msg_.biases[24].code, 231);
    assign(test_msg_.biases[24].discontinuity_counter, 82);
    assign(test_msg_.biases[24].integer_indicator, 167);
    assign(test_msg_.biases[24].widelane_integer_indicator, 138);

    assign(test_msg_.biases[25].bias, -1619830156);
    assign(test_msg_.biases[25].code, 2);
    assign(test_msg_.biases[25].discontinuity_counter, 207);
    assign(test_msg_.biases[25].integer_indicator, 127);
    assign(test_msg_.biases[25].widelane_integer_indicator, 237);

    assign(test_msg_.biases[26].bias, -83375622);
    assign(test_msg_.biases[26].code, 3);
    assign(test_msg_.biases[26].discontinuity_counter, 145);
    assign(test_msg_.biases[26].integer_indicator, 42);
    assign(test_msg_.biases[26].widelane_integer_indicator, 66);

    assign(test_msg_.biases[27].bias, 1077458389);
    assign(test_msg_.biases[27].code, 2);
    assign(test_msg_.biases[27].discontinuity_counter, 26);
    assign(test_msg_.biases[27].integer_indicator, 75);
    assign(test_msg_.biases[27].widelane_integer_indicator, 230);

    assign(test_msg_.biases[28].bias, -883355501);
    assign(test_msg_.biases[28].code, 97);
    assign(test_msg_.biases[28].discontinuity_counter, 6);
    assign(test_msg_.biases[28].integer_indicator, 88);
    assign(test_msg_.biases[28].widelane_integer_indicator, 255);

    assign(test_msg_.biases[29].bias, -1448611273);
    assign(test_msg_.biases[29].code, 27);
    assign(test_msg_.biases[29].discontinuity_counter, 230);
    assign(test_msg_.biases[29].integer_indicator, 68);
    assign(test_msg_.biases[29].widelane_integer_indicator, 243);
    assign(test_msg_.dispersive_bias, 98);
    assign(test_msg_.iod_ssr, 230);
    assign(test_msg_.mw_consistency, 209);
    assign(test_msg_.n_biases, 30);
    assign(test_msg_.sid.code, 82);
    assign(test_msg_.sid.sat, 169);
    assign(test_msg_.time.tow, 210803409);
    assign(test_msg_.time.wn, 42197);
    assign(test_msg_.update_interval, 177);
    assign(test_msg_.yaw, 5881);
    assign(test_msg_.yaw_rate, 17);
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
      : public sbp::MessageHandler<sbp_msg_ssr_phase_biases_t> {
    using sbp::MessageHandler<sbp_msg_ssr_phase_biases_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_phase_biases_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ssr_phase_biases_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgSsrPhaseBiases,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_phase_biases_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgSsrPhaseBiases);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ssr_phase_biases,
             sizeof(msg->ssr_phase_biases));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ssr_phase_biases_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ssr_phase_biases, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgSsrPhaseBiases);
    info.sender_id = 52955;
    info.preamble = 0x55;
    info.crc = 0xf0db;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 255;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ssr_phase_biases_t &lesser,
                        const sbp_msg_ssr_phase_biases_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ssr_phase_biases_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ssr_phase_biases_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_ssr_phase_biases_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ssr_phase_biases_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ssr_phase_biases_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ssr_phase_biases_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgSsrPhaseBiases, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrPhaseBiases, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgSsrPhaseBiases, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgSsrPhaseBiases, &wrapped_greater,
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
  sbp_msg_ssr_phase_biases_t test_msg_{};
  uint8_t encoded_frame_[255 + 8] = {
      85,  230, 5,   219, 206, 255, 209, 154, 144, 12,  213, 164, 169, 82,  177,
      230, 98,  209, 249, 22,  17,  29,  250, 245, 193, 219, 30,  212, 177, 207,
      187, 33,  146, 58,  204, 164, 65,  114, 49,  248, 52,  8,   161, 44,  252,
      166, 168, 232, 124, 134, 86,  173, 241, 174, 44,  142, 155, 129, 143, 184,
      161, 211, 15,  36,  189, 208, 194, 221, 152, 16,  203, 87,  34,  188, 141,
      104, 189, 102, 156, 252, 22,  251, 136, 49,  188, 157, 222, 245, 49,  132,
      16,  34,  142, 228, 85,  139, 221, 197, 235, 98,  74,  107, 70,  36,  38,
      239, 251, 112, 188, 124, 246, 141, 164, 150, 104, 7,   213, 44,  21,  244,
      192, 4,   143, 24,  42,  21,  84,  136, 7,   42,  118, 45,  23,  174, 175,
      129, 54,  169, 14,  213, 2,   197, 98,  60,  13,  207, 105, 100, 129, 72,
      136, 240, 140, 129, 9,   114, 172, 151, 150, 17,  210, 127, 115, 151, 3,
      242, 254, 215, 14,  5,   34,  126, 2,   215, 65,  38,  176, 23,  210, 201,
      97,  36,  207, 92,  224, 26,  116, 155, 211, 165, 47,  102, 38,  67,  199,
      55,  117, 36,  169, 33,  1,   230, 201, 183, 21,  42,  62,  147, 173, 173,
      155, 98,  146, 231, 167, 138, 82,  167, 127, 229, 1,   2,   127, 237, 207,
      116, 90,  115, 159, 3,   42,  66,  145, 250, 201, 7,   251, 2,   75,  230,
      26,  213, 181, 56,  64,  97,  88,  255, 6,   147, 16,  89,  203, 27,  68,
      243, 230, 55,  242, 167, 169, 219, 240,
  };
  uint8_t encoded_payload_[255] = {
      209, 154, 144, 12,  213, 164, 169, 82,  177, 230, 98,  209, 249, 22,  17,
      29,  250, 245, 193, 219, 30,  212, 177, 207, 187, 33,  146, 58,  204, 164,
      65,  114, 49,  248, 52,  8,   161, 44,  252, 166, 168, 232, 124, 134, 86,
      173, 241, 174, 44,  142, 155, 129, 143, 184, 161, 211, 15,  36,  189, 208,
      194, 221, 152, 16,  203, 87,  34,  188, 141, 104, 189, 102, 156, 252, 22,
      251, 136, 49,  188, 157, 222, 245, 49,  132, 16,  34,  142, 228, 85,  139,
      221, 197, 235, 98,  74,  107, 70,  36,  38,  239, 251, 112, 188, 124, 246,
      141, 164, 150, 104, 7,   213, 44,  21,  244, 192, 4,   143, 24,  42,  21,
      84,  136, 7,   42,  118, 45,  23,  174, 175, 129, 54,  169, 14,  213, 2,
      197, 98,  60,  13,  207, 105, 100, 129, 72,  136, 240, 140, 129, 9,   114,
      172, 151, 150, 17,  210, 127, 115, 151, 3,   242, 254, 215, 14,  5,   34,
      126, 2,   215, 65,  38,  176, 23,  210, 201, 97,  36,  207, 92,  224, 26,
      116, 155, 211, 165, 47,  102, 38,  67,  199, 55,  117, 36,  169, 33,  1,
      230, 201, 183, 21,  42,  62,  147, 173, 173, 155, 98,  146, 231, 167, 138,
      82,  167, 127, 229, 1,   2,   127, 237, 207, 116, 90,  115, 159, 3,   42,
      66,  145, 250, 201, 7,   251, 2,   75,  230, 26,  213, 181, 56,  64,  97,
      88,  255, 6,   147, 16,  89,  203, 27,  68,  243, 230, 55,  242, 167, 169,
  };
};

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ssr_phase_biases_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgSsrPhaseBiases, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[255];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ssr_phase_biases_encode(&buf[0], sizeof(buf), &n_written,
                                            &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgSsrPhaseBiases, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[255];

  EXPECT_EQ(sbp_msg_ssr_phase_biases_encode(&buf[0], sizeof(buf), nullptr,
                                            &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[255];

  for (uint8_t i = 0; i < 255; i++) {
    EXPECT_EQ(
        sbp_msg_ssr_phase_biases_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_phase_biases_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ssr_phase_biases_decode(&info.encoded_payload[0],
                                            info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgSsrPhaseBiases, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_phase_biases_t msg{};

  EXPECT_EQ(sbp_msg_ssr_phase_biases_decode(&info.encoded_payload[0],
                                            info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_phase_biases_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ssr_phase_biases_t t{};
      return sbp_msg_ssr_phase_biases_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ssr_phase_biases_t t{};
      t.n_biases = 1;
      return sbp_msg_ssr_phase_biases_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ssr_phase_biases_decode(&info.encoded_payload[0], i,
                                              nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, SlowRead) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, BadCRC) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ssr_phase_biases_send(&state, info.sender_id,
                                          &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSsrPhaseBiases, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgSsrPhaseBiases, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSsrPhaseBiases, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, Comparison) {
  auto info = get_test_msg_info();

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[0].bias, greater.biases[0].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[0].code, greater.biases[0].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[0].discontinuity_counter,
                        greater.biases[0].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[0].integer_indicator,
                        greater.biases[0].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[0].widelane_integer_indicator,
                        greater.biases[0].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[1].bias, greater.biases[1].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[1].code, greater.biases[1].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[1].discontinuity_counter,
                        greater.biases[1].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[1].integer_indicator,
                        greater.biases[1].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[1].widelane_integer_indicator,
                        greater.biases[1].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[2].bias, greater.biases[2].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[2].code, greater.biases[2].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[2].discontinuity_counter,
                        greater.biases[2].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[2].integer_indicator,
                        greater.biases[2].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[2].widelane_integer_indicator,
                        greater.biases[2].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[3].bias, greater.biases[3].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[3].code, greater.biases[3].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[3].discontinuity_counter,
                        greater.biases[3].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[3].integer_indicator,
                        greater.biases[3].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[3].widelane_integer_indicator,
                        greater.biases[3].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[4].bias, greater.biases[4].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[4].code, greater.biases[4].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[4].discontinuity_counter,
                        greater.biases[4].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[4].integer_indicator,
                        greater.biases[4].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[4].widelane_integer_indicator,
                        greater.biases[4].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[5].bias, greater.biases[5].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[5].code, greater.biases[5].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[5].discontinuity_counter,
                        greater.biases[5].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[5].integer_indicator,
                        greater.biases[5].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[5].widelane_integer_indicator,
                        greater.biases[5].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[6].bias, greater.biases[6].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[6].code, greater.biases[6].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[6].discontinuity_counter,
                        greater.biases[6].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[6].integer_indicator,
                        greater.biases[6].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[6].widelane_integer_indicator,
                        greater.biases[6].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[7].bias, greater.biases[7].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[7].code, greater.biases[7].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[7].discontinuity_counter,
                        greater.biases[7].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[7].integer_indicator,
                        greater.biases[7].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[7].widelane_integer_indicator,
                        greater.biases[7].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[8].bias, greater.biases[8].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[8].code, greater.biases[8].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[8].discontinuity_counter,
                        greater.biases[8].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[8].integer_indicator,
                        greater.biases[8].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[8].widelane_integer_indicator,
                        greater.biases[8].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[9].bias, greater.biases[9].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[9].code, greater.biases[9].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[9].discontinuity_counter,
                        greater.biases[9].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[9].integer_indicator,
                        greater.biases[9].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[9].widelane_integer_indicator,
                        greater.biases[9].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[10].bias, greater.biases[10].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[10].code, greater.biases[10].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[10].discontinuity_counter,
                        greater.biases[10].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[10].integer_indicator,
                        greater.biases[10].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[10].widelane_integer_indicator,
                        greater.biases[10].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[11].bias, greater.biases[11].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[11].code, greater.biases[11].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[11].discontinuity_counter,
                        greater.biases[11].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[11].integer_indicator,
                        greater.biases[11].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[11].widelane_integer_indicator,
                        greater.biases[11].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[12].bias, greater.biases[12].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[12].code, greater.biases[12].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[12].discontinuity_counter,
                        greater.biases[12].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[12].integer_indicator,
                        greater.biases[12].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[12].widelane_integer_indicator,
                        greater.biases[12].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[13].bias, greater.biases[13].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[13].code, greater.biases[13].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[13].discontinuity_counter,
                        greater.biases[13].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[13].integer_indicator,
                        greater.biases[13].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[13].widelane_integer_indicator,
                        greater.biases[13].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[14].bias, greater.biases[14].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[14].code, greater.biases[14].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[14].discontinuity_counter,
                        greater.biases[14].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[14].integer_indicator,
                        greater.biases[14].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[14].widelane_integer_indicator,
                        greater.biases[14].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[15].bias, greater.biases[15].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[15].code, greater.biases[15].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[15].discontinuity_counter,
                        greater.biases[15].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[15].integer_indicator,
                        greater.biases[15].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[15].widelane_integer_indicator,
                        greater.biases[15].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[16].bias, greater.biases[16].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[16].code, greater.biases[16].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[16].discontinuity_counter,
                        greater.biases[16].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[16].integer_indicator,
                        greater.biases[16].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[16].widelane_integer_indicator,
                        greater.biases[16].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[17].bias, greater.biases[17].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[17].code, greater.biases[17].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[17].discontinuity_counter,
                        greater.biases[17].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[17].integer_indicator,
                        greater.biases[17].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[17].widelane_integer_indicator,
                        greater.biases[17].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[18].bias, greater.biases[18].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[18].code, greater.biases[18].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[18].discontinuity_counter,
                        greater.biases[18].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[18].integer_indicator,
                        greater.biases[18].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[18].widelane_integer_indicator,
                        greater.biases[18].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[19].bias, greater.biases[19].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[19].code, greater.biases[19].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[19].discontinuity_counter,
                        greater.biases[19].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[19].integer_indicator,
                        greater.biases[19].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[19].widelane_integer_indicator,
                        greater.biases[19].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[20].bias, greater.biases[20].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[20].code, greater.biases[20].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[20].discontinuity_counter,
                        greater.biases[20].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[20].integer_indicator,
                        greater.biases[20].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[20].widelane_integer_indicator,
                        greater.biases[20].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[21].bias, greater.biases[21].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[21].code, greater.biases[21].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[21].discontinuity_counter,
                        greater.biases[21].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[21].integer_indicator,
                        greater.biases[21].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[21].widelane_integer_indicator,
                        greater.biases[21].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[22].bias, greater.biases[22].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[22].code, greater.biases[22].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[22].discontinuity_counter,
                        greater.biases[22].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[22].integer_indicator,
                        greater.biases[22].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[22].widelane_integer_indicator,
                        greater.biases[22].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[23].bias, greater.biases[23].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[23].code, greater.biases[23].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[23].discontinuity_counter,
                        greater.biases[23].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[23].integer_indicator,
                        greater.biases[23].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[23].widelane_integer_indicator,
                        greater.biases[23].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[24].bias, greater.biases[24].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[24].code, greater.biases[24].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[24].discontinuity_counter,
                        greater.biases[24].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[24].integer_indicator,
                        greater.biases[24].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[24].widelane_integer_indicator,
                        greater.biases[24].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[25].bias, greater.biases[25].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[25].code, greater.biases[25].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[25].discontinuity_counter,
                        greater.biases[25].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[25].integer_indicator,
                        greater.biases[25].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[25].widelane_integer_indicator,
                        greater.biases[25].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[26].bias, greater.biases[26].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[26].code, greater.biases[26].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[26].discontinuity_counter,
                        greater.biases[26].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[26].integer_indicator,
                        greater.biases[26].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[26].widelane_integer_indicator,
                        greater.biases[26].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[27].bias, greater.biases[27].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[27].code, greater.biases[27].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[27].discontinuity_counter,
                        greater.biases[27].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[27].integer_indicator,
                        greater.biases[27].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[27].widelane_integer_indicator,
                        greater.biases[27].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[28].bias, greater.biases[28].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[28].code, greater.biases[28].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[28].discontinuity_counter,
                        greater.biases[28].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[28].integer_indicator,
                        greater.biases[28].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[28].widelane_integer_indicator,
                        greater.biases[28].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[29].bias, greater.biases[29].bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[29].code, greater.biases[29].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[29].discontinuity_counter,
                        greater.biases[29].discontinuity_counter);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[29].integer_indicator,
                        greater.biases[29].integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[29].widelane_integer_indicator,
                        greater.biases[29].widelane_integer_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.dispersive_bias, greater.dispersive_bias);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.iod_ssr, greater.iod_ssr);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.mw_consistency, greater.mw_consistency);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.n_biases, greater.n_biases);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.code, greater.sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.sat, greater.sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.time.tow, greater.time.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.time.wn, greater.time.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.update_interval, greater.update_interval);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.yaw, greater.yaw);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_phase_biases_t lesser = info.test_msg;
    sbp_msg_ssr_phase_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.yaw_rate, greater.yaw_rate);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_phase_biases_t>::id,
  // SbpMsgSsrPhaseBiases);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ssr_phase_biases_t>::name,
               "MSG_SSR_PHASE_BIASES");
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ssr_phase_biases_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_phase_biases_t>::get(const_sbp_msg_t);
  sbp_msg_ssr_phase_biases_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_phase_biases_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ssr_phase_biases_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.ssr_phase_biases, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ssr_phase_biases_t>::to_sbp_msg(info.test_msg,
                                                             &msg2);
  EXPECT_EQ(msg2.ssr_phase_biases, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_phase_biases_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_phase_biases_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[255];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_phase_biases_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_phase_biases_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_phase_biases_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgSsrPhaseBiases,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrPhaseBiases0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgSsrPhaseBiases,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace
