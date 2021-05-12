#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_piksi_620 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_thread_state_t>
{
public:
  Test_auto_check_sbp_piksi_620() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_thread_state_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_thread_state_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_thread_state_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_620, Test)     
{

    uint8_t encoded_frame[] = {85,23,0,246,215,26,109,97,105,110,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,156,9,0,0,73,138, };

    sbp_msg_thread_state_t test_unpacked_msg{};
    test_unpacked_msg.cpu = 0;
    {
      const char assign_string[] = { (char)109,(char)97,(char)105,(char)110,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      memcpy(test_unpacked_msg.name, assign_string, sizeof(assign_string));
    }
    test_unpacked_msg.stack_free = 2460;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.cpu, 0);
    {
      const char check_string[] = { (char)109,(char)97,(char)105,(char)110,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.name, check_string, sizeof(check_string)), 0);
    }
    EXPECT_EQ(last_msg_.stack_free, 2460);
}                                                     
class Test_auto_check_sbp_piksi_621 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_thread_state_t>
{
public:
  Test_auto_check_sbp_piksi_621() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_thread_state_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_thread_state_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_thread_state_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_621, Test)     
{

    uint8_t encoded_frame[] = {85,23,0,246,215,26,105,100,108,101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,83,2,36,0,0,0,151,20, };

    sbp_msg_thread_state_t test_unpacked_msg{};
    test_unpacked_msg.cpu = 595;
    {
      const char assign_string[] = { (char)105,(char)100,(char)108,(char)101,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      memcpy(test_unpacked_msg.name, assign_string, sizeof(assign_string));
    }
    test_unpacked_msg.stack_free = 36;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.cpu, 595);
    {
      const char check_string[] = { (char)105,(char)100,(char)108,(char)101,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.name, check_string, sizeof(check_string)), 0);
    }
    EXPECT_EQ(last_msg_.stack_free, 36);
}                                                     
class Test_auto_check_sbp_piksi_622 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_thread_state_t>
{
public:
  Test_auto_check_sbp_piksi_622() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_thread_state_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_thread_state_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_thread_state_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_622, Test)     
{

    uint8_t encoded_frame[] = {85,23,0,246,215,26,78,65,80,32,73,83,82,0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,116,4,0,0,226,60, };

    sbp_msg_thread_state_t test_unpacked_msg{};
    test_unpacked_msg.cpu = 14;
    {
      const char assign_string[] = { (char)78,(char)65,(char)80,(char)32,(char)73,(char)83,(char)82,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      memcpy(test_unpacked_msg.name, assign_string, sizeof(assign_string));
    }
    test_unpacked_msg.stack_free = 1140;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.cpu, 14);
    {
      const char check_string[] = { (char)78,(char)65,(char)80,(char)32,(char)73,(char)83,(char)82,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.name, check_string, sizeof(check_string)), 0);
    }
    EXPECT_EQ(last_msg_.stack_free, 1140);
}                                                     
class Test_auto_check_sbp_piksi_623 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_thread_state_t>
{
public:
  Test_auto_check_sbp_piksi_623() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_thread_state_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_thread_state_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_thread_state_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_623, Test)     
{

    uint8_t encoded_frame[] = {85,23,0,246,215,26,83,66,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,196,19,0,0,90,169, };

    sbp_msg_thread_state_t test_unpacked_msg{};
    test_unpacked_msg.cpu = 1;
    {
      const char assign_string[] = { (char)83,(char)66,(char)80,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      memcpy(test_unpacked_msg.name, assign_string, sizeof(assign_string));
    }
    test_unpacked_msg.stack_free = 5060;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.cpu, 1);
    {
      const char check_string[] = { (char)83,(char)66,(char)80,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.name, check_string, sizeof(check_string)), 0);
    }
    EXPECT_EQ(last_msg_.stack_free, 5060);
}                                                     
class Test_auto_check_sbp_piksi_624 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_thread_state_t>
{
public:
  Test_auto_check_sbp_piksi_624() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_thread_state_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_thread_state_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_thread_state_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_624, Test)     
{

    uint8_t encoded_frame[] = {85,23,0,246,215,26,109,97,110,97,103,101,32,97,99,113,0,0,0,0,0,0,0,0,0,0,7,0,20,9,0,0,47,75, };

    sbp_msg_thread_state_t test_unpacked_msg{};
    test_unpacked_msg.cpu = 7;
    {
      const char assign_string[] = { (char)109,(char)97,(char)110,(char)97,(char)103,(char)101,(char)32,(char)97,(char)99,(char)113,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      memcpy(test_unpacked_msg.name, assign_string, sizeof(assign_string));
    }
    test_unpacked_msg.stack_free = 2324;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.cpu, 7);
    {
      const char check_string[] = { (char)109,(char)97,(char)110,(char)97,(char)103,(char)101,(char)32,(char)97,(char)99,(char)113,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.name, check_string, sizeof(check_string)), 0);
    }
    EXPECT_EQ(last_msg_.stack_free, 2324);
}                                                     
class Test_auto_check_sbp_piksi_625 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_thread_state_t>
{
public:
  Test_auto_check_sbp_piksi_625() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_thread_state_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_thread_state_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_thread_state_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_625, Test)     
{

    uint8_t encoded_frame[] = {85,23,0,195,4,26,109,97,105,110,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,148,9,0,0,195,212, };

    sbp_msg_thread_state_t test_unpacked_msg{};
    test_unpacked_msg.cpu = 0;
    {
      const char assign_string[] = { (char)109,(char)97,(char)105,(char)110,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      memcpy(test_unpacked_msg.name, assign_string, sizeof(assign_string));
    }
    test_unpacked_msg.stack_free = 2452;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.cpu, 0);
    {
      const char check_string[] = { (char)109,(char)97,(char)105,(char)110,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.name, check_string, sizeof(check_string)), 0);
    }
    EXPECT_EQ(last_msg_.stack_free, 2452);
}                                                     
class Test_auto_check_sbp_piksi_626 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_thread_state_t>
{
public:
  Test_auto_check_sbp_piksi_626() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_thread_state_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_thread_state_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_thread_state_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_626, Test)     
{

    uint8_t encoded_frame[] = {85,23,0,195,4,26,105,100,108,101,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,228,1,36,0,0,0,225,18, };

    sbp_msg_thread_state_t test_unpacked_msg{};
    test_unpacked_msg.cpu = 484;
    {
      const char assign_string[] = { (char)105,(char)100,(char)108,(char)101,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      memcpy(test_unpacked_msg.name, assign_string, sizeof(assign_string));
    }
    test_unpacked_msg.stack_free = 36;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.cpu, 484);
    {
      const char check_string[] = { (char)105,(char)100,(char)108,(char)101,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.name, check_string, sizeof(check_string)), 0);
    }
    EXPECT_EQ(last_msg_.stack_free, 36);
}                                                     
class Test_auto_check_sbp_piksi_627 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_thread_state_t>
{
public:
  Test_auto_check_sbp_piksi_627() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_thread_state_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_thread_state_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_thread_state_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_627, Test)     
{

    uint8_t encoded_frame[] = {85,23,0,195,4,26,78,65,80,32,73,83,82,0,0,0,0,0,0,0,0,0,0,0,0,0,138,1,92,7,0,0,166,116, };

    sbp_msg_thread_state_t test_unpacked_msg{};
    test_unpacked_msg.cpu = 394;
    {
      const char assign_string[] = { (char)78,(char)65,(char)80,(char)32,(char)73,(char)83,(char)82,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      memcpy(test_unpacked_msg.name, assign_string, sizeof(assign_string));
    }
    test_unpacked_msg.stack_free = 1884;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.cpu, 394);
    {
      const char check_string[] = { (char)78,(char)65,(char)80,(char)32,(char)73,(char)83,(char)82,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.name, check_string, sizeof(check_string)), 0);
    }
    EXPECT_EQ(last_msg_.stack_free, 1884);
}                                                     
class Test_auto_check_sbp_piksi_628 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_thread_state_t>
{
public:
  Test_auto_check_sbp_piksi_628() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_thread_state_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_thread_state_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_thread_state_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_628, Test)     
{

    uint8_t encoded_frame[] = {85,23,0,195,4,26,83,66,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,4,12,0,0,229,174, };

    sbp_msg_thread_state_t test_unpacked_msg{};
    test_unpacked_msg.cpu = 1;
    {
      const char assign_string[] = { (char)83,(char)66,(char)80,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      memcpy(test_unpacked_msg.name, assign_string, sizeof(assign_string));
    }
    test_unpacked_msg.stack_free = 3076;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.cpu, 1);
    {
      const char check_string[] = { (char)83,(char)66,(char)80,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.name, check_string, sizeof(check_string)), 0);
    }
    EXPECT_EQ(last_msg_.stack_free, 3076);
}                                                     
class Test_auto_check_sbp_piksi_629 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_thread_state_t>
{
public:
  Test_auto_check_sbp_piksi_629() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_thread_state_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_thread_state_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_thread_state_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_629, Test)     
{

    uint8_t encoded_frame[] = {85,23,0,195,4,26,109,97,110,97,103,101,32,97,99,113,0,0,0,0,0,0,0,0,0,0,10,0,124,9,0,0,52,2, };

    sbp_msg_thread_state_t test_unpacked_msg{};
    test_unpacked_msg.cpu = 10;
    {
      const char assign_string[] = { (char)109,(char)97,(char)110,(char)97,(char)103,(char)101,(char)32,(char)97,(char)99,(char)113,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      memcpy(test_unpacked_msg.name, assign_string, sizeof(assign_string));
    }
    test_unpacked_msg.stack_free = 2428;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.cpu, 10);
    {
      const char check_string[] = { (char)109,(char)97,(char)110,(char)97,(char)103,(char)101,(char)32,(char)97,(char)99,(char)113,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.name, check_string, sizeof(check_string)), 0);
    }
    EXPECT_EQ(last_msg_.stack_free, 2428);
}                                                     
class Test_auto_check_sbp_piksi_6210 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_thread_state_t>
{
public:
  Test_auto_check_sbp_piksi_6210() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_thread_state_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_thread_state_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_thread_state_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_piksi_6210, Test)     
{

    uint8_t encoded_frame[] = {85,23,0,195,4,26,109,97,110,97,103,101,32,116,114,97,99,107,0,0,0,0,0,0,0,0,0,0,28,9,0,0,122,54, };

    sbp_msg_thread_state_t test_unpacked_msg{};
    test_unpacked_msg.cpu = 0;
    {
      const char assign_string[] = { (char)109,(char)97,(char)110,(char)97,(char)103,(char)101,(char)32,(char)116,(char)114,(char)97,(char)99,(char)107,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      memcpy(test_unpacked_msg.name, assign_string, sizeof(assign_string));
    }
    test_unpacked_msg.stack_free = 2332;
                                                                              
    EXPECT_EQ(send_message( 1219, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 1219);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.cpu, 0);
    {
      const char check_string[] = { (char)109,(char)97,(char)110,(char)97,(char)103,(char)101,(char)32,(char)116,(char)114,(char)97,(char)99,(char)107,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.name, check_string, sizeof(check_string)), 0);
    }
    EXPECT_EQ(last_msg_.stack_free, 2332);
}