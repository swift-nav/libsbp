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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgSpecan.yaml by generate.py. Do not
// modify by hand!

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
class Testauto_check_sbp_piksi_MsgSpecan0 : public ::testing::Test {
 public:
  Testauto_check_sbp_piksi_MsgSpecan0() {
    assign(test_msg_.amplitude_ref, 3780.199951171875);
    assign(test_msg_.amplitude_unit, 1329.199951171875);

    assign(test_msg_.amplitude_value[0], 100);

    assign(test_msg_.amplitude_value[1], 179);

    assign(test_msg_.amplitude_value[2], 185);

    assign(test_msg_.amplitude_value[3], 17);

    assign(test_msg_.amplitude_value[4], 175);

    assign(test_msg_.amplitude_value[5], 49);

    assign(test_msg_.amplitude_value[6], 193);

    assign(test_msg_.amplitude_value[7], 228);

    assign(test_msg_.amplitude_value[8], 228);

    assign(test_msg_.amplitude_value[9], 47);

    assign(test_msg_.amplitude_value[10], 33);

    assign(test_msg_.amplitude_value[11], 24);

    assign(test_msg_.amplitude_value[12], 141);

    assign(test_msg_.amplitude_value[13], 177);

    assign(test_msg_.amplitude_value[14], 18);

    assign(test_msg_.amplitude_value[15], 99);

    assign(test_msg_.amplitude_value[16], 246);

    assign(test_msg_.amplitude_value[17], 121);

    assign(test_msg_.amplitude_value[18], 61);

    assign(test_msg_.amplitude_value[19], 40);

    assign(test_msg_.amplitude_value[20], 91);

    assign(test_msg_.amplitude_value[21], 145);

    assign(test_msg_.amplitude_value[22], 223);

    assign(test_msg_.amplitude_value[23], 167);

    assign(test_msg_.amplitude_value[24], 174);

    assign(test_msg_.amplitude_value[25], 9);

    assign(test_msg_.amplitude_value[26], 116);

    assign(test_msg_.amplitude_value[27], 11);

    assign(test_msg_.amplitude_value[28], 247);

    assign(test_msg_.amplitude_value[29], 84);

    assign(test_msg_.amplitude_value[30], 49);

    assign(test_msg_.amplitude_value[31], 153);

    assign(test_msg_.amplitude_value[32], 205);

    assign(test_msg_.amplitude_value[33], 2);

    assign(test_msg_.amplitude_value[34], 230);

    assign(test_msg_.amplitude_value[35], 194);

    assign(test_msg_.amplitude_value[36], 218);

    assign(test_msg_.amplitude_value[37], 241);

    assign(test_msg_.amplitude_value[38], 101);

    assign(test_msg_.amplitude_value[39], 107);

    assign(test_msg_.amplitude_value[40], 45);

    assign(test_msg_.amplitude_value[41], 137);

    assign(test_msg_.amplitude_value[42], 93);

    assign(test_msg_.amplitude_value[43], 114);

    assign(test_msg_.amplitude_value[44], 230);

    assign(test_msg_.amplitude_value[45], 43);

    assign(test_msg_.amplitude_value[46], 224);

    assign(test_msg_.amplitude_value[47], 23);

    assign(test_msg_.amplitude_value[48], 74);

    assign(test_msg_.amplitude_value[49], 209);

    assign(test_msg_.amplitude_value[50], 199);

    assign(test_msg_.amplitude_value[51], 211);

    assign(test_msg_.amplitude_value[52], 130);

    assign(test_msg_.amplitude_value[53], 89);

    assign(test_msg_.amplitude_value[54], 220);

    assign(test_msg_.amplitude_value[55], 163);

    assign(test_msg_.amplitude_value[56], 68);

    assign(test_msg_.amplitude_value[57], 20);

    assign(test_msg_.amplitude_value[58], 253);

    assign(test_msg_.amplitude_value[59], 7);

    assign(test_msg_.amplitude_value[60], 206);

    assign(test_msg_.amplitude_value[61], 50);

    assign(test_msg_.amplitude_value[62], 129);

    assign(test_msg_.amplitude_value[63], 116);

    assign(test_msg_.amplitude_value[64], 194);

    assign(test_msg_.amplitude_value[65], 23);

    assign(test_msg_.amplitude_value[66], 31);

    assign(test_msg_.amplitude_value[67], 226);

    assign(test_msg_.amplitude_value[68], 217);

    assign(test_msg_.amplitude_value[69], 157);

    assign(test_msg_.amplitude_value[70], 205);

    assign(test_msg_.amplitude_value[71], 221);

    assign(test_msg_.amplitude_value[72], 5);

    assign(test_msg_.amplitude_value[73], 224);

    assign(test_msg_.amplitude_value[74], 92);

    assign(test_msg_.amplitude_value[75], 82);

    assign(test_msg_.amplitude_value[76], 109);

    assign(test_msg_.amplitude_value[77], 223);

    assign(test_msg_.amplitude_value[78], 195);

    assign(test_msg_.amplitude_value[79], 233);

    assign(test_msg_.amplitude_value[80], 165);

    assign(test_msg_.amplitude_value[81], 1);

    assign(test_msg_.amplitude_value[82], 82);

    assign(test_msg_.amplitude_value[83], 141);

    assign(test_msg_.amplitude_value[84], 157);

    assign(test_msg_.amplitude_value[85], 177);

    assign(test_msg_.amplitude_value[86], 169);

    assign(test_msg_.amplitude_value[87], 244);

    assign(test_msg_.amplitude_value[88], 131);

    assign(test_msg_.amplitude_value[89], 96);

    assign(test_msg_.amplitude_value[90], 109);

    assign(test_msg_.amplitude_value[91], 111);

    assign(test_msg_.amplitude_value[92], 253);

    assign(test_msg_.amplitude_value[93], 149);

    assign(test_msg_.amplitude_value[94], 28);

    assign(test_msg_.amplitude_value[95], 225);

    assign(test_msg_.amplitude_value[96], 225);

    assign(test_msg_.amplitude_value[97], 72);

    assign(test_msg_.amplitude_value[98], 158);

    assign(test_msg_.amplitude_value[99], 158);

    assign(test_msg_.amplitude_value[100], 210);

    assign(test_msg_.amplitude_value[101], 196);

    assign(test_msg_.amplitude_value[102], 206);

    assign(test_msg_.amplitude_value[103], 70);

    assign(test_msg_.amplitude_value[104], 63);

    assign(test_msg_.amplitude_value[105], 225);

    assign(test_msg_.amplitude_value[106], 184);

    assign(test_msg_.amplitude_value[107], 150);

    assign(test_msg_.amplitude_value[108], 174);

    assign(test_msg_.amplitude_value[109], 240);

    assign(test_msg_.amplitude_value[110], 45);

    assign(test_msg_.amplitude_value[111], 146);

    assign(test_msg_.amplitude_value[112], 59);

    assign(test_msg_.amplitude_value[113], 82);

    assign(test_msg_.amplitude_value[114], 194);

    assign(test_msg_.amplitude_value[115], 4);

    assign(test_msg_.amplitude_value[116], 179);

    assign(test_msg_.amplitude_value[117], 148);

    assign(test_msg_.amplitude_value[118], 66);

    assign(test_msg_.amplitude_value[119], 254);

    assign(test_msg_.amplitude_value[120], 115);

    assign(test_msg_.amplitude_value[121], 77);

    assign(test_msg_.amplitude_value[122], 30);

    assign(test_msg_.amplitude_value[123], 46);

    assign(test_msg_.amplitude_value[124], 4);

    assign(test_msg_.amplitude_value[125], 204);

    assign(test_msg_.amplitude_value[126], 37);

    assign(test_msg_.amplitude_value[127], 200);

    assign(test_msg_.amplitude_value[128], 121);

    assign(test_msg_.amplitude_value[129], 18);

    assign(test_msg_.amplitude_value[130], 17);

    assign(test_msg_.amplitude_value[131], 171);

    assign(test_msg_.amplitude_value[132], 102);

    assign(test_msg_.amplitude_value[133], 163);

    assign(test_msg_.amplitude_value[134], 175);

    assign(test_msg_.amplitude_value[135], 50);

    assign(test_msg_.amplitude_value[136], 66);

    assign(test_msg_.amplitude_value[137], 101);

    assign(test_msg_.amplitude_value[138], 69);

    assign(test_msg_.amplitude_value[139], 13);

    assign(test_msg_.amplitude_value[140], 223);

    assign(test_msg_.amplitude_value[141], 172);

    assign(test_msg_.amplitude_value[142], 160);

    assign(test_msg_.amplitude_value[143], 233);

    assign(test_msg_.amplitude_value[144], 220);

    assign(test_msg_.amplitude_value[145], 101);

    assign(test_msg_.amplitude_value[146], 237);

    assign(test_msg_.amplitude_value[147], 156);

    assign(test_msg_.amplitude_value[148], 62);

    assign(test_msg_.amplitude_value[149], 117);

    assign(test_msg_.amplitude_value[150], 47);

    assign(test_msg_.amplitude_value[151], 143);

    assign(test_msg_.amplitude_value[152], 94);

    assign(test_msg_.amplitude_value[153], 135);

    assign(test_msg_.amplitude_value[154], 22);

    assign(test_msg_.amplitude_value[155], 155);

    assign(test_msg_.amplitude_value[156], 113);

    assign(test_msg_.amplitude_value[157], 110);

    assign(test_msg_.amplitude_value[158], 15);

    assign(test_msg_.amplitude_value[159], 243);

    assign(test_msg_.amplitude_value[160], 141);

    assign(test_msg_.amplitude_value[161], 227);

    assign(test_msg_.amplitude_value[162], 46);

    assign(test_msg_.amplitude_value[163], 143);

    assign(test_msg_.amplitude_value[164], 227);

    assign(test_msg_.amplitude_value[165], 209);

    assign(test_msg_.amplitude_value[166], 249);

    assign(test_msg_.amplitude_value[167], 2);

    assign(test_msg_.amplitude_value[168], 153);

    assign(test_msg_.amplitude_value[169], 168);

    assign(test_msg_.amplitude_value[170], 131);

    assign(test_msg_.amplitude_value[171], 249);

    assign(test_msg_.amplitude_value[172], 160);

    assign(test_msg_.amplitude_value[173], 88);

    assign(test_msg_.amplitude_value[174], 38);

    assign(test_msg_.amplitude_value[175], 117);

    assign(test_msg_.amplitude_value[176], 129);

    assign(test_msg_.amplitude_value[177], 57);

    assign(test_msg_.amplitude_value[178], 40);

    assign(test_msg_.amplitude_value[179], 109);

    assign(test_msg_.amplitude_value[180], 209);

    assign(test_msg_.amplitude_value[181], 177);

    assign(test_msg_.amplitude_value[182], 38);

    assign(test_msg_.amplitude_value[183], 47);

    assign(test_msg_.amplitude_value[184], 12);

    assign(test_msg_.amplitude_value[185], 15);

    assign(test_msg_.amplitude_value[186], 16);

    assign(test_msg_.amplitude_value[187], 9);

    assign(test_msg_.amplitude_value[188], 175);

    assign(test_msg_.amplitude_value[189], 69);

    assign(test_msg_.amplitude_value[190], 70);

    assign(test_msg_.amplitude_value[191], 182);

    assign(test_msg_.amplitude_value[192], 239);

    assign(test_msg_.amplitude_value[193], 117);

    assign(test_msg_.amplitude_value[194], 135);

    assign(test_msg_.amplitude_value[195], 6);

    assign(test_msg_.amplitude_value[196], 71);

    assign(test_msg_.amplitude_value[197], 99);

    assign(test_msg_.amplitude_value[198], 230);

    assign(test_msg_.amplitude_value[199], 115);

    assign(test_msg_.amplitude_value[200], 2);

    assign(test_msg_.amplitude_value[201], 71);

    assign(test_msg_.amplitude_value[202], 165);

    assign(test_msg_.amplitude_value[203], 228);

    assign(test_msg_.amplitude_value[204], 123);

    assign(test_msg_.amplitude_value[205], 210);

    assign(test_msg_.amplitude_value[206], 168);

    assign(test_msg_.amplitude_value[207], 90);

    assign(test_msg_.amplitude_value[208], 124);

    assign(test_msg_.amplitude_value[209], 20);

    assign(test_msg_.amplitude_value[210], 7);

    assign(test_msg_.amplitude_value[211], 220);

    assign(test_msg_.amplitude_value[212], 144);

    assign(test_msg_.amplitude_value[213], 168);

    assign(test_msg_.amplitude_value[214], 69);

    assign(test_msg_.amplitude_value[215], 22);

    assign(test_msg_.amplitude_value[216], 72);

    assign(test_msg_.amplitude_value[217], 162);

    assign(test_msg_.amplitude_value[218], 69);

    assign(test_msg_.amplitude_value[219], 111);

    assign(test_msg_.amplitude_value[220], 91);

    assign(test_msg_.amplitude_value[221], 251);

    assign(test_msg_.amplitude_value[222], 72);

    assign(test_msg_.amplitude_value[223], 220);

    assign(test_msg_.amplitude_value[224], 28);

    assign(test_msg_.amplitude_value[225], 119);

    assign(test_msg_.amplitude_value[226], 150);
    assign(test_msg_.channel_tag, 35146);
    assign(test_msg_.freq_ref, 7737.2001953125);
    assign(test_msg_.freq_step, 8226.2001953125);
    assign(test_msg_.n_amplitude_value, 227);
    assign(test_msg_.t.ns_residual, -1479025396);
    assign(test_msg_.t.tow, 1227027783);
    assign(test_msg_.t.wn, 5075);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_specan_t> {
    using sbp::MessageHandler<sbp_msg_specan_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_specan_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_specan_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgSpecan, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_specan_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgSpecan);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->specan, sizeof(msg->specan));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_specan_t test_msg;
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
    memcpy(&info.test_msg_wrapped.specan, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgSpecan);
    info.sender_id = 54300;
    info.preamble = 0x55;
    info.crc = 0x025f;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 255;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_specan_t &lesser,
                        const sbp_msg_specan_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_specan_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_specan_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_specan_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_specan_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_specan_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_specan_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgSpecan, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgSpecan, &wrapped_greater, &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgSpecan, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgSpecan, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_specan_t test_msg_{};
  uint8_t encoded_frame_[255 + 8] = {
      85,  81,  0,   28,  212, 255, 74,  137, 71,  245, 34,  73,  12,  221, 215,
      167, 211, 19,  154, 201, 241, 69,  205, 136, 0,   70,  51,  67,  108, 69,
      102, 38,  166, 68,  100, 179, 185, 17,  175, 49,  193, 228, 228, 47,  33,
      24,  141, 177, 18,  99,  246, 121, 61,  40,  91,  145, 223, 167, 174, 9,
      116, 11,  247, 84,  49,  153, 205, 2,   230, 194, 218, 241, 101, 107, 45,
      137, 93,  114, 230, 43,  224, 23,  74,  209, 199, 211, 130, 89,  220, 163,
      68,  20,  253, 7,   206, 50,  129, 116, 194, 23,  31,  226, 217, 157, 205,
      221, 5,   224, 92,  82,  109, 223, 195, 233, 165, 1,   82,  141, 157, 177,
      169, 244, 131, 96,  109, 111, 253, 149, 28,  225, 225, 72,  158, 158, 210,
      196, 206, 70,  63,  225, 184, 150, 174, 240, 45,  146, 59,  82,  194, 4,
      179, 148, 66,  254, 115, 77,  30,  46,  4,   204, 37,  200, 121, 18,  17,
      171, 102, 163, 175, 50,  66,  101, 69,  13,  223, 172, 160, 233, 220, 101,
      237, 156, 62,  117, 47,  143, 94,  135, 22,  155, 113, 110, 15,  243, 141,
      227, 46,  143, 227, 209, 249, 2,   153, 168, 131, 249, 160, 88,  38,  117,
      129, 57,  40,  109, 209, 177, 38,  47,  12,  15,  16,  9,   175, 69,  70,
      182, 239, 117, 135, 6,   71,  99,  230, 115, 2,   71,  165, 228, 123, 210,
      168, 90,  124, 20,  7,   220, 144, 168, 69,  22,  72,  162, 69,  111, 91,
      251, 72,  220, 28,  119, 150, 95,  2,
  };
  uint8_t encoded_payload_[255] = {
      74,  137, 71,  245, 34,  73,  12,  221, 215, 167, 211, 19,  154, 201, 241,
      69,  205, 136, 0,   70,  51,  67,  108, 69,  102, 38,  166, 68,  100, 179,
      185, 17,  175, 49,  193, 228, 228, 47,  33,  24,  141, 177, 18,  99,  246,
      121, 61,  40,  91,  145, 223, 167, 174, 9,   116, 11,  247, 84,  49,  153,
      205, 2,   230, 194, 218, 241, 101, 107, 45,  137, 93,  114, 230, 43,  224,
      23,  74,  209, 199, 211, 130, 89,  220, 163, 68,  20,  253, 7,   206, 50,
      129, 116, 194, 23,  31,  226, 217, 157, 205, 221, 5,   224, 92,  82,  109,
      223, 195, 233, 165, 1,   82,  141, 157, 177, 169, 244, 131, 96,  109, 111,
      253, 149, 28,  225, 225, 72,  158, 158, 210, 196, 206, 70,  63,  225, 184,
      150, 174, 240, 45,  146, 59,  82,  194, 4,   179, 148, 66,  254, 115, 77,
      30,  46,  4,   204, 37,  200, 121, 18,  17,  171, 102, 163, 175, 50,  66,
      101, 69,  13,  223, 172, 160, 233, 220, 101, 237, 156, 62,  117, 47,  143,
      94,  135, 22,  155, 113, 110, 15,  243, 141, 227, 46,  143, 227, 209, 249,
      2,   153, 168, 131, 249, 160, 88,  38,  117, 129, 57,  40,  109, 209, 177,
      38,  47,  12,  15,  16,  9,   175, 69,  70,  182, 239, 117, 135, 6,   71,
      99,  230, 115, 2,   71,  165, 228, 123, 210, 168, 90,  124, 20,  7,   220,
      144, 168, 69,  22,  72,  162, 69,  111, 91,  251, 72,  220, 28,  119, 150,
  };
};

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_specan_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgSpecan, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[255];
  uint8_t n_written;

  EXPECT_EQ(
      sbp_msg_specan_encode(&buf[0], sizeof(buf), &n_written, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgSpecan,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[255];

  EXPECT_EQ(
      sbp_msg_specan_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}
TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[255];

  for (uint8_t i = 0; i < 255; i++) {
    EXPECT_EQ(sbp_msg_specan_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_specan_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_specan_decode(&info.encoded_payload[0], info.payload_len,
                                  &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgSpecan, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_specan_t msg{};

  EXPECT_EQ(sbp_msg_specan_decode(&info.encoded_payload[0], info.payload_len,
                                  nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_specan_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_specan_t t{};
      return sbp_msg_specan_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_specan_t t{};
      t.n_amplitude_value = 1;
      return sbp_msg_specan_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_specan_decode(&info.encoded_payload[0], i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, ReceiveThroughSbpStateUnderflow) {
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

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, SlowRead) {
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

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, BadCRC) {
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

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_specan_send(&state, info.sender_id, &info.test_msg,
                                &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSpecan, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgSpecan, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSpecan, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_ref, greater.amplitude_ref);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_unit, greater.amplitude_unit);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[0], greater.amplitude_value[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[1], greater.amplitude_value[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[2], greater.amplitude_value[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[3], greater.amplitude_value[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[4], greater.amplitude_value[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[5], greater.amplitude_value[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[6], greater.amplitude_value[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[7], greater.amplitude_value[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[8], greater.amplitude_value[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[9], greater.amplitude_value[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[10],
                        greater.amplitude_value[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[11],
                        greater.amplitude_value[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[12],
                        greater.amplitude_value[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[13],
                        greater.amplitude_value[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[14],
                        greater.amplitude_value[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[15],
                        greater.amplitude_value[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[16],
                        greater.amplitude_value[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[17],
                        greater.amplitude_value[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[18],
                        greater.amplitude_value[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[19],
                        greater.amplitude_value[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[20],
                        greater.amplitude_value[20]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[21],
                        greater.amplitude_value[21]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[22],
                        greater.amplitude_value[22]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[23],
                        greater.amplitude_value[23]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[24],
                        greater.amplitude_value[24]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[25],
                        greater.amplitude_value[25]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[26],
                        greater.amplitude_value[26]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[27],
                        greater.amplitude_value[27]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[28],
                        greater.amplitude_value[28]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[29],
                        greater.amplitude_value[29]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[30],
                        greater.amplitude_value[30]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[31],
                        greater.amplitude_value[31]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[32],
                        greater.amplitude_value[32]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[33],
                        greater.amplitude_value[33]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[34],
                        greater.amplitude_value[34]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[35],
                        greater.amplitude_value[35]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[36],
                        greater.amplitude_value[36]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[37],
                        greater.amplitude_value[37]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[38],
                        greater.amplitude_value[38]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[39],
                        greater.amplitude_value[39]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[40],
                        greater.amplitude_value[40]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[41],
                        greater.amplitude_value[41]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[42],
                        greater.amplitude_value[42]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[43],
                        greater.amplitude_value[43]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[44],
                        greater.amplitude_value[44]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[45],
                        greater.amplitude_value[45]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[46],
                        greater.amplitude_value[46]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[47],
                        greater.amplitude_value[47]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[48],
                        greater.amplitude_value[48]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[49],
                        greater.amplitude_value[49]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[50],
                        greater.amplitude_value[50]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[51],
                        greater.amplitude_value[51]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[52],
                        greater.amplitude_value[52]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[53],
                        greater.amplitude_value[53]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[54],
                        greater.amplitude_value[54]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[55],
                        greater.amplitude_value[55]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[56],
                        greater.amplitude_value[56]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[57],
                        greater.amplitude_value[57]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[58],
                        greater.amplitude_value[58]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[59],
                        greater.amplitude_value[59]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[60],
                        greater.amplitude_value[60]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[61],
                        greater.amplitude_value[61]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[62],
                        greater.amplitude_value[62]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[63],
                        greater.amplitude_value[63]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[64],
                        greater.amplitude_value[64]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[65],
                        greater.amplitude_value[65]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[66],
                        greater.amplitude_value[66]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[67],
                        greater.amplitude_value[67]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[68],
                        greater.amplitude_value[68]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[69],
                        greater.amplitude_value[69]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[70],
                        greater.amplitude_value[70]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[71],
                        greater.amplitude_value[71]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[72],
                        greater.amplitude_value[72]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[73],
                        greater.amplitude_value[73]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[74],
                        greater.amplitude_value[74]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[75],
                        greater.amplitude_value[75]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[76],
                        greater.amplitude_value[76]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[77],
                        greater.amplitude_value[77]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[78],
                        greater.amplitude_value[78]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[79],
                        greater.amplitude_value[79]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[80],
                        greater.amplitude_value[80]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[81],
                        greater.amplitude_value[81]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[82],
                        greater.amplitude_value[82]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[83],
                        greater.amplitude_value[83]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[84],
                        greater.amplitude_value[84]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[85],
                        greater.amplitude_value[85]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[86],
                        greater.amplitude_value[86]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[87],
                        greater.amplitude_value[87]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[88],
                        greater.amplitude_value[88]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[89],
                        greater.amplitude_value[89]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[90],
                        greater.amplitude_value[90]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[91],
                        greater.amplitude_value[91]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[92],
                        greater.amplitude_value[92]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[93],
                        greater.amplitude_value[93]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[94],
                        greater.amplitude_value[94]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[95],
                        greater.amplitude_value[95]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[96],
                        greater.amplitude_value[96]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[97],
                        greater.amplitude_value[97]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[98],
                        greater.amplitude_value[98]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[99],
                        greater.amplitude_value[99]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[100],
                        greater.amplitude_value[100]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[101],
                        greater.amplitude_value[101]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[102],
                        greater.amplitude_value[102]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[103],
                        greater.amplitude_value[103]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[104],
                        greater.amplitude_value[104]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[105],
                        greater.amplitude_value[105]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[106],
                        greater.amplitude_value[106]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[107],
                        greater.amplitude_value[107]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[108],
                        greater.amplitude_value[108]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[109],
                        greater.amplitude_value[109]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[110],
                        greater.amplitude_value[110]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[111],
                        greater.amplitude_value[111]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[112],
                        greater.amplitude_value[112]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[113],
                        greater.amplitude_value[113]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[114],
                        greater.amplitude_value[114]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[115],
                        greater.amplitude_value[115]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[116],
                        greater.amplitude_value[116]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[117],
                        greater.amplitude_value[117]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[118],
                        greater.amplitude_value[118]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[119],
                        greater.amplitude_value[119]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[120],
                        greater.amplitude_value[120]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[121],
                        greater.amplitude_value[121]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[122],
                        greater.amplitude_value[122]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[123],
                        greater.amplitude_value[123]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[124],
                        greater.amplitude_value[124]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[125],
                        greater.amplitude_value[125]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[126],
                        greater.amplitude_value[126]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[127],
                        greater.amplitude_value[127]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[128],
                        greater.amplitude_value[128]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[129],
                        greater.amplitude_value[129]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[130],
                        greater.amplitude_value[130]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[131],
                        greater.amplitude_value[131]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[132],
                        greater.amplitude_value[132]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[133],
                        greater.amplitude_value[133]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[134],
                        greater.amplitude_value[134]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[135],
                        greater.amplitude_value[135]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[136],
                        greater.amplitude_value[136]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[137],
                        greater.amplitude_value[137]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[138],
                        greater.amplitude_value[138]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[139],
                        greater.amplitude_value[139]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[140],
                        greater.amplitude_value[140]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[141],
                        greater.amplitude_value[141]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[142],
                        greater.amplitude_value[142]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[143],
                        greater.amplitude_value[143]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[144],
                        greater.amplitude_value[144]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[145],
                        greater.amplitude_value[145]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[146],
                        greater.amplitude_value[146]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[147],
                        greater.amplitude_value[147]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[148],
                        greater.amplitude_value[148]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[149],
                        greater.amplitude_value[149]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[150],
                        greater.amplitude_value[150]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[151],
                        greater.amplitude_value[151]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[152],
                        greater.amplitude_value[152]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[153],
                        greater.amplitude_value[153]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[154],
                        greater.amplitude_value[154]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[155],
                        greater.amplitude_value[155]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[156],
                        greater.amplitude_value[156]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[157],
                        greater.amplitude_value[157]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[158],
                        greater.amplitude_value[158]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[159],
                        greater.amplitude_value[159]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[160],
                        greater.amplitude_value[160]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[161],
                        greater.amplitude_value[161]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[162],
                        greater.amplitude_value[162]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[163],
                        greater.amplitude_value[163]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[164],
                        greater.amplitude_value[164]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[165],
                        greater.amplitude_value[165]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[166],
                        greater.amplitude_value[166]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[167],
                        greater.amplitude_value[167]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[168],
                        greater.amplitude_value[168]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[169],
                        greater.amplitude_value[169]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[170],
                        greater.amplitude_value[170]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[171],
                        greater.amplitude_value[171]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[172],
                        greater.amplitude_value[172]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[173],
                        greater.amplitude_value[173]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[174],
                        greater.amplitude_value[174]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[175],
                        greater.amplitude_value[175]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[176],
                        greater.amplitude_value[176]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[177],
                        greater.amplitude_value[177]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[178],
                        greater.amplitude_value[178]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[179],
                        greater.amplitude_value[179]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[180],
                        greater.amplitude_value[180]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[181],
                        greater.amplitude_value[181]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[182],
                        greater.amplitude_value[182]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[183],
                        greater.amplitude_value[183]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[184],
                        greater.amplitude_value[184]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[185],
                        greater.amplitude_value[185]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[186],
                        greater.amplitude_value[186]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[187],
                        greater.amplitude_value[187]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[188],
                        greater.amplitude_value[188]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[189],
                        greater.amplitude_value[189]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[190],
                        greater.amplitude_value[190]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[191],
                        greater.amplitude_value[191]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[192],
                        greater.amplitude_value[192]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[193],
                        greater.amplitude_value[193]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[194],
                        greater.amplitude_value[194]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[195],
                        greater.amplitude_value[195]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[196],
                        greater.amplitude_value[196]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[197],
                        greater.amplitude_value[197]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[198],
                        greater.amplitude_value[198]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[199],
                        greater.amplitude_value[199]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[200],
                        greater.amplitude_value[200]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[201],
                        greater.amplitude_value[201]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[202],
                        greater.amplitude_value[202]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[203],
                        greater.amplitude_value[203]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[204],
                        greater.amplitude_value[204]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[205],
                        greater.amplitude_value[205]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[206],
                        greater.amplitude_value[206]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[207],
                        greater.amplitude_value[207]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[208],
                        greater.amplitude_value[208]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[209],
                        greater.amplitude_value[209]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[210],
                        greater.amplitude_value[210]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[211],
                        greater.amplitude_value[211]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[212],
                        greater.amplitude_value[212]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[213],
                        greater.amplitude_value[213]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[214],
                        greater.amplitude_value[214]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[215],
                        greater.amplitude_value[215]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[216],
                        greater.amplitude_value[216]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[217],
                        greater.amplitude_value[217]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[218],
                        greater.amplitude_value[218]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[219],
                        greater.amplitude_value[219]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[220],
                        greater.amplitude_value[220]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[221],
                        greater.amplitude_value[221]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[222],
                        greater.amplitude_value[222]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[223],
                        greater.amplitude_value[223]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[224],
                        greater.amplitude_value[224]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[225],
                        greater.amplitude_value[225]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.amplitude_value[226],
                        greater.amplitude_value[226]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.channel_tag, greater.channel_tag);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.freq_ref, greater.freq_ref);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.freq_step, greater.freq_step);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.n_amplitude_value, greater.n_amplitude_value);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.t.ns_residual, greater.t.ns_residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.t.tow, greater.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_specan_t lesser = info.test_msg;
    sbp_msg_specan_t greater = info.test_msg;
    make_lesser_greater(lesser.t.wn, greater.t.wn);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_specan_t>::id, SbpMsgSpecan);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_specan_t>::name, "MSG_SPECAN");
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_specan_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_specan_t>::get(const_sbp_msg_t);
  sbp_msg_specan_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_specan_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_specan_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.specan, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_specan_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.specan, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_specan_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_specan_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[255];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_specan_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_specan_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_specan_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgSpecan, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgSpecan0, SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgSpecan, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace