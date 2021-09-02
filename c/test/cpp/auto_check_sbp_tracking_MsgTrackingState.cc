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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingState.yaml by
// generate.py. Do not modify by hand!

#include <gtest/gtest.h>
#include <libsbp/cpp/message_handler.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/state.h>
#include <cstring>
class Test_auto_check_sbp_tracking_MsgTrackingState0
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t> {
 public:
  Test_auto_check_sbp_tracking_MsgTrackingState0()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_tracking_state_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_tracking_MsgTrackingState0, Test) {
  uint8_t encoded_frame[] = {
      85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   197, 253, 28,
      66,  1,   203, 0,   0,   0,   231, 99,  16, 66,  1,   208, 0,   0,
      0,   212, 129, 22,  66,  1,   212, 0,   0,  0,   58,  21,  28,  66,
      1,   217, 0,   0,   0,   178, 33,  40,  66, 1,   218, 0,   0,   0,
      235, 189, 21,  66,  1,   220, 0,   0,   0,  29,  177, 25,  66,  1,
      222, 0,   0,   0,   43,  169, 27,  66,  1,  225, 0,   0,   0,   137,
      125, 42,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
      0,   0,   0,   0,   0,   128, 191, 222, 97,
  };

  sbp_msg_tracking_state_dep_b_t test_msg{};
  test_msg.n_states = 11;

  test_msg.states[0].cn0 = 39.24782180786133;
  test_msg.states[0].sid.code = 0;
  test_msg.states[0].sid.reserved = 0;
  test_msg.states[0].sid.sat = 202;
  test_msg.states[0].state = 1;

  test_msg.states[1].cn0 = 36.09756088256836;
  test_msg.states[1].sid.code = 0;
  test_msg.states[1].sid.reserved = 0;
  test_msg.states[1].sid.sat = 203;
  test_msg.states[1].state = 1;

  test_msg.states[2].cn0 = 37.62678527832031;
  test_msg.states[2].sid.code = 0;
  test_msg.states[2].sid.reserved = 0;
  test_msg.states[2].sid.sat = 208;
  test_msg.states[2].state = 1;

  test_msg.states[3].cn0 = 39.020729064941406;
  test_msg.states[3].sid.code = 0;
  test_msg.states[3].sid.reserved = 0;
  test_msg.states[3].sid.sat = 212;
  test_msg.states[3].state = 1;

  test_msg.states[4].cn0 = 42.03290557861328;
  test_msg.states[4].sid.code = 0;
  test_msg.states[4].sid.reserved = 0;
  test_msg.states[4].sid.sat = 217;
  test_msg.states[4].state = 1;

  test_msg.states[5].cn0 = 37.43546676635742;
  test_msg.states[5].sid.code = 0;
  test_msg.states[5].sid.reserved = 0;
  test_msg.states[5].sid.sat = 218;
  test_msg.states[5].state = 1;

  test_msg.states[6].cn0 = 38.4229621887207;
  test_msg.states[6].sid.code = 0;
  test_msg.states[6].sid.reserved = 0;
  test_msg.states[6].sid.sat = 220;
  test_msg.states[6].state = 1;

  test_msg.states[7].cn0 = 38.91520309448242;
  test_msg.states[7].sid.code = 0;
  test_msg.states[7].sid.reserved = 0;
  test_msg.states[7].sid.sat = 222;
  test_msg.states[7].state = 1;

  test_msg.states[8].cn0 = 42.62259292602539;
  test_msg.states[8].sid.code = 0;
  test_msg.states[8].sid.reserved = 0;
  test_msg.states[8].sid.sat = 225;
  test_msg.states[8].state = 1;

  test_msg.states[9].cn0 = -1.0;
  test_msg.states[9].sid.code = 0;
  test_msg.states[9].sid.reserved = 0;
  test_msg.states[9].sid.sat = 0;
  test_msg.states[9].state = 0;

  test_msg.states[10].cn0 = -1.0;
  test_msg.states[10].sid.code = 0;
  test_msg.states[10].sid.reserved = 0;
  test_msg.states[10].sid.sat = 0;
  test_msg.states[10].state = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.n_states, 11)
      << "incorrect value for last_msg_.n_states, expected 11, is "
      << last_msg_.n_states;
  EXPECT_LT((last_msg_.states[0].cn0 * 100 - 39.2478218079 * 100), 0.05)
      << "incorrect value for last_msg_.states[0].cn0, expected 39.2478218079, "
         "is "
      << last_msg_.states[0].cn0;
  EXPECT_EQ(last_msg_.states[0].sid.code, 0)
      << "incorrect value for last_msg_.states[0].sid.code, expected 0, is "
      << last_msg_.states[0].sid.code;
  EXPECT_EQ(last_msg_.states[0].sid.reserved, 0)
      << "incorrect value for last_msg_.states[0].sid.reserved, expected 0, is "
      << last_msg_.states[0].sid.reserved;
  EXPECT_EQ(last_msg_.states[0].sid.sat, 202)
      << "incorrect value for last_msg_.states[0].sid.sat, expected 202, is "
      << last_msg_.states[0].sid.sat;
  EXPECT_EQ(last_msg_.states[0].state, 1)
      << "incorrect value for last_msg_.states[0].state, expected 1, is "
      << last_msg_.states[0].state;
  EXPECT_LT((last_msg_.states[1].cn0 * 100 - 36.0975608826 * 100), 0.05)
      << "incorrect value for last_msg_.states[1].cn0, expected 36.0975608826, "
         "is "
      << last_msg_.states[1].cn0;
  EXPECT_EQ(last_msg_.states[1].sid.code, 0)
      << "incorrect value for last_msg_.states[1].sid.code, expected 0, is "
      << last_msg_.states[1].sid.code;
  EXPECT_EQ(last_msg_.states[1].sid.reserved, 0)
      << "incorrect value for last_msg_.states[1].sid.reserved, expected 0, is "
      << last_msg_.states[1].sid.reserved;
  EXPECT_EQ(last_msg_.states[1].sid.sat, 203)
      << "incorrect value for last_msg_.states[1].sid.sat, expected 203, is "
      << last_msg_.states[1].sid.sat;
  EXPECT_EQ(last_msg_.states[1].state, 1)
      << "incorrect value for last_msg_.states[1].state, expected 1, is "
      << last_msg_.states[1].state;
  EXPECT_LT((last_msg_.states[2].cn0 * 100 - 37.6267852783 * 100), 0.05)
      << "incorrect value for last_msg_.states[2].cn0, expected 37.6267852783, "
         "is "
      << last_msg_.states[2].cn0;
  EXPECT_EQ(last_msg_.states[2].sid.code, 0)
      << "incorrect value for last_msg_.states[2].sid.code, expected 0, is "
      << last_msg_.states[2].sid.code;
  EXPECT_EQ(last_msg_.states[2].sid.reserved, 0)
      << "incorrect value for last_msg_.states[2].sid.reserved, expected 0, is "
      << last_msg_.states[2].sid.reserved;
  EXPECT_EQ(last_msg_.states[2].sid.sat, 208)
      << "incorrect value for last_msg_.states[2].sid.sat, expected 208, is "
      << last_msg_.states[2].sid.sat;
  EXPECT_EQ(last_msg_.states[2].state, 1)
      << "incorrect value for last_msg_.states[2].state, expected 1, is "
      << last_msg_.states[2].state;
  EXPECT_LT((last_msg_.states[3].cn0 * 100 - 39.0207290649 * 100), 0.05)
      << "incorrect value for last_msg_.states[3].cn0, expected 39.0207290649, "
         "is "
      << last_msg_.states[3].cn0;
  EXPECT_EQ(last_msg_.states[3].sid.code, 0)
      << "incorrect value for last_msg_.states[3].sid.code, expected 0, is "
      << last_msg_.states[3].sid.code;
  EXPECT_EQ(last_msg_.states[3].sid.reserved, 0)
      << "incorrect value for last_msg_.states[3].sid.reserved, expected 0, is "
      << last_msg_.states[3].sid.reserved;
  EXPECT_EQ(last_msg_.states[3].sid.sat, 212)
      << "incorrect value for last_msg_.states[3].sid.sat, expected 212, is "
      << last_msg_.states[3].sid.sat;
  EXPECT_EQ(last_msg_.states[3].state, 1)
      << "incorrect value for last_msg_.states[3].state, expected 1, is "
      << last_msg_.states[3].state;
  EXPECT_LT((last_msg_.states[4].cn0 * 100 - 42.0329055786 * 100), 0.05)
      << "incorrect value for last_msg_.states[4].cn0, expected 42.0329055786, "
         "is "
      << last_msg_.states[4].cn0;
  EXPECT_EQ(last_msg_.states[4].sid.code, 0)
      << "incorrect value for last_msg_.states[4].sid.code, expected 0, is "
      << last_msg_.states[4].sid.code;
  EXPECT_EQ(last_msg_.states[4].sid.reserved, 0)
      << "incorrect value for last_msg_.states[4].sid.reserved, expected 0, is "
      << last_msg_.states[4].sid.reserved;
  EXPECT_EQ(last_msg_.states[4].sid.sat, 217)
      << "incorrect value for last_msg_.states[4].sid.sat, expected 217, is "
      << last_msg_.states[4].sid.sat;
  EXPECT_EQ(last_msg_.states[4].state, 1)
      << "incorrect value for last_msg_.states[4].state, expected 1, is "
      << last_msg_.states[4].state;
  EXPECT_LT((last_msg_.states[5].cn0 * 100 - 37.4354667664 * 100), 0.05)
      << "incorrect value for last_msg_.states[5].cn0, expected 37.4354667664, "
         "is "
      << last_msg_.states[5].cn0;
  EXPECT_EQ(last_msg_.states[5].sid.code, 0)
      << "incorrect value for last_msg_.states[5].sid.code, expected 0, is "
      << last_msg_.states[5].sid.code;
  EXPECT_EQ(last_msg_.states[5].sid.reserved, 0)
      << "incorrect value for last_msg_.states[5].sid.reserved, expected 0, is "
      << last_msg_.states[5].sid.reserved;
  EXPECT_EQ(last_msg_.states[5].sid.sat, 218)
      << "incorrect value for last_msg_.states[5].sid.sat, expected 218, is "
      << last_msg_.states[5].sid.sat;
  EXPECT_EQ(last_msg_.states[5].state, 1)
      << "incorrect value for last_msg_.states[5].state, expected 1, is "
      << last_msg_.states[5].state;
  EXPECT_LT((last_msg_.states[6].cn0 * 100 - 38.4229621887 * 100), 0.05)
      << "incorrect value for last_msg_.states[6].cn0, expected 38.4229621887, "
         "is "
      << last_msg_.states[6].cn0;
  EXPECT_EQ(last_msg_.states[6].sid.code, 0)
      << "incorrect value for last_msg_.states[6].sid.code, expected 0, is "
      << last_msg_.states[6].sid.code;
  EXPECT_EQ(last_msg_.states[6].sid.reserved, 0)
      << "incorrect value for last_msg_.states[6].sid.reserved, expected 0, is "
      << last_msg_.states[6].sid.reserved;
  EXPECT_EQ(last_msg_.states[6].sid.sat, 220)
      << "incorrect value for last_msg_.states[6].sid.sat, expected 220, is "
      << last_msg_.states[6].sid.sat;
  EXPECT_EQ(last_msg_.states[6].state, 1)
      << "incorrect value for last_msg_.states[6].state, expected 1, is "
      << last_msg_.states[6].state;
  EXPECT_LT((last_msg_.states[7].cn0 * 100 - 38.9152030945 * 100), 0.05)
      << "incorrect value for last_msg_.states[7].cn0, expected 38.9152030945, "
         "is "
      << last_msg_.states[7].cn0;
  EXPECT_EQ(last_msg_.states[7].sid.code, 0)
      << "incorrect value for last_msg_.states[7].sid.code, expected 0, is "
      << last_msg_.states[7].sid.code;
  EXPECT_EQ(last_msg_.states[7].sid.reserved, 0)
      << "incorrect value for last_msg_.states[7].sid.reserved, expected 0, is "
      << last_msg_.states[7].sid.reserved;
  EXPECT_EQ(last_msg_.states[7].sid.sat, 222)
      << "incorrect value for last_msg_.states[7].sid.sat, expected 222, is "
      << last_msg_.states[7].sid.sat;
  EXPECT_EQ(last_msg_.states[7].state, 1)
      << "incorrect value for last_msg_.states[7].state, expected 1, is "
      << last_msg_.states[7].state;
  EXPECT_LT((last_msg_.states[8].cn0 * 100 - 42.622592926 * 100), 0.05)
      << "incorrect value for last_msg_.states[8].cn0, expected 42.622592926, "
         "is "
      << last_msg_.states[8].cn0;
  EXPECT_EQ(last_msg_.states[8].sid.code, 0)
      << "incorrect value for last_msg_.states[8].sid.code, expected 0, is "
      << last_msg_.states[8].sid.code;
  EXPECT_EQ(last_msg_.states[8].sid.reserved, 0)
      << "incorrect value for last_msg_.states[8].sid.reserved, expected 0, is "
      << last_msg_.states[8].sid.reserved;
  EXPECT_EQ(last_msg_.states[8].sid.sat, 225)
      << "incorrect value for last_msg_.states[8].sid.sat, expected 225, is "
      << last_msg_.states[8].sid.sat;
  EXPECT_EQ(last_msg_.states[8].state, 1)
      << "incorrect value for last_msg_.states[8].state, expected 1, is "
      << last_msg_.states[8].state;
  EXPECT_LT((last_msg_.states[9].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for last_msg_.states[9].cn0, expected -1.0, is "
      << last_msg_.states[9].cn0;
  EXPECT_EQ(last_msg_.states[9].sid.code, 0)
      << "incorrect value for last_msg_.states[9].sid.code, expected 0, is "
      << last_msg_.states[9].sid.code;
  EXPECT_EQ(last_msg_.states[9].sid.reserved, 0)
      << "incorrect value for last_msg_.states[9].sid.reserved, expected 0, is "
      << last_msg_.states[9].sid.reserved;
  EXPECT_EQ(last_msg_.states[9].sid.sat, 0)
      << "incorrect value for last_msg_.states[9].sid.sat, expected 0, is "
      << last_msg_.states[9].sid.sat;
  EXPECT_EQ(last_msg_.states[9].state, 0)
      << "incorrect value for last_msg_.states[9].state, expected 0, is "
      << last_msg_.states[9].state;
  EXPECT_LT((last_msg_.states[10].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for last_msg_.states[10].cn0, expected -1.0, is "
      << last_msg_.states[10].cn0;
  EXPECT_EQ(last_msg_.states[10].sid.code, 0)
      << "incorrect value for last_msg_.states[10].sid.code, expected 0, is "
      << last_msg_.states[10].sid.code;
  EXPECT_EQ(last_msg_.states[10].sid.reserved, 0)
      << "incorrect value for last_msg_.states[10].sid.reserved, expected 0, "
         "is "
      << last_msg_.states[10].sid.reserved;
  EXPECT_EQ(last_msg_.states[10].sid.sat, 0)
      << "incorrect value for last_msg_.states[10].sid.sat, expected 0, is "
      << last_msg_.states[10].sid.sat;
  EXPECT_EQ(last_msg_.states[10].state, 0)
      << "incorrect value for last_msg_.states[10].state, expected 0, is "
      << last_msg_.states[10].state;
}
class Test_auto_check_sbp_tracking_MsgTrackingState1
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t> {
 public:
  Test_auto_check_sbp_tracking_MsgTrackingState1()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_tracking_state_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_tracking_MsgTrackingState1, Test) {
  uint8_t encoded_frame[] = {
      85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   250, 249, 27,
      66,  1,   203, 0,   0,   0,   40,  143, 11, 66,  1,   208, 0,   0,
      0,   190, 200, 21,  66,  1,   212, 0,   0,  0,   251, 233, 26,  66,
      1,   217, 0,   0,   0,   209, 238, 39,  66, 1,   218, 0,   0,   0,
      162, 219, 21,  66,  1,   220, 0,   0,   0,  162, 197, 25,  66,  1,
      222, 0,   0,   0,   14,  35,  28,  66,  1,  225, 0,   0,   0,   9,
      153, 43,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
      0,   0,   0,   0,   0,   128, 191, 20,  31,
  };

  sbp_msg_tracking_state_dep_b_t test_msg{};
  test_msg.n_states = 11;

  test_msg.states[0].cn0 = 38.994117736816406;
  test_msg.states[0].sid.code = 0;
  test_msg.states[0].sid.reserved = 0;
  test_msg.states[0].sid.sat = 202;
  test_msg.states[0].state = 1;

  test_msg.states[1].cn0 = 34.889801025390625;
  test_msg.states[1].sid.code = 0;
  test_msg.states[1].sid.reserved = 0;
  test_msg.states[1].sid.sat = 203;
  test_msg.states[1].state = 1;

  test_msg.states[2].cn0 = 37.44603729248047;
  test_msg.states[2].sid.code = 0;
  test_msg.states[2].sid.reserved = 0;
  test_msg.states[2].sid.sat = 208;
  test_msg.states[2].state = 1;

  test_msg.states[3].cn0 = 38.72849655151367;
  test_msg.states[3].sid.code = 0;
  test_msg.states[3].sid.reserved = 0;
  test_msg.states[3].sid.sat = 212;
  test_msg.states[3].state = 1;

  test_msg.states[4].cn0 = 41.983219146728516;
  test_msg.states[4].sid.code = 0;
  test_msg.states[4].sid.reserved = 0;
  test_msg.states[4].sid.sat = 217;
  test_msg.states[4].state = 1;

  test_msg.states[5].cn0 = 37.46448516845703;
  test_msg.states[5].sid.code = 0;
  test_msg.states[5].sid.reserved = 0;
  test_msg.states[5].sid.sat = 218;
  test_msg.states[5].state = 1;

  test_msg.states[6].cn0 = 38.44300079345703;
  test_msg.states[6].sid.code = 0;
  test_msg.states[6].sid.reserved = 0;
  test_msg.states[6].sid.sat = 220;
  test_msg.states[6].state = 1;

  test_msg.states[7].cn0 = 39.03423309326172;
  test_msg.states[7].sid.code = 0;
  test_msg.states[7].sid.reserved = 0;
  test_msg.states[7].sid.sat = 222;
  test_msg.states[7].state = 1;

  test_msg.states[8].cn0 = 42.89944839477539;
  test_msg.states[8].sid.code = 0;
  test_msg.states[8].sid.reserved = 0;
  test_msg.states[8].sid.sat = 225;
  test_msg.states[8].state = 1;

  test_msg.states[9].cn0 = -1.0;
  test_msg.states[9].sid.code = 0;
  test_msg.states[9].sid.reserved = 0;
  test_msg.states[9].sid.sat = 0;
  test_msg.states[9].state = 0;

  test_msg.states[10].cn0 = -1.0;
  test_msg.states[10].sid.code = 0;
  test_msg.states[10].sid.reserved = 0;
  test_msg.states[10].sid.sat = 0;
  test_msg.states[10].state = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.n_states, 11)
      << "incorrect value for last_msg_.n_states, expected 11, is "
      << last_msg_.n_states;
  EXPECT_LT((last_msg_.states[0].cn0 * 100 - 38.9941177368 * 100), 0.05)
      << "incorrect value for last_msg_.states[0].cn0, expected 38.9941177368, "
         "is "
      << last_msg_.states[0].cn0;
  EXPECT_EQ(last_msg_.states[0].sid.code, 0)
      << "incorrect value for last_msg_.states[0].sid.code, expected 0, is "
      << last_msg_.states[0].sid.code;
  EXPECT_EQ(last_msg_.states[0].sid.reserved, 0)
      << "incorrect value for last_msg_.states[0].sid.reserved, expected 0, is "
      << last_msg_.states[0].sid.reserved;
  EXPECT_EQ(last_msg_.states[0].sid.sat, 202)
      << "incorrect value for last_msg_.states[0].sid.sat, expected 202, is "
      << last_msg_.states[0].sid.sat;
  EXPECT_EQ(last_msg_.states[0].state, 1)
      << "incorrect value for last_msg_.states[0].state, expected 1, is "
      << last_msg_.states[0].state;
  EXPECT_LT((last_msg_.states[1].cn0 * 100 - 34.8898010254 * 100), 0.05)
      << "incorrect value for last_msg_.states[1].cn0, expected 34.8898010254, "
         "is "
      << last_msg_.states[1].cn0;
  EXPECT_EQ(last_msg_.states[1].sid.code, 0)
      << "incorrect value for last_msg_.states[1].sid.code, expected 0, is "
      << last_msg_.states[1].sid.code;
  EXPECT_EQ(last_msg_.states[1].sid.reserved, 0)
      << "incorrect value for last_msg_.states[1].sid.reserved, expected 0, is "
      << last_msg_.states[1].sid.reserved;
  EXPECT_EQ(last_msg_.states[1].sid.sat, 203)
      << "incorrect value for last_msg_.states[1].sid.sat, expected 203, is "
      << last_msg_.states[1].sid.sat;
  EXPECT_EQ(last_msg_.states[1].state, 1)
      << "incorrect value for last_msg_.states[1].state, expected 1, is "
      << last_msg_.states[1].state;
  EXPECT_LT((last_msg_.states[2].cn0 * 100 - 37.4460372925 * 100), 0.05)
      << "incorrect value for last_msg_.states[2].cn0, expected 37.4460372925, "
         "is "
      << last_msg_.states[2].cn0;
  EXPECT_EQ(last_msg_.states[2].sid.code, 0)
      << "incorrect value for last_msg_.states[2].sid.code, expected 0, is "
      << last_msg_.states[2].sid.code;
  EXPECT_EQ(last_msg_.states[2].sid.reserved, 0)
      << "incorrect value for last_msg_.states[2].sid.reserved, expected 0, is "
      << last_msg_.states[2].sid.reserved;
  EXPECT_EQ(last_msg_.states[2].sid.sat, 208)
      << "incorrect value for last_msg_.states[2].sid.sat, expected 208, is "
      << last_msg_.states[2].sid.sat;
  EXPECT_EQ(last_msg_.states[2].state, 1)
      << "incorrect value for last_msg_.states[2].state, expected 1, is "
      << last_msg_.states[2].state;
  EXPECT_LT((last_msg_.states[3].cn0 * 100 - 38.7284965515 * 100), 0.05)
      << "incorrect value for last_msg_.states[3].cn0, expected 38.7284965515, "
         "is "
      << last_msg_.states[3].cn0;
  EXPECT_EQ(last_msg_.states[3].sid.code, 0)
      << "incorrect value for last_msg_.states[3].sid.code, expected 0, is "
      << last_msg_.states[3].sid.code;
  EXPECT_EQ(last_msg_.states[3].sid.reserved, 0)
      << "incorrect value for last_msg_.states[3].sid.reserved, expected 0, is "
      << last_msg_.states[3].sid.reserved;
  EXPECT_EQ(last_msg_.states[3].sid.sat, 212)
      << "incorrect value for last_msg_.states[3].sid.sat, expected 212, is "
      << last_msg_.states[3].sid.sat;
  EXPECT_EQ(last_msg_.states[3].state, 1)
      << "incorrect value for last_msg_.states[3].state, expected 1, is "
      << last_msg_.states[3].state;
  EXPECT_LT((last_msg_.states[4].cn0 * 100 - 41.9832191467 * 100), 0.05)
      << "incorrect value for last_msg_.states[4].cn0, expected 41.9832191467, "
         "is "
      << last_msg_.states[4].cn0;
  EXPECT_EQ(last_msg_.states[4].sid.code, 0)
      << "incorrect value for last_msg_.states[4].sid.code, expected 0, is "
      << last_msg_.states[4].sid.code;
  EXPECT_EQ(last_msg_.states[4].sid.reserved, 0)
      << "incorrect value for last_msg_.states[4].sid.reserved, expected 0, is "
      << last_msg_.states[4].sid.reserved;
  EXPECT_EQ(last_msg_.states[4].sid.sat, 217)
      << "incorrect value for last_msg_.states[4].sid.sat, expected 217, is "
      << last_msg_.states[4].sid.sat;
  EXPECT_EQ(last_msg_.states[4].state, 1)
      << "incorrect value for last_msg_.states[4].state, expected 1, is "
      << last_msg_.states[4].state;
  EXPECT_LT((last_msg_.states[5].cn0 * 100 - 37.4644851685 * 100), 0.05)
      << "incorrect value for last_msg_.states[5].cn0, expected 37.4644851685, "
         "is "
      << last_msg_.states[5].cn0;
  EXPECT_EQ(last_msg_.states[5].sid.code, 0)
      << "incorrect value for last_msg_.states[5].sid.code, expected 0, is "
      << last_msg_.states[5].sid.code;
  EXPECT_EQ(last_msg_.states[5].sid.reserved, 0)
      << "incorrect value for last_msg_.states[5].sid.reserved, expected 0, is "
      << last_msg_.states[5].sid.reserved;
  EXPECT_EQ(last_msg_.states[5].sid.sat, 218)
      << "incorrect value for last_msg_.states[5].sid.sat, expected 218, is "
      << last_msg_.states[5].sid.sat;
  EXPECT_EQ(last_msg_.states[5].state, 1)
      << "incorrect value for last_msg_.states[5].state, expected 1, is "
      << last_msg_.states[5].state;
  EXPECT_LT((last_msg_.states[6].cn0 * 100 - 38.4430007935 * 100), 0.05)
      << "incorrect value for last_msg_.states[6].cn0, expected 38.4430007935, "
         "is "
      << last_msg_.states[6].cn0;
  EXPECT_EQ(last_msg_.states[6].sid.code, 0)
      << "incorrect value for last_msg_.states[6].sid.code, expected 0, is "
      << last_msg_.states[6].sid.code;
  EXPECT_EQ(last_msg_.states[6].sid.reserved, 0)
      << "incorrect value for last_msg_.states[6].sid.reserved, expected 0, is "
      << last_msg_.states[6].sid.reserved;
  EXPECT_EQ(last_msg_.states[6].sid.sat, 220)
      << "incorrect value for last_msg_.states[6].sid.sat, expected 220, is "
      << last_msg_.states[6].sid.sat;
  EXPECT_EQ(last_msg_.states[6].state, 1)
      << "incorrect value for last_msg_.states[6].state, expected 1, is "
      << last_msg_.states[6].state;
  EXPECT_LT((last_msg_.states[7].cn0 * 100 - 39.0342330933 * 100), 0.05)
      << "incorrect value for last_msg_.states[7].cn0, expected 39.0342330933, "
         "is "
      << last_msg_.states[7].cn0;
  EXPECT_EQ(last_msg_.states[7].sid.code, 0)
      << "incorrect value for last_msg_.states[7].sid.code, expected 0, is "
      << last_msg_.states[7].sid.code;
  EXPECT_EQ(last_msg_.states[7].sid.reserved, 0)
      << "incorrect value for last_msg_.states[7].sid.reserved, expected 0, is "
      << last_msg_.states[7].sid.reserved;
  EXPECT_EQ(last_msg_.states[7].sid.sat, 222)
      << "incorrect value for last_msg_.states[7].sid.sat, expected 222, is "
      << last_msg_.states[7].sid.sat;
  EXPECT_EQ(last_msg_.states[7].state, 1)
      << "incorrect value for last_msg_.states[7].state, expected 1, is "
      << last_msg_.states[7].state;
  EXPECT_LT((last_msg_.states[8].cn0 * 100 - 42.8994483948 * 100), 0.05)
      << "incorrect value for last_msg_.states[8].cn0, expected 42.8994483948, "
         "is "
      << last_msg_.states[8].cn0;
  EXPECT_EQ(last_msg_.states[8].sid.code, 0)
      << "incorrect value for last_msg_.states[8].sid.code, expected 0, is "
      << last_msg_.states[8].sid.code;
  EXPECT_EQ(last_msg_.states[8].sid.reserved, 0)
      << "incorrect value for last_msg_.states[8].sid.reserved, expected 0, is "
      << last_msg_.states[8].sid.reserved;
  EXPECT_EQ(last_msg_.states[8].sid.sat, 225)
      << "incorrect value for last_msg_.states[8].sid.sat, expected 225, is "
      << last_msg_.states[8].sid.sat;
  EXPECT_EQ(last_msg_.states[8].state, 1)
      << "incorrect value for last_msg_.states[8].state, expected 1, is "
      << last_msg_.states[8].state;
  EXPECT_LT((last_msg_.states[9].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for last_msg_.states[9].cn0, expected -1.0, is "
      << last_msg_.states[9].cn0;
  EXPECT_EQ(last_msg_.states[9].sid.code, 0)
      << "incorrect value for last_msg_.states[9].sid.code, expected 0, is "
      << last_msg_.states[9].sid.code;
  EXPECT_EQ(last_msg_.states[9].sid.reserved, 0)
      << "incorrect value for last_msg_.states[9].sid.reserved, expected 0, is "
      << last_msg_.states[9].sid.reserved;
  EXPECT_EQ(last_msg_.states[9].sid.sat, 0)
      << "incorrect value for last_msg_.states[9].sid.sat, expected 0, is "
      << last_msg_.states[9].sid.sat;
  EXPECT_EQ(last_msg_.states[9].state, 0)
      << "incorrect value for last_msg_.states[9].state, expected 0, is "
      << last_msg_.states[9].state;
  EXPECT_LT((last_msg_.states[10].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for last_msg_.states[10].cn0, expected -1.0, is "
      << last_msg_.states[10].cn0;
  EXPECT_EQ(last_msg_.states[10].sid.code, 0)
      << "incorrect value for last_msg_.states[10].sid.code, expected 0, is "
      << last_msg_.states[10].sid.code;
  EXPECT_EQ(last_msg_.states[10].sid.reserved, 0)
      << "incorrect value for last_msg_.states[10].sid.reserved, expected 0, "
         "is "
      << last_msg_.states[10].sid.reserved;
  EXPECT_EQ(last_msg_.states[10].sid.sat, 0)
      << "incorrect value for last_msg_.states[10].sid.sat, expected 0, is "
      << last_msg_.states[10].sid.sat;
  EXPECT_EQ(last_msg_.states[10].state, 0)
      << "incorrect value for last_msg_.states[10].state, expected 0, is "
      << last_msg_.states[10].state;
}
class Test_auto_check_sbp_tracking_MsgTrackingState2
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t> {
 public:
  Test_auto_check_sbp_tracking_MsgTrackingState2()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_tracking_state_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_tracking_MsgTrackingState2, Test) {
  uint8_t encoded_frame[] = {
      85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   123, 209, 27,
      66,  1,   203, 0,   0,   0,   214, 64,  15, 66,  1,   208, 0,   0,
      0,   56,  55,  22,  66,  1,   212, 0,   0,  0,   91,  142, 27,  66,
      1,   217, 0,   0,   0,   253, 154, 41,  66, 1,   218, 0,   0,   0,
      128, 142, 22,  66,  1,   220, 0,   0,   0,  17,  174, 23,  66,  1,
      222, 0,   0,   0,   155, 2,   29,  66,  1,  225, 0,   0,   0,   162,
      100, 42,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
      0,   0,   0,   0,   0,   128, 191, 233, 71,
  };

  sbp_msg_tracking_state_dep_b_t test_msg{};
  test_msg.n_states = 11;

  test_msg.states[0].cn0 = 38.95457077026367;
  test_msg.states[0].sid.code = 0;
  test_msg.states[0].sid.reserved = 0;
  test_msg.states[0].sid.sat = 202;
  test_msg.states[0].state = 1;

  test_msg.states[1].cn0 = 35.813316345214844;
  test_msg.states[1].sid.code = 0;
  test_msg.states[1].sid.reserved = 0;
  test_msg.states[1].sid.sat = 203;
  test_msg.states[1].state = 1;

  test_msg.states[2].cn0 = 37.553924560546875;
  test_msg.states[2].sid.code = 0;
  test_msg.states[2].sid.reserved = 0;
  test_msg.states[2].sid.sat = 208;
  test_msg.states[2].state = 1;

  test_msg.states[3].cn0 = 38.88901901245117;
  test_msg.states[3].sid.code = 0;
  test_msg.states[3].sid.reserved = 0;
  test_msg.states[3].sid.sat = 212;
  test_msg.states[3].state = 1;

  test_msg.states[4].cn0 = 42.4013557434082;
  test_msg.states[4].sid.code = 0;
  test_msg.states[4].sid.reserved = 0;
  test_msg.states[4].sid.sat = 217;
  test_msg.states[4].state = 1;

  test_msg.states[5].cn0 = 37.63916015625;
  test_msg.states[5].sid.code = 0;
  test_msg.states[5].sid.reserved = 0;
  test_msg.states[5].sid.sat = 218;
  test_msg.states[5].state = 1;

  test_msg.states[6].cn0 = 37.919986724853516;
  test_msg.states[6].sid.code = 0;
  test_msg.states[6].sid.reserved = 0;
  test_msg.states[6].sid.sat = 220;
  test_msg.states[6].state = 1;

  test_msg.states[7].cn0 = 39.25254440307617;
  test_msg.states[7].sid.code = 0;
  test_msg.states[7].sid.reserved = 0;
  test_msg.states[7].sid.sat = 222;
  test_msg.states[7].state = 1;

  test_msg.states[8].cn0 = 42.59827423095703;
  test_msg.states[8].sid.code = 0;
  test_msg.states[8].sid.reserved = 0;
  test_msg.states[8].sid.sat = 225;
  test_msg.states[8].state = 1;

  test_msg.states[9].cn0 = -1.0;
  test_msg.states[9].sid.code = 0;
  test_msg.states[9].sid.reserved = 0;
  test_msg.states[9].sid.sat = 0;
  test_msg.states[9].state = 0;

  test_msg.states[10].cn0 = -1.0;
  test_msg.states[10].sid.code = 0;
  test_msg.states[10].sid.reserved = 0;
  test_msg.states[10].sid.sat = 0;
  test_msg.states[10].state = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.n_states, 11)
      << "incorrect value for last_msg_.n_states, expected 11, is "
      << last_msg_.n_states;
  EXPECT_LT((last_msg_.states[0].cn0 * 100 - 38.9545707703 * 100), 0.05)
      << "incorrect value for last_msg_.states[0].cn0, expected 38.9545707703, "
         "is "
      << last_msg_.states[0].cn0;
  EXPECT_EQ(last_msg_.states[0].sid.code, 0)
      << "incorrect value for last_msg_.states[0].sid.code, expected 0, is "
      << last_msg_.states[0].sid.code;
  EXPECT_EQ(last_msg_.states[0].sid.reserved, 0)
      << "incorrect value for last_msg_.states[0].sid.reserved, expected 0, is "
      << last_msg_.states[0].sid.reserved;
  EXPECT_EQ(last_msg_.states[0].sid.sat, 202)
      << "incorrect value for last_msg_.states[0].sid.sat, expected 202, is "
      << last_msg_.states[0].sid.sat;
  EXPECT_EQ(last_msg_.states[0].state, 1)
      << "incorrect value for last_msg_.states[0].state, expected 1, is "
      << last_msg_.states[0].state;
  EXPECT_LT((last_msg_.states[1].cn0 * 100 - 35.8133163452 * 100), 0.05)
      << "incorrect value for last_msg_.states[1].cn0, expected 35.8133163452, "
         "is "
      << last_msg_.states[1].cn0;
  EXPECT_EQ(last_msg_.states[1].sid.code, 0)
      << "incorrect value for last_msg_.states[1].sid.code, expected 0, is "
      << last_msg_.states[1].sid.code;
  EXPECT_EQ(last_msg_.states[1].sid.reserved, 0)
      << "incorrect value for last_msg_.states[1].sid.reserved, expected 0, is "
      << last_msg_.states[1].sid.reserved;
  EXPECT_EQ(last_msg_.states[1].sid.sat, 203)
      << "incorrect value for last_msg_.states[1].sid.sat, expected 203, is "
      << last_msg_.states[1].sid.sat;
  EXPECT_EQ(last_msg_.states[1].state, 1)
      << "incorrect value for last_msg_.states[1].state, expected 1, is "
      << last_msg_.states[1].state;
  EXPECT_LT((last_msg_.states[2].cn0 * 100 - 37.5539245605 * 100), 0.05)
      << "incorrect value for last_msg_.states[2].cn0, expected 37.5539245605, "
         "is "
      << last_msg_.states[2].cn0;
  EXPECT_EQ(last_msg_.states[2].sid.code, 0)
      << "incorrect value for last_msg_.states[2].sid.code, expected 0, is "
      << last_msg_.states[2].sid.code;
  EXPECT_EQ(last_msg_.states[2].sid.reserved, 0)
      << "incorrect value for last_msg_.states[2].sid.reserved, expected 0, is "
      << last_msg_.states[2].sid.reserved;
  EXPECT_EQ(last_msg_.states[2].sid.sat, 208)
      << "incorrect value for last_msg_.states[2].sid.sat, expected 208, is "
      << last_msg_.states[2].sid.sat;
  EXPECT_EQ(last_msg_.states[2].state, 1)
      << "incorrect value for last_msg_.states[2].state, expected 1, is "
      << last_msg_.states[2].state;
  EXPECT_LT((last_msg_.states[3].cn0 * 100 - 38.8890190125 * 100), 0.05)
      << "incorrect value for last_msg_.states[3].cn0, expected 38.8890190125, "
         "is "
      << last_msg_.states[3].cn0;
  EXPECT_EQ(last_msg_.states[3].sid.code, 0)
      << "incorrect value for last_msg_.states[3].sid.code, expected 0, is "
      << last_msg_.states[3].sid.code;
  EXPECT_EQ(last_msg_.states[3].sid.reserved, 0)
      << "incorrect value for last_msg_.states[3].sid.reserved, expected 0, is "
      << last_msg_.states[3].sid.reserved;
  EXPECT_EQ(last_msg_.states[3].sid.sat, 212)
      << "incorrect value for last_msg_.states[3].sid.sat, expected 212, is "
      << last_msg_.states[3].sid.sat;
  EXPECT_EQ(last_msg_.states[3].state, 1)
      << "incorrect value for last_msg_.states[3].state, expected 1, is "
      << last_msg_.states[3].state;
  EXPECT_LT((last_msg_.states[4].cn0 * 100 - 42.4013557434 * 100), 0.05)
      << "incorrect value for last_msg_.states[4].cn0, expected 42.4013557434, "
         "is "
      << last_msg_.states[4].cn0;
  EXPECT_EQ(last_msg_.states[4].sid.code, 0)
      << "incorrect value for last_msg_.states[4].sid.code, expected 0, is "
      << last_msg_.states[4].sid.code;
  EXPECT_EQ(last_msg_.states[4].sid.reserved, 0)
      << "incorrect value for last_msg_.states[4].sid.reserved, expected 0, is "
      << last_msg_.states[4].sid.reserved;
  EXPECT_EQ(last_msg_.states[4].sid.sat, 217)
      << "incorrect value for last_msg_.states[4].sid.sat, expected 217, is "
      << last_msg_.states[4].sid.sat;
  EXPECT_EQ(last_msg_.states[4].state, 1)
      << "incorrect value for last_msg_.states[4].state, expected 1, is "
      << last_msg_.states[4].state;
  EXPECT_LT((last_msg_.states[5].cn0 * 100 - 37.6391601562 * 100), 0.05)
      << "incorrect value for last_msg_.states[5].cn0, expected 37.6391601562, "
         "is "
      << last_msg_.states[5].cn0;
  EXPECT_EQ(last_msg_.states[5].sid.code, 0)
      << "incorrect value for last_msg_.states[5].sid.code, expected 0, is "
      << last_msg_.states[5].sid.code;
  EXPECT_EQ(last_msg_.states[5].sid.reserved, 0)
      << "incorrect value for last_msg_.states[5].sid.reserved, expected 0, is "
      << last_msg_.states[5].sid.reserved;
  EXPECT_EQ(last_msg_.states[5].sid.sat, 218)
      << "incorrect value for last_msg_.states[5].sid.sat, expected 218, is "
      << last_msg_.states[5].sid.sat;
  EXPECT_EQ(last_msg_.states[5].state, 1)
      << "incorrect value for last_msg_.states[5].state, expected 1, is "
      << last_msg_.states[5].state;
  EXPECT_LT((last_msg_.states[6].cn0 * 100 - 37.9199867249 * 100), 0.05)
      << "incorrect value for last_msg_.states[6].cn0, expected 37.9199867249, "
         "is "
      << last_msg_.states[6].cn0;
  EXPECT_EQ(last_msg_.states[6].sid.code, 0)
      << "incorrect value for last_msg_.states[6].sid.code, expected 0, is "
      << last_msg_.states[6].sid.code;
  EXPECT_EQ(last_msg_.states[6].sid.reserved, 0)
      << "incorrect value for last_msg_.states[6].sid.reserved, expected 0, is "
      << last_msg_.states[6].sid.reserved;
  EXPECT_EQ(last_msg_.states[6].sid.sat, 220)
      << "incorrect value for last_msg_.states[6].sid.sat, expected 220, is "
      << last_msg_.states[6].sid.sat;
  EXPECT_EQ(last_msg_.states[6].state, 1)
      << "incorrect value for last_msg_.states[6].state, expected 1, is "
      << last_msg_.states[6].state;
  EXPECT_LT((last_msg_.states[7].cn0 * 100 - 39.2525444031 * 100), 0.05)
      << "incorrect value for last_msg_.states[7].cn0, expected 39.2525444031, "
         "is "
      << last_msg_.states[7].cn0;
  EXPECT_EQ(last_msg_.states[7].sid.code, 0)
      << "incorrect value for last_msg_.states[7].sid.code, expected 0, is "
      << last_msg_.states[7].sid.code;
  EXPECT_EQ(last_msg_.states[7].sid.reserved, 0)
      << "incorrect value for last_msg_.states[7].sid.reserved, expected 0, is "
      << last_msg_.states[7].sid.reserved;
  EXPECT_EQ(last_msg_.states[7].sid.sat, 222)
      << "incorrect value for last_msg_.states[7].sid.sat, expected 222, is "
      << last_msg_.states[7].sid.sat;
  EXPECT_EQ(last_msg_.states[7].state, 1)
      << "incorrect value for last_msg_.states[7].state, expected 1, is "
      << last_msg_.states[7].state;
  EXPECT_LT((last_msg_.states[8].cn0 * 100 - 42.598274231 * 100), 0.05)
      << "incorrect value for last_msg_.states[8].cn0, expected 42.598274231, "
         "is "
      << last_msg_.states[8].cn0;
  EXPECT_EQ(last_msg_.states[8].sid.code, 0)
      << "incorrect value for last_msg_.states[8].sid.code, expected 0, is "
      << last_msg_.states[8].sid.code;
  EXPECT_EQ(last_msg_.states[8].sid.reserved, 0)
      << "incorrect value for last_msg_.states[8].sid.reserved, expected 0, is "
      << last_msg_.states[8].sid.reserved;
  EXPECT_EQ(last_msg_.states[8].sid.sat, 225)
      << "incorrect value for last_msg_.states[8].sid.sat, expected 225, is "
      << last_msg_.states[8].sid.sat;
  EXPECT_EQ(last_msg_.states[8].state, 1)
      << "incorrect value for last_msg_.states[8].state, expected 1, is "
      << last_msg_.states[8].state;
  EXPECT_LT((last_msg_.states[9].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for last_msg_.states[9].cn0, expected -1.0, is "
      << last_msg_.states[9].cn0;
  EXPECT_EQ(last_msg_.states[9].sid.code, 0)
      << "incorrect value for last_msg_.states[9].sid.code, expected 0, is "
      << last_msg_.states[9].sid.code;
  EXPECT_EQ(last_msg_.states[9].sid.reserved, 0)
      << "incorrect value for last_msg_.states[9].sid.reserved, expected 0, is "
      << last_msg_.states[9].sid.reserved;
  EXPECT_EQ(last_msg_.states[9].sid.sat, 0)
      << "incorrect value for last_msg_.states[9].sid.sat, expected 0, is "
      << last_msg_.states[9].sid.sat;
  EXPECT_EQ(last_msg_.states[9].state, 0)
      << "incorrect value for last_msg_.states[9].state, expected 0, is "
      << last_msg_.states[9].state;
  EXPECT_LT((last_msg_.states[10].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for last_msg_.states[10].cn0, expected -1.0, is "
      << last_msg_.states[10].cn0;
  EXPECT_EQ(last_msg_.states[10].sid.code, 0)
      << "incorrect value for last_msg_.states[10].sid.code, expected 0, is "
      << last_msg_.states[10].sid.code;
  EXPECT_EQ(last_msg_.states[10].sid.reserved, 0)
      << "incorrect value for last_msg_.states[10].sid.reserved, expected 0, "
         "is "
      << last_msg_.states[10].sid.reserved;
  EXPECT_EQ(last_msg_.states[10].sid.sat, 0)
      << "incorrect value for last_msg_.states[10].sid.sat, expected 0, is "
      << last_msg_.states[10].sid.sat;
  EXPECT_EQ(last_msg_.states[10].state, 0)
      << "incorrect value for last_msg_.states[10].state, expected 0, is "
      << last_msg_.states[10].state;
}
class Test_auto_check_sbp_tracking_MsgTrackingState3
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t> {
 public:
  Test_auto_check_sbp_tracking_MsgTrackingState3()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_tracking_state_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_tracking_MsgTrackingState3, Test) {
  uint8_t encoded_frame[] = {
      85,  19,  0,   246, 215, 99,  1,   202, 0,   0,   0,   120, 122, 29,
      66,  1,   203, 0,   0,   0,   66,  22,  18,  66,  1,   208, 0,   0,
      0,   153, 163, 24,  66,  1,   212, 0,   0,   0,   178, 204, 28,  66,
      1,   217, 0,   0,   0,   220, 59,  38,  66,  1,   218, 0,   0,   0,
      161, 27,  20,  66,  1,   220, 0,   0,   0,   125, 107, 24,  66,  1,
      222, 0,   0,   0,   242, 46,  28,  66,  1,   225, 0,   0,   0,   231,
      130, 41,  66,  0,   0,   0,   0,   0,   0,   0,   128, 191, 0,   0,
      0,   0,   0,   0,   0,   128, 191, 73,  193,
  };

  sbp_msg_tracking_state_dep_b_t test_msg{};
  test_msg.n_states = 11;

  test_msg.states[0].cn0 = 39.369598388671875;
  test_msg.states[0].sid.code = 0;
  test_msg.states[0].sid.reserved = 0;
  test_msg.states[0].sid.sat = 202;
  test_msg.states[0].state = 1;

  test_msg.states[1].cn0 = 36.52173614501953;
  test_msg.states[1].sid.code = 0;
  test_msg.states[1].sid.reserved = 0;
  test_msg.states[1].sid.sat = 203;
  test_msg.states[1].state = 1;

  test_msg.states[2].cn0 = 38.15976333618164;
  test_msg.states[2].sid.code = 0;
  test_msg.states[2].sid.reserved = 0;
  test_msg.states[2].sid.sat = 208;
  test_msg.states[2].state = 1;

  test_msg.states[3].cn0 = 39.19989776611328;
  test_msg.states[3].sid.code = 0;
  test_msg.states[3].sid.reserved = 0;
  test_msg.states[3].sid.sat = 212;
  test_msg.states[3].state = 1;

  test_msg.states[4].cn0 = 41.55845642089844;
  test_msg.states[4].sid.code = 0;
  test_msg.states[4].sid.reserved = 0;
  test_msg.states[4].sid.sat = 217;
  test_msg.states[4].state = 1;

  test_msg.states[5].cn0 = 37.026981353759766;
  test_msg.states[5].sid.code = 0;
  test_msg.states[5].sid.reserved = 0;
  test_msg.states[5].sid.sat = 218;
  test_msg.states[5].state = 1;

  test_msg.states[6].cn0 = 38.1049690246582;
  test_msg.states[6].sid.code = 0;
  test_msg.states[6].sid.reserved = 0;
  test_msg.states[6].sid.sat = 220;
  test_msg.states[6].state = 1;

  test_msg.states[7].cn0 = 39.04584503173828;
  test_msg.states[7].sid.code = 0;
  test_msg.states[7].sid.reserved = 0;
  test_msg.states[7].sid.sat = 222;
  test_msg.states[7].state = 1;

  test_msg.states[8].cn0 = 42.37783432006836;
  test_msg.states[8].sid.code = 0;
  test_msg.states[8].sid.reserved = 0;
  test_msg.states[8].sid.sat = 225;
  test_msg.states[8].state = 1;

  test_msg.states[9].cn0 = -1.0;
  test_msg.states[9].sid.code = 0;
  test_msg.states[9].sid.reserved = 0;
  test_msg.states[9].sid.sat = 0;
  test_msg.states[9].state = 0;

  test_msg.states[10].cn0 = -1.0;
  test_msg.states[10].sid.code = 0;
  test_msg.states[10].sid.reserved = 0;
  test_msg.states[10].sid.sat = 0;
  test_msg.states[10].state = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.n_states, 11)
      << "incorrect value for last_msg_.n_states, expected 11, is "
      << last_msg_.n_states;
  EXPECT_LT((last_msg_.states[0].cn0 * 100 - 39.3695983887 * 100), 0.05)
      << "incorrect value for last_msg_.states[0].cn0, expected 39.3695983887, "
         "is "
      << last_msg_.states[0].cn0;
  EXPECT_EQ(last_msg_.states[0].sid.code, 0)
      << "incorrect value for last_msg_.states[0].sid.code, expected 0, is "
      << last_msg_.states[0].sid.code;
  EXPECT_EQ(last_msg_.states[0].sid.reserved, 0)
      << "incorrect value for last_msg_.states[0].sid.reserved, expected 0, is "
      << last_msg_.states[0].sid.reserved;
  EXPECT_EQ(last_msg_.states[0].sid.sat, 202)
      << "incorrect value for last_msg_.states[0].sid.sat, expected 202, is "
      << last_msg_.states[0].sid.sat;
  EXPECT_EQ(last_msg_.states[0].state, 1)
      << "incorrect value for last_msg_.states[0].state, expected 1, is "
      << last_msg_.states[0].state;
  EXPECT_LT((last_msg_.states[1].cn0 * 100 - 36.521736145 * 100), 0.05)
      << "incorrect value for last_msg_.states[1].cn0, expected 36.521736145, "
         "is "
      << last_msg_.states[1].cn0;
  EXPECT_EQ(last_msg_.states[1].sid.code, 0)
      << "incorrect value for last_msg_.states[1].sid.code, expected 0, is "
      << last_msg_.states[1].sid.code;
  EXPECT_EQ(last_msg_.states[1].sid.reserved, 0)
      << "incorrect value for last_msg_.states[1].sid.reserved, expected 0, is "
      << last_msg_.states[1].sid.reserved;
  EXPECT_EQ(last_msg_.states[1].sid.sat, 203)
      << "incorrect value for last_msg_.states[1].sid.sat, expected 203, is "
      << last_msg_.states[1].sid.sat;
  EXPECT_EQ(last_msg_.states[1].state, 1)
      << "incorrect value for last_msg_.states[1].state, expected 1, is "
      << last_msg_.states[1].state;
  EXPECT_LT((last_msg_.states[2].cn0 * 100 - 38.1597633362 * 100), 0.05)
      << "incorrect value for last_msg_.states[2].cn0, expected 38.1597633362, "
         "is "
      << last_msg_.states[2].cn0;
  EXPECT_EQ(last_msg_.states[2].sid.code, 0)
      << "incorrect value for last_msg_.states[2].sid.code, expected 0, is "
      << last_msg_.states[2].sid.code;
  EXPECT_EQ(last_msg_.states[2].sid.reserved, 0)
      << "incorrect value for last_msg_.states[2].sid.reserved, expected 0, is "
      << last_msg_.states[2].sid.reserved;
  EXPECT_EQ(last_msg_.states[2].sid.sat, 208)
      << "incorrect value for last_msg_.states[2].sid.sat, expected 208, is "
      << last_msg_.states[2].sid.sat;
  EXPECT_EQ(last_msg_.states[2].state, 1)
      << "incorrect value for last_msg_.states[2].state, expected 1, is "
      << last_msg_.states[2].state;
  EXPECT_LT((last_msg_.states[3].cn0 * 100 - 39.1998977661 * 100), 0.05)
      << "incorrect value for last_msg_.states[3].cn0, expected 39.1998977661, "
         "is "
      << last_msg_.states[3].cn0;
  EXPECT_EQ(last_msg_.states[3].sid.code, 0)
      << "incorrect value for last_msg_.states[3].sid.code, expected 0, is "
      << last_msg_.states[3].sid.code;
  EXPECT_EQ(last_msg_.states[3].sid.reserved, 0)
      << "incorrect value for last_msg_.states[3].sid.reserved, expected 0, is "
      << last_msg_.states[3].sid.reserved;
  EXPECT_EQ(last_msg_.states[3].sid.sat, 212)
      << "incorrect value for last_msg_.states[3].sid.sat, expected 212, is "
      << last_msg_.states[3].sid.sat;
  EXPECT_EQ(last_msg_.states[3].state, 1)
      << "incorrect value for last_msg_.states[3].state, expected 1, is "
      << last_msg_.states[3].state;
  EXPECT_LT((last_msg_.states[4].cn0 * 100 - 41.5584564209 * 100), 0.05)
      << "incorrect value for last_msg_.states[4].cn0, expected 41.5584564209, "
         "is "
      << last_msg_.states[4].cn0;
  EXPECT_EQ(last_msg_.states[4].sid.code, 0)
      << "incorrect value for last_msg_.states[4].sid.code, expected 0, is "
      << last_msg_.states[4].sid.code;
  EXPECT_EQ(last_msg_.states[4].sid.reserved, 0)
      << "incorrect value for last_msg_.states[4].sid.reserved, expected 0, is "
      << last_msg_.states[4].sid.reserved;
  EXPECT_EQ(last_msg_.states[4].sid.sat, 217)
      << "incorrect value for last_msg_.states[4].sid.sat, expected 217, is "
      << last_msg_.states[4].sid.sat;
  EXPECT_EQ(last_msg_.states[4].state, 1)
      << "incorrect value for last_msg_.states[4].state, expected 1, is "
      << last_msg_.states[4].state;
  EXPECT_LT((last_msg_.states[5].cn0 * 100 - 37.0269813538 * 100), 0.05)
      << "incorrect value for last_msg_.states[5].cn0, expected 37.0269813538, "
         "is "
      << last_msg_.states[5].cn0;
  EXPECT_EQ(last_msg_.states[5].sid.code, 0)
      << "incorrect value for last_msg_.states[5].sid.code, expected 0, is "
      << last_msg_.states[5].sid.code;
  EXPECT_EQ(last_msg_.states[5].sid.reserved, 0)
      << "incorrect value for last_msg_.states[5].sid.reserved, expected 0, is "
      << last_msg_.states[5].sid.reserved;
  EXPECT_EQ(last_msg_.states[5].sid.sat, 218)
      << "incorrect value for last_msg_.states[5].sid.sat, expected 218, is "
      << last_msg_.states[5].sid.sat;
  EXPECT_EQ(last_msg_.states[5].state, 1)
      << "incorrect value for last_msg_.states[5].state, expected 1, is "
      << last_msg_.states[5].state;
  EXPECT_LT((last_msg_.states[6].cn0 * 100 - 38.1049690247 * 100), 0.05)
      << "incorrect value for last_msg_.states[6].cn0, expected 38.1049690247, "
         "is "
      << last_msg_.states[6].cn0;
  EXPECT_EQ(last_msg_.states[6].sid.code, 0)
      << "incorrect value for last_msg_.states[6].sid.code, expected 0, is "
      << last_msg_.states[6].sid.code;
  EXPECT_EQ(last_msg_.states[6].sid.reserved, 0)
      << "incorrect value for last_msg_.states[6].sid.reserved, expected 0, is "
      << last_msg_.states[6].sid.reserved;
  EXPECT_EQ(last_msg_.states[6].sid.sat, 220)
      << "incorrect value for last_msg_.states[6].sid.sat, expected 220, is "
      << last_msg_.states[6].sid.sat;
  EXPECT_EQ(last_msg_.states[6].state, 1)
      << "incorrect value for last_msg_.states[6].state, expected 1, is "
      << last_msg_.states[6].state;
  EXPECT_LT((last_msg_.states[7].cn0 * 100 - 39.0458450317 * 100), 0.05)
      << "incorrect value for last_msg_.states[7].cn0, expected 39.0458450317, "
         "is "
      << last_msg_.states[7].cn0;
  EXPECT_EQ(last_msg_.states[7].sid.code, 0)
      << "incorrect value for last_msg_.states[7].sid.code, expected 0, is "
      << last_msg_.states[7].sid.code;
  EXPECT_EQ(last_msg_.states[7].sid.reserved, 0)
      << "incorrect value for last_msg_.states[7].sid.reserved, expected 0, is "
      << last_msg_.states[7].sid.reserved;
  EXPECT_EQ(last_msg_.states[7].sid.sat, 222)
      << "incorrect value for last_msg_.states[7].sid.sat, expected 222, is "
      << last_msg_.states[7].sid.sat;
  EXPECT_EQ(last_msg_.states[7].state, 1)
      << "incorrect value for last_msg_.states[7].state, expected 1, is "
      << last_msg_.states[7].state;
  EXPECT_LT((last_msg_.states[8].cn0 * 100 - 42.3778343201 * 100), 0.05)
      << "incorrect value for last_msg_.states[8].cn0, expected 42.3778343201, "
         "is "
      << last_msg_.states[8].cn0;
  EXPECT_EQ(last_msg_.states[8].sid.code, 0)
      << "incorrect value for last_msg_.states[8].sid.code, expected 0, is "
      << last_msg_.states[8].sid.code;
  EXPECT_EQ(last_msg_.states[8].sid.reserved, 0)
      << "incorrect value for last_msg_.states[8].sid.reserved, expected 0, is "
      << last_msg_.states[8].sid.reserved;
  EXPECT_EQ(last_msg_.states[8].sid.sat, 225)
      << "incorrect value for last_msg_.states[8].sid.sat, expected 225, is "
      << last_msg_.states[8].sid.sat;
  EXPECT_EQ(last_msg_.states[8].state, 1)
      << "incorrect value for last_msg_.states[8].state, expected 1, is "
      << last_msg_.states[8].state;
  EXPECT_LT((last_msg_.states[9].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for last_msg_.states[9].cn0, expected -1.0, is "
      << last_msg_.states[9].cn0;
  EXPECT_EQ(last_msg_.states[9].sid.code, 0)
      << "incorrect value for last_msg_.states[9].sid.code, expected 0, is "
      << last_msg_.states[9].sid.code;
  EXPECT_EQ(last_msg_.states[9].sid.reserved, 0)
      << "incorrect value for last_msg_.states[9].sid.reserved, expected 0, is "
      << last_msg_.states[9].sid.reserved;
  EXPECT_EQ(last_msg_.states[9].sid.sat, 0)
      << "incorrect value for last_msg_.states[9].sid.sat, expected 0, is "
      << last_msg_.states[9].sid.sat;
  EXPECT_EQ(last_msg_.states[9].state, 0)
      << "incorrect value for last_msg_.states[9].state, expected 0, is "
      << last_msg_.states[9].state;
  EXPECT_LT((last_msg_.states[10].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for last_msg_.states[10].cn0, expected -1.0, is "
      << last_msg_.states[10].cn0;
  EXPECT_EQ(last_msg_.states[10].sid.code, 0)
      << "incorrect value for last_msg_.states[10].sid.code, expected 0, is "
      << last_msg_.states[10].sid.code;
  EXPECT_EQ(last_msg_.states[10].sid.reserved, 0)
      << "incorrect value for last_msg_.states[10].sid.reserved, expected 0, "
         "is "
      << last_msg_.states[10].sid.reserved;
  EXPECT_EQ(last_msg_.states[10].sid.sat, 0)
      << "incorrect value for last_msg_.states[10].sid.sat, expected 0, is "
      << last_msg_.states[10].sid.sat;
  EXPECT_EQ(last_msg_.states[10].state, 0)
      << "incorrect value for last_msg_.states[10].state, expected 0, is "
      << last_msg_.states[10].state;
}
class Test_auto_check_sbp_tracking_MsgTrackingState4
    : public ::testing::Test,
      public sbp::State,
      public sbp::IReader,
      public sbp::IWriter,
      sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t> {
 public:
  Test_auto_check_sbp_tracking_MsgTrackingState4()
      : ::testing::Test(),
        sbp::State(),
        sbp::IReader(),
        sbp::IWriter(),
        sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>(this),
        last_msg_(),
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
  void handle_sbp_msg(uint16_t sender_id,
                      const sbp_msg_tracking_state_dep_b_t &msg) override {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_b_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;
  size_t n_callbacks_logged_;
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};

TEST_F(Test_auto_check_sbp_tracking_MsgTrackingState4, Test) {
  uint8_t encoded_frame[] = {
      85,  19,  0,   246, 215, 99,  1,   202, 0,  0,   0,   103, 208, 30,
      66,  1,   203, 0,   0,   0,   117, 24,  18, 66,  1,   208, 0,   0,
      0,   200, 173, 20,  66,  1,   212, 0,   0,  0,   137, 68,  27,  66,
      1,   217, 0,   0,   0,   243, 51,  40,  66, 1,   218, 0,   0,   0,
      225, 58,  23,  66,  1,   220, 0,   0,   0,  132, 221, 22,  66,  1,
      222, 0,   0,   0,   157, 29,  26,  66,  1,  225, 0,   0,   0,   133,
      21,  41,  66,  0,   0,   0,   0,   0,   0,  0,   128, 191, 0,   0,
      0,   0,   0,   0,   0,   128, 191, 126, 47,
  };

  sbp_msg_tracking_state_dep_b_t test_msg{};
  test_msg.n_states = 11;

  test_msg.states[0].cn0 = 39.70351791381836;
  test_msg.states[0].sid.code = 0;
  test_msg.states[0].sid.reserved = 0;
  test_msg.states[0].sid.sat = 202;
  test_msg.states[0].state = 1;

  test_msg.states[1].cn0 = 36.52388381958008;
  test_msg.states[1].sid.code = 0;
  test_msg.states[1].sid.reserved = 0;
  test_msg.states[1].sid.sat = 203;
  test_msg.states[1].state = 1;

  test_msg.states[2].cn0 = 37.169708251953125;
  test_msg.states[2].sid.code = 0;
  test_msg.states[2].sid.reserved = 0;
  test_msg.states[2].sid.sat = 208;
  test_msg.states[2].state = 1;

  test_msg.states[3].cn0 = 38.81692886352539;
  test_msg.states[3].sid.code = 0;
  test_msg.states[3].sid.reserved = 0;
  test_msg.states[3].sid.sat = 212;
  test_msg.states[3].state = 1;

  test_msg.states[4].cn0 = 42.05073165893555;
  test_msg.states[4].sid.code = 0;
  test_msg.states[4].sid.reserved = 0;
  test_msg.states[4].sid.sat = 217;
  test_msg.states[4].state = 1;

  test_msg.states[5].cn0 = 37.807498931884766;
  test_msg.states[5].sid.code = 0;
  test_msg.states[5].sid.reserved = 0;
  test_msg.states[5].sid.sat = 218;
  test_msg.states[5].state = 1;

  test_msg.states[6].cn0 = 37.71632385253906;
  test_msg.states[6].sid.code = 0;
  test_msg.states[6].sid.reserved = 0;
  test_msg.states[6].sid.sat = 220;
  test_msg.states[6].state = 1;

  test_msg.states[7].cn0 = 38.5289192199707;
  test_msg.states[7].sid.code = 0;
  test_msg.states[7].sid.reserved = 0;
  test_msg.states[7].sid.sat = 222;
  test_msg.states[7].state = 1;

  test_msg.states[8].cn0 = 42.27101516723633;
  test_msg.states[8].sid.code = 0;
  test_msg.states[8].sid.reserved = 0;
  test_msg.states[8].sid.sat = 225;
  test_msg.states[8].state = 1;

  test_msg.states[9].cn0 = -1.0;
  test_msg.states[9].sid.code = 0;
  test_msg.states[9].sid.reserved = 0;
  test_msg.states[9].sid.sat = 0;
  test_msg.states[9].state = 0;

  test_msg.states[10].cn0 = -1.0;
  test_msg.states[10].sid.code = 0;
  test_msg.states[10].sid.reserved = 0;
  test_msg.states[10].sid.sat = 0;
  test_msg.states[10].state = 0;

  EXPECT_EQ(send_message(55286, test_msg), SBP_OK);

  EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));
  EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);

  while (dummy_rd_ < dummy_wr_) {
    process();
  }

  EXPECT_EQ(n_callbacks_logged_, 1);
  EXPECT_EQ(last_sender_id_, 55286);
  EXPECT_EQ(last_msg_, test_msg);
  EXPECT_EQ(last_msg_.n_states, 11)
      << "incorrect value for last_msg_.n_states, expected 11, is "
      << last_msg_.n_states;
  EXPECT_LT((last_msg_.states[0].cn0 * 100 - 39.7035179138 * 100), 0.05)
      << "incorrect value for last_msg_.states[0].cn0, expected 39.7035179138, "
         "is "
      << last_msg_.states[0].cn0;
  EXPECT_EQ(last_msg_.states[0].sid.code, 0)
      << "incorrect value for last_msg_.states[0].sid.code, expected 0, is "
      << last_msg_.states[0].sid.code;
  EXPECT_EQ(last_msg_.states[0].sid.reserved, 0)
      << "incorrect value for last_msg_.states[0].sid.reserved, expected 0, is "
      << last_msg_.states[0].sid.reserved;
  EXPECT_EQ(last_msg_.states[0].sid.sat, 202)
      << "incorrect value for last_msg_.states[0].sid.sat, expected 202, is "
      << last_msg_.states[0].sid.sat;
  EXPECT_EQ(last_msg_.states[0].state, 1)
      << "incorrect value for last_msg_.states[0].state, expected 1, is "
      << last_msg_.states[0].state;
  EXPECT_LT((last_msg_.states[1].cn0 * 100 - 36.5238838196 * 100), 0.05)
      << "incorrect value for last_msg_.states[1].cn0, expected 36.5238838196, "
         "is "
      << last_msg_.states[1].cn0;
  EXPECT_EQ(last_msg_.states[1].sid.code, 0)
      << "incorrect value for last_msg_.states[1].sid.code, expected 0, is "
      << last_msg_.states[1].sid.code;
  EXPECT_EQ(last_msg_.states[1].sid.reserved, 0)
      << "incorrect value for last_msg_.states[1].sid.reserved, expected 0, is "
      << last_msg_.states[1].sid.reserved;
  EXPECT_EQ(last_msg_.states[1].sid.sat, 203)
      << "incorrect value for last_msg_.states[1].sid.sat, expected 203, is "
      << last_msg_.states[1].sid.sat;
  EXPECT_EQ(last_msg_.states[1].state, 1)
      << "incorrect value for last_msg_.states[1].state, expected 1, is "
      << last_msg_.states[1].state;
  EXPECT_LT((last_msg_.states[2].cn0 * 100 - 37.169708252 * 100), 0.05)
      << "incorrect value for last_msg_.states[2].cn0, expected 37.169708252, "
         "is "
      << last_msg_.states[2].cn0;
  EXPECT_EQ(last_msg_.states[2].sid.code, 0)
      << "incorrect value for last_msg_.states[2].sid.code, expected 0, is "
      << last_msg_.states[2].sid.code;
  EXPECT_EQ(last_msg_.states[2].sid.reserved, 0)
      << "incorrect value for last_msg_.states[2].sid.reserved, expected 0, is "
      << last_msg_.states[2].sid.reserved;
  EXPECT_EQ(last_msg_.states[2].sid.sat, 208)
      << "incorrect value for last_msg_.states[2].sid.sat, expected 208, is "
      << last_msg_.states[2].sid.sat;
  EXPECT_EQ(last_msg_.states[2].state, 1)
      << "incorrect value for last_msg_.states[2].state, expected 1, is "
      << last_msg_.states[2].state;
  EXPECT_LT((last_msg_.states[3].cn0 * 100 - 38.8169288635 * 100), 0.05)
      << "incorrect value for last_msg_.states[3].cn0, expected 38.8169288635, "
         "is "
      << last_msg_.states[3].cn0;
  EXPECT_EQ(last_msg_.states[3].sid.code, 0)
      << "incorrect value for last_msg_.states[3].sid.code, expected 0, is "
      << last_msg_.states[3].sid.code;
  EXPECT_EQ(last_msg_.states[3].sid.reserved, 0)
      << "incorrect value for last_msg_.states[3].sid.reserved, expected 0, is "
      << last_msg_.states[3].sid.reserved;
  EXPECT_EQ(last_msg_.states[3].sid.sat, 212)
      << "incorrect value for last_msg_.states[3].sid.sat, expected 212, is "
      << last_msg_.states[3].sid.sat;
  EXPECT_EQ(last_msg_.states[3].state, 1)
      << "incorrect value for last_msg_.states[3].state, expected 1, is "
      << last_msg_.states[3].state;
  EXPECT_LT((last_msg_.states[4].cn0 * 100 - 42.0507316589 * 100), 0.05)
      << "incorrect value for last_msg_.states[4].cn0, expected 42.0507316589, "
         "is "
      << last_msg_.states[4].cn0;
  EXPECT_EQ(last_msg_.states[4].sid.code, 0)
      << "incorrect value for last_msg_.states[4].sid.code, expected 0, is "
      << last_msg_.states[4].sid.code;
  EXPECT_EQ(last_msg_.states[4].sid.reserved, 0)
      << "incorrect value for last_msg_.states[4].sid.reserved, expected 0, is "
      << last_msg_.states[4].sid.reserved;
  EXPECT_EQ(last_msg_.states[4].sid.sat, 217)
      << "incorrect value for last_msg_.states[4].sid.sat, expected 217, is "
      << last_msg_.states[4].sid.sat;
  EXPECT_EQ(last_msg_.states[4].state, 1)
      << "incorrect value for last_msg_.states[4].state, expected 1, is "
      << last_msg_.states[4].state;
  EXPECT_LT((last_msg_.states[5].cn0 * 100 - 37.8074989319 * 100), 0.05)
      << "incorrect value for last_msg_.states[5].cn0, expected 37.8074989319, "
         "is "
      << last_msg_.states[5].cn0;
  EXPECT_EQ(last_msg_.states[5].sid.code, 0)
      << "incorrect value for last_msg_.states[5].sid.code, expected 0, is "
      << last_msg_.states[5].sid.code;
  EXPECT_EQ(last_msg_.states[5].sid.reserved, 0)
      << "incorrect value for last_msg_.states[5].sid.reserved, expected 0, is "
      << last_msg_.states[5].sid.reserved;
  EXPECT_EQ(last_msg_.states[5].sid.sat, 218)
      << "incorrect value for last_msg_.states[5].sid.sat, expected 218, is "
      << last_msg_.states[5].sid.sat;
  EXPECT_EQ(last_msg_.states[5].state, 1)
      << "incorrect value for last_msg_.states[5].state, expected 1, is "
      << last_msg_.states[5].state;
  EXPECT_LT((last_msg_.states[6].cn0 * 100 - 37.7163238525 * 100), 0.05)
      << "incorrect value for last_msg_.states[6].cn0, expected 37.7163238525, "
         "is "
      << last_msg_.states[6].cn0;
  EXPECT_EQ(last_msg_.states[6].sid.code, 0)
      << "incorrect value for last_msg_.states[6].sid.code, expected 0, is "
      << last_msg_.states[6].sid.code;
  EXPECT_EQ(last_msg_.states[6].sid.reserved, 0)
      << "incorrect value for last_msg_.states[6].sid.reserved, expected 0, is "
      << last_msg_.states[6].sid.reserved;
  EXPECT_EQ(last_msg_.states[6].sid.sat, 220)
      << "incorrect value for last_msg_.states[6].sid.sat, expected 220, is "
      << last_msg_.states[6].sid.sat;
  EXPECT_EQ(last_msg_.states[6].state, 1)
      << "incorrect value for last_msg_.states[6].state, expected 1, is "
      << last_msg_.states[6].state;
  EXPECT_LT((last_msg_.states[7].cn0 * 100 - 38.52891922 * 100), 0.05)
      << "incorrect value for last_msg_.states[7].cn0, expected 38.52891922, "
         "is "
      << last_msg_.states[7].cn0;
  EXPECT_EQ(last_msg_.states[7].sid.code, 0)
      << "incorrect value for last_msg_.states[7].sid.code, expected 0, is "
      << last_msg_.states[7].sid.code;
  EXPECT_EQ(last_msg_.states[7].sid.reserved, 0)
      << "incorrect value for last_msg_.states[7].sid.reserved, expected 0, is "
      << last_msg_.states[7].sid.reserved;
  EXPECT_EQ(last_msg_.states[7].sid.sat, 222)
      << "incorrect value for last_msg_.states[7].sid.sat, expected 222, is "
      << last_msg_.states[7].sid.sat;
  EXPECT_EQ(last_msg_.states[7].state, 1)
      << "incorrect value for last_msg_.states[7].state, expected 1, is "
      << last_msg_.states[7].state;
  EXPECT_LT((last_msg_.states[8].cn0 * 100 - 42.2710151672 * 100), 0.05)
      << "incorrect value for last_msg_.states[8].cn0, expected 42.2710151672, "
         "is "
      << last_msg_.states[8].cn0;
  EXPECT_EQ(last_msg_.states[8].sid.code, 0)
      << "incorrect value for last_msg_.states[8].sid.code, expected 0, is "
      << last_msg_.states[8].sid.code;
  EXPECT_EQ(last_msg_.states[8].sid.reserved, 0)
      << "incorrect value for last_msg_.states[8].sid.reserved, expected 0, is "
      << last_msg_.states[8].sid.reserved;
  EXPECT_EQ(last_msg_.states[8].sid.sat, 225)
      << "incorrect value for last_msg_.states[8].sid.sat, expected 225, is "
      << last_msg_.states[8].sid.sat;
  EXPECT_EQ(last_msg_.states[8].state, 1)
      << "incorrect value for last_msg_.states[8].state, expected 1, is "
      << last_msg_.states[8].state;
  EXPECT_LT((last_msg_.states[9].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for last_msg_.states[9].cn0, expected -1.0, is "
      << last_msg_.states[9].cn0;
  EXPECT_EQ(last_msg_.states[9].sid.code, 0)
      << "incorrect value for last_msg_.states[9].sid.code, expected 0, is "
      << last_msg_.states[9].sid.code;
  EXPECT_EQ(last_msg_.states[9].sid.reserved, 0)
      << "incorrect value for last_msg_.states[9].sid.reserved, expected 0, is "
      << last_msg_.states[9].sid.reserved;
  EXPECT_EQ(last_msg_.states[9].sid.sat, 0)
      << "incorrect value for last_msg_.states[9].sid.sat, expected 0, is "
      << last_msg_.states[9].sid.sat;
  EXPECT_EQ(last_msg_.states[9].state, 0)
      << "incorrect value for last_msg_.states[9].state, expected 0, is "
      << last_msg_.states[9].state;
  EXPECT_LT((last_msg_.states[10].cn0 * 100 - -1.0 * 100), 0.05)
      << "incorrect value for last_msg_.states[10].cn0, expected -1.0, is "
      << last_msg_.states[10].cn0;
  EXPECT_EQ(last_msg_.states[10].sid.code, 0)
      << "incorrect value for last_msg_.states[10].sid.code, expected 0, is "
      << last_msg_.states[10].sid.code;
  EXPECT_EQ(last_msg_.states[10].sid.reserved, 0)
      << "incorrect value for last_msg_.states[10].sid.reserved, expected 0, "
         "is "
      << last_msg_.states[10].sid.reserved;
  EXPECT_EQ(last_msg_.states[10].sid.sat, 0)
      << "incorrect value for last_msg_.states[10].sid.sat, expected 0, is "
      << last_msg_.states[10].sid.sat;
  EXPECT_EQ(last_msg_.states[10].state, 0)
      << "incorrect value for last_msg_.states[10].state, expected 0, is "
      << last_msg_.states[10].state;
}
