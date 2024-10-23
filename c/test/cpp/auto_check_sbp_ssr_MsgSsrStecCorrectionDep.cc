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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrectionDep.yaml by
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
class Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0 : public ::testing::Test {
 public:
  Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0() {
    assign(test_msg_.header.iod_atmo, 60);
    assign(test_msg_.header.num_msgs, 157);
    assign(test_msg_.header.seq_num, 112);
    assign(test_msg_.header.tile_id, 30066);
    assign(test_msg_.header.tile_set_id, 58526);
    assign(test_msg_.header.time.tow, 714907186);
    assign(test_msg_.header.time.wn, 40055);
    assign(test_msg_.header.update_interval, 47);
    assign(test_msg_.n_stec_sat_list, 21);

    assign(test_msg_.stec_sat_list[0].stec_coeff[0], -5289);

    assign(test_msg_.stec_sat_list[0].stec_coeff[1], -20141);

    assign(test_msg_.stec_sat_list[0].stec_coeff[2], 966);

    assign(test_msg_.stec_sat_list[0].stec_coeff[3], 2062);
    assign(test_msg_.stec_sat_list[0].stec_quality_indicator, 70);
    assign(test_msg_.stec_sat_list[0].sv_id.constellation, 40);
    assign(test_msg_.stec_sat_list[0].sv_id.satId, 132);

    assign(test_msg_.stec_sat_list[1].stec_coeff[0], -19147);

    assign(test_msg_.stec_sat_list[1].stec_coeff[1], -20902);

    assign(test_msg_.stec_sat_list[1].stec_coeff[2], -26889);

    assign(test_msg_.stec_sat_list[1].stec_coeff[3], -21446);
    assign(test_msg_.stec_sat_list[1].stec_quality_indicator, 44);
    assign(test_msg_.stec_sat_list[1].sv_id.constellation, 12);
    assign(test_msg_.stec_sat_list[1].sv_id.satId, 70);

    assign(test_msg_.stec_sat_list[2].stec_coeff[0], 32176);

    assign(test_msg_.stec_sat_list[2].stec_coeff[1], -20220);

    assign(test_msg_.stec_sat_list[2].stec_coeff[2], 29157);

    assign(test_msg_.stec_sat_list[2].stec_coeff[3], 19726);
    assign(test_msg_.stec_sat_list[2].stec_quality_indicator, 119);
    assign(test_msg_.stec_sat_list[2].sv_id.constellation, 179);
    assign(test_msg_.stec_sat_list[2].sv_id.satId, 247);

    assign(test_msg_.stec_sat_list[3].stec_coeff[0], -8651);

    assign(test_msg_.stec_sat_list[3].stec_coeff[1], -27973);

    assign(test_msg_.stec_sat_list[3].stec_coeff[2], 23546);

    assign(test_msg_.stec_sat_list[3].stec_coeff[3], -10284);
    assign(test_msg_.stec_sat_list[3].stec_quality_indicator, 23);
    assign(test_msg_.stec_sat_list[3].sv_id.constellation, 185);
    assign(test_msg_.stec_sat_list[3].sv_id.satId, 153);

    assign(test_msg_.stec_sat_list[4].stec_coeff[0], 27486);

    assign(test_msg_.stec_sat_list[4].stec_coeff[1], 23329);

    assign(test_msg_.stec_sat_list[4].stec_coeff[2], 234);

    assign(test_msg_.stec_sat_list[4].stec_coeff[3], -29739);
    assign(test_msg_.stec_sat_list[4].stec_quality_indicator, 250);
    assign(test_msg_.stec_sat_list[4].sv_id.constellation, 107);
    assign(test_msg_.stec_sat_list[4].sv_id.satId, 14);

    assign(test_msg_.stec_sat_list[5].stec_coeff[0], 18965);

    assign(test_msg_.stec_sat_list[5].stec_coeff[1], -22098);

    assign(test_msg_.stec_sat_list[5].stec_coeff[2], 22077);

    assign(test_msg_.stec_sat_list[5].stec_coeff[3], -29093);
    assign(test_msg_.stec_sat_list[5].stec_quality_indicator, 50);
    assign(test_msg_.stec_sat_list[5].sv_id.constellation, 179);
    assign(test_msg_.stec_sat_list[5].sv_id.satId, 95);

    assign(test_msg_.stec_sat_list[6].stec_coeff[0], -7898);

    assign(test_msg_.stec_sat_list[6].stec_coeff[1], 26002);

    assign(test_msg_.stec_sat_list[6].stec_coeff[2], -29879);

    assign(test_msg_.stec_sat_list[6].stec_coeff[3], 30008);
    assign(test_msg_.stec_sat_list[6].stec_quality_indicator, 9);
    assign(test_msg_.stec_sat_list[6].sv_id.constellation, 108);
    assign(test_msg_.stec_sat_list[6].sv_id.satId, 51);

    assign(test_msg_.stec_sat_list[7].stec_coeff[0], -12948);

    assign(test_msg_.stec_sat_list[7].stec_coeff[1], 4701);

    assign(test_msg_.stec_sat_list[7].stec_coeff[2], -15597);

    assign(test_msg_.stec_sat_list[7].stec_coeff[3], -13791);
    assign(test_msg_.stec_sat_list[7].stec_quality_indicator, 213);
    assign(test_msg_.stec_sat_list[7].sv_id.constellation, 37);
    assign(test_msg_.stec_sat_list[7].sv_id.satId, 82);

    assign(test_msg_.stec_sat_list[8].stec_coeff[0], -17283);

    assign(test_msg_.stec_sat_list[8].stec_coeff[1], 14455);

    assign(test_msg_.stec_sat_list[8].stec_coeff[2], -27067);

    assign(test_msg_.stec_sat_list[8].stec_coeff[3], 19606);
    assign(test_msg_.stec_sat_list[8].stec_quality_indicator, 178);
    assign(test_msg_.stec_sat_list[8].sv_id.constellation, 206);
    assign(test_msg_.stec_sat_list[8].sv_id.satId, 87);

    assign(test_msg_.stec_sat_list[9].stec_coeff[0], -12215);

    assign(test_msg_.stec_sat_list[9].stec_coeff[1], -6072);

    assign(test_msg_.stec_sat_list[9].stec_coeff[2], -1528);

    assign(test_msg_.stec_sat_list[9].stec_coeff[3], -19765);
    assign(test_msg_.stec_sat_list[9].stec_quality_indicator, 18);
    assign(test_msg_.stec_sat_list[9].sv_id.constellation, 131);
    assign(test_msg_.stec_sat_list[9].sv_id.satId, 3);

    assign(test_msg_.stec_sat_list[10].stec_coeff[0], 12630);

    assign(test_msg_.stec_sat_list[10].stec_coeff[1], -19721);

    assign(test_msg_.stec_sat_list[10].stec_coeff[2], 14502);

    assign(test_msg_.stec_sat_list[10].stec_coeff[3], 2591);
    assign(test_msg_.stec_sat_list[10].stec_quality_indicator, 252);
    assign(test_msg_.stec_sat_list[10].sv_id.constellation, 163);
    assign(test_msg_.stec_sat_list[10].sv_id.satId, 170);

    assign(test_msg_.stec_sat_list[11].stec_coeff[0], -23340);

    assign(test_msg_.stec_sat_list[11].stec_coeff[1], -24063);

    assign(test_msg_.stec_sat_list[11].stec_coeff[2], 4650);

    assign(test_msg_.stec_sat_list[11].stec_coeff[3], -22148);
    assign(test_msg_.stec_sat_list[11].stec_quality_indicator, 241);
    assign(test_msg_.stec_sat_list[11].sv_id.constellation, 213);
    assign(test_msg_.stec_sat_list[11].sv_id.satId, 119);

    assign(test_msg_.stec_sat_list[12].stec_coeff[0], 5944);

    assign(test_msg_.stec_sat_list[12].stec_coeff[1], 32142);

    assign(test_msg_.stec_sat_list[12].stec_coeff[2], 30760);

    assign(test_msg_.stec_sat_list[12].stec_coeff[3], 11587);
    assign(test_msg_.stec_sat_list[12].stec_quality_indicator, 26);
    assign(test_msg_.stec_sat_list[12].sv_id.constellation, 158);
    assign(test_msg_.stec_sat_list[12].sv_id.satId, 121);

    assign(test_msg_.stec_sat_list[13].stec_coeff[0], 3095);

    assign(test_msg_.stec_sat_list[13].stec_coeff[1], 22769);

    assign(test_msg_.stec_sat_list[13].stec_coeff[2], -4283);

    assign(test_msg_.stec_sat_list[13].stec_coeff[3], 14844);
    assign(test_msg_.stec_sat_list[13].stec_quality_indicator, 110);
    assign(test_msg_.stec_sat_list[13].sv_id.constellation, 235);
    assign(test_msg_.stec_sat_list[13].sv_id.satId, 126);

    assign(test_msg_.stec_sat_list[14].stec_coeff[0], -21032);

    assign(test_msg_.stec_sat_list[14].stec_coeff[1], -19726);

    assign(test_msg_.stec_sat_list[14].stec_coeff[2], 1297);

    assign(test_msg_.stec_sat_list[14].stec_coeff[3], -22049);
    assign(test_msg_.stec_sat_list[14].stec_quality_indicator, 201);
    assign(test_msg_.stec_sat_list[14].sv_id.constellation, 44);
    assign(test_msg_.stec_sat_list[14].sv_id.satId, 93);

    assign(test_msg_.stec_sat_list[15].stec_coeff[0], 619);

    assign(test_msg_.stec_sat_list[15].stec_coeff[1], -5744);

    assign(test_msg_.stec_sat_list[15].stec_coeff[2], 22542);

    assign(test_msg_.stec_sat_list[15].stec_coeff[3], -12000);
    assign(test_msg_.stec_sat_list[15].stec_quality_indicator, 77);
    assign(test_msg_.stec_sat_list[15].sv_id.constellation, 3);
    assign(test_msg_.stec_sat_list[15].sv_id.satId, 192);

    assign(test_msg_.stec_sat_list[16].stec_coeff[0], 10651);

    assign(test_msg_.stec_sat_list[16].stec_coeff[1], -2889);

    assign(test_msg_.stec_sat_list[16].stec_coeff[2], 21150);

    assign(test_msg_.stec_sat_list[16].stec_coeff[3], 26421);
    assign(test_msg_.stec_sat_list[16].stec_quality_indicator, 123);
    assign(test_msg_.stec_sat_list[16].sv_id.constellation, 17);
    assign(test_msg_.stec_sat_list[16].sv_id.satId, 1);

    assign(test_msg_.stec_sat_list[17].stec_coeff[0], -19165);

    assign(test_msg_.stec_sat_list[17].stec_coeff[1], 30229);

    assign(test_msg_.stec_sat_list[17].stec_coeff[2], -1282);

    assign(test_msg_.stec_sat_list[17].stec_coeff[3], -18382);
    assign(test_msg_.stec_sat_list[17].stec_quality_indicator, 185);
    assign(test_msg_.stec_sat_list[17].sv_id.constellation, 202);
    assign(test_msg_.stec_sat_list[17].sv_id.satId, 14);

    assign(test_msg_.stec_sat_list[18].stec_coeff[0], -23752);

    assign(test_msg_.stec_sat_list[18].stec_coeff[1], 32433);

    assign(test_msg_.stec_sat_list[18].stec_coeff[2], 20441);

    assign(test_msg_.stec_sat_list[18].stec_coeff[3], -4181);
    assign(test_msg_.stec_sat_list[18].stec_quality_indicator, 45);
    assign(test_msg_.stec_sat_list[18].sv_id.constellation, 31);
    assign(test_msg_.stec_sat_list[18].sv_id.satId, 50);

    assign(test_msg_.stec_sat_list[19].stec_coeff[0], -13968);

    assign(test_msg_.stec_sat_list[19].stec_coeff[1], -29322);

    assign(test_msg_.stec_sat_list[19].stec_coeff[2], -23790);

    assign(test_msg_.stec_sat_list[19].stec_coeff[3], 9063);
    assign(test_msg_.stec_sat_list[19].stec_quality_indicator, 238);
    assign(test_msg_.stec_sat_list[19].sv_id.constellation, 188);
    assign(test_msg_.stec_sat_list[19].sv_id.satId, 237);

    assign(test_msg_.stec_sat_list[20].stec_coeff[0], 4737);

    assign(test_msg_.stec_sat_list[20].stec_coeff[1], 21877);

    assign(test_msg_.stec_sat_list[20].stec_coeff[2], 20414);

    assign(test_msg_.stec_sat_list[20].stec_coeff[3], -10286);
    assign(test_msg_.stec_sat_list[20].stec_quality_indicator, 82);
    assign(test_msg_.stec_sat_list[20].sv_id.constellation, 21);
    assign(test_msg_.stec_sat_list[20].sv_id.satId, 63);
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
      : public sbp::MessageHandler<sbp_msg_ssr_stec_correction_dep_t> {
    using sbp::MessageHandler<
        sbp_msg_ssr_stec_correction_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_stec_correction_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ssr_stec_correction_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgSsrStecCorrectionDep,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_stec_correction_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgSsrStecCorrectionDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ssr_stec_correction_dep,
             sizeof(msg->ssr_stec_correction_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ssr_stec_correction_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ssr_stec_correction_dep, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgSsrStecCorrectionDep);
    info.sender_id = 38860;
    info.preamble = 0x55;
    info.crc = 0xb1e3;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 245;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ssr_stec_correction_dep_t &lesser,
                        const sbp_msg_ssr_stec_correction_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_t>::to_sbp_msg(
            lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ssr_stec_correction_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ssr_stec_correction_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrStecCorrectionDep, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrStecCorrectionDep, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgSsrStecCorrectionDep, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgSsrStecCorrectionDep, &wrapped_greater,
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
  sbp_msg_ssr_stec_correction_dep_t test_msg_{};
  uint8_t encoded_frame_[245 + 8] = {
      85,  251, 5,   204, 151, 245, 158, 228, 114, 117, 50,  158, 156, 42,  119,
      156, 157, 112, 47,  60,  132, 40,  70,  87,  235, 83,  177, 198, 3,   14,
      8,   70,  12,  44,  53,  181, 90,  174, 247, 150, 58,  172, 247, 179, 119,
      176, 125, 4,   177, 229, 113, 14,  77,  153, 185, 23,  53,  222, 187, 146,
      250, 91,  212, 215, 14,  107, 250, 94,  107, 33,  91,  234, 0,   213, 139,
      95,  179, 50,  21,  74,  174, 169, 61,  86,  91,  142, 51,  108, 9,   38,
      225, 146, 101, 73,  139, 56,  117, 82,  37,  213, 108, 205, 93,  18,  19,
      195, 33,  202, 87,  206, 178, 125, 188, 119, 56,  69,  150, 150, 76,  3,
      131, 18,  73,  208, 72,  232, 8,   250, 203, 178, 170, 163, 252, 86,  49,
      247, 178, 166, 56,  31,  10,  119, 213, 241, 212, 164, 1,   162, 42,  18,
      124, 169, 121, 158, 26,  56,  23,  142, 125, 40,  120, 67,  45,  126, 235,
      110, 23,  12,  241, 88,  69,  239, 252, 57,  93,  44,  201, 216, 173, 242,
      178, 17,  5,   223, 169, 192, 3,   77,  107, 2,   144, 233, 14,  88,  32,
      209, 1,   17,  123, 155, 41,  183, 244, 158, 82,  53,  103, 14,  202, 185,
      35,  181, 21,  118, 254, 250, 50,  184, 50,  31,  45,  56,  163, 177, 126,
      217, 79,  171, 239, 237, 188, 238, 112, 201, 118, 141, 18,  163, 103, 35,
      63,  21,  82,  129, 18,  117, 85,  190, 79,  210, 215, 227, 177,
  };
  uint8_t encoded_payload_[245] = {
      158, 228, 114, 117, 50,  158, 156, 42,  119, 156, 157, 112, 47,  60,  132,
      40,  70,  87,  235, 83,  177, 198, 3,   14,  8,   70,  12,  44,  53,  181,
      90,  174, 247, 150, 58,  172, 247, 179, 119, 176, 125, 4,   177, 229, 113,
      14,  77,  153, 185, 23,  53,  222, 187, 146, 250, 91,  212, 215, 14,  107,
      250, 94,  107, 33,  91,  234, 0,   213, 139, 95,  179, 50,  21,  74,  174,
      169, 61,  86,  91,  142, 51,  108, 9,   38,  225, 146, 101, 73,  139, 56,
      117, 82,  37,  213, 108, 205, 93,  18,  19,  195, 33,  202, 87,  206, 178,
      125, 188, 119, 56,  69,  150, 150, 76,  3,   131, 18,  73,  208, 72,  232,
      8,   250, 203, 178, 170, 163, 252, 86,  49,  247, 178, 166, 56,  31,  10,
      119, 213, 241, 212, 164, 1,   162, 42,  18,  124, 169, 121, 158, 26,  56,
      23,  142, 125, 40,  120, 67,  45,  126, 235, 110, 23,  12,  241, 88,  69,
      239, 252, 57,  93,  44,  201, 216, 173, 242, 178, 17,  5,   223, 169, 192,
      3,   77,  107, 2,   144, 233, 14,  88,  32,  209, 1,   17,  123, 155, 41,
      183, 244, 158, 82,  53,  103, 14,  202, 185, 35,  181, 21,  118, 254, 250,
      50,  184, 50,  31,  45,  56,  163, 177, 126, 217, 79,  171, 239, 237, 188,
      238, 112, 201, 118, 141, 18,  163, 103, 35,  63,  21,  82,  129, 18,  117,
      85,  190, 79,  210, 215,
  };
};

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgSsrStecCorrectionDep,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[245];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_encode(&buf[0], sizeof(buf),
                                                   &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 245);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 245), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(
      sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                         SbpMsgSsrStecCorrectionDep, &info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(n_written, 245);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 245), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[245];

  EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_encode(&buf[0], sizeof(buf),
                                                   nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 245), 0);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[245];

  for (uint8_t i = 0; i < 245; i++) {
    EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_encode(&buf[0], i, nullptr,
                                                     &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_stec_correction_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 245);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgSsrStecCorrectionDep, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 245);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_stec_correction_dep_t msg{};

  EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_stec_correction_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ssr_stec_correction_dep_t t{};
      return sbp_msg_ssr_stec_correction_dep_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ssr_stec_correction_dep_t t{};
      t.n_stec_sat_list = 1;
      return sbp_msg_ssr_stec_correction_dep_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_decode(&info.encoded_payload[0],
                                                     i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, SlowRead) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, BadCRC) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSsrStecCorrectionDep, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(
        sbp_message_send(&state, SbpMsgSsrStecCorrectionDep, info.sender_id,
                         &info.test_msg_wrapped, &Writer::write_c),
        SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSsrStecCorrectionDep, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.header.iod_atmo, greater.header.iod_atmo);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.header.num_msgs, greater.header.num_msgs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.header.seq_num, greater.header.seq_num);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.header.tile_id, greater.header.tile_id);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.header.tile_set_id, greater.header.tile_set_id);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.header.time.tow, greater.header.time.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.header.time.wn, greater.header.time.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.header.update_interval,
                        greater.header.update_interval);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.n_stec_sat_list, greater.n_stec_sat_list);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[0].stec_coeff[0],
                        greater.stec_sat_list[0].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[0].stec_coeff[1],
                        greater.stec_sat_list[0].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[0].stec_coeff[2],
                        greater.stec_sat_list[0].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[0].stec_coeff[3],
                        greater.stec_sat_list[0].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[0].stec_quality_indicator,
                        greater.stec_sat_list[0].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[0].sv_id.constellation,
                        greater.stec_sat_list[0].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[0].sv_id.satId,
                        greater.stec_sat_list[0].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[1].stec_coeff[0],
                        greater.stec_sat_list[1].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[1].stec_coeff[1],
                        greater.stec_sat_list[1].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[1].stec_coeff[2],
                        greater.stec_sat_list[1].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[1].stec_coeff[3],
                        greater.stec_sat_list[1].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[1].stec_quality_indicator,
                        greater.stec_sat_list[1].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[1].sv_id.constellation,
                        greater.stec_sat_list[1].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[1].sv_id.satId,
                        greater.stec_sat_list[1].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[2].stec_coeff[0],
                        greater.stec_sat_list[2].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[2].stec_coeff[1],
                        greater.stec_sat_list[2].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[2].stec_coeff[2],
                        greater.stec_sat_list[2].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[2].stec_coeff[3],
                        greater.stec_sat_list[2].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[2].stec_quality_indicator,
                        greater.stec_sat_list[2].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[2].sv_id.constellation,
                        greater.stec_sat_list[2].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[2].sv_id.satId,
                        greater.stec_sat_list[2].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[3].stec_coeff[0],
                        greater.stec_sat_list[3].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[3].stec_coeff[1],
                        greater.stec_sat_list[3].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[3].stec_coeff[2],
                        greater.stec_sat_list[3].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[3].stec_coeff[3],
                        greater.stec_sat_list[3].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[3].stec_quality_indicator,
                        greater.stec_sat_list[3].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[3].sv_id.constellation,
                        greater.stec_sat_list[3].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[3].sv_id.satId,
                        greater.stec_sat_list[3].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[4].stec_coeff[0],
                        greater.stec_sat_list[4].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[4].stec_coeff[1],
                        greater.stec_sat_list[4].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[4].stec_coeff[2],
                        greater.stec_sat_list[4].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[4].stec_coeff[3],
                        greater.stec_sat_list[4].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[4].stec_quality_indicator,
                        greater.stec_sat_list[4].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[4].sv_id.constellation,
                        greater.stec_sat_list[4].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[4].sv_id.satId,
                        greater.stec_sat_list[4].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[5].stec_coeff[0],
                        greater.stec_sat_list[5].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[5].stec_coeff[1],
                        greater.stec_sat_list[5].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[5].stec_coeff[2],
                        greater.stec_sat_list[5].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[5].stec_coeff[3],
                        greater.stec_sat_list[5].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[5].stec_quality_indicator,
                        greater.stec_sat_list[5].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[5].sv_id.constellation,
                        greater.stec_sat_list[5].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[5].sv_id.satId,
                        greater.stec_sat_list[5].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[6].stec_coeff[0],
                        greater.stec_sat_list[6].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[6].stec_coeff[1],
                        greater.stec_sat_list[6].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[6].stec_coeff[2],
                        greater.stec_sat_list[6].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[6].stec_coeff[3],
                        greater.stec_sat_list[6].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[6].stec_quality_indicator,
                        greater.stec_sat_list[6].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[6].sv_id.constellation,
                        greater.stec_sat_list[6].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[6].sv_id.satId,
                        greater.stec_sat_list[6].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[7].stec_coeff[0],
                        greater.stec_sat_list[7].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[7].stec_coeff[1],
                        greater.stec_sat_list[7].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[7].stec_coeff[2],
                        greater.stec_sat_list[7].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[7].stec_coeff[3],
                        greater.stec_sat_list[7].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[7].stec_quality_indicator,
                        greater.stec_sat_list[7].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[7].sv_id.constellation,
                        greater.stec_sat_list[7].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[7].sv_id.satId,
                        greater.stec_sat_list[7].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[8].stec_coeff[0],
                        greater.stec_sat_list[8].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[8].stec_coeff[1],
                        greater.stec_sat_list[8].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[8].stec_coeff[2],
                        greater.stec_sat_list[8].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[8].stec_coeff[3],
                        greater.stec_sat_list[8].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[8].stec_quality_indicator,
                        greater.stec_sat_list[8].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[8].sv_id.constellation,
                        greater.stec_sat_list[8].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[8].sv_id.satId,
                        greater.stec_sat_list[8].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[9].stec_coeff[0],
                        greater.stec_sat_list[9].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[9].stec_coeff[1],
                        greater.stec_sat_list[9].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[9].stec_coeff[2],
                        greater.stec_sat_list[9].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[9].stec_coeff[3],
                        greater.stec_sat_list[9].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[9].stec_quality_indicator,
                        greater.stec_sat_list[9].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[9].sv_id.constellation,
                        greater.stec_sat_list[9].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[9].sv_id.satId,
                        greater.stec_sat_list[9].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[10].stec_coeff[0],
                        greater.stec_sat_list[10].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[10].stec_coeff[1],
                        greater.stec_sat_list[10].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[10].stec_coeff[2],
                        greater.stec_sat_list[10].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[10].stec_coeff[3],
                        greater.stec_sat_list[10].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[10].stec_quality_indicator,
                        greater.stec_sat_list[10].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[10].sv_id.constellation,
                        greater.stec_sat_list[10].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[10].sv_id.satId,
                        greater.stec_sat_list[10].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[11].stec_coeff[0],
                        greater.stec_sat_list[11].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[11].stec_coeff[1],
                        greater.stec_sat_list[11].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[11].stec_coeff[2],
                        greater.stec_sat_list[11].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[11].stec_coeff[3],
                        greater.stec_sat_list[11].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[11].stec_quality_indicator,
                        greater.stec_sat_list[11].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[11].sv_id.constellation,
                        greater.stec_sat_list[11].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[11].sv_id.satId,
                        greater.stec_sat_list[11].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[12].stec_coeff[0],
                        greater.stec_sat_list[12].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[12].stec_coeff[1],
                        greater.stec_sat_list[12].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[12].stec_coeff[2],
                        greater.stec_sat_list[12].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[12].stec_coeff[3],
                        greater.stec_sat_list[12].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[12].stec_quality_indicator,
                        greater.stec_sat_list[12].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[12].sv_id.constellation,
                        greater.stec_sat_list[12].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[12].sv_id.satId,
                        greater.stec_sat_list[12].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[13].stec_coeff[0],
                        greater.stec_sat_list[13].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[13].stec_coeff[1],
                        greater.stec_sat_list[13].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[13].stec_coeff[2],
                        greater.stec_sat_list[13].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[13].stec_coeff[3],
                        greater.stec_sat_list[13].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[13].stec_quality_indicator,
                        greater.stec_sat_list[13].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[13].sv_id.constellation,
                        greater.stec_sat_list[13].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[13].sv_id.satId,
                        greater.stec_sat_list[13].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[14].stec_coeff[0],
                        greater.stec_sat_list[14].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[14].stec_coeff[1],
                        greater.stec_sat_list[14].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[14].stec_coeff[2],
                        greater.stec_sat_list[14].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[14].stec_coeff[3],
                        greater.stec_sat_list[14].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[14].stec_quality_indicator,
                        greater.stec_sat_list[14].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[14].sv_id.constellation,
                        greater.stec_sat_list[14].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[14].sv_id.satId,
                        greater.stec_sat_list[14].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[15].stec_coeff[0],
                        greater.stec_sat_list[15].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[15].stec_coeff[1],
                        greater.stec_sat_list[15].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[15].stec_coeff[2],
                        greater.stec_sat_list[15].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[15].stec_coeff[3],
                        greater.stec_sat_list[15].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[15].stec_quality_indicator,
                        greater.stec_sat_list[15].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[15].sv_id.constellation,
                        greater.stec_sat_list[15].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[15].sv_id.satId,
                        greater.stec_sat_list[15].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[16].stec_coeff[0],
                        greater.stec_sat_list[16].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[16].stec_coeff[1],
                        greater.stec_sat_list[16].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[16].stec_coeff[2],
                        greater.stec_sat_list[16].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[16].stec_coeff[3],
                        greater.stec_sat_list[16].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[16].stec_quality_indicator,
                        greater.stec_sat_list[16].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[16].sv_id.constellation,
                        greater.stec_sat_list[16].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[16].sv_id.satId,
                        greater.stec_sat_list[16].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[17].stec_coeff[0],
                        greater.stec_sat_list[17].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[17].stec_coeff[1],
                        greater.stec_sat_list[17].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[17].stec_coeff[2],
                        greater.stec_sat_list[17].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[17].stec_coeff[3],
                        greater.stec_sat_list[17].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[17].stec_quality_indicator,
                        greater.stec_sat_list[17].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[17].sv_id.constellation,
                        greater.stec_sat_list[17].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[17].sv_id.satId,
                        greater.stec_sat_list[17].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[18].stec_coeff[0],
                        greater.stec_sat_list[18].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[18].stec_coeff[1],
                        greater.stec_sat_list[18].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[18].stec_coeff[2],
                        greater.stec_sat_list[18].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[18].stec_coeff[3],
                        greater.stec_sat_list[18].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[18].stec_quality_indicator,
                        greater.stec_sat_list[18].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[18].sv_id.constellation,
                        greater.stec_sat_list[18].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[18].sv_id.satId,
                        greater.stec_sat_list[18].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[19].stec_coeff[0],
                        greater.stec_sat_list[19].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[19].stec_coeff[1],
                        greater.stec_sat_list[19].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[19].stec_coeff[2],
                        greater.stec_sat_list[19].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[19].stec_coeff[3],
                        greater.stec_sat_list[19].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[19].stec_quality_indicator,
                        greater.stec_sat_list[19].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[19].sv_id.constellation,
                        greater.stec_sat_list[19].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[19].sv_id.satId,
                        greater.stec_sat_list[19].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[20].stec_coeff[0],
                        greater.stec_sat_list[20].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[20].stec_coeff[1],
                        greater.stec_sat_list[20].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[20].stec_coeff[2],
                        greater.stec_sat_list[20].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[20].stec_coeff[3],
                        greater.stec_sat_list[20].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[20].stec_quality_indicator,
                        greater.stec_sat_list[20].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[20].sv_id.constellation,
                        greater.stec_sat_list[20].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[20].sv_id.satId,
                        greater.stec_sat_list[20].sv_id.satId);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_t>::id,
  // SbpMsgSsrStecCorrectionDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_t>::name,
               "MSG_SSR_STEC_CORRECTION_DEP");
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ssr_stec_correction_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_t>::get(
          const_sbp_msg_t);
  sbp_msg_ssr_stec_correction_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.ssr_stec_correction_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_t>::to_sbp_msg(
      info.test_msg, &msg2);
  EXPECT_EQ(msg2.ssr_stec_correction_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[245];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 245);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 245), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_stec_correction_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 245);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgSsrStecCorrectionDep,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDep0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgSsrStecCorrectionDep,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace
