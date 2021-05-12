#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_120 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_t>
{
public:
  Test_auto_check_sbp_navigation_120() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_120, Test)     
{

    uint8_t encoded_frame[] = {85,11,2,211,136,20,40,244,122,19,150,98,238,255,190,64,20,0,246,163,9,0,0,0,14,0,219,191, };

    sbp_msg_baseline_ecef_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 14;
    test_unpacked_msg.tow = 326825000;
    test_unpacked_msg.x = -1154410;
    test_unpacked_msg.y = 1327294;
    test_unpacked_msg.z = 631798;
                                                                              
    EXPECT_EQ(send_message( 35027, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 35027);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 14);
    EXPECT_EQ(last_msg_.tow, 326825000);
    EXPECT_EQ(last_msg_.x, -1154410);
    EXPECT_EQ(last_msg_.y, 1327294);
    EXPECT_EQ(last_msg_.z, 631798);
}                                                     
class Test_auto_check_sbp_navigation_121 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_t>
{
public:
  Test_auto_check_sbp_navigation_121() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_121, Test)     
{

    uint8_t encoded_frame[] = {85,11,2,211,136,20,16,248,122,19,72,99,238,255,191,65,20,0,138,162,9,0,0,0,15,0,240,78, };

    sbp_msg_baseline_ecef_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 15;
    test_unpacked_msg.tow = 326826000;
    test_unpacked_msg.x = -1154232;
    test_unpacked_msg.y = 1327551;
    test_unpacked_msg.z = 631434;
                                                                              
    EXPECT_EQ(send_message( 35027, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 35027);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326826000);
    EXPECT_EQ(last_msg_.x, -1154232);
    EXPECT_EQ(last_msg_.y, 1327551);
    EXPECT_EQ(last_msg_.z, 631434);
}                                                     
class Test_auto_check_sbp_navigation_122 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_t>
{
public:
  Test_auto_check_sbp_navigation_122() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_122, Test)     
{

    uint8_t encoded_frame[] = {85,11,2,211,136,20,248,251,122,19,41,99,238,255,181,65,20,0,148,161,9,0,0,0,15,0,4,132, };

    sbp_msg_baseline_ecef_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 15;
    test_unpacked_msg.tow = 326827000;
    test_unpacked_msg.x = -1154263;
    test_unpacked_msg.y = 1327541;
    test_unpacked_msg.z = 631188;
                                                                              
    EXPECT_EQ(send_message( 35027, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 35027);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326827000);
    EXPECT_EQ(last_msg_.x, -1154263);
    EXPECT_EQ(last_msg_.y, 1327541);
    EXPECT_EQ(last_msg_.z, 631188);
}                                                     
class Test_auto_check_sbp_navigation_123 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_t>
{
public:
  Test_auto_check_sbp_navigation_123() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_123, Test)     
{

    uint8_t encoded_frame[] = {85,11,2,211,136,20,224,255,122,19,188,97,238,255,81,64,20,0,65,160,9,0,0,0,15,0,67,94, };

    sbp_msg_baseline_ecef_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 15;
    test_unpacked_msg.tow = 326828000;
    test_unpacked_msg.x = -1154628;
    test_unpacked_msg.y = 1327185;
    test_unpacked_msg.z = 630849;
                                                                              
    EXPECT_EQ(send_message( 35027, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 35027);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326828000);
    EXPECT_EQ(last_msg_.x, -1154628);
    EXPECT_EQ(last_msg_.y, 1327185);
    EXPECT_EQ(last_msg_.z, 630849);
}                                                     
class Test_auto_check_sbp_navigation_124 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_baseline_ecef_t>
{
public:
  Test_auto_check_sbp_navigation_124() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_baseline_ecef_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_baseline_ecef_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_baseline_ecef_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_124, Test)     
{

    uint8_t encoded_frame[] = {85,11,2,211,136,20,200,3,123,19,189,96,238,255,93,63,20,0,98,159,9,0,0,0,15,0,106,94, };

    sbp_msg_baseline_ecef_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 0;
    test_unpacked_msg.n_sats = 15;
    test_unpacked_msg.tow = 326829000;
    test_unpacked_msg.x = -1154883;
    test_unpacked_msg.y = 1326941;
    test_unpacked_msg.z = 630626;
                                                                              
    EXPECT_EQ(send_message( 35027, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 35027);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_EQ(last_msg_.accuracy, 0);
    EXPECT_EQ(last_msg_.flags, 0);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326829000);
    EXPECT_EQ(last_msg_.x, -1154883);
    EXPECT_EQ(last_msg_.y, 1326941);
    EXPECT_EQ(last_msg_.z, 630626);
}