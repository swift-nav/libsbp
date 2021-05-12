#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_observation_570 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_a_t>
{
public:
  Test_auto_check_sbp_observation_570() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_570, Test)     
{

    uint8_t encoded_frame[] = {85,69,0,195,4,98,56,158,67,24,46,7,32,56,235,249,121,244,114,255,255,33,46,67,218,0,238,203,70,124,22,25,3,0,98,43,184,157,2,176,133,197,125,126,71,253,255,185,39,68,55,3,60,173,162,131,98,231,253,255,139,30,33,16,10,128,178,248,136,42,113,253,255,40,20,42,71,13,246,246,17,135,255,51,3,0,64,27,108,249,22,210,41,114,118,131,48,255,255,31,52,226,58,30,23,217, };

    sbp_msg_obs_dep_a_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 32;
    
    
    test_unpacked_msg.header.t.tow = 407084600;
    
    test_unpacked_msg.header.t.wn = 1838;
    
    
    
    test_unpacked_msg.obs[0].L.f = 33;
    
    test_unpacked_msg.obs[0].L.i = -36108;
    
    test_unpacked_msg.obs[0].P = 2046421816;
    
    test_unpacked_msg.obs[0].cn0 = 46;
    
    test_unpacked_msg.obs[0].lock = 55875;
    
    test_unpacked_msg.obs[0].prn = 0;
    
    
    
    test_unpacked_msg.obs[1].L.f = 98;
    
    test_unpacked_msg.obs[1].L.i = 203030;
    
    test_unpacked_msg.obs[1].P = 2085014510;
    
    test_unpacked_msg.obs[1].cn0 = 43;
    
    test_unpacked_msg.obs[1].lock = 40376;
    
    test_unpacked_msg.obs[1].prn = 2;
    
    
    
    test_unpacked_msg.obs[2].L.f = 185;
    
    test_unpacked_msg.obs[2].L.i = -178306;
    
    test_unpacked_msg.obs[2].P = 2110096816;
    
    test_unpacked_msg.obs[2].cn0 = 39;
    
    test_unpacked_msg.obs[2].lock = 14148;
    
    test_unpacked_msg.obs[2].prn = 3;
    
    
    
    test_unpacked_msg.obs[3].L.f = 139;
    
    test_unpacked_msg.obs[3].L.i = -137374;
    
    test_unpacked_msg.obs[3].P = 2208476476;
    
    test_unpacked_msg.obs[3].cn0 = 30;
    
    test_unpacked_msg.obs[3].lock = 4129;
    
    test_unpacked_msg.obs[3].prn = 10;
    
    
    
    test_unpacked_msg.obs[4].L.f = 40;
    
    test_unpacked_msg.obs[4].L.i = -167638;
    
    test_unpacked_msg.obs[4].P = 2298000000;
    
    test_unpacked_msg.obs[4].cn0 = 20;
    
    test_unpacked_msg.obs[4].lock = 18218;
    
    test_unpacked_msg.obs[4].prn = 13;
    
    
    
    test_unpacked_msg.obs[5].L.f = 64;
    
    test_unpacked_msg.obs[5].L.i = 209919;
    
    test_unpacked_msg.obs[5].P = 2266101494;
    
    test_unpacked_msg.obs[5].cn0 = 27;
    
    test_unpacked_msg.obs[5].lock = 63852;
    
    test_unpacked_msg.obs[5].prn = 22;
    
    
    
    test_unpacked_msg.obs[6].L.f = 31;
    
    test_unpacked_msg.obs[6].L.i = -53117;
    
    test_unpacked_msg.obs[6].P = 1987193298;
    
    test_unpacked_msg.obs[6].cn0 = 52;
    
    test_unpacked_msg.obs[6].lock = 15074;
    
    test_unpacked_msg.obs[6].prn = 30;
    test_unpacked_msg.obs_count = 7;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 32);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 407084600);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1838);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 33);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, -36108);
    
    EXPECT_EQ(last_msg_.obs[0].P, 2046421816);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 46);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 55875);
    
    EXPECT_EQ(last_msg_.obs[0].prn, 0);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 98);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, 203030);
    
    EXPECT_EQ(last_msg_.obs[1].P, 2085014510);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 43);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 40376);
    
    EXPECT_EQ(last_msg_.obs[1].prn, 2);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 185);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, -178306);
    
    EXPECT_EQ(last_msg_.obs[2].P, 2110096816);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 39);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 14148);
    
    EXPECT_EQ(last_msg_.obs[2].prn, 3);
    
    
    EXPECT_EQ(last_msg_.obs[3].L.f, 139);
    
    EXPECT_EQ(last_msg_.obs[3].L.i, -137374);
    
    EXPECT_EQ(last_msg_.obs[3].P, 2208476476);
    
    EXPECT_EQ(last_msg_.obs[3].cn0, 30);
    
    EXPECT_EQ(last_msg_.obs[3].lock, 4129);
    
    EXPECT_EQ(last_msg_.obs[3].prn, 10);
    
    
    EXPECT_EQ(last_msg_.obs[4].L.f, 40);
    
    EXPECT_EQ(last_msg_.obs[4].L.i, -167638);
    
    EXPECT_EQ(last_msg_.obs[4].P, 2298000000);
    
    EXPECT_EQ(last_msg_.obs[4].cn0, 20);
    
    EXPECT_EQ(last_msg_.obs[4].lock, 18218);
    
    EXPECT_EQ(last_msg_.obs[4].prn, 13);
    
    
    EXPECT_EQ(last_msg_.obs[5].L.f, 64);
    
    EXPECT_EQ(last_msg_.obs[5].L.i, 209919);
    
    EXPECT_EQ(last_msg_.obs[5].P, 2266101494);
    
    EXPECT_EQ(last_msg_.obs[5].cn0, 27);
    
    EXPECT_EQ(last_msg_.obs[5].lock, 63852);
    
    EXPECT_EQ(last_msg_.obs[5].prn, 22);
    
    
    EXPECT_EQ(last_msg_.obs[6].L.f, 31);
    
    EXPECT_EQ(last_msg_.obs[6].L.i, -53117);
    
    EXPECT_EQ(last_msg_.obs[6].P, 1987193298);
    
    EXPECT_EQ(last_msg_.obs[6].cn0, 52);
    
    EXPECT_EQ(last_msg_.obs[6].lock, 15074);
    
    EXPECT_EQ(last_msg_.obs[6].prn, 30);
    EXPECT_EQ(last_msg_.obs_count, 7);
}                                                     
class Test_auto_check_sbp_observation_571 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_a_t>
{
public:
  Test_auto_check_sbp_observation_571() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_571, Test)     
{

    uint8_t encoded_frame[] = {85,69,0,195,4,20,56,158,67,24,46,7,33,84,52,164,117,102,32,0,0,147,62,62,250,31,234,14, };

    sbp_msg_obs_dep_a_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 33;
    
    
    test_unpacked_msg.header.t.tow = 407084600;
    
    test_unpacked_msg.header.t.wn = 1838;
    
    
    
    test_unpacked_msg.obs[0].L.f = 147;
    
    test_unpacked_msg.obs[0].L.i = 8294;
    
    test_unpacked_msg.obs[0].P = 1973695572;
    
    test_unpacked_msg.obs[0].cn0 = 62;
    
    test_unpacked_msg.obs[0].lock = 64062;
    
    test_unpacked_msg.obs[0].prn = 31;
    test_unpacked_msg.obs_count = 1;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 33);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 407084600);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1838);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 147);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, 8294);
    
    EXPECT_EQ(last_msg_.obs[0].P, 1973695572);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 62);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 64062);
    
    EXPECT_EQ(last_msg_.obs[0].prn, 31);
    EXPECT_EQ(last_msg_.obs_count, 1);
}                                                     
class Test_auto_check_sbp_observation_572 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_a_t>
{
public:
  Test_auto_check_sbp_observation_572() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_572, Test)     
{

    uint8_t encoded_frame[] = {85,69,0,195,4,98,0,159,67,24,46,7,32,32,209,249,121,145,114,255,255,141,45,67,218,0,177,128,70,124,79,27,3,0,159,44,184,157,2,59,135,197,125,175,69,253,255,77,40,68,55,3,211,172,162,131,177,229,253,255,20,31,33,16,10,128,178,248,136,116,111,253,255,94,21,42,71,13,182,173,17,135,37,54,3,0,214,27,108,249,22,91,20,114,118,240,47,255,255,129,52,226,58,30,200,119, };

    sbp_msg_obs_dep_a_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 32;
    
    
    test_unpacked_msg.header.t.tow = 407084800;
    
    test_unpacked_msg.header.t.wn = 1838;
    
    
    
    test_unpacked_msg.obs[0].L.f = 141;
    
    test_unpacked_msg.obs[0].L.i = -36207;
    
    test_unpacked_msg.obs[0].P = 2046415136;
    
    test_unpacked_msg.obs[0].cn0 = 45;
    
    test_unpacked_msg.obs[0].lock = 55875;
    
    test_unpacked_msg.obs[0].prn = 0;
    
    
    
    test_unpacked_msg.obs[1].L.f = 159;
    
    test_unpacked_msg.obs[1].L.i = 203599;
    
    test_unpacked_msg.obs[1].P = 2084995249;
    
    test_unpacked_msg.obs[1].cn0 = 44;
    
    test_unpacked_msg.obs[1].lock = 40376;
    
    test_unpacked_msg.obs[1].prn = 2;
    
    
    
    test_unpacked_msg.obs[2].L.f = 77;
    
    test_unpacked_msg.obs[2].L.i = -178769;
    
    test_unpacked_msg.obs[2].P = 2110097211;
    
    test_unpacked_msg.obs[2].cn0 = 40;
    
    test_unpacked_msg.obs[2].lock = 14148;
    
    test_unpacked_msg.obs[2].prn = 3;
    
    
    
    test_unpacked_msg.obs[3].L.f = 20;
    
    test_unpacked_msg.obs[3].L.i = -137807;
    
    test_unpacked_msg.obs[3].P = 2208476371;
    
    test_unpacked_msg.obs[3].cn0 = 31;
    
    test_unpacked_msg.obs[3].lock = 4129;
    
    test_unpacked_msg.obs[3].prn = 10;
    
    
    
    test_unpacked_msg.obs[4].L.f = 94;
    
    test_unpacked_msg.obs[4].L.i = -168076;
    
    test_unpacked_msg.obs[4].P = 2298000000;
    
    test_unpacked_msg.obs[4].cn0 = 21;
    
    test_unpacked_msg.obs[4].lock = 18218;
    
    test_unpacked_msg.obs[4].prn = 13;
    
    
    
    test_unpacked_msg.obs[5].L.f = 214;
    
    test_unpacked_msg.obs[5].L.i = 210469;
    
    test_unpacked_msg.obs[5].P = 2266082742;
    
    test_unpacked_msg.obs[5].cn0 = 27;
    
    test_unpacked_msg.obs[5].lock = 63852;
    
    test_unpacked_msg.obs[5].prn = 22;
    
    
    
    test_unpacked_msg.obs[6].L.f = 129;
    
    test_unpacked_msg.obs[6].L.i = -53264;
    
    test_unpacked_msg.obs[6].P = 1987187803;
    
    test_unpacked_msg.obs[6].cn0 = 52;
    
    test_unpacked_msg.obs[6].lock = 15074;
    
    test_unpacked_msg.obs[6].prn = 30;
    test_unpacked_msg.obs_count = 7;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 32);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 407084800);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1838);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 141);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, -36207);
    
    EXPECT_EQ(last_msg_.obs[0].P, 2046415136);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 45);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 55875);
    
    EXPECT_EQ(last_msg_.obs[0].prn, 0);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 159);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, 203599);
    
    EXPECT_EQ(last_msg_.obs[1].P, 2084995249);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 44);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 40376);
    
    EXPECT_EQ(last_msg_.obs[1].prn, 2);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 77);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, -178769);
    
    EXPECT_EQ(last_msg_.obs[2].P, 2110097211);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 40);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 14148);
    
    EXPECT_EQ(last_msg_.obs[2].prn, 3);
    
    
    EXPECT_EQ(last_msg_.obs[3].L.f, 20);
    
    EXPECT_EQ(last_msg_.obs[3].L.i, -137807);
    
    EXPECT_EQ(last_msg_.obs[3].P, 2208476371);
    
    EXPECT_EQ(last_msg_.obs[3].cn0, 31);
    
    EXPECT_EQ(last_msg_.obs[3].lock, 4129);
    
    EXPECT_EQ(last_msg_.obs[3].prn, 10);
    
    
    EXPECT_EQ(last_msg_.obs[4].L.f, 94);
    
    EXPECT_EQ(last_msg_.obs[4].L.i, -168076);
    
    EXPECT_EQ(last_msg_.obs[4].P, 2298000000);
    
    EXPECT_EQ(last_msg_.obs[4].cn0, 21);
    
    EXPECT_EQ(last_msg_.obs[4].lock, 18218);
    
    EXPECT_EQ(last_msg_.obs[4].prn, 13);
    
    
    EXPECT_EQ(last_msg_.obs[5].L.f, 214);
    
    EXPECT_EQ(last_msg_.obs[5].L.i, 210469);
    
    EXPECT_EQ(last_msg_.obs[5].P, 2266082742);
    
    EXPECT_EQ(last_msg_.obs[5].cn0, 27);
    
    EXPECT_EQ(last_msg_.obs[5].lock, 63852);
    
    EXPECT_EQ(last_msg_.obs[5].prn, 22);
    
    
    EXPECT_EQ(last_msg_.obs[6].L.f, 129);
    
    EXPECT_EQ(last_msg_.obs[6].L.i, -53264);
    
    EXPECT_EQ(last_msg_.obs[6].P, 1987187803);
    
    EXPECT_EQ(last_msg_.obs[6].cn0, 52);
    
    EXPECT_EQ(last_msg_.obs[6].lock, 15074);
    
    EXPECT_EQ(last_msg_.obs[6].prn, 30);
    EXPECT_EQ(last_msg_.obs_count, 7);
}                                                     
class Test_auto_check_sbp_observation_573 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_a_t>
{
public:
  Test_auto_check_sbp_observation_573() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_573, Test)     
{

    uint8_t encoded_frame[] = {85,69,0,195,4,20,0,159,67,24,46,7,33,49,19,164,117,120,32,0,0,222,63,62,250,31,11,231, };

    sbp_msg_obs_dep_a_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 33;
    
    
    test_unpacked_msg.header.t.tow = 407084800;
    
    test_unpacked_msg.header.t.wn = 1838;
    
    
    
    test_unpacked_msg.obs[0].L.f = 222;
    
    test_unpacked_msg.obs[0].L.i = 8312;
    
    test_unpacked_msg.obs[0].P = 1973687089;
    
    test_unpacked_msg.obs[0].cn0 = 63;
    
    test_unpacked_msg.obs[0].lock = 64062;
    
    test_unpacked_msg.obs[0].prn = 31;
    test_unpacked_msg.obs_count = 1;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 33);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 407084800);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1838);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 222);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, 8312);
    
    EXPECT_EQ(last_msg_.obs[0].P, 1973687089);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 63);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 64062);
    
    EXPECT_EQ(last_msg_.obs[0].prn, 31);
    EXPECT_EQ(last_msg_.obs_count, 1);
}                                                     
class Test_auto_check_sbp_observation_574 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_a_t>
{
public:
  Test_auto_check_sbp_observation_574() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_574, Test)     
{

    uint8_t encoded_frame[] = {85,69,0,195,4,72,96,162,68,24,46,7,16,87,132,217,121,121,148,255,255,189,43,175,147,0,132,64,200,125,106,31,254,255,1,41,14,177,3,128,178,248,136,70,68,254,255,166,18,184,133,13,24,127,178,134,6,25,2,0,249,28,33,96,22,170,104,86,118,67,112,255,255,203,56,208,88,30,43,107, };

    sbp_msg_obs_dep_a_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 16;
    
    
    test_unpacked_msg.header.t.tow = 407151200;
    
    test_unpacked_msg.header.t.wn = 1838;
    
    
    
    test_unpacked_msg.obs[0].L.f = 189;
    
    test_unpacked_msg.obs[0].L.i = -27527;
    
    test_unpacked_msg.obs[0].P = 2044298327;
    
    test_unpacked_msg.obs[0].cn0 = 43;
    
    test_unpacked_msg.obs[0].lock = 37807;
    
    test_unpacked_msg.obs[0].prn = 0;
    
    
    
    test_unpacked_msg.obs[1].L.f = 1;
    
    test_unpacked_msg.obs[1].L.i = -123030;
    
    test_unpacked_msg.obs[1].P = 2110275716;
    
    test_unpacked_msg.obs[1].cn0 = 41;
    
    test_unpacked_msg.obs[1].lock = 45326;
    
    test_unpacked_msg.obs[1].prn = 3;
    
    
    
    test_unpacked_msg.obs[2].L.f = 166;
    
    test_unpacked_msg.obs[2].L.i = -113594;
    
    test_unpacked_msg.obs[2].P = 2298000000;
    
    test_unpacked_msg.obs[2].cn0 = 18;
    
    test_unpacked_msg.obs[2].lock = 34232;
    
    test_unpacked_msg.obs[2].prn = 13;
    
    
    
    test_unpacked_msg.obs[3].L.f = 249;
    
    test_unpacked_msg.obs[3].L.i = 137478;
    
    test_unpacked_msg.obs[3].P = 2259844888;
    
    test_unpacked_msg.obs[3].cn0 = 28;
    
    test_unpacked_msg.obs[3].lock = 24609;
    
    test_unpacked_msg.obs[3].prn = 22;
    
    
    
    test_unpacked_msg.obs[4].L.f = 203;
    
    test_unpacked_msg.obs[4].L.i = -36797;
    
    test_unpacked_msg.obs[4].P = 1985374378;
    
    test_unpacked_msg.obs[4].cn0 = 56;
    
    test_unpacked_msg.obs[4].lock = 22736;
    
    test_unpacked_msg.obs[4].prn = 30;
    test_unpacked_msg.obs_count = 5;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 16);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 407151200);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1838);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 189);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, -27527);
    
    EXPECT_EQ(last_msg_.obs[0].P, 2044298327);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 43);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 37807);
    
    EXPECT_EQ(last_msg_.obs[0].prn, 0);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 1);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, -123030);
    
    EXPECT_EQ(last_msg_.obs[1].P, 2110275716);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 41);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 45326);
    
    EXPECT_EQ(last_msg_.obs[1].prn, 3);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 166);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, -113594);
    
    EXPECT_EQ(last_msg_.obs[2].P, 2298000000);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 18);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 34232);
    
    EXPECT_EQ(last_msg_.obs[2].prn, 13);
    
    
    EXPECT_EQ(last_msg_.obs[3].L.f, 249);
    
    EXPECT_EQ(last_msg_.obs[3].L.i, 137478);
    
    EXPECT_EQ(last_msg_.obs[3].P, 2259844888);
    
    EXPECT_EQ(last_msg_.obs[3].cn0, 28);
    
    EXPECT_EQ(last_msg_.obs[3].lock, 24609);
    
    EXPECT_EQ(last_msg_.obs[3].prn, 22);
    
    
    EXPECT_EQ(last_msg_.obs[4].L.f, 203);
    
    EXPECT_EQ(last_msg_.obs[4].L.i, -36797);
    
    EXPECT_EQ(last_msg_.obs[4].P, 1985374378);
    
    EXPECT_EQ(last_msg_.obs[4].cn0, 56);
    
    EXPECT_EQ(last_msg_.obs[4].lock, 22736);
    
    EXPECT_EQ(last_msg_.obs[4].prn, 30);
    EXPECT_EQ(last_msg_.obs_count, 5);
}                                                     
class Test_auto_check_sbp_observation_575 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_a_t>
{
public:
  Test_auto_check_sbp_observation_575() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_575, Test)     
{

    uint8_t encoded_frame[] = {85,69,0,195,4,72,40,163,68,24,46,7,16,132,107,217,121,14,148,255,255,1,44,175,147,0,129,66,200,125,148,29,254,255,153,41,14,177,3,128,178,248,136,143,66,254,255,222,18,184,133,13,158,53,178,134,42,27,2,0,237,30,33,96,22,38,83,86,118,168,111,255,255,45,56,208,88,30,1,175, };

    sbp_msg_obs_dep_a_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 16;
    
    
    test_unpacked_msg.header.t.tow = 407151400;
    
    test_unpacked_msg.header.t.wn = 1838;
    
    
    
    test_unpacked_msg.obs[0].L.f = 1;
    
    test_unpacked_msg.obs[0].L.i = -27634;
    
    test_unpacked_msg.obs[0].P = 2044291972;
    
    test_unpacked_msg.obs[0].cn0 = 44;
    
    test_unpacked_msg.obs[0].lock = 37807;
    
    test_unpacked_msg.obs[0].prn = 0;
    
    
    
    test_unpacked_msg.obs[1].L.f = 153;
    
    test_unpacked_msg.obs[1].L.i = -123500;
    
    test_unpacked_msg.obs[1].P = 2110276225;
    
    test_unpacked_msg.obs[1].cn0 = 41;
    
    test_unpacked_msg.obs[1].lock = 45326;
    
    test_unpacked_msg.obs[1].prn = 3;
    
    
    
    test_unpacked_msg.obs[2].L.f = 222;
    
    test_unpacked_msg.obs[2].L.i = -114033;
    
    test_unpacked_msg.obs[2].P = 2298000000;
    
    test_unpacked_msg.obs[2].cn0 = 18;
    
    test_unpacked_msg.obs[2].lock = 34232;
    
    test_unpacked_msg.obs[2].prn = 13;
    
    
    
    test_unpacked_msg.obs[3].L.f = 237;
    
    test_unpacked_msg.obs[3].L.i = 138026;
    
    test_unpacked_msg.obs[3].P = 2259826078;
    
    test_unpacked_msg.obs[3].cn0 = 30;
    
    test_unpacked_msg.obs[3].lock = 24609;
    
    test_unpacked_msg.obs[3].prn = 22;
    
    
    
    test_unpacked_msg.obs[4].L.f = 45;
    
    test_unpacked_msg.obs[4].L.i = -36952;
    
    test_unpacked_msg.obs[4].P = 1985368870;
    
    test_unpacked_msg.obs[4].cn0 = 56;
    
    test_unpacked_msg.obs[4].lock = 22736;
    
    test_unpacked_msg.obs[4].prn = 30;
    test_unpacked_msg.obs_count = 5;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 16);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 407151400);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1838);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 1);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, -27634);
    
    EXPECT_EQ(last_msg_.obs[0].P, 2044291972);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 44);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 37807);
    
    EXPECT_EQ(last_msg_.obs[0].prn, 0);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 153);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, -123500);
    
    EXPECT_EQ(last_msg_.obs[1].P, 2110276225);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 41);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 45326);
    
    EXPECT_EQ(last_msg_.obs[1].prn, 3);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 222);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, -114033);
    
    EXPECT_EQ(last_msg_.obs[2].P, 2298000000);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 18);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 34232);
    
    EXPECT_EQ(last_msg_.obs[2].prn, 13);
    
    
    EXPECT_EQ(last_msg_.obs[3].L.f, 237);
    
    EXPECT_EQ(last_msg_.obs[3].L.i, 138026);
    
    EXPECT_EQ(last_msg_.obs[3].P, 2259826078);
    
    EXPECT_EQ(last_msg_.obs[3].cn0, 30);
    
    EXPECT_EQ(last_msg_.obs[3].lock, 24609);
    
    EXPECT_EQ(last_msg_.obs[3].prn, 22);
    
    
    EXPECT_EQ(last_msg_.obs[4].L.f, 45);
    
    EXPECT_EQ(last_msg_.obs[4].L.i, -36952);
    
    EXPECT_EQ(last_msg_.obs[4].P, 1985368870);
    
    EXPECT_EQ(last_msg_.obs[4].cn0, 56);
    
    EXPECT_EQ(last_msg_.obs[4].lock, 22736);
    
    EXPECT_EQ(last_msg_.obs[4].prn, 30);
    EXPECT_EQ(last_msg_.obs_count, 5);
}