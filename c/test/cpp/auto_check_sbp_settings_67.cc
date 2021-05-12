#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_settings_670 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>
{
public:
  Test_auto_check_sbp_settings_670() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_settings_read_by_index_resp_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_settings_read_by_index_resp_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_settings_670, Test)     
{

    uint8_t encoded_frame[] = {85,167,0,246,215,78,0,0,116,101,108,101,109,101,116,114,121,95,114,97,100,105,111,0,99,111,110,102,105,103,117,114,97,116,105,111,110,95,115,116,114,105,110,103,0,65,84,38,70,44,65,84,83,49,61,49,49,53,44,65,84,83,50,61,49,50,56,44,65,84,83,53,61,48,44,65,84,38,87,44,65,84,90,0,248,233, };

    sbp_msg_settings_read_by_index_resp_t test_unpacked_msg{};
    test_unpacked_msg.index = 0;
    
    {
      const char assign_string[] = { (char)116,(char)101,(char)108,(char)101,(char)109,(char)101,(char)116,(char)114,(char)121,(char)95,(char)114,(char)97,(char)100,(char)105,(char)111,(char)0,(char)99,(char)111,(char)110,(char)102,(char)105,(char)103,(char)117,(char)114,(char)97,(char)116,(char)105,(char)111,(char)110,(char)95,(char)115,(char)116,(char)114,(char)105,(char)110,(char)103,(char)0,(char)65,(char)84,(char)38,(char)70,(char)44,(char)65,(char)84,(char)83,(char)49,(char)61,(char)49,(char)49,(char)53,(char)44,(char)65,(char)84,(char)83,(char)50,(char)61,(char)49,(char)50,(char)56,(char)44,(char)65,(char)84,(char)83,(char)53,(char)61,(char)48,(char)44,(char)65,(char)84,(char)38,(char)87,(char)44,(char)65,(char)84,(char)90,(char)0 };
      memcpy(test_unpacked_msg.setting.data, assign_string, sizeof(assign_string));
    }
    
    
    test_unpacked_msg.setting.lens[0] = 15;
    
    test_unpacked_msg.setting.lens[1] = 20;
    
    test_unpacked_msg.setting.lens[2] = 38;
    
    test_unpacked_msg.setting.n_sections = 3;
    
    
    test_unpacked_msg.setting.offsets[0] = 0;
    
    test_unpacked_msg.setting.offsets[1] = 16;
    
    test_unpacked_msg.setting.offsets[2] = 37;
    
    test_unpacked_msg.setting.packed_len = 76;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.index, 0);
    
    {
      const char check_string[] = { (char)116,(char)101,(char)108,(char)101,(char)109,(char)101,(char)116,(char)114,(char)121,(char)95,(char)114,(char)97,(char)100,(char)105,(char)111,(char)0,(char)99,(char)111,(char)110,(char)102,(char)105,(char)103,(char)117,(char)114,(char)97,(char)116,(char)105,(char)111,(char)110,(char)95,(char)115,(char)116,(char)114,(char)105,(char)110,(char)103,(char)0,(char)65,(char)84,(char)38,(char)70,(char)44,(char)65,(char)84,(char)83,(char)49,(char)61,(char)49,(char)49,(char)53,(char)44,(char)65,(char)84,(char)83,(char)50,(char)61,(char)49,(char)50,(char)56,(char)44,(char)65,(char)84,(char)83,(char)53,(char)61,(char)48,(char)44,(char)65,(char)84,(char)38,(char)87,(char)44,(char)65,(char)84,(char)90,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.setting.data, check_string, sizeof(check_string)), 0);
    }
    
    EXPECT_EQ(last_msg_.setting.lens[0], 15);
    EXPECT_EQ(last_msg_.setting.lens[1], 20);
    EXPECT_EQ(last_msg_.setting.lens[2], 38);
    
    EXPECT_EQ(last_msg_.setting.n_sections, 3);
    
    EXPECT_EQ(last_msg_.setting.offsets[0], 0);
    EXPECT_EQ(last_msg_.setting.offsets[1], 16);
    EXPECT_EQ(last_msg_.setting.offsets[2], 37);
    
    EXPECT_EQ(last_msg_.setting.packed_len, 76);
}                                                     
class Test_auto_check_sbp_settings_671 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>
{
public:
  Test_auto_check_sbp_settings_671() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_settings_read_by_index_resp_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_settings_read_by_index_resp_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_settings_671, Test)     
{

    uint8_t encoded_frame[] = {85,167,0,246,215,35,1,0,117,97,114,116,95,102,116,100,105,0,109,111,100,101,0,83,66,80,0,101,110,117,109,58,83,66,80,44,78,77,69,65,0,167,243, };

    sbp_msg_settings_read_by_index_resp_t test_unpacked_msg{};
    test_unpacked_msg.index = 1;
    
    {
      const char assign_string[] = { (char)117,(char)97,(char)114,(char)116,(char)95,(char)102,(char)116,(char)100,(char)105,(char)0,(char)109,(char)111,(char)100,(char)101,(char)0,(char)83,(char)66,(char)80,(char)0,(char)101,(char)110,(char)117,(char)109,(char)58,(char)83,(char)66,(char)80,(char)44,(char)78,(char)77,(char)69,(char)65,(char)0 };
      memcpy(test_unpacked_msg.setting.data, assign_string, sizeof(assign_string));
    }
    
    
    test_unpacked_msg.setting.lens[0] = 9;
    
    test_unpacked_msg.setting.lens[1] = 4;
    
    test_unpacked_msg.setting.lens[2] = 3;
    
    test_unpacked_msg.setting.lens[3] = 13;
    
    test_unpacked_msg.setting.n_sections = 4;
    
    
    test_unpacked_msg.setting.offsets[0] = 0;
    
    test_unpacked_msg.setting.offsets[1] = 10;
    
    test_unpacked_msg.setting.offsets[2] = 15;
    
    test_unpacked_msg.setting.offsets[3] = 19;
    
    test_unpacked_msg.setting.packed_len = 33;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.index, 1);
    
    {
      const char check_string[] = { (char)117,(char)97,(char)114,(char)116,(char)95,(char)102,(char)116,(char)100,(char)105,(char)0,(char)109,(char)111,(char)100,(char)101,(char)0,(char)83,(char)66,(char)80,(char)0,(char)101,(char)110,(char)117,(char)109,(char)58,(char)83,(char)66,(char)80,(char)44,(char)78,(char)77,(char)69,(char)65,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.setting.data, check_string, sizeof(check_string)), 0);
    }
    
    EXPECT_EQ(last_msg_.setting.lens[0], 9);
    EXPECT_EQ(last_msg_.setting.lens[1], 4);
    EXPECT_EQ(last_msg_.setting.lens[2], 3);
    EXPECT_EQ(last_msg_.setting.lens[3], 13);
    
    EXPECT_EQ(last_msg_.setting.n_sections, 4);
    
    EXPECT_EQ(last_msg_.setting.offsets[0], 0);
    EXPECT_EQ(last_msg_.setting.offsets[1], 10);
    EXPECT_EQ(last_msg_.setting.offsets[2], 15);
    EXPECT_EQ(last_msg_.setting.offsets[3], 19);
    
    EXPECT_EQ(last_msg_.setting.packed_len, 33);
}                                                     
class Test_auto_check_sbp_settings_672 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>
{
public:
  Test_auto_check_sbp_settings_672() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_settings_read_by_index_resp_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_settings_read_by_index_resp_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_settings_672, Test)     
{

    uint8_t encoded_frame[] = {85,167,0,246,215,35,2,0,117,97,114,116,95,102,116,100,105,0,115,98,112,95,109,101,115,115,97,103,101,95,109,97,115,107,0,54,53,53,51,53,0,4,56, };

    sbp_msg_settings_read_by_index_resp_t test_unpacked_msg{};
    test_unpacked_msg.index = 2;
    
    {
      const char assign_string[] = { (char)117,(char)97,(char)114,(char)116,(char)95,(char)102,(char)116,(char)100,(char)105,(char)0,(char)115,(char)98,(char)112,(char)95,(char)109,(char)101,(char)115,(char)115,(char)97,(char)103,(char)101,(char)95,(char)109,(char)97,(char)115,(char)107,(char)0,(char)54,(char)53,(char)53,(char)51,(char)53,(char)0 };
      memcpy(test_unpacked_msg.setting.data, assign_string, sizeof(assign_string));
    }
    
    
    test_unpacked_msg.setting.lens[0] = 9;
    
    test_unpacked_msg.setting.lens[1] = 16;
    
    test_unpacked_msg.setting.lens[2] = 5;
    
    test_unpacked_msg.setting.n_sections = 3;
    
    
    test_unpacked_msg.setting.offsets[0] = 0;
    
    test_unpacked_msg.setting.offsets[1] = 10;
    
    test_unpacked_msg.setting.offsets[2] = 27;
    
    test_unpacked_msg.setting.packed_len = 33;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.index, 2);
    
    {
      const char check_string[] = { (char)117,(char)97,(char)114,(char)116,(char)95,(char)102,(char)116,(char)100,(char)105,(char)0,(char)115,(char)98,(char)112,(char)95,(char)109,(char)101,(char)115,(char)115,(char)97,(char)103,(char)101,(char)95,(char)109,(char)97,(char)115,(char)107,(char)0,(char)54,(char)53,(char)53,(char)51,(char)53,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.setting.data, check_string, sizeof(check_string)), 0);
    }
    
    EXPECT_EQ(last_msg_.setting.lens[0], 9);
    EXPECT_EQ(last_msg_.setting.lens[1], 16);
    EXPECT_EQ(last_msg_.setting.lens[2], 5);
    
    EXPECT_EQ(last_msg_.setting.n_sections, 3);
    
    EXPECT_EQ(last_msg_.setting.offsets[0], 0);
    EXPECT_EQ(last_msg_.setting.offsets[1], 10);
    EXPECT_EQ(last_msg_.setting.offsets[2], 27);
    
    EXPECT_EQ(last_msg_.setting.packed_len, 33);
}                                                     
class Test_auto_check_sbp_settings_673 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>
{
public:
  Test_auto_check_sbp_settings_673() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_settings_read_by_index_resp_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_settings_read_by_index_resp_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_settings_673, Test)     
{

    uint8_t encoded_frame[] = {85,167,0,246,215,29,3,0,117,97,114,116,95,102,116,100,105,0,98,97,117,100,114,97,116,101,0,49,48,48,48,48,48,48,0,242,146, };

    sbp_msg_settings_read_by_index_resp_t test_unpacked_msg{};
    test_unpacked_msg.index = 3;
    
    {
      const char assign_string[] = { (char)117,(char)97,(char)114,(char)116,(char)95,(char)102,(char)116,(char)100,(char)105,(char)0,(char)98,(char)97,(char)117,(char)100,(char)114,(char)97,(char)116,(char)101,(char)0,(char)49,(char)48,(char)48,(char)48,(char)48,(char)48,(char)48,(char)0 };
      memcpy(test_unpacked_msg.setting.data, assign_string, sizeof(assign_string));
    }
    
    
    test_unpacked_msg.setting.lens[0] = 9;
    
    test_unpacked_msg.setting.lens[1] = 8;
    
    test_unpacked_msg.setting.lens[2] = 7;
    
    test_unpacked_msg.setting.n_sections = 3;
    
    
    test_unpacked_msg.setting.offsets[0] = 0;
    
    test_unpacked_msg.setting.offsets[1] = 10;
    
    test_unpacked_msg.setting.offsets[2] = 19;
    
    test_unpacked_msg.setting.packed_len = 27;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.index, 3);
    
    {
      const char check_string[] = { (char)117,(char)97,(char)114,(char)116,(char)95,(char)102,(char)116,(char)100,(char)105,(char)0,(char)98,(char)97,(char)117,(char)100,(char)114,(char)97,(char)116,(char)101,(char)0,(char)49,(char)48,(char)48,(char)48,(char)48,(char)48,(char)48,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.setting.data, check_string, sizeof(check_string)), 0);
    }
    
    EXPECT_EQ(last_msg_.setting.lens[0], 9);
    EXPECT_EQ(last_msg_.setting.lens[1], 8);
    EXPECT_EQ(last_msg_.setting.lens[2], 7);
    
    EXPECT_EQ(last_msg_.setting.n_sections, 3);
    
    EXPECT_EQ(last_msg_.setting.offsets[0], 0);
    EXPECT_EQ(last_msg_.setting.offsets[1], 10);
    EXPECT_EQ(last_msg_.setting.offsets[2], 19);
    
    EXPECT_EQ(last_msg_.setting.packed_len, 27);
}                                                     
class Test_auto_check_sbp_settings_674 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>
{
public:
  Test_auto_check_sbp_settings_674() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_settings_read_by_index_resp_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_settings_read_by_index_resp_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_settings_read_by_index_resp_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_settings_674, Test)     
{

    uint8_t encoded_frame[] = {85,167,0,246,215,36,4,0,117,97,114,116,95,117,97,114,116,97,0,109,111,100,101,0,83,66,80,0,101,110,117,109,58,83,66,80,44,78,77,69,65,0,22,4, };

    sbp_msg_settings_read_by_index_resp_t test_unpacked_msg{};
    test_unpacked_msg.index = 4;
    
    {
      const char assign_string[] = { (char)117,(char)97,(char)114,(char)116,(char)95,(char)117,(char)97,(char)114,(char)116,(char)97,(char)0,(char)109,(char)111,(char)100,(char)101,(char)0,(char)83,(char)66,(char)80,(char)0,(char)101,(char)110,(char)117,(char)109,(char)58,(char)83,(char)66,(char)80,(char)44,(char)78,(char)77,(char)69,(char)65,(char)0 };
      memcpy(test_unpacked_msg.setting.data, assign_string, sizeof(assign_string));
    }
    
    
    test_unpacked_msg.setting.lens[0] = 10;
    
    test_unpacked_msg.setting.lens[1] = 4;
    
    test_unpacked_msg.setting.lens[2] = 3;
    
    test_unpacked_msg.setting.lens[3] = 13;
    
    test_unpacked_msg.setting.n_sections = 4;
    
    
    test_unpacked_msg.setting.offsets[0] = 0;
    
    test_unpacked_msg.setting.offsets[1] = 11;
    
    test_unpacked_msg.setting.offsets[2] = 16;
    
    test_unpacked_msg.setting.offsets[3] = 20;
    
    test_unpacked_msg.setting.packed_len = 34;
                                                                              
    EXPECT_EQ(send_message( 55286, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 55286);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.index, 4);
    
    {
      const char check_string[] = { (char)117,(char)97,(char)114,(char)116,(char)95,(char)117,(char)97,(char)114,(char)116,(char)97,(char)0,(char)109,(char)111,(char)100,(char)101,(char)0,(char)83,(char)66,(char)80,(char)0,(char)101,(char)110,(char)117,(char)109,(char)58,(char)83,(char)66,(char)80,(char)44,(char)78,(char)77,(char)69,(char)65,(char)0 };
      EXPECT_EQ(memcmp(last_msg_.setting.data, check_string, sizeof(check_string)), 0);
    }
    
    EXPECT_EQ(last_msg_.setting.lens[0], 10);
    EXPECT_EQ(last_msg_.setting.lens[1], 4);
    EXPECT_EQ(last_msg_.setting.lens[2], 3);
    EXPECT_EQ(last_msg_.setting.lens[3], 13);
    
    EXPECT_EQ(last_msg_.setting.n_sections, 4);
    
    EXPECT_EQ(last_msg_.setting.offsets[0], 0);
    EXPECT_EQ(last_msg_.setting.offsets[1], 11);
    EXPECT_EQ(last_msg_.setting.offsets[2], 16);
    EXPECT_EQ(last_msg_.setting.offsets[3], 20);
    
    EXPECT_EQ(last_msg_.setting.packed_len, 34);
}