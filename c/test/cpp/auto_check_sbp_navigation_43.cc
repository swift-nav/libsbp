#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_430 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_cov_gnss_t>
{
public:
  Test_auto_check_sbp_navigation_430() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_cov_gnss_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_cov_gnss_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_cov_gnss_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_430, Test)     
{

    uint8_t encoded_frame[] = {85,50,2,0,16,42,168,230,233,29,251,255,255,255,0,0,0,0,246,255,255,255,15,58,207,58,248,139,116,55,103,197,57,57,203,186,129,58,109,171,44,57,135,39,1,60,21,2,155,3, };

    sbp_msg_vel_ned_cov_gnss_t test_unpacked_msg{};
    test_unpacked_msg.cov_d_d = 0.007882959209382534;
    test_unpacked_msg.cov_e_d = 0.00016467059322167188;
    test_unpacked_msg.cov_e_e = 0.0009897587588056922;
    test_unpacked_msg.cov_n_d = 0.00017716512957122177;
    test_unpacked_msg.cov_n_e = 1.457612233934924e-05;
    test_unpacked_msg.cov_n_n = 0.0015810149488970637;
    test_unpacked_msg.d = -10;
    test_unpacked_msg.e = 0;
    test_unpacked_msg.flags = 2;
    test_unpacked_msg.n = -5;
    test_unpacked_msg.n_sats = 21;
    test_unpacked_msg.tow = 501868200;
                                                                              
    EXPECT_EQ(send_message( 4096, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 4096);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cov_d_d*100 - 0.00788295920938*100), 0.05);
    EXPECT_LT((last_msg_.cov_e_d*100 - 0.000164670593222*100), 0.05);
    EXPECT_LT((last_msg_.cov_e_e*100 - 0.000989758758806*100), 0.05);
    EXPECT_LT((last_msg_.cov_n_d*100 - 0.000177165129571*100), 0.05);
    EXPECT_LT((last_msg_.cov_n_e*100 - 1.45761223393e-05*100), 0.05);
    EXPECT_LT((last_msg_.cov_n_n*100 - 0.0015810149489*100), 0.05);
    EXPECT_EQ(last_msg_.d, -10);
    EXPECT_EQ(last_msg_.e, 0);
    EXPECT_EQ(last_msg_.flags, 2);
    EXPECT_EQ(last_msg_.n, -5);
    EXPECT_EQ(last_msg_.n_sats, 21);
    EXPECT_EQ(last_msg_.tow, 501868200);
}