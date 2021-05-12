#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_270 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_cov_t>
{
public:
  Test_auto_check_sbp_navigation_270() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_cov_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_cov_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_cov_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_270, Test)     
{

    uint8_t encoded_frame[] = {85,17,2,66,0,54,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,28,64,0,0,0,0,0,0,0,0,0,0,224,64,0,0,160,64,0,0,0,65,0,0,192,64,0,0,128,63,0,0,0,64,5,5,151,98, };

    sbp_msg_pos_llh_cov_t test_unpacked_msg{};
    test_unpacked_msg.cov_d_d = 2.0;
    test_unpacked_msg.cov_e_d = 1.0;
    test_unpacked_msg.cov_e_e = 6.0;
    test_unpacked_msg.cov_n_d = 8.0;
    test_unpacked_msg.cov_n_e = 5.0;
    test_unpacked_msg.cov_n_n = 7.0;
    test_unpacked_msg.flags = 5;
    test_unpacked_msg.height = 0.0;
    test_unpacked_msg.lat = 0.0;
    test_unpacked_msg.lon = 7.0;
    test_unpacked_msg.n_sats = 5;
    test_unpacked_msg.tow = 7;
                                                                              
    EXPECT_EQ(send_message( 66, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 66);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cov_d_d*100 - 2.0*100), 0.05);
    EXPECT_LT((last_msg_.cov_e_d*100 - 1.0*100), 0.05);
    EXPECT_LT((last_msg_.cov_e_e*100 - 6.0*100), 0.05);
    EXPECT_LT((last_msg_.cov_n_d*100 - 8.0*100), 0.05);
    EXPECT_LT((last_msg_.cov_n_e*100 - 5.0*100), 0.05);
    EXPECT_LT((last_msg_.cov_n_n*100 - 7.0*100), 0.05);
    EXPECT_EQ(last_msg_.flags, 5);
    EXPECT_LT((last_msg_.height*100 - 0.0*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 0.0*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - 7.0*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 5);
    EXPECT_EQ(last_msg_.tow, 7);
}