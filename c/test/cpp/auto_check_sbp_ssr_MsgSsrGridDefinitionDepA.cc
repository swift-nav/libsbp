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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGridDefinitionDepA.yaml by
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
class Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0() {
    assign(test_msg_.header.area_width, 43860);
    assign(test_msg_.header.lat_nw_corner_enc, 34021);
    assign(test_msg_.header.lon_nw_corner_enc, 11919);
    assign(test_msg_.header.num_msgs, 204);
    assign(test_msg_.header.region_size_inverse, 11);
    assign(test_msg_.header.seq_num, 52);
    assign(test_msg_.n_rle_list, 246);

    assign(test_msg_.rle_list[0], 92);

    assign(test_msg_.rle_list[1], 104);

    assign(test_msg_.rle_list[2], 25);

    assign(test_msg_.rle_list[3], 204);

    assign(test_msg_.rle_list[4], 182);

    assign(test_msg_.rle_list[5], 22);

    assign(test_msg_.rle_list[6], 98);

    assign(test_msg_.rle_list[7], 203);

    assign(test_msg_.rle_list[8], 123);

    assign(test_msg_.rle_list[9], 211);

    assign(test_msg_.rle_list[10], 38);

    assign(test_msg_.rle_list[11], 13);

    assign(test_msg_.rle_list[12], 253);

    assign(test_msg_.rle_list[13], 129);

    assign(test_msg_.rle_list[14], 173);

    assign(test_msg_.rle_list[15], 171);

    assign(test_msg_.rle_list[16], 235);

    assign(test_msg_.rle_list[17], 253);

    assign(test_msg_.rle_list[18], 26);

    assign(test_msg_.rle_list[19], 203);

    assign(test_msg_.rle_list[20], 3);

    assign(test_msg_.rle_list[21], 120);

    assign(test_msg_.rle_list[22], 126);

    assign(test_msg_.rle_list[23], 42);

    assign(test_msg_.rle_list[24], 44);

    assign(test_msg_.rle_list[25], 39);

    assign(test_msg_.rle_list[26], 87);

    assign(test_msg_.rle_list[27], 69);

    assign(test_msg_.rle_list[28], 154);

    assign(test_msg_.rle_list[29], 13);

    assign(test_msg_.rle_list[30], 28);

    assign(test_msg_.rle_list[31], 179);

    assign(test_msg_.rle_list[32], 32);

    assign(test_msg_.rle_list[33], 47);

    assign(test_msg_.rle_list[34], 36);

    assign(test_msg_.rle_list[35], 195);

    assign(test_msg_.rle_list[36], 39);

    assign(test_msg_.rle_list[37], 198);

    assign(test_msg_.rle_list[38], 134);

    assign(test_msg_.rle_list[39], 235);

    assign(test_msg_.rle_list[40], 134);

    assign(test_msg_.rle_list[41], 57);

    assign(test_msg_.rle_list[42], 120);

    assign(test_msg_.rle_list[43], 243);

    assign(test_msg_.rle_list[44], 151);

    assign(test_msg_.rle_list[45], 35);

    assign(test_msg_.rle_list[46], 17);

    assign(test_msg_.rle_list[47], 201);

    assign(test_msg_.rle_list[48], 211);

    assign(test_msg_.rle_list[49], 125);

    assign(test_msg_.rle_list[50], 117);

    assign(test_msg_.rle_list[51], 164);

    assign(test_msg_.rle_list[52], 142);

    assign(test_msg_.rle_list[53], 101);

    assign(test_msg_.rle_list[54], 239);

    assign(test_msg_.rle_list[55], 144);

    assign(test_msg_.rle_list[56], 158);

    assign(test_msg_.rle_list[57], 239);

    assign(test_msg_.rle_list[58], 90);

    assign(test_msg_.rle_list[59], 56);

    assign(test_msg_.rle_list[60], 71);

    assign(test_msg_.rle_list[61], 120);

    assign(test_msg_.rle_list[62], 67);

    assign(test_msg_.rle_list[63], 221);

    assign(test_msg_.rle_list[64], 114);

    assign(test_msg_.rle_list[65], 10);

    assign(test_msg_.rle_list[66], 190);

    assign(test_msg_.rle_list[67], 4);

    assign(test_msg_.rle_list[68], 230);

    assign(test_msg_.rle_list[69], 164);

    assign(test_msg_.rle_list[70], 171);

    assign(test_msg_.rle_list[71], 78);

    assign(test_msg_.rle_list[72], 185);

    assign(test_msg_.rle_list[73], 90);

    assign(test_msg_.rle_list[74], 46);

    assign(test_msg_.rle_list[75], 177);

    assign(test_msg_.rle_list[76], 82);

    assign(test_msg_.rle_list[77], 228);

    assign(test_msg_.rle_list[78], 123);

    assign(test_msg_.rle_list[79], 222);

    assign(test_msg_.rle_list[80], 227);

    assign(test_msg_.rle_list[81], 145);

    assign(test_msg_.rle_list[82], 195);

    assign(test_msg_.rle_list[83], 219);

    assign(test_msg_.rle_list[84], 27);

    assign(test_msg_.rle_list[85], 56);

    assign(test_msg_.rle_list[86], 227);

    assign(test_msg_.rle_list[87], 246);

    assign(test_msg_.rle_list[88], 215);

    assign(test_msg_.rle_list[89], 144);

    assign(test_msg_.rle_list[90], 158);

    assign(test_msg_.rle_list[91], 31);

    assign(test_msg_.rle_list[92], 214);

    assign(test_msg_.rle_list[93], 241);

    assign(test_msg_.rle_list[94], 254);

    assign(test_msg_.rle_list[95], 200);

    assign(test_msg_.rle_list[96], 86);

    assign(test_msg_.rle_list[97], 142);

    assign(test_msg_.rle_list[98], 89);

    assign(test_msg_.rle_list[99], 12);

    assign(test_msg_.rle_list[100], 121);

    assign(test_msg_.rle_list[101], 29);

    assign(test_msg_.rle_list[102], 124);

    assign(test_msg_.rle_list[103], 9);

    assign(test_msg_.rle_list[104], 19);

    assign(test_msg_.rle_list[105], 153);

    assign(test_msg_.rle_list[106], 44);

    assign(test_msg_.rle_list[107], 35);

    assign(test_msg_.rle_list[108], 126);

    assign(test_msg_.rle_list[109], 14);

    assign(test_msg_.rle_list[110], 217);

    assign(test_msg_.rle_list[111], 65);

    assign(test_msg_.rle_list[112], 116);

    assign(test_msg_.rle_list[113], 26);

    assign(test_msg_.rle_list[114], 139);

    assign(test_msg_.rle_list[115], 122);

    assign(test_msg_.rle_list[116], 114);

    assign(test_msg_.rle_list[117], 90);

    assign(test_msg_.rle_list[118], 124);

    assign(test_msg_.rle_list[119], 81);

    assign(test_msg_.rle_list[120], 0);

    assign(test_msg_.rle_list[121], 186);

    assign(test_msg_.rle_list[122], 246);

    assign(test_msg_.rle_list[123], 46);

    assign(test_msg_.rle_list[124], 98);

    assign(test_msg_.rle_list[125], 179);

    assign(test_msg_.rle_list[126], 243);

    assign(test_msg_.rle_list[127], 198);

    assign(test_msg_.rle_list[128], 217);

    assign(test_msg_.rle_list[129], 36);

    assign(test_msg_.rle_list[130], 30);

    assign(test_msg_.rle_list[131], 202);

    assign(test_msg_.rle_list[132], 12);

    assign(test_msg_.rle_list[133], 135);

    assign(test_msg_.rle_list[134], 61);

    assign(test_msg_.rle_list[135], 42);

    assign(test_msg_.rle_list[136], 150);

    assign(test_msg_.rle_list[137], 221);

    assign(test_msg_.rle_list[138], 102);

    assign(test_msg_.rle_list[139], 83);

    assign(test_msg_.rle_list[140], 179);

    assign(test_msg_.rle_list[141], 43);

    assign(test_msg_.rle_list[142], 252);

    assign(test_msg_.rle_list[143], 81);

    assign(test_msg_.rle_list[144], 62);

    assign(test_msg_.rle_list[145], 126);

    assign(test_msg_.rle_list[146], 204);

    assign(test_msg_.rle_list[147], 195);

    assign(test_msg_.rle_list[148], 238);

    assign(test_msg_.rle_list[149], 18);

    assign(test_msg_.rle_list[150], 128);

    assign(test_msg_.rle_list[151], 193);

    assign(test_msg_.rle_list[152], 53);

    assign(test_msg_.rle_list[153], 94);

    assign(test_msg_.rle_list[154], 99);

    assign(test_msg_.rle_list[155], 63);

    assign(test_msg_.rle_list[156], 182);

    assign(test_msg_.rle_list[157], 2);

    assign(test_msg_.rle_list[158], 186);

    assign(test_msg_.rle_list[159], 220);

    assign(test_msg_.rle_list[160], 77);

    assign(test_msg_.rle_list[161], 186);

    assign(test_msg_.rle_list[162], 224);

    assign(test_msg_.rle_list[163], 220);

    assign(test_msg_.rle_list[164], 13);

    assign(test_msg_.rle_list[165], 212);

    assign(test_msg_.rle_list[166], 182);

    assign(test_msg_.rle_list[167], 88);

    assign(test_msg_.rle_list[168], 15);

    assign(test_msg_.rle_list[169], 151);

    assign(test_msg_.rle_list[170], 5);

    assign(test_msg_.rle_list[171], 93);

    assign(test_msg_.rle_list[172], 251);

    assign(test_msg_.rle_list[173], 164);

    assign(test_msg_.rle_list[174], 18);

    assign(test_msg_.rle_list[175], 228);

    assign(test_msg_.rle_list[176], 168);

    assign(test_msg_.rle_list[177], 226);

    assign(test_msg_.rle_list[178], 195);

    assign(test_msg_.rle_list[179], 44);

    assign(test_msg_.rle_list[180], 170);

    assign(test_msg_.rle_list[181], 145);

    assign(test_msg_.rle_list[182], 36);

    assign(test_msg_.rle_list[183], 58);

    assign(test_msg_.rle_list[184], 96);

    assign(test_msg_.rle_list[185], 107);

    assign(test_msg_.rle_list[186], 144);

    assign(test_msg_.rle_list[187], 11);

    assign(test_msg_.rle_list[188], 228);

    assign(test_msg_.rle_list[189], 12);

    assign(test_msg_.rle_list[190], 163);

    assign(test_msg_.rle_list[191], 238);

    assign(test_msg_.rle_list[192], 247);

    assign(test_msg_.rle_list[193], 159);

    assign(test_msg_.rle_list[194], 189);

    assign(test_msg_.rle_list[195], 1);

    assign(test_msg_.rle_list[196], 115);

    assign(test_msg_.rle_list[197], 65);

    assign(test_msg_.rle_list[198], 202);

    assign(test_msg_.rle_list[199], 121);

    assign(test_msg_.rle_list[200], 47);

    assign(test_msg_.rle_list[201], 193);

    assign(test_msg_.rle_list[202], 11);

    assign(test_msg_.rle_list[203], 96);

    assign(test_msg_.rle_list[204], 93);

    assign(test_msg_.rle_list[205], 72);

    assign(test_msg_.rle_list[206], 81);

    assign(test_msg_.rle_list[207], 207);

    assign(test_msg_.rle_list[208], 121);

    assign(test_msg_.rle_list[209], 19);

    assign(test_msg_.rle_list[210], 151);

    assign(test_msg_.rle_list[211], 136);

    assign(test_msg_.rle_list[212], 233);

    assign(test_msg_.rle_list[213], 51);

    assign(test_msg_.rle_list[214], 133);

    assign(test_msg_.rle_list[215], 195);

    assign(test_msg_.rle_list[216], 77);

    assign(test_msg_.rle_list[217], 44);

    assign(test_msg_.rle_list[218], 147);

    assign(test_msg_.rle_list[219], 206);

    assign(test_msg_.rle_list[220], 120);

    assign(test_msg_.rle_list[221], 252);

    assign(test_msg_.rle_list[222], 77);

    assign(test_msg_.rle_list[223], 212);

    assign(test_msg_.rle_list[224], 68);

    assign(test_msg_.rle_list[225], 60);

    assign(test_msg_.rle_list[226], 206);

    assign(test_msg_.rle_list[227], 106);

    assign(test_msg_.rle_list[228], 207);

    assign(test_msg_.rle_list[229], 243);

    assign(test_msg_.rle_list[230], 158);

    assign(test_msg_.rle_list[231], 94);

    assign(test_msg_.rle_list[232], 6);

    assign(test_msg_.rle_list[233], 3);

    assign(test_msg_.rle_list[234], 205);

    assign(test_msg_.rle_list[235], 92);

    assign(test_msg_.rle_list[236], 84);

    assign(test_msg_.rle_list[237], 2);

    assign(test_msg_.rle_list[238], 220);

    assign(test_msg_.rle_list[239], 50);

    assign(test_msg_.rle_list[240], 61);

    assign(test_msg_.rle_list[241], 38);

    assign(test_msg_.rle_list[242], 141);

    assign(test_msg_.rle_list[243], 117);

    assign(test_msg_.rle_list[244], 108);

    assign(test_msg_.rle_list[245], 101);
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
      : public sbp::MessageHandler<sbp_msg_ssr_grid_definition_dep_a_t> {
    using sbp::MessageHandler<
        sbp_msg_ssr_grid_definition_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_grid_definition_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(
        uint16_t sender_id,
        const sbp_msg_ssr_grid_definition_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgSsrGridDefinitionDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_grid_definition_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgSsrGridDefinitionDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ssr_grid_definition_dep_a,
             sizeof(msg->ssr_grid_definition_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ssr_grid_definition_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ssr_grid_definition_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgSsrGridDefinitionDepA);
    info.sender_id = 63413;
    info.preamble = 0x55;
    info.crc = 0x8b4c;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 255;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ssr_grid_definition_dep_a_t &lesser,
                        const sbp_msg_ssr_grid_definition_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t>::to_sbp_msg(
            lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_ssr_grid_definition_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ssr_grid_definition_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ssr_grid_definition_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ssr_grid_definition_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrGridDefinitionDepA, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrGridDefinitionDepA, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgSsrGridDefinitionDepA, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgSsrGridDefinitionDepA, &wrapped_greater,
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
  sbp_msg_ssr_grid_definition_dep_a_t test_msg_{};
  uint8_t encoded_frame_[255 + 8] = {
      85,  245, 5,   181, 247, 255, 11,  84,  171, 229, 132, 143, 46,  204, 52,
      92,  104, 25,  204, 182, 22,  98,  203, 123, 211, 38,  13,  253, 129, 173,
      171, 235, 253, 26,  203, 3,   120, 126, 42,  44,  39,  87,  69,  154, 13,
      28,  179, 32,  47,  36,  195, 39,  198, 134, 235, 134, 57,  120, 243, 151,
      35,  17,  201, 211, 125, 117, 164, 142, 101, 239, 144, 158, 239, 90,  56,
      71,  120, 67,  221, 114, 10,  190, 4,   230, 164, 171, 78,  185, 90,  46,
      177, 82,  228, 123, 222, 227, 145, 195, 219, 27,  56,  227, 246, 215, 144,
      158, 31,  214, 241, 254, 200, 86,  142, 89,  12,  121, 29,  124, 9,   19,
      153, 44,  35,  126, 14,  217, 65,  116, 26,  139, 122, 114, 90,  124, 81,
      0,   186, 246, 46,  98,  179, 243, 198, 217, 36,  30,  202, 12,  135, 61,
      42,  150, 221, 102, 83,  179, 43,  252, 81,  62,  126, 204, 195, 238, 18,
      128, 193, 53,  94,  99,  63,  182, 2,   186, 220, 77,  186, 224, 220, 13,
      212, 182, 88,  15,  151, 5,   93,  251, 164, 18,  228, 168, 226, 195, 44,
      170, 145, 36,  58,  96,  107, 144, 11,  228, 12,  163, 238, 247, 159, 189,
      1,   115, 65,  202, 121, 47,  193, 11,  96,  93,  72,  81,  207, 121, 19,
      151, 136, 233, 51,  133, 195, 77,  44,  147, 206, 120, 252, 77,  212, 68,
      60,  206, 106, 207, 243, 158, 94,  6,   3,   205, 92,  84,  2,   220, 50,
      61,  38,  141, 117, 108, 101, 76,  139,
  };
  uint8_t encoded_payload_[255] = {
      11,  84,  171, 229, 132, 143, 46,  204, 52,  92,  104, 25,  204, 182, 22,
      98,  203, 123, 211, 38,  13,  253, 129, 173, 171, 235, 253, 26,  203, 3,
      120, 126, 42,  44,  39,  87,  69,  154, 13,  28,  179, 32,  47,  36,  195,
      39,  198, 134, 235, 134, 57,  120, 243, 151, 35,  17,  201, 211, 125, 117,
      164, 142, 101, 239, 144, 158, 239, 90,  56,  71,  120, 67,  221, 114, 10,
      190, 4,   230, 164, 171, 78,  185, 90,  46,  177, 82,  228, 123, 222, 227,
      145, 195, 219, 27,  56,  227, 246, 215, 144, 158, 31,  214, 241, 254, 200,
      86,  142, 89,  12,  121, 29,  124, 9,   19,  153, 44,  35,  126, 14,  217,
      65,  116, 26,  139, 122, 114, 90,  124, 81,  0,   186, 246, 46,  98,  179,
      243, 198, 217, 36,  30,  202, 12,  135, 61,  42,  150, 221, 102, 83,  179,
      43,  252, 81,  62,  126, 204, 195, 238, 18,  128, 193, 53,  94,  99,  63,
      182, 2,   186, 220, 77,  186, 224, 220, 13,  212, 182, 88,  15,  151, 5,
      93,  251, 164, 18,  228, 168, 226, 195, 44,  170, 145, 36,  58,  96,  107,
      144, 11,  228, 12,  163, 238, 247, 159, 189, 1,   115, 65,  202, 121, 47,
      193, 11,  96,  93,  72,  81,  207, 121, 19,  151, 136, 233, 51,  133, 195,
      77,  44,  147, 206, 120, 252, 77,  212, 68,  60,  206, 106, 207, 243, 158,
      94,  6,   3,   205, 92,  84,  2,   220, 50,  61,  38,  141, 117, 108, 101,
  };
};

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ssr_grid_definition_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgSsrGridDefinitionDepA,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[255];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ssr_grid_definition_dep_a_encode(
                &buf[0], sizeof(buf), &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(
      sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                         SbpMsgSsrGridDefinitionDepA, &info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[255];

  EXPECT_EQ(sbp_msg_ssr_grid_definition_dep_a_encode(&buf[0], sizeof(buf),
                                                     nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[255];

  for (uint8_t i = 0; i < 255; i++) {
    EXPECT_EQ(sbp_msg_ssr_grid_definition_dep_a_encode(&buf[0], i, nullptr,
                                                       &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_grid_definition_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ssr_grid_definition_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgSsrGridDefinitionDepA, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_grid_definition_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_ssr_grid_definition_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_grid_definition_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ssr_grid_definition_dep_a_t t{};
      return sbp_msg_ssr_grid_definition_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ssr_grid_definition_dep_a_t t{};
      t.n_rle_list = 1;
      return sbp_msg_ssr_grid_definition_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ssr_grid_definition_dep_a_decode(&info.encoded_payload[0],
                                                       i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, SlowRead) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, BadCRC) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ssr_grid_definition_dep_a_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgSsrGridDefinitionDepA, info.sender_id,
                       &info.test_msg_wrapped, &Writer::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(
        sbp_message_send(&state, SbpMsgSsrGridDefinitionDepA, info.sender_id,
                         &info.test_msg_wrapped, &Writer::write_c),
        SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgSsrGridDefinitionDepA, info.sender_id,
                       &info.test_msg_wrapped, &SlowWriter::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.area_width, greater.header.area_width);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.lat_nw_corner_enc,
                        greater.header.lat_nw_corner_enc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.lon_nw_corner_enc,
                        greater.header.lon_nw_corner_enc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.num_msgs, greater.header.num_msgs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.region_size_inverse,
                        greater.header.region_size_inverse);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.header.seq_num, greater.header.seq_num);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_rle_list, greater.n_rle_list);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[0], greater.rle_list[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[1], greater.rle_list[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[2], greater.rle_list[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[3], greater.rle_list[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[4], greater.rle_list[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[5], greater.rle_list[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[6], greater.rle_list[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[7], greater.rle_list[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[8], greater.rle_list[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[9], greater.rle_list[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[10], greater.rle_list[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[11], greater.rle_list[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[12], greater.rle_list[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[13], greater.rle_list[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[14], greater.rle_list[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[15], greater.rle_list[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[16], greater.rle_list[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[17], greater.rle_list[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[18], greater.rle_list[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[19], greater.rle_list[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[20], greater.rle_list[20]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[21], greater.rle_list[21]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[22], greater.rle_list[22]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[23], greater.rle_list[23]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[24], greater.rle_list[24]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[25], greater.rle_list[25]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[26], greater.rle_list[26]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[27], greater.rle_list[27]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[28], greater.rle_list[28]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[29], greater.rle_list[29]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[30], greater.rle_list[30]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[31], greater.rle_list[31]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[32], greater.rle_list[32]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[33], greater.rle_list[33]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[34], greater.rle_list[34]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[35], greater.rle_list[35]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[36], greater.rle_list[36]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[37], greater.rle_list[37]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[38], greater.rle_list[38]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[39], greater.rle_list[39]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[40], greater.rle_list[40]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[41], greater.rle_list[41]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[42], greater.rle_list[42]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[43], greater.rle_list[43]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[44], greater.rle_list[44]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[45], greater.rle_list[45]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[46], greater.rle_list[46]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[47], greater.rle_list[47]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[48], greater.rle_list[48]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[49], greater.rle_list[49]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[50], greater.rle_list[50]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[51], greater.rle_list[51]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[52], greater.rle_list[52]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[53], greater.rle_list[53]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[54], greater.rle_list[54]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[55], greater.rle_list[55]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[56], greater.rle_list[56]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[57], greater.rle_list[57]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[58], greater.rle_list[58]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[59], greater.rle_list[59]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[60], greater.rle_list[60]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[61], greater.rle_list[61]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[62], greater.rle_list[62]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[63], greater.rle_list[63]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[64], greater.rle_list[64]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[65], greater.rle_list[65]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[66], greater.rle_list[66]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[67], greater.rle_list[67]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[68], greater.rle_list[68]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[69], greater.rle_list[69]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[70], greater.rle_list[70]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[71], greater.rle_list[71]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[72], greater.rle_list[72]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[73], greater.rle_list[73]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[74], greater.rle_list[74]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[75], greater.rle_list[75]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[76], greater.rle_list[76]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[77], greater.rle_list[77]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[78], greater.rle_list[78]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[79], greater.rle_list[79]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[80], greater.rle_list[80]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[81], greater.rle_list[81]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[82], greater.rle_list[82]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[83], greater.rle_list[83]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[84], greater.rle_list[84]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[85], greater.rle_list[85]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[86], greater.rle_list[86]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[87], greater.rle_list[87]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[88], greater.rle_list[88]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[89], greater.rle_list[89]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[90], greater.rle_list[90]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[91], greater.rle_list[91]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[92], greater.rle_list[92]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[93], greater.rle_list[93]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[94], greater.rle_list[94]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[95], greater.rle_list[95]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[96], greater.rle_list[96]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[97], greater.rle_list[97]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[98], greater.rle_list[98]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[99], greater.rle_list[99]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[100], greater.rle_list[100]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[101], greater.rle_list[101]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[102], greater.rle_list[102]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[103], greater.rle_list[103]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[104], greater.rle_list[104]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[105], greater.rle_list[105]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[106], greater.rle_list[106]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[107], greater.rle_list[107]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[108], greater.rle_list[108]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[109], greater.rle_list[109]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[110], greater.rle_list[110]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[111], greater.rle_list[111]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[112], greater.rle_list[112]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[113], greater.rle_list[113]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[114], greater.rle_list[114]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[115], greater.rle_list[115]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[116], greater.rle_list[116]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[117], greater.rle_list[117]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[118], greater.rle_list[118]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[119], greater.rle_list[119]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[120], greater.rle_list[120]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[121], greater.rle_list[121]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[122], greater.rle_list[122]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[123], greater.rle_list[123]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[124], greater.rle_list[124]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[125], greater.rle_list[125]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[126], greater.rle_list[126]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[127], greater.rle_list[127]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[128], greater.rle_list[128]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[129], greater.rle_list[129]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[130], greater.rle_list[130]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[131], greater.rle_list[131]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[132], greater.rle_list[132]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[133], greater.rle_list[133]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[134], greater.rle_list[134]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[135], greater.rle_list[135]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[136], greater.rle_list[136]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[137], greater.rle_list[137]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[138], greater.rle_list[138]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[139], greater.rle_list[139]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[140], greater.rle_list[140]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[141], greater.rle_list[141]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[142], greater.rle_list[142]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[143], greater.rle_list[143]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[144], greater.rle_list[144]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[145], greater.rle_list[145]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[146], greater.rle_list[146]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[147], greater.rle_list[147]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[148], greater.rle_list[148]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[149], greater.rle_list[149]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[150], greater.rle_list[150]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[151], greater.rle_list[151]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[152], greater.rle_list[152]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[153], greater.rle_list[153]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[154], greater.rle_list[154]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[155], greater.rle_list[155]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[156], greater.rle_list[156]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[157], greater.rle_list[157]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[158], greater.rle_list[158]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[159], greater.rle_list[159]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[160], greater.rle_list[160]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[161], greater.rle_list[161]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[162], greater.rle_list[162]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[163], greater.rle_list[163]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[164], greater.rle_list[164]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[165], greater.rle_list[165]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[166], greater.rle_list[166]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[167], greater.rle_list[167]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[168], greater.rle_list[168]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[169], greater.rle_list[169]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[170], greater.rle_list[170]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[171], greater.rle_list[171]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[172], greater.rle_list[172]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[173], greater.rle_list[173]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[174], greater.rle_list[174]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[175], greater.rle_list[175]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[176], greater.rle_list[176]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[177], greater.rle_list[177]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[178], greater.rle_list[178]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[179], greater.rle_list[179]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[180], greater.rle_list[180]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[181], greater.rle_list[181]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[182], greater.rle_list[182]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[183], greater.rle_list[183]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[184], greater.rle_list[184]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[185], greater.rle_list[185]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[186], greater.rle_list[186]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[187], greater.rle_list[187]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[188], greater.rle_list[188]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[189], greater.rle_list[189]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[190], greater.rle_list[190]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[191], greater.rle_list[191]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[192], greater.rle_list[192]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[193], greater.rle_list[193]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[194], greater.rle_list[194]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[195], greater.rle_list[195]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[196], greater.rle_list[196]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[197], greater.rle_list[197]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[198], greater.rle_list[198]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[199], greater.rle_list[199]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[200], greater.rle_list[200]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[201], greater.rle_list[201]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[202], greater.rle_list[202]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[203], greater.rle_list[203]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[204], greater.rle_list[204]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[205], greater.rle_list[205]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[206], greater.rle_list[206]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[207], greater.rle_list[207]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[208], greater.rle_list[208]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[209], greater.rle_list[209]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[210], greater.rle_list[210]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[211], greater.rle_list[211]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[212], greater.rle_list[212]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[213], greater.rle_list[213]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[214], greater.rle_list[214]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[215], greater.rle_list[215]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[216], greater.rle_list[216]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[217], greater.rle_list[217]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[218], greater.rle_list[218]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[219], greater.rle_list[219]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[220], greater.rle_list[220]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[221], greater.rle_list[221]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[222], greater.rle_list[222]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[223], greater.rle_list[223]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[224], greater.rle_list[224]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[225], greater.rle_list[225]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[226], greater.rle_list[226]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[227], greater.rle_list[227]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[228], greater.rle_list[228]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[229], greater.rle_list[229]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[230], greater.rle_list[230]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[231], greater.rle_list[231]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[232], greater.rle_list[232]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[233], greater.rle_list[233]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[234], greater.rle_list[234]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[235], greater.rle_list[235]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[236], greater.rle_list[236]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[237], greater.rle_list[237]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[238], greater.rle_list[238]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[239], greater.rle_list[239]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[240], greater.rle_list[240]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[241], greater.rle_list[241]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[242], greater.rle_list[242]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[243], greater.rle_list[243]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[244], greater.rle_list[244]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_grid_definition_dep_a_t lesser = info.test_msg;
    sbp_msg_ssr_grid_definition_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.rle_list[245], greater.rle_list[245]);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t>::id,
  // SbpMsgSsrGridDefinitionDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t>::name,
               "MSG_SSR_GRID_DEFINITION_DEP_A");
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ssr_grid_definition_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t>::get(
          const_sbp_msg_t);
  sbp_msg_ssr_grid_definition_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.ssr_grid_definition_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t>::to_sbp_msg(
      info.test_msg, &msg2);
  EXPECT_EQ(msg2.ssr_grid_definition_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t>::encoded_len(
          info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[255];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_grid_definition_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_grid_definition_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgSsrGridDefinitionDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrGridDefinitionDepA0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgSsrGridDefinitionDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace