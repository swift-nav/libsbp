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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingState.yaml by
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
class Testauto_check_sbp_tracking_MsgTrackingState0 : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgTrackingState0() {
    assign(test_msg_.n_states, 63);

    assign(test_msg_.states[0].cn0, 102);
    assign(test_msg_.states[0].fcn, 3);
    assign(test_msg_.states[0].sid.code, 184);
    assign(test_msg_.states[0].sid.sat, 117);

    assign(test_msg_.states[1].cn0, 141);
    assign(test_msg_.states[1].fcn, 140);
    assign(test_msg_.states[1].sid.code, 106);
    assign(test_msg_.states[1].sid.sat, 38);

    assign(test_msg_.states[2].cn0, 195);
    assign(test_msg_.states[2].fcn, 90);
    assign(test_msg_.states[2].sid.code, 4);
    assign(test_msg_.states[2].sid.sat, 25);

    assign(test_msg_.states[3].cn0, 82);
    assign(test_msg_.states[3].fcn, 75);
    assign(test_msg_.states[3].sid.code, 108);
    assign(test_msg_.states[3].sid.sat, 246);

    assign(test_msg_.states[4].cn0, 163);
    assign(test_msg_.states[4].fcn, 45);
    assign(test_msg_.states[4].sid.code, 127);
    assign(test_msg_.states[4].sid.sat, 137);

    assign(test_msg_.states[5].cn0, 93);
    assign(test_msg_.states[5].fcn, 187);
    assign(test_msg_.states[5].sid.code, 46);
    assign(test_msg_.states[5].sid.sat, 32);

    assign(test_msg_.states[6].cn0, 147);
    assign(test_msg_.states[6].fcn, 201);
    assign(test_msg_.states[6].sid.code, 60);
    assign(test_msg_.states[6].sid.sat, 153);

    assign(test_msg_.states[7].cn0, 208);
    assign(test_msg_.states[7].fcn, 5);
    assign(test_msg_.states[7].sid.code, 29);
    assign(test_msg_.states[7].sid.sat, 23);

    assign(test_msg_.states[8].cn0, 69);
    assign(test_msg_.states[8].fcn, 219);
    assign(test_msg_.states[8].sid.code, 30);
    assign(test_msg_.states[8].sid.sat, 181);

    assign(test_msg_.states[9].cn0, 121);
    assign(test_msg_.states[9].fcn, 3);
    assign(test_msg_.states[9].sid.code, 136);
    assign(test_msg_.states[9].sid.sat, 254);

    assign(test_msg_.states[10].cn0, 215);
    assign(test_msg_.states[10].fcn, 144);
    assign(test_msg_.states[10].sid.code, 98);
    assign(test_msg_.states[10].sid.sat, 33);

    assign(test_msg_.states[11].cn0, 56);
    assign(test_msg_.states[11].fcn, 14);
    assign(test_msg_.states[11].sid.code, 182);
    assign(test_msg_.states[11].sid.sat, 133);

    assign(test_msg_.states[12].cn0, 62);
    assign(test_msg_.states[12].fcn, 218);
    assign(test_msg_.states[12].sid.code, 77);
    assign(test_msg_.states[12].sid.sat, 169);

    assign(test_msg_.states[13].cn0, 249);
    assign(test_msg_.states[13].fcn, 171);
    assign(test_msg_.states[13].sid.code, 84);
    assign(test_msg_.states[13].sid.sat, 242);

    assign(test_msg_.states[14].cn0, 130);
    assign(test_msg_.states[14].fcn, 131);
    assign(test_msg_.states[14].sid.code, 137);
    assign(test_msg_.states[14].sid.sat, 152);

    assign(test_msg_.states[15].cn0, 68);
    assign(test_msg_.states[15].fcn, 42);
    assign(test_msg_.states[15].sid.code, 21);
    assign(test_msg_.states[15].sid.sat, 193);

    assign(test_msg_.states[16].cn0, 227);
    assign(test_msg_.states[16].fcn, 216);
    assign(test_msg_.states[16].sid.code, 227);
    assign(test_msg_.states[16].sid.sat, 253);

    assign(test_msg_.states[17].cn0, 179);
    assign(test_msg_.states[17].fcn, 210);
    assign(test_msg_.states[17].sid.code, 26);
    assign(test_msg_.states[17].sid.sat, 24);

    assign(test_msg_.states[18].cn0, 255);
    assign(test_msg_.states[18].fcn, 227);
    assign(test_msg_.states[18].sid.code, 15);
    assign(test_msg_.states[18].sid.sat, 19);

    assign(test_msg_.states[19].cn0, 200);
    assign(test_msg_.states[19].fcn, 187);
    assign(test_msg_.states[19].sid.code, 75);
    assign(test_msg_.states[19].sid.sat, 122);

    assign(test_msg_.states[20].cn0, 122);
    assign(test_msg_.states[20].fcn, 218);
    assign(test_msg_.states[20].sid.code, 48);
    assign(test_msg_.states[20].sid.sat, 217);

    assign(test_msg_.states[21].cn0, 149);
    assign(test_msg_.states[21].fcn, 142);
    assign(test_msg_.states[21].sid.code, 238);
    assign(test_msg_.states[21].sid.sat, 187);

    assign(test_msg_.states[22].cn0, 212);
    assign(test_msg_.states[22].fcn, 251);
    assign(test_msg_.states[22].sid.code, 55);
    assign(test_msg_.states[22].sid.sat, 238);

    assign(test_msg_.states[23].cn0, 104);
    assign(test_msg_.states[23].fcn, 194);
    assign(test_msg_.states[23].sid.code, 160);
    assign(test_msg_.states[23].sid.sat, 128);

    assign(test_msg_.states[24].cn0, 62);
    assign(test_msg_.states[24].fcn, 141);
    assign(test_msg_.states[24].sid.code, 255);
    assign(test_msg_.states[24].sid.sat, 113);

    assign(test_msg_.states[25].cn0, 39);
    assign(test_msg_.states[25].fcn, 245);
    assign(test_msg_.states[25].sid.code, 69);
    assign(test_msg_.states[25].sid.sat, 43);

    assign(test_msg_.states[26].cn0, 56);
    assign(test_msg_.states[26].fcn, 108);
    assign(test_msg_.states[26].sid.code, 230);
    assign(test_msg_.states[26].sid.sat, 100);

    assign(test_msg_.states[27].cn0, 143);
    assign(test_msg_.states[27].fcn, 149);
    assign(test_msg_.states[27].sid.code, 68);
    assign(test_msg_.states[27].sid.sat, 247);

    assign(test_msg_.states[28].cn0, 70);
    assign(test_msg_.states[28].fcn, 233);
    assign(test_msg_.states[28].sid.code, 101);
    assign(test_msg_.states[28].sid.sat, 137);

    assign(test_msg_.states[29].cn0, 110);
    assign(test_msg_.states[29].fcn, 38);
    assign(test_msg_.states[29].sid.code, 165);
    assign(test_msg_.states[29].sid.sat, 49);

    assign(test_msg_.states[30].cn0, 213);
    assign(test_msg_.states[30].fcn, 80);
    assign(test_msg_.states[30].sid.code, 230);
    assign(test_msg_.states[30].sid.sat, 218);

    assign(test_msg_.states[31].cn0, 128);
    assign(test_msg_.states[31].fcn, 139);
    assign(test_msg_.states[31].sid.code, 179);
    assign(test_msg_.states[31].sid.sat, 196);

    assign(test_msg_.states[32].cn0, 171);
    assign(test_msg_.states[32].fcn, 196);
    assign(test_msg_.states[32].sid.code, 178);
    assign(test_msg_.states[32].sid.sat, 15);

    assign(test_msg_.states[33].cn0, 194);
    assign(test_msg_.states[33].fcn, 97);
    assign(test_msg_.states[33].sid.code, 212);
    assign(test_msg_.states[33].sid.sat, 8);

    assign(test_msg_.states[34].cn0, 99);
    assign(test_msg_.states[34].fcn, 79);
    assign(test_msg_.states[34].sid.code, 233);
    assign(test_msg_.states[34].sid.sat, 83);

    assign(test_msg_.states[35].cn0, 180);
    assign(test_msg_.states[35].fcn, 31);
    assign(test_msg_.states[35].sid.code, 90);
    assign(test_msg_.states[35].sid.sat, 55);

    assign(test_msg_.states[36].cn0, 186);
    assign(test_msg_.states[36].fcn, 105);
    assign(test_msg_.states[36].sid.code, 25);
    assign(test_msg_.states[36].sid.sat, 5);

    assign(test_msg_.states[37].cn0, 111);
    assign(test_msg_.states[37].fcn, 80);
    assign(test_msg_.states[37].sid.code, 224);
    assign(test_msg_.states[37].sid.sat, 22);

    assign(test_msg_.states[38].cn0, 166);
    assign(test_msg_.states[38].fcn, 106);
    assign(test_msg_.states[38].sid.code, 48);
    assign(test_msg_.states[38].sid.sat, 8);

    assign(test_msg_.states[39].cn0, 49);
    assign(test_msg_.states[39].fcn, 156);
    assign(test_msg_.states[39].sid.code, 48);
    assign(test_msg_.states[39].sid.sat, 4);

    assign(test_msg_.states[40].cn0, 146);
    assign(test_msg_.states[40].fcn, 142);
    assign(test_msg_.states[40].sid.code, 19);
    assign(test_msg_.states[40].sid.sat, 86);

    assign(test_msg_.states[41].cn0, 64);
    assign(test_msg_.states[41].fcn, 115);
    assign(test_msg_.states[41].sid.code, 124);
    assign(test_msg_.states[41].sid.sat, 91);

    assign(test_msg_.states[42].cn0, 178);
    assign(test_msg_.states[42].fcn, 115);
    assign(test_msg_.states[42].sid.code, 230);
    assign(test_msg_.states[42].sid.sat, 28);

    assign(test_msg_.states[43].cn0, 242);
    assign(test_msg_.states[43].fcn, 16);
    assign(test_msg_.states[43].sid.code, 131);
    assign(test_msg_.states[43].sid.sat, 190);

    assign(test_msg_.states[44].cn0, 113);
    assign(test_msg_.states[44].fcn, 182);
    assign(test_msg_.states[44].sid.code, 59);
    assign(test_msg_.states[44].sid.sat, 105);

    assign(test_msg_.states[45].cn0, 179);
    assign(test_msg_.states[45].fcn, 48);
    assign(test_msg_.states[45].sid.code, 180);
    assign(test_msg_.states[45].sid.sat, 192);

    assign(test_msg_.states[46].cn0, 211);
    assign(test_msg_.states[46].fcn, 172);
    assign(test_msg_.states[46].sid.code, 31);
    assign(test_msg_.states[46].sid.sat, 166);

    assign(test_msg_.states[47].cn0, 49);
    assign(test_msg_.states[47].fcn, 140);
    assign(test_msg_.states[47].sid.code, 228);
    assign(test_msg_.states[47].sid.sat, 77);

    assign(test_msg_.states[48].cn0, 194);
    assign(test_msg_.states[48].fcn, 240);
    assign(test_msg_.states[48].sid.code, 77);
    assign(test_msg_.states[48].sid.sat, 128);

    assign(test_msg_.states[49].cn0, 58);
    assign(test_msg_.states[49].fcn, 41);
    assign(test_msg_.states[49].sid.code, 194);
    assign(test_msg_.states[49].sid.sat, 134);

    assign(test_msg_.states[50].cn0, 55);
    assign(test_msg_.states[50].fcn, 129);
    assign(test_msg_.states[50].sid.code, 53);
    assign(test_msg_.states[50].sid.sat, 18);

    assign(test_msg_.states[51].cn0, 92);
    assign(test_msg_.states[51].fcn, 134);
    assign(test_msg_.states[51].sid.code, 72);
    assign(test_msg_.states[51].sid.sat, 91);

    assign(test_msg_.states[52].cn0, 56);
    assign(test_msg_.states[52].fcn, 157);
    assign(test_msg_.states[52].sid.code, 224);
    assign(test_msg_.states[52].sid.sat, 33);

    assign(test_msg_.states[53].cn0, 174);
    assign(test_msg_.states[53].fcn, 224);
    assign(test_msg_.states[53].sid.code, 54);
    assign(test_msg_.states[53].sid.sat, 186);

    assign(test_msg_.states[54].cn0, 190);
    assign(test_msg_.states[54].fcn, 148);
    assign(test_msg_.states[54].sid.code, 84);
    assign(test_msg_.states[54].sid.sat, 82);

    assign(test_msg_.states[55].cn0, 67);
    assign(test_msg_.states[55].fcn, 62);
    assign(test_msg_.states[55].sid.code, 54);
    assign(test_msg_.states[55].sid.sat, 236);

    assign(test_msg_.states[56].cn0, 254);
    assign(test_msg_.states[56].fcn, 57);
    assign(test_msg_.states[56].sid.code, 215);
    assign(test_msg_.states[56].sid.sat, 52);

    assign(test_msg_.states[57].cn0, 174);
    assign(test_msg_.states[57].fcn, 36);
    assign(test_msg_.states[57].sid.code, 133);
    assign(test_msg_.states[57].sid.sat, 16);

    assign(test_msg_.states[58].cn0, 17);
    assign(test_msg_.states[58].fcn, 145);
    assign(test_msg_.states[58].sid.code, 172);
    assign(test_msg_.states[58].sid.sat, 219);

    assign(test_msg_.states[59].cn0, 97);
    assign(test_msg_.states[59].fcn, 111);
    assign(test_msg_.states[59].sid.code, 179);
    assign(test_msg_.states[59].sid.sat, 192);

    assign(test_msg_.states[60].cn0, 134);
    assign(test_msg_.states[60].fcn, 208);
    assign(test_msg_.states[60].sid.code, 56);
    assign(test_msg_.states[60].sid.sat, 207);

    assign(test_msg_.states[61].cn0, 226);
    assign(test_msg_.states[61].fcn, 43);
    assign(test_msg_.states[61].sid.code, 17);
    assign(test_msg_.states[61].sid.sat, 180);

    assign(test_msg_.states[62].cn0, 113);
    assign(test_msg_.states[62].fcn, 140);
    assign(test_msg_.states[62].sid.code, 182);
    assign(test_msg_.states[62].sid.sat, 255);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_t> {
    using sbp::MessageHandler<sbp_msg_tracking_state_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_tracking_state_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingState,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingState);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state,
             sizeof(msg->tracking_state));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingState);
    info.sender_id = 33079;
    info.preamble = 0x55;
    info.crc = 0x6f8d;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 252;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_t &lesser,
                        const sbp_msg_tracking_state_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_tracking_state_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgTrackingState, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingState, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgTrackingState, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgTrackingState, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_tracking_state_t test_msg_{};
  uint8_t encoded_frame_[252 + 8] = {
      85,  65,  0,   55,  129, 252, 117, 184, 3,   102, 38,  106, 140, 141, 25,
      4,   90,  195, 246, 108, 75,  82,  137, 127, 45,  163, 32,  46,  187, 93,
      153, 60,  201, 147, 23,  29,  5,   208, 181, 30,  219, 69,  254, 136, 3,
      121, 33,  98,  144, 215, 133, 182, 14,  56,  169, 77,  218, 62,  242, 84,
      171, 249, 152, 137, 131, 130, 193, 21,  42,  68,  253, 227, 216, 227, 24,
      26,  210, 179, 19,  15,  227, 255, 122, 75,  187, 200, 217, 48,  218, 122,
      187, 238, 142, 149, 238, 55,  251, 212, 128, 160, 194, 104, 113, 255, 141,
      62,  43,  69,  245, 39,  100, 230, 108, 56,  247, 68,  149, 143, 137, 101,
      233, 70,  49,  165, 38,  110, 218, 230, 80,  213, 196, 179, 139, 128, 15,
      178, 196, 171, 8,   212, 97,  194, 83,  233, 79,  99,  55,  90,  31,  180,
      5,   25,  105, 186, 22,  224, 80,  111, 8,   48,  106, 166, 4,   48,  156,
      49,  86,  19,  142, 146, 91,  124, 115, 64,  28,  230, 115, 178, 190, 131,
      16,  242, 105, 59,  182, 113, 192, 180, 48,  179, 166, 31,  172, 211, 77,
      228, 140, 49,  128, 77,  240, 194, 134, 194, 41,  58,  18,  53,  129, 55,
      91,  72,  134, 92,  33,  224, 157, 56,  186, 54,  224, 174, 82,  84,  148,
      190, 236, 54,  62,  67,  52,  215, 57,  254, 16,  133, 36,  174, 219, 172,
      145, 17,  192, 179, 111, 97,  207, 56,  208, 134, 180, 17,  43,  226, 255,
      182, 140, 113, 141, 111,
  };
  uint8_t encoded_payload_[252] = {
      117, 184, 3,   102, 38,  106, 140, 141, 25,  4,   90,  195, 246, 108, 75,
      82,  137, 127, 45,  163, 32,  46,  187, 93,  153, 60,  201, 147, 23,  29,
      5,   208, 181, 30,  219, 69,  254, 136, 3,   121, 33,  98,  144, 215, 133,
      182, 14,  56,  169, 77,  218, 62,  242, 84,  171, 249, 152, 137, 131, 130,
      193, 21,  42,  68,  253, 227, 216, 227, 24,  26,  210, 179, 19,  15,  227,
      255, 122, 75,  187, 200, 217, 48,  218, 122, 187, 238, 142, 149, 238, 55,
      251, 212, 128, 160, 194, 104, 113, 255, 141, 62,  43,  69,  245, 39,  100,
      230, 108, 56,  247, 68,  149, 143, 137, 101, 233, 70,  49,  165, 38,  110,
      218, 230, 80,  213, 196, 179, 139, 128, 15,  178, 196, 171, 8,   212, 97,
      194, 83,  233, 79,  99,  55,  90,  31,  180, 5,   25,  105, 186, 22,  224,
      80,  111, 8,   48,  106, 166, 4,   48,  156, 49,  86,  19,  142, 146, 91,
      124, 115, 64,  28,  230, 115, 178, 190, 131, 16,  242, 105, 59,  182, 113,
      192, 180, 48,  179, 166, 31,  172, 211, 77,  228, 140, 49,  128, 77,  240,
      194, 134, 194, 41,  58,  18,  53,  129, 55,  91,  72,  134, 92,  33,  224,
      157, 56,  186, 54,  224, 174, 82,  84,  148, 190, 236, 54,  62,  67,  52,
      215, 57,  254, 16,  133, 36,  174, 219, 172, 145, 17,  192, 179, 111, 97,
      207, 56,  208, 134, 180, 17,  43,  226, 255, 182, 140, 113,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgTrackingState, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[252];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_encode(&buf[0], sizeof(buf), &n_written,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 252);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingState, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 252);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[252];

  EXPECT_EQ(sbp_msg_tracking_state_encode(&buf[0], sizeof(buf), nullptr,
                                          &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[252];

  for (uint8_t i = 0; i < 252; i++) {
    EXPECT_EQ(
        sbp_msg_tracking_state_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_decode(&info.encoded_payload[0],
                                          info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 252);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgTrackingState, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 252);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_decode(&info.encoded_payload[0],
                                          info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_tracking_state_t t{};
      return sbp_msg_tracking_state_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_tracking_state_t t{};
      t.n_states = 1;
      return sbp_msg_tracking_state_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_tracking_state_decode(&info.encoded_payload[0], i,
                                            nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_send(&state, info.sender_id, &info.test_msg,
                                        &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingState, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgTrackingState, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingState, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.n_states, greater.n_states);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].cn0, greater.states[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].fcn, greater.states[0].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.code, greater.states[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.sat, greater.states[0].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].cn0, greater.states[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].fcn, greater.states[1].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.code, greater.states[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.sat, greater.states[1].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].cn0, greater.states[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].fcn, greater.states[2].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.code, greater.states[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.sat, greater.states[2].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].cn0, greater.states[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].fcn, greater.states[3].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.code, greater.states[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.sat, greater.states[3].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].cn0, greater.states[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].fcn, greater.states[4].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.code, greater.states[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.sat, greater.states[4].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].cn0, greater.states[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].fcn, greater.states[5].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.code, greater.states[5].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.sat, greater.states[5].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].cn0, greater.states[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].fcn, greater.states[6].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.code, greater.states[6].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.sat, greater.states[6].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].cn0, greater.states[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].fcn, greater.states[7].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.code, greater.states[7].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.sat, greater.states[7].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].cn0, greater.states[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].fcn, greater.states[8].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.code, greater.states[8].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.sat, greater.states[8].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].cn0, greater.states[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].fcn, greater.states[9].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.code, greater.states[9].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.sat, greater.states[9].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].cn0, greater.states[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].fcn, greater.states[10].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.code,
                        greater.states[10].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.sat, greater.states[10].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[11].cn0, greater.states[11].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[11].fcn, greater.states[11].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[11].sid.code,
                        greater.states[11].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[11].sid.sat, greater.states[11].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[12].cn0, greater.states[12].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[12].fcn, greater.states[12].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[12].sid.code,
                        greater.states[12].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[12].sid.sat, greater.states[12].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[13].cn0, greater.states[13].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[13].fcn, greater.states[13].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[13].sid.code,
                        greater.states[13].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[13].sid.sat, greater.states[13].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[14].cn0, greater.states[14].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[14].fcn, greater.states[14].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[14].sid.code,
                        greater.states[14].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[14].sid.sat, greater.states[14].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[15].cn0, greater.states[15].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[15].fcn, greater.states[15].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[15].sid.code,
                        greater.states[15].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[15].sid.sat, greater.states[15].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[16].cn0, greater.states[16].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[16].fcn, greater.states[16].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[16].sid.code,
                        greater.states[16].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[16].sid.sat, greater.states[16].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[17].cn0, greater.states[17].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[17].fcn, greater.states[17].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[17].sid.code,
                        greater.states[17].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[17].sid.sat, greater.states[17].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[18].cn0, greater.states[18].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[18].fcn, greater.states[18].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[18].sid.code,
                        greater.states[18].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[18].sid.sat, greater.states[18].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[19].cn0, greater.states[19].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[19].fcn, greater.states[19].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[19].sid.code,
                        greater.states[19].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[19].sid.sat, greater.states[19].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[20].cn0, greater.states[20].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[20].fcn, greater.states[20].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[20].sid.code,
                        greater.states[20].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[20].sid.sat, greater.states[20].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[21].cn0, greater.states[21].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[21].fcn, greater.states[21].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[21].sid.code,
                        greater.states[21].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[21].sid.sat, greater.states[21].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[22].cn0, greater.states[22].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[22].fcn, greater.states[22].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[22].sid.code,
                        greater.states[22].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[22].sid.sat, greater.states[22].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[23].cn0, greater.states[23].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[23].fcn, greater.states[23].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[23].sid.code,
                        greater.states[23].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[23].sid.sat, greater.states[23].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[24].cn0, greater.states[24].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[24].fcn, greater.states[24].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[24].sid.code,
                        greater.states[24].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[24].sid.sat, greater.states[24].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[25].cn0, greater.states[25].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[25].fcn, greater.states[25].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[25].sid.code,
                        greater.states[25].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[25].sid.sat, greater.states[25].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[26].cn0, greater.states[26].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[26].fcn, greater.states[26].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[26].sid.code,
                        greater.states[26].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[26].sid.sat, greater.states[26].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[27].cn0, greater.states[27].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[27].fcn, greater.states[27].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[27].sid.code,
                        greater.states[27].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[27].sid.sat, greater.states[27].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[28].cn0, greater.states[28].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[28].fcn, greater.states[28].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[28].sid.code,
                        greater.states[28].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[28].sid.sat, greater.states[28].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[29].cn0, greater.states[29].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[29].fcn, greater.states[29].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[29].sid.code,
                        greater.states[29].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[29].sid.sat, greater.states[29].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[30].cn0, greater.states[30].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[30].fcn, greater.states[30].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[30].sid.code,
                        greater.states[30].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[30].sid.sat, greater.states[30].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[31].cn0, greater.states[31].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[31].fcn, greater.states[31].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[31].sid.code,
                        greater.states[31].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[31].sid.sat, greater.states[31].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[32].cn0, greater.states[32].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[32].fcn, greater.states[32].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[32].sid.code,
                        greater.states[32].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[32].sid.sat, greater.states[32].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[33].cn0, greater.states[33].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[33].fcn, greater.states[33].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[33].sid.code,
                        greater.states[33].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[33].sid.sat, greater.states[33].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[34].cn0, greater.states[34].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[34].fcn, greater.states[34].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[34].sid.code,
                        greater.states[34].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[34].sid.sat, greater.states[34].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[35].cn0, greater.states[35].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[35].fcn, greater.states[35].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[35].sid.code,
                        greater.states[35].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[35].sid.sat, greater.states[35].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[36].cn0, greater.states[36].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[36].fcn, greater.states[36].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[36].sid.code,
                        greater.states[36].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[36].sid.sat, greater.states[36].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[37].cn0, greater.states[37].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[37].fcn, greater.states[37].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[37].sid.code,
                        greater.states[37].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[37].sid.sat, greater.states[37].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[38].cn0, greater.states[38].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[38].fcn, greater.states[38].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[38].sid.code,
                        greater.states[38].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[38].sid.sat, greater.states[38].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[39].cn0, greater.states[39].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[39].fcn, greater.states[39].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[39].sid.code,
                        greater.states[39].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[39].sid.sat, greater.states[39].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[40].cn0, greater.states[40].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[40].fcn, greater.states[40].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[40].sid.code,
                        greater.states[40].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[40].sid.sat, greater.states[40].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[41].cn0, greater.states[41].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[41].fcn, greater.states[41].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[41].sid.code,
                        greater.states[41].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[41].sid.sat, greater.states[41].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[42].cn0, greater.states[42].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[42].fcn, greater.states[42].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[42].sid.code,
                        greater.states[42].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[42].sid.sat, greater.states[42].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[43].cn0, greater.states[43].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[43].fcn, greater.states[43].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[43].sid.code,
                        greater.states[43].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[43].sid.sat, greater.states[43].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[44].cn0, greater.states[44].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[44].fcn, greater.states[44].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[44].sid.code,
                        greater.states[44].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[44].sid.sat, greater.states[44].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[45].cn0, greater.states[45].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[45].fcn, greater.states[45].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[45].sid.code,
                        greater.states[45].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[45].sid.sat, greater.states[45].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[46].cn0, greater.states[46].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[46].fcn, greater.states[46].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[46].sid.code,
                        greater.states[46].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[46].sid.sat, greater.states[46].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[47].cn0, greater.states[47].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[47].fcn, greater.states[47].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[47].sid.code,
                        greater.states[47].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[47].sid.sat, greater.states[47].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[48].cn0, greater.states[48].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[48].fcn, greater.states[48].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[48].sid.code,
                        greater.states[48].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[48].sid.sat, greater.states[48].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[49].cn0, greater.states[49].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[49].fcn, greater.states[49].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[49].sid.code,
                        greater.states[49].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[49].sid.sat, greater.states[49].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[50].cn0, greater.states[50].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[50].fcn, greater.states[50].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[50].sid.code,
                        greater.states[50].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[50].sid.sat, greater.states[50].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[51].cn0, greater.states[51].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[51].fcn, greater.states[51].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[51].sid.code,
                        greater.states[51].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[51].sid.sat, greater.states[51].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[52].cn0, greater.states[52].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[52].fcn, greater.states[52].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[52].sid.code,
                        greater.states[52].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[52].sid.sat, greater.states[52].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[53].cn0, greater.states[53].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[53].fcn, greater.states[53].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[53].sid.code,
                        greater.states[53].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[53].sid.sat, greater.states[53].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[54].cn0, greater.states[54].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[54].fcn, greater.states[54].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[54].sid.code,
                        greater.states[54].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[54].sid.sat, greater.states[54].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[55].cn0, greater.states[55].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[55].fcn, greater.states[55].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[55].sid.code,
                        greater.states[55].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[55].sid.sat, greater.states[55].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[56].cn0, greater.states[56].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[56].fcn, greater.states[56].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[56].sid.code,
                        greater.states[56].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[56].sid.sat, greater.states[56].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[57].cn0, greater.states[57].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[57].fcn, greater.states[57].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[57].sid.code,
                        greater.states[57].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[57].sid.sat, greater.states[57].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[58].cn0, greater.states[58].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[58].fcn, greater.states[58].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[58].sid.code,
                        greater.states[58].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[58].sid.sat, greater.states[58].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[59].cn0, greater.states[59].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[59].fcn, greater.states[59].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[59].sid.code,
                        greater.states[59].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[59].sid.sat, greater.states[59].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[60].cn0, greater.states[60].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[60].fcn, greater.states[60].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[60].sid.code,
                        greater.states[60].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[60].sid.sat, greater.states[60].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[61].cn0, greater.states[61].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[61].fcn, greater.states[61].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[61].sid.code,
                        greater.states[61].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[61].sid.sat, greater.states[61].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[62].cn0, greater.states[62].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[62].fcn, greater.states[62].fcn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[62].sid.code,
                        greater.states[62].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_t lesser = info.test_msg;
    sbp_msg_tracking_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[62].sid.sat, greater.states[62].sid.sat);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_t>::id,
  // SbpMsgTrackingState);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_t>::name,
               "MSG_TRACKING_STATE");
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_t>::get(const_sbp_msg_t);
  sbp_msg_tracking_state_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.tracking_state, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_t>::to_sbp_msg(info.test_msg,
                                                           &msg2);
  EXPECT_EQ(msg2.tracking_state, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_tracking_state_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[252];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 252);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 252);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingState,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingState,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_tracking_MsgTrackingState1 : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgTrackingState1() {
    assign(test_msg_.n_states, 11);

    assign(test_msg_.states[0].cn0, 39.24782180786133);
    assign(test_msg_.states[0].sid.code, 0);
    assign(test_msg_.states[0].sid.reserved, 0);
    assign(test_msg_.states[0].sid.sat, 202);
    assign(test_msg_.states[0].state, 1);

    assign(test_msg_.states[1].cn0, 36.09756088256836);
    assign(test_msg_.states[1].sid.code, 0);
    assign(test_msg_.states[1].sid.reserved, 0);
    assign(test_msg_.states[1].sid.sat, 203);
    assign(test_msg_.states[1].state, 1);

    assign(test_msg_.states[2].cn0, 37.62678527832031);
    assign(test_msg_.states[2].sid.code, 0);
    assign(test_msg_.states[2].sid.reserved, 0);
    assign(test_msg_.states[2].sid.sat, 208);
    assign(test_msg_.states[2].state, 1);

    assign(test_msg_.states[3].cn0, 39.020729064941406);
    assign(test_msg_.states[3].sid.code, 0);
    assign(test_msg_.states[3].sid.reserved, 0);
    assign(test_msg_.states[3].sid.sat, 212);
    assign(test_msg_.states[3].state, 1);

    assign(test_msg_.states[4].cn0, 42.03290557861328);
    assign(test_msg_.states[4].sid.code, 0);
    assign(test_msg_.states[4].sid.reserved, 0);
    assign(test_msg_.states[4].sid.sat, 217);
    assign(test_msg_.states[4].state, 1);

    assign(test_msg_.states[5].cn0, 37.43546676635742);
    assign(test_msg_.states[5].sid.code, 0);
    assign(test_msg_.states[5].sid.reserved, 0);
    assign(test_msg_.states[5].sid.sat, 218);
    assign(test_msg_.states[5].state, 1);

    assign(test_msg_.states[6].cn0, 38.4229621887207);
    assign(test_msg_.states[6].sid.code, 0);
    assign(test_msg_.states[6].sid.reserved, 0);
    assign(test_msg_.states[6].sid.sat, 220);
    assign(test_msg_.states[6].state, 1);

    assign(test_msg_.states[7].cn0, 38.91520309448242);
    assign(test_msg_.states[7].sid.code, 0);
    assign(test_msg_.states[7].sid.reserved, 0);
    assign(test_msg_.states[7].sid.sat, 222);
    assign(test_msg_.states[7].state, 1);

    assign(test_msg_.states[8].cn0, 42.62259292602539);
    assign(test_msg_.states[8].sid.code, 0);
    assign(test_msg_.states[8].sid.reserved, 0);
    assign(test_msg_.states[8].sid.sat, 225);
    assign(test_msg_.states[8].state, 1);

    assign(test_msg_.states[9].cn0, -1.0);
    assign(test_msg_.states[9].sid.code, 0);
    assign(test_msg_.states[9].sid.reserved, 0);
    assign(test_msg_.states[9].sid.sat, 0);
    assign(test_msg_.states[9].state, 0);

    assign(test_msg_.states[10].cn0, -1.0);
    assign(test_msg_.states[10].sid.code, 0);
    assign(test_msg_.states[10].sid.reserved, 0);
    assign(test_msg_.states[10].sid.sat, 0);
    assign(test_msg_.states[10].state, 0);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_tracking_state_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDepB,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_dep_b,
             sizeof(msg->tracking_state_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_dep_b, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDepB);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0x61de;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 99;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_dep_b_t &lesser,
                        const sbp_msg_tracking_state_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_tracking_state_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_greater,
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
  sbp_msg_tracking_state_dep_b_t test_msg_{};
  uint8_t encoded_frame_[99 + 8] = {
      85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   197, 253, 28,
      66,  1,   203, 0,   0,   0,   231, 99,  16, 66,  1,   208, 0,   0,
      0,   212, 129, 22,  66,  1,   212, 0,   0,  0,   58,  21,  28,  66,
      1,   217, 0,   0,   0,   178, 33,  40,  66, 1,   218, 0,   0,   0,
      235, 189, 21,  66,  1,   220, 0,   0,   0,  29,  177, 25,  66,  1,
      222, 0,   0,   0,   43,  169, 27,  66,  1,  225, 0,   0,   0,   137,
      125, 42,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
      0,   0,   0,   0,   0,   128, 191, 222, 97,
  };
  uint8_t encoded_payload_[99] = {
      1, 202, 0, 0, 0, 197, 253, 28,  66,  1, 203, 0, 0, 0, 231, 99,  16,  66,
      1, 208, 0, 0, 0, 212, 129, 22,  66,  1, 212, 0, 0, 0, 58,  21,  28,  66,
      1, 217, 0, 0, 0, 178, 33,  40,  66,  1, 218, 0, 0, 0, 235, 189, 21,  66,
      1, 220, 0, 0, 0, 29,  177, 25,  66,  1, 222, 0, 0, 0, 43,  169, 27,  66,
      1, 225, 0, 0, 0, 137, 125, 42,  66,  0, 0,   0, 0, 0, 0,   0,   128, 191,
      0, 0,   0, 0, 0, 0,   0,   128, 191,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgTrackingStateDepB, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[99];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], sizeof(buf),
                                                &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDepB, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[99];

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[99];

  for (uint8_t i = 0; i < 99; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], i, nullptr,
                                                  &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgTrackingStateDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_tracking_state_dep_b_t t{};
      return sbp_msg_tracking_state_dep_b_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_tracking_state_dep_b_t t{};
      t.n_states = 1;
      return sbp_msg_tracking_state_dep_b_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(&info.encoded_payload[0], i,
                                                  nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_send(&state, info.sender_id,
                                              &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.n_states, greater.n_states);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].cn0, greater.states[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.code, greater.states[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.reserved,
                        greater.states[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.sat, greater.states[0].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].state, greater.states[0].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].cn0, greater.states[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.code, greater.states[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.reserved,
                        greater.states[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.sat, greater.states[1].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].state, greater.states[1].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].cn0, greater.states[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.code, greater.states[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.reserved,
                        greater.states[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.sat, greater.states[2].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].state, greater.states[2].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].cn0, greater.states[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.code, greater.states[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.reserved,
                        greater.states[3].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.sat, greater.states[3].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].state, greater.states[3].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].cn0, greater.states[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.code, greater.states[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.reserved,
                        greater.states[4].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.sat, greater.states[4].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].state, greater.states[4].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].cn0, greater.states[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.code, greater.states[5].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.reserved,
                        greater.states[5].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.sat, greater.states[5].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].state, greater.states[5].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].cn0, greater.states[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.code, greater.states[6].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.reserved,
                        greater.states[6].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.sat, greater.states[6].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].state, greater.states[6].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].cn0, greater.states[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.code, greater.states[7].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.reserved,
                        greater.states[7].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.sat, greater.states[7].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].state, greater.states[7].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].cn0, greater.states[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.code, greater.states[8].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.reserved,
                        greater.states[8].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.sat, greater.states[8].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].state, greater.states[8].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].cn0, greater.states[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.code, greater.states[9].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.reserved,
                        greater.states[9].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.sat, greater.states[9].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].state, greater.states[9].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].cn0, greater.states[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.code,
                        greater.states[10].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.reserved,
                        greater.states[10].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.sat, greater.states[10].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].state, greater.states[10].state);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::id,
  // SbpMsgTrackingStateDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::name,
               "MSG_TRACKING_STATE_DEP_B");
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_tracking_state_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(info.test_msg,
                                                                 &msg2);
  EXPECT_EQ(msg2.tracking_state_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[99];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDepB,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState1,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDepB,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_tracking_MsgTrackingState2 : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgTrackingState2() {
    assign(test_msg_.n_states, 11);

    assign(test_msg_.states[0].cn0, 38.994117736816406);
    assign(test_msg_.states[0].sid.code, 0);
    assign(test_msg_.states[0].sid.reserved, 0);
    assign(test_msg_.states[0].sid.sat, 202);
    assign(test_msg_.states[0].state, 1);

    assign(test_msg_.states[1].cn0, 34.889801025390625);
    assign(test_msg_.states[1].sid.code, 0);
    assign(test_msg_.states[1].sid.reserved, 0);
    assign(test_msg_.states[1].sid.sat, 203);
    assign(test_msg_.states[1].state, 1);

    assign(test_msg_.states[2].cn0, 37.44603729248047);
    assign(test_msg_.states[2].sid.code, 0);
    assign(test_msg_.states[2].sid.reserved, 0);
    assign(test_msg_.states[2].sid.sat, 208);
    assign(test_msg_.states[2].state, 1);

    assign(test_msg_.states[3].cn0, 38.72849655151367);
    assign(test_msg_.states[3].sid.code, 0);
    assign(test_msg_.states[3].sid.reserved, 0);
    assign(test_msg_.states[3].sid.sat, 212);
    assign(test_msg_.states[3].state, 1);

    assign(test_msg_.states[4].cn0, 41.983219146728516);
    assign(test_msg_.states[4].sid.code, 0);
    assign(test_msg_.states[4].sid.reserved, 0);
    assign(test_msg_.states[4].sid.sat, 217);
    assign(test_msg_.states[4].state, 1);

    assign(test_msg_.states[5].cn0, 37.46448516845703);
    assign(test_msg_.states[5].sid.code, 0);
    assign(test_msg_.states[5].sid.reserved, 0);
    assign(test_msg_.states[5].sid.sat, 218);
    assign(test_msg_.states[5].state, 1);

    assign(test_msg_.states[6].cn0, 38.44300079345703);
    assign(test_msg_.states[6].sid.code, 0);
    assign(test_msg_.states[6].sid.reserved, 0);
    assign(test_msg_.states[6].sid.sat, 220);
    assign(test_msg_.states[6].state, 1);

    assign(test_msg_.states[7].cn0, 39.03423309326172);
    assign(test_msg_.states[7].sid.code, 0);
    assign(test_msg_.states[7].sid.reserved, 0);
    assign(test_msg_.states[7].sid.sat, 222);
    assign(test_msg_.states[7].state, 1);

    assign(test_msg_.states[8].cn0, 42.89944839477539);
    assign(test_msg_.states[8].sid.code, 0);
    assign(test_msg_.states[8].sid.reserved, 0);
    assign(test_msg_.states[8].sid.sat, 225);
    assign(test_msg_.states[8].state, 1);

    assign(test_msg_.states[9].cn0, -1.0);
    assign(test_msg_.states[9].sid.code, 0);
    assign(test_msg_.states[9].sid.reserved, 0);
    assign(test_msg_.states[9].sid.sat, 0);
    assign(test_msg_.states[9].state, 0);

    assign(test_msg_.states[10].cn0, -1.0);
    assign(test_msg_.states[10].sid.code, 0);
    assign(test_msg_.states[10].sid.reserved, 0);
    assign(test_msg_.states[10].sid.sat, 0);
    assign(test_msg_.states[10].state, 0);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_tracking_state_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDepB,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_dep_b,
             sizeof(msg->tracking_state_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_dep_b, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDepB);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0x1f14;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 99;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_dep_b_t &lesser,
                        const sbp_msg_tracking_state_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_tracking_state_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_greater,
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
  sbp_msg_tracking_state_dep_b_t test_msg_{};
  uint8_t encoded_frame_[99 + 8] = {
      85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   250, 249, 27,
      66,  1,   203, 0,   0,   0,   40,  143, 11, 66,  1,   208, 0,   0,
      0,   190, 200, 21,  66,  1,   212, 0,   0,  0,   251, 233, 26,  66,
      1,   217, 0,   0,   0,   209, 238, 39,  66, 1,   218, 0,   0,   0,
      162, 219, 21,  66,  1,   220, 0,   0,   0,  162, 197, 25,  66,  1,
      222, 0,   0,   0,   14,  35,  28,  66,  1,  225, 0,   0,   0,   9,
      153, 43,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
      0,   0,   0,   0,   0,   128, 191, 20,  31,
  };
  uint8_t encoded_payload_[99] = {
      1, 202, 0, 0, 0, 250, 249, 27,  66,  1, 203, 0, 0, 0, 40,  143, 11,  66,
      1, 208, 0, 0, 0, 190, 200, 21,  66,  1, 212, 0, 0, 0, 251, 233, 26,  66,
      1, 217, 0, 0, 0, 209, 238, 39,  66,  1, 218, 0, 0, 0, 162, 219, 21,  66,
      1, 220, 0, 0, 0, 162, 197, 25,  66,  1, 222, 0, 0, 0, 14,  35,  28,  66,
      1, 225, 0, 0, 0, 9,   153, 43,  66,  0, 0,   0, 0, 0, 0,   0,   128, 191,
      0, 0,   0, 0, 0, 0,   0,   128, 191,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgTrackingStateDepB, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[99];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], sizeof(buf),
                                                &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDepB, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[99];

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[99];

  for (uint8_t i = 0; i < 99; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], i, nullptr,
                                                  &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgTrackingStateDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_tracking_state_dep_b_t t{};
      return sbp_msg_tracking_state_dep_b_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_tracking_state_dep_b_t t{};
      t.n_states = 1;
      return sbp_msg_tracking_state_dep_b_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(&info.encoded_payload[0], i,
                                                  nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_send(&state, info.sender_id,
                                              &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.n_states, greater.n_states);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].cn0, greater.states[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.code, greater.states[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.reserved,
                        greater.states[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.sat, greater.states[0].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].state, greater.states[0].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].cn0, greater.states[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.code, greater.states[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.reserved,
                        greater.states[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.sat, greater.states[1].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].state, greater.states[1].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].cn0, greater.states[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.code, greater.states[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.reserved,
                        greater.states[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.sat, greater.states[2].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].state, greater.states[2].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].cn0, greater.states[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.code, greater.states[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.reserved,
                        greater.states[3].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.sat, greater.states[3].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].state, greater.states[3].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].cn0, greater.states[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.code, greater.states[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.reserved,
                        greater.states[4].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.sat, greater.states[4].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].state, greater.states[4].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].cn0, greater.states[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.code, greater.states[5].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.reserved,
                        greater.states[5].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.sat, greater.states[5].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].state, greater.states[5].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].cn0, greater.states[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.code, greater.states[6].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.reserved,
                        greater.states[6].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.sat, greater.states[6].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].state, greater.states[6].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].cn0, greater.states[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.code, greater.states[7].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.reserved,
                        greater.states[7].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.sat, greater.states[7].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].state, greater.states[7].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].cn0, greater.states[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.code, greater.states[8].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.reserved,
                        greater.states[8].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.sat, greater.states[8].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].state, greater.states[8].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].cn0, greater.states[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.code, greater.states[9].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.reserved,
                        greater.states[9].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.sat, greater.states[9].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].state, greater.states[9].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].cn0, greater.states[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.code,
                        greater.states[10].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.reserved,
                        greater.states[10].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.sat, greater.states[10].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].state, greater.states[10].state);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::id,
  // SbpMsgTrackingStateDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::name,
               "MSG_TRACKING_STATE_DEP_B");
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_tracking_state_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(info.test_msg,
                                                                 &msg2);
  EXPECT_EQ(msg2.tracking_state_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[99];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDepB,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState2,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDepB,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_tracking_MsgTrackingState3 : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgTrackingState3() {
    assign(test_msg_.n_states, 11);

    assign(test_msg_.states[0].cn0, 38.95457077026367);
    assign(test_msg_.states[0].sid.code, 0);
    assign(test_msg_.states[0].sid.reserved, 0);
    assign(test_msg_.states[0].sid.sat, 202);
    assign(test_msg_.states[0].state, 1);

    assign(test_msg_.states[1].cn0, 35.813316345214844);
    assign(test_msg_.states[1].sid.code, 0);
    assign(test_msg_.states[1].sid.reserved, 0);
    assign(test_msg_.states[1].sid.sat, 203);
    assign(test_msg_.states[1].state, 1);

    assign(test_msg_.states[2].cn0, 37.553924560546875);
    assign(test_msg_.states[2].sid.code, 0);
    assign(test_msg_.states[2].sid.reserved, 0);
    assign(test_msg_.states[2].sid.sat, 208);
    assign(test_msg_.states[2].state, 1);

    assign(test_msg_.states[3].cn0, 38.88901901245117);
    assign(test_msg_.states[3].sid.code, 0);
    assign(test_msg_.states[3].sid.reserved, 0);
    assign(test_msg_.states[3].sid.sat, 212);
    assign(test_msg_.states[3].state, 1);

    assign(test_msg_.states[4].cn0, 42.4013557434082);
    assign(test_msg_.states[4].sid.code, 0);
    assign(test_msg_.states[4].sid.reserved, 0);
    assign(test_msg_.states[4].sid.sat, 217);
    assign(test_msg_.states[4].state, 1);

    assign(test_msg_.states[5].cn0, 37.63916015625);
    assign(test_msg_.states[5].sid.code, 0);
    assign(test_msg_.states[5].sid.reserved, 0);
    assign(test_msg_.states[5].sid.sat, 218);
    assign(test_msg_.states[5].state, 1);

    assign(test_msg_.states[6].cn0, 37.919986724853516);
    assign(test_msg_.states[6].sid.code, 0);
    assign(test_msg_.states[6].sid.reserved, 0);
    assign(test_msg_.states[6].sid.sat, 220);
    assign(test_msg_.states[6].state, 1);

    assign(test_msg_.states[7].cn0, 39.25254440307617);
    assign(test_msg_.states[7].sid.code, 0);
    assign(test_msg_.states[7].sid.reserved, 0);
    assign(test_msg_.states[7].sid.sat, 222);
    assign(test_msg_.states[7].state, 1);

    assign(test_msg_.states[8].cn0, 42.59827423095703);
    assign(test_msg_.states[8].sid.code, 0);
    assign(test_msg_.states[8].sid.reserved, 0);
    assign(test_msg_.states[8].sid.sat, 225);
    assign(test_msg_.states[8].state, 1);

    assign(test_msg_.states[9].cn0, -1.0);
    assign(test_msg_.states[9].sid.code, 0);
    assign(test_msg_.states[9].sid.reserved, 0);
    assign(test_msg_.states[9].sid.sat, 0);
    assign(test_msg_.states[9].state, 0);

    assign(test_msg_.states[10].cn0, -1.0);
    assign(test_msg_.states[10].sid.code, 0);
    assign(test_msg_.states[10].sid.reserved, 0);
    assign(test_msg_.states[10].sid.sat, 0);
    assign(test_msg_.states[10].state, 0);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_tracking_state_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDepB,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_dep_b,
             sizeof(msg->tracking_state_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_dep_b, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDepB);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0x47e9;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 99;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_dep_b_t &lesser,
                        const sbp_msg_tracking_state_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_tracking_state_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_greater,
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
  sbp_msg_tracking_state_dep_b_t test_msg_{};
  uint8_t encoded_frame_[99 + 8] = {
      85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   123, 209, 27,
      66,  1,   203, 0,   0,   0,   214, 64,  15, 66,  1,   208, 0,   0,
      0,   56,  55,  22,  66,  1,   212, 0,   0,  0,   91,  142, 27,  66,
      1,   217, 0,   0,   0,   253, 154, 41,  66, 1,   218, 0,   0,   0,
      128, 142, 22,  66,  1,   220, 0,   0,   0,  17,  174, 23,  66,  1,
      222, 0,   0,   0,   155, 2,   29,  66,  1,  225, 0,   0,   0,   162,
      100, 42,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
      0,   0,   0,   0,   0,   128, 191, 233, 71,
  };
  uint8_t encoded_payload_[99] = {
      1, 202, 0, 0, 0, 123, 209, 27,  66,  1, 203, 0, 0, 0, 214, 64,  15,  66,
      1, 208, 0, 0, 0, 56,  55,  22,  66,  1, 212, 0, 0, 0, 91,  142, 27,  66,
      1, 217, 0, 0, 0, 253, 154, 41,  66,  1, 218, 0, 0, 0, 128, 142, 22,  66,
      1, 220, 0, 0, 0, 17,  174, 23,  66,  1, 222, 0, 0, 0, 155, 2,   29,  66,
      1, 225, 0, 0, 0, 162, 100, 42,  66,  0, 0,   0, 0, 0, 0,   0,   128, 191,
      0, 0,   0, 0, 0, 0,   0,   128, 191,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgTrackingStateDepB, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[99];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], sizeof(buf),
                                                &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDepB, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[99];

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[99];

  for (uint8_t i = 0; i < 99; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], i, nullptr,
                                                  &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgTrackingStateDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_tracking_state_dep_b_t t{};
      return sbp_msg_tracking_state_dep_b_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_tracking_state_dep_b_t t{};
      t.n_states = 1;
      return sbp_msg_tracking_state_dep_b_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(&info.encoded_payload[0], i,
                                                  nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_send(&state, info.sender_id,
                                              &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.n_states, greater.n_states);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].cn0, greater.states[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.code, greater.states[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.reserved,
                        greater.states[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.sat, greater.states[0].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].state, greater.states[0].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].cn0, greater.states[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.code, greater.states[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.reserved,
                        greater.states[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.sat, greater.states[1].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].state, greater.states[1].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].cn0, greater.states[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.code, greater.states[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.reserved,
                        greater.states[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.sat, greater.states[2].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].state, greater.states[2].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].cn0, greater.states[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.code, greater.states[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.reserved,
                        greater.states[3].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.sat, greater.states[3].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].state, greater.states[3].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].cn0, greater.states[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.code, greater.states[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.reserved,
                        greater.states[4].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.sat, greater.states[4].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].state, greater.states[4].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].cn0, greater.states[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.code, greater.states[5].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.reserved,
                        greater.states[5].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.sat, greater.states[5].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].state, greater.states[5].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].cn0, greater.states[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.code, greater.states[6].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.reserved,
                        greater.states[6].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.sat, greater.states[6].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].state, greater.states[6].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].cn0, greater.states[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.code, greater.states[7].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.reserved,
                        greater.states[7].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.sat, greater.states[7].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].state, greater.states[7].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].cn0, greater.states[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.code, greater.states[8].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.reserved,
                        greater.states[8].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.sat, greater.states[8].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].state, greater.states[8].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].cn0, greater.states[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.code, greater.states[9].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.reserved,
                        greater.states[9].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.sat, greater.states[9].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].state, greater.states[9].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].cn0, greater.states[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.code,
                        greater.states[10].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.reserved,
                        greater.states[10].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.sat, greater.states[10].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].state, greater.states[10].state);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::id,
  // SbpMsgTrackingStateDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::name,
               "MSG_TRACKING_STATE_DEP_B");
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_tracking_state_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(info.test_msg,
                                                                 &msg2);
  EXPECT_EQ(msg2.tracking_state_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[99];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDepB,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState3,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDepB,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_tracking_MsgTrackingState4 : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgTrackingState4() {
    assign(test_msg_.n_states, 11);

    assign(test_msg_.states[0].cn0, 39.369598388671875);
    assign(test_msg_.states[0].sid.code, 0);
    assign(test_msg_.states[0].sid.reserved, 0);
    assign(test_msg_.states[0].sid.sat, 202);
    assign(test_msg_.states[0].state, 1);

    assign(test_msg_.states[1].cn0, 36.52173614501953);
    assign(test_msg_.states[1].sid.code, 0);
    assign(test_msg_.states[1].sid.reserved, 0);
    assign(test_msg_.states[1].sid.sat, 203);
    assign(test_msg_.states[1].state, 1);

    assign(test_msg_.states[2].cn0, 38.15976333618164);
    assign(test_msg_.states[2].sid.code, 0);
    assign(test_msg_.states[2].sid.reserved, 0);
    assign(test_msg_.states[2].sid.sat, 208);
    assign(test_msg_.states[2].state, 1);

    assign(test_msg_.states[3].cn0, 39.19989776611328);
    assign(test_msg_.states[3].sid.code, 0);
    assign(test_msg_.states[3].sid.reserved, 0);
    assign(test_msg_.states[3].sid.sat, 212);
    assign(test_msg_.states[3].state, 1);

    assign(test_msg_.states[4].cn0, 41.55845642089844);
    assign(test_msg_.states[4].sid.code, 0);
    assign(test_msg_.states[4].sid.reserved, 0);
    assign(test_msg_.states[4].sid.sat, 217);
    assign(test_msg_.states[4].state, 1);

    assign(test_msg_.states[5].cn0, 37.026981353759766);
    assign(test_msg_.states[5].sid.code, 0);
    assign(test_msg_.states[5].sid.reserved, 0);
    assign(test_msg_.states[5].sid.sat, 218);
    assign(test_msg_.states[5].state, 1);

    assign(test_msg_.states[6].cn0, 38.1049690246582);
    assign(test_msg_.states[6].sid.code, 0);
    assign(test_msg_.states[6].sid.reserved, 0);
    assign(test_msg_.states[6].sid.sat, 220);
    assign(test_msg_.states[6].state, 1);

    assign(test_msg_.states[7].cn0, 39.04584503173828);
    assign(test_msg_.states[7].sid.code, 0);
    assign(test_msg_.states[7].sid.reserved, 0);
    assign(test_msg_.states[7].sid.sat, 222);
    assign(test_msg_.states[7].state, 1);

    assign(test_msg_.states[8].cn0, 42.37783432006836);
    assign(test_msg_.states[8].sid.code, 0);
    assign(test_msg_.states[8].sid.reserved, 0);
    assign(test_msg_.states[8].sid.sat, 225);
    assign(test_msg_.states[8].state, 1);

    assign(test_msg_.states[9].cn0, -1.0);
    assign(test_msg_.states[9].sid.code, 0);
    assign(test_msg_.states[9].sid.reserved, 0);
    assign(test_msg_.states[9].sid.sat, 0);
    assign(test_msg_.states[9].state, 0);

    assign(test_msg_.states[10].cn0, -1.0);
    assign(test_msg_.states[10].sid.code, 0);
    assign(test_msg_.states[10].sid.reserved, 0);
    assign(test_msg_.states[10].sid.sat, 0);
    assign(test_msg_.states[10].state, 0);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_tracking_state_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDepB,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_dep_b,
             sizeof(msg->tracking_state_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_dep_b, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDepB);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0xc149;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 99;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_dep_b_t &lesser,
                        const sbp_msg_tracking_state_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_tracking_state_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_greater,
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
  sbp_msg_tracking_state_dep_b_t test_msg_{};
  uint8_t encoded_frame_[99 + 8] = {
      85,  19,  0,   246, 215, 99,  1,   202, 0,   0,   0,   120, 122, 29,
      66,  1,   203, 0,   0,   0,   66,  22,  18,  66,  1,   208, 0,   0,
      0,   153, 163, 24,  66,  1,   212, 0,   0,   0,   178, 204, 28,  66,
      1,   217, 0,   0,   0,   220, 59,  38,  66,  1,   218, 0,   0,   0,
      161, 27,  20,  66,  1,   220, 0,   0,   0,   125, 107, 24,  66,  1,
      222, 0,   0,   0,   242, 46,  28,  66,  1,   225, 0,   0,   0,   231,
      130, 41,  66,  0,   0,   0,   0,   0,   0,   0,   128, 191, 0,   0,
      0,   0,   0,   0,   0,   128, 191, 73,  193,
  };
  uint8_t encoded_payload_[99] = {
      1, 202, 0, 0, 0, 120, 122, 29,  66,  1, 203, 0, 0, 0, 66,  22,  18,  66,
      1, 208, 0, 0, 0, 153, 163, 24,  66,  1, 212, 0, 0, 0, 178, 204, 28,  66,
      1, 217, 0, 0, 0, 220, 59,  38,  66,  1, 218, 0, 0, 0, 161, 27,  20,  66,
      1, 220, 0, 0, 0, 125, 107, 24,  66,  1, 222, 0, 0, 0, 242, 46,  28,  66,
      1, 225, 0, 0, 0, 231, 130, 41,  66,  0, 0,   0, 0, 0, 0,   0,   128, 191,
      0, 0,   0, 0, 0, 0,   0,   128, 191,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgTrackingStateDepB, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[99];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], sizeof(buf),
                                                &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDepB, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[99];

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[99];

  for (uint8_t i = 0; i < 99; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], i, nullptr,
                                                  &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgTrackingStateDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_tracking_state_dep_b_t t{};
      return sbp_msg_tracking_state_dep_b_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_tracking_state_dep_b_t t{};
      t.n_states = 1;
      return sbp_msg_tracking_state_dep_b_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(&info.encoded_payload[0], i,
                                                  nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_send(&state, info.sender_id,
                                              &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.n_states, greater.n_states);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].cn0, greater.states[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.code, greater.states[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.reserved,
                        greater.states[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.sat, greater.states[0].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].state, greater.states[0].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].cn0, greater.states[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.code, greater.states[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.reserved,
                        greater.states[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.sat, greater.states[1].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].state, greater.states[1].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].cn0, greater.states[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.code, greater.states[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.reserved,
                        greater.states[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.sat, greater.states[2].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].state, greater.states[2].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].cn0, greater.states[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.code, greater.states[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.reserved,
                        greater.states[3].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.sat, greater.states[3].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].state, greater.states[3].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].cn0, greater.states[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.code, greater.states[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.reserved,
                        greater.states[4].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.sat, greater.states[4].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].state, greater.states[4].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].cn0, greater.states[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.code, greater.states[5].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.reserved,
                        greater.states[5].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.sat, greater.states[5].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].state, greater.states[5].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].cn0, greater.states[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.code, greater.states[6].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.reserved,
                        greater.states[6].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.sat, greater.states[6].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].state, greater.states[6].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].cn0, greater.states[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.code, greater.states[7].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.reserved,
                        greater.states[7].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.sat, greater.states[7].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].state, greater.states[7].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].cn0, greater.states[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.code, greater.states[8].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.reserved,
                        greater.states[8].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.sat, greater.states[8].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].state, greater.states[8].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].cn0, greater.states[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.code, greater.states[9].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.reserved,
                        greater.states[9].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.sat, greater.states[9].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].state, greater.states[9].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].cn0, greater.states[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.code,
                        greater.states[10].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.reserved,
                        greater.states[10].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.sat, greater.states[10].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].state, greater.states[10].state);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::id,
  // SbpMsgTrackingStateDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::name,
               "MSG_TRACKING_STATE_DEP_B");
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_tracking_state_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(info.test_msg,
                                                                 &msg2);
  EXPECT_EQ(msg2.tracking_state_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[99];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDepB,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState4,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDepB,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_tracking_MsgTrackingState5 : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgTrackingState5() {
    assign(test_msg_.n_states, 11);

    assign(test_msg_.states[0].cn0, 39.70351791381836);
    assign(test_msg_.states[0].sid.code, 0);
    assign(test_msg_.states[0].sid.reserved, 0);
    assign(test_msg_.states[0].sid.sat, 202);
    assign(test_msg_.states[0].state, 1);

    assign(test_msg_.states[1].cn0, 36.52388381958008);
    assign(test_msg_.states[1].sid.code, 0);
    assign(test_msg_.states[1].sid.reserved, 0);
    assign(test_msg_.states[1].sid.sat, 203);
    assign(test_msg_.states[1].state, 1);

    assign(test_msg_.states[2].cn0, 37.169708251953125);
    assign(test_msg_.states[2].sid.code, 0);
    assign(test_msg_.states[2].sid.reserved, 0);
    assign(test_msg_.states[2].sid.sat, 208);
    assign(test_msg_.states[2].state, 1);

    assign(test_msg_.states[3].cn0, 38.81692886352539);
    assign(test_msg_.states[3].sid.code, 0);
    assign(test_msg_.states[3].sid.reserved, 0);
    assign(test_msg_.states[3].sid.sat, 212);
    assign(test_msg_.states[3].state, 1);

    assign(test_msg_.states[4].cn0, 42.05073165893555);
    assign(test_msg_.states[4].sid.code, 0);
    assign(test_msg_.states[4].sid.reserved, 0);
    assign(test_msg_.states[4].sid.sat, 217);
    assign(test_msg_.states[4].state, 1);

    assign(test_msg_.states[5].cn0, 37.807498931884766);
    assign(test_msg_.states[5].sid.code, 0);
    assign(test_msg_.states[5].sid.reserved, 0);
    assign(test_msg_.states[5].sid.sat, 218);
    assign(test_msg_.states[5].state, 1);

    assign(test_msg_.states[6].cn0, 37.71632385253906);
    assign(test_msg_.states[6].sid.code, 0);
    assign(test_msg_.states[6].sid.reserved, 0);
    assign(test_msg_.states[6].sid.sat, 220);
    assign(test_msg_.states[6].state, 1);

    assign(test_msg_.states[7].cn0, 38.5289192199707);
    assign(test_msg_.states[7].sid.code, 0);
    assign(test_msg_.states[7].sid.reserved, 0);
    assign(test_msg_.states[7].sid.sat, 222);
    assign(test_msg_.states[7].state, 1);

    assign(test_msg_.states[8].cn0, 42.27101516723633);
    assign(test_msg_.states[8].sid.code, 0);
    assign(test_msg_.states[8].sid.reserved, 0);
    assign(test_msg_.states[8].sid.sat, 225);
    assign(test_msg_.states[8].state, 1);

    assign(test_msg_.states[9].cn0, -1.0);
    assign(test_msg_.states[9].sid.code, 0);
    assign(test_msg_.states[9].sid.reserved, 0);
    assign(test_msg_.states[9].sid.sat, 0);
    assign(test_msg_.states[9].state, 0);

    assign(test_msg_.states[10].cn0, -1.0);
    assign(test_msg_.states[10].sid.code, 0);
    assign(test_msg_.states[10].sid.reserved, 0);
    assign(test_msg_.states[10].sid.sat, 0);
    assign(test_msg_.states[10].state, 0);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_tracking_state_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDepB,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_dep_b,
             sizeof(msg->tracking_state_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_dep_b, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDepB);
    info.sender_id = 55286;
    info.preamble = 0x55;
    info.crc = 0x2f7e;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 99;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_dep_b_t &lesser,
                        const sbp_msg_tracking_state_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_tracking_state_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_greater,
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
  sbp_msg_tracking_state_dep_b_t test_msg_{};
  uint8_t encoded_frame_[99 + 8] = {
      85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   103, 208, 30,
      66,  1,   203, 0,   0,   0,   117, 24,  18, 66,  1,   208, 0,   0,
      0,   200, 173, 20,  66,  1,   212, 0,   0,  0,   137, 68,  27,  66,
      1,   217, 0,   0,   0,   243, 51,  40,  66, 1,   218, 0,   0,   0,
      225, 58,  23,  66,  1,   220, 0,   0,   0,  132, 221, 22,  66,  1,
      222, 0,   0,   0,   157, 29,  26,  66,  1,  225, 0,   0,   0,   133,
      21,  41,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
      0,   0,   0,   0,   0,   128, 191, 126, 47,
  };
  uint8_t encoded_payload_[99] = {
      1, 202, 0, 0, 0, 103, 208, 30,  66,  1, 203, 0, 0, 0, 117, 24, 18,  66,
      1, 208, 0, 0, 0, 200, 173, 20,  66,  1, 212, 0, 0, 0, 137, 68, 27,  66,
      1, 217, 0, 0, 0, 243, 51,  40,  66,  1, 218, 0, 0, 0, 225, 58, 23,  66,
      1, 220, 0, 0, 0, 132, 221, 22,  66,  1, 222, 0, 0, 0, 157, 29, 26,  66,
      1, 225, 0, 0, 0, 133, 21,  41,  66,  0, 0,   0, 0, 0, 0,   0,  128, 191,
      0, 0,   0, 0, 0, 0,   0,   128, 191,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgTrackingStateDepB, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[99];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], sizeof(buf),
                                                &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDepB, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[99];

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[99];

  for (uint8_t i = 0; i < 99; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], i, nullptr,
                                                  &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgTrackingStateDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_tracking_state_dep_b_t t{};
      return sbp_msg_tracking_state_dep_b_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_tracking_state_dep_b_t t{};
      t.n_states = 1;
      return sbp_msg_tracking_state_dep_b_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(&info.encoded_payload[0], i,
                                                  nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_send(&state, info.sender_id,
                                              &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.n_states, greater.n_states);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].cn0, greater.states[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.code, greater.states[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.reserved,
                        greater.states[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.sat, greater.states[0].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].state, greater.states[0].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].cn0, greater.states[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.code, greater.states[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.reserved,
                        greater.states[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.sat, greater.states[1].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].state, greater.states[1].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].cn0, greater.states[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.code, greater.states[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.reserved,
                        greater.states[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.sat, greater.states[2].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].state, greater.states[2].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].cn0, greater.states[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.code, greater.states[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.reserved,
                        greater.states[3].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.sat, greater.states[3].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].state, greater.states[3].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].cn0, greater.states[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.code, greater.states[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.reserved,
                        greater.states[4].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.sat, greater.states[4].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].state, greater.states[4].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].cn0, greater.states[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.code, greater.states[5].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.reserved,
                        greater.states[5].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.sat, greater.states[5].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].state, greater.states[5].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].cn0, greater.states[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.code, greater.states[6].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.reserved,
                        greater.states[6].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.sat, greater.states[6].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].state, greater.states[6].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].cn0, greater.states[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.code, greater.states[7].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.reserved,
                        greater.states[7].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.sat, greater.states[7].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].state, greater.states[7].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].cn0, greater.states[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.code, greater.states[8].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.reserved,
                        greater.states[8].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.sat, greater.states[8].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].state, greater.states[8].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].cn0, greater.states[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.code, greater.states[9].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.reserved,
                        greater.states[9].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.sat, greater.states[9].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].state, greater.states[9].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].cn0, greater.states[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.code,
                        greater.states[10].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.reserved,
                        greater.states[10].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.sat, greater.states[10].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].state, greater.states[10].state);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::id,
  // SbpMsgTrackingStateDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::name,
               "MSG_TRACKING_STATE_DEP_B");
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_tracking_state_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(info.test_msg,
                                                                 &msg2);
  EXPECT_EQ(msg2.tracking_state_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[99];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 99);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 99), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 99);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDepB,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingState5,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDepB,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace
