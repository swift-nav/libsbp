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
// spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashProgram.yaml by generate.py.
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
class Testauto_check_sbp_flash_MsgFlashProgram0 : public ::testing::Test {
 public:
  Testauto_check_sbp_flash_MsgFlashProgram0() {
    assign(test_msg_.addr_len, 250);

    assign(test_msg_.addr_start[0], 87);

    assign(test_msg_.addr_start[1], 52);

    assign(test_msg_.addr_start[2], 244);

    assign(test_msg_.data[0], 176);

    assign(test_msg_.data[1], 222);

    assign(test_msg_.data[2], 235);

    assign(test_msg_.data[3], 106);

    assign(test_msg_.data[4], 144);

    assign(test_msg_.data[5], 29);

    assign(test_msg_.data[6], 141);

    assign(test_msg_.data[7], 255);

    assign(test_msg_.data[8], 3);

    assign(test_msg_.data[9], 16);

    assign(test_msg_.data[10], 192);

    assign(test_msg_.data[11], 237);

    assign(test_msg_.data[12], 172);

    assign(test_msg_.data[13], 254);

    assign(test_msg_.data[14], 213);

    assign(test_msg_.data[15], 4);

    assign(test_msg_.data[16], 220);

    assign(test_msg_.data[17], 98);

    assign(test_msg_.data[18], 34);

    assign(test_msg_.data[19], 222);

    assign(test_msg_.data[20], 230);

    assign(test_msg_.data[21], 214);

    assign(test_msg_.data[22], 6);

    assign(test_msg_.data[23], 217);

    assign(test_msg_.data[24], 172);

    assign(test_msg_.data[25], 122);

    assign(test_msg_.data[26], 46);

    assign(test_msg_.data[27], 13);

    assign(test_msg_.data[28], 38);

    assign(test_msg_.data[29], 240);

    assign(test_msg_.data[30], 236);

    assign(test_msg_.data[31], 60);

    assign(test_msg_.data[32], 121);

    assign(test_msg_.data[33], 47);

    assign(test_msg_.data[34], 252);

    assign(test_msg_.data[35], 163);

    assign(test_msg_.data[36], 141);

    assign(test_msg_.data[37], 222);

    assign(test_msg_.data[38], 29);

    assign(test_msg_.data[39], 168);

    assign(test_msg_.data[40], 214);

    assign(test_msg_.data[41], 118);

    assign(test_msg_.data[42], 55);

    assign(test_msg_.data[43], 201);

    assign(test_msg_.data[44], 233);

    assign(test_msg_.data[45], 21);

    assign(test_msg_.data[46], 214);

    assign(test_msg_.data[47], 57);

    assign(test_msg_.data[48], 245);

    assign(test_msg_.data[49], 246);

    assign(test_msg_.data[50], 19);

    assign(test_msg_.data[51], 3);

    assign(test_msg_.data[52], 121);

    assign(test_msg_.data[53], 49);

    assign(test_msg_.data[54], 231);

    assign(test_msg_.data[55], 37);

    assign(test_msg_.data[56], 186);

    assign(test_msg_.data[57], 58);

    assign(test_msg_.data[58], 238);

    assign(test_msg_.data[59], 98);

    assign(test_msg_.data[60], 39);

    assign(test_msg_.data[61], 70);

    assign(test_msg_.data[62], 232);

    assign(test_msg_.data[63], 133);

    assign(test_msg_.data[64], 25);

    assign(test_msg_.data[65], 10);

    assign(test_msg_.data[66], 134);

    assign(test_msg_.data[67], 129);

    assign(test_msg_.data[68], 69);

    assign(test_msg_.data[69], 228);

    assign(test_msg_.data[70], 134);

    assign(test_msg_.data[71], 9);

    assign(test_msg_.data[72], 88);

    assign(test_msg_.data[73], 183);

    assign(test_msg_.data[74], 133);

    assign(test_msg_.data[75], 171);

    assign(test_msg_.data[76], 255);

    assign(test_msg_.data[77], 166);

    assign(test_msg_.data[78], 100);

    assign(test_msg_.data[79], 152);

    assign(test_msg_.data[80], 231);

    assign(test_msg_.data[81], 92);

    assign(test_msg_.data[82], 9);

    assign(test_msg_.data[83], 196);

    assign(test_msg_.data[84], 106);

    assign(test_msg_.data[85], 246);

    assign(test_msg_.data[86], 29);

    assign(test_msg_.data[87], 145);

    assign(test_msg_.data[88], 156);

    assign(test_msg_.data[89], 151);

    assign(test_msg_.data[90], 32);

    assign(test_msg_.data[91], 67);

    assign(test_msg_.data[92], 188);

    assign(test_msg_.data[93], 63);

    assign(test_msg_.data[94], 233);

    assign(test_msg_.data[95], 142);

    assign(test_msg_.data[96], 174);

    assign(test_msg_.data[97], 139);

    assign(test_msg_.data[98], 154);

    assign(test_msg_.data[99], 127);

    assign(test_msg_.data[100], 35);

    assign(test_msg_.data[101], 60);

    assign(test_msg_.data[102], 56);

    assign(test_msg_.data[103], 187);

    assign(test_msg_.data[104], 121);

    assign(test_msg_.data[105], 103);

    assign(test_msg_.data[106], 135);

    assign(test_msg_.data[107], 152);

    assign(test_msg_.data[108], 182);

    assign(test_msg_.data[109], 88);

    assign(test_msg_.data[110], 160);

    assign(test_msg_.data[111], 255);

    assign(test_msg_.data[112], 227);

    assign(test_msg_.data[113], 240);

    assign(test_msg_.data[114], 54);

    assign(test_msg_.data[115], 100);

    assign(test_msg_.data[116], 91);

    assign(test_msg_.data[117], 31);

    assign(test_msg_.data[118], 141);

    assign(test_msg_.data[119], 102);

    assign(test_msg_.data[120], 130);

    assign(test_msg_.data[121], 254);

    assign(test_msg_.data[122], 54);

    assign(test_msg_.data[123], 227);

    assign(test_msg_.data[124], 229);

    assign(test_msg_.data[125], 62);

    assign(test_msg_.data[126], 53);

    assign(test_msg_.data[127], 225);

    assign(test_msg_.data[128], 143);

    assign(test_msg_.data[129], 88);

    assign(test_msg_.data[130], 139);

    assign(test_msg_.data[131], 126);

    assign(test_msg_.data[132], 235);

    assign(test_msg_.data[133], 235);

    assign(test_msg_.data[134], 35);

    assign(test_msg_.data[135], 54);

    assign(test_msg_.data[136], 134);

    assign(test_msg_.data[137], 163);

    assign(test_msg_.data[138], 92);

    assign(test_msg_.data[139], 57);

    assign(test_msg_.data[140], 87);

    assign(test_msg_.data[141], 130);

    assign(test_msg_.data[142], 178);

    assign(test_msg_.data[143], 22);

    assign(test_msg_.data[144], 158);

    assign(test_msg_.data[145], 18);

    assign(test_msg_.data[146], 237);

    assign(test_msg_.data[147], 209);

    assign(test_msg_.data[148], 187);

    assign(test_msg_.data[149], 226);

    assign(test_msg_.data[150], 1);

    assign(test_msg_.data[151], 46);

    assign(test_msg_.data[152], 64);

    assign(test_msg_.data[153], 226);

    assign(test_msg_.data[154], 235);

    assign(test_msg_.data[155], 213);

    assign(test_msg_.data[156], 186);

    assign(test_msg_.data[157], 159);

    assign(test_msg_.data[158], 221);

    assign(test_msg_.data[159], 186);

    assign(test_msg_.data[160], 25);

    assign(test_msg_.data[161], 115);

    assign(test_msg_.data[162], 84);

    assign(test_msg_.data[163], 131);

    assign(test_msg_.data[164], 167);

    assign(test_msg_.data[165], 201);

    assign(test_msg_.data[166], 104);

    assign(test_msg_.data[167], 1);

    assign(test_msg_.data[168], 200);

    assign(test_msg_.data[169], 13);

    assign(test_msg_.data[170], 50);

    assign(test_msg_.data[171], 71);

    assign(test_msg_.data[172], 73);

    assign(test_msg_.data[173], 193);

    assign(test_msg_.data[174], 201);

    assign(test_msg_.data[175], 250);

    assign(test_msg_.data[176], 172);

    assign(test_msg_.data[177], 193);

    assign(test_msg_.data[178], 13);

    assign(test_msg_.data[179], 20);

    assign(test_msg_.data[180], 238);

    assign(test_msg_.data[181], 130);

    assign(test_msg_.data[182], 243);

    assign(test_msg_.data[183], 68);

    assign(test_msg_.data[184], 4);

    assign(test_msg_.data[185], 72);

    assign(test_msg_.data[186], 46);

    assign(test_msg_.data[187], 194);

    assign(test_msg_.data[188], 113);

    assign(test_msg_.data[189], 255);

    assign(test_msg_.data[190], 238);

    assign(test_msg_.data[191], 15);

    assign(test_msg_.data[192], 230);

    assign(test_msg_.data[193], 64);

    assign(test_msg_.data[194], 178);

    assign(test_msg_.data[195], 127);

    assign(test_msg_.data[196], 217);

    assign(test_msg_.data[197], 92);

    assign(test_msg_.data[198], 160);

    assign(test_msg_.data[199], 201);

    assign(test_msg_.data[200], 118);

    assign(test_msg_.data[201], 163);

    assign(test_msg_.data[202], 144);

    assign(test_msg_.data[203], 58);

    assign(test_msg_.data[204], 28);

    assign(test_msg_.data[205], 174);

    assign(test_msg_.data[206], 65);

    assign(test_msg_.data[207], 73);

    assign(test_msg_.data[208], 45);

    assign(test_msg_.data[209], 123);

    assign(test_msg_.data[210], 118);

    assign(test_msg_.data[211], 83);

    assign(test_msg_.data[212], 107);

    assign(test_msg_.data[213], 239);

    assign(test_msg_.data[214], 168);

    assign(test_msg_.data[215], 32);

    assign(test_msg_.data[216], 212);

    assign(test_msg_.data[217], 191);

    assign(test_msg_.data[218], 81);

    assign(test_msg_.data[219], 93);

    assign(test_msg_.data[220], 186);

    assign(test_msg_.data[221], 223);

    assign(test_msg_.data[222], 32);

    assign(test_msg_.data[223], 19);

    assign(test_msg_.data[224], 58);

    assign(test_msg_.data[225], 137);

    assign(test_msg_.data[226], 72);

    assign(test_msg_.data[227], 217);

    assign(test_msg_.data[228], 151);

    assign(test_msg_.data[229], 251);

    assign(test_msg_.data[230], 83);

    assign(test_msg_.data[231], 20);

    assign(test_msg_.data[232], 113);

    assign(test_msg_.data[233], 37);

    assign(test_msg_.data[234], 151);

    assign(test_msg_.data[235], 34);

    assign(test_msg_.data[236], 37);

    assign(test_msg_.data[237], 71);

    assign(test_msg_.data[238], 95);

    assign(test_msg_.data[239], 105);

    assign(test_msg_.data[240], 235);

    assign(test_msg_.data[241], 144);

    assign(test_msg_.data[242], 164);

    assign(test_msg_.data[243], 83);

    assign(test_msg_.data[244], 197);

    assign(test_msg_.data[245], 254);

    assign(test_msg_.data[246], 183);

    assign(test_msg_.data[247], 223);

    assign(test_msg_.data[248], 91);

    assign(test_msg_.data[249], 19);
    assign(test_msg_.target, 212);
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
      : public sbp::MessageHandler<sbp_msg_flash_program_t> {
    using sbp::MessageHandler<sbp_msg_flash_program_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_flash_program_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_flash_program_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgFlashProgram,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_flash_program_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgFlashProgram);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->flash_program,
             sizeof(msg->flash_program));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_flash_program_t test_msg;
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
    memcpy(&info.test_msg_wrapped.flash_program, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgFlashProgram);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0xe32d;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 255;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_flash_program_t &lesser,
                        const sbp_msg_flash_program_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_flash_program_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_flash_program_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_flash_program_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_flash_program_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_flash_program_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_flash_program_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgFlashProgram, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgFlashProgram, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgFlashProgram, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgFlashProgram, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_flash_program_t test_msg_{};
  uint8_t encoded_frame_[255 + 8] = {
      85,  230, 0,   195, 4,   255, 212, 87,  52,  244, 250, 176, 222, 235, 106,
      144, 29,  141, 255, 3,   16,  192, 237, 172, 254, 213, 4,   220, 98,  34,
      222, 230, 214, 6,   217, 172, 122, 46,  13,  38,  240, 236, 60,  121, 47,
      252, 163, 141, 222, 29,  168, 214, 118, 55,  201, 233, 21,  214, 57,  245,
      246, 19,  3,   121, 49,  231, 37,  186, 58,  238, 98,  39,  70,  232, 133,
      25,  10,  134, 129, 69,  228, 134, 9,   88,  183, 133, 171, 255, 166, 100,
      152, 231, 92,  9,   196, 106, 246, 29,  145, 156, 151, 32,  67,  188, 63,
      233, 142, 174, 139, 154, 127, 35,  60,  56,  187, 121, 103, 135, 152, 182,
      88,  160, 255, 227, 240, 54,  100, 91,  31,  141, 102, 130, 254, 54,  227,
      229, 62,  53,  225, 143, 88,  139, 126, 235, 235, 35,  54,  134, 163, 92,
      57,  87,  130, 178, 22,  158, 18,  237, 209, 187, 226, 1,   46,  64,  226,
      235, 213, 186, 159, 221, 186, 25,  115, 84,  131, 167, 201, 104, 1,   200,
      13,  50,  71,  73,  193, 201, 250, 172, 193, 13,  20,  238, 130, 243, 68,
      4,   72,  46,  194, 113, 255, 238, 15,  230, 64,  178, 127, 217, 92,  160,
      201, 118, 163, 144, 58,  28,  174, 65,  73,  45,  123, 118, 83,  107, 239,
      168, 32,  212, 191, 81,  93,  186, 223, 32,  19,  58,  137, 72,  217, 151,
      251, 83,  20,  113, 37,  151, 34,  37,  71,  95,  105, 235, 144, 164, 83,
      197, 254, 183, 223, 91,  19,  45,  227,
  };
  uint8_t encoded_payload_[255] = {
      212, 87,  52,  244, 250, 176, 222, 235, 106, 144, 29,  141, 255, 3,   16,
      192, 237, 172, 254, 213, 4,   220, 98,  34,  222, 230, 214, 6,   217, 172,
      122, 46,  13,  38,  240, 236, 60,  121, 47,  252, 163, 141, 222, 29,  168,
      214, 118, 55,  201, 233, 21,  214, 57,  245, 246, 19,  3,   121, 49,  231,
      37,  186, 58,  238, 98,  39,  70,  232, 133, 25,  10,  134, 129, 69,  228,
      134, 9,   88,  183, 133, 171, 255, 166, 100, 152, 231, 92,  9,   196, 106,
      246, 29,  145, 156, 151, 32,  67,  188, 63,  233, 142, 174, 139, 154, 127,
      35,  60,  56,  187, 121, 103, 135, 152, 182, 88,  160, 255, 227, 240, 54,
      100, 91,  31,  141, 102, 130, 254, 54,  227, 229, 62,  53,  225, 143, 88,
      139, 126, 235, 235, 35,  54,  134, 163, 92,  57,  87,  130, 178, 22,  158,
      18,  237, 209, 187, 226, 1,   46,  64,  226, 235, 213, 186, 159, 221, 186,
      25,  115, 84,  131, 167, 201, 104, 1,   200, 13,  50,  71,  73,  193, 201,
      250, 172, 193, 13,  20,  238, 130, 243, 68,  4,   72,  46,  194, 113, 255,
      238, 15,  230, 64,  178, 127, 217, 92,  160, 201, 118, 163, 144, 58,  28,
      174, 65,  73,  45,  123, 118, 83,  107, 239, 168, 32,  212, 191, 81,  93,
      186, 223, 32,  19,  58,  137, 72,  217, 151, 251, 83,  20,  113, 37,  151,
      34,  37,  71,  95,  105, 235, 144, 164, 83,  197, 254, 183, 223, 91,  19,
  };
};

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_flash_program_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgFlashProgram, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[255];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_flash_program_encode(&buf[0], sizeof(buf), &n_written,
                                         &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgFlashProgram, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[255];

  EXPECT_EQ(sbp_msg_flash_program_encode(&buf[0], sizeof(buf), nullptr,
                                         &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}
TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[255];

  for (uint8_t i = 0; i < 255; i++) {
    EXPECT_EQ(sbp_msg_flash_program_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_flash_program_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_flash_program_decode(&info.encoded_payload[0],
                                         info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgFlashProgram, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_flash_program_t msg{};

  EXPECT_EQ(sbp_msg_flash_program_decode(&info.encoded_payload[0],
                                         info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_flash_program_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_flash_program_t t{};
      return sbp_msg_flash_program_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_flash_program_t t{};
      t.addr_len = 1;
      return sbp_msg_flash_program_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_flash_program_decode(&info.encoded_payload[0], i, nullptr,
                                           &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0,
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

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, SlowRead) {
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

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, BadCRC) {
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

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_flash_program_send(&state, info.sender_id, &info.test_msg,
                                       &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgFlashProgram, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgFlashProgram, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgFlashProgram, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.addr_len, greater.addr_len);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.addr_start[0], greater.addr_start[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.addr_start[1], greater.addr_start[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.addr_start[2], greater.addr_start[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[0], greater.data[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[1], greater.data[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[2], greater.data[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[3], greater.data[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[4], greater.data[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[5], greater.data[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[6], greater.data[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[7], greater.data[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[8], greater.data[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[9], greater.data[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[10], greater.data[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[11], greater.data[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[12], greater.data[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[13], greater.data[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[14], greater.data[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[15], greater.data[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[16], greater.data[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[17], greater.data[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[18], greater.data[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[19], greater.data[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[20], greater.data[20]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[21], greater.data[21]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[22], greater.data[22]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[23], greater.data[23]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[24], greater.data[24]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[25], greater.data[25]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[26], greater.data[26]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[27], greater.data[27]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[28], greater.data[28]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[29], greater.data[29]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[30], greater.data[30]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[31], greater.data[31]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[32], greater.data[32]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[33], greater.data[33]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[34], greater.data[34]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[35], greater.data[35]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[36], greater.data[36]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[37], greater.data[37]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[38], greater.data[38]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[39], greater.data[39]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[40], greater.data[40]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[41], greater.data[41]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[42], greater.data[42]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[43], greater.data[43]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[44], greater.data[44]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[45], greater.data[45]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[46], greater.data[46]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[47], greater.data[47]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[48], greater.data[48]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[49], greater.data[49]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[50], greater.data[50]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[51], greater.data[51]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[52], greater.data[52]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[53], greater.data[53]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[54], greater.data[54]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[55], greater.data[55]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[56], greater.data[56]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[57], greater.data[57]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[58], greater.data[58]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[59], greater.data[59]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[60], greater.data[60]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[61], greater.data[61]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[62], greater.data[62]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[63], greater.data[63]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[64], greater.data[64]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[65], greater.data[65]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[66], greater.data[66]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[67], greater.data[67]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[68], greater.data[68]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[69], greater.data[69]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[70], greater.data[70]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[71], greater.data[71]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[72], greater.data[72]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[73], greater.data[73]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[74], greater.data[74]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[75], greater.data[75]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[76], greater.data[76]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[77], greater.data[77]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[78], greater.data[78]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[79], greater.data[79]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[80], greater.data[80]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[81], greater.data[81]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[82], greater.data[82]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[83], greater.data[83]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[84], greater.data[84]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[85], greater.data[85]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[86], greater.data[86]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[87], greater.data[87]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[88], greater.data[88]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[89], greater.data[89]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[90], greater.data[90]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[91], greater.data[91]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[92], greater.data[92]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[93], greater.data[93]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[94], greater.data[94]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[95], greater.data[95]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[96], greater.data[96]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[97], greater.data[97]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[98], greater.data[98]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[99], greater.data[99]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[100], greater.data[100]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[101], greater.data[101]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[102], greater.data[102]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[103], greater.data[103]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[104], greater.data[104]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[105], greater.data[105]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[106], greater.data[106]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[107], greater.data[107]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[108], greater.data[108]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[109], greater.data[109]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[110], greater.data[110]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[111], greater.data[111]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[112], greater.data[112]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[113], greater.data[113]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[114], greater.data[114]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[115], greater.data[115]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[116], greater.data[116]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[117], greater.data[117]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[118], greater.data[118]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[119], greater.data[119]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[120], greater.data[120]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[121], greater.data[121]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[122], greater.data[122]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[123], greater.data[123]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[124], greater.data[124]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[125], greater.data[125]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[126], greater.data[126]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[127], greater.data[127]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[128], greater.data[128]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[129], greater.data[129]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[130], greater.data[130]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[131], greater.data[131]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[132], greater.data[132]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[133], greater.data[133]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[134], greater.data[134]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[135], greater.data[135]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[136], greater.data[136]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[137], greater.data[137]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[138], greater.data[138]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[139], greater.data[139]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[140], greater.data[140]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[141], greater.data[141]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[142], greater.data[142]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[143], greater.data[143]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[144], greater.data[144]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[145], greater.data[145]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[146], greater.data[146]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[147], greater.data[147]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[148], greater.data[148]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[149], greater.data[149]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[150], greater.data[150]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[151], greater.data[151]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[152], greater.data[152]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[153], greater.data[153]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[154], greater.data[154]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[155], greater.data[155]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[156], greater.data[156]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[157], greater.data[157]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[158], greater.data[158]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[159], greater.data[159]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[160], greater.data[160]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[161], greater.data[161]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[162], greater.data[162]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[163], greater.data[163]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[164], greater.data[164]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[165], greater.data[165]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[166], greater.data[166]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[167], greater.data[167]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[168], greater.data[168]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[169], greater.data[169]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[170], greater.data[170]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[171], greater.data[171]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[172], greater.data[172]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[173], greater.data[173]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[174], greater.data[174]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[175], greater.data[175]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[176], greater.data[176]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[177], greater.data[177]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[178], greater.data[178]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[179], greater.data[179]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[180], greater.data[180]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[181], greater.data[181]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[182], greater.data[182]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[183], greater.data[183]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[184], greater.data[184]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[185], greater.data[185]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[186], greater.data[186]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[187], greater.data[187]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[188], greater.data[188]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[189], greater.data[189]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[190], greater.data[190]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[191], greater.data[191]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[192], greater.data[192]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[193], greater.data[193]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[194], greater.data[194]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[195], greater.data[195]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[196], greater.data[196]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[197], greater.data[197]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[198], greater.data[198]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[199], greater.data[199]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[200], greater.data[200]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[201], greater.data[201]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[202], greater.data[202]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[203], greater.data[203]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[204], greater.data[204]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[205], greater.data[205]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[206], greater.data[206]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[207], greater.data[207]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[208], greater.data[208]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[209], greater.data[209]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[210], greater.data[210]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[211], greater.data[211]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[212], greater.data[212]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[213], greater.data[213]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[214], greater.data[214]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[215], greater.data[215]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[216], greater.data[216]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[217], greater.data[217]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[218], greater.data[218]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[219], greater.data[219]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[220], greater.data[220]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[221], greater.data[221]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[222], greater.data[222]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[223], greater.data[223]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[224], greater.data[224]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[225], greater.data[225]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[226], greater.data[226]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[227], greater.data[227]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[228], greater.data[228]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[229], greater.data[229]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[230], greater.data[230]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[231], greater.data[231]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[232], greater.data[232]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[233], greater.data[233]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[234], greater.data[234]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[235], greater.data[235]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[236], greater.data[236]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[237], greater.data[237]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[238], greater.data[238]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[239], greater.data[239]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[240], greater.data[240]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[241], greater.data[241]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[242], greater.data[242]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[243], greater.data[243]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[244], greater.data[244]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[245], greater.data[245]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[246], greater.data[246]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[247], greater.data[247]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[248], greater.data[248]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.data[249], greater.data[249]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_flash_program_t lesser = info.test_msg;
    sbp_msg_flash_program_t greater = info.test_msg;
    make_lesser_greater(lesser.target, greater.target);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_flash_program_t>::id,
  // SbpMsgFlashProgram);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_flash_program_t>::name,
               "MSG_FLASH_PROGRAM");
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_flash_program_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_flash_program_t>::get(const_sbp_msg_t);
  sbp_msg_flash_program_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_flash_program_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_flash_program_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.flash_program, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_flash_program_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.flash_program, info.test_msg);
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_flash_program_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_flash_program_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[255];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_flash_program_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_flash_program_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_flash_program_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0,
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

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgFlashProgram,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_flash_MsgFlashProgram0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgFlashProgram,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace