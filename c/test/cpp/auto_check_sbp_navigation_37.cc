#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_370 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_370() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_370, Test)     
{

    uint8_t encoded_frame[] = {85,4,2,246,215,20,20,46,39,0,218,11,0,0,134,245,255,255,163,252,255,255,0,0,9,0,80,236, };

    sbp_msg_vel_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2567700;
    test_unpacked_msg.x = 3034;
    test_unpacked_msg.y = -2682;
    test_unpacked_msg.z = -861;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567700);
    EXPECT_EQ(last_msg_.x, 3034);
    EXPECT_EQ(last_msg_.y, -2682);
    EXPECT_EQ(last_msg_.z, -861);
}                                                     
class Test_auto_check_sbp_navigation_371 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_371() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_371, Test)     
{

    uint8_t encoded_frame[] = {85,4,2,246,215,20,120,46,39,0,68,11,0,0,24,246,255,255,220,252,255,255,0,0,9,0,248,138, };

    sbp_msg_vel_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2567800;
    test_unpacked_msg.x = 2884;
    test_unpacked_msg.y = -2536;
    test_unpacked_msg.z = -804;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567800);
    EXPECT_EQ(last_msg_.x, 2884);
    EXPECT_EQ(last_msg_.y, -2536);
    EXPECT_EQ(last_msg_.z, -804);
}                                                     
class Test_auto_check_sbp_navigation_372 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_372() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_372, Test)     
{

    uint8_t encoded_frame[] = {85,4,2,246,215,20,220,46,39,0,21,11,0,0,77,246,255,255,247,252,255,255,0,0,9,0,25,174, };

    sbp_msg_vel_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2567900;
    test_unpacked_msg.x = 2837;
    test_unpacked_msg.y = -2483;
    test_unpacked_msg.z = -777;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567900);
    EXPECT_EQ(last_msg_.x, 2837);
    EXPECT_EQ(last_msg_.y, -2483);
    EXPECT_EQ(last_msg_.z, -777);
}                                                     
class Test_auto_check_sbp_navigation_373 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_373() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_373, Test)     
{

    uint8_t encoded_frame[] = {85,4,2,246,215,20,64,47,39,0,121,11,0,0,2,246,255,255,234,252,255,255,0,0,9,0,195,228, };

    sbp_msg_vel_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2568000;
    test_unpacked_msg.x = 2937;
    test_unpacked_msg.y = -2558;
    test_unpacked_msg.z = -790;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2568000);
    EXPECT_EQ(last_msg_.x, 2937);
    EXPECT_EQ(last_msg_.y, -2558);
    EXPECT_EQ(last_msg_.z, -790);
}                                                     
class Test_auto_check_sbp_navigation_374 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_374() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_374, Test)     
{

    uint8_t encoded_frame[] = {85,4,2,246,215,20,164,47,39,0,31,11,0,0,93,246,255,255,16,253,255,255,0,0,9,0,219,164, };

    sbp_msg_vel_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2568100;
    test_unpacked_msg.x = 2847;
    test_unpacked_msg.y = -2467;
    test_unpacked_msg.z = -752;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2568100);
    EXPECT_EQ(last_msg_.x, 2847);
    EXPECT_EQ(last_msg_.y, -2467);
    EXPECT_EQ(last_msg_.z, -752);
}                                                     
class Test_auto_check_sbp_navigation_375 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_375() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_375, Test)     
{

    uint8_t encoded_frame[] = {85,4,2,195,4,20,212,157,67,24,24,0,0,0,245,255,255,255,219,255,255,255,0,0,8,0,68,255, };

    sbp_msg_vel_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084500;
    test_unpacked_msg.x = 24;
    test_unpacked_msg.y = -11;
    test_unpacked_msg.z = -37;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084500);
    EXPECT_EQ(last_msg_.x, 24);
    EXPECT_EQ(last_msg_.y, -11);
    EXPECT_EQ(last_msg_.z, -37);
}                                                     
class Test_auto_check_sbp_navigation_376 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_376() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_376, Test)     
{

    uint8_t encoded_frame[] = {85,4,2,195,4,20,56,158,67,24,4,0,0,0,234,255,255,255,18,0,0,0,0,0,8,0,214,136, };

    sbp_msg_vel_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084600;
    test_unpacked_msg.x = 4;
    test_unpacked_msg.y = -22;
    test_unpacked_msg.z = 18;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084600);
    EXPECT_EQ(last_msg_.x, 4);
    EXPECT_EQ(last_msg_.y, -22);
    EXPECT_EQ(last_msg_.z, 18);
}                                                     
class Test_auto_check_sbp_navigation_377 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_377() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_377, Test)     
{

    uint8_t encoded_frame[] = {85,4,2,195,4,20,156,158,67,24,230,255,255,255,4,0,0,0,1,0,0,0,0,0,8,0,122,159, };

    sbp_msg_vel_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084700;
    test_unpacked_msg.x = -26;
    test_unpacked_msg.y = 4;
    test_unpacked_msg.z = 1;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084700);
    EXPECT_EQ(last_msg_.x, -26);
    EXPECT_EQ(last_msg_.y, 4);
    EXPECT_EQ(last_msg_.z, 1);
}                                                     
class Test_auto_check_sbp_navigation_378 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_378() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_378, Test)     
{

    uint8_t encoded_frame[] = {85,4,2,195,4,20,0,159,67,24,247,255,255,255,237,255,255,255,28,0,0,0,0,0,8,0,232,146, };

    sbp_msg_vel_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084800;
    test_unpacked_msg.x = -9;
    test_unpacked_msg.y = -19;
    test_unpacked_msg.z = 28;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084800);
    EXPECT_EQ(last_msg_.x, -9);
    EXPECT_EQ(last_msg_.y, -19);
    EXPECT_EQ(last_msg_.z, 28);
}                                                     
class Test_auto_check_sbp_navigation_379 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_379() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_379, Test)     
{

    uint8_t encoded_frame[] = {85,4,2,195,4,20,100,159,67,24,255,255,255,255,2,0,0,0,245,255,255,255,0,0,8,0,171,238, };

    sbp_msg_vel_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084900;
    test_unpacked_msg.x = -1;
    test_unpacked_msg.y = 2;
    test_unpacked_msg.z = -11;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084900);
    EXPECT_EQ(last_msg_.x, -1);
    EXPECT_EQ(last_msg_.y, 2);
    EXPECT_EQ(last_msg_.z, -11);
}                                                     
class Test_auto_check_sbp_navigation_3710 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_3710() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ecef_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ecef_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ecef_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_3710, Test)     
{

    uint8_t encoded_frame[] = {85,4,2,195,4,20,46,162,68,24,207,255,255,255,185,255,255,255,65,0,0,0,0,0,5,0,82,154, };

    sbp_msg_vel_ecef_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 5;
    test_unpacked_msg.tow = 407151150;
    test_unpacked_msg.x = -49;
    test_unpacked_msg.y = -71;
    test_unpacked_msg.z = 65;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 5);
    EXPECT_EQ(last_msg_.tow, 407151150);
    EXPECT_EQ(last_msg_.x, -49);
    EXPECT_EQ(last_msg_.y, -71);
    EXPECT_EQ(last_msg_.z, 65);
}