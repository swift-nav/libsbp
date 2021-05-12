#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_observation_510 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_t>
{
public:
  Test_auto_check_sbp_observation_510() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_510, Test)     
{

    uint8_t encoded_frame[] = {85,74,0,129,240,249,152,202,226,25,0,0,0,0,106,8,32,49,227,254,62,121,242,158,6,146,0,250,172,182,10,15,10,0,30,228,254,62,12,189,40,5,59,83,251,172,178,10,15,10,1,215,205,144,72,106,111,160,7,243,109,243,119,158,10,15,18,0,25,207,144,72,223,96,241,5,12,52,246,27,125,9,11,18,1,34,184,223,74,150,138,222,7,53,13,11,245,114,9,15,22,0,113,80,6,69,162,41,65,7,70,127,246,246,189,9,15,23,0,247,80,6,69,213,35,167,5,221,152,248,231,158,9,11,23,1,8,146,166,64,12,122,203,6,114,51,248,67,93,3,11,27,0,221,172,173,75,217,47,244,7,232,225,11,237,123,5,15,31,0,250,174,173,75,216,163,50,6,40,70,9,62,120,3,11,31,1,135,16,6,66,99,218,11,7,7,138,242,96,176,10,15,2,3,148,130,6,58,217,88,54,6,203,21,252,96,170,10,15,3,3,186,108,197,63,127,54,211,6,80,4,241,219,200,10,15,17,3,167,195,8,57,19,204,22,6,105,51,254,182,152,10,15,18,3,237,248, };

    sbp_msg_obs_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 32;
    
    
    test_unpacked_msg.header.t.ns_residual = 0;
    
    test_unpacked_msg.header.t.tow = 434293400;
    
    test_unpacked_msg.header.t.wn = 2154;
    
    
    
    test_unpacked_msg.obs[0].D.f = 172;
    
    test_unpacked_msg.obs[0].D.i = -1536;
    
    
    test_unpacked_msg.obs[0].L.f = 146;
    
    test_unpacked_msg.obs[0].L.i = 111080057;
    
    test_unpacked_msg.obs[0].P = 1056891697;
    
    test_unpacked_msg.obs[0].cn0 = 182;
    
    test_unpacked_msg.obs[0].flags = 15;
    
    test_unpacked_msg.obs[0].lock = 10;
    
    
    test_unpacked_msg.obs[0].sid.code = 0;
    
    test_unpacked_msg.obs[0].sid.sat = 10;
    
    
    
    test_unpacked_msg.obs[1].D.f = 172;
    
    test_unpacked_msg.obs[1].D.i = -1197;
    
    
    test_unpacked_msg.obs[1].L.f = 59;
    
    test_unpacked_msg.obs[1].L.i = 86555916;
    
    test_unpacked_msg.obs[1].P = 1056891934;
    
    test_unpacked_msg.obs[1].cn0 = 178;
    
    test_unpacked_msg.obs[1].flags = 15;
    
    test_unpacked_msg.obs[1].lock = 10;
    
    
    test_unpacked_msg.obs[1].sid.code = 1;
    
    test_unpacked_msg.obs[1].sid.sat = 10;
    
    
    
    test_unpacked_msg.obs[2].D.f = 119;
    
    test_unpacked_msg.obs[2].D.i = -3219;
    
    
    test_unpacked_msg.obs[2].L.f = 243;
    
    test_unpacked_msg.obs[2].L.i = 127954794;
    
    test_unpacked_msg.obs[2].P = 1217449431;
    
    test_unpacked_msg.obs[2].cn0 = 158;
    
    test_unpacked_msg.obs[2].flags = 15;
    
    test_unpacked_msg.obs[2].lock = 10;
    
    
    test_unpacked_msg.obs[2].sid.code = 0;
    
    test_unpacked_msg.obs[2].sid.sat = 18;
    
    
    
    test_unpacked_msg.obs[3].D.f = 27;
    
    test_unpacked_msg.obs[3].D.i = -2508;
    
    
    test_unpacked_msg.obs[3].L.f = 12;
    
    test_unpacked_msg.obs[3].L.i = 99705055;
    
    test_unpacked_msg.obs[3].P = 1217449753;
    
    test_unpacked_msg.obs[3].cn0 = 125;
    
    test_unpacked_msg.obs[3].flags = 11;
    
    test_unpacked_msg.obs[3].lock = 9;
    
    
    test_unpacked_msg.obs[3].sid.code = 1;
    
    test_unpacked_msg.obs[3].sid.sat = 18;
    
    
    
    test_unpacked_msg.obs[4].D.f = 245;
    
    test_unpacked_msg.obs[4].D.i = 2829;
    
    
    test_unpacked_msg.obs[4].L.f = 53;
    
    test_unpacked_msg.obs[4].L.i = 132024982;
    
    test_unpacked_msg.obs[4].P = 1256175650;
    
    test_unpacked_msg.obs[4].cn0 = 114;
    
    test_unpacked_msg.obs[4].flags = 15;
    
    test_unpacked_msg.obs[4].lock = 9;
    
    
    test_unpacked_msg.obs[4].sid.code = 0;
    
    test_unpacked_msg.obs[4].sid.sat = 22;
    
    
    
    test_unpacked_msg.obs[5].D.f = 246;
    
    test_unpacked_msg.obs[5].D.i = -2433;
    
    
    test_unpacked_msg.obs[5].L.f = 70;
    
    test_unpacked_msg.obs[5].L.i = 121711010;
    
    test_unpacked_msg.obs[5].P = 1158041713;
    
    test_unpacked_msg.obs[5].cn0 = 189;
    
    test_unpacked_msg.obs[5].flags = 15;
    
    test_unpacked_msg.obs[5].lock = 9;
    
    
    test_unpacked_msg.obs[5].sid.code = 0;
    
    test_unpacked_msg.obs[5].sid.sat = 23;
    
    
    
    test_unpacked_msg.obs[6].D.f = 231;
    
    test_unpacked_msg.obs[6].D.i = -1896;
    
    
    test_unpacked_msg.obs[6].L.f = 221;
    
    test_unpacked_msg.obs[6].L.i = 94839765;
    
    test_unpacked_msg.obs[6].P = 1158041847;
    
    test_unpacked_msg.obs[6].cn0 = 158;
    
    test_unpacked_msg.obs[6].flags = 11;
    
    test_unpacked_msg.obs[6].lock = 9;
    
    
    test_unpacked_msg.obs[6].sid.code = 1;
    
    test_unpacked_msg.obs[6].sid.sat = 23;
    
    
    
    test_unpacked_msg.obs[7].D.f = 67;
    
    test_unpacked_msg.obs[7].D.i = -1997;
    
    
    test_unpacked_msg.obs[7].L.f = 114;
    
    test_unpacked_msg.obs[7].L.i = 113998348;
    
    test_unpacked_msg.obs[7].P = 1084658184;
    
    test_unpacked_msg.obs[7].cn0 = 93;
    
    test_unpacked_msg.obs[7].flags = 11;
    
    test_unpacked_msg.obs[7].lock = 3;
    
    
    test_unpacked_msg.obs[7].sid.code = 0;
    
    test_unpacked_msg.obs[7].sid.sat = 27;
    
    
    
    test_unpacked_msg.obs[8].D.f = 237;
    
    test_unpacked_msg.obs[8].D.i = 3041;
    
    
    test_unpacked_msg.obs[8].L.f = 232;
    
    test_unpacked_msg.obs[8].L.i = 133443545;
    
    test_unpacked_msg.obs[8].P = 1269673181;
    
    test_unpacked_msg.obs[8].cn0 = 123;
    
    test_unpacked_msg.obs[8].flags = 15;
    
    test_unpacked_msg.obs[8].lock = 5;
    
    
    test_unpacked_msg.obs[8].sid.code = 0;
    
    test_unpacked_msg.obs[8].sid.sat = 31;
    
    
    
    test_unpacked_msg.obs[9].D.f = 62;
    
    test_unpacked_msg.obs[9].D.i = 2374;
    
    
    test_unpacked_msg.obs[9].L.f = 40;
    
    test_unpacked_msg.obs[9].L.i = 103982040;
    
    test_unpacked_msg.obs[9].P = 1269673722;
    
    test_unpacked_msg.obs[9].cn0 = 120;
    
    test_unpacked_msg.obs[9].flags = 11;
    
    test_unpacked_msg.obs[9].lock = 3;
    
    
    test_unpacked_msg.obs[9].sid.code = 1;
    
    test_unpacked_msg.obs[9].sid.sat = 31;
    
    
    
    test_unpacked_msg.obs[10].D.f = 96;
    
    test_unpacked_msg.obs[10].D.i = -3446;
    
    
    test_unpacked_msg.obs[10].L.f = 7;
    
    test_unpacked_msg.obs[10].L.i = 118217315;
    
    test_unpacked_msg.obs[10].P = 1107693703;
    
    test_unpacked_msg.obs[10].cn0 = 176;
    
    test_unpacked_msg.obs[10].flags = 15;
    
    test_unpacked_msg.obs[10].lock = 10;
    
    
    test_unpacked_msg.obs[10].sid.code = 3;
    
    test_unpacked_msg.obs[10].sid.sat = 2;
    
    
    
    test_unpacked_msg.obs[11].D.f = 96;
    
    test_unpacked_msg.obs[11].D.i = -1003;
    
    
    test_unpacked_msg.obs[11].L.f = 203;
    
    test_unpacked_msg.obs[11].L.i = 104224985;
    
    test_unpacked_msg.obs[11].P = 973505172;
    
    test_unpacked_msg.obs[11].cn0 = 170;
    
    test_unpacked_msg.obs[11].flags = 15;
    
    test_unpacked_msg.obs[11].lock = 10;
    
    
    test_unpacked_msg.obs[11].sid.code = 3;
    
    test_unpacked_msg.obs[11].sid.sat = 3;
    
    
    
    test_unpacked_msg.obs[12].D.f = 219;
    
    test_unpacked_msg.obs[12].D.i = -3836;
    
    
    test_unpacked_msg.obs[12].L.f = 80;
    
    test_unpacked_msg.obs[12].L.i = 114505343;
    
    test_unpacked_msg.obs[12].P = 1069903034;
    
    test_unpacked_msg.obs[12].cn0 = 200;
    
    test_unpacked_msg.obs[12].flags = 15;
    
    test_unpacked_msg.obs[12].lock = 10;
    
    
    test_unpacked_msg.obs[12].sid.code = 3;
    
    test_unpacked_msg.obs[12].sid.sat = 17;
    
    
    
    test_unpacked_msg.obs[13].D.f = 182;
    
    test_unpacked_msg.obs[13].D.i = -461;
    
    
    test_unpacked_msg.obs[13].L.f = 105;
    
    test_unpacked_msg.obs[13].L.i = 102157331;
    
    test_unpacked_msg.obs[13].P = 956875687;
    
    test_unpacked_msg.obs[13].cn0 = 152;
    
    test_unpacked_msg.obs[13].flags = 15;
    
    test_unpacked_msg.obs[13].lock = 10;
    
    
    test_unpacked_msg.obs[13].sid.code = 3;
    
    test_unpacked_msg.obs[13].sid.sat = 18;
    test_unpacked_msg.obs_count = 14;
                                                                              
    EXPECT_EQ(send_message( 61569, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 61569);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 32);
    
    
    EXPECT_EQ(last_msg_.header.t.ns_residual, 0);
    
    EXPECT_EQ(last_msg_.header.t.tow, 434293400);
    
    EXPECT_EQ(last_msg_.header.t.wn, 2154);
    
    
    EXPECT_EQ(last_msg_.obs[0].D.f, 172);
    
    EXPECT_EQ(last_msg_.obs[0].D.i, -1536);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 146);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, 111080057);
    
    EXPECT_EQ(last_msg_.obs[0].P, 1056891697);
    
    EXPECT_EQ(last_msg_.obs[0].cn0, 182);
    
    EXPECT_EQ(last_msg_.obs[0].flags, 15);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 10);
    
    
    EXPECT_EQ(last_msg_.obs[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.sat, 10);
    
    
    EXPECT_EQ(last_msg_.obs[1].D.f, 172);
    
    EXPECT_EQ(last_msg_.obs[1].D.i, -1197);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 59);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, 86555916);
    
    EXPECT_EQ(last_msg_.obs[1].P, 1056891934);
    
    EXPECT_EQ(last_msg_.obs[1].cn0, 178);
    
    EXPECT_EQ(last_msg_.obs[1].flags, 15);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 10);
    
    
    EXPECT_EQ(last_msg_.obs[1].sid.code, 1);
    
    EXPECT_EQ(last_msg_.obs[1].sid.sat, 10);
    
    
    EXPECT_EQ(last_msg_.obs[2].D.f, 119);
    
    EXPECT_EQ(last_msg_.obs[2].D.i, -3219);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 243);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, 127954794);
    
    EXPECT_EQ(last_msg_.obs[2].P, 1217449431);
    
    EXPECT_EQ(last_msg_.obs[2].cn0, 158);
    
    EXPECT_EQ(last_msg_.obs[2].flags, 15);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 10);
    
    
    EXPECT_EQ(last_msg_.obs[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.sat, 18);
    
    
    EXPECT_EQ(last_msg_.obs[3].D.f, 27);
    
    EXPECT_EQ(last_msg_.obs[3].D.i, -2508);
    
    
    EXPECT_EQ(last_msg_.obs[3].L.f, 12);
    
    EXPECT_EQ(last_msg_.obs[3].L.i, 99705055);
    
    EXPECT_EQ(last_msg_.obs[3].P, 1217449753);
    
    EXPECT_EQ(last_msg_.obs[3].cn0, 125);
    
    EXPECT_EQ(last_msg_.obs[3].flags, 11);
    
    EXPECT_EQ(last_msg_.obs[3].lock, 9);
    
    
    EXPECT_EQ(last_msg_.obs[3].sid.code, 1);
    
    EXPECT_EQ(last_msg_.obs[3].sid.sat, 18);
    
    
    EXPECT_EQ(last_msg_.obs[4].D.f, 245);
    
    EXPECT_EQ(last_msg_.obs[4].D.i, 2829);
    
    
    EXPECT_EQ(last_msg_.obs[4].L.f, 53);
    
    EXPECT_EQ(last_msg_.obs[4].L.i, 132024982);
    
    EXPECT_EQ(last_msg_.obs[4].P, 1256175650);
    
    EXPECT_EQ(last_msg_.obs[4].cn0, 114);
    
    EXPECT_EQ(last_msg_.obs[4].flags, 15);
    
    EXPECT_EQ(last_msg_.obs[4].lock, 9);
    
    
    EXPECT_EQ(last_msg_.obs[4].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[4].sid.sat, 22);
    
    
    EXPECT_EQ(last_msg_.obs[5].D.f, 246);
    
    EXPECT_EQ(last_msg_.obs[5].D.i, -2433);
    
    
    EXPECT_EQ(last_msg_.obs[5].L.f, 70);
    
    EXPECT_EQ(last_msg_.obs[5].L.i, 121711010);
    
    EXPECT_EQ(last_msg_.obs[5].P, 1158041713);
    
    EXPECT_EQ(last_msg_.obs[5].cn0, 189);
    
    EXPECT_EQ(last_msg_.obs[5].flags, 15);
    
    EXPECT_EQ(last_msg_.obs[5].lock, 9);
    
    
    EXPECT_EQ(last_msg_.obs[5].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[5].sid.sat, 23);
    
    
    EXPECT_EQ(last_msg_.obs[6].D.f, 231);
    
    EXPECT_EQ(last_msg_.obs[6].D.i, -1896);
    
    
    EXPECT_EQ(last_msg_.obs[6].L.f, 221);
    
    EXPECT_EQ(last_msg_.obs[6].L.i, 94839765);
    
    EXPECT_EQ(last_msg_.obs[6].P, 1158041847);
    
    EXPECT_EQ(last_msg_.obs[6].cn0, 158);
    
    EXPECT_EQ(last_msg_.obs[6].flags, 11);
    
    EXPECT_EQ(last_msg_.obs[6].lock, 9);
    
    
    EXPECT_EQ(last_msg_.obs[6].sid.code, 1);
    
    EXPECT_EQ(last_msg_.obs[6].sid.sat, 23);
    
    
    EXPECT_EQ(last_msg_.obs[7].D.f, 67);
    
    EXPECT_EQ(last_msg_.obs[7].D.i, -1997);
    
    
    EXPECT_EQ(last_msg_.obs[7].L.f, 114);
    
    EXPECT_EQ(last_msg_.obs[7].L.i, 113998348);
    
    EXPECT_EQ(last_msg_.obs[7].P, 1084658184);
    
    EXPECT_EQ(last_msg_.obs[7].cn0, 93);
    
    EXPECT_EQ(last_msg_.obs[7].flags, 11);
    
    EXPECT_EQ(last_msg_.obs[7].lock, 3);
    
    
    EXPECT_EQ(last_msg_.obs[7].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[7].sid.sat, 27);
    
    
    EXPECT_EQ(last_msg_.obs[8].D.f, 237);
    
    EXPECT_EQ(last_msg_.obs[8].D.i, 3041);
    
    
    EXPECT_EQ(last_msg_.obs[8].L.f, 232);
    
    EXPECT_EQ(last_msg_.obs[8].L.i, 133443545);
    
    EXPECT_EQ(last_msg_.obs[8].P, 1269673181);
    
    EXPECT_EQ(last_msg_.obs[8].cn0, 123);
    
    EXPECT_EQ(last_msg_.obs[8].flags, 15);
    
    EXPECT_EQ(last_msg_.obs[8].lock, 5);
    
    
    EXPECT_EQ(last_msg_.obs[8].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[8].sid.sat, 31);
    
    
    EXPECT_EQ(last_msg_.obs[9].D.f, 62);
    
    EXPECT_EQ(last_msg_.obs[9].D.i, 2374);
    
    
    EXPECT_EQ(last_msg_.obs[9].L.f, 40);
    
    EXPECT_EQ(last_msg_.obs[9].L.i, 103982040);
    
    EXPECT_EQ(last_msg_.obs[9].P, 1269673722);
    
    EXPECT_EQ(last_msg_.obs[9].cn0, 120);
    
    EXPECT_EQ(last_msg_.obs[9].flags, 11);
    
    EXPECT_EQ(last_msg_.obs[9].lock, 3);
    
    
    EXPECT_EQ(last_msg_.obs[9].sid.code, 1);
    
    EXPECT_EQ(last_msg_.obs[9].sid.sat, 31);
    
    
    EXPECT_EQ(last_msg_.obs[10].D.f, 96);
    
    EXPECT_EQ(last_msg_.obs[10].D.i, -3446);
    
    
    EXPECT_EQ(last_msg_.obs[10].L.f, 7);
    
    EXPECT_EQ(last_msg_.obs[10].L.i, 118217315);
    
    EXPECT_EQ(last_msg_.obs[10].P, 1107693703);
    
    EXPECT_EQ(last_msg_.obs[10].cn0, 176);
    
    EXPECT_EQ(last_msg_.obs[10].flags, 15);
    
    EXPECT_EQ(last_msg_.obs[10].lock, 10);
    
    
    EXPECT_EQ(last_msg_.obs[10].sid.code, 3);
    
    EXPECT_EQ(last_msg_.obs[10].sid.sat, 2);
    
    
    EXPECT_EQ(last_msg_.obs[11].D.f, 96);
    
    EXPECT_EQ(last_msg_.obs[11].D.i, -1003);
    
    
    EXPECT_EQ(last_msg_.obs[11].L.f, 203);
    
    EXPECT_EQ(last_msg_.obs[11].L.i, 104224985);
    
    EXPECT_EQ(last_msg_.obs[11].P, 973505172);
    
    EXPECT_EQ(last_msg_.obs[11].cn0, 170);
    
    EXPECT_EQ(last_msg_.obs[11].flags, 15);
    
    EXPECT_EQ(last_msg_.obs[11].lock, 10);
    
    
    EXPECT_EQ(last_msg_.obs[11].sid.code, 3);
    
    EXPECT_EQ(last_msg_.obs[11].sid.sat, 3);
    
    
    EXPECT_EQ(last_msg_.obs[12].D.f, 219);
    
    EXPECT_EQ(last_msg_.obs[12].D.i, -3836);
    
    
    EXPECT_EQ(last_msg_.obs[12].L.f, 80);
    
    EXPECT_EQ(last_msg_.obs[12].L.i, 114505343);
    
    EXPECT_EQ(last_msg_.obs[12].P, 1069903034);
    
    EXPECT_EQ(last_msg_.obs[12].cn0, 200);
    
    EXPECT_EQ(last_msg_.obs[12].flags, 15);
    
    EXPECT_EQ(last_msg_.obs[12].lock, 10);
    
    
    EXPECT_EQ(last_msg_.obs[12].sid.code, 3);
    
    EXPECT_EQ(last_msg_.obs[12].sid.sat, 17);
    
    
    EXPECT_EQ(last_msg_.obs[13].D.f, 182);
    
    EXPECT_EQ(last_msg_.obs[13].D.i, -461);
    
    
    EXPECT_EQ(last_msg_.obs[13].L.f, 105);
    
    EXPECT_EQ(last_msg_.obs[13].L.i, 102157331);
    
    EXPECT_EQ(last_msg_.obs[13].P, 956875687);
    
    EXPECT_EQ(last_msg_.obs[13].cn0, 152);
    
    EXPECT_EQ(last_msg_.obs[13].flags, 15);
    
    EXPECT_EQ(last_msg_.obs[13].lock, 10);
    
    
    EXPECT_EQ(last_msg_.obs[13].sid.code, 3);
    
    EXPECT_EQ(last_msg_.obs[13].sid.sat, 18);
    EXPECT_EQ(last_msg_.obs_count, 14);
}                                                     
class Test_auto_check_sbp_observation_511 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_obs_t>
{
public:
  Test_auto_check_sbp_observation_511() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_obs_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_obs_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_obs_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_511, Test)     
{

    uint8_t encoded_frame[] = {85,74,0,129,240,11,152,202,226,25,0,0,0,0,106,8,16,201,101, };

    sbp_msg_obs_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 16;
    
    
    test_unpacked_msg.header.t.ns_residual = 0;
    
    test_unpacked_msg.header.t.tow = 434293400;
    
    test_unpacked_msg.header.t.wn = 2154;
                                                                              
    EXPECT_EQ(send_message( 61569, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 61569);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 16);
    
    
    EXPECT_EQ(last_msg_.header.t.ns_residual, 0);
    
    EXPECT_EQ(last_msg_.header.t.tow, 434293400);
    
    EXPECT_EQ(last_msg_.header.t.wn, 2154);
}