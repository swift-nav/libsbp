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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgOsr.yaml by generate.py. Do
// not modify by hand!

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
class Testauto_check_sbp_observation_MsgOsr0 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgOsr0() {
    assign(test_msg_.header.n_obs, 64);
    assign(test_msg_.header.t.ns_residual, 0);
    assign(test_msg_.header.t.tow, 501867000);
    assign(test_msg_.header.t.wn, 2152);
    assign(test_msg_.n_obs, 12);

    assign(test_msg_.obs[0].L.f, 66);
    assign(test_msg_.obs[0].L.i, 121567974);
    assign(test_msg_.obs[0].P, 1156681547);
    assign(test_msg_.obs[0].flags, 3);
    assign(test_msg_.obs[0].iono_std, 13);
    assign(test_msg_.obs[0].lock, 15);
    assign(test_msg_.obs[0].range_std, 7);
    assign(test_msg_.obs[0].sid.code, 0);
    assign(test_msg_.obs[0].sid.sat, 1);
    assign(test_msg_.obs[0].tropo_std, 7);

    assign(test_msg_.obs[1].L.f, 75);
    assign(test_msg_.obs[1].L.i, 111817196);
    assign(test_msg_.obs[1].P, 1063905486);
    assign(test_msg_.obs[1].flags, 3);
    assign(test_msg_.obs[1].iono_std, 13);
    assign(test_msg_.obs[1].lock, 15);
    assign(test_msg_.obs[1].range_std, 3);
    assign(test_msg_.obs[1].sid.code, 0);
    assign(test_msg_.obs[1].sid.sat, 13);
    assign(test_msg_.obs[1].tropo_std, 3);

    assign(test_msg_.obs[2].L.f, 128);
    assign(test_msg_.obs[2].L.i, 110692129);
    assign(test_msg_.obs[2].P, 1053200685);
    assign(test_msg_.obs[2].flags, 3);
    assign(test_msg_.obs[2].iono_std, 13);
    assign(test_msg_.obs[2].lock, 15);
    assign(test_msg_.obs[2].range_std, 3);
    assign(test_msg_.obs[2].sid.code, 0);
    assign(test_msg_.obs[2].sid.sat, 14);
    assign(test_msg_.obs[2].tropo_std, 3);

    assign(test_msg_.obs[3].L.f, 127);
    assign(test_msg_.obs[3].L.i, 119549583);
    assign(test_msg_.obs[3].P, 1137476697);
    assign(test_msg_.obs[3].flags, 3);
    assign(test_msg_.obs[3].iono_std, 13);
    assign(test_msg_.obs[3].lock, 15);
    assign(test_msg_.obs[3].range_std, 5);
    assign(test_msg_.obs[3].sid.code, 0);
    assign(test_msg_.obs[3].sid.sat, 15);
    assign(test_msg_.obs[3].tropo_std, 5);

    assign(test_msg_.obs[4].L.f, 55);
    assign(test_msg_.obs[4].L.i, 106934294);
    assign(test_msg_.obs[4].P, 1017446132);
    assign(test_msg_.obs[4].flags, 3);
    assign(test_msg_.obs[4].iono_std, 0);
    assign(test_msg_.obs[4].lock, 15);
    assign(test_msg_.obs[4].range_std, 2);
    assign(test_msg_.obs[4].sid.code, 0);
    assign(test_msg_.obs[4].sid.sat, 17);
    assign(test_msg_.obs[4].tropo_std, 2);

    assign(test_msg_.obs[5].L.f, 108);
    assign(test_msg_.obs[5].L.i, 110024343);
    assign(test_msg_.obs[5].P, 1046846826);
    assign(test_msg_.obs[5].flags, 3);
    assign(test_msg_.obs[5].iono_std, 13);
    assign(test_msg_.obs[5].lock, 15);
    assign(test_msg_.obs[5].range_std, 3);
    assign(test_msg_.obs[5].sid.code, 0);
    assign(test_msg_.obs[5].sid.sat, 19);
    assign(test_msg_.obs[5].tropo_std, 3);

    assign(test_msg_.obs[6].L.f, 206);
    assign(test_msg_.obs[6].L.i, 111507381);
    assign(test_msg_.obs[6].P, 1060957521);
    assign(test_msg_.obs[6].flags, 3);
    assign(test_msg_.obs[6].iono_std, 13);
    assign(test_msg_.obs[6].lock, 15);
    assign(test_msg_.obs[6].range_std, 3);
    assign(test_msg_.obs[6].sid.code, 0);
    assign(test_msg_.obs[6].sid.sat, 28);
    assign(test_msg_.obs[6].tropo_std, 3);

    assign(test_msg_.obs[7].L.f, 200);
    assign(test_msg_.obs[7].L.i, 113614775);
    assign(test_msg_.obs[7].P, 1081009286);
    assign(test_msg_.obs[7].flags, 3);
    assign(test_msg_.obs[7].iono_std, 13);
    assign(test_msg_.obs[7].lock, 15);
    assign(test_msg_.obs[7].range_std, 3);
    assign(test_msg_.obs[7].sid.code, 0);
    assign(test_msg_.obs[7].sid.sat, 30);
    assign(test_msg_.obs[7].tropo_std, 3);

    assign(test_msg_.obs[8].L.f, 170);
    assign(test_msg_.obs[8].L.i, 94728270);
    assign(test_msg_.obs[8].P, 1156681781);
    assign(test_msg_.obs[8].flags, 3);
    assign(test_msg_.obs[8].iono_std, 21);
    assign(test_msg_.obs[8].lock, 15);
    assign(test_msg_.obs[8].range_std, 7);
    assign(test_msg_.obs[8].sid.code, 6);
    assign(test_msg_.obs[8].sid.sat, 1);
    assign(test_msg_.obs[8].tropo_std, 7);

    assign(test_msg_.obs[9].L.f, 129);
    assign(test_msg_.obs[9].L.i, 87130275);
    assign(test_msg_.obs[9].P, 1063905531);
    assign(test_msg_.obs[9].flags, 3);
    assign(test_msg_.obs[9].iono_std, 21);
    assign(test_msg_.obs[9].lock, 15);
    assign(test_msg_.obs[9].range_std, 3);
    assign(test_msg_.obs[9].sid.code, 6);
    assign(test_msg_.obs[9].sid.sat, 13);
    assign(test_msg_.obs[9].tropo_std, 3);

    assign(test_msg_.obs[10].L.f, 46);
    assign(test_msg_.obs[10].L.i, 86253605);
    assign(test_msg_.obs[10].P, 1053200752);
    assign(test_msg_.obs[10].flags, 3);
    assign(test_msg_.obs[10].iono_std, 21);
    assign(test_msg_.obs[10].lock, 15);
    assign(test_msg_.obs[10].range_std, 3);
    assign(test_msg_.obs[10].sid.code, 6);
    assign(test_msg_.obs[10].sid.sat, 14);
    assign(test_msg_.obs[10].tropo_std, 3);

    assign(test_msg_.obs[11].L.f, 95);
    assign(test_msg_.obs[11].L.i, 93155512);
    assign(test_msg_.obs[11].P, 1137476774);
    assign(test_msg_.obs[11].flags, 3);
    assign(test_msg_.obs[11].iono_std, 21);
    assign(test_msg_.obs[11].lock, 15);
    assign(test_msg_.obs[11].range_std, 5);
    assign(test_msg_.obs[11].sid.code, 6);
    assign(test_msg_.obs[11].sid.sat, 15);
    assign(test_msg_.obs[11].tropo_std, 5);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_osr_t> {
    using sbp::MessageHandler<sbp_msg_osr_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_osr_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id, const sbp_msg_osr_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgOsr, &CHandler::callback_static, this,
                            &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_osr_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgOsr);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->osr, sizeof(msg->osr));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_osr_t test_msg;
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
    memcpy(&info.test_msg_wrapped.osr, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgOsr);
    info.sender_id = 0;
    info.preamble = 0x55;
    info.crc = 0xe379;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 239;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_osr_t &lesser,
                        const sbp_msg_osr_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_osr_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_osr_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_osr_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_osr_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_osr_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_osr_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgOsr, &wrapped_lesser, &wrapped_lesser), 0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgOsr, &wrapped_greater, &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgOsr, &wrapped_lesser, &wrapped_greater), 0);
    EXPECT_GT(sbp_message_cmp(SbpMsgOsr, &wrapped_greater, &wrapped_lesser), 0);

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
  sbp_msg_osr_t test_msg_{};
  uint8_t encoded_frame_[239 + 8] = {
      85,  64,  6,   0,   0,   239, 248, 225, 233, 29,  0,   0,   0,   0,   104,
      8,   64,  75,  143, 241, 68,  230, 250, 62,  7,   66,  15,  3,   1,   0,
      13,  0,   7,   0,   7,   0,   206, 232, 105, 63,  236, 49,  170, 6,   75,
      15,  3,   13,  0,   13,  0,   3,   0,   3,   0,   45,  145, 198, 62,  33,
      7,   153, 6,   128, 15,  3,   14,  0,   13,  0,   3,   0,   3,   0,   89,
      132, 204, 67,  143, 46,  32,  7,   127, 15,  3,   15,  0,   13,  0,   5,
      0,   5,   0,   244, 254, 164, 60,  22,  176, 95,  6,   55,  15,  3,   17,
      0,   0,   0,   2,   0,   2,   0,   106, 157, 101, 62,  151, 214, 142, 6,
      108, 15,  3,   19,  0,   13,  0,   3,   0,   3,   0,   81,  237, 60,  63,
      181, 119, 165, 6,   206, 15,  3,   28,  0,   13,  0,   3,   0,   3,   0,
      134, 228, 110, 64,  183, 159, 197, 6,   200, 15,  3,   30,  0,   13,  0,
      3,   0,   3,   0,   53,  144, 241, 68,  78,  112, 165, 5,   170, 15,  3,
      1,   6,   21,  0,   7,   0,   7,   0,   251, 232, 105, 63,  163, 128, 49,
      5,   129, 15,  3,   13,  6,   21,  0,   3,   0,   3,   0,   112, 145, 198,
      62,  37,  32,  36,  5,   46,  15,  3,   14,  6,   21,  0,   3,   0,   3,
      0,   166, 132, 204, 67,  184, 112, 141, 5,   95,  15,  3,   15,  6,   21,
      0,   5,   0,   5,   0,   121, 227,
  };
  uint8_t encoded_payload_[239] = {
      248, 225, 233, 29,  0,   0,   0,   0,   104, 8,   64,  75,  143, 241, 68,
      230, 250, 62,  7,   66,  15,  3,   1,   0,   13,  0,   7,   0,   7,   0,
      206, 232, 105, 63,  236, 49,  170, 6,   75,  15,  3,   13,  0,   13,  0,
      3,   0,   3,   0,   45,  145, 198, 62,  33,  7,   153, 6,   128, 15,  3,
      14,  0,   13,  0,   3,   0,   3,   0,   89,  132, 204, 67,  143, 46,  32,
      7,   127, 15,  3,   15,  0,   13,  0,   5,   0,   5,   0,   244, 254, 164,
      60,  22,  176, 95,  6,   55,  15,  3,   17,  0,   0,   0,   2,   0,   2,
      0,   106, 157, 101, 62,  151, 214, 142, 6,   108, 15,  3,   19,  0,   13,
      0,   3,   0,   3,   0,   81,  237, 60,  63,  181, 119, 165, 6,   206, 15,
      3,   28,  0,   13,  0,   3,   0,   3,   0,   134, 228, 110, 64,  183, 159,
      197, 6,   200, 15,  3,   30,  0,   13,  0,   3,   0,   3,   0,   53,  144,
      241, 68,  78,  112, 165, 5,   170, 15,  3,   1,   6,   21,  0,   7,   0,
      7,   0,   251, 232, 105, 63,  163, 128, 49,  5,   129, 15,  3,   13,  6,
      21,  0,   3,   0,   3,   0,   112, 145, 198, 62,  37,  32,  36,  5,   46,
      15,  3,   14,  6,   21,  0,   3,   0,   3,   0,   166, 132, 204, 67,  184,
      112, 141, 5,   95,  15,  3,   15,  6,   21,  0,   5,   0,   5,   0,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgOsr0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_osr_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgOsr, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[239];
  uint8_t n_written;

  EXPECT_EQ(
      sbp_msg_osr_encode(&buf[0], sizeof(buf), &n_written, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(n_written, 239);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 239), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgOsr,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 239);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 239), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[239];

  EXPECT_EQ(sbp_msg_osr_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 239), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgOsr0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[239];

  for (uint8_t i = 0; i < 239; i++) {
    EXPECT_EQ(sbp_msg_osr_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_osr_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_osr_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 239);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgOsr, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 239);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_osr_t msg{};

  EXPECT_EQ(sbp_msg_osr_decode(&info.encoded_payload[0], info.payload_len,
                               nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgOsr0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_osr_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_osr_t t{};
      return sbp_msg_osr_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_osr_t t{};
      t.n_obs = 1;
      return sbp_msg_osr_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_osr_decode(&info.encoded_payload[0], i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgOsr0,
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

TEST_F(Testauto_check_sbp_observation_MsgOsr0, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgOsr0, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgOsr0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_osr_send(&state, info.sender_id, &info.test_msg,
                             &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgOsr, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgOsr, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgOsr, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.ns_residual,
                        greater.header.t.ns_residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].flags, greater.obs[0].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].iono_std, greater.obs[0].iono_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].range_std, greater.obs[0].range_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.code, greater.obs[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.sat, greater.obs[0].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].tropo_std, greater.obs[0].tropo_std);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].flags, greater.obs[1].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].iono_std, greater.obs[1].iono_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].range_std, greater.obs[1].range_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.code, greater.obs[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.sat, greater.obs[1].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].tropo_std, greater.obs[1].tropo_std);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].flags, greater.obs[2].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].iono_std, greater.obs[2].iono_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].range_std, greater.obs[2].range_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.code, greater.obs[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.sat, greater.obs[2].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].tropo_std, greater.obs[2].tropo_std);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.f, greater.obs[3].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.i, greater.obs[3].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].P, greater.obs[3].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].flags, greater.obs[3].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].iono_std, greater.obs[3].iono_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].lock, greater.obs[3].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].range_std, greater.obs[3].range_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.code, greater.obs[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.sat, greater.obs[3].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].tropo_std, greater.obs[3].tropo_std);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.f, greater.obs[4].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.i, greater.obs[4].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].P, greater.obs[4].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].flags, greater.obs[4].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].iono_std, greater.obs[4].iono_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].lock, greater.obs[4].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].range_std, greater.obs[4].range_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.code, greater.obs[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.sat, greater.obs[4].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].tropo_std, greater.obs[4].tropo_std);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].L.f, greater.obs[5].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].L.i, greater.obs[5].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].P, greater.obs[5].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].flags, greater.obs[5].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].iono_std, greater.obs[5].iono_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].lock, greater.obs[5].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].range_std, greater.obs[5].range_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].sid.code, greater.obs[5].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].sid.sat, greater.obs[5].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].tropo_std, greater.obs[5].tropo_std);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].L.f, greater.obs[6].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].L.i, greater.obs[6].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].P, greater.obs[6].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].flags, greater.obs[6].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].iono_std, greater.obs[6].iono_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].lock, greater.obs[6].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].range_std, greater.obs[6].range_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].sid.code, greater.obs[6].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].sid.sat, greater.obs[6].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].tropo_std, greater.obs[6].tropo_std);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].L.f, greater.obs[7].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].L.i, greater.obs[7].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].P, greater.obs[7].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].flags, greater.obs[7].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].iono_std, greater.obs[7].iono_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].lock, greater.obs[7].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].range_std, greater.obs[7].range_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].sid.code, greater.obs[7].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].sid.sat, greater.obs[7].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].tropo_std, greater.obs[7].tropo_std);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].L.f, greater.obs[8].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].L.i, greater.obs[8].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].P, greater.obs[8].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].flags, greater.obs[8].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].iono_std, greater.obs[8].iono_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].lock, greater.obs[8].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].range_std, greater.obs[8].range_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].sid.code, greater.obs[8].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].sid.sat, greater.obs[8].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].tropo_std, greater.obs[8].tropo_std);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].L.f, greater.obs[9].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].L.i, greater.obs[9].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].P, greater.obs[9].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].flags, greater.obs[9].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].iono_std, greater.obs[9].iono_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].lock, greater.obs[9].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].range_std, greater.obs[9].range_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].sid.code, greater.obs[9].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].sid.sat, greater.obs[9].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].tropo_std, greater.obs[9].tropo_std);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].L.f, greater.obs[10].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].L.i, greater.obs[10].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].P, greater.obs[10].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].flags, greater.obs[10].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].iono_std, greater.obs[10].iono_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].lock, greater.obs[10].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].range_std, greater.obs[10].range_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].sid.code, greater.obs[10].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].sid.sat, greater.obs[10].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].tropo_std, greater.obs[10].tropo_std);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].L.f, greater.obs[11].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].L.i, greater.obs[11].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].P, greater.obs[11].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].flags, greater.obs[11].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].iono_std, greater.obs[11].iono_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].lock, greater.obs[11].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].range_std, greater.obs[11].range_std);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].sid.code, greater.obs[11].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].sid.sat, greater.obs[11].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_osr_t lesser = info.test_msg;
    sbp_msg_osr_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].tropo_std, greater.obs[11].tropo_std);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_osr_t>::id, SbpMsgOsr);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_osr_t>::name, "MSG_OSR");
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_osr_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_osr_t>::get(const_sbp_msg_t);
  sbp_msg_osr_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_osr_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 = sbp::MessageTraits<sbp_msg_osr_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.osr, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_osr_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.osr, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_osr_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_osr_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[239];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_osr_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 239);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 239), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_osr_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_osr_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 239);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_observation_MsgOsr0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgOsr, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgOsr0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgOsr, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace