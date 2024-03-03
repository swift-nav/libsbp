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
// spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCellModemStatus.yaml by
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
class Testauto_check_sbp_piksi_MsgCellModemStatus0 : public ::testing::Test {
 public:
  Testauto_check_sbp_piksi_MsgCellModemStatus0() {
    assign(test_msg_.n_reserved, 250);

    assign(test_msg_.reserved[0], 123);

    assign(test_msg_.reserved[1], 242);

    assign(test_msg_.reserved[2], 46);

    assign(test_msg_.reserved[3], 52);

    assign(test_msg_.reserved[4], 64);

    assign(test_msg_.reserved[5], 176);

    assign(test_msg_.reserved[6], 154);

    assign(test_msg_.reserved[7], 98);

    assign(test_msg_.reserved[8], 43);

    assign(test_msg_.reserved[9], 132);

    assign(test_msg_.reserved[10], 196);

    assign(test_msg_.reserved[11], 89);

    assign(test_msg_.reserved[12], 253);

    assign(test_msg_.reserved[13], 161);

    assign(test_msg_.reserved[14], 250);

    assign(test_msg_.reserved[15], 174);

    assign(test_msg_.reserved[16], 204);

    assign(test_msg_.reserved[17], 110);

    assign(test_msg_.reserved[18], 47);

    assign(test_msg_.reserved[19], 38);

    assign(test_msg_.reserved[20], 187);

    assign(test_msg_.reserved[21], 63);

    assign(test_msg_.reserved[22], 102);

    assign(test_msg_.reserved[23], 177);

    assign(test_msg_.reserved[24], 162);

    assign(test_msg_.reserved[25], 49);

    assign(test_msg_.reserved[26], 80);

    assign(test_msg_.reserved[27], 194);

    assign(test_msg_.reserved[28], 37);

    assign(test_msg_.reserved[29], 107);

    assign(test_msg_.reserved[30], 60);

    assign(test_msg_.reserved[31], 225);

    assign(test_msg_.reserved[32], 52);

    assign(test_msg_.reserved[33], 101);

    assign(test_msg_.reserved[34], 178);

    assign(test_msg_.reserved[35], 142);

    assign(test_msg_.reserved[36], 246);

    assign(test_msg_.reserved[37], 21);

    assign(test_msg_.reserved[38], 17);

    assign(test_msg_.reserved[39], 93);

    assign(test_msg_.reserved[40], 75);

    assign(test_msg_.reserved[41], 169);

    assign(test_msg_.reserved[42], 86);

    assign(test_msg_.reserved[43], 16);

    assign(test_msg_.reserved[44], 209);

    assign(test_msg_.reserved[45], 80);

    assign(test_msg_.reserved[46], 243);

    assign(test_msg_.reserved[47], 30);

    assign(test_msg_.reserved[48], 206);

    assign(test_msg_.reserved[49], 220);

    assign(test_msg_.reserved[50], 206);

    assign(test_msg_.reserved[51], 115);

    assign(test_msg_.reserved[52], 47);

    assign(test_msg_.reserved[53], 154);

    assign(test_msg_.reserved[54], 91);

    assign(test_msg_.reserved[55], 227);

    assign(test_msg_.reserved[56], 88);

    assign(test_msg_.reserved[57], 11);

    assign(test_msg_.reserved[58], 1);

    assign(test_msg_.reserved[59], 85);

    assign(test_msg_.reserved[60], 146);

    assign(test_msg_.reserved[61], 100);

    assign(test_msg_.reserved[62], 190);

    assign(test_msg_.reserved[63], 232);

    assign(test_msg_.reserved[64], 207);

    assign(test_msg_.reserved[65], 61);

    assign(test_msg_.reserved[66], 61);

    assign(test_msg_.reserved[67], 201);

    assign(test_msg_.reserved[68], 220);

    assign(test_msg_.reserved[69], 31);

    assign(test_msg_.reserved[70], 78);

    assign(test_msg_.reserved[71], 34);

    assign(test_msg_.reserved[72], 57);

    assign(test_msg_.reserved[73], 82);

    assign(test_msg_.reserved[74], 59);

    assign(test_msg_.reserved[75], 104);

    assign(test_msg_.reserved[76], 65);

    assign(test_msg_.reserved[77], 221);

    assign(test_msg_.reserved[78], 0);

    assign(test_msg_.reserved[79], 43);

    assign(test_msg_.reserved[80], 210);

    assign(test_msg_.reserved[81], 9);

    assign(test_msg_.reserved[82], 32);

    assign(test_msg_.reserved[83], 122);

    assign(test_msg_.reserved[84], 29);

    assign(test_msg_.reserved[85], 237);

    assign(test_msg_.reserved[86], 11);

    assign(test_msg_.reserved[87], 151);

    assign(test_msg_.reserved[88], 223);

    assign(test_msg_.reserved[89], 18);

    assign(test_msg_.reserved[90], 81);

    assign(test_msg_.reserved[91], 204);

    assign(test_msg_.reserved[92], 172);

    assign(test_msg_.reserved[93], 234);

    assign(test_msg_.reserved[94], 127);

    assign(test_msg_.reserved[95], 3);

    assign(test_msg_.reserved[96], 82);

    assign(test_msg_.reserved[97], 133);

    assign(test_msg_.reserved[98], 169);

    assign(test_msg_.reserved[99], 12);

    assign(test_msg_.reserved[100], 176);

    assign(test_msg_.reserved[101], 193);

    assign(test_msg_.reserved[102], 0);

    assign(test_msg_.reserved[103], 24);

    assign(test_msg_.reserved[104], 121);

    assign(test_msg_.reserved[105], 85);

    assign(test_msg_.reserved[106], 55);

    assign(test_msg_.reserved[107], 214);

    assign(test_msg_.reserved[108], 198);

    assign(test_msg_.reserved[109], 75);

    assign(test_msg_.reserved[110], 234);

    assign(test_msg_.reserved[111], 179);

    assign(test_msg_.reserved[112], 214);

    assign(test_msg_.reserved[113], 85);

    assign(test_msg_.reserved[114], 94);

    assign(test_msg_.reserved[115], 115);

    assign(test_msg_.reserved[116], 21);

    assign(test_msg_.reserved[117], 73);

    assign(test_msg_.reserved[118], 121);

    assign(test_msg_.reserved[119], 75);

    assign(test_msg_.reserved[120], 46);

    assign(test_msg_.reserved[121], 158);

    assign(test_msg_.reserved[122], 63);

    assign(test_msg_.reserved[123], 100);

    assign(test_msg_.reserved[124], 122);

    assign(test_msg_.reserved[125], 213);

    assign(test_msg_.reserved[126], 20);

    assign(test_msg_.reserved[127], 85);

    assign(test_msg_.reserved[128], 212);

    assign(test_msg_.reserved[129], 131);

    assign(test_msg_.reserved[130], 50);

    assign(test_msg_.reserved[131], 224);

    assign(test_msg_.reserved[132], 218);

    assign(test_msg_.reserved[133], 215);

    assign(test_msg_.reserved[134], 215);

    assign(test_msg_.reserved[135], 149);

    assign(test_msg_.reserved[136], 2);

    assign(test_msg_.reserved[137], 19);

    assign(test_msg_.reserved[138], 129);

    assign(test_msg_.reserved[139], 39);

    assign(test_msg_.reserved[140], 164);

    assign(test_msg_.reserved[141], 5);

    assign(test_msg_.reserved[142], 175);

    assign(test_msg_.reserved[143], 6);

    assign(test_msg_.reserved[144], 62);

    assign(test_msg_.reserved[145], 51);

    assign(test_msg_.reserved[146], 78);

    assign(test_msg_.reserved[147], 66);

    assign(test_msg_.reserved[148], 248);

    assign(test_msg_.reserved[149], 116);

    assign(test_msg_.reserved[150], 88);

    assign(test_msg_.reserved[151], 90);

    assign(test_msg_.reserved[152], 128);

    assign(test_msg_.reserved[153], 226);

    assign(test_msg_.reserved[154], 177);

    assign(test_msg_.reserved[155], 0);

    assign(test_msg_.reserved[156], 47);

    assign(test_msg_.reserved[157], 140);

    assign(test_msg_.reserved[158], 33);

    assign(test_msg_.reserved[159], 126);

    assign(test_msg_.reserved[160], 221);

    assign(test_msg_.reserved[161], 110);

    assign(test_msg_.reserved[162], 144);

    assign(test_msg_.reserved[163], 97);

    assign(test_msg_.reserved[164], 74);

    assign(test_msg_.reserved[165], 250);

    assign(test_msg_.reserved[166], 181);

    assign(test_msg_.reserved[167], 199);

    assign(test_msg_.reserved[168], 27);

    assign(test_msg_.reserved[169], 176);

    assign(test_msg_.reserved[170], 65);

    assign(test_msg_.reserved[171], 185);

    assign(test_msg_.reserved[172], 110);

    assign(test_msg_.reserved[173], 92);

    assign(test_msg_.reserved[174], 34);

    assign(test_msg_.reserved[175], 44);

    assign(test_msg_.reserved[176], 131);

    assign(test_msg_.reserved[177], 96);

    assign(test_msg_.reserved[178], 178);

    assign(test_msg_.reserved[179], 40);

    assign(test_msg_.reserved[180], 176);

    assign(test_msg_.reserved[181], 4);

    assign(test_msg_.reserved[182], 90);

    assign(test_msg_.reserved[183], 36);

    assign(test_msg_.reserved[184], 7);

    assign(test_msg_.reserved[185], 180);

    assign(test_msg_.reserved[186], 244);

    assign(test_msg_.reserved[187], 244);

    assign(test_msg_.reserved[188], 23);

    assign(test_msg_.reserved[189], 108);

    assign(test_msg_.reserved[190], 171);

    assign(test_msg_.reserved[191], 204);

    assign(test_msg_.reserved[192], 196);

    assign(test_msg_.reserved[193], 61);

    assign(test_msg_.reserved[194], 51);

    assign(test_msg_.reserved[195], 179);

    assign(test_msg_.reserved[196], 242);

    assign(test_msg_.reserved[197], 156);

    assign(test_msg_.reserved[198], 81);

    assign(test_msg_.reserved[199], 83);

    assign(test_msg_.reserved[200], 16);

    assign(test_msg_.reserved[201], 15);

    assign(test_msg_.reserved[202], 134);

    assign(test_msg_.reserved[203], 40);

    assign(test_msg_.reserved[204], 245);

    assign(test_msg_.reserved[205], 253);

    assign(test_msg_.reserved[206], 150);

    assign(test_msg_.reserved[207], 94);

    assign(test_msg_.reserved[208], 150);

    assign(test_msg_.reserved[209], 144);

    assign(test_msg_.reserved[210], 197);

    assign(test_msg_.reserved[211], 113);

    assign(test_msg_.reserved[212], 5);

    assign(test_msg_.reserved[213], 141);

    assign(test_msg_.reserved[214], 232);

    assign(test_msg_.reserved[215], 33);

    assign(test_msg_.reserved[216], 101);

    assign(test_msg_.reserved[217], 231);

    assign(test_msg_.reserved[218], 38);

    assign(test_msg_.reserved[219], 75);

    assign(test_msg_.reserved[220], 178);

    assign(test_msg_.reserved[221], 243);

    assign(test_msg_.reserved[222], 119);

    assign(test_msg_.reserved[223], 1);

    assign(test_msg_.reserved[224], 248);

    assign(test_msg_.reserved[225], 218);

    assign(test_msg_.reserved[226], 86);

    assign(test_msg_.reserved[227], 7);

    assign(test_msg_.reserved[228], 88);

    assign(test_msg_.reserved[229], 197);

    assign(test_msg_.reserved[230], 148);

    assign(test_msg_.reserved[231], 240);

    assign(test_msg_.reserved[232], 227);

    assign(test_msg_.reserved[233], 2);

    assign(test_msg_.reserved[234], 65);

    assign(test_msg_.reserved[235], 173);

    assign(test_msg_.reserved[236], 122);

    assign(test_msg_.reserved[237], 143);

    assign(test_msg_.reserved[238], 251);

    assign(test_msg_.reserved[239], 156);

    assign(test_msg_.reserved[240], 217);

    assign(test_msg_.reserved[241], 67);

    assign(test_msg_.reserved[242], 239);

    assign(test_msg_.reserved[243], 219);

    assign(test_msg_.reserved[244], 31);

    assign(test_msg_.reserved[245], 224);

    assign(test_msg_.reserved[246], 176);

    assign(test_msg_.reserved[247], 129);

    assign(test_msg_.reserved[248], 81);

    assign(test_msg_.reserved[249], 80);
    assign(test_msg_.signal_error_rate, 8588.2001953125);
    assign(test_msg_.signal_strength, 103);
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
      : public sbp::MessageHandler<sbp_msg_cell_modem_status_t> {
    using sbp::MessageHandler<sbp_msg_cell_modem_status_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_cell_modem_status_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_cell_modem_status_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgCellModemStatus,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_cell_modem_status_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgCellModemStatus);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->cell_modem_status,
             sizeof(msg->cell_modem_status));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_cell_modem_status_t test_msg;
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
    memcpy(&info.test_msg_wrapped.cell_modem_status, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgCellModemStatus);
    info.sender_id = 6931;
    info.preamble = 0x55;
    info.crc = 0xe628;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 255;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_cell_modem_status_t &lesser,
                        const sbp_msg_cell_modem_status_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_cell_modem_status_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_cell_modem_status_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_cell_modem_status_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_cell_modem_status_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_cell_modem_status_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_cell_modem_status_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgCellModemStatus, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgCellModemStatus, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgCellModemStatus, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgCellModemStatus, &wrapped_greater,
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
  sbp_msg_cell_modem_status_t test_msg_{};
  uint8_t encoded_frame_[255 + 8] = {
      85,  190, 0,   19,  27,  255, 103, 205, 48,  6,   70,  123, 242, 46,  52,
      64,  176, 154, 98,  43,  132, 196, 89,  253, 161, 250, 174, 204, 110, 47,
      38,  187, 63,  102, 177, 162, 49,  80,  194, 37,  107, 60,  225, 52,  101,
      178, 142, 246, 21,  17,  93,  75,  169, 86,  16,  209, 80,  243, 30,  206,
      220, 206, 115, 47,  154, 91,  227, 88,  11,  1,   85,  146, 100, 190, 232,
      207, 61,  61,  201, 220, 31,  78,  34,  57,  82,  59,  104, 65,  221, 0,
      43,  210, 9,   32,  122, 29,  237, 11,  151, 223, 18,  81,  204, 172, 234,
      127, 3,   82,  133, 169, 12,  176, 193, 0,   24,  121, 85,  55,  214, 198,
      75,  234, 179, 214, 85,  94,  115, 21,  73,  121, 75,  46,  158, 63,  100,
      122, 213, 20,  85,  212, 131, 50,  224, 218, 215, 215, 149, 2,   19,  129,
      39,  164, 5,   175, 6,   62,  51,  78,  66,  248, 116, 88,  90,  128, 226,
      177, 0,   47,  140, 33,  126, 221, 110, 144, 97,  74,  250, 181, 199, 27,
      176, 65,  185, 110, 92,  34,  44,  131, 96,  178, 40,  176, 4,   90,  36,
      7,   180, 244, 244, 23,  108, 171, 204, 196, 61,  51,  179, 242, 156, 81,
      83,  16,  15,  134, 40,  245, 253, 150, 94,  150, 144, 197, 113, 5,   141,
      232, 33,  101, 231, 38,  75,  178, 243, 119, 1,   248, 218, 86,  7,   88,
      197, 148, 240, 227, 2,   65,  173, 122, 143, 251, 156, 217, 67,  239, 219,
      31,  224, 176, 129, 81,  80,  40,  230,
  };
  uint8_t encoded_payload_[255] = {
      103, 205, 48,  6,   70,  123, 242, 46,  52,  64,  176, 154, 98,  43,  132,
      196, 89,  253, 161, 250, 174, 204, 110, 47,  38,  187, 63,  102, 177, 162,
      49,  80,  194, 37,  107, 60,  225, 52,  101, 178, 142, 246, 21,  17,  93,
      75,  169, 86,  16,  209, 80,  243, 30,  206, 220, 206, 115, 47,  154, 91,
      227, 88,  11,  1,   85,  146, 100, 190, 232, 207, 61,  61,  201, 220, 31,
      78,  34,  57,  82,  59,  104, 65,  221, 0,   43,  210, 9,   32,  122, 29,
      237, 11,  151, 223, 18,  81,  204, 172, 234, 127, 3,   82,  133, 169, 12,
      176, 193, 0,   24,  121, 85,  55,  214, 198, 75,  234, 179, 214, 85,  94,
      115, 21,  73,  121, 75,  46,  158, 63,  100, 122, 213, 20,  85,  212, 131,
      50,  224, 218, 215, 215, 149, 2,   19,  129, 39,  164, 5,   175, 6,   62,
      51,  78,  66,  248, 116, 88,  90,  128, 226, 177, 0,   47,  140, 33,  126,
      221, 110, 144, 97,  74,  250, 181, 199, 27,  176, 65,  185, 110, 92,  34,
      44,  131, 96,  178, 40,  176, 4,   90,  36,  7,   180, 244, 244, 23,  108,
      171, 204, 196, 61,  51,  179, 242, 156, 81,  83,  16,  15,  134, 40,  245,
      253, 150, 94,  150, 144, 197, 113, 5,   141, 232, 33,  101, 231, 38,  75,
      178, 243, 119, 1,   248, 218, 86,  7,   88,  197, 148, 240, 227, 2,   65,
      173, 122, 143, 251, 156, 217, 67,  239, 219, 31,  224, 176, 129, 81,  80,
  };
};

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_cell_modem_status_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgCellModemStatus, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[255];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_cell_modem_status_encode(&buf[0], sizeof(buf), &n_written,
                                             &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgCellModemStatus, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[255];

  EXPECT_EQ(sbp_msg_cell_modem_status_encode(&buf[0], sizeof(buf), nullptr,
                                             &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}
TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[255];

  for (uint8_t i = 0; i < 255; i++) {
    EXPECT_EQ(
        sbp_msg_cell_modem_status_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_cell_modem_status_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_cell_modem_status_decode(&info.encoded_payload[0],
                                             info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgCellModemStatus, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_cell_modem_status_t msg{};

  EXPECT_EQ(sbp_msg_cell_modem_status_decode(&info.encoded_payload[0],
                                             info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_cell_modem_status_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_cell_modem_status_t t{};
      return sbp_msg_cell_modem_status_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_cell_modem_status_t t{};
      t.n_reserved = 1;
      return sbp_msg_cell_modem_status_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_cell_modem_status_decode(&info.encoded_payload[0], i,
                                               nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0,
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

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, SlowRead) {
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

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, BadCRC) {
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

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_cell_modem_status_send(&state, info.sender_id,
                                           &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgCellModemStatus, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgCellModemStatus, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgCellModemStatus, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.n_reserved, greater.n_reserved);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[0], greater.reserved[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[1], greater.reserved[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[2], greater.reserved[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[3], greater.reserved[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[4], greater.reserved[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[5], greater.reserved[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[6], greater.reserved[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[7], greater.reserved[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[8], greater.reserved[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[9], greater.reserved[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[10], greater.reserved[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[11], greater.reserved[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[12], greater.reserved[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[13], greater.reserved[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[14], greater.reserved[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[15], greater.reserved[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[16], greater.reserved[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[17], greater.reserved[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[18], greater.reserved[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[19], greater.reserved[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[20], greater.reserved[20]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[21], greater.reserved[21]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[22], greater.reserved[22]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[23], greater.reserved[23]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[24], greater.reserved[24]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[25], greater.reserved[25]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[26], greater.reserved[26]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[27], greater.reserved[27]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[28], greater.reserved[28]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[29], greater.reserved[29]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[30], greater.reserved[30]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[31], greater.reserved[31]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[32], greater.reserved[32]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[33], greater.reserved[33]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[34], greater.reserved[34]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[35], greater.reserved[35]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[36], greater.reserved[36]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[37], greater.reserved[37]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[38], greater.reserved[38]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[39], greater.reserved[39]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[40], greater.reserved[40]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[41], greater.reserved[41]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[42], greater.reserved[42]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[43], greater.reserved[43]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[44], greater.reserved[44]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[45], greater.reserved[45]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[46], greater.reserved[46]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[47], greater.reserved[47]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[48], greater.reserved[48]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[49], greater.reserved[49]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[50], greater.reserved[50]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[51], greater.reserved[51]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[52], greater.reserved[52]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[53], greater.reserved[53]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[54], greater.reserved[54]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[55], greater.reserved[55]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[56], greater.reserved[56]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[57], greater.reserved[57]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[58], greater.reserved[58]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[59], greater.reserved[59]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[60], greater.reserved[60]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[61], greater.reserved[61]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[62], greater.reserved[62]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[63], greater.reserved[63]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[64], greater.reserved[64]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[65], greater.reserved[65]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[66], greater.reserved[66]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[67], greater.reserved[67]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[68], greater.reserved[68]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[69], greater.reserved[69]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[70], greater.reserved[70]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[71], greater.reserved[71]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[72], greater.reserved[72]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[73], greater.reserved[73]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[74], greater.reserved[74]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[75], greater.reserved[75]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[76], greater.reserved[76]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[77], greater.reserved[77]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[78], greater.reserved[78]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[79], greater.reserved[79]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[80], greater.reserved[80]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[81], greater.reserved[81]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[82], greater.reserved[82]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[83], greater.reserved[83]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[84], greater.reserved[84]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[85], greater.reserved[85]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[86], greater.reserved[86]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[87], greater.reserved[87]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[88], greater.reserved[88]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[89], greater.reserved[89]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[90], greater.reserved[90]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[91], greater.reserved[91]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[92], greater.reserved[92]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[93], greater.reserved[93]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[94], greater.reserved[94]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[95], greater.reserved[95]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[96], greater.reserved[96]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[97], greater.reserved[97]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[98], greater.reserved[98]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[99], greater.reserved[99]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[100], greater.reserved[100]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[101], greater.reserved[101]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[102], greater.reserved[102]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[103], greater.reserved[103]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[104], greater.reserved[104]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[105], greater.reserved[105]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[106], greater.reserved[106]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[107], greater.reserved[107]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[108], greater.reserved[108]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[109], greater.reserved[109]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[110], greater.reserved[110]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[111], greater.reserved[111]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[112], greater.reserved[112]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[113], greater.reserved[113]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[114], greater.reserved[114]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[115], greater.reserved[115]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[116], greater.reserved[116]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[117], greater.reserved[117]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[118], greater.reserved[118]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[119], greater.reserved[119]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[120], greater.reserved[120]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[121], greater.reserved[121]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[122], greater.reserved[122]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[123], greater.reserved[123]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[124], greater.reserved[124]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[125], greater.reserved[125]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[126], greater.reserved[126]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[127], greater.reserved[127]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[128], greater.reserved[128]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[129], greater.reserved[129]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[130], greater.reserved[130]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[131], greater.reserved[131]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[132], greater.reserved[132]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[133], greater.reserved[133]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[134], greater.reserved[134]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[135], greater.reserved[135]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[136], greater.reserved[136]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[137], greater.reserved[137]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[138], greater.reserved[138]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[139], greater.reserved[139]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[140], greater.reserved[140]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[141], greater.reserved[141]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[142], greater.reserved[142]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[143], greater.reserved[143]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[144], greater.reserved[144]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[145], greater.reserved[145]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[146], greater.reserved[146]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[147], greater.reserved[147]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[148], greater.reserved[148]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[149], greater.reserved[149]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[150], greater.reserved[150]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[151], greater.reserved[151]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[152], greater.reserved[152]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[153], greater.reserved[153]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[154], greater.reserved[154]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[155], greater.reserved[155]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[156], greater.reserved[156]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[157], greater.reserved[157]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[158], greater.reserved[158]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[159], greater.reserved[159]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[160], greater.reserved[160]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[161], greater.reserved[161]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[162], greater.reserved[162]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[163], greater.reserved[163]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[164], greater.reserved[164]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[165], greater.reserved[165]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[166], greater.reserved[166]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[167], greater.reserved[167]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[168], greater.reserved[168]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[169], greater.reserved[169]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[170], greater.reserved[170]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[171], greater.reserved[171]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[172], greater.reserved[172]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[173], greater.reserved[173]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[174], greater.reserved[174]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[175], greater.reserved[175]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[176], greater.reserved[176]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[177], greater.reserved[177]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[178], greater.reserved[178]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[179], greater.reserved[179]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[180], greater.reserved[180]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[181], greater.reserved[181]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[182], greater.reserved[182]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[183], greater.reserved[183]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[184], greater.reserved[184]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[185], greater.reserved[185]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[186], greater.reserved[186]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[187], greater.reserved[187]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[188], greater.reserved[188]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[189], greater.reserved[189]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[190], greater.reserved[190]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[191], greater.reserved[191]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[192], greater.reserved[192]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[193], greater.reserved[193]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[194], greater.reserved[194]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[195], greater.reserved[195]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[196], greater.reserved[196]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[197], greater.reserved[197]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[198], greater.reserved[198]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[199], greater.reserved[199]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[200], greater.reserved[200]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[201], greater.reserved[201]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[202], greater.reserved[202]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[203], greater.reserved[203]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[204], greater.reserved[204]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[205], greater.reserved[205]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[206], greater.reserved[206]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[207], greater.reserved[207]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[208], greater.reserved[208]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[209], greater.reserved[209]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[210], greater.reserved[210]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[211], greater.reserved[211]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[212], greater.reserved[212]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[213], greater.reserved[213]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[214], greater.reserved[214]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[215], greater.reserved[215]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[216], greater.reserved[216]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[217], greater.reserved[217]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[218], greater.reserved[218]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[219], greater.reserved[219]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[220], greater.reserved[220]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[221], greater.reserved[221]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[222], greater.reserved[222]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[223], greater.reserved[223]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[224], greater.reserved[224]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[225], greater.reserved[225]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[226], greater.reserved[226]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[227], greater.reserved[227]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[228], greater.reserved[228]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[229], greater.reserved[229]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[230], greater.reserved[230]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[231], greater.reserved[231]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[232], greater.reserved[232]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[233], greater.reserved[233]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[234], greater.reserved[234]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[235], greater.reserved[235]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[236], greater.reserved[236]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[237], greater.reserved[237]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[238], greater.reserved[238]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[239], greater.reserved[239]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[240], greater.reserved[240]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[241], greater.reserved[241]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[242], greater.reserved[242]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[243], greater.reserved[243]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[244], greater.reserved[244]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[245], greater.reserved[245]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[246], greater.reserved[246]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[247], greater.reserved[247]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[248], greater.reserved[248]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.reserved[249], greater.reserved[249]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.signal_error_rate, greater.signal_error_rate);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_cell_modem_status_t lesser = info.test_msg;
    sbp_msg_cell_modem_status_t greater = info.test_msg;
    make_lesser_greater(lesser.signal_strength, greater.signal_strength);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_cell_modem_status_t>::id,
  // SbpMsgCellModemStatus);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_cell_modem_status_t>::name,
               "MSG_CELL_MODEM_STATUS");
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_cell_modem_status_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_cell_modem_status_t>::get(const_sbp_msg_t);
  sbp_msg_cell_modem_status_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_cell_modem_status_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 = sbp::MessageTraits<sbp_msg_cell_modem_status_t>::to_sbp_msg(
      info.test_msg);
  EXPECT_EQ(msg1.cell_modem_status, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_cell_modem_status_t>::to_sbp_msg(info.test_msg,
                                                              &msg2);
  EXPECT_EQ(msg2.cell_modem_status, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_cell_modem_status_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_cell_modem_status_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[255];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_cell_modem_status_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 255);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 255), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_cell_modem_status_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_cell_modem_status_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 255);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0,
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

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgCellModemStatus,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_piksi_MsgCellModemStatus0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgCellModemStatus,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace