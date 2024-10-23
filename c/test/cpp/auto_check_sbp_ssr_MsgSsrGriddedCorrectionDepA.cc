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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionDepA.yaml by
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
class Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0() {
    assign(test_msg_.header.iod_atmo, 245);
    assign(test_msg_.header.num_msgs, 37695);
    assign(test_msg_.header.seq_num, 64616);
    assign(test_msg_.header.time.tow, 892131748);
    assign(test_msg_.header.time.wn, 23906);
    assign(test_msg_.header.tropo_quality_indicator, 28);
    assign(test_msg_.header.update_interval, 133);
    assign(test_msg_.index, 25695);
    assign(test_msg_.n_stec_residuals, 47);

    assign(test_msg_.stec_residuals[0].residual, -26738);
    assign(test_msg_.stec_residuals[0].stddev, 74);
    assign(test_msg_.stec_residuals[0].sv_id.constellation, 25);
    assign(test_msg_.stec_residuals[0].sv_id.satId, 87);

    assign(test_msg_.stec_residuals[1].residual, 1886);
    assign(test_msg_.stec_residuals[1].stddev, 146);
    assign(test_msg_.stec_residuals[1].sv_id.constellation, 95);
    assign(test_msg_.stec_residuals[1].sv_id.satId, 151);

    assign(test_msg_.stec_residuals[2].residual, 22183);
    assign(test_msg_.stec_residuals[2].stddev, 42);
    assign(test_msg_.stec_residuals[2].sv_id.constellation, 45);
    assign(test_msg_.stec_residuals[2].sv_id.satId, 237);

    assign(test_msg_.stec_residuals[3].residual, -5463);
    assign(test_msg_.stec_residuals[3].stddev, 220);
    assign(test_msg_.stec_residuals[3].sv_id.constellation, 224);
    assign(test_msg_.stec_residuals[3].sv_id.satId, 116);

    assign(test_msg_.stec_residuals[4].residual, 3346);
    assign(test_msg_.stec_residuals[4].stddev, 178);
    assign(test_msg_.stec_residuals[4].sv_id.constellation, 176);
    assign(test_msg_.stec_residuals[4].sv_id.satId, 23);

    assign(test_msg_.stec_residuals[5].residual, 28320);
    assign(test_msg_.stec_residuals[5].stddev, 15);
    assign(test_msg_.stec_residuals[5].sv_id.constellation, 160);
    assign(test_msg_.stec_residuals[5].sv_id.satId, 79);

    assign(test_msg_.stec_residuals[6].residual, -24937);
    assign(test_msg_.stec_residuals[6].stddev, 22);
    assign(test_msg_.stec_residuals[6].sv_id.constellation, 206);
    assign(test_msg_.stec_residuals[6].sv_id.satId, 53);

    assign(test_msg_.stec_residuals[7].residual, -21968);
    assign(test_msg_.stec_residuals[7].stddev, 82);
    assign(test_msg_.stec_residuals[7].sv_id.constellation, 184);
    assign(test_msg_.stec_residuals[7].sv_id.satId, 117);

    assign(test_msg_.stec_residuals[8].residual, 17786);
    assign(test_msg_.stec_residuals[8].stddev, 180);
    assign(test_msg_.stec_residuals[8].sv_id.constellation, 53);
    assign(test_msg_.stec_residuals[8].sv_id.satId, 40);

    assign(test_msg_.stec_residuals[9].residual, 26689);
    assign(test_msg_.stec_residuals[9].stddev, 244);
    assign(test_msg_.stec_residuals[9].sv_id.constellation, 38);
    assign(test_msg_.stec_residuals[9].sv_id.satId, 110);

    assign(test_msg_.stec_residuals[10].residual, 22755);
    assign(test_msg_.stec_residuals[10].stddev, 169);
    assign(test_msg_.stec_residuals[10].sv_id.constellation, 238);
    assign(test_msg_.stec_residuals[10].sv_id.satId, 19);

    assign(test_msg_.stec_residuals[11].residual, 9535);
    assign(test_msg_.stec_residuals[11].stddev, 183);
    assign(test_msg_.stec_residuals[11].sv_id.constellation, 146);
    assign(test_msg_.stec_residuals[11].sv_id.satId, 164);

    assign(test_msg_.stec_residuals[12].residual, -22293);
    assign(test_msg_.stec_residuals[12].stddev, 114);
    assign(test_msg_.stec_residuals[12].sv_id.constellation, 71);
    assign(test_msg_.stec_residuals[12].sv_id.satId, 85);

    assign(test_msg_.stec_residuals[13].residual, -25379);
    assign(test_msg_.stec_residuals[13].stddev, 60);
    assign(test_msg_.stec_residuals[13].sv_id.constellation, 105);
    assign(test_msg_.stec_residuals[13].sv_id.satId, 211);

    assign(test_msg_.stec_residuals[14].residual, -29182);
    assign(test_msg_.stec_residuals[14].stddev, 172);
    assign(test_msg_.stec_residuals[14].sv_id.constellation, 230);
    assign(test_msg_.stec_residuals[14].sv_id.satId, 18);

    assign(test_msg_.stec_residuals[15].residual, 32289);
    assign(test_msg_.stec_residuals[15].stddev, 106);
    assign(test_msg_.stec_residuals[15].sv_id.constellation, 39);
    assign(test_msg_.stec_residuals[15].sv_id.satId, 16);

    assign(test_msg_.stec_residuals[16].residual, 10730);
    assign(test_msg_.stec_residuals[16].stddev, 162);
    assign(test_msg_.stec_residuals[16].sv_id.constellation, 188);
    assign(test_msg_.stec_residuals[16].sv_id.satId, 99);

    assign(test_msg_.stec_residuals[17].residual, 20707);
    assign(test_msg_.stec_residuals[17].stddev, 12);
    assign(test_msg_.stec_residuals[17].sv_id.constellation, 138);
    assign(test_msg_.stec_residuals[17].sv_id.satId, 197);

    assign(test_msg_.stec_residuals[18].residual, 1518);
    assign(test_msg_.stec_residuals[18].stddev, 93);
    assign(test_msg_.stec_residuals[18].sv_id.constellation, 67);
    assign(test_msg_.stec_residuals[18].sv_id.satId, 54);

    assign(test_msg_.stec_residuals[19].residual, 3457);
    assign(test_msg_.stec_residuals[19].stddev, 46);
    assign(test_msg_.stec_residuals[19].sv_id.constellation, 207);
    assign(test_msg_.stec_residuals[19].sv_id.satId, 1);

    assign(test_msg_.stec_residuals[20].residual, -18118);
    assign(test_msg_.stec_residuals[20].stddev, 127);
    assign(test_msg_.stec_residuals[20].sv_id.constellation, 49);
    assign(test_msg_.stec_residuals[20].sv_id.satId, 115);

    assign(test_msg_.stec_residuals[21].residual, -9888);
    assign(test_msg_.stec_residuals[21].stddev, 202);
    assign(test_msg_.stec_residuals[21].sv_id.constellation, 200);
    assign(test_msg_.stec_residuals[21].sv_id.satId, 156);

    assign(test_msg_.stec_residuals[22].residual, -14793);
    assign(test_msg_.stec_residuals[22].stddev, 81);
    assign(test_msg_.stec_residuals[22].sv_id.constellation, 245);
    assign(test_msg_.stec_residuals[22].sv_id.satId, 15);

    assign(test_msg_.stec_residuals[23].residual, 18758);
    assign(test_msg_.stec_residuals[23].stddev, 82);
    assign(test_msg_.stec_residuals[23].sv_id.constellation, 132);
    assign(test_msg_.stec_residuals[23].sv_id.satId, 218);

    assign(test_msg_.stec_residuals[24].residual, 3839);
    assign(test_msg_.stec_residuals[24].stddev, 134);
    assign(test_msg_.stec_residuals[24].sv_id.constellation, 26);
    assign(test_msg_.stec_residuals[24].sv_id.satId, 147);

    assign(test_msg_.stec_residuals[25].residual, -10697);
    assign(test_msg_.stec_residuals[25].stddev, 83);
    assign(test_msg_.stec_residuals[25].sv_id.constellation, 138);
    assign(test_msg_.stec_residuals[25].sv_id.satId, 96);

    assign(test_msg_.stec_residuals[26].residual, 20387);
    assign(test_msg_.stec_residuals[26].stddev, 173);
    assign(test_msg_.stec_residuals[26].sv_id.constellation, 170);
    assign(test_msg_.stec_residuals[26].sv_id.satId, 156);

    assign(test_msg_.stec_residuals[27].residual, -3789);
    assign(test_msg_.stec_residuals[27].stddev, 107);
    assign(test_msg_.stec_residuals[27].sv_id.constellation, 115);
    assign(test_msg_.stec_residuals[27].sv_id.satId, 228);

    assign(test_msg_.stec_residuals[28].residual, -11608);
    assign(test_msg_.stec_residuals[28].stddev, 10);
    assign(test_msg_.stec_residuals[28].sv_id.constellation, 112);
    assign(test_msg_.stec_residuals[28].sv_id.satId, 245);

    assign(test_msg_.stec_residuals[29].residual, 14593);
    assign(test_msg_.stec_residuals[29].stddev, 108);
    assign(test_msg_.stec_residuals[29].sv_id.constellation, 117);
    assign(test_msg_.stec_residuals[29].sv_id.satId, 5);

    assign(test_msg_.stec_residuals[30].residual, 30609);
    assign(test_msg_.stec_residuals[30].stddev, 226);
    assign(test_msg_.stec_residuals[30].sv_id.constellation, 212);
    assign(test_msg_.stec_residuals[30].sv_id.satId, 248);

    assign(test_msg_.stec_residuals[31].residual, -13683);
    assign(test_msg_.stec_residuals[31].stddev, 106);
    assign(test_msg_.stec_residuals[31].sv_id.constellation, 5);
    assign(test_msg_.stec_residuals[31].sv_id.satId, 165);

    assign(test_msg_.stec_residuals[32].residual, 15652);
    assign(test_msg_.stec_residuals[32].stddev, 243);
    assign(test_msg_.stec_residuals[32].sv_id.constellation, 60);
    assign(test_msg_.stec_residuals[32].sv_id.satId, 0);

    assign(test_msg_.stec_residuals[33].residual, 3287);
    assign(test_msg_.stec_residuals[33].stddev, 137);
    assign(test_msg_.stec_residuals[33].sv_id.constellation, 216);
    assign(test_msg_.stec_residuals[33].sv_id.satId, 203);

    assign(test_msg_.stec_residuals[34].residual, 29687);
    assign(test_msg_.stec_residuals[34].stddev, 152);
    assign(test_msg_.stec_residuals[34].sv_id.constellation, 28);
    assign(test_msg_.stec_residuals[34].sv_id.satId, 16);

    assign(test_msg_.stec_residuals[35].residual, -6960);
    assign(test_msg_.stec_residuals[35].stddev, 203);
    assign(test_msg_.stec_residuals[35].sv_id.constellation, 119);
    assign(test_msg_.stec_residuals[35].sv_id.satId, 181);

    assign(test_msg_.stec_residuals[36].residual, -15193);
    assign(test_msg_.stec_residuals[36].stddev, 32);
    assign(test_msg_.stec_residuals[36].sv_id.constellation, 34);
    assign(test_msg_.stec_residuals[36].sv_id.satId, 236);

    assign(test_msg_.stec_residuals[37].residual, 25873);
    assign(test_msg_.stec_residuals[37].stddev, 200);
    assign(test_msg_.stec_residuals[37].sv_id.constellation, 1);
    assign(test_msg_.stec_residuals[37].sv_id.satId, 109);

    assign(test_msg_.stec_residuals[38].residual, -22403);
    assign(test_msg_.stec_residuals[38].stddev, 137);
    assign(test_msg_.stec_residuals[38].sv_id.constellation, 94);
    assign(test_msg_.stec_residuals[38].sv_id.satId, 25);

    assign(test_msg_.stec_residuals[39].residual, 7588);
    assign(test_msg_.stec_residuals[39].stddev, 31);
    assign(test_msg_.stec_residuals[39].sv_id.constellation, 4);
    assign(test_msg_.stec_residuals[39].sv_id.satId, 157);

    assign(test_msg_.stec_residuals[40].residual, -6840);
    assign(test_msg_.stec_residuals[40].stddev, 126);
    assign(test_msg_.stec_residuals[40].sv_id.constellation, 132);
    assign(test_msg_.stec_residuals[40].sv_id.satId, 48);

    assign(test_msg_.stec_residuals[41].residual, -31412);
    assign(test_msg_.stec_residuals[41].stddev, 21);
    assign(test_msg_.stec_residuals[41].sv_id.constellation, 68);
    assign(test_msg_.stec_residuals[41].sv_id.satId, 186);

    assign(test_msg_.stec_residuals[42].residual, -23413);
    assign(test_msg_.stec_residuals[42].stddev, 148);
    assign(test_msg_.stec_residuals[42].sv_id.constellation, 180);
    assign(test_msg_.stec_residuals[42].sv_id.satId, 0);

    assign(test_msg_.stec_residuals[43].residual, 30934);
    assign(test_msg_.stec_residuals[43].stddev, 177);
    assign(test_msg_.stec_residuals[43].sv_id.constellation, 149);
    assign(test_msg_.stec_residuals[43].sv_id.satId, 119);

    assign(test_msg_.stec_residuals[44].residual, 26960);
    assign(test_msg_.stec_residuals[44].stddev, 10);
    assign(test_msg_.stec_residuals[44].sv_id.constellation, 80);
    assign(test_msg_.stec_residuals[44].sv_id.satId, 201);

    assign(test_msg_.stec_residuals[45].residual, 11853);
    assign(test_msg_.stec_residuals[45].stddev, 233);
    assign(test_msg_.stec_residuals[45].sv_id.constellation, 118);
    assign(test_msg_.stec_residuals[45].sv_id.satId, 136);

    assign(test_msg_.stec_residuals[46].residual, -25077);
    assign(test_msg_.stec_residuals[46].stddev, 103);
    assign(test_msg_.stec_residuals[46].sv_id.constellation, 227);
    assign(test_msg_.stec_residuals[46].sv_id.satId, 233);
    assign(test_msg_.tropo_delay_correction.hydro, 10643);
    assign(test_msg_.tropo_delay_correction.stddev, 92);
    assign(test_msg_.tropo_delay_correction.wet, 33);
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
      : public sbp::MessageHandler<sbp_msg_ssr_gridded_correction_dep_a_t> {
    using sbp::MessageHandler<
        sbp_msg_ssr_gridded_correction_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_gridded_correction_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(
        uint16_t sender_id,
        const sbp_msg_ssr_gridded_correction_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgSsrGriddedCorrectionDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_gridded_correction_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgSsrGriddedCorrectionDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ssr_gridded_correction_dep_a,
             sizeof(msg->ssr_gridded_correction_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ssr_gridded_correction_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ssr_gridded_correction_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgSsrGriddedCorrectionDepA);
    info.sender_id = 27244;
    info.preamble = 0x55;
    info.crc = 0xd8a7;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 254;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ssr_gridded_correction_dep_a_t &lesser,
                        const sbp_msg_ssr_gridded_correction_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t>::to_sbp_msg(
            lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_ssr_gridded_correction_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ssr_gridded_correction_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ssr_gridded_correction_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ssr_gridded_correction_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrGriddedCorrectionDepA, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrGriddedCorrectionDepA, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgSsrGriddedCorrectionDepA, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgSsrGriddedCorrectionDepA, &wrapped_greater,
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
  sbp_msg_ssr_gridded_correction_dep_a_t test_msg_{};
  uint8_t encoded_frame_[254 + 8] = {
      85,  250, 5,   108, 106, 254, 164, 217, 44,  53,  98,  93,  63,  147, 104,
      252, 133, 245, 28,  95,  100, 147, 41,  33,  92,  87,  25,  142, 151, 74,
      151, 95,  94,  7,   146, 237, 45,  167, 86,  42,  116, 224, 169, 234, 220,
      23,  176, 18,  13,  178, 79,  160, 160, 110, 15,  53,  206, 151, 158, 22,
      117, 184, 48,  170, 82,  40,  53,  122, 69,  180, 110, 38,  65,  104, 244,
      19,  238, 227, 88,  169, 164, 146, 63,  37,  183, 85,  71,  235, 168, 114,
      211, 105, 221, 156, 60,  18,  230, 2,   142, 172, 16,  39,  33,  126, 106,
      99,  188, 234, 41,  162, 197, 138, 227, 80,  12,  54,  67,  238, 5,   93,
      1,   207, 129, 13,  46,  115, 49,  58,  185, 127, 156, 200, 96,  217, 202,
      15,  245, 55,  198, 81,  218, 132, 70,  73,  82,  147, 26,  255, 14,  134,
      96,  138, 55,  214, 83,  156, 170, 163, 79,  173, 228, 115, 51,  241, 107,
      245, 112, 168, 210, 10,  5,   117, 1,   57,  108, 248, 212, 145, 119, 226,
      165, 5,   141, 202, 106, 0,   60,  36,  61,  243, 203, 216, 215, 12,  137,
      16,  28,  247, 115, 152, 181, 119, 208, 228, 203, 236, 34,  167, 196, 32,
      109, 1,   17,  101, 200, 25,  94,  125, 168, 137, 157, 4,   164, 29,  31,
      48,  132, 72,  229, 126, 186, 68,  76,  133, 21,  0,   180, 139, 164, 148,
      119, 149, 214, 120, 177, 201, 80,  80,  105, 10,  136, 118, 77,  46,  233,
      233, 227, 11,  158, 103, 167, 216,
  };
  uint8_t encoded_payload_[254] = {
      164, 217, 44,  53,  98,  93,  63,  147, 104, 252, 133, 245, 28,  95,  100,
      147, 41,  33,  92,  87,  25,  142, 151, 74,  151, 95,  94,  7,   146, 237,
      45,  167, 86,  42,  116, 224, 169, 234, 220, 23,  176, 18,  13,  178, 79,
      160, 160, 110, 15,  53,  206, 151, 158, 22,  117, 184, 48,  170, 82,  40,
      53,  122, 69,  180, 110, 38,  65,  104, 244, 19,  238, 227, 88,  169, 164,
      146, 63,  37,  183, 85,  71,  235, 168, 114, 211, 105, 221, 156, 60,  18,
      230, 2,   142, 172, 16,  39,  33,  126, 106, 99,  188, 234, 41,  162, 197,
      138, 227, 80,  12,  54,  67,  238, 5,   93,  1,   207, 129, 13,  46,  115,
      49,  58,  185, 127, 156, 200, 96,  217, 202, 15,  245, 55,  198, 81,  218,
      132, 70,  73,  82,  147, 26,  255, 14,  134, 96,  138, 55,  214, 83,  156,
      170, 163, 79,  173, 228, 115, 51,  241, 107, 245, 112, 168, 210, 10,  5,
      117, 1,   57,  108, 248, 212, 145, 119, 226, 165, 5,   141, 202, 106, 0,
      60,  36,  61,  243, 203, 216, 215, 12,  137, 16,  28,  247, 115, 152, 181,
      119, 208, 228, 203, 236, 34,  167, 196, 32,  109, 1,   17,  101, 200, 25,
      94,  125, 168, 137, 157, 4,   164, 29,  31,  48,  132, 72,  229, 126, 186,
      68,  76,  133, 21,  0,   180, 139, 164, 148, 119, 149, 214, 120, 177, 201,
      80,  80,  105, 10,  136, 118, 77,  46,  233, 233, 227, 11,  158, 103,
  };
};

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ssr_gridded_correction_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgSsrGriddedCorrectionDepA,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[254];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_dep_a_encode(
                &buf[0], sizeof(buf), &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 254);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgSsrGriddedCorrectionDepA,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 254);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[254];

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_dep_a_encode(
                &buf[0], sizeof(buf), nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[254];

  for (uint8_t i = 0; i < 254; i++) {
    EXPECT_EQ(sbp_msg_ssr_gridded_correction_dep_a_encode(&buf[0], i, nullptr,
                                                          &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_gridded_correction_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 254);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgSsrGriddedCorrectionDepA, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 254);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_gridded_correction_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_gridded_correction_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ssr_gridded_correction_dep_a_t t{};
      return sbp_msg_ssr_gridded_correction_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ssr_gridded_correction_dep_a_t t{};
      t.n_stec_residuals = 1;
      return sbp_msg_ssr_gridded_correction_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ssr_gridded_correction_dep_a_decode(
                  &info.encoded_payload[0], i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0, SlowRead) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0, BadCRC) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_dep_a_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgSsrGriddedCorrectionDepA, info.sender_id,
                       &info.test_msg_wrapped, &Writer::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(
        sbp_message_send(&state, SbpMsgSsrGriddedCorrectionDepA, info.sender_id,
                         &info.test_msg_wrapped, &Writer::write_c),
        SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgSsrGriddedCorrectionDepA, info.sender_id,
                       &info.test_msg_wrapped, &SlowWriter::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.iod_atmo, greater.header.iod_atmo);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.num_msgs, greater.header.num_msgs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.seq_num, greater.header.seq_num);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.time.tow, greater.header.time.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.time.wn, greater.header.time.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.tropo_quality_indicator,
                        greater.header.tropo_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.update_interval,
                        greater.header.update_interval);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.index, greater.index);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_stec_residuals, greater.n_stec_residuals);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[0].residual,
                        greater.stec_residuals[0].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[0].stddev,
                        greater.stec_residuals[0].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[0].sv_id.constellation,
                        greater.stec_residuals[0].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[0].sv_id.satId,
                        greater.stec_residuals[0].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[1].residual,
                        greater.stec_residuals[1].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[1].stddev,
                        greater.stec_residuals[1].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[1].sv_id.constellation,
                        greater.stec_residuals[1].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[1].sv_id.satId,
                        greater.stec_residuals[1].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[2].residual,
                        greater.stec_residuals[2].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[2].stddev,
                        greater.stec_residuals[2].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[2].sv_id.constellation,
                        greater.stec_residuals[2].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[2].sv_id.satId,
                        greater.stec_residuals[2].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[3].residual,
                        greater.stec_residuals[3].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[3].stddev,
                        greater.stec_residuals[3].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[3].sv_id.constellation,
                        greater.stec_residuals[3].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[3].sv_id.satId,
                        greater.stec_residuals[3].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[4].residual,
                        greater.stec_residuals[4].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[4].stddev,
                        greater.stec_residuals[4].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[4].sv_id.constellation,
                        greater.stec_residuals[4].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[4].sv_id.satId,
                        greater.stec_residuals[4].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[5].residual,
                        greater.stec_residuals[5].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[5].stddev,
                        greater.stec_residuals[5].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[5].sv_id.constellation,
                        greater.stec_residuals[5].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[5].sv_id.satId,
                        greater.stec_residuals[5].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[6].residual,
                        greater.stec_residuals[6].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[6].stddev,
                        greater.stec_residuals[6].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[6].sv_id.constellation,
                        greater.stec_residuals[6].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[6].sv_id.satId,
                        greater.stec_residuals[6].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[7].residual,
                        greater.stec_residuals[7].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[7].stddev,
                        greater.stec_residuals[7].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[7].sv_id.constellation,
                        greater.stec_residuals[7].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[7].sv_id.satId,
                        greater.stec_residuals[7].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[8].residual,
                        greater.stec_residuals[8].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[8].stddev,
                        greater.stec_residuals[8].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[8].sv_id.constellation,
                        greater.stec_residuals[8].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[8].sv_id.satId,
                        greater.stec_residuals[8].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[9].residual,
                        greater.stec_residuals[9].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[9].stddev,
                        greater.stec_residuals[9].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[9].sv_id.constellation,
                        greater.stec_residuals[9].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[9].sv_id.satId,
                        greater.stec_residuals[9].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[10].residual,
                        greater.stec_residuals[10].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[10].stddev,
                        greater.stec_residuals[10].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[10].sv_id.constellation,
                        greater.stec_residuals[10].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[10].sv_id.satId,
                        greater.stec_residuals[10].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[11].residual,
                        greater.stec_residuals[11].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[11].stddev,
                        greater.stec_residuals[11].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[11].sv_id.constellation,
                        greater.stec_residuals[11].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[11].sv_id.satId,
                        greater.stec_residuals[11].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[12].residual,
                        greater.stec_residuals[12].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[12].stddev,
                        greater.stec_residuals[12].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[12].sv_id.constellation,
                        greater.stec_residuals[12].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[12].sv_id.satId,
                        greater.stec_residuals[12].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[13].residual,
                        greater.stec_residuals[13].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[13].stddev,
                        greater.stec_residuals[13].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[13].sv_id.constellation,
                        greater.stec_residuals[13].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[13].sv_id.satId,
                        greater.stec_residuals[13].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[14].residual,
                        greater.stec_residuals[14].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[14].stddev,
                        greater.stec_residuals[14].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[14].sv_id.constellation,
                        greater.stec_residuals[14].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[14].sv_id.satId,
                        greater.stec_residuals[14].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[15].residual,
                        greater.stec_residuals[15].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[15].stddev,
                        greater.stec_residuals[15].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[15].sv_id.constellation,
                        greater.stec_residuals[15].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[15].sv_id.satId,
                        greater.stec_residuals[15].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[16].residual,
                        greater.stec_residuals[16].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[16].stddev,
                        greater.stec_residuals[16].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[16].sv_id.constellation,
                        greater.stec_residuals[16].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[16].sv_id.satId,
                        greater.stec_residuals[16].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[17].residual,
                        greater.stec_residuals[17].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[17].stddev,
                        greater.stec_residuals[17].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[17].sv_id.constellation,
                        greater.stec_residuals[17].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[17].sv_id.satId,
                        greater.stec_residuals[17].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[18].residual,
                        greater.stec_residuals[18].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[18].stddev,
                        greater.stec_residuals[18].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[18].sv_id.constellation,
                        greater.stec_residuals[18].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[18].sv_id.satId,
                        greater.stec_residuals[18].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[19].residual,
                        greater.stec_residuals[19].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[19].stddev,
                        greater.stec_residuals[19].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[19].sv_id.constellation,
                        greater.stec_residuals[19].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[19].sv_id.satId,
                        greater.stec_residuals[19].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[20].residual,
                        greater.stec_residuals[20].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[20].stddev,
                        greater.stec_residuals[20].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[20].sv_id.constellation,
                        greater.stec_residuals[20].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[20].sv_id.satId,
                        greater.stec_residuals[20].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[21].residual,
                        greater.stec_residuals[21].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[21].stddev,
                        greater.stec_residuals[21].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[21].sv_id.constellation,
                        greater.stec_residuals[21].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[21].sv_id.satId,
                        greater.stec_residuals[21].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[22].residual,
                        greater.stec_residuals[22].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[22].stddev,
                        greater.stec_residuals[22].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[22].sv_id.constellation,
                        greater.stec_residuals[22].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[22].sv_id.satId,
                        greater.stec_residuals[22].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[23].residual,
                        greater.stec_residuals[23].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[23].stddev,
                        greater.stec_residuals[23].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[23].sv_id.constellation,
                        greater.stec_residuals[23].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[23].sv_id.satId,
                        greater.stec_residuals[23].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[24].residual,
                        greater.stec_residuals[24].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[24].stddev,
                        greater.stec_residuals[24].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[24].sv_id.constellation,
                        greater.stec_residuals[24].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[24].sv_id.satId,
                        greater.stec_residuals[24].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[25].residual,
                        greater.stec_residuals[25].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[25].stddev,
                        greater.stec_residuals[25].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[25].sv_id.constellation,
                        greater.stec_residuals[25].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[25].sv_id.satId,
                        greater.stec_residuals[25].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[26].residual,
                        greater.stec_residuals[26].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[26].stddev,
                        greater.stec_residuals[26].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[26].sv_id.constellation,
                        greater.stec_residuals[26].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[26].sv_id.satId,
                        greater.stec_residuals[26].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[27].residual,
                        greater.stec_residuals[27].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[27].stddev,
                        greater.stec_residuals[27].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[27].sv_id.constellation,
                        greater.stec_residuals[27].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[27].sv_id.satId,
                        greater.stec_residuals[27].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[28].residual,
                        greater.stec_residuals[28].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[28].stddev,
                        greater.stec_residuals[28].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[28].sv_id.constellation,
                        greater.stec_residuals[28].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[28].sv_id.satId,
                        greater.stec_residuals[28].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[29].residual,
                        greater.stec_residuals[29].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[29].stddev,
                        greater.stec_residuals[29].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[29].sv_id.constellation,
                        greater.stec_residuals[29].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[29].sv_id.satId,
                        greater.stec_residuals[29].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[30].residual,
                        greater.stec_residuals[30].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[30].stddev,
                        greater.stec_residuals[30].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[30].sv_id.constellation,
                        greater.stec_residuals[30].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[30].sv_id.satId,
                        greater.stec_residuals[30].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[31].residual,
                        greater.stec_residuals[31].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[31].stddev,
                        greater.stec_residuals[31].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[31].sv_id.constellation,
                        greater.stec_residuals[31].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[31].sv_id.satId,
                        greater.stec_residuals[31].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[32].residual,
                        greater.stec_residuals[32].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[32].stddev,
                        greater.stec_residuals[32].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[32].sv_id.constellation,
                        greater.stec_residuals[32].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[32].sv_id.satId,
                        greater.stec_residuals[32].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[33].residual,
                        greater.stec_residuals[33].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[33].stddev,
                        greater.stec_residuals[33].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[33].sv_id.constellation,
                        greater.stec_residuals[33].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[33].sv_id.satId,
                        greater.stec_residuals[33].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[34].residual,
                        greater.stec_residuals[34].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[34].stddev,
                        greater.stec_residuals[34].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[34].sv_id.constellation,
                        greater.stec_residuals[34].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[34].sv_id.satId,
                        greater.stec_residuals[34].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[35].residual,
                        greater.stec_residuals[35].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[35].stddev,
                        greater.stec_residuals[35].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[35].sv_id.constellation,
                        greater.stec_residuals[35].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[35].sv_id.satId,
                        greater.stec_residuals[35].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[36].residual,
                        greater.stec_residuals[36].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[36].stddev,
                        greater.stec_residuals[36].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[36].sv_id.constellation,
                        greater.stec_residuals[36].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[36].sv_id.satId,
                        greater.stec_residuals[36].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[37].residual,
                        greater.stec_residuals[37].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[37].stddev,
                        greater.stec_residuals[37].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[37].sv_id.constellation,
                        greater.stec_residuals[37].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[37].sv_id.satId,
                        greater.stec_residuals[37].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[38].residual,
                        greater.stec_residuals[38].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[38].stddev,
                        greater.stec_residuals[38].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[38].sv_id.constellation,
                        greater.stec_residuals[38].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[38].sv_id.satId,
                        greater.stec_residuals[38].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[39].residual,
                        greater.stec_residuals[39].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[39].stddev,
                        greater.stec_residuals[39].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[39].sv_id.constellation,
                        greater.stec_residuals[39].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[39].sv_id.satId,
                        greater.stec_residuals[39].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[40].residual,
                        greater.stec_residuals[40].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[40].stddev,
                        greater.stec_residuals[40].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[40].sv_id.constellation,
                        greater.stec_residuals[40].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[40].sv_id.satId,
                        greater.stec_residuals[40].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[41].residual,
                        greater.stec_residuals[41].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[41].stddev,
                        greater.stec_residuals[41].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[41].sv_id.constellation,
                        greater.stec_residuals[41].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[41].sv_id.satId,
                        greater.stec_residuals[41].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[42].residual,
                        greater.stec_residuals[42].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[42].stddev,
                        greater.stec_residuals[42].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[42].sv_id.constellation,
                        greater.stec_residuals[42].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[42].sv_id.satId,
                        greater.stec_residuals[42].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[43].residual,
                        greater.stec_residuals[43].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[43].stddev,
                        greater.stec_residuals[43].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[43].sv_id.constellation,
                        greater.stec_residuals[43].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[43].sv_id.satId,
                        greater.stec_residuals[43].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[44].residual,
                        greater.stec_residuals[44].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[44].stddev,
                        greater.stec_residuals[44].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[44].sv_id.constellation,
                        greater.stec_residuals[44].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[44].sv_id.satId,
                        greater.stec_residuals[44].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[45].residual,
                        greater.stec_residuals[45].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[45].stddev,
                        greater.stec_residuals[45].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[45].sv_id.constellation,
                        greater.stec_residuals[45].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[45].sv_id.satId,
                        greater.stec_residuals[45].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[46].residual,
                        greater.stec_residuals[46].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[46].stddev,
                        greater.stec_residuals[46].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[46].sv_id.constellation,
                        greater.stec_residuals[46].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[46].sv_id.satId,
                        greater.stec_residuals[46].sv_id.satId);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tropo_delay_correction.hydro,
                        greater.tropo_delay_correction.hydro);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tropo_delay_correction.stddev,
                        greater.tropo_delay_correction.stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.tropo_delay_correction.wet,
                        greater.tropo_delay_correction.wet);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t>::id,
  // SbpMsgSsrGriddedCorrectionDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t>::name,
               "MSG_SSR_GRIDDED_CORRECTION_DEP_A");
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ssr_gridded_correction_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t>::get(
          const_sbp_msg_t);
  sbp_msg_ssr_gridded_correction_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.ssr_gridded_correction_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t>::to_sbp_msg(
      info.test_msg, &msg2);
  EXPECT_EQ(msg2.ssr_gridded_correction_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t>::encoded_len(
          info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[254];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 254);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_gridded_correction_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_gridded_correction_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 254);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgSsrGriddedCorrectionDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrectionDepA0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgSsrGriddedCorrectionDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace
