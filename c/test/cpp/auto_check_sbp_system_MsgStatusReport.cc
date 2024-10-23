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
// spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusReport.yaml by generate.py.
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
class Testauto_check_sbp_system_MsgStatusReport0 : public ::testing::Test {
 public:
  Testauto_check_sbp_system_MsgStatusReport0() {
    assign(test_msg_.n_status, 60);
    assign(test_msg_.reporting_system, 64850);
    assign(test_msg_.sbp_version, 24497);
    assign(test_msg_.sequence, 1519336451);

    assign(test_msg_.status[0].component, 52215);
    assign(test_msg_.status[0].generic, 221);
    assign(test_msg_.status[0].specific, 198);

    assign(test_msg_.status[1].component, 53148);
    assign(test_msg_.status[1].generic, 217);
    assign(test_msg_.status[1].specific, 238);

    assign(test_msg_.status[2].component, 34978);
    assign(test_msg_.status[2].generic, 154);
    assign(test_msg_.status[2].specific, 11);

    assign(test_msg_.status[3].component, 60530);
    assign(test_msg_.status[3].generic, 134);
    assign(test_msg_.status[3].specific, 235);

    assign(test_msg_.status[4].component, 34060);
    assign(test_msg_.status[4].generic, 9);
    assign(test_msg_.status[4].specific, 30);

    assign(test_msg_.status[5].component, 37295);
    assign(test_msg_.status[5].generic, 26);
    assign(test_msg_.status[5].specific, 114);

    assign(test_msg_.status[6].component, 5335);
    assign(test_msg_.status[6].generic, 146);
    assign(test_msg_.status[6].specific, 249);

    assign(test_msg_.status[7].component, 13878);
    assign(test_msg_.status[7].generic, 133);
    assign(test_msg_.status[7].specific, 193);

    assign(test_msg_.status[8].component, 47722);
    assign(test_msg_.status[8].generic, 210);
    assign(test_msg_.status[8].specific, 183);

    assign(test_msg_.status[9].component, 33024);
    assign(test_msg_.status[9].generic, 5);
    assign(test_msg_.status[9].specific, 248);

    assign(test_msg_.status[10].component, 38369);
    assign(test_msg_.status[10].generic, 135);
    assign(test_msg_.status[10].specific, 127);

    assign(test_msg_.status[11].component, 6658);
    assign(test_msg_.status[11].generic, 88);
    assign(test_msg_.status[11].specific, 92);

    assign(test_msg_.status[12].component, 26378);
    assign(test_msg_.status[12].generic, 73);
    assign(test_msg_.status[12].specific, 3);

    assign(test_msg_.status[13].component, 17511);
    assign(test_msg_.status[13].generic, 76);
    assign(test_msg_.status[13].specific, 184);

    assign(test_msg_.status[14].component, 52769);
    assign(test_msg_.status[14].generic, 194);
    assign(test_msg_.status[14].specific, 163);

    assign(test_msg_.status[15].component, 7803);
    assign(test_msg_.status[15].generic, 151);
    assign(test_msg_.status[15].specific, 176);

    assign(test_msg_.status[16].component, 44181);
    assign(test_msg_.status[16].generic, 184);
    assign(test_msg_.status[16].specific, 231);

    assign(test_msg_.status[17].component, 58998);
    assign(test_msg_.status[17].generic, 200);
    assign(test_msg_.status[17].specific, 168);

    assign(test_msg_.status[18].component, 28004);
    assign(test_msg_.status[18].generic, 10);
    assign(test_msg_.status[18].specific, 233);

    assign(test_msg_.status[19].component, 15364);
    assign(test_msg_.status[19].generic, 247);
    assign(test_msg_.status[19].specific, 82);

    assign(test_msg_.status[20].component, 42711);
    assign(test_msg_.status[20].generic, 28);
    assign(test_msg_.status[20].specific, 138);

    assign(test_msg_.status[21].component, 11630);
    assign(test_msg_.status[21].generic, 98);
    assign(test_msg_.status[21].specific, 218);

    assign(test_msg_.status[22].component, 46068);
    assign(test_msg_.status[22].generic, 126);
    assign(test_msg_.status[22].specific, 107);

    assign(test_msg_.status[23].component, 31836);
    assign(test_msg_.status[23].generic, 94);
    assign(test_msg_.status[23].specific, 157);

    assign(test_msg_.status[24].component, 47914);
    assign(test_msg_.status[24].generic, 124);
    assign(test_msg_.status[24].specific, 6);

    assign(test_msg_.status[25].component, 63329);
    assign(test_msg_.status[25].generic, 160);
    assign(test_msg_.status[25].specific, 188);

    assign(test_msg_.status[26].component, 30830);
    assign(test_msg_.status[26].generic, 254);
    assign(test_msg_.status[26].specific, 214);

    assign(test_msg_.status[27].component, 13166);
    assign(test_msg_.status[27].generic, 240);
    assign(test_msg_.status[27].specific, 164);

    assign(test_msg_.status[28].component, 4755);
    assign(test_msg_.status[28].generic, 74);
    assign(test_msg_.status[28].specific, 178);

    assign(test_msg_.status[29].component, 1091);
    assign(test_msg_.status[29].generic, 27);
    assign(test_msg_.status[29].specific, 73);

    assign(test_msg_.status[30].component, 16574);
    assign(test_msg_.status[30].generic, 179);
    assign(test_msg_.status[30].specific, 146);

    assign(test_msg_.status[31].component, 39293);
    assign(test_msg_.status[31].generic, 192);
    assign(test_msg_.status[31].specific, 46);

    assign(test_msg_.status[32].component, 17098);
    assign(test_msg_.status[32].generic, 248);
    assign(test_msg_.status[32].specific, 46);

    assign(test_msg_.status[33].component, 41256);
    assign(test_msg_.status[33].generic, 173);
    assign(test_msg_.status[33].specific, 242);

    assign(test_msg_.status[34].component, 982);
    assign(test_msg_.status[34].generic, 11);
    assign(test_msg_.status[34].specific, 1);

    assign(test_msg_.status[35].component, 18038);
    assign(test_msg_.status[35].generic, 162);
    assign(test_msg_.status[35].specific, 61);

    assign(test_msg_.status[36].component, 7090);
    assign(test_msg_.status[36].generic, 156);
    assign(test_msg_.status[36].specific, 40);

    assign(test_msg_.status[37].component, 29119);
    assign(test_msg_.status[37].generic, 230);
    assign(test_msg_.status[37].specific, 200);

    assign(test_msg_.status[38].component, 2120);
    assign(test_msg_.status[38].generic, 215);
    assign(test_msg_.status[38].specific, 245);

    assign(test_msg_.status[39].component, 15182);
    assign(test_msg_.status[39].generic, 222);
    assign(test_msg_.status[39].specific, 250);

    assign(test_msg_.status[40].component, 8307);
    assign(test_msg_.status[40].generic, 33);
    assign(test_msg_.status[40].specific, 30);

    assign(test_msg_.status[41].component, 43731);
    assign(test_msg_.status[41].generic, 145);
    assign(test_msg_.status[41].specific, 92);

    assign(test_msg_.status[42].component, 19357);
    assign(test_msg_.status[42].generic, 24);
    assign(test_msg_.status[42].specific, 169);

    assign(test_msg_.status[43].component, 14086);
    assign(test_msg_.status[43].generic, 62);
    assign(test_msg_.status[43].specific, 8);

    assign(test_msg_.status[44].component, 21099);
    assign(test_msg_.status[44].generic, 140);
    assign(test_msg_.status[44].specific, 49);

    assign(test_msg_.status[45].component, 31411);
    assign(test_msg_.status[45].generic, 90);
    assign(test_msg_.status[45].specific, 71);

    assign(test_msg_.status[46].component, 22556);
    assign(test_msg_.status[46].generic, 103);
    assign(test_msg_.status[46].specific, 51);

    assign(test_msg_.status[47].component, 18609);
    assign(test_msg_.status[47].generic, 93);
    assign(test_msg_.status[47].specific, 39);

    assign(test_msg_.status[48].component, 2964);
    assign(test_msg_.status[48].generic, 202);
    assign(test_msg_.status[48].specific, 42);

    assign(test_msg_.status[49].component, 23586);
    assign(test_msg_.status[49].generic, 204);
    assign(test_msg_.status[49].specific, 102);

    assign(test_msg_.status[50].component, 25117);
    assign(test_msg_.status[50].generic, 249);
    assign(test_msg_.status[50].specific, 91);

    assign(test_msg_.status[51].component, 24454);
    assign(test_msg_.status[51].generic, 23);
    assign(test_msg_.status[51].specific, 248);

    assign(test_msg_.status[52].component, 5312);
    assign(test_msg_.status[52].generic, 83);
    assign(test_msg_.status[52].specific, 195);

    assign(test_msg_.status[53].component, 46175);
    assign(test_msg_.status[53].generic, 54);
    assign(test_msg_.status[53].specific, 36);

    assign(test_msg_.status[54].component, 19386);
    assign(test_msg_.status[54].generic, 64);
    assign(test_msg_.status[54].specific, 20);

    assign(test_msg_.status[55].component, 34205);
    assign(test_msg_.status[55].generic, 12);
    assign(test_msg_.status[55].specific, 149);

    assign(test_msg_.status[56].component, 3612);
    assign(test_msg_.status[56].generic, 185);
    assign(test_msg_.status[56].specific, 129);

    assign(test_msg_.status[57].component, 61285);
    assign(test_msg_.status[57].generic, 74);
    assign(test_msg_.status[57].specific, 248);

    assign(test_msg_.status[58].component, 7925);
    assign(test_msg_.status[58].generic, 228);
    assign(test_msg_.status[58].specific, 88);

    assign(test_msg_.status[59].component, 54414);
    assign(test_msg_.status[59].generic, 53);
    assign(test_msg_.status[59].specific, 224);
    assign(test_msg_.uptime, 1657804265);
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
      : public sbp::MessageHandler<sbp_msg_status_report_t> {
    using sbp::MessageHandler<sbp_msg_status_report_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_status_report_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_status_report_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgStatusReport,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_status_report_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgStatusReport);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->status_report,
             sizeof(msg->status_report));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_status_report_t test_msg;
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
    memcpy(&info.test_msg_wrapped.status_report, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgStatusReport);
    info.sender_id = 21510;
    info.preamble = 0x55;
    info.crc = 0xa69e;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 252;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_status_report_t &lesser,
                        const sbp_msg_status_report_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_status_report_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_status_report_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_status_report_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_status_report_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_status_report_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_status_report_cmp(&greater, &lesser), 0);

    EXPECT_EQ(
        sbp_message_cmp(SbpMsgStatusReport, &wrapped_lesser, &wrapped_lesser),
        0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgStatusReport, &wrapped_greater, &wrapped_greater),
        0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgStatusReport, &wrapped_lesser, &wrapped_greater),
        0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgStatusReport, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_status_report_t test_msg_{};
  uint8_t encoded_frame_[252 + 8] = {
      85,  254, 255, 6,   84,  252, 82,  253, 177, 95,  3,   60,  143, 90,  233,
      21,  208, 98,  247, 203, 221, 198, 156, 207, 217, 238, 162, 136, 154, 11,
      114, 236, 134, 235, 12,  133, 9,   30,  175, 145, 26,  114, 215, 20,  146,
      249, 54,  54,  133, 193, 106, 186, 210, 183, 0,   129, 5,   248, 225, 149,
      135, 127, 2,   26,  88,  92,  10,  103, 73,  3,   103, 68,  76,  184, 33,
      206, 194, 163, 123, 30,  151, 176, 149, 172, 184, 231, 118, 230, 200, 168,
      100, 109, 10,  233, 4,   60,  247, 82,  215, 166, 28,  138, 110, 45,  98,
      218, 244, 179, 126, 107, 92,  124, 94,  157, 42,  187, 124, 6,   97,  247,
      160, 188, 110, 120, 254, 214, 110, 51,  240, 164, 147, 18,  74,  178, 67,
      4,   27,  73,  190, 64,  179, 146, 125, 153, 192, 46,  202, 66,  248, 46,
      40,  161, 173, 242, 214, 3,   11,  1,   118, 70,  162, 61,  178, 27,  156,
      40,  191, 113, 230, 200, 72,  8,   215, 245, 78,  59,  222, 250, 115, 32,
      33,  30,  211, 170, 145, 92,  157, 75,  24,  169, 6,   55,  62,  8,   107,
      82,  140, 49,  179, 122, 90,  71,  28,  88,  103, 51,  177, 72,  93,  39,
      148, 11,  202, 42,  34,  92,  204, 102, 29,  98,  249, 91,  134, 95,  23,
      248, 192, 20,  83,  195, 95,  180, 54,  36,  186, 75,  64,  20,  157, 133,
      12,  149, 28,  14,  185, 129, 101, 239, 74,  248, 245, 30,  228, 88,  142,
      212, 53,  224, 158, 166,
  };
  uint8_t encoded_payload_[252] = {
      82,  253, 177, 95,  3,   60,  143, 90,  233, 21,  208, 98,  247, 203, 221,
      198, 156, 207, 217, 238, 162, 136, 154, 11,  114, 236, 134, 235, 12,  133,
      9,   30,  175, 145, 26,  114, 215, 20,  146, 249, 54,  54,  133, 193, 106,
      186, 210, 183, 0,   129, 5,   248, 225, 149, 135, 127, 2,   26,  88,  92,
      10,  103, 73,  3,   103, 68,  76,  184, 33,  206, 194, 163, 123, 30,  151,
      176, 149, 172, 184, 231, 118, 230, 200, 168, 100, 109, 10,  233, 4,   60,
      247, 82,  215, 166, 28,  138, 110, 45,  98,  218, 244, 179, 126, 107, 92,
      124, 94,  157, 42,  187, 124, 6,   97,  247, 160, 188, 110, 120, 254, 214,
      110, 51,  240, 164, 147, 18,  74,  178, 67,  4,   27,  73,  190, 64,  179,
      146, 125, 153, 192, 46,  202, 66,  248, 46,  40,  161, 173, 242, 214, 3,
      11,  1,   118, 70,  162, 61,  178, 27,  156, 40,  191, 113, 230, 200, 72,
      8,   215, 245, 78,  59,  222, 250, 115, 32,  33,  30,  211, 170, 145, 92,
      157, 75,  24,  169, 6,   55,  62,  8,   107, 82,  140, 49,  179, 122, 90,
      71,  28,  88,  103, 51,  177, 72,  93,  39,  148, 11,  202, 42,  34,  92,
      204, 102, 29,  98,  249, 91,  134, 95,  23,  248, 192, 20,  83,  195, 95,
      180, 54,  36,  186, 75,  64,  20,  157, 133, 12,  149, 28,  14,  185, 129,
      101, 239, 74,  248, 245, 30,  228, 88,  142, 212, 53,  224,
  };
};

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_status_report_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgStatusReport, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[252];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_status_report_encode(&buf[0], sizeof(buf), &n_written,
                                         &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 252);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgStatusReport, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 252);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[252];

  EXPECT_EQ(sbp_msg_status_report_encode(&buf[0], sizeof(buf), nullptr,
                                         &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);
}
TEST_F(Testauto_check_sbp_system_MsgStatusReport0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[252];

  for (uint8_t i = 0; i < 252; i++) {
    EXPECT_EQ(sbp_msg_status_report_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_status_report_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_status_report_decode(&info.encoded_payload[0],
                                         info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 252);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgStatusReport, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 252);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_status_report_t msg{};

  EXPECT_EQ(sbp_msg_status_report_decode(&info.encoded_payload[0],
                                         info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_system_MsgStatusReport0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_status_report_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_status_report_t t{};
      return sbp_msg_status_report_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_status_report_t t{};
      t.n_status = 1;
      return sbp_msg_status_report_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_status_report_decode(&info.encoded_payload[0], i, nullptr,
                                           &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_system_MsgStatusReport0,
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

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, SlowRead) {
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

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, BadCRC) {
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

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_status_report_send(&state, info.sender_id, &info.test_msg,
                                       &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgStatusReport, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgStatusReport, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgStatusReport, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.n_status, greater.n_status);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.reporting_system, greater.reporting_system);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.sbp_version, greater.sbp_version);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.sequence, greater.sequence);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[0].component,
                        greater.status[0].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[0].generic, greater.status[0].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[0].specific, greater.status[0].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[1].component,
                        greater.status[1].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[1].generic, greater.status[1].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[1].specific, greater.status[1].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[2].component,
                        greater.status[2].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[2].generic, greater.status[2].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[2].specific, greater.status[2].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[3].component,
                        greater.status[3].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[3].generic, greater.status[3].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[3].specific, greater.status[3].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[4].component,
                        greater.status[4].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[4].generic, greater.status[4].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[4].specific, greater.status[4].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[5].component,
                        greater.status[5].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[5].generic, greater.status[5].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[5].specific, greater.status[5].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[6].component,
                        greater.status[6].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[6].generic, greater.status[6].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[6].specific, greater.status[6].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[7].component,
                        greater.status[7].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[7].generic, greater.status[7].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[7].specific, greater.status[7].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[8].component,
                        greater.status[8].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[8].generic, greater.status[8].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[8].specific, greater.status[8].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[9].component,
                        greater.status[9].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[9].generic, greater.status[9].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[9].specific, greater.status[9].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[10].component,
                        greater.status[10].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[10].generic, greater.status[10].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[10].specific,
                        greater.status[10].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[11].component,
                        greater.status[11].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[11].generic, greater.status[11].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[11].specific,
                        greater.status[11].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[12].component,
                        greater.status[12].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[12].generic, greater.status[12].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[12].specific,
                        greater.status[12].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[13].component,
                        greater.status[13].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[13].generic, greater.status[13].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[13].specific,
                        greater.status[13].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[14].component,
                        greater.status[14].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[14].generic, greater.status[14].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[14].specific,
                        greater.status[14].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[15].component,
                        greater.status[15].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[15].generic, greater.status[15].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[15].specific,
                        greater.status[15].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[16].component,
                        greater.status[16].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[16].generic, greater.status[16].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[16].specific,
                        greater.status[16].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[17].component,
                        greater.status[17].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[17].generic, greater.status[17].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[17].specific,
                        greater.status[17].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[18].component,
                        greater.status[18].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[18].generic, greater.status[18].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[18].specific,
                        greater.status[18].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[19].component,
                        greater.status[19].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[19].generic, greater.status[19].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[19].specific,
                        greater.status[19].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[20].component,
                        greater.status[20].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[20].generic, greater.status[20].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[20].specific,
                        greater.status[20].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[21].component,
                        greater.status[21].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[21].generic, greater.status[21].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[21].specific,
                        greater.status[21].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[22].component,
                        greater.status[22].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[22].generic, greater.status[22].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[22].specific,
                        greater.status[22].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[23].component,
                        greater.status[23].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[23].generic, greater.status[23].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[23].specific,
                        greater.status[23].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[24].component,
                        greater.status[24].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[24].generic, greater.status[24].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[24].specific,
                        greater.status[24].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[25].component,
                        greater.status[25].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[25].generic, greater.status[25].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[25].specific,
                        greater.status[25].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[26].component,
                        greater.status[26].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[26].generic, greater.status[26].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[26].specific,
                        greater.status[26].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[27].component,
                        greater.status[27].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[27].generic, greater.status[27].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[27].specific,
                        greater.status[27].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[28].component,
                        greater.status[28].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[28].generic, greater.status[28].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[28].specific,
                        greater.status[28].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[29].component,
                        greater.status[29].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[29].generic, greater.status[29].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[29].specific,
                        greater.status[29].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[30].component,
                        greater.status[30].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[30].generic, greater.status[30].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[30].specific,
                        greater.status[30].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[31].component,
                        greater.status[31].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[31].generic, greater.status[31].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[31].specific,
                        greater.status[31].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[32].component,
                        greater.status[32].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[32].generic, greater.status[32].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[32].specific,
                        greater.status[32].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[33].component,
                        greater.status[33].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[33].generic, greater.status[33].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[33].specific,
                        greater.status[33].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[34].component,
                        greater.status[34].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[34].generic, greater.status[34].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[34].specific,
                        greater.status[34].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[35].component,
                        greater.status[35].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[35].generic, greater.status[35].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[35].specific,
                        greater.status[35].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[36].component,
                        greater.status[36].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[36].generic, greater.status[36].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[36].specific,
                        greater.status[36].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[37].component,
                        greater.status[37].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[37].generic, greater.status[37].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[37].specific,
                        greater.status[37].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[38].component,
                        greater.status[38].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[38].generic, greater.status[38].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[38].specific,
                        greater.status[38].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[39].component,
                        greater.status[39].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[39].generic, greater.status[39].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[39].specific,
                        greater.status[39].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[40].component,
                        greater.status[40].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[40].generic, greater.status[40].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[40].specific,
                        greater.status[40].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[41].component,
                        greater.status[41].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[41].generic, greater.status[41].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[41].specific,
                        greater.status[41].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[42].component,
                        greater.status[42].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[42].generic, greater.status[42].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[42].specific,
                        greater.status[42].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[43].component,
                        greater.status[43].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[43].generic, greater.status[43].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[43].specific,
                        greater.status[43].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[44].component,
                        greater.status[44].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[44].generic, greater.status[44].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[44].specific,
                        greater.status[44].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[45].component,
                        greater.status[45].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[45].generic, greater.status[45].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[45].specific,
                        greater.status[45].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[46].component,
                        greater.status[46].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[46].generic, greater.status[46].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[46].specific,
                        greater.status[46].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[47].component,
                        greater.status[47].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[47].generic, greater.status[47].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[47].specific,
                        greater.status[47].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[48].component,
                        greater.status[48].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[48].generic, greater.status[48].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[48].specific,
                        greater.status[48].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[49].component,
                        greater.status[49].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[49].generic, greater.status[49].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[49].specific,
                        greater.status[49].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[50].component,
                        greater.status[50].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[50].generic, greater.status[50].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[50].specific,
                        greater.status[50].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[51].component,
                        greater.status[51].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[51].generic, greater.status[51].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[51].specific,
                        greater.status[51].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[52].component,
                        greater.status[52].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[52].generic, greater.status[52].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[52].specific,
                        greater.status[52].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[53].component,
                        greater.status[53].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[53].generic, greater.status[53].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[53].specific,
                        greater.status[53].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[54].component,
                        greater.status[54].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[54].generic, greater.status[54].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[54].specific,
                        greater.status[54].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[55].component,
                        greater.status[55].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[55].generic, greater.status[55].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[55].specific,
                        greater.status[55].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[56].component,
                        greater.status[56].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[56].generic, greater.status[56].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[56].specific,
                        greater.status[56].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[57].component,
                        greater.status[57].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[57].generic, greater.status[57].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[57].specific,
                        greater.status[57].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[58].component,
                        greater.status[58].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[58].generic, greater.status[58].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[58].specific,
                        greater.status[58].specific);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[59].component,
                        greater.status[59].component);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[59].generic, greater.status[59].generic);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.status[59].specific,
                        greater.status[59].specific);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_status_report_t lesser = info.test_msg;
    sbp_msg_status_report_t greater = info.test_msg;
    make_lesser_greater(lesser.uptime, greater.uptime);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_status_report_t>::id,
  // SbpMsgStatusReport);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_status_report_t>::name,
               "MSG_STATUS_REPORT");
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_status_report_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_status_report_t>::get(const_sbp_msg_t);
  sbp_msg_status_report_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_status_report_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_status_report_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.status_report, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_status_report_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.status_report, info.test_msg);
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_status_report_t>::encoded_len(info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_status_report_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[252];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_status_report_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 252);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_status_report_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_status_report_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 252);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0,
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

TEST_F(Testauto_check_sbp_system_MsgStatusReport0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgStatusReport,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_system_MsgStatusReport0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgStatusReport,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace
