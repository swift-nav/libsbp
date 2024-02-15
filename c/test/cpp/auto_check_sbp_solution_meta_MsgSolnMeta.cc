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
// spec/tests/yaml/swiftnav/sbp/soln_meta/test_MsgSolnMeta.yaml by generate.py.
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
class Testauto_check_sbp_solution_meta_MsgSolnMeta0 : public ::testing::Test {
 public:
  Testauto_check_sbp_solution_meta_MsgSolnMeta0() {
    assign(test_msg_.age_corrections, 21256);
    assign(test_msg_.age_gnss, 3573765977);
    assign(test_msg_.hdop, 41156);
    assign(test_msg_.n_sol_in, 119);
    assign(test_msg_.pdop, 11642);

    assign(test_msg_.sol_in[0].flags, 109);
    assign(test_msg_.sol_in[0].sensor_type, 95);

    assign(test_msg_.sol_in[1].flags, 131);
    assign(test_msg_.sol_in[1].sensor_type, 86);

    assign(test_msg_.sol_in[2].flags, 70);
    assign(test_msg_.sol_in[2].sensor_type, 71);

    assign(test_msg_.sol_in[3].flags, 73);
    assign(test_msg_.sol_in[3].sensor_type, 84);

    assign(test_msg_.sol_in[4].flags, 26);
    assign(test_msg_.sol_in[4].sensor_type, 131);

    assign(test_msg_.sol_in[5].flags, 247);
    assign(test_msg_.sol_in[5].sensor_type, 82);

    assign(test_msg_.sol_in[6].flags, 97);
    assign(test_msg_.sol_in[6].sensor_type, 140);

    assign(test_msg_.sol_in[7].flags, 110);
    assign(test_msg_.sol_in[7].sensor_type, 115);

    assign(test_msg_.sol_in[8].flags, 253);
    assign(test_msg_.sol_in[8].sensor_type, 118);

    assign(test_msg_.sol_in[9].flags, 122);
    assign(test_msg_.sol_in[9].sensor_type, 2);

    assign(test_msg_.sol_in[10].flags, 148);
    assign(test_msg_.sol_in[10].sensor_type, 186);

    assign(test_msg_.sol_in[11].flags, 148);
    assign(test_msg_.sol_in[11].sensor_type, 122);

    assign(test_msg_.sol_in[12].flags, 231);
    assign(test_msg_.sol_in[12].sensor_type, 180);

    assign(test_msg_.sol_in[13].flags, 46);
    assign(test_msg_.sol_in[13].sensor_type, 68);

    assign(test_msg_.sol_in[14].flags, 102);
    assign(test_msg_.sol_in[14].sensor_type, 190);

    assign(test_msg_.sol_in[15].flags, 48);
    assign(test_msg_.sol_in[15].sensor_type, 243);

    assign(test_msg_.sol_in[16].flags, 15);
    assign(test_msg_.sol_in[16].sensor_type, 192);

    assign(test_msg_.sol_in[17].flags, 89);
    assign(test_msg_.sol_in[17].sensor_type, 208);

    assign(test_msg_.sol_in[18].flags, 10);
    assign(test_msg_.sol_in[18].sensor_type, 56);

    assign(test_msg_.sol_in[19].flags, 2);
    assign(test_msg_.sol_in[19].sensor_type, 245);

    assign(test_msg_.sol_in[20].flags, 201);
    assign(test_msg_.sol_in[20].sensor_type, 254);

    assign(test_msg_.sol_in[21].flags, 32);
    assign(test_msg_.sol_in[21].sensor_type, 120);

    assign(test_msg_.sol_in[22].flags, 2);
    assign(test_msg_.sol_in[22].sensor_type, 126);

    assign(test_msg_.sol_in[23].flags, 161);
    assign(test_msg_.sol_in[23].sensor_type, 83);

    assign(test_msg_.sol_in[24].flags, 123);
    assign(test_msg_.sol_in[24].sensor_type, 238);

    assign(test_msg_.sol_in[25].flags, 230);
    assign(test_msg_.sol_in[25].sensor_type, 102);

    assign(test_msg_.sol_in[26].flags, 190);
    assign(test_msg_.sol_in[26].sensor_type, 76);

    assign(test_msg_.sol_in[27].flags, 182);
    assign(test_msg_.sol_in[27].sensor_type, 225);

    assign(test_msg_.sol_in[28].flags, 228);
    assign(test_msg_.sol_in[28].sensor_type, 207);

    assign(test_msg_.sol_in[29].flags, 218);
    assign(test_msg_.sol_in[29].sensor_type, 7);

    assign(test_msg_.sol_in[30].flags, 89);
    assign(test_msg_.sol_in[30].sensor_type, 117);

    assign(test_msg_.sol_in[31].flags, 191);
    assign(test_msg_.sol_in[31].sensor_type, 29);

    assign(test_msg_.sol_in[32].flags, 248);
    assign(test_msg_.sol_in[32].sensor_type, 56);

    assign(test_msg_.sol_in[33].flags, 255);
    assign(test_msg_.sol_in[33].sensor_type, 185);

    assign(test_msg_.sol_in[34].flags, 18);
    assign(test_msg_.sol_in[34].sensor_type, 46);

    assign(test_msg_.sol_in[35].flags, 142);
    assign(test_msg_.sol_in[35].sensor_type, 72);

    assign(test_msg_.sol_in[36].flags, 113);
    assign(test_msg_.sol_in[36].sensor_type, 82);

    assign(test_msg_.sol_in[37].flags, 4);
    assign(test_msg_.sol_in[37].sensor_type, 26);

    assign(test_msg_.sol_in[38].flags, 254);
    assign(test_msg_.sol_in[38].sensor_type, 172);

    assign(test_msg_.sol_in[39].flags, 136);
    assign(test_msg_.sol_in[39].sensor_type, 178);

    assign(test_msg_.sol_in[40].flags, 115);
    assign(test_msg_.sol_in[40].sensor_type, 113);

    assign(test_msg_.sol_in[41].flags, 193);
    assign(test_msg_.sol_in[41].sensor_type, 58);

    assign(test_msg_.sol_in[42].flags, 227);
    assign(test_msg_.sol_in[42].sensor_type, 89);

    assign(test_msg_.sol_in[43].flags, 246);
    assign(test_msg_.sol_in[43].sensor_type, 182);

    assign(test_msg_.sol_in[44].flags, 77);
    assign(test_msg_.sol_in[44].sensor_type, 76);

    assign(test_msg_.sol_in[45].flags, 245);
    assign(test_msg_.sol_in[45].sensor_type, 108);

    assign(test_msg_.sol_in[46].flags, 31);
    assign(test_msg_.sol_in[46].sensor_type, 41);

    assign(test_msg_.sol_in[47].flags, 124);
    assign(test_msg_.sol_in[47].sensor_type, 70);

    assign(test_msg_.sol_in[48].flags, 145);
    assign(test_msg_.sol_in[48].sensor_type, 249);

    assign(test_msg_.sol_in[49].flags, 78);
    assign(test_msg_.sol_in[49].sensor_type, 15);

    assign(test_msg_.sol_in[50].flags, 38);
    assign(test_msg_.sol_in[50].sensor_type, 228);

    assign(test_msg_.sol_in[51].flags, 129);
    assign(test_msg_.sol_in[51].sensor_type, 241);

    assign(test_msg_.sol_in[52].flags, 176);
    assign(test_msg_.sol_in[52].sensor_type, 8);

    assign(test_msg_.sol_in[53].flags, 72);
    assign(test_msg_.sol_in[53].sensor_type, 251);

    assign(test_msg_.sol_in[54].flags, 80);
    assign(test_msg_.sol_in[54].sensor_type, 248);

    assign(test_msg_.sol_in[55].flags, 244);
    assign(test_msg_.sol_in[55].sensor_type, 115);

    assign(test_msg_.sol_in[56].flags, 145);
    assign(test_msg_.sol_in[56].sensor_type, 231);

    assign(test_msg_.sol_in[57].flags, 190);
    assign(test_msg_.sol_in[57].sensor_type, 191);

    assign(test_msg_.sol_in[58].flags, 168);
    assign(test_msg_.sol_in[58].sensor_type, 178);

    assign(test_msg_.sol_in[59].flags, 233);
    assign(test_msg_.sol_in[59].sensor_type, 89);

    assign(test_msg_.sol_in[60].flags, 176);
    assign(test_msg_.sol_in[60].sensor_type, 69);

    assign(test_msg_.sol_in[61].flags, 140);
    assign(test_msg_.sol_in[61].sensor_type, 174);

    assign(test_msg_.sol_in[62].flags, 141);
    assign(test_msg_.sol_in[62].sensor_type, 182);

    assign(test_msg_.sol_in[63].flags, 82);
    assign(test_msg_.sol_in[63].sensor_type, 81);

    assign(test_msg_.sol_in[64].flags, 79);
    assign(test_msg_.sol_in[64].sensor_type, 92);

    assign(test_msg_.sol_in[65].flags, 223);
    assign(test_msg_.sol_in[65].sensor_type, 101);

    assign(test_msg_.sol_in[66].flags, 64);
    assign(test_msg_.sol_in[66].sensor_type, 100);

    assign(test_msg_.sol_in[67].flags, 215);
    assign(test_msg_.sol_in[67].sensor_type, 184);

    assign(test_msg_.sol_in[68].flags, 37);
    assign(test_msg_.sol_in[68].sensor_type, 124);

    assign(test_msg_.sol_in[69].flags, 227);
    assign(test_msg_.sol_in[69].sensor_type, 21);

    assign(test_msg_.sol_in[70].flags, 102);
    assign(test_msg_.sol_in[70].sensor_type, 135);

    assign(test_msg_.sol_in[71].flags, 36);
    assign(test_msg_.sol_in[71].sensor_type, 72);

    assign(test_msg_.sol_in[72].flags, 56);
    assign(test_msg_.sol_in[72].sensor_type, 219);

    assign(test_msg_.sol_in[73].flags, 90);
    assign(test_msg_.sol_in[73].sensor_type, 146);

    assign(test_msg_.sol_in[74].flags, 104);
    assign(test_msg_.sol_in[74].sensor_type, 219);

    assign(test_msg_.sol_in[75].flags, 102);
    assign(test_msg_.sol_in[75].sensor_type, 227);

    assign(test_msg_.sol_in[76].flags, 12);
    assign(test_msg_.sol_in[76].sensor_type, 83);

    assign(test_msg_.sol_in[77].flags, 122);
    assign(test_msg_.sol_in[77].sensor_type, 41);

    assign(test_msg_.sol_in[78].flags, 94);
    assign(test_msg_.sol_in[78].sensor_type, 173);

    assign(test_msg_.sol_in[79].flags, 174);
    assign(test_msg_.sol_in[79].sensor_type, 1);

    assign(test_msg_.sol_in[80].flags, 130);
    assign(test_msg_.sol_in[80].sensor_type, 134);

    assign(test_msg_.sol_in[81].flags, 237);
    assign(test_msg_.sol_in[81].sensor_type, 104);

    assign(test_msg_.sol_in[82].flags, 249);
    assign(test_msg_.sol_in[82].sensor_type, 116);

    assign(test_msg_.sol_in[83].flags, 230);
    assign(test_msg_.sol_in[83].sensor_type, 107);

    assign(test_msg_.sol_in[84].flags, 123);
    assign(test_msg_.sol_in[84].sensor_type, 130);

    assign(test_msg_.sol_in[85].flags, 162);
    assign(test_msg_.sol_in[85].sensor_type, 25);

    assign(test_msg_.sol_in[86].flags, 223);
    assign(test_msg_.sol_in[86].sensor_type, 57);

    assign(test_msg_.sol_in[87].flags, 174);
    assign(test_msg_.sol_in[87].sensor_type, 193);

    assign(test_msg_.sol_in[88].flags, 193);
    assign(test_msg_.sol_in[88].sensor_type, 146);

    assign(test_msg_.sol_in[89].flags, 44);
    assign(test_msg_.sol_in[89].sensor_type, 239);

    assign(test_msg_.sol_in[90].flags, 197);
    assign(test_msg_.sol_in[90].sensor_type, 246);

    assign(test_msg_.sol_in[91].flags, 80);
    assign(test_msg_.sol_in[91].sensor_type, 214);

    assign(test_msg_.sol_in[92].flags, 100);
    assign(test_msg_.sol_in[92].sensor_type, 83);

    assign(test_msg_.sol_in[93].flags, 72);
    assign(test_msg_.sol_in[93].sensor_type, 66);

    assign(test_msg_.sol_in[94].flags, 137);
    assign(test_msg_.sol_in[94].sensor_type, 133);

    assign(test_msg_.sol_in[95].flags, 82);
    assign(test_msg_.sol_in[95].sensor_type, 140);

    assign(test_msg_.sol_in[96].flags, 2);
    assign(test_msg_.sol_in[96].sensor_type, 2);

    assign(test_msg_.sol_in[97].flags, 9);
    assign(test_msg_.sol_in[97].sensor_type, 96);

    assign(test_msg_.sol_in[98].flags, 158);
    assign(test_msg_.sol_in[98].sensor_type, 96);

    assign(test_msg_.sol_in[99].flags, 97);
    assign(test_msg_.sol_in[99].sensor_type, 134);

    assign(test_msg_.sol_in[100].flags, 129);
    assign(test_msg_.sol_in[100].sensor_type, 43);

    assign(test_msg_.sol_in[101].flags, 25);
    assign(test_msg_.sol_in[101].sensor_type, 141);

    assign(test_msg_.sol_in[102].flags, 200);
    assign(test_msg_.sol_in[102].sensor_type, 183);

    assign(test_msg_.sol_in[103].flags, 57);
    assign(test_msg_.sol_in[103].sensor_type, 214);

    assign(test_msg_.sol_in[104].flags, 103);
    assign(test_msg_.sol_in[104].sensor_type, 248);

    assign(test_msg_.sol_in[105].flags, 65);
    assign(test_msg_.sol_in[105].sensor_type, 222);

    assign(test_msg_.sol_in[106].flags, 15);
    assign(test_msg_.sol_in[106].sensor_type, 195);

    assign(test_msg_.sol_in[107].flags, 21);
    assign(test_msg_.sol_in[107].sensor_type, 244);

    assign(test_msg_.sol_in[108].flags, 46);
    assign(test_msg_.sol_in[108].sensor_type, 180);

    assign(test_msg_.sol_in[109].flags, 130);
    assign(test_msg_.sol_in[109].sensor_type, 140);

    assign(test_msg_.sol_in[110].flags, 17);
    assign(test_msg_.sol_in[110].sensor_type, 36);

    assign(test_msg_.sol_in[111].flags, 209);
    assign(test_msg_.sol_in[111].sensor_type, 194);

    assign(test_msg_.sol_in[112].flags, 254);
    assign(test_msg_.sol_in[112].sensor_type, 65);

    assign(test_msg_.sol_in[113].flags, 103);
    assign(test_msg_.sol_in[113].sensor_type, 115);

    assign(test_msg_.sol_in[114].flags, 129);
    assign(test_msg_.sol_in[114].sensor_type, 152);

    assign(test_msg_.sol_in[115].flags, 235);
    assign(test_msg_.sol_in[115].sensor_type, 234);

    assign(test_msg_.sol_in[116].flags, 234);
    assign(test_msg_.sol_in[116].sensor_type, 194);

    assign(test_msg_.sol_in[117].flags, 201);
    assign(test_msg_.sol_in[117].sensor_type, 170);

    assign(test_msg_.sol_in[118].flags, 154);
    assign(test_msg_.sol_in[118].sensor_type, 210);
    assign(test_msg_.tow, 3628191792);
    assign(test_msg_.vdop, 58512);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_soln_meta_t> {
    using sbp::MessageHandler<sbp_msg_soln_meta_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_soln_meta_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_soln_meta_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgSolnMeta, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_soln_meta_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgSolnMeta);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->soln_meta, sizeof(msg->soln_meta));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_soln_meta_t test_msg;
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
    memcpy(&info.test_msg_wrapped.soln_meta, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgSolnMeta);
    info.sender_id = 15360;
    info.preamble = 0x55;
    info.crc = 0xf796;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 254;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_soln_meta_t &lesser,
                        const sbp_msg_soln_meta_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_soln_meta_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_soln_meta_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_soln_meta_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_soln_meta_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_soln_meta_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_soln_meta_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgSolnMeta, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgSolnMeta, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgSolnMeta, &wrapped_lesser, &wrapped_greater), 0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgSolnMeta, &wrapped_greater, &wrapped_lesser), 0);

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
  sbp_msg_soln_meta_t test_msg_{};
  uint8_t encoded_frame_[254 + 8] = {
      85,  14,  255, 0,   60,  254, 48,  208, 65,  216, 122, 45,  196, 160, 144,
      228, 8,   83,  89,  87,  3,   213, 95,  109, 86,  131, 71,  70,  84,  73,
      131, 26,  82,  247, 140, 97,  115, 110, 118, 253, 2,   122, 186, 148, 122,
      148, 180, 231, 68,  46,  190, 102, 243, 48,  192, 15,  208, 89,  56,  10,
      245, 2,   254, 201, 120, 32,  126, 2,   83,  161, 238, 123, 102, 230, 76,
      190, 225, 182, 207, 228, 7,   218, 117, 89,  29,  191, 56,  248, 185, 255,
      46,  18,  72,  142, 82,  113, 26,  4,   172, 254, 178, 136, 113, 115, 58,
      193, 89,  227, 182, 246, 76,  77,  108, 245, 41,  31,  70,  124, 249, 145,
      15,  78,  228, 38,  241, 129, 8,   176, 251, 72,  248, 80,  115, 244, 231,
      145, 191, 190, 178, 168, 89,  233, 69,  176, 174, 140, 182, 141, 81,  82,
      92,  79,  101, 223, 100, 64,  184, 215, 124, 37,  21,  227, 135, 102, 72,
      36,  219, 56,  146, 90,  219, 104, 227, 102, 83,  12,  41,  122, 173, 94,
      1,   174, 134, 130, 104, 237, 116, 249, 107, 230, 130, 123, 25,  162, 57,
      223, 193, 174, 146, 193, 239, 44,  246, 197, 214, 80,  83,  100, 66,  72,
      133, 137, 140, 82,  2,   2,   96,  9,   96,  158, 134, 97,  43,  129, 141,
      25,  183, 200, 214, 57,  248, 103, 222, 65,  195, 15,  244, 21,  180, 46,
      140, 130, 36,  17,  194, 209, 65,  254, 115, 103, 152, 129, 234, 235, 194,
      234, 170, 201, 210, 154, 150, 247,
  };
  uint8_t encoded_payload_[254] = {
      48,  208, 65,  216, 122, 45,  196, 160, 144, 228, 8,   83,  89,  87,  3,
      213, 95,  109, 86,  131, 71,  70,  84,  73,  131, 26,  82,  247, 140, 97,
      115, 110, 118, 253, 2,   122, 186, 148, 122, 148, 180, 231, 68,  46,  190,
      102, 243, 48,  192, 15,  208, 89,  56,  10,  245, 2,   254, 201, 120, 32,
      126, 2,   83,  161, 238, 123, 102, 230, 76,  190, 225, 182, 207, 228, 7,
      218, 117, 89,  29,  191, 56,  248, 185, 255, 46,  18,  72,  142, 82,  113,
      26,  4,   172, 254, 178, 136, 113, 115, 58,  193, 89,  227, 182, 246, 76,
      77,  108, 245, 41,  31,  70,  124, 249, 145, 15,  78,  228, 38,  241, 129,
      8,   176, 251, 72,  248, 80,  115, 244, 231, 145, 191, 190, 178, 168, 89,
      233, 69,  176, 174, 140, 182, 141, 81,  82,  92,  79,  101, 223, 100, 64,
      184, 215, 124, 37,  21,  227, 135, 102, 72,  36,  219, 56,  146, 90,  219,
      104, 227, 102, 83,  12,  41,  122, 173, 94,  1,   174, 134, 130, 104, 237,
      116, 249, 107, 230, 130, 123, 25,  162, 57,  223, 193, 174, 146, 193, 239,
      44,  246, 197, 214, 80,  83,  100, 66,  72,  133, 137, 140, 82,  2,   2,
      96,  9,   96,  158, 134, 97,  43,  129, 141, 25,  183, 200, 214, 57,  248,
      103, 222, 65,  195, 15,  244, 21,  180, 46,  140, 130, 36,  17,  194, 209,
      65,  254, 115, 103, 152, 129, 234, 235, 194, 234, 170, 201, 210, 154,
  };
};

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_soln_meta_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgSolnMeta, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[254];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_soln_meta_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 254);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgSolnMeta,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 254);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[254];

  EXPECT_EQ(
      sbp_msg_soln_meta_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);
}
TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[254];

  for (uint8_t i = 0; i < 254; i++) {
    EXPECT_EQ(sbp_msg_soln_meta_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_soln_meta_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_soln_meta_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 254);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgSolnMeta, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 254);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_soln_meta_t msg{};

  EXPECT_EQ(sbp_msg_soln_meta_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_soln_meta_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_soln_meta_t t{};
      return sbp_msg_soln_meta_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_soln_meta_t t{};
      t.n_sol_in = 1;
      return sbp_msg_soln_meta_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_soln_meta_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0,
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

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, SlowRead) {
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

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, BadCRC) {
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

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_soln_meta_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSolnMeta, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgSolnMeta, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSolnMeta, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.age_corrections, greater.age_corrections);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.age_gnss, greater.age_gnss);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.hdop, greater.hdop);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sol_in, greater.n_sol_in);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.pdop, greater.pdop);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[0].flags, greater.sol_in[0].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[0].sensor_type,
                        greater.sol_in[0].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[1].flags, greater.sol_in[1].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[1].sensor_type,
                        greater.sol_in[1].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[2].flags, greater.sol_in[2].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[2].sensor_type,
                        greater.sol_in[2].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[3].flags, greater.sol_in[3].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[3].sensor_type,
                        greater.sol_in[3].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[4].flags, greater.sol_in[4].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[4].sensor_type,
                        greater.sol_in[4].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[5].flags, greater.sol_in[5].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[5].sensor_type,
                        greater.sol_in[5].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[6].flags, greater.sol_in[6].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[6].sensor_type,
                        greater.sol_in[6].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[7].flags, greater.sol_in[7].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[7].sensor_type,
                        greater.sol_in[7].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[8].flags, greater.sol_in[8].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[8].sensor_type,
                        greater.sol_in[8].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[9].flags, greater.sol_in[9].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[9].sensor_type,
                        greater.sol_in[9].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[10].flags, greater.sol_in[10].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[10].sensor_type,
                        greater.sol_in[10].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[11].flags, greater.sol_in[11].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[11].sensor_type,
                        greater.sol_in[11].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[12].flags, greater.sol_in[12].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[12].sensor_type,
                        greater.sol_in[12].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[13].flags, greater.sol_in[13].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[13].sensor_type,
                        greater.sol_in[13].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[14].flags, greater.sol_in[14].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[14].sensor_type,
                        greater.sol_in[14].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[15].flags, greater.sol_in[15].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[15].sensor_type,
                        greater.sol_in[15].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[16].flags, greater.sol_in[16].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[16].sensor_type,
                        greater.sol_in[16].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[17].flags, greater.sol_in[17].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[17].sensor_type,
                        greater.sol_in[17].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[18].flags, greater.sol_in[18].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[18].sensor_type,
                        greater.sol_in[18].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[19].flags, greater.sol_in[19].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[19].sensor_type,
                        greater.sol_in[19].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[20].flags, greater.sol_in[20].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[20].sensor_type,
                        greater.sol_in[20].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[21].flags, greater.sol_in[21].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[21].sensor_type,
                        greater.sol_in[21].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[22].flags, greater.sol_in[22].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[22].sensor_type,
                        greater.sol_in[22].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[23].flags, greater.sol_in[23].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[23].sensor_type,
                        greater.sol_in[23].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[24].flags, greater.sol_in[24].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[24].sensor_type,
                        greater.sol_in[24].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[25].flags, greater.sol_in[25].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[25].sensor_type,
                        greater.sol_in[25].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[26].flags, greater.sol_in[26].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[26].sensor_type,
                        greater.sol_in[26].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[27].flags, greater.sol_in[27].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[27].sensor_type,
                        greater.sol_in[27].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[28].flags, greater.sol_in[28].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[28].sensor_type,
                        greater.sol_in[28].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[29].flags, greater.sol_in[29].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[29].sensor_type,
                        greater.sol_in[29].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[30].flags, greater.sol_in[30].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[30].sensor_type,
                        greater.sol_in[30].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[31].flags, greater.sol_in[31].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[31].sensor_type,
                        greater.sol_in[31].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[32].flags, greater.sol_in[32].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[32].sensor_type,
                        greater.sol_in[32].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[33].flags, greater.sol_in[33].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[33].sensor_type,
                        greater.sol_in[33].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[34].flags, greater.sol_in[34].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[34].sensor_type,
                        greater.sol_in[34].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[35].flags, greater.sol_in[35].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[35].sensor_type,
                        greater.sol_in[35].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[36].flags, greater.sol_in[36].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[36].sensor_type,
                        greater.sol_in[36].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[37].flags, greater.sol_in[37].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[37].sensor_type,
                        greater.sol_in[37].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[38].flags, greater.sol_in[38].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[38].sensor_type,
                        greater.sol_in[38].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[39].flags, greater.sol_in[39].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[39].sensor_type,
                        greater.sol_in[39].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[40].flags, greater.sol_in[40].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[40].sensor_type,
                        greater.sol_in[40].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[41].flags, greater.sol_in[41].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[41].sensor_type,
                        greater.sol_in[41].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[42].flags, greater.sol_in[42].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[42].sensor_type,
                        greater.sol_in[42].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[43].flags, greater.sol_in[43].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[43].sensor_type,
                        greater.sol_in[43].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[44].flags, greater.sol_in[44].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[44].sensor_type,
                        greater.sol_in[44].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[45].flags, greater.sol_in[45].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[45].sensor_type,
                        greater.sol_in[45].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[46].flags, greater.sol_in[46].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[46].sensor_type,
                        greater.sol_in[46].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[47].flags, greater.sol_in[47].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[47].sensor_type,
                        greater.sol_in[47].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[48].flags, greater.sol_in[48].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[48].sensor_type,
                        greater.sol_in[48].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[49].flags, greater.sol_in[49].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[49].sensor_type,
                        greater.sol_in[49].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[50].flags, greater.sol_in[50].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[50].sensor_type,
                        greater.sol_in[50].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[51].flags, greater.sol_in[51].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[51].sensor_type,
                        greater.sol_in[51].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[52].flags, greater.sol_in[52].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[52].sensor_type,
                        greater.sol_in[52].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[53].flags, greater.sol_in[53].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[53].sensor_type,
                        greater.sol_in[53].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[54].flags, greater.sol_in[54].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[54].sensor_type,
                        greater.sol_in[54].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[55].flags, greater.sol_in[55].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[55].sensor_type,
                        greater.sol_in[55].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[56].flags, greater.sol_in[56].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[56].sensor_type,
                        greater.sol_in[56].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[57].flags, greater.sol_in[57].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[57].sensor_type,
                        greater.sol_in[57].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[58].flags, greater.sol_in[58].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[58].sensor_type,
                        greater.sol_in[58].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[59].flags, greater.sol_in[59].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[59].sensor_type,
                        greater.sol_in[59].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[60].flags, greater.sol_in[60].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[60].sensor_type,
                        greater.sol_in[60].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[61].flags, greater.sol_in[61].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[61].sensor_type,
                        greater.sol_in[61].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[62].flags, greater.sol_in[62].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[62].sensor_type,
                        greater.sol_in[62].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[63].flags, greater.sol_in[63].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[63].sensor_type,
                        greater.sol_in[63].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[64].flags, greater.sol_in[64].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[64].sensor_type,
                        greater.sol_in[64].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[65].flags, greater.sol_in[65].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[65].sensor_type,
                        greater.sol_in[65].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[66].flags, greater.sol_in[66].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[66].sensor_type,
                        greater.sol_in[66].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[67].flags, greater.sol_in[67].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[67].sensor_type,
                        greater.sol_in[67].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[68].flags, greater.sol_in[68].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[68].sensor_type,
                        greater.sol_in[68].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[69].flags, greater.sol_in[69].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[69].sensor_type,
                        greater.sol_in[69].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[70].flags, greater.sol_in[70].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[70].sensor_type,
                        greater.sol_in[70].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[71].flags, greater.sol_in[71].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[71].sensor_type,
                        greater.sol_in[71].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[72].flags, greater.sol_in[72].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[72].sensor_type,
                        greater.sol_in[72].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[73].flags, greater.sol_in[73].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[73].sensor_type,
                        greater.sol_in[73].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[74].flags, greater.sol_in[74].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[74].sensor_type,
                        greater.sol_in[74].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[75].flags, greater.sol_in[75].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[75].sensor_type,
                        greater.sol_in[75].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[76].flags, greater.sol_in[76].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[76].sensor_type,
                        greater.sol_in[76].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[77].flags, greater.sol_in[77].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[77].sensor_type,
                        greater.sol_in[77].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[78].flags, greater.sol_in[78].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[78].sensor_type,
                        greater.sol_in[78].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[79].flags, greater.sol_in[79].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[79].sensor_type,
                        greater.sol_in[79].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[80].flags, greater.sol_in[80].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[80].sensor_type,
                        greater.sol_in[80].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[81].flags, greater.sol_in[81].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[81].sensor_type,
                        greater.sol_in[81].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[82].flags, greater.sol_in[82].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[82].sensor_type,
                        greater.sol_in[82].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[83].flags, greater.sol_in[83].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[83].sensor_type,
                        greater.sol_in[83].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[84].flags, greater.sol_in[84].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[84].sensor_type,
                        greater.sol_in[84].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[85].flags, greater.sol_in[85].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[85].sensor_type,
                        greater.sol_in[85].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[86].flags, greater.sol_in[86].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[86].sensor_type,
                        greater.sol_in[86].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[87].flags, greater.sol_in[87].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[87].sensor_type,
                        greater.sol_in[87].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[88].flags, greater.sol_in[88].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[88].sensor_type,
                        greater.sol_in[88].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[89].flags, greater.sol_in[89].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[89].sensor_type,
                        greater.sol_in[89].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[90].flags, greater.sol_in[90].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[90].sensor_type,
                        greater.sol_in[90].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[91].flags, greater.sol_in[91].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[91].sensor_type,
                        greater.sol_in[91].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[92].flags, greater.sol_in[92].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[92].sensor_type,
                        greater.sol_in[92].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[93].flags, greater.sol_in[93].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[93].sensor_type,
                        greater.sol_in[93].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[94].flags, greater.sol_in[94].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[94].sensor_type,
                        greater.sol_in[94].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[95].flags, greater.sol_in[95].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[95].sensor_type,
                        greater.sol_in[95].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[96].flags, greater.sol_in[96].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[96].sensor_type,
                        greater.sol_in[96].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[97].flags, greater.sol_in[97].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[97].sensor_type,
                        greater.sol_in[97].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[98].flags, greater.sol_in[98].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[98].sensor_type,
                        greater.sol_in[98].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[99].flags, greater.sol_in[99].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[99].sensor_type,
                        greater.sol_in[99].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[100].flags, greater.sol_in[100].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[100].sensor_type,
                        greater.sol_in[100].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[101].flags, greater.sol_in[101].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[101].sensor_type,
                        greater.sol_in[101].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[102].flags, greater.sol_in[102].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[102].sensor_type,
                        greater.sol_in[102].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[103].flags, greater.sol_in[103].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[103].sensor_type,
                        greater.sol_in[103].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[104].flags, greater.sol_in[104].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[104].sensor_type,
                        greater.sol_in[104].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[105].flags, greater.sol_in[105].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[105].sensor_type,
                        greater.sol_in[105].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[106].flags, greater.sol_in[106].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[106].sensor_type,
                        greater.sol_in[106].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[107].flags, greater.sol_in[107].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[107].sensor_type,
                        greater.sol_in[107].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[108].flags, greater.sol_in[108].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[108].sensor_type,
                        greater.sol_in[108].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[109].flags, greater.sol_in[109].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[109].sensor_type,
                        greater.sol_in[109].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[110].flags, greater.sol_in[110].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[110].sensor_type,
                        greater.sol_in[110].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[111].flags, greater.sol_in[111].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[111].sensor_type,
                        greater.sol_in[111].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[112].flags, greater.sol_in[112].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[112].sensor_type,
                        greater.sol_in[112].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[113].flags, greater.sol_in[113].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[113].sensor_type,
                        greater.sol_in[113].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[114].flags, greater.sol_in[114].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[114].sensor_type,
                        greater.sol_in[114].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[115].flags, greater.sol_in[115].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[115].sensor_type,
                        greater.sol_in[115].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[116].flags, greater.sol_in[116].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[116].sensor_type,
                        greater.sol_in[116].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[117].flags, greater.sol_in[117].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[117].sensor_type,
                        greater.sol_in[117].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[118].flags, greater.sol_in[118].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[118].sensor_type,
                        greater.sol_in[118].sensor_type);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.tow, greater.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_t lesser = info.test_msg;
    sbp_msg_soln_meta_t greater = info.test_msg;
    make_lesser_greater(lesser.vdop, greater.vdop);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_soln_meta_t>::id, SbpMsgSolnMeta);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_soln_meta_t>::name, "MSG_SOLN_META");
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_soln_meta_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_soln_meta_t>::get(const_sbp_msg_t);
  sbp_msg_soln_meta_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_soln_meta_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_soln_meta_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.soln_meta, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_soln_meta_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.soln_meta, info.test_msg);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_soln_meta_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_soln_meta_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[254];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_soln_meta_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 254);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_soln_meta_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_soln_meta_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 254);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0,
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

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgSolnMeta, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMeta0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgSolnMeta, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace