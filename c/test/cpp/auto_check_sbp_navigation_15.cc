#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_150 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_150() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_150, Test)     
{

    uint8_t encoded_frame[] = {85,3,2,246,215,22,20,46,39,0,243,134,254,255,234,153,255,255,0,0,0,0,0,0,0,0,9,1,93,193, };

    sbp_msg_baseline_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = 0;
    test_unpacked_msg.e = -26134;
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -96525;
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
    EXPECT_EQ(last_msg_.e, -26134);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -96525);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567700);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_151 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_151() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_151, Test)     
{

    uint8_t encoded_frame[] = {85,3,2,246,215,22,120,46,39,0,139,134,254,255,109,155,255,255,0,0,0,0,0,0,0,0,9,1,38,39, };

    sbp_msg_baseline_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = 0;
    test_unpacked_msg.e = -25747;
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -96629;
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
    EXPECT_EQ(last_msg_.e, -25747);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -96629);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567800);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_152 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_152() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_152, Test)     
{

    uint8_t encoded_frame[] = {85,3,2,246,215,22,220,46,39,0,37,134,254,255,240,156,255,255,0,0,0,0,0,0,0,0,9,1,58,133, };

    sbp_msg_baseline_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = 0;
    test_unpacked_msg.e = -25360;
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -96731;
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
    EXPECT_EQ(last_msg_.e, -25360);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -96731);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2567900);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_153 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_153() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_153, Test)     
{

    uint8_t encoded_frame[] = {85,3,2,246,215,22,64,47,39,0,193,133,254,255,115,158,255,255,0,0,0,0,0,0,0,0,9,1,56,214, };

    sbp_msg_baseline_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = 0;
    test_unpacked_msg.e = -24973;
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -96831;
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
    EXPECT_EQ(last_msg_.e, -24973);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -96831);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2568000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_154 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_154() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_154, Test)     
{

    uint8_t encoded_frame[] = {85,3,2,246,215,22,164,47,39,0,93,133,254,255,246,159,255,255,0,0,0,0,0,0,0,0,9,1,234,244, };

    sbp_msg_baseline_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = 0;
    test_unpacked_msg.e = -24586;
    test_unpacked_msg.flags = 1;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -96931;
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
    EXPECT_EQ(last_msg_.e, -24586);
    EXPECT_EQ(last_msg_.flags, 1);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -96931);
    EXPECT_EQ(last_msg_.n_sats, 9);
    EXPECT_EQ(last_msg_.tow, 2568100);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_155 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_155() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_155, Test)     
{

    uint8_t encoded_frame[] = {85,3,2,195,4,22,156,21,69,24,130,246,255,255,241,4,0,0,35,196,255,255,0,0,0,0,6,0,250,21, };

    sbp_msg_baseline_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = -15325;
    test_unpacked_msg.e = 1265;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -2430;
    test_unpacked_msg.n_sats = 6;
    test_unpacked_msg.tow = 407180700;
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
    EXPECT_EQ(last_msg_.d, -15325);
    EXPECT_EQ(last_msg_.e, 1265);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -2430);
    EXPECT_EQ(last_msg_.n_sats, 6);
    EXPECT_EQ(last_msg_.tow, 407180700);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_156 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_156() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_156, Test)     
{

    uint8_t encoded_frame[] = {85,3,2,195,4,22,0,22,69,24,130,246,255,255,241,4,0,0,35,196,255,255,0,0,0,0,6,0,240,133, };

    sbp_msg_baseline_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = -15325;
    test_unpacked_msg.e = 1265;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -2430;
    test_unpacked_msg.n_sats = 6;
    test_unpacked_msg.tow = 407180800;
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
    EXPECT_EQ(last_msg_.d, -15325);
    EXPECT_EQ(last_msg_.e, 1265);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -2430);
    EXPECT_EQ(last_msg_.n_sats, 6);
    EXPECT_EQ(last_msg_.tow, 407180800);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_157 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_157() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_157, Test)     
{

    uint8_t encoded_frame[] = {85,3,2,195,4,22,100,22,69,24,32,251,255,255,199,11,0,0,57,161,255,255,0,0,0,0,6,0,12,181, };

    sbp_msg_baseline_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = -24263;
    test_unpacked_msg.e = 3015;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -1248;
    test_unpacked_msg.n_sats = 6;
    test_unpacked_msg.tow = 407180900;
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
    EXPECT_EQ(last_msg_.d, -24263);
    EXPECT_EQ(last_msg_.e, 3015);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -1248);
    EXPECT_EQ(last_msg_.n_sats, 6);
    EXPECT_EQ(last_msg_.tow, 407180900);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_158 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_158() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_158, Test)     
{

    uint8_t encoded_frame[] = {85,3,2,195,4,22,200,22,69,24,33,251,255,255,199,11,0,0,54,161,255,255,0,0,0,0,6,0,86,58, };

    sbp_msg_baseline_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = -24266;
    test_unpacked_msg.e = 3015;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = -1247;
    test_unpacked_msg.n_sats = 6;
    test_unpacked_msg.tow = 407181000;
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
    EXPECT_EQ(last_msg_.d, -24266);
    EXPECT_EQ(last_msg_.e, 3015);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, -1247);
    EXPECT_EQ(last_msg_.n_sats, 6);
    EXPECT_EQ(last_msg_.tow, 407181000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_159 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_159() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_159, Test)     
{

    uint8_t encoded_frame[] = {85,3,2,195,4,22,44,23,69,24,110,6,0,0,55,8,0,0,160,166,255,255,0,0,0,0,6,0,51,249, };

    sbp_msg_baseline_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = -22880;
    test_unpacked_msg.e = 2103;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = 1646;
    test_unpacked_msg.n_sats = 6;
    test_unpacked_msg.tow = 407181100;
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
    EXPECT_EQ(last_msg_.d, -22880);
    EXPECT_EQ(last_msg_.e, 2103);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, 1646);
    EXPECT_EQ(last_msg_.n_sats, 6);
    EXPECT_EQ(last_msg_.tow, 407181100);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_1510 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_1510() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ned_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ned_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ned_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_1510, Test)     
{

    uint8_t encoded_frame[] = {85,3,2,195,4,22,144,23,69,24,110,6,0,0,54,8,0,0,160,166,255,255,0,0,0,0,6,0,206,22, };

    sbp_msg_baseline_ned_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.d = -22880;
    test_unpacked_msg.e = 2102;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.n = 1646;
    test_unpacked_msg.n_sats = 6;
    test_unpacked_msg.tow = 407181200;
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
    EXPECT_EQ(last_msg_.d, -22880);
    EXPECT_EQ(last_msg_.e, 2102);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_EQ(last_msg_.n, 1646);
    EXPECT_EQ(last_msg_.n_sats, 6);
    EXPECT_EQ(last_msg_.tow, 407181200);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}