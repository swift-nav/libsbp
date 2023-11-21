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
// spec/tests/yaml/swiftnav/sbp/logging/test_MsgPrintDep.yaml by generate.py. Do
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
class Testauto_check_sbp_logging_MsgPrintDep0 : public ::testing::Test {
 public:
  Testauto_check_sbp_logging_MsgPrintDep0() {
    size_t written;
    EXPECT_TRUE(sbp_msg_print_dep_text_set(
        &test_msg_, "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n", false,
        &written));
    EXPECT_EQ(written, strlen("INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n"));
    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg_), 43);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_print_dep_t> {
    using sbp::MessageHandler<sbp_msg_print_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_print_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_print_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgPrintDep, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_print_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgPrintDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->print_dep, sizeof(msg->print_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_print_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.print_dep, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgPrintDep);
    info.sender_id = 8738;
    info.preamble = 0x55;
    info.crc = 0x6774;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 43;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_print_dep_t &lesser,
                        const sbp_msg_print_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_print_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_print_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_print_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_print_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgPrintDep, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_lesser, &wrapped_greater), 0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_greater, &wrapped_lesser), 0);

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
  sbp_msg_print_dep_t test_msg_{};
  uint8_t encoded_frame_[43 + 8] = {
      85,  16,  0,   34, 34, 43, 73, 78, 70, 79, 58,  32,  97,
      99,  113, 58,  32, 80, 82, 78, 32, 49, 53, 32,  102, 111,
      117, 110, 100, 32, 64, 32, 45, 50, 52, 57, 55,  32,  72,
      122, 44,  32,  50, 48, 32, 83, 78, 82, 10, 116, 103,
  };
  uint8_t encoded_payload_[43] = {
      73, 78, 70, 79,  58,  32,  97,  99,  113, 58, 32, 80, 82, 78, 32,
      49, 53, 32, 102, 111, 117, 110, 100, 32,  64, 32, 45, 50, 52, 57,
      55, 32, 72, 122, 44,  32,  50,  48,  32,  83, 78, 82, 10,
  };
};

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_print_dep_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgPrintDep, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[43];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_print_dep_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 43);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 43), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgPrintDep,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 43);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 43), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[43];

  EXPECT_EQ(
      sbp_msg_print_dep_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 43), 0);
}
TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[43];

  for (uint8_t i = 0; i < 43; i++) {
    EXPECT_EQ(sbp_msg_print_dep_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_print_dep_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 43);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgPrintDep, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 43);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};

  EXPECT_EQ(sbp_msg_print_dep_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = SBP_MSG_PRINT_DEP_ENCODED_OVERHEAD;
    // size_t overhead = []()->size_t{sbp_msg_print_dep_t t{}; return
    // sbp_msg_print_dep_encoded_len(&t); }();
    if (i >= overhead) {
      expected_return = SBP_OK;
    }

    EXPECT_EQ(
        sbp_msg_print_dep_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0,
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, SlowRead) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, BadCRC) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_print_dep_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_print_dep_t lesser = info.test_msg;
    sbp_msg_print_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.text, greater.text);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::id, SbpMsgPrintDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_print_dep_t>::name, "MSG_PRINT_DEP");
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_print_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_print_dep_t>::get(const_sbp_msg_t);
  sbp_msg_print_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_print_dep_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.print_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.print_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[43];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 43);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 43), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 43);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgPrintDep, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgPrintDep, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_logging_MsgPrintDep0_text
    : public Testauto_check_sbp_logging_MsgPrintDep0 {};

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0_text, StringInit) {
  sbp_msg_print_dep_t t{};
  sbp_msg_print_dep_text_init(&t);
  EXPECT_TRUE(sbp_msg_print_dep_text_valid(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0_text, IsValid) {
  sbp_msg_print_dep_t t{};

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &t, "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n", false, &written));
  EXPECT_EQ(written, strlen("INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&t), 43);
  EXPECT_TRUE(sbp_msg_print_dep_text_valid(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0_text, SpaceRemaining) {
  sbp_msg_print_dep_t t{};
  size_t empty_space_remaining = sbp_msg_print_dep_text_space_remaining(&t);

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &t, "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n", false, &written));
  EXPECT_EQ(written, strlen("INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&t), 43);
  size_t assigned_space_remaining = sbp_msg_print_dep_text_space_remaining(&t);
  EXPECT_LT(assigned_space_remaining, empty_space_remaining);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0_text, SetRaw) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t t{};

  size_t nwritten{};

  EXPECT_TRUE(sbp_msg_print_dep_text_set_raw(
      &t, info.test_msg.text.data,
      sbp_msg_print_dep_text_strlen(&info.test_msg), false, &nwritten));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&info.test_msg),
            sbp_msg_print_dep_text_encoded_len(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0_text, Set) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n";

  EXPECT_TRUE(sbp_msg_print_dep_text_set(&t, text, false, &nwritten));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0_text, Printf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n";

  EXPECT_TRUE(sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", text));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0_text, Vprintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n";

  auto lambda = [&t, &nwritten](const char *format, ...) -> bool {
    va_list ap;
    va_start(ap, format);
    bool ret = sbp_msg_print_dep_text_vprintf(&t, false, &nwritten, format, ap);
    va_end(ap);
    return ret;
  };

  EXPECT_TRUE(lambda("%s", text));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0_text, AppendPrintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  char part1[] = "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n";
  char part2[] = "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n";

  part1[1] = 0;

  EXPECT_TRUE(
      sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", &part1[0]));
  EXPECT_EQ(nwritten, 1);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), &part1[0]);

  EXPECT_TRUE(sbp_msg_print_dep_text_append_printf(&t, false, &nwritten, "%s",
                                                   &part2[1]));
  EXPECT_EQ(nwritten, strlen(&part2[1]));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t),
               "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n");
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep0_text, AppendVprintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  char part1[] = "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n";
  char part2[] = "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n";

  part1[1] = 0;

  EXPECT_TRUE(
      sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", &part1[0]));
  EXPECT_EQ(nwritten, 1);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), &part1[0]);

  auto lambda = [&t, &nwritten](const char *format, ...) -> bool {
    va_list ap;
    va_start(ap, format);
    bool ret =
        sbp_msg_print_dep_text_append_vprintf(&t, false, &nwritten, format, ap);
    va_end(ap);
    return ret;
  };

  EXPECT_TRUE(lambda("%s", &part2[1]));
  EXPECT_EQ(nwritten, strlen(&part2[1]));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t),
               "INFO: acq: PRN 15 found @ -2497 Hz, 20 SNR\n");
}

class Testauto_check_sbp_logging_MsgPrintDep1 : public ::testing::Test {
 public:
  Testauto_check_sbp_logging_MsgPrintDep1() {
    size_t written;
    EXPECT_TRUE(sbp_msg_print_dep_text_set(
        &test_msg_, "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n", false,
        &written));
    EXPECT_EQ(written, strlen("INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n"));
    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg_), 42);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_print_dep_t> {
    using sbp::MessageHandler<sbp_msg_print_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_print_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_print_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgPrintDep, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_print_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgPrintDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->print_dep, sizeof(msg->print_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_print_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.print_dep, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgPrintDep);
    info.sender_id = 8738;
    info.preamble = 0x55;
    info.crc = 0x2b8c;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 42;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_print_dep_t &lesser,
                        const sbp_msg_print_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_print_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_print_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_print_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_print_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgPrintDep, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_lesser, &wrapped_greater), 0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_greater, &wrapped_lesser), 0);

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
  sbp_msg_print_dep_t test_msg_{};
  uint8_t encoded_frame_[42 + 8] = {
      85, 16, 0,  34, 34,  42, 73, 78,  70,  79,  58,  32,  97, 99, 113, 58, 32,
      80, 82, 78, 32, 51,  49, 32, 102, 111, 117, 110, 100, 32, 64, 32,  52, 50,
      52, 53, 32, 72, 122, 44, 32, 50,  49,  32,  83,  78,  82, 10, 140, 43,
  };
  uint8_t encoded_payload_[42] = {
      73, 78, 70, 79, 58,  32,  97,  99,  113, 58, 32, 80, 82, 78,
      32, 51, 49, 32, 102, 111, 117, 110, 100, 32, 64, 32, 52, 50,
      52, 53, 32, 72, 122, 44,  32,  50,  49,  32, 83, 78, 82, 10,
  };
};

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_print_dep_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgPrintDep, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[42];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_print_dep_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 42);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 42), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgPrintDep,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 42);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 42), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[42];

  EXPECT_EQ(
      sbp_msg_print_dep_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 42), 0);
}
TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[42];

  for (uint8_t i = 0; i < 42; i++) {
    EXPECT_EQ(sbp_msg_print_dep_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_print_dep_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 42);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgPrintDep, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 42);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};

  EXPECT_EQ(sbp_msg_print_dep_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = SBP_MSG_PRINT_DEP_ENCODED_OVERHEAD;
    // size_t overhead = []()->size_t{sbp_msg_print_dep_t t{}; return
    // sbp_msg_print_dep_encoded_len(&t); }();
    if (i >= overhead) {
      expected_return = SBP_OK;
    }

    EXPECT_EQ(
        sbp_msg_print_dep_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1,
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, SlowRead) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, BadCRC) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_print_dep_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_print_dep_t lesser = info.test_msg;
    sbp_msg_print_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.text, greater.text);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::id, SbpMsgPrintDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_print_dep_t>::name, "MSG_PRINT_DEP");
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_print_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_print_dep_t>::get(const_sbp_msg_t);
  sbp_msg_print_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_print_dep_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.print_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.print_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[42];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 42);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 42), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 42);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgPrintDep, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgPrintDep, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_logging_MsgPrintDep1_text
    : public Testauto_check_sbp_logging_MsgPrintDep1 {};

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1_text, StringInit) {
  sbp_msg_print_dep_t t{};
  sbp_msg_print_dep_text_init(&t);
  EXPECT_TRUE(sbp_msg_print_dep_text_valid(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1_text, IsValid) {
  sbp_msg_print_dep_t t{};

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &t, "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n", false, &written));
  EXPECT_EQ(written, strlen("INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&t), 42);
  EXPECT_TRUE(sbp_msg_print_dep_text_valid(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1_text, SpaceRemaining) {
  sbp_msg_print_dep_t t{};
  size_t empty_space_remaining = sbp_msg_print_dep_text_space_remaining(&t);

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &t, "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n", false, &written));
  EXPECT_EQ(written, strlen("INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&t), 42);
  size_t assigned_space_remaining = sbp_msg_print_dep_text_space_remaining(&t);
  EXPECT_LT(assigned_space_remaining, empty_space_remaining);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1_text, SetRaw) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t t{};

  size_t nwritten{};

  EXPECT_TRUE(sbp_msg_print_dep_text_set_raw(
      &t, info.test_msg.text.data,
      sbp_msg_print_dep_text_strlen(&info.test_msg), false, &nwritten));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&info.test_msg),
            sbp_msg_print_dep_text_encoded_len(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1_text, Set) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n";

  EXPECT_TRUE(sbp_msg_print_dep_text_set(&t, text, false, &nwritten));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1_text, Printf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n";

  EXPECT_TRUE(sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", text));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1_text, Vprintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n";

  auto lambda = [&t, &nwritten](const char *format, ...) -> bool {
    va_list ap;
    va_start(ap, format);
    bool ret = sbp_msg_print_dep_text_vprintf(&t, false, &nwritten, format, ap);
    va_end(ap);
    return ret;
  };

  EXPECT_TRUE(lambda("%s", text));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1_text, AppendPrintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  char part1[] = "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n";
  char part2[] = "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n";

  part1[1] = 0;

  EXPECT_TRUE(
      sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", &part1[0]));
  EXPECT_EQ(nwritten, 1);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), &part1[0]);

  EXPECT_TRUE(sbp_msg_print_dep_text_append_printf(&t, false, &nwritten, "%s",
                                                   &part2[1]));
  EXPECT_EQ(nwritten, strlen(&part2[1]));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t),
               "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n");
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep1_text, AppendVprintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  char part1[] = "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n";
  char part2[] = "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n";

  part1[1] = 0;

  EXPECT_TRUE(
      sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", &part1[0]));
  EXPECT_EQ(nwritten, 1);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), &part1[0]);

  auto lambda = [&t, &nwritten](const char *format, ...) -> bool {
    va_list ap;
    va_start(ap, format);
    bool ret =
        sbp_msg_print_dep_text_append_vprintf(&t, false, &nwritten, format, ap);
    va_end(ap);
    return ret;
  };

  EXPECT_TRUE(lambda("%s", &part2[1]));
  EXPECT_EQ(nwritten, strlen(&part2[1]));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t),
               "INFO: acq: PRN 31 found @ 4245 Hz, 21 SNR\n");
}

class Testauto_check_sbp_logging_MsgPrintDep2 : public ::testing::Test {
 public:
  Testauto_check_sbp_logging_MsgPrintDep2() {
    size_t written;
    EXPECT_TRUE(sbp_msg_print_dep_text_set(
        &test_msg_, "INFO: Disabling channel 0 (PRN 11)\n", false, &written));
    EXPECT_EQ(written, strlen("INFO: Disabling channel 0 (PRN 11)\n"));
    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg_), 35);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_print_dep_t> {
    using sbp::MessageHandler<sbp_msg_print_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_print_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_print_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgPrintDep, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_print_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgPrintDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->print_dep, sizeof(msg->print_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_print_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.print_dep, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgPrintDep);
    info.sender_id = 8738;
    info.preamble = 0x55;
    info.crc = 0x8f17;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 35;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_print_dep_t &lesser,
                        const sbp_msg_print_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_print_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_print_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_print_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_print_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgPrintDep, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_lesser, &wrapped_greater), 0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_greater, &wrapped_lesser), 0);

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
  sbp_msg_print_dep_t test_msg_{};
  uint8_t encoded_frame_[35 + 8] = {
      85, 16, 0,   34,  34,  35,  73, 78, 70,  79, 58,  32,  68,  105, 115,
      97, 98, 108, 105, 110, 103, 32, 99, 104, 97, 110, 110, 101, 108, 32,
      48, 32, 40,  80,  82,  78,  32, 49, 49,  41, 10,  23,  143,
  };
  uint8_t encoded_payload_[35] = {
      73,  78,  70,  79, 58, 32,  68, 105, 115, 97,  98,  108,
      105, 110, 103, 32, 99, 104, 97, 110, 110, 101, 108, 32,
      48,  32,  40,  80, 82, 78,  32, 49,  49,  41,  10,
  };
};

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_print_dep_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgPrintDep, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[35];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_print_dep_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 35);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 35), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgPrintDep,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 35);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 35), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[35];

  EXPECT_EQ(
      sbp_msg_print_dep_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 35), 0);
}
TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[35];

  for (uint8_t i = 0; i < 35; i++) {
    EXPECT_EQ(sbp_msg_print_dep_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_print_dep_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 35);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgPrintDep, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 35);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};

  EXPECT_EQ(sbp_msg_print_dep_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = SBP_MSG_PRINT_DEP_ENCODED_OVERHEAD;
    // size_t overhead = []()->size_t{sbp_msg_print_dep_t t{}; return
    // sbp_msg_print_dep_encoded_len(&t); }();
    if (i >= overhead) {
      expected_return = SBP_OK;
    }

    EXPECT_EQ(
        sbp_msg_print_dep_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2,
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, SlowRead) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, BadCRC) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_print_dep_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_print_dep_t lesser = info.test_msg;
    sbp_msg_print_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.text, greater.text);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::id, SbpMsgPrintDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_print_dep_t>::name, "MSG_PRINT_DEP");
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_print_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_print_dep_t>::get(const_sbp_msg_t);
  sbp_msg_print_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_print_dep_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.print_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.print_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[35];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 35);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 35), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 35);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgPrintDep, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgPrintDep, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_logging_MsgPrintDep2_text
    : public Testauto_check_sbp_logging_MsgPrintDep2 {};

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2_text, StringInit) {
  sbp_msg_print_dep_t t{};
  sbp_msg_print_dep_text_init(&t);
  EXPECT_TRUE(sbp_msg_print_dep_text_valid(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2_text, IsValid) {
  sbp_msg_print_dep_t t{};

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &t, "INFO: Disabling channel 0 (PRN 11)\n", false, &written));
  EXPECT_EQ(written, strlen("INFO: Disabling channel 0 (PRN 11)\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&t), 35);
  EXPECT_TRUE(sbp_msg_print_dep_text_valid(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2_text, SpaceRemaining) {
  sbp_msg_print_dep_t t{};
  size_t empty_space_remaining = sbp_msg_print_dep_text_space_remaining(&t);

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &t, "INFO: Disabling channel 0 (PRN 11)\n", false, &written));
  EXPECT_EQ(written, strlen("INFO: Disabling channel 0 (PRN 11)\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&t), 35);
  size_t assigned_space_remaining = sbp_msg_print_dep_text_space_remaining(&t);
  EXPECT_LT(assigned_space_remaining, empty_space_remaining);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2_text, SetRaw) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t t{};

  size_t nwritten{};

  EXPECT_TRUE(sbp_msg_print_dep_text_set_raw(
      &t, info.test_msg.text.data,
      sbp_msg_print_dep_text_strlen(&info.test_msg), false, &nwritten));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&info.test_msg),
            sbp_msg_print_dep_text_encoded_len(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2_text, Set) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: Disabling channel 0 (PRN 11)\n";

  EXPECT_TRUE(sbp_msg_print_dep_text_set(&t, text, false, &nwritten));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2_text, Printf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: Disabling channel 0 (PRN 11)\n";

  EXPECT_TRUE(sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", text));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2_text, Vprintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: Disabling channel 0 (PRN 11)\n";

  auto lambda = [&t, &nwritten](const char *format, ...) -> bool {
    va_list ap;
    va_start(ap, format);
    bool ret = sbp_msg_print_dep_text_vprintf(&t, false, &nwritten, format, ap);
    va_end(ap);
    return ret;
  };

  EXPECT_TRUE(lambda("%s", text));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2_text, AppendPrintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  char part1[] = "INFO: Disabling channel 0 (PRN 11)\n";
  char part2[] = "INFO: Disabling channel 0 (PRN 11)\n";

  part1[1] = 0;

  EXPECT_TRUE(
      sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", &part1[0]));
  EXPECT_EQ(nwritten, 1);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), &part1[0]);

  EXPECT_TRUE(sbp_msg_print_dep_text_append_printf(&t, false, &nwritten, "%s",
                                                   &part2[1]));
  EXPECT_EQ(nwritten, strlen(&part2[1]));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t),
               "INFO: Disabling channel 0 (PRN 11)\n");
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep2_text, AppendVprintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  char part1[] = "INFO: Disabling channel 0 (PRN 11)\n";
  char part2[] = "INFO: Disabling channel 0 (PRN 11)\n";

  part1[1] = 0;

  EXPECT_TRUE(
      sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", &part1[0]));
  EXPECT_EQ(nwritten, 1);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), &part1[0]);

  auto lambda = [&t, &nwritten](const char *format, ...) -> bool {
    va_list ap;
    va_start(ap, format);
    bool ret =
        sbp_msg_print_dep_text_append_vprintf(&t, false, &nwritten, format, ap);
    va_end(ap);
    return ret;
  };

  EXPECT_TRUE(lambda("%s", &part2[1]));
  EXPECT_EQ(nwritten, strlen(&part2[1]));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t),
               "INFO: Disabling channel 0 (PRN 11)\n");
}

class Testauto_check_sbp_logging_MsgPrintDep3 : public ::testing::Test {
 public:
  Testauto_check_sbp_logging_MsgPrintDep3() {
    size_t written;
    EXPECT_TRUE(sbp_msg_print_dep_text_set(
        &test_msg_, "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n", false,
        &written));
    EXPECT_EQ(written, strlen("INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n"));
    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg_), 41);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_print_dep_t> {
    using sbp::MessageHandler<sbp_msg_print_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_print_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_print_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgPrintDep, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_print_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgPrintDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->print_dep, sizeof(msg->print_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_print_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.print_dep, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgPrintDep);
    info.sender_id = 8738;
    info.preamble = 0x55;
    info.crc = 0x30ef;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 41;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_print_dep_t &lesser,
                        const sbp_msg_print_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_print_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_print_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_print_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_print_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgPrintDep, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_lesser, &wrapped_greater), 0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_greater, &wrapped_lesser), 0);

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
  sbp_msg_print_dep_t test_msg_{};
  uint8_t encoded_frame_[41 + 8] = {
      85,  16,  0,  34, 34, 41, 73, 78, 70,  79, 58,  32,  97,
      99,  113, 58, 32, 80, 82, 78, 32, 50,  32, 102, 111, 117,
      110, 100, 32, 64, 32, 51, 57, 57, 54,  32, 72,  122, 44,
      32,  50,  48, 32, 83, 78, 82, 10, 239, 48,
  };
  uint8_t encoded_payload_[41] = {
      73, 78, 70, 79,  58,  32,  97,  99,  113, 58, 32, 80, 82, 78,
      32, 50, 32, 102, 111, 117, 110, 100, 32,  64, 32, 51, 57, 57,
      54, 32, 72, 122, 44,  32,  50,  48,  32,  83, 78, 82, 10,
  };
};

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_print_dep_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgPrintDep, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[41];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_print_dep_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 41);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 41), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgPrintDep,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 41);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 41), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[41];

  EXPECT_EQ(
      sbp_msg_print_dep_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 41), 0);
}
TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[41];

  for (uint8_t i = 0; i < 41; i++) {
    EXPECT_EQ(sbp_msg_print_dep_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_print_dep_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 41);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgPrintDep, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 41);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};

  EXPECT_EQ(sbp_msg_print_dep_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = SBP_MSG_PRINT_DEP_ENCODED_OVERHEAD;
    // size_t overhead = []()->size_t{sbp_msg_print_dep_t t{}; return
    // sbp_msg_print_dep_encoded_len(&t); }();
    if (i >= overhead) {
      expected_return = SBP_OK;
    }

    EXPECT_EQ(
        sbp_msg_print_dep_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3,
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, SlowRead) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, BadCRC) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_print_dep_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_print_dep_t lesser = info.test_msg;
    sbp_msg_print_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.text, greater.text);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::id, SbpMsgPrintDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_print_dep_t>::name, "MSG_PRINT_DEP");
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_print_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_print_dep_t>::get(const_sbp_msg_t);
  sbp_msg_print_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_print_dep_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.print_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.print_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[41];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 41);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 41), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 41);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgPrintDep, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgPrintDep, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_logging_MsgPrintDep3_text
    : public Testauto_check_sbp_logging_MsgPrintDep3 {};

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3_text, StringInit) {
  sbp_msg_print_dep_t t{};
  sbp_msg_print_dep_text_init(&t);
  EXPECT_TRUE(sbp_msg_print_dep_text_valid(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3_text, IsValid) {
  sbp_msg_print_dep_t t{};

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &t, "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n", false, &written));
  EXPECT_EQ(written, strlen("INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&t), 41);
  EXPECT_TRUE(sbp_msg_print_dep_text_valid(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3_text, SpaceRemaining) {
  sbp_msg_print_dep_t t{};
  size_t empty_space_remaining = sbp_msg_print_dep_text_space_remaining(&t);

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &t, "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n", false, &written));
  EXPECT_EQ(written, strlen("INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&t), 41);
  size_t assigned_space_remaining = sbp_msg_print_dep_text_space_remaining(&t);
  EXPECT_LT(assigned_space_remaining, empty_space_remaining);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3_text, SetRaw) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t t{};

  size_t nwritten{};

  EXPECT_TRUE(sbp_msg_print_dep_text_set_raw(
      &t, info.test_msg.text.data,
      sbp_msg_print_dep_text_strlen(&info.test_msg), false, &nwritten));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&info.test_msg),
            sbp_msg_print_dep_text_encoded_len(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3_text, Set) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n";

  EXPECT_TRUE(sbp_msg_print_dep_text_set(&t, text, false, &nwritten));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3_text, Printf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n";

  EXPECT_TRUE(sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", text));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3_text, Vprintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n";

  auto lambda = [&t, &nwritten](const char *format, ...) -> bool {
    va_list ap;
    va_start(ap, format);
    bool ret = sbp_msg_print_dep_text_vprintf(&t, false, &nwritten, format, ap);
    va_end(ap);
    return ret;
  };

  EXPECT_TRUE(lambda("%s", text));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3_text, AppendPrintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  char part1[] = "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n";
  char part2[] = "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n";

  part1[1] = 0;

  EXPECT_TRUE(
      sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", &part1[0]));
  EXPECT_EQ(nwritten, 1);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), &part1[0]);

  EXPECT_TRUE(sbp_msg_print_dep_text_append_printf(&t, false, &nwritten, "%s",
                                                   &part2[1]));
  EXPECT_EQ(nwritten, strlen(&part2[1]));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t),
               "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n");
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep3_text, AppendVprintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  char part1[] = "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n";
  char part2[] = "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n";

  part1[1] = 0;

  EXPECT_TRUE(
      sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", &part1[0]));
  EXPECT_EQ(nwritten, 1);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), &part1[0]);

  auto lambda = [&t, &nwritten](const char *format, ...) -> bool {
    va_list ap;
    va_start(ap, format);
    bool ret =
        sbp_msg_print_dep_text_append_vprintf(&t, false, &nwritten, format, ap);
    va_end(ap);
    return ret;
  };

  EXPECT_TRUE(lambda("%s", &part2[1]));
  EXPECT_EQ(nwritten, strlen(&part2[1]));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t),
               "INFO: acq: PRN 2 found @ 3996 Hz, 20 SNR\n");
}

class Testauto_check_sbp_logging_MsgPrintDep4 : public ::testing::Test {
 public:
  Testauto_check_sbp_logging_MsgPrintDep4() {
    size_t written;
    EXPECT_TRUE(sbp_msg_print_dep_text_set(
        &test_msg_, "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n", false,
        &written));
    EXPECT_EQ(written, strlen("INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n"));
    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg_), 42);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_print_dep_t> {
    using sbp::MessageHandler<sbp_msg_print_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_print_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_print_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgPrintDep, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_print_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgPrintDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->print_dep, sizeof(msg->print_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_print_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.print_dep, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgPrintDep);
    info.sender_id = 8738;
    info.preamble = 0x55;
    info.crc = 0xf82f;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 42;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_print_dep_t &lesser,
                        const sbp_msg_print_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_print_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_print_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_print_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_print_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgPrintDep, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_lesser, &wrapped_greater), 0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_greater, &wrapped_lesser), 0);

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
  sbp_msg_print_dep_t test_msg_{};
  uint8_t encoded_frame_[42 + 8] = {
      85,  16,  0,  34, 34, 42, 73, 78, 70, 79, 58,  32,  97,
      99,  113, 58, 32, 80, 82, 78, 32, 52, 32, 102, 111, 117,
      110, 100, 32, 64, 32, 45, 55, 52, 57, 50, 32,  72,  122,
      44,  32,  50, 48, 32, 83, 78, 82, 10, 47, 248,
  };
  uint8_t encoded_payload_[42] = {
      73, 78, 70, 79,  58,  32,  97,  99,  113, 58, 32, 80, 82, 78,
      32, 52, 32, 102, 111, 117, 110, 100, 32,  64, 32, 45, 55, 52,
      57, 50, 32, 72,  122, 44,  32,  50,  48,  32, 83, 78, 82, 10,
  };
};

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_print_dep_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgPrintDep, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[42];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_print_dep_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 42);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 42), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgPrintDep,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 42);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 42), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[42];

  EXPECT_EQ(
      sbp_msg_print_dep_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 42), 0);
}
TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[42];

  for (uint8_t i = 0; i < 42; i++) {
    EXPECT_EQ(sbp_msg_print_dep_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_print_dep_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 42);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgPrintDep, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 42);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};

  EXPECT_EQ(sbp_msg_print_dep_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = SBP_MSG_PRINT_DEP_ENCODED_OVERHEAD;
    // size_t overhead = []()->size_t{sbp_msg_print_dep_t t{}; return
    // sbp_msg_print_dep_encoded_len(&t); }();
    if (i >= overhead) {
      expected_return = SBP_OK;
    }

    EXPECT_EQ(
        sbp_msg_print_dep_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4,
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, SlowRead) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, BadCRC) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_print_dep_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_print_dep_t lesser = info.test_msg;
    sbp_msg_print_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.text, greater.text);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::id, SbpMsgPrintDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_print_dep_t>::name, "MSG_PRINT_DEP");
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_print_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_print_dep_t>::get(const_sbp_msg_t);
  sbp_msg_print_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_print_dep_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.print_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.print_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[42];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 42);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 42), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 42);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgPrintDep, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgPrintDep, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_logging_MsgPrintDep4_text
    : public Testauto_check_sbp_logging_MsgPrintDep4 {};

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4_text, StringInit) {
  sbp_msg_print_dep_t t{};
  sbp_msg_print_dep_text_init(&t);
  EXPECT_TRUE(sbp_msg_print_dep_text_valid(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4_text, IsValid) {
  sbp_msg_print_dep_t t{};

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &t, "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n", false, &written));
  EXPECT_EQ(written, strlen("INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&t), 42);
  EXPECT_TRUE(sbp_msg_print_dep_text_valid(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4_text, SpaceRemaining) {
  sbp_msg_print_dep_t t{};
  size_t empty_space_remaining = sbp_msg_print_dep_text_space_remaining(&t);

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &t, "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n", false, &written));
  EXPECT_EQ(written, strlen("INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&t), 42);
  size_t assigned_space_remaining = sbp_msg_print_dep_text_space_remaining(&t);
  EXPECT_LT(assigned_space_remaining, empty_space_remaining);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4_text, SetRaw) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t t{};

  size_t nwritten{};

  EXPECT_TRUE(sbp_msg_print_dep_text_set_raw(
      &t, info.test_msg.text.data,
      sbp_msg_print_dep_text_strlen(&info.test_msg), false, &nwritten));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&info.test_msg),
            sbp_msg_print_dep_text_encoded_len(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4_text, Set) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n";

  EXPECT_TRUE(sbp_msg_print_dep_text_set(&t, text, false, &nwritten));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4_text, Printf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n";

  EXPECT_TRUE(sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", text));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4_text, Vprintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n";

  auto lambda = [&t, &nwritten](const char *format, ...) -> bool {
    va_list ap;
    va_start(ap, format);
    bool ret = sbp_msg_print_dep_text_vprintf(&t, false, &nwritten, format, ap);
    va_end(ap);
    return ret;
  };

  EXPECT_TRUE(lambda("%s", text));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4_text, AppendPrintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  char part1[] = "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n";
  char part2[] = "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n";

  part1[1] = 0;

  EXPECT_TRUE(
      sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", &part1[0]));
  EXPECT_EQ(nwritten, 1);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), &part1[0]);

  EXPECT_TRUE(sbp_msg_print_dep_text_append_printf(&t, false, &nwritten, "%s",
                                                   &part2[1]));
  EXPECT_EQ(nwritten, strlen(&part2[1]));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t),
               "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n");
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep4_text, AppendVprintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  char part1[] = "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n";
  char part2[] = "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n";

  part1[1] = 0;

  EXPECT_TRUE(
      sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", &part1[0]));
  EXPECT_EQ(nwritten, 1);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), &part1[0]);

  auto lambda = [&t, &nwritten](const char *format, ...) -> bool {
    va_list ap;
    va_start(ap, format);
    bool ret =
        sbp_msg_print_dep_text_append_vprintf(&t, false, &nwritten, format, ap);
    va_end(ap);
    return ret;
  };

  EXPECT_TRUE(lambda("%s", &part2[1]));
  EXPECT_EQ(nwritten, strlen(&part2[1]));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t),
               "INFO: acq: PRN 4 found @ -7492 Hz, 20 SNR\n");
}

class Testauto_check_sbp_logging_MsgPrintDep5 : public ::testing::Test {
 public:
  Testauto_check_sbp_logging_MsgPrintDep5() {
    size_t written;
    EXPECT_TRUE(sbp_msg_print_dep_text_set(
        &test_msg_, "INFO: Disabling channel 1 (PRN 15)\n", false, &written));
    EXPECT_EQ(written, strlen("INFO: Disabling channel 1 (PRN 15)\n"));
    EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&test_msg_), 35);
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

  struct CppHandler final : public sbp::MessageHandler<sbp_msg_print_dep_t> {
    using sbp::MessageHandler<sbp_msg_print_dep_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_print_dep_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(uint16_t sender_id,
                        const sbp_msg_print_dep_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgPrintDep, &CHandler::callback_static,
                            this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_print_dep_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgPrintDep);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->print_dep, sizeof(msg->print_dep));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_print_dep_t test_msg;
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
    memcpy(&info.test_msg_wrapped.print_dep, &test_msg_, sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgPrintDep);
    info.sender_id = 8738;
    info.preamble = 0x55;
    info.crc = 0x8b9e;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 35;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_print_dep_t &lesser,
                        const sbp_msg_print_dep_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(greater);

    EXPECT_EQ(sbp_msg_print_dep_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_print_dep_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_print_dep_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_print_dep_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgPrintDep, &wrapped_lesser, &wrapped_lesser),
              0);
    EXPECT_EQ(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_greater, &wrapped_greater), 0);
    EXPECT_LE(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_lesser, &wrapped_greater), 0);
    EXPECT_GT(
        sbp_message_cmp(SbpMsgPrintDep, &wrapped_greater, &wrapped_lesser), 0);

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
  sbp_msg_print_dep_t test_msg_{};
  uint8_t encoded_frame_[35 + 8] = {
      85, 16, 0,   34,  34,  35,  73, 78, 70,  79, 58,  32,  68,  105, 115,
      97, 98, 108, 105, 110, 103, 32, 99, 104, 97, 110, 110, 101, 108, 32,
      49, 32, 40,  80,  82,  78,  32, 49, 53,  41, 10,  158, 139,
  };
  uint8_t encoded_payload_[35] = {
      73,  78,  70,  79, 58, 32,  68, 105, 115, 97,  98,  108,
      105, 110, 103, 32, 99, 104, 97, 110, 110, 101, 108, 32,
      49,  32,  40,  80, 82, 78,  32, 49,  53,  41,  10,
  };
};

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_print_dep_encoded_len(&info.test_msg), info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgPrintDep, &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[35];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_print_dep_encode(&buf[0], sizeof(buf), &n_written,
                                     &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 35);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 35), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written, SbpMsgPrintDep,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 35);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 35), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[35];

  EXPECT_EQ(
      sbp_msg_print_dep_encode(&buf[0], sizeof(buf), nullptr, &info.test_msg),
      SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 35), 0);
}
TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[35];

  for (uint8_t i = 0; i < 35; i++) {
    EXPECT_EQ(sbp_msg_print_dep_encode(&buf[0], i, nullptr, &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_print_dep_decode(&info.encoded_payload[0], info.payload_len,
                                     &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 35);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(sbp_message_decode(&info.encoded_payload[0], info.payload_len,
                               &n_read, SbpMsgPrintDep, &wrapped_msg),
            SBP_OK);
  EXPECT_EQ(n_read, 35);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};

  EXPECT_EQ(sbp_msg_print_dep_decode(&info.encoded_payload[0], info.payload_len,
                                     nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = SBP_MSG_PRINT_DEP_ENCODED_OVERHEAD;
    // size_t overhead = []()->size_t{sbp_msg_print_dep_t t{}; return
    // sbp_msg_print_dep_encoded_len(&t); }();
    if (i >= overhead) {
      expected_return = SBP_OK;
    }

    EXPECT_EQ(
        sbp_msg_print_dep_decode(&info.encoded_payload[0], i, nullptr, &msg),
        expected_return);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, ReceiveThroughSbpState) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5,
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, SlowRead) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, BadCRC) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_print_dep_send(&state, info.sender_id, &info.test_msg,
                                   &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                             &info.test_msg_wrapped, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                               &info.test_msg_wrapped, &Writer::write_c),
              SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_message_send(&state, SbpMsgPrintDep, info.sender_id,
                             &info.test_msg_wrapped, &SlowWriter::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, Comparison) {
  auto info = get_test_msg_info();
  {
    sbp_msg_print_dep_t lesser = info.test_msg;
    sbp_msg_print_dep_t greater = info.test_msg;
    make_lesser_greater(lesser.text, greater.text);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::id, SbpMsgPrintDep);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_print_dep_t>::name, "MSG_PRINT_DEP");
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_print_dep_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_print_dep_t>::get(const_sbp_msg_t);
  sbp_msg_print_dep_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_print_dep_t>::get(non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(info.test_msg);
  EXPECT_EQ(msg1.print_dep, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_print_dep_t>::to_sbp_msg(info.test_msg, &msg2);
  EXPECT_EQ(msg2.print_dep, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::encoded_len(info.test_msg),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[35];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 35);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 35), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_print_dep_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 35);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, ReceiveThroughMessageHandler) {
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

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgPrintDep, &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5, SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(
      state.send_message(info.sender_id, SbpMsgPrintDep, info.test_msg_wrapped),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

class Testauto_check_sbp_logging_MsgPrintDep5_text
    : public Testauto_check_sbp_logging_MsgPrintDep5 {};

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5_text, StringInit) {
  sbp_msg_print_dep_t t{};
  sbp_msg_print_dep_text_init(&t);
  EXPECT_TRUE(sbp_msg_print_dep_text_valid(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5_text, IsValid) {
  sbp_msg_print_dep_t t{};

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &t, "INFO: Disabling channel 1 (PRN 15)\n", false, &written));
  EXPECT_EQ(written, strlen("INFO: Disabling channel 1 (PRN 15)\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&t), 35);
  EXPECT_TRUE(sbp_msg_print_dep_text_valid(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5_text, SpaceRemaining) {
  sbp_msg_print_dep_t t{};
  size_t empty_space_remaining = sbp_msg_print_dep_text_space_remaining(&t);

  size_t written;
  EXPECT_TRUE(sbp_msg_print_dep_text_set(
      &t, "INFO: Disabling channel 1 (PRN 15)\n", false, &written));
  EXPECT_EQ(written, strlen("INFO: Disabling channel 1 (PRN 15)\n"));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&t), 35);
  size_t assigned_space_remaining = sbp_msg_print_dep_text_space_remaining(&t);
  EXPECT_LT(assigned_space_remaining, empty_space_remaining);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5_text, SetRaw) {
  auto info = get_test_msg_info();
  sbp_msg_print_dep_t t{};

  size_t nwritten{};

  EXPECT_TRUE(sbp_msg_print_dep_text_set_raw(
      &t, info.test_msg.text.data,
      sbp_msg_print_dep_text_strlen(&info.test_msg), false, &nwritten));
  EXPECT_EQ(sbp_msg_print_dep_text_encoded_len(&info.test_msg),
            sbp_msg_print_dep_text_encoded_len(&t));
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5_text, Set) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: Disabling channel 1 (PRN 15)\n";

  EXPECT_TRUE(sbp_msg_print_dep_text_set(&t, text, false, &nwritten));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5_text, Printf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: Disabling channel 1 (PRN 15)\n";

  EXPECT_TRUE(sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", text));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5_text, Vprintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  const char *text = "INFO: Disabling channel 1 (PRN 15)\n";

  auto lambda = [&t, &nwritten](const char *format, ...) -> bool {
    va_list ap;
    va_start(ap, format);
    bool ret = sbp_msg_print_dep_text_vprintf(&t, false, &nwritten, format, ap);
    va_end(ap);
    return ret;
  };

  EXPECT_TRUE(lambda("%s", text));
  EXPECT_EQ(nwritten, strlen(text));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), text);
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5_text, AppendPrintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  char part1[] = "INFO: Disabling channel 1 (PRN 15)\n";
  char part2[] = "INFO: Disabling channel 1 (PRN 15)\n";

  part1[1] = 0;

  EXPECT_TRUE(
      sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", &part1[0]));
  EXPECT_EQ(nwritten, 1);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), &part1[0]);

  EXPECT_TRUE(sbp_msg_print_dep_text_append_printf(&t, false, &nwritten, "%s",
                                                   &part2[1]));
  EXPECT_EQ(nwritten, strlen(&part2[1]));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t),
               "INFO: Disabling channel 1 (PRN 15)\n");
}

TEST_F(Testauto_check_sbp_logging_MsgPrintDep5_text, AppendVprintf) {
  sbp_msg_print_dep_t t{};
  size_t nwritten{};
  char part1[] = "INFO: Disabling channel 1 (PRN 15)\n";
  char part2[] = "INFO: Disabling channel 1 (PRN 15)\n";

  part1[1] = 0;

  EXPECT_TRUE(
      sbp_msg_print_dep_text_printf(&t, false, &nwritten, "%s", &part1[0]));
  EXPECT_EQ(nwritten, 1);
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t), &part1[0]);

  auto lambda = [&t, &nwritten](const char *format, ...) -> bool {
    va_list ap;
    va_start(ap, format);
    bool ret =
        sbp_msg_print_dep_text_append_vprintf(&t, false, &nwritten, format, ap);
    va_end(ap);
    return ret;
  };

  EXPECT_TRUE(lambda("%s", &part2[1]));
  EXPECT_EQ(nwritten, strlen(&part2[1]));
  EXPECT_STREQ(sbp_msg_print_dep_text_get(&t),
               "INFO: Disabling channel 1 (PRN 15)\n");
}

}  // namespace