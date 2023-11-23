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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgProtectionLevel.yaml by
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
#include <libsbp/legacy/navigation.h>
class Test_legacy_auto_check_sbp_navigation_MsgProtectionLevel0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::PayloadHandler<msg_protection_level_t> {
 public:
  Test_legacy_auto_check_sbp_navigation_MsgProtectionLevel0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::PayloadHandler<msg_protection_level_t>(this),
        last_msg_storage_(),
        last_msg_(
            reinterpret_cast<msg_protection_level_t *>(last_msg_storage_)),
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
                      const msg_protection_level_t &msg) override {
    memcpy(last_msg_storage_, &msg, message_length);
    last_msg_len_ = message_length;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  uint8_t last_msg_storage_[SBP_MAX_PAYLOAD_LEN];
  msg_protection_level_t *last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_legacy_auto_check_sbp_navigation_MsgProtectionLevel0, Test) {
  uint8_t encoded_frame[] = {
      85,  23,  2,   45,  3,   76, 110, 84,  4,   242, 46,  51,  53,  160,
      89,  84,  167, 41,  57,  21, 217, 244, 61,  161, 83,  104, 140, 137,
      90,  246, 51,  51,  51,  51, 51,  170, 180, 64,  154, 153, 153, 153,
      25,  88,  195, 64,  51,  51, 51,  51,  51,  195, 121, 64,  231, 251,
      38,  221, 208, 183, 167, 80, 223, 26,  97,  164, 45,  46,  186, 60,
      235, 227, 183, 160, 187, 93, 116, 224, 105, 40,  32,  33,  133, 188,
  };

  uint8_t test_msg_storage[SBP_MAX_PAYLOAD_LEN]{};
  uint8_t test_msg_len = 0;
  msg_protection_level_t *test_msg = (msg_protection_level_t *)test_msg_storage;
  test_msg_len = (uint8_t)sizeof(*test_msg);
  test_msg->atpl = 10663;
  test_msg->ctpl = 5433;
  test_msg->flags = 555755625;
  test_msg->heading = -529244741;
  test_msg->height = 412.2;
  test_msg->hopl = 26707;
  test_msg->hpl = 41013;
  test_msg->hvpl = 62681;
  test_msg->lat = 5290.2;
  test_msg->lon = 9904.2;
  test_msg->pitch = -1598561301;
  test_msg->popl = 35212;
  test_msg->roll = 1018834477;
  test_msg->ropl = 63066;
  test_msg->tow = 4060370030;
  test_msg->v_x = -584647705;
  test_msg->v_y = 1353168848;
  test_msg->v_z = -1537140001;
  test_msg->vpl = 21593;
  test_msg->vvpl = 41277;
  test_msg->wn = 13102;

  EXPECT_EQ(send_message(0x217, 813, test_msg_len, test_msg_storage), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 813);
  EXPECT_EQ(last_msg_len_, test_msg_len);
  EXPECT_EQ(last_msg_->atpl, 10663)
      << "incorrect value for atpl, expected 10663, is " << last_msg_->atpl;
  EXPECT_EQ(last_msg_->ctpl, 5433)
      << "incorrect value for ctpl, expected 5433, is " << last_msg_->ctpl;
  EXPECT_EQ(last_msg_->flags, 555755625)
      << "incorrect value for flags, expected 555755625, is "
      << last_msg_->flags;
  EXPECT_EQ(last_msg_->heading, -529244741)
      << "incorrect value for heading, expected -529244741, is "
      << last_msg_->heading;
  EXPECT_LT((last_msg_->height * 100 - 412.2 * 100), 0.05)
      << "incorrect value for height, expected 412.2, is " << last_msg_->height;
  EXPECT_EQ(last_msg_->hopl, 26707)
      << "incorrect value for hopl, expected 26707, is " << last_msg_->hopl;
  EXPECT_EQ(last_msg_->hpl, 41013)
      << "incorrect value for hpl, expected 41013, is " << last_msg_->hpl;
  EXPECT_EQ(last_msg_->hvpl, 62681)
      << "incorrect value for hvpl, expected 62681, is " << last_msg_->hvpl;
  EXPECT_LT((last_msg_->lat * 100 - 5290.2 * 100), 0.05)
      << "incorrect value for lat, expected 5290.2, is " << last_msg_->lat;
  EXPECT_LT((last_msg_->lon * 100 - 9904.2 * 100), 0.05)
      << "incorrect value for lon, expected 9904.2, is " << last_msg_->lon;
  EXPECT_EQ(last_msg_->pitch, -1598561301)
      << "incorrect value for pitch, expected -1598561301, is "
      << last_msg_->pitch;
  EXPECT_EQ(last_msg_->popl, 35212)
      << "incorrect value for popl, expected 35212, is " << last_msg_->popl;
  EXPECT_EQ(last_msg_->roll, 1018834477)
      << "incorrect value for roll, expected 1018834477, is "
      << last_msg_->roll;
  EXPECT_EQ(last_msg_->ropl, 63066)
      << "incorrect value for ropl, expected 63066, is " << last_msg_->ropl;
  EXPECT_EQ(last_msg_->tow, 4060370030)
      << "incorrect value for tow, expected 4060370030, is " << last_msg_->tow;
  EXPECT_EQ(last_msg_->v_x, -584647705)
      << "incorrect value for v_x, expected -584647705, is " << last_msg_->v_x;
  EXPECT_EQ(last_msg_->v_y, 1353168848)
      << "incorrect value for v_y, expected 1353168848, is " << last_msg_->v_y;
  EXPECT_EQ(last_msg_->v_z, -1537140001)
      << "incorrect value for v_z, expected -1537140001, is " << last_msg_->v_z;
  EXPECT_EQ(last_msg_->vpl, 21593)
      << "incorrect value for vpl, expected 21593, is " << last_msg_->vpl;
  EXPECT_EQ(last_msg_->vvpl, 41277)
      << "incorrect value for vvpl, expected 41277, is " << last_msg_->vvpl;
  EXPECT_EQ(last_msg_->wn, 13102)
      << "incorrect value for wn, expected 13102, is " << last_msg_->wn;
}
