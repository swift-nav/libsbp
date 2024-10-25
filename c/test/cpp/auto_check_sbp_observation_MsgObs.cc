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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgObs.yaml by generate.py. Do
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
class Testauto_check_sbp_observation_MsgObs0 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgObs0() {
    assign(test_msg_.header.n_obs, 32);
    assign(test_msg_.header.t.ns_residual, 0);
    assign(test_msg_.header.t.tow, 434293400);
    assign(test_msg_.header.t.wn, 2154);
    assign(test_msg_.n_obs, 14);

    assign(test_msg_.obs[0].D.f, 172);
    assign(test_msg_.obs[0].D.i, -1536);
    assign(test_msg_.obs[0].L.f, 146);
    assign(test_msg_.obs[0].L.i, 111080057);
    assign(test_msg_.obs[0].P, 1056891697);
    assign(test_msg_.obs[0].cn0, 182);
    assign(test_msg_.obs[0].flags, 15);
    assign(test_msg_.obs[0].lock, 10);
    assign(test_msg_.obs[0].sid.code, 0);
    assign(test_msg_.obs[0].sid.sat, 10);

    assign(test_msg_.obs[1].D.f, 172);
    assign(test_msg_.obs[1].D.i, -1197);
    assign(test_msg_.obs[1].L.f, 59);
    assign(test_msg_.obs[1].L.i, 86555916);
    assign(test_msg_.obs[1].P, 1056891934);
    assign(test_msg_.obs[1].cn0, 178);
    assign(test_msg_.obs[1].flags, 15);
    assign(test_msg_.obs[1].lock, 10);
    assign(test_msg_.obs[1].sid.code, 1);
    assign(test_msg_.obs[1].sid.sat, 10);

    assign(test_msg_.obs[2].D.f, 119);
    assign(test_msg_.obs[2].D.i, -3219);
    assign(test_msg_.obs[2].L.f, 243);
    assign(test_msg_.obs[2].L.i, 127954794);
    assign(test_msg_.obs[2].P, 1217449431);
    assign(test_msg_.obs[2].cn0, 158);
    assign(test_msg_.obs[2].flags, 15);
    assign(test_msg_.obs[2].lock, 10);
    assign(test_msg_.obs[2].sid.code, 0);
    assign(test_msg_.obs[2].sid.sat, 18);

    assign(test_msg_.obs[3].D.f, 27);
    assign(test_msg_.obs[3].D.i, -2508);
    assign(test_msg_.obs[3].L.f, 12);
    assign(test_msg_.obs[3].L.i, 99705055);
    assign(test_msg_.obs[3].P, 1217449753);
    assign(test_msg_.obs[3].cn0, 125);
    assign(test_msg_.obs[3].flags, 11);
    assign(test_msg_.obs[3].lock, 9);
    assign(test_msg_.obs[3].sid.code, 1);
    assign(test_msg_.obs[3].sid.sat, 18);

    assign(test_msg_.obs[4].D.f, 245);
    assign(test_msg_.obs[4].D.i, 2829);
    assign(test_msg_.obs[4].L.f, 53);
    assign(test_msg_.obs[4].L.i, 132024982);
    assign(test_msg_.obs[4].P, 1256175650);
    assign(test_msg_.obs[4].cn0, 114);
    assign(test_msg_.obs[4].flags, 15);
    assign(test_msg_.obs[4].lock, 9);
    assign(test_msg_.obs[4].sid.code, 0);
    assign(test_msg_.obs[4].sid.sat, 22);

    assign(test_msg_.obs[5].D.f, 246);
    assign(test_msg_.obs[5].D.i, -2433);
    assign(test_msg_.obs[5].L.f, 70);
    assign(test_msg_.obs[5].L.i, 121711010);
    assign(test_msg_.obs[5].P, 1158041713);
    assign(test_msg_.obs[5].cn0, 189);
    assign(test_msg_.obs[5].flags, 15);
    assign(test_msg_.obs[5].lock, 9);
    assign(test_msg_.obs[5].sid.code, 0);
    assign(test_msg_.obs[5].sid.sat, 23);

    assign(test_msg_.obs[6].D.f, 231);
    assign(test_msg_.obs[6].D.i, -1896);
    assign(test_msg_.obs[6].L.f, 221);
    assign(test_msg_.obs[6].L.i, 94839765);
    assign(test_msg_.obs[6].P, 1158041847);
    assign(test_msg_.obs[6].cn0, 158);
    assign(test_msg_.obs[6].flags, 11);
    assign(test_msg_.obs[6].lock, 9);
    assign(test_msg_.obs[6].sid.code, 1);
    assign(test_msg_.obs[6].sid.sat, 23);

    assign(test_msg_.obs[7].D.f, 67);
    assign(test_msg_.obs[7].D.i, -1997);
    assign(test_msg_.obs[7].L.f, 114);
    assign(test_msg_.obs[7].L.i, 113998348);
    assign(test_msg_.obs[7].P, 1084658184);
    assign(test_msg_.obs[7].cn0, 93);
    assign(test_msg_.obs[7].flags, 11);
    assign(test_msg_.obs[7].lock, 3);
    assign(test_msg_.obs[7].sid.code, 0);
    assign(test_msg_.obs[7].sid.sat, 27);

    assign(test_msg_.obs[8].D.f, 237);
    assign(test_msg_.obs[8].D.i, 3041);
    assign(test_msg_.obs[8].L.f, 232);
    assign(test_msg_.obs[8].L.i, 133443545);
    assign(test_msg_.obs[8].P, 1269673181);
    assign(test_msg_.obs[8].cn0, 123);
    assign(test_msg_.obs[8].flags, 15);
    assign(test_msg_.obs[8].lock, 5);
    assign(test_msg_.obs[8].sid.code, 0);
    assign(test_msg_.obs[8].sid.sat, 31);

    assign(test_msg_.obs[9].D.f, 62);
    assign(test_msg_.obs[9].D.i, 2374);
    assign(test_msg_.obs[9].L.f, 40);
    assign(test_msg_.obs[9].L.i, 103982040);
    assign(test_msg_.obs[9].P, 1269673722);
    assign(test_msg_.obs[9].cn0, 120);
    assign(test_msg_.obs[9].flags, 11);
    assign(test_msg_.obs[9].lock, 3);
    assign(test_msg_.obs[9].sid.code, 1);
    assign(test_msg_.obs[9].sid.sat, 31);

    assign(test_msg_.obs[10].D.f, 96);
    assign(test_msg_.obs[10].D.i, -3446);
    assign(test_msg_.obs[10].L.f, 7);
    assign(test_msg_.obs[10].L.i, 118217315);
    assign(test_msg_.obs[10].P, 1107693703);
    assign(test_msg_.obs[10].cn0, 176);
    assign(test_msg_.obs[10].flags, 15);
    assign(test_msg_.obs[10].lock, 10);
    assign(test_msg_.obs[10].sid.code, 3);
    assign(test_msg_.obs[10].sid.sat, 2);

    assign(test_msg_.obs[11].D.f, 96);
    assign(test_msg_.obs[11].D.i, -1003);
    assign(test_msg_.obs[11].L.f, 203);
    assign(test_msg_.obs[11].L.i, 104224985);
    assign(test_msg_.obs[11].P, 973505172);
    assign(test_msg_.obs[11].cn0, 170);
    assign(test_msg_.obs[11].flags, 15);
    assign(test_msg_.obs[11].lock, 10);
    assign(test_msg_.obs[11].sid.code, 3);
    assign(test_msg_.obs[11].sid.sat, 3);

    assign(test_msg_.obs[12].D.f, 219);
    assign(test_msg_.obs[12].D.i, -3836);
    assign(test_msg_.obs[12].L.f, 80);
    assign(test_msg_.obs[12].L.i, 114505343);
    assign(test_msg_.obs[12].P, 1069903034);
    assign(test_msg_.obs[12].cn0, 200);
    assign(test_msg_.obs[12].flags, 15);
    assign(test_msg_.obs[12].lock, 10);
    assign(test_msg_.obs[12].sid.code, 3);
    assign(test_msg_.obs[12].sid.sat, 17);

    assign(test_msg_.obs[13].D.f, 182);
    assign(test_msg_.obs[13].D.i, -461);
    assign(test_msg_.obs[13].L.f, 105);
    assign(test_msg_.obs[13].L.i, 102157331);
    assign(test_msg_.obs[13].P, 956875687);
    assign(test_msg_.obs[13].cn0, 152);
    assign(test_msg_.obs[13].flags, 15);
    assign(test_msg_.obs[13].lock, 10);
    assign(test_msg_.obs[13].sid.code, 3);
    assign(test_msg_.obs[13].sid.sat, 18);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_t> {
    using sbp::MessageHandler<sbp_msg_obs_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObs, &CHandler::callback_static, this,
                            &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObs);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs, sizeof(msg->obs));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObs);
    info.sender_id = 61569;
    info.preamble = 0x55;
    info.crc = 0xf8ed;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 249;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_t &lesser,
                        const sbp_msg_obs_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObs, &wrapped_lesser, &wrapped_lesser), 0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgObs, &wrapped_greater, &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObs, &wrapped_lesser, &wrapped_greater), 0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObs, &wrapped_greater, &wrapped_lesser), 0);

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
  sbp_msg_obs_t test_msg_{};
  uint8_t encoded_frame_[249 + 8] = {
      85,  74,  0,   129, 240, 249, 152, 202, 226, 25,  0,   0,   0,   0,   106,
      8,   32,  49,  227, 254, 62,  121, 242, 158, 6,   146, 0,   250, 172, 182,
      10,  15,  10,  0,   30,  228, 254, 62,  12,  189, 40,  5,   59,  83,  251,
      172, 178, 10,  15,  10,  1,   215, 205, 144, 72,  106, 111, 160, 7,   243,
      109, 243, 119, 158, 10,  15,  18,  0,   25,  207, 144, 72,  223, 96,  241,
      5,   12,  52,  246, 27,  125, 9,   11,  18,  1,   34,  184, 223, 74,  150,
      138, 222, 7,   53,  13,  11,  245, 114, 9,   15,  22,  0,   113, 80,  6,
      69,  162, 41,  65,  7,   70,  127, 246, 246, 189, 9,   15,  23,  0,   247,
      80,  6,   69,  213, 35,  167, 5,   221, 152, 248, 231, 158, 9,   11,  23,
      1,   8,   146, 166, 64,  12,  122, 203, 6,   114, 51,  248, 67,  93,  3,
      11,  27,  0,   221, 172, 173, 75,  217, 47,  244, 7,   232, 225, 11,  237,
      123, 5,   15,  31,  0,   250, 174, 173, 75,  216, 163, 50,  6,   40,  70,
      9,   62,  120, 3,   11,  31,  1,   135, 16,  6,   66,  99,  218, 11,  7,
      7,   138, 242, 96,  176, 10,  15,  2,   3,   148, 130, 6,   58,  217, 88,
      54,  6,   203, 21,  252, 96,  170, 10,  15,  3,   3,   186, 108, 197, 63,
      127, 54,  211, 6,   80,  4,   241, 219, 200, 10,  15,  17,  3,   167, 195,
      8,   57,  19,  204, 22,  6,   105, 51,  254, 182, 152, 10,  15,  18,  3,
      237, 248,
  };
  uint8_t encoded_payload_[249] = {
      152, 202, 226, 25,  0,   0,   0,   0,   106, 8,   32,  49,  227, 254, 62,
      121, 242, 158, 6,   146, 0,   250, 172, 182, 10,  15,  10,  0,   30,  228,
      254, 62,  12,  189, 40,  5,   59,  83,  251, 172, 178, 10,  15,  10,  1,
      215, 205, 144, 72,  106, 111, 160, 7,   243, 109, 243, 119, 158, 10,  15,
      18,  0,   25,  207, 144, 72,  223, 96,  241, 5,   12,  52,  246, 27,  125,
      9,   11,  18,  1,   34,  184, 223, 74,  150, 138, 222, 7,   53,  13,  11,
      245, 114, 9,   15,  22,  0,   113, 80,  6,   69,  162, 41,  65,  7,   70,
      127, 246, 246, 189, 9,   15,  23,  0,   247, 80,  6,   69,  213, 35,  167,
      5,   221, 152, 248, 231, 158, 9,   11,  23,  1,   8,   146, 166, 64,  12,
      122, 203, 6,   114, 51,  248, 67,  93,  3,   11,  27,  0,   221, 172, 173,
      75,  217, 47,  244, 7,   232, 225, 11,  237, 123, 5,   15,  31,  0,   250,
      174, 173, 75,  216, 163, 50,  6,   40,  70,  9,   62,  120, 3,   11,  31,
      1,   135, 16,  6,   66,  99,  218, 11,  7,   7,   138, 242, 96,  176, 10,
      15,  2,   3,   148, 130, 6,   58,  217, 88,  54,  6,   203, 21,  252, 96,
      170, 10,  15,  3,   3,   186, 108, 197, 63,  127, 54,  211, 6,   80,  4,
      241, 219, 200, 10,  15,  17,  3,   167, 195, 8,   57,  19,  204, 22,  6,
      105, 51,  254, 182, 152, 10,  15,  18,  3,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgObs0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObs, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[249];
  uint8_t n_written;

  EXPECT_EQ(
      sbp_msg_obs_encode(&buf[0], sizeof(buf), &n_written, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(n_written, 249);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 249), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObs,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 249);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 249), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[249];

  EXPECT_EQ(sbp_msg_obs_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 249), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgObs0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[249];

  for (uint8_t i = 0; i < 249; i++) {
    EXPECT_EQ(sbp_msg_obs_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 249);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObs, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 249);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_t msg{};

  EXPECT_EQ(sbp_msg_obs_decode(&info.encoded_payload[0], info.payload_len,
                               nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgObs0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_obs_t t{};
      return sbp_msg_obs_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_obs_t t{};
      t.n_obs = 1;
      return sbp_msg_obs_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_obs_decode(&info.encoded_payload[0], i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgObs0,
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

TEST_F(Testauto_check_sbp_observation_MsgObs0, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgObs0, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgObs0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_send(&state, info.sender_id, &info.test_msg,
                             &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObs, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObs, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObs, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.ns_residual,
                        greater.header.t.ns_residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.n_obs, greater.n_obs);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].D.f, greater.obs[0].D.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].D.i, greater.obs[0].D.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.f, greater.obs[0].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].L.i, greater.obs[0].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].P, greater.obs[0].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].cn0, greater.obs[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].flags, greater.obs[0].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].lock, greater.obs[0].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.code, greater.obs[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[0].sid.sat, greater.obs[0].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].D.f, greater.obs[1].D.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].D.i, greater.obs[1].D.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.f, greater.obs[1].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].L.i, greater.obs[1].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].P, greater.obs[1].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].cn0, greater.obs[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].flags, greater.obs[1].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].lock, greater.obs[1].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.code, greater.obs[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[1].sid.sat, greater.obs[1].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].D.f, greater.obs[2].D.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].D.i, greater.obs[2].D.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.f, greater.obs[2].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].L.i, greater.obs[2].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].P, greater.obs[2].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].cn0, greater.obs[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].flags, greater.obs[2].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].lock, greater.obs[2].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.code, greater.obs[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[2].sid.sat, greater.obs[2].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].D.f, greater.obs[3].D.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].D.i, greater.obs[3].D.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.f, greater.obs[3].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].L.i, greater.obs[3].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].P, greater.obs[3].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].cn0, greater.obs[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].flags, greater.obs[3].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].lock, greater.obs[3].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.code, greater.obs[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[3].sid.sat, greater.obs[3].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].D.f, greater.obs[4].D.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].D.i, greater.obs[4].D.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.f, greater.obs[4].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].L.i, greater.obs[4].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].P, greater.obs[4].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].cn0, greater.obs[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].flags, greater.obs[4].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].lock, greater.obs[4].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.code, greater.obs[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[4].sid.sat, greater.obs[4].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].D.f, greater.obs[5].D.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].D.i, greater.obs[5].D.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].L.f, greater.obs[5].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].L.i, greater.obs[5].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].P, greater.obs[5].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].cn0, greater.obs[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].flags, greater.obs[5].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].lock, greater.obs[5].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].sid.code, greater.obs[5].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[5].sid.sat, greater.obs[5].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].D.f, greater.obs[6].D.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].D.i, greater.obs[6].D.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].L.f, greater.obs[6].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].L.i, greater.obs[6].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].P, greater.obs[6].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].cn0, greater.obs[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].flags, greater.obs[6].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].lock, greater.obs[6].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].sid.code, greater.obs[6].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[6].sid.sat, greater.obs[6].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].D.f, greater.obs[7].D.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].D.i, greater.obs[7].D.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].L.f, greater.obs[7].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].L.i, greater.obs[7].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].P, greater.obs[7].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].cn0, greater.obs[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].flags, greater.obs[7].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].lock, greater.obs[7].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].sid.code, greater.obs[7].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[7].sid.sat, greater.obs[7].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].D.f, greater.obs[8].D.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].D.i, greater.obs[8].D.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].L.f, greater.obs[8].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].L.i, greater.obs[8].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].P, greater.obs[8].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].cn0, greater.obs[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].flags, greater.obs[8].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].lock, greater.obs[8].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].sid.code, greater.obs[8].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[8].sid.sat, greater.obs[8].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].D.f, greater.obs[9].D.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].D.i, greater.obs[9].D.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].L.f, greater.obs[9].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].L.i, greater.obs[9].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].P, greater.obs[9].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].cn0, greater.obs[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].flags, greater.obs[9].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].lock, greater.obs[9].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].sid.code, greater.obs[9].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[9].sid.sat, greater.obs[9].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].D.f, greater.obs[10].D.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].D.i, greater.obs[10].D.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].L.f, greater.obs[10].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].L.i, greater.obs[10].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].P, greater.obs[10].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].cn0, greater.obs[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].flags, greater.obs[10].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].lock, greater.obs[10].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].sid.code, greater.obs[10].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[10].sid.sat, greater.obs[10].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].D.f, greater.obs[11].D.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].D.i, greater.obs[11].D.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].L.f, greater.obs[11].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].L.i, greater.obs[11].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].P, greater.obs[11].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].cn0, greater.obs[11].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].flags, greater.obs[11].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].lock, greater.obs[11].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].sid.code, greater.obs[11].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[11].sid.sat, greater.obs[11].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[12].D.f, greater.obs[12].D.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[12].D.i, greater.obs[12].D.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[12].L.f, greater.obs[12].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[12].L.i, greater.obs[12].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[12].P, greater.obs[12].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[12].cn0, greater.obs[12].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[12].flags, greater.obs[12].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[12].lock, greater.obs[12].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[12].sid.code, greater.obs[12].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[12].sid.sat, greater.obs[12].sid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[13].D.f, greater.obs[13].D.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[13].D.i, greater.obs[13].D.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[13].L.f, greater.obs[13].L.f);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[13].L.i, greater.obs[13].L.i);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[13].P, greater.obs[13].P);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[13].cn0, greater.obs[13].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[13].flags, greater.obs[13].flags);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[13].lock, greater.obs[13].lock);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[13].sid.code, greater.obs[13].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.obs[13].sid.sat, greater.obs[13].sid.sat);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_t>::id, SbpMsgObs);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_t>::name, "MSG_OBS");
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_t>::get(const_sbp_msg_t);
  sbp_msg_obs_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 = sbp::MessageTraits<sbp_msg_obs_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[249];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 249);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 249), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 249);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_observation_MsgObs0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObs, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObs0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObs0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObs, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_observation_MsgObs1 : public ::testing::Test {
 public:
  Testauto_check_sbp_observation_MsgObs1() {
    assign(test_msg_.header.n_obs, 16);
    assign(test_msg_.header.t.ns_residual, 0);
    assign(test_msg_.header.t.tow, 434293400);
    assign(test_msg_.header.t.wn, 2154);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_obs_t> {
    using sbp::MessageHandler<sbp_msg_obs_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgObs, &CHandler::callback_static, this,
                            &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_obs_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgObs);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->obs, sizeof(msg->obs));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_obs_t test_msg;
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
    memcpy(&info.test_msg_wrapped.obs, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgObs);
    info.sender_id = 61569;
    info.preamble = 0x55;
    info.crc = 0x65c9;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 11;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_obs_t &lesser,
                        const sbp_msg_obs_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_obs_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_obs_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_obs_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_obs_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_obs_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_obs_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgObs, &wrapped_lesser, &wrapped_lesser), 0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgObs, &wrapped_greater, &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgObs, &wrapped_lesser, &wrapped_greater), 0);
    EXPECT_GT(sbp_message_cmp(SbpMsgObs, &wrapped_greater, &wrapped_lesser), 0);

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
  sbp_msg_obs_t test_msg_{};
  uint8_t encoded_frame_[11 + 8] = {
      85, 74, 0, 129, 240, 11, 152, 202, 226, 25,
      0,  0,  0, 0,   106, 8,  16,  201, 101,
  };
  uint8_t encoded_payload_[11] = {
      152, 202, 226, 25, 0, 0, 0, 0, 106, 8, 16,
  };
};

TEST_F(Testauto_check_sbp_observation_MsgObs1, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_obs_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgObs, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[11];
  uint8_t n_written;

  EXPECT_EQ(
      sbp_msg_obs_encode(&buf[0], sizeof(buf), &n_written, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(n_written, 11);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 11), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgObs,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 11);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 11), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[11];

  EXPECT_EQ(sbp_msg_obs_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 11), 0);
}
TEST_F(Testauto_check_sbp_observation_MsgObs1, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[11];

  for (uint8_t i = 0; i < 11; i++) {
    EXPECT_EQ(sbp_msg_obs_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_obs_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 11);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgObs, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 11);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_obs_t msg{};

  EXPECT_EQ(sbp_msg_obs_decode(&info.encoded_payload[0], info.payload_len,
                               nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_observation_MsgObs1, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_obs_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;

    EXPECT_EQ(sbp_msg_obs_decode(&info.encoded_payload[0], i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_observation_MsgObs1,
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

TEST_F(Testauto_check_sbp_observation_MsgObs1, SlowRead) {
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

TEST_F(Testauto_check_sbp_observation_MsgObs1, BadCRC) {
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

TEST_F(Testauto_check_sbp_observation_MsgObs1, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_obs_send(&state, info.sender_id, &info.test_msg,
                             &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObs, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgObs, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgObs, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.header.n_obs, greater.header.n_obs);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.ns_residual,
                        greater.header.t.ns_residual);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.tow, greater.header.t.tow);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_obs_t lesser = info.test_msg;
    sbp_msg_obs_t greater = info.test_msg;
    make_lesser_greater(lesser.header.t.wn, greater.header.t.wn);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_t>::id, SbpMsgObs);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_obs_t>::name, "MSG_OBS");
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_obs_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_t>::get(const_sbp_msg_t);
  sbp_msg_obs_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_obs_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 = sbp::MessageTraits<sbp_msg_obs_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.obs, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_obs_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.obs, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[11];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 11);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 11), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_obs_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_obs_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 11);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_observation_MsgObs1,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgObs, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_observation_MsgObs1, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_observation_MsgObs1,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgObs, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace
