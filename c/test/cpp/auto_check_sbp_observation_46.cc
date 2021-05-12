#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_observation_460 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_ephemeris_bds_t>
{
public:
  Test_auto_check_sbp_observation_460() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_ephemeris_bds_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_ephemeris_bds_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_ephemeris_bds_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_460, Test)     
{

    uint8_t encoded_frame[] = {85,137,0,128,240,147,8,12,174,179,6,0,106,8,0,0,0,64,48,42,0,0,1,0,125,99,52,50,207,46,151,176,0,112,96,67,0,164,106,67,0,60,255,54,0,224,47,53,0,0,143,179,0,192,190,52,146,101,162,196,109,104,19,62,253,87,86,202,62,28,251,63,0,0,0,96,151,60,117,63,0,0,128,154,127,93,185,64,151,193,64,0,10,166,4,192,160,75,174,98,8,201,35,190,205,29,12,71,189,150,5,192,176,72,249,189,193,172,240,63,72,249,188,180,160,203,9,62,0,0,0,0,92,51,77,191,0,128,174,43,0,0,88,161,174,179,6,0,106,8,6,5,0,157,249, };

    sbp_msg_ephemeris_bds_t test_unpacked_msg{};
    test_unpacked_msg.af0 = -0.0008911322802305222;
    test_unpacked_msg.af1 = 1.2398970739013748e-12;
    test_unpacked_msg.af2 = -7.318364664277155e-19;
    test_unpacked_msg.c_ic = -6.658956408500671e-08;
    test_unpacked_msg.c_is = 3.5529956221580505e-07;
    test_unpacked_msg.c_rc = 234.640625;
    test_unpacked_msg.c_rs = 224.4375;
    test_unpacked_msg.c_uc = 7.606577128171921e-06;
    test_unpacked_msg.c_us = 6.551854312419891e-07;
    
    test_unpacked_msg.common.fit_interval = 10800;
    
    test_unpacked_msg.common.health_bits = 0;
    
    
    test_unpacked_msg.common.sid.code = 12;
    
    test_unpacked_msg.common.sid.sat = 8;
    
    
    test_unpacked_msg.common.toe.tow = 439214;
    
    test_unpacked_msg.common.toe.wn = 2154;
    
    test_unpacked_msg.common.ura = 2.0;
    
    test_unpacked_msg.common.valid = 1;
    test_unpacked_msg.dn = 1.1296899132622133e-09;
    test_unpacked_msg.ecc = 0.005184737499803305;
    test_unpacked_msg.inc = 1.0421769543504915;
    test_unpacked_msg.inc_dot = 7.507455572801683e-10;
    test_unpacked_msg.iodc = 5;
    test_unpacked_msg.iode = 6;
    test_unpacked_msg.m0 = 1.6943958190727237;
    test_unpacked_msg.omega0 = -2.581073762870982;
    test_unpacked_msg.omegadot = -2.303310227830545e-09;
    test_unpacked_msg.sqrta = 6493.49845123291;
    test_unpacked_msg.tgd1 = 1.0499999980595476e-08;
    test_unpacked_msg.tgd2 = -1.0999999799921056e-09;
    
    test_unpacked_msg.toc.tow = 439214;
    
    test_unpacked_msg.toc.wn = 2154;
    test_unpacked_msg.w = -2.698603205735458;
                                                                              
    EXPECT_EQ(send_message( 61568, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 61568);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.af0*100 - -0.000891132280231*100), 0.05);
    EXPECT_LT((last_msg_.af1*100 - 1.2398970739e-12*100), 0.05);
    EXPECT_LT((last_msg_.af2*100 - -7.31836466428e-19*100), 0.05);
    EXPECT_LT((last_msg_.c_ic*100 - -6.6589564085e-08*100), 0.05);
    EXPECT_LT((last_msg_.c_is*100 - 3.55299562216e-07*100), 0.05);
    EXPECT_LT((last_msg_.c_rc*100 - 234.640625*100), 0.05);
    EXPECT_LT((last_msg_.c_rs*100 - 224.4375*100), 0.05);
    EXPECT_LT((last_msg_.c_uc*100 - 7.60657712817e-06*100), 0.05);
    EXPECT_LT((last_msg_.c_us*100 - 6.55185431242e-07*100), 0.05);
    
    EXPECT_EQ(last_msg_.common.fit_interval, 10800);
    
    EXPECT_EQ(last_msg_.common.health_bits, 0);
    
    
    EXPECT_EQ(last_msg_.common.sid.code, 12);
    
    EXPECT_EQ(last_msg_.common.sid.sat, 8);
    
    
    EXPECT_EQ(last_msg_.common.toe.tow, 439214);
    
    EXPECT_EQ(last_msg_.common.toe.wn, 2154);
    
    EXPECT_LT((last_msg_.common.ura*100 - 2.0*100), 0.05);
    
    EXPECT_EQ(last_msg_.common.valid, 1);
    EXPECT_LT((last_msg_.dn*100 - 1.12968991326e-09*100), 0.05);
    EXPECT_LT((last_msg_.ecc*100 - 0.0051847374998*100), 0.05);
    EXPECT_LT((last_msg_.inc*100 - 1.04217695435*100), 0.05);
    EXPECT_LT((last_msg_.inc_dot*100 - 7.5074555728e-10*100), 0.05);
    EXPECT_EQ(last_msg_.iodc, 5);
    EXPECT_EQ(last_msg_.iode, 6);
    EXPECT_LT((last_msg_.m0*100 - 1.69439581907*100), 0.05);
    EXPECT_LT((last_msg_.omega0*100 - -2.58107376287*100), 0.05);
    EXPECT_LT((last_msg_.omegadot*100 - -2.30331022783e-09*100), 0.05);
    EXPECT_LT((last_msg_.sqrta*100 - 6493.49845123*100), 0.05);
    EXPECT_LT((last_msg_.tgd1*100 - 1.04999999806e-08*100), 0.05);
    EXPECT_LT((last_msg_.tgd2*100 - -1.09999997999e-09*100), 0.05);
    
    EXPECT_EQ(last_msg_.toc.tow, 439214);
    
    EXPECT_EQ(last_msg_.toc.wn, 2154);
    EXPECT_LT((last_msg_.w*100 - -2.69860320574*100), 0.05);
}