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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrection.yaml by
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
class Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0 : public ::testing::Test {
 public:
  Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0() {
    assign(test_msg_.header.iod_atmo, 170);
    assign(test_msg_.header.num_msgs, 48535);
    assign(test_msg_.header.seq_num, 50380);
    assign(test_msg_.header.tile_id, 12951);
    assign(test_msg_.header.tile_set_id, 3605);
    assign(test_msg_.header.time.tow, 2535294328);
    assign(test_msg_.header.time.wn, 58798);
    assign(test_msg_.header.tropo_quality_indicator, 120);
    assign(test_msg_.header.update_interval, 105);
    assign(test_msg_.index, 43413);
    assign(test_msg_.n_stec_residuals, 46);

    assign(test_msg_.stec_residuals[0].residual, -21246);
    assign(test_msg_.stec_residuals[0].stddev, 88);
    assign(test_msg_.stec_residuals[0].sv_id.constellation, 101);
    assign(test_msg_.stec_residuals[0].sv_id.satId, 140);

    assign(test_msg_.stec_residuals[1].residual, -26570);
    assign(test_msg_.stec_residuals[1].stddev, 115);
    assign(test_msg_.stec_residuals[1].sv_id.constellation, 180);
    assign(test_msg_.stec_residuals[1].sv_id.satId, 70);

    assign(test_msg_.stec_residuals[2].residual, 6049);
    assign(test_msg_.stec_residuals[2].stddev, 135);
    assign(test_msg_.stec_residuals[2].sv_id.constellation, 201);
    assign(test_msg_.stec_residuals[2].sv_id.satId, 78);

    assign(test_msg_.stec_residuals[3].residual, 19261);
    assign(test_msg_.stec_residuals[3].stddev, 178);
    assign(test_msg_.stec_residuals[3].sv_id.constellation, 98);
    assign(test_msg_.stec_residuals[3].sv_id.satId, 152);

    assign(test_msg_.stec_residuals[4].residual, 14226);
    assign(test_msg_.stec_residuals[4].stddev, 58);
    assign(test_msg_.stec_residuals[4].sv_id.constellation, 229);
    assign(test_msg_.stec_residuals[4].sv_id.satId, 120);

    assign(test_msg_.stec_residuals[5].residual, 17894);
    assign(test_msg_.stec_residuals[5].stddev, 172);
    assign(test_msg_.stec_residuals[5].sv_id.constellation, 234);
    assign(test_msg_.stec_residuals[5].sv_id.satId, 169);

    assign(test_msg_.stec_residuals[6].residual, 22930);
    assign(test_msg_.stec_residuals[6].stddev, 150);
    assign(test_msg_.stec_residuals[6].sv_id.constellation, 127);
    assign(test_msg_.stec_residuals[6].sv_id.satId, 191);

    assign(test_msg_.stec_residuals[7].residual, 10721);
    assign(test_msg_.stec_residuals[7].stddev, 17);
    assign(test_msg_.stec_residuals[7].sv_id.constellation, 111);
    assign(test_msg_.stec_residuals[7].sv_id.satId, 91);

    assign(test_msg_.stec_residuals[8].residual, -22874);
    assign(test_msg_.stec_residuals[8].stddev, 120);
    assign(test_msg_.stec_residuals[8].sv_id.constellation, 52);
    assign(test_msg_.stec_residuals[8].sv_id.satId, 119);

    assign(test_msg_.stec_residuals[9].residual, 780);
    assign(test_msg_.stec_residuals[9].stddev, 156);
    assign(test_msg_.stec_residuals[9].sv_id.constellation, 221);
    assign(test_msg_.stec_residuals[9].sv_id.satId, 57);

    assign(test_msg_.stec_residuals[10].residual, 32547);
    assign(test_msg_.stec_residuals[10].stddev, 8);
    assign(test_msg_.stec_residuals[10].sv_id.constellation, 156);
    assign(test_msg_.stec_residuals[10].sv_id.satId, 70);

    assign(test_msg_.stec_residuals[11].residual, 14208);
    assign(test_msg_.stec_residuals[11].stddev, 115);
    assign(test_msg_.stec_residuals[11].sv_id.constellation, 58);
    assign(test_msg_.stec_residuals[11].sv_id.satId, 127);

    assign(test_msg_.stec_residuals[12].residual, -26246);
    assign(test_msg_.stec_residuals[12].stddev, 124);
    assign(test_msg_.stec_residuals[12].sv_id.constellation, 157);
    assign(test_msg_.stec_residuals[12].sv_id.satId, 80);

    assign(test_msg_.stec_residuals[13].residual, 26466);
    assign(test_msg_.stec_residuals[13].stddev, 204);
    assign(test_msg_.stec_residuals[13].sv_id.constellation, 128);
    assign(test_msg_.stec_residuals[13].sv_id.satId, 27);

    assign(test_msg_.stec_residuals[14].residual, -7552);
    assign(test_msg_.stec_residuals[14].stddev, 148);
    assign(test_msg_.stec_residuals[14].sv_id.constellation, 238);
    assign(test_msg_.stec_residuals[14].sv_id.satId, 75);

    assign(test_msg_.stec_residuals[15].residual, -12072);
    assign(test_msg_.stec_residuals[15].stddev, 149);
    assign(test_msg_.stec_residuals[15].sv_id.constellation, 61);
    assign(test_msg_.stec_residuals[15].sv_id.satId, 248);

    assign(test_msg_.stec_residuals[16].residual, -28632);
    assign(test_msg_.stec_residuals[16].stddev, 186);
    assign(test_msg_.stec_residuals[16].sv_id.constellation, 224);
    assign(test_msg_.stec_residuals[16].sv_id.satId, 167);

    assign(test_msg_.stec_residuals[17].residual, -4024);
    assign(test_msg_.stec_residuals[17].stddev, 100);
    assign(test_msg_.stec_residuals[17].sv_id.constellation, 227);
    assign(test_msg_.stec_residuals[17].sv_id.satId, 157);

    assign(test_msg_.stec_residuals[18].residual, 2004);
    assign(test_msg_.stec_residuals[18].stddev, 59);
    assign(test_msg_.stec_residuals[18].sv_id.constellation, 12);
    assign(test_msg_.stec_residuals[18].sv_id.satId, 35);

    assign(test_msg_.stec_residuals[19].residual, 6998);
    assign(test_msg_.stec_residuals[19].stddev, 24);
    assign(test_msg_.stec_residuals[19].sv_id.constellation, 81);
    assign(test_msg_.stec_residuals[19].sv_id.satId, 176);

    assign(test_msg_.stec_residuals[20].residual, -31701);
    assign(test_msg_.stec_residuals[20].stddev, 45);
    assign(test_msg_.stec_residuals[20].sv_id.constellation, 67);
    assign(test_msg_.stec_residuals[20].sv_id.satId, 155);

    assign(test_msg_.stec_residuals[21].residual, 28678);
    assign(test_msg_.stec_residuals[21].stddev, 183);
    assign(test_msg_.stec_residuals[21].sv_id.constellation, 44);
    assign(test_msg_.stec_residuals[21].sv_id.satId, 203);

    assign(test_msg_.stec_residuals[22].residual, -15793);
    assign(test_msg_.stec_residuals[22].stddev, 253);
    assign(test_msg_.stec_residuals[22].sv_id.constellation, 176);
    assign(test_msg_.stec_residuals[22].sv_id.satId, 231);

    assign(test_msg_.stec_residuals[23].residual, -7589);
    assign(test_msg_.stec_residuals[23].stddev, 116);
    assign(test_msg_.stec_residuals[23].sv_id.constellation, 103);
    assign(test_msg_.stec_residuals[23].sv_id.satId, 247);

    assign(test_msg_.stec_residuals[24].residual, -7362);
    assign(test_msg_.stec_residuals[24].stddev, 240);
    assign(test_msg_.stec_residuals[24].sv_id.constellation, 23);
    assign(test_msg_.stec_residuals[24].sv_id.satId, 148);

    assign(test_msg_.stec_residuals[25].residual, 4813);
    assign(test_msg_.stec_residuals[25].stddev, 242);
    assign(test_msg_.stec_residuals[25].sv_id.constellation, 219);
    assign(test_msg_.stec_residuals[25].sv_id.satId, 29);

    assign(test_msg_.stec_residuals[26].residual, 20295);
    assign(test_msg_.stec_residuals[26].stddev, 37);
    assign(test_msg_.stec_residuals[26].sv_id.constellation, 72);
    assign(test_msg_.stec_residuals[26].sv_id.satId, 207);

    assign(test_msg_.stec_residuals[27].residual, -13623);
    assign(test_msg_.stec_residuals[27].stddev, 91);
    assign(test_msg_.stec_residuals[27].sv_id.constellation, 176);
    assign(test_msg_.stec_residuals[27].sv_id.satId, 42);

    assign(test_msg_.stec_residuals[28].residual, 15250);
    assign(test_msg_.stec_residuals[28].stddev, 110);
    assign(test_msg_.stec_residuals[28].sv_id.constellation, 115);
    assign(test_msg_.stec_residuals[28].sv_id.satId, 105);

    assign(test_msg_.stec_residuals[29].residual, -18560);
    assign(test_msg_.stec_residuals[29].stddev, 185);
    assign(test_msg_.stec_residuals[29].sv_id.constellation, 109);
    assign(test_msg_.stec_residuals[29].sv_id.satId, 44);

    assign(test_msg_.stec_residuals[30].residual, 23717);
    assign(test_msg_.stec_residuals[30].stddev, 79);
    assign(test_msg_.stec_residuals[30].sv_id.constellation, 31);
    assign(test_msg_.stec_residuals[30].sv_id.satId, 67);

    assign(test_msg_.stec_residuals[31].residual, 1886);
    assign(test_msg_.stec_residuals[31].stddev, 162);
    assign(test_msg_.stec_residuals[31].sv_id.constellation, 180);
    assign(test_msg_.stec_residuals[31].sv_id.satId, 189);

    assign(test_msg_.stec_residuals[32].residual, 12242);
    assign(test_msg_.stec_residuals[32].stddev, 7);
    assign(test_msg_.stec_residuals[32].sv_id.constellation, 156);
    assign(test_msg_.stec_residuals[32].sv_id.satId, 121);

    assign(test_msg_.stec_residuals[33].residual, 10670);
    assign(test_msg_.stec_residuals[33].stddev, 241);
    assign(test_msg_.stec_residuals[33].sv_id.constellation, 205);
    assign(test_msg_.stec_residuals[33].sv_id.satId, 7);

    assign(test_msg_.stec_residuals[34].residual, 25899);
    assign(test_msg_.stec_residuals[34].stddev, 186);
    assign(test_msg_.stec_residuals[34].sv_id.constellation, 210);
    assign(test_msg_.stec_residuals[34].sv_id.satId, 129);

    assign(test_msg_.stec_residuals[35].residual, -2078);
    assign(test_msg_.stec_residuals[35].stddev, 187);
    assign(test_msg_.stec_residuals[35].sv_id.constellation, 195);
    assign(test_msg_.stec_residuals[35].sv_id.satId, 208);

    assign(test_msg_.stec_residuals[36].residual, -16264);
    assign(test_msg_.stec_residuals[36].stddev, 102);
    assign(test_msg_.stec_residuals[36].sv_id.constellation, 160);
    assign(test_msg_.stec_residuals[36].sv_id.satId, 219);

    assign(test_msg_.stec_residuals[37].residual, -21002);
    assign(test_msg_.stec_residuals[37].stddev, 94);
    assign(test_msg_.stec_residuals[37].sv_id.constellation, 42);
    assign(test_msg_.stec_residuals[37].sv_id.satId, 166);

    assign(test_msg_.stec_residuals[38].residual, 7902);
    assign(test_msg_.stec_residuals[38].stddev, 35);
    assign(test_msg_.stec_residuals[38].sv_id.constellation, 156);
    assign(test_msg_.stec_residuals[38].sv_id.satId, 102);

    assign(test_msg_.stec_residuals[39].residual, -30275);
    assign(test_msg_.stec_residuals[39].stddev, 204);
    assign(test_msg_.stec_residuals[39].sv_id.constellation, 64);
    assign(test_msg_.stec_residuals[39].sv_id.satId, 247);

    assign(test_msg_.stec_residuals[40].residual, -8633);
    assign(test_msg_.stec_residuals[40].stddev, 222);
    assign(test_msg_.stec_residuals[40].sv_id.constellation, 32);
    assign(test_msg_.stec_residuals[40].sv_id.satId, 220);

    assign(test_msg_.stec_residuals[41].residual, 6403);
    assign(test_msg_.stec_residuals[41].stddev, 45);
    assign(test_msg_.stec_residuals[41].sv_id.constellation, 246);
    assign(test_msg_.stec_residuals[41].sv_id.satId, 201);

    assign(test_msg_.stec_residuals[42].residual, 22643);
    assign(test_msg_.stec_residuals[42].stddev, 218);
    assign(test_msg_.stec_residuals[42].sv_id.constellation, 239);
    assign(test_msg_.stec_residuals[42].sv_id.satId, 251);

    assign(test_msg_.stec_residuals[43].residual, 16760);
    assign(test_msg_.stec_residuals[43].stddev, 175);
    assign(test_msg_.stec_residuals[43].sv_id.constellation, 209);
    assign(test_msg_.stec_residuals[43].sv_id.satId, 10);

    assign(test_msg_.stec_residuals[44].residual, -20951);
    assign(test_msg_.stec_residuals[44].stddev, 137);
    assign(test_msg_.stec_residuals[44].sv_id.constellation, 194);
    assign(test_msg_.stec_residuals[44].sv_id.satId, 131);

    assign(test_msg_.stec_residuals[45].residual, -740);
    assign(test_msg_.stec_residuals[45].stddev, 42);
    assign(test_msg_.stec_residuals[45].sv_id.constellation, 68);
    assign(test_msg_.stec_residuals[45].sv_id.satId, 17);
    assign(test_msg_.tropo_delay_correction.hydro, -3035);
    assign(test_msg_.tropo_delay_correction.stddev, 72);
    assign(test_msg_.tropo_delay_correction.wet, 78);
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
      : public sbp::MessageHandler<sbp_msg_ssr_gridded_correction_t> {
    using sbp::MessageHandler<sbp_msg_ssr_gridded_correction_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_gridded_correction_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ssr_gridded_correction_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgSsrGriddedCorrection,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_gridded_correction_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgSsrGriddedCorrection);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ssr_gridded_correction,
             sizeof(msg->ssr_gridded_correction));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ssr_gridded_correction_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ssr_gridded_correction, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgSsrGriddedCorrection);
    info.sender_id = 63940;
    info.preamble = 0x55;
    info.crc = 0x23b2;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 253;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ssr_gridded_correction_t &lesser,
                        const sbp_msg_ssr_gridded_correction_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ssr_gridded_correction_t>::to_sbp_msg(
            lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ssr_gridded_correction_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_ssr_gridded_correction_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ssr_gridded_correction_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ssr_gridded_correction_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ssr_gridded_correction_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrGriddedCorrection, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrGriddedCorrection, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgSsrGriddedCorrection, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgSsrGriddedCorrection, &wrapped_greater,
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
  sbp_msg_ssr_gridded_correction_t test_msg_{};
  uint8_t encoded_frame_[253 + 8] = {
      85,  252, 5,   196, 249, 253, 21,  14,  151, 50,  120, 133, 29,  151, 174,
      229, 151, 189, 204, 196, 105, 170, 120, 149, 169, 37,  244, 78,  72,  140,
      101, 2,   173, 88,  70,  180, 54,  152, 115, 78,  201, 161, 23,  135, 152,
      98,  61,  75,  178, 120, 229, 146, 55,  58,  169, 234, 230, 69,  172, 191,
      127, 146, 89,  150, 91,  111, 225, 41,  17,  119, 52,  166, 166, 120, 57,
      221, 12,  3,   156, 70,  156, 35,  127, 8,   127, 58,  128, 55,  115, 80,
      157, 122, 153, 124, 27,  128, 98,  103, 204, 75,  238, 128, 226, 148, 248,
      61,  216, 208, 149, 167, 224, 40,  144, 186, 157, 227, 72,  240, 100, 35,
      12,  212, 7,   59,  176, 81,  86,  27,  24,  155, 67,  43,  132, 45,  203,
      44,  6,   112, 183, 231, 176, 79,  194, 253, 247, 103, 91,  226, 116, 148,
      23,  62,  227, 240, 29,  219, 205, 18,  242, 207, 72,  71,  79,  37,  42,
      176, 201, 202, 91,  105, 115, 146, 59,  110, 44,  109, 128, 183, 185, 67,
      31,  165, 92,  79,  189, 180, 94,  7,   162, 121, 156, 210, 47,  7,   7,
      205, 174, 41,  241, 129, 210, 43,  101, 186, 208, 195, 226, 247, 187, 219,
      160, 120, 192, 102, 166, 42,  246, 173, 94,  102, 156, 222, 30,  35,  247,
      64,  189, 137, 204, 220, 32,  71,  222, 222, 201, 246, 3,   25,  45,  251,
      239, 115, 88,  218, 10,  209, 120, 65,  175, 131, 194, 41,  174, 137, 17,
      68,  28,  253, 42,  178, 35,
  };
  uint8_t encoded_payload_[253] = {
      21,  14,  151, 50,  120, 133, 29,  151, 174, 229, 151, 189, 204, 196, 105,
      170, 120, 149, 169, 37,  244, 78,  72,  140, 101, 2,   173, 88,  70,  180,
      54,  152, 115, 78,  201, 161, 23,  135, 152, 98,  61,  75,  178, 120, 229,
      146, 55,  58,  169, 234, 230, 69,  172, 191, 127, 146, 89,  150, 91,  111,
      225, 41,  17,  119, 52,  166, 166, 120, 57,  221, 12,  3,   156, 70,  156,
      35,  127, 8,   127, 58,  128, 55,  115, 80,  157, 122, 153, 124, 27,  128,
      98,  103, 204, 75,  238, 128, 226, 148, 248, 61,  216, 208, 149, 167, 224,
      40,  144, 186, 157, 227, 72,  240, 100, 35,  12,  212, 7,   59,  176, 81,
      86,  27,  24,  155, 67,  43,  132, 45,  203, 44,  6,   112, 183, 231, 176,
      79,  194, 253, 247, 103, 91,  226, 116, 148, 23,  62,  227, 240, 29,  219,
      205, 18,  242, 207, 72,  71,  79,  37,  42,  176, 201, 202, 91,  105, 115,
      146, 59,  110, 44,  109, 128, 183, 185, 67,  31,  165, 92,  79,  189, 180,
      94,  7,   162, 121, 156, 210, 47,  7,   7,   205, 174, 41,  241, 129, 210,
      43,  101, 186, 208, 195, 226, 247, 187, 219, 160, 120, 192, 102, 166, 42,
      246, 173, 94,  102, 156, 222, 30,  35,  247, 64,  189, 137, 204, 220, 32,
      71,  222, 222, 201, 246, 3,   25,  45,  251, 239, 115, 88,  218, 10,  209,
      120, 65,  175, 131, 194, 41,  174, 137, 17,  68,  28,  253, 42,
  };
};

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ssr_gridded_correction_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgSsrGriddedCorrection,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[253];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_encode(&buf[0], sizeof(buf),
                                                  &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 253);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 253), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(
      sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                         SbpMsgSsrGriddedCorrection, &info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(n_written, 253);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 253), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[253];

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_encode(&buf[0], sizeof(buf), nullptr,
                                                  &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 253), 0);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[253];

  for (uint8_t i = 0; i < 253; i++) {
    EXPECT_EQ(sbp_msg_ssr_gridded_correction_encode(&buf[0], i, nullptr,
                                                    &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_gridded_correction_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 253);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgSsrGriddedCorrection, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 253);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_gridded_correction_t msg{};

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_gridded_correction_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ssr_gridded_correction_t t{};
      return sbp_msg_ssr_gridded_correction_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ssr_gridded_correction_t t{};
      t.n_stec_residuals = 1;
      return sbp_msg_ssr_gridded_correction_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ssr_gridded_correction_decode(&info.encoded_payload[0], i,
                                                    nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, SlowRead) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, BadCRC) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ssr_gridded_correction_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSsrGriddedCorrection, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(
        sbp_message_send(&state, SbpMsgSsrGriddedCorrection, info.sender_id,
                         &info.test_msg_wrapped, &Writer::write_c),
        SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSsrGriddedCorrection, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.header.iod_atmo, greater.header.iod_atmo);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.header.num_msgs, greater.header.num_msgs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.header.seq_num, greater.header.seq_num);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.header.tile_id, greater.header.tile_id);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.header.tile_set_id, greater.header.tile_set_id);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.header.time.tow, greater.header.time.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.header.time.wn, greater.header.time.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.header.tropo_quality_indicator,
                        greater.header.tropo_quality_indicator);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.header.update_interval,
                        greater.header.update_interval);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.index, greater.index);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.n_stec_residuals, greater.n_stec_residuals);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[0].residual,
                        greater.stec_residuals[0].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[0].stddev,
                        greater.stec_residuals[0].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[0].sv_id.constellation,
                        greater.stec_residuals[0].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[0].sv_id.satId,
                        greater.stec_residuals[0].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[1].residual,
                        greater.stec_residuals[1].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[1].stddev,
                        greater.stec_residuals[1].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[1].sv_id.constellation,
                        greater.stec_residuals[1].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[1].sv_id.satId,
                        greater.stec_residuals[1].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[2].residual,
                        greater.stec_residuals[2].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[2].stddev,
                        greater.stec_residuals[2].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[2].sv_id.constellation,
                        greater.stec_residuals[2].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[2].sv_id.satId,
                        greater.stec_residuals[2].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[3].residual,
                        greater.stec_residuals[3].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[3].stddev,
                        greater.stec_residuals[3].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[3].sv_id.constellation,
                        greater.stec_residuals[3].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[3].sv_id.satId,
                        greater.stec_residuals[3].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[4].residual,
                        greater.stec_residuals[4].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[4].stddev,
                        greater.stec_residuals[4].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[4].sv_id.constellation,
                        greater.stec_residuals[4].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[4].sv_id.satId,
                        greater.stec_residuals[4].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[5].residual,
                        greater.stec_residuals[5].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[5].stddev,
                        greater.stec_residuals[5].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[5].sv_id.constellation,
                        greater.stec_residuals[5].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[5].sv_id.satId,
                        greater.stec_residuals[5].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[6].residual,
                        greater.stec_residuals[6].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[6].stddev,
                        greater.stec_residuals[6].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[6].sv_id.constellation,
                        greater.stec_residuals[6].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[6].sv_id.satId,
                        greater.stec_residuals[6].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[7].residual,
                        greater.stec_residuals[7].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[7].stddev,
                        greater.stec_residuals[7].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[7].sv_id.constellation,
                        greater.stec_residuals[7].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[7].sv_id.satId,
                        greater.stec_residuals[7].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[8].residual,
                        greater.stec_residuals[8].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[8].stddev,
                        greater.stec_residuals[8].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[8].sv_id.constellation,
                        greater.stec_residuals[8].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[8].sv_id.satId,
                        greater.stec_residuals[8].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[9].residual,
                        greater.stec_residuals[9].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[9].stddev,
                        greater.stec_residuals[9].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[9].sv_id.constellation,
                        greater.stec_residuals[9].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[9].sv_id.satId,
                        greater.stec_residuals[9].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[10].residual,
                        greater.stec_residuals[10].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[10].stddev,
                        greater.stec_residuals[10].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[10].sv_id.constellation,
                        greater.stec_residuals[10].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[10].sv_id.satId,
                        greater.stec_residuals[10].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[11].residual,
                        greater.stec_residuals[11].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[11].stddev,
                        greater.stec_residuals[11].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[11].sv_id.constellation,
                        greater.stec_residuals[11].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[11].sv_id.satId,
                        greater.stec_residuals[11].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[12].residual,
                        greater.stec_residuals[12].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[12].stddev,
                        greater.stec_residuals[12].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[12].sv_id.constellation,
                        greater.stec_residuals[12].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[12].sv_id.satId,
                        greater.stec_residuals[12].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[13].residual,
                        greater.stec_residuals[13].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[13].stddev,
                        greater.stec_residuals[13].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[13].sv_id.constellation,
                        greater.stec_residuals[13].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[13].sv_id.satId,
                        greater.stec_residuals[13].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[14].residual,
                        greater.stec_residuals[14].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[14].stddev,
                        greater.stec_residuals[14].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[14].sv_id.constellation,
                        greater.stec_residuals[14].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[14].sv_id.satId,
                        greater.stec_residuals[14].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[15].residual,
                        greater.stec_residuals[15].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[15].stddev,
                        greater.stec_residuals[15].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[15].sv_id.constellation,
                        greater.stec_residuals[15].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[15].sv_id.satId,
                        greater.stec_residuals[15].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[16].residual,
                        greater.stec_residuals[16].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[16].stddev,
                        greater.stec_residuals[16].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[16].sv_id.constellation,
                        greater.stec_residuals[16].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[16].sv_id.satId,
                        greater.stec_residuals[16].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[17].residual,
                        greater.stec_residuals[17].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[17].stddev,
                        greater.stec_residuals[17].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[17].sv_id.constellation,
                        greater.stec_residuals[17].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[17].sv_id.satId,
                        greater.stec_residuals[17].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[18].residual,
                        greater.stec_residuals[18].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[18].stddev,
                        greater.stec_residuals[18].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[18].sv_id.constellation,
                        greater.stec_residuals[18].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[18].sv_id.satId,
                        greater.stec_residuals[18].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[19].residual,
                        greater.stec_residuals[19].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[19].stddev,
                        greater.stec_residuals[19].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[19].sv_id.constellation,
                        greater.stec_residuals[19].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[19].sv_id.satId,
                        greater.stec_residuals[19].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[20].residual,
                        greater.stec_residuals[20].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[20].stddev,
                        greater.stec_residuals[20].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[20].sv_id.constellation,
                        greater.stec_residuals[20].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[20].sv_id.satId,
                        greater.stec_residuals[20].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[21].residual,
                        greater.stec_residuals[21].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[21].stddev,
                        greater.stec_residuals[21].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[21].sv_id.constellation,
                        greater.stec_residuals[21].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[21].sv_id.satId,
                        greater.stec_residuals[21].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[22].residual,
                        greater.stec_residuals[22].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[22].stddev,
                        greater.stec_residuals[22].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[22].sv_id.constellation,
                        greater.stec_residuals[22].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[22].sv_id.satId,
                        greater.stec_residuals[22].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[23].residual,
                        greater.stec_residuals[23].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[23].stddev,
                        greater.stec_residuals[23].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[23].sv_id.constellation,
                        greater.stec_residuals[23].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[23].sv_id.satId,
                        greater.stec_residuals[23].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[24].residual,
                        greater.stec_residuals[24].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[24].stddev,
                        greater.stec_residuals[24].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[24].sv_id.constellation,
                        greater.stec_residuals[24].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[24].sv_id.satId,
                        greater.stec_residuals[24].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[25].residual,
                        greater.stec_residuals[25].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[25].stddev,
                        greater.stec_residuals[25].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[25].sv_id.constellation,
                        greater.stec_residuals[25].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[25].sv_id.satId,
                        greater.stec_residuals[25].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[26].residual,
                        greater.stec_residuals[26].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[26].stddev,
                        greater.stec_residuals[26].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[26].sv_id.constellation,
                        greater.stec_residuals[26].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[26].sv_id.satId,
                        greater.stec_residuals[26].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[27].residual,
                        greater.stec_residuals[27].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[27].stddev,
                        greater.stec_residuals[27].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[27].sv_id.constellation,
                        greater.stec_residuals[27].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[27].sv_id.satId,
                        greater.stec_residuals[27].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[28].residual,
                        greater.stec_residuals[28].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[28].stddev,
                        greater.stec_residuals[28].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[28].sv_id.constellation,
                        greater.stec_residuals[28].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[28].sv_id.satId,
                        greater.stec_residuals[28].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[29].residual,
                        greater.stec_residuals[29].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[29].stddev,
                        greater.stec_residuals[29].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[29].sv_id.constellation,
                        greater.stec_residuals[29].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[29].sv_id.satId,
                        greater.stec_residuals[29].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[30].residual,
                        greater.stec_residuals[30].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[30].stddev,
                        greater.stec_residuals[30].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[30].sv_id.constellation,
                        greater.stec_residuals[30].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[30].sv_id.satId,
                        greater.stec_residuals[30].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[31].residual,
                        greater.stec_residuals[31].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[31].stddev,
                        greater.stec_residuals[31].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[31].sv_id.constellation,
                        greater.stec_residuals[31].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[31].sv_id.satId,
                        greater.stec_residuals[31].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[32].residual,
                        greater.stec_residuals[32].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[32].stddev,
                        greater.stec_residuals[32].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[32].sv_id.constellation,
                        greater.stec_residuals[32].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[32].sv_id.satId,
                        greater.stec_residuals[32].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[33].residual,
                        greater.stec_residuals[33].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[33].stddev,
                        greater.stec_residuals[33].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[33].sv_id.constellation,
                        greater.stec_residuals[33].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[33].sv_id.satId,
                        greater.stec_residuals[33].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[34].residual,
                        greater.stec_residuals[34].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[34].stddev,
                        greater.stec_residuals[34].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[34].sv_id.constellation,
                        greater.stec_residuals[34].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[34].sv_id.satId,
                        greater.stec_residuals[34].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[35].residual,
                        greater.stec_residuals[35].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[35].stddev,
                        greater.stec_residuals[35].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[35].sv_id.constellation,
                        greater.stec_residuals[35].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[35].sv_id.satId,
                        greater.stec_residuals[35].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[36].residual,
                        greater.stec_residuals[36].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[36].stddev,
                        greater.stec_residuals[36].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[36].sv_id.constellation,
                        greater.stec_residuals[36].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[36].sv_id.satId,
                        greater.stec_residuals[36].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[37].residual,
                        greater.stec_residuals[37].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[37].stddev,
                        greater.stec_residuals[37].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[37].sv_id.constellation,
                        greater.stec_residuals[37].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[37].sv_id.satId,
                        greater.stec_residuals[37].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[38].residual,
                        greater.stec_residuals[38].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[38].stddev,
                        greater.stec_residuals[38].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[38].sv_id.constellation,
                        greater.stec_residuals[38].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[38].sv_id.satId,
                        greater.stec_residuals[38].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[39].residual,
                        greater.stec_residuals[39].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[39].stddev,
                        greater.stec_residuals[39].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[39].sv_id.constellation,
                        greater.stec_residuals[39].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[39].sv_id.satId,
                        greater.stec_residuals[39].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[40].residual,
                        greater.stec_residuals[40].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[40].stddev,
                        greater.stec_residuals[40].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[40].sv_id.constellation,
                        greater.stec_residuals[40].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[40].sv_id.satId,
                        greater.stec_residuals[40].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[41].residual,
                        greater.stec_residuals[41].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[41].stddev,
                        greater.stec_residuals[41].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[41].sv_id.constellation,
                        greater.stec_residuals[41].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[41].sv_id.satId,
                        greater.stec_residuals[41].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[42].residual,
                        greater.stec_residuals[42].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[42].stddev,
                        greater.stec_residuals[42].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[42].sv_id.constellation,
                        greater.stec_residuals[42].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[42].sv_id.satId,
                        greater.stec_residuals[42].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[43].residual,
                        greater.stec_residuals[43].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[43].stddev,
                        greater.stec_residuals[43].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[43].sv_id.constellation,
                        greater.stec_residuals[43].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[43].sv_id.satId,
                        greater.stec_residuals[43].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[44].residual,
                        greater.stec_residuals[44].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[44].stddev,
                        greater.stec_residuals[44].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[44].sv_id.constellation,
                        greater.stec_residuals[44].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[44].sv_id.satId,
                        greater.stec_residuals[44].sv_id.satId);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[45].residual,
                        greater.stec_residuals[45].residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[45].stddev,
                        greater.stec_residuals[45].stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[45].sv_id.constellation,
                        greater.stec_residuals[45].sv_id.constellation);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.stec_residuals[45].sv_id.satId,
                        greater.stec_residuals[45].sv_id.satId);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.tropo_delay_correction.hydro,
                        greater.tropo_delay_correction.hydro);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.tropo_delay_correction.stddev,
                        greater.tropo_delay_correction.stddev);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_gridded_correction_t lesser = info.test_msg;
    sbp_msg_ssr_gridded_correction_t greater = info.test_msg;
    make_lesser_greater(lesser.tropo_delay_correction.wet,
                        greater.tropo_delay_correction.wet);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_gridded_correction_t>::id,
  // SbpMsgSsrGriddedCorrection);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ssr_gridded_correction_t>::name,
               "MSG_SSR_GRIDDED_CORRECTION");
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ssr_gridded_correction_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_gridded_correction_t>::get(
          const_sbp_msg_t);
  sbp_msg_ssr_gridded_correction_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_gridded_correction_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ssr_gridded_correction_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.ssr_gridded_correction, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ssr_gridded_correction_t>::to_sbp_msg(
      info.test_msg, &msg2);
  EXPECT_EQ(msg2.ssr_gridded_correction, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_gridded_correction_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_gridded_correction_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[253];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_gridded_correction_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 253);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 253), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_gridded_correction_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_gridded_correction_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 253);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgSsrGriddedCorrection,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGriddedCorrection0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgSsrGriddedCorrection,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace
