#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_190 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_190() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_gps_time_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_gps_time_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_190, Test)     
{

    uint8_t encoded_frame[] = {85,0,1,246,215,11,251,6,120,46,39,0,0,0,0,0,0,133,36, };

    sbp_msg_gps_time_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.ns_residual = 0;
    test_unpacked_msg.tow = 2567800;
    test_unpacked_msg.wn = 1787;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.ns_residual, 0);
    EXPECT_EQ(last_msg_.tow, 2567800);
    EXPECT_EQ(last_msg_.wn, 1787);
}                                                     
class Test_auto_check_sbp_navigation_191 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_191() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_gps_time_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_gps_time_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_191, Test)     
{

    uint8_t encoded_frame[] = {85,0,1,246,215,11,251,6,220,46,39,0,0,0,0,0,0,36,160, };

    sbp_msg_gps_time_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.ns_residual = 0;
    test_unpacked_msg.tow = 2567900;
    test_unpacked_msg.wn = 1787;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.ns_residual, 0);
    EXPECT_EQ(last_msg_.tow, 2567900);
    EXPECT_EQ(last_msg_.wn, 1787);
}                                                     
class Test_auto_check_sbp_navigation_192 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_192() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_gps_time_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_gps_time_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_192, Test)     
{

    uint8_t encoded_frame[] = {85,0,1,246,215,11,251,6,64,47,39,0,0,0,0,0,0,171,190, };

    sbp_msg_gps_time_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.ns_residual = 0;
    test_unpacked_msg.tow = 2568000;
    test_unpacked_msg.wn = 1787;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.ns_residual, 0);
    EXPECT_EQ(last_msg_.tow, 2568000);
    EXPECT_EQ(last_msg_.wn, 1787);
}                                                     
class Test_auto_check_sbp_navigation_193 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_193() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_gps_time_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_gps_time_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_193, Test)     
{

    uint8_t encoded_frame[] = {85,0,1,246,215,11,251,6,164,47,39,0,0,0,0,0,0,211,101, };

    sbp_msg_gps_time_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.ns_residual = 0;
    test_unpacked_msg.tow = 2568100;
    test_unpacked_msg.wn = 1787;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.ns_residual, 0);
    EXPECT_EQ(last_msg_.tow, 2568100);
    EXPECT_EQ(last_msg_.wn, 1787);
}                                                     
class Test_auto_check_sbp_navigation_194 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_194() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_gps_time_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_gps_time_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_194, Test)     
{

    uint8_t encoded_frame[] = {85,0,1,246,215,11,251,6,8,48,39,0,0,0,0,0,0,251,44, };

    sbp_msg_gps_time_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.ns_residual = 0;
    test_unpacked_msg.tow = 2568200;
    test_unpacked_msg.wn = 1787;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.ns_residual, 0);
    EXPECT_EQ(last_msg_.tow, 2568200);
    EXPECT_EQ(last_msg_.wn, 1787);
}                                                     
class Test_auto_check_sbp_navigation_195 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_195() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_gps_time_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_gps_time_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_195, Test)     
{

    uint8_t encoded_frame[] = {85,0,1,195,4,11,46,7,212,157,67,24,111,147,252,255,0,215,190, };

    sbp_msg_gps_time_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.ns_residual = -224401;
    test_unpacked_msg.tow = 407084500;
    test_unpacked_msg.wn = 1838;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.ns_residual, -224401);
    EXPECT_EQ(last_msg_.tow, 407084500);
    EXPECT_EQ(last_msg_.wn, 1838);
}                                                     
class Test_auto_check_sbp_navigation_196 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_196() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_gps_time_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_gps_time_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_196, Test)     
{

    uint8_t encoded_frame[] = {85,0,1,195,4,11,46,7,56,158,67,24,109,103,3,0,0,134,89, };

    sbp_msg_gps_time_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.ns_residual = 223085;
    test_unpacked_msg.tow = 407084600;
    test_unpacked_msg.wn = 1838;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.ns_residual, 223085);
    EXPECT_EQ(last_msg_.tow, 407084600);
    EXPECT_EQ(last_msg_.wn, 1838);
}                                                     
class Test_auto_check_sbp_navigation_197 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_197() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_gps_time_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_gps_time_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_197, Test)     
{

    uint8_t encoded_frame[] = {85,0,1,195,4,11,46,7,156,158,67,24,233,152,252,255,0,206,241, };

    sbp_msg_gps_time_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.ns_residual = -222999;
    test_unpacked_msg.tow = 407084700;
    test_unpacked_msg.wn = 1838;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.ns_residual, -222999);
    EXPECT_EQ(last_msg_.tow, 407084700);
    EXPECT_EQ(last_msg_.wn, 1838);
}                                                     
class Test_auto_check_sbp_navigation_198 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_198() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_gps_time_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_gps_time_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_198, Test)     
{

    uint8_t encoded_frame[] = {85,0,1,195,4,11,46,7,0,159,67,24,240,154,3,0,0,147,98, };

    sbp_msg_gps_time_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.ns_residual = 236272;
    test_unpacked_msg.tow = 407084800;
    test_unpacked_msg.wn = 1838;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.ns_residual, 236272);
    EXPECT_EQ(last_msg_.tow, 407084800);
    EXPECT_EQ(last_msg_.wn, 1838);
}                                                     
class Test_auto_check_sbp_navigation_199 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_199() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_gps_time_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_gps_time_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_199, Test)     
{

    uint8_t encoded_frame[] = {85,0,1,195,4,11,46,7,100,159,67,24,144,101,252,255,0,186,152, };

    sbp_msg_gps_time_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.ns_residual = -236144;
    test_unpacked_msg.tow = 407084900;
    test_unpacked_msg.wn = 1838;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.ns_residual, -236144);
    EXPECT_EQ(last_msg_.tow, 407084900);
    EXPECT_EQ(last_msg_.wn, 1838);
}                                                     
class Test_auto_check_sbp_navigation_1910 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_1910() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_gps_time_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_gps_time_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_gps_time_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_1910, Test)     
{

    uint8_t encoded_frame[] = {85,0,1,195,4,11,46,7,46,162,68,24,205,230,250,255,0,11,225, };

    sbp_msg_gps_time_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.ns_residual = -334131;
    test_unpacked_msg.tow = 407151150;
    test_unpacked_msg.wn = 1838;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.ns_residual, -334131);
    EXPECT_EQ(last_msg_.tow, 407151150);
    EXPECT_EQ(last_msg_.wn, 1838);
}