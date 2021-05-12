#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_tracking_750 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>
{
public:
  Test_auto_check_sbp_tracking_750() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_detailed_dep_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_detailed_dep_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_750, Test)     
{

    uint8_t encoded_frame[] = {85,17,0,59,103,55,163,151,112,215,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,5,0,0,169,177,208,54,15,0,0,0,85,61,0,0,39,0,1,0,0,0,0,0,0,0,40,0,108,1,0,11,0,0,9,166,214, };

    sbp_msg_tracking_state_detailed_dep_t test_unpacked_msg{};
    
    test_unpacked_msg.L.f = 169;
    
    test_unpacked_msg.L.i = 1319;
    test_unpacked_msg.P = 0;
    test_unpacked_msg.P_std = 0;
    test_unpacked_msg.acceleration = 108;
    test_unpacked_msg.clock_drift = 0;
    test_unpacked_msg.clock_offset = 0;
    test_unpacked_msg.cn0 = 177;
    test_unpacked_msg.corr_spacing = 40;
    test_unpacked_msg.doppler = 15701;
    test_unpacked_msg.doppler_std = 39;
    test_unpacked_msg.lock = 14032;
    test_unpacked_msg.misc_flags = 9;
    test_unpacked_msg.nav_flags = 0;
    test_unpacked_msg.pset_flags = 0;
    test_unpacked_msg.recv_time = 7909447587;
    
    test_unpacked_msg.sid.code = 0;
    
    test_unpacked_msg.sid.reserved = 0;
    
    test_unpacked_msg.sid.sat = 15;
    test_unpacked_msg.sync_flags = 1;
    
    test_unpacked_msg.tot.tow = 0;
    
    test_unpacked_msg.tot.wn = 0;
    test_unpacked_msg.tow_flags = 0;
    test_unpacked_msg.track_flags = 11;
    test_unpacked_msg.uptime = 1;
                                                                              
    EXPECT_EQ(send_message( 26427, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 26427);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.L.f, 169);
    
    EXPECT_EQ(last_msg_.L.i, 1319);
    EXPECT_EQ(last_msg_.P, 0);
    EXPECT_EQ(last_msg_.P_std, 0);
    EXPECT_EQ(last_msg_.acceleration, 108);
    EXPECT_EQ(last_msg_.clock_drift, 0);
    EXPECT_EQ(last_msg_.clock_offset, 0);
    EXPECT_EQ(last_msg_.cn0, 177);
    EXPECT_EQ(last_msg_.corr_spacing, 40);
    EXPECT_EQ(last_msg_.doppler, 15701);
    EXPECT_EQ(last_msg_.doppler_std, 39);
    EXPECT_EQ(last_msg_.lock, 14032);
    EXPECT_EQ(last_msg_.misc_flags, 9);
    EXPECT_EQ(last_msg_.nav_flags, 0);
    EXPECT_EQ(last_msg_.pset_flags, 0);
    EXPECT_EQ(last_msg_.recv_time, 7909447587);
    
    EXPECT_EQ(last_msg_.sid.code, 0);
    
    EXPECT_EQ(last_msg_.sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.sid.sat, 15);
    EXPECT_EQ(last_msg_.sync_flags, 1);
    
    EXPECT_EQ(last_msg_.tot.tow, 0);
    
    EXPECT_EQ(last_msg_.tot.wn, 0);
    EXPECT_EQ(last_msg_.tow_flags, 0);
    EXPECT_EQ(last_msg_.track_flags, 11);
    EXPECT_EQ(last_msg_.uptime, 1);
}                                                     
class Test_auto_check_sbp_tracking_751 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>
{
public:
  Test_auto_check_sbp_tracking_751() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_detailed_dep_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_detailed_dep_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_751, Test)     
{

    uint8_t encoded_frame[] = {85,17,0,59,103,55,97,251,61,245,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,7,0,0,14,175,208,54,15,0,0,0,51,61,0,0,30,0,1,0,0,0,0,0,0,0,40,0,224,1,0,11,0,0,9,136,179, };

    sbp_msg_tracking_state_detailed_dep_t test_unpacked_msg{};
    
    test_unpacked_msg.L.f = 14;
    
    test_unpacked_msg.L.i = 1810;
    test_unpacked_msg.P = 0;
    test_unpacked_msg.P_std = 0;
    test_unpacked_msg.acceleration = -32;
    test_unpacked_msg.clock_drift = 0;
    test_unpacked_msg.clock_offset = 0;
    test_unpacked_msg.cn0 = 175;
    test_unpacked_msg.corr_spacing = 40;
    test_unpacked_msg.doppler = 15667;
    test_unpacked_msg.doppler_std = 30;
    test_unpacked_msg.lock = 14032;
    test_unpacked_msg.misc_flags = 9;
    test_unpacked_msg.nav_flags = 0;
    test_unpacked_msg.pset_flags = 0;
    test_unpacked_msg.recv_time = 8409447265;
    
    test_unpacked_msg.sid.code = 0;
    
    test_unpacked_msg.sid.reserved = 0;
    
    test_unpacked_msg.sid.sat = 15;
    test_unpacked_msg.sync_flags = 1;
    
    test_unpacked_msg.tot.tow = 0;
    
    test_unpacked_msg.tot.wn = 0;
    test_unpacked_msg.tow_flags = 0;
    test_unpacked_msg.track_flags = 11;
    test_unpacked_msg.uptime = 1;
                                                                              
    EXPECT_EQ(send_message( 26427, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 26427);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.L.f, 14);
    
    EXPECT_EQ(last_msg_.L.i, 1810);
    EXPECT_EQ(last_msg_.P, 0);
    EXPECT_EQ(last_msg_.P_std, 0);
    EXPECT_EQ(last_msg_.acceleration, -32);
    EXPECT_EQ(last_msg_.clock_drift, 0);
    EXPECT_EQ(last_msg_.clock_offset, 0);
    EXPECT_EQ(last_msg_.cn0, 175);
    EXPECT_EQ(last_msg_.corr_spacing, 40);
    EXPECT_EQ(last_msg_.doppler, 15667);
    EXPECT_EQ(last_msg_.doppler_std, 30);
    EXPECT_EQ(last_msg_.lock, 14032);
    EXPECT_EQ(last_msg_.misc_flags, 9);
    EXPECT_EQ(last_msg_.nav_flags, 0);
    EXPECT_EQ(last_msg_.pset_flags, 0);
    EXPECT_EQ(last_msg_.recv_time, 8409447265);
    
    EXPECT_EQ(last_msg_.sid.code, 0);
    
    EXPECT_EQ(last_msg_.sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.sid.sat, 15);
    EXPECT_EQ(last_msg_.sync_flags, 1);
    
    EXPECT_EQ(last_msg_.tot.tow, 0);
    
    EXPECT_EQ(last_msg_.tot.wn, 0);
    EXPECT_EQ(last_msg_.tow_flags, 0);
    EXPECT_EQ(last_msg_.track_flags, 11);
    EXPECT_EQ(last_msg_.uptime, 1);
}                                                     
class Test_auto_check_sbp_tracking_752 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>
{
public:
  Test_auto_check_sbp_tracking_752() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_detailed_dep_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_detailed_dep_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_752, Test)     
{

    uint8_t encoded_frame[] = {85,17,0,59,103,55,139,218,236,18,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,250,8,0,0,8,179,208,54,15,0,0,0,67,61,0,0,22,0,2,0,0,0,0,0,0,0,40,0,27,1,0,11,0,2,9,217,159, };

    sbp_msg_tracking_state_detailed_dep_t test_unpacked_msg{};
    
    test_unpacked_msg.L.f = 8;
    
    test_unpacked_msg.L.i = 2298;
    test_unpacked_msg.P = 0;
    test_unpacked_msg.P_std = 0;
    test_unpacked_msg.acceleration = 27;
    test_unpacked_msg.clock_drift = 0;
    test_unpacked_msg.clock_offset = 0;
    test_unpacked_msg.cn0 = 179;
    test_unpacked_msg.corr_spacing = 40;
    test_unpacked_msg.doppler = 15683;
    test_unpacked_msg.doppler_std = 22;
    test_unpacked_msg.lock = 14032;
    test_unpacked_msg.misc_flags = 9;
    test_unpacked_msg.nav_flags = 0;
    test_unpacked_msg.pset_flags = 2;
    test_unpacked_msg.recv_time = 8907446923;
    
    test_unpacked_msg.sid.code = 0;
    
    test_unpacked_msg.sid.reserved = 0;
    
    test_unpacked_msg.sid.sat = 15;
    test_unpacked_msg.sync_flags = 1;
    
    test_unpacked_msg.tot.tow = 0;
    
    test_unpacked_msg.tot.wn = 0;
    test_unpacked_msg.tow_flags = 0;
    test_unpacked_msg.track_flags = 11;
    test_unpacked_msg.uptime = 2;
                                                                              
    EXPECT_EQ(send_message( 26427, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 26427);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.L.f, 8);
    
    EXPECT_EQ(last_msg_.L.i, 2298);
    EXPECT_EQ(last_msg_.P, 0);
    EXPECT_EQ(last_msg_.P_std, 0);
    EXPECT_EQ(last_msg_.acceleration, 27);
    EXPECT_EQ(last_msg_.clock_drift, 0);
    EXPECT_EQ(last_msg_.clock_offset, 0);
    EXPECT_EQ(last_msg_.cn0, 179);
    EXPECT_EQ(last_msg_.corr_spacing, 40);
    EXPECT_EQ(last_msg_.doppler, 15683);
    EXPECT_EQ(last_msg_.doppler_std, 22);
    EXPECT_EQ(last_msg_.lock, 14032);
    EXPECT_EQ(last_msg_.misc_flags, 9);
    EXPECT_EQ(last_msg_.nav_flags, 0);
    EXPECT_EQ(last_msg_.pset_flags, 2);
    EXPECT_EQ(last_msg_.recv_time, 8907446923);
    
    EXPECT_EQ(last_msg_.sid.code, 0);
    
    EXPECT_EQ(last_msg_.sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.sid.sat, 15);
    EXPECT_EQ(last_msg_.sync_flags, 1);
    
    EXPECT_EQ(last_msg_.tot.tow, 0);
    
    EXPECT_EQ(last_msg_.tot.wn, 0);
    EXPECT_EQ(last_msg_.tow_flags, 0);
    EXPECT_EQ(last_msg_.track_flags, 11);
    EXPECT_EQ(last_msg_.uptime, 2);
}                                                     
class Test_auto_check_sbp_tracking_753 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>
{
public:
  Test_auto_check_sbp_tracking_753() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_detailed_dep_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_detailed_dep_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_753, Test)     
{

    uint8_t encoded_frame[] = {85,17,0,59,103,55,255,251,170,48,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,226,10,0,0,125,181,208,54,15,0,0,0,29,61,0,0,10,0,2,0,0,0,0,0,0,0,40,0,220,1,0,11,0,3,9,66,95, };

    sbp_msg_tracking_state_detailed_dep_t test_unpacked_msg{};
    
    test_unpacked_msg.L.f = 125;
    
    test_unpacked_msg.L.i = 2786;
    test_unpacked_msg.P = 0;
    test_unpacked_msg.P_std = 0;
    test_unpacked_msg.acceleration = -36;
    test_unpacked_msg.clock_drift = 0;
    test_unpacked_msg.clock_offset = 0;
    test_unpacked_msg.cn0 = 181;
    test_unpacked_msg.corr_spacing = 40;
    test_unpacked_msg.doppler = 15645;
    test_unpacked_msg.doppler_std = 10;
    test_unpacked_msg.lock = 14032;
    test_unpacked_msg.misc_flags = 9;
    test_unpacked_msg.nav_flags = 0;
    test_unpacked_msg.pset_flags = 3;
    test_unpacked_msg.recv_time = 9406446591;
    
    test_unpacked_msg.sid.code = 0;
    
    test_unpacked_msg.sid.reserved = 0;
    
    test_unpacked_msg.sid.sat = 15;
    test_unpacked_msg.sync_flags = 1;
    
    test_unpacked_msg.tot.tow = 0;
    
    test_unpacked_msg.tot.wn = 0;
    test_unpacked_msg.tow_flags = 0;
    test_unpacked_msg.track_flags = 11;
    test_unpacked_msg.uptime = 2;
                                                                              
    EXPECT_EQ(send_message( 26427, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 26427);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.L.f, 125);
    
    EXPECT_EQ(last_msg_.L.i, 2786);
    EXPECT_EQ(last_msg_.P, 0);
    EXPECT_EQ(last_msg_.P_std, 0);
    EXPECT_EQ(last_msg_.acceleration, -36);
    EXPECT_EQ(last_msg_.clock_drift, 0);
    EXPECT_EQ(last_msg_.clock_offset, 0);
    EXPECT_EQ(last_msg_.cn0, 181);
    EXPECT_EQ(last_msg_.corr_spacing, 40);
    EXPECT_EQ(last_msg_.doppler, 15645);
    EXPECT_EQ(last_msg_.doppler_std, 10);
    EXPECT_EQ(last_msg_.lock, 14032);
    EXPECT_EQ(last_msg_.misc_flags, 9);
    EXPECT_EQ(last_msg_.nav_flags, 0);
    EXPECT_EQ(last_msg_.pset_flags, 3);
    EXPECT_EQ(last_msg_.recv_time, 9406446591);
    
    EXPECT_EQ(last_msg_.sid.code, 0);
    
    EXPECT_EQ(last_msg_.sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.sid.sat, 15);
    EXPECT_EQ(last_msg_.sync_flags, 1);
    
    EXPECT_EQ(last_msg_.tot.tow, 0);
    
    EXPECT_EQ(last_msg_.tot.wn, 0);
    EXPECT_EQ(last_msg_.tow_flags, 0);
    EXPECT_EQ(last_msg_.track_flags, 11);
    EXPECT_EQ(last_msg_.uptime, 2);
}                                                     
class Test_auto_check_sbp_tracking_754 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>
{
public:
  Test_auto_check_sbp_tracking_754() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_tracking_state_detailed_dep_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_tracking_state_detailed_dep_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_tracking_state_detailed_dep_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_tracking_754, Test)     
{

    uint8_t encoded_frame[] = {85,17,0,59,103,55,189,95,120,78,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,203,12,0,0,64,184,208,54,15,0,0,0,24,61,0,0,4,0,3,0,0,0,0,0,0,0,40,0,2,1,0,11,0,3,9,194,206, };

    sbp_msg_tracking_state_detailed_dep_t test_unpacked_msg{};
    
    test_unpacked_msg.L.f = 64;
    
    test_unpacked_msg.L.i = 3275;
    test_unpacked_msg.P = 0;
    test_unpacked_msg.P_std = 0;
    test_unpacked_msg.acceleration = 2;
    test_unpacked_msg.clock_drift = 0;
    test_unpacked_msg.clock_offset = 0;
    test_unpacked_msg.cn0 = 184;
    test_unpacked_msg.corr_spacing = 40;
    test_unpacked_msg.doppler = 15640;
    test_unpacked_msg.doppler_std = 4;
    test_unpacked_msg.lock = 14032;
    test_unpacked_msg.misc_flags = 9;
    test_unpacked_msg.nav_flags = 0;
    test_unpacked_msg.pset_flags = 3;
    test_unpacked_msg.recv_time = 9906446269;
    
    test_unpacked_msg.sid.code = 0;
    
    test_unpacked_msg.sid.reserved = 0;
    
    test_unpacked_msg.sid.sat = 15;
    test_unpacked_msg.sync_flags = 1;
    
    test_unpacked_msg.tot.tow = 0;
    
    test_unpacked_msg.tot.wn = 0;
    test_unpacked_msg.tow_flags = 0;
    test_unpacked_msg.track_flags = 11;
    test_unpacked_msg.uptime = 3;
                                                                              
    EXPECT_EQ(send_message( 26427, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 26427);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    EXPECT_EQ(last_msg_.L.f, 64);
    
    EXPECT_EQ(last_msg_.L.i, 3275);
    EXPECT_EQ(last_msg_.P, 0);
    EXPECT_EQ(last_msg_.P_std, 0);
    EXPECT_EQ(last_msg_.acceleration, 2);
    EXPECT_EQ(last_msg_.clock_drift, 0);
    EXPECT_EQ(last_msg_.clock_offset, 0);
    EXPECT_EQ(last_msg_.cn0, 184);
    EXPECT_EQ(last_msg_.corr_spacing, 40);
    EXPECT_EQ(last_msg_.doppler, 15640);
    EXPECT_EQ(last_msg_.doppler_std, 4);
    EXPECT_EQ(last_msg_.lock, 14032);
    EXPECT_EQ(last_msg_.misc_flags, 9);
    EXPECT_EQ(last_msg_.nav_flags, 0);
    EXPECT_EQ(last_msg_.pset_flags, 3);
    EXPECT_EQ(last_msg_.recv_time, 9906446269);
    
    EXPECT_EQ(last_msg_.sid.code, 0);
    
    EXPECT_EQ(last_msg_.sid.reserved, 0);
    
    EXPECT_EQ(last_msg_.sid.sat, 15);
    EXPECT_EQ(last_msg_.sync_flags, 1);
    
    EXPECT_EQ(last_msg_.tot.tow, 0);
    
    EXPECT_EQ(last_msg_.tot.wn, 0);
    EXPECT_EQ(last_msg_.tow_flags, 0);
    EXPECT_EQ(last_msg_.track_flags, 11);
    EXPECT_EQ(last_msg_.uptime, 3);
}