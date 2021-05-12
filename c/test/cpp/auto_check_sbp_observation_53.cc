#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_observation_530 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_c_t>
{
public:
  Test_auto_check_sbp_observation_530() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_c_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_c_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_c_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_530, Test)     
{

    uint8_t encoded_frame[] = {85,73,0,70,152,87,8,95,183,24,106,7,32,126,250,73,80,113,94,247,255,231,163,229,229,4,0,0,0,60,220,96,70,81,147,250,255,196,208,20,28,6,0,0,0,248,61,62,77,28,60,242,255,110,171,180,178,7,0,0,0,237,84,190,77,172,37,13,0,41,170,233,164,10,0,0,0,36,85,9,75,240,188,21,0,19,182,196,209,12,0,0,0,190,175, };

    sbp_msg_obs_dep_c_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 32;
    
    
    test_unpacked_msg.header.t.tow = 414670600;
    
    test_unpacked_msg.header.t.wn = 1898;
    
    
    
    test_unpacked_msg.obs[0].L.f = 231;
    
    test_unpacked_msg.obs[0].L.i = -565647;
    
    test_unpacked_msg.obs[0].P = 1347025534;
    
    test_unpacked_msg.obs[0].cn0 = 163;
    
    test_unpacked_msg.obs[0].lock = 58853;
    
    
    test_unpacked_msg.obs[0].sid.code = 0;
    
    test_unpacked_msg.obs[0].sid.reserved = 0;
    
    test_unpacked_msg.obs[0].sid.sat = 4;
    
    
    
    test_unpacked_msg.obs[1].L.f = 196;
    
    test_unpacked_msg.obs[1].L.i = -355503;
    
    test_unpacked_msg.obs[1].P = 1180752956;
    
    test_unpacked_msg.obs[1].cn0 = 208;
    
    test_unpacked_msg.obs[1].lock = 7188;
    
    
    test_unpacked_msg.obs[1].sid.code = 0;
    
    test_unpacked_msg.obs[1].sid.reserved = 0;
    
    test_unpacked_msg.obs[1].sid.sat = 6;
    
    
    
    test_unpacked_msg.obs[2].L.f = 110;
    
    test_unpacked_msg.obs[2].L.i = -902116;
    
    test_unpacked_msg.obs[2].P = 1295924728;
    
    test_unpacked_msg.obs[2].cn0 = 171;
    
    test_unpacked_msg.obs[2].lock = 45748;
    
    
    test_unpacked_msg.obs[2].sid.code = 0;
    
    test_unpacked_msg.obs[2].sid.reserved = 0;
    
    test_unpacked_msg.obs[2].sid.sat = 7;
    
    
    
    test_unpacked_msg.obs[3].L.f = 41;
    
    test_unpacked_msg.obs[3].L.i = 861612;
    
    test_unpacked_msg.obs[3].P = 1304319213;
    
    test_unpacked_msg.obs[3].cn0 = 170;
    
    test_unpacked_msg.obs[3].lock = 42217;
    
    
    test_unpacked_msg.obs[3].sid.code = 0;
    
    test_unpacked_msg.obs[3].sid.reserved = 0;
    
    test_unpacked_msg.obs[3].sid.sat = 10;
    
    
    
    test_unpacked_msg.obs[4].L.f = 19;
    
    test_unpacked_msg.obs[4].L.i = 1424624;
    
    test_unpacked_msg.obs[4].P = 1258902820;
    
    test_unpacked_msg.obs[4].cn0 = 182;
    
    test_unpacked_msg.obs[4].lock = 53700;
    
    
    test_unpacked_msg.obs[4].sid.code = 0;
    
    test_unpacked_msg.obs[4].sid.reserved = 0;
    
    test_unpacked_msg.obs[4].sid.sat = 12;
    test_unpacked_msg.obs_count = 5;
                                                                              
    EXPECT_EQ(send_message( 38982, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 38982);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 32);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 414670600);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1898);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 231);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, -565647);
    
    EXPECT_EQ(last_msg_.obs[0].P, 1347025534);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 163);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 58853);
    
    
    EXPECT_EQ(last_msg_.obs[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.sat, 4);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 196);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, -355503);
    
    EXPECT_EQ(last_msg_.obs[1].P, 1180752956);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 208);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 7188);
    
    
    EXPECT_EQ(last_msg_.obs[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.sat, 6);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 110);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, -902116);
    
    EXPECT_EQ(last_msg_.obs[2].P, 1295924728);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 171);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 45748);
    
    
    EXPECT_EQ(last_msg_.obs[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.sat, 7);
    
    
    EXPECT_EQ(last_msg_.obs[3].L.f, 41);
    
    EXPECT_EQ(last_msg_.obs[3].L.i, 861612);
    
    EXPECT_EQ(last_msg_.obs[3].P, 1304319213);
    
    EXPECT_EQ(last_msg_.obs[3].cn0, 170);
    
    EXPECT_EQ(last_msg_.obs[3].lock, 42217);
    
    
    EXPECT_EQ(last_msg_.obs[3].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[3].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[3].sid.sat, 10);
    
    
    EXPECT_EQ(last_msg_.obs[4].L.f, 19);
    
    EXPECT_EQ(last_msg_.obs[4].L.i, 1424624);
    
    EXPECT_EQ(last_msg_.obs[4].P, 1258902820);
    
    EXPECT_EQ(last_msg_.obs[4].cn0, 182);
    
    EXPECT_EQ(last_msg_.obs[4].lock, 53700);
    
    
    EXPECT_EQ(last_msg_.obs[4].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[4].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[4].sid.sat, 12);
    EXPECT_EQ(last_msg_.obs_count, 5);
}                                                     
class Test_auto_check_sbp_observation_531 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_c_t>
{
public:
  Test_auto_check_sbp_observation_531() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_c_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_c_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_c_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_531, Test)     
{

    uint8_t encoded_frame[] = {85,73,0,70,152,55,8,95,183,24,106,7,33,68,166,75,77,186,230,24,0,101,186,162,102,16,0,0,0,87,255,155,69,74,158,5,0,26,190,206,30,27,0,0,0,64,89,124,68,26,22,3,0,114,217,225,73,29,0,0,0,37,179, };

    sbp_msg_obs_dep_c_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 33;
    
    
    test_unpacked_msg.header.t.tow = 414670600;
    
    test_unpacked_msg.header.t.wn = 1898;
    
    
    
    test_unpacked_msg.obs[0].L.f = 101;
    
    test_unpacked_msg.obs[0].L.i = 1631930;
    
    test_unpacked_msg.obs[0].P = 1296803396;
    
    test_unpacked_msg.obs[0].cn0 = 186;
    
    test_unpacked_msg.obs[0].lock = 26274;
    
    
    test_unpacked_msg.obs[0].sid.code = 0;
    
    test_unpacked_msg.obs[0].sid.reserved = 0;
    
    test_unpacked_msg.obs[0].sid.sat = 16;
    
    
    
    test_unpacked_msg.obs[1].L.f = 26;
    
    test_unpacked_msg.obs[1].L.i = 368202;
    
    test_unpacked_msg.obs[1].P = 1167851351;
    
    test_unpacked_msg.obs[1].cn0 = 190;
    
    test_unpacked_msg.obs[1].lock = 7886;
    
    
    test_unpacked_msg.obs[1].sid.code = 0;
    
    test_unpacked_msg.obs[1].sid.reserved = 0;
    
    test_unpacked_msg.obs[1].sid.sat = 27;
    
    
    
    test_unpacked_msg.obs[2].L.f = 114;
    
    test_unpacked_msg.obs[2].L.i = 202266;
    
    test_unpacked_msg.obs[2].P = 1149000000;
    
    test_unpacked_msg.obs[2].cn0 = 217;
    
    test_unpacked_msg.obs[2].lock = 18913;
    
    
    test_unpacked_msg.obs[2].sid.code = 0;
    
    test_unpacked_msg.obs[2].sid.reserved = 0;
    
    test_unpacked_msg.obs[2].sid.sat = 29;
    test_unpacked_msg.obs_count = 3;
                                                                              
    EXPECT_EQ(send_message( 38982, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 38982);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 33);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 414670600);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1898);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 101);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, 1631930);
    
    EXPECT_EQ(last_msg_.obs[0].P, 1296803396);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 186);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 26274);
    
    
    EXPECT_EQ(last_msg_.obs[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.sat, 16);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 26);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, 368202);
    
    EXPECT_EQ(last_msg_.obs[1].P, 1167851351);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 190);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 7886);
    
    
    EXPECT_EQ(last_msg_.obs[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.sat, 27);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 114);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, 202266);
    
    EXPECT_EQ(last_msg_.obs[2].P, 1149000000);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 217);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 18913);
    
    
    EXPECT_EQ(last_msg_.obs[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.sat, 29);
    EXPECT_EQ(last_msg_.obs_count, 3);
}                                                     
class Test_auto_check_sbp_observation_532 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_c_t>
{
public:
  Test_auto_check_sbp_observation_532() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_c_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_c_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_c_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_532, Test)     
{

    uint8_t encoded_frame[] = {85,73,0,0,0,87,8,95,183,24,106,7,32,217,251,73,80,9,72,248,255,30,168,113,81,4,0,0,0,211,220,96,70,198,107,251,255,115,195,53,144,6,0,0,0,77,61,62,77,40,161,243,255,130,176,93,142,7,0,0,0,1,86,190,77,88,77,12,0,116,199,229,213,10,0,0,0,93,85,9,75,64,139,20,0,120,177,196,194,12,0,0,0,141,161, };

    sbp_msg_obs_dep_c_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 32;
    
    
    test_unpacked_msg.header.t.tow = 414670600;
    
    test_unpacked_msg.header.t.wn = 1898;
    
    
    
    test_unpacked_msg.obs[0].L.f = 30;
    
    test_unpacked_msg.obs[0].L.i = -505847;
    
    test_unpacked_msg.obs[0].P = 1347025881;
    
    test_unpacked_msg.obs[0].cn0 = 168;
    
    test_unpacked_msg.obs[0].lock = 20849;
    
    
    test_unpacked_msg.obs[0].sid.code = 0;
    
    test_unpacked_msg.obs[0].sid.reserved = 0;
    
    test_unpacked_msg.obs[0].sid.sat = 4;
    
    
    
    test_unpacked_msg.obs[1].L.f = 115;
    
    test_unpacked_msg.obs[1].L.i = -300090;
    
    test_unpacked_msg.obs[1].P = 1180753107;
    
    test_unpacked_msg.obs[1].cn0 = 195;
    
    test_unpacked_msg.obs[1].lock = 36917;
    
    
    test_unpacked_msg.obs[1].sid.code = 0;
    
    test_unpacked_msg.obs[1].sid.reserved = 0;
    
    test_unpacked_msg.obs[1].sid.sat = 6;
    
    
    
    test_unpacked_msg.obs[2].L.f = 130;
    
    test_unpacked_msg.obs[2].L.i = -810712;
    
    test_unpacked_msg.obs[2].P = 1295924557;
    
    test_unpacked_msg.obs[2].cn0 = 176;
    
    test_unpacked_msg.obs[2].lock = 36445;
    
    
    test_unpacked_msg.obs[2].sid.code = 0;
    
    test_unpacked_msg.obs[2].sid.reserved = 0;
    
    test_unpacked_msg.obs[2].sid.sat = 7;
    
    
    
    test_unpacked_msg.obs[3].L.f = 116;
    
    test_unpacked_msg.obs[3].L.i = 806232;
    
    test_unpacked_msg.obs[3].P = 1304319489;
    
    test_unpacked_msg.obs[3].cn0 = 199;
    
    test_unpacked_msg.obs[3].lock = 54757;
    
    
    test_unpacked_msg.obs[3].sid.code = 0;
    
    test_unpacked_msg.obs[3].sid.reserved = 0;
    
    test_unpacked_msg.obs[3].sid.sat = 10;
    
    
    
    test_unpacked_msg.obs[4].L.f = 120;
    
    test_unpacked_msg.obs[4].L.i = 1346368;
    
    test_unpacked_msg.obs[4].P = 1258902877;
    
    test_unpacked_msg.obs[4].cn0 = 177;
    
    test_unpacked_msg.obs[4].lock = 49860;
    
    
    test_unpacked_msg.obs[4].sid.code = 0;
    
    test_unpacked_msg.obs[4].sid.reserved = 0;
    
    test_unpacked_msg.obs[4].sid.sat = 12;
    test_unpacked_msg.obs_count = 5;
                                                                              
    EXPECT_EQ(send_message( 0, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 0);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 32);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 414670600);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1898);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 30);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, -505847);
    
    EXPECT_EQ(last_msg_.obs[0].P, 1347025881);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 168);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 20849);
    
    
    EXPECT_EQ(last_msg_.obs[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.sat, 4);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 115);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, -300090);
    
    EXPECT_EQ(last_msg_.obs[1].P, 1180753107);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 195);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 36917);
    
    
    EXPECT_EQ(last_msg_.obs[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.sat, 6);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 130);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, -810712);
    
    EXPECT_EQ(last_msg_.obs[2].P, 1295924557);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 176);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 36445);
    
    
    EXPECT_EQ(last_msg_.obs[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.sat, 7);
    
    
    EXPECT_EQ(last_msg_.obs[3].L.f, 116);
    
    EXPECT_EQ(last_msg_.obs[3].L.i, 806232);
    
    EXPECT_EQ(last_msg_.obs[3].P, 1304319489);
    
    EXPECT_EQ(last_msg_.obs[3].cn0, 199);
    
    EXPECT_EQ(last_msg_.obs[3].lock, 54757);
    
    
    EXPECT_EQ(last_msg_.obs[3].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[3].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[3].sid.sat, 10);
    
    
    EXPECT_EQ(last_msg_.obs[4].L.f, 120);
    
    EXPECT_EQ(last_msg_.obs[4].L.i, 1346368);
    
    EXPECT_EQ(last_msg_.obs[4].P, 1258902877);
    
    EXPECT_EQ(last_msg_.obs[4].cn0, 177);
    
    EXPECT_EQ(last_msg_.obs[4].lock, 49860);
    
    
    EXPECT_EQ(last_msg_.obs[4].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[4].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[4].sid.sat, 12);
    EXPECT_EQ(last_msg_.obs_count, 5);
}                                                     
class Test_auto_check_sbp_observation_533 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_c_t>
{
public:
  Test_auto_check_sbp_observation_533() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_c_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_c_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_c_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_533, Test)     
{

    uint8_t encoded_frame[] = {85,73,0,0,0,55,8,95,183,24,106,7,33,70,167,75,77,140,136,23,0,90,187,158,129,16,0,0,0,232,255,155,69,45,175,5,0,17,208,175,56,27,0,0,0,64,89,124,68,45,96,3,0,75,185,73,206,29,0,0,0,220,158, };

    sbp_msg_obs_dep_c_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 33;
    
    
    test_unpacked_msg.header.t.tow = 414670600;
    
    test_unpacked_msg.header.t.wn = 1898;
    
    
    
    test_unpacked_msg.obs[0].L.f = 90;
    
    test_unpacked_msg.obs[0].L.i = 1542284;
    
    test_unpacked_msg.obs[0].P = 1296803654;
    
    test_unpacked_msg.obs[0].cn0 = 187;
    
    test_unpacked_msg.obs[0].lock = 33182;
    
    
    test_unpacked_msg.obs[0].sid.code = 0;
    
    test_unpacked_msg.obs[0].sid.reserved = 0;
    
    test_unpacked_msg.obs[0].sid.sat = 16;
    
    
    
    test_unpacked_msg.obs[1].L.f = 17;
    
    test_unpacked_msg.obs[1].L.i = 372525;
    
    test_unpacked_msg.obs[1].P = 1167851496;
    
    test_unpacked_msg.obs[1].cn0 = 208;
    
    test_unpacked_msg.obs[1].lock = 14511;
    
    
    test_unpacked_msg.obs[1].sid.code = 0;
    
    test_unpacked_msg.obs[1].sid.reserved = 0;
    
    test_unpacked_msg.obs[1].sid.sat = 27;
    
    
    
    test_unpacked_msg.obs[2].L.f = 75;
    
    test_unpacked_msg.obs[2].L.i = 221229;
    
    test_unpacked_msg.obs[2].P = 1149000000;
    
    test_unpacked_msg.obs[2].cn0 = 185;
    
    test_unpacked_msg.obs[2].lock = 52809;
    
    
    test_unpacked_msg.obs[2].sid.code = 0;
    
    test_unpacked_msg.obs[2].sid.reserved = 0;
    
    test_unpacked_msg.obs[2].sid.sat = 29;
    test_unpacked_msg.obs_count = 3;
                                                                              
    EXPECT_EQ(send_message( 0, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 0);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 33);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 414670600);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1898);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 90);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, 1542284);
    
    EXPECT_EQ(last_msg_.obs[0].P, 1296803654);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 187);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 33182);
    
    
    EXPECT_EQ(last_msg_.obs[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.sat, 16);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 17);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, 372525);
    
    EXPECT_EQ(last_msg_.obs[1].P, 1167851496);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 208);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 14511);
    
    
    EXPECT_EQ(last_msg_.obs[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.sat, 27);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 75);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, 221229);
    
    EXPECT_EQ(last_msg_.obs[2].P, 1149000000);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 185);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 52809);
    
    
    EXPECT_EQ(last_msg_.obs[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.sat, 29);
    EXPECT_EQ(last_msg_.obs_count, 3);
}                                                     
class Test_auto_check_sbp_observation_534 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_dep_c_t>
{
public:
  Test_auto_check_sbp_observation_534() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_dep_c_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_dep_c_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_dep_c_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_534, Test)     
{

    uint8_t encoded_frame[] = {85,73,0,70,152,87,208,95,183,24,106,7,32,44,8,74,80,86,93,247,255,57,158,229,229,4,0,0,0,224,229,96,70,156,146,250,255,221,200,20,28,6,0,0,0,60,82,62,77,93,58,242,255,39,164,180,178,7,0,0,0,222,73,190,77,46,39,13,0,202,181,233,164,10,0,0,0,149,64,9,75,114,191,21,0,249,182,196,209,12,0,0,0,112,8, };

    sbp_msg_obs_dep_c_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 32;
    
    
    test_unpacked_msg.header.t.tow = 414670800;
    
    test_unpacked_msg.header.t.wn = 1898;
    
    
    
    test_unpacked_msg.obs[0].L.f = 57;
    
    test_unpacked_msg.obs[0].L.i = -565930;
    
    test_unpacked_msg.obs[0].P = 1347029036;
    
    test_unpacked_msg.obs[0].cn0 = 158;
    
    test_unpacked_msg.obs[0].lock = 58853;
    
    
    test_unpacked_msg.obs[0].sid.code = 0;
    
    test_unpacked_msg.obs[0].sid.reserved = 0;
    
    test_unpacked_msg.obs[0].sid.sat = 4;
    
    
    
    test_unpacked_msg.obs[1].L.f = 221;
    
    test_unpacked_msg.obs[1].L.i = -355684;
    
    test_unpacked_msg.obs[1].P = 1180755424;
    
    test_unpacked_msg.obs[1].cn0 = 200;
    
    test_unpacked_msg.obs[1].lock = 7188;
    
    
    test_unpacked_msg.obs[1].sid.code = 0;
    
    test_unpacked_msg.obs[1].sid.reserved = 0;
    
    test_unpacked_msg.obs[1].sid.sat = 6;
    
    
    
    test_unpacked_msg.obs[2].L.f = 39;
    
    test_unpacked_msg.obs[2].L.i = -902563;
    
    test_unpacked_msg.obs[2].P = 1295929916;
    
    test_unpacked_msg.obs[2].cn0 = 164;
    
    test_unpacked_msg.obs[2].lock = 45748;
    
    
    test_unpacked_msg.obs[2].sid.code = 0;
    
    test_unpacked_msg.obs[2].sid.reserved = 0;
    
    test_unpacked_msg.obs[2].sid.sat = 7;
    
    
    
    test_unpacked_msg.obs[3].L.f = 202;
    
    test_unpacked_msg.obs[3].L.i = 861998;
    
    test_unpacked_msg.obs[3].P = 1304316382;
    
    test_unpacked_msg.obs[3].cn0 = 181;
    
    test_unpacked_msg.obs[3].lock = 42217;
    
    
    test_unpacked_msg.obs[3].sid.code = 0;
    
    test_unpacked_msg.obs[3].sid.reserved = 0;
    
    test_unpacked_msg.obs[3].sid.sat = 10;
    
    
    
    test_unpacked_msg.obs[4].L.f = 249;
    
    test_unpacked_msg.obs[4].L.i = 1425266;
    
    test_unpacked_msg.obs[4].P = 1258897557;
    
    test_unpacked_msg.obs[4].cn0 = 182;
    
    test_unpacked_msg.obs[4].lock = 53700;
    
    
    test_unpacked_msg.obs[4].sid.code = 0;
    
    test_unpacked_msg.obs[4].sid.reserved = 0;
    
    test_unpacked_msg.obs[4].sid.sat = 12;
    test_unpacked_msg.obs_count = 5;
                                                                              
    EXPECT_EQ(send_message( 38982, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 38982);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 32);
    
    
    EXPECT_EQ(last_msg_.header.t.tow, 414670800);
    
    EXPECT_EQ(last_msg_.header.t.wn, 1898);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 57);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, -565930);
    
    EXPECT_EQ(last_msg_.obs[0].P, 1347029036);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 158);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 58853);
    
    
    EXPECT_EQ(last_msg_.obs[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.sat, 4);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 221);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, -355684);
    
    EXPECT_EQ(last_msg_.obs[1].P, 1180755424);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 200);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 7188);
    
    
    EXPECT_EQ(last_msg_.obs[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.sat, 6);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 39);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, -902563);
    
    EXPECT_EQ(last_msg_.obs[2].P, 1295929916);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 164);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 45748);
    
    
    EXPECT_EQ(last_msg_.obs[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.sat, 7);
    
    
    EXPECT_EQ(last_msg_.obs[3].L.f, 202);
    
    EXPECT_EQ(last_msg_.obs[3].L.i, 861998);
    
    EXPECT_EQ(last_msg_.obs[3].P, 1304316382);
    
    EXPECT_EQ(last_msg_.obs[3].cn0, 181);
    
    EXPECT_EQ(last_msg_.obs[3].lock, 42217);
    
    
    EXPECT_EQ(last_msg_.obs[3].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[3].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[3].sid.sat, 10);
    
    
    EXPECT_EQ(last_msg_.obs[4].L.f, 249);
    
    EXPECT_EQ(last_msg_.obs[4].L.i, 1425266);
    
    EXPECT_EQ(last_msg_.obs[4].P, 1258897557);
    
    EXPECT_EQ(last_msg_.obs[4].cn0, 182);
    
    EXPECT_EQ(last_msg_.obs[4].lock, 53700);
    
    
    EXPECT_EQ(last_msg_.obs[4].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[4].sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.obs[4].sid.sat, 12);
    EXPECT_EQ(last_msg_.obs_count, 5);
}