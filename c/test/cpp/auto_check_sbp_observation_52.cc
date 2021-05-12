#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_observation_520 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_b_t>
{
public:
  Test_auto_check_sbp_observation_520() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_520, Test)     
{

    uint8_t encoded_frame[] = {85,67,0,246,215,103,120,46,39,0,251,6,32,180,175,187,133,223,53,7,7,27,157,0,0,202,0,0,0,58,140,85,147,88,28,190,7,175,144,0,0,203,0,0,0,220,140,248,138,208,172,77,7,135,151,0,0,208,0,0,0,173,194,72,135,115,18,28,7,242,156,0,0,212,0,0,0,164,144,105,124,18,196,137,6,120,168,0,0,217,0,0,0,30,232,228,139,210,7,90,7,87,150,0,0,218,0,0,0,169,85, };

    sbp_msg_obs_dep_b_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 32;
    
    
    test_unpacked_msg.header.t.tow = 2567800;
    
    test_unpacked_msg.header.t.wn = 1787;
    
    
    
    test_unpacked_msg.obs[0].L.f = 27;
    
    test_unpacked_msg.obs[0].L.i = 117913055;
    
    test_unpacked_msg.obs[0].P = 2243669940;
    
    test_unpacked_msg.obs[0].cn0 = 157;
    
    test_unpacked_msg.obs[0].lock = 0;
    
    
    test_unpacked_msg.obs[0].sid.code = 0;
    
    test_unpacked_msg.obs[0].sid.reserved = 0;
    
    test_unpacked_msg.obs[0].sid.sat = 202;
    
    
    
    test_unpacked_msg.obs[1].L.f = 175;
    
    test_unpacked_msg.obs[1].L.i = 129899608;
    
    test_unpacked_msg.obs[1].P = 2471857210;
    
    test_unpacked_msg.obs[1].cn0 = 144;
    
    test_unpacked_msg.obs[1].lock = 0;
    
    
    test_unpacked_msg.obs[1].sid.code = 0;
    
    test_unpacked_msg.obs[1].sid.reserved = 0;
    
    test_unpacked_msg.obs[1].sid.sat = 203;
    
    
    
    test_unpacked_msg.obs[2].L.f = 135;
    
    test_unpacked_msg.obs[2].L.i = 122531024;
    
    test_unpacked_msg.obs[2].P = 2331544796;
    
    test_unpacked_msg.obs[2].cn0 = 151;
    
    test_unpacked_msg.obs[2].lock = 0;
    
    
    test_unpacked_msg.obs[2].sid.code = 0;
    
    test_unpacked_msg.obs[2].sid.reserved = 0;
    
    test_unpacked_msg.obs[2].sid.sat = 208;
    
    
    
    test_unpacked_msg.obs[3].L.f = 242;
    
    test_unpacked_msg.obs[3].L.i = 119280243;
    
    test_unpacked_msg.obs[3].P = 2269692589;
    
    test_unpacked_msg.obs[3].cn0 = 156;
    
    test_unpacked_msg.obs[3].lock = 0;
    
    
    test_unpacked_msg.obs[3].sid.code = 0;
    
    test_unpacked_msg.obs[3].sid.reserved = 0;
    
    test_unpacked_msg.obs[3].sid.sat = 212;
    
    
    
    test_unpacked_msg.obs[4].L.f = 120;
    
    test_unpacked_msg.obs[4].L.i = 109691922;
    
    test_unpacked_msg.obs[4].P = 2087293092;
    
    test_unpacked_msg.obs[4].cn0 = 168;
    
    test_unpacked_msg.obs[4].lock = 0;
    
    
    test_unpacked_msg.obs[4].sid.code = 0;
    
    test_unpacked_msg.obs[4].sid.reserved = 0;
    
    test_unpacked_msg.obs[4].sid.sat = 217;
    
    
    
    test_unpacked_msg.obs[5].L.f = 87;
    
    test_unpacked_msg.obs[5].L.i = 123340754;
    
    test_unpacked_msg.obs[5].P = 2347034654;
    
    test_unpacked_msg.obs[5].cn0 = 150;
    
    test_unpacked_msg.obs[5].lock = 0;
    
    
    test_unpacked_msg.obs[5].sid.code = 0;
    
    test_unpacked_msg.obs[5].sid.reserved = 0;
    
    test_unpacked_msg.obs[5].sid.sat = 218;
    test_unpacked_msg.obs_count = 6;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 32);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 2567800);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1787);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 27);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, 117913055);
    
    EXPECT_EQ(last_msg_.obs[0].P, 2243669940);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 157);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.sat, 202);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 175);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, 129899608);
    
    EXPECT_EQ(last_msg_.obs[1].P, 2471857210);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 144);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.sat, 203);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 135);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, 122531024);
    
    EXPECT_EQ(last_msg_.obs[2].P, 2331544796);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 151);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.sat, 208);
    
    
    EXPECT_EQ(last_msg_.obs[3].L.f, 242);
    
    EXPECT_EQ(last_msg_.obs[3].L.i, 119280243);
    
    EXPECT_EQ(last_msg_.obs[3].P, 2269692589);
    
    EXPECT_EQ(last_msg_.obs[3].cn0, 156);
    
    EXPECT_EQ(last_msg_.obs[3].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[3].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[3].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[3].sid.sat, 212);
    
    
    EXPECT_EQ(last_msg_.obs[4].L.f, 120);
    
    EXPECT_EQ(last_msg_.obs[4].L.i, 109691922);
    
    EXPECT_EQ(last_msg_.obs[4].P, 2087293092);
    
    EXPECT_EQ(last_msg_.obs[4].cn0, 168);
    
    EXPECT_EQ(last_msg_.obs[4].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[4].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[4].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[4].sid.sat, 217);
    
    
    EXPECT_EQ(last_msg_.obs[5].L.f, 87);
    
    EXPECT_EQ(last_msg_.obs[5].L.i, 123340754);
    
    EXPECT_EQ(last_msg_.obs[5].P, 2347034654);
    
    EXPECT_EQ(last_msg_.obs[5].cn0, 150);
    
    EXPECT_EQ(last_msg_.obs[5].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[5].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[5].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[5].sid.sat, 218);
    EXPECT_EQ(last_msg_.obs_count, 6);
}                                                     
class Test_auto_check_sbp_observation_521 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_b_t>
{
public:
  Test_auto_check_sbp_observation_521() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_521, Test)     
{

    uint8_t encoded_frame[] = {85,67,0,246,215,55,120,46,39,0,251,6,33,68,199,101,136,133,247,42,7,219,154,0,0,220,0,0,0,219,14,123,133,96,215,3,7,235,156,0,0,222,0,0,0,87,166,81,122,5,173,109,6,174,170,0,0,225,0,0,0,11,233, };

    sbp_msg_obs_dep_b_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 33;
    
    
    test_unpacked_msg.header.t.tow = 2567800;
    
    test_unpacked_msg.header.t.wn = 1787;
    
    
    
    test_unpacked_msg.obs[0].L.f = 219;
    
    test_unpacked_msg.obs[0].L.i = 120256389;
    
    test_unpacked_msg.obs[0].P = 2288371524;
    
    test_unpacked_msg.obs[0].cn0 = 154;
    
    test_unpacked_msg.obs[0].lock = 0;
    
    
    test_unpacked_msg.obs[0].sid.code = 0;
    
    test_unpacked_msg.obs[0].sid.reserved = 0;
    
    test_unpacked_msg.obs[0].sid.sat = 220;
    
    
    
    test_unpacked_msg.obs[1].L.f = 235;
    
    test_unpacked_msg.obs[1].L.i = 117692256;
    
    test_unpacked_msg.obs[1].P = 2239434459;
    
    test_unpacked_msg.obs[1].cn0 = 156;
    
    test_unpacked_msg.obs[1].lock = 0;
    
    
    test_unpacked_msg.obs[1].sid.code = 0;
    
    test_unpacked_msg.obs[1].sid.reserved = 0;
    
    test_unpacked_msg.obs[1].sid.sat = 222;
    
    
    
    test_unpacked_msg.obs[2].L.f = 174;
    
    test_unpacked_msg.obs[2].L.i = 107851013;
    
    test_unpacked_msg.obs[2].P = 2052171351;
    
    test_unpacked_msg.obs[2].cn0 = 170;
    
    test_unpacked_msg.obs[2].lock = 0;
    
    
    test_unpacked_msg.obs[2].sid.code = 0;
    
    test_unpacked_msg.obs[2].sid.reserved = 0;
    
    test_unpacked_msg.obs[2].sid.sat = 225;
    test_unpacked_msg.obs_count = 3;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 33);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 2567800);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1787);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 219);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, 120256389);
    
    EXPECT_EQ(last_msg_.obs[0].P, 2288371524);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 154);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.sat, 220);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 235);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, 117692256);
    
    EXPECT_EQ(last_msg_.obs[1].P, 2239434459);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 156);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.sat, 222);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 174);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, 107851013);
    
    EXPECT_EQ(last_msg_.obs[2].P, 2052171351);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 170);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.sat, 225);
    EXPECT_EQ(last_msg_.obs_count, 3);
}                                                     
class Test_auto_check_sbp_observation_522 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_b_t>
{
public:
  Test_auto_check_sbp_observation_522() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_522, Test)     
{

    uint8_t encoded_frame[] = {85,67,0,246,215,103,64,47,39,0,251,6,32,100,132,187,133,236,51,7,7,94,156,0,0,202,0,0,0,97,184,85,147,178,30,190,7,40,140,0,0,203,0,0,0,135,111,248,138,90,171,77,7,2,150,0,0,208,0,0,0,180,238,72,135,190,20,28,7,241,155,0,0,212,0,0,0,15,153,105,124,92,196,137,6,153,168,0,0,217,0,0,0,49,185,228,139,144,5,90,7,41,150,0,0,218,0,0,0,241,98, };

    sbp_msg_obs_dep_b_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 32;
    
    
    test_unpacked_msg.header.t.tow = 2568000;
    
    test_unpacked_msg.header.t.wn = 1787;
    
    
    
    test_unpacked_msg.obs[0].L.f = 94;
    
    test_unpacked_msg.obs[0].L.i = 117912556;
    
    test_unpacked_msg.obs[0].P = 2243658852;
    
    test_unpacked_msg.obs[0].cn0 = 156;
    
    test_unpacked_msg.obs[0].lock = 0;
    
    
    test_unpacked_msg.obs[0].sid.code = 0;
    
    test_unpacked_msg.obs[0].sid.reserved = 0;
    
    test_unpacked_msg.obs[0].sid.sat = 202;
    
    
    
    test_unpacked_msg.obs[1].L.f = 40;
    
    test_unpacked_msg.obs[1].L.i = 129900210;
    
    test_unpacked_msg.obs[1].P = 2471868513;
    
    test_unpacked_msg.obs[1].cn0 = 140;
    
    test_unpacked_msg.obs[1].lock = 0;
    
    
    test_unpacked_msg.obs[1].sid.code = 0;
    
    test_unpacked_msg.obs[1].sid.reserved = 0;
    
    test_unpacked_msg.obs[1].sid.sat = 203;
    
    
    
    test_unpacked_msg.obs[2].L.f = 2;
    
    test_unpacked_msg.obs[2].L.i = 122530650;
    
    test_unpacked_msg.obs[2].P = 2331537287;
    
    test_unpacked_msg.obs[2].cn0 = 150;
    
    test_unpacked_msg.obs[2].lock = 0;
    
    
    test_unpacked_msg.obs[2].sid.code = 0;
    
    test_unpacked_msg.obs[2].sid.reserved = 0;
    
    test_unpacked_msg.obs[2].sid.sat = 208;
    
    
    
    test_unpacked_msg.obs[3].L.f = 241;
    
    test_unpacked_msg.obs[3].L.i = 119280830;
    
    test_unpacked_msg.obs[3].P = 2269703860;
    
    test_unpacked_msg.obs[3].cn0 = 155;
    
    test_unpacked_msg.obs[3].lock = 0;
    
    
    test_unpacked_msg.obs[3].sid.code = 0;
    
    test_unpacked_msg.obs[3].sid.reserved = 0;
    
    test_unpacked_msg.obs[3].sid.sat = 212;
    
    
    
    test_unpacked_msg.obs[4].L.f = 153;
    
    test_unpacked_msg.obs[4].L.i = 109691996;
    
    test_unpacked_msg.obs[4].P = 2087295247;
    
    test_unpacked_msg.obs[4].cn0 = 168;
    
    test_unpacked_msg.obs[4].lock = 0;
    
    
    test_unpacked_msg.obs[4].sid.code = 0;
    
    test_unpacked_msg.obs[4].sid.reserved = 0;
    
    test_unpacked_msg.obs[4].sid.sat = 217;
    
    
    
    test_unpacked_msg.obs[5].L.f = 41;
    
    test_unpacked_msg.obs[5].L.i = 123340176;
    
    test_unpacked_msg.obs[5].P = 2347022641;
    
    test_unpacked_msg.obs[5].cn0 = 150;
    
    test_unpacked_msg.obs[5].lock = 0;
    
    
    test_unpacked_msg.obs[5].sid.code = 0;
    
    test_unpacked_msg.obs[5].sid.reserved = 0;
    
    test_unpacked_msg.obs[5].sid.sat = 218;
    test_unpacked_msg.obs_count = 6;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 32);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 2568000);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1787);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 94);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, 117912556);
    
    EXPECT_EQ(last_msg_.obs[0].P, 2243658852);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 156);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.sat, 202);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 40);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, 129900210);
    
    EXPECT_EQ(last_msg_.obs[1].P, 2471868513);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 140);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.sat, 203);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 2);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, 122530650);
    
    EXPECT_EQ(last_msg_.obs[2].P, 2331537287);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 150);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.sat, 208);
    
    
    EXPECT_EQ(last_msg_.obs[3].L.f, 241);
    
    EXPECT_EQ(last_msg_.obs[3].L.i, 119280830);
    
    EXPECT_EQ(last_msg_.obs[3].P, 2269703860);
    
    EXPECT_EQ(last_msg_.obs[3].cn0, 155);
    
    EXPECT_EQ(last_msg_.obs[3].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[3].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[3].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[3].sid.sat, 212);
    
    
    EXPECT_EQ(last_msg_.obs[4].L.f, 153);
    
    EXPECT_EQ(last_msg_.obs[4].L.i, 109691996);
    
    EXPECT_EQ(last_msg_.obs[4].P, 2087295247);
    
    EXPECT_EQ(last_msg_.obs[4].cn0, 168);
    
    EXPECT_EQ(last_msg_.obs[4].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[4].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[4].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[4].sid.sat, 217);
    
    
    EXPECT_EQ(last_msg_.obs[5].L.f, 41);
    
    EXPECT_EQ(last_msg_.obs[5].L.i, 123340176);
    
    EXPECT_EQ(last_msg_.obs[5].P, 2347022641);
    
    EXPECT_EQ(last_msg_.obs[5].cn0, 150);
    
    EXPECT_EQ(last_msg_.obs[5].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[5].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[5].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[5].sid.sat, 218);
    EXPECT_EQ(last_msg_.obs_count, 6);
}                                                     
class Test_auto_check_sbp_observation_523 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_b_t>
{
public:
  Test_auto_check_sbp_observation_523() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_523, Test)     
{

    uint8_t encoded_frame[] = {85,67,0,246,215,55,64,47,39,0,251,6,33,234,148,101,136,15,245,42,7,20,154,0,0,220,0,0,0,208,247,122,133,16,214,3,7,38,156,0,0,222,0,0,0,15,150,81,122,22,172,109,6,7,172,0,0,225,0,0,0,201,13, };

    sbp_msg_obs_dep_b_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 33;
    
    
    test_unpacked_msg.header.t.tow = 2568000;
    
    test_unpacked_msg.header.t.wn = 1787;
    
    
    
    test_unpacked_msg.obs[0].L.f = 20;
    
    test_unpacked_msg.obs[0].L.i = 120255759;
    
    test_unpacked_msg.obs[0].P = 2288358634;
    
    test_unpacked_msg.obs[0].cn0 = 154;
    
    test_unpacked_msg.obs[0].lock = 0;
    
    
    test_unpacked_msg.obs[0].sid.code = 0;
    
    test_unpacked_msg.obs[0].sid.reserved = 0;
    
    test_unpacked_msg.obs[0].sid.sat = 220;
    
    
    
    test_unpacked_msg.obs[1].L.f = 38;
    
    test_unpacked_msg.obs[1].L.i = 117691920;
    
    test_unpacked_msg.obs[1].P = 2239428560;
    
    test_unpacked_msg.obs[1].cn0 = 156;
    
    test_unpacked_msg.obs[1].lock = 0;
    
    
    test_unpacked_msg.obs[1].sid.code = 0;
    
    test_unpacked_msg.obs[1].sid.reserved = 0;
    
    test_unpacked_msg.obs[1].sid.sat = 222;
    
    
    
    test_unpacked_msg.obs[2].L.f = 7;
    
    test_unpacked_msg.obs[2].L.i = 107850774;
    
    test_unpacked_msg.obs[2].P = 2052167183;
    
    test_unpacked_msg.obs[2].cn0 = 172;
    
    test_unpacked_msg.obs[2].lock = 0;
    
    
    test_unpacked_msg.obs[2].sid.code = 0;
    
    test_unpacked_msg.obs[2].sid.reserved = 0;
    
    test_unpacked_msg.obs[2].sid.sat = 225;
    test_unpacked_msg.obs_count = 3;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 33);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 2568000);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1787);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 20);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, 120255759);
    
    EXPECT_EQ(last_msg_.obs[0].P, 2288358634);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 154);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.sat, 220);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 38);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, 117691920);
    
    EXPECT_EQ(last_msg_.obs[1].P, 2239428560);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 156);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.sat, 222);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 7);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, 107850774);
    
    EXPECT_EQ(last_msg_.obs[2].P, 2052167183);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 172);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.sat, 225);
    EXPECT_EQ(last_msg_.obs_count, 3);
}                                                     
class Test_auto_check_sbp_observation_524 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_b_t>
{
public:
  Test_auto_check_sbp_observation_524() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_b_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_b_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_b_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_524, Test)     
{

    uint8_t encoded_frame[] = {85,67,0,246,215,103,8,48,39,0,251,6,32,254,96,187,133,249,49,7,7,165,156,0,0,202,0,0,0,113,229,85,147,11,33,190,7,106,143,0,0,203,0,0,0,182,85,248,138,227,169,77,7,159,150,0,0,208,0,0,0,17,24,73,135,10,23,28,7,7,156,0,0,212,0,0,0,108,155,105,124,166,196,137,6,186,170,0,0,217,0,0,0,214,142,228,139,77,3,90,7,236,151,0,0,218,0,0,0,59,118, };

    sbp_msg_obs_dep_b_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 32;
    
    
    test_unpacked_msg.header.t.tow = 2568200;
    
    test_unpacked_msg.header.t.wn = 1787;
    
    
    
    test_unpacked_msg.obs[0].L.f = 165;
    
    test_unpacked_msg.obs[0].L.i = 117912057;
    
    test_unpacked_msg.obs[0].P = 2243649790;
    
    test_unpacked_msg.obs[0].cn0 = 156;
    
    test_unpacked_msg.obs[0].lock = 0;
    
    
    test_unpacked_msg.obs[0].sid.code = 0;
    
    test_unpacked_msg.obs[0].sid.reserved = 0;
    
    test_unpacked_msg.obs[0].sid.sat = 202;
    
    
    
    test_unpacked_msg.obs[1].L.f = 106;
    
    test_unpacked_msg.obs[1].L.i = 129900811;
    
    test_unpacked_msg.obs[1].P = 2471880049;
    
    test_unpacked_msg.obs[1].cn0 = 143;
    
    test_unpacked_msg.obs[1].lock = 0;
    
    
    test_unpacked_msg.obs[1].sid.code = 0;
    
    test_unpacked_msg.obs[1].sid.reserved = 0;
    
    test_unpacked_msg.obs[1].sid.sat = 203;
    
    
    
    test_unpacked_msg.obs[2].L.f = 159;
    
    test_unpacked_msg.obs[2].L.i = 122530275;
    
    test_unpacked_msg.obs[2].P = 2331530678;
    
    test_unpacked_msg.obs[2].cn0 = 150;
    
    test_unpacked_msg.obs[2].lock = 0;
    
    
    test_unpacked_msg.obs[2].sid.code = 0;
    
    test_unpacked_msg.obs[2].sid.reserved = 0;
    
    test_unpacked_msg.obs[2].sid.sat = 208;
    
    
    
    test_unpacked_msg.obs[3].L.f = 7;
    
    test_unpacked_msg.obs[3].L.i = 119281418;
    
    test_unpacked_msg.obs[3].P = 2269714449;
    
    test_unpacked_msg.obs[3].cn0 = 156;
    
    test_unpacked_msg.obs[3].lock = 0;
    
    
    test_unpacked_msg.obs[3].sid.code = 0;
    
    test_unpacked_msg.obs[3].sid.reserved = 0;
    
    test_unpacked_msg.obs[3].sid.sat = 212;
    
    
    
    test_unpacked_msg.obs[4].L.f = 186;
    
    test_unpacked_msg.obs[4].L.i = 109692070;
    
    test_unpacked_msg.obs[4].P = 2087295852;
    
    test_unpacked_msg.obs[4].cn0 = 170;
    
    test_unpacked_msg.obs[4].lock = 0;
    
    
    test_unpacked_msg.obs[4].sid.code = 0;
    
    test_unpacked_msg.obs[4].sid.reserved = 0;
    
    test_unpacked_msg.obs[4].sid.sat = 217;
    
    
    
    test_unpacked_msg.obs[5].L.f = 236;
    
    test_unpacked_msg.obs[5].L.i = 123339597;
    
    test_unpacked_msg.obs[5].P = 2347011798;
    
    test_unpacked_msg.obs[5].cn0 = 151;
    
    test_unpacked_msg.obs[5].lock = 0;
    
    
    test_unpacked_msg.obs[5].sid.code = 0;
    
    test_unpacked_msg.obs[5].sid.reserved = 0;
    
    test_unpacked_msg.obs[5].sid.sat = 218;
    test_unpacked_msg.obs_count = 6;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 32);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 2568200);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1787);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 165);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, 117912057);
    
    EXPECT_EQ(last_msg_.obs[0].P, 2243649790);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 156);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.sat, 202);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 106);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, 129900811);
    
    EXPECT_EQ(last_msg_.obs[1].P, 2471880049);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 143);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.sat, 203);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 159);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, 122530275);
    
    EXPECT_EQ(last_msg_.obs[2].P, 2331530678);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 150);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.sat, 208);
    
    
    EXPECT_EQ(last_msg_.obs[3].L.f, 7);
    
    EXPECT_EQ(last_msg_.obs[3].L.i, 119281418);
    
    EXPECT_EQ(last_msg_.obs[3].P, 2269714449);
    
    EXPECT_EQ(last_msg_.obs[3].cn0, 156);
    
    EXPECT_EQ(last_msg_.obs[3].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[3].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[3].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[3].sid.sat, 212);
    
    
    EXPECT_EQ(last_msg_.obs[4].L.f, 186);
    
    EXPECT_EQ(last_msg_.obs[4].L.i, 109692070);
    
    EXPECT_EQ(last_msg_.obs[4].P, 2087295852);
    
    EXPECT_EQ(last_msg_.obs[4].cn0, 170);
    
    EXPECT_EQ(last_msg_.obs[4].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[4].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[4].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[4].sid.sat, 217);
    
    
    EXPECT_EQ(last_msg_.obs[5].L.f, 236);
    
    EXPECT_EQ(last_msg_.obs[5].L.i, 123339597);
    
    EXPECT_EQ(last_msg_.obs[5].P, 2347011798);
    
    EXPECT_EQ(last_msg_.obs[5].cn0, 151);
    
    EXPECT_EQ(last_msg_.obs[5].lock, 0);
    
    
    EXPECT_EQ(last_msg_.obs[5].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[5].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[5].sid.sat, 218);
    EXPECT_EQ(last_msg_.obs_count, 6);
}