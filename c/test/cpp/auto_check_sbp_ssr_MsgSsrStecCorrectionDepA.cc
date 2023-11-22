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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrStecCorrectionDepA.yaml by
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
class Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0() {
    assign(test_msg_.header.iod_atmo, 4);
    assign(test_msg_.header.num_msgs, 147);
    assign(test_msg_.header.seq_num, 123);
    assign(test_msg_.header.time.tow, 3905179974);
    assign(test_msg_.header.time.wn, 11193);
    assign(test_msg_.header.update_interval, 39);
    assign(test_msg_.n_stec_sat_list, 22);

    assign(test_msg_.stec_sat_list[0].stec_coeff[0], -1951);

    assign(test_msg_.stec_sat_list[0].stec_coeff[1], -9854);

    assign(test_msg_.stec_sat_list[0].stec_coeff[2], 27353);

    assign(test_msg_.stec_sat_list[0].stec_coeff[3], 3130);
    assign(test_msg_.stec_sat_list[0].stec_quality_indicator, 111);
    assign(test_msg_.stec_sat_list[0].sv_id.constellation, 19);
    assign(test_msg_.stec_sat_list[0].sv_id.satId, 126);

    assign(test_msg_.stec_sat_list[1].stec_coeff[0], 24401);

    assign(test_msg_.stec_sat_list[1].stec_coeff[1], 4182);

    assign(test_msg_.stec_sat_list[1].stec_coeff[2], 21543);

    assign(test_msg_.stec_sat_list[1].stec_coeff[3], -12060);
    assign(test_msg_.stec_sat_list[1].stec_quality_indicator, 171);
    assign(test_msg_.stec_sat_list[1].sv_id.constellation, 230);
    assign(test_msg_.stec_sat_list[1].sv_id.satId, 65);

    assign(test_msg_.stec_sat_list[2].stec_coeff[0], -13469);

    assign(test_msg_.stec_sat_list[2].stec_coeff[1], -18883);

    assign(test_msg_.stec_sat_list[2].stec_coeff[2], 32066);

    assign(test_msg_.stec_sat_list[2].stec_coeff[3], 971);
    assign(test_msg_.stec_sat_list[2].stec_quality_indicator, 219);
    assign(test_msg_.stec_sat_list[2].sv_id.constellation, 81);
    assign(test_msg_.stec_sat_list[2].sv_id.satId, 201);

    assign(test_msg_.stec_sat_list[3].stec_coeff[0], 32220);

    assign(test_msg_.stec_sat_list[3].stec_coeff[1], 5436);

    assign(test_msg_.stec_sat_list[3].stec_coeff[2], -9635);

    assign(test_msg_.stec_sat_list[3].stec_coeff[3], -24841);
    assign(test_msg_.stec_sat_list[3].stec_quality_indicator, 100);
    assign(test_msg_.stec_sat_list[3].sv_id.constellation, 44);
    assign(test_msg_.stec_sat_list[3].sv_id.satId, 193);

    assign(test_msg_.stec_sat_list[4].stec_coeff[0], 3718);

    assign(test_msg_.stec_sat_list[4].stec_coeff[1], 12497);

    assign(test_msg_.stec_sat_list[4].stec_coeff[2], -10482);

    assign(test_msg_.stec_sat_list[4].stec_coeff[3], -27495);
    assign(test_msg_.stec_sat_list[4].stec_quality_indicator, 129);
    assign(test_msg_.stec_sat_list[4].sv_id.constellation, 93);
    assign(test_msg_.stec_sat_list[4].sv_id.satId, 207);

    assign(test_msg_.stec_sat_list[5].stec_coeff[0], -4940);

    assign(test_msg_.stec_sat_list[5].stec_coeff[1], -13875);

    assign(test_msg_.stec_sat_list[5].stec_coeff[2], 801);

    assign(test_msg_.stec_sat_list[5].stec_coeff[3], -13066);
    assign(test_msg_.stec_sat_list[5].stec_quality_indicator, 225);
    assign(test_msg_.stec_sat_list[5].sv_id.constellation, 72);
    assign(test_msg_.stec_sat_list[5].sv_id.satId, 147);

    assign(test_msg_.stec_sat_list[6].stec_coeff[0], -15868);

    assign(test_msg_.stec_sat_list[6].stec_coeff[1], -2369);

    assign(test_msg_.stec_sat_list[6].stec_coeff[2], -9396);

    assign(test_msg_.stec_sat_list[6].stec_coeff[3], -16609);
    assign(test_msg_.stec_sat_list[6].stec_quality_indicator, 98);
    assign(test_msg_.stec_sat_list[6].sv_id.constellation, 3);
    assign(test_msg_.stec_sat_list[6].sv_id.satId, 19);

    assign(test_msg_.stec_sat_list[7].stec_coeff[0], -1265);

    assign(test_msg_.stec_sat_list[7].stec_coeff[1], 4897);

    assign(test_msg_.stec_sat_list[7].stec_coeff[2], 13920);

    assign(test_msg_.stec_sat_list[7].stec_coeff[3], -28102);
    assign(test_msg_.stec_sat_list[7].stec_quality_indicator, 177);
    assign(test_msg_.stec_sat_list[7].sv_id.constellation, 79);
    assign(test_msg_.stec_sat_list[7].sv_id.satId, 113);

    assign(test_msg_.stec_sat_list[8].stec_coeff[0], 5448);

    assign(test_msg_.stec_sat_list[8].stec_coeff[1], -11359);

    assign(test_msg_.stec_sat_list[8].stec_coeff[2], 5574);

    assign(test_msg_.stec_sat_list[8].stec_coeff[3], 28654);
    assign(test_msg_.stec_sat_list[8].stec_quality_indicator, 249);
    assign(test_msg_.stec_sat_list[8].sv_id.constellation, 100);
    assign(test_msg_.stec_sat_list[8].sv_id.satId, 210);

    assign(test_msg_.stec_sat_list[9].stec_coeff[0], -10783);

    assign(test_msg_.stec_sat_list[9].stec_coeff[1], 18179);

    assign(test_msg_.stec_sat_list[9].stec_coeff[2], 16371);

    assign(test_msg_.stec_sat_list[9].stec_coeff[3], -5055);
    assign(test_msg_.stec_sat_list[9].stec_quality_indicator, 227);
    assign(test_msg_.stec_sat_list[9].sv_id.constellation, 36);
    assign(test_msg_.stec_sat_list[9].sv_id.satId, 107);

    assign(test_msg_.stec_sat_list[10].stec_coeff[0], 4009);

    assign(test_msg_.stec_sat_list[10].stec_coeff[1], 1462);

    assign(test_msg_.stec_sat_list[10].stec_coeff[2], -19216);

    assign(test_msg_.stec_sat_list[10].stec_coeff[3], 31241);
    assign(test_msg_.stec_sat_list[10].stec_quality_indicator, 0);
    assign(test_msg_.stec_sat_list[10].sv_id.constellation, 77);
    assign(test_msg_.stec_sat_list[10].sv_id.satId, 92);

    assign(test_msg_.stec_sat_list[11].stec_coeff[0], 26727);

    assign(test_msg_.stec_sat_list[11].stec_coeff[1], -16898);

    assign(test_msg_.stec_sat_list[11].stec_coeff[2], 28241);

    assign(test_msg_.stec_sat_list[11].stec_coeff[3], 12546);
    assign(test_msg_.stec_sat_list[11].stec_quality_indicator, 6);
    assign(test_msg_.stec_sat_list[11].sv_id.constellation, 232);
    assign(test_msg_.stec_sat_list[11].sv_id.satId, 86);

    assign(test_msg_.stec_sat_list[12].stec_coeff[0], 12855);

    assign(test_msg_.stec_sat_list[12].stec_coeff[1], 1461);

    assign(test_msg_.stec_sat_list[12].stec_coeff[2], 20603);

    assign(test_msg_.stec_sat_list[12].stec_coeff[3], -3023);
    assign(test_msg_.stec_sat_list[12].stec_quality_indicator, 216);
    assign(test_msg_.stec_sat_list[12].sv_id.constellation, 84);
    assign(test_msg_.stec_sat_list[12].sv_id.satId, 202);

    assign(test_msg_.stec_sat_list[13].stec_coeff[0], -6492);

    assign(test_msg_.stec_sat_list[13].stec_coeff[1], 16952);

    assign(test_msg_.stec_sat_list[13].stec_coeff[2], -22404);

    assign(test_msg_.stec_sat_list[13].stec_coeff[3], -29893);
    assign(test_msg_.stec_sat_list[13].stec_quality_indicator, 125);
    assign(test_msg_.stec_sat_list[13].sv_id.constellation, 188);
    assign(test_msg_.stec_sat_list[13].sv_id.satId, 224);

    assign(test_msg_.stec_sat_list[14].stec_coeff[0], -10053);

    assign(test_msg_.stec_sat_list[14].stec_coeff[1], -24897);

    assign(test_msg_.stec_sat_list[14].stec_coeff[2], 23629);

    assign(test_msg_.stec_sat_list[14].stec_coeff[3], -710);
    assign(test_msg_.stec_sat_list[14].stec_quality_indicator, 51);
    assign(test_msg_.stec_sat_list[14].sv_id.constellation, 118);
    assign(test_msg_.stec_sat_list[14].sv_id.satId, 106);

    assign(test_msg_.stec_sat_list[15].stec_coeff[0], -26103);

    assign(test_msg_.stec_sat_list[15].stec_coeff[1], -9539);

    assign(test_msg_.stec_sat_list[15].stec_coeff[2], -11971);

    assign(test_msg_.stec_sat_list[15].stec_coeff[3], 20993);
    assign(test_msg_.stec_sat_list[15].stec_quality_indicator, 165);
    assign(test_msg_.stec_sat_list[15].sv_id.constellation, 150);
    assign(test_msg_.stec_sat_list[15].sv_id.satId, 132);

    assign(test_msg_.stec_sat_list[16].stec_coeff[0], -18891);

    assign(test_msg_.stec_sat_list[16].stec_coeff[1], -16272);

    assign(test_msg_.stec_sat_list[16].stec_coeff[2], -22578);

    assign(test_msg_.stec_sat_list[16].stec_coeff[3], -2915);
    assign(test_msg_.stec_sat_list[16].stec_quality_indicator, 23);
    assign(test_msg_.stec_sat_list[16].sv_id.constellation, 196);
    assign(test_msg_.stec_sat_list[16].sv_id.satId, 181);

    assign(test_msg_.stec_sat_list[17].stec_coeff[0], 15833);

    assign(test_msg_.stec_sat_list[17].stec_coeff[1], 24920);

    assign(test_msg_.stec_sat_list[17].stec_coeff[2], -13879);

    assign(test_msg_.stec_sat_list[17].stec_coeff[3], -1206);
    assign(test_msg_.stec_sat_list[17].stec_quality_indicator, 189);
    assign(test_msg_.stec_sat_list[17].sv_id.constellation, 1);
    assign(test_msg_.stec_sat_list[17].sv_id.satId, 35);

    assign(test_msg_.stec_sat_list[18].stec_coeff[0], 14008);

    assign(test_msg_.stec_sat_list[18].stec_coeff[1], 18996);

    assign(test_msg_.stec_sat_list[18].stec_coeff[2], 2798);

    assign(test_msg_.stec_sat_list[18].stec_coeff[3], 5761);
    assign(test_msg_.stec_sat_list[18].stec_quality_indicator, 104);
    assign(test_msg_.stec_sat_list[18].sv_id.constellation, 14);
    assign(test_msg_.stec_sat_list[18].sv_id.satId, 217);

    assign(test_msg_.stec_sat_list[19].stec_coeff[0], -25256);

    assign(test_msg_.stec_sat_list[19].stec_coeff[1], -15330);

    assign(test_msg_.stec_sat_list[19].stec_coeff[2], 6831);

    assign(test_msg_.stec_sat_list[19].stec_coeff[3], 8780);
    assign(test_msg_.stec_sat_list[19].stec_quality_indicator, 109);
    assign(test_msg_.stec_sat_list[19].sv_id.constellation, 226);
    assign(test_msg_.stec_sat_list[19].sv_id.satId, 178);

    assign(test_msg_.stec_sat_list[20].stec_coeff[0], 3304);

    assign(test_msg_.stec_sat_list[20].stec_coeff[1], -2893);

    assign(test_msg_.stec_sat_list[20].stec_coeff[2], -25841);

    assign(test_msg_.stec_sat_list[20].stec_coeff[3], -13628);
    assign(test_msg_.stec_sat_list[20].stec_quality_indicator, 154);
    assign(test_msg_.stec_sat_list[20].sv_id.constellation, 220);
    assign(test_msg_.stec_sat_list[20].sv_id.satId, 116);

    assign(test_msg_.stec_sat_list[21].stec_coeff[0], -10742);

    assign(test_msg_.stec_sat_list[21].stec_coeff[1], 10098);

    assign(test_msg_.stec_sat_list[21].stec_coeff[2], 7413);

    assign(test_msg_.stec_sat_list[21].stec_coeff[3], 17645);
    assign(test_msg_.stec_sat_list[21].stec_quality_indicator, 115);
    assign(test_msg_.stec_sat_list[21].sv_id.constellation, 70);
    assign(test_msg_.stec_sat_list[21].sv_id.satId, 72);
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
      : public sbp::MessageHandler<sbp_msg_ssr_stec_correction_dep_a_t> {
    using sbp::MessageHandler<
        sbp_msg_ssr_stec_correction_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_stec_correction_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(
        uint16_t sender_id,
        const sbp_msg_ssr_stec_correction_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgSsrStecCorrectionDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_stec_correction_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgSsrStecCorrectionDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ssr_stec_correction_dep_a,
             sizeof(msg->ssr_stec_correction_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ssr_stec_correction_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ssr_stec_correction_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgSsrStecCorrectionDepA);
    info.sender_id = 1831;
    info.preamble = 0x55;
    info.crc = 0x9b88;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 252;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ssr_stec_correction_dep_a_t &lesser,
                        const sbp_msg_ssr_stec_correction_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t>::to_sbp_msg(
            lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ssr_stec_correction_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ssr_stec_correction_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrStecCorrectionDepA, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrStecCorrectionDepA, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgSsrStecCorrectionDepA, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgSsrStecCorrectionDepA, &wrapped_greater,
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
  sbp_msg_ssr_stec_correction_dep_a_t test_msg_{};
  uint8_t encoded_frame_[252 + 8] = {
      85,  235, 5,   39,  7,   252, 70,  81,  196, 232, 185, 43,  147, 123, 39,
      4,   126, 19,  111, 97,  248, 130, 217, 217, 106, 58,  12,  65,  230, 171,
      81,  95,  86,  16,  39,  84,  228, 208, 201, 81,  219, 99,  203, 61,  182,
      66,  125, 203, 3,   193, 44,  100, 220, 125, 60,  21,  93,  218, 247, 158,
      207, 93,  129, 134, 14,  209, 48,  14,  215, 153, 148, 147, 72,  225, 180,
      236, 205, 201, 33,  3,   246, 204, 19,  3,   98,  4,   194, 191, 246, 76,
      219, 31,  191, 113, 79,  177, 15,  251, 33,  19,  96,  54,  58,  146, 210,
      100, 249, 72,  21,  161, 211, 198, 21,  238, 111, 107, 36,  227, 225, 213,
      3,   71,  243, 63,  65,  236, 92,  77,  0,   169, 15,  182, 5,   240, 180,
      9,   122, 86,  232, 6,   103, 104, 254, 189, 81,  110, 2,   49,  202, 84,
      216, 55,  50,  181, 5,   123, 80,  49,  244, 224, 188, 125, 164, 230, 56,
      66,  124, 168, 59,  139, 106, 118, 51,  187, 216, 191, 158, 77,  92,  58,
      253, 132, 150, 165, 9,   154, 189, 218, 61,  209, 1,   82,  181, 196, 23,
      53,  182, 112, 192, 206, 167, 157, 244, 35,  1,   189, 217, 61,  88,  97,
      201, 201, 74,  251, 217, 14,  104, 184, 54,  52,  74,  238, 10,  129, 22,
      178, 226, 109, 88,  157, 30,  196, 175, 26,  76,  34,  116, 220, 154, 232,
      12,  179, 244, 15,  155, 196, 202, 72,  70,  115, 10,  214, 114, 39,  245,
      28,  237, 68,  136, 155,
  };
  uint8_t encoded_payload_[252] = {
      70,  81,  196, 232, 185, 43,  147, 123, 39,  4,   126, 19,  111, 97,  248,
      130, 217, 217, 106, 58,  12,  65,  230, 171, 81,  95,  86,  16,  39,  84,
      228, 208, 201, 81,  219, 99,  203, 61,  182, 66,  125, 203, 3,   193, 44,
      100, 220, 125, 60,  21,  93,  218, 247, 158, 207, 93,  129, 134, 14,  209,
      48,  14,  215, 153, 148, 147, 72,  225, 180, 236, 205, 201, 33,  3,   246,
      204, 19,  3,   98,  4,   194, 191, 246, 76,  219, 31,  191, 113, 79,  177,
      15,  251, 33,  19,  96,  54,  58,  146, 210, 100, 249, 72,  21,  161, 211,
      198, 21,  238, 111, 107, 36,  227, 225, 213, 3,   71,  243, 63,  65,  236,
      92,  77,  0,   169, 15,  182, 5,   240, 180, 9,   122, 86,  232, 6,   103,
      104, 254, 189, 81,  110, 2,   49,  202, 84,  216, 55,  50,  181, 5,   123,
      80,  49,  244, 224, 188, 125, 164, 230, 56,  66,  124, 168, 59,  139, 106,
      118, 51,  187, 216, 191, 158, 77,  92,  58,  253, 132, 150, 165, 9,   154,
      189, 218, 61,  209, 1,   82,  181, 196, 23,  53,  182, 112, 192, 206, 167,
      157, 244, 35,  1,   189, 217, 61,  88,  97,  201, 201, 74,  251, 217, 14,
      104, 184, 54,  52,  74,  238, 10,  129, 22,  178, 226, 109, 88,  157, 30,
      196, 175, 26,  76,  34,  116, 220, 154, 232, 12,  179, 244, 15,  155, 196,
      202, 72,  70,  115, 10,  214, 114, 39,  245, 28,  237, 68,
  };
};

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgSsrStecCorrectionDepA,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[252];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_a_encode(
                &buf[0], sizeof(buf), &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 252);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(
      sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                         SbpMsgSsrStecCorrectionDepA, &info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(n_written, 252);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[252];

  EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_a_encode(&buf[0], sizeof(buf),
                                                     nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[252];

  for (uint8_t i = 0; i < 252; i++) {
    EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_a_encode(&buf[0], i, nullptr,
                                                       &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_stec_correction_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 252);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgSsrStecCorrectionDepA, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 252);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_stec_correction_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_stec_correction_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ssr_stec_correction_dep_a_t t{};
      return sbp_msg_ssr_stec_correction_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ssr_stec_correction_dep_a_t t{};
      t.n_stec_sat_list = 1;
      return sbp_msg_ssr_stec_correction_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_a_decode(&info.encoded_payload[0],
                                                       i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, SlowRead) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, BadCRC) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ssr_stec_correction_dep_a_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgSsrStecCorrectionDepA, info.sender_id,
                       &info.test_msg_wrapped, &Writer::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(
        sbp_message_send(&state, SbpMsgSsrStecCorrectionDepA, info.sender_id,
                         &info.test_msg_wrapped, &Writer::write_c),
        SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgSsrStecCorrectionDepA, info.sender_id,
                       &info.test_msg_wrapped, &SlowWriter::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.iod_atmo, greater.header.iod_atmo);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.num_msgs, greater.header.num_msgs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.seq_num, greater.header.seq_num);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.time.tow, greater.header.time.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.time.wn, greater.header.time.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.update_interval,
                        greater.header.update_interval);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_stec_sat_list, greater.n_stec_sat_list);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[0].stec_coeff[0],
                        greater.stec_sat_list[0].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[0].stec_coeff[1],
                        greater.stec_sat_list[0].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[0].stec_coeff[2],
                        greater.stec_sat_list[0].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[0].stec_coeff[3],
                        greater.stec_sat_list[0].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[0].stec_quality_indicator,
                        greater.stec_sat_list[0].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[0].sv_id.constellation,
                        greater.stec_sat_list[0].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[0].sv_id.satId,
                        greater.stec_sat_list[0].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[1].stec_coeff[0],
                        greater.stec_sat_list[1].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[1].stec_coeff[1],
                        greater.stec_sat_list[1].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[1].stec_coeff[2],
                        greater.stec_sat_list[1].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[1].stec_coeff[3],
                        greater.stec_sat_list[1].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[1].stec_quality_indicator,
                        greater.stec_sat_list[1].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[1].sv_id.constellation,
                        greater.stec_sat_list[1].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[1].sv_id.satId,
                        greater.stec_sat_list[1].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[2].stec_coeff[0],
                        greater.stec_sat_list[2].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[2].stec_coeff[1],
                        greater.stec_sat_list[2].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[2].stec_coeff[2],
                        greater.stec_sat_list[2].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[2].stec_coeff[3],
                        greater.stec_sat_list[2].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[2].stec_quality_indicator,
                        greater.stec_sat_list[2].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[2].sv_id.constellation,
                        greater.stec_sat_list[2].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[2].sv_id.satId,
                        greater.stec_sat_list[2].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[3].stec_coeff[0],
                        greater.stec_sat_list[3].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[3].stec_coeff[1],
                        greater.stec_sat_list[3].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[3].stec_coeff[2],
                        greater.stec_sat_list[3].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[3].stec_coeff[3],
                        greater.stec_sat_list[3].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[3].stec_quality_indicator,
                        greater.stec_sat_list[3].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[3].sv_id.constellation,
                        greater.stec_sat_list[3].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[3].sv_id.satId,
                        greater.stec_sat_list[3].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[4].stec_coeff[0],
                        greater.stec_sat_list[4].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[4].stec_coeff[1],
                        greater.stec_sat_list[4].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[4].stec_coeff[2],
                        greater.stec_sat_list[4].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[4].stec_coeff[3],
                        greater.stec_sat_list[4].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[4].stec_quality_indicator,
                        greater.stec_sat_list[4].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[4].sv_id.constellation,
                        greater.stec_sat_list[4].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[4].sv_id.satId,
                        greater.stec_sat_list[4].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[5].stec_coeff[0],
                        greater.stec_sat_list[5].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[5].stec_coeff[1],
                        greater.stec_sat_list[5].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[5].stec_coeff[2],
                        greater.stec_sat_list[5].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[5].stec_coeff[3],
                        greater.stec_sat_list[5].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[5].stec_quality_indicator,
                        greater.stec_sat_list[5].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[5].sv_id.constellation,
                        greater.stec_sat_list[5].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[5].sv_id.satId,
                        greater.stec_sat_list[5].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[6].stec_coeff[0],
                        greater.stec_sat_list[6].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[6].stec_coeff[1],
                        greater.stec_sat_list[6].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[6].stec_coeff[2],
                        greater.stec_sat_list[6].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[6].stec_coeff[3],
                        greater.stec_sat_list[6].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[6].stec_quality_indicator,
                        greater.stec_sat_list[6].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[6].sv_id.constellation,
                        greater.stec_sat_list[6].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[6].sv_id.satId,
                        greater.stec_sat_list[6].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[7].stec_coeff[0],
                        greater.stec_sat_list[7].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[7].stec_coeff[1],
                        greater.stec_sat_list[7].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[7].stec_coeff[2],
                        greater.stec_sat_list[7].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[7].stec_coeff[3],
                        greater.stec_sat_list[7].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[7].stec_quality_indicator,
                        greater.stec_sat_list[7].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[7].sv_id.constellation,
                        greater.stec_sat_list[7].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[7].sv_id.satId,
                        greater.stec_sat_list[7].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[8].stec_coeff[0],
                        greater.stec_sat_list[8].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[8].stec_coeff[1],
                        greater.stec_sat_list[8].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[8].stec_coeff[2],
                        greater.stec_sat_list[8].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[8].stec_coeff[3],
                        greater.stec_sat_list[8].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[8].stec_quality_indicator,
                        greater.stec_sat_list[8].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[8].sv_id.constellation,
                        greater.stec_sat_list[8].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[8].sv_id.satId,
                        greater.stec_sat_list[8].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[9].stec_coeff[0],
                        greater.stec_sat_list[9].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[9].stec_coeff[1],
                        greater.stec_sat_list[9].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[9].stec_coeff[2],
                        greater.stec_sat_list[9].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[9].stec_coeff[3],
                        greater.stec_sat_list[9].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[9].stec_quality_indicator,
                        greater.stec_sat_list[9].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[9].sv_id.constellation,
                        greater.stec_sat_list[9].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[9].sv_id.satId,
                        greater.stec_sat_list[9].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[10].stec_coeff[0],
                        greater.stec_sat_list[10].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[10].stec_coeff[1],
                        greater.stec_sat_list[10].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[10].stec_coeff[2],
                        greater.stec_sat_list[10].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[10].stec_coeff[3],
                        greater.stec_sat_list[10].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[10].stec_quality_indicator,
                        greater.stec_sat_list[10].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[10].sv_id.constellation,
                        greater.stec_sat_list[10].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[10].sv_id.satId,
                        greater.stec_sat_list[10].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[11].stec_coeff[0],
                        greater.stec_sat_list[11].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[11].stec_coeff[1],
                        greater.stec_sat_list[11].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[11].stec_coeff[2],
                        greater.stec_sat_list[11].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[11].stec_coeff[3],
                        greater.stec_sat_list[11].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[11].stec_quality_indicator,
                        greater.stec_sat_list[11].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[11].sv_id.constellation,
                        greater.stec_sat_list[11].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[11].sv_id.satId,
                        greater.stec_sat_list[11].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[12].stec_coeff[0],
                        greater.stec_sat_list[12].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[12].stec_coeff[1],
                        greater.stec_sat_list[12].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[12].stec_coeff[2],
                        greater.stec_sat_list[12].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[12].stec_coeff[3],
                        greater.stec_sat_list[12].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[12].stec_quality_indicator,
                        greater.stec_sat_list[12].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[12].sv_id.constellation,
                        greater.stec_sat_list[12].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[12].sv_id.satId,
                        greater.stec_sat_list[12].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[13].stec_coeff[0],
                        greater.stec_sat_list[13].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[13].stec_coeff[1],
                        greater.stec_sat_list[13].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[13].stec_coeff[2],
                        greater.stec_sat_list[13].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[13].stec_coeff[3],
                        greater.stec_sat_list[13].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[13].stec_quality_indicator,
                        greater.stec_sat_list[13].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[13].sv_id.constellation,
                        greater.stec_sat_list[13].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[13].sv_id.satId,
                        greater.stec_sat_list[13].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[14].stec_coeff[0],
                        greater.stec_sat_list[14].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[14].stec_coeff[1],
                        greater.stec_sat_list[14].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[14].stec_coeff[2],
                        greater.stec_sat_list[14].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[14].stec_coeff[3],
                        greater.stec_sat_list[14].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[14].stec_quality_indicator,
                        greater.stec_sat_list[14].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[14].sv_id.constellation,
                        greater.stec_sat_list[14].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[14].sv_id.satId,
                        greater.stec_sat_list[14].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[15].stec_coeff[0],
                        greater.stec_sat_list[15].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[15].stec_coeff[1],
                        greater.stec_sat_list[15].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[15].stec_coeff[2],
                        greater.stec_sat_list[15].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[15].stec_coeff[3],
                        greater.stec_sat_list[15].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[15].stec_quality_indicator,
                        greater.stec_sat_list[15].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[15].sv_id.constellation,
                        greater.stec_sat_list[15].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[15].sv_id.satId,
                        greater.stec_sat_list[15].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[16].stec_coeff[0],
                        greater.stec_sat_list[16].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[16].stec_coeff[1],
                        greater.stec_sat_list[16].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[16].stec_coeff[2],
                        greater.stec_sat_list[16].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[16].stec_coeff[3],
                        greater.stec_sat_list[16].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[16].stec_quality_indicator,
                        greater.stec_sat_list[16].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[16].sv_id.constellation,
                        greater.stec_sat_list[16].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[16].sv_id.satId,
                        greater.stec_sat_list[16].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[17].stec_coeff[0],
                        greater.stec_sat_list[17].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[17].stec_coeff[1],
                        greater.stec_sat_list[17].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[17].stec_coeff[2],
                        greater.stec_sat_list[17].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[17].stec_coeff[3],
                        greater.stec_sat_list[17].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[17].stec_quality_indicator,
                        greater.stec_sat_list[17].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[17].sv_id.constellation,
                        greater.stec_sat_list[17].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[17].sv_id.satId,
                        greater.stec_sat_list[17].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[18].stec_coeff[0],
                        greater.stec_sat_list[18].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[18].stec_coeff[1],
                        greater.stec_sat_list[18].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[18].stec_coeff[2],
                        greater.stec_sat_list[18].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[18].stec_coeff[3],
                        greater.stec_sat_list[18].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[18].stec_quality_indicator,
                        greater.stec_sat_list[18].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[18].sv_id.constellation,
                        greater.stec_sat_list[18].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[18].sv_id.satId,
                        greater.stec_sat_list[18].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[19].stec_coeff[0],
                        greater.stec_sat_list[19].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[19].stec_coeff[1],
                        greater.stec_sat_list[19].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[19].stec_coeff[2],
                        greater.stec_sat_list[19].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[19].stec_coeff[3],
                        greater.stec_sat_list[19].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[19].stec_quality_indicator,
                        greater.stec_sat_list[19].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[19].sv_id.constellation,
                        greater.stec_sat_list[19].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[19].sv_id.satId,
                        greater.stec_sat_list[19].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[20].stec_coeff[0],
                        greater.stec_sat_list[20].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[20].stec_coeff[1],
                        greater.stec_sat_list[20].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[20].stec_coeff[2],
                        greater.stec_sat_list[20].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[20].stec_coeff[3],
                        greater.stec_sat_list[20].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[20].stec_quality_indicator,
                        greater.stec_sat_list[20].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[20].sv_id.constellation,
                        greater.stec_sat_list[20].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[20].sv_id.satId,
                        greater.stec_sat_list[20].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[21].stec_coeff[0],
                        greater.stec_sat_list[21].stec_coeff[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[21].stec_coeff[1],
                        greater.stec_sat_list[21].stec_coeff[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[21].stec_coeff[2],
                        greater.stec_sat_list[21].stec_coeff[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[21].stec_coeff[3],
                        greater.stec_sat_list[21].stec_coeff[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[21].stec_quality_indicator,
                        greater.stec_sat_list[21].stec_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[21].sv_id.constellation,
                        greater.stec_sat_list[21].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_stec_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_stec_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_sat_list[21].sv_id.satId,
                        greater.stec_sat_list[21].sv_id.satId);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t>::id,
  // SbpMsgSsrStecCorrectionDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t>::name,
               "MSG_SSR_STEC_CORRECTION_DEP_A");
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ssr_stec_correction_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t>::get(
          const_sbp_msg_t);
  sbp_msg_ssr_stec_correction_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.ssr_stec_correction_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t>::to_sbp_msg(
      info.test_msg, &msg2);
  EXPECT_EQ(msg2.ssr_stec_correction_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t>::encoded_len(
          info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[252];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 252);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_stec_correction_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_stec_correction_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 252);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgSsrStecCorrectionDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrStecCorrectionDepA0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgSsrStecCorrectionDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace