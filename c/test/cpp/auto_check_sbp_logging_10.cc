#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_logging_100 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_print_dep_t>
{
public:
  Test_auto_check_sbp_logging_100() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_print_dep_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_print_dep_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_print_dep_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_logging_100, Test)     
{

    uint8_t encoded_frame[] = {85,16,0,34,34,43,73,78,70,79,58,32,97,99,113,58,32,80,82,78,32,49,53,32,102,111,117,110,100,32,64,32,45,50,52,57,55,32,72,122,44,32,50,48,32,83,78,82,10,116,103, };

    sbp_msg_print_dep_t test_unpacked_msg{};
    
    {
      const char assign_string[] = { (char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)49,(char)53,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)45,(char)50,(char)52,(char)57,(char)55,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)48,(char)32,(char)83,(char)78,(char)82,(char)10 };
      memcpy(test_unpacked_msg.text.data, assign_string, sizeof(assign_string));
    }
    
    test_unpacked_msg.text.len = 43;
                                                                              
    EXPECT_EQ(send_message( 8738, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 8738);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    {
      const char check_string[] = { (char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)49,(char)53,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)45,(char)50,(char)52,(char)57,(char)55,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)48,(char)32,(char)83,(char)78,(char)82,(char)10 };
      EXPECT_EQ(memcmp(last_msg_.text.data, check_string, sizeof(check_string)), 0);
    }
    
    EXPECT_EQ(last_msg_.text.len, 43);
}                                                     
class Test_auto_check_sbp_logging_101 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_print_dep_t>
{
public:
  Test_auto_check_sbp_logging_101() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_print_dep_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_print_dep_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_print_dep_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_logging_101, Test)     
{

    uint8_t encoded_frame[] = {85,16,0,34,34,42,73,78,70,79,58,32,97,99,113,58,32,80,82,78,32,51,49,32,102,111,117,110,100,32,64,32,52,50,52,53,32,72,122,44,32,50,49,32,83,78,82,10,140,43, };

    sbp_msg_print_dep_t test_unpacked_msg{};
    
    {
      const char assign_string[] = { (char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)51,(char)49,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)52,(char)50,(char)52,(char)53,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)49,(char)32,(char)83,(char)78,(char)82,(char)10 };
      memcpy(test_unpacked_msg.text.data, assign_string, sizeof(assign_string));
    }
    
    test_unpacked_msg.text.len = 42;
                                                                              
    EXPECT_EQ(send_message( 8738, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 8738);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    {
      const char check_string[] = { (char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)51,(char)49,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)52,(char)50,(char)52,(char)53,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)49,(char)32,(char)83,(char)78,(char)82,(char)10 };
      EXPECT_EQ(memcmp(last_msg_.text.data, check_string, sizeof(check_string)), 0);
    }
    
    EXPECT_EQ(last_msg_.text.len, 42);
}                                                     
class Test_auto_check_sbp_logging_102 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_print_dep_t>
{
public:
  Test_auto_check_sbp_logging_102() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_print_dep_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_print_dep_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_print_dep_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_logging_102, Test)     
{

    uint8_t encoded_frame[] = {85,16,0,34,34,35,73,78,70,79,58,32,68,105,115,97,98,108,105,110,103,32,99,104,97,110,110,101,108,32,48,32,40,80,82,78,32,49,49,41,10,23,143, };

    sbp_msg_print_dep_t test_unpacked_msg{};
    
    {
      const char assign_string[] = { (char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)68,(char)105,(char)115,(char)97,(char)98,(char)108,(char)105,(char)110,(char)103,(char)32,(char)99,(char)104,(char)97,(char)110,(char)110,(char)101,(char)108,(char)32,(char)48,(char)32,(char)40,(char)80,(char)82,(char)78,(char)32,(char)49,(char)49,(char)41,(char)10 };
      memcpy(test_unpacked_msg.text.data, assign_string, sizeof(assign_string));
    }
    
    test_unpacked_msg.text.len = 35;
                                                                              
    EXPECT_EQ(send_message( 8738, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 8738);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    {
      const char check_string[] = { (char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)68,(char)105,(char)115,(char)97,(char)98,(char)108,(char)105,(char)110,(char)103,(char)32,(char)99,(char)104,(char)97,(char)110,(char)110,(char)101,(char)108,(char)32,(char)48,(char)32,(char)40,(char)80,(char)82,(char)78,(char)32,(char)49,(char)49,(char)41,(char)10 };
      EXPECT_EQ(memcmp(last_msg_.text.data, check_string, sizeof(check_string)), 0);
    }
    
    EXPECT_EQ(last_msg_.text.len, 35);
}                                                     
class Test_auto_check_sbp_logging_103 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_print_dep_t>
{
public:
  Test_auto_check_sbp_logging_103() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_print_dep_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_print_dep_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_print_dep_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_logging_103, Test)     
{

    uint8_t encoded_frame[] = {85,16,0,34,34,41,73,78,70,79,58,32,97,99,113,58,32,80,82,78,32,50,32,102,111,117,110,100,32,64,32,51,57,57,54,32,72,122,44,32,50,48,32,83,78,82,10,239,48, };

    sbp_msg_print_dep_t test_unpacked_msg{};
    
    {
      const char assign_string[] = { (char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)50,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)51,(char)57,(char)57,(char)54,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)48,(char)32,(char)83,(char)78,(char)82,(char)10 };
      memcpy(test_unpacked_msg.text.data, assign_string, sizeof(assign_string));
    }
    
    test_unpacked_msg.text.len = 41;
                                                                              
    EXPECT_EQ(send_message( 8738, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 8738);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    {
      const char check_string[] = { (char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)50,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)51,(char)57,(char)57,(char)54,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)48,(char)32,(char)83,(char)78,(char)82,(char)10 };
      EXPECT_EQ(memcmp(last_msg_.text.data, check_string, sizeof(check_string)), 0);
    }
    
    EXPECT_EQ(last_msg_.text.len, 41);
}                                                     
class Test_auto_check_sbp_logging_104 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_print_dep_t>
{
public:
  Test_auto_check_sbp_logging_104() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_print_dep_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_print_dep_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_print_dep_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_logging_104, Test)     
{

    uint8_t encoded_frame[] = {85,16,0,34,34,42,73,78,70,79,58,32,97,99,113,58,32,80,82,78,32,52,32,102,111,117,110,100,32,64,32,45,55,52,57,50,32,72,122,44,32,50,48,32,83,78,82,10,47,248, };

    sbp_msg_print_dep_t test_unpacked_msg{};
    
    {
      const char assign_string[] = { (char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)52,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)45,(char)55,(char)52,(char)57,(char)50,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)48,(char)32,(char)83,(char)78,(char)82,(char)10 };
      memcpy(test_unpacked_msg.text.data, assign_string, sizeof(assign_string));
    }
    
    test_unpacked_msg.text.len = 42;
                                                                              
    EXPECT_EQ(send_message( 8738, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 8738);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    {
      const char check_string[] = { (char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)97,(char)99,(char)113,(char)58,(char)32,(char)80,(char)82,(char)78,(char)32,(char)52,(char)32,(char)102,(char)111,(char)117,(char)110,(char)100,(char)32,(char)64,(char)32,(char)45,(char)55,(char)52,(char)57,(char)50,(char)32,(char)72,(char)122,(char)44,(char)32,(char)50,(char)48,(char)32,(char)83,(char)78,(char)82,(char)10 };
      EXPECT_EQ(memcmp(last_msg_.text.data, check_string, sizeof(check_string)), 0);
    }
    
    EXPECT_EQ(last_msg_.text.len, 42);
}                                                     
class Test_auto_check_sbp_logging_105 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_print_dep_t>
{
public:
  Test_auto_check_sbp_logging_105() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_print_dep_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_print_dep_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_print_dep_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_logging_105, Test)     
{

    uint8_t encoded_frame[] = {85,16,0,34,34,35,73,78,70,79,58,32,68,105,115,97,98,108,105,110,103,32,99,104,97,110,110,101,108,32,49,32,40,80,82,78,32,49,53,41,10,158,139, };

    sbp_msg_print_dep_t test_unpacked_msg{};
    
    {
      const char assign_string[] = { (char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)68,(char)105,(char)115,(char)97,(char)98,(char)108,(char)105,(char)110,(char)103,(char)32,(char)99,(char)104,(char)97,(char)110,(char)110,(char)101,(char)108,(char)32,(char)49,(char)32,(char)40,(char)80,(char)82,(char)78,(char)32,(char)49,(char)53,(char)41,(char)10 };
      memcpy(test_unpacked_msg.text.data, assign_string, sizeof(assign_string));
    }
    
    test_unpacked_msg.text.len = 35;
                                                                              
    EXPECT_EQ(send_message( 8738, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 8738);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    
    {
      const char check_string[] = { (char)73,(char)78,(char)70,(char)79,(char)58,(char)32,(char)68,(char)105,(char)115,(char)97,(char)98,(char)108,(char)105,(char)110,(char)103,(char)32,(char)99,(char)104,(char)97,(char)110,(char)110,(char)101,(char)108,(char)32,(char)49,(char)32,(char)40,(char)80,(char)82,(char)78,(char)32,(char)49,(char)53,(char)41,(char)10 };
      EXPECT_EQ(memcmp(last_msg_.text.data, check_string, sizeof(check_string)), 0);
    }
    
    EXPECT_EQ(last_msg_.text.len, 35);
}