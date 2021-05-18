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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/bootload/test_MsgBootloaderHandshakeResp.yaml by generate.py. Do not modify by hand!

#include <cstring>
#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_bootload_MsgBootloaderHandshakeResp0 : 
  public ::testing::Test, 
  public sbp::State, 
  public sbp::IReader, 
  public sbp::IWriter, 
  sbp::MessageHandler<sbp_msg_bootloader_handshake_resp_t>
{
public:
  Test_auto_check_sbp_bootload_MsgBootloaderHandshakeResp0() : 
        ::testing::Test(), 
        sbp::State(), 
        sbp::IReader(), 
        sbp::IWriter(), 
        sbp::MessageHandler<sbp_msg_bootloader_handshake_resp_t>(this), 
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_bootloader_handshake_resp_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_bootloader_handshake_resp_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_bootload_MsgBootloaderHandshakeResp0, Test)     
{

    uint8_t encoded_frame[] = {85,180,0,0,0,9,0,0,0,0,118,49,46,50,10,201,1, };

    sbp_msg_bootloader_handshake_resp_t test_msg{};
    test_msg.flags = 0;
    {
      const char assign_string[] = { (char)118,(char)49,(char)46,(char)50,(char)10 };
      memcpy(test_msg.version.data, assign_string, sizeof(assign_string));
    }
    test_msg.version.len = 5;
                                                                              
    EXPECT_EQ(send_message( 0, test_msg), SBP_OK);
                                                                              
    EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (dummy_rd_ < dummy_wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 0);
    EXPECT_EQ(last_msg_, test_msg);
    EXPECT_EQ(last_msg_.flags, 0) << "incorrect value for flags, expected 0, is " << last_msg_.flags;
    {
      const char check_string[] = { (char)118,(char)49,(char)46,(char)50,(char)10 };
      EXPECT_EQ(memcmp(last_msg_.version.data, check_string, sizeof(check_string)), 0) << "incorrect value for last_msg_.version.data, expected string '" << check_string << "', is '" << last_msg_.version.data << "'";
    }
    EXPECT_EQ(last_msg_.version.len, 5) << "incorrect value for version.len, expected 5, is " << last_msg_.version.len;
}                                                     
class Test_auto_check_sbp_bootload_MsgBootloaderHandshakeResp1 : 
  public ::testing::Test, 
  public sbp::State, 
  public sbp::IReader, 
  public sbp::IWriter, 
  sbp::MessageHandler<sbp_msg_bootloader_handshake_dep_a_t>
{
public:
  Test_auto_check_sbp_bootload_MsgBootloaderHandshakeResp1() : 
        ::testing::Test(), 
        sbp::State(), 
        sbp::IReader(), 
        sbp::IWriter(), 
        sbp::MessageHandler<sbp_msg_bootloader_handshake_dep_a_t>(this), 
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_bootloader_handshake_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_bootloader_handshake_dep_a_t last_msg_;
  uint8_t last_msg_len_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t dummy_wr_;
  uint32_t dummy_rd_;
  uint8_t dummy_buff_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_bootload_MsgBootloaderHandshakeResp1, Test)     
{

    uint8_t encoded_frame[] = {85,176,0,195,4,4,118,49,46,50,1,206, };

    sbp_msg_bootloader_handshake_dep_a_t test_msg{};
    test_msg.handshake.data[0] = 118;
    test_msg.handshake.data[1] = 49;
    test_msg.handshake.data[2] = 46;
    test_msg.handshake.data[3] = 50;
    test_msg.handshake.len = 4;
                                                                              
    EXPECT_EQ(send_message( 1219, test_msg), SBP_OK);
                                                                              
    EXPECT_EQ(dummy_wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(dummy_buff_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (dummy_rd_ < dummy_wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(last_msg_, test_msg);
    EXPECT_EQ(last_msg_.handshake.data[0], 118) << "incorrect value for handshake.data[0], expected 118, is " << last_msg_.handshake.data[0];
    EXPECT_EQ(last_msg_.handshake.data[1], 49) << "incorrect value for handshake.data[1], expected 49, is " << last_msg_.handshake.data[1];
    EXPECT_EQ(last_msg_.handshake.data[2], 46) << "incorrect value for handshake.data[2], expected 46, is " << last_msg_.handshake.data[2];
    EXPECT_EQ(last_msg_.handshake.data[3], 50) << "incorrect value for handshake.data[3], expected 50, is " << last_msg_.handshake.data[3];
    EXPECT_EQ(last_msg_.handshake.len, 4) << "incorrect value for handshake.len, expected 4, is " << last_msg_.handshake.len;
}
