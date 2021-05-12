#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_observation_540 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_osr_t>
{
public:
  Test_auto_check_sbp_observation_540() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_osr_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_osr_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_osr_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_540, Test)     
{

    uint8_t encoded_frame[] = {85,64,6,0,0,239,248,225,233,29,0,0,0,0,104,8,64,75,143,241,68,230,250,62,7,66,15,3,1,0,13,0,7,0,7,0,206,232,105,63,236,49,170,6,75,15,3,13,0,13,0,3,0,3,0,45,145,198,62,33,7,153,6,128,15,3,14,0,13,0,3,0,3,0,89,132,204,67,143,46,32,7,127,15,3,15,0,13,0,5,0,5,0,244,254,164,60,22,176,95,6,55,15,3,17,0,0,0,2,0,2,0,106,157,101,62,151,214,142,6,108,15,3,19,0,13,0,3,0,3,0,81,237,60,63,181,119,165,6,206,15,3,28,0,13,0,3,0,3,0,134,228,110,64,183,159,197,6,200,15,3,30,0,13,0,3,0,3,0,53,144,241,68,78,112,165,5,170,15,3,1,6,21,0,7,0,7,0,251,232,105,63,163,128,49,5,129,15,3,13,6,21,0,3,0,3,0,112,145,198,62,37,32,36,5,46,15,3,14,6,21,0,3,0,3,0,166,132,204,67,184,112,141,5,95,15,3,15,6,21,0,5,0,5,0,121,227, };

    sbp_msg_osr_t test_unpacked_msg{};
    
    test_unpacked_msg.header.n_obs = 64;
    
    
    test_unpacked_msg.header.t.ns_residual = 0;
    
    test_unpacked_msg.header.t.tow = 501867000;
    
    test_unpacked_msg.header.t.wn = 2152;
    
    
    
    test_unpacked_msg.obs[0].L.f = 66;
    
    test_unpacked_msg.obs[0].L.i = 121567974;
    
    test_unpacked_msg.obs[0].P = 1156681547;
    
    test_unpacked_msg.obs[0].flags = 3;
    
    test_unpacked_msg.obs[0].iono_std = 13;
    
    test_unpacked_msg.obs[0].lock = 15;
    
    test_unpacked_msg.obs[0].range_std = 7;
    
    
    test_unpacked_msg.obs[0].sid.code = 0;
    
    test_unpacked_msg.obs[0].sid.sat = 1;
    
    test_unpacked_msg.obs[0].tropo_std = 7;
    
    
    
    test_unpacked_msg.obs[1].L.f = 75;
    
    test_unpacked_msg.obs[1].L.i = 111817196;
    
    test_unpacked_msg.obs[1].P = 1063905486;
    
    test_unpacked_msg.obs[1].flags = 3;
    
    test_unpacked_msg.obs[1].iono_std = 13;
    
    test_unpacked_msg.obs[1].lock = 15;
    
    test_unpacked_msg.obs[1].range_std = 3;
    
    
    test_unpacked_msg.obs[1].sid.code = 0;
    
    test_unpacked_msg.obs[1].sid.sat = 13;
    
    test_unpacked_msg.obs[1].tropo_std = 3;
    
    
    
    test_unpacked_msg.obs[2].L.f = 128;
    
    test_unpacked_msg.obs[2].L.i = 110692129;
    
    test_unpacked_msg.obs[2].P = 1053200685;
    
    test_unpacked_msg.obs[2].flags = 3;
    
    test_unpacked_msg.obs[2].iono_std = 13;
    
    test_unpacked_msg.obs[2].lock = 15;
    
    test_unpacked_msg.obs[2].range_std = 3;
    
    
    test_unpacked_msg.obs[2].sid.code = 0;
    
    test_unpacked_msg.obs[2].sid.sat = 14;
    
    test_unpacked_msg.obs[2].tropo_std = 3;
    
    
    
    test_unpacked_msg.obs[3].L.f = 127;
    
    test_unpacked_msg.obs[3].L.i = 119549583;
    
    test_unpacked_msg.obs[3].P = 1137476697;
    
    test_unpacked_msg.obs[3].flags = 3;
    
    test_unpacked_msg.obs[3].iono_std = 13;
    
    test_unpacked_msg.obs[3].lock = 15;
    
    test_unpacked_msg.obs[3].range_std = 5;
    
    
    test_unpacked_msg.obs[3].sid.code = 0;
    
    test_unpacked_msg.obs[3].sid.sat = 15;
    
    test_unpacked_msg.obs[3].tropo_std = 5;
    
    
    
    test_unpacked_msg.obs[4].L.f = 55;
    
    test_unpacked_msg.obs[4].L.i = 106934294;
    
    test_unpacked_msg.obs[4].P = 1017446132;
    
    test_unpacked_msg.obs[4].flags = 3;
    
    test_unpacked_msg.obs[4].iono_std = 0;
    
    test_unpacked_msg.obs[4].lock = 15;
    
    test_unpacked_msg.obs[4].range_std = 2;
    
    
    test_unpacked_msg.obs[4].sid.code = 0;
    
    test_unpacked_msg.obs[4].sid.sat = 17;
    
    test_unpacked_msg.obs[4].tropo_std = 2;
    
    
    
    test_unpacked_msg.obs[5].L.f = 108;
    
    test_unpacked_msg.obs[5].L.i = 110024343;
    
    test_unpacked_msg.obs[5].P = 1046846826;
    
    test_unpacked_msg.obs[5].flags = 3;
    
    test_unpacked_msg.obs[5].iono_std = 13;
    
    test_unpacked_msg.obs[5].lock = 15;
    
    test_unpacked_msg.obs[5].range_std = 3;
    
    
    test_unpacked_msg.obs[5].sid.code = 0;
    
    test_unpacked_msg.obs[5].sid.sat = 19;
    
    test_unpacked_msg.obs[5].tropo_std = 3;
    
    
    
    test_unpacked_msg.obs[6].L.f = 206;
    
    test_unpacked_msg.obs[6].L.i = 111507381;
    
    test_unpacked_msg.obs[6].P = 1060957521;
    
    test_unpacked_msg.obs[6].flags = 3;
    
    test_unpacked_msg.obs[6].iono_std = 13;
    
    test_unpacked_msg.obs[6].lock = 15;
    
    test_unpacked_msg.obs[6].range_std = 3;
    
    
    test_unpacked_msg.obs[6].sid.code = 0;
    
    test_unpacked_msg.obs[6].sid.sat = 28;
    
    test_unpacked_msg.obs[6].tropo_std = 3;
    
    
    
    test_unpacked_msg.obs[7].L.f = 200;
    
    test_unpacked_msg.obs[7].L.i = 113614775;
    
    test_unpacked_msg.obs[7].P = 1081009286;
    
    test_unpacked_msg.obs[7].flags = 3;
    
    test_unpacked_msg.obs[7].iono_std = 13;
    
    test_unpacked_msg.obs[7].lock = 15;
    
    test_unpacked_msg.obs[7].range_std = 3;
    
    
    test_unpacked_msg.obs[7].sid.code = 0;
    
    test_unpacked_msg.obs[7].sid.sat = 30;
    
    test_unpacked_msg.obs[7].tropo_std = 3;
    
    
    
    test_unpacked_msg.obs[8].L.f = 170;
    
    test_unpacked_msg.obs[8].L.i = 94728270;
    
    test_unpacked_msg.obs[8].P = 1156681781;
    
    test_unpacked_msg.obs[8].flags = 3;
    
    test_unpacked_msg.obs[8].iono_std = 21;
    
    test_unpacked_msg.obs[8].lock = 15;
    
    test_unpacked_msg.obs[8].range_std = 7;
    
    
    test_unpacked_msg.obs[8].sid.code = 6;
    
    test_unpacked_msg.obs[8].sid.sat = 1;
    
    test_unpacked_msg.obs[8].tropo_std = 7;
    
    
    
    test_unpacked_msg.obs[9].L.f = 129;
    
    test_unpacked_msg.obs[9].L.i = 87130275;
    
    test_unpacked_msg.obs[9].P = 1063905531;
    
    test_unpacked_msg.obs[9].flags = 3;
    
    test_unpacked_msg.obs[9].iono_std = 21;
    
    test_unpacked_msg.obs[9].lock = 15;
    
    test_unpacked_msg.obs[9].range_std = 3;
    
    
    test_unpacked_msg.obs[9].sid.code = 6;
    
    test_unpacked_msg.obs[9].sid.sat = 13;
    
    test_unpacked_msg.obs[9].tropo_std = 3;
    
    
    
    test_unpacked_msg.obs[10].L.f = 46;
    
    test_unpacked_msg.obs[10].L.i = 86253605;
    
    test_unpacked_msg.obs[10].P = 1053200752;
    
    test_unpacked_msg.obs[10].flags = 3;
    
    test_unpacked_msg.obs[10].iono_std = 21;
    
    test_unpacked_msg.obs[10].lock = 15;
    
    test_unpacked_msg.obs[10].range_std = 3;
    
    
    test_unpacked_msg.obs[10].sid.code = 6;
    
    test_unpacked_msg.obs[10].sid.sat = 14;
    
    test_unpacked_msg.obs[10].tropo_std = 3;
    
    
    
    test_unpacked_msg.obs[11].L.f = 95;
    
    test_unpacked_msg.obs[11].L.i = 93155512;
    
    test_unpacked_msg.obs[11].P = 1137476774;
    
    test_unpacked_msg.obs[11].flags = 3;
    
    test_unpacked_msg.obs[11].iono_std = 21;
    
    test_unpacked_msg.obs[11].lock = 15;
    
    test_unpacked_msg.obs[11].range_std = 5;
    
    
    test_unpacked_msg.obs[11].sid.code = 6;
    
    test_unpacked_msg.obs[11].sid.sat = 15;
    
    test_unpacked_msg.obs[11].tropo_std = 5;
    test_unpacked_msg.obs_count = 12;
                                                                              
    EXPECT_EQ(send_message( 0, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 0);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.header.n_obs, 64);
    
    
    EXPECT_EQ(last_msg_.header.t.ns_residual, 0);
    
    EXPECT_EQ(last_msg_.header.t.tow, 501867000);
    
    EXPECT_EQ(last_msg_.header.t.wn, 2152);
    
    
    EXPECT_EQ(last_msg_.obs[0].L.f, 66);
    
    EXPECT_EQ(last_msg_.obs[0].L.i, 121567974);
    
    EXPECT_EQ(last_msg_.obs[0].P, 1156681547);
    
    EXPECT_EQ(last_msg_.obs[0].flags, 3);
    
    EXPECT_EQ(last_msg_.obs[0].iono_std, 13);
    
    EXPECT_EQ(last_msg_.obs[0].lock, 15);
    
    EXPECT_EQ(last_msg_.obs[0].range_std, 7);
    
    
    EXPECT_EQ(last_msg_.obs[0].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[0].sid.sat, 1);
    
    EXPECT_EQ(last_msg_.obs[0].tropo_std, 7);
    
    
    EXPECT_EQ(last_msg_.obs[1].L.f, 75);
    
    EXPECT_EQ(last_msg_.obs[1].L.i, 111817196);
    
    EXPECT_EQ(last_msg_.obs[1].P, 1063905486);
    
    EXPECT_EQ(last_msg_.obs[1].flags, 3);
    
    EXPECT_EQ(last_msg_.obs[1].iono_std, 13);
    
    EXPECT_EQ(last_msg_.obs[1].lock, 15);
    
    EXPECT_EQ(last_msg_.obs[1].range_std, 3);
    
    
    EXPECT_EQ(last_msg_.obs[1].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[1].sid.sat, 13);
    
    EXPECT_EQ(last_msg_.obs[1].tropo_std, 3);
    
    
    EXPECT_EQ(last_msg_.obs[2].L.f, 128);
    
    EXPECT_EQ(last_msg_.obs[2].L.i, 110692129);
    
    EXPECT_EQ(last_msg_.obs[2].P, 1053200685);
    
    EXPECT_EQ(last_msg_.obs[2].flags, 3);
    
    EXPECT_EQ(last_msg_.obs[2].iono_std, 13);
    
    EXPECT_EQ(last_msg_.obs[2].lock, 15);
    
    EXPECT_EQ(last_msg_.obs[2].range_std, 3);
    
    
    EXPECT_EQ(last_msg_.obs[2].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[2].sid.sat, 14);
    
    EXPECT_EQ(last_msg_.obs[2].tropo_std, 3);
    
    
    EXPECT_EQ(last_msg_.obs[3].L.f, 127);
    
    EXPECT_EQ(last_msg_.obs[3].L.i, 119549583);
    
    EXPECT_EQ(last_msg_.obs[3].P, 1137476697);
    
    EXPECT_EQ(last_msg_.obs[3].flags, 3);
    
    EXPECT_EQ(last_msg_.obs[3].iono_std, 13);
    
    EXPECT_EQ(last_msg_.obs[3].lock, 15);
    
    EXPECT_EQ(last_msg_.obs[3].range_std, 5);
    
    
    EXPECT_EQ(last_msg_.obs[3].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[3].sid.sat, 15);
    
    EXPECT_EQ(last_msg_.obs[3].tropo_std, 5);
    
    
    EXPECT_EQ(last_msg_.obs[4].L.f, 55);
    
    EXPECT_EQ(last_msg_.obs[4].L.i, 106934294);
    
    EXPECT_EQ(last_msg_.obs[4].P, 1017446132);
    
    EXPECT_EQ(last_msg_.obs[4].flags, 3);
    
    EXPECT_EQ(last_msg_.obs[4].iono_std, 0);
    
    EXPECT_EQ(last_msg_.obs[4].lock, 15);
    
    EXPECT_EQ(last_msg_.obs[4].range_std, 2);
    
    
    EXPECT_EQ(last_msg_.obs[4].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[4].sid.sat, 17);
    
    EXPECT_EQ(last_msg_.obs[4].tropo_std, 2);
    
    
    EXPECT_EQ(last_msg_.obs[5].L.f, 108);
    
    EXPECT_EQ(last_msg_.obs[5].L.i, 110024343);
    
    EXPECT_EQ(last_msg_.obs[5].P, 1046846826);
    
    EXPECT_EQ(last_msg_.obs[5].flags, 3);
    
    EXPECT_EQ(last_msg_.obs[5].iono_std, 13);
    
    EXPECT_EQ(last_msg_.obs[5].lock, 15);
    
    EXPECT_EQ(last_msg_.obs[5].range_std, 3);
    
    
    EXPECT_EQ(last_msg_.obs[5].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[5].sid.sat, 19);
    
    EXPECT_EQ(last_msg_.obs[5].tropo_std, 3);
    
    
    EXPECT_EQ(last_msg_.obs[6].L.f, 206);
    
    EXPECT_EQ(last_msg_.obs[6].L.i, 111507381);
    
    EXPECT_EQ(last_msg_.obs[6].P, 1060957521);
    
    EXPECT_EQ(last_msg_.obs[6].flags, 3);
    
    EXPECT_EQ(last_msg_.obs[6].iono_std, 13);
    
    EXPECT_EQ(last_msg_.obs[6].lock, 15);
    
    EXPECT_EQ(last_msg_.obs[6].range_std, 3);
    
    
    EXPECT_EQ(last_msg_.obs[6].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[6].sid.sat, 28);
    
    EXPECT_EQ(last_msg_.obs[6].tropo_std, 3);
    
    
    EXPECT_EQ(last_msg_.obs[7].L.f, 200);
    
    EXPECT_EQ(last_msg_.obs[7].L.i, 113614775);
    
    EXPECT_EQ(last_msg_.obs[7].P, 1081009286);
    
    EXPECT_EQ(last_msg_.obs[7].flags, 3);
    
    EXPECT_EQ(last_msg_.obs[7].iono_std, 13);
    
    EXPECT_EQ(last_msg_.obs[7].lock, 15);
    
    EXPECT_EQ(last_msg_.obs[7].range_std, 3);
    
    
    EXPECT_EQ(last_msg_.obs[7].sid.code, 0);
    
    EXPECT_EQ(last_msg_.obs[7].sid.sat, 30);
    
    EXPECT_EQ(last_msg_.obs[7].tropo_std, 3);
    
    
    EXPECT_EQ(last_msg_.obs[8].L.f, 170);
    
    EXPECT_EQ(last_msg_.obs[8].L.i, 94728270);
    
    EXPECT_EQ(last_msg_.obs[8].P, 1156681781);
    
    EXPECT_EQ(last_msg_.obs[8].flags, 3);
    
    EXPECT_EQ(last_msg_.obs[8].iono_std, 21);
    
    EXPECT_EQ(last_msg_.obs[8].lock, 15);
    
    EXPECT_EQ(last_msg_.obs[8].range_std, 7);
    
    
    EXPECT_EQ(last_msg_.obs[8].sid.code, 6);
    
    EXPECT_EQ(last_msg_.obs[8].sid.sat, 1);
    
    EXPECT_EQ(last_msg_.obs[8].tropo_std, 7);
    
    
    EXPECT_EQ(last_msg_.obs[9].L.f, 129);
    
    EXPECT_EQ(last_msg_.obs[9].L.i, 87130275);
    
    EXPECT_EQ(last_msg_.obs[9].P, 1063905531);
    
    EXPECT_EQ(last_msg_.obs[9].flags, 3);
    
    EXPECT_EQ(last_msg_.obs[9].iono_std, 21);
    
    EXPECT_EQ(last_msg_.obs[9].lock, 15);
    
    EXPECT_EQ(last_msg_.obs[9].range_std, 3);
    
    
    EXPECT_EQ(last_msg_.obs[9].sid.code, 6);
    
    EXPECT_EQ(last_msg_.obs[9].sid.sat, 13);
    
    EXPECT_EQ(last_msg_.obs[9].tropo_std, 3);
    
    
    EXPECT_EQ(last_msg_.obs[10].L.f, 46);
    
    EXPECT_EQ(last_msg_.obs[10].L.i, 86253605);
    
    EXPECT_EQ(last_msg_.obs[10].P, 1053200752);
    
    EXPECT_EQ(last_msg_.obs[10].flags, 3);
    
    EXPECT_EQ(last_msg_.obs[10].iono_std, 21);
    
    EXPECT_EQ(last_msg_.obs[10].lock, 15);
    
    EXPECT_EQ(last_msg_.obs[10].range_std, 3);
    
    
    EXPECT_EQ(last_msg_.obs[10].sid.code, 6);
    
    EXPECT_EQ(last_msg_.obs[10].sid.sat, 14);
    
    EXPECT_EQ(last_msg_.obs[10].tropo_std, 3);
    
    
    EXPECT_EQ(last_msg_.obs[11].L.f, 95);
    
    EXPECT_EQ(last_msg_.obs[11].L.i, 93155512);
    
    EXPECT_EQ(last_msg_.obs[11].P, 1137476774);
    
    EXPECT_EQ(last_msg_.obs[11].flags, 3);
    
    EXPECT_EQ(last_msg_.obs[11].iono_std, 21);
    
    EXPECT_EQ(last_msg_.obs[11].lock, 15);
    
    EXPECT_EQ(last_msg_.obs[11].range_std, 5);
    
    
    EXPECT_EQ(last_msg_.obs[11].sid.code, 6);
    
    EXPECT_EQ(last_msg_.obs[11].sid.sat, 15);
    
    EXPECT_EQ(last_msg_.obs[11].tropo_std, 5);
    EXPECT_EQ(last_msg_.obs_count, 12);
}