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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionNoStdDepA.yaml
// by generate.py. Do not modify by hand!

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
class Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0() {
    assign(test_msg_.header.iod_atmo, 236);
    assign(test_msg_.header.num_msgs, 62837);
    assign(test_msg_.header.seq_num, 63555);
    assign(test_msg_.header.time.tow, 2837573811);
    assign(test_msg_.header.time.wn, 8940);
    assign(test_msg_.header.tropo_quality_indicator, 230);
    assign(test_msg_.header.update_interval, 233);
    assign(test_msg_.index, 26598);
    assign(test_msg_.n_stec_residuals, 59);

    assign(test_msg_.stec_residuals[0].residual, -23949);
    assign(test_msg_.stec_residuals[0].sv_id.constellation, 157);
    assign(test_msg_.stec_residuals[0].sv_id.satId, 231);

    assign(test_msg_.stec_residuals[1].residual, 27427);
    assign(test_msg_.stec_residuals[1].sv_id.constellation, 146);
    assign(test_msg_.stec_residuals[1].sv_id.satId, 197);

    assign(test_msg_.stec_residuals[2].residual, 10548);
    assign(test_msg_.stec_residuals[2].sv_id.constellation, 109);
    assign(test_msg_.stec_residuals[2].sv_id.satId, 222);

    assign(test_msg_.stec_residuals[3].residual, -18195);
    assign(test_msg_.stec_residuals[3].sv_id.constellation, 12);
    assign(test_msg_.stec_residuals[3].sv_id.satId, 86);

    assign(test_msg_.stec_residuals[4].residual, -27511);
    assign(test_msg_.stec_residuals[4].sv_id.constellation, 204);
    assign(test_msg_.stec_residuals[4].sv_id.satId, 65);

    assign(test_msg_.stec_residuals[5].residual, 11);
    assign(test_msg_.stec_residuals[5].sv_id.constellation, 183);
    assign(test_msg_.stec_residuals[5].sv_id.satId, 171);

    assign(test_msg_.stec_residuals[6].residual, 13740);
    assign(test_msg_.stec_residuals[6].sv_id.constellation, 203);
    assign(test_msg_.stec_residuals[6].sv_id.satId, 180);

    assign(test_msg_.stec_residuals[7].residual, 29626);
    assign(test_msg_.stec_residuals[7].sv_id.constellation, 85);
    assign(test_msg_.stec_residuals[7].sv_id.satId, 196);

    assign(test_msg_.stec_residuals[8].residual, 7846);
    assign(test_msg_.stec_residuals[8].sv_id.constellation, 92);
    assign(test_msg_.stec_residuals[8].sv_id.satId, 203);

    assign(test_msg_.stec_residuals[9].residual, 18376);
    assign(test_msg_.stec_residuals[9].sv_id.constellation, 13);
    assign(test_msg_.stec_residuals[9].sv_id.satId, 42);

    assign(test_msg_.stec_residuals[10].residual, -24357);
    assign(test_msg_.stec_residuals[10].sv_id.constellation, 137);
    assign(test_msg_.stec_residuals[10].sv_id.satId, 98);

    assign(test_msg_.stec_residuals[11].residual, -1441);
    assign(test_msg_.stec_residuals[11].sv_id.constellation, 216);
    assign(test_msg_.stec_residuals[11].sv_id.satId, 95);

    assign(test_msg_.stec_residuals[12].residual, -10660);
    assign(test_msg_.stec_residuals[12].sv_id.constellation, 196);
    assign(test_msg_.stec_residuals[12].sv_id.satId, 99);

    assign(test_msg_.stec_residuals[13].residual, -8509);
    assign(test_msg_.stec_residuals[13].sv_id.constellation, 253);
    assign(test_msg_.stec_residuals[13].sv_id.satId, 159);

    assign(test_msg_.stec_residuals[14].residual, 16361);
    assign(test_msg_.stec_residuals[14].sv_id.constellation, 146);
    assign(test_msg_.stec_residuals[14].sv_id.satId, 233);

    assign(test_msg_.stec_residuals[15].residual, 10346);
    assign(test_msg_.stec_residuals[15].sv_id.constellation, 24);
    assign(test_msg_.stec_residuals[15].sv_id.satId, 76);

    assign(test_msg_.stec_residuals[16].residual, -18679);
    assign(test_msg_.stec_residuals[16].sv_id.constellation, 65);
    assign(test_msg_.stec_residuals[16].sv_id.satId, 253);

    assign(test_msg_.stec_residuals[17].residual, 15292);
    assign(test_msg_.stec_residuals[17].sv_id.constellation, 215);
    assign(test_msg_.stec_residuals[17].sv_id.satId, 40);

    assign(test_msg_.stec_residuals[18].residual, 29537);
    assign(test_msg_.stec_residuals[18].sv_id.constellation, 69);
    assign(test_msg_.stec_residuals[18].sv_id.satId, 117);

    assign(test_msg_.stec_residuals[19].residual, -29440);
    assign(test_msg_.stec_residuals[19].sv_id.constellation, 56);
    assign(test_msg_.stec_residuals[19].sv_id.satId, 60);

    assign(test_msg_.stec_residuals[20].residual, -24266);
    assign(test_msg_.stec_residuals[20].sv_id.constellation, 171);
    assign(test_msg_.stec_residuals[20].sv_id.satId, 207);

    assign(test_msg_.stec_residuals[21].residual, 22272);
    assign(test_msg_.stec_residuals[21].sv_id.constellation, 61);
    assign(test_msg_.stec_residuals[21].sv_id.satId, 23);

    assign(test_msg_.stec_residuals[22].residual, 9303);
    assign(test_msg_.stec_residuals[22].sv_id.constellation, 123);
    assign(test_msg_.stec_residuals[22].sv_id.satId, 230);

    assign(test_msg_.stec_residuals[23].residual, -23794);
    assign(test_msg_.stec_residuals[23].sv_id.constellation, 255);
    assign(test_msg_.stec_residuals[23].sv_id.satId, 184);

    assign(test_msg_.stec_residuals[24].residual, -26837);
    assign(test_msg_.stec_residuals[24].sv_id.constellation, 224);
    assign(test_msg_.stec_residuals[24].sv_id.satId, 187);

    assign(test_msg_.stec_residuals[25].residual, 14631);
    assign(test_msg_.stec_residuals[25].sv_id.constellation, 104);
    assign(test_msg_.stec_residuals[25].sv_id.satId, 151);

    assign(test_msg_.stec_residuals[26].residual, -8144);
    assign(test_msg_.stec_residuals[26].sv_id.constellation, 54);
    assign(test_msg_.stec_residuals[26].sv_id.satId, 5);

    assign(test_msg_.stec_residuals[27].residual, 23612);
    assign(test_msg_.stec_residuals[27].sv_id.constellation, 129);
    assign(test_msg_.stec_residuals[27].sv_id.satId, 181);

    assign(test_msg_.stec_residuals[28].residual, 28013);
    assign(test_msg_.stec_residuals[28].sv_id.constellation, 114);
    assign(test_msg_.stec_residuals[28].sv_id.satId, 171);

    assign(test_msg_.stec_residuals[29].residual, 2166);
    assign(test_msg_.stec_residuals[29].sv_id.constellation, 23);
    assign(test_msg_.stec_residuals[29].sv_id.satId, 12);

    assign(test_msg_.stec_residuals[30].residual, -10186);
    assign(test_msg_.stec_residuals[30].sv_id.constellation, 159);
    assign(test_msg_.stec_residuals[30].sv_id.satId, 64);

    assign(test_msg_.stec_residuals[31].residual, 17432);
    assign(test_msg_.stec_residuals[31].sv_id.constellation, 20);
    assign(test_msg_.stec_residuals[31].sv_id.satId, 33);

    assign(test_msg_.stec_residuals[32].residual, -8666);
    assign(test_msg_.stec_residuals[32].sv_id.constellation, 36);
    assign(test_msg_.stec_residuals[32].sv_id.satId, 160);

    assign(test_msg_.stec_residuals[33].residual, 25436);
    assign(test_msg_.stec_residuals[33].sv_id.constellation, 190);
    assign(test_msg_.stec_residuals[33].sv_id.satId, 145);

    assign(test_msg_.stec_residuals[34].residual, -3864);
    assign(test_msg_.stec_residuals[34].sv_id.constellation, 159);
    assign(test_msg_.stec_residuals[34].sv_id.satId, 108);

    assign(test_msg_.stec_residuals[35].residual, 4093);
    assign(test_msg_.stec_residuals[35].sv_id.constellation, 221);
    assign(test_msg_.stec_residuals[35].sv_id.satId, 227);

    assign(test_msg_.stec_residuals[36].residual, -18055);
    assign(test_msg_.stec_residuals[36].sv_id.constellation, 23);
    assign(test_msg_.stec_residuals[36].sv_id.satId, 62);

    assign(test_msg_.stec_residuals[37].residual, -27900);
    assign(test_msg_.stec_residuals[37].sv_id.constellation, 116);
    assign(test_msg_.stec_residuals[37].sv_id.satId, 168);

    assign(test_msg_.stec_residuals[38].residual, 30687);
    assign(test_msg_.stec_residuals[38].sv_id.constellation, 72);
    assign(test_msg_.stec_residuals[38].sv_id.satId, 123);

    assign(test_msg_.stec_residuals[39].residual, -13151);
    assign(test_msg_.stec_residuals[39].sv_id.constellation, 242);
    assign(test_msg_.stec_residuals[39].sv_id.satId, 226);

    assign(test_msg_.stec_residuals[40].residual, -22903);
    assign(test_msg_.stec_residuals[40].sv_id.constellation, 202);
    assign(test_msg_.stec_residuals[40].sv_id.satId, 180);

    assign(test_msg_.stec_residuals[41].residual, 4988);
    assign(test_msg_.stec_residuals[41].sv_id.constellation, 24);
    assign(test_msg_.stec_residuals[41].sv_id.satId, 58);

    assign(test_msg_.stec_residuals[42].residual, 27408);
    assign(test_msg_.stec_residuals[42].sv_id.constellation, 188);
    assign(test_msg_.stec_residuals[42].sv_id.satId, 181);

    assign(test_msg_.stec_residuals[43].residual, 319);
    assign(test_msg_.stec_residuals[43].sv_id.constellation, 231);
    assign(test_msg_.stec_residuals[43].sv_id.satId, 66);

    assign(test_msg_.stec_residuals[44].residual, 15987);
    assign(test_msg_.stec_residuals[44].sv_id.constellation, 252);
    assign(test_msg_.stec_residuals[44].sv_id.satId, 64);

    assign(test_msg_.stec_residuals[45].residual, 22266);
    assign(test_msg_.stec_residuals[45].sv_id.constellation, 97);
    assign(test_msg_.stec_residuals[45].sv_id.satId, 233);

    assign(test_msg_.stec_residuals[46].residual, -19919);
    assign(test_msg_.stec_residuals[46].sv_id.constellation, 221);
    assign(test_msg_.stec_residuals[46].sv_id.satId, 156);

    assign(test_msg_.stec_residuals[47].residual, 17350);
    assign(test_msg_.stec_residuals[47].sv_id.constellation, 73);
    assign(test_msg_.stec_residuals[47].sv_id.satId, 32);

    assign(test_msg_.stec_residuals[48].residual, 14410);
    assign(test_msg_.stec_residuals[48].sv_id.constellation, 253);
    assign(test_msg_.stec_residuals[48].sv_id.satId, 249);

    assign(test_msg_.stec_residuals[49].residual, 23671);
    assign(test_msg_.stec_residuals[49].sv_id.constellation, 165);
    assign(test_msg_.stec_residuals[49].sv_id.satId, 38);

    assign(test_msg_.stec_residuals[50].residual, -31905);
    assign(test_msg_.stec_residuals[50].sv_id.constellation, 44);
    assign(test_msg_.stec_residuals[50].sv_id.satId, 99);

    assign(test_msg_.stec_residuals[51].residual, 14305);
    assign(test_msg_.stec_residuals[51].sv_id.constellation, 192);
    assign(test_msg_.stec_residuals[51].sv_id.satId, 89);

    assign(test_msg_.stec_residuals[52].residual, -12968);
    assign(test_msg_.stec_residuals[52].sv_id.constellation, 171);
    assign(test_msg_.stec_residuals[52].sv_id.satId, 95);

    assign(test_msg_.stec_residuals[53].residual, 21479);
    assign(test_msg_.stec_residuals[53].sv_id.constellation, 116);
    assign(test_msg_.stec_residuals[53].sv_id.satId, 21);

    assign(test_msg_.stec_residuals[54].residual, 28260);
    assign(test_msg_.stec_residuals[54].sv_id.constellation, 71);
    assign(test_msg_.stec_residuals[54].sv_id.satId, 71);

    assign(test_msg_.stec_residuals[55].residual, -11112);
    assign(test_msg_.stec_residuals[55].sv_id.constellation, 254);
    assign(test_msg_.stec_residuals[55].sv_id.satId, 217);

    assign(test_msg_.stec_residuals[56].residual, -25304);
    assign(test_msg_.stec_residuals[56].sv_id.constellation, 8);
    assign(test_msg_.stec_residuals[56].sv_id.satId, 18);

    assign(test_msg_.stec_residuals[57].residual, -4024);
    assign(test_msg_.stec_residuals[57].sv_id.constellation, 54);
    assign(test_msg_.stec_residuals[57].sv_id.satId, 244);

    assign(test_msg_.stec_residuals[58].residual, -15505);
    assign(test_msg_.stec_residuals[58].sv_id.constellation, 189);
    assign(test_msg_.stec_residuals[58].sv_id.satId, 231);
    assign(test_msg_.tropo_delay_correction.hydro, 16250);
    assign(test_msg_.tropo_delay_correction.wet, 101);
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

  struct CppHandler final : public sbp::MessageHandler<
                                sbp_msg_ssr_gridded_correction_no_std_dep_a_t> {
    using sbp::MessageHandler<
        sbp_msg_ssr_gridded_correction_no_std_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_gridded_correction_no_std_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(
        uint16_t sender_id,
        const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgSsrGriddedCorrectionNoStdDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_gridded_correction_no_std_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgSsrGriddedCorrectionNoStdDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ssr_gridded_correction_no_std_dep_a,
             sizeof(msg->ssr_gridded_correction_no_std_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ssr_gridded_correction_no_std_dep_a,
           &test_msg_, sizeof(test_msg_));
    info.msg_type =
        static_cast<sbp_msg_type_t>(SbpMsgSsrGriddedCorrectionNoStdDepA);
    info.sender_id = 7270;
    info.preamble = 0x55;
    info.crc = 0x51cd;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 254;

    return info;
  }

 protected:
  void comparison_tests(
      const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &lesser,
      const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser = sbp::MessageTraits<
        sbp_msg_ssr_gridded_correction_no_std_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater = sbp::MessageTraits<
        sbp_msg_ssr_gridded_correction_no_std_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_ssr_gridded_correction_no_std_dep_a_cmp(&lesser, &lesser),
              0);
    EXPECT_EQ(
        sbp_msg_ssr_gridded_correction_no_std_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(
        sbp_msg_ssr_gridded_correction_no_std_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(
        sbp_msg_ssr_gridded_correction_no_std_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrGriddedCorrectionNoStdDepA,
                              &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrGriddedCorrectionNoStdDepA,
                              &wrapped_greater, &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgSsrGriddedCorrectionNoStdDepA,
                              &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgSsrGriddedCorrectionNoStdDepA,
                              &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_ssr_gridded_correction_no_std_dep_a_t test_msg_{};
  uint8_t encoded_frame_[254 + 8] = {
      85,  240, 5,   102, 28,  254, 179, 240, 33,  169, 236, 34,  117, 245, 67,
      248, 233, 236, 230, 230, 103, 122, 63,  101, 231, 157, 115, 162, 197, 146,
      35,  107, 222, 109, 52,  41,  86,  12,  237, 184, 65,  204, 137, 148, 171,
      183, 11,  0,   180, 203, 172, 53,  196, 85,  186, 115, 203, 92,  166, 30,
      42,  13,  200, 71,  98,  137, 219, 160, 95,  216, 95,  250, 99,  196, 92,
      214, 159, 253, 195, 222, 233, 146, 233, 63,  76,  24,  106, 40,  253, 65,
      9,   183, 40,  215, 188, 59,  117, 69,  97,  115, 60,  56,  0,   141, 207,
      171, 54,  161, 23,  61,  0,   87,  230, 123, 87,  36,  184, 255, 14,  163,
      187, 224, 43,  151, 151, 104, 39,  57,  5,   54,  48,  224, 181, 129, 60,
      92,  171, 114, 109, 109, 12,  23,  118, 8,   64,  159, 54,  216, 33,  20,
      24,  68,  160, 36,  38,  222, 145, 190, 92,  99,  108, 159, 232, 240, 227,
      221, 253, 15,  62,  23,  121, 185, 168, 116, 4,   147, 123, 72,  223, 119,
      226, 242, 161, 204, 180, 202, 137, 166, 58,  24,  124, 19,  181, 188, 16,
      107, 66,  231, 63,  1,   64,  252, 115, 62,  233, 97,  250, 86,  156, 221,
      49,  178, 32,  73,  198, 67,  249, 253, 74,  56,  38,  165, 119, 92,  99,
      44,  95,  131, 89,  192, 225, 55,  95,  171, 88,  205, 21,  116, 231, 83,
      71,  71,  100, 110, 217, 254, 152, 212, 18,  8,   40,  157, 244, 54,  72,
      240, 231, 189, 111, 195, 205, 81,
  };
  uint8_t encoded_payload_[254] = {
      179, 240, 33,  169, 236, 34,  117, 245, 67,  248, 233, 236, 230, 230, 103,
      122, 63,  101, 231, 157, 115, 162, 197, 146, 35,  107, 222, 109, 52,  41,
      86,  12,  237, 184, 65,  204, 137, 148, 171, 183, 11,  0,   180, 203, 172,
      53,  196, 85,  186, 115, 203, 92,  166, 30,  42,  13,  200, 71,  98,  137,
      219, 160, 95,  216, 95,  250, 99,  196, 92,  214, 159, 253, 195, 222, 233,
      146, 233, 63,  76,  24,  106, 40,  253, 65,  9,   183, 40,  215, 188, 59,
      117, 69,  97,  115, 60,  56,  0,   141, 207, 171, 54,  161, 23,  61,  0,
      87,  230, 123, 87,  36,  184, 255, 14,  163, 187, 224, 43,  151, 151, 104,
      39,  57,  5,   54,  48,  224, 181, 129, 60,  92,  171, 114, 109, 109, 12,
      23,  118, 8,   64,  159, 54,  216, 33,  20,  24,  68,  160, 36,  38,  222,
      145, 190, 92,  99,  108, 159, 232, 240, 227, 221, 253, 15,  62,  23,  121,
      185, 168, 116, 4,   147, 123, 72,  223, 119, 226, 242, 161, 204, 180, 202,
      137, 166, 58,  24,  124, 19,  181, 188, 16,  107, 66,  231, 63,  1,   64,
      252, 115, 62,  233, 97,  250, 86,  156, 221, 49,  178, 32,  73,  198, 67,
      249, 253, 74,  56,  38,  165, 119, 92,  99,  44,  95,  131, 89,  192, 225,
      55,  95,  171, 88,  205, 21,  116, 231, 83,  71,  71,  100, 110, 217, 254,
      152, 212, 18,  8,   40,  157, 244, 54,  72,  240, 231, 189, 111, 195,
  };
};

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp_msg_ssr_gridded_correction_no_std_dep_a_encoded_len(&info.test_msg),
      info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgSsrGriddedCorrectionNoStdDepA,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[254];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_no_std_dep_a_encode(
                &buf[0], sizeof(buf), &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 254);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgSsrGriddedCorrectionNoStdDepA,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 254);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[254];

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_no_std_dep_a_encode(
                &buf[0], sizeof(buf), nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[254];

  for (uint8_t i = 0; i < 254; i++) {
    EXPECT_EQ(sbp_msg_ssr_gridded_correction_no_std_dep_a_encode(
                  &buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_gridded_correction_no_std_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_no_std_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 254);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgSsrGriddedCorrectionNoStdDepA, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 254);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_gridded_correction_no_std_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_no_std_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_gridded_correction_no_std_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ssr_gridded_correction_no_std_dep_a_t t{};
      return sbp_msg_ssr_gridded_correction_no_std_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ssr_gridded_correction_no_std_dep_a_t t{};
      t.n_stec_residuals = 1;
      return sbp_msg_ssr_gridded_correction_no_std_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ssr_gridded_correction_no_std_dep_a_decode(
                  &info.encoded_payload[0], i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0, SlowRead) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0, BadCRC) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_no_std_dep_a_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSsrGriddedCorrectionNoStdDepA,
                             info.sender_id, &info.test_msg_wrapped,
                             &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgSsrGriddedCorrectionNoStdDepA,
                               info.sender_id, &info.test_msg_wrapped,
                               &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSsrGriddedCorrectionNoStdDepA,
                             info.sender_id, &info.test_msg_wrapped,
                             &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.iod_atmo, greater.header.iod_atmo);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.num_msgs, greater.header.num_msgs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.seq_num, greater.header.seq_num);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.time.tow, greater.header.time.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.time.wn, greater.header.time.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.tropo_quality_indicator,
                        greater.header.tropo_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.update_interval,
                        greater.header.update_interval);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.index, greater.index);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_stec_residuals, greater.n_stec_residuals);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[0].residual,
                        greater.stec_residuals[0].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[0].sv_id.constellation,
                        greater.stec_residuals[0].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[0].sv_id.satId,
                        greater.stec_residuals[0].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[1].residual,
                        greater.stec_residuals[1].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[1].sv_id.constellation,
                        greater.stec_residuals[1].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[1].sv_id.satId,
                        greater.stec_residuals[1].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[2].residual,
                        greater.stec_residuals[2].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[2].sv_id.constellation,
                        greater.stec_residuals[2].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[2].sv_id.satId,
                        greater.stec_residuals[2].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[3].residual,
                        greater.stec_residuals[3].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[3].sv_id.constellation,
                        greater.stec_residuals[3].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[3].sv_id.satId,
                        greater.stec_residuals[3].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[4].residual,
                        greater.stec_residuals[4].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[4].sv_id.constellation,
                        greater.stec_residuals[4].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[4].sv_id.satId,
                        greater.stec_residuals[4].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[5].residual,
                        greater.stec_residuals[5].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[5].sv_id.constellation,
                        greater.stec_residuals[5].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[5].sv_id.satId,
                        greater.stec_residuals[5].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[6].residual,
                        greater.stec_residuals[6].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[6].sv_id.constellation,
                        greater.stec_residuals[6].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[6].sv_id.satId,
                        greater.stec_residuals[6].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[7].residual,
                        greater.stec_residuals[7].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[7].sv_id.constellation,
                        greater.stec_residuals[7].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[7].sv_id.satId,
                        greater.stec_residuals[7].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[8].residual,
                        greater.stec_residuals[8].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[8].sv_id.constellation,
                        greater.stec_residuals[8].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[8].sv_id.satId,
                        greater.stec_residuals[8].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[9].residual,
                        greater.stec_residuals[9].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[9].sv_id.constellation,
                        greater.stec_residuals[9].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[9].sv_id.satId,
                        greater.stec_residuals[9].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[10].residual,
                        greater.stec_residuals[10].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[10].sv_id.constellation,
                        greater.stec_residuals[10].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[10].sv_id.satId,
                        greater.stec_residuals[10].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[11].residual,
                        greater.stec_residuals[11].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[11].sv_id.constellation,
                        greater.stec_residuals[11].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[11].sv_id.satId,
                        greater.stec_residuals[11].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[12].residual,
                        greater.stec_residuals[12].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[12].sv_id.constellation,
                        greater.stec_residuals[12].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[12].sv_id.satId,
                        greater.stec_residuals[12].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[13].residual,
                        greater.stec_residuals[13].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[13].sv_id.constellation,
                        greater.stec_residuals[13].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[13].sv_id.satId,
                        greater.stec_residuals[13].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[14].residual,
                        greater.stec_residuals[14].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[14].sv_id.constellation,
                        greater.stec_residuals[14].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[14].sv_id.satId,
                        greater.stec_residuals[14].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[15].residual,
                        greater.stec_residuals[15].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[15].sv_id.constellation,
                        greater.stec_residuals[15].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[15].sv_id.satId,
                        greater.stec_residuals[15].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[16].residual,
                        greater.stec_residuals[16].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[16].sv_id.constellation,
                        greater.stec_residuals[16].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[16].sv_id.satId,
                        greater.stec_residuals[16].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[17].residual,
                        greater.stec_residuals[17].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[17].sv_id.constellation,
                        greater.stec_residuals[17].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[17].sv_id.satId,
                        greater.stec_residuals[17].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[18].residual,
                        greater.stec_residuals[18].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[18].sv_id.constellation,
                        greater.stec_residuals[18].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[18].sv_id.satId,
                        greater.stec_residuals[18].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[19].residual,
                        greater.stec_residuals[19].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[19].sv_id.constellation,
                        greater.stec_residuals[19].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[19].sv_id.satId,
                        greater.stec_residuals[19].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[20].residual,
                        greater.stec_residuals[20].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[20].sv_id.constellation,
                        greater.stec_residuals[20].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[20].sv_id.satId,
                        greater.stec_residuals[20].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[21].residual,
                        greater.stec_residuals[21].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[21].sv_id.constellation,
                        greater.stec_residuals[21].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[21].sv_id.satId,
                        greater.stec_residuals[21].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[22].residual,
                        greater.stec_residuals[22].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[22].sv_id.constellation,
                        greater.stec_residuals[22].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[22].sv_id.satId,
                        greater.stec_residuals[22].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[23].residual,
                        greater.stec_residuals[23].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[23].sv_id.constellation,
                        greater.stec_residuals[23].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[23].sv_id.satId,
                        greater.stec_residuals[23].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[24].residual,
                        greater.stec_residuals[24].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[24].sv_id.constellation,
                        greater.stec_residuals[24].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[24].sv_id.satId,
                        greater.stec_residuals[24].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[25].residual,
                        greater.stec_residuals[25].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[25].sv_id.constellation,
                        greater.stec_residuals[25].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[25].sv_id.satId,
                        greater.stec_residuals[25].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[26].residual,
                        greater.stec_residuals[26].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[26].sv_id.constellation,
                        greater.stec_residuals[26].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[26].sv_id.satId,
                        greater.stec_residuals[26].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[27].residual,
                        greater.stec_residuals[27].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[27].sv_id.constellation,
                        greater.stec_residuals[27].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[27].sv_id.satId,
                        greater.stec_residuals[27].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[28].residual,
                        greater.stec_residuals[28].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[28].sv_id.constellation,
                        greater.stec_residuals[28].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[28].sv_id.satId,
                        greater.stec_residuals[28].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[29].residual,
                        greater.stec_residuals[29].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[29].sv_id.constellation,
                        greater.stec_residuals[29].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[29].sv_id.satId,
                        greater.stec_residuals[29].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[30].residual,
                        greater.stec_residuals[30].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[30].sv_id.constellation,
                        greater.stec_residuals[30].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[30].sv_id.satId,
                        greater.stec_residuals[30].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[31].residual,
                        greater.stec_residuals[31].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[31].sv_id.constellation,
                        greater.stec_residuals[31].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[31].sv_id.satId,
                        greater.stec_residuals[31].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[32].residual,
                        greater.stec_residuals[32].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[32].sv_id.constellation,
                        greater.stec_residuals[32].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[32].sv_id.satId,
                        greater.stec_residuals[32].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[33].residual,
                        greater.stec_residuals[33].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[33].sv_id.constellation,
                        greater.stec_residuals[33].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[33].sv_id.satId,
                        greater.stec_residuals[33].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[34].residual,
                        greater.stec_residuals[34].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[34].sv_id.constellation,
                        greater.stec_residuals[34].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[34].sv_id.satId,
                        greater.stec_residuals[34].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[35].residual,
                        greater.stec_residuals[35].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[35].sv_id.constellation,
                        greater.stec_residuals[35].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[35].sv_id.satId,
                        greater.stec_residuals[35].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[36].residual,
                        greater.stec_residuals[36].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[36].sv_id.constellation,
                        greater.stec_residuals[36].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[36].sv_id.satId,
                        greater.stec_residuals[36].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[37].residual,
                        greater.stec_residuals[37].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[37].sv_id.constellation,
                        greater.stec_residuals[37].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[37].sv_id.satId,
                        greater.stec_residuals[37].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[38].residual,
                        greater.stec_residuals[38].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[38].sv_id.constellation,
                        greater.stec_residuals[38].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[38].sv_id.satId,
                        greater.stec_residuals[38].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[39].residual,
                        greater.stec_residuals[39].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[39].sv_id.constellation,
                        greater.stec_residuals[39].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[39].sv_id.satId,
                        greater.stec_residuals[39].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[40].residual,
                        greater.stec_residuals[40].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[40].sv_id.constellation,
                        greater.stec_residuals[40].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[40].sv_id.satId,
                        greater.stec_residuals[40].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[41].residual,
                        greater.stec_residuals[41].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[41].sv_id.constellation,
                        greater.stec_residuals[41].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[41].sv_id.satId,
                        greater.stec_residuals[41].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[42].residual,
                        greater.stec_residuals[42].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[42].sv_id.constellation,
                        greater.stec_residuals[42].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[42].sv_id.satId,
                        greater.stec_residuals[42].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[43].residual,
                        greater.stec_residuals[43].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[43].sv_id.constellation,
                        greater.stec_residuals[43].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[43].sv_id.satId,
                        greater.stec_residuals[43].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[44].residual,
                        greater.stec_residuals[44].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[44].sv_id.constellation,
                        greater.stec_residuals[44].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[44].sv_id.satId,
                        greater.stec_residuals[44].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[45].residual,
                        greater.stec_residuals[45].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[45].sv_id.constellation,
                        greater.stec_residuals[45].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[45].sv_id.satId,
                        greater.stec_residuals[45].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[46].residual,
                        greater.stec_residuals[46].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[46].sv_id.constellation,
                        greater.stec_residuals[46].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[46].sv_id.satId,
                        greater.stec_residuals[46].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[47].residual,
                        greater.stec_residuals[47].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[47].sv_id.constellation,
                        greater.stec_residuals[47].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[47].sv_id.satId,
                        greater.stec_residuals[47].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[48].residual,
                        greater.stec_residuals[48].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[48].sv_id.constellation,
                        greater.stec_residuals[48].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[48].sv_id.satId,
                        greater.stec_residuals[48].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[49].residual,
                        greater.stec_residuals[49].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[49].sv_id.constellation,
                        greater.stec_residuals[49].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[49].sv_id.satId,
                        greater.stec_residuals[49].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[50].residual,
                        greater.stec_residuals[50].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[50].sv_id.constellation,
                        greater.stec_residuals[50].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[50].sv_id.satId,
                        greater.stec_residuals[50].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[51].residual,
                        greater.stec_residuals[51].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[51].sv_id.constellation,
                        greater.stec_residuals[51].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[51].sv_id.satId,
                        greater.stec_residuals[51].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[52].residual,
                        greater.stec_residuals[52].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[52].sv_id.constellation,
                        greater.stec_residuals[52].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[52].sv_id.satId,
                        greater.stec_residuals[52].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[53].residual,
                        greater.stec_residuals[53].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[53].sv_id.constellation,
                        greater.stec_residuals[53].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[53].sv_id.satId,
                        greater.stec_residuals[53].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[54].residual,
                        greater.stec_residuals[54].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[54].sv_id.constellation,
                        greater.stec_residuals[54].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[54].sv_id.satId,
                        greater.stec_residuals[54].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[55].residual,
                        greater.stec_residuals[55].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[55].sv_id.constellation,
                        greater.stec_residuals[55].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[55].sv_id.satId,
                        greater.stec_residuals[55].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[56].residual,
                        greater.stec_residuals[56].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[56].sv_id.constellation,
                        greater.stec_residuals[56].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[56].sv_id.satId,
                        greater.stec_residuals[56].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[57].residual,
                        greater.stec_residuals[57].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[57].sv_id.constellation,
                        greater.stec_residuals[57].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[57].sv_id.satId,
                        greater.stec_residuals[57].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[58].residual,
                        greater.stec_residuals[58].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[58].sv_id.constellation,
                        greater.stec_residuals[58].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[58].sv_id.satId,
                        greater.stec_residuals[58].sv_id.satId);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tropo_delay_correction.hydro,
                        greater.tropo_delay_correction.hydro);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_no_std_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tropo_delay_correction.wet,
                        greater.tropo_delay_correction.wet);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t>::id,
  // SbpMsgSsrGriddedCorrectionNoStdDepA);
  EXPECT_STREQ(
      sbp::MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t>::name,
      "MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A");
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ssr_gridded_correction_no_std_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t>::get(
          const_sbp_msg_t);
  sbp_msg_ssr_gridded_correction_no_std_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 = sbp::MessageTraits<
      sbp_msg_ssr_gridded_correction_no_std_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.ssr_gridded_correction_no_std_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t>::to_sbp_msg(
      info.test_msg, &msg2);
  EXPECT_EQ(msg2.ssr_gridded_correction_no_std_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t>::
                encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t>::send(
          &state, info.sender_id, info.test_msg, &Writer::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[254];
  uint8_t n_written;

  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t>::encode(
          &buf[0], sizeof(buf), &n_written, info.test_msg),
      SBP_OK);
  EXPECT_EQ(n_written, 254);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_gridded_correction_no_std_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_ssr_gridded_correction_no_std_dep_a_t>::decode(
          &info.encoded_payload[0], info.payload_len, &n_read, &msg),
      SBP_OK);
  EXPECT_EQ(n_read, 254);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgSsrGriddedCorrectionNoStdDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepA0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgSsrGriddedCorrectionNoStdDepA,
                         info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace
