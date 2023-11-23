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
// spec/tests/yaml/swiftnav/sbp/file_io/test_MsgFileioReadReq.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>

#include <libsbp/common.h>
#include <libsbp/cpp/state.h>

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/file_io.h>
class Test_legacy_auto_check_sbp_file_io_MsgFileioReadReq0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_fileio_read_req_t> {
 public:
  Test_legacy_auto_check_sbp_file_io_MsgFileioReadReq0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_fileio_read_req_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_fileio_read_req_t *>(last_msg_storage_)),
        last_msg_len_(),
        last_sender_id_(),
        n_callbacks_logged_(),
        dummy_wr_(),
        dummy_rd_(),
        dummy_buff_() {
    set_reader(this);
    set_writer(this);
  }

  s32 read(uint8_t *buf, const uint32_t n) override {
    uint32_t real_n = n;
    memcpy(buf, dummy_buff_ + dummy_rd_, real_n);
    dummy_rd_ += real_n;
    return (s32)real_n;
  }

  s32 write(const uint8_t *buf, uint32_t n) override {
    uint32_t real_n = n;
    memcpy(dummy_buff_ + dummy_wr_, buf, real_n);
    dummy_wr_ += real_n;
    return (s32)real_n;
  }

 protected:
  void handle_sbp_msg(uint16_t sender_id, uint8_t message_length,
                      const msg_fileio_read_req_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_fileio_read_req_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_file_io_MsgFileioReadReq0, Test) {
  uint8_t encoded_frame[] = {
      85,  168, 0,   195, 4,   28,  34,  156, 130, 40,  98,  178,
      190, 23,  53,  47,  112, 97,  116, 104, 47,  116, 111, 47,
      115, 111, 109, 101, 47,  102, 105, 108, 101, 0,   86,  100,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_fileio_read_req_t *test_msg = (msg_fileio_read_req_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->chunk_size = 53;
  {
    const char assign_string[] = {(char)47,  (char)112, (char)97,  (char)116,
                                  (char)104, (char)47,  (char)116, (char)111,
                                  (char)47,  (char)115, (char)111, (char)109,
                                  (char)101, (char)47,  (char)102, (char)105,
                                  (char)108, (char)101, (char)0};
    memcpy(test_msg->filename, assign_string, sizeof(assign_string));
    if (sizeof(test_msg->filename) == 0) {
      test_msg_len = (uint8_t)(test_msg_len + sizeof(assign_string));
    }
  }
  test_msg->offset = 398373474;
  test_msg->sequence = 679648290;

  EXPECT_EQ(send_message(0xa8, 1219, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 1219);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->chunk_size, 53)
      << "incorrect value for chunk_size, expected 53, is "
      << last_msg_->chunk_size;
  {
    const char check_string[] = {(char)47,  (char)112, (char)97,  (char)116,
                                 (char)104, (char)47,  (char)116, (char)111,
                                 (char)47,  (char)115, (char)111, (char)109,
                                 (char)101, (char)47,  (char)102, (char)105,
                                 (char)108, (char)101, (char)0};
    EXPECT_EQ(memcmp(last_msg_->filename, check_string, sizeof(check_string)),
              0)
        << "incorrect value for last_msg_->filename, expected string '"
        << check_string << "', is '" << last_msg_->filename << "'";
  }
  EXPECT_EQ(last_msg_->offset, 398373474)
      << "incorrect value for offset, expected 398373474, is "
      << last_msg_->offset;
  EXPECT_EQ(last_msg_->sequence, 679648290)
      << "incorrect value for sequence, expected 679648290, is "
      << last_msg_->sequence;
}
