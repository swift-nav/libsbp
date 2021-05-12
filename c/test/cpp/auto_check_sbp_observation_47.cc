#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_observation_470 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_ephemeris_glo_t>
{
public:
  Test_auto_check_sbp_observation_470() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_ephemeris_glo_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_ephemeris_glo_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_ephemeris_glo_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_470, Test)     
{

    uint8_t encoded_frame[] = {85,139,0,10,9,92,4,3,70,197,6,0,106,8,0,0,160,64,96,9,0,0,1,0,0,0,128,43,128,97,175,184,0,0,64,177,0,0,128,66,246,57,103,193,0,0,0,34,170,78,34,65,0,0,240,199,84,86,117,193,0,0,0,98,6,250,154,192,0,0,0,217,58,221,163,192,0,0,0,184,138,46,139,64,0,0,122,53,0,0,122,53,0,128,59,54,14,100,89,149, };

    sbp_msg_ephemeris_glo_t test_unpacked_msg{};
    
    test_unpacked_msg.acc[0] = 9.313225746154785e-07;
    
    test_unpacked_msg.acc[1] = 9.313225746154785e-07;
    
    test_unpacked_msg.acc[2] = 2.7939677238464355e-06;
    
    test_unpacked_msg.common.fit_interval = 2400;
    
    test_unpacked_msg.common.health_bits = 0;
    
    
    test_unpacked_msg.common.sid.code = 3;
    
    test_unpacked_msg.common.sid.sat = 4;
    
    
    test_unpacked_msg.common.toe.tow = 443718;
    
    test_unpacked_msg.common.toe.wn = 2154;
    
    test_unpacked_msg.common.ura = 5.0;
    
    test_unpacked_msg.common.valid = 1;
    test_unpacked_msg.d_tau = -2.7939677238464355e-09;
    test_unpacked_msg.fcn = 14;
    test_unpacked_msg.gamma = 9.094947017729282e-13;
    test_unpacked_msg.iod = 100;
    
    test_unpacked_msg.pos[0] = -12177330.078125;
    
    test_unpacked_msg.pos[1] = 599893.06640625;
    
    test_unpacked_msg.pos[2] = -22373708.49609375;
    test_unpacked_msg.tau = -8.36281105875969e-05;
    
    test_unpacked_msg.vel[0] = -1726.506233215332;
    
    test_unpacked_msg.vel[1] = -2542.6149368286133;
    
    test_unpacked_msg.vel[2] = 869.8177337646484;
                                                                              
    EXPECT_EQ(send_message( 2314, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 2314);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.acc[0]*100 - 9.31322574615e-07*100), 0.05);
    EXPECT_LT((last_msg_.acc[1]*100 - 9.31322574615e-07*100), 0.05);
    EXPECT_LT((last_msg_.acc[2]*100 - 2.79396772385e-06*100), 0.05);
    
    EXPECT_EQ(last_msg_.common.fit_interval, 2400);
    
    EXPECT_EQ(last_msg_.common.health_bits, 0);
    
    
    EXPECT_EQ(last_msg_.common.sid.code, 3);
    
    EXPECT_EQ(last_msg_.common.sid.sat, 4);
    
    
    EXPECT_EQ(last_msg_.common.toe.tow, 443718);
    
    EXPECT_EQ(last_msg_.common.toe.wn, 2154);
    
    EXPECT_LT((last_msg_.common.ura*100 - 5.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.common.valid, 1);
    EXPECT_LT((last_msg_.d_tau*100 - -2.79396772385e-09*100), 0.05);
    EXPECT_EQ(last_msg_.fcn, 14);
    EXPECT_LT((last_msg_.gamma*100 - 9.09494701773e-13*100), 0.05);
    EXPECT_EQ(last_msg_.iod, 100);
    EXPECT_LT((last_msg_.pos[0]*100 - -12177330.0781*100), 0.05);
    EXPECT_LT((last_msg_.pos[1]*100 - 599893.066406*100), 0.05);
    EXPECT_LT((last_msg_.pos[2]*100 - -22373708.4961*100), 0.05);
    EXPECT_LT((last_msg_.tau*100 - -8.36281105876e-05*100), 0.05);
    EXPECT_LT((last_msg_.vel[0]*100 - -1726.50623322*100), 0.05);
    EXPECT_LT((last_msg_.vel[1]*100 - -2542.61493683*100), 0.05);
    EXPECT_LT((last_msg_.vel[2]*100 - 869.817733765*100), 0.05);
}