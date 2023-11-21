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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaCertificate.yaml by
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
class Testauto_check_sbp_signing_MsgEcdsaCertificate0 : public ::testing::Test {
 public:
  Testauto_check_sbp_signing_MsgEcdsaCertificate0() {
    assign(test_msg_.certificate_bytes[0], 180);

    assign(test_msg_.certificate_bytes[1], 160);

    assign(test_msg_.certificate_bytes[2], 116);

    assign(test_msg_.certificate_bytes[3], 77);

    assign(test_msg_.certificate_bytes[4], 243);

    assign(test_msg_.certificate_bytes[5], 28);

    assign(test_msg_.certificate_bytes[6], 173);

    assign(test_msg_.certificate_bytes[7], 36);

    assign(test_msg_.certificate_bytes[8], 86);

    assign(test_msg_.certificate_bytes[9], 33);

    assign(test_msg_.certificate_bytes[10], 8);

    assign(test_msg_.certificate_bytes[11], 31);

    assign(test_msg_.certificate_bytes[12], 120);

    assign(test_msg_.certificate_bytes[13], 73);

    assign(test_msg_.certificate_bytes[14], 64);

    assign(test_msg_.certificate_bytes[15], 169);

    assign(test_msg_.certificate_bytes[16], 148);

    assign(test_msg_.certificate_bytes[17], 224);

    assign(test_msg_.certificate_bytes[18], 57);

    assign(test_msg_.certificate_bytes[19], 95);

    assign(test_msg_.certificate_bytes[20], 17);

    assign(test_msg_.certificate_bytes[21], 40);

    assign(test_msg_.certificate_bytes[22], 213);

    assign(test_msg_.certificate_bytes[23], 92);

    assign(test_msg_.certificate_bytes[24], 195);

    assign(test_msg_.certificate_bytes[25], 146);

    assign(test_msg_.certificate_bytes[26], 235);

    assign(test_msg_.certificate_bytes[27], 228);

    assign(test_msg_.certificate_bytes[28], 177);

    assign(test_msg_.certificate_bytes[29], 101);

    assign(test_msg_.certificate_bytes[30], 82);

    assign(test_msg_.certificate_bytes[31], 182);

    assign(test_msg_.certificate_bytes[32], 25);

    assign(test_msg_.certificate_bytes[33], 172);

    assign(test_msg_.certificate_bytes[34], 170);

    assign(test_msg_.certificate_bytes[35], 250);

    assign(test_msg_.certificate_bytes[36], 236);

    assign(test_msg_.certificate_bytes[37], 7);

    assign(test_msg_.certificate_bytes[38], 119);

    assign(test_msg_.certificate_bytes[39], 4);

    assign(test_msg_.certificate_bytes[40], 201);

    assign(test_msg_.certificate_bytes[41], 10);

    assign(test_msg_.certificate_bytes[42], 14);

    assign(test_msg_.certificate_bytes[43], 208);

    assign(test_msg_.certificate_bytes[44], 47);

    assign(test_msg_.certificate_bytes[45], 126);

    assign(test_msg_.certificate_bytes[46], 49);

    assign(test_msg_.certificate_bytes[47], 210);

    assign(test_msg_.certificate_bytes[48], 174);

    assign(test_msg_.certificate_bytes[49], 75);

    assign(test_msg_.certificate_bytes[50], 221);

    assign(test_msg_.certificate_bytes[51], 203);

    assign(test_msg_.certificate_bytes[52], 24);

    assign(test_msg_.certificate_bytes[53], 66);

    assign(test_msg_.certificate_bytes[54], 52);

    assign(test_msg_.certificate_bytes[55], 35);

    assign(test_msg_.certificate_bytes[56], 26);

    assign(test_msg_.certificate_bytes[57], 30);

    assign(test_msg_.certificate_bytes[58], 140);

    assign(test_msg_.certificate_bytes[59], 111);

    assign(test_msg_.certificate_bytes[60], 246);

    assign(test_msg_.certificate_bytes[61], 39);

    assign(test_msg_.certificate_bytes[62], 226);

    assign(test_msg_.certificate_bytes[63], 205);

    assign(test_msg_.certificate_bytes[64], 198);

    assign(test_msg_.certificate_bytes[65], 178);

    assign(test_msg_.certificate_bytes[66], 196);

    assign(test_msg_.certificate_bytes[67], 5);

    assign(test_msg_.certificate_bytes[68], 81);

    assign(test_msg_.certificate_bytes[69], 9);

    assign(test_msg_.certificate_bytes[70], 44);

    assign(test_msg_.certificate_bytes[71], 164);

    assign(test_msg_.certificate_bytes[72], 163);

    assign(test_msg_.certificate_bytes[73], 214);

    assign(test_msg_.certificate_bytes[74], 138);

    assign(test_msg_.certificate_bytes[75], 123);

    assign(test_msg_.certificate_bytes[76], 76);

    assign(test_msg_.certificate_bytes[77], 74);

    assign(test_msg_.certificate_bytes[78], 237);

    assign(test_msg_.certificate_bytes[79], 121);

    assign(test_msg_.certificate_bytes[80], 13);

    assign(test_msg_.certificate_bytes[81], 137);

    assign(test_msg_.certificate_bytes[82], 186);

    assign(test_msg_.certificate_bytes[83], 97);

    assign(test_msg_.certificate_bytes[84], 193);

    assign(test_msg_.certificate_bytes[85], 189);

    assign(test_msg_.certificate_bytes[86], 200);

    assign(test_msg_.certificate_bytes[87], 124);

    assign(test_msg_.certificate_bytes[88], 69);

    assign(test_msg_.certificate_bytes[89], 115);

    assign(test_msg_.certificate_bytes[90], 230);

    assign(test_msg_.certificate_bytes[91], 159);

    assign(test_msg_.certificate_bytes[92], 185);

    assign(test_msg_.certificate_bytes[93], 158);

    assign(test_msg_.certificate_bytes[94], 51);

    assign(test_msg_.certificate_bytes[95], 12);

    assign(test_msg_.certificate_bytes[96], 225);

    assign(test_msg_.certificate_bytes[97], 65);

    assign(test_msg_.certificate_bytes[98], 192);

    assign(test_msg_.certificate_bytes[99], 105);

    assign(test_msg_.certificate_bytes[100], 56);

    assign(test_msg_.certificate_bytes[101], 41);

    assign(test_msg_.certificate_bytes[102], 85);

    assign(test_msg_.certificate_bytes[103], 133);

    assign(test_msg_.certificate_bytes[104], 19);

    assign(test_msg_.certificate_bytes[105], 217);

    assign(test_msg_.certificate_bytes[106], 166);

    assign(test_msg_.certificate_bytes[107], 48);

    assign(test_msg_.certificate_bytes[108], 139);

    assign(test_msg_.certificate_bytes[109], 131);

    assign(test_msg_.certificate_bytes[110], 96);

    assign(test_msg_.certificate_bytes[111], 216);

    assign(test_msg_.certificate_bytes[112], 98);

    assign(test_msg_.certificate_bytes[113], 147);

    assign(test_msg_.certificate_bytes[114], 132);

    assign(test_msg_.certificate_bytes[115], 234);

    assign(test_msg_.certificate_bytes[116], 167);

    assign(test_msg_.certificate_bytes[117], 248);

    assign(test_msg_.certificate_bytes[118], 247);

    assign(test_msg_.certificate_bytes[119], 32);

    assign(test_msg_.certificate_bytes[120], 239);

    assign(test_msg_.certificate_bytes[121], 194);

    assign(test_msg_.certificate_bytes[122], 188);

    assign(test_msg_.certificate_bytes[123], 254);

    assign(test_msg_.certificate_bytes[124], 114);

    assign(test_msg_.certificate_bytes[125], 117);

    assign(test_msg_.certificate_bytes[126], 83);

    assign(test_msg_.certificate_bytes[127], 25);

    assign(test_msg_.certificate_bytes[128], 251);

    assign(test_msg_.certificate_bytes[129], 191);

    assign(test_msg_.certificate_bytes[130], 104);

    assign(test_msg_.certificate_bytes[131], 240);

    assign(test_msg_.certificate_bytes[132], 118);

    assign(test_msg_.certificate_bytes[133], 68);

    assign(test_msg_.certificate_bytes[134], 42);

    assign(test_msg_.certificate_bytes[135], 93);

    assign(test_msg_.certificate_bytes[136], 18);

    assign(test_msg_.certificate_bytes[137], 16);

    assign(test_msg_.certificate_bytes[138], 37);

    assign(test_msg_.certificate_bytes[139], 232);

    assign(test_msg_.certificate_bytes[140], 99);

    assign(test_msg_.certificate_bytes[141], 179);

    assign(test_msg_.certificate_bytes[142], 23);

    assign(test_msg_.certificate_bytes[143], 90);

    assign(test_msg_.certificate_bytes[144], 94);

    assign(test_msg_.certificate_bytes[145], 136);

    assign(test_msg_.certificate_bytes[146], 6);

    assign(test_msg_.certificate_bytes[147], 125);

    assign(test_msg_.certificate_bytes[148], 91);

    assign(test_msg_.certificate_bytes[149], 255);

    assign(test_msg_.certificate_bytes[150], 15);

    assign(test_msg_.certificate_bytes[151], 71);

    assign(test_msg_.certificate_bytes[152], 43);

    assign(test_msg_.certificate_bytes[153], 46);

    assign(test_msg_.certificate_bytes[154], 25);

    assign(test_msg_.certificate_bytes[155], 252);

    assign(test_msg_.certificate_bytes[156], 229);

    assign(test_msg_.certificate_bytes[157], 80);

    assign(test_msg_.certificate_bytes[158], 143);

    assign(test_msg_.certificate_bytes[159], 58);

    assign(test_msg_.certificate_bytes[160], 241);

    assign(test_msg_.certificate_bytes[161], 11);

    assign(test_msg_.certificate_bytes[162], 62);

    assign(test_msg_.certificate_bytes[163], 181);

    assign(test_msg_.certificate_bytes[164], 155);

    assign(test_msg_.certificate_bytes[165], 53);

    assign(test_msg_.certificate_bytes[166], 153);

    assign(test_msg_.certificate_bytes[167], 149);

    assign(test_msg_.certificate_bytes[168], 152);

    assign(test_msg_.certificate_bytes[169], 227);

    assign(test_msg_.certificate_bytes[170], 150);

    assign(test_msg_.certificate_bytes[171], 87);

    assign(test_msg_.certificate_bytes[172], 112);

    assign(test_msg_.certificate_bytes[173], 165);

    assign(test_msg_.certificate_bytes[174], 2);

    assign(test_msg_.certificate_bytes[175], 128);

    assign(test_msg_.certificate_bytes[176], 231);

    assign(test_msg_.certificate_bytes[177], 25);

    assign(test_msg_.certificate_bytes[178], 157);

    assign(test_msg_.certificate_bytes[179], 244);

    assign(test_msg_.certificate_bytes[180], 204);

    assign(test_msg_.certificate_bytes[181], 108);

    assign(test_msg_.certificate_bytes[182], 253);

    assign(test_msg_.certificate_bytes[183], 127);

    assign(test_msg_.certificate_bytes[184], 122);

    assign(test_msg_.certificate_bytes[185], 145);

    assign(test_msg_.certificate_bytes[186], 113);

    assign(test_msg_.certificate_bytes[187], 162);

    assign(test_msg_.certificate_bytes[188], 197);

    assign(test_msg_.certificate_bytes[189], 171);

    assign(test_msg_.certificate_bytes[190], 199);

    assign(test_msg_.certificate_bytes[191], 54);

    assign(test_msg_.certificate_bytes[192], 184);

    assign(test_msg_.certificate_bytes[193], 222);

    assign(test_msg_.certificate_bytes[194], 206);

    assign(test_msg_.certificate_bytes[195], 67);

    assign(test_msg_.certificate_bytes[196], 144);

    assign(test_msg_.certificate_bytes[197], 78);

    assign(test_msg_.certificate_bytes[198], 187);

    assign(test_msg_.certificate_bytes[199], 207);

    assign(test_msg_.certificate_bytes[200], 60);

    assign(test_msg_.certificate_bytes[201], 211);

    assign(test_msg_.certificate_bytes[202], 141);

    assign(test_msg_.certificate_bytes[203], 135);

    assign(test_msg_.certificate_bytes[204], 106);

    assign(test_msg_.certificate_bytes[205], 220);

    assign(test_msg_.certificate_bytes[206], 79);

    assign(test_msg_.certificate_bytes[207], 183);

    assign(test_msg_.certificate_bytes[208], 245);

    assign(test_msg_.certificate_bytes[209], 21);

    assign(test_msg_.certificate_bytes[210], 161);

    assign(test_msg_.certificate_bytes[211], 168);

    assign(test_msg_.certificate_bytes[212], 34);

    assign(test_msg_.certificate_bytes[213], 129);

    assign(test_msg_.certificate_bytes[214], 50);

    assign(test_msg_.certificate_bytes[215], 176);

    assign(test_msg_.certificate_bytes[216], 1);

    assign(test_msg_.certificate_bytes[217], 218);

    assign(test_msg_.certificate_bytes[218], 20);

    assign(test_msg_.certificate_bytes[219], 130);

    assign(test_msg_.certificate_bytes[220], 59);

    assign(test_msg_.certificate_bytes[221], 249);

    assign(test_msg_.certificate_bytes[222], 109);

    assign(test_msg_.certificate_bytes[223], 219);

    assign(test_msg_.certificate_bytes[224], 0);

    assign(test_msg_.certificate_bytes[225], 100);

    assign(test_msg_.certificate_bytes[226], 103);

    assign(test_msg_.certificate_bytes[227], 55);

    assign(test_msg_.certificate_bytes[228], 29);

    assign(test_msg_.certificate_bytes[229], 242);

    assign(test_msg_.certificate_bytes[230], 110);

    assign(test_msg_.certificate_bytes[231], 154);

    assign(test_msg_.certificate_bytes[232], 190);

    assign(test_msg_.certificate_bytes[233], 233);

    assign(test_msg_.certificate_bytes[234], 142);

    assign(test_msg_.certificate_bytes[235], 45);

    assign(test_msg_.certificate_bytes[236], 61);

    assign(test_msg_.certificate_bytes[237], 215);

    assign(test_msg_.certificate_bytes[238], 202);

    assign(test_msg_.certificate_bytes[239], 238);

    assign(test_msg_.certificate_bytes[240], 88);

    assign(test_msg_.certificate_bytes[241], 209);

    assign(test_msg_.certificate_bytes[242], 70);

    assign(test_msg_.certificate_bytes[243], 63);

    assign(test_msg_.certificate_bytes[244], 151);

    assign(test_msg_.certificate_bytes[245], 27);

    assign(test_msg_.certificate_bytes[246], 102);

    assign(test_msg_.certificate_id[0], 10);

    assign(test_msg_.certificate_id[1], 11);

    assign(test_msg_.certificate_id[2], 12);

    assign(test_msg_.certificate_id[3], 13);
    assign(test_msg_.flags, 2);
    assign(test_msg_.n_certificate_bytes, 247);
    assign(test_msg_.n_msg, 48);
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
      : public sbp::MessageHandler<sbp_msg_ecdsa_certificate_t> {
    using sbp::MessageHandler<sbp_msg_ecdsa_certificate_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ecdsa_certificate_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ecdsa_certificate_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgEcdsaCertificate,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ecdsa_certificate_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgEcdsaCertificate);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ecdsa_certificate,
             sizeof(msg->ecdsa_certificate));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ecdsa_certificate_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ecdsa_certificate, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgEcdsaCertificate);
    info.sender_id = 66;
    info.preamble = 0x55;
    info.crc = 0x1EDB;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 253;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ecdsa_certificate_t &lesser,
                        const sbp_msg_ecdsa_certificate_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ecdsa_certificate_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ecdsa_certificate_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_ecdsa_certificate_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ecdsa_certificate_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ecdsa_certificate_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ecdsa_certificate_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgEcdsaCertificate, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgEcdsaCertificate, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgEcdsaCertificate, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgEcdsaCertificate, &wrapped_greater,
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
  sbp_msg_ecdsa_certificate_t test_msg_{};
  uint8_t encoded_frame_[253 + 8] = {
      85,  4,   12,  66,  0,   253, 48,  10,  11,  12,  13,  2,   180, 160, 116,
      77,  243, 28,  173, 36,  86,  33,  8,   31,  120, 73,  64,  169, 148, 224,
      57,  95,  17,  40,  213, 92,  195, 146, 235, 228, 177, 101, 82,  182, 25,
      172, 170, 250, 236, 7,   119, 4,   201, 10,  14,  208, 47,  126, 49,  210,
      174, 75,  221, 203, 24,  66,  52,  35,  26,  30,  140, 111, 246, 39,  226,
      205, 198, 178, 196, 5,   81,  9,   44,  164, 163, 214, 138, 123, 76,  74,
      237, 121, 13,  137, 186, 97,  193, 189, 200, 124, 69,  115, 230, 159, 185,
      158, 51,  12,  225, 65,  192, 105, 56,  41,  85,  133, 19,  217, 166, 48,
      139, 131, 96,  216, 98,  147, 132, 234, 167, 248, 247, 32,  239, 194, 188,
      254, 114, 117, 83,  25,  251, 191, 104, 240, 118, 68,  42,  93,  18,  16,
      37,  232, 99,  179, 23,  90,  94,  136, 6,   125, 91,  255, 15,  71,  43,
      46,  25,  252, 229, 80,  143, 58,  241, 11,  62,  181, 155, 53,  153, 149,
      152, 227, 150, 87,  112, 165, 2,   128, 231, 25,  157, 244, 204, 108, 253,
      127, 122, 145, 113, 162, 197, 171, 199, 54,  184, 222, 206, 67,  144, 78,
      187, 207, 60,  211, 141, 135, 106, 220, 79,  183, 245, 21,  161, 168, 34,
      129, 50,  176, 1,   218, 20,  130, 59,  249, 109, 219, 0,   100, 103, 55,
      29,  242, 110, 154, 190, 233, 142, 45,  61,  215, 202, 238, 88,  209, 70,
      63,  151, 27,  102, 219, 30,
  };
  uint8_t encoded_payload_[253] = {
      48,  10,  11,  12,  13,  2,   180, 160, 116, 77,  243, 28,  173, 36,  86,
      33,  8,   31,  120, 73,  64,  169, 148, 224, 57,  95,  17,  40,  213, 92,
      195, 146, 235, 228, 177, 101, 82,  182, 25,  172, 170, 250, 236, 7,   119,
      4,   201, 10,  14,  208, 47,  126, 49,  210, 174, 75,  221, 203, 24,  66,
      52,  35,  26,  30,  140, 111, 246, 39,  226, 205, 198, 178, 196, 5,   81,
      9,   44,  164, 163, 214, 138, 123, 76,  74,  237, 121, 13,  137, 186, 97,
      193, 189, 200, 124, 69,  115, 230, 159, 185, 158, 51,  12,  225, 65,  192,
      105, 56,  41,  85,  133, 19,  217, 166, 48,  139, 131, 96,  216, 98,  147,
      132, 234, 167, 248, 247, 32,  239, 194, 188, 254, 114, 117, 83,  25,  251,
      191, 104, 240, 118, 68,  42,  93,  18,  16,  37,  232, 99,  179, 23,  90,
      94,  136, 6,   125, 91,  255, 15,  71,  43,  46,  25,  252, 229, 80,  143,
      58,  241, 11,  62,  181, 155, 53,  153, 149, 152, 227, 150, 87,  112, 165,
      2,   128, 231, 25,  157, 244, 204, 108, 253, 127, 122, 145, 113, 162, 197,
      171, 199, 54,  184, 222, 206, 67,  144, 78,  187, 207, 60,  211, 141, 135,
      106, 220, 79,  183, 245, 21,  161, 168, 34,  129, 50,  176, 1,   218, 20,
      130, 59,  249, 109, 219, 0,   100, 103, 55,  29,  242, 110, 154, 190, 233,
      142, 45,  61,  215, 202, 238, 88,  209, 70,  63,  151, 27,  102,
  };
};

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ecdsa_certificate_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgEcdsaCertificate, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[253];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ecdsa_certificate_encode(&buf[0], sizeof(buf), &n_written,
                                             &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 253);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 253), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgEcdsaCertificate, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 253);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 253), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[253];

  EXPECT_EQ(sbp_msg_ecdsa_certificate_encode(&buf[0], sizeof(buf), nullptr,
                                             &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 253), 0);
}
TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[253];

  for (uint8_t i = 0; i < 253; i++) {
    EXPECT_EQ(
        sbp_msg_ecdsa_certificate_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ecdsa_certificate_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ecdsa_certificate_decode(&info.encoded_payload[0],
                                             info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 253);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgEcdsaCertificate, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 253);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ecdsa_certificate_t msg{};

  EXPECT_EQ(sbp_msg_ecdsa_certificate_decode(&info.encoded_payload[0],
                                             info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ecdsa_certificate_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ecdsa_certificate_t t{};
      return sbp_msg_ecdsa_certificate_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ecdsa_certificate_t t{};
      t.n_certificate_bytes = 1;
      return sbp_msg_ecdsa_certificate_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ecdsa_certificate_decode(&info.encoded_payload[0], i,
                                               nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0,
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0,
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, SlowRead) {
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, BadCRC) {
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ecdsa_certificate_send(&state, info.sender_id,
                                           &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEcdsaCertificate, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgEcdsaCertificate, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEcdsaCertificate, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, Comparison) {
  auto info = get_test_msg_info();

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[0],
                        greater.certificate_bytes[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[1],
                        greater.certificate_bytes[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[2],
                        greater.certificate_bytes[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[3],
                        greater.certificate_bytes[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[4],
                        greater.certificate_bytes[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[5],
                        greater.certificate_bytes[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[6],
                        greater.certificate_bytes[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[7],
                        greater.certificate_bytes[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[8],
                        greater.certificate_bytes[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[9],
                        greater.certificate_bytes[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[10],
                        greater.certificate_bytes[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[11],
                        greater.certificate_bytes[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[12],
                        greater.certificate_bytes[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[13],
                        greater.certificate_bytes[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[14],
                        greater.certificate_bytes[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[15],
                        greater.certificate_bytes[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[16],
                        greater.certificate_bytes[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[17],
                        greater.certificate_bytes[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[18],
                        greater.certificate_bytes[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[19],
                        greater.certificate_bytes[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[20],
                        greater.certificate_bytes[20]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[21],
                        greater.certificate_bytes[21]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[22],
                        greater.certificate_bytes[22]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[23],
                        greater.certificate_bytes[23]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[24],
                        greater.certificate_bytes[24]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[25],
                        greater.certificate_bytes[25]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[26],
                        greater.certificate_bytes[26]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[27],
                        greater.certificate_bytes[27]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[28],
                        greater.certificate_bytes[28]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[29],
                        greater.certificate_bytes[29]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[30],
                        greater.certificate_bytes[30]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[31],
                        greater.certificate_bytes[31]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[32],
                        greater.certificate_bytes[32]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[33],
                        greater.certificate_bytes[33]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[34],
                        greater.certificate_bytes[34]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[35],
                        greater.certificate_bytes[35]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[36],
                        greater.certificate_bytes[36]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[37],
                        greater.certificate_bytes[37]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[38],
                        greater.certificate_bytes[38]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[39],
                        greater.certificate_bytes[39]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[40],
                        greater.certificate_bytes[40]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[41],
                        greater.certificate_bytes[41]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[42],
                        greater.certificate_bytes[42]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[43],
                        greater.certificate_bytes[43]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[44],
                        greater.certificate_bytes[44]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[45],
                        greater.certificate_bytes[45]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[46],
                        greater.certificate_bytes[46]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[47],
                        greater.certificate_bytes[47]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[48],
                        greater.certificate_bytes[48]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[49],
                        greater.certificate_bytes[49]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[50],
                        greater.certificate_bytes[50]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[51],
                        greater.certificate_bytes[51]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[52],
                        greater.certificate_bytes[52]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[53],
                        greater.certificate_bytes[53]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[54],
                        greater.certificate_bytes[54]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[55],
                        greater.certificate_bytes[55]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[56],
                        greater.certificate_bytes[56]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[57],
                        greater.certificate_bytes[57]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[58],
                        greater.certificate_bytes[58]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[59],
                        greater.certificate_bytes[59]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[60],
                        greater.certificate_bytes[60]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[61],
                        greater.certificate_bytes[61]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[62],
                        greater.certificate_bytes[62]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[63],
                        greater.certificate_bytes[63]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[64],
                        greater.certificate_bytes[64]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[65],
                        greater.certificate_bytes[65]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[66],
                        greater.certificate_bytes[66]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[67],
                        greater.certificate_bytes[67]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[68],
                        greater.certificate_bytes[68]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[69],
                        greater.certificate_bytes[69]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[70],
                        greater.certificate_bytes[70]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[71],
                        greater.certificate_bytes[71]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[72],
                        greater.certificate_bytes[72]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[73],
                        greater.certificate_bytes[73]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[74],
                        greater.certificate_bytes[74]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[75],
                        greater.certificate_bytes[75]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[76],
                        greater.certificate_bytes[76]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[77],
                        greater.certificate_bytes[77]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[78],
                        greater.certificate_bytes[78]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[79],
                        greater.certificate_bytes[79]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[80],
                        greater.certificate_bytes[80]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[81],
                        greater.certificate_bytes[81]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[82],
                        greater.certificate_bytes[82]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[83],
                        greater.certificate_bytes[83]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[84],
                        greater.certificate_bytes[84]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[85],
                        greater.certificate_bytes[85]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[86],
                        greater.certificate_bytes[86]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[87],
                        greater.certificate_bytes[87]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[88],
                        greater.certificate_bytes[88]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[89],
                        greater.certificate_bytes[89]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[90],
                        greater.certificate_bytes[90]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[91],
                        greater.certificate_bytes[91]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[92],
                        greater.certificate_bytes[92]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[93],
                        greater.certificate_bytes[93]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[94],
                        greater.certificate_bytes[94]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[95],
                        greater.certificate_bytes[95]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[96],
                        greater.certificate_bytes[96]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[97],
                        greater.certificate_bytes[97]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[98],
                        greater.certificate_bytes[98]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[99],
                        greater.certificate_bytes[99]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[100],
                        greater.certificate_bytes[100]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[101],
                        greater.certificate_bytes[101]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[102],
                        greater.certificate_bytes[102]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[103],
                        greater.certificate_bytes[103]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[104],
                        greater.certificate_bytes[104]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[105],
                        greater.certificate_bytes[105]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[106],
                        greater.certificate_bytes[106]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[107],
                        greater.certificate_bytes[107]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[108],
                        greater.certificate_bytes[108]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[109],
                        greater.certificate_bytes[109]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[110],
                        greater.certificate_bytes[110]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[111],
                        greater.certificate_bytes[111]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[112],
                        greater.certificate_bytes[112]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[113],
                        greater.certificate_bytes[113]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[114],
                        greater.certificate_bytes[114]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[115],
                        greater.certificate_bytes[115]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[116],
                        greater.certificate_bytes[116]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[117],
                        greater.certificate_bytes[117]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[118],
                        greater.certificate_bytes[118]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[119],
                        greater.certificate_bytes[119]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[120],
                        greater.certificate_bytes[120]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[121],
                        greater.certificate_bytes[121]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[122],
                        greater.certificate_bytes[122]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[123],
                        greater.certificate_bytes[123]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[124],
                        greater.certificate_bytes[124]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[125],
                        greater.certificate_bytes[125]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[126],
                        greater.certificate_bytes[126]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[127],
                        greater.certificate_bytes[127]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[128],
                        greater.certificate_bytes[128]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[129],
                        greater.certificate_bytes[129]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[130],
                        greater.certificate_bytes[130]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[131],
                        greater.certificate_bytes[131]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[132],
                        greater.certificate_bytes[132]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[133],
                        greater.certificate_bytes[133]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[134],
                        greater.certificate_bytes[134]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[135],
                        greater.certificate_bytes[135]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[136],
                        greater.certificate_bytes[136]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[137],
                        greater.certificate_bytes[137]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[138],
                        greater.certificate_bytes[138]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[139],
                        greater.certificate_bytes[139]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[140],
                        greater.certificate_bytes[140]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[141],
                        greater.certificate_bytes[141]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[142],
                        greater.certificate_bytes[142]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[143],
                        greater.certificate_bytes[143]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[144],
                        greater.certificate_bytes[144]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[145],
                        greater.certificate_bytes[145]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[146],
                        greater.certificate_bytes[146]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[147],
                        greater.certificate_bytes[147]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[148],
                        greater.certificate_bytes[148]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[149],
                        greater.certificate_bytes[149]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[150],
                        greater.certificate_bytes[150]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[151],
                        greater.certificate_bytes[151]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[152],
                        greater.certificate_bytes[152]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[153],
                        greater.certificate_bytes[153]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[154],
                        greater.certificate_bytes[154]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[155],
                        greater.certificate_bytes[155]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[156],
                        greater.certificate_bytes[156]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[157],
                        greater.certificate_bytes[157]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[158],
                        greater.certificate_bytes[158]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[159],
                        greater.certificate_bytes[159]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[160],
                        greater.certificate_bytes[160]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[161],
                        greater.certificate_bytes[161]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[162],
                        greater.certificate_bytes[162]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[163],
                        greater.certificate_bytes[163]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[164],
                        greater.certificate_bytes[164]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[165],
                        greater.certificate_bytes[165]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[166],
                        greater.certificate_bytes[166]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[167],
                        greater.certificate_bytes[167]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[168],
                        greater.certificate_bytes[168]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[169],
                        greater.certificate_bytes[169]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[170],
                        greater.certificate_bytes[170]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[171],
                        greater.certificate_bytes[171]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[172],
                        greater.certificate_bytes[172]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[173],
                        greater.certificate_bytes[173]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[174],
                        greater.certificate_bytes[174]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[175],
                        greater.certificate_bytes[175]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[176],
                        greater.certificate_bytes[176]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[177],
                        greater.certificate_bytes[177]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[178],
                        greater.certificate_bytes[178]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[179],
                        greater.certificate_bytes[179]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[180],
                        greater.certificate_bytes[180]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[181],
                        greater.certificate_bytes[181]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[182],
                        greater.certificate_bytes[182]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[183],
                        greater.certificate_bytes[183]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[184],
                        greater.certificate_bytes[184]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[185],
                        greater.certificate_bytes[185]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[186],
                        greater.certificate_bytes[186]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[187],
                        greater.certificate_bytes[187]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[188],
                        greater.certificate_bytes[188]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[189],
                        greater.certificate_bytes[189]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[190],
                        greater.certificate_bytes[190]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[191],
                        greater.certificate_bytes[191]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[192],
                        greater.certificate_bytes[192]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[193],
                        greater.certificate_bytes[193]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[194],
                        greater.certificate_bytes[194]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[195],
                        greater.certificate_bytes[195]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[196],
                        greater.certificate_bytes[196]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[197],
                        greater.certificate_bytes[197]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[198],
                        greater.certificate_bytes[198]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[199],
                        greater.certificate_bytes[199]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[200],
                        greater.certificate_bytes[200]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[201],
                        greater.certificate_bytes[201]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[202],
                        greater.certificate_bytes[202]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[203],
                        greater.certificate_bytes[203]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[204],
                        greater.certificate_bytes[204]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[205],
                        greater.certificate_bytes[205]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[206],
                        greater.certificate_bytes[206]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[207],
                        greater.certificate_bytes[207]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[208],
                        greater.certificate_bytes[208]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[209],
                        greater.certificate_bytes[209]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[210],
                        greater.certificate_bytes[210]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[211],
                        greater.certificate_bytes[211]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[212],
                        greater.certificate_bytes[212]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[213],
                        greater.certificate_bytes[213]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[214],
                        greater.certificate_bytes[214]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[215],
                        greater.certificate_bytes[215]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[216],
                        greater.certificate_bytes[216]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[217],
                        greater.certificate_bytes[217]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[218],
                        greater.certificate_bytes[218]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[219],
                        greater.certificate_bytes[219]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[220],
                        greater.certificate_bytes[220]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[221],
                        greater.certificate_bytes[221]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[222],
                        greater.certificate_bytes[222]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[223],
                        greater.certificate_bytes[223]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[224],
                        greater.certificate_bytes[224]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[225],
                        greater.certificate_bytes[225]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[226],
                        greater.certificate_bytes[226]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[227],
                        greater.certificate_bytes[227]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[228],
                        greater.certificate_bytes[228]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[229],
                        greater.certificate_bytes[229]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[230],
                        greater.certificate_bytes[230]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[231],
                        greater.certificate_bytes[231]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[232],
                        greater.certificate_bytes[232]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[233],
                        greater.certificate_bytes[233]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[234],
                        greater.certificate_bytes[234]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[235],
                        greater.certificate_bytes[235]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[236],
                        greater.certificate_bytes[236]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[237],
                        greater.certificate_bytes[237]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[238],
                        greater.certificate_bytes[238]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[239],
                        greater.certificate_bytes[239]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[240],
                        greater.certificate_bytes[240]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[241],
                        greater.certificate_bytes[241]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[242],
                        greater.certificate_bytes[242]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[243],
                        greater.certificate_bytes[243]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[244],
                        greater.certificate_bytes[244]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[245],
                        greater.certificate_bytes[245]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_bytes[246],
                        greater.certificate_bytes[246]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_id[0], greater.certificate_id[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_id[1], greater.certificate_id[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_id[2], greater.certificate_id[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_id[3], greater.certificate_id[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.n_certificate_bytes,
                        greater.n_certificate_bytes);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ecdsa_certificate_t lesser = info.test_msg;
    sbp_msg_ecdsa_certificate_t greater = info.test_msg;
    make_lesser_greater(lesser.n_msg, greater.n_msg);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_certificate_t>::id,
  // SbpMsgEcdsaCertificate);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ecdsa_certificate_t>::name,
               "MSG_ECDSA_CERTIFICATE");
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ecdsa_certificate_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ecdsa_certificate_t>::get(const_sbp_msg_t);
  sbp_msg_ecdsa_certificate_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ecdsa_certificate_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 = sbp::MessageTraits<sbp_msg_ecdsa_certificate_t>::to_sbp_msg(
      info.test_msg);
  EXPECT_EQ(msg1.ecdsa_certificate, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ecdsa_certificate_t>::to_sbp_msg(info.test_msg,
                                                              &msg2);
  EXPECT_EQ(msg2.ecdsa_certificate, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_certificate_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_certificate_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[253];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_certificate_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 253);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 253), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ecdsa_certificate_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_certificate_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 253);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0,
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgEcdsaCertificate,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaCertificate0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgEcdsaCertificate,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace