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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaSignatureDepA.yaml by
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
class Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0() {
    assign(test_msg_.certificate_id[0], 1);

    assign(test_msg_.certificate_id[1], 2);

    assign(test_msg_.certificate_id[2], 3);

    assign(test_msg_.certificate_id[3], 4);
    assign(test_msg_.flags, 0);
    assign(test_msg_.n_signed_messages, 184);
    assign(test_msg_.on_demand_counter, 2);

    assign(test_msg_.signature[0], 0);

    assign(test_msg_.signature[1], 1);

    assign(test_msg_.signature[2], 2);

    assign(test_msg_.signature[3], 3);

    assign(test_msg_.signature[4], 4);

    assign(test_msg_.signature[5], 5);

    assign(test_msg_.signature[6], 6);

    assign(test_msg_.signature[7], 7);

    assign(test_msg_.signature[8], 0);

    assign(test_msg_.signature[9], 1);

    assign(test_msg_.signature[10], 2);

    assign(test_msg_.signature[11], 3);

    assign(test_msg_.signature[12], 4);

    assign(test_msg_.signature[13], 5);

    assign(test_msg_.signature[14], 6);

    assign(test_msg_.signature[15], 7);

    assign(test_msg_.signature[16], 0);

    assign(test_msg_.signature[17], 1);

    assign(test_msg_.signature[18], 2);

    assign(test_msg_.signature[19], 3);

    assign(test_msg_.signature[20], 4);

    assign(test_msg_.signature[21], 5);

    assign(test_msg_.signature[22], 6);

    assign(test_msg_.signature[23], 7);

    assign(test_msg_.signature[24], 0);

    assign(test_msg_.signature[25], 1);

    assign(test_msg_.signature[26], 2);

    assign(test_msg_.signature[27], 3);

    assign(test_msg_.signature[28], 4);

    assign(test_msg_.signature[29], 5);

    assign(test_msg_.signature[30], 6);

    assign(test_msg_.signature[31], 7);

    assign(test_msg_.signature[32], 0);

    assign(test_msg_.signature[33], 1);

    assign(test_msg_.signature[34], 2);

    assign(test_msg_.signature[35], 3);

    assign(test_msg_.signature[36], 4);

    assign(test_msg_.signature[37], 5);

    assign(test_msg_.signature[38], 6);

    assign(test_msg_.signature[39], 7);

    assign(test_msg_.signature[40], 0);

    assign(test_msg_.signature[41], 1);

    assign(test_msg_.signature[42], 2);

    assign(test_msg_.signature[43], 3);

    assign(test_msg_.signature[44], 4);

    assign(test_msg_.signature[45], 5);

    assign(test_msg_.signature[46], 6);

    assign(test_msg_.signature[47], 7);

    assign(test_msg_.signature[48], 0);

    assign(test_msg_.signature[49], 1);

    assign(test_msg_.signature[50], 2);

    assign(test_msg_.signature[51], 3);

    assign(test_msg_.signature[52], 4);

    assign(test_msg_.signature[53], 5);

    assign(test_msg_.signature[54], 6);

    assign(test_msg_.signature[55], 7);

    assign(test_msg_.signature[56], 0);

    assign(test_msg_.signature[57], 1);

    assign(test_msg_.signature[58], 2);

    assign(test_msg_.signature[59], 3);

    assign(test_msg_.signature[60], 4);

    assign(test_msg_.signature[61], 5);

    assign(test_msg_.signature[62], 6);

    assign(test_msg_.signature[63], 7);

    assign(test_msg_.signed_messages[0], 10);

    assign(test_msg_.signed_messages[1], 21);

    assign(test_msg_.signed_messages[2], 23);

    assign(test_msg_.signed_messages[3], 63);

    assign(test_msg_.signed_messages[4], 140);

    assign(test_msg_.signed_messages[5], 37);

    assign(test_msg_.signed_messages[6], 130);

    assign(test_msg_.signed_messages[7], 106);

    assign(test_msg_.signed_messages[8], 28);

    assign(test_msg_.signed_messages[9], 40);

    assign(test_msg_.signed_messages[10], 165);

    assign(test_msg_.signed_messages[11], 179);

    assign(test_msg_.signed_messages[12], 73);

    assign(test_msg_.signed_messages[13], 178);

    assign(test_msg_.signed_messages[14], 60);

    assign(test_msg_.signed_messages[15], 126);

    assign(test_msg_.signed_messages[16], 114);

    assign(test_msg_.signed_messages[17], 78);

    assign(test_msg_.signed_messages[18], 113);

    assign(test_msg_.signed_messages[19], 27);

    assign(test_msg_.signed_messages[20], 95);

    assign(test_msg_.signed_messages[21], 3);

    assign(test_msg_.signed_messages[22], 62);

    assign(test_msg_.signed_messages[23], 104);

    assign(test_msg_.signed_messages[24], 145);

    assign(test_msg_.signed_messages[25], 96);

    assign(test_msg_.signed_messages[26], 19);

    assign(test_msg_.signed_messages[27], 92);

    assign(test_msg_.signed_messages[28], 123);

    assign(test_msg_.signed_messages[29], 14);

    assign(test_msg_.signed_messages[30], 90);

    assign(test_msg_.signed_messages[31], 153);

    assign(test_msg_.signed_messages[32], 183);

    assign(test_msg_.signed_messages[33], 9);

    assign(test_msg_.signed_messages[34], 72);

    assign(test_msg_.signed_messages[35], 81);

    assign(test_msg_.signed_messages[36], 118);

    assign(test_msg_.signed_messages[37], 112);

    assign(test_msg_.signed_messages[38], 124);

    assign(test_msg_.signed_messages[39], 16);

    assign(test_msg_.signed_messages[40], 182);

    assign(test_msg_.signed_messages[41], 76);

    assign(test_msg_.signed_messages[42], 146);

    assign(test_msg_.signed_messages[43], 115);

    assign(test_msg_.signed_messages[44], 58);

    assign(test_msg_.signed_messages[45], 144);

    assign(test_msg_.signed_messages[46], 17);

    assign(test_msg_.signed_messages[47], 105);

    assign(test_msg_.signed_messages[48], 66);

    assign(test_msg_.signed_messages[49], 31);

    assign(test_msg_.signed_messages[50], 135);

    assign(test_msg_.signed_messages[51], 54);

    assign(test_msg_.signed_messages[52], 100);

    assign(test_msg_.signed_messages[53], 84);

    assign(test_msg_.signed_messages[54], 181);

    assign(test_msg_.signed_messages[55], 103);

    assign(test_msg_.signed_messages[56], 11);

    assign(test_msg_.signed_messages[57], 88);

    assign(test_msg_.signed_messages[58], 133);

    assign(test_msg_.signed_messages[59], 155);

    assign(test_msg_.signed_messages[60], 167);

    assign(test_msg_.signed_messages[61], 173);

    assign(test_msg_.signed_messages[62], 143);

    assign(test_msg_.signed_messages[63], 86);

    assign(test_msg_.signed_messages[64], 158);

    assign(test_msg_.signed_messages[65], 20);

    assign(test_msg_.signed_messages[66], 168);

    assign(test_msg_.signed_messages[67], 132);

    assign(test_msg_.signed_messages[68], 141);

    assign(test_msg_.signed_messages[69], 102);

    assign(test_msg_.signed_messages[70], 50);

    assign(test_msg_.signed_messages[71], 48);

    assign(test_msg_.signed_messages[72], 71);

    assign(test_msg_.signed_messages[73], 147);

    assign(test_msg_.signed_messages[74], 53);

    assign(test_msg_.signed_messages[75], 87);

    assign(test_msg_.signed_messages[76], 1);

    assign(test_msg_.signed_messages[77], 108);

    assign(test_msg_.signed_messages[78], 138);

    assign(test_msg_.signed_messages[79], 36);

    assign(test_msg_.signed_messages[80], 134);

    assign(test_msg_.signed_messages[81], 139);

    assign(test_msg_.signed_messages[82], 163);

    assign(test_msg_.signed_messages[83], 82);

    assign(test_msg_.signed_messages[84], 43);

    assign(test_msg_.signed_messages[85], 52);

    assign(test_msg_.signed_messages[86], 150);

    assign(test_msg_.signed_messages[87], 12);

    assign(test_msg_.signed_messages[88], 30);

    assign(test_msg_.signed_messages[89], 110);

    assign(test_msg_.signed_messages[90], 156);

    assign(test_msg_.signed_messages[91], 107);

    assign(test_msg_.signed_messages[92], 120);

    assign(test_msg_.signed_messages[93], 91);

    assign(test_msg_.signed_messages[94], 122);

    assign(test_msg_.signed_messages[95], 69);

    assign(test_msg_.signed_messages[96], 164);

    assign(test_msg_.signed_messages[97], 170);

    assign(test_msg_.signed_messages[98], 116);

    assign(test_msg_.signed_messages[99], 25);

    assign(test_msg_.signed_messages[100], 94);

    assign(test_msg_.signed_messages[101], 5);

    assign(test_msg_.signed_messages[102], 22);

    assign(test_msg_.signed_messages[103], 24);

    assign(test_msg_.signed_messages[104], 162);

    assign(test_msg_.signed_messages[105], 175);

    assign(test_msg_.signed_messages[106], 38);

    assign(test_msg_.signed_messages[107], 157);

    assign(test_msg_.signed_messages[108], 98);

    assign(test_msg_.signed_messages[109], 44);

    assign(test_msg_.signed_messages[110], 160);

    assign(test_msg_.signed_messages[111], 47);

    assign(test_msg_.signed_messages[112], 97);

    assign(test_msg_.signed_messages[113], 142);

    assign(test_msg_.signed_messages[114], 8);

    assign(test_msg_.signed_messages[115], 74);

    assign(test_msg_.signed_messages[116], 13);

    assign(test_msg_.signed_messages[117], 177);

    assign(test_msg_.signed_messages[118], 15);

    assign(test_msg_.signed_messages[119], 128);

    assign(test_msg_.signed_messages[120], 26);

    assign(test_msg_.signed_messages[121], 131);

    assign(test_msg_.signed_messages[122], 154);

    assign(test_msg_.signed_messages[123], 65);

    assign(test_msg_.signed_messages[124], 169);

    assign(test_msg_.signed_messages[125], 55);

    assign(test_msg_.signed_messages[126], 136);

    assign(test_msg_.signed_messages[127], 125);

    assign(test_msg_.signed_messages[128], 171);

    assign(test_msg_.signed_messages[129], 161);

    assign(test_msg_.signed_messages[130], 29);

    assign(test_msg_.signed_messages[131], 129);

    assign(test_msg_.signed_messages[132], 151);

    assign(test_msg_.signed_messages[133], 68);

    assign(test_msg_.signed_messages[134], 166);

    assign(test_msg_.signed_messages[135], 51);

    assign(test_msg_.signed_messages[136], 70);

    assign(test_msg_.signed_messages[137], 45);

    assign(test_msg_.signed_messages[138], 56);

    assign(test_msg_.signed_messages[139], 79);

    assign(test_msg_.signed_messages[140], 149);

    assign(test_msg_.signed_messages[141], 99);

    assign(test_msg_.signed_messages[142], 42);

    assign(test_msg_.signed_messages[143], 101);

    assign(test_msg_.signed_messages[144], 152);

    assign(test_msg_.signed_messages[145], 39);

    assign(test_msg_.signed_messages[146], 89);

    assign(test_msg_.signed_messages[147], 180);

    assign(test_msg_.signed_messages[148], 64);

    assign(test_msg_.signed_messages[149], 49);

    assign(test_msg_.signed_messages[150], 6);

    assign(test_msg_.signed_messages[151], 80);

    assign(test_msg_.signed_messages[152], 172);

    assign(test_msg_.signed_messages[153], 32);

    assign(test_msg_.signed_messages[154], 109);

    assign(test_msg_.signed_messages[155], 2);

    assign(test_msg_.signed_messages[156], 119);

    assign(test_msg_.signed_messages[157], 93);

    assign(test_msg_.signed_messages[158], 176);

    assign(test_msg_.signed_messages[159], 0);

    assign(test_msg_.signed_messages[160], 33);

    assign(test_msg_.signed_messages[161], 57);

    assign(test_msg_.signed_messages[162], 34);

    assign(test_msg_.signed_messages[163], 18);

    assign(test_msg_.signed_messages[164], 85);

    assign(test_msg_.signed_messages[165], 121);

    assign(test_msg_.signed_messages[166], 137);

    assign(test_msg_.signed_messages[167], 83);

    assign(test_msg_.signed_messages[168], 111);

    assign(test_msg_.signed_messages[169], 59);

    assign(test_msg_.signed_messages[170], 7);

    assign(test_msg_.signed_messages[171], 77);

    assign(test_msg_.signed_messages[172], 4);

    assign(test_msg_.signed_messages[173], 117);

    assign(test_msg_.signed_messages[174], 159);

    assign(test_msg_.signed_messages[175], 148);

    assign(test_msg_.signed_messages[176], 35);

    assign(test_msg_.signed_messages[177], 61);

    assign(test_msg_.signed_messages[178], 41);

    assign(test_msg_.signed_messages[179], 67);

    assign(test_msg_.signed_messages[180], 46);

    assign(test_msg_.signed_messages[181], 127);

    assign(test_msg_.signed_messages[182], 75);

    assign(test_msg_.signed_messages[183], 174);
    assign(test_msg_.stream_counter, 1);
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
      : public sbp::MessageHandler<sbp_msg_ecdsa_signature_dep_a_t> {
    using sbp::MessageHandler<sbp_msg_ecdsa_signature_dep_a_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ecdsa_signature_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ecdsa_signature_dep_a_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgEcdsaSignatureDepA,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ecdsa_signature_dep_a_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgEcdsaSignatureDepA);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ecdsa_signature_dep_a,
             sizeof(msg->ecdsa_signature_dep_a));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ecdsa_signature_dep_a_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ecdsa_signature_dep_a, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgEcdsaSignatureDepA);
    info.sender_id = 66;
    info.preamble = 0x55;
    info.crc = 0xAC61;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 255;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ecdsa_signature_dep_a_t &lesser,
                        const sbp_msg_ecdsa_signature_dep_a_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_a_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_a_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_ecdsa_signature_dep_a_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ecdsa_signature_dep_a_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ecdsa_signature_dep_a_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ecdsa_signature_dep_a_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgEcdsaSignatureDepA, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgEcdsaSignatureDepA, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgEcdsaSignatureDepA, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgEcdsaSignatureDepA, &wrapped_greater,
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
  sbp_msg_ecdsa_signature_dep_a_t test_msg_{};
  uint8_t encoded_frame_[255 + 8] = {
      85,  6,   12,  66,  0,   255, 0,   1,   2,   1,   2,   3,   4,   0,   1,
      2,   3,   4,   5,   6,   7,   0,   1,   2,   3,   4,   5,   6,   7,   0,
      1,   2,   3,   4,   5,   6,   7,   0,   1,   2,   3,   4,   5,   6,   7,
      0,   1,   2,   3,   4,   5,   6,   7,   0,   1,   2,   3,   4,   5,   6,
      7,   0,   1,   2,   3,   4,   5,   6,   7,   0,   1,   2,   3,   4,   5,
      6,   7,   10,  21,  23,  63,  140, 37,  130, 106, 28,  40,  165, 179, 73,
      178, 60,  126, 114, 78,  113, 27,  95,  3,   62,  104, 145, 96,  19,  92,
      123, 14,  90,  153, 183, 9,   72,  81,  118, 112, 124, 16,  182, 76,  146,
      115, 58,  144, 17,  105, 66,  31,  135, 54,  100, 84,  181, 103, 11,  88,
      133, 155, 167, 173, 143, 86,  158, 20,  168, 132, 141, 102, 50,  48,  71,
      147, 53,  87,  1,   108, 138, 36,  134, 139, 163, 82,  43,  52,  150, 12,
      30,  110, 156, 107, 120, 91,  122, 69,  164, 170, 116, 25,  94,  5,   22,
      24,  162, 175, 38,  157, 98,  44,  160, 47,  97,  142, 8,   74,  13,  177,
      15,  128, 26,  131, 154, 65,  169, 55,  136, 125, 171, 161, 29,  129, 151,
      68,  166, 51,  70,  45,  56,  79,  149, 99,  42,  101, 152, 39,  89,  180,
      64,  49,  6,   80,  172, 32,  109, 2,   119, 93,  176, 0,   33,  57,  34,
      18,  85,  121, 137, 83,  111, 59,  7,   77,  4,   117, 159, 148, 35,  61,
      41,  67,  46,  127, 75,  174, 97,  172,
  };
  uint8_t encoded_payload_[255] = {
      0,   1,   2,   1,   2,   3,   4,   0,   1,   2,   3,   4,   5,   6,   7,
      0,   1,   2,   3,   4,   5,   6,   7,   0,   1,   2,   3,   4,   5,   6,
      7,   0,   1,   2,   3,   4,   5,   6,   7,   0,   1,   2,   3,   4,   5,
      6,   7,   0,   1,   2,   3,   4,   5,   6,   7,   0,   1,   2,   3,   4,
      5,   6,   7,   0,   1,   2,   3,   4,   5,   6,   7,   10,  21,  23,  63,
      140, 37,  130, 106, 28,  40,  165, 179, 73,  178, 60,  126, 114, 78,  113,
      27,  95,  3,   62,  104, 145, 96,  19,  92,  123, 14,  90,  153, 183, 9,
      72,  81,  118, 112, 124, 16,  182, 76,  146, 115, 58,  144, 17,  105, 66,
      31,  135, 54,  100, 84,  181, 103, 11,  88,  133, 155, 167, 173, 143, 86,
      158, 20,  168, 132, 141, 102, 50,  48,  71,  147, 53,  87,  1,   108, 138,
      36,  134, 139, 163, 82,  43,  52,  150, 12,  30,  110, 156, 107, 120, 91,
      122, 69,  164, 170, 116, 25,  94,  5,   22,  24,  162, 175, 38,  157, 98,
      44,  160, 47,  97,  142, 8,   74,  13,  177, 15,  128, 26,  131, 154, 65,
      169, 55,  136, 125, 171, 161, 29,  129, 151, 68,  166, 51,  70,  45,  56,
      79,  149, 99,  42,  101, 152, 39,  89,  180, 64,  49,  6,   80,  172, 32,
      109, 2,   119, 93,  176, 0,   33,  57,  34,  18,  85,  121, 137, 83,  111,
      59,  7,   77,  4,   117, 159, 148, 35,  61,  41,  67,  46,  127, 75,  174,
  };
};

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ecdsa_signature_dep_a_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgEcdsaSignatureDepA, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[255];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ecdsa_signature_dep_a_encode(&buf[0], sizeof(buf),
                                                 &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(
      sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                         SbpMsgEcdsaSignatureDepA, &info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[255];

  EXPECT_EQ(sbp_msg_ecdsa_signature_dep_a_encode(&buf[0], sizeof(buf), nullptr,
                                                 &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}
TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[255];

  for (uint8_t i = 0; i < 255; i++) {
    EXPECT_EQ(sbp_msg_ecdsa_signature_dep_a_encode(&buf[0], i, nullptr,
                                                   &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ecdsa_signature_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ecdsa_signature_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgEcdsaSignatureDepA, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ecdsa_signature_dep_a_t msg{};

  EXPECT_EQ(sbp_msg_ecdsa_signature_dep_a_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ecdsa_signature_dep_a_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ecdsa_signature_dep_a_t t{};
      return sbp_msg_ecdsa_signature_dep_a_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ecdsa_signature_dep_a_t t{};
      t.n_signed_messages = 1;
      return sbp_msg_ecdsa_signature_dep_a_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ecdsa_signature_dep_a_decode(&info.encoded_payload[0], i,
                                                   nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0, SlowRead) {
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0, BadCRC) {
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ecdsa_signature_dep_a_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEcdsaSignatureDepA, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgEcdsaSignatureDepA, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgEcdsaSignatureDepA, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0, Comparison) {
  auto info = get_test_msg_info();

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_id[0], greater.certificate_id[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_id[1], greater.certificate_id[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_id[2], greater.certificate_id[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.certificate_id[3], greater.certificate_id[3]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.flags, greater.flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.n_signed_messages, greater.n_signed_messages);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.on_demand_counter, greater.on_demand_counter);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[0], greater.signature[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[1], greater.signature[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[2], greater.signature[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[3], greater.signature[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[4], greater.signature[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[5], greater.signature[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[6], greater.signature[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[7], greater.signature[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[8], greater.signature[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[9], greater.signature[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[10], greater.signature[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[11], greater.signature[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[12], greater.signature[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[13], greater.signature[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[14], greater.signature[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[15], greater.signature[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[16], greater.signature[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[17], greater.signature[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[18], greater.signature[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[19], greater.signature[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[20], greater.signature[20]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[21], greater.signature[21]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[22], greater.signature[22]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[23], greater.signature[23]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[24], greater.signature[24]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[25], greater.signature[25]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[26], greater.signature[26]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[27], greater.signature[27]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[28], greater.signature[28]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[29], greater.signature[29]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[30], greater.signature[30]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[31], greater.signature[31]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[32], greater.signature[32]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[33], greater.signature[33]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[34], greater.signature[34]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[35], greater.signature[35]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[36], greater.signature[36]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[37], greater.signature[37]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[38], greater.signature[38]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[39], greater.signature[39]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[40], greater.signature[40]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[41], greater.signature[41]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[42], greater.signature[42]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[43], greater.signature[43]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[44], greater.signature[44]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[45], greater.signature[45]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[46], greater.signature[46]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[47], greater.signature[47]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[48], greater.signature[48]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[49], greater.signature[49]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[50], greater.signature[50]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[51], greater.signature[51]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[52], greater.signature[52]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[53], greater.signature[53]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[54], greater.signature[54]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[55], greater.signature[55]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[56], greater.signature[56]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[57], greater.signature[57]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[58], greater.signature[58]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[59], greater.signature[59]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[60], greater.signature[60]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[61], greater.signature[61]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[62], greater.signature[62]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signature[63], greater.signature[63]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[0], greater.signed_messages[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[1], greater.signed_messages[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[2], greater.signed_messages[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[3], greater.signed_messages[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[4], greater.signed_messages[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[5], greater.signed_messages[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[6], greater.signed_messages[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[7], greater.signed_messages[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[8], greater.signed_messages[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[9], greater.signed_messages[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[10],
                        greater.signed_messages[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[11],
                        greater.signed_messages[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[12],
                        greater.signed_messages[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[13],
                        greater.signed_messages[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[14],
                        greater.signed_messages[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[15],
                        greater.signed_messages[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[16],
                        greater.signed_messages[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[17],
                        greater.signed_messages[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[18],
                        greater.signed_messages[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[19],
                        greater.signed_messages[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[20],
                        greater.signed_messages[20]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[21],
                        greater.signed_messages[21]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[22],
                        greater.signed_messages[22]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[23],
                        greater.signed_messages[23]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[24],
                        greater.signed_messages[24]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[25],
                        greater.signed_messages[25]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[26],
                        greater.signed_messages[26]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[27],
                        greater.signed_messages[27]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[28],
                        greater.signed_messages[28]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[29],
                        greater.signed_messages[29]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[30],
                        greater.signed_messages[30]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[31],
                        greater.signed_messages[31]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[32],
                        greater.signed_messages[32]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[33],
                        greater.signed_messages[33]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[34],
                        greater.signed_messages[34]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[35],
                        greater.signed_messages[35]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[36],
                        greater.signed_messages[36]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[37],
                        greater.signed_messages[37]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[38],
                        greater.signed_messages[38]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[39],
                        greater.signed_messages[39]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[40],
                        greater.signed_messages[40]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[41],
                        greater.signed_messages[41]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[42],
                        greater.signed_messages[42]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[43],
                        greater.signed_messages[43]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[44],
                        greater.signed_messages[44]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[45],
                        greater.signed_messages[45]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[46],
                        greater.signed_messages[46]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[47],
                        greater.signed_messages[47]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[48],
                        greater.signed_messages[48]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[49],
                        greater.signed_messages[49]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[50],
                        greater.signed_messages[50]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[51],
                        greater.signed_messages[51]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[52],
                        greater.signed_messages[52]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[53],
                        greater.signed_messages[53]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[54],
                        greater.signed_messages[54]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[55],
                        greater.signed_messages[55]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[56],
                        greater.signed_messages[56]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[57],
                        greater.signed_messages[57]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[58],
                        greater.signed_messages[58]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[59],
                        greater.signed_messages[59]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[60],
                        greater.signed_messages[60]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[61],
                        greater.signed_messages[61]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[62],
                        greater.signed_messages[62]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[63],
                        greater.signed_messages[63]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[64],
                        greater.signed_messages[64]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[65],
                        greater.signed_messages[65]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[66],
                        greater.signed_messages[66]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[67],
                        greater.signed_messages[67]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[68],
                        greater.signed_messages[68]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[69],
                        greater.signed_messages[69]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[70],
                        greater.signed_messages[70]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[71],
                        greater.signed_messages[71]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[72],
                        greater.signed_messages[72]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[73],
                        greater.signed_messages[73]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[74],
                        greater.signed_messages[74]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[75],
                        greater.signed_messages[75]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[76],
                        greater.signed_messages[76]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[77],
                        greater.signed_messages[77]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[78],
                        greater.signed_messages[78]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[79],
                        greater.signed_messages[79]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[80],
                        greater.signed_messages[80]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[81],
                        greater.signed_messages[81]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[82],
                        greater.signed_messages[82]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[83],
                        greater.signed_messages[83]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[84],
                        greater.signed_messages[84]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[85],
                        greater.signed_messages[85]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[86],
                        greater.signed_messages[86]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[87],
                        greater.signed_messages[87]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[88],
                        greater.signed_messages[88]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[89],
                        greater.signed_messages[89]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[90],
                        greater.signed_messages[90]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[91],
                        greater.signed_messages[91]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[92],
                        greater.signed_messages[92]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[93],
                        greater.signed_messages[93]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[94],
                        greater.signed_messages[94]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[95],
                        greater.signed_messages[95]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[96],
                        greater.signed_messages[96]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[97],
                        greater.signed_messages[97]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[98],
                        greater.signed_messages[98]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[99],
                        greater.signed_messages[99]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[100],
                        greater.signed_messages[100]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[101],
                        greater.signed_messages[101]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[102],
                        greater.signed_messages[102]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[103],
                        greater.signed_messages[103]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[104],
                        greater.signed_messages[104]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[105],
                        greater.signed_messages[105]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[106],
                        greater.signed_messages[106]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[107],
                        greater.signed_messages[107]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[108],
                        greater.signed_messages[108]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[109],
                        greater.signed_messages[109]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[110],
                        greater.signed_messages[110]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[111],
                        greater.signed_messages[111]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[112],
                        greater.signed_messages[112]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[113],
                        greater.signed_messages[113]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[114],
                        greater.signed_messages[114]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[115],
                        greater.signed_messages[115]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[116],
                        greater.signed_messages[116]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[117],
                        greater.signed_messages[117]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[118],
                        greater.signed_messages[118]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[119],
                        greater.signed_messages[119]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[120],
                        greater.signed_messages[120]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[121],
                        greater.signed_messages[121]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[122],
                        greater.signed_messages[122]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[123],
                        greater.signed_messages[123]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[124],
                        greater.signed_messages[124]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[125],
                        greater.signed_messages[125]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[126],
                        greater.signed_messages[126]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[127],
                        greater.signed_messages[127]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[128],
                        greater.signed_messages[128]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[129],
                        greater.signed_messages[129]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[130],
                        greater.signed_messages[130]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[131],
                        greater.signed_messages[131]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[132],
                        greater.signed_messages[132]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[133],
                        greater.signed_messages[133]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[134],
                        greater.signed_messages[134]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[135],
                        greater.signed_messages[135]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[136],
                        greater.signed_messages[136]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[137],
                        greater.signed_messages[137]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[138],
                        greater.signed_messages[138]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[139],
                        greater.signed_messages[139]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[140],
                        greater.signed_messages[140]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[141],
                        greater.signed_messages[141]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[142],
                        greater.signed_messages[142]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[143],
                        greater.signed_messages[143]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[144],
                        greater.signed_messages[144]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[145],
                        greater.signed_messages[145]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[146],
                        greater.signed_messages[146]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[147],
                        greater.signed_messages[147]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[148],
                        greater.signed_messages[148]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[149],
                        greater.signed_messages[149]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[150],
                        greater.signed_messages[150]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[151],
                        greater.signed_messages[151]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[152],
                        greater.signed_messages[152]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[153],
                        greater.signed_messages[153]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[154],
                        greater.signed_messages[154]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[155],
                        greater.signed_messages[155]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[156],
                        greater.signed_messages[156]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[157],
                        greater.signed_messages[157]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[158],
                        greater.signed_messages[158]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[159],
                        greater.signed_messages[159]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[160],
                        greater.signed_messages[160]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[161],
                        greater.signed_messages[161]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[162],
                        greater.signed_messages[162]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[163],
                        greater.signed_messages[163]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[164],
                        greater.signed_messages[164]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[165],
                        greater.signed_messages[165]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[166],
                        greater.signed_messages[166]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[167],
                        greater.signed_messages[167]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[168],
                        greater.signed_messages[168]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[169],
                        greater.signed_messages[169]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[170],
                        greater.signed_messages[170]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[171],
                        greater.signed_messages[171]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[172],
                        greater.signed_messages[172]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[173],
                        greater.signed_messages[173]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[174],
                        greater.signed_messages[174]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[175],
                        greater.signed_messages[175]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[176],
                        greater.signed_messages[176]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[177],
                        greater.signed_messages[177]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[178],
                        greater.signed_messages[178]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[179],
                        greater.signed_messages[179]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[180],
                        greater.signed_messages[180]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[181],
                        greater.signed_messages[181]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[182],
                        greater.signed_messages[182]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.signed_messages[183],
                        greater.signed_messages[183]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ecdsa_signature_dep_a_t lesser = info.test_msg;
    sbp_msg_ecdsa_signature_dep_a_t greater = info.test_msg;
    make_lesser_greater(lesser.stream_counter, greater.stream_counter);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_a_t>::id,
  // SbpMsgEcdsaSignatureDepA);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_a_t>::name,
               "MSG_ECDSA_SIGNATURE_DEP_A");
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ecdsa_signature_dep_a_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_a_t>::get(const_sbp_msg_t);
  sbp_msg_ecdsa_signature_dep_a_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_a_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_a_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.ecdsa_signature_dep_a, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_a_t>::to_sbp_msg(info.test_msg,
                                                                  &msg2);
  EXPECT_EQ(msg2.ecdsa_signature_dep_a, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_a_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_a_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[255];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_a_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ecdsa_signature_dep_a_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ecdsa_signature_dep_a_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
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

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgEcdsaSignatureDepA,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_signing_MsgEcdsaSignatureDepA0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgEcdsaSignatureDepA,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace