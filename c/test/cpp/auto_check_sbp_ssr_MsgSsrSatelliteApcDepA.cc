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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApcDepA.yaml by
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
class Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0 : public ::testing::Test {
 public:
  Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0() {
    assign(test_msg_.apc[0].pco[0], -21547);

    assign(test_msg_.apc[0].pco[1], -10498);

    assign(test_msg_.apc[0].pco[2], 1236);

    assign(test_msg_.apc[0].pcv[0], 8);

    assign(test_msg_.apc[0].pcv[1], 33);

    assign(test_msg_.apc[0].pcv[2], 31);

    assign(test_msg_.apc[0].pcv[3], 80);

    assign(test_msg_.apc[0].pcv[4], 21);

    assign(test_msg_.apc[0].pcv[5], 4);

    assign(test_msg_.apc[0].pcv[6], 105);

    assign(test_msg_.apc[0].pcv[7], -31);

    assign(test_msg_.apc[0].pcv[8], 39);

    assign(test_msg_.apc[0].pcv[9], -117);

    assign(test_msg_.apc[0].pcv[10], 124);

    assign(test_msg_.apc[0].pcv[11], -107);

    assign(test_msg_.apc[0].pcv[12], 48);

    assign(test_msg_.apc[0].pcv[13], 15);

    assign(test_msg_.apc[0].pcv[14], -42);

    assign(test_msg_.apc[0].pcv[15], -59);

    assign(test_msg_.apc[0].pcv[16], -115);

    assign(test_msg_.apc[0].pcv[17], 32);

    assign(test_msg_.apc[0].pcv[18], 33);

    assign(test_msg_.apc[0].pcv[19], -121);

    assign(test_msg_.apc[0].pcv[20], -106);
    assign(test_msg_.apc[0].sat_info, 240);
    assign(test_msg_.apc[0].sid.code, 169);
    assign(test_msg_.apc[0].sid.sat, 203);
    assign(test_msg_.apc[0].svn, 1102);

    assign(test_msg_.apc[1].pco[0], 23079);

    assign(test_msg_.apc[1].pco[1], -22252);

    assign(test_msg_.apc[1].pco[2], 12271);

    assign(test_msg_.apc[1].pcv[0], -103);

    assign(test_msg_.apc[1].pcv[1], -81);

    assign(test_msg_.apc[1].pcv[2], 35);

    assign(test_msg_.apc[1].pcv[3], -111);

    assign(test_msg_.apc[1].pcv[4], -111);

    assign(test_msg_.apc[1].pcv[5], 123);

    assign(test_msg_.apc[1].pcv[6], -62);

    assign(test_msg_.apc[1].pcv[7], 2);

    assign(test_msg_.apc[1].pcv[8], 102);

    assign(test_msg_.apc[1].pcv[9], 74);

    assign(test_msg_.apc[1].pcv[10], -107);

    assign(test_msg_.apc[1].pcv[11], 95);

    assign(test_msg_.apc[1].pcv[12], -85);

    assign(test_msg_.apc[1].pcv[13], -18);

    assign(test_msg_.apc[1].pcv[14], -7);

    assign(test_msg_.apc[1].pcv[15], 7);

    assign(test_msg_.apc[1].pcv[16], -19);

    assign(test_msg_.apc[1].pcv[17], -86);

    assign(test_msg_.apc[1].pcv[18], 125);

    assign(test_msg_.apc[1].pcv[19], 106);

    assign(test_msg_.apc[1].pcv[20], -98);
    assign(test_msg_.apc[1].sat_info, 49);
    assign(test_msg_.apc[1].sid.code, 123);
    assign(test_msg_.apc[1].sid.sat, 148);
    assign(test_msg_.apc[1].svn, 24967);

    assign(test_msg_.apc[2].pco[0], -7596);

    assign(test_msg_.apc[2].pco[1], 31630);

    assign(test_msg_.apc[2].pco[2], -9907);

    assign(test_msg_.apc[2].pcv[0], -8);

    assign(test_msg_.apc[2].pcv[1], 67);

    assign(test_msg_.apc[2].pcv[2], -41);

    assign(test_msg_.apc[2].pcv[3], -127);

    assign(test_msg_.apc[2].pcv[4], 114);

    assign(test_msg_.apc[2].pcv[5], -118);

    assign(test_msg_.apc[2].pcv[6], 25);

    assign(test_msg_.apc[2].pcv[7], -16);

    assign(test_msg_.apc[2].pcv[8], 10);

    assign(test_msg_.apc[2].pcv[9], 56);

    assign(test_msg_.apc[2].pcv[10], 76);

    assign(test_msg_.apc[2].pcv[11], 61);

    assign(test_msg_.apc[2].pcv[12], -95);

    assign(test_msg_.apc[2].pcv[13], -40);

    assign(test_msg_.apc[2].pcv[14], 22);

    assign(test_msg_.apc[2].pcv[15], -75);

    assign(test_msg_.apc[2].pcv[16], -82);

    assign(test_msg_.apc[2].pcv[17], 33);

    assign(test_msg_.apc[2].pcv[18], 13);

    assign(test_msg_.apc[2].pcv[19], -4);

    assign(test_msg_.apc[2].pcv[20], -20);
    assign(test_msg_.apc[2].sat_info, 181);
    assign(test_msg_.apc[2].sid.code, 188);
    assign(test_msg_.apc[2].sid.sat, 83);
    assign(test_msg_.apc[2].svn, 7106);

    assign(test_msg_.apc[3].pco[0], -19478);

    assign(test_msg_.apc[3].pco[1], 11484);

    assign(test_msg_.apc[3].pco[2], 14804);

    assign(test_msg_.apc[3].pcv[0], 44);

    assign(test_msg_.apc[3].pcv[1], -83);

    assign(test_msg_.apc[3].pcv[2], 49);

    assign(test_msg_.apc[3].pcv[3], 36);

    assign(test_msg_.apc[3].pcv[4], -119);

    assign(test_msg_.apc[3].pcv[5], -8);

    assign(test_msg_.apc[3].pcv[6], -21);

    assign(test_msg_.apc[3].pcv[7], 97);

    assign(test_msg_.apc[3].pcv[8], 112);

    assign(test_msg_.apc[3].pcv[9], -99);

    assign(test_msg_.apc[3].pcv[10], -117);

    assign(test_msg_.apc[3].pcv[11], 26);

    assign(test_msg_.apc[3].pcv[12], 115);

    assign(test_msg_.apc[3].pcv[13], -64);

    assign(test_msg_.apc[3].pcv[14], 31);

    assign(test_msg_.apc[3].pcv[15], 85);

    assign(test_msg_.apc[3].pcv[16], 127);

    assign(test_msg_.apc[3].pcv[17], -28);

    assign(test_msg_.apc[3].pcv[18], 81);

    assign(test_msg_.apc[3].pcv[19], -4);

    assign(test_msg_.apc[3].pcv[20], -37);
    assign(test_msg_.apc[3].sat_info, 128);
    assign(test_msg_.apc[3].sid.code, 196);
    assign(test_msg_.apc[3].sid.sat, 230);
    assign(test_msg_.apc[3].svn, 61399);

    assign(test_msg_.apc[4].pco[0], -11049);

    assign(test_msg_.apc[4].pco[1], 6580);

    assign(test_msg_.apc[4].pco[2], -28589);

    assign(test_msg_.apc[4].pcv[0], -9);

    assign(test_msg_.apc[4].pcv[1], 12);

    assign(test_msg_.apc[4].pcv[2], 27);

    assign(test_msg_.apc[4].pcv[3], -57);

    assign(test_msg_.apc[4].pcv[4], -83);

    assign(test_msg_.apc[4].pcv[5], 74);

    assign(test_msg_.apc[4].pcv[6], 23);

    assign(test_msg_.apc[4].pcv[7], 4);

    assign(test_msg_.apc[4].pcv[8], -17);

    assign(test_msg_.apc[4].pcv[9], 103);

    assign(test_msg_.apc[4].pcv[10], -33);

    assign(test_msg_.apc[4].pcv[11], -36);

    assign(test_msg_.apc[4].pcv[12], -117);

    assign(test_msg_.apc[4].pcv[13], 91);

    assign(test_msg_.apc[4].pcv[14], 127);

    assign(test_msg_.apc[4].pcv[15], -42);

    assign(test_msg_.apc[4].pcv[16], 86);

    assign(test_msg_.apc[4].pcv[17], 48);

    assign(test_msg_.apc[4].pcv[18], -53);

    assign(test_msg_.apc[4].pcv[19], -28);

    assign(test_msg_.apc[4].pcv[20], 99);
    assign(test_msg_.apc[4].sat_info, 147);
    assign(test_msg_.apc[4].sid.code, 110);
    assign(test_msg_.apc[4].sid.sat, 249);
    assign(test_msg_.apc[4].svn, 41224);

    assign(test_msg_.apc[5].pco[0], -21881);

    assign(test_msg_.apc[5].pco[1], -9942);

    assign(test_msg_.apc[5].pco[2], -5689);

    assign(test_msg_.apc[5].pcv[0], 42);

    assign(test_msg_.apc[5].pcv[1], -86);

    assign(test_msg_.apc[5].pcv[2], 78);

    assign(test_msg_.apc[5].pcv[3], -50);

    assign(test_msg_.apc[5].pcv[4], 41);

    assign(test_msg_.apc[5].pcv[5], 43);

    assign(test_msg_.apc[5].pcv[6], 81);

    assign(test_msg_.apc[5].pcv[7], -9);

    assign(test_msg_.apc[5].pcv[8], 99);

    assign(test_msg_.apc[5].pcv[9], -58);

    assign(test_msg_.apc[5].pcv[10], -112);

    assign(test_msg_.apc[5].pcv[11], 2);

    assign(test_msg_.apc[5].pcv[12], -124);

    assign(test_msg_.apc[5].pcv[13], 2);

    assign(test_msg_.apc[5].pcv[14], -32);

    assign(test_msg_.apc[5].pcv[15], -36);

    assign(test_msg_.apc[5].pcv[16], -108);

    assign(test_msg_.apc[5].pcv[17], 58);

    assign(test_msg_.apc[5].pcv[18], 85);

    assign(test_msg_.apc[5].pcv[19], -118);

    assign(test_msg_.apc[5].pcv[20], -46);
    assign(test_msg_.apc[5].sat_info, 159);
    assign(test_msg_.apc[5].sid.code, 83);
    assign(test_msg_.apc[5].sid.sat, 45);
    assign(test_msg_.apc[5].svn, 64011);

    assign(test_msg_.apc[6].pco[0], -14290);

    assign(test_msg_.apc[6].pco[1], 30340);

    assign(test_msg_.apc[6].pco[2], 3569);

    assign(test_msg_.apc[6].pcv[0], 37);

    assign(test_msg_.apc[6].pcv[1], 62);

    assign(test_msg_.apc[6].pcv[2], 107);

    assign(test_msg_.apc[6].pcv[3], -3);

    assign(test_msg_.apc[6].pcv[4], -66);

    assign(test_msg_.apc[6].pcv[5], -120);

    assign(test_msg_.apc[6].pcv[6], 66);

    assign(test_msg_.apc[6].pcv[7], 9);

    assign(test_msg_.apc[6].pcv[8], 84);

    assign(test_msg_.apc[6].pcv[9], -101);

    assign(test_msg_.apc[6].pcv[10], 86);

    assign(test_msg_.apc[6].pcv[11], -76);

    assign(test_msg_.apc[6].pcv[12], 41);

    assign(test_msg_.apc[6].pcv[13], -60);

    assign(test_msg_.apc[6].pcv[14], 40);

    assign(test_msg_.apc[6].pcv[15], 119);

    assign(test_msg_.apc[6].pcv[16], 101);

    assign(test_msg_.apc[6].pcv[17], -4);

    assign(test_msg_.apc[6].pcv[18], -33);

    assign(test_msg_.apc[6].pcv[19], -112);

    assign(test_msg_.apc[6].pcv[20], -103);
    assign(test_msg_.apc[6].sat_info, 7);
    assign(test_msg_.apc[6].sid.code, 158);
    assign(test_msg_.apc[6].sid.sat, 200);
    assign(test_msg_.apc[6].svn, 17310);
    assign(test_msg_.n_apc, 7);
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
      : public sbp::MessageHandler<sbp_msg_ssr_satellite_apc_dep_t> {
    using sbp::MessageHandler<sbp_msg_ssr_satellite_apc_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_satellite_apc_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_ssr_satellite_apc_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgSsrSatelliteApcDep,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_ssr_satellite_apc_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgSsrSatelliteApcDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->ssr_satellite_apc_dep,
             sizeof(msg->ssr_satellite_apc_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_ssr_satellite_apc_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.ssr_satellite_apc_dep, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgSsrSatelliteApcDep);
    info.sender_id = 4920;
    info.preamble = 0x55;
    info.crc = 0x0d32;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 224;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_ssr_satellite_apc_dep_t &lesser,
                        const sbp_msg_ssr_satellite_apc_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_ssr_satellite_apc_dep_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_ssr_satellite_apc_dep_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_ssr_satellite_apc_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_ssr_satellite_apc_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_ssr_satellite_apc_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_ssr_satellite_apc_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrSatelliteApcDep, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgSsrSatelliteApcDep, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgSsrSatelliteApcDep, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgSsrSatelliteApcDep, &wrapped_greater,
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
  sbp_msg_ssr_satellite_apc_dep_t test_msg_{};
  uint8_t encoded_frame_[224 + 8] = {
      85,  4,   6,   56,  19,  224, 203, 169, 240, 78,  4,   213, 171, 254, 214,
      212, 4,   8,   33,  31,  80,  21,  4,   105, 225, 39,  139, 124, 149, 48,
      15,  214, 197, 141, 32,  33,  135, 150, 148, 123, 49,  135, 97,  39,  90,
      20,  169, 239, 47,  153, 175, 35,  145, 145, 123, 194, 2,   102, 74,  149,
      95,  171, 238, 249, 7,   237, 170, 125, 106, 158, 83,  188, 181, 194, 27,
      84,  226, 142, 123, 77,  217, 248, 67,  215, 129, 114, 138, 25,  240, 10,
      56,  76,  61,  161, 216, 22,  181, 174, 33,  13,  252, 236, 230, 196, 128,
      215, 239, 234, 179, 220, 44,  212, 57,  44,  173, 49,  36,  137, 248, 235,
      97,  112, 157, 139, 26,  115, 192, 31,  85,  127, 228, 81,  252, 219, 249,
      110, 147, 8,   161, 215, 212, 180, 25,  83,  144, 247, 12,  27,  199, 173,
      74,  23,  4,   239, 103, 223, 220, 139, 91,  127, 214, 86,  48,  203, 228,
      99,  45,  83,  159, 11,  250, 135, 170, 42,  217, 199, 233, 42,  170, 78,
      206, 41,  43,  81,  247, 99,  198, 144, 2,   132, 2,   224, 220, 148, 58,
      85,  138, 210, 200, 158, 7,   158, 67,  46,  200, 132, 118, 241, 13,  37,
      62,  107, 253, 190, 136, 66,  9,   84,  155, 86,  180, 41,  196, 40,  119,
      101, 252, 223, 144, 153, 50,  13,
  };
  uint8_t encoded_payload_[224] = {
      203, 169, 240, 78,  4,   213, 171, 254, 214, 212, 4,   8,   33,  31,  80,
      21,  4,   105, 225, 39,  139, 124, 149, 48,  15,  214, 197, 141, 32,  33,
      135, 150, 148, 123, 49,  135, 97,  39,  90,  20,  169, 239, 47,  153, 175,
      35,  145, 145, 123, 194, 2,   102, 74,  149, 95,  171, 238, 249, 7,   237,
      170, 125, 106, 158, 83,  188, 181, 194, 27,  84,  226, 142, 123, 77,  217,
      248, 67,  215, 129, 114, 138, 25,  240, 10,  56,  76,  61,  161, 216, 22,
      181, 174, 33,  13,  252, 236, 230, 196, 128, 215, 239, 234, 179, 220, 44,
      212, 57,  44,  173, 49,  36,  137, 248, 235, 97,  112, 157, 139, 26,  115,
      192, 31,  85,  127, 228, 81,  252, 219, 249, 110, 147, 8,   161, 215, 212,
      180, 25,  83,  144, 247, 12,  27,  199, 173, 74,  23,  4,   239, 103, 223,
      220, 139, 91,  127, 214, 86,  48,  203, 228, 99,  45,  83,  159, 11,  250,
      135, 170, 42,  217, 199, 233, 42,  170, 78,  206, 41,  43,  81,  247, 99,
      198, 144, 2,   132, 2,   224, 220, 148, 58,  85,  138, 210, 200, 158, 7,
      158, 67,  46,  200, 132, 118, 241, 13,  37,  62,  107, 253, 190, 136, 66,
      9,   84,  155, 86,  180, 41,  196, 40,  119, 101, 252, 223, 144, 153,
  };
};

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_ssr_satellite_apc_dep_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgSsrSatelliteApcDep, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[224];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_ssr_satellite_apc_dep_encode(&buf[0], sizeof(buf),
                                                 &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 224);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 224), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(
      sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                         SbpMsgSsrSatelliteApcDep, &info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(n_written, 224);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 224), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[224];

  EXPECT_EQ(sbp_msg_ssr_satellite_apc_dep_encode(&buf[0], sizeof(buf), nullptr,
                                                 &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 224), 0);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[224];

  for (uint8_t i = 0; i < 224; i++) {
    EXPECT_EQ(sbp_msg_ssr_satellite_apc_dep_encode(&buf[0], i, nullptr,
                                                   &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_satellite_apc_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_ssr_satellite_apc_dep_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 224);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgSsrSatelliteApcDep, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 224);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_satellite_apc_dep_t msg{};

  EXPECT_EQ(sbp_msg_ssr_satellite_apc_dep_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_satellite_apc_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_ssr_satellite_apc_dep_t t{};
      return sbp_msg_ssr_satellite_apc_dep_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_ssr_satellite_apc_dep_t t{};
      t.n_apc = 1;
      return sbp_msg_ssr_satellite_apc_dep_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_ssr_satellite_apc_dep_decode(&info.encoded_payload[0], i,
                                                   nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, SlowRead) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, BadCRC) {
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_ssr_satellite_apc_dep_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSsrSatelliteApcDep, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgSsrSatelliteApcDep, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSsrSatelliteApcDep, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, Comparison) {
  auto info = get_test_msg_info();

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pco[0], greater.apc[0].pco[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pco[1], greater.apc[0].pco[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pco[2], greater.apc[0].pco[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[0], greater.apc[0].pcv[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[1], greater.apc[0].pcv[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[2], greater.apc[0].pcv[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[3], greater.apc[0].pcv[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[4], greater.apc[0].pcv[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[5], greater.apc[0].pcv[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[6], greater.apc[0].pcv[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[7], greater.apc[0].pcv[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[8], greater.apc[0].pcv[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[9], greater.apc[0].pcv[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[10], greater.apc[0].pcv[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[11], greater.apc[0].pcv[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[12], greater.apc[0].pcv[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[13], greater.apc[0].pcv[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[14], greater.apc[0].pcv[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[15], greater.apc[0].pcv[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[16], greater.apc[0].pcv[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[17], greater.apc[0].pcv[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[18], greater.apc[0].pcv[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[19], greater.apc[0].pcv[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].pcv[20], greater.apc[0].pcv[20]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].sat_info, greater.apc[0].sat_info);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].sid.code, greater.apc[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].sid.sat, greater.apc[0].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[0].svn, greater.apc[0].svn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pco[0], greater.apc[1].pco[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pco[1], greater.apc[1].pco[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pco[2], greater.apc[1].pco[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[0], greater.apc[1].pcv[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[1], greater.apc[1].pcv[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[2], greater.apc[1].pcv[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[3], greater.apc[1].pcv[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[4], greater.apc[1].pcv[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[5], greater.apc[1].pcv[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[6], greater.apc[1].pcv[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[7], greater.apc[1].pcv[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[8], greater.apc[1].pcv[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[9], greater.apc[1].pcv[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[10], greater.apc[1].pcv[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[11], greater.apc[1].pcv[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[12], greater.apc[1].pcv[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[13], greater.apc[1].pcv[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[14], greater.apc[1].pcv[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[15], greater.apc[1].pcv[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[16], greater.apc[1].pcv[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[17], greater.apc[1].pcv[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[18], greater.apc[1].pcv[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[19], greater.apc[1].pcv[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].pcv[20], greater.apc[1].pcv[20]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].sat_info, greater.apc[1].sat_info);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].sid.code, greater.apc[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].sid.sat, greater.apc[1].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[1].svn, greater.apc[1].svn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pco[0], greater.apc[2].pco[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pco[1], greater.apc[2].pco[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pco[2], greater.apc[2].pco[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[0], greater.apc[2].pcv[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[1], greater.apc[2].pcv[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[2], greater.apc[2].pcv[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[3], greater.apc[2].pcv[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[4], greater.apc[2].pcv[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[5], greater.apc[2].pcv[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[6], greater.apc[2].pcv[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[7], greater.apc[2].pcv[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[8], greater.apc[2].pcv[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[9], greater.apc[2].pcv[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[10], greater.apc[2].pcv[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[11], greater.apc[2].pcv[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[12], greater.apc[2].pcv[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[13], greater.apc[2].pcv[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[14], greater.apc[2].pcv[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[15], greater.apc[2].pcv[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[16], greater.apc[2].pcv[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[17], greater.apc[2].pcv[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[18], greater.apc[2].pcv[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[19], greater.apc[2].pcv[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].pcv[20], greater.apc[2].pcv[20]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].sat_info, greater.apc[2].sat_info);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].sid.code, greater.apc[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].sid.sat, greater.apc[2].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[2].svn, greater.apc[2].svn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pco[0], greater.apc[3].pco[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pco[1], greater.apc[3].pco[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pco[2], greater.apc[3].pco[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[0], greater.apc[3].pcv[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[1], greater.apc[3].pcv[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[2], greater.apc[3].pcv[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[3], greater.apc[3].pcv[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[4], greater.apc[3].pcv[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[5], greater.apc[3].pcv[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[6], greater.apc[3].pcv[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[7], greater.apc[3].pcv[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[8], greater.apc[3].pcv[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[9], greater.apc[3].pcv[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[10], greater.apc[3].pcv[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[11], greater.apc[3].pcv[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[12], greater.apc[3].pcv[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[13], greater.apc[3].pcv[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[14], greater.apc[3].pcv[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[15], greater.apc[3].pcv[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[16], greater.apc[3].pcv[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[17], greater.apc[3].pcv[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[18], greater.apc[3].pcv[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[19], greater.apc[3].pcv[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].pcv[20], greater.apc[3].pcv[20]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].sat_info, greater.apc[3].sat_info);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].sid.code, greater.apc[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].sid.sat, greater.apc[3].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[3].svn, greater.apc[3].svn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pco[0], greater.apc[4].pco[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pco[1], greater.apc[4].pco[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pco[2], greater.apc[4].pco[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[0], greater.apc[4].pcv[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[1], greater.apc[4].pcv[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[2], greater.apc[4].pcv[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[3], greater.apc[4].pcv[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[4], greater.apc[4].pcv[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[5], greater.apc[4].pcv[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[6], greater.apc[4].pcv[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[7], greater.apc[4].pcv[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[8], greater.apc[4].pcv[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[9], greater.apc[4].pcv[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[10], greater.apc[4].pcv[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[11], greater.apc[4].pcv[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[12], greater.apc[4].pcv[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[13], greater.apc[4].pcv[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[14], greater.apc[4].pcv[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[15], greater.apc[4].pcv[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[16], greater.apc[4].pcv[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[17], greater.apc[4].pcv[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[18], greater.apc[4].pcv[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[19], greater.apc[4].pcv[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].pcv[20], greater.apc[4].pcv[20]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].sat_info, greater.apc[4].sat_info);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].sid.code, greater.apc[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].sid.sat, greater.apc[4].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[4].svn, greater.apc[4].svn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pco[0], greater.apc[5].pco[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pco[1], greater.apc[5].pco[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pco[2], greater.apc[5].pco[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[0], greater.apc[5].pcv[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[1], greater.apc[5].pcv[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[2], greater.apc[5].pcv[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[3], greater.apc[5].pcv[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[4], greater.apc[5].pcv[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[5], greater.apc[5].pcv[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[6], greater.apc[5].pcv[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[7], greater.apc[5].pcv[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[8], greater.apc[5].pcv[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[9], greater.apc[5].pcv[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[10], greater.apc[5].pcv[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[11], greater.apc[5].pcv[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[12], greater.apc[5].pcv[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[13], greater.apc[5].pcv[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[14], greater.apc[5].pcv[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[15], greater.apc[5].pcv[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[16], greater.apc[5].pcv[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[17], greater.apc[5].pcv[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[18], greater.apc[5].pcv[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[19], greater.apc[5].pcv[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].pcv[20], greater.apc[5].pcv[20]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].sat_info, greater.apc[5].sat_info);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].sid.code, greater.apc[5].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].sid.sat, greater.apc[5].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[5].svn, greater.apc[5].svn);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pco[0], greater.apc[6].pco[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pco[1], greater.apc[6].pco[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pco[2], greater.apc[6].pco[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[0], greater.apc[6].pcv[0]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[1], greater.apc[6].pcv[1]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[2], greater.apc[6].pcv[2]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[3], greater.apc[6].pcv[3]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[4], greater.apc[6].pcv[4]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[5], greater.apc[6].pcv[5]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[6], greater.apc[6].pcv[6]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[7], greater.apc[6].pcv[7]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[8], greater.apc[6].pcv[8]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[9], greater.apc[6].pcv[9]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[10], greater.apc[6].pcv[10]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[11], greater.apc[6].pcv[11]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[12], greater.apc[6].pcv[12]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[13], greater.apc[6].pcv[13]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[14], greater.apc[6].pcv[14]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[15], greater.apc[6].pcv[15]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[16], greater.apc[6].pcv[16]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[17], greater.apc[6].pcv[17]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[18], greater.apc[6].pcv[18]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[19], greater.apc[6].pcv[19]);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].pcv[20], greater.apc[6].pcv[20]);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].sat_info, greater.apc[6].sat_info);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].sid.code, greater.apc[6].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].sid.sat, greater.apc[6].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.apc[6].svn, greater.apc[6].svn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_ssr_satellite_apc_dep_t lesser = info.test_msg;
    sbp_msg_ssr_satellite_apc_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.n_apc, greater.n_apc);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_satellite_apc_dep_t>::id,
  // SbpMsgSsrSatelliteApcDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_ssr_satellite_apc_dep_t>::name,
               "MSG_SSR_SATELLITE_APC_DEP");
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_ssr_satellite_apc_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_satellite_apc_dep_t>::get(const_sbp_msg_t);
  sbp_msg_ssr_satellite_apc_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_ssr_satellite_apc_dep_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_ssr_satellite_apc_dep_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.ssr_satellite_apc_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_ssr_satellite_apc_dep_t>::to_sbp_msg(info.test_msg,
                                                                  &msg2);
  EXPECT_EQ(msg2.ssr_satellite_apc_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_satellite_apc_dep_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_satellite_apc_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[224];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_satellite_apc_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 224);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 224), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_ssr_satellite_apc_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_ssr_satellite_apc_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 224);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0,
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

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgSsrSatelliteApcDep,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_ssr_MsgSsrSatelliteApcDepA0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgSsrSatelliteApcDep,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace