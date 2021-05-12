#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_210 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_ecef_t>
{
public:
  Test_auto_check_sbp_navigation_210() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_ecef_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_ecef_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_210, Test)     
{

    uint8_t encoded_frame[] = {85,9,2,211,136,32,16,248,122,19,73,29,46,132,182,122,68,193,219,192,29,176,121,119,80,193,83,11,210,90,79,75,77,65,0,0,15,2,84,6, };

    sbp_msg_pos_ecef_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 2;
    test_unpacked_msg.n_sats = 15;
    test_unpacked_msg.tow = 326826000;
    test_unpacked_msg.x = -2684269.0326572997;
    test_unpacked_msg.y = -4316646.751816;
    test_unpacked_msg.z = 3839646.7095350414;
                                                                              
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
    EXPECT_EQ(last_msg_.flags, 2);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326826000);
    EXPECT_LT((last_msg_.x*100 - -2684269.03266*100), 0.05);
    EXPECT_LT((last_msg_.y*100 - -4316646.75182*100), 0.05);
    EXPECT_LT((last_msg_.z*100 - 3839646.70954*100), 0.05);
}                                                     
class Test_auto_check_sbp_navigation_211 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_ecef_t>
{
public:
  Test_auto_check_sbp_navigation_211() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_ecef_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_ecef_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_211, Test)     
{

    uint8_t encoded_frame[] = {85,9,2,211,136,32,248,251,122,19,103,106,57,136,182,122,68,193,176,242,200,176,121,119,80,193,244,135,97,59,79,75,77,65,0,0,15,2,147,216, };

    sbp_msg_pos_ecef_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 2;
    test_unpacked_msg.n_sats = 15;
    test_unpacked_msg.tow = 326827000;
    test_unpacked_msg.x = -2684269.064252186;
    test_unpacked_msg.y = -4316646.762264892;
    test_unpacked_msg.z = 3839646.463913912;
                                                                              
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
    EXPECT_EQ(last_msg_.flags, 2);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326827000);
    EXPECT_LT((last_msg_.x*100 - -2684269.06425*100), 0.05);
    EXPECT_LT((last_msg_.y*100 - -4316646.76226*100), 0.05);
    EXPECT_LT((last_msg_.z*100 - 3839646.46391*100), 0.05);
}                                                     
class Test_auto_check_sbp_navigation_212 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_ecef_t>
{
public:
  Test_auto_check_sbp_navigation_212() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_ecef_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_ecef_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_212, Test)     
{

    uint8_t encoded_frame[] = {85,9,2,211,136,32,224,255,122,19,101,179,242,182,182,122,68,193,130,196,145,199,121,119,80,193,212,10,253,15,79,75,77,65,0,0,15,2,40,201, };

    sbp_msg_pos_ecef_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 2;
    test_unpacked_msg.n_sats = 15;
    test_unpacked_msg.tow = 326828000;
    test_unpacked_msg.x = -2684269.4292816394;
    test_unpacked_msg.y = -4316647.118271949;
    test_unpacked_msg.z = 3839646.124909738;
                                                                              
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
    EXPECT_EQ(last_msg_.flags, 2);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326828000);
    EXPECT_LT((last_msg_.x*100 - -2684269.42928*100), 0.05);
    EXPECT_LT((last_msg_.y*100 - -4316647.11827*100), 0.05);
    EXPECT_LT((last_msg_.z*100 - 3839646.12491*100), 0.05);
}                                                     
class Test_auto_check_sbp_navigation_213 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_ecef_t>
{
public:
  Test_auto_check_sbp_navigation_213() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_ecef_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_ecef_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_ecef_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_213, Test)     
{

    uint8_t encoded_frame[] = {85,9,2,211,136,32,200,3,123,19,146,214,132,215,182,122,68,193,213,68,49,215,121,119,80,193,71,34,110,243,78,75,77,65,0,0,15,2,187,86, };

    sbp_msg_pos_ecef_t test_unpacked_msg{};
    test_unpacked_msg.accuracy = 0;
    test_unpacked_msg.flags = 2;
    test_unpacked_msg.n_sats = 15;
    test_unpacked_msg.tow = 326829000;
    test_unpacked_msg.x = -2684269.683741399;
    test_unpacked_msg.y = -4316647.3623821335;
    test_unpacked_msg.z = 3839645.90179852;
                                                                              
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
    EXPECT_EQ(last_msg_.flags, 2);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326829000);
    EXPECT_LT((last_msg_.x*100 - -2684269.68374*100), 0.05);
    EXPECT_LT((last_msg_.y*100 - -4316647.36238*100), 0.05);
    EXPECT_LT((last_msg_.z*100 - 3839645.9018*100), 0.05);
}