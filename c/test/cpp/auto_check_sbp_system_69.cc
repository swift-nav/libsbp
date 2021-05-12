#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_system_690 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_group_meta_t>
{
public:
  Test_auto_check_sbp_system_690() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_group_meta_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
  {
    set_reader(this);
    set_writer(this);
  }

  s32 read(uint8_t *buf, const uint32_t n) override {
    uint32_t real_n = n;
    memcpy(buf, io_buf_ + rd_, real_n);
    rd_ += real_n;
    return (s32)real_n;
  }

  s32 write(const uint8_t *buf, uint32_t n) override {
    uint32_t real_n = n;
    memcpy(io_buf_ + wr_, buf, real_n);
    wr_ += real_n;
    return (s32)real_n;
  }


protected:

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_group_meta_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_group_meta_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_system_690, Test)     
{

    uint8_t encoded_frame[] = {85,10,255,238,238,9,1,2,3,10,255,10,2,2,255,2,14, };

    sbp_msg_group_meta_t test_unpacked_msg{};
    test_unpacked_msg.flags = 2;
    test_unpacked_msg.group_id = 1;
    
    test_unpacked_msg.group_msgs[0] = 65290;
    
    test_unpacked_msg.group_msgs[1] = 522;
    
    test_unpacked_msg.group_msgs[2] = 65282;
    test_unpacked_msg.n_group_msgs = 3;
                                                                              
    EXPECT_EQ(send_message( 61166, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 61166);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 2);
    EXPECT_EQ(last_msg_.group_id, 1);
    EXPECT_EQ(last_msg_.group_msgs[0], 65290);
    EXPECT_EQ(last_msg_.group_msgs[1], 522);
    EXPECT_EQ(last_msg_.group_msgs[2], 65282);
    EXPECT_EQ(last_msg_.n_group_msgs, 3);
}                                                     
class Test_auto_check_sbp_system_691 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_group_meta_t>
{
public:
  Test_auto_check_sbp_system_691() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_group_meta_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
  {
    set_reader(this);
    set_writer(this);
  }

  s32 read(uint8_t *buf, const uint32_t n) override {
    uint32_t real_n = n;
    memcpy(buf, io_buf_ + rd_, real_n);
    rd_ += real_n;
    return (s32)real_n;
  }

  s32 write(const uint8_t *buf, uint32_t n) override {
    uint32_t real_n = n;
    memcpy(io_buf_ + wr_, buf, real_n);
    wr_ += real_n;
    return (s32)real_n;
  }


protected:

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_group_meta_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_group_meta_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_system_691, Test)     
{

    uint8_t encoded_frame[] = {85,10,255,21,3,31,1,1,14,2,1,3,1,10,2,17,2,9,2,20,2,14,2,18,2,13,2,21,2,33,2,3,255,6,255,14,255,82,154, };

    sbp_msg_group_meta_t test_unpacked_msg{};
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.group_id = 1;
    
    test_unpacked_msg.group_msgs[0] = 258;
    
    test_unpacked_msg.group_msgs[1] = 259;
    
    test_unpacked_msg.group_msgs[2] = 522;
    
    test_unpacked_msg.group_msgs[3] = 529;
    
    test_unpacked_msg.group_msgs[4] = 521;
    
    test_unpacked_msg.group_msgs[5] = 532;
    
    test_unpacked_msg.group_msgs[6] = 526;
    
    test_unpacked_msg.group_msgs[7] = 530;
    
    test_unpacked_msg.group_msgs[8] = 525;
    
    test_unpacked_msg.group_msgs[9] = 533;
    
    test_unpacked_msg.group_msgs[10] = 545;
    
    test_unpacked_msg.group_msgs[11] = 65283;
    
    test_unpacked_msg.group_msgs[12] = 65286;
    
    test_unpacked_msg.group_msgs[13] = 65294;
    test_unpacked_msg.n_group_msgs = 14;
                                                                              
    EXPECT_EQ(send_message( 789, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 789);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.group_id, 1);
    EXPECT_EQ(last_msg_.group_msgs[0], 258);
    EXPECT_EQ(last_msg_.group_msgs[1], 259);
    EXPECT_EQ(last_msg_.group_msgs[2], 522);
    EXPECT_EQ(last_msg_.group_msgs[3], 529);
    EXPECT_EQ(last_msg_.group_msgs[4], 521);
    EXPECT_EQ(last_msg_.group_msgs[5], 532);
    EXPECT_EQ(last_msg_.group_msgs[6], 526);
    EXPECT_EQ(last_msg_.group_msgs[7], 530);
    EXPECT_EQ(last_msg_.group_msgs[8], 525);
    EXPECT_EQ(last_msg_.group_msgs[9], 533);
    EXPECT_EQ(last_msg_.group_msgs[10], 545);
    EXPECT_EQ(last_msg_.group_msgs[11], 65283);
    EXPECT_EQ(last_msg_.group_msgs[12], 65286);
    EXPECT_EQ(last_msg_.group_msgs[13], 65294);
    EXPECT_EQ(last_msg_.n_group_msgs, 14);
}