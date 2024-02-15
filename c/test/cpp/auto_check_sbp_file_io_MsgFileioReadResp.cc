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
// spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadResp.yaml by
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
class Testauto_check_sbp_file_io_MsgFileioReadResp0 : public ::testing::Test {
 public:
  Testauto_check_sbp_file_io_MsgFileioReadResp0() {
    assign(test_msg_.contents[0], 73);

    assign(test_msg_.contents[1], 231);

    assign(test_msg_.contents[2], 227);

    assign(test_msg_.contents[3], 179);

    assign(test_msg_.contents[4], 18);

    assign(test_msg_.contents[5], 76);

    assign(test_msg_.contents[6], 68);

    assign(test_msg_.contents[7], 229);

    assign(test_msg_.contents[8], 216);

    assign(test_msg_.contents[9], 21);

    assign(test_msg_.contents[10], 98);

    assign(test_msg_.contents[11], 183);

    assign(test_msg_.contents[12], 69);

    assign(test_msg_.contents[13], 190);

    assign(test_msg_.contents[14], 5);

    assign(test_msg_.contents[15], 252);

    assign(test_msg_.contents[16], 176);

    assign(test_msg_.contents[17], 55);

    assign(test_msg_.contents[18], 32);

    assign(test_msg_.contents[19], 78);

    assign(test_msg_.contents[20], 8);

    assign(test_msg_.contents[21], 52);

    assign(test_msg_.contents[22], 127);

    assign(test_msg_.contents[23], 50);

    assign(test_msg_.contents[24], 71);

    assign(test_msg_.contents[25], 106);

    assign(test_msg_.contents[26], 61);

    assign(test_msg_.contents[27], 79);

    assign(test_msg_.contents[28], 191);

    assign(test_msg_.contents[29], 106);

    assign(test_msg_.contents[30], 46);

    assign(test_msg_.contents[31], 79);

    assign(test_msg_.contents[32], 118);

    assign(test_msg_.contents[33], 248);

    assign(test_msg_.contents[34], 118);

    assign(test_msg_.contents[35], 207);

    assign(test_msg_.contents[36], 206);

    assign(test_msg_.contents[37], 210);

    assign(test_msg_.contents[38], 91);

    assign(test_msg_.contents[39], 73);

    assign(test_msg_.contents[40], 251);

    assign(test_msg_.contents[41], 81);

    assign(test_msg_.contents[42], 131);

    assign(test_msg_.contents[43], 205);

    assign(test_msg_.contents[44], 193);

    assign(test_msg_.contents[45], 146);

    assign(test_msg_.contents[46], 206);

    assign(test_msg_.contents[47], 185);

    assign(test_msg_.contents[48], 140);

    assign(test_msg_.contents[49], 249);

    assign(test_msg_.contents[50], 163);

    assign(test_msg_.contents[51], 231);

    assign(test_msg_.contents[52], 65);

    assign(test_msg_.contents[53], 67);

    assign(test_msg_.contents[54], 94);

    assign(test_msg_.contents[55], 250);

    assign(test_msg_.contents[56], 109);

    assign(test_msg_.contents[57], 152);

    assign(test_msg_.contents[58], 95);

    assign(test_msg_.contents[59], 123);

    assign(test_msg_.contents[60], 77);

    assign(test_msg_.contents[61], 224);

    assign(test_msg_.contents[62], 124);

    assign(test_msg_.contents[63], 238);

    assign(test_msg_.contents[64], 205);

    assign(test_msg_.contents[65], 65);

    assign(test_msg_.contents[66], 103);

    assign(test_msg_.contents[67], 35);

    assign(test_msg_.contents[68], 104);

    assign(test_msg_.contents[69], 209);

    assign(test_msg_.contents[70], 5);

    assign(test_msg_.contents[71], 191);

    assign(test_msg_.contents[72], 47);

    assign(test_msg_.contents[73], 249);

    assign(test_msg_.contents[74], 176);

    assign(test_msg_.contents[75], 166);

    assign(test_msg_.contents[76], 213);

    assign(test_msg_.contents[77], 46);

    assign(test_msg_.contents[78], 192);

    assign(test_msg_.contents[79], 86);

    assign(test_msg_.contents[80], 32);

    assign(test_msg_.contents[81], 103);

    assign(test_msg_.contents[82], 146);

    assign(test_msg_.contents[83], 252);

    assign(test_msg_.contents[84], 4);

    assign(test_msg_.contents[85], 16);

    assign(test_msg_.contents[86], 54);

    assign(test_msg_.contents[87], 161);

    assign(test_msg_.contents[88], 60);

    assign(test_msg_.contents[89], 6);

    assign(test_msg_.contents[90], 13);

    assign(test_msg_.contents[91], 191);

    assign(test_msg_.contents[92], 116);

    assign(test_msg_.contents[93], 182);

    assign(test_msg_.contents[94], 42);

    assign(test_msg_.contents[95], 191);

    assign(test_msg_.contents[96], 213);

    assign(test_msg_.contents[97], 20);

    assign(test_msg_.contents[98], 217);

    assign(test_msg_.contents[99], 8);

    assign(test_msg_.contents[100], 142);

    assign(test_msg_.contents[101], 187);

    assign(test_msg_.contents[102], 238);

    assign(test_msg_.contents[103], 120);

    assign(test_msg_.contents[104], 184);

    assign(test_msg_.contents[105], 250);

    assign(test_msg_.contents[106], 31);

    assign(test_msg_.contents[107], 151);

    assign(test_msg_.contents[108], 37);

    assign(test_msg_.contents[109], 51);

    assign(test_msg_.contents[110], 177);

    assign(test_msg_.contents[111], 130);

    assign(test_msg_.contents[112], 190);

    assign(test_msg_.contents[113], 155);

    assign(test_msg_.contents[114], 71);

    assign(test_msg_.contents[115], 68);

    assign(test_msg_.contents[116], 56);

    assign(test_msg_.contents[117], 238);

    assign(test_msg_.contents[118], 92);

    assign(test_msg_.contents[119], 130);

    assign(test_msg_.contents[120], 37);

    assign(test_msg_.contents[121], 137);

    assign(test_msg_.contents[122], 146);

    assign(test_msg_.contents[123], 246);

    assign(test_msg_.contents[124], 114);

    assign(test_msg_.contents[125], 116);

    assign(test_msg_.contents[126], 138);

    assign(test_msg_.contents[127], 165);

    assign(test_msg_.contents[128], 217);

    assign(test_msg_.contents[129], 79);

    assign(test_msg_.contents[130], 10);

    assign(test_msg_.contents[131], 189);

    assign(test_msg_.contents[132], 128);

    assign(test_msg_.contents[133], 189);

    assign(test_msg_.contents[134], 2);

    assign(test_msg_.contents[135], 240);

    assign(test_msg_.contents[136], 92);

    assign(test_msg_.contents[137], 28);

    assign(test_msg_.contents[138], 126);

    assign(test_msg_.contents[139], 105);

    assign(test_msg_.contents[140], 236);

    assign(test_msg_.contents[141], 228);

    assign(test_msg_.contents[142], 194);

    assign(test_msg_.contents[143], 0);

    assign(test_msg_.contents[144], 51);

    assign(test_msg_.contents[145], 61);

    assign(test_msg_.contents[146], 74);

    assign(test_msg_.contents[147], 41);

    assign(test_msg_.contents[148], 10);

    assign(test_msg_.contents[149], 239);

    assign(test_msg_.contents[150], 133);

    assign(test_msg_.contents[151], 106);

    assign(test_msg_.contents[152], 190);

    assign(test_msg_.contents[153], 30);

    assign(test_msg_.contents[154], 27);

    assign(test_msg_.contents[155], 3);

    assign(test_msg_.contents[156], 240);

    assign(test_msg_.contents[157], 205);

    assign(test_msg_.contents[158], 253);

    assign(test_msg_.contents[159], 113);

    assign(test_msg_.contents[160], 25);

    assign(test_msg_.contents[161], 28);

    assign(test_msg_.contents[162], 187);

    assign(test_msg_.contents[163], 81);

    assign(test_msg_.contents[164], 101);

    assign(test_msg_.contents[165], 216);

    assign(test_msg_.contents[166], 121);

    assign(test_msg_.contents[167], 41);

    assign(test_msg_.contents[168], 179);

    assign(test_msg_.contents[169], 120);

    assign(test_msg_.contents[170], 152);

    assign(test_msg_.contents[171], 18);

    assign(test_msg_.contents[172], 116);

    assign(test_msg_.contents[173], 53);

    assign(test_msg_.contents[174], 212);

    assign(test_msg_.contents[175], 100);

    assign(test_msg_.contents[176], 2);

    assign(test_msg_.contents[177], 114);

    assign(test_msg_.contents[178], 198);

    assign(test_msg_.contents[179], 200);

    assign(test_msg_.contents[180], 10);

    assign(test_msg_.contents[181], 147);

    assign(test_msg_.contents[182], 25);

    assign(test_msg_.contents[183], 33);

    assign(test_msg_.contents[184], 115);

    assign(test_msg_.contents[185], 208);

    assign(test_msg_.contents[186], 113);

    assign(test_msg_.contents[187], 60);

    assign(test_msg_.contents[188], 179);

    assign(test_msg_.contents[189], 183);

    assign(test_msg_.contents[190], 0);

    assign(test_msg_.contents[191], 41);

    assign(test_msg_.contents[192], 217);

    assign(test_msg_.contents[193], 206);

    assign(test_msg_.contents[194], 255);

    assign(test_msg_.contents[195], 211);

    assign(test_msg_.contents[196], 225);

    assign(test_msg_.contents[197], 142);

    assign(test_msg_.contents[198], 191);

    assign(test_msg_.contents[199], 133);

    assign(test_msg_.contents[200], 81);

    assign(test_msg_.contents[201], 15);

    assign(test_msg_.contents[202], 248);

    assign(test_msg_.contents[203], 193);

    assign(test_msg_.contents[204], 66);

    assign(test_msg_.contents[205], 191);

    assign(test_msg_.contents[206], 244);

    assign(test_msg_.contents[207], 221);

    assign(test_msg_.contents[208], 248);

    assign(test_msg_.contents[209], 199);

    assign(test_msg_.contents[210], 241);

    assign(test_msg_.contents[211], 112);

    assign(test_msg_.contents[212], 51);

    assign(test_msg_.contents[213], 1);

    assign(test_msg_.contents[214], 180);

    assign(test_msg_.contents[215], 180);

    assign(test_msg_.contents[216], 125);

    assign(test_msg_.contents[217], 97);

    assign(test_msg_.contents[218], 145);

    assign(test_msg_.contents[219], 25);

    assign(test_msg_.contents[220], 72);

    assign(test_msg_.contents[221], 210);

    assign(test_msg_.contents[222], 215);

    assign(test_msg_.contents[223], 208);

    assign(test_msg_.contents[224], 15);

    assign(test_msg_.contents[225], 126);

    assign(test_msg_.contents[226], 56);

    assign(test_msg_.contents[227], 38);

    assign(test_msg_.contents[228], 65);

    assign(test_msg_.contents[229], 4);

    assign(test_msg_.contents[230], 64);

    assign(test_msg_.contents[231], 19);

    assign(test_msg_.contents[232], 74);

    assign(test_msg_.contents[233], 223);

    assign(test_msg_.contents[234], 111);

    assign(test_msg_.contents[235], 109);

    assign(test_msg_.contents[236], 52);

    assign(test_msg_.contents[237], 43);

    assign(test_msg_.contents[238], 167);

    assign(test_msg_.contents[239], 186);

    assign(test_msg_.contents[240], 202);

    assign(test_msg_.contents[241], 111);

    assign(test_msg_.contents[242], 11);

    assign(test_msg_.contents[243], 91);

    assign(test_msg_.contents[244], 21);

    assign(test_msg_.contents[245], 236);

    assign(test_msg_.contents[246], 234);

    assign(test_msg_.contents[247], 196);

    assign(test_msg_.contents[248], 36);

    assign(test_msg_.contents[249], 171);

    assign(test_msg_.contents[250], 147);
    assign(test_msg_.n_contents, 251);
    assign(test_msg_.sequence, 259241795);
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
      : public sbp::MessageHandler<sbp_msg_fileio_read_resp_t> {
    using sbp::MessageHandler<sbp_msg_fileio_read_resp_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_fileio_read_resp_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_fileio_read_resp_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgFileioReadResp,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_fileio_read_resp_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgFileioReadResp);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->fileio_read_resp,
             sizeof(msg->fileio_read_resp));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_fileio_read_resp_t test_msg;
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
    memcpy(&info.test_msg_wrapped.fileio_read_resp, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgFileioReadResp);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0xf00a;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 255;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_fileio_read_resp_t &lesser,
                        const sbp_msg_fileio_read_resp_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_fileio_read_resp_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_fileio_read_resp_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_fileio_read_resp_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_fileio_read_resp_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_fileio_read_resp_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_fileio_read_resp_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgFileioReadResp, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgFileioReadResp, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgFileioReadResp, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgFileioReadResp, &wrapped_greater,
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
  sbp_msg_fileio_read_resp_t test_msg_{};
  uint8_t encoded_frame_[255 + 8] = {
      85,  163, 0,   195, 4,   255, 67,  183, 115, 15,  73,  231, 227, 179, 18,
      76,  68,  229, 216, 21,  98,  183, 69,  190, 5,   252, 176, 55,  32,  78,
      8,   52,  127, 50,  71,  106, 61,  79,  191, 106, 46,  79,  118, 248, 118,
      207, 206, 210, 91,  73,  251, 81,  131, 205, 193, 146, 206, 185, 140, 249,
      163, 231, 65,  67,  94,  250, 109, 152, 95,  123, 77,  224, 124, 238, 205,
      65,  103, 35,  104, 209, 5,   191, 47,  249, 176, 166, 213, 46,  192, 86,
      32,  103, 146, 252, 4,   16,  54,  161, 60,  6,   13,  191, 116, 182, 42,
      191, 213, 20,  217, 8,   142, 187, 238, 120, 184, 250, 31,  151, 37,  51,
      177, 130, 190, 155, 71,  68,  56,  238, 92,  130, 37,  137, 146, 246, 114,
      116, 138, 165, 217, 79,  10,  189, 128, 189, 2,   240, 92,  28,  126, 105,
      236, 228, 194, 0,   51,  61,  74,  41,  10,  239, 133, 106, 190, 30,  27,
      3,   240, 205, 253, 113, 25,  28,  187, 81,  101, 216, 121, 41,  179, 120,
      152, 18,  116, 53,  212, 100, 2,   114, 198, 200, 10,  147, 25,  33,  115,
      208, 113, 60,  179, 183, 0,   41,  217, 206, 255, 211, 225, 142, 191, 133,
      81,  15,  248, 193, 66,  191, 244, 221, 248, 199, 241, 112, 51,  1,   180,
      180, 125, 97,  145, 25,  72,  210, 215, 208, 15,  126, 56,  38,  65,  4,
      64,  19,  74,  223, 111, 109, 52,  43,  167, 186, 202, 111, 11,  91,  21,
      236, 234, 196, 36,  171, 147, 10,  240,
  };
  uint8_t encoded_payload_[255] = {
      67,  183, 115, 15,  73,  231, 227, 179, 18,  76,  68,  229, 216, 21,  98,
      183, 69,  190, 5,   252, 176, 55,  32,  78,  8,   52,  127, 50,  71,  106,
      61,  79,  191, 106, 46,  79,  118, 248, 118, 207, 206, 210, 91,  73,  251,
      81,  131, 205, 193, 146, 206, 185, 140, 249, 163, 231, 65,  67,  94,  250,
      109, 152, 95,  123, 77,  224, 124, 238, 205, 65,  103, 35,  104, 209, 5,
      191, 47,  249, 176, 166, 213, 46,  192, 86,  32,  103, 146, 252, 4,   16,
      54,  161, 60,  6,   13,  191, 116, 182, 42,  191, 213, 20,  217, 8,   142,
      187, 238, 120, 184, 250, 31,  151, 37,  51,  177, 130, 190, 155, 71,  68,
      56,  238, 92,  130, 37,  137, 146, 246, 114, 116, 138, 165, 217, 79,  10,
      189, 128, 189, 2,   240, 92,  28,  126, 105, 236, 228, 194, 0,   51,  61,
      74,  41,  10,  239, 133, 106, 190, 30,  27,  3,   240, 205, 253, 113, 25,
      28,  187, 81,  101, 216, 121, 41,  179, 120, 152, 18,  116, 53,  212, 100,
      2,   114, 198, 200, 10,  147, 25,  33,  115, 208, 113, 60,  179, 183, 0,
      41,  217, 206, 255, 211, 225, 142, 191, 133, 81,  15,  248, 193, 66,  191,
      244, 221, 248, 199, 241, 112, 51,  1,   180, 180, 125, 97,  145, 25,  72,
      210, 215, 208, 15,  126, 56,  38,  65,  4,   64,  19,  74,  223, 111, 109,
      52,  43,  167, 186, 202, 111, 11,  91,  21,  236, 234, 196, 36,  171, 147,
  };
};

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_fileio_read_resp_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgFileioReadResp, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[255];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_fileio_read_resp_encode(&buf[0], sizeof(buf), &n_written,
                                            &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgFileioReadResp, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[255];

  EXPECT_EQ(sbp_msg_fileio_read_resp_encode(&buf[0], sizeof(buf), nullptr,
                                            &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}
TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[255];

  for (uint8_t i = 0; i < 255; i++) {
    EXPECT_EQ(
        sbp_msg_fileio_read_resp_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_fileio_read_resp_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_fileio_read_resp_decode(&info.encoded_payload[0],
                                            info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgFileioReadResp, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_fileio_read_resp_t msg{};

  EXPECT_EQ(sbp_msg_fileio_read_resp_decode(&info.encoded_payload[0],
                                            info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_fileio_read_resp_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_fileio_read_resp_t t{};
      return sbp_msg_fileio_read_resp_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_fileio_read_resp_t t{};
      t.n_contents = 1;
      return sbp_msg_fileio_read_resp_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_fileio_read_resp_decode(&info.encoded_payload[0], i,
                                              nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0,
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

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, SlowRead) {
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

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, BadCRC) {
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

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_fileio_read_resp_send(&state, info.sender_id,
                                          &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgFileioReadResp, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgFileioReadResp, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgFileioReadResp, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, Comparison) {
  auto info = get_test_msg_info();

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[0], greater.contents[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[1], greater.contents[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[2], greater.contents[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[3], greater.contents[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[4], greater.contents[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[5], greater.contents[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[6], greater.contents[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[7], greater.contents[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[8], greater.contents[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[9], greater.contents[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[10], greater.contents[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[11], greater.contents[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[12], greater.contents[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[13], greater.contents[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[14], greater.contents[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[15], greater.contents[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[16], greater.contents[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[17], greater.contents[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[18], greater.contents[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[19], greater.contents[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[20], greater.contents[20]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[21], greater.contents[21]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[22], greater.contents[22]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[23], greater.contents[23]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[24], greater.contents[24]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[25], greater.contents[25]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[26], greater.contents[26]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[27], greater.contents[27]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[28], greater.contents[28]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[29], greater.contents[29]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[30], greater.contents[30]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[31], greater.contents[31]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[32], greater.contents[32]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[33], greater.contents[33]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[34], greater.contents[34]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[35], greater.contents[35]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[36], greater.contents[36]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[37], greater.contents[37]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[38], greater.contents[38]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[39], greater.contents[39]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[40], greater.contents[40]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[41], greater.contents[41]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[42], greater.contents[42]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[43], greater.contents[43]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[44], greater.contents[44]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[45], greater.contents[45]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[46], greater.contents[46]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[47], greater.contents[47]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[48], greater.contents[48]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[49], greater.contents[49]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[50], greater.contents[50]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[51], greater.contents[51]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[52], greater.contents[52]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[53], greater.contents[53]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[54], greater.contents[54]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[55], greater.contents[55]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[56], greater.contents[56]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[57], greater.contents[57]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[58], greater.contents[58]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[59], greater.contents[59]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[60], greater.contents[60]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[61], greater.contents[61]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[62], greater.contents[62]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[63], greater.contents[63]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[64], greater.contents[64]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[65], greater.contents[65]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[66], greater.contents[66]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[67], greater.contents[67]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[68], greater.contents[68]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[69], greater.contents[69]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[70], greater.contents[70]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[71], greater.contents[71]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[72], greater.contents[72]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[73], greater.contents[73]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[74], greater.contents[74]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[75], greater.contents[75]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[76], greater.contents[76]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[77], greater.contents[77]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[78], greater.contents[78]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[79], greater.contents[79]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[80], greater.contents[80]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[81], greater.contents[81]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[82], greater.contents[82]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[83], greater.contents[83]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[84], greater.contents[84]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[85], greater.contents[85]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[86], greater.contents[86]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[87], greater.contents[87]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[88], greater.contents[88]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[89], greater.contents[89]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[90], greater.contents[90]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[91], greater.contents[91]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[92], greater.contents[92]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[93], greater.contents[93]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[94], greater.contents[94]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[95], greater.contents[95]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[96], greater.contents[96]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[97], greater.contents[97]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[98], greater.contents[98]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[99], greater.contents[99]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[100], greater.contents[100]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[101], greater.contents[101]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[102], greater.contents[102]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[103], greater.contents[103]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[104], greater.contents[104]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[105], greater.contents[105]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[106], greater.contents[106]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[107], greater.contents[107]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[108], greater.contents[108]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[109], greater.contents[109]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[110], greater.contents[110]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[111], greater.contents[111]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[112], greater.contents[112]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[113], greater.contents[113]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[114], greater.contents[114]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[115], greater.contents[115]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[116], greater.contents[116]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[117], greater.contents[117]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[118], greater.contents[118]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[119], greater.contents[119]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[120], greater.contents[120]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[121], greater.contents[121]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[122], greater.contents[122]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[123], greater.contents[123]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[124], greater.contents[124]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[125], greater.contents[125]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[126], greater.contents[126]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[127], greater.contents[127]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[128], greater.contents[128]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[129], greater.contents[129]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[130], greater.contents[130]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[131], greater.contents[131]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[132], greater.contents[132]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[133], greater.contents[133]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[134], greater.contents[134]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[135], greater.contents[135]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[136], greater.contents[136]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[137], greater.contents[137]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[138], greater.contents[138]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[139], greater.contents[139]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[140], greater.contents[140]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[141], greater.contents[141]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[142], greater.contents[142]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[143], greater.contents[143]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[144], greater.contents[144]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[145], greater.contents[145]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[146], greater.contents[146]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[147], greater.contents[147]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[148], greater.contents[148]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[149], greater.contents[149]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[150], greater.contents[150]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[151], greater.contents[151]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[152], greater.contents[152]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[153], greater.contents[153]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[154], greater.contents[154]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[155], greater.contents[155]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[156], greater.contents[156]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[157], greater.contents[157]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[158], greater.contents[158]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[159], greater.contents[159]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[160], greater.contents[160]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[161], greater.contents[161]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[162], greater.contents[162]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[163], greater.contents[163]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[164], greater.contents[164]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[165], greater.contents[165]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[166], greater.contents[166]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[167], greater.contents[167]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[168], greater.contents[168]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[169], greater.contents[169]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[170], greater.contents[170]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[171], greater.contents[171]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[172], greater.contents[172]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[173], greater.contents[173]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[174], greater.contents[174]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[175], greater.contents[175]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[176], greater.contents[176]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[177], greater.contents[177]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[178], greater.contents[178]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[179], greater.contents[179]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[180], greater.contents[180]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[181], greater.contents[181]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[182], greater.contents[182]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[183], greater.contents[183]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[184], greater.contents[184]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[185], greater.contents[185]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[186], greater.contents[186]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[187], greater.contents[187]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[188], greater.contents[188]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[189], greater.contents[189]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[190], greater.contents[190]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[191], greater.contents[191]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[192], greater.contents[192]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[193], greater.contents[193]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[194], greater.contents[194]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[195], greater.contents[195]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[196], greater.contents[196]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[197], greater.contents[197]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[198], greater.contents[198]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[199], greater.contents[199]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[200], greater.contents[200]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[201], greater.contents[201]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[202], greater.contents[202]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[203], greater.contents[203]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[204], greater.contents[204]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[205], greater.contents[205]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[206], greater.contents[206]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[207], greater.contents[207]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[208], greater.contents[208]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[209], greater.contents[209]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[210], greater.contents[210]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[211], greater.contents[211]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[212], greater.contents[212]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[213], greater.contents[213]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[214], greater.contents[214]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[215], greater.contents[215]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[216], greater.contents[216]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[217], greater.contents[217]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[218], greater.contents[218]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[219], greater.contents[219]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[220], greater.contents[220]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[221], greater.contents[221]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[222], greater.contents[222]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[223], greater.contents[223]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[224], greater.contents[224]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[225], greater.contents[225]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[226], greater.contents[226]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[227], greater.contents[227]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[228], greater.contents[228]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[229], greater.contents[229]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[230], greater.contents[230]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[231], greater.contents[231]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[232], greater.contents[232]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[233], greater.contents[233]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[234], greater.contents[234]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[235], greater.contents[235]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[236], greater.contents[236]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[237], greater.contents[237]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[238], greater.contents[238]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[239], greater.contents[239]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[240], greater.contents[240]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[241], greater.contents[241]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[242], greater.contents[242]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[243], greater.contents[243]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[244], greater.contents[244]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[245], greater.contents[245]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[246], greater.contents[246]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[247], greater.contents[247]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[248], greater.contents[248]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[249], greater.contents[249]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.contents[250], greater.contents[250]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.n_contents, greater.n_contents);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_fileio_read_resp_t lesser = info.test_msg;
    sbp_msg_fileio_read_resp_t greater = info.test_msg;
    make_lesser_greater(lesser.sequence, greater.sequence);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_fileio_read_resp_t>::id,
  // SbpMsgFileioReadResp);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_fileio_read_resp_t>::name,
               "MSG_FILEIO_READ_RESP");
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_fileio_read_resp_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_fileio_read_resp_t>::get(const_sbp_msg_t);
  sbp_msg_fileio_read_resp_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_fileio_read_resp_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_fileio_read_resp_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.fileio_read_resp, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_fileio_read_resp_t>::to_sbp_msg(info.test_msg,
                                                             &msg2);
  EXPECT_EQ(msg2.fileio_read_resp, info.test_msg);
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_fileio_read_resp_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_fileio_read_resp_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[255];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_fileio_read_resp_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_fileio_read_resp_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_fileio_read_resp_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0,
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

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgFileioReadResp,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_file_io_MsgFileioReadResp0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgFileioReadResp,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace