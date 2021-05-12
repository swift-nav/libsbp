#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_170 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_dops_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_170() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_dops_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_dops_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_dops_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_170, Test)     
{

    uint8_t encoded_frame[] = {85,6,2,246,215,14,8,48,39,0,180,0,190,0,170,0,160,0,150,0,121,170, };

    sbp_msg_dops_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.gdop = 180;
    test_unpacked_msg.hdop = 160;
    test_unpacked_msg.pdop = 190;
    test_unpacked_msg.tdop = 170;
    test_unpacked_msg.tow = 2568200;
    test_unpacked_msg.vdop = 150;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.gdop, 180);
    EXPECT_EQ(last_msg_.hdop, 160);
    EXPECT_EQ(last_msg_.pdop, 190);
    EXPECT_EQ(last_msg_.tdop, 170);
    EXPECT_EQ(last_msg_.tow, 2568200);
    EXPECT_EQ(last_msg_.vdop, 150);
}                                                     
class Test_auto_check_sbp_navigation_171 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_dops_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_171() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_dops_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_dops_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_dops_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_171, Test)     
{

    uint8_t encoded_frame[] = {85,6,2,246,215,14,240,51,39,0,180,0,190,0,170,0,160,0,150,0,78,169, };

    sbp_msg_dops_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.gdop = 180;
    test_unpacked_msg.hdop = 160;
    test_unpacked_msg.pdop = 190;
    test_unpacked_msg.tdop = 170;
    test_unpacked_msg.tow = 2569200;
    test_unpacked_msg.vdop = 150;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.gdop, 180);
    EXPECT_EQ(last_msg_.hdop, 160);
    EXPECT_EQ(last_msg_.pdop, 190);
    EXPECT_EQ(last_msg_.tdop, 170);
    EXPECT_EQ(last_msg_.tow, 2569200);
    EXPECT_EQ(last_msg_.vdop, 150);
}                                                     
class Test_auto_check_sbp_navigation_172 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_dops_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_172() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_dops_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_dops_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_dops_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_172, Test)     
{

    uint8_t encoded_frame[] = {85,6,2,246,215,14,216,55,39,0,180,0,190,0,170,0,160,0,150,0,71,218, };

    sbp_msg_dops_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.gdop = 180;
    test_unpacked_msg.hdop = 160;
    test_unpacked_msg.pdop = 190;
    test_unpacked_msg.tdop = 170;
    test_unpacked_msg.tow = 2570200;
    test_unpacked_msg.vdop = 150;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.gdop, 180);
    EXPECT_EQ(last_msg_.hdop, 160);
    EXPECT_EQ(last_msg_.pdop, 190);
    EXPECT_EQ(last_msg_.tdop, 170);
    EXPECT_EQ(last_msg_.tow, 2570200);
    EXPECT_EQ(last_msg_.vdop, 150);
}                                                     
class Test_auto_check_sbp_navigation_173 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_dops_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_173() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_dops_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_dops_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_dops_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_173, Test)     
{

    uint8_t encoded_frame[] = {85,6,2,195,4,14,212,157,67,24,247,0,215,0,123,0,17,1,44,0,206,21, };

    sbp_msg_dops_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.gdop = 247;
    test_unpacked_msg.hdop = 273;
    test_unpacked_msg.pdop = 215;
    test_unpacked_msg.tdop = 123;
    test_unpacked_msg.tow = 407084500;
    test_unpacked_msg.vdop = 44;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.gdop, 247);
    EXPECT_EQ(last_msg_.hdop, 273);
    EXPECT_EQ(last_msg_.pdop, 215);
    EXPECT_EQ(last_msg_.tdop, 123);
    EXPECT_EQ(last_msg_.tow, 407084500);
    EXPECT_EQ(last_msg_.vdop, 44);
}                                                     
class Test_auto_check_sbp_navigation_174 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_dops_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_174() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_dops_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_dops_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_dops_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_174, Test)     
{

    uint8_t encoded_frame[] = {85,6,2,195,4,14,0,0,0,0,255,255,255,255,0,0,0,0,0,0,146,12, };

    sbp_msg_dops_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.gdop = 65535;
    test_unpacked_msg.hdop = 0;
    test_unpacked_msg.pdop = 65535;
    test_unpacked_msg.tdop = 0;
    test_unpacked_msg.tow = 0;
    test_unpacked_msg.vdop = 0;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.gdop, 65535);
    EXPECT_EQ(last_msg_.hdop, 0);
    EXPECT_EQ(last_msg_.pdop, 65535);
    EXPECT_EQ(last_msg_.tdop, 0);
    EXPECT_EQ(last_msg_.tow, 0);
    EXPECT_EQ(last_msg_.vdop, 0);
}                                                     
class Test_auto_check_sbp_navigation_175 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_dops_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_175() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_dops_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_dops_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_dops_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_175, Test)     
{

    uint8_t encoded_frame[] = {85,6,2,195,4,14,128,165,68,24,92,1,56,1,155,0,125,2,113,0,129,93, };

    sbp_msg_dops_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.gdop = 348;
    test_unpacked_msg.hdop = 637;
    test_unpacked_msg.pdop = 312;
    test_unpacked_msg.tdop = 155;
    test_unpacked_msg.tow = 407152000;
    test_unpacked_msg.vdop = 113;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.gdop, 348);
    EXPECT_EQ(last_msg_.hdop, 637);
    EXPECT_EQ(last_msg_.pdop, 312);
    EXPECT_EQ(last_msg_.tdop, 155);
    EXPECT_EQ(last_msg_.tow, 407152000);
    EXPECT_EQ(last_msg_.vdop, 113);
}                                                     
class Test_auto_check_sbp_navigation_176 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_dops_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_176() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_dops_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_dops_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_dops_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_176, Test)     
{

    uint8_t encoded_frame[] = {85,6,2,195,4,14,104,169,68,24,92,1,55,1,155,0,125,2,113,0,209,128, };

    sbp_msg_dops_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.gdop = 348;
    test_unpacked_msg.hdop = 637;
    test_unpacked_msg.pdop = 311;
    test_unpacked_msg.tdop = 155;
    test_unpacked_msg.tow = 407153000;
    test_unpacked_msg.vdop = 113;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.gdop, 348);
    EXPECT_EQ(last_msg_.hdop, 637);
    EXPECT_EQ(last_msg_.pdop, 311);
    EXPECT_EQ(last_msg_.tdop, 155);
    EXPECT_EQ(last_msg_.tow, 407153000);
    EXPECT_EQ(last_msg_.vdop, 113);
}                                                     
class Test_auto_check_sbp_navigation_177 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_dops_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_177() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_dops_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_dops_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_dops_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_177, Test)     
{

    uint8_t encoded_frame[] = {85,6,2,195,4,14,80,173,68,24,92,1,55,1,155,0,125,2,112,0,30,6, };

    sbp_msg_dops_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.gdop = 348;
    test_unpacked_msg.hdop = 637;
    test_unpacked_msg.pdop = 311;
    test_unpacked_msg.tdop = 155;
    test_unpacked_msg.tow = 407154000;
    test_unpacked_msg.vdop = 112;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.gdop, 348);
    EXPECT_EQ(last_msg_.hdop, 637);
    EXPECT_EQ(last_msg_.pdop, 311);
    EXPECT_EQ(last_msg_.tdop, 155);
    EXPECT_EQ(last_msg_.tow, 407154000);
    EXPECT_EQ(last_msg_.vdop, 112);
}                                                     
class Test_auto_check_sbp_navigation_178 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_dops_dep_a_t>
{
public:
  Test_auto_check_sbp_navigation_178() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_dops_dep_a_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_dops_dep_a_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_dops_dep_a_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_178, Test)     
{

    uint8_t encoded_frame[] = {85,6,2,195,4,14,56,177,68,24,92,1,55,1,155,0,125,2,112,0,70,67, };

    sbp_msg_dops_dep_a_t test_unpacked_msg{};
    test_unpacked_msg.gdop = 348;
    test_unpacked_msg.hdop = 637;
    test_unpacked_msg.pdop = 311;
    test_unpacked_msg.tdop = 155;
    test_unpacked_msg.tow = 407155000;
    test_unpacked_msg.vdop = 112;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.gdop, 348);
    EXPECT_EQ(last_msg_.hdop, 637);
    EXPECT_EQ(last_msg_.pdop, 311);
    EXPECT_EQ(last_msg_.tdop, 155);
    EXPECT_EQ(last_msg_.tow, 407155000);
    EXPECT_EQ(last_msg_.vdop, 112);
}