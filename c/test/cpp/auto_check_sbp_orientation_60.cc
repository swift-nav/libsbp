#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_orientation_600 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_orient_quat_t>
{
public:
  Test_auto_check_sbp_orientation_600() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_orient_quat_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_orient_quat_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_orient_quat_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_orientation_600, Test)     
{

    uint8_t encoded_frame[] = {85,32,2,66,0,37,0,0,0,0,3,0,0,0,7,0,0,0,8,0,0,0,4,0,0,0,0,0,64,64,0,0,128,64,0,0,0,65,0,0,64,64,1,186,6, };

    sbp_msg_orient_quat_t test_unpacked_msg{};
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.tow = 0;
    test_unpacked_msg.w = 3;
    test_unpacked_msg.w_accuracy = 3.0;
    test_unpacked_msg.x = 7;
    test_unpacked_msg.x_accuracy = 4.0;
    test_unpacked_msg.y = 8;
    test_unpacked_msg.y_accuracy = 8.0;
    test_unpacked_msg.z = 4;
    test_unpacked_msg.z_accuracy = 3.0;
                                                                              
    EXPECT_EQ(send_message( 66, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 66);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.tow, 0);
    EXPECT_EQ(last_msg_.w, 3);
    EXPECT_LT((last_msg_.w_accuracy*100 - 3.0*100), 0.05);
    EXPECT_EQ(last_msg_.x, 7);
    EXPECT_LT((last_msg_.x_accuracy*100 - 4.0*100), 0.05);
    EXPECT_EQ(last_msg_.y, 8);
    EXPECT_LT((last_msg_.y_accuracy*100 - 8.0*100), 0.05);
    EXPECT_EQ(last_msg_.z, 4);
    EXPECT_LT((last_msg_.z_accuracy*100 - 3.0*100), 0.05);
}