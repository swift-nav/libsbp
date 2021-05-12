#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_navigation_260 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_t>
{
public:
  Test_auto_check_sbp_navigation_260() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_260, Test)     
{

    uint8_t encoded_frame[] = {85,10,2,211,136,34,40,244,122,19,201,106,155,186,42,160,66,64,168,109,26,225,0,120,94,192,130,102,237,230,43,54,60,64,0,0,0,0,14,2,175,162, };

    sbp_msg_pos_llh_t test_unpacked_msg{};
    test_unpacked_msg.flags = 2;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 28.21160739227208;
    test_unpacked_msg.lat = 37.25130398358085;
    test_unpacked_msg.lon = -121.87505366879361;
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
    EXPECT_EQ(last_msg_.flags, 2);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 28.2116073923*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.2513039836*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -121.875053669*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 14);
    EXPECT_EQ(last_msg_.tow, 326825000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_261 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_t>
{
public:
  Test_auto_check_sbp_navigation_261() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_261, Test)     
{

    uint8_t encoded_frame[] = {85,10,2,211,136,34,16,248,122,19,52,177,251,178,42,160,66,64,237,22,97,224,0,120,94,192,107,188,109,90,247,189,59,64,0,0,0,0,15,2,38,177, };

    sbp_msg_pos_llh_t test_unpacked_msg{};
    test_unpacked_msg.flags = 2;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 27.742055560866373;
    test_unpacked_msg.lat = 37.251303074738104;
    test_unpacked_msg.lon = -121.87505349618341;
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
    EXPECT_EQ(last_msg_.flags, 2);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 27.7420555609*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.2513030747*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -121.875053496*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326826000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_262 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_t>
{
public:
  Test_auto_check_sbp_navigation_262() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_262, Test)     
{

    uint8_t encoded_frame[] = {85,10,2,211,136,34,248,251,122,19,135,66,9,163,42,160,66,64,146,8,99,225,0,120,94,192,45,181,143,219,28,157,59,64,0,0,0,0,15,2,51,40, };

    sbp_msg_pos_llh_t test_unpacked_msg{};
    test_unpacked_msg.flags = 2;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 27.613721582970516;
    test_unpacked_msg.lat = 37.25130117370741;
    test_unpacked_msg.lon = -121.87505373641241;
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
    EXPECT_EQ(last_msg_.flags, 2);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 27.613721583*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.2513011737*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -121.875053736*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326827000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_263 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_t>
{
public:
  Test_auto_check_sbp_navigation_263() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_263, Test)     
{

    uint8_t encoded_frame[] = {85,10,2,211,136,34,224,255,122,19,18,44,253,119,42,160,66,64,48,109,39,231,0,120,94,192,185,76,48,17,119,205,59,64,0,0,0,0,15,2,12,194, };

    sbp_msg_pos_llh_t test_unpacked_msg{};
    test_unpacked_msg.flags = 2;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 27.80259807042305;
    test_unpacked_msg.lat = 37.251296042079176;
    test_unpacked_msg.lon = -121.87505511141057;
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
    EXPECT_EQ(last_msg_.flags, 2);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 27.8025980704*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.2512960421*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -121.875055111*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326828000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}                                                     
class Test_auto_check_sbp_navigation_264 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_pos_llh_t>
{
public:
  Test_auto_check_sbp_navigation_264() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_pos_llh_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
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

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_pos_llh_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_pos_llh_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_navigation_264, Test)     
{

    uint8_t encoded_frame[] = {85,10,2,211,136,34,200,3,123,19,225,237,238,90,42,160,66,64,59,143,70,235,0,120,94,192,101,106,249,224,131,240,59,64,0,0,0,0,15,2,34,103, };

    sbp_msg_pos_llh_t test_unpacked_msg{};
    test_unpacked_msg.flags = 2;
    test_unpacked_msg.h_accuracy = 0;
    test_unpacked_msg.height = 27.939512310879213;
    test_unpacked_msg.lat = 37.251292578377395;
    test_unpacked_msg.lon = -121.87505609407974;
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
    EXPECT_EQ(last_msg_.flags, 2);
    EXPECT_EQ(last_msg_.h_accuracy, 0);
    EXPECT_LT((last_msg_.height*100 - 27.9395123109*100), 0.05);
    EXPECT_LT((last_msg_.lat*100 - 37.2512925784*100), 0.05);
    EXPECT_LT((last_msg_.lon*100 - -121.875056094*100), 0.05);
    EXPECT_EQ(last_msg_.n_sats, 15);
    EXPECT_EQ(last_msg_.tow, 326829000);
    EXPECT_EQ(last_msg_.v_accuracy, 0);
}