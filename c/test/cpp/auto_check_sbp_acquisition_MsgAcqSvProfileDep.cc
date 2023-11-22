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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqSvProfileDep.yaml by
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
class Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0() {
    assign(test_msg_.acq_sv_profile[0].bin_width, 187);
    assign(test_msg_.acq_sv_profile[0].cf, 60);
    assign(test_msg_.acq_sv_profile[0].cf_max, 36);
    assign(test_msg_.acq_sv_profile[0].cf_min, 132);
    assign(test_msg_.acq_sv_profile[0].cn0, 151);
    assign(test_msg_.acq_sv_profile[0].cp, 241);
    assign(test_msg_.acq_sv_profile[0].int_time, 12);
    assign(test_msg_.acq_sv_profile[0].job_type, 67);
    assign(test_msg_.acq_sv_profile[0].sid.code, 0);
    assign(test_msg_.acq_sv_profile[0].sid.reserved, 0);
    assign(test_msg_.acq_sv_profile[0].sid.sat, 22);
    assign(test_msg_.acq_sv_profile[0].status, 103);
    assign(test_msg_.acq_sv_profile[0].time_spent, 75);
    assign(test_msg_.acq_sv_profile[0].timestamp, 91);

    assign(test_msg_.acq_sv_profile[1].bin_width, 176);
    assign(test_msg_.acq_sv_profile[1].cf, 212);
    assign(test_msg_.acq_sv_profile[1].cf_max, 24);
    assign(test_msg_.acq_sv_profile[1].cf_min, 155);
    assign(test_msg_.acq_sv_profile[1].cn0, 111);
    assign(test_msg_.acq_sv_profile[1].cp, 247);
    assign(test_msg_.acq_sv_profile[1].int_time, 179);
    assign(test_msg_.acq_sv_profile[1].job_type, 238);
    assign(test_msg_.acq_sv_profile[1].sid.code, 1);
    assign(test_msg_.acq_sv_profile[1].sid.reserved, 0);
    assign(test_msg_.acq_sv_profile[1].sid.sat, 23);
    assign(test_msg_.acq_sv_profile[1].status, 38);
    assign(test_msg_.acq_sv_profile[1].time_spent, 234);
    assign(test_msg_.acq_sv_profile[1].timestamp, 166);

    assign(test_msg_.acq_sv_profile[2].bin_width, 52);
    assign(test_msg_.acq_sv_profile[2].cf, 212);
    assign(test_msg_.acq_sv_profile[2].cf_max, 248);
    assign(test_msg_.acq_sv_profile[2].cf_min, 76);
    assign(test_msg_.acq_sv_profile[2].cn0, 68);
    assign(test_msg_.acq_sv_profile[2].cp, 101);
    assign(test_msg_.acq_sv_profile[2].int_time, 53);
    assign(test_msg_.acq_sv_profile[2].job_type, 142);
    assign(test_msg_.acq_sv_profile[2].sid.code, 0);
    assign(test_msg_.acq_sv_profile[2].sid.reserved, 0);
    assign(test_msg_.acq_sv_profile[2].sid.sat, 24);
    assign(test_msg_.acq_sv_profile[2].status, 213);
    assign(test_msg_.acq_sv_profile[2].time_spent, 245);
    assign(test_msg_.acq_sv_profile[2].timestamp, 49);
    assign(test_msg_.n_acq_sv_profile, 3);
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
      : public sbp::MessageHandler<sbp_msg_acq_sv_profile_dep_t> {
    using sbp::MessageHandler<sbp_msg_acq_sv_profile_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_acq_sv_profile_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_acq_sv_profile_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgAcqSvProfileDep,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_acq_sv_profile_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgAcqSvProfileDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->acq_sv_profile_dep,
             sizeof(msg->acq_sv_profile_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_acq_sv_profile_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.acq_sv_profile_dep, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgAcqSvProfileDep);
    info.sender_id = 1219;
    info.preamble = 0x55;
    info.crc = 0x8443;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 105;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_acq_sv_profile_dep_t &lesser,
                        const sbp_msg_acq_sv_profile_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_acq_sv_profile_dep_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_acq_sv_profile_dep_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_acq_sv_profile_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_acq_sv_profile_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_acq_sv_profile_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_acq_sv_profile_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqSvProfileDep, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgAcqSvProfileDep, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgAcqSvProfileDep, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgAcqSvProfileDep, &wrapped_greater,
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
  sbp_msg_acq_sv_profile_dep_t test_msg_{};
  uint8_t encoded_frame_[105 + 8] = {
      85,  30,  0,   195, 4,  105, 67, 103, 151, 0,   12,  22,  0,   0,   0,
      187, 0,   91,  0,   0,  0,   75, 0,   0,   0,   132, 0,   0,   0,   36,
      0,   0,   0,   60,  0,  0,   0,  241, 0,   0,   0,   238, 38,  111, 0,
      179, 23,  0,   1,   0,  176, 0,  166, 0,   0,   0,   234, 0,   0,   0,
      155, 0,   0,   0,   24, 0,   0,  0,   212, 0,   0,   0,   247, 0,   0,
      0,   142, 213, 68,  0,  53,  24, 0,   0,   0,   52,  0,   49,  0,   0,
      0,   245, 0,   0,   0,  76,  0,  0,   0,   248, 0,   0,   0,   212, 0,
      0,   0,   101, 0,   0,  0,   67, 132,
  };
  uint8_t encoded_payload_[105] = {
      67, 103, 151, 0,   12,  22,  0,   0,   0,  187, 0,   91,  0,  0,  0,
      75, 0,   0,   0,   132, 0,   0,   0,   36, 0,   0,   0,   60, 0,  0,
      0,  241, 0,   0,   0,   238, 38,  111, 0,  179, 23,  0,   1,  0,  176,
      0,  166, 0,   0,   0,   234, 0,   0,   0,  155, 0,   0,   0,  24, 0,
      0,  0,   212, 0,   0,   0,   247, 0,   0,  0,   142, 213, 68, 0,  53,
      24, 0,   0,   0,   52,  0,   49,  0,   0,  0,   245, 0,   0,  0,  76,
      0,  0,   0,   248, 0,   0,   0,   212, 0,  0,   0,   101, 0,  0,  0,
  };
};

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_acq_sv_profile_dep_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(
      sbp_message_encoded_len(SbpMsgAcqSvProfileDep, &info.test_msg_wrapped),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[105];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_acq_sv_profile_dep_encode(&buf[0], sizeof(buf), &n_written,
                                              &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 105);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 105), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgAcqSvProfileDep, &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 105);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 105), 0);
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[105];

  EXPECT_EQ(sbp_msg_acq_sv_profile_dep_encode(&buf[0], sizeof(buf), nullptr,
                                              &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 105), 0);
}
TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[105];

  for (uint8_t i = 0; i < 105; i++) {
    EXPECT_EQ(
        sbp_msg_acq_sv_profile_dep_encode(&buf[0], i, nullptr, &info.test_msg),
        SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_acq_sv_profile_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_acq_sv_profile_dep_decode(&info.encoded_payload[0],
                                              info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 105);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgAcqSvProfileDep, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 105);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_acq_sv_profile_dep_t msg{};

  EXPECT_EQ(sbp_msg_acq_sv_profile_dep_decode(&info.encoded_payload[0],
                                              info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_acq_sv_profile_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_acq_sv_profile_dep_t t{};
      return sbp_msg_acq_sv_profile_dep_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_acq_sv_profile_dep_t t{};
      t.n_acq_sv_profile = 1;
      return sbp_msg_acq_sv_profile_dep_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_acq_sv_profile_dep_decode(&info.encoded_payload[0], i,
                                                nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
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

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
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

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0, SlowRead) {
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

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0, BadCRC) {
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

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_acq_sv_profile_dep_send(&state, info.sender_id,
                                            &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgAcqSvProfileDep, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgAcqSvProfileDep, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgAcqSvProfileDep, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0, Comparison) {
  auto info = get_test_msg_info();

  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[0].bin_width,
                        greater.acq_sv_profile[0].bin_width);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[0].cf,
                        greater.acq_sv_profile[0].cf);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[0].cf_max,
                        greater.acq_sv_profile[0].cf_max);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[0].cf_min,
                        greater.acq_sv_profile[0].cf_min);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[0].cn0,
                        greater.acq_sv_profile[0].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[0].cp,
                        greater.acq_sv_profile[0].cp);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[0].int_time,
                        greater.acq_sv_profile[0].int_time);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[0].job_type,
                        greater.acq_sv_profile[0].job_type);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[0].sid.code,
                        greater.acq_sv_profile[0].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[0].sid.reserved,
                        greater.acq_sv_profile[0].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[0].sid.sat,
                        greater.acq_sv_profile[0].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[0].status,
                        greater.acq_sv_profile[0].status);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[0].time_spent,
                        greater.acq_sv_profile[0].time_spent);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[0].timestamp,
                        greater.acq_sv_profile[0].timestamp);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[1].bin_width,
                        greater.acq_sv_profile[1].bin_width);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[1].cf,
                        greater.acq_sv_profile[1].cf);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[1].cf_max,
                        greater.acq_sv_profile[1].cf_max);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[1].cf_min,
                        greater.acq_sv_profile[1].cf_min);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[1].cn0,
                        greater.acq_sv_profile[1].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[1].cp,
                        greater.acq_sv_profile[1].cp);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[1].int_time,
                        greater.acq_sv_profile[1].int_time);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[1].job_type,
                        greater.acq_sv_profile[1].job_type);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[1].sid.code,
                        greater.acq_sv_profile[1].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[1].sid.reserved,
                        greater.acq_sv_profile[1].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[1].sid.sat,
                        greater.acq_sv_profile[1].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[1].status,
                        greater.acq_sv_profile[1].status);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[1].time_spent,
                        greater.acq_sv_profile[1].time_spent);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[1].timestamp,
                        greater.acq_sv_profile[1].timestamp);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[2].bin_width,
                        greater.acq_sv_profile[2].bin_width);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[2].cf,
                        greater.acq_sv_profile[2].cf);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[2].cf_max,
                        greater.acq_sv_profile[2].cf_max);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[2].cf_min,
                        greater.acq_sv_profile[2].cf_min);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[2].cn0,
                        greater.acq_sv_profile[2].cn0);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[2].cp,
                        greater.acq_sv_profile[2].cp);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[2].int_time,
                        greater.acq_sv_profile[2].int_time);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[2].job_type,
                        greater.acq_sv_profile[2].job_type);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[2].sid.code,
                        greater.acq_sv_profile[2].sid.code);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[2].sid.reserved,
                        greater.acq_sv_profile[2].sid.reserved);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[2].sid.sat,
                        greater.acq_sv_profile[2].sid.sat);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[2].status,
                        greater.acq_sv_profile[2].status);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[2].time_spent,
                        greater.acq_sv_profile[2].time_spent);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.acq_sv_profile[2].timestamp,
                        greater.acq_sv_profile[2].timestamp);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_acq_sv_profile_dep_t lesser = info.test_msg;
    sbp_msg_acq_sv_profile_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.n_acq_sv_profile, greater.n_acq_sv_profile);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_acq_sv_profile_dep_t>::id,
  // SbpMsgAcqSvProfileDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_acq_sv_profile_dep_t>::name,
               "MSG_ACQ_SV_PROFILE_DEP");
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_acq_sv_profile_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_acq_sv_profile_dep_t>::get(const_sbp_msg_t);
  sbp_msg_acq_sv_profile_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_acq_sv_profile_dep_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 = sbp::MessageTraits<sbp_msg_acq_sv_profile_dep_t>::to_sbp_msg(
      info.test_msg);
  EXPECT_EQ(msg1.acq_sv_profile_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_acq_sv_profile_dep_t>::to_sbp_msg(info.test_msg,
                                                               &msg2);
  EXPECT_EQ(msg2.acq_sv_profile_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_acq_sv_profile_dep_t>::encoded_len(
                info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_acq_sv_profile_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[105];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_acq_sv_profile_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 105);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 105), 0);
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_acq_sv_profile_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_acq_sv_profile_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 105);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
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

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgAcqSvProfileDep,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_acquisition_MsgAcqSvProfileDep0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgAcqSvProfileDep,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace