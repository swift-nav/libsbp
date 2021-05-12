#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_140 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_t>
{
public:
  Test_auto_check_sbp_navigation_140() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_140, Test)     
{

    uint8_t encoded_frame[] = {85,12,2,211,136,22,40,244,122,19,201,115,12,0,179,88,230,255,153,125,0,0,0,0,0,0,14,0,226,70, };

    sbp_msg_baseline_ned_t test_unpacked_msg{};
    test_unpacked_msg.d = 32153;
    test_unpacked_msg.e = -1681229;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = 816073;
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
    EXPECT_EQ(last_msg_.d, 32153);
    EXPECT_EQ(last_msg_.e, -1681229);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, 816073);
    EXPECT_EQ(last_msg_.n_sats, 14);
    EXPECT_EQ(last_msg_.tow, 326825000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_141 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_t>
{
public:
  Test_auto_check_sbp_navigation_141() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_141, Test)     
{

    uint8_t encoded_frame[] = {85,12,2,211,136,22,16,248,122,19,98,115,12,0,194,88,230,255,110,127,0,0,0,0,0,0,15,0,69,93, };

    sbp_msg_baseline_ned_t test_unpacked_msg{};
    test_unpacked_msg.d = 32622;
    test_unpacked_msg.e = -1681214;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = 815970;
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
    EXPECT_EQ(last_msg_.d, 32622);
    EXPECT_EQ(last_msg_.e, -1681214);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, 815970);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326826000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_142 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_t>
{
public:
  Test_auto_check_sbp_navigation_142() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_142, Test)     
{

    uint8_t encoded_frame[] = {85,12,2,211,136,22,248,251,122,19,143,114,12,0,173,88,230,255,238,127,0,0,0,0,0,0,15,0,210,169, };

    sbp_msg_baseline_ned_t test_unpacked_msg{};
    test_unpacked_msg.d = 32750;
    test_unpacked_msg.e = -1681235;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = 815759;
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
    EXPECT_EQ(last_msg_.d, 32750);
    EXPECT_EQ(last_msg_.e, -1681235);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, 815759);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326827000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_143 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_t>
{
public:
  Test_auto_check_sbp_navigation_143() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_143, Test)     
{

    uint8_t encoded_frame[] = {85,12,2,211,136,22,224,255,122,19,86,112,12,0,51,88,230,255,47,127,0,0,0,0,0,0,15,0,135,107, };

    sbp_msg_baseline_ned_t test_unpacked_msg{};
    test_unpacked_msg.d = 32559;
    test_unpacked_msg.e = -1681357;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = 815190;
    test_unpacked_msg.n_sats = 15;
    test_unpacked_msg.tow = 326828000;
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
    EXPECT_EQ(last_msg_.d, 32559);
    EXPECT_EQ(last_msg_.e, -1681357);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, 815190);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326828000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_144 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_t>
{
public:
  Test_auto_check_sbp_navigation_144() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_144, Test)     
{

    uint8_t encoded_frame[] = {85,12,2,211,136,22,200,3,123,19,214,110,12,0,220,87,230,255,165,126,0,0,0,0,0,0,15,0,190,80, };

    sbp_msg_baseline_ned_t test_unpacked_msg{};
    test_unpacked_msg.d = 32421;
    test_unpacked_msg.e = -1681444;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = 814806;
    test_unpacked_msg.n_sats = 15;
    test_unpacked_msg.tow = 326829000;
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
    EXPECT_EQ(last_msg_.d, 32421);
    EXPECT_EQ(last_msg_.e, -1681444);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, 814806);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326829000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}