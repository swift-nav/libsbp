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
// spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingResourceCounter.yaml
// by generate.py. Do not modify by hand!

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
class Testauto_check_sbp_profiling_MsgProfilingResourceCounter0
    : public ::testing::Test {
 public:
  Testauto_check_sbp_profiling_MsgProfilingResourceCounter0() {
    assign(test_msg_.buckets[0].cv, 2);
    assign(test_msg_.buckets[0].heap_bytes_alloc, 927480);
    assign(test_msg_.buckets[0].heap_bytes_free, 0);
    assign(test_msg_.buckets[0].io, 0);
    assign(test_msg_.buckets[0].io_read, 0);
    assign(test_msg_.buckets[0].io_write, 0);
    assign(test_msg_.buckets[0].mutex, 2);
    {
      const char assign_string[] = {
          (char)70,  (char)117, (char)115, (char)105, (char)111, (char)110,
          (char)32,  (char)101, (char)110, (char)103, (char)105, (char)110,
          (char)101, (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0};
      memcpy(test_msg_.buckets[0].name, assign_string, sizeof(assign_string));
    }
    assign(test_msg_.buckets[0].thread, 1);

    assign(test_msg_.buckets[1].cv, 1);
    assign(test_msg_.buckets[1].heap_bytes_alloc, 84454);
    assign(test_msg_.buckets[1].heap_bytes_free, 0);
    assign(test_msg_.buckets[1].io, 1);
    assign(test_msg_.buckets[1].io_read, 19520);
    assign(test_msg_.buckets[1].io_write, 879);
    assign(test_msg_.buckets[1].mutex, 1);
    {
      const char assign_string[] = {
          (char)78, (char)84,  (char)82,  (char)73,  (char)80,  (char)32,
          (char)99, (char)108, (char)105, (char)101, (char)110, (char)116,
          (char)0,  (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,  (char)0,   (char)0};
      memcpy(test_msg_.buckets[1].name, assign_string, sizeof(assign_string));
    }
    assign(test_msg_.buckets[1].thread, 1);

    assign(test_msg_.buckets[2].cv, 1);
    assign(test_msg_.buckets[2].heap_bytes_alloc, 4328776);
    assign(test_msg_.buckets[2].heap_bytes_free, 0);
    assign(test_msg_.buckets[2].io, 0);
    assign(test_msg_.buckets[2].io_read, 0);
    assign(test_msg_.buckets[2].io_write, 0);
    assign(test_msg_.buckets[2].mutex, 1);
    {
      const char assign_string[] = {
          (char)83, (char)83, (char)82, (char)50, (char)79, (char)83, (char)82,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,
          (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0,  (char)0};
      memcpy(test_msg_.buckets[2].name, assign_string, sizeof(assign_string));
    }
    assign(test_msg_.buckets[2].thread, 1);

    assign(test_msg_.buckets[3].cv, 1);
    assign(test_msg_.buckets[3].heap_bytes_alloc, 247112);
    assign(test_msg_.buckets[3].heap_bytes_free, 0);
    assign(test_msg_.buckets[3].io, 0);
    assign(test_msg_.buckets[3].io_read, 0);
    assign(test_msg_.buckets[3].io_write, 0);
    assign(test_msg_.buckets[3].mutex, 2);
    {
      const char assign_string[] = {
          (char)80,  (char)101, (char)114, (char)105, (char)111, (char)100,
          (char)105, (char)99,  (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0,   (char)0,   (char)0,   (char)0,
          (char)0,   (char)0,   (char)0};
      memcpy(test_msg_.buckets[3].name, assign_string, sizeof(assign_string));
    }
    assign(test_msg_.buckets[3].thread, 1);

    assign(test_msg_.buckets[4].cv, 1);
    assign(test_msg_.buckets[4].heap_bytes_alloc, 18305);
    assign(test_msg_.buckets[4].heap_bytes_free, 0);
    assign(test_msg_.buckets[4].io, 1);
    assign(test_msg_.buckets[4].io_read, 26207);
    assign(test_msg_.buckets[4].io_write, 0);
    assign(test_msg_.buckets[4].mutex, 1);
    {
      const char assign_string[] = {
          (char)73, (char)77, (char)85, (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0,
          (char)0,  (char)0,  (char)0,  (char)0, (char)0, (char)0, (char)0};
      memcpy(test_msg_.buckets[4].name, assign_string, sizeof(assign_string));
    }
    assign(test_msg_.buckets[4].thread, 1);

    assign(test_msg_.buckets[5].cv, 2);
    assign(test_msg_.buckets[5].heap_bytes_alloc, 43507);
    assign(test_msg_.buckets[5].heap_bytes_free, 0);
    assign(test_msg_.buckets[5].io, 2);
    assign(test_msg_.buckets[5].io_read, 498);
    assign(test_msg_.buckets[5].io_write, 235451);
    assign(test_msg_.buckets[5].mutex, 2);
    {
      const char assign_string[] = {
          (char)115, (char)98, (char)112, (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0,
          (char)0,   (char)0,  (char)0,   (char)0, (char)0, (char)0, (char)0};
      memcpy(test_msg_.buckets[5].name, assign_string, sizeof(assign_string));
    }
    assign(test_msg_.buckets[5].thread, 5);
    assign(test_msg_.n_buckets, 6);
    assign(test_msg_.seq_len, 3);
    assign(test_msg_.seq_no, 1);
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
      : public sbp::MessageHandler<sbp_msg_profiling_resource_counter_t> {
    using sbp::MessageHandler<
        sbp_msg_profiling_resource_counter_t>::MessageHandler;

    struct Output final {
      uint16_t sender_id;
      sbp_msg_profiling_resource_counter_t msg;
    };

    std::vector<Output> outputs{};

   protected:
    void handle_sbp_msg(
        uint16_t sender_id,
        const sbp_msg_profiling_resource_counter_t &msg) override {
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg, sizeof(msg));
    }
  };

  struct CHandler final {
    explicit CHandler(sbp_state_t *state) : state_{state} {
      sbp_callback_register(state, SbpMsgProfilingResourceCounter,
                            &CHandler::callback_static, this, &node_);
    }

    ~CHandler() { sbp_remove_callback(state_, &node_); }

    struct Output final {
      uint16_t sender_id;
      sbp_msg_profiling_resource_counter_t msg;
    };

    std::vector<Output> outputs{};

   private:
    void callback(uint16_t sender_id, sbp_msg_type_t msg_type,
                  const sbp_msg_t *msg) {
      ASSERT_EQ(msg_type, SbpMsgProfilingResourceCounter);
      outputs.emplace_back();
      outputs.back().sender_id = sender_id;
      memcpy(&outputs.back().msg, &msg->profiling_resource_counter,
             sizeof(msg->profiling_resource_counter));
    }

    static void callback_static(uint16_t sender_id, sbp_msg_type_t msg_type,
                                const sbp_msg_t *msg, void *ctx) {
      static_cast<CHandler *>(ctx)->callback(sender_id, msg_type, msg);
    }

    sbp_msg_callbacks_node_t node_{};
    sbp_state_t *state_;
  };

  struct TestMsgInfo {
    sbp_msg_profiling_resource_counter_t test_msg;
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
    memcpy(&info.test_msg_wrapped.profiling_resource_counter, &test_msg_,
           sizeof(test_msg_));
    info.msg_type = static_cast<sbp_msg_type_t>(SbpMsgProfilingResourceCounter);
    info.sender_id = 4096;
    info.preamble = 0x55;
    info.crc = 0x99b5;
    info.encoded_frame = encoded_frame_;
    info.frame_len = sizeof(encoded_frame_);
    info.encoded_payload = encoded_payload_;
    info.payload_len = 248;

    return info;
  }

 protected:
  void comparison_tests(const sbp_msg_profiling_resource_counter_t &lesser,
                        const sbp_msg_profiling_resource_counter_t &greater) {
    sbp_msg_t wrapped_lesser =
        sbp::MessageTraits<sbp_msg_profiling_resource_counter_t>::to_sbp_msg(
            lesser);
    sbp_msg_t wrapped_greater =
        sbp::MessageTraits<sbp_msg_profiling_resource_counter_t>::to_sbp_msg(
            greater);

    EXPECT_EQ(sbp_msg_profiling_resource_counter_cmp(&lesser, &lesser), 0);
    EXPECT_EQ(sbp_msg_profiling_resource_counter_cmp(&greater, &greater), 0);
    EXPECT_LE(sbp_msg_profiling_resource_counter_cmp(&lesser, &greater), 0);
    EXPECT_GT(sbp_msg_profiling_resource_counter_cmp(&greater, &lesser), 0);

    EXPECT_EQ(sbp_message_cmp(SbpMsgProfilingResourceCounter, &wrapped_lesser,
                              &wrapped_lesser),
              0);
    EXPECT_EQ(sbp_message_cmp(SbpMsgProfilingResourceCounter, &wrapped_greater,
                              &wrapped_greater),
              0);
    EXPECT_LE(sbp_message_cmp(SbpMsgProfilingResourceCounter, &wrapped_lesser,
                              &wrapped_greater),
              0);
    EXPECT_GT(sbp_message_cmp(SbpMsgProfilingResourceCounter, &wrapped_greater,
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
  sbp_msg_profiling_resource_counter_t test_msg_{};
  uint8_t encoded_frame_[248 + 8] = {
      85,  3,   207, 0,   16,  248, 1,   3,   70, 117, 115, 105, 111, 110, 32,
      101, 110, 103, 105, 110, 101, 0,   0,   0,  0,   0,   0,   0,   0,   1,
      2,   2,   0,   248, 38,  14,  0,   0,   0,  0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   78,  84,  82,  73,  80, 32,  99,  108, 105, 101, 110,
      116, 0,   0,   0,   0,   0,   0,   0,   0,  0,   1,   1,   1,   1,   230,
      73,  1,   0,   0,   0,   0,   0,   111, 3,  0,   0,   64,  76,  0,   0,
      83,  83,  82,  50,  79,  83,  82,  0,   0,  0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   1,   1,   1,  0,   72,  13,  66,  0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,   80,  101, 114, 105,
      111, 100, 105, 99,  0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,
      0,   0,   1,   2,   1,   0,   72,  197, 3,  0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   73,  77, 85,  0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   1,   1,
      1,   1,   129, 71,  0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   95,
      102, 0,   0,   115, 98,  112, 0,   0,   0,  0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,  5,   2,   2,   2,   243, 169,
      0,   0,   0,   0,   0,   0,   187, 151, 3,  0,   242, 1,   0,   0,   181,
      153,
  };
  uint8_t encoded_payload_[248] = {
      1,   3,   70, 117, 115, 105, 111, 110, 32,  101, 110, 103, 105, 110, 101,
      0,   0,   0,  0,   0,   0,   0,   0,   1,   2,   2,   0,   248, 38,  14,
      0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   78,  84,
      82,  73,  80, 32,  99,  108, 105, 101, 110, 116, 0,   0,   0,   0,   0,
      0,   0,   0,  0,   1,   1,   1,   1,   230, 73,  1,   0,   0,   0,   0,
      0,   111, 3,  0,   0,   64,  76,  0,   0,   83,  83,  82,  50,  79,  83,
      82,  0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      1,   1,   1,  0,   72,  13,  66,  0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,  0,   0,   80,  101, 114, 105, 111, 100, 105, 99,  0,   0,
      0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   1,   2,   1,   0,
      72,  197, 3,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   73,  77, 85,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,  0,   0,   0,   0,   1,   1,   1,   1,   129, 71,  0,   0,
      0,   0,   0,  0,   0,   0,   0,   0,   95,  102, 0,   0,   115, 98,  112,
      0,   0,   0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,  5,   2,   2,   2,   243, 169, 0,   0,   0,   0,   0,   0,
      187, 151, 3,  0,   242, 1,   0,   0,
  };
};

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0, EncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(sbp_msg_profiling_resource_counter_encoded_len(&info.test_msg),
            info.payload_len);

  EXPECT_EQ(sbp_message_encoded_len(SbpMsgProfilingResourceCounter,
                                    &info.test_msg_wrapped),
            info.payload_len);
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0, EncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[248];
  uint8_t n_written;

  EXPECT_EQ(sbp_msg_profiling_resource_counter_encode(
                &buf[0], sizeof(buf), &n_written, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 248);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 248), 0);

  memset(&buf[0], 0, sizeof(buf));
  EXPECT_EQ(sbp_message_encode(&buf[0], sizeof(buf), &n_written,
                               SbpMsgProfilingResourceCounter,
                               &info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(n_written, 248);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 248), 0);
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       EncodeToBufWithoutNwritten) {
  auto info = get_test_msg_info();
  uint8_t buf[248];

  EXPECT_EQ(sbp_msg_profiling_resource_counter_encode(&buf[0], sizeof(buf),
                                                      nullptr, &info.test_msg),
            SBP_OK);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 248), 0);
}
TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       EncodedToBufUnderflow) {
  auto info = get_test_msg_info();
  uint8_t buf[248];

  for (uint8_t i = 0; i < 248; i++) {
    EXPECT_EQ(sbp_msg_profiling_resource_counter_encode(&buf[0], i, nullptr,
                                                        &info.test_msg),
              SBP_ENCODE_ERROR);
  }
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       DecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_profiling_resource_counter_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp_msg_profiling_resource_counter_decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 248);
  EXPECT_EQ(msg, info.test_msg);

  sbp_msg_t wrapped_msg{};
  EXPECT_EQ(
      sbp_message_decode(&info.encoded_payload[0], info.payload_len, &n_read,
                         SbpMsgProfilingResourceCounter, &wrapped_msg),
      SBP_OK);
  EXPECT_EQ(n_read, 248);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       DecodeFromBufWithoutNread) {
  auto info = get_test_msg_info();
  sbp_msg_profiling_resource_counter_t msg{};

  EXPECT_EQ(sbp_msg_profiling_resource_counter_decode(
                &info.encoded_payload[0], info.payload_len, nullptr, &msg),
            SBP_OK);
  EXPECT_EQ(msg, info.test_msg);
}
TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       DecodeFromBufUnderflow) {
  auto info = get_test_msg_info();
  sbp_msg_profiling_resource_counter_t msg{};

  for (uint8_t i = 0; i < info.payload_len; i++) {
    int expected_return = SBP_DECODE_ERROR;
    size_t overhead = []() -> size_t {
      sbp_msg_profiling_resource_counter_t t{};
      return sbp_msg_profiling_resource_counter_encoded_len(&t);
    }();
    size_t elem_size = []() -> size_t {
      sbp_msg_profiling_resource_counter_t t{};
      t.n_buckets = 1;
      return sbp_msg_profiling_resource_counter_encoded_len(&t);
    }() - overhead;

    if (i >= overhead) {
      if (((i - overhead) % elem_size) == 0) {
        expected_return = SBP_OK;
      }
    }

    EXPECT_EQ(sbp_msg_profiling_resource_counter_decode(
                  &info.encoded_payload[0], i, nullptr, &msg),
              expected_return);
  }
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
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

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
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

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0, SlowRead) {
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

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0, BadCRC) {
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

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       SendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp_msg_profiling_resource_counter_send(
                &state, info.sender_id, &info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       SendWrappedThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgProfilingResourceCounter, info.sender_id,
                       &info.test_msg_wrapped, &Writer::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       SendThroughSbpStateUnderflow) {
  auto info = get_test_msg_info();

  for (uint32_t i = 0; i < info.frame_len; i++) {
    sbp_state_t state;
    sbp_state_init(&state);

    auto writer = info.get_frame_writer(i);
    sbp_state_set_io_context(&state, &writer);

    EXPECT_NE(
        sbp_message_send(&state, SbpMsgProfilingResourceCounter, info.sender_id,
                         &info.test_msg_wrapped, &Writer::write_c),
        SBP_OK);
    EXPECT_EQ(writer.len(), i);
    EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, i), 0);
  }
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       DISABLED_SlowWrite) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_slow_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(
      sbp_message_send(&state, SbpMsgProfilingResourceCounter, info.sender_id,
                       &info.test_msg_wrapped, &SlowWriter::write_c),
      SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0, Comparison) {
  auto info = get_test_msg_info();

  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[0].cv, greater.buckets[0].cv);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[0].heap_bytes_alloc,
                        greater.buckets[0].heap_bytes_alloc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[0].heap_bytes_free,
                        greater.buckets[0].heap_bytes_free);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[0].io, greater.buckets[0].io);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[0].io_read, greater.buckets[0].io_read);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[0].io_write,
                        greater.buckets[0].io_write);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[0].mutex, greater.buckets[0].mutex);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[0].name, greater.buckets[0].name);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[0].thread, greater.buckets[0].thread);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[1].cv, greater.buckets[1].cv);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[1].heap_bytes_alloc,
                        greater.buckets[1].heap_bytes_alloc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[1].heap_bytes_free,
                        greater.buckets[1].heap_bytes_free);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[1].io, greater.buckets[1].io);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[1].io_read, greater.buckets[1].io_read);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[1].io_write,
                        greater.buckets[1].io_write);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[1].mutex, greater.buckets[1].mutex);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[1].name, greater.buckets[1].name);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[1].thread, greater.buckets[1].thread);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[2].cv, greater.buckets[2].cv);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[2].heap_bytes_alloc,
                        greater.buckets[2].heap_bytes_alloc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[2].heap_bytes_free,
                        greater.buckets[2].heap_bytes_free);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[2].io, greater.buckets[2].io);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[2].io_read, greater.buckets[2].io_read);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[2].io_write,
                        greater.buckets[2].io_write);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[2].mutex, greater.buckets[2].mutex);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[2].name, greater.buckets[2].name);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[2].thread, greater.buckets[2].thread);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[3].cv, greater.buckets[3].cv);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[3].heap_bytes_alloc,
                        greater.buckets[3].heap_bytes_alloc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[3].heap_bytes_free,
                        greater.buckets[3].heap_bytes_free);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[3].io, greater.buckets[3].io);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[3].io_read, greater.buckets[3].io_read);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[3].io_write,
                        greater.buckets[3].io_write);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[3].mutex, greater.buckets[3].mutex);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[3].name, greater.buckets[3].name);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[3].thread, greater.buckets[3].thread);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[4].cv, greater.buckets[4].cv);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[4].heap_bytes_alloc,
                        greater.buckets[4].heap_bytes_alloc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[4].heap_bytes_free,
                        greater.buckets[4].heap_bytes_free);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[4].io, greater.buckets[4].io);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[4].io_read, greater.buckets[4].io_read);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[4].io_write,
                        greater.buckets[4].io_write);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[4].mutex, greater.buckets[4].mutex);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[4].name, greater.buckets[4].name);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[4].thread, greater.buckets[4].thread);
    comparison_tests(lesser, greater);
  }

  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[5].cv, greater.buckets[5].cv);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[5].heap_bytes_alloc,
                        greater.buckets[5].heap_bytes_alloc);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[5].heap_bytes_free,
                        greater.buckets[5].heap_bytes_free);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[5].io, greater.buckets[5].io);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[5].io_read, greater.buckets[5].io_read);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[5].io_write,
                        greater.buckets[5].io_write);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[5].mutex, greater.buckets[5].mutex);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[5].name, greater.buckets[5].name);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.buckets[5].thread, greater.buckets[5].thread);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.n_buckets, greater.n_buckets);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.seq_len, greater.seq_len);
    comparison_tests(lesser, greater);
  }
  {
    sbp_msg_profiling_resource_counter_t lesser = info.test_msg;
    sbp_msg_profiling_resource_counter_t greater = info.test_msg;
    make_lesser_greater(lesser.seq_no, greater.seq_no);
    comparison_tests(lesser, greater);
  }
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       CppTraitsProperties) {
  // EXPECT_EQ(sbp::MessageTraits<sbp_msg_profiling_resource_counter_t>::id,
  // SbpMsgProfilingResourceCounter);
  EXPECT_STREQ(sbp::MessageTraits<sbp_msg_profiling_resource_counter_t>::name,
               "MSG_PROFILING_RESOURCE_COUNTER");
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       CppTraitsFromSbpMsgT) {
  auto info = get_test_msg_info();

  const sbp_msg_t &const_sbp_msg_t = info.test_msg_wrapped;
  sbp_msg_t &non_const_sbp_msg_t = info.test_msg_wrapped;

  const sbp_msg_profiling_resource_counter_t &const_unwrapped =
      sbp::MessageTraits<sbp_msg_profiling_resource_counter_t>::get(
          const_sbp_msg_t);
  sbp_msg_profiling_resource_counter_t &non_const_unwrapped =
      sbp::MessageTraits<sbp_msg_profiling_resource_counter_t>::get(
          non_const_sbp_msg_t);

  EXPECT_EQ((const void *)&const_sbp_msg_t, (const void *)&const_unwrapped);
  EXPECT_EQ((void *)&non_const_sbp_msg_t, (void *)&non_const_unwrapped);
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       CppTraitsToSbpMsgT) {
  auto info = get_test_msg_info();

  sbp_msg_t msg1 =
      sbp::MessageTraits<sbp_msg_profiling_resource_counter_t>::to_sbp_msg(
          info.test_msg);
  EXPECT_EQ(msg1.profiling_resource_counter, info.test_msg);

  sbp_msg_t msg2;
  sbp::MessageTraits<sbp_msg_profiling_resource_counter_t>::to_sbp_msg(
      info.test_msg, &msg2);
  EXPECT_EQ(msg2.profiling_resource_counter, info.test_msg);
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       CppTraitsEncodedLen) {
  auto info = get_test_msg_info();
  EXPECT_EQ(
      sbp::MessageTraits<sbp_msg_profiling_resource_counter_t>::encoded_len(
          info.test_msg),
      info.payload_len);
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       CppTraitsSendThroughSbpState) {
  auto info = get_test_msg_info();
  sbp_state_t state;
  sbp_state_init(&state);

  auto writer = info.get_frame_writer();
  sbp_state_set_io_context(&state, &writer);

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_profiling_resource_counter_t>::send(
                &state, info.sender_id, info.test_msg, &Writer::write_c),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), &info.encoded_frame[0], writer.len()), 0);
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       CppTraitsEncodeToBuf) {
  auto info = get_test_msg_info();
  uint8_t buf[248];
  uint8_t n_written;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_profiling_resource_counter_t>::encode(
                &buf[0], sizeof(buf), &n_written, info.test_msg),
            SBP_OK);
  EXPECT_EQ(n_written, 248);
  EXPECT_EQ(memcmp(&buf[0], info.encoded_payload, 248), 0);
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       CppTraitsDecodeFromBuf) {
  auto info = get_test_msg_info();
  sbp_msg_profiling_resource_counter_t msg{};
  uint8_t n_read;

  EXPECT_EQ(sbp::MessageTraits<sbp_msg_profiling_resource_counter_t>::decode(
                &info.encoded_payload[0], info.payload_len, &n_read, &msg),
            SBP_OK);
  EXPECT_EQ(n_read, 248);
  EXPECT_EQ(msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
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

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       ProcessSbpMsgTThroughMessageHandler) {
  auto info = get_test_msg_info();
  sbp::State state{};
  CppHandler handler(&state);

  state.process_message(info.sender_id, SbpMsgProfilingResourceCounter,
                        &info.test_msg_wrapped);

  EXPECT_EQ(handler.outputs.size(), 1);
  EXPECT_EQ(handler.outputs[0].sender_id, info.sender_id);
  EXPECT_EQ(handler.outputs[0].msg, info.test_msg);
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       SendThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, info.test_msg), SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

TEST_F(Testauto_check_sbp_profiling_MsgProfilingResourceCounter0,
       SendWrappedSbpMsgTThroughCppState) {
  auto info = get_test_msg_info();
  auto writer = info.get_frame_writer();

  sbp::State state{};
  state.set_writer(&writer);

  EXPECT_EQ(state.send_message(info.sender_id, SbpMsgProfilingResourceCounter,
                               info.test_msg_wrapped),
            SBP_OK);
  EXPECT_EQ(writer.len(), info.frame_len);
  EXPECT_EQ(memcmp(writer.data(), info.encoded_frame, info.frame_len), 0);
}

}  // namespace