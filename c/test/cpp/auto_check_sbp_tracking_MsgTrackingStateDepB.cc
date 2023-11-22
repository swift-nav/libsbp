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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDepB.yaml by
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
class Testauto_check_sbp_tracking_MsgTrackingStateDepB0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgTrackingStateDepB0() {
    assign(test_msg_.n_states, 28);

    assign(test_msg_.states[0].cn0, 5856.2001953125);
    assign(test_msg_.states[0].sid.code, 63);
    assign(test_msg_.states[0].sid.reserved, 68);
    assign(test_msg_.states[0].sid.sat, 58295);
    assign(test_msg_.states[0].state, 115);

    assign(test_msg_.states[1].cn0, 2612.199951171875);
    assign(test_msg_.states[1].sid.code, 43);
    assign(test_msg_.states[1].sid.reserved, 222);
    assign(test_msg_.states[1].sid.sat, 31151);
    assign(test_msg_.states[1].state, 255);

    assign(test_msg_.states[2].cn0, 2925.199951171875);
    assign(test_msg_.states[2].sid.code, 53);
    assign(test_msg_.states[2].sid.reserved, 20);
    assign(test_msg_.states[2].sid.sat, 1520);
    assign(test_msg_.states[2].state, 78);

    assign(test_msg_.states[3].cn0, 3198.199951171875);
    assign(test_msg_.states[3].sid.code, 66);
    assign(test_msg_.states[3].sid.reserved, 155);
    assign(test_msg_.states[3].sid.sat, 60802);
    assign(test_msg_.states[3].state, 153);

    assign(test_msg_.states[4].cn0, 8623.2001953125);
    assign(test_msg_.states[4].sid.code, 161);
    assign(test_msg_.states[4].sid.reserved, 190);
    assign(test_msg_.states[4].sid.sat, 35058);
    assign(test_msg_.states[4].state, 53);

    assign(test_msg_.states[5].cn0, 5915.2001953125);
    assign(test_msg_.states[5].sid.code, 142);
    assign(test_msg_.states[5].sid.reserved, 149);
    assign(test_msg_.states[5].sid.sat, 65405);
    assign(test_msg_.states[5].state, 153);

    assign(test_msg_.states[6].cn0, 5412.2001953125);
    assign(test_msg_.states[6].sid.code, 31);
    assign(test_msg_.states[6].sid.reserved, 76);
    assign(test_msg_.states[6].sid.sat, 24422);
    assign(test_msg_.states[6].state, 248);

    assign(test_msg_.states[7].cn0, 6428.2001953125);
    assign(test_msg_.states[7].sid.code, 27);
    assign(test_msg_.states[7].sid.reserved, 12);
    assign(test_msg_.states[7].sid.sat, 36211);
    assign(test_msg_.states[7].state, 131);

    assign(test_msg_.states[8].cn0, 3104.199951171875);
    assign(test_msg_.states[8].sid.code, 39);
    assign(test_msg_.states[8].sid.reserved, 23);
    assign(test_msg_.states[8].sid.sat, 37676);
    assign(test_msg_.states[8].state, 208);

    assign(test_msg_.states[9].cn0, 3686.199951171875);
    assign(test_msg_.states[9].sid.code, 49);
    assign(test_msg_.states[9].sid.reserved, 203);
    assign(test_msg_.states[9].sid.sat, 64415);
    assign(test_msg_.states[9].state, 237);

    assign(test_msg_.states[10].cn0, 5967.2001953125);
    assign(test_msg_.states[10].sid.code, 128);
    assign(test_msg_.states[10].sid.reserved, 206);
    assign(test_msg_.states[10].sid.sat, 22486);
    assign(test_msg_.states[10].state, 70);

    assign(test_msg_.states[11].cn0, 5423.2001953125);
    assign(test_msg_.states[11].sid.code, 218);
    assign(test_msg_.states[11].sid.reserved, 19);
    assign(test_msg_.states[11].sid.sat, 28622);
    assign(test_msg_.states[11].state, 14);

    assign(test_msg_.states[12].cn0, 438.20001220703125);
    assign(test_msg_.states[12].sid.code, 54);
    assign(test_msg_.states[12].sid.reserved, 2);
    assign(test_msg_.states[12].sid.sat, 53602);
    assign(test_msg_.states[12].state, 216);

    assign(test_msg_.states[13].cn0, 1862.199951171875);
    assign(test_msg_.states[13].sid.code, 7);
    assign(test_msg_.states[13].sid.reserved, 34);
    assign(test_msg_.states[13].sid.sat, 25477);
    assign(test_msg_.states[13].state, 200);

    assign(test_msg_.states[14].cn0, 5462.2001953125);
    assign(test_msg_.states[14].sid.code, 135);
    assign(test_msg_.states[14].sid.reserved, 46);
    assign(test_msg_.states[14].sid.sat, 21803);
    assign(test_msg_.states[14].state, 155);

    assign(test_msg_.states[15].cn0, 7454.2001953125);
    assign(test_msg_.states[15].sid.code, 171);
    assign(test_msg_.states[15].sid.reserved, 201);
    assign(test_msg_.states[15].sid.sat, 21251);
    assign(test_msg_.states[15].state, 155);

    assign(test_msg_.states[16].cn0, 7134.2001953125);
    assign(test_msg_.states[16].sid.code, 16);
    assign(test_msg_.states[16].sid.reserved, 19);
    assign(test_msg_.states[16].sid.sat, 50475);
    assign(test_msg_.states[16].state, 121);

    assign(test_msg_.states[17].cn0, 3111.199951171875);
    assign(test_msg_.states[17].sid.code, 63);
    assign(test_msg_.states[17].sid.reserved, 176);
    assign(test_msg_.states[17].sid.sat, 13813);
    assign(test_msg_.states[17].state, 128);

    assign(test_msg_.states[18].cn0, 4297.2001953125);
    assign(test_msg_.states[18].sid.code, 153);
    assign(test_msg_.states[18].sid.reserved, 51);
    assign(test_msg_.states[18].sid.sat, 15636);
    assign(test_msg_.states[18].state, 36);

    assign(test_msg_.states[19].cn0, 2649.199951171875);
    assign(test_msg_.states[19].sid.code, 140);
    assign(test_msg_.states[19].sid.reserved, 22);
    assign(test_msg_.states[19].sid.sat, 29778);
    assign(test_msg_.states[19].state, 46);

    assign(test_msg_.states[20].cn0, 941.2000122070312);
    assign(test_msg_.states[20].sid.code, 96);
    assign(test_msg_.states[20].sid.reserved, 143);
    assign(test_msg_.states[20].sid.sat, 37443);
    assign(test_msg_.states[20].state, 177);

    assign(test_msg_.states[21].cn0, 1539.199951171875);
    assign(test_msg_.states[21].sid.code, 201);
    assign(test_msg_.states[21].sid.reserved, 251);
    assign(test_msg_.states[21].sid.sat, 41011);
    assign(test_msg_.states[21].state, 220);

    assign(test_msg_.states[22].cn0, 1443.199951171875);
    assign(test_msg_.states[22].sid.code, 161);
    assign(test_msg_.states[22].sid.reserved, 220);
    assign(test_msg_.states[22].sid.sat, 706);
    assign(test_msg_.states[22].state, 168);

    assign(test_msg_.states[23].cn0, 1074.199951171875);
    assign(test_msg_.states[23].sid.code, 125);
    assign(test_msg_.states[23].sid.reserved, 178);
    assign(test_msg_.states[23].sid.sat, 2312);
    assign(test_msg_.states[23].state, 69);

    assign(test_msg_.states[24].cn0, 2122.199951171875);
    assign(test_msg_.states[24].sid.code, 186);
    assign(test_msg_.states[24].sid.reserved, 171);
    assign(test_msg_.states[24].sid.sat, 34580);
    assign(test_msg_.states[24].state, 185);

    assign(test_msg_.states[25].cn0, 9076.2001953125);
    assign(test_msg_.states[25].sid.code, 85);
    assign(test_msg_.states[25].sid.reserved, 170);
    assign(test_msg_.states[25].sid.sat, 39804);
    assign(test_msg_.states[25].state, 18);

    assign(test_msg_.states[26].cn0, 4781.2001953125);
    assign(test_msg_.states[26].sid.code, 255);
    assign(test_msg_.states[26].sid.reserved, 186);
    assign(test_msg_.states[26].sid.sat, 52980);
    assign(test_msg_.states[26].state, 57);

    assign(test_msg_.states[27].cn0, 3076.199951171875);
    assign(test_msg_.states[27].sid.code, 181);
    assign(test_msg_.states[27].sid.reserved, 175);
    assign(test_msg_.states[27].sid.sat, 24007);
    assign(test_msg_.states[27].state, 165);
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
      : public sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t> {
    using sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_tracking_state_dep_b_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgTrackingStateDepB,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_tracking_state_dep_b_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgTrackingStateDepB);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->tracking_state_dep_b,
             sizeof(msg->tracking_state_dep_b));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_tracking_state_dep_b_t test_msg;
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
    memcpy(&info.test_msg_wrapped.tracking_state_dep_b, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgTrackingStateDepB);
    info.sender_id = 61938;
    info.preamble = 0x55;
    info.crc = 0x1c06;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 252;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_tracking_state_dep_b_t &lesser,
                        const sbp_msg_tracking_state_dep_b_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_tracking_state_dep_b_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_tracking_state_dep_b_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_tracking_state_dep_b_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_tracking_state_dep_b_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgTrackingStateDepB, &wrapped_greater,
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
  sbp_msg_tracking_state_dep_b_t test_msg_{};
  uint8_t encoded_frame_[252 + 8] = {
      85,  19,  0,   242, 241, 252, 115, 183, 227, 63,  68,  154, 1,   183, 69,
      255, 175, 121, 43,  222, 51,  67,  35,  69,  78,  240, 5,   53,  20,  51,
      211, 54,  69,  153, 130, 237, 66,  155, 51,  227, 71,  69,  53,  242, 136,
      161, 190, 205, 188, 6,   70,  153, 125, 255, 142, 149, 154, 217, 184, 69,
      248, 102, 95,  31,  76,  154, 33,  169, 69,  131, 115, 141, 27,  12,  154,
      225, 200, 69,  208, 44,  147, 39,  23,  51,  3,   66,  69,  237, 159, 251,
      49,  203, 51,  99,  102, 69,  70,  214, 87,  128, 206, 154, 121, 186, 69,
      14,  206, 111, 218, 19,  154, 121, 169, 69,  216, 98,  209, 54,  2,   154,
      25,  219, 67,  200, 133, 99,  7,   34,  102, 198, 232, 68,  155, 43,  85,
      135, 46,  154, 177, 170, 69,  155, 3,   83,  171, 201, 154, 241, 232, 69,
      121, 43,  197, 16,  19,  154, 241, 222, 69,  128, 245, 53,  63,  176, 51,
      115, 66,  69,  36,  20,  61,  153, 51,  154, 73,  134, 69,  46,  82,  116,
      140, 22,  51,  147, 37,  69,  177, 67,  146, 96,  143, 205, 76,  107, 68,
      220, 51,  160, 201, 251, 102, 102, 192, 68,  168, 194, 2,   161, 220, 102,
      102, 180, 68,  69,  8,   9,   125, 178, 102, 70,  134, 68,  185, 20,  135,
      186, 171, 51,  163, 4,   69,  18,  124, 155, 85,  170, 205, 208, 13,  70,
      57,  244, 206, 255, 186, 154, 105, 149, 69,  165, 199, 93,  181, 175, 51,
      67,  64,  69,  6,   28,
  };
  uint8_t encoded_payload_[252] = {
      115, 183, 227, 63,  68,  154, 1,   183, 69,  255, 175, 121, 43,  222, 51,
      67,  35,  69,  78,  240, 5,   53,  20,  51,  211, 54,  69,  153, 130, 237,
      66,  155, 51,  227, 71,  69,  53,  242, 136, 161, 190, 205, 188, 6,   70,
      153, 125, 255, 142, 149, 154, 217, 184, 69,  248, 102, 95,  31,  76,  154,
      33,  169, 69,  131, 115, 141, 27,  12,  154, 225, 200, 69,  208, 44,  147,
      39,  23,  51,  3,   66,  69,  237, 159, 251, 49,  203, 51,  99,  102, 69,
      70,  214, 87,  128, 206, 154, 121, 186, 69,  14,  206, 111, 218, 19,  154,
      121, 169, 69,  216, 98,  209, 54,  2,   154, 25,  219, 67,  200, 133, 99,
      7,   34,  102, 198, 232, 68,  155, 43,  85,  135, 46,  154, 177, 170, 69,
      155, 3,   83,  171, 201, 154, 241, 232, 69,  121, 43,  197, 16,  19,  154,
      241, 222, 69,  128, 245, 53,  63,  176, 51,  115, 66,  69,  36,  20,  61,
      153, 51,  154, 73,  134, 69,  46,  82,  116, 140, 22,  51,  147, 37,  69,
      177, 67,  146, 96,  143, 205, 76,  107, 68,  220, 51,  160, 201, 251, 102,
      102, 192, 68,  168, 194, 2,   161, 220, 102, 102, 180, 68,  69,  8,   9,
      125, 178, 102, 70,  134, 68,  185, 20,  135, 186, 171, 51,  163, 4,   69,
      18,  124, 155, 85,  170, 205, 208, 13,  70,  57,  244, 206, 255, 186, 154,
      105, 149, 69,  165, 199, 93,  181, 175, 51,  67,  64,  69,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgTrackingStateDepB, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[252];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], sizeof(buf),
                                                &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 252);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgTrackingStateDepB, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 252);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[252];

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], sizeof(buf), nullptr,
                                                &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[252];

  for (uint8_t i = 0; i < 252; i++) {
    EXPECT_EQ(sbp_msg_tracking_state_dep_b_encode(&buf[0], i, nullptr,
                                                  &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 252);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgTrackingStateDepB, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 252);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_tracking_state_dep_b_t t{};
      return sbp_msg_tracking_state_dep_b_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_tracking_state_dep_b_t t{};
      t.n_states = 1;
      return sbp_msg_tracking_state_dep_b_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_tracking_state_dep_b_decode(&info.encoded_payload[0], i,
                                                  nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_tracking_state_dep_b_send(&state, info.sender_id,
                                              &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgTrackingStateDepB, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.n_states, greater.n_states);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].cn0, greater.states[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.code, greater.states[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.reserved,
                        greater.states[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].sid.sat, greater.states[0].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].state, greater.states[0].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].cn0, greater.states[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.code, greater.states[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.reserved,
                        greater.states[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].sid.sat, greater.states[1].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].state, greater.states[1].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].cn0, greater.states[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.code, greater.states[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.reserved,
                        greater.states[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].sid.sat, greater.states[2].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].state, greater.states[2].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].cn0, greater.states[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.code, greater.states[3].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.reserved,
                        greater.states[3].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].sid.sat, greater.states[3].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].state, greater.states[3].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].cn0, greater.states[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.code, greater.states[4].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.reserved,
                        greater.states[4].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].sid.sat, greater.states[4].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].state, greater.states[4].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].cn0, greater.states[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.code, greater.states[5].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.reserved,
                        greater.states[5].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].sid.sat, greater.states[5].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].state, greater.states[5].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].cn0, greater.states[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.code, greater.states[6].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.reserved,
                        greater.states[6].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].sid.sat, greater.states[6].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].state, greater.states[6].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].cn0, greater.states[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.code, greater.states[7].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.reserved,
                        greater.states[7].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].sid.sat, greater.states[7].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].state, greater.states[7].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].cn0, greater.states[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.code, greater.states[8].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.reserved,
                        greater.states[8].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].sid.sat, greater.states[8].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].state, greater.states[8].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].cn0, greater.states[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.code, greater.states[9].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.reserved,
                        greater.states[9].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].sid.sat, greater.states[9].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].state, greater.states[9].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].cn0, greater.states[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.code,
                        greater.states[10].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.reserved,
                        greater.states[10].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].sid.sat, greater.states[10].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].state, greater.states[10].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[11].cn0, greater.states[11].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[11].sid.code,
                        greater.states[11].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[11].sid.reserved,
                        greater.states[11].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[11].sid.sat, greater.states[11].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[11].state, greater.states[11].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[12].cn0, greater.states[12].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[12].sid.code,
                        greater.states[12].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[12].sid.reserved,
                        greater.states[12].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[12].sid.sat, greater.states[12].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[12].state, greater.states[12].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[13].cn0, greater.states[13].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[13].sid.code,
                        greater.states[13].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[13].sid.reserved,
                        greater.states[13].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[13].sid.sat, greater.states[13].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[13].state, greater.states[13].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[14].cn0, greater.states[14].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[14].sid.code,
                        greater.states[14].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[14].sid.reserved,
                        greater.states[14].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[14].sid.sat, greater.states[14].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[14].state, greater.states[14].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[15].cn0, greater.states[15].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[15].sid.code,
                        greater.states[15].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[15].sid.reserved,
                        greater.states[15].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[15].sid.sat, greater.states[15].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[15].state, greater.states[15].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[16].cn0, greater.states[16].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[16].sid.code,
                        greater.states[16].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[16].sid.reserved,
                        greater.states[16].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[16].sid.sat, greater.states[16].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[16].state, greater.states[16].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[17].cn0, greater.states[17].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[17].sid.code,
                        greater.states[17].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[17].sid.reserved,
                        greater.states[17].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[17].sid.sat, greater.states[17].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[17].state, greater.states[17].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[18].cn0, greater.states[18].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[18].sid.code,
                        greater.states[18].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[18].sid.reserved,
                        greater.states[18].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[18].sid.sat, greater.states[18].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[18].state, greater.states[18].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[19].cn0, greater.states[19].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[19].sid.code,
                        greater.states[19].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[19].sid.reserved,
                        greater.states[19].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[19].sid.sat, greater.states[19].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[19].state, greater.states[19].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[20].cn0, greater.states[20].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[20].sid.code,
                        greater.states[20].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[20].sid.reserved,
                        greater.states[20].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[20].sid.sat, greater.states[20].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[20].state, greater.states[20].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[21].cn0, greater.states[21].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[21].sid.code,
                        greater.states[21].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[21].sid.reserved,
                        greater.states[21].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[21].sid.sat, greater.states[21].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[21].state, greater.states[21].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[22].cn0, greater.states[22].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[22].sid.code,
                        greater.states[22].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[22].sid.reserved,
                        greater.states[22].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[22].sid.sat, greater.states[22].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[22].state, greater.states[22].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[23].cn0, greater.states[23].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[23].sid.code,
                        greater.states[23].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[23].sid.reserved,
                        greater.states[23].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[23].sid.sat, greater.states[23].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[23].state, greater.states[23].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[24].cn0, greater.states[24].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[24].sid.code,
                        greater.states[24].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[24].sid.reserved,
                        greater.states[24].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[24].sid.sat, greater.states[24].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[24].state, greater.states[24].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[25].cn0, greater.states[25].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[25].sid.code,
                        greater.states[25].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[25].sid.reserved,
                        greater.states[25].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[25].sid.sat, greater.states[25].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[25].state, greater.states[25].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[26].cn0, greater.states[26].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[26].sid.code,
                        greater.states[26].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[26].sid.reserved,
                        greater.states[26].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[26].sid.sat, greater.states[26].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[26].state, greater.states[26].state);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[27].cn0, greater.states[27].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[27].sid.code,
                        greater.states[27].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[27].sid.reserved,
                        greater.states[27].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[27].sid.sat, greater.states[27].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_tracking_state_dep_b_t lesser = info.test_msg;
    sbp_msg_tracking_state_dep_b_t greater = info.test_msg;
    make_lesser_greater(lesser.states[27].state, greater.states[27].state);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::id,
  // SbpMsgTrackingStateDepB);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::name,
               "MSG_TRACKING_STATE_DEP_B");
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_tracking_state_dep_b_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::get(const_sbp_msg_t);
  sbp_msg_tracking_state_dep_b_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.tracking_state_dep_b, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::to_sbp_msg(info.test_msg,
                                                                 &msg2);
  EXPECT_EQ(msg2.tracking_state_dep_b, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[252];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 252);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 252), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_tracking_state_dep_b_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_tracking_state_dep_b_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 252);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
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

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgTrackingStateDepB,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgTrackingStateDepB0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgTrackingStateDepB,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace