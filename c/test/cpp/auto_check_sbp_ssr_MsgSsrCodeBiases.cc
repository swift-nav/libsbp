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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrCodeBiases.yaml by generate.py.
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
class Testauto_check_sbp_ssr_MsgSsrCodeBiases0 : public ::testing::Test {
 public:
  Testauto_check_sbp_ssr_MsgSsrCodeBiases0() {
    assign(test_msg_.biases[0].code, 51);
    assign(test_msg_.biases[0].value, -31996);

    assign(test_msg_.biases[1].code, 240);
    assign(test_msg_.biases[1].value, 21368);

    assign(test_msg_.biases[2].code, 148);
    assign(test_msg_.biases[2].value, -10799);

    assign(test_msg_.biases[3].code, 62);
    assign(test_msg_.biases[3].value, -5916);

    assign(test_msg_.biases[4].code, 71);
    assign(test_msg_.biases[4].value, -17342);

    assign(test_msg_.biases[5].code, 210);
    assign(test_msg_.biases[5].value, 13952);

    assign(test_msg_.biases[6].code, 131);
    assign(test_msg_.biases[6].value, -32360);

    assign(test_msg_.biases[7].code, 111);
    assign(test_msg_.biases[7].value, -3445);

    assign(test_msg_.biases[8].code, 177);
    assign(test_msg_.biases[8].value, 11409);

    assign(test_msg_.biases[9].code, 9);
    assign(test_msg_.biases[9].value, -12299);

    assign(test_msg_.biases[10].code, 241);
    assign(test_msg_.biases[10].value, -26934);

    assign(test_msg_.biases[11].code, 141);
    assign(test_msg_.biases[11].value, -24782);

    assign(test_msg_.biases[12].code, 220);
    assign(test_msg_.biases[12].value, 9611);

    assign(test_msg_.biases[13].code, 187);
    assign(test_msg_.biases[13].value, -16542);

    assign(test_msg_.biases[14].code, 23);
    assign(test_msg_.biases[14].value, -30592);

    assign(test_msg_.biases[15].code, 167);
    assign(test_msg_.biases[15].value, 1736);

    assign(test_msg_.biases[16].code, 211);
    assign(test_msg_.biases[16].value, 5978);

    assign(test_msg_.biases[17].code, 244);
    assign(test_msg_.biases[17].value, -10358);

    assign(test_msg_.biases[18].code, 209);
    assign(test_msg_.biases[18].value, 3467);

    assign(test_msg_.biases[19].code, 101);
    assign(test_msg_.biases[19].value, 1824);

    assign(test_msg_.biases[20].code, 18);
    assign(test_msg_.biases[20].value, 17949);

    assign(test_msg_.biases[21].code, 250);
    assign(test_msg_.biases[21].value, 18797);

    assign(test_msg_.biases[22].code, 202);
    assign(test_msg_.biases[22].value, -28593);

    assign(test_msg_.biases[23].code, 9);
    assign(test_msg_.biases[23].value, 17810);

    assign(test_msg_.biases[24].code, 241);
    assign(test_msg_.biases[24].value, 5684);

    assign(test_msg_.biases[25].code, 99);
    assign(test_msg_.biases[25].value, -13214);

    assign(test_msg_.biases[26].code, 3);
    assign(test_msg_.biases[26].value, -6485);

    assign(test_msg_.biases[27].code, 180);
    assign(test_msg_.biases[27].value, 15947);

    assign(test_msg_.biases[28].code, 145);
    assign(test_msg_.biases[28].value, -32170);

    assign(test_msg_.biases[29].code, 31);
    assign(test_msg_.biases[29].value, -25826);

    assign(test_msg_.biases[30].code, 37);
    assign(test_msg_.biases[30].value, 14098);

    assign(test_msg_.biases[31].code, 210);
    assign(test_msg_.biases[31].value, 32551);

    assign(test_msg_.biases[32].code, 242);
    assign(test_msg_.biases[32].value, 3394);

    assign(test_msg_.biases[33].code, 237);
    assign(test_msg_.biases[33].value, -21864);

    assign(test_msg_.biases[34].code, 212);
    assign(test_msg_.biases[34].value, -2545);

    assign(test_msg_.biases[35].code, 59);
    assign(test_msg_.biases[35].value, -19362);

    assign(test_msg_.biases[36].code, 195);
    assign(test_msg_.biases[36].value, 17821);

    assign(test_msg_.biases[37].code, 100);
    assign(test_msg_.biases[37].value, 4215);

    assign(test_msg_.biases[38].code, 68);
    assign(test_msg_.biases[38].value, -20557);

    assign(test_msg_.biases[39].code, 144);
    assign(test_msg_.biases[39].value, 20849);

    assign(test_msg_.biases[40].code, 82);
    assign(test_msg_.biases[40].value, -26850);

    assign(test_msg_.biases[41].code, 21);
    assign(test_msg_.biases[41].value, 10605);

    assign(test_msg_.biases[42].code, 225);
    assign(test_msg_.biases[42].value, 19720);

    assign(test_msg_.biases[43].code, 164);
    assign(test_msg_.biases[43].value, 157);

    assign(test_msg_.biases[44].code, 73);
    assign(test_msg_.biases[44].value, 1566);

    assign(test_msg_.biases[45].code, 78);
    assign(test_msg_.biases[45].value, -28847);

    assign(test_msg_.biases[46].code, 116);
    assign(test_msg_.biases[46].value, -26640);

    assign(test_msg_.biases[47].code, 55);
    assign(test_msg_.biases[47].value, -22087);

    assign(test_msg_.biases[48].code, 254);
    assign(test_msg_.biases[48].value, 10035);

    assign(test_msg_.biases[49].code, 74);
    assign(test_msg_.biases[49].value, -2129);

    assign(test_msg_.biases[50].code, 34);
    assign(test_msg_.biases[50].value, 19041);

    assign(test_msg_.biases[51].code, 97);
    assign(test_msg_.biases[51].value, 12464);

    assign(test_msg_.biases[52].code, 236);
    assign(test_msg_.biases[52].value, 3245);

    assign(test_msg_.biases[53].code, 174);
    assign(test_msg_.biases[53].value, -32155);

    assign(test_msg_.biases[54].code, 30);
    assign(test_msg_.biases[54].value, -15959);

    assign(test_msg_.biases[55].code, 190);
    assign(test_msg_.biases[55].value, -15156);

    assign(test_msg_.biases[56].code, 123);
    assign(test_msg_.biases[56].value, 6507);

    assign(test_msg_.biases[57].code, 225);
    assign(test_msg_.biases[57].value, 2378);

    assign(test_msg_.biases[58].code, 10);
    assign(test_msg_.biases[58].value, 823);

    assign(test_msg_.biases[59].code, 131);
    assign(test_msg_.biases[59].value, 25590);

    assign(test_msg_.biases[60].code, 133);
    assign(test_msg_.biases[60].value, -7390);

    assign(test_msg_.biases[61].code, 203);
    assign(test_msg_.biases[61].value, 4676);

    assign(test_msg_.biases[62].code, 97);
    assign(test_msg_.biases[62].value, 23007);

    assign(test_msg_.biases[63].code, 192);
    assign(test_msg_.biases[63].value, 13046);

    assign(test_msg_.biases[64].code, 69);
    assign(test_msg_.biases[64].value, 2651);

    assign(test_msg_.biases[65].code, 151);
    assign(test_msg_.biases[65].value, 30282);

    assign(test_msg_.biases[66].code, 110);
    assign(test_msg_.biases[66].value, -22492);

    assign(test_msg_.biases[67].code, 247);
    assign(test_msg_.biases[67].value, 19872);

    assign(test_msg_.biases[68].code, 179);
    assign(test_msg_.biases[68].value, -19827);

    assign(test_msg_.biases[69].code, 99);
    assign(test_msg_.biases[69].value, 30911);

    assign(test_msg_.biases[70].code, 77);
    assign(test_msg_.biases[70].value, 23488);

    assign(test_msg_.biases[71].code, 224);
    assign(test_msg_.biases[71].value, -7679);

    assign(test_msg_.biases[72].code, 50);
    assign(test_msg_.biases[72].value, -28073);

    assign(test_msg_.biases[73].code, 148);
    assign(test_msg_.biases[73].value, 25838);

    assign(test_msg_.biases[74].code, 179);
    assign(test_msg_.biases[74].value, -7299);

    assign(test_msg_.biases[75].code, 215);
    assign(test_msg_.biases[75].value, -18328);

    assign(test_msg_.biases[76].code, 31);
    assign(test_msg_.biases[76].value, 23097);

    assign(test_msg_.biases[77].code, 79);
    assign(test_msg_.biases[77].value, -25579);

    assign(test_msg_.biases[78].code, 245);
    assign(test_msg_.biases[78].value, 15441);

    assign(test_msg_.biases[79].code, 93);
    assign(test_msg_.biases[79].value, 15530);

    assign(test_msg_.biases[80].code, 200);
    assign(test_msg_.biases[80].value, 3495);
    assign(test_msg_.iod_ssr, 132);
    assign(test_msg_.n_biases, 81);
    assign(test_msg_.sid.code, 241);
    assign(test_msg_.sid.sat, 133);
    assign(test_msg_.time.tow, 387144400);
    assign(test_msg_.time.wn, 16905);
    assign(test_msg_.update_interval, 254);
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
      : public sbp::MessageHandler<sbp_msg_ssr_code_biases_t> {
    using sbp::MessageHandler<sbp_msg_ssr_code_biases_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_code_biases_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ssr_code_biases_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgSsrCodeBiases,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_code_biases_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgSsrCodeBiases);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ssr_code_biases,
             sizeof(msg->ssr_code_biases));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ssr_code_biases_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ssr_code_biases, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgSsrCodeBiases);
    info.sender_id = 22311;
    info.preamble = 0x55;
    info.crc = 0x847d;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 253;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ssr_code_biases_t &lesser,
                        const sbp_msg_ssr_code_biases_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ssr_code_biases_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ssr_code_biases_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_ssr_code_biases_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ssr_code_biases_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ssr_code_biases_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ssr_code_biases_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgSsrCodeBiases, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrCodeBiases, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgSsrCodeBiases, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgSsrCodeBiases, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_ssr_code_biases_t test_msg_{};
  uint8_t encoded_frame_[253 + 8] = {
      85,  225, 5,   39,  87,  253, 208, 90,  19,  23,  9,   66,  133, 241, 254,
      132, 51,  4,   131, 240, 120, 83,  148, 209, 213, 62,  228, 232, 71,  66,
      188, 210, 128, 54,  131, 152, 129, 111, 139, 242, 177, 145, 44,  9,   245,
      207, 241, 202, 150, 141, 50,  159, 220, 139, 37,  187, 98,  191, 23,  128,
      136, 167, 200, 6,   211, 90,  23,  244, 138, 215, 209, 139, 13,  101, 32,
      7,   18,  29,  70,  250, 109, 73,  202, 79,  144, 9,   146, 69,  241, 52,
      22,  99,  98,  204, 3,   171, 230, 180, 75,  62,  145, 86,  130, 31,  30,
      155, 37,  18,  55,  210, 39,  127, 242, 66,  13,  237, 152, 170, 212, 15,
      246, 59,  94,  180, 195, 157, 69,  100, 119, 16,  68,  179, 175, 144, 113,
      81,  82,  30,  151, 21,  109, 41,  225, 8,   77,  164, 157, 0,   73,  30,
      6,   78,  81,  143, 116, 240, 151, 55,  185, 169, 254, 51,  39,  74,  175,
      247, 34,  97,  74,  97,  176, 48,  236, 173, 12,  174, 101, 130, 30,  169,
      193, 190, 204, 196, 123, 107, 25,  225, 74,  9,   10,  55,  3,   131, 246,
      99,  133, 34,  227, 203, 68,  18,  97,  223, 89,  192, 246, 50,  69,  91,
      10,  151, 74,  118, 110, 36,  168, 247, 160, 77,  179, 141, 178, 99,  191,
      120, 77,  192, 91,  224, 1,   226, 50,  87,  146, 148, 238, 100, 179, 125,
      227, 215, 104, 184, 31,  57,  90,  79,  21,  156, 245, 81,  60,  93,  170,
      60,  200, 167, 13,  125, 132,
  };
  uint8_t encoded_payload_[253] = {
      208, 90,  19,  23,  9,   66,  133, 241, 254, 132, 51,  4,   131, 240, 120,
      83,  148, 209, 213, 62,  228, 232, 71,  66,  188, 210, 128, 54,  131, 152,
      129, 111, 139, 242, 177, 145, 44,  9,   245, 207, 241, 202, 150, 141, 50,
      159, 220, 139, 37,  187, 98,  191, 23,  128, 136, 167, 200, 6,   211, 90,
      23,  244, 138, 215, 209, 139, 13,  101, 32,  7,   18,  29,  70,  250, 109,
      73,  202, 79,  144, 9,   146, 69,  241, 52,  22,  99,  98,  204, 3,   171,
      230, 180, 75,  62,  145, 86,  130, 31,  30,  155, 37,  18,  55,  210, 39,
      127, 242, 66,  13,  237, 152, 170, 212, 15,  246, 59,  94,  180, 195, 157,
      69,  100, 119, 16,  68,  179, 175, 144, 113, 81,  82,  30,  151, 21,  109,
      41,  225, 8,   77,  164, 157, 0,   73,  30,  6,   78,  81,  143, 116, 240,
      151, 55,  185, 169, 254, 51,  39,  74,  175, 247, 34,  97,  74,  97,  176,
      48,  236, 173, 12,  174, 101, 130, 30,  169, 193, 190, 204, 196, 123, 107,
      25,  225, 74,  9,   10,  55,  3,   131, 246, 99,  133, 34,  227, 203, 68,
      18,  97,  223, 89,  192, 246, 50,  69,  91,  10,  151, 74,  118, 110, 36,
      168, 247, 160, 77,  179, 141, 178, 99,  191, 120, 77,  192, 91,  224, 1,
      226, 50,  87,  146, 148, 238, 100, 179, 125, 227, 215, 104, 184, 31,  57,
      90,  79,  21,  156, 245, 81,  60,  93,  170, 60,  200, 167, 13,
  };
};

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ssr_code_biases_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgSsrCodeBiases, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[253];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ssr_code_biases_encode(&buf[0], sizeof(buf), &n_written,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 253);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 253), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgSsrCodeBiases, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 253);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 253), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[253];

  EXPECT_EQ(sbp_msg_ssr_code_biases_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 253), 0);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[253];

  for (uint8_t i = 0; i < 253; i++) {
    EXPECT_EQ(
        sbp_msg_ssr_code_biases_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_code_biases_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ssr_code_biases_decode(&info.encoded_payload[0],
                                           info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 253);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgSsrCodeBiases, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 253);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_code_biases_t msg{};

  EXPECT_EQ(sbp_msg_ssr_code_biases_decode(&info.encoded_payload[0],
                                           info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_code_biases_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ssr_code_biases_t t{};
      return sbp_msg_ssr_code_biases_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ssr_code_biases_t t{};
      t.n_biases = 1;
      return sbp_msg_ssr_code_biases_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ssr_code_biases_decode(&info.encoded_payload[0], i,
                                             nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, SlowRead) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, BadCRC) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ssr_code_biases_send(&state, info.sender_id, &info.test_msg,
                                         &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSsrCodeBiases, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgSsrCodeBiases, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSsrCodeBiases, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, Comparison) {
  auto info = get_test_msg_info();

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[0].code, greater.biases[0].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[0].value, greater.biases[0].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[1].code, greater.biases[1].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[1].value, greater.biases[1].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[2].code, greater.biases[2].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[2].value, greater.biases[2].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[3].code, greater.biases[3].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[3].value, greater.biases[3].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[4].code, greater.biases[4].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[4].value, greater.biases[4].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[5].code, greater.biases[5].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[5].value, greater.biases[5].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[6].code, greater.biases[6].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[6].value, greater.biases[6].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[7].code, greater.biases[7].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[7].value, greater.biases[7].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[8].code, greater.biases[8].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[8].value, greater.biases[8].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[9].code, greater.biases[9].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[9].value, greater.biases[9].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[10].code, greater.biases[10].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[10].value, greater.biases[10].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[11].code, greater.biases[11].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[11].value, greater.biases[11].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[12].code, greater.biases[12].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[12].value, greater.biases[12].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[13].code, greater.biases[13].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[13].value, greater.biases[13].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[14].code, greater.biases[14].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[14].value, greater.biases[14].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[15].code, greater.biases[15].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[15].value, greater.biases[15].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[16].code, greater.biases[16].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[16].value, greater.biases[16].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[17].code, greater.biases[17].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[17].value, greater.biases[17].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[18].code, greater.biases[18].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[18].value, greater.biases[18].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[19].code, greater.biases[19].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[19].value, greater.biases[19].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[20].code, greater.biases[20].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[20].value, greater.biases[20].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[21].code, greater.biases[21].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[21].value, greater.biases[21].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[22].code, greater.biases[22].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[22].value, greater.biases[22].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[23].code, greater.biases[23].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[23].value, greater.biases[23].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[24].code, greater.biases[24].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[24].value, greater.biases[24].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[25].code, greater.biases[25].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[25].value, greater.biases[25].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[26].code, greater.biases[26].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[26].value, greater.biases[26].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[27].code, greater.biases[27].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[27].value, greater.biases[27].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[28].code, greater.biases[28].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[28].value, greater.biases[28].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[29].code, greater.biases[29].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[29].value, greater.biases[29].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[30].code, greater.biases[30].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[30].value, greater.biases[30].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[31].code, greater.biases[31].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[31].value, greater.biases[31].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[32].code, greater.biases[32].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[32].value, greater.biases[32].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[33].code, greater.biases[33].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[33].value, greater.biases[33].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[34].code, greater.biases[34].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[34].value, greater.biases[34].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[35].code, greater.biases[35].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[35].value, greater.biases[35].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[36].code, greater.biases[36].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[36].value, greater.biases[36].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[37].code, greater.biases[37].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[37].value, greater.biases[37].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[38].code, greater.biases[38].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[38].value, greater.biases[38].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[39].code, greater.biases[39].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[39].value, greater.biases[39].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[40].code, greater.biases[40].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[40].value, greater.biases[40].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[41].code, greater.biases[41].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[41].value, greater.biases[41].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[42].code, greater.biases[42].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[42].value, greater.biases[42].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[43].code, greater.biases[43].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[43].value, greater.biases[43].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[44].code, greater.biases[44].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[44].value, greater.biases[44].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[45].code, greater.biases[45].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[45].value, greater.biases[45].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[46].code, greater.biases[46].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[46].value, greater.biases[46].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[47].code, greater.biases[47].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[47].value, greater.biases[47].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[48].code, greater.biases[48].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[48].value, greater.biases[48].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[49].code, greater.biases[49].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[49].value, greater.biases[49].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[50].code, greater.biases[50].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[50].value, greater.biases[50].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[51].code, greater.biases[51].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[51].value, greater.biases[51].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[52].code, greater.biases[52].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[52].value, greater.biases[52].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[53].code, greater.biases[53].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[53].value, greater.biases[53].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[54].code, greater.biases[54].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[54].value, greater.biases[54].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[55].code, greater.biases[55].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[55].value, greater.biases[55].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[56].code, greater.biases[56].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[56].value, greater.biases[56].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[57].code, greater.biases[57].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[57].value, greater.biases[57].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[58].code, greater.biases[58].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[58].value, greater.biases[58].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[59].code, greater.biases[59].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[59].value, greater.biases[59].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[60].code, greater.biases[60].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[60].value, greater.biases[60].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[61].code, greater.biases[61].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[61].value, greater.biases[61].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[62].code, greater.biases[62].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[62].value, greater.biases[62].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[63].code, greater.biases[63].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[63].value, greater.biases[63].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[64].code, greater.biases[64].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[64].value, greater.biases[64].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[65].code, greater.biases[65].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[65].value, greater.biases[65].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[66].code, greater.biases[66].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[66].value, greater.biases[66].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[67].code, greater.biases[67].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[67].value, greater.biases[67].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[68].code, greater.biases[68].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[68].value, greater.biases[68].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[69].code, greater.biases[69].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[69].value, greater.biases[69].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[70].code, greater.biases[70].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[70].value, greater.biases[70].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[71].code, greater.biases[71].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[71].value, greater.biases[71].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[72].code, greater.biases[72].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[72].value, greater.biases[72].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[73].code, greater.biases[73].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[73].value, greater.biases[73].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[74].code, greater.biases[74].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[74].value, greater.biases[74].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[75].code, greater.biases[75].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[75].value, greater.biases[75].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[76].code, greater.biases[76].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[76].value, greater.biases[76].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[77].code, greater.biases[77].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[77].value, greater.biases[77].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[78].code, greater.biases[78].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[78].value, greater.biases[78].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[79].code, greater.biases[79].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[79].value, greater.biases[79].value);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[80].code, greater.biases[80].code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.biases[80].value, greater.biases[80].value);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.iod_ssr, greater.iod_ssr);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.n_biases, greater.n_biases);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.code, greater.sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.sid.sat, greater.sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.time.tow, greater.time.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.time.wn, greater.time.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_code_biases_t lesser = info.test_msg;
    sbp_msg_ssr_code_biases_t greater = info.test_msg;
    make_lesser_greater(lesser.update_interval, greater.update_interval);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_code_biases_t>::id,
  // SbpMsgSsrCodeBiases);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ssr_code_biases_t>::name,
               "MSG_SSR_CODE_BIASES");
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ssr_code_biases_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_code_biases_t>::get(const_sbp_msg_t);
  sbp_msg_ssr_code_biases_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_code_biases_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ssr_code_biases_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.ssr_code_biases, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ssr_code_biases_t>::to_sbp_msg(info.test_msg,
                                                            &msg2);
  EXPECT_EQ(msg2.ssr_code_biases, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_ssr_code_biases_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_code_biases_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[253];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_code_biases_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 253);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 253), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_code_biases_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_code_biases_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 253);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgSsrCodeBiases,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrCodeBiases0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgSsrCodeBiases,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace