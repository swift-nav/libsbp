#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_380 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ecef_cov_gnss_t>
{
public:
  Test_auto_check_sbp_navigation_380() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ecef_cov_gnss_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ecef_cov_gnss_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ecef_cov_gnss_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_380, Test)     
{

    uint8_t encoded_frame[] = {85,53,2,0,16,42,224,229,233,29,253,255,255,255,1,0,0,0,4,0,0,0,46,224,32,59,32,214,14,59,150,147,220,186,19,63,138,59,26,150,35,187,11,193,119,59,21,2,22,230, };

    sbp_msg_vel_ecef_cov_gnss_t test_unpacked_msg{};
    test_unpacked_msg.cov_x_x = 0.0024547684006392956;
    test_unpacked_msg.cov_x_y = 0.0021795108914375305;
    test_unpacked_msg.cov_x_z = -0.0016828652005642653;
    test_unpacked_msg.cov_y_y = 0.004218944814056158;
    test_unpacked_msg.cov_y_z = -0.0024961293675005436;
    test_unpacked_msg.cov_z_z = 0.0037804271560162306;
    test_unpacked_msg.flags = 2;
    test_unpacked_msg.n_sats = 21;
    test_unpacked_msg.tow = 501868000;
    test_unpacked_msg.x = -3;
    test_unpacked_msg.y = 1;
    test_unpacked_msg.z = 4;
                                                                              
    EXPECT_EQ(send_message( 4096, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 4096);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cov_x_x*100 - 0.00245476840064*100), 0.05);
    EXPECT_LT((last_msg_.cov_x_y*100 - 0.00217951089144*100), 0.05);
    EXPECT_LT((last_msg_.cov_x_z*100 - -0.00168286520056*100), 0.05);
    EXPECT_LT((last_msg_.cov_y_y*100 - 0.00421894481406*100), 0.05);
    EXPECT_LT((last_msg_.cov_y_z*100 - -0.0024961293675*100), 0.05);
    EXPECT_LT((last_msg_.cov_z_z*100 - 0.00378042715602*100), 0.05);
    EXPECT_EQ(last_msg_.flags, 2);
    EXPECT_EQ(last_msg_.n_sats, 21);
    EXPECT_EQ(last_msg_.tow, 501868000);
    EXPECT_EQ(last_msg_.x, -3);
    EXPECT_EQ(last_msg_.y, 1);
    EXPECT_EQ(last_msg_.z, 4);
}