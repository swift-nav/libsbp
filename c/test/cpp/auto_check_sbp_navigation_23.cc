#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_230 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_ecef_cov_gnss_t>
{
public:
  Test_auto_check_sbp_navigation_230() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_ecef_cov_gnss_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_ecef_cov_gnss_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_cov_gnss_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_230, Test)     
{

    uint8_t encoded_frame[] = {85,52,2,0,16,54,24,229,233,29,52,254,158,218,42,142,68,193,69,162,89,91,34,68,80,193,131,21,176,129,239,174,77,65,158,232,30,60,218,221,20,60,129,136,198,187,205,120,166,60,5,166,35,188,122,177,115,60,18,4,159,102, };

    sbp_msg_pos_ecef_cov_gnss_t test_unpacked_msg{};
    test_unpacked_msg.cov_x_x = 0.009699014946818352;
    test_unpacked_msg.cov_x_y = 0.009086096659302711;
    test_unpacked_msg.cov_x_z = -0.006058753002434969;
    test_unpacked_msg.cov_y_y = 0.020321274176239967;
    test_unpacked_msg.cov_y_z = -0.009988312609493732;
    test_unpacked_msg.cov_z_z = 0.01487385667860508;
    test_unpacked_msg.flags = 4;
    test_unpacked_msg.n_sats = 18;
    test_unpacked_msg.tow = 501867800;
    test_unpacked_msg.x = -2694229.7079770807;
    test_unpacked_msg.y = -4264073.427345817;
    test_unpacked_msg.z = 3890655.013186158;
                                                                              
    EXPECT_EQ(send_message( 4096, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 4096);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.cov_x_x*100 - 0.00969901494682*100), 0.05);
    EXPECT_LT((last_msg_.cov_x_y*100 - 0.0090860966593*100), 0.05);
    EXPECT_LT((last_msg_.cov_x_z*100 - -0.00605875300243*100), 0.05);
    EXPECT_LT((last_msg_.cov_y_y*100 - 0.0203212741762*100), 0.05);
    EXPECT_LT((last_msg_.cov_y_z*100 - -0.00998831260949*100), 0.05);
    EXPECT_LT((last_msg_.cov_z_z*100 - 0.0148738566786*100), 0.05);
    EXPECT_EQ(last_msg_.flags, 4);
    EXPECT_EQ(last_msg_.n_sats, 18);
    EXPECT_EQ(last_msg_.tow, 501867800);
    EXPECT_LT((last_msg_.x*100 - -2694229.70798*100), 0.05);
    EXPECT_LT((last_msg_.y*100 - -4264073.42735*100), 0.05);
    EXPECT_LT((last_msg_.z*100 - 3890655.01319*100), 0.05);
}