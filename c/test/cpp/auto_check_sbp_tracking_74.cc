#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_tracking_740 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>
{
public:
  Test_auto_check_sbp_tracking_740() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_740, Test)     
{

    uint8_t encoded_frame[] = {85,19,0,246,215,99,1,202,0,0,0,197,253,28,66,1,203,0,0,0,231,99,16,66,1,208,0,0,0,212,129,22,66,1,212,0,0,0,58,21,28,66,1,217,0,0,0,178,33,40,66,1,218,0,0,0,235,189,21,66,1,220,0,0,0,29,177,25,66,1,222,0,0,0,43,169,27,66,1,225,0,0,0,137,125,42,66,0,0,0,0,0,0,0,128,191,0,0,0,0,0,0,0,128,191,222,97, };

    sbp_msg_tracking_state_dep_b_t test_unpacked_msg{};
    
    
    test_unpacked_msg.states[0].cn0 = 39.24782180786133;
    
    
    test_unpacked_msg.states[0].sid.code = 0;
    
    test_unpacked_msg.states[0].sid.reserved = 0;
    
    test_unpacked_msg.states[0].sid.sat = 202;
    
    test_unpacked_msg.states[0].state = 1;
    
    
    test_unpacked_msg.states[1].cn0 = 36.09756088256836;
    
    
    test_unpacked_msg.states[1].sid.code = 0;
    
    test_unpacked_msg.states[1].sid.reserved = 0;
    
    test_unpacked_msg.states[1].sid.sat = 203;
    
    test_unpacked_msg.states[1].state = 1;
    
    
    test_unpacked_msg.states[2].cn0 = 37.62678527832031;
    
    
    test_unpacked_msg.states[2].sid.code = 0;
    
    test_unpacked_msg.states[2].sid.reserved = 0;
    
    test_unpacked_msg.states[2].sid.sat = 208;
    
    test_unpacked_msg.states[2].state = 1;
    
    
    test_unpacked_msg.states[3].cn0 = 39.020729064941406;
    
    
    test_unpacked_msg.states[3].sid.code = 0;
    
    test_unpacked_msg.states[3].sid.reserved = 0;
    
    test_unpacked_msg.states[3].sid.sat = 212;
    
    test_unpacked_msg.states[3].state = 1;
    
    
    test_unpacked_msg.states[4].cn0 = 42.03290557861328;
    
    
    test_unpacked_msg.states[4].sid.code = 0;
    
    test_unpacked_msg.states[4].sid.reserved = 0;
    
    test_unpacked_msg.states[4].sid.sat = 217;
    
    test_unpacked_msg.states[4].state = 1;
    
    
    test_unpacked_msg.states[5].cn0 = 37.43546676635742;
    
    
    test_unpacked_msg.states[5].sid.code = 0;
    
    test_unpacked_msg.states[5].sid.reserved = 0;
    
    test_unpacked_msg.states[5].sid.sat = 218;
    
    test_unpacked_msg.states[5].state = 1;
    
    
    test_unpacked_msg.states[6].cn0 = 38.4229621887207;
    
    
    test_unpacked_msg.states[6].sid.code = 0;
    
    test_unpacked_msg.states[6].sid.reserved = 0;
    
    test_unpacked_msg.states[6].sid.sat = 220;
    
    test_unpacked_msg.states[6].state = 1;
    
    
    test_unpacked_msg.states[7].cn0 = 38.91520309448242;
    
    
    test_unpacked_msg.states[7].sid.code = 0;
    
    test_unpacked_msg.states[7].sid.reserved = 0;
    
    test_unpacked_msg.states[7].sid.sat = 222;
    
    test_unpacked_msg.states[7].state = 1;
    
    
    test_unpacked_msg.states[8].cn0 = 42.62259292602539;
    
    
    test_unpacked_msg.states[8].sid.code = 0;
    
    test_unpacked_msg.states[8].sid.reserved = 0;
    
    test_unpacked_msg.states[8].sid.sat = 225;
    
    test_unpacked_msg.states[8].state = 1;
    
    
    test_unpacked_msg.states[9].cn0 = -1.0;
    
    
    test_unpacked_msg.states[9].sid.code = 0;
    
    test_unpacked_msg.states[9].sid.reserved = 0;
    
    test_unpacked_msg.states[9].sid.sat = 0;
    
    test_unpacked_msg.states[9].state = 0;
    
    
    test_unpacked_msg.states[10].cn0 = -1.0;
    
    
    test_unpacked_msg.states[10].sid.code = 0;
    
    test_unpacked_msg.states[10].sid.reserved = 0;
    
    test_unpacked_msg.states[10].sid.sat = 0;
    
    test_unpacked_msg.states[10].state = 0;
    test_unpacked_msg.states_count = 11;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_LT((last_msg_.states[0].cn0*100 - 39.2478218079*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[0].sid.sat, 202);
    
    EXPECT_EQ(last_msg_.states[0].state, 1);
    
    EXPECT_LT((last_msg_.states[1].cn0*100 - 36.0975608826*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[1].sid.sat, 203);
    
    EXPECT_EQ(last_msg_.states[1].state, 1);
    
    EXPECT_LT((last_msg_.states[2].cn0*100 - 37.6267852783*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[2].sid.sat, 208);
    
    EXPECT_EQ(last_msg_.states[2].state, 1);
    
    EXPECT_LT((last_msg_.states[3].cn0*100 - 39.0207290649*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[3].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[3].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[3].sid.sat, 212);
    
    EXPECT_EQ(last_msg_.states[3].state, 1);
    
    EXPECT_LT((last_msg_.states[4].cn0*100 - 42.0329055786*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[4].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[4].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[4].sid.sat, 217);
    
    EXPECT_EQ(last_msg_.states[4].state, 1);
    
    EXPECT_LT((last_msg_.states[5].cn0*100 - 37.4354667664*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[5].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[5].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[5].sid.sat, 218);
    
    EXPECT_EQ(last_msg_.states[5].state, 1);
    
    EXPECT_LT((last_msg_.states[6].cn0*100 - 38.4229621887*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[6].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[6].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[6].sid.sat, 220);
    
    EXPECT_EQ(last_msg_.states[6].state, 1);
    
    EXPECT_LT((last_msg_.states[7].cn0*100 - 38.9152030945*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[7].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[7].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[7].sid.sat, 222);
    
    EXPECT_EQ(last_msg_.states[7].state, 1);
    
    EXPECT_LT((last_msg_.states[8].cn0*100 - 42.622592926*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[8].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[8].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[8].sid.sat, 225);
    
    EXPECT_EQ(last_msg_.states[8].state, 1);
    
    EXPECT_LT((last_msg_.states[9].cn0*100 - -1.0*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[9].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[9].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[9].sid.sat, 0);
    
    EXPECT_EQ(last_msg_.states[9].state, 0);
    
    EXPECT_LT((last_msg_.states[10].cn0*100 - -1.0*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[10].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[10].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[10].sid.sat, 0);
    
    EXPECT_EQ(last_msg_.states[10].state, 0);
    EXPECT_EQ(last_msg_.states_count, 11);
}                                                     
class Test_auto_check_sbp_tracking_741 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>
{
public:
  Test_auto_check_sbp_tracking_741() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_741, Test)     
{

    uint8_t encoded_frame[] = {85,19,0,246,215,99,1,202,0,0,0,250,249,27,66,1,203,0,0,0,40,143,11,66,1,208,0,0,0,190,200,21,66,1,212,0,0,0,251,233,26,66,1,217,0,0,0,209,238,39,66,1,218,0,0,0,162,219,21,66,1,220,0,0,0,162,197,25,66,1,222,0,0,0,14,35,28,66,1,225,0,0,0,9,153,43,66,0,0,0,0,0,0,0,128,191,0,0,0,0,0,0,0,128,191,20,31, };

    sbp_msg_tracking_state_dep_b_t test_unpacked_msg{};
    
    
    test_unpacked_msg.states[0].cn0 = 38.994117736816406;
    
    
    test_unpacked_msg.states[0].sid.code = 0;
    
    test_unpacked_msg.states[0].sid.reserved = 0;
    
    test_unpacked_msg.states[0].sid.sat = 202;
    
    test_unpacked_msg.states[0].state = 1;
    
    
    test_unpacked_msg.states[1].cn0 = 34.889801025390625;
    
    
    test_unpacked_msg.states[1].sid.code = 0;
    
    test_unpacked_msg.states[1].sid.reserved = 0;
    
    test_unpacked_msg.states[1].sid.sat = 203;
    
    test_unpacked_msg.states[1].state = 1;
    
    
    test_unpacked_msg.states[2].cn0 = 37.44603729248047;
    
    
    test_unpacked_msg.states[2].sid.code = 0;
    
    test_unpacked_msg.states[2].sid.reserved = 0;
    
    test_unpacked_msg.states[2].sid.sat = 208;
    
    test_unpacked_msg.states[2].state = 1;
    
    
    test_unpacked_msg.states[3].cn0 = 38.72849655151367;
    
    
    test_unpacked_msg.states[3].sid.code = 0;
    
    test_unpacked_msg.states[3].sid.reserved = 0;
    
    test_unpacked_msg.states[3].sid.sat = 212;
    
    test_unpacked_msg.states[3].state = 1;
    
    
    test_unpacked_msg.states[4].cn0 = 41.983219146728516;
    
    
    test_unpacked_msg.states[4].sid.code = 0;
    
    test_unpacked_msg.states[4].sid.reserved = 0;
    
    test_unpacked_msg.states[4].sid.sat = 217;
    
    test_unpacked_msg.states[4].state = 1;
    
    
    test_unpacked_msg.states[5].cn0 = 37.46448516845703;
    
    
    test_unpacked_msg.states[5].sid.code = 0;
    
    test_unpacked_msg.states[5].sid.reserved = 0;
    
    test_unpacked_msg.states[5].sid.sat = 218;
    
    test_unpacked_msg.states[5].state = 1;
    
    
    test_unpacked_msg.states[6].cn0 = 38.44300079345703;
    
    
    test_unpacked_msg.states[6].sid.code = 0;
    
    test_unpacked_msg.states[6].sid.reserved = 0;
    
    test_unpacked_msg.states[6].sid.sat = 220;
    
    test_unpacked_msg.states[6].state = 1;
    
    
    test_unpacked_msg.states[7].cn0 = 39.03423309326172;
    
    
    test_unpacked_msg.states[7].sid.code = 0;
    
    test_unpacked_msg.states[7].sid.reserved = 0;
    
    test_unpacked_msg.states[7].sid.sat = 222;
    
    test_unpacked_msg.states[7].state = 1;
    
    
    test_unpacked_msg.states[8].cn0 = 42.89944839477539;
    
    
    test_unpacked_msg.states[8].sid.code = 0;
    
    test_unpacked_msg.states[8].sid.reserved = 0;
    
    test_unpacked_msg.states[8].sid.sat = 225;
    
    test_unpacked_msg.states[8].state = 1;
    
    
    test_unpacked_msg.states[9].cn0 = -1.0;
    
    
    test_unpacked_msg.states[9].sid.code = 0;
    
    test_unpacked_msg.states[9].sid.reserved = 0;
    
    test_unpacked_msg.states[9].sid.sat = 0;
    
    test_unpacked_msg.states[9].state = 0;
    
    
    test_unpacked_msg.states[10].cn0 = -1.0;
    
    
    test_unpacked_msg.states[10].sid.code = 0;
    
    test_unpacked_msg.states[10].sid.reserved = 0;
    
    test_unpacked_msg.states[10].sid.sat = 0;
    
    test_unpacked_msg.states[10].state = 0;
    test_unpacked_msg.states_count = 11;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_LT((last_msg_.states[0].cn0*100 - 38.9941177368*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[0].sid.sat, 202);
    
    EXPECT_EQ(last_msg_.states[0].state, 1);
    
    EXPECT_LT((last_msg_.states[1].cn0*100 - 34.8898010254*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[1].sid.sat, 203);
    
    EXPECT_EQ(last_msg_.states[1].state, 1);
    
    EXPECT_LT((last_msg_.states[2].cn0*100 - 37.4460372925*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[2].sid.sat, 208);
    
    EXPECT_EQ(last_msg_.states[2].state, 1);
    
    EXPECT_LT((last_msg_.states[3].cn0*100 - 38.7284965515*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[3].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[3].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[3].sid.sat, 212);
    
    EXPECT_EQ(last_msg_.states[3].state, 1);
    
    EXPECT_LT((last_msg_.states[4].cn0*100 - 41.9832191467*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[4].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[4].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[4].sid.sat, 217);
    
    EXPECT_EQ(last_msg_.states[4].state, 1);
    
    EXPECT_LT((last_msg_.states[5].cn0*100 - 37.4644851685*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[5].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[5].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[5].sid.sat, 218);
    
    EXPECT_EQ(last_msg_.states[5].state, 1);
    
    EXPECT_LT((last_msg_.states[6].cn0*100 - 38.4430007935*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[6].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[6].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[6].sid.sat, 220);
    
    EXPECT_EQ(last_msg_.states[6].state, 1);
    
    EXPECT_LT((last_msg_.states[7].cn0*100 - 39.0342330933*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[7].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[7].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[7].sid.sat, 222);
    
    EXPECT_EQ(last_msg_.states[7].state, 1);
    
    EXPECT_LT((last_msg_.states[8].cn0*100 - 42.8994483948*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[8].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[8].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[8].sid.sat, 225);
    
    EXPECT_EQ(last_msg_.states[8].state, 1);
    
    EXPECT_LT((last_msg_.states[9].cn0*100 - -1.0*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[9].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[9].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[9].sid.sat, 0);
    
    EXPECT_EQ(last_msg_.states[9].state, 0);
    
    EXPECT_LT((last_msg_.states[10].cn0*100 - -1.0*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[10].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[10].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[10].sid.sat, 0);
    
    EXPECT_EQ(last_msg_.states[10].state, 0);
    EXPECT_EQ(last_msg_.states_count, 11);
}                                                     
class Test_auto_check_sbp_tracking_742 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>
{
public:
  Test_auto_check_sbp_tracking_742() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_742, Test)     
{

    uint8_t encoded_frame[] = {85,19,0,246,215,99,1,202,0,0,0,123,209,27,66,1,203,0,0,0,214,64,15,66,1,208,0,0,0,56,55,22,66,1,212,0,0,0,91,142,27,66,1,217,0,0,0,253,154,41,66,1,218,0,0,0,128,142,22,66,1,220,0,0,0,17,174,23,66,1,222,0,0,0,155,2,29,66,1,225,0,0,0,162,100,42,66,0,0,0,0,0,0,0,128,191,0,0,0,0,0,0,0,128,191,233,71, };

    sbp_msg_tracking_state_dep_b_t test_unpacked_msg{};
    
    
    test_unpacked_msg.states[0].cn0 = 38.95457077026367;
    
    
    test_unpacked_msg.states[0].sid.code = 0;
    
    test_unpacked_msg.states[0].sid.reserved = 0;
    
    test_unpacked_msg.states[0].sid.sat = 202;
    
    test_unpacked_msg.states[0].state = 1;
    
    
    test_unpacked_msg.states[1].cn0 = 35.813316345214844;
    
    
    test_unpacked_msg.states[1].sid.code = 0;
    
    test_unpacked_msg.states[1].sid.reserved = 0;
    
    test_unpacked_msg.states[1].sid.sat = 203;
    
    test_unpacked_msg.states[1].state = 1;
    
    
    test_unpacked_msg.states[2].cn0 = 37.553924560546875;
    
    
    test_unpacked_msg.states[2].sid.code = 0;
    
    test_unpacked_msg.states[2].sid.reserved = 0;
    
    test_unpacked_msg.states[2].sid.sat = 208;
    
    test_unpacked_msg.states[2].state = 1;
    
    
    test_unpacked_msg.states[3].cn0 = 38.88901901245117;
    
    
    test_unpacked_msg.states[3].sid.code = 0;
    
    test_unpacked_msg.states[3].sid.reserved = 0;
    
    test_unpacked_msg.states[3].sid.sat = 212;
    
    test_unpacked_msg.states[3].state = 1;
    
    
    test_unpacked_msg.states[4].cn0 = 42.4013557434082;
    
    
    test_unpacked_msg.states[4].sid.code = 0;
    
    test_unpacked_msg.states[4].sid.reserved = 0;
    
    test_unpacked_msg.states[4].sid.sat = 217;
    
    test_unpacked_msg.states[4].state = 1;
    
    
    test_unpacked_msg.states[5].cn0 = 37.63916015625;
    
    
    test_unpacked_msg.states[5].sid.code = 0;
    
    test_unpacked_msg.states[5].sid.reserved = 0;
    
    test_unpacked_msg.states[5].sid.sat = 218;
    
    test_unpacked_msg.states[5].state = 1;
    
    
    test_unpacked_msg.states[6].cn0 = 37.919986724853516;
    
    
    test_unpacked_msg.states[6].sid.code = 0;
    
    test_unpacked_msg.states[6].sid.reserved = 0;
    
    test_unpacked_msg.states[6].sid.sat = 220;
    
    test_unpacked_msg.states[6].state = 1;
    
    
    test_unpacked_msg.states[7].cn0 = 39.25254440307617;
    
    
    test_unpacked_msg.states[7].sid.code = 0;
    
    test_unpacked_msg.states[7].sid.reserved = 0;
    
    test_unpacked_msg.states[7].sid.sat = 222;
    
    test_unpacked_msg.states[7].state = 1;
    
    
    test_unpacked_msg.states[8].cn0 = 42.59827423095703;
    
    
    test_unpacked_msg.states[8].sid.code = 0;
    
    test_unpacked_msg.states[8].sid.reserved = 0;
    
    test_unpacked_msg.states[8].sid.sat = 225;
    
    test_unpacked_msg.states[8].state = 1;
    
    
    test_unpacked_msg.states[9].cn0 = -1.0;
    
    
    test_unpacked_msg.states[9].sid.code = 0;
    
    test_unpacked_msg.states[9].sid.reserved = 0;
    
    test_unpacked_msg.states[9].sid.sat = 0;
    
    test_unpacked_msg.states[9].state = 0;
    
    
    test_unpacked_msg.states[10].cn0 = -1.0;
    
    
    test_unpacked_msg.states[10].sid.code = 0;
    
    test_unpacked_msg.states[10].sid.reserved = 0;
    
    test_unpacked_msg.states[10].sid.sat = 0;
    
    test_unpacked_msg.states[10].state = 0;
    test_unpacked_msg.states_count = 11;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_LT((last_msg_.states[0].cn0*100 - 38.9545707703*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[0].sid.sat, 202);
    
    EXPECT_EQ(last_msg_.states[0].state, 1);
    
    EXPECT_LT((last_msg_.states[1].cn0*100 - 35.8133163452*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[1].sid.sat, 203);
    
    EXPECT_EQ(last_msg_.states[1].state, 1);
    
    EXPECT_LT((last_msg_.states[2].cn0*100 - 37.5539245605*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[2].sid.sat, 208);
    
    EXPECT_EQ(last_msg_.states[2].state, 1);
    
    EXPECT_LT((last_msg_.states[3].cn0*100 - 38.8890190125*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[3].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[3].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[3].sid.sat, 212);
    
    EXPECT_EQ(last_msg_.states[3].state, 1);
    
    EXPECT_LT((last_msg_.states[4].cn0*100 - 42.4013557434*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[4].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[4].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[4].sid.sat, 217);
    
    EXPECT_EQ(last_msg_.states[4].state, 1);
    
    EXPECT_LT((last_msg_.states[5].cn0*100 - 37.6391601562*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[5].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[5].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[5].sid.sat, 218);
    
    EXPECT_EQ(last_msg_.states[5].state, 1);
    
    EXPECT_LT((last_msg_.states[6].cn0*100 - 37.9199867249*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[6].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[6].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[6].sid.sat, 220);
    
    EXPECT_EQ(last_msg_.states[6].state, 1);
    
    EXPECT_LT((last_msg_.states[7].cn0*100 - 39.2525444031*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[7].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[7].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[7].sid.sat, 222);
    
    EXPECT_EQ(last_msg_.states[7].state, 1);
    
    EXPECT_LT((last_msg_.states[8].cn0*100 - 42.598274231*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[8].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[8].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[8].sid.sat, 225);
    
    EXPECT_EQ(last_msg_.states[8].state, 1);
    
    EXPECT_LT((last_msg_.states[9].cn0*100 - -1.0*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[9].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[9].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[9].sid.sat, 0);
    
    EXPECT_EQ(last_msg_.states[9].state, 0);
    
    EXPECT_LT((last_msg_.states[10].cn0*100 - -1.0*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[10].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[10].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[10].sid.sat, 0);
    
    EXPECT_EQ(last_msg_.states[10].state, 0);
    EXPECT_EQ(last_msg_.states_count, 11);
}                                                     
class Test_auto_check_sbp_tracking_743 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>
{
public:
  Test_auto_check_sbp_tracking_743() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_743, Test)     
{

    uint8_t encoded_frame[] = {85,19,0,246,215,99,1,202,0,0,0,120,122,29,66,1,203,0,0,0,66,22,18,66,1,208,0,0,0,153,163,24,66,1,212,0,0,0,178,204,28,66,1,217,0,0,0,220,59,38,66,1,218,0,0,0,161,27,20,66,1,220,0,0,0,125,107,24,66,1,222,0,0,0,242,46,28,66,1,225,0,0,0,231,130,41,66,0,0,0,0,0,0,0,128,191,0,0,0,0,0,0,0,128,191,73,193, };

    sbp_msg_tracking_state_dep_b_t test_unpacked_msg{};
    
    
    test_unpacked_msg.states[0].cn0 = 39.369598388671875;
    
    
    test_unpacked_msg.states[0].sid.code = 0;
    
    test_unpacked_msg.states[0].sid.reserved = 0;
    
    test_unpacked_msg.states[0].sid.sat = 202;
    
    test_unpacked_msg.states[0].state = 1;
    
    
    test_unpacked_msg.states[1].cn0 = 36.52173614501953;
    
    
    test_unpacked_msg.states[1].sid.code = 0;
    
    test_unpacked_msg.states[1].sid.reserved = 0;
    
    test_unpacked_msg.states[1].sid.sat = 203;
    
    test_unpacked_msg.states[1].state = 1;
    
    
    test_unpacked_msg.states[2].cn0 = 38.15976333618164;
    
    
    test_unpacked_msg.states[2].sid.code = 0;
    
    test_unpacked_msg.states[2].sid.reserved = 0;
    
    test_unpacked_msg.states[2].sid.sat = 208;
    
    test_unpacked_msg.states[2].state = 1;
    
    
    test_unpacked_msg.states[3].cn0 = 39.19989776611328;
    
    
    test_unpacked_msg.states[3].sid.code = 0;
    
    test_unpacked_msg.states[3].sid.reserved = 0;
    
    test_unpacked_msg.states[3].sid.sat = 212;
    
    test_unpacked_msg.states[3].state = 1;
    
    
    test_unpacked_msg.states[4].cn0 = 41.55845642089844;
    
    
    test_unpacked_msg.states[4].sid.code = 0;
    
    test_unpacked_msg.states[4].sid.reserved = 0;
    
    test_unpacked_msg.states[4].sid.sat = 217;
    
    test_unpacked_msg.states[4].state = 1;
    
    
    test_unpacked_msg.states[5].cn0 = 37.026981353759766;
    
    
    test_unpacked_msg.states[5].sid.code = 0;
    
    test_unpacked_msg.states[5].sid.reserved = 0;
    
    test_unpacked_msg.states[5].sid.sat = 218;
    
    test_unpacked_msg.states[5].state = 1;
    
    
    test_unpacked_msg.states[6].cn0 = 38.1049690246582;
    
    
    test_unpacked_msg.states[6].sid.code = 0;
    
    test_unpacked_msg.states[6].sid.reserved = 0;
    
    test_unpacked_msg.states[6].sid.sat = 220;
    
    test_unpacked_msg.states[6].state = 1;
    
    
    test_unpacked_msg.states[7].cn0 = 39.04584503173828;
    
    
    test_unpacked_msg.states[7].sid.code = 0;
    
    test_unpacked_msg.states[7].sid.reserved = 0;
    
    test_unpacked_msg.states[7].sid.sat = 222;
    
    test_unpacked_msg.states[7].state = 1;
    
    
    test_unpacked_msg.states[8].cn0 = 42.37783432006836;
    
    
    test_unpacked_msg.states[8].sid.code = 0;
    
    test_unpacked_msg.states[8].sid.reserved = 0;
    
    test_unpacked_msg.states[8].sid.sat = 225;
    
    test_unpacked_msg.states[8].state = 1;
    
    
    test_unpacked_msg.states[9].cn0 = -1.0;
    
    
    test_unpacked_msg.states[9].sid.code = 0;
    
    test_unpacked_msg.states[9].sid.reserved = 0;
    
    test_unpacked_msg.states[9].sid.sat = 0;
    
    test_unpacked_msg.states[9].state = 0;
    
    
    test_unpacked_msg.states[10].cn0 = -1.0;
    
    
    test_unpacked_msg.states[10].sid.code = 0;
    
    test_unpacked_msg.states[10].sid.reserved = 0;
    
    test_unpacked_msg.states[10].sid.sat = 0;
    
    test_unpacked_msg.states[10].state = 0;
    test_unpacked_msg.states_count = 11;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_LT((last_msg_.states[0].cn0*100 - 39.3695983887*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[0].sid.sat, 202);
    
    EXPECT_EQ(last_msg_.states[0].state, 1);
    
    EXPECT_LT((last_msg_.states[1].cn0*100 - 36.521736145*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[1].sid.sat, 203);
    
    EXPECT_EQ(last_msg_.states[1].state, 1);
    
    EXPECT_LT((last_msg_.states[2].cn0*100 - 38.1597633362*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[2].sid.sat, 208);
    
    EXPECT_EQ(last_msg_.states[2].state, 1);
    
    EXPECT_LT((last_msg_.states[3].cn0*100 - 39.1998977661*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[3].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[3].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[3].sid.sat, 212);
    
    EXPECT_EQ(last_msg_.states[3].state, 1);
    
    EXPECT_LT((last_msg_.states[4].cn0*100 - 41.5584564209*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[4].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[4].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[4].sid.sat, 217);
    
    EXPECT_EQ(last_msg_.states[4].state, 1);
    
    EXPECT_LT((last_msg_.states[5].cn0*100 - 37.0269813538*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[5].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[5].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[5].sid.sat, 218);
    
    EXPECT_EQ(last_msg_.states[5].state, 1);
    
    EXPECT_LT((last_msg_.states[6].cn0*100 - 38.1049690247*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[6].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[6].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[6].sid.sat, 220);
    
    EXPECT_EQ(last_msg_.states[6].state, 1);
    
    EXPECT_LT((last_msg_.states[7].cn0*100 - 39.0458450317*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[7].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[7].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[7].sid.sat, 222);
    
    EXPECT_EQ(last_msg_.states[7].state, 1);
    
    EXPECT_LT((last_msg_.states[8].cn0*100 - 42.3778343201*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[8].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[8].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[8].sid.sat, 225);
    
    EXPECT_EQ(last_msg_.states[8].state, 1);
    
    EXPECT_LT((last_msg_.states[9].cn0*100 - -1.0*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[9].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[9].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[9].sid.sat, 0);
    
    EXPECT_EQ(last_msg_.states[9].state, 0);
    
    EXPECT_LT((last_msg_.states[10].cn0*100 - -1.0*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[10].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[10].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[10].sid.sat, 0);
    
    EXPECT_EQ(last_msg_.states[10].state, 0);
    EXPECT_EQ(last_msg_.states_count, 11);
}                                                     
class Test_auto_check_sbp_tracking_744 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>
{
public:
  Test_auto_check_sbp_tracking_744() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_744, Test)     
{

    uint8_t encoded_frame[] = {85,19,0,246,215,99,1,202,0,0,0,103,208,30,66,1,203,0,0,0,117,24,18,66,1,208,0,0,0,200,173,20,66,1,212,0,0,0,137,68,27,66,1,217,0,0,0,243,51,40,66,1,218,0,0,0,225,58,23,66,1,220,0,0,0,132,221,22,66,1,222,0,0,0,157,29,26,66,1,225,0,0,0,133,21,41,66,0,0,0,0,0,0,0,128,191,0,0,0,0,0,0,0,128,191,126,47, };

    sbp_msg_tracking_state_dep_b_t test_unpacked_msg{};
    
    
    test_unpacked_msg.states[0].cn0 = 39.70351791381836;
    
    
    test_unpacked_msg.states[0].sid.code = 0;
    
    test_unpacked_msg.states[0].sid.reserved = 0;
    
    test_unpacked_msg.states[0].sid.sat = 202;
    
    test_unpacked_msg.states[0].state = 1;
    
    
    test_unpacked_msg.states[1].cn0 = 36.52388381958008;
    
    
    test_unpacked_msg.states[1].sid.code = 0;
    
    test_unpacked_msg.states[1].sid.reserved = 0;
    
    test_unpacked_msg.states[1].sid.sat = 203;
    
    test_unpacked_msg.states[1].state = 1;
    
    
    test_unpacked_msg.states[2].cn0 = 37.169708251953125;
    
    
    test_unpacked_msg.states[2].sid.code = 0;
    
    test_unpacked_msg.states[2].sid.reserved = 0;
    
    test_unpacked_msg.states[2].sid.sat = 208;
    
    test_unpacked_msg.states[2].state = 1;
    
    
    test_unpacked_msg.states[3].cn0 = 38.81692886352539;
    
    
    test_unpacked_msg.states[3].sid.code = 0;
    
    test_unpacked_msg.states[3].sid.reserved = 0;
    
    test_unpacked_msg.states[3].sid.sat = 212;
    
    test_unpacked_msg.states[3].state = 1;
    
    
    test_unpacked_msg.states[4].cn0 = 42.05073165893555;
    
    
    test_unpacked_msg.states[4].sid.code = 0;
    
    test_unpacked_msg.states[4].sid.reserved = 0;
    
    test_unpacked_msg.states[4].sid.sat = 217;
    
    test_unpacked_msg.states[4].state = 1;
    
    
    test_unpacked_msg.states[5].cn0 = 37.807498931884766;
    
    
    test_unpacked_msg.states[5].sid.code = 0;
    
    test_unpacked_msg.states[5].sid.reserved = 0;
    
    test_unpacked_msg.states[5].sid.sat = 218;
    
    test_unpacked_msg.states[5].state = 1;
    
    
    test_unpacked_msg.states[6].cn0 = 37.71632385253906;
    
    
    test_unpacked_msg.states[6].sid.code = 0;
    
    test_unpacked_msg.states[6].sid.reserved = 0;
    
    test_unpacked_msg.states[6].sid.sat = 220;
    
    test_unpacked_msg.states[6].state = 1;
    
    
    test_unpacked_msg.states[7].cn0 = 38.5289192199707;
    
    
    test_unpacked_msg.states[7].sid.code = 0;
    
    test_unpacked_msg.states[7].sid.reserved = 0;
    
    test_unpacked_msg.states[7].sid.sat = 222;
    
    test_unpacked_msg.states[7].state = 1;
    
    
    test_unpacked_msg.states[8].cn0 = 42.27101516723633;
    
    
    test_unpacked_msg.states[8].sid.code = 0;
    
    test_unpacked_msg.states[8].sid.reserved = 0;
    
    test_unpacked_msg.states[8].sid.sat = 225;
    
    test_unpacked_msg.states[8].state = 1;
    
    
    test_unpacked_msg.states[9].cn0 = -1.0;
    
    
    test_unpacked_msg.states[9].sid.code = 0;
    
    test_unpacked_msg.states[9].sid.reserved = 0;
    
    test_unpacked_msg.states[9].sid.sat = 0;
    
    test_unpacked_msg.states[9].state = 0;
    
    
    test_unpacked_msg.states[10].cn0 = -1.0;
    
    
    test_unpacked_msg.states[10].sid.code = 0;
    
    test_unpacked_msg.states[10].sid.reserved = 0;
    
    test_unpacked_msg.states[10].sid.sat = 0;
    
    test_unpacked_msg.states[10].state = 0;
    test_unpacked_msg.states_count = 11;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_LT((last_msg_.states[0].cn0*100 - 39.7035179138*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[0].sid.sat, 202);
    
    EXPECT_EQ(last_msg_.states[0].state, 1);
    
    EXPECT_LT((last_msg_.states[1].cn0*100 - 36.5238838196*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[1].sid.sat, 203);
    
    EXPECT_EQ(last_msg_.states[1].state, 1);
    
    EXPECT_LT((last_msg_.states[2].cn0*100 - 37.169708252*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[2].sid.sat, 208);
    
    EXPECT_EQ(last_msg_.states[2].state, 1);
    
    EXPECT_LT((last_msg_.states[3].cn0*100 - 38.8169288635*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[3].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[3].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[3].sid.sat, 212);
    
    EXPECT_EQ(last_msg_.states[3].state, 1);
    
    EXPECT_LT((last_msg_.states[4].cn0*100 - 42.0507316589*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[4].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[4].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[4].sid.sat, 217);
    
    EXPECT_EQ(last_msg_.states[4].state, 1);
    
    EXPECT_LT((last_msg_.states[5].cn0*100 - 37.8074989319*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[5].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[5].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[5].sid.sat, 218);
    
    EXPECT_EQ(last_msg_.states[5].state, 1);
    
    EXPECT_LT((last_msg_.states[6].cn0*100 - 37.7163238525*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[6].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[6].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[6].sid.sat, 220);
    
    EXPECT_EQ(last_msg_.states[6].state, 1);
    
    EXPECT_LT((last_msg_.states[7].cn0*100 - 38.52891922*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[7].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[7].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[7].sid.sat, 222);
    
    EXPECT_EQ(last_msg_.states[7].state, 1);
    
    EXPECT_LT((last_msg_.states[8].cn0*100 - 42.2710151672*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[8].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[8].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[8].sid.sat, 225);
    
    EXPECT_EQ(last_msg_.states[8].state, 1);
    
    EXPECT_LT((last_msg_.states[9].cn0*100 - -1.0*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[9].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[9].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[9].sid.sat, 0);
    
    EXPECT_EQ(last_msg_.states[9].state, 0);
    
    EXPECT_LT((last_msg_.states[10].cn0*100 - -1.0*100), 0.05);
    
    
    EXPECT_EQ(last_msg_.states[10].sid.code, 0);
    
    EXPECT_EQ(last_msg_.states[10].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.states[10].sid.sat, 0);
    
    EXPECT_EQ(last_msg_.states[10].state, 0);
    EXPECT_EQ(last_msg_.states_count, 11);
}