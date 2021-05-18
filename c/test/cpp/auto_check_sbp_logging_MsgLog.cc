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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/logging/test_MsgLog.yaml by generate.py. Do not modify by hand!

#include <cstring>
#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_logging_MsgLog0 : 
  public ::testing::Test, 
  public sbp::State, 
  public sbp::IReader, 
  public sbp::IWriter, 
  sbp::MessageHandler<sbp_msg_log_t>
{
public:
  Test_auto_check_sbp_logging_MsgLog0() : 
        ::testing::Test(), 
        sbp::State(), 
        sbp::IReader(), 
        sbp::IWriter(), 
        sbp::MessageHandler<sbp_msg_log_t>(this), 
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_log_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_log_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_logging_MsgLog0, Test)     
{

    uint8_t encoded_frame[] = {85,1,4,10,9,44,6,70,105,108,116,101,114,101,100,32,97,108,108,32,111,98,115,32,102,114,111,109,32,50,51,49,52,32,97,116,32,116,111,119,32,56,51,46,53,51,57,48,49,57,177,163, };

    sbp_msg_log_t test_msg{};
    test_msg.level = 6;
    {
      const char assign_string[] = { (char)70,(char)105,(char)108,(char)116,(char)101,(char)114,(char)101,(char)100,(char)32,(char)97,(char)108,(char)108,(char)32,(char)111,(char)98,(char)115,(char)32,(char)102,(char)114,(char)111,(char)109,(char)32,(char)50,(char)51,(char)49,(char)52,(char)32,(char)97,(char)116,(char)32,(char)116,(char)111,(char)119,(char)32,(char)56,(char)51,(char)46,(char)53,(char)51,(char)57,(char)48,(char)49,(char)57 };
      memcpy(test_msg.text.data, assign_string, sizeof(assign_string));
    }
    test_msg.text.len = 43;
                                                                              
    EXPECT_EQ(send_message( 2314, test_msg), SBP_OK);
                                                                              
    EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (dummy_rd_ < dummy_wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 2314);
    EXPECT_EQ(last_msg_, test_msg);
    EXPECT_EQ(last_msg_.level, 6) << "incorrect value for level, expected 6, is " << last_msg_.level;
    {
      const char check_string[] = { (char)70,(char)105,(char)108,(char)116,(char)101,(char)114,(char)101,(char)100,(char)32,(char)97,(char)108,(char)108,(char)32,(char)111,(char)98,(char)115,(char)32,(char)102,(char)114,(char)111,(char)109,(char)32,(char)50,(char)51,(char)49,(char)52,(char)32,(char)97,(char)116,(char)32,(char)116,(char)111,(char)119,(char)32,(char)56,(char)51,(char)46,(char)53,(char)51,(char)57,(char)48,(char)49,(char)57 };
      EXPECT_EQ(memcmp(last_msg_.text.data, check_string, sizeof(check_string)), 0) << "incorrect value for last_msg_.text.data, expected string '" << check_string << "', is '" << last_msg_.text.data << "'";
    }
    EXPECT_EQ(last_msg_.text.len, 43) << "incorrect value for text.len, expected 43, is " << last_msg_.text.len;
}
