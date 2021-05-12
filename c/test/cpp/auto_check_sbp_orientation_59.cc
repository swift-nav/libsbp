#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_orientation_590 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_orient_euler_t>
{
public:
  Test_auto_check_sbp_orientation_590() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_orient_euler_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_orient_euler_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_orient_euler_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_orientation_590, Test)     
{

    uint8_t encoded_frame[] = {85,33,2,66,0,29,1,0,0,0,1,0,0,0,2,0,0,0,8,0,0,0,0,0,224,64,0,0,64,64,0,0,224,64,3,44,226, };

    sbp_msg_orient_euler_t test_unpacked_msg{};
    test_unpacked_msg.flags = 3;
    test_unpacked_msg.pitch = 2;
    test_unpacked_msg.pitch_accuracy = 3.0;
    test_unpacked_msg.roll = 1;
    test_unpacked_msg.roll_accuracy = 7.0;
    test_unpacked_msg.tow = 1;
    test_unpacked_msg.yaw = 8;
    test_unpacked_msg.yaw_accuracy = 7.0;
                                                                              
    EXPECT_EQ(send_message( 66, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 66);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 3);
    EXPECT_EQ(last_msg_.pitch, 2);
    EXPECT_LT((last_msg_.pitch_accuracy*100 - 3.0*100), 0.05);
    EXPECT_EQ(last_msg_.roll, 1);
    EXPECT_LT((last_msg_.roll_accuracy*100 - 7.0*100), 0.05);
    EXPECT_EQ(last_msg_.tow, 1);
    EXPECT_EQ(last_msg_.yaw, 8);
    EXPECT_LT((last_msg_.yaw_accuracy*100 - 7.0*100), 0.05);
}