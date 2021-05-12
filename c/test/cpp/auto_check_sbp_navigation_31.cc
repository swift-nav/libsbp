#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_310 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_protection_level_t>
{
public:
  Test_auto_check_sbp_navigation_310() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_protection_level_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_protection_level_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_protection_level_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_310, Test)     
{

    uint8_t encoded_frame[] = {85,22,2,0,16,33,136,227,233,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,82,195, };

    sbp_msg_protection_level_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.height = 0.0;
    test_unpacked_msg.hpl = 0;
    test_unpacked_msg.lat = 0.0;
    test_unpacked_msg.lon = 0.0;
    test_unpacked_msg.tow = 501867400;
    test_unpacked_msg.vpl = 0;
                                                                              
    EXPECT_EQ(send_message( 4096, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 4096);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_LT((last_msg_.height*100 - 0.0*100), 0.05);
    EXPECT_EQ(last_msg_.hpl, 0);
    EXPECT_LT((last_msg_.lat*100 - 0.0*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - 0.0*100), 0.05);
    EXPECT_EQ(last_msg_.tow, 501867400);
    EXPECT_EQ(last_msg_.vpl, 0);
}