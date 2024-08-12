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
// spec/tests/yaml/swiftnav/sbp/soln_meta/test_MsgSolnMetaDepA.yaml by
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
class Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0() {
    assign(test_msg_.age_corrections, 48671);
    assign(test_msg_.alignment_status, 115);
    assign(test_msg_.hdop, 31133);
    assign(test_msg_.last_used_gnss_pos_tow, 610745181);
    assign(test_msg_.last_used_gnss_vel_tow, 782016851);
    assign(test_msg_.n_sats, 238);
    assign(test_msg_.n_sol_in, 118);
    assign(test_msg_.pdop, 57015);

    assign(test_msg_.sol_in[0].flags, 67);
    assign(test_msg_.sol_in[0].sensor_type, 253);

    assign(test_msg_.sol_in[1].flags, 200);
    assign(test_msg_.sol_in[1].sensor_type, 87);

    assign(test_msg_.sol_in[2].flags, 250);
    assign(test_msg_.sol_in[2].sensor_type, 39);

    assign(test_msg_.sol_in[3].flags, 242);
    assign(test_msg_.sol_in[3].sensor_type, 245);

    assign(test_msg_.sol_in[4].flags, 72);
    assign(test_msg_.sol_in[4].sensor_type, 228);

    assign(test_msg_.sol_in[5].flags, 222);
    assign(test_msg_.sol_in[5].sensor_type, 18);

    assign(test_msg_.sol_in[6].flags, 88);
    assign(test_msg_.sol_in[6].sensor_type, 11);

    assign(test_msg_.sol_in[7].flags, 218);
    assign(test_msg_.sol_in[7].sensor_type, 207);

    assign(test_msg_.sol_in[8].flags, 13);
    assign(test_msg_.sol_in[8].sensor_type, 231);

    assign(test_msg_.sol_in[9].flags, 224);
    assign(test_msg_.sol_in[9].sensor_type, 226);

    assign(test_msg_.sol_in[10].flags, 196);
    assign(test_msg_.sol_in[10].sensor_type, 22);

    assign(test_msg_.sol_in[11].flags, 242);
    assign(test_msg_.sol_in[11].sensor_type, 21);

    assign(test_msg_.sol_in[12].flags, 89);
    assign(test_msg_.sol_in[12].sensor_type, 12);

    assign(test_msg_.sol_in[13].flags, 219);
    assign(test_msg_.sol_in[13].sensor_type, 71);

    assign(test_msg_.sol_in[14].flags, 85);
    assign(test_msg_.sol_in[14].sensor_type, 182);

    assign(test_msg_.sol_in[15].flags, 204);
    assign(test_msg_.sol_in[15].sensor_type, 145);

    assign(test_msg_.sol_in[16].flags, 40);
    assign(test_msg_.sol_in[16].sensor_type, 146);

    assign(test_msg_.sol_in[17].flags, 51);
    assign(test_msg_.sol_in[17].sensor_type, 204);

    assign(test_msg_.sol_in[18].flags, 153);
    assign(test_msg_.sol_in[18].sensor_type, 21);

    assign(test_msg_.sol_in[19].flags, 44);
    assign(test_msg_.sol_in[19].sensor_type, 227);

    assign(test_msg_.sol_in[20].flags, 28);
    assign(test_msg_.sol_in[20].sensor_type, 15);

    assign(test_msg_.sol_in[21].flags, 39);
    assign(test_msg_.sol_in[21].sensor_type, 255);

    assign(test_msg_.sol_in[22].flags, 216);
    assign(test_msg_.sol_in[22].sensor_type, 205);

    assign(test_msg_.sol_in[23].flags, 190);
    assign(test_msg_.sol_in[23].sensor_type, 240);

    assign(test_msg_.sol_in[24].flags, 219);
    assign(test_msg_.sol_in[24].sensor_type, 93);

    assign(test_msg_.sol_in[25].flags, 42);
    assign(test_msg_.sol_in[25].sensor_type, 103);

    assign(test_msg_.sol_in[26].flags, 182);
    assign(test_msg_.sol_in[26].sensor_type, 41);

    assign(test_msg_.sol_in[27].flags, 222);
    assign(test_msg_.sol_in[27].sensor_type, 76);

    assign(test_msg_.sol_in[28].flags, 23);
    assign(test_msg_.sol_in[28].sensor_type, 17);

    assign(test_msg_.sol_in[29].flags, 31);
    assign(test_msg_.sol_in[29].sensor_type, 125);

    assign(test_msg_.sol_in[30].flags, 229);
    assign(test_msg_.sol_in[30].sensor_type, 18);

    assign(test_msg_.sol_in[31].flags, 47);
    assign(test_msg_.sol_in[31].sensor_type, 28);

    assign(test_msg_.sol_in[32].flags, 25);
    assign(test_msg_.sol_in[32].sensor_type, 214);

    assign(test_msg_.sol_in[33].flags, 84);
    assign(test_msg_.sol_in[33].sensor_type, 100);

    assign(test_msg_.sol_in[34].flags, 72);
    assign(test_msg_.sol_in[34].sensor_type, 106);

    assign(test_msg_.sol_in[35].flags, 10);
    assign(test_msg_.sol_in[35].sensor_type, 48);

    assign(test_msg_.sol_in[36].flags, 232);
    assign(test_msg_.sol_in[36].sensor_type, 222);

    assign(test_msg_.sol_in[37].flags, 73);
    assign(test_msg_.sol_in[37].sensor_type, 235);

    assign(test_msg_.sol_in[38].flags, 163);
    assign(test_msg_.sol_in[38].sensor_type, 109);

    assign(test_msg_.sol_in[39].flags, 152);
    assign(test_msg_.sol_in[39].sensor_type, 51);

    assign(test_msg_.sol_in[40].flags, 235);
    assign(test_msg_.sol_in[40].sensor_type, 133);

    assign(test_msg_.sol_in[41].flags, 70);
    assign(test_msg_.sol_in[41].sensor_type, 87);

    assign(test_msg_.sol_in[42].flags, 108);
    assign(test_msg_.sol_in[42].sensor_type, 2);

    assign(test_msg_.sol_in[43].flags, 101);
    assign(test_msg_.sol_in[43].sensor_type, 91);

    assign(test_msg_.sol_in[44].flags, 55);
    assign(test_msg_.sol_in[44].sensor_type, 200);

    assign(test_msg_.sol_in[45].flags, 156);
    assign(test_msg_.sol_in[45].sensor_type, 24);

    assign(test_msg_.sol_in[46].flags, 73);
    assign(test_msg_.sol_in[46].sensor_type, 233);

    assign(test_msg_.sol_in[47].flags, 66);
    assign(test_msg_.sol_in[47].sensor_type, 39);

    assign(test_msg_.sol_in[48].flags, 140);
    assign(test_msg_.sol_in[48].sensor_type, 97);

    assign(test_msg_.sol_in[49].flags, 227);
    assign(test_msg_.sol_in[49].sensor_type, 252);

    assign(test_msg_.sol_in[50].flags, 237);
    assign(test_msg_.sol_in[50].sensor_type, 230);

    assign(test_msg_.sol_in[51].flags, 241);
    assign(test_msg_.sol_in[51].sensor_type, 135);

    assign(test_msg_.sol_in[52].flags, 205);
    assign(test_msg_.sol_in[52].sensor_type, 245);

    assign(test_msg_.sol_in[53].flags, 0);
    assign(test_msg_.sol_in[53].sensor_type, 70);

    assign(test_msg_.sol_in[54].flags, 188);
    assign(test_msg_.sol_in[54].sensor_type, 219);

    assign(test_msg_.sol_in[55].flags, 136);
    assign(test_msg_.sol_in[55].sensor_type, 107);

    assign(test_msg_.sol_in[56].flags, 58);
    assign(test_msg_.sol_in[56].sensor_type, 178);

    assign(test_msg_.sol_in[57].flags, 29);
    assign(test_msg_.sol_in[57].sensor_type, 1);

    assign(test_msg_.sol_in[58].flags, 213);
    assign(test_msg_.sol_in[58].sensor_type, 44);

    assign(test_msg_.sol_in[59].flags, 147);
    assign(test_msg_.sol_in[59].sensor_type, 225);

    assign(test_msg_.sol_in[60].flags, 96);
    assign(test_msg_.sol_in[60].sensor_type, 190);

    assign(test_msg_.sol_in[61].flags, 108);
    assign(test_msg_.sol_in[61].sensor_type, 192);

    assign(test_msg_.sol_in[62].flags, 15);
    assign(test_msg_.sol_in[62].sensor_type, 228);

    assign(test_msg_.sol_in[63].flags, 18);
    assign(test_msg_.sol_in[63].sensor_type, 203);

    assign(test_msg_.sol_in[64].flags, 222);
    assign(test_msg_.sol_in[64].sensor_type, 3);

    assign(test_msg_.sol_in[65].flags, 68);
    assign(test_msg_.sol_in[65].sensor_type, 180);

    assign(test_msg_.sol_in[66].flags, 229);
    assign(test_msg_.sol_in[66].sensor_type, 101);

    assign(test_msg_.sol_in[67].flags, 203);
    assign(test_msg_.sol_in[67].sensor_type, 223);

    assign(test_msg_.sol_in[68].flags, 164);
    assign(test_msg_.sol_in[68].sensor_type, 243);

    assign(test_msg_.sol_in[69].flags, 165);
    assign(test_msg_.sol_in[69].sensor_type, 92);

    assign(test_msg_.sol_in[70].flags, 159);
    assign(test_msg_.sol_in[70].sensor_type, 220);

    assign(test_msg_.sol_in[71].flags, 121);
    assign(test_msg_.sol_in[71].sensor_type, 174);

    assign(test_msg_.sol_in[72].flags, 167);
    assign(test_msg_.sol_in[72].sensor_type, 112);

    assign(test_msg_.sol_in[73].flags, 40);
    assign(test_msg_.sol_in[73].sensor_type, 240);

    assign(test_msg_.sol_in[74].flags, 3);
    assign(test_msg_.sol_in[74].sensor_type, 59);

    assign(test_msg_.sol_in[75].flags, 52);
    assign(test_msg_.sol_in[75].sensor_type, 230);

    assign(test_msg_.sol_in[76].flags, 148);
    assign(test_msg_.sol_in[76].sensor_type, 149);

    assign(test_msg_.sol_in[77].flags, 142);
    assign(test_msg_.sol_in[77].sensor_type, 218);

    assign(test_msg_.sol_in[78].flags, 109);
    assign(test_msg_.sol_in[78].sensor_type, 212);

    assign(test_msg_.sol_in[79].flags, 71);
    assign(test_msg_.sol_in[79].sensor_type, 176);

    assign(test_msg_.sol_in[80].flags, 172);
    assign(test_msg_.sol_in[80].sensor_type, 179);

    assign(test_msg_.sol_in[81].flags, 1);
    assign(test_msg_.sol_in[81].sensor_type, 77);

    assign(test_msg_.sol_in[82].flags, 70);
    assign(test_msg_.sol_in[82].sensor_type, 193);

    assign(test_msg_.sol_in[83].flags, 149);
    assign(test_msg_.sol_in[83].sensor_type, 147);

    assign(test_msg_.sol_in[84].flags, 144);
    assign(test_msg_.sol_in[84].sensor_type, 23);

    assign(test_msg_.sol_in[85].flags, 239);
    assign(test_msg_.sol_in[85].sensor_type, 148);

    assign(test_msg_.sol_in[86].flags, 186);
    assign(test_msg_.sol_in[86].sensor_type, 195);

    assign(test_msg_.sol_in[87].flags, 30);
    assign(test_msg_.sol_in[87].sensor_type, 86);

    assign(test_msg_.sol_in[88].flags, 143);
    assign(test_msg_.sol_in[88].sensor_type, 34);

    assign(test_msg_.sol_in[89].flags, 207);
    assign(test_msg_.sol_in[89].sensor_type, 156);

    assign(test_msg_.sol_in[90].flags, 55);
    assign(test_msg_.sol_in[90].sensor_type, 63);

    assign(test_msg_.sol_in[91].flags, 255);
    assign(test_msg_.sol_in[91].sensor_type, 117);

    assign(test_msg_.sol_in[92].flags, 222);
    assign(test_msg_.sol_in[92].sensor_type, 222);

    assign(test_msg_.sol_in[93].flags, 145);
    assign(test_msg_.sol_in[93].sensor_type, 219);

    assign(test_msg_.sol_in[94].flags, 191);
    assign(test_msg_.sol_in[94].sensor_type, 224);

    assign(test_msg_.sol_in[95].flags, 109);
    assign(test_msg_.sol_in[95].sensor_type, 210);

    assign(test_msg_.sol_in[96].flags, 153);
    assign(test_msg_.sol_in[96].sensor_type, 86);

    assign(test_msg_.sol_in[97].flags, 32);
    assign(test_msg_.sol_in[97].sensor_type, 21);

    assign(test_msg_.sol_in[98].flags, 10);
    assign(test_msg_.sol_in[98].sensor_type, 226);

    assign(test_msg_.sol_in[99].flags, 63);
    assign(test_msg_.sol_in[99].sensor_type, 60);

    assign(test_msg_.sol_in[100].flags, 236);
    assign(test_msg_.sol_in[100].sensor_type, 106);

    assign(test_msg_.sol_in[101].flags, 96);
    assign(test_msg_.sol_in[101].sensor_type, 93);

    assign(test_msg_.sol_in[102].flags, 163);
    assign(test_msg_.sol_in[102].sensor_type, 30);

    assign(test_msg_.sol_in[103].flags, 238);
    assign(test_msg_.sol_in[103].sensor_type, 106);

    assign(test_msg_.sol_in[104].flags, 133);
    assign(test_msg_.sol_in[104].sensor_type, 147);

    assign(test_msg_.sol_in[105].flags, 107);
    assign(test_msg_.sol_in[105].sensor_type, 132);

    assign(test_msg_.sol_in[106].flags, 214);
    assign(test_msg_.sol_in[106].sensor_type, 152);

    assign(test_msg_.sol_in[107].flags, 185);
    assign(test_msg_.sol_in[107].sensor_type, 221);

    assign(test_msg_.sol_in[108].flags, 21);
    assign(test_msg_.sol_in[108].sensor_type, 202);

    assign(test_msg_.sol_in[109].flags, 51);
    assign(test_msg_.sol_in[109].sensor_type, 252);

    assign(test_msg_.sol_in[110].flags, 59);
    assign(test_msg_.sol_in[110].sensor_type, 130);

    assign(test_msg_.sol_in[111].flags, 202);
    assign(test_msg_.sol_in[111].sensor_type, 166);

    assign(test_msg_.sol_in[112].flags, 170);
    assign(test_msg_.sol_in[112].sensor_type, 127);

    assign(test_msg_.sol_in[113].flags, 193);
    assign(test_msg_.sol_in[113].sensor_type, 58);

    assign(test_msg_.sol_in[114].flags, 125);
    assign(test_msg_.sol_in[114].sensor_type, 215);

    assign(test_msg_.sol_in[115].flags, 58);
    assign(test_msg_.sol_in[115].sensor_type, 22);

    assign(test_msg_.sol_in[116].flags, 47);
    assign(test_msg_.sol_in[116].sensor_type, 135);

    assign(test_msg_.sol_in[117].flags, 142);
    assign(test_msg_.sol_in[117].sensor_type, 88);
    assign(test_msg_.vdop, 41989);
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
      : public sbp::MessageHandler<sbp_msg_soln_meta_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_soln_meta_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_soln_meta_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_soln_meta_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgSolnMetaDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_soln_meta_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgSolnMetaDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->soln_meta_dep_a,
             sizeof(msg->soln_meta_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_soln_meta_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.soln_meta_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgSolnMetaDepA);
    info.sender_id = 61780;
    info.preamble = 0x55;
    info.crc = 0xd34d;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 254;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_soln_meta_dep_a_t &lesser,
                        const sbp_msg_soln_meta_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_soln_meta_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_soln_meta_dep_a_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_soln_meta_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_soln_meta_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_soln_meta_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_soln_meta_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgSolnMetaDepA, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgSolnMetaDepA, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgSolnMetaDepA, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgSolnMetaDepA, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_soln_meta_dep_a_t test_msg_{};
  uint8_t encoded_frame_[254 + 8] = {
      85,  15,  255, 84,  241, 254, 183, 222, 157, 121, 5,   164, 238, 31,  190,
      115, 93,  59,  103, 36,  83,  161, 156, 46,  253, 67,  87,  200, 39,  250,
      245, 242, 228, 72,  18,  222, 11,  88,  207, 218, 231, 13,  226, 224, 22,
      196, 21,  242, 12,  89,  71,  219, 182, 85,  145, 204, 146, 40,  204, 51,
      21,  153, 227, 44,  15,  28,  255, 39,  205, 216, 240, 190, 93,  219, 103,
      42,  41,  182, 76,  222, 17,  23,  125, 31,  18,  229, 28,  47,  214, 25,
      100, 84,  106, 72,  48,  10,  222, 232, 235, 73,  109, 163, 51,  152, 133,
      235, 87,  70,  2,   108, 91,  101, 200, 55,  24,  156, 233, 73,  39,  66,
      97,  140, 252, 227, 230, 237, 135, 241, 245, 205, 70,  0,   219, 188, 107,
      136, 178, 58,  1,   29,  44,  213, 225, 147, 190, 96,  192, 108, 228, 15,
      203, 18,  3,   222, 180, 68,  101, 229, 223, 203, 243, 164, 92,  165, 220,
      159, 174, 121, 112, 167, 240, 40,  59,  3,   230, 52,  149, 148, 218, 142,
      212, 109, 176, 71,  179, 172, 77,  1,   193, 70,  147, 149, 23,  144, 148,
      239, 195, 186, 86,  30,  34,  143, 156, 207, 63,  55,  117, 255, 222, 222,
      219, 145, 224, 191, 210, 109, 86,  153, 21,  32,  226, 10,  60,  63,  106,
      236, 93,  96,  30,  163, 106, 238, 147, 133, 132, 107, 152, 214, 221, 185,
      202, 21,  252, 51,  130, 59,  166, 202, 127, 170, 58,  193, 215, 125, 22,
      58,  135, 47,  88,  142, 77,  211,
  };
  uint8_t encoded_payload_[254] = {
      183, 222, 157, 121, 5,   164, 238, 31,  190, 115, 93,  59,  103, 36,  83,
      161, 156, 46,  253, 67,  87,  200, 39,  250, 245, 242, 228, 72,  18,  222,
      11,  88,  207, 218, 231, 13,  226, 224, 22,  196, 21,  242, 12,  89,  71,
      219, 182, 85,  145, 204, 146, 40,  204, 51,  21,  153, 227, 44,  15,  28,
      255, 39,  205, 216, 240, 190, 93,  219, 103, 42,  41,  182, 76,  222, 17,
      23,  125, 31,  18,  229, 28,  47,  214, 25,  100, 84,  106, 72,  48,  10,
      222, 232, 235, 73,  109, 163, 51,  152, 133, 235, 87,  70,  2,   108, 91,
      101, 200, 55,  24,  156, 233, 73,  39,  66,  97,  140, 252, 227, 230, 237,
      135, 241, 245, 205, 70,  0,   219, 188, 107, 136, 178, 58,  1,   29,  44,
      213, 225, 147, 190, 96,  192, 108, 228, 15,  203, 18,  3,   222, 180, 68,
      101, 229, 223, 203, 243, 164, 92,  165, 220, 159, 174, 121, 112, 167, 240,
      40,  59,  3,   230, 52,  149, 148, 218, 142, 212, 109, 176, 71,  179, 172,
      77,  1,   193, 70,  147, 149, 23,  144, 148, 239, 195, 186, 86,  30,  34,
      143, 156, 207, 63,  55,  117, 255, 222, 222, 219, 145, 224, 191, 210, 109,
      86,  153, 21,  32,  226, 10,  60,  63,  106, 236, 93,  96,  30,  163, 106,
      238, 147, 133, 132, 107, 152, 214, 221, 185, 202, 21,  252, 51,  130, 59,
      166, 202, 127, 170, 58,  193, 215, 125, 22,  58,  135, 47,  88,  142,
  };
};

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_soln_meta_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgSolnMetaDepA, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[254];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_soln_meta_dep_a_encode(&buf[0], sizeof(buf), &n_written,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 254);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgSolnMetaDepA, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 254);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[254];

  EXPECT_EQ(sbp_msg_soln_meta_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                           &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);
}
TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[254];

  for (uint8_t i = 0; i < 254; i++) {
    EXPECT_EQ(
        sbp_msg_soln_meta_dep_a_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_soln_meta_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_soln_meta_dep_a_decode(&info.encoded_payload[0],
                                           info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 254);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgSolnMetaDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 254);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_soln_meta_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_soln_meta_dep_a_decode(&info.encoded_payload[0],
                                           info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_soln_meta_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_soln_meta_dep_a_t t{};
      return sbp_msg_soln_meta_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_soln_meta_dep_a_t t{};
      t.n_sol_in = 1;
      return sbp_msg_soln_meta_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_soln_meta_dep_a_decode(&info.encoded_payload[0], i,
                                             nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
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

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
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

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0, SlowRead) {
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

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0, BadCRC) {
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

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_soln_meta_dep_a_send(&state, info.sender_id, &info.test_msg,
                                         &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSolnMetaDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgSolnMetaDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSolnMetaDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.age_corrections, greater.age_corrections);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.alignment_status, greater.alignment_status);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.hdop, greater.hdop);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.last_used_gnss_pos_tow,
                        greater.last_used_gnss_pos_tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.last_used_gnss_vel_tow,
                        greater.last_used_gnss_vel_tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sats, greater.n_sats);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_sol_in, greater.n_sol_in);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.pdop, greater.pdop);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[0].flags, greater.sol_in[0].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[0].sensor_type,
                        greater.sol_in[0].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[1].flags, greater.sol_in[1].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[1].sensor_type,
                        greater.sol_in[1].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[2].flags, greater.sol_in[2].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[2].sensor_type,
                        greater.sol_in[2].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[3].flags, greater.sol_in[3].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[3].sensor_type,
                        greater.sol_in[3].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[4].flags, greater.sol_in[4].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[4].sensor_type,
                        greater.sol_in[4].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[5].flags, greater.sol_in[5].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[5].sensor_type,
                        greater.sol_in[5].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[6].flags, greater.sol_in[6].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[6].sensor_type,
                        greater.sol_in[6].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[7].flags, greater.sol_in[7].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[7].sensor_type,
                        greater.sol_in[7].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[8].flags, greater.sol_in[8].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[8].sensor_type,
                        greater.sol_in[8].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[9].flags, greater.sol_in[9].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[9].sensor_type,
                        greater.sol_in[9].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[10].flags, greater.sol_in[10].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[10].sensor_type,
                        greater.sol_in[10].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[11].flags, greater.sol_in[11].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[11].sensor_type,
                        greater.sol_in[11].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[12].flags, greater.sol_in[12].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[12].sensor_type,
                        greater.sol_in[12].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[13].flags, greater.sol_in[13].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[13].sensor_type,
                        greater.sol_in[13].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[14].flags, greater.sol_in[14].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[14].sensor_type,
                        greater.sol_in[14].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[15].flags, greater.sol_in[15].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[15].sensor_type,
                        greater.sol_in[15].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[16].flags, greater.sol_in[16].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[16].sensor_type,
                        greater.sol_in[16].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[17].flags, greater.sol_in[17].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[17].sensor_type,
                        greater.sol_in[17].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[18].flags, greater.sol_in[18].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[18].sensor_type,
                        greater.sol_in[18].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[19].flags, greater.sol_in[19].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[19].sensor_type,
                        greater.sol_in[19].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[20].flags, greater.sol_in[20].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[20].sensor_type,
                        greater.sol_in[20].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[21].flags, greater.sol_in[21].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[21].sensor_type,
                        greater.sol_in[21].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[22].flags, greater.sol_in[22].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[22].sensor_type,
                        greater.sol_in[22].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[23].flags, greater.sol_in[23].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[23].sensor_type,
                        greater.sol_in[23].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[24].flags, greater.sol_in[24].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[24].sensor_type,
                        greater.sol_in[24].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[25].flags, greater.sol_in[25].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[25].sensor_type,
                        greater.sol_in[25].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[26].flags, greater.sol_in[26].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[26].sensor_type,
                        greater.sol_in[26].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[27].flags, greater.sol_in[27].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[27].sensor_type,
                        greater.sol_in[27].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[28].flags, greater.sol_in[28].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[28].sensor_type,
                        greater.sol_in[28].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[29].flags, greater.sol_in[29].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[29].sensor_type,
                        greater.sol_in[29].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[30].flags, greater.sol_in[30].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[30].sensor_type,
                        greater.sol_in[30].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[31].flags, greater.sol_in[31].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[31].sensor_type,
                        greater.sol_in[31].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[32].flags, greater.sol_in[32].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[32].sensor_type,
                        greater.sol_in[32].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[33].flags, greater.sol_in[33].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[33].sensor_type,
                        greater.sol_in[33].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[34].flags, greater.sol_in[34].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[34].sensor_type,
                        greater.sol_in[34].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[35].flags, greater.sol_in[35].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[35].sensor_type,
                        greater.sol_in[35].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[36].flags, greater.sol_in[36].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[36].sensor_type,
                        greater.sol_in[36].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[37].flags, greater.sol_in[37].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[37].sensor_type,
                        greater.sol_in[37].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[38].flags, greater.sol_in[38].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[38].sensor_type,
                        greater.sol_in[38].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[39].flags, greater.sol_in[39].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[39].sensor_type,
                        greater.sol_in[39].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[40].flags, greater.sol_in[40].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[40].sensor_type,
                        greater.sol_in[40].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[41].flags, greater.sol_in[41].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[41].sensor_type,
                        greater.sol_in[41].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[42].flags, greater.sol_in[42].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[42].sensor_type,
                        greater.sol_in[42].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[43].flags, greater.sol_in[43].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[43].sensor_type,
                        greater.sol_in[43].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[44].flags, greater.sol_in[44].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[44].sensor_type,
                        greater.sol_in[44].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[45].flags, greater.sol_in[45].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[45].sensor_type,
                        greater.sol_in[45].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[46].flags, greater.sol_in[46].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[46].sensor_type,
                        greater.sol_in[46].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[47].flags, greater.sol_in[47].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[47].sensor_type,
                        greater.sol_in[47].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[48].flags, greater.sol_in[48].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[48].sensor_type,
                        greater.sol_in[48].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[49].flags, greater.sol_in[49].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[49].sensor_type,
                        greater.sol_in[49].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[50].flags, greater.sol_in[50].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[50].sensor_type,
                        greater.sol_in[50].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[51].flags, greater.sol_in[51].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[51].sensor_type,
                        greater.sol_in[51].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[52].flags, greater.sol_in[52].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[52].sensor_type,
                        greater.sol_in[52].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[53].flags, greater.sol_in[53].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[53].sensor_type,
                        greater.sol_in[53].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[54].flags, greater.sol_in[54].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[54].sensor_type,
                        greater.sol_in[54].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[55].flags, greater.sol_in[55].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[55].sensor_type,
                        greater.sol_in[55].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[56].flags, greater.sol_in[56].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[56].sensor_type,
                        greater.sol_in[56].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[57].flags, greater.sol_in[57].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[57].sensor_type,
                        greater.sol_in[57].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[58].flags, greater.sol_in[58].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[58].sensor_type,
                        greater.sol_in[58].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[59].flags, greater.sol_in[59].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[59].sensor_type,
                        greater.sol_in[59].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[60].flags, greater.sol_in[60].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[60].sensor_type,
                        greater.sol_in[60].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[61].flags, greater.sol_in[61].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[61].sensor_type,
                        greater.sol_in[61].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[62].flags, greater.sol_in[62].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[62].sensor_type,
                        greater.sol_in[62].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[63].flags, greater.sol_in[63].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[63].sensor_type,
                        greater.sol_in[63].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[64].flags, greater.sol_in[64].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[64].sensor_type,
                        greater.sol_in[64].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[65].flags, greater.sol_in[65].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[65].sensor_type,
                        greater.sol_in[65].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[66].flags, greater.sol_in[66].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[66].sensor_type,
                        greater.sol_in[66].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[67].flags, greater.sol_in[67].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[67].sensor_type,
                        greater.sol_in[67].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[68].flags, greater.sol_in[68].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[68].sensor_type,
                        greater.sol_in[68].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[69].flags, greater.sol_in[69].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[69].sensor_type,
                        greater.sol_in[69].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[70].flags, greater.sol_in[70].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[70].sensor_type,
                        greater.sol_in[70].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[71].flags, greater.sol_in[71].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[71].sensor_type,
                        greater.sol_in[71].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[72].flags, greater.sol_in[72].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[72].sensor_type,
                        greater.sol_in[72].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[73].flags, greater.sol_in[73].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[73].sensor_type,
                        greater.sol_in[73].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[74].flags, greater.sol_in[74].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[74].sensor_type,
                        greater.sol_in[74].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[75].flags, greater.sol_in[75].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[75].sensor_type,
                        greater.sol_in[75].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[76].flags, greater.sol_in[76].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[76].sensor_type,
                        greater.sol_in[76].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[77].flags, greater.sol_in[77].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[77].sensor_type,
                        greater.sol_in[77].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[78].flags, greater.sol_in[78].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[78].sensor_type,
                        greater.sol_in[78].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[79].flags, greater.sol_in[79].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[79].sensor_type,
                        greater.sol_in[79].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[80].flags, greater.sol_in[80].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[80].sensor_type,
                        greater.sol_in[80].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[81].flags, greater.sol_in[81].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[81].sensor_type,
                        greater.sol_in[81].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[82].flags, greater.sol_in[82].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[82].sensor_type,
                        greater.sol_in[82].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[83].flags, greater.sol_in[83].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[83].sensor_type,
                        greater.sol_in[83].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[84].flags, greater.sol_in[84].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[84].sensor_type,
                        greater.sol_in[84].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[85].flags, greater.sol_in[85].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[85].sensor_type,
                        greater.sol_in[85].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[86].flags, greater.sol_in[86].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[86].sensor_type,
                        greater.sol_in[86].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[87].flags, greater.sol_in[87].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[87].sensor_type,
                        greater.sol_in[87].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[88].flags, greater.sol_in[88].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[88].sensor_type,
                        greater.sol_in[88].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[89].flags, greater.sol_in[89].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[89].sensor_type,
                        greater.sol_in[89].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[90].flags, greater.sol_in[90].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[90].sensor_type,
                        greater.sol_in[90].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[91].flags, greater.sol_in[91].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[91].sensor_type,
                        greater.sol_in[91].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[92].flags, greater.sol_in[92].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[92].sensor_type,
                        greater.sol_in[92].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[93].flags, greater.sol_in[93].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[93].sensor_type,
                        greater.sol_in[93].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[94].flags, greater.sol_in[94].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[94].sensor_type,
                        greater.sol_in[94].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[95].flags, greater.sol_in[95].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[95].sensor_type,
                        greater.sol_in[95].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[96].flags, greater.sol_in[96].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[96].sensor_type,
                        greater.sol_in[96].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[97].flags, greater.sol_in[97].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[97].sensor_type,
                        greater.sol_in[97].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[98].flags, greater.sol_in[98].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[98].sensor_type,
                        greater.sol_in[98].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[99].flags, greater.sol_in[99].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[99].sensor_type,
                        greater.sol_in[99].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[100].flags, greater.sol_in[100].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[100].sensor_type,
                        greater.sol_in[100].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[101].flags, greater.sol_in[101].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[101].sensor_type,
                        greater.sol_in[101].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[102].flags, greater.sol_in[102].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[102].sensor_type,
                        greater.sol_in[102].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[103].flags, greater.sol_in[103].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[103].sensor_type,
                        greater.sol_in[103].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[104].flags, greater.sol_in[104].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[104].sensor_type,
                        greater.sol_in[104].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[105].flags, greater.sol_in[105].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[105].sensor_type,
                        greater.sol_in[105].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[106].flags, greater.sol_in[106].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[106].sensor_type,
                        greater.sol_in[106].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[107].flags, greater.sol_in[107].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[107].sensor_type,
                        greater.sol_in[107].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[108].flags, greater.sol_in[108].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[108].sensor_type,
                        greater.sol_in[108].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[109].flags, greater.sol_in[109].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[109].sensor_type,
                        greater.sol_in[109].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[110].flags, greater.sol_in[110].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[110].sensor_type,
                        greater.sol_in[110].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[111].flags, greater.sol_in[111].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[111].sensor_type,
                        greater.sol_in[111].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[112].flags, greater.sol_in[112].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[112].sensor_type,
                        greater.sol_in[112].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[113].flags, greater.sol_in[113].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[113].sensor_type,
                        greater.sol_in[113].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[114].flags, greater.sol_in[114].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[114].sensor_type,
                        greater.sol_in[114].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[115].flags, greater.sol_in[115].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[115].sensor_type,
                        greater.sol_in[115].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[116].flags, greater.sol_in[116].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[116].sensor_type,
                        greater.sol_in[116].sensor_type);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[117].flags, greater.sol_in[117].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.sol_in[117].sensor_type,
                        greater.sol_in[117].sensor_type);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_soln_meta_dep_a_t lesser = info.test_msg;
    sbp_msg_soln_meta_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.vdop, greater.vdop);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_soln_meta_dep_a_t>::id,
  // SbpMsgSolnMetaDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_soln_meta_dep_a_t>::name,
               "MSG_SOLN_META_DEP_A");
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_soln_meta_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_soln_meta_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_soln_meta_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_soln_meta_dep_a_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_soln_meta_dep_a_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.soln_meta_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_soln_meta_dep_a_t>::to_sbp_msg(info.test_msg,
                                                            &msg2);
  EXPECT_EQ(msg2.soln_meta_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_soln_meta_dep_a_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_soln_meta_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[254];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_soln_meta_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 254);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 254), 0);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_soln_meta_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_soln_meta_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 254);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
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

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgSolnMetaDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_solution_meta_MsgSolnMetaDepA0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgSolnMetaDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace