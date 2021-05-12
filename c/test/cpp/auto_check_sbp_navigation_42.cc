#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_420 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_420() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_420, Test)     
{

    uint8_t encoded_frame[] = {85,5,2,246,215,22,20,46,39,0,198,251,255,255,156,15,0,0,0,0,0,0,0,0,0,0,9,0,161,92, };

    sbp_msg_vel_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = 0;
    test_unpacked_msg.e = 3996;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -1082;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2567700;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, 0);
    EXPECT_EQ(last_msg_.e, 3996);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -1082);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567700);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_421 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_421() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_421, Test)     
{

    uint8_t encoded_frame[] = {85,5,2,246,215,22,120,46,39,0,14,252,255,255,207,14,0,0,0,0,0,0,0,0,0,0,9,0,125,160, };

    sbp_msg_vel_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = 0;
    test_unpacked_msg.e = 3791;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -1010;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2567800;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, 0);
    EXPECT_EQ(last_msg_.e, 3791);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -1010);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567800);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_422 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_422() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_422, Test)     
{

    uint8_t encoded_frame[] = {85,5,2,246,215,22,220,46,39,0,48,252,255,255,140,14,0,0,0,0,0,0,0,0,0,0,9,0,179,135, };

    sbp_msg_vel_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = 0;
    test_unpacked_msg.e = 3724;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -976;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2567900;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, 0);
    EXPECT_EQ(last_msg_.e, 3724);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -976);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567900);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_423 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_423() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_423, Test)     
{

    uint8_t encoded_frame[] = {85,5,2,246,215,22,64,47,39,0,32,252,255,255,8,15,0,0,0,0,0,0,0,0,0,0,9,0,51,177, };

    sbp_msg_vel_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = 0;
    test_unpacked_msg.e = 3848;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -992;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2568000;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, 0);
    EXPECT_EQ(last_msg_.e, 3848);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -992);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2568000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_424 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_424() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_424, Test)     
{

    uint8_t encoded_frame[] = {85,5,2,246,215,22,164,47,39,0,80,252,255,255,140,14,0,0,0,0,0,0,0,0,0,0,9,0,23,0, };

    sbp_msg_vel_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = 0;
    test_unpacked_msg.e = 3724;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -944;
    test_unpacked_msg.n_sats = 9;
    test_unpacked_msg.tow = 2568100;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, 0);
    EXPECT_EQ(last_msg_.e, 3724);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -944);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2568100);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_425 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_425() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_425, Test)     
{

    uint8_t encoded_frame[] = {85,5,2,195,4,22,212,157,67,24,229,255,255,255,26,0,0,0,25,0,0,0,0,0,0,0,8,0,132,25, };

    sbp_msg_vel_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = 25;
    test_unpacked_msg.e = 26;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -27;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084500;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, 25);
    EXPECT_EQ(last_msg_.e, 26);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -27);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084500);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_426 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_426() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_426, Test)     
{

    uint8_t encoded_frame[] = {85,5,2,195,4,22,56,158,67,24,4,0,0,0,15,0,0,0,232,255,255,255,0,0,0,0,8,0,42,14, };

    sbp_msg_vel_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = -24;
    test_unpacked_msg.e = 15;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = 4;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084600;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, -24);
    EXPECT_EQ(last_msg_.e, 15);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, 4);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084600);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_427 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_427() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_427, Test)     
{

    uint8_t encoded_frame[] = {85,5,2,195,4,22,156,158,67,24,251,255,255,255,232,255,255,255,247,255,255,255,0,0,0,0,8,0,218,148, };

    sbp_msg_vel_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = -9;
    test_unpacked_msg.e = -24;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -5;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084700;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, -9);
    EXPECT_EQ(last_msg_.e, -24);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -5);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084700);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_428 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_428() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_428, Test)     
{

    uint8_t encoded_frame[] = {85,5,2,195,4,22,0,159,67,24,10,0,0,0,2,0,0,0,222,255,255,255,0,0,0,0,8,0,148,16, };

    sbp_msg_vel_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = -34;
    test_unpacked_msg.e = 2;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = 10;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084800;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, -34);
    EXPECT_EQ(last_msg_.e, 2);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, 10);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084800);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_429 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_429() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_429, Test)     
{

    uint8_t encoded_frame[] = {85,5,2,195,4,22,100,159,67,24,248,255,255,255,254,255,255,255,7,0,0,0,0,0,0,0,8,0,255,236, };

    sbp_msg_vel_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = 7;
    test_unpacked_msg.e = -2;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -8;
    test_unpacked_msg.n_sats = 8;
    test_unpacked_msg.tow = 407084900;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, 7);
    EXPECT_EQ(last_msg_.e, -2);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -8);
    EXPECT_EQ(last_msg_.n_sats, 8);
    EXPECT_EQ(last_msg_.tow, 407084900);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_4210 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_4210() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_4210, Test)     
{

    uint8_t encoded_frame[] = {85,5,2,195,4,22,46,162,68,24,255,255,255,255,253,255,255,255,148,255,255,255,0,0,0,0,5,0,166,189, };

    sbp_msg_vel_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = -108;
    test_unpacked_msg.e = -3;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -1;
    test_unpacked_msg.n_sats = 5;
    test_unpacked_msg.tow = 407151150;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, -108);
    EXPECT_EQ(last_msg_.e, -3);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -1);
    EXPECT_EQ(last_msg_.n_sats, 5);
    EXPECT_EQ(last_msg_.tow, 407151150);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}