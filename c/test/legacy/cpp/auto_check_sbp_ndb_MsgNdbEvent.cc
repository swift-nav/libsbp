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
// spec/tests/yaml/swiftnav/sbp/ndb/test_MsgNdbEvent.yaml by generate.py. Do not
// modify by hand!

#include <gtest/gtest.h>

#include <libsbp/common.h>

// Obviously we don't normally want to silence this message, but we also need to
// still test the legacy implementation for as long as it exists. By silencing
// these messages here we can get a less noisy build in libsbp
#ifdef SBP_MESSAGE
#undef SBP_MESSAGE
#define SBP_MESSAGE(x)
#endif
#include <libsbp/legacy/cpp/legacy_state.h>
#include <libsbp/legacy/cpp/message_traits.h>
#include <libsbp/legacy/cpp/payload_handler.h>
#include <libsbp/legacy/ndb.h>

template <typename T, typename U = std::remove_reference_t<T>>
U get_as(const uint8_t *buf) {
  U v;
  memcpy(&v, buf, sizeof(T));
  return v;
}
class Test_legacy_auto_check_sbp_ndb_MsgNdbEvent0
    : public ::testing::Test,
      public sbp::LegacyState,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_ndb_event_t> {
 public:
  Test_legacy_auto_check_sbp_ndb_MsgNdbEvent0()
      : ::testing::Test(),
        sbp::LegacyState(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_ndb_event_t>(this),
        last_msg_storage_(),
        last_msg_(reinterpret_cast<msg_ndb_event_t *>(last_msg_storage_)),
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
                      const msg_ndb_event_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_ndb_event_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_ndb_MsgNdbEvent0, Test) {
  uint8_t encoded_frame[] = {
      85, 0,   4,  164, 174, 18,  254, 188, 70, 185, 69,  0,  0,
      0,  249, 73, 205, 115, 238, 74,  98,  66, 182, 148, 16, 166,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_ndb_event_t *test_msg = (msg_ndb_event_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->data_source = 115;
  test_msg->event = 249;
  test_msg->object_sid.code = 74;
  test_msg->object_sid.sat = 238;
  test_msg->object_type = 73;
  test_msg->original_sender = 38070;
  test_msg->recv_time = 299461164286;
  test_msg->result = 205;
  test_msg->src_sid.code = 66;
  test_msg->src_sid.sat = 98;

  EXPECT_EQ(send_message(0x400, 44708, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 44708);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(get_as<decltype(last_msg_->data_source)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->data_source)),
            115)
      << "incorrect value for data_source, expected 115, is "
      << last_msg_->data_source;
  EXPECT_EQ(get_as<decltype(last_msg_->event)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->event)),
            249)
      << "incorrect value for event, expected 249, is " << last_msg_->event;
  EXPECT_EQ(get_as<decltype(last_msg_->object_sid.code)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->object_sid.code)),
            74)
      << "incorrect value for object_sid.code, expected 74, is "
      << last_msg_->object_sid.code;
  EXPECT_EQ(get_as<decltype(last_msg_->object_sid.sat)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->object_sid.sat)),
            238)
      << "incorrect value for object_sid.sat, expected 238, is "
      << last_msg_->object_sid.sat;
  EXPECT_EQ(get_as<decltype(last_msg_->object_type)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->object_type)),
            73)
      << "incorrect value for object_type, expected 73, is "
      << last_msg_->object_type;
  EXPECT_EQ(get_as<decltype(last_msg_->original_sender)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->original_sender)),
            38070)
      << "incorrect value for original_sender, expected 38070, is "
      << last_msg_->original_sender;
  EXPECT_EQ(get_as<decltype(last_msg_->recv_time)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->recv_time)),
            299461164286)
      << "incorrect value for recv_time, expected 299461164286, is "
      << last_msg_->recv_time;
  EXPECT_EQ(get_as<decltype(last_msg_->result)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->result)),
            205)
      << "incorrect value for result, expected 205, is " << last_msg_->result;
  EXPECT_EQ(get_as<decltype(last_msg_->src_sid.code)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->src_sid.code)),
            66)
      << "incorrect value for src_sid.code, expected 66, is "
      << last_msg_->src_sid.code;
  EXPECT_EQ(get_as<decltype(last_msg_->src_sid.sat)>(
                reinterpret_cast<const uint8_t *>(&last_msg_->src_sid.sat)),
            98)
      << "incorrect value for src_sid.sat, expected 98, is "
      << last_msg_->src_sid.sat;
}
