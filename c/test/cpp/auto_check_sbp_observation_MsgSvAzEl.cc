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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgSvAzEl.yaml by generate.py.
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
class Testauto_check_sbp_observation_MsgSvAzEl0 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgSvAzEl0() {
    assign(test_msg_.azel[0].az, 160);
    assign(test_msg_.azel[0].el, 12);
    assign(test_msg_.azel[0].sid.code, 0);
    assign(test_msg_.azel[0].sid.sat, 8);

    assign(test_msg_.azel[1].az, 139);
    assign(test_msg_.azel[1].el, 66);
    assign(test_msg_.azel[1].sid.code, 0);
    assign(test_msg_.azel[1].sid.sat, 10);

    assign(test_msg_.azel[2].az, 16);
    assign(test_msg_.azel[2].el, 1);
    assign(test_msg_.azel[2].sid.code, 0);
    assign(test_msg_.azel[2].sid.sat, 13);

    assign(test_msg_.azel[3].az, 24);
    assign(test_msg_.azel[3].el, 25);
    assign(test_msg_.azel[3].sid.code, 0);
    assign(test_msg_.azel[3].sid.sat, 15);

    assign(test_msg_.azel[4].az, 127);
    assign(test_msg_.azel[4].el, 18);
    assign(test_msg_.azel[4].sid.code, 0);
    assign(test_msg_.azel[4].sid.sat, 16);

    assign(test_msg_.azel[5].az, 42);
    assign(test_msg_.azel[5].el, 53);
    assign(test_msg_.azel[5].sid.code, 0);
    assign(test_msg_.azel[5].sid.sat, 18);

    assign(test_msg_.azel[6].az, 31);
    assign(test_msg_.azel[6].el, 16);
    assign(test_msg_.azel[6].sid.code, 0);
    assign(test_msg_.azel[6].sid.sat, 20);

    assign(test_msg_.azel[7].az, 12);
    assign(test_msg_.azel[7].el, 67);
    assign(test_msg_.azel[7].sid.code, 0);
    assign(test_msg_.azel[7].sid.sat, 23);

    assign(test_msg_.azel[8].az, 47);
    assign(test_msg_.azel[8].el, 10);
    assign(test_msg_.azel[8].sid.code, 0);
    assign(test_msg_.azel[8].sid.sat, 24);

    assign(test_msg_.azel[9].az, 116);
    assign(test_msg_.azel[9].el, 8);
    assign(test_msg_.azel[9].sid.code, 0);
    assign(test_msg_.azel[9].sid.sat, 26);

    assign(test_msg_.azel[10].az, 153);
    assign(test_msg_.azel[10].el, 43);
    assign(test_msg_.azel[10].sid.code, 0);
    assign(test_msg_.azel[10].sid.sat, 27);

    assign(test_msg_.azel[11].az, 77);
    assign(test_msg_.azel[11].el, 10);
    assign(test_msg_.azel[11].sid.code, 0);
    assign(test_msg_.azel[11].sid.sat, 29);

    assign(test_msg_.azel[12].az, 94);
    assign(test_msg_.azel[12].el, 26);
    assign(test_msg_.azel[12].sid.code, 0);
    assign(test_msg_.azel[12].sid.sat, 32);

    assign(test_msg_.azel[13].az, 16);
    assign(test_msg_.azel[13].el, 58);
    assign(test_msg_.azel[13].sid.code, 3);
    assign(test_msg_.azel[13].sid.sat, 1);

    assign(test_msg_.azel[14].az, 108);
    assign(test_msg_.azel[14].el, 53);
    assign(test_msg_.azel[14].sid.code, 3);
    assign(test_msg_.azel[14].sid.sat, 2);

    assign(test_msg_.azel[15].az, 17);
    assign(test_msg_.azel[15].el, 13);
    assign(test_msg_.azel[15].sid.code, 3);
    assign(test_msg_.azel[15].sid.sat, 8);

    assign(test_msg_.azel[16].az, 165);
    assign(test_msg_.azel[16].el, 40);
    assign(test_msg_.azel[16].sid.code, 3);
    assign(test_msg_.azel[16].sid.sat, 17);

    assign(test_msg_.azel[17].az, 63);
    assign(test_msg_.azel[17].el, 35);
    assign(test_msg_.azel[17].sid.code, 3);
    assign(test_msg_.azel[17].sid.sat, 23);

    assign(test_msg_.azel[18].az, 41);
    assign(test_msg_.azel[18].el, 73);
    assign(test_msg_.azel[18].sid.code, 3);
    assign(test_msg_.azel[18].sid.sat, 24);

    assign(test_msg_.azel[19].az, 114);
    assign(test_msg_.azel[19].el, 26);
    assign(test_msg_.azel[19].sid.code, 12);
    assign(test_msg_.azel[19].sid.sat, 20);

    assign(test_msg_.azel[20].az, 72);
    assign(test_msg_.azel[20].el, 54);
    assign(test_msg_.azel[20].sid.code, 12);
    assign(test_msg_.azel[20].sid.sat, 27);

    assign(test_msg_.azel[21].az, 69);
    assign(test_msg_.azel[21].el, 3);
    assign(test_msg_.azel[21].sid.code, 12);
    assign(test_msg_.azel[21].sid.sat, 28);

    assign(test_msg_.azel[22].az, 158);
    assign(test_msg_.azel[22].el, 14);
    assign(test_msg_.azel[22].sid.code, 12);
    assign(test_msg_.azel[22].sid.sat, 29);

    assign(test_msg_.azel[23].az, 152);
    assign(test_msg_.azel[23].el, 68);
    assign(test_msg_.azel[23].sid.code, 12);
    assign(test_msg_.azel[23].sid.sat, 30);

    assign(test_msg_.azel[24].az, 120);
    assign(test_msg_.azel[24].el, 82);
    assign(test_msg_.azel[24].sid.code, 12);
    assign(test_msg_.azel[24].sid.sat, 32);

    assign(test_msg_.azel[25].az, 131);
    assign(test_msg_.azel[25].el, 6);
    assign(test_msg_.azel[25].sid.code, 14);
    assign(test_msg_.azel[25].sid.sat, 2);

    assign(test_msg_.azel[26].az, 27);
    assign(test_msg_.azel[26].el, 44);
    assign(test_msg_.azel[26].sid.code, 14);
    assign(test_msg_.azel[26].sid.sat, 4);

    assign(test_msg_.azel[27].az, 101);
    assign(test_msg_.azel[27].el, 21);
    assign(test_msg_.azel[27].sid.code, 14);
    assign(test_msg_.azel[27].sid.sat, 5);

    assign(test_msg_.azel[28].az, 81);
    assign(test_msg_.azel[28].el, 65);
    assign(test_msg_.azel[28].sid.code, 14);
    assign(test_msg_.azel[28].sid.sat, 9);

    assign(test_msg_.azel[29].az, 49);
    assign(test_msg_.azel[29].el, 56);
    assign(test_msg_.azel[29].sid.code, 14);
    assign(test_msg_.azel[29].sid.sat, 11);

    assign(test_msg_.azel[30].az, 59);
    assign(test_msg_.azel[30].el, 6);
    assign(test_msg_.azel[30].sid.code, 14);
    assign(test_msg_.azel[30].sid.sat, 12);

    assign(test_msg_.azel[31].az, 154);
    assign(test_msg_.azel[31].el, 4);
    assign(test_msg_.azel[31].sid.code, 14);
    assign(test_msg_.azel[31].sid.sat, 30);

    assign(test_msg_.azel[32].az, 165);
    assign(test_msg_.azel[32].el, 62);
    assign(test_msg_.azel[32].sid.code, 14);
    assign(test_msg_.azel[32].sid.sat, 36);
    assign(test_msg_.n_azel, 33);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_sv_az_el_t> {
    using sbp::MessageHandler<sbp_msg_sv_az_el_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_sv_az_el_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_sv_az_el_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgSvAzEl, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_sv_az_el_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgSvAzEl);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->sv_az_el, sizeof(msg->sv_az_el));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_sv_az_el_t test_msg;
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
    memcpy(&info.test_msg_wrapped.sv_az_el, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgSvAzEl);
    info.sender_id = 31183;
    info.preamble = 0x55;
    info.crc = 0x24A8;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 132;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_sv_az_el_t &lesser,
                        const sbp_msg_sv_az_el_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_sv_az_el_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_sv_az_el_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_sv_az_el_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_sv_az_el_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_sv_az_el_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_sv_az_el_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgSvAzEl, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgSvAzEl, &wrapped_greater, &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgSvAzEl, &wrapped_lesser, &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgSvAzEl, &wrapped_greater, &wrapped_lesser),
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
  sbp_msg_sv_az_el_t test_msg_{};
  uint8_t encoded_frame_[132 + 8] = {
      85,  151, 0,  207, 121, 132, 8,  0,  160, 12, 10,  0,  139, 66, 13, 0,
      16,  1,   15, 0,   24,  25,  16, 0,  127, 18, 18,  0,  42,  53, 20, 0,
      31,  16,  23, 0,   12,  67,  24, 0,  47,  10, 26,  0,  116, 8,  27, 0,
      153, 43,  29, 0,   77,  10,  32, 0,  94,  26, 1,   3,  16,  58, 2,  3,
      108, 53,  8,  3,   17,  13,  17, 3,  165, 40, 23,  3,  63,  35, 24, 3,
      41,  73,  20, 12,  114, 26,  27, 12, 72,  54, 28,  12, 69,  3,  29, 12,
      158, 14,  30, 12,  152, 68,  32, 12, 120, 82, 2,   14, 131, 6,  4,  14,
      27,  44,  5,  14,  101, 21,  9,  14, 81,  65, 11,  14, 49,  56, 12, 14,
      59,  6,   30, 14,  154, 4,   36, 14, 165, 62, 168, 36,
  };
  uint8_t encoded_payload_[132] = {
      8,   0,  160, 12,  10,  0,   139, 66, 13,  0,  16,  1,  15,  0,   24,
      25,  16, 0,   127, 18,  18,  0,   42, 53,  20, 0,   31, 16,  23,  0,
      12,  67, 24,  0,   47,  10,  26,  0,  116, 8,  27,  0,  153, 43,  29,
      0,   77, 10,  32,  0,   94,  26,  1,  3,   16, 58,  2,  3,   108, 53,
      8,   3,  17,  13,  17,  3,   165, 40, 23,  3,  63,  35, 24,  3,   41,
      73,  20, 12,  114, 26,  27,  12,  72, 54,  28, 12,  69, 3,   29,  12,
      158, 14, 30,  12,  152, 68,  32,  12, 120, 82, 2,   14, 131, 6,   4,
      14,  27, 44,  5,   14,  101, 21,  9,  14,  81, 65,  11, 14,  49,  56,
      12,  14, 59,  6,   30,  14,  154, 4,  36,  14, 165, 62,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_sv_az_el_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgSvAzEl, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[132];
  uint8_t n_written;

  EXPECT_EQ(
      sbp_msg_sv_az_el_encode(&buf[0], sizeof(buf), &n_written, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(n_written, 132);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 132), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgSvAzEl,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 132);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 132), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[132];

  EXPECT_EQ(
      sbp_msg_sv_az_el_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 132), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[132];

  for (uint8_t i = 0; i < 132; i++) {
    EXPECT_EQ(sbp_msg_sv_az_el_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_sv_az_el_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_sv_az_el_decode(&info.encoded_payload[0], info.payload_len,
                                    &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 132);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgSvAzEl, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 132);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_sv_az_el_t msg{};

  EXPECT_EQ(sbp_msg_sv_az_el_decode(&info.encoded_payload[0], info.payload_len,
                                    nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_sv_az_el_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_sv_az_el_t t{};
      return sbp_msg_sv_az_el_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_sv_az_el_t t{};
      t.n_azel = 1;
      return sbp_msg_sv_az_el_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(
        sbp_msg_sv_az_el_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0,
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

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_sv_az_el_send(&state, info.sender_id, &info.test_msg,
                                  &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSvAzEl, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgSvAzEl, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgSvAzEl, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, Comparison) {
  auto info = get_test_msg_info();

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[0].az, greater.azel[0].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[0].el, greater.azel[0].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[0].sid.code, greater.azel[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[0].sid.sat, greater.azel[0].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[1].az, greater.azel[1].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[1].el, greater.azel[1].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[1].sid.code, greater.azel[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[1].sid.sat, greater.azel[1].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[2].az, greater.azel[2].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[2].el, greater.azel[2].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[2].sid.code, greater.azel[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[2].sid.sat, greater.azel[2].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[3].az, greater.azel[3].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[3].el, greater.azel[3].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[3].sid.code, greater.azel[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[3].sid.sat, greater.azel[3].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[4].az, greater.azel[4].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[4].el, greater.azel[4].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[4].sid.code, greater.azel[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[4].sid.sat, greater.azel[4].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[5].az, greater.azel[5].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[5].el, greater.azel[5].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[5].sid.code, greater.azel[5].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[5].sid.sat, greater.azel[5].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[6].az, greater.azel[6].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[6].el, greater.azel[6].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[6].sid.code, greater.azel[6].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[6].sid.sat, greater.azel[6].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[7].az, greater.azel[7].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[7].el, greater.azel[7].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[7].sid.code, greater.azel[7].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[7].sid.sat, greater.azel[7].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[8].az, greater.azel[8].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[8].el, greater.azel[8].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[8].sid.code, greater.azel[8].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[8].sid.sat, greater.azel[8].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[9].az, greater.azel[9].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[9].el, greater.azel[9].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[9].sid.code, greater.azel[9].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[9].sid.sat, greater.azel[9].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[10].az, greater.azel[10].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[10].el, greater.azel[10].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[10].sid.code, greater.azel[10].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[10].sid.sat, greater.azel[10].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[11].az, greater.azel[11].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[11].el, greater.azel[11].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[11].sid.code, greater.azel[11].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[11].sid.sat, greater.azel[11].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[12].az, greater.azel[12].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[12].el, greater.azel[12].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[12].sid.code, greater.azel[12].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[12].sid.sat, greater.azel[12].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[13].az, greater.azel[13].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[13].el, greater.azel[13].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[13].sid.code, greater.azel[13].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[13].sid.sat, greater.azel[13].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[14].az, greater.azel[14].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[14].el, greater.azel[14].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[14].sid.code, greater.azel[14].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[14].sid.sat, greater.azel[14].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[15].az, greater.azel[15].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[15].el, greater.azel[15].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[15].sid.code, greater.azel[15].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[15].sid.sat, greater.azel[15].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[16].az, greater.azel[16].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[16].el, greater.azel[16].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[16].sid.code, greater.azel[16].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[16].sid.sat, greater.azel[16].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[17].az, greater.azel[17].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[17].el, greater.azel[17].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[17].sid.code, greater.azel[17].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[17].sid.sat, greater.azel[17].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[18].az, greater.azel[18].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[18].el, greater.azel[18].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[18].sid.code, greater.azel[18].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[18].sid.sat, greater.azel[18].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[19].az, greater.azel[19].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[19].el, greater.azel[19].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[19].sid.code, greater.azel[19].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[19].sid.sat, greater.azel[19].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[20].az, greater.azel[20].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[20].el, greater.azel[20].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[20].sid.code, greater.azel[20].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[20].sid.sat, greater.azel[20].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[21].az, greater.azel[21].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[21].el, greater.azel[21].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[21].sid.code, greater.azel[21].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[21].sid.sat, greater.azel[21].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[22].az, greater.azel[22].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[22].el, greater.azel[22].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[22].sid.code, greater.azel[22].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[22].sid.sat, greater.azel[22].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[23].az, greater.azel[23].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[23].el, greater.azel[23].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[23].sid.code, greater.azel[23].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[23].sid.sat, greater.azel[23].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[24].az, greater.azel[24].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[24].el, greater.azel[24].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[24].sid.code, greater.azel[24].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[24].sid.sat, greater.azel[24].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[25].az, greater.azel[25].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[25].el, greater.azel[25].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[25].sid.code, greater.azel[25].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[25].sid.sat, greater.azel[25].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[26].az, greater.azel[26].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[26].el, greater.azel[26].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[26].sid.code, greater.azel[26].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[26].sid.sat, greater.azel[26].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[27].az, greater.azel[27].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[27].el, greater.azel[27].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[27].sid.code, greater.azel[27].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[27].sid.sat, greater.azel[27].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[28].az, greater.azel[28].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[28].el, greater.azel[28].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[28].sid.code, greater.azel[28].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[28].sid.sat, greater.azel[28].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[29].az, greater.azel[29].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[29].el, greater.azel[29].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[29].sid.code, greater.azel[29].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[29].sid.sat, greater.azel[29].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[30].az, greater.azel[30].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[30].el, greater.azel[30].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[30].sid.code, greater.azel[30].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[30].sid.sat, greater.azel[30].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[31].az, greater.azel[31].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[31].el, greater.azel[31].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[31].sid.code, greater.azel[31].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[31].sid.sat, greater.azel[31].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[32].az, greater.azel[32].az);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[32].el, greater.azel[32].el);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[32].sid.code, greater.azel[32].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.azel[32].sid.sat, greater.azel[32].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_sv_az_el_t lesser = info.test_msg;
    sbp_msg_sv_az_el_t greater = info.test_msg;
    make_lesser_greater(lesser.n_azel, greater.n_azel);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_sv_az_el_t>::id, SbpMsgSvAzEl);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_sv_az_el_t>::name, "MSG_SV_AZ_EL");
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_sv_az_el_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_sv_az_el_t>::get(const_sbp_msg_t);
  sbp_msg_sv_az_el_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_sv_az_el_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_sv_az_el_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.sv_az_el, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_sv_az_el_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.sv_az_el, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_sv_az_el_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_sv_az_el_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[132];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_sv_az_el_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 132);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 132), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_sv_az_el_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_sv_az_el_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 132);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0,
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

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgSvAzEl, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgSvAzEl0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgSvAzEl, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace
