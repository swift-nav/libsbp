#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_400 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_t>
{
public:
  Test_auto_check_sbp_navigation_400() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_400, Test)     
{

    uint8_t encoded_frame[] = {85,14,2,211,136,22,40,244,122,19,3,0,0,0,252,255,255,255,243,255,255,255,0,0,0,0,14,0,86,209, };

    sbp_msg_vel_ned_t test_unpacked_msg{};
    test_unpacked_msg.d = -13;
    test_unpacked_msg.e = -4;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = 3;
    test_unpacked_msg.n_sats = 14;
    test_unpacked_msg.tow = 326825000;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 35027, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 35027);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, -13);
    EXPECT_EQ(last_msg_.e, -4);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, 3);
    EXPECT_EQ(last_msg_.n_sats, 14);
    EXPECT_EQ(last_msg_.tow, 326825000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_401 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_t>
{
public:
  Test_auto_check_sbp_navigation_401() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_401, Test)     
{

    uint8_t encoded_frame[] = {85,14,2,211,136,22,28,246,122,19,252,255,255,255,255,255,255,255,232,255,255,255,0,0,0,0,15,0,16,228, };

    sbp_msg_vel_ned_t test_unpacked_msg{};
    test_unpacked_msg.d = -24;
    test_unpacked_msg.e = -1;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -4;
    test_unpacked_msg.n_sats = 15;
    test_unpacked_msg.tow = 326825500;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 35027, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 35027);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, -24);
    EXPECT_EQ(last_msg_.e, -1);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -4);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326825500);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_402 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_t>
{
public:
  Test_auto_check_sbp_navigation_402() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_402, Test)     
{

    uint8_t encoded_frame[] = {85,14,2,211,136,22,16,248,122,19,0,0,0,0,253,255,255,255,244,255,255,255,0,0,0,0,15,0,11,164, };

    sbp_msg_vel_ned_t test_unpacked_msg{};
    test_unpacked_msg.d = -12;
    test_unpacked_msg.e = -3;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = 0;
    test_unpacked_msg.n_sats = 15;
    test_unpacked_msg.tow = 326826000;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 35027, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 35027);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, -12);
    EXPECT_EQ(last_msg_.e, -3);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, 0);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326826000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_403 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_t>
{
public:
  Test_auto_check_sbp_navigation_403() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_403, Test)     
{

    uint8_t encoded_frame[] = {85,14,2,211,136,22,4,250,122,19,2,0,0,0,3,0,0,0,232,255,255,255,0,0,0,0,15,0,152,208, };

    sbp_msg_vel_ned_t test_unpacked_msg{};
    test_unpacked_msg.d = -24;
    test_unpacked_msg.e = 3;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = 2;
    test_unpacked_msg.n_sats = 15;
    test_unpacked_msg.tow = 326826500;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 35027, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 35027);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, -24);
    EXPECT_EQ(last_msg_.e, 3);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, 2);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326826500);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_404 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_vel_ned_t>
{
public:
  Test_auto_check_sbp_navigation_404() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_vel_ned_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_vel_ned_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_vel_ned_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_404, Test)     
{

    uint8_t encoded_frame[] = {85,14,2,211,136,22,248,251,122,19,1,0,0,0,0,0,0,0,235,255,255,255,0,0,0,0,15,0,182,120, };

    sbp_msg_vel_ned_t test_unpacked_msg{};
    test_unpacked_msg.d = -21;
    test_unpacked_msg.e = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = 1;
    test_unpacked_msg.n_sats = 15;
    test_unpacked_msg.tow = 326827000;
    test_unpacked_msg.v_accuracy = 0;
                                                                              
    EXPECT_EQ(send_message( 35027, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 35027);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.d, -21);
    EXPECT_EQ(last_msg_.e, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, 1);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326827000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}