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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgFwd.yaml by generate.py. Do not modify by hand!

#include <cstring>
#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/unpacked_message_traits.h>
#include <libsbp/cpp/unpacked_handler.h>                                                     
class Test_auto_check_sbp_logging_MsgFwd0 : 
  public ::testing::Test, 
  public sbp::State, 
  public sbp::IReader, 
  public sbp::IWriter, 
  sbp::UnpackedMessageHandler<sbp_msg_fwd_t>
{
public:
  Test_auto_check_sbp_logging_MsgFwd0() : 
        ::testing::Test(), 
        sbp::State(), 
        sbp::IReader(), 
        sbp::IWriter(), 
        sbp::UnpackedMessageHandler<sbp_msg_fwd_t>(this), 
        last_msg_(),
        last_msg_len_(),
        last_sender_id_(), 
        n_callbacks_logged_(), 
        dummy_wr_(), 
        dummy_rd_(), 
        dummy_buff_()
  {
    set_reader(this);
    set_writer(this);
  }

  s32 read(uint8_t *buf, const uint32_t n) override
  {
    uint32_t real_n = n;
    memcpy(buf, dummy_buff_ + dummy_rd_, real_n);
    dummy_rd_ += real_n;
    return (s32)real_n;
  }

  s32 write(const uint8_t *buf, uint32_t n) override
  {
    uint32_t real_n = n;
    memcpy(dummy_buff_ + dummy_wr_, buf, real_n);
    dummy_wr_ += real_n;
    return (s32)real_n;
  }


protected:

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_fwd_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_fwd_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_logging_MsgFwd0, Test)     
{

    uint8_t encoded_frame[] = {85,2,4,66,0,18,0,0,86,81,68,47,81,103,65,69,65,65,65,65,65,69,97,103,125,95, };

    sbp_msg_fwd_t test_msg{};
    {
      const char assign_string[] = { (char)86,(char)81,(char)68,(char)47,(char)81,(char)103,(char)65,(char)69,(char)65,(char)65,(char)65,(char)65,(char)65,(char)69,(char)97,(char)103 };
      memcpy(test_msg.fwd_payload.data, assign_string, sizeof(assign_string));
    }
    test_msg.fwd_payload.packed_len = 16;
    test_msg.protocol = 0;
    test_msg.source = 0;
                                                                              
    EXPECT_EQ(send_message( 66, test_msg), SBP_OK);
                                                                              
    EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (dummy_rd_ < dummy_wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 66);
    EXPECT_EQ(last_msg_, test_msg);
    {
      const char check_string[] = { (char)86,(char)81,(char)68,(char)47,(char)81,(char)103,(char)65,(char)69,(char)65,(char)65,(char)65,(char)65,(char)65,(char)69,(char)97,(char)103 };
      EXPECT_EQ(memcmp(last_msg_.fwd_payload.data, check_string, sizeof(check_string)), 0) << "incorrect value for last_msg_.fwd_payload.data, expected string '" << check_string << "', is '" << last_msg_.fwd_payload.data << "'";
    }
    EXPECT_EQ(last_msg_.fwd_payload.packed_len, 16) << "incorrect value for fwd_payload.packed_len, expected 16, is " << last_msg_.fwd_payload.packed_len;
    EXPECT_EQ(last_msg_.protocol, 0) << "incorrect value for protocol, expected 0, is " << last_msg_.protocol;
    EXPECT_EQ(last_msg_.source, 0) << "incorrect value for source, expected 0, is " << last_msg_.source;
}
