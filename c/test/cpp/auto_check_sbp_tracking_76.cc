#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_tracking_760 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>
{
public:
  Test_auto_check_sbp_tracking_760() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_760, Test)     
{

    uint8_t encoded_frame[] = {85,22,0,195,4,66,1,0,204,177,51,65,1,2,198,4,39,65,1,3,219,182,27,65,1,7,132,120,101,65,1,10,91,91,251,64,1,13,42,37,163,64,1,22,130,184,215,64,1,30,115,53,75,65,1,31,16,74,126,65,1,25,132,196,135,64,1,6,100,59,223,64,17,225, };

    sbp_msg_tracking_state_dep_a_t test_unpacked_msg{};
    
    
    test_unpacked_msg.states[0].cn0 = 11.230907440185547;
    
    test_unpacked_msg.states[0].prn = 0;
    
    test_unpacked_msg.states[0].state = 1;
    
    
    test_unpacked_msg.states[1].cn0 = 10.438665390014648;
    
    test_unpacked_msg.states[1].prn = 2;
    
    test_unpacked_msg.states[1].state = 1;
    
    
    test_unpacked_msg.states[2].cn0 = 9.732142448425293;
    
    test_unpacked_msg.states[2].prn = 3;
    
    test_unpacked_msg.states[2].state = 1;
    
    
    test_unpacked_msg.states[3].cn0 = 14.341922760009766;
    
    test_unpacked_msg.states[3].prn = 7;
    
    test_unpacked_msg.states[3].state = 1;
    
    
    test_unpacked_msg.states[4].cn0 = 7.8549017906188965;
    
    test_unpacked_msg.states[4].prn = 10;
    
    test_unpacked_msg.states[4].state = 1;
    
    
    test_unpacked_msg.states[5].cn0 = 5.0982866287231445;
    
    test_unpacked_msg.states[5].prn = 13;
    
    test_unpacked_msg.states[5].state = 1;
    
    
    test_unpacked_msg.states[6].cn0 = 6.741272926330566;
    
    test_unpacked_msg.states[6].prn = 22;
    
    test_unpacked_msg.states[6].state = 1;
    
    
    test_unpacked_msg.states[7].cn0 = 12.700549125671387;
    
    test_unpacked_msg.states[7].prn = 30;
    
    test_unpacked_msg.states[7].state = 1;
    
    
    test_unpacked_msg.states[8].cn0 = 15.893081665039062;
    
    test_unpacked_msg.states[8].prn = 31;
    
    test_unpacked_msg.states[8].state = 1;
    
    
    test_unpacked_msg.states[9].cn0 = 4.242738723754883;
    
    test_unpacked_msg.states[9].prn = 25;
    
    test_unpacked_msg.states[9].state = 1;
    
    
    test_unpacked_msg.states[10].cn0 = 6.97599983215332;
    
    test_unpacked_msg.states[10].prn = 6;
    
    test_unpacked_msg.states[10].state = 1;
    test_unpacked_msg.states_count = 11;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_LT((last_msg_.states[0].cn0*100 - 11.2309074402*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[0].prn, 0);
    
    EXPECT_EQ(last_msg_.states[0].state, 1);
    
    EXPECT_LT((last_msg_.states[1].cn0*100 - 10.43866539*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[1].prn, 2);
    
    EXPECT_EQ(last_msg_.states[1].state, 1);
    
    EXPECT_LT((last_msg_.states[2].cn0*100 - 9.73214244843*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[2].prn, 3);
    
    EXPECT_EQ(last_msg_.states[2].state, 1);
    
    EXPECT_LT((last_msg_.states[3].cn0*100 - 14.34192276*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[3].prn, 7);
    
    EXPECT_EQ(last_msg_.states[3].state, 1);
    
    EXPECT_LT((last_msg_.states[4].cn0*100 - 7.85490179062*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[4].prn, 10);
    
    EXPECT_EQ(last_msg_.states[4].state, 1);
    
    EXPECT_LT((last_msg_.states[5].cn0*100 - 5.09828662872*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[5].prn, 13);
    
    EXPECT_EQ(last_msg_.states[5].state, 1);
    
    EXPECT_LT((last_msg_.states[6].cn0*100 - 6.74127292633*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[6].prn, 22);
    
    EXPECT_EQ(last_msg_.states[6].state, 1);
    
    EXPECT_LT((last_msg_.states[7].cn0*100 - 12.7005491257*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[7].prn, 30);
    
    EXPECT_EQ(last_msg_.states[7].state, 1);
    
    EXPECT_LT((last_msg_.states[8].cn0*100 - 15.893081665*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[8].prn, 31);
    
    EXPECT_EQ(last_msg_.states[8].state, 1);
    
    EXPECT_LT((last_msg_.states[9].cn0*100 - 4.24273872375*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[9].prn, 25);
    
    EXPECT_EQ(last_msg_.states[9].state, 1);
    
    EXPECT_LT((last_msg_.states[10].cn0*100 - 6.97599983215*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[10].prn, 6);
    
    EXPECT_EQ(last_msg_.states[10].state, 1);
    EXPECT_EQ(last_msg_.states_count, 11);
}                                                     
class Test_auto_check_sbp_tracking_761 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>
{
public:
  Test_auto_check_sbp_tracking_761() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_761, Test)     
{

    uint8_t encoded_frame[] = {85,22,0,195,4,66,1,0,216,57,48,65,1,2,145,41,46,65,1,3,4,26,34,65,1,7,177,67,109,65,1,10,61,80,249,64,1,13,250,199,155,64,1,22,55,19,215,64,1,30,138,138,79,65,1,31,214,179,119,65,1,25,53,138,120,64,1,6,183,247,129,64,168,173, };

    sbp_msg_tracking_state_dep_a_t test_unpacked_msg{};
    
    
    test_unpacked_msg.states[0].cn0 = 11.014122009277344;
    
    test_unpacked_msg.states[0].prn = 0;
    
    test_unpacked_msg.states[0].state = 1;
    
    
    test_unpacked_msg.states[1].cn0 = 10.885148048400879;
    
    test_unpacked_msg.states[1].prn = 2;
    
    test_unpacked_msg.states[1].state = 1;
    
    
    test_unpacked_msg.states[2].cn0 = 10.131351470947266;
    
    test_unpacked_msg.states[2].prn = 3;
    
    test_unpacked_msg.states[2].state = 1;
    
    
    test_unpacked_msg.states[3].cn0 = 14.829026222229004;
    
    test_unpacked_msg.states[3].prn = 7;
    
    test_unpacked_msg.states[3].state = 1;
    
    
    test_unpacked_msg.states[4].cn0 = 7.79104471206665;
    
    test_unpacked_msg.states[4].prn = 10;
    
    test_unpacked_msg.states[4].state = 1;
    
    
    test_unpacked_msg.states[5].cn0 = 4.868161201477051;
    
    test_unpacked_msg.states[5].prn = 13;
    
    test_unpacked_msg.states[5].state = 1;
    
    
    test_unpacked_msg.states[6].cn0 = 6.721095561981201;
    
    test_unpacked_msg.states[6].prn = 22;
    
    test_unpacked_msg.states[6].state = 1;
    
    
    test_unpacked_msg.states[7].cn0 = 12.971323013305664;
    
    test_unpacked_msg.states[7].prn = 30;
    
    test_unpacked_msg.states[7].state = 1;
    
    
    test_unpacked_msg.states[8].cn0 = 15.481405258178711;
    
    test_unpacked_msg.states[8].prn = 31;
    
    test_unpacked_msg.states[8].state = 1;
    
    
    test_unpacked_msg.states[9].cn0 = 3.8834354877471924;
    
    test_unpacked_msg.states[9].prn = 25;
    
    test_unpacked_msg.states[9].state = 1;
    
    
    test_unpacked_msg.states[10].cn0 = 4.061488628387451;
    
    test_unpacked_msg.states[10].prn = 6;
    
    test_unpacked_msg.states[10].state = 1;
    test_unpacked_msg.states_count = 11;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_LT((last_msg_.states[0].cn0*100 - 11.0141220093*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[0].prn, 0);
    
    EXPECT_EQ(last_msg_.states[0].state, 1);
    
    EXPECT_LT((last_msg_.states[1].cn0*100 - 10.8851480484*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[1].prn, 2);
    
    EXPECT_EQ(last_msg_.states[1].state, 1);
    
    EXPECT_LT((last_msg_.states[2].cn0*100 - 10.1313514709*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[2].prn, 3);
    
    EXPECT_EQ(last_msg_.states[2].state, 1);
    
    EXPECT_LT((last_msg_.states[3].cn0*100 - 14.8290262222*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[3].prn, 7);
    
    EXPECT_EQ(last_msg_.states[3].state, 1);
    
    EXPECT_LT((last_msg_.states[4].cn0*100 - 7.79104471207*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[4].prn, 10);
    
    EXPECT_EQ(last_msg_.states[4].state, 1);
    
    EXPECT_LT((last_msg_.states[5].cn0*100 - 4.86816120148*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[5].prn, 13);
    
    EXPECT_EQ(last_msg_.states[5].state, 1);
    
    EXPECT_LT((last_msg_.states[6].cn0*100 - 6.72109556198*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[6].prn, 22);
    
    EXPECT_EQ(last_msg_.states[6].state, 1);
    
    EXPECT_LT((last_msg_.states[7].cn0*100 - 12.9713230133*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[7].prn, 30);
    
    EXPECT_EQ(last_msg_.states[7].state, 1);
    
    EXPECT_LT((last_msg_.states[8].cn0*100 - 15.4814052582*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[8].prn, 31);
    
    EXPECT_EQ(last_msg_.states[8].state, 1);
    
    EXPECT_LT((last_msg_.states[9].cn0*100 - 3.88343548775*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[9].prn, 25);
    
    EXPECT_EQ(last_msg_.states[9].state, 1);
    
    EXPECT_LT((last_msg_.states[10].cn0*100 - 4.06148862839*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[10].prn, 6);
    
    EXPECT_EQ(last_msg_.states[10].state, 1);
    EXPECT_EQ(last_msg_.states_count, 11);
}                                                     
class Test_auto_check_sbp_tracking_762 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>
{
public:
  Test_auto_check_sbp_tracking_762() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_762, Test)     
{

    uint8_t encoded_frame[] = {85,22,0,195,4,66,1,0,141,76,60,65,1,2,69,139,46,65,1,3,146,27,30,65,1,7,235,56,97,65,1,10,141,213,243,64,1,13,250,170,166,64,1,22,17,101,201,64,1,30,172,183,83,65,1,31,238,193,120,65,1,25,220,48,132,64,1,6,49,214,54,64,110,179, };

    sbp_msg_tracking_state_dep_a_t test_unpacked_msg{};
    
    
    test_unpacked_msg.states[0].cn0 = 11.768689155578613;
    
    test_unpacked_msg.states[0].prn = 0;
    
    test_unpacked_msg.states[0].state = 1;
    
    
    test_unpacked_msg.states[1].cn0 = 10.909001350402832;
    
    test_unpacked_msg.states[1].prn = 2;
    
    test_unpacked_msg.states[1].state = 1;
    
    
    test_unpacked_msg.states[2].cn0 = 9.881731033325195;
    
    test_unpacked_msg.states[2].prn = 3;
    
    test_unpacked_msg.states[2].state = 1;
    
    
    test_unpacked_msg.states[3].cn0 = 14.076395988464355;
    
    test_unpacked_msg.states[3].prn = 7;
    
    test_unpacked_msg.states[3].state = 1;
    
    
    test_unpacked_msg.states[4].cn0 = 7.619818210601807;
    
    test_unpacked_msg.states[4].prn = 10;
    
    test_unpacked_msg.states[4].state = 1;
    
    
    test_unpacked_msg.states[5].cn0 = 5.208371162414551;
    
    test_unpacked_msg.states[5].prn = 13;
    
    test_unpacked_msg.states[5].state = 1;
    
    
    test_unpacked_msg.states[6].cn0 = 6.2935872077941895;
    
    test_unpacked_msg.states[6].prn = 22;
    
    test_unpacked_msg.states[6].state = 1;
    
    
    test_unpacked_msg.states[7].cn0 = 13.232341766357422;
    
    test_unpacked_msg.states[7].prn = 30;
    
    test_unpacked_msg.states[7].state = 1;
    
    
    test_unpacked_msg.states[8].cn0 = 15.547346115112305;
    
    test_unpacked_msg.states[8].prn = 31;
    
    test_unpacked_msg.states[8].state = 1;
    
    
    test_unpacked_msg.states[9].cn0 = 4.130964279174805;
    
    test_unpacked_msg.states[9].prn = 25;
    
    test_unpacked_msg.states[9].state = 1;
    
    
    test_unpacked_msg.states[10].cn0 = 2.856823205947876;
    
    test_unpacked_msg.states[10].prn = 6;
    
    test_unpacked_msg.states[10].state = 1;
    test_unpacked_msg.states_count = 11;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_LT((last_msg_.states[0].cn0*100 - 11.7686891556*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[0].prn, 0);
    
    EXPECT_EQ(last_msg_.states[0].state, 1);
    
    EXPECT_LT((last_msg_.states[1].cn0*100 - 10.9090013504*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[1].prn, 2);
    
    EXPECT_EQ(last_msg_.states[1].state, 1);
    
    EXPECT_LT((last_msg_.states[2].cn0*100 - 9.88173103333*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[2].prn, 3);
    
    EXPECT_EQ(last_msg_.states[2].state, 1);
    
    EXPECT_LT((last_msg_.states[3].cn0*100 - 14.0763959885*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[3].prn, 7);
    
    EXPECT_EQ(last_msg_.states[3].state, 1);
    
    EXPECT_LT((last_msg_.states[4].cn0*100 - 7.6198182106*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[4].prn, 10);
    
    EXPECT_EQ(last_msg_.states[4].state, 1);
    
    EXPECT_LT((last_msg_.states[5].cn0*100 - 5.20837116241*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[5].prn, 13);
    
    EXPECT_EQ(last_msg_.states[5].state, 1);
    
    EXPECT_LT((last_msg_.states[6].cn0*100 - 6.29358720779*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[6].prn, 22);
    
    EXPECT_EQ(last_msg_.states[6].state, 1);
    
    EXPECT_LT((last_msg_.states[7].cn0*100 - 13.2323417664*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[7].prn, 30);
    
    EXPECT_EQ(last_msg_.states[7].state, 1);
    
    EXPECT_LT((last_msg_.states[8].cn0*100 - 15.5473461151*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[8].prn, 31);
    
    EXPECT_EQ(last_msg_.states[8].state, 1);
    
    EXPECT_LT((last_msg_.states[9].cn0*100 - 4.13096427917*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[9].prn, 25);
    
    EXPECT_EQ(last_msg_.states[9].state, 1);
    
    EXPECT_LT((last_msg_.states[10].cn0*100 - 2.85682320595*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[10].prn, 6);
    
    EXPECT_EQ(last_msg_.states[10].state, 1);
    EXPECT_EQ(last_msg_.states_count, 11);
}                                                     
class Test_auto_check_sbp_tracking_763 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>
{
public:
  Test_auto_check_sbp_tracking_763() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_763, Test)     
{

    uint8_t encoded_frame[] = {85,22,0,195,4,66,1,0,55,143,120,66,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,248,89, };

    sbp_msg_tracking_state_dep_a_t test_unpacked_msg{};
    
    
    test_unpacked_msg.states[0].cn0 = 62.13985824584961;
    
    test_unpacked_msg.states[0].prn = 0;
    
    test_unpacked_msg.states[0].state = 1;
    
    
    test_unpacked_msg.states[1].cn0 = -1.0;
    
    test_unpacked_msg.states[1].prn = 0;
    
    test_unpacked_msg.states[1].state = 0;
    
    
    test_unpacked_msg.states[2].cn0 = -1.0;
    
    test_unpacked_msg.states[2].prn = 0;
    
    test_unpacked_msg.states[2].state = 0;
    
    
    test_unpacked_msg.states[3].cn0 = -1.0;
    
    test_unpacked_msg.states[3].prn = 0;
    
    test_unpacked_msg.states[3].state = 0;
    
    
    test_unpacked_msg.states[4].cn0 = -1.0;
    
    test_unpacked_msg.states[4].prn = 0;
    
    test_unpacked_msg.states[4].state = 0;
    
    
    test_unpacked_msg.states[5].cn0 = -1.0;
    
    test_unpacked_msg.states[5].prn = 0;
    
    test_unpacked_msg.states[5].state = 0;
    
    
    test_unpacked_msg.states[6].cn0 = -1.0;
    
    test_unpacked_msg.states[6].prn = 0;
    
    test_unpacked_msg.states[6].state = 0;
    
    
    test_unpacked_msg.states[7].cn0 = -1.0;
    
    test_unpacked_msg.states[7].prn = 0;
    
    test_unpacked_msg.states[7].state = 0;
    
    
    test_unpacked_msg.states[8].cn0 = -1.0;
    
    test_unpacked_msg.states[8].prn = 0;
    
    test_unpacked_msg.states[8].state = 0;
    
    
    test_unpacked_msg.states[9].cn0 = -1.0;
    
    test_unpacked_msg.states[9].prn = 0;
    
    test_unpacked_msg.states[9].state = 0;
    
    
    test_unpacked_msg.states[10].cn0 = -1.0;
    
    test_unpacked_msg.states[10].prn = 0;
    
    test_unpacked_msg.states[10].state = 0;
    test_unpacked_msg.states_count = 11;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_LT((last_msg_.states[0].cn0*100 - 62.1398582458*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[0].prn, 0);
    
    EXPECT_EQ(last_msg_.states[0].state, 1);
    
    EXPECT_LT((last_msg_.states[1].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[1].prn, 0);
    
    EXPECT_EQ(last_msg_.states[1].state, 0);
    
    EXPECT_LT((last_msg_.states[2].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[2].prn, 0);
    
    EXPECT_EQ(last_msg_.states[2].state, 0);
    
    EXPECT_LT((last_msg_.states[3].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[3].prn, 0);
    
    EXPECT_EQ(last_msg_.states[3].state, 0);
    
    EXPECT_LT((last_msg_.states[4].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[4].prn, 0);
    
    EXPECT_EQ(last_msg_.states[4].state, 0);
    
    EXPECT_LT((last_msg_.states[5].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[5].prn, 0);
    
    EXPECT_EQ(last_msg_.states[5].state, 0);
    
    EXPECT_LT((last_msg_.states[6].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[6].prn, 0);
    
    EXPECT_EQ(last_msg_.states[6].state, 0);
    
    EXPECT_LT((last_msg_.states[7].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[7].prn, 0);
    
    EXPECT_EQ(last_msg_.states[7].state, 0);
    
    EXPECT_LT((last_msg_.states[8].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[8].prn, 0);
    
    EXPECT_EQ(last_msg_.states[8].state, 0);
    
    EXPECT_LT((last_msg_.states[9].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[9].prn, 0);
    
    EXPECT_EQ(last_msg_.states[9].state, 0);
    
    EXPECT_LT((last_msg_.states[10].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[10].prn, 0);
    
    EXPECT_EQ(last_msg_.states[10].state, 0);
    EXPECT_EQ(last_msg_.states_count, 11);
}                                                     
class Test_auto_check_sbp_tracking_764 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>
{
public:
  Test_auto_check_sbp_tracking_764() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_764, Test)     
{

    uint8_t encoded_frame[] = {85,22,0,195,4,66,1,0,218,14,19,66,1,2,210,3,21,65,1,3,234,214,134,65,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,84,101, };

    sbp_msg_tracking_state_dep_a_t test_unpacked_msg{};
    
    
    test_unpacked_msg.states[0].cn0 = 36.764503479003906;
    
    test_unpacked_msg.states[0].prn = 0;
    
    test_unpacked_msg.states[0].state = 1;
    
    
    test_unpacked_msg.states[1].cn0 = 9.313432693481445;
    
    test_unpacked_msg.states[1].prn = 2;
    
    test_unpacked_msg.states[1].state = 1;
    
    
    test_unpacked_msg.states[2].cn0 = 16.854938507080078;
    
    test_unpacked_msg.states[2].prn = 3;
    
    test_unpacked_msg.states[2].state = 1;
    
    
    test_unpacked_msg.states[3].cn0 = -1.0;
    
    test_unpacked_msg.states[3].prn = 0;
    
    test_unpacked_msg.states[3].state = 0;
    
    
    test_unpacked_msg.states[4].cn0 = -1.0;
    
    test_unpacked_msg.states[4].prn = 0;
    
    test_unpacked_msg.states[4].state = 0;
    
    
    test_unpacked_msg.states[5].cn0 = -1.0;
    
    test_unpacked_msg.states[5].prn = 0;
    
    test_unpacked_msg.states[5].state = 0;
    
    
    test_unpacked_msg.states[6].cn0 = -1.0;
    
    test_unpacked_msg.states[6].prn = 0;
    
    test_unpacked_msg.states[6].state = 0;
    
    
    test_unpacked_msg.states[7].cn0 = -1.0;
    
    test_unpacked_msg.states[7].prn = 0;
    
    test_unpacked_msg.states[7].state = 0;
    
    
    test_unpacked_msg.states[8].cn0 = -1.0;
    
    test_unpacked_msg.states[8].prn = 0;
    
    test_unpacked_msg.states[8].state = 0;
    
    
    test_unpacked_msg.states[9].cn0 = -1.0;
    
    test_unpacked_msg.states[9].prn = 0;
    
    test_unpacked_msg.states[9].state = 0;
    
    
    test_unpacked_msg.states[10].cn0 = -1.0;
    
    test_unpacked_msg.states[10].prn = 0;
    
    test_unpacked_msg.states[10].state = 0;
    test_unpacked_msg.states_count = 11;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_LT((last_msg_.states[0].cn0*100 - 36.764503479*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[0].prn, 0);
    
    EXPECT_EQ(last_msg_.states[0].state, 1);
    
    EXPECT_LT((last_msg_.states[1].cn0*100 - 9.31343269348*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[1].prn, 2);
    
    EXPECT_EQ(last_msg_.states[1].state, 1);
    
    EXPECT_LT((last_msg_.states[2].cn0*100 - 16.8549385071*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[2].prn, 3);
    
    EXPECT_EQ(last_msg_.states[2].state, 1);
    
    EXPECT_LT((last_msg_.states[3].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[3].prn, 0);
    
    EXPECT_EQ(last_msg_.states[3].state, 0);
    
    EXPECT_LT((last_msg_.states[4].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[4].prn, 0);
    
    EXPECT_EQ(last_msg_.states[4].state, 0);
    
    EXPECT_LT((last_msg_.states[5].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[5].prn, 0);
    
    EXPECT_EQ(last_msg_.states[5].state, 0);
    
    EXPECT_LT((last_msg_.states[6].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[6].prn, 0);
    
    EXPECT_EQ(last_msg_.states[6].state, 0);
    
    EXPECT_LT((last_msg_.states[7].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[7].prn, 0);
    
    EXPECT_EQ(last_msg_.states[7].state, 0);
    
    EXPECT_LT((last_msg_.states[8].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[8].prn, 0);
    
    EXPECT_EQ(last_msg_.states[8].state, 0);
    
    EXPECT_LT((last_msg_.states[9].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[9].prn, 0);
    
    EXPECT_EQ(last_msg_.states[9].state, 0);
    
    EXPECT_LT((last_msg_.states[10].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[10].prn, 0);
    
    EXPECT_EQ(last_msg_.states[10].state, 0);
    EXPECT_EQ(last_msg_.states_count, 11);
}                                                     
class Test_auto_check_sbp_tracking_765 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>
{
public:
  Test_auto_check_sbp_tracking_765() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_765, Test)     
{

    uint8_t encoded_frame[] = {85,22,0,195,4,66,1,0,98,39,219,65,1,2,0,0,56,64,1,3,121,123,7,65,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,0,0,0,0,128,191,37,123, };

    sbp_msg_tracking_state_dep_a_t test_unpacked_msg{};
    
    
    test_unpacked_msg.states[0].cn0 = 27.394229888916016;
    
    test_unpacked_msg.states[0].prn = 0;
    
    test_unpacked_msg.states[0].state = 1;
    
    
    test_unpacked_msg.states[1].cn0 = 2.875;
    
    test_unpacked_msg.states[1].prn = 2;
    
    test_unpacked_msg.states[1].state = 1;
    
    
    test_unpacked_msg.states[2].cn0 = 8.467644691467285;
    
    test_unpacked_msg.states[2].prn = 3;
    
    test_unpacked_msg.states[2].state = 1;
    
    
    test_unpacked_msg.states[3].cn0 = -1.0;
    
    test_unpacked_msg.states[3].prn = 0;
    
    test_unpacked_msg.states[3].state = 0;
    
    
    test_unpacked_msg.states[4].cn0 = -1.0;
    
    test_unpacked_msg.states[4].prn = 0;
    
    test_unpacked_msg.states[4].state = 0;
    
    
    test_unpacked_msg.states[5].cn0 = -1.0;
    
    test_unpacked_msg.states[5].prn = 0;
    
    test_unpacked_msg.states[5].state = 0;
    
    
    test_unpacked_msg.states[6].cn0 = -1.0;
    
    test_unpacked_msg.states[6].prn = 0;
    
    test_unpacked_msg.states[6].state = 0;
    
    
    test_unpacked_msg.states[7].cn0 = -1.0;
    
    test_unpacked_msg.states[7].prn = 0;
    
    test_unpacked_msg.states[7].state = 0;
    
    
    test_unpacked_msg.states[8].cn0 = -1.0;
    
    test_unpacked_msg.states[8].prn = 0;
    
    test_unpacked_msg.states[8].state = 0;
    
    
    test_unpacked_msg.states[9].cn0 = -1.0;
    
    test_unpacked_msg.states[9].prn = 0;
    
    test_unpacked_msg.states[9].state = 0;
    
    
    test_unpacked_msg.states[10].cn0 = -1.0;
    
    test_unpacked_msg.states[10].prn = 0;
    
    test_unpacked_msg.states[10].state = 0;
    test_unpacked_msg.states_count = 11;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_LT((last_msg_.states[0].cn0*100 - 27.3942298889*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[0].prn, 0);
    
    EXPECT_EQ(last_msg_.states[0].state, 1);
    
    EXPECT_LT((last_msg_.states[1].cn0*100 - 2.875*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[1].prn, 2);
    
    EXPECT_EQ(last_msg_.states[1].state, 1);
    
    EXPECT_LT((last_msg_.states[2].cn0*100 - 8.46764469147*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[2].prn, 3);
    
    EXPECT_EQ(last_msg_.states[2].state, 1);
    
    EXPECT_LT((last_msg_.states[3].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[3].prn, 0);
    
    EXPECT_EQ(last_msg_.states[3].state, 0);
    
    EXPECT_LT((last_msg_.states[4].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[4].prn, 0);
    
    EXPECT_EQ(last_msg_.states[4].state, 0);
    
    EXPECT_LT((last_msg_.states[5].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[5].prn, 0);
    
    EXPECT_EQ(last_msg_.states[5].state, 0);
    
    EXPECT_LT((last_msg_.states[6].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[6].prn, 0);
    
    EXPECT_EQ(last_msg_.states[6].state, 0);
    
    EXPECT_LT((last_msg_.states[7].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[7].prn, 0);
    
    EXPECT_EQ(last_msg_.states[7].state, 0);
    
    EXPECT_LT((last_msg_.states[8].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[8].prn, 0);
    
    EXPECT_EQ(last_msg_.states[8].state, 0);
    
    EXPECT_LT((last_msg_.states[9].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[9].prn, 0);
    
    EXPECT_EQ(last_msg_.states[9].state, 0);
    
    EXPECT_LT((last_msg_.states[10].cn0*100 - -1.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.states[10].prn, 0);
    
    EXPECT_EQ(last_msg_.states[10].state, 0);
    EXPECT_EQ(last_msg_.states_count, 11);
}