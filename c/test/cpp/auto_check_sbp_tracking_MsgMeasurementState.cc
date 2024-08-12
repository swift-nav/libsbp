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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgMeasurementState.yaml by
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
class Testauto_check_sbp_tracking_MsgMeasurementState0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_tracking_MsgMeasurementState0() {
    assign(test_msg_.n_states, 79);

    assign(test_msg_.states[0].cn0, 162);
    assign(test_msg_.states[0].mesid.code, 0);
    assign(test_msg_.states[0].mesid.sat, 29);

    assign(test_msg_.states[1].cn0, 0);
    assign(test_msg_.states[1].mesid.code, 0);
    assign(test_msg_.states[1].mesid.sat, 0);

    assign(test_msg_.states[2].cn0, 0);
    assign(test_msg_.states[2].mesid.code, 0);
    assign(test_msg_.states[2].mesid.sat, 0);

    assign(test_msg_.states[3].cn0, 201);
    assign(test_msg_.states[3].mesid.code, 0);
    assign(test_msg_.states[3].mesid.sat, 27);

    assign(test_msg_.states[4].cn0, 168);
    assign(test_msg_.states[4].mesid.code, 0);
    assign(test_msg_.states[4].mesid.sat, 20);

    assign(test_msg_.states[5].cn0, 184);
    assign(test_msg_.states[5].mesid.code, 0);
    assign(test_msg_.states[5].mesid.sat, 32);

    assign(test_msg_.states[6].cn0, 187);
    assign(test_msg_.states[6].mesid.code, 0);
    assign(test_msg_.states[6].mesid.sat, 15);

    assign(test_msg_.states[7].cn0, 0);
    assign(test_msg_.states[7].mesid.code, 0);
    assign(test_msg_.states[7].mesid.sat, 0);

    assign(test_msg_.states[8].cn0, 210);
    assign(test_msg_.states[8].mesid.code, 0);
    assign(test_msg_.states[8].mesid.sat, 18);

    assign(test_msg_.states[9].cn0, 167);
    assign(test_msg_.states[9].mesid.code, 0);
    assign(test_msg_.states[9].mesid.sat, 16);

    assign(test_msg_.states[10].cn0, 0);
    assign(test_msg_.states[10].mesid.code, 0);
    assign(test_msg_.states[10].mesid.sat, 0);

    assign(test_msg_.states[11].cn0, 213);
    assign(test_msg_.states[11].mesid.code, 0);
    assign(test_msg_.states[11].mesid.sat, 23);

    assign(test_msg_.states[12].cn0, 223);
    assign(test_msg_.states[12].mesid.code, 0);
    assign(test_msg_.states[12].mesid.sat, 10);

    assign(test_msg_.states[13].cn0, 0);
    assign(test_msg_.states[13].mesid.code, 0);
    assign(test_msg_.states[13].mesid.sat, 0);

    assign(test_msg_.states[14].cn0, 0);
    assign(test_msg_.states[14].mesid.code, 0);
    assign(test_msg_.states[14].mesid.sat, 0);

    assign(test_msg_.states[15].cn0, 0);
    assign(test_msg_.states[15].mesid.code, 0);
    assign(test_msg_.states[15].mesid.sat, 0);

    assign(test_msg_.states[16].cn0, 0);
    assign(test_msg_.states[16].mesid.code, 0);
    assign(test_msg_.states[16].mesid.sat, 0);

    assign(test_msg_.states[17].cn0, 202);
    assign(test_msg_.states[17].mesid.code, 2);
    assign(test_msg_.states[17].mesid.sat, 131);

    assign(test_msg_.states[18].cn0, 192);
    assign(test_msg_.states[18].mesid.code, 1);
    assign(test_msg_.states[18].mesid.sat, 27);

    assign(test_msg_.states[19].cn0, 165);
    assign(test_msg_.states[19].mesid.code, 1);
    assign(test_msg_.states[19].mesid.sat, 15);

    assign(test_msg_.states[20].cn0, 146);
    assign(test_msg_.states[20].mesid.code, 1);
    assign(test_msg_.states[20].mesid.sat, 29);

    assign(test_msg_.states[21].cn0, 170);
    assign(test_msg_.states[21].mesid.code, 1);
    assign(test_msg_.states[21].mesid.sat, 32);

    assign(test_msg_.states[22].cn0, 201);
    assign(test_msg_.states[22].mesid.code, 1);
    assign(test_msg_.states[22].mesid.sat, 18);

    assign(test_msg_.states[23].cn0, 0);
    assign(test_msg_.states[23].mesid.code, 0);
    assign(test_msg_.states[23].mesid.sat, 0);

    assign(test_msg_.states[24].cn0, 0);
    assign(test_msg_.states[24].mesid.code, 0);
    assign(test_msg_.states[24].mesid.sat, 0);

    assign(test_msg_.states[25].cn0, 0);
    assign(test_msg_.states[25].mesid.code, 0);
    assign(test_msg_.states[25].mesid.sat, 0);

    assign(test_msg_.states[26].cn0, 212);
    assign(test_msg_.states[26].mesid.code, 1);
    assign(test_msg_.states[26].mesid.sat, 23);

    assign(test_msg_.states[27].cn0, 205);
    assign(test_msg_.states[27].mesid.code, 1);
    assign(test_msg_.states[27].mesid.sat, 10);

    assign(test_msg_.states[28].cn0, 0);
    assign(test_msg_.states[28].mesid.code, 0);
    assign(test_msg_.states[28].mesid.sat, 0);

    assign(test_msg_.states[29].cn0, 230);
    assign(test_msg_.states[29].mesid.code, 3);
    assign(test_msg_.states[29].mesid.sat, 96);

    assign(test_msg_.states[30].cn0, 0);
    assign(test_msg_.states[30].mesid.code, 0);
    assign(test_msg_.states[30].mesid.sat, 0);

    assign(test_msg_.states[31].cn0, 214);
    assign(test_msg_.states[31].mesid.code, 3);
    assign(test_msg_.states[31].mesid.sat, 101);

    assign(test_msg_.states[32].cn0, 212);
    assign(test_msg_.states[32].mesid.code, 3);
    assign(test_msg_.states[32].mesid.sat, 103);

    assign(test_msg_.states[33].cn0, 209);
    assign(test_msg_.states[33].mesid.code, 3);
    assign(test_msg_.states[33].mesid.sat, 104);

    assign(test_msg_.states[34].cn0, 157);
    assign(test_msg_.states[34].mesid.code, 3);
    assign(test_msg_.states[34].mesid.sat, 106);

    assign(test_msg_.states[35].cn0, 230);
    assign(test_msg_.states[35].mesid.code, 3);
    assign(test_msg_.states[35].mesid.sat, 102);

    assign(test_msg_.states[36].cn0, 0);
    assign(test_msg_.states[36].mesid.code, 0);
    assign(test_msg_.states[36].mesid.sat, 0);

    assign(test_msg_.states[37].cn0, 0);
    assign(test_msg_.states[37].mesid.code, 0);
    assign(test_msg_.states[37].mesid.sat, 0);

    assign(test_msg_.states[38].cn0, 189);
    assign(test_msg_.states[38].mesid.code, 4);
    assign(test_msg_.states[38].mesid.sat, 101);

    assign(test_msg_.states[39].cn0, 207);
    assign(test_msg_.states[39].mesid.code, 4);
    assign(test_msg_.states[39].mesid.sat, 96);

    assign(test_msg_.states[40].cn0, 164);
    assign(test_msg_.states[40].mesid.code, 4);
    assign(test_msg_.states[40].mesid.sat, 106);

    assign(test_msg_.states[41].cn0, 193);
    assign(test_msg_.states[41].mesid.code, 4);
    assign(test_msg_.states[41].mesid.sat, 104);

    assign(test_msg_.states[42].cn0, 0);
    assign(test_msg_.states[42].mesid.code, 0);
    assign(test_msg_.states[42].mesid.sat, 0);

    assign(test_msg_.states[43].cn0, 208);
    assign(test_msg_.states[43].mesid.code, 4);
    assign(test_msg_.states[43].mesid.sat, 102);

    assign(test_msg_.states[44].cn0, 0);
    assign(test_msg_.states[44].mesid.code, 0);
    assign(test_msg_.states[44].mesid.sat, 0);

    assign(test_msg_.states[45].cn0, 212);
    assign(test_msg_.states[45].mesid.code, 12);
    assign(test_msg_.states[45].mesid.sat, 27);

    assign(test_msg_.states[46].cn0, 161);
    assign(test_msg_.states[46].mesid.code, 12);
    assign(test_msg_.states[46].mesid.sat, 29);

    assign(test_msg_.states[47].cn0, 216);
    assign(test_msg_.states[47].mesid.code, 12);
    assign(test_msg_.states[47].mesid.sat, 32);

    assign(test_msg_.states[48].cn0, 216);
    assign(test_msg_.states[48].mesid.code, 12);
    assign(test_msg_.states[48].mesid.sat, 30);

    assign(test_msg_.states[49].cn0, 178);
    assign(test_msg_.states[49].mesid.code, 12);
    assign(test_msg_.states[49].mesid.sat, 20);

    assign(test_msg_.states[50].cn0, 0);
    assign(test_msg_.states[50].mesid.code, 0);
    assign(test_msg_.states[50].mesid.sat, 0);

    assign(test_msg_.states[51].cn0, 0);
    assign(test_msg_.states[51].mesid.code, 0);
    assign(test_msg_.states[51].mesid.sat, 0);

    assign(test_msg_.states[52].cn0, 0);
    assign(test_msg_.states[52].mesid.code, 0);
    assign(test_msg_.states[52].mesid.sat, 0);

    assign(test_msg_.states[53].cn0, 0);
    assign(test_msg_.states[53].mesid.code, 0);
    assign(test_msg_.states[53].mesid.sat, 0);

    assign(test_msg_.states[54].cn0, 0);
    assign(test_msg_.states[54].mesid.code, 0);
    assign(test_msg_.states[54].mesid.sat, 0);

    assign(test_msg_.states[55].cn0, 0);
    assign(test_msg_.states[55].mesid.code, 0);
    assign(test_msg_.states[55].mesid.sat, 0);

    assign(test_msg_.states[56].cn0, 0);
    assign(test_msg_.states[56].mesid.code, 0);
    assign(test_msg_.states[56].mesid.sat, 0);

    assign(test_msg_.states[57].cn0, 0);
    assign(test_msg_.states[57].mesid.code, 0);
    assign(test_msg_.states[57].mesid.sat, 0);

    assign(test_msg_.states[58].cn0, 0);
    assign(test_msg_.states[58].mesid.code, 0);
    assign(test_msg_.states[58].mesid.sat, 0);

    assign(test_msg_.states[59].cn0, 0);
    assign(test_msg_.states[59].mesid.code, 0);
    assign(test_msg_.states[59].mesid.sat, 0);

    assign(test_msg_.states[60].cn0, 0);
    assign(test_msg_.states[60].mesid.code, 0);
    assign(test_msg_.states[60].mesid.sat, 0);

    assign(test_msg_.states[61].cn0, 0);
    assign(test_msg_.states[61].mesid.code, 0);
    assign(test_msg_.states[61].mesid.sat, 0);

    assign(test_msg_.states[62].cn0, 0);
    assign(test_msg_.states[62].mesid.code, 0);
    assign(test_msg_.states[62].mesid.sat, 0);

    assign(test_msg_.states[63].cn0, 203);
    assign(test_msg_.states[63].mesid.code, 14);
    assign(test_msg_.states[63].mesid.sat, 36);

    assign(test_msg_.states[64].cn0, 0);
    assign(test_msg_.states[64].mesid.code, 0);
    assign(test_msg_.states[64].mesid.sat, 0);

    assign(test_msg_.states[65].cn0, 158);
    assign(test_msg_.states[65].mesid.code, 14);
    assign(test_msg_.states[65].mesid.sat, 5);

    assign(test_msg_.states[66].cn0, 194);
    assign(test_msg_.states[66].mesid.code, 14);
    assign(test_msg_.states[66].mesid.sat, 4);

    assign(test_msg_.states[67].cn0, 192);
    assign(test_msg_.states[67].mesid.code, 14);
    assign(test_msg_.states[67].mesid.sat, 11);

    assign(test_msg_.states[68].cn0, 207);
    assign(test_msg_.states[68].mesid.code, 14);
    assign(test_msg_.states[68].mesid.sat, 9);

    assign(test_msg_.states[69].cn0, 0);
    assign(test_msg_.states[69].mesid.code, 0);
    assign(test_msg_.states[69].mesid.sat, 0);

    assign(test_msg_.states[70].cn0, 0);
    assign(test_msg_.states[70].mesid.code, 0);
    assign(test_msg_.states[70].mesid.sat, 0);

    assign(test_msg_.states[71].cn0, 0);
    assign(test_msg_.states[71].mesid.code, 0);
    assign(test_msg_.states[71].mesid.sat, 0);

    assign(test_msg_.states[72].cn0, 218);
    assign(test_msg_.states[72].mesid.code, 20);
    assign(test_msg_.states[72].mesid.sat, 9);

    assign(test_msg_.states[73].cn0, 176);
    assign(test_msg_.states[73].mesid.code, 20);
    assign(test_msg_.states[73].mesid.sat, 5);

    assign(test_msg_.states[74].cn0, 217);
    assign(test_msg_.states[74].mesid.code, 20);
    assign(test_msg_.states[74].mesid.sat, 36);

    assign(test_msg_.states[75].cn0, 200);
    assign(test_msg_.states[75].mesid.code, 20);
    assign(test_msg_.states[75].mesid.sat, 11);

    assign(test_msg_.states[76].cn0, 205);
    assign(test_msg_.states[76].mesid.code, 20);
    assign(test_msg_.states[76].mesid.sat, 4);

    assign(test_msg_.states[77].cn0, 0);
    assign(test_msg_.states[77].mesid.code, 0);
    assign(test_msg_.states[77].mesid.sat, 0);

    assign(test_msg_.states[78].cn0, 0);
    assign(test_msg_.states[78].mesid.code, 0);
    assign(test_msg_.states[78].mesid.sat, 0);
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
      : public sbp::MessageHandler<sbp_msg_measurement_state_t> {
    using sbp::MessageHandler<sbp_msg_measurement_state_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_measurement_state_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_measurement_state_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgMeasurementState,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_measurement_state_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgMeasurementState);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->measurement_state,
             sizeof(msg->measurement_state));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_measurement_state_t test_msg;
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
    memcpy(&info.test_msg_wrapped.measurement_state, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgMeasurementState);
    info.sender_id = 31183;
    info.preamble = 0x55;
    info.crc = 0x3623;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 237;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_measurement_state_t &lesser,
                        const sbp_msg_measurement_state_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_measurement_state_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_measurement_state_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_measurement_state_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_measurement_state_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_measurement_state_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_measurement_state_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgMeasurementState, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgMeasurementState, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgMeasurementState, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgMeasurementState, &wrapped_greater,
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
  sbp_msg_measurement_state_t test_msg_{};
  uint8_t encoded_frame_[237 + 8] = {
      85,  97, 0,   207, 121, 237, 29,  0,  162, 0,   0,  0,   0,   0,  0,
      27,  0,  201, 20,  0,   168, 32,  0,  184, 15,  0,  187, 0,   0,  0,
      18,  0,  210, 16,  0,   167, 0,   0,  0,   23,  0,  213, 10,  0,  223,
      0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,  0,   131, 2,  202,
      27,  1,  192, 15,  1,   165, 29,  1,  146, 32,  1,  170, 18,  1,  201,
      0,   0,  0,   0,   0,   0,   0,   0,  0,   23,  1,  212, 10,  1,  205,
      0,   0,  0,   96,  3,   230, 0,   0,  0,   101, 3,  214, 103, 3,  212,
      104, 3,  209, 106, 3,   157, 102, 3,  230, 0,   0,  0,   0,   0,  0,
      101, 4,  189, 96,  4,   207, 106, 4,  164, 104, 4,  193, 0,   0,  0,
      102, 4,  208, 0,   0,   0,   27,  12, 212, 29,  12, 161, 32,  12, 216,
      30,  12, 216, 20,  12,  178, 0,   0,  0,   0,   0,  0,   0,   0,  0,
      0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,  0,   0,   0,  0,
      0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,  0,   0,   0,  0,
      36,  14, 203, 0,   0,   0,   5,   14, 158, 4,   14, 194, 11,  14, 192,
      9,   14, 207, 0,   0,   0,   0,   0,  0,   0,   0,  0,   9,   20, 218,
      5,   20, 176, 36,  20,  217, 11,  20, 200, 4,   20, 205, 0,   0,  0,
      0,   0,  0,   35,  54,
  };
  uint8_t encoded_payload_[237] = {
      29,  0,  162, 0,   0,  0,   0,   0,  0,   27,  0,  201, 20,  0,  168,
      32,  0,  184, 15,  0,  187, 0,   0,  0,   18,  0,  210, 16,  0,  167,
      0,   0,  0,   23,  0,  213, 10,  0,  223, 0,   0,  0,   0,   0,  0,
      0,   0,  0,   0,   0,  0,   131, 2,  202, 27,  1,  192, 15,  1,  165,
      29,  1,  146, 32,  1,  170, 18,  1,  201, 0,   0,  0,   0,   0,  0,
      0,   0,  0,   23,  1,  212, 10,  1,  205, 0,   0,  0,   96,  3,  230,
      0,   0,  0,   101, 3,  214, 103, 3,  212, 104, 3,  209, 106, 3,  157,
      102, 3,  230, 0,   0,  0,   0,   0,  0,   101, 4,  189, 96,  4,  207,
      106, 4,  164, 104, 4,  193, 0,   0,  0,   102, 4,  208, 0,   0,  0,
      27,  12, 212, 29,  12, 161, 32,  12, 216, 30,  12, 216, 20,  12, 178,
      0,   0,  0,   0,   0,  0,   0,   0,  0,   0,   0,  0,   0,   0,  0,
      0,   0,  0,   0,   0,  0,   0,   0,  0,   0,   0,  0,   0,   0,  0,
      0,   0,  0,   0,   0,  0,   0,   0,  0,   36,  14, 203, 0,   0,  0,
      5,   14, 158, 4,   14, 194, 11,  14, 192, 9,   14, 207, 0,   0,  0,
      0,   0,  0,   0,   0,  0,   9,   20, 218, 5,   20, 176, 36,  20, 217,
      11,  20, 200, 4,   20, 205, 0,   0,  0,   0,   0,  0,
  };
};

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_measurement_state_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgMeasurementState, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[237];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_measurement_state_encode(&buf[0], sizeof(buf), &n_written,
                                             &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 237);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 237), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgMeasurementState, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 237);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 237), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[237];

  EXPECT_EQ(sbp_msg_measurement_state_encode(&buf[0], sizeof(buf), nullptr,
                                             &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 237), 0);
}
TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[237];

  for (uint8_t i = 0; i < 237; i++) {
    EXPECT_EQ(
        sbp_msg_measurement_state_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_measurement_state_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_measurement_state_decode(&info.encoded_payload[0],
                                             info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 237);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgMeasurementState, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 237);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_measurement_state_t msg{};

  EXPECT_EQ(sbp_msg_measurement_state_decode(&info.encoded_payload[0],
                                             info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_measurement_state_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_measurement_state_t t{};
      return sbp_msg_measurement_state_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_measurement_state_t t{};
      t.n_states = 1;
      return sbp_msg_measurement_state_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_measurement_state_decode(&info.encoded_payload[0], i,
                                               nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0,
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

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0,
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

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0, SlowRead) {
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

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0, BadCRC) {
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

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_measurement_state_send(&state, info.sender_id,
                                           &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgMeasurementState, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgMeasurementState, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgMeasurementState, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.n_states, greater.n_states);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].cn0, greater.states[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].mesid.code,
                        greater.states[0].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[0].mesid.sat,
                        greater.states[0].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].cn0, greater.states[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].mesid.code,
                        greater.states[1].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[1].mesid.sat,
                        greater.states[1].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].cn0, greater.states[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].mesid.code,
                        greater.states[2].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[2].mesid.sat,
                        greater.states[2].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].cn0, greater.states[3].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].mesid.code,
                        greater.states[3].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[3].mesid.sat,
                        greater.states[3].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].cn0, greater.states[4].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].mesid.code,
                        greater.states[4].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[4].mesid.sat,
                        greater.states[4].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].cn0, greater.states[5].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].mesid.code,
                        greater.states[5].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[5].mesid.sat,
                        greater.states[5].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].cn0, greater.states[6].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].mesid.code,
                        greater.states[6].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[6].mesid.sat,
                        greater.states[6].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].cn0, greater.states[7].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].mesid.code,
                        greater.states[7].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[7].mesid.sat,
                        greater.states[7].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].cn0, greater.states[8].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].mesid.code,
                        greater.states[8].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[8].mesid.sat,
                        greater.states[8].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].cn0, greater.states[9].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].mesid.code,
                        greater.states[9].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[9].mesid.sat,
                        greater.states[9].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].cn0, greater.states[10].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].mesid.code,
                        greater.states[10].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[10].mesid.sat,
                        greater.states[10].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[11].cn0, greater.states[11].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[11].mesid.code,
                        greater.states[11].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[11].mesid.sat,
                        greater.states[11].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[12].cn0, greater.states[12].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[12].mesid.code,
                        greater.states[12].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[12].mesid.sat,
                        greater.states[12].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[13].cn0, greater.states[13].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[13].mesid.code,
                        greater.states[13].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[13].mesid.sat,
                        greater.states[13].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[14].cn0, greater.states[14].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[14].mesid.code,
                        greater.states[14].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[14].mesid.sat,
                        greater.states[14].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[15].cn0, greater.states[15].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[15].mesid.code,
                        greater.states[15].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[15].mesid.sat,
                        greater.states[15].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[16].cn0, greater.states[16].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[16].mesid.code,
                        greater.states[16].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[16].mesid.sat,
                        greater.states[16].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[17].cn0, greater.states[17].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[17].mesid.code,
                        greater.states[17].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[17].mesid.sat,
                        greater.states[17].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[18].cn0, greater.states[18].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[18].mesid.code,
                        greater.states[18].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[18].mesid.sat,
                        greater.states[18].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[19].cn0, greater.states[19].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[19].mesid.code,
                        greater.states[19].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[19].mesid.sat,
                        greater.states[19].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[20].cn0, greater.states[20].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[20].mesid.code,
                        greater.states[20].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[20].mesid.sat,
                        greater.states[20].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[21].cn0, greater.states[21].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[21].mesid.code,
                        greater.states[21].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[21].mesid.sat,
                        greater.states[21].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[22].cn0, greater.states[22].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[22].mesid.code,
                        greater.states[22].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[22].mesid.sat,
                        greater.states[22].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[23].cn0, greater.states[23].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[23].mesid.code,
                        greater.states[23].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[23].mesid.sat,
                        greater.states[23].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[24].cn0, greater.states[24].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[24].mesid.code,
                        greater.states[24].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[24].mesid.sat,
                        greater.states[24].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[25].cn0, greater.states[25].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[25].mesid.code,
                        greater.states[25].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[25].mesid.sat,
                        greater.states[25].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[26].cn0, greater.states[26].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[26].mesid.code,
                        greater.states[26].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[26].mesid.sat,
                        greater.states[26].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[27].cn0, greater.states[27].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[27].mesid.code,
                        greater.states[27].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[27].mesid.sat,
                        greater.states[27].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[28].cn0, greater.states[28].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[28].mesid.code,
                        greater.states[28].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[28].mesid.sat,
                        greater.states[28].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[29].cn0, greater.states[29].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[29].mesid.code,
                        greater.states[29].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[29].mesid.sat,
                        greater.states[29].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[30].cn0, greater.states[30].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[30].mesid.code,
                        greater.states[30].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[30].mesid.sat,
                        greater.states[30].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[31].cn0, greater.states[31].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[31].mesid.code,
                        greater.states[31].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[31].mesid.sat,
                        greater.states[31].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[32].cn0, greater.states[32].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[32].mesid.code,
                        greater.states[32].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[32].mesid.sat,
                        greater.states[32].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[33].cn0, greater.states[33].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[33].mesid.code,
                        greater.states[33].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[33].mesid.sat,
                        greater.states[33].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[34].cn0, greater.states[34].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[34].mesid.code,
                        greater.states[34].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[34].mesid.sat,
                        greater.states[34].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[35].cn0, greater.states[35].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[35].mesid.code,
                        greater.states[35].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[35].mesid.sat,
                        greater.states[35].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[36].cn0, greater.states[36].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[36].mesid.code,
                        greater.states[36].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[36].mesid.sat,
                        greater.states[36].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[37].cn0, greater.states[37].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[37].mesid.code,
                        greater.states[37].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[37].mesid.sat,
                        greater.states[37].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[38].cn0, greater.states[38].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[38].mesid.code,
                        greater.states[38].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[38].mesid.sat,
                        greater.states[38].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[39].cn0, greater.states[39].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[39].mesid.code,
                        greater.states[39].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[39].mesid.sat,
                        greater.states[39].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[40].cn0, greater.states[40].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[40].mesid.code,
                        greater.states[40].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[40].mesid.sat,
                        greater.states[40].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[41].cn0, greater.states[41].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[41].mesid.code,
                        greater.states[41].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[41].mesid.sat,
                        greater.states[41].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[42].cn0, greater.states[42].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[42].mesid.code,
                        greater.states[42].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[42].mesid.sat,
                        greater.states[42].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[43].cn0, greater.states[43].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[43].mesid.code,
                        greater.states[43].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[43].mesid.sat,
                        greater.states[43].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[44].cn0, greater.states[44].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[44].mesid.code,
                        greater.states[44].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[44].mesid.sat,
                        greater.states[44].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[45].cn0, greater.states[45].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[45].mesid.code,
                        greater.states[45].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[45].mesid.sat,
                        greater.states[45].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[46].cn0, greater.states[46].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[46].mesid.code,
                        greater.states[46].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[46].mesid.sat,
                        greater.states[46].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[47].cn0, greater.states[47].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[47].mesid.code,
                        greater.states[47].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[47].mesid.sat,
                        greater.states[47].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[48].cn0, greater.states[48].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[48].mesid.code,
                        greater.states[48].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[48].mesid.sat,
                        greater.states[48].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[49].cn0, greater.states[49].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[49].mesid.code,
                        greater.states[49].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[49].mesid.sat,
                        greater.states[49].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[50].cn0, greater.states[50].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[50].mesid.code,
                        greater.states[50].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[50].mesid.sat,
                        greater.states[50].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[51].cn0, greater.states[51].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[51].mesid.code,
                        greater.states[51].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[51].mesid.sat,
                        greater.states[51].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[52].cn0, greater.states[52].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[52].mesid.code,
                        greater.states[52].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[52].mesid.sat,
                        greater.states[52].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[53].cn0, greater.states[53].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[53].mesid.code,
                        greater.states[53].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[53].mesid.sat,
                        greater.states[53].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[54].cn0, greater.states[54].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[54].mesid.code,
                        greater.states[54].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[54].mesid.sat,
                        greater.states[54].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[55].cn0, greater.states[55].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[55].mesid.code,
                        greater.states[55].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[55].mesid.sat,
                        greater.states[55].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[56].cn0, greater.states[56].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[56].mesid.code,
                        greater.states[56].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[56].mesid.sat,
                        greater.states[56].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[57].cn0, greater.states[57].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[57].mesid.code,
                        greater.states[57].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[57].mesid.sat,
                        greater.states[57].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[58].cn0, greater.states[58].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[58].mesid.code,
                        greater.states[58].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[58].mesid.sat,
                        greater.states[58].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[59].cn0, greater.states[59].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[59].mesid.code,
                        greater.states[59].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[59].mesid.sat,
                        greater.states[59].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[60].cn0, greater.states[60].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[60].mesid.code,
                        greater.states[60].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[60].mesid.sat,
                        greater.states[60].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[61].cn0, greater.states[61].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[61].mesid.code,
                        greater.states[61].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[61].mesid.sat,
                        greater.states[61].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[62].cn0, greater.states[62].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[62].mesid.code,
                        greater.states[62].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[62].mesid.sat,
                        greater.states[62].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[63].cn0, greater.states[63].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[63].mesid.code,
                        greater.states[63].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[63].mesid.sat,
                        greater.states[63].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[64].cn0, greater.states[64].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[64].mesid.code,
                        greater.states[64].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[64].mesid.sat,
                        greater.states[64].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[65].cn0, greater.states[65].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[65].mesid.code,
                        greater.states[65].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[65].mesid.sat,
                        greater.states[65].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[66].cn0, greater.states[66].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[66].mesid.code,
                        greater.states[66].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[66].mesid.sat,
                        greater.states[66].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[67].cn0, greater.states[67].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[67].mesid.code,
                        greater.states[67].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[67].mesid.sat,
                        greater.states[67].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[68].cn0, greater.states[68].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[68].mesid.code,
                        greater.states[68].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[68].mesid.sat,
                        greater.states[68].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[69].cn0, greater.states[69].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[69].mesid.code,
                        greater.states[69].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[69].mesid.sat,
                        greater.states[69].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[70].cn0, greater.states[70].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[70].mesid.code,
                        greater.states[70].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[70].mesid.sat,
                        greater.states[70].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[71].cn0, greater.states[71].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[71].mesid.code,
                        greater.states[71].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[71].mesid.sat,
                        greater.states[71].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[72].cn0, greater.states[72].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[72].mesid.code,
                        greater.states[72].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[72].mesid.sat,
                        greater.states[72].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[73].cn0, greater.states[73].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[73].mesid.code,
                        greater.states[73].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[73].mesid.sat,
                        greater.states[73].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[74].cn0, greater.states[74].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[74].mesid.code,
                        greater.states[74].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[74].mesid.sat,
                        greater.states[74].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[75].cn0, greater.states[75].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[75].mesid.code,
                        greater.states[75].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[75].mesid.sat,
                        greater.states[75].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[76].cn0, greater.states[76].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[76].mesid.code,
                        greater.states[76].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[76].mesid.sat,
                        greater.states[76].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[77].cn0, greater.states[77].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[77].mesid.code,
                        greater.states[77].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[77].mesid.sat,
                        greater.states[77].mesid.sat);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[78].cn0, greater.states[78].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[78].mesid.code,
                        greater.states[78].mesid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_measurement_state_t lesser = info.test_msg;
    sbp_msg_measurement_state_t greater = info.test_msg;
    make_lesser_greater(lesser.states[78].mesid.sat,
                        greater.states[78].mesid.sat);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_measurement_state_t>::id,
  // SbpMsgMeasurementState);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_measurement_state_t>::name,
               "MSG_MEASUREMENT_STATE");
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_measurement_state_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_measurement_state_t>::get(const_sbp_msg_t);
  sbp_msg_measurement_state_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_measurement_state_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 = sbp::MessageTraits<sbp_msg_measurement_state_t>::to_sbp_msg(
      info.test_msg);
  EXPECT_EQ(msg1.measurement_state, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_measurement_state_t>::to_sbp_msg(info.test_msg,
                                                              &msg2);
  EXPECT_EQ(msg2.measurement_state, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_measurement_state_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_measurement_state_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[237];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_measurement_state_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 237);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 237), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_measurement_state_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_measurement_state_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 237);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0,
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

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgMeasurementState,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_tracking_MsgMeasurementState0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgMeasurementState,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace